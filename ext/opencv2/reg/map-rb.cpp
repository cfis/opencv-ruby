#include <opencv2/reg/map.hpp>
#include "map-rb.hpp"

using namespace Rice;

void Init_Reg_Map()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvReg = define_module_under(rb_mCv, "Reg");

  Rice::Data_Type<cv::reg::Map> rb_cCvRegMap = define_class_under<cv::reg::Map>(rb_mCvReg, "Map").
    define_method<void(cv::reg::Map::*)(cv::InputArray, cv::OutputArray) const>("warp", &cv::reg::Map::warp,
      Arg("img1"), Arg("img2")).
    define_method<void(cv::reg::Map::*)(cv::InputArray, cv::OutputArray) const>("inverse_warp", &cv::reg::Map::inverseWarp,
      Arg("img1"), Arg("img2")).
    define_method<cv::Ptr<cv::reg::Map>(cv::reg::Map::*)() const>("inverse_map", &cv::reg::Map::inverseMap).
    define_method<void(cv::reg::Map::*)(cv::Ptr<cv::reg::Map>)>("compose", &cv::reg::Map::compose,
      Arg("map")).
    define_method<void(cv::reg::Map::*)(double)>("scale", &cv::reg::Map::scale,
      Arg("factor"));
}
