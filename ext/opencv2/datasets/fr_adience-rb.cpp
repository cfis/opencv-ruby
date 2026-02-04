#include <opencv2/datasets/fr_adience.hpp>
#include "fr_adience-rb.hpp"

using namespace Rice;

void Init_Datasets_FrAdience()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvDatasets = define_module_under(rb_mCv, "Datasets");

  Enum<cv::datasets::genderType> rb_cCvDatasetsGenderType = define_enum_under<cv::datasets::genderType>("GenderType", rb_mCvDatasets).
    define_value("male", cv::datasets::genderType::male).
    define_value("female", cv::datasets::genderType::female).
    define_value("none", cv::datasets::genderType::none);

  Rice::Data_Type<cv::datasets::FR_adienceObj> rb_cCvDatasetsFRAdienceObj = define_class_under<cv::datasets::FR_adienceObj, cv::datasets::Object>(rb_mCvDatasets, "FRAdienceObj").
    define_constructor(Constructor<cv::datasets::FR_adienceObj>()).
    define_attr("user_id", &cv::datasets::FR_adienceObj::user_id).
    define_attr("original_image", &cv::datasets::FR_adienceObj::original_image).
    define_attr("face_id", &cv::datasets::FR_adienceObj::face_id).
    define_attr("age", &cv::datasets::FR_adienceObj::age).
    define_attr("gender", &cv::datasets::FR_adienceObj::gender).
    define_attr("x", &cv::datasets::FR_adienceObj::x).
    define_attr("y", &cv::datasets::FR_adienceObj::y).
    define_attr("dx", &cv::datasets::FR_adienceObj::dx).
    define_attr("dy", &cv::datasets::FR_adienceObj::dy).
    define_attr("tilt_ang", &cv::datasets::FR_adienceObj::tilt_ang).
    define_attr("fiducial_yaw_angle", &cv::datasets::FR_adienceObj::fiducial_yaw_angle).
    define_attr("fiducial_score", &cv::datasets::FR_adienceObj::fiducial_score);

  Rice::Data_Type<cv::datasets::FR_adience> rb_cCvDatasetsFRAdience = define_class_under<cv::datasets::FR_adience, cv::datasets::Dataset>(rb_mCvDatasets, "FRAdience").
    define_method<void(cv::datasets::FR_adience::*)(const std::string&)>("load", &cv::datasets::FR_adience::load,
      Arg("path")).
    define_singleton_function<cv::Ptr<cv::datasets::FR_adience>(*)()>("create", &cv::datasets::FR_adience::create).
    define_attr("paths", &cv::datasets::FR_adience::paths);
}