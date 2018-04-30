/*
 * Description: save pointcloud to binary PCD file
 */

#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl_ros/point_cloud.h>
#include <pcl_ros/io/pcd_io.h>
#include <string>
#include "saver_option.h"

sensor_msgs::PointCloud2 * pointcloud_buffer;

void print_usage(){
    std::cout << "Usage:" << std::endl;
    std::cout << "\t pointcloud_saver" << std::endl;
    std::cout << "\t pointcloud_saver [-f <filename>] [--xyz(default)|--bin] [ROS remapping args])" << std::endl;
}

void update_pcl(const sensor_msgs::PointCloud2& pcl_msg){
    *pointcloud_buffer = pcl_msg;
}

void print_notice(){
    ROS_INFO("Press CTRL+C to save the latest pointcloud.");
}

int main(int argc, char * argv[]){
    ros::init(argc,argv,"pointcloud_saver");
    ros::NodeHandle n;

    pointcloud_buffer = new sensor_msgs::PointCloud2;
    pointcloud_saver::SaverOption option;

    // get filename / use default one
    if (!option.parse_params(argc,argv)) {
        ROS_ERROR("Invalid Usage");
        print_usage();
        delete pointcloud_buffer;
        ros::shutdown();
        return 0;
    }

    ros::Subscriber sub_ = n.subscribe("/points",1000,update_pcl);

    print_notice();

    ros::spin();

    // on shutdown, save pointcloud to file
    pcl::PointCloud<pcl::PointXYZ> pcl_out;
    pcl::fromROSMsg(*pointcloud_buffer, pcl_out);
    if (pcl_out.empty()){
        ROS_WARN("No points available, skip saving.");
        delete pointcloud_buffer;
        ros::shutdown();
        return 0;
    }

    // save pointcloud
    std::string file_name = option.get_full_fname();
    if (option.get_file_format() == pointcloud_saver::XYZ){
        pcl::io::savePCDFileASCII(file_name, pcl_out);
    }
    else{
        pcl::io::savePCDFileBinary(file_name,pcl_out);
    }

    delete pointcloud_buffer;
    ros::shutdown();
}