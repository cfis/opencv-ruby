#include <opencv2/datasets/gr_skig.hpp>
#include "gr_skig-rb.hpp"

using namespace Rice;

void Init_Datasets_GrSkig()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvDatasets = define_module_under(rb_mCv, "Datasets");

  Enum<cv::datasets::actionType> rb_cCvDatasetsActionType = define_enum_under<cv::datasets::actionType>("ActionType", rb_mCvDatasets).
    define_value("circle", cv::datasets::actionType::circle).
    define_value("triangle", cv::datasets::actionType::triangle).
    define_value("updown", cv::datasets::actionType::updown).
    define_value("rightleft", cv::datasets::actionType::rightleft).
    define_value("wave", cv::datasets::actionType::wave).
    define_value("z", cv::datasets::actionType::z).
    define_value("cross", cv::datasets::actionType::cross).
    define_value("comehere", cv::datasets::actionType::comehere).
    define_value("turnaround", cv::datasets::actionType::turnaround).
    define_value("pat", cv::datasets::actionType::pat);

  Enum<cv::datasets::poseType> rb_cCvDatasetsPoseType = define_enum_under<cv::datasets::poseType>("PoseType", rb_mCvDatasets).
    define_value("fist", cv::datasets::poseType::fist).
    define_value("index", cv::datasets::poseType::index).
    define_value("flat", cv::datasets::poseType::flat);

  Enum<cv::datasets::illuminationType> rb_cCvDatasetsIlluminationType = define_enum_under<cv::datasets::illuminationType>("IlluminationType", rb_mCvDatasets).
    define_value("light", cv::datasets::illuminationType::light).
    define_value("dark", cv::datasets::illuminationType::dark);

  Enum<cv::datasets::backgroundType> rb_cCvDatasetsBackgroundType = define_enum_under<cv::datasets::backgroundType>("BackgroundType", rb_mCvDatasets).
    define_value("woodenBoard", cv::datasets::backgroundType::woodenBoard).
    define_value("whitePaper", cv::datasets::backgroundType::whitePaper).
    define_value("paperWithCharacters", cv::datasets::backgroundType::paperWithCharacters);

  Rice::Data_Type<cv::datasets::GR_skigObj> rb_cCvDatasetsGRSkigObj = define_class_under<cv::datasets::GR_skigObj, cv::datasets::Object>(rb_mCvDatasets, "GRSkigObj").
    define_constructor(Constructor<cv::datasets::GR_skigObj>()).
    define_attr("rgb", &cv::datasets::GR_skigObj::rgb).
    define_attr("dep", &cv::datasets::GR_skigObj::dep).
    define_attr("person", &cv::datasets::GR_skigObj::person).
    define_attr("background", &cv::datasets::GR_skigObj::background).
    define_attr("illumination", &cv::datasets::GR_skigObj::illumination).
    define_attr("pose", &cv::datasets::GR_skigObj::pose).
    define_attr("type", &cv::datasets::GR_skigObj::type);

  Rice::Data_Type<cv::datasets::GR_skig> rb_cCvDatasetsGRSkig = define_class_under<cv::datasets::GR_skig, cv::datasets::Dataset>(rb_mCvDatasets, "GRSkig").
    define_method<void(cv::datasets::GR_skig::*)(const std::string&)>("load", &cv::datasets::GR_skig::load,
      Arg("path")).
    define_singleton_function<cv::Ptr<cv::datasets::GR_skig>(*)()>("create", &cv::datasets::GR_skig::create);
}