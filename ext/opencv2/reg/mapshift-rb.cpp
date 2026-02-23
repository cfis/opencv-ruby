#include <opencv2/reg/mapshift.hpp>
#include "mapshift-rb.hpp"

using namespace Rice;

void Init_Reg_Mapshift()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvReg = define_module_under(rb_mCv, "Reg");

  Rice::Data_Type<cv::reg::MapShift> rb_cCvRegMapShift = define_class_under<cv::reg::MapShift, cv::reg::Map>(rb_mCvReg, "MapShift").
    define_constructor(Constructor<cv::reg::MapShift>()).
    define_constructor(Constructor<cv::reg::MapShift, cv::InputArray>(),
      Arg("shift")).
    define_method<void(cv::reg::MapShift::*)(cv::InputArray, cv::OutputArray) const>("inverse_warp", &cv::reg::MapShift::inverseWarp,
      Arg("img1"), Arg("img2")).
    define_method<cv::Ptr<cv::reg::Map>(cv::reg::MapShift::*)() const>("inverse_map", &cv::reg::MapShift::inverseMap).
    define_method<void(cv::reg::MapShift::*)(cv::Ptr<cv::reg::Map>)>("compose", &cv::reg::MapShift::compose,
      Arg("map")).
    define_method<void(cv::reg::MapShift::*)(double)>("scale", &cv::reg::MapShift::scale,
      Arg("factor")).
    define_method<const cv::Vec<double, 2>&(cv::reg::MapShift::*)() const>("get_shift", &cv::reg::MapShift::getShift).
    define_method<void(cv::reg::MapShift::*)(cv::OutputArray) const>("get_shift", &cv::reg::MapShift::getShift,
      Arg("shift"));
}
