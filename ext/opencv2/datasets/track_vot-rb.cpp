#include <opencv2/datasets/track_vot.hpp>
#include "track_vot-rb.hpp"

using namespace Rice;

void Init_Datasets_TrackVot()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvDatasets = define_module_under(rb_mCv, "Datasets");

  Rice::Data_Type<cv::datasets::TRACK_votObj> rb_cCvDatasetsTRACKVotObj = define_class_under<cv::datasets::TRACK_votObj, cv::datasets::Object>(rb_mCvDatasets, "TRACKVotObj").
    define_constructor(Constructor<cv::datasets::TRACK_votObj>()).
    define_attr("id", &cv::datasets::TRACK_votObj::id).
    define_attr("image_path", &cv::datasets::TRACK_votObj::imagePath).
    define_attr("gtbb", &cv::datasets::TRACK_votObj::gtbb);

  Rice::Data_Type<cv::datasets::TRACK_vot> rb_cCvDatasetsTRACKVot = define_class_under<cv::datasets::TRACK_vot, cv::datasets::Dataset>(rb_mCvDatasets, "TRACKVot").
    define_method<void(cv::datasets::TRACK_vot::*)(const std::string&)>("load", &cv::datasets::TRACK_vot::load,
      Arg("path")).
    define_method<int(cv::datasets::TRACK_vot::*)()>("get_datasets_num", &cv::datasets::TRACK_vot::getDatasetsNum).
    define_method<int(cv::datasets::TRACK_vot::*)(int)>("get_dataset_length", &cv::datasets::TRACK_vot::getDatasetLength,
      Arg("id")).
    define_method<bool(cv::datasets::TRACK_vot::*)(int)>("init_dataset", &cv::datasets::TRACK_vot::initDataset,
      Arg("id")).
    define_method<bool(cv::datasets::TRACK_vot::*)(cv::Mat&)>("get_next_frame", &cv::datasets::TRACK_vot::getNextFrame,
      Arg("frame")).
    define_method<std::vector<cv::Point_<double>>(cv::datasets::TRACK_vot::*)()>("get_gt", &cv::datasets::TRACK_vot::getGT).
    define_singleton_function<cv::Ptr<cv::datasets::TRACK_vot>(*)()>("create", &cv::datasets::TRACK_vot::create);
}