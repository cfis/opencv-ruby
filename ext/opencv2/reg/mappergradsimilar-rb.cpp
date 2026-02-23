#include <opencv2/reg/mappergradsimilar.hpp>
#include "mappergradsimilar-rb.hpp"

using namespace Rice;

void Init_Reg_Mappergradsimilar()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvReg = define_module_under(rb_mCv, "Reg");

  Rice::Data_Type<cv::reg::MapperGradSimilar> rb_cCvRegMapperGradSimilar = define_class_under<cv::reg::MapperGradSimilar, cv::reg::Mapper>(rb_mCvReg, "MapperGradSimilar").
    define_constructor(Constructor<cv::reg::MapperGradSimilar>()).
    define_method<cv::Ptr<cv::reg::Map>(cv::reg::MapperGradSimilar::*)(cv::InputArray, cv::InputArray, cv::Ptr<cv::reg::Map>) const>("calculate", &cv::reg::MapperGradSimilar::calculate,
      Arg("img1"), Arg("img2"), Arg("init") = static_cast<cv::Ptr<cv::reg::Map>>(cv::Ptr<cv::reg::Map>())).
    define_method<cv::Ptr<cv::reg::Map>(cv::reg::MapperGradSimilar::*)() const>("get_map", &cv::reg::MapperGradSimilar::getMap);
}
