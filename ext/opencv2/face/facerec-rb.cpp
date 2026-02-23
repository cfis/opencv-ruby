#include <opencv2/face/facerec.hpp>
#include "facerec-rb.hpp"

using namespace Rice;

void Init_Face_Facerec()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvFace = define_module_under(rb_mCv, "Face");

  Rice::Data_Type<cv::face::BasicFaceRecognizer> rb_cCvFaceBasicFaceRecognizer = define_class_under<cv::face::BasicFaceRecognizer, cv::face::FaceRecognizer>(rb_mCvFace, "BasicFaceRecognizer").
    define_method<int(cv::face::BasicFaceRecognizer::*)() const>("get_num_components", &cv::face::BasicFaceRecognizer::getNumComponents).
    define_method<void(cv::face::BasicFaceRecognizer::*)(int)>("set_num_components", &cv::face::BasicFaceRecognizer::setNumComponents,
      Arg("val")).
    define_method<double(cv::face::BasicFaceRecognizer::*)() const>("get_threshold", &cv::face::BasicFaceRecognizer::getThreshold).
    define_method<void(cv::face::BasicFaceRecognizer::*)(double)>("set_threshold", &cv::face::BasicFaceRecognizer::setThreshold,
      Arg("val")).
    define_method<std::vector<cv::Mat>(cv::face::BasicFaceRecognizer::*)() const>("get_projections", &cv::face::BasicFaceRecognizer::getProjections).
    define_method<cv::Mat(cv::face::BasicFaceRecognizer::*)() const>("get_labels", &cv::face::BasicFaceRecognizer::getLabels).
    define_method<cv::Mat(cv::face::BasicFaceRecognizer::*)() const>("get_eigen_values", &cv::face::BasicFaceRecognizer::getEigenValues).
    define_method<cv::Mat(cv::face::BasicFaceRecognizer::*)() const>("get_eigen_vectors", &cv::face::BasicFaceRecognizer::getEigenVectors).
    define_method<cv::Mat(cv::face::BasicFaceRecognizer::*)() const>("get_mean", &cv::face::BasicFaceRecognizer::getMean).
    define_method<void(cv::face::BasicFaceRecognizer::*)(const cv::FileNode&)>("read", &cv::face::BasicFaceRecognizer::read,
      Arg("fn")).
    define_method<void(cv::face::BasicFaceRecognizer::*)(cv::FileStorage&) const>("write", &cv::face::BasicFaceRecognizer::write,
      Arg("fs")).
    define_method<bool(cv::face::BasicFaceRecognizer::*)() const>("empty?", &cv::face::BasicFaceRecognizer::empty);

  Rice::Data_Type<cv::face::EigenFaceRecognizer> rb_cCvFaceEigenFaceRecognizer = define_class_under<cv::face::EigenFaceRecognizer, cv::face::BasicFaceRecognizer>(rb_mCvFace, "EigenFaceRecognizer").
    define_singleton_function<cv::Ptr<cv::face::EigenFaceRecognizer>(*)(int, double)>("create", &cv::face::EigenFaceRecognizer::create,
      Arg("num_components") = static_cast<int>(0), Arg("threshold") = static_cast<double>(DBL_MAX));

  Rice::Data_Type<cv::face::FisherFaceRecognizer> rb_cCvFaceFisherFaceRecognizer = define_class_under<cv::face::FisherFaceRecognizer, cv::face::BasicFaceRecognizer>(rb_mCvFace, "FisherFaceRecognizer").
    define_singleton_function<cv::Ptr<cv::face::FisherFaceRecognizer>(*)(int, double)>("create", &cv::face::FisherFaceRecognizer::create,
      Arg("num_components") = static_cast<int>(0), Arg("threshold") = static_cast<double>(DBL_MAX));

  Rice::Data_Type<cv::face::LBPHFaceRecognizer> rb_cCvFaceLBPHFaceRecognizer = define_class_under<cv::face::LBPHFaceRecognizer, cv::face::FaceRecognizer>(rb_mCvFace, "LBPHFaceRecognizer").
    define_method<int(cv::face::LBPHFaceRecognizer::*)() const>("get_grid_x", &cv::face::LBPHFaceRecognizer::getGridX).
    define_method<void(cv::face::LBPHFaceRecognizer::*)(int)>("set_grid_x", &cv::face::LBPHFaceRecognizer::setGridX,
      Arg("val")).
    define_method<int(cv::face::LBPHFaceRecognizer::*)() const>("get_grid_y", &cv::face::LBPHFaceRecognizer::getGridY).
    define_method<void(cv::face::LBPHFaceRecognizer::*)(int)>("set_grid_y", &cv::face::LBPHFaceRecognizer::setGridY,
      Arg("val")).
    define_method<int(cv::face::LBPHFaceRecognizer::*)() const>("get_radius", &cv::face::LBPHFaceRecognizer::getRadius).
    define_method<void(cv::face::LBPHFaceRecognizer::*)(int)>("set_radius", &cv::face::LBPHFaceRecognizer::setRadius,
      Arg("val")).
    define_method<int(cv::face::LBPHFaceRecognizer::*)() const>("get_neighbors", &cv::face::LBPHFaceRecognizer::getNeighbors).
    define_method<void(cv::face::LBPHFaceRecognizer::*)(int)>("set_neighbors", &cv::face::LBPHFaceRecognizer::setNeighbors,
      Arg("val")).
    define_method<double(cv::face::LBPHFaceRecognizer::*)() const>("get_threshold", &cv::face::LBPHFaceRecognizer::getThreshold).
    define_method<void(cv::face::LBPHFaceRecognizer::*)(double)>("set_threshold", &cv::face::LBPHFaceRecognizer::setThreshold,
      Arg("val")).
    define_method<std::vector<cv::Mat>(cv::face::LBPHFaceRecognizer::*)() const>("get_histograms", &cv::face::LBPHFaceRecognizer::getHistograms).
    define_method<cv::Mat(cv::face::LBPHFaceRecognizer::*)() const>("get_labels", &cv::face::LBPHFaceRecognizer::getLabels).
    define_singleton_function<cv::Ptr<cv::face::LBPHFaceRecognizer>(*)(int, int, int, int, double)>("create", &cv::face::LBPHFaceRecognizer::create,
      Arg("radius") = static_cast<int>(1), Arg("neighbors") = static_cast<int>(8), Arg("grid_x") = static_cast<int>(8), Arg("grid_y") = static_cast<int>(8), Arg("threshold") = static_cast<double>(DBL_MAX));
}
