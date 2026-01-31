#include <opencv2/datasets/track_alov.hpp>
#include "track_alov-rb.hpp"

using namespace Rice;

void Init_Datasets_TrackAlov()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvDatasets = define_module_under(rb_mCv, "Datasets");

  Rice::Data_Type<cv::datasets::TRACK_alovObj> rb_cCvDatasetsTRACKAlovObj = define_class_under<cv::datasets::TRACK_alovObj, cv::datasets::Object>(rb_mCvDatasets, "TRACKAlovObj").
    define_constructor(Constructor<cv::datasets::TRACK_alovObj>()).
    define_attr("id", &cv::datasets::TRACK_alovObj::id).
    define_attr("image_path", &cv::datasets::TRACK_alovObj::imagePath).
    define_attr("gtbb", &cv::datasets::TRACK_alovObj::gtbb);

  rb_mCvDatasets.define_constant("SectionNames", cv::datasets::sectionNames);

  rb_mCvDatasets.define_constant("SectionSizes", cv::datasets::sectionSizes);

  Rice::Data_Type<cv::datasets::TRACK_alov> rb_cCvDatasetsTRACKAlov = define_class_under<cv::datasets::TRACK_alov, cv::datasets::Dataset>(rb_mCvDatasets, "TRACKAlov").
    define_method<void(cv::datasets::TRACK_alov::*)(const std::string&)>("load", &cv::datasets::TRACK_alov::load,
      Arg("path")).
    define_method<void(cv::datasets::TRACK_alov::*)(const std::string&)>("load_annotated_only", &cv::datasets::TRACK_alov::loadAnnotatedOnly,
      Arg("path")).
    define_method<int(cv::datasets::TRACK_alov::*)()>("get_datasets_num", &cv::datasets::TRACK_alov::getDatasetsNum).
    define_method<int(cv::datasets::TRACK_alov::*)(int)>("get_dataset_length", &cv::datasets::TRACK_alov::getDatasetLength,
      Arg("id")).
    define_method<bool(cv::datasets::TRACK_alov::*)(int)>("init_dataset", &cv::datasets::TRACK_alov::initDataset,
      Arg("id")).
    define_method<bool(cv::datasets::TRACK_alov::*)(cv::Mat&)>("get_next_frame", &cv::datasets::TRACK_alov::getNextFrame,
      Arg("frame")).
    define_method<std::vector<cv::Point_<float>>(cv::datasets::TRACK_alov::*)()>("get_next_gt", &cv::datasets::TRACK_alov::getNextGT).
    define_method<bool(cv::datasets::TRACK_alov::*)(cv::Mat&, int, int)>("get_frame", &cv::datasets::TRACK_alov::getFrame,
      Arg("frame"), Arg("dataset_id"), Arg("frame_id")).
    define_method<std::vector<cv::Point_<float>>(cv::datasets::TRACK_alov::*)(int, int)>("get_gt", &cv::datasets::TRACK_alov::getGT,
      Arg("dataset_id"), Arg("frame_id")).
    define_singleton_function<cv::Ptr<cv::datasets::TRACK_alov>(*)()>("create", &cv::datasets::TRACK_alov::create);
}