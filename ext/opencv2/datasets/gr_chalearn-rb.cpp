#include <opencv2/datasets/gr_chalearn.hpp>
#include "gr_chalearn-rb.hpp"

using namespace Rice;

void Init_Datasets_GrChalearn()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvDatasets = define_module_under(rb_mCv, "Datasets");

  Rice::Data_Type<cv::datasets::groundTruth> rb_cCvDatasetsGroundTruth = define_class_under<cv::datasets::groundTruth>(rb_mCvDatasets, "GroundTruth").
    define_constructor(Constructor<cv::datasets::groundTruth>()).
    define_attr("gesture_id", &cv::datasets::groundTruth::gestureID).
    define_attr("initial_frame", &cv::datasets::groundTruth::initialFrame).
    define_attr("last_frame", &cv::datasets::groundTruth::lastFrame);

  Rice::Data_Type<cv::datasets::join> rb_cCvDatasetsJoin = define_class_under<cv::datasets::join>(rb_mCvDatasets, "Join").
    define_constructor(Constructor<cv::datasets::join>()).
    define_attr("wx", &cv::datasets::join::Wx).
    define_attr("wy", &cv::datasets::join::Wy).
    define_attr("wz", &cv::datasets::join::Wz).
    define_attr("rx", &cv::datasets::join::Rx).
    define_attr("ry", &cv::datasets::join::Ry).
    define_attr("rz", &cv::datasets::join::Rz).
    define_attr("rw", &cv::datasets::join::Rw).
    define_attr("px", &cv::datasets::join::Px).
    define_attr("py", &cv::datasets::join::Py);

  Rice::Data_Type<cv::datasets::skeleton> rb_cCvDatasetsSkeleton = define_class_under<cv::datasets::skeleton>(rb_mCvDatasets, "Skeleton").
    define_constructor(Constructor<cv::datasets::skeleton>()).
    define_attr("s", &cv::datasets::skeleton::s, Rice::AttrAccess::Read);

  Rice::Data_Type<cv::datasets::GR_chalearnObj> rb_cCvDatasetsGRChalearnObj = define_class_under<cv::datasets::GR_chalearnObj, cv::datasets::Object>(rb_mCvDatasets, "GRChalearnObj").
    define_constructor(Constructor<cv::datasets::GR_chalearnObj>()).
    define_attr("name", &cv::datasets::GR_chalearnObj::name).
    define_attr("name_color", &cv::datasets::GR_chalearnObj::nameColor).
    define_attr("name_depth", &cv::datasets::GR_chalearnObj::nameDepth).
    define_attr("name_user", &cv::datasets::GR_chalearnObj::nameUser).
    define_attr("num_frames", &cv::datasets::GR_chalearnObj::numFrames).
    define_attr("fps", &cv::datasets::GR_chalearnObj::fps).
    define_attr("depth", &cv::datasets::GR_chalearnObj::depth).
    define_attr("ground_truths", &cv::datasets::GR_chalearnObj::groundTruths).
    define_attr("skeletons", &cv::datasets::GR_chalearnObj::skeletons);

  Rice::Data_Type<cv::datasets::GR_chalearn> rb_cCvDatasetsGRChalearn = define_class_under<cv::datasets::GR_chalearn, cv::datasets::Dataset>(rb_mCvDatasets, "GRChalearn").
    define_method<void(cv::datasets::GR_chalearn::*)(const std::string&)>("load", &cv::datasets::GR_chalearn::load,
      Arg("path")).
    define_singleton_function<cv::Ptr<cv::datasets::GR_chalearn>(*)()>("create", &cv::datasets::GR_chalearn::create);
}
