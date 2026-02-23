#include <opencv2/datasets/util.hpp>
#include "util-rb.hpp"

using namespace Rice;

void Init_Datasets_Util()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvDatasets = define_module_under(rb_mCv, "Datasets");

  rb_mCvDatasets.define_module_function<void(*)(const std::string&, std::vector<std::string>&, char)>("split", &cv::datasets::split,
    Arg("s"), Arg("elems"), Arg("delim"));

  rb_mCvDatasets.define_module_function<void(*)(const std::string&)>("create_directory", &cv::datasets::createDirectory,
    Arg("path"));

  rb_mCvDatasets.define_module_function<void(*)(const std::string&, std::vector<std::string>&)>("get_dir_list", &cv::datasets::getDirList,
    Arg("dir_name"), Arg("file_names"));
}
