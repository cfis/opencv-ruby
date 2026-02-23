#include <opencv2/reg/mappergradeuclid.hpp>
#include "mappergradeuclid-rb.hpp"

using namespace Rice;

void Init_Reg_Mappergradeuclid()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvReg = define_module_under(rb_mCv, "Reg");

  Rice::Data_Type<cv::reg::MapperGradEuclid> rb_cCvRegMapperGradEuclid = define_class_under<cv::reg::MapperGradEuclid, cv::reg::Mapper>(rb_mCvReg, "MapperGradEuclid").
    define_constructor(Constructor<cv::reg::MapperGradEuclid>()).
    define_method<cv::Ptr<cv::reg::Map>(cv::reg::MapperGradEuclid::*)(cv::InputArray, cv::InputArray, cv::Ptr<cv::reg::Map>) const>("calculate", &cv::reg::MapperGradEuclid::calculate,
      Arg("img1"), Arg("img2"), Arg("init") = static_cast<cv::Ptr<cv::reg::Map>>(cv::Ptr<cv::reg::Map>())).
    define_method<cv::Ptr<cv::reg::Map>(cv::reg::MapperGradEuclid::*)() const>("get_map", &cv::reg::MapperGradEuclid::getMap);
}
