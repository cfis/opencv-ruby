#include <opencv2/reg/mappergradproj.hpp>
#include "mappergradproj-rb.hpp"

using namespace Rice;

void Init_Reg_Mappergradproj()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvReg = define_module_under(rb_mCv, "Reg");

  Rice::Data_Type<cv::reg::MapperGradProj> rb_cCvRegMapperGradProj = define_class_under<cv::reg::MapperGradProj, cv::reg::Mapper>(rb_mCvReg, "MapperGradProj").
    define_constructor(Constructor<cv::reg::MapperGradProj>()).
    define_method<cv::Ptr<cv::reg::Map>(cv::reg::MapperGradProj::*)(cv::InputArray, cv::InputArray, cv::Ptr<cv::reg::Map>) const>("calculate", &cv::reg::MapperGradProj::calculate,
      Arg("img1"), Arg("img2"), Arg("init") = static_cast<cv::Ptr<cv::reg::Map>>(cv::Ptr<cv::reg::Map>())).
    define_method<cv::Ptr<cv::reg::Map>(cv::reg::MapperGradProj::*)() const>("get_map", &cv::reg::MapperGradProj::getMap);
}