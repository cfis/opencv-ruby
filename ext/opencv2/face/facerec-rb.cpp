#include <opencv2/face/facerec.hpp>
#include "facerec-rb.hpp"

using namespace Rice;

void Init_Face_Facerec()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvFace = define_module_under(rb_mCv, "Face");

  Rice::Data_Type<cv::face::BasicFaceRecognizer> rb_cCvFaceBasicFaceRecognizer = define_class_under<cv::face::BasicFaceRecognizer, cv::face::FaceRecognizer>(rb_mCvFace, "BasicFaceRecognizer").
    define_method("get_num_components", &cv::face::BasicFaceRecognizer::getNumComponents).
    define_method("set_num_components", &cv::face::BasicFaceRecognizer::setNumComponents,
      Arg("val")).
    define_method("get_threshold", &cv::face::BasicFaceRecognizer::getThreshold).
    define_method("set_threshold", &cv::face::BasicFaceRecognizer::setThreshold,
      Arg("val")).
    define_method("get_projections", &cv::face::BasicFaceRecognizer::getProjections).
    define_method("get_labels", &cv::face::BasicFaceRecognizer::getLabels).
    define_method("get_eigen_values", &cv::face::BasicFaceRecognizer::getEigenValues).
    define_method("get_eigen_vectors", &cv::face::BasicFaceRecognizer::getEigenVectors).
    define_method("get_mean", &cv::face::BasicFaceRecognizer::getMean).
    define_method<void(cv::face::BasicFaceRecognizer::*)(const cv::FileNode&)>("read", &cv::face::BasicFaceRecognizer::read,
      Arg("fn")).
    define_method<void(cv::face::BasicFaceRecognizer::*)(cv::FileStorage&) const>("write", &cv::face::BasicFaceRecognizer::write,
      Arg("fs")).
    define_method("empty?", &cv::face::BasicFaceRecognizer::empty);

  Rice::Data_Type<cv::face::EigenFaceRecognizer> rb_cCvFaceEigenFaceRecognizer = define_class_under<cv::face::EigenFaceRecognizer, cv::face::BasicFaceRecognizer>(rb_mCvFace, "EigenFaceRecognizer").
    define_singleton_function("create", &cv::face::EigenFaceRecognizer::create,
      Arg("num_components") = static_cast<int>(0), Arg("threshold") = static_cast<double>(DBL_MAX));

  Rice::Data_Type<cv::face::FisherFaceRecognizer> rb_cCvFaceFisherFaceRecognizer = define_class_under<cv::face::FisherFaceRecognizer, cv::face::BasicFaceRecognizer>(rb_mCvFace, "FisherFaceRecognizer").
    define_singleton_function("create", &cv::face::FisherFaceRecognizer::create,
      Arg("num_components") = static_cast<int>(0), Arg("threshold") = static_cast<double>(DBL_MAX));

  Rice::Data_Type<cv::face::LBPHFaceRecognizer> rb_cCvFaceLBPHFaceRecognizer = define_class_under<cv::face::LBPHFaceRecognizer, cv::face::FaceRecognizer>(rb_mCvFace, "LBPHFaceRecognizer").
    define_method("get_grid_x", &cv::face::LBPHFaceRecognizer::getGridX).
    define_method("set_grid_x", &cv::face::LBPHFaceRecognizer::setGridX,
      Arg("val")).
    define_method("get_grid_y", &cv::face::LBPHFaceRecognizer::getGridY).
    define_method("set_grid_y", &cv::face::LBPHFaceRecognizer::setGridY,
      Arg("val")).
    define_method("get_radius", &cv::face::LBPHFaceRecognizer::getRadius).
    define_method("set_radius", &cv::face::LBPHFaceRecognizer::setRadius,
      Arg("val")).
    define_method("get_neighbors", &cv::face::LBPHFaceRecognizer::getNeighbors).
    define_method("set_neighbors", &cv::face::LBPHFaceRecognizer::setNeighbors,
      Arg("val")).
    define_method("get_threshold", &cv::face::LBPHFaceRecognizer::getThreshold).
    define_method("set_threshold", &cv::face::LBPHFaceRecognizer::setThreshold,
      Arg("val")).
    define_method("get_histograms", &cv::face::LBPHFaceRecognizer::getHistograms).
    define_method("get_labels", &cv::face::LBPHFaceRecognizer::getLabels).
    define_singleton_function("create", &cv::face::LBPHFaceRecognizer::create,
      Arg("radius") = static_cast<int>(1), Arg("neighbors") = static_cast<int>(8), Arg("grid_x") = static_cast<int>(8), Arg("grid_y") = static_cast<int>(8), Arg("threshold") = static_cast<double>(DBL_MAX));
}