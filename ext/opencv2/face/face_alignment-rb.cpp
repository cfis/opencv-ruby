#include <opencv2/face/face_alignment.hpp>
#include "face_alignment-rb.hpp"

using namespace Rice;

void Init_Face_FaceAlignment()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvFace = define_module_under(rb_mCv, "Face");

  Rice::Data_Type<cv::face::FacemarkKazemi> rb_cCvFaceFacemarkKazemi = define_class_under<cv::face::FacemarkKazemi, cv::face::Facemark>(rb_mCvFace, "FacemarkKazemi").
    define_singleton_function<cv::Ptr<cv::face::FacemarkKazemi>(*)(const cv::face::FacemarkKazemi::Params&)>("create", &cv::face::FacemarkKazemi::create,
      Arg("parameters") = static_cast<const cv::face::FacemarkKazemi::Params&>(cv::face::FacemarkKazemi::Params())).
    define_method<bool(cv::face::FacemarkKazemi::*)(std::vector<cv::Mat>&, std::vector<std::vector<cv::Point_<float>>>&, std::string, cv::Size, std::string)>("training", &cv::face::FacemarkKazemi::training,
      Arg("images"), Arg("landmarks"), Arg("configfile"), Arg("scale"), Arg("model_filename") = static_cast<std::string>("face_landmarks.dat")).
    define_method<bool(cv::face::FacemarkKazemi::*)(bool (*)(cv::InputArray, cv::OutputArray, void*), void*)>("set_face_detector", &cv::face::FacemarkKazemi::setFaceDetector,
      Arg("f"), ArgBuffer("user_data")).
    define_method<bool(cv::face::FacemarkKazemi::*)(cv::InputArray, cv::OutputArray)>("get_faces", &cv::face::FacemarkKazemi::getFaces,
      Arg("image"), Arg("faces"));

  Rice::Data_Type<cv::face::FacemarkKazemi::Params> rb_cCvFaceFacemarkKazemiParams = define_class_under<cv::face::FacemarkKazemi::Params>(rb_cCvFaceFacemarkKazemi, "Params").
    define_constructor(Constructor<cv::face::FacemarkKazemi::Params>()).
    define_attr("cascade_depth", &cv::face::FacemarkKazemi::Params::cascade_depth).
    define_attr("tree_depth", &cv::face::FacemarkKazemi::Params::tree_depth).
    define_attr("num_trees_per_cascade_level", &cv::face::FacemarkKazemi::Params::num_trees_per_cascade_level).
    define_attr("learning_rate", &cv::face::FacemarkKazemi::Params::learning_rate).
    define_attr("oversampling_amount", &cv::face::FacemarkKazemi::Params::oversampling_amount).
    define_attr("num_test_coordinates", &cv::face::FacemarkKazemi::Params::num_test_coordinates).
    define_attr("lambda", &cv::face::FacemarkKazemi::Params::lambda).
    define_attr("num_test_splits", &cv::face::FacemarkKazemi::Params::num_test_splits).
    define_attr("configfile", &cv::face::FacemarkKazemi::Params::configfile);
}
