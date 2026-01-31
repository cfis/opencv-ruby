#include <opencv2/reg/mappergradshift.hpp>
#include "mappergradshift-rb.hpp"

using namespace Rice;

void Init_Reg_Mappergradshift()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvReg = define_module_under(rb_mCv, "Reg");

  Rice::Data_Type<cv::reg::MapperGradShift> rb_cCvRegMapperGradShift = define_class_under<cv::reg::MapperGradShift, cv::reg::Mapper>(rb_mCvReg, "MapperGradShift").
    define_constructor(Constructor<cv::reg::MapperGradShift>()).
    define_method<cv::Ptr<cv::reg::Map>(cv::reg::MapperGradShift::*)(cv::InputArray, cv::InputArray, cv::Ptr<cv::reg::Map>) const>("calculate", &cv::reg::MapperGradShift::calculate,
      Arg("img1"), Arg("img2"), Arg("init") = static_cast<cv::Ptr<cv::reg::Map>>(cv::Ptr<cv::reg::Map>())).
    define_method<cv::Ptr<cv::reg::Map>(cv::reg::MapperGradShift::*)() const>("get_map", &cv::reg::MapperGradShift::getMap);
}