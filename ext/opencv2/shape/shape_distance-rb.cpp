#include <opencv2/shape/shape_distance.hpp>
#include "shape_distance-rb.hpp"

using namespace Rice;

void Init_Shape_ShapeDistance()
{
  Module rb_mCv = define_module("Cv");

  Rice::Data_Type<cv::ShapeDistanceExtractor> rb_cCvShapeDistanceExtractor = define_class_under<cv::ShapeDistanceExtractor, cv::Algorithm>(rb_mCv, "ShapeDistanceExtractor").
    define_method<float(cv::ShapeDistanceExtractor::*)(cv::InputArray, cv::InputArray)>("compute_distance", &cv::ShapeDistanceExtractor::computeDistance,
      Arg("contour1"), Arg("contour2"));

  Rice::Data_Type<cv::ShapeContextDistanceExtractor> rb_cCvShapeContextDistanceExtractor = define_class_under<cv::ShapeContextDistanceExtractor, cv::ShapeDistanceExtractor>(rb_mCv, "ShapeContextDistanceExtractor").
    define_method<void(cv::ShapeContextDistanceExtractor::*)(int)>("set_angular_bins", &cv::ShapeContextDistanceExtractor::setAngularBins,
      Arg("n_angular_bins")).
    define_method<int(cv::ShapeContextDistanceExtractor::*)() const>("get_angular_bins", &cv::ShapeContextDistanceExtractor::getAngularBins).
    define_method<void(cv::ShapeContextDistanceExtractor::*)(int)>("set_radial_bins", &cv::ShapeContextDistanceExtractor::setRadialBins,
      Arg("n_radial_bins")).
    define_method<int(cv::ShapeContextDistanceExtractor::*)() const>("get_radial_bins", &cv::ShapeContextDistanceExtractor::getRadialBins).
    define_method<void(cv::ShapeContextDistanceExtractor::*)(float)>("set_inner_radius", &cv::ShapeContextDistanceExtractor::setInnerRadius,
      Arg("inner_radius")).
    define_method<float(cv::ShapeContextDistanceExtractor::*)() const>("get_inner_radius", &cv::ShapeContextDistanceExtractor::getInnerRadius).
    define_method<void(cv::ShapeContextDistanceExtractor::*)(float)>("set_outer_radius", &cv::ShapeContextDistanceExtractor::setOuterRadius,
      Arg("outer_radius")).
    define_method<float(cv::ShapeContextDistanceExtractor::*)() const>("get_outer_radius", &cv::ShapeContextDistanceExtractor::getOuterRadius).
    define_method<void(cv::ShapeContextDistanceExtractor::*)(bool)>("set_rotation_invariant", &cv::ShapeContextDistanceExtractor::setRotationInvariant,
      Arg("rotation_invariant")).
    define_method<bool(cv::ShapeContextDistanceExtractor::*)() const>("get_rotation_invariant?", &cv::ShapeContextDistanceExtractor::getRotationInvariant).
    define_method<void(cv::ShapeContextDistanceExtractor::*)(float)>("set_shape_context_weight", &cv::ShapeContextDistanceExtractor::setShapeContextWeight,
      Arg("shape_context_weight")).
    define_method<float(cv::ShapeContextDistanceExtractor::*)() const>("get_shape_context_weight", &cv::ShapeContextDistanceExtractor::getShapeContextWeight).
    define_method<void(cv::ShapeContextDistanceExtractor::*)(float)>("set_image_appearance_weight", &cv::ShapeContextDistanceExtractor::setImageAppearanceWeight,
      Arg("image_appearance_weight")).
    define_method<float(cv::ShapeContextDistanceExtractor::*)() const>("get_image_appearance_weight", &cv::ShapeContextDistanceExtractor::getImageAppearanceWeight).
    define_method<void(cv::ShapeContextDistanceExtractor::*)(float)>("set_bending_energy_weight", &cv::ShapeContextDistanceExtractor::setBendingEnergyWeight,
      Arg("bending_energy_weight")).
    define_method<float(cv::ShapeContextDistanceExtractor::*)() const>("get_bending_energy_weight", &cv::ShapeContextDistanceExtractor::getBendingEnergyWeight).
    define_method<void(cv::ShapeContextDistanceExtractor::*)(cv::InputArray, cv::InputArray)>("set_images", &cv::ShapeContextDistanceExtractor::setImages,
      Arg("image1"), Arg("image2")).
    define_method<void(cv::ShapeContextDistanceExtractor::*)(cv::OutputArray, cv::OutputArray) const>("get_images", &cv::ShapeContextDistanceExtractor::getImages,
      Arg("image1"), Arg("image2")).
    define_method<void(cv::ShapeContextDistanceExtractor::*)(int)>("set_iterations", &cv::ShapeContextDistanceExtractor::setIterations,
      Arg("iterations")).
    define_method<int(cv::ShapeContextDistanceExtractor::*)() const>("get_iterations", &cv::ShapeContextDistanceExtractor::getIterations).
    define_method<void(cv::ShapeContextDistanceExtractor::*)(cv::Ptr<cv::HistogramCostExtractor>)>("set_cost_extractor", &cv::ShapeContextDistanceExtractor::setCostExtractor,
      Arg("comparer")).
    define_method<cv::Ptr<cv::HistogramCostExtractor>(cv::ShapeContextDistanceExtractor::*)() const>("get_cost_extractor", &cv::ShapeContextDistanceExtractor::getCostExtractor).
    define_method<void(cv::ShapeContextDistanceExtractor::*)(float)>("set_std_dev", &cv::ShapeContextDistanceExtractor::setStdDev,
      Arg("sigma")).
    define_method<float(cv::ShapeContextDistanceExtractor::*)() const>("get_std_dev", &cv::ShapeContextDistanceExtractor::getStdDev).
    define_method<void(cv::ShapeContextDistanceExtractor::*)(cv::Ptr<cv::ShapeTransformer>)>("set_transform_algorithm", &cv::ShapeContextDistanceExtractor::setTransformAlgorithm,
      Arg("transformer")).
    define_method<cv::Ptr<cv::ShapeTransformer>(cv::ShapeContextDistanceExtractor::*)() const>("get_transform_algorithm", &cv::ShapeContextDistanceExtractor::getTransformAlgorithm);

  rb_mCv.define_module_function<cv::Ptr<cv::ShapeContextDistanceExtractor>(*)(int, int, float, float, int, const cv::Ptr<cv::HistogramCostExtractor>&, const cv::Ptr<cv::ShapeTransformer>&)>("create_shape_context_distance_extractor", &cv::createShapeContextDistanceExtractor,
    Arg("n_angular_bins") = static_cast<int>(12), Arg("n_radial_bins") = static_cast<int>(4), Arg("inner_radius") = static_cast<float>(0.2f), Arg("outer_radius") = static_cast<float>(2), Arg("iterations") = static_cast<int>(3), Arg("comparer") = static_cast<const cv::Ptr<cv::HistogramCostExtractor>&>(cv::createChiHistogramCostExtractor()), Arg("transformer") = static_cast<const cv::Ptr<cv::ShapeTransformer>&>(cv::createThinPlateSplineShapeTransformer()));

  Rice::Data_Type<cv::HausdorffDistanceExtractor> rb_cCvHausdorffDistanceExtractor = define_class_under<cv::HausdorffDistanceExtractor, cv::ShapeDistanceExtractor>(rb_mCv, "HausdorffDistanceExtractor").
    define_method<void(cv::HausdorffDistanceExtractor::*)(int)>("set_distance_flag", &cv::HausdorffDistanceExtractor::setDistanceFlag,
      Arg("distance_flag")).
    define_method<int(cv::HausdorffDistanceExtractor::*)() const>("get_distance_flag", &cv::HausdorffDistanceExtractor::getDistanceFlag).
    define_method<void(cv::HausdorffDistanceExtractor::*)(float)>("set_rank_proportion", &cv::HausdorffDistanceExtractor::setRankProportion,
      Arg("rank_proportion")).
    define_method<float(cv::HausdorffDistanceExtractor::*)() const>("get_rank_proportion", &cv::HausdorffDistanceExtractor::getRankProportion);

  rb_mCv.define_module_function<cv::Ptr<cv::HausdorffDistanceExtractor>(*)(int, float)>("create_hausdorff_distance_extractor", &cv::createHausdorffDistanceExtractor,
    Arg("distance_flag") = static_cast<int>(cv::NORM_L2), Arg("rank_prop") = static_cast<float>(0.6f));
}
