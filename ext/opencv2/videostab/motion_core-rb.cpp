#include <opencv2/videostab/motion_core.hpp>
#include "motion_core-rb.hpp"

using namespace Rice;

void Init_Videostab_MotionCore()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvVideostab = define_module_under(rb_mCv, "Videostab");

  Enum<cv::videostab::MotionModel> rb_cCvVideostabMotionModel = define_enum_under<cv::videostab::MotionModel>("MotionModel", rb_mCvVideostab).
    define_value("MM_TRANSLATION", cv::videostab::MotionModel::MM_TRANSLATION).
    define_value("MM_TRANSLATION_AND_SCALE", cv::videostab::MotionModel::MM_TRANSLATION_AND_SCALE).
    define_value("MM_ROTATION", cv::videostab::MotionModel::MM_ROTATION).
    define_value("MM_RIGID", cv::videostab::MotionModel::MM_RIGID).
    define_value("MM_SIMILARITY", cv::videostab::MotionModel::MM_SIMILARITY).
    define_value("MM_AFFINE", cv::videostab::MotionModel::MM_AFFINE).
    define_value("MM_HOMOGRAPHY", cv::videostab::MotionModel::MM_HOMOGRAPHY).
    define_value("MM_UNKNOWN", cv::videostab::MotionModel::MM_UNKNOWN);

  Rice::Data_Type<cv::videostab::RansacParams> rb_cCvVideostabRansacParams = define_class_under<cv::videostab::RansacParams>(rb_mCvVideostab, "RansacParams").
    define_attr("size", &cv::videostab::RansacParams::size).
    define_attr("thresh", &cv::videostab::RansacParams::thresh).
    define_attr("eps", &cv::videostab::RansacParams::eps).
    define_attr("prob", &cv::videostab::RansacParams::prob).
    define_constructor(Constructor<cv::videostab::RansacParams>()).
    define_constructor(Constructor<cv::videostab::RansacParams, int, float, float, float>(),
      Arg("size"), Arg("thresh"), Arg("eps"), Arg("prob")).
    define_method<int(cv::videostab::RansacParams::*)() const>("niters", &cv::videostab::RansacParams::niters).
    define_singleton_function<cv::videostab::RansacParams(*)(cv::videostab::MotionModel)>("default2d_motion", &cv::videostab::RansacParams::default2dMotion,
      Arg("model"));
}