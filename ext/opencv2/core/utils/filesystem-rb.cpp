#include <opencv2/core/core.hpp>
#include <opencv2/core/utils/filesystem.hpp>
#include "filesystem-rb.hpp"

using namespace Rice;


void Init_Filesystem()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvUtils = define_module_under(rb_mCv, "Utils");
  
  Module rb_mCvUtilsFs = define_module_under(rb_mCvUtils, "Fs");
  
  rb_mCvUtilsFs.define_module_function("exists?", &cv::utils::fs::exists,
    Arg("path"));
  
  rb_mCvUtilsFs.define_module_function("directory?", &cv::utils::fs::isDirectory,
    Arg("path"));
  
  rb_mCvUtilsFs.define_module_function("remove_all", &cv::utils::fs::remove_all,
    Arg("path"));
  
  rb_mCvUtilsFs.define_module_function("getcwd", &cv::utils::fs::getcwd);
  
  rb_mCvUtilsFs.define_module_function("canonical", &cv::utils::fs::canonical,
    Arg("path"));
  
  rb_mCvUtilsFs.define_module_function("join", &cv::utils::fs::join,
    Arg("base"), Arg("path"));
  
  rb_mCvUtilsFs.define_module_function<cv::String(*)(const cv::String&)>("get_parent", &cv::utils::fs::getParent,
    Arg("path"));
  
  rb_mCvUtilsFs.define_module_function<std::wstring(*)(const std::wstring&)>("get_parent", &cv::utils::fs::getParent,
    Arg("path"));
  
  rb_mCvUtilsFs.define_module_function("glob", &cv::utils::fs::glob,
    Arg("directory"), Arg("pattern"), Arg("result"), Arg("recursive") = static_cast<bool>(false), Arg("include_directories") = static_cast<bool>(false));
  
  rb_mCvUtilsFs.define_module_function("glob_relative", &cv::utils::fs::glob_relative,
    Arg("directory"), Arg("pattern"), Arg("result"), Arg("recursive") = static_cast<bool>(false), Arg("include_directories") = static_cast<bool>(false));
  
  rb_mCvUtilsFs.define_module_function("create_directory?", &cv::utils::fs::createDirectory,
    Arg("path"));
  
  rb_mCvUtilsFs.define_module_function("create_directories?", &cv::utils::fs::createDirectories,
    Arg("path"));

}