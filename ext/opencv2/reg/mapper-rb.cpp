#include <opencv2/reg/mapper.hpp>
#include "mapper-rb.hpp"

using namespace Rice;

void Init_Reg_Mapper()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvReg = define_module_under(rb_mCv, "Reg");

  Rice::Data_Type<cv::reg::Mapper> rb_cCvRegMapper = define_class_under<cv::reg::Mapper>(rb_mCvReg, "Mapper").
    define_method<cv::Ptr<cv::reg::Map>(cv::reg::Mapper::*)(cv::InputArray, cv::InputArray, cv::Ptr<cv::reg::Map>) const>("calculate", &cv::reg::Mapper::calculate,
      Arg("img1"), Arg("img2"), Arg("init") = static_cast<cv::Ptr<cv::reg::Map>>(cv::Ptr<cv::reg::Map>())).
    define_method<cv::Ptr<cv::reg::Map>(cv::reg::Mapper::*)() const>("get_map", &cv::reg::Mapper::getMap);
}
