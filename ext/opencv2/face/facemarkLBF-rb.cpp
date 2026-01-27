#include <opencv2/face/facemarkLBF.hpp>
#include "facemarkLBF-rb.hpp"

using namespace Rice;

void Init_Face_FacemarkLBF()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvFace = define_module_under(rb_mCv, "Face");

  Rice::Data_Type<cv::face::FacemarkLBF> rb_cCvFaceFacemarkLBF = define_class_under<cv::face::FacemarkLBF, cv::face::FacemarkTrain>(rb_mCvFace, "FacemarkLBF").
    define_singleton_function("create", &cv::face::FacemarkLBF::create,
      Arg("parameters") = static_cast<const cv::face::FacemarkLBF::Params&>(cv::face::FacemarkLBF::Params()));

  Rice::Data_Type<cv::face::FacemarkLBF::Params> rb_cCvFaceFacemarkLBFParams = define_class_under<cv::face::FacemarkLBF::Params>(rb_cCvFaceFacemarkLBF, "Params").
    define_constructor(Constructor<cv::face::FacemarkLBF::Params>()).
    define_attr("shape_offset", &cv::face::FacemarkLBF::Params::shape_offset).
    define_attr("cascade_face", &cv::face::FacemarkLBF::Params::cascade_face).
    define_attr("verbose", &cv::face::FacemarkLBF::Params::verbose).
    define_attr("n_landmarks", &cv::face::FacemarkLBF::Params::n_landmarks).
    define_attr("init_shape_n", &cv::face::FacemarkLBF::Params::initShape_n).
    define_attr("stages_n", &cv::face::FacemarkLBF::Params::stages_n).
    define_attr("tree_n", &cv::face::FacemarkLBF::Params::tree_n).
    define_attr("tree_depth", &cv::face::FacemarkLBF::Params::tree_depth).
    define_attr("bagging_overlap", &cv::face::FacemarkLBF::Params::bagging_overlap).
    define_attr("model_filename", &cv::face::FacemarkLBF::Params::model_filename).
    define_attr("save_model", &cv::face::FacemarkLBF::Params::save_model).
    define_attr("seed", &cv::face::FacemarkLBF::Params::seed).
    define_attr("feats_m", &cv::face::FacemarkLBF::Params::feats_m).
    define_attr("radius_m", &cv::face::FacemarkLBF::Params::radius_m).
    define_attr("detect_roi", &cv::face::FacemarkLBF::Params::detectROI).
    define_method("read", &cv::face::FacemarkLBF::Params::read,
      Arg("arg_0")).
    define_method("write", &cv::face::FacemarkLBF::Params::write,
      Arg("arg_0"));
}