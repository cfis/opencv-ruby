#include <opencv2/core/ovx.hpp>
#include "ovx-rb.hpp"

using namespace Rice;


void Init_Ovx()
{
  Module rb_mCv = define_module("Cv");
  
  rb_mCv.define_module_function("have_open_vx?", &cv::haveOpenVX);
  
  rb_mCv.define_module_function("use_open_vx?", &cv::useOpenVX);
  
  rb_mCv.define_module_function("set_use_open_vx", &cv::setUseOpenVX,
    Arg("flag"));

}