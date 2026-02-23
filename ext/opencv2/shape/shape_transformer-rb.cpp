#include <opencv2/shape/shape_transformer.hpp>
#include "shape_transformer-rb.hpp"

using namespace Rice;

void Init_Shape_ShapeTransformer()
{
  Module rb_mCv = define_module("Cv");

  Rice::Data_Type<cv::ShapeTransformer> rb_cCvShapeTransformer = define_class_under<cv::ShapeTransformer, cv::Algorithm>(rb_mCv, "ShapeTransformer").
    define_method<void(cv::ShapeTransformer::*)(cv::InputArray, cv::InputArray, std::vector<cv::DMatch>&)>("estimate_transformation", &cv::ShapeTransformer::estimateTransformation,
      Arg("transforming_shape"), Arg("target_shape"), Arg("matches")).
    define_method<float(cv::ShapeTransformer::*)(cv::InputArray, cv::OutputArray)>("apply_transformation", &cv::ShapeTransformer::applyTransformation,
      Arg("input"), Arg("output") = static_cast<cv::OutputArray>(cv::noArray())).
    define_method<void(cv::ShapeTransformer::*)(cv::InputArray, cv::OutputArray, int, int, const cv::Scalar&) const>("warp_image", &cv::ShapeTransformer::warpImage,
      Arg("transforming_image"), Arg("output"), Arg("flags") = static_cast<int>(cv::INTER_LINEAR), Arg("border_mode") = static_cast<int>(cv::BORDER_CONSTANT), Arg("border_value") = static_cast<const cv::Scalar&>(cv::Scalar()));

  Rice::Data_Type<cv::ThinPlateSplineShapeTransformer> rb_cCvThinPlateSplineShapeTransformer = define_class_under<cv::ThinPlateSplineShapeTransformer, cv::ShapeTransformer>(rb_mCv, "ThinPlateSplineShapeTransformer").
    define_method<void(cv::ThinPlateSplineShapeTransformer::*)(double)>("set_regularization_parameter", &cv::ThinPlateSplineShapeTransformer::setRegularizationParameter,
      Arg("beta")).
    define_method<double(cv::ThinPlateSplineShapeTransformer::*)() const>("get_regularization_parameter", &cv::ThinPlateSplineShapeTransformer::getRegularizationParameter);

  rb_mCv.define_module_function<cv::Ptr<cv::ThinPlateSplineShapeTransformer>(*)(double)>("create_thin_plate_spline_shape_transformer", &cv::createThinPlateSplineShapeTransformer,
    Arg("regularization_parameter") = static_cast<double>(0));

  Rice::Data_Type<cv::AffineTransformer> rb_cCvAffineTransformer = define_class_under<cv::AffineTransformer, cv::ShapeTransformer>(rb_mCv, "AffineTransformer").
    define_method<void(cv::AffineTransformer::*)(bool)>("set_full_affine", &cv::AffineTransformer::setFullAffine,
      Arg("full_affine")).
    define_method<bool(cv::AffineTransformer::*)() const>("get_full_affine?", &cv::AffineTransformer::getFullAffine);

  rb_mCv.define_module_function<cv::Ptr<cv::AffineTransformer>(*)(bool)>("create_affine_transformer", &cv::createAffineTransformer,
    Arg("full_affine"));
}
