#include <opencv2/reg/mapprojec.hpp>
#include "mapprojec-rb.hpp"

using namespace Rice;

void Init_Reg_Mapprojec()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvReg = define_module_under(rb_mCv, "Reg");

  Rice::Data_Type<cv::reg::MapProjec> rb_cCvRegMapProjec = define_class_under<cv::reg::MapProjec, cv::reg::Map>(rb_mCvReg, "MapProjec").
    define_constructor(Constructor<cv::reg::MapProjec>()).
    define_constructor(Constructor<cv::reg::MapProjec, cv::InputArray>(),
      Arg("proj_tr")).
    define_method<void(cv::reg::MapProjec::*)(cv::InputArray, cv::OutputArray) const>("inverse_warp", &cv::reg::MapProjec::inverseWarp,
      Arg("img1"), Arg("img2")).
    define_method<cv::Ptr<cv::reg::Map>(cv::reg::MapProjec::*)() const>("inverse_map", &cv::reg::MapProjec::inverseMap).
    define_method<void(cv::reg::MapProjec::*)(cv::Ptr<cv::reg::Map>)>("compose", &cv::reg::MapProjec::compose,
      Arg("map")).
    define_method<void(cv::reg::MapProjec::*)(double)>("scale", &cv::reg::MapProjec::scale,
      Arg("factor")).
    define_method<const cv::Matx<double, 3, 3>&(cv::reg::MapProjec::*)() const>("get_proj_tr", &cv::reg::MapProjec::getProjTr).
    define_method<void(cv::reg::MapProjec::*)(cv::OutputArray) const>("get_proj_tr", &cv::reg::MapProjec::getProjTr,
      Arg("proj_tr")).
    define_method<void(cv::reg::MapProjec::*)()>("normalize", &cv::reg::MapProjec::normalize);
}
