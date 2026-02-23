#include <opencv2/ccalib/multicalib.hpp>
#include "multicalib-rb.hpp"

using namespace Rice;

void Init_Ccalib_Multicalib()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvMulticalib = define_module_under(rb_mCv, "Multicalib");

  Rice::Data_Type<cv::multicalib::MultiCameraCalibration> rb_cCvMulticalibMultiCameraCalibration = define_class_under<cv::multicalib::MultiCameraCalibration>(rb_mCvMulticalib, "MultiCameraCalibration").
    define_constructor(Constructor<cv::multicalib::MultiCameraCalibration, int, int, const std::string&, float, float, int, int, int, int, cv::TermCriteria, cv::Ptr<cv::Feature2D>, cv::Ptr<cv::Feature2D>, cv::Ptr<cv::DescriptorMatcher>>(),
      Arg("camera_type"), Arg("n_cameras"), Arg("file_name"), Arg("pattern_width"), Arg("pattern_height"), Arg("verbose") = static_cast<int>(0), Arg("show_extration") = static_cast<int>(0), Arg("n_mini_matches") = static_cast<int>(20), Arg("flags") = static_cast<int>(0), Arg("criteria") = static_cast<cv::TermCriteria>(cv::TermCriteria(cv::TermCriteria::Type::COUNT + cv::TermCriteria::Type::EPS, 200, 1e-7)), Arg("detector") = static_cast<cv::Ptr<cv::Feature2D>>(cv::AKAZE::create(cv::AKAZE::DescriptorType::DESCRIPTOR_MLDB, 0, 3, 0.006f)), Arg("descriptor") = static_cast<cv::Ptr<cv::Feature2D>>(cv::AKAZE::create(cv::AKAZE::DescriptorType::DESCRIPTOR_MLDB,0, 3, 0.006f)), Arg("matcher") = static_cast<cv::Ptr<cv::DescriptorMatcher>>(cv::DescriptorMatcher::create("BruteForce-L1"))).
    define_method<void(cv::multicalib::MultiCameraCalibration::*)()>("load_images", &cv::multicalib::MultiCameraCalibration::loadImages).
    define_method<void(cv::multicalib::MultiCameraCalibration::*)()>("initialize", &cv::multicalib::MultiCameraCalibration::initialize).
    define_method<double(cv::multicalib::MultiCameraCalibration::*)()>("optimize_extrinsics", &cv::multicalib::MultiCameraCalibration::optimizeExtrinsics).
    define_method<double(cv::multicalib::MultiCameraCalibration::*)()>("run", &cv::multicalib::MultiCameraCalibration::run).
    define_method<void(cv::multicalib::MultiCameraCalibration::*)(const std::string&)>("write_parameters", &cv::multicalib::MultiCameraCalibration::writeParameters,
      Arg("filename"));

  Rice::Data_Type<cv::multicalib::MultiCameraCalibration::edge> rb_cCvMulticalibMultiCameraCalibrationEdge = define_class_under<cv::multicalib::MultiCameraCalibration::edge>(rb_cCvMulticalibMultiCameraCalibration, "Edge").
    define_attr("camera_vertex", &cv::multicalib::MultiCameraCalibration::edge::cameraVertex).
    define_attr("photo_vertex", &cv::multicalib::MultiCameraCalibration::edge::photoVertex).
    define_attr("photo_index", &cv::multicalib::MultiCameraCalibration::edge::photoIndex).
    define_attr("transform", &cv::multicalib::MultiCameraCalibration::edge::transform).
    define_constructor(Constructor<cv::multicalib::MultiCameraCalibration::edge, int, int, int, cv::Mat>(),
      Arg("cv"), Arg("pv"), Arg("pi"), Arg("trans"));

  Rice::Data_Type<cv::multicalib::MultiCameraCalibration::vertex> rb_cCvMulticalibMultiCameraCalibrationVertex = define_class_under<cv::multicalib::MultiCameraCalibration::vertex>(rb_cCvMulticalibMultiCameraCalibration, "Vertex").
    define_attr("pose", &cv::multicalib::MultiCameraCalibration::vertex::pose).
    define_attr("timestamp", &cv::multicalib::MultiCameraCalibration::vertex::timestamp).
    define_constructor(Constructor<cv::multicalib::MultiCameraCalibration::vertex, cv::Mat, int>(),
      Arg("po"), Arg("ts")).
    define_constructor(Constructor<cv::multicalib::MultiCameraCalibration::vertex>());

  rb_cCvMulticalibMultiCameraCalibration.define_constant("PINHOLE", (int)cv::multicalib::MultiCameraCalibration::PINHOLE);
  rb_cCvMulticalibMultiCameraCalibration.define_constant("OMNIDIRECTIONAL", (int)cv::multicalib::MultiCameraCalibration::OMNIDIRECTIONAL);
}
