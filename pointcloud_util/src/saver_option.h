#ifndef POINTCLOUD_UTIL_SAVEROPTION_H
#define POINTCLOUD_UTIL_SAVEROPTION_H

#include <ros/ros.h>
#include <string>
#include <cstring>

namespace pointcloud_saver {

    enum FileFormat {
        XYZ,
        BIN,
    };

    class SaverOption {
    public:
        SaverOption();

        // return true on success, false on failure
        bool parse_params(int argc, char *argv[]);

        std::string get_full_fname();

        FileFormat get_file_format();

    private:
        std::string filename_;
        FileFormat format_;
    };

}

#endif //POINTCLOUD_UTIL_SAVEROPTION_H
