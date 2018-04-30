# package: pointcloud_util
This is a ROS package, and it includes all utility related with ROS/PCL pointcloud. 
Refer to detailed node description below.

## pointcloud_saver
- Description: listen to a Pointcloud2-type ROS rostopic and save the last message.
- Usage: 
    + pointcloud_saver
    + pointcloud_saver [-f \<filename\>] [ROS remapping args]
- Subscribe Topics:
    + /points:      the pointcloud topic to be saved
Note: 
    Use Ctrl+C to shutdown the node (the latest topic on the node will be saved)
   	