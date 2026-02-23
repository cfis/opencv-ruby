#include <opencv2/reg/mapaffine.hpp>
#include "mapaffine-rb.hpp"

using namespace Rice;

void Init_Reg_Mapaffine()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvReg = define_module_under(rb_mCv, "Reg");

  Rice::Data_Type<cv::reg::MapAffine> rb_cCvRegMapAffine = define_class_under<cv::reg::MapAffine, cv::reg::Map>(rb_mCvReg, "MapAffine").
    define_constructor(Constructor<cv::reg::MapAffine>()).
    define_constructor(Constructor<cv::reg::MapAffine, cv::InputArray, cv::InputArray>(),
      Arg("lin_tr"), Arg("shift")).
    define_method<void(cv::reg::MapAffine::*)(cv::InputArray, cv::OutputArray) const>("inverse_warp", &cv::reg::MapAffine::inverseWarp,
      Arg("img1"), Arg("img2")).
    define_method<cv::Ptr<cv::reg::Map>(cv::reg::MapAffine::*)() const>("inverse_map", &cv::reg::MapAffine::inverseMap).
    define_method<void(cv::reg::MapAffine::*)(cv::Ptr<cv::reg::Map>)>("compose", &cv::reg::MapAffine::compose,
      Arg("map")).
    define_method<void(cv::reg::MapAffine::*)(double)>("scale", &cv::reg::MapAffine::scale,
      Arg("factor")).
    define_method<const cv::Matx<double, 2, 2>&(cv::reg::MapAffine::*)() const>("get_lin_tr", &cv::reg::MapAffine::getLinTr).
    define_method<void(cv::reg::MapAffine::*)(cv::OutputArray) const>("get_lin_tr", &cv::reg::MapAffine::getLinTr,
      Arg("lin_tr")).
    define_method<const cv::Vec<double, 2>&(cv::reg::MapAffine::*)() const>("get_shift", &cv::reg::MapAffine::getShift).
    define_method<void(cv::reg::MapAffine::*)(cv::OutputArray) const>("get_shift", &cv::reg::MapAffine::getShift,
      Arg("shift"));
}
