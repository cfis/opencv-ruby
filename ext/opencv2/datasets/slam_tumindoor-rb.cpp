#include <opencv2/datasets/slam_tumindoor.hpp>
#include "slam_tumindoor-rb.hpp"

using namespace Rice;

void Init_Datasets_SlamTumindoor()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvDatasets = define_module_under(rb_mCv, "Datasets");

  Enum<cv::datasets::imageType> rb_cCvDatasetsImageType = define_enum_under<cv::datasets::imageType>("ImageType", rb_mCvDatasets).
    define_value("LEFT", cv::datasets::imageType::LEFT).
    define_value("RIGHT", cv::datasets::imageType::RIGHT).
    define_value("LADYBUG", cv::datasets::imageType::LADYBUG);

  Rice::Data_Type<cv::datasets::SLAM_tumindoorObj> rb_cCvDatasetsSLAMTumindoorObj = define_class_under<cv::datasets::SLAM_tumindoorObj, cv::datasets::Object>(rb_mCvDatasets, "SLAMTumindoorObj").
    define_constructor(Constructor<cv::datasets::SLAM_tumindoorObj>()).
    define_attr("name", &cv::datasets::SLAM_tumindoorObj::name).
    define_attr("transform_mat", &cv::datasets::SLAM_tumindoorObj::transformMat).
    define_attr("type", &cv::datasets::SLAM_tumindoorObj::type);

  Rice::Data_Type<cv::datasets::SLAM_tumindoor> rb_cCvDatasetsSLAMTumindoor = define_class_under<cv::datasets::SLAM_tumindoor, cv::datasets::Dataset>(rb_mCvDatasets, "SLAMTumindoor").
    define_method<void(cv::datasets::SLAM_tumindoor::*)(const std::string&)>("load", &cv::datasets::SLAM_tumindoor::load,
      Arg("path")).
    define_singleton_function<cv::Ptr<cv::datasets::SLAM_tumindoor>(*)()>("create", &cv::datasets::SLAM_tumindoor::create);
}