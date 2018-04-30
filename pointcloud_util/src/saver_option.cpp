#include "saver_option.h"

namespace pointcloud_saver {

    SaverOption::SaverOption() {
        filename_ = "mypointcloud";
        format_ = pointcloud_saver::XYZ;
    }

    bool SaverOption::parse_params(int argc, char *argv[]) {
        for (int i = 1; i < argc; i++) {
            if (strcmp(argv[i], "-f") == 0) {
                if ((i + 1) >= argc) {
                    ROS_ERROR("missing filename after -f");
                    return false;
                }
                filename_ = std::string(argv[i + 1]);
                i++;
            } else if (strcmp(argv[i], "--xyz") == 0) {
                format_ = XYZ;
            } else if (strcmp(argv[i], "--bin") == 0) {
                format_ = BIN;
            } else {
                ROS_ERROR("Unrecognized option: %s", argv[i]);
                return false;
            }
        }
        return true;
    }

    FileFormat SaverOption::get_file_format() {
        return format_;
    }

    std::string SaverOption::get_full_fname() {
        if (format_ == XYZ) {
            return filename_ + ".xyz";
        } else {
            return filename_ + ".bin";
        }
    }
}