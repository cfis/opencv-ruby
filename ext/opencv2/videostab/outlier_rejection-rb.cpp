#include <opencv2/videostab/outlier_rejection.hpp>
#include "outlier_rejection-rb.hpp"

using namespace Rice;

void Init_Videostab_OutlierRejection()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvVideostab = define_module_under(rb_mCv, "Videostab");

  Rice::Data_Type<cv::videostab::IOutlierRejector> rb_cCvVideostabIOutlierRejector = define_class_under<cv::videostab::IOutlierRejector>(rb_mCvVideostab, "IOutlierRejector").
    define_method<void(cv::videostab::IOutlierRejector::*)(cv::Size, cv::InputArray, cv::InputArray, cv::OutputArray)>("process", &cv::videostab::IOutlierRejector::process,
      Arg("frame_size"), Arg("points0"), Arg("points1"), Arg("mask"));

  Rice::Data_Type<cv::videostab::NullOutlierRejector> rb_cCvVideostabNullOutlierRejector = define_class_under<cv::videostab::NullOutlierRejector, cv::videostab::IOutlierRejector>(rb_mCvVideostab, "NullOutlierRejector").
    define_constructor(Constructor<cv::videostab::NullOutlierRejector>()).
    define_method<void(cv::videostab::NullOutlierRejector::*)(cv::Size, cv::InputArray, cv::InputArray, cv::OutputArray)>("process", &cv::videostab::NullOutlierRejector::process,
      Arg("frame_size"), Arg("points0"), Arg("points1"), Arg("mask"));

  Rice::Data_Type<cv::videostab::TranslationBasedLocalOutlierRejector> rb_cCvVideostabTranslationBasedLocalOutlierRejector = define_class_under<cv::videostab::TranslationBasedLocalOutlierRejector, cv::videostab::IOutlierRejector>(rb_mCvVideostab, "TranslationBasedLocalOutlierRejector").
    define_constructor(Constructor<cv::videostab::TranslationBasedLocalOutlierRejector>()).
    define_method<void(cv::videostab::TranslationBasedLocalOutlierRejector::*)(cv::Size)>("set_cell_size", &cv::videostab::TranslationBasedLocalOutlierRejector::setCellSize,
      Arg("val")).
    define_method<cv::Size(cv::videostab::TranslationBasedLocalOutlierRejector::*)() const>("cell_size", &cv::videostab::TranslationBasedLocalOutlierRejector::cellSize).
    define_method<void(cv::videostab::TranslationBasedLocalOutlierRejector::*)(cv::videostab::RansacParams)>("set_ransac_params", &cv::videostab::TranslationBasedLocalOutlierRejector::setRansacParams,
      Arg("val")).
    define_method<cv::videostab::RansacParams(cv::videostab::TranslationBasedLocalOutlierRejector::*)() const>("ransac_params", &cv::videostab::TranslationBasedLocalOutlierRejector::ransacParams).
    define_method<void(cv::videostab::TranslationBasedLocalOutlierRejector::*)(cv::Size, cv::InputArray, cv::InputArray, cv::OutputArray)>("process", &cv::videostab::TranslationBasedLocalOutlierRejector::process,
      Arg("frame_size"), Arg("points0"), Arg("points1"), Arg("mask"));
}
