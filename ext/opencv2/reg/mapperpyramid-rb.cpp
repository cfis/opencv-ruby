#include <opencv2/reg/mapperpyramid.hpp>
#include "mapperpyramid-rb.hpp"

using namespace Rice;

void Init_Reg_Mapperpyramid()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvReg = define_module_under(rb_mCv, "Reg");

  Rice::Data_Type<cv::reg::MapperPyramid> rb_cCvRegMapperPyramid = define_class_under<cv::reg::MapperPyramid, cv::reg::Mapper>(rb_mCvReg, "MapperPyramid").
    define_constructor(Constructor<cv::reg::MapperPyramid, cv::Ptr<cv::reg::Mapper>>(),
      Arg("base_mapper")).
    define_method<cv::Ptr<cv::reg::Map>(cv::reg::MapperPyramid::*)(cv::InputArray, cv::InputArray, cv::Ptr<cv::reg::Map>) const>("calculate", &cv::reg::MapperPyramid::calculate,
      Arg("img1"), Arg("img2"), Arg("init") = static_cast<cv::Ptr<cv::reg::Map>>(cv::Ptr<cv::reg::Map>())).
    define_method<cv::Ptr<cv::reg::Map>(cv::reg::MapperPyramid::*)() const>("get_map", &cv::reg::MapperPyramid::getMap).
    define_attr("num_lev_", &cv::reg::MapperPyramid::numLev_).
    define_attr("num_iter_per_scale_", &cv::reg::MapperPyramid::numIterPerScale_);

  Rice::Data_Type<cv::reg::MapTypeCaster> rb_cCvRegMapTypeCaster = define_class_under<cv::reg::MapTypeCaster>(rb_mCvReg, "MapTypeCaster").
    define_constructor(Constructor<cv::reg::MapTypeCaster>()).
    define_singleton_function<cv::Ptr<cv::reg::MapAffine>(*)(cv::Ptr<cv::reg::Map>)>("to_affine", &cv::reg::MapTypeCaster::toAffine,
      Arg("source_map")).
    define_singleton_function<cv::Ptr<cv::reg::MapShift>(*)(cv::Ptr<cv::reg::Map>)>("to_shift", &cv::reg::MapTypeCaster::toShift,
      Arg("source_map")).
    define_singleton_function<cv::Ptr<cv::reg::MapProjec>(*)(cv::Ptr<cv::reg::Map>)>("to_projec", &cv::reg::MapTypeCaster::toProjec,
      Arg("source_map"));
}
