#include <opencv2/face/facemark.hpp>
#include "facemark-rb.hpp"

using namespace Rice;

void Init_Face_Facemark()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvFace = define_module_under(rb_mCv, "Face");

  Rice::Data_Type<cv::face::Facemark> rb_cCvFaceFacemark = define_class_under<cv::face::Facemark, cv::Algorithm>(rb_mCvFace, "Facemark").
    define_method<void(cv::face::Facemark::*)(cv::String)>("load_model", &cv::face::Facemark::loadModel,
      Arg("model")).
    define_method<bool(cv::face::Facemark::*)(cv::InputArray, cv::InputArray, cv::OutputArrayOfArrays)>("fit", &cv::face::Facemark::fit,
      Arg("image"), Arg("faces"), Arg("landmarks"));

  rb_mCvFace.define_module_function<cv::Ptr<cv::face::Facemark>(*)()>("create_facemark_aam", &cv::face::createFacemarkAAM);

  rb_mCvFace.define_module_function<cv::Ptr<cv::face::Facemark>(*)()>("create_facemark_lbf", &cv::face::createFacemarkLBF);

  rb_mCvFace.define_module_function<cv::Ptr<cv::face::Facemark>(*)()>("create_facemark_kazemi", &cv::face::createFacemarkKazemi);
}
