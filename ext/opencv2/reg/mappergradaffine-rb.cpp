#include <opencv2/reg/mappergradaffine.hpp>
#include "mappergradaffine-rb.hpp"

using namespace Rice;

void Init_Reg_Mappergradaffine()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvReg = define_module_under(rb_mCv, "Reg");

  Rice::Data_Type<cv::reg::MapperGradAffine> rb_cCvRegMapperGradAffine = define_class_under<cv::reg::MapperGradAffine, cv::reg::Mapper>(rb_mCvReg, "MapperGradAffine").
    define_constructor(Constructor<cv::reg::MapperGradAffine>()).
    define_method<cv::Ptr<cv::reg::Map>(cv::reg::MapperGradAffine::*)(cv::InputArray, cv::InputArray, cv::Ptr<cv::reg::Map>) const>("calculate", &cv::reg::MapperGradAffine::calculate,
      Arg("img1"), Arg("img2"), Arg("init") = static_cast<cv::Ptr<cv::reg::Map>>(cv::Ptr<cv::reg::Map>())).
    define_method<cv::Ptr<cv::reg::Map>(cv::reg::MapperGradAffine::*)() const>("get_map", &cv::reg::MapperGradAffine::getMap);
}
