#include <opencv2/line_descriptor/descriptor.hpp>
#include "descriptor-rb.hpp"

using namespace Rice;

void Init_LineDescriptor_Descriptor()
{
  Class(rb_cObject).define_constant("RELATIVE_ERROR_FACTOR", RELATIVE_ERROR_FACTOR);

  Class(rb_cObject).define_constant("MLN10", MLN10);

  Module rb_mCv = define_module("Cv");

  Module rb_mCvLineDescriptor = define_module_under(rb_mCv, "LineDescriptor");

  Rice::Data_Type<cv::line_descriptor::KeyLine> rb_cCvLineDescriptorKeyLine = define_class_under<cv::line_descriptor::KeyLine>(rb_mCvLineDescriptor, "KeyLine").
    define_attr("angle", &cv::line_descriptor::KeyLine::angle).
    define_attr("class_id", &cv::line_descriptor::KeyLine::class_id).
    define_attr("octave", &cv::line_descriptor::KeyLine::octave).
    define_attr("pt", &cv::line_descriptor::KeyLine::pt).
    define_attr("response", &cv::line_descriptor::KeyLine::response).
    define_attr("size", &cv::line_descriptor::KeyLine::size).
    define_attr("start_point_x", &cv::line_descriptor::KeyLine::startPointX).
    define_attr("start_point_y", &cv::line_descriptor::KeyLine::startPointY).
    define_attr("end_point_x", &cv::line_descriptor::KeyLine::endPointX).
    define_attr("end_point_y", &cv::line_descriptor::KeyLine::endPointY).
    define_attr("s_point_in_octave_x", &cv::line_descriptor::KeyLine::sPointInOctaveX).
    define_attr("s_point_in_octave_y", &cv::line_descriptor::KeyLine::sPointInOctaveY).
    define_attr("e_point_in_octave_x", &cv::line_descriptor::KeyLine::ePointInOctaveX).
    define_attr("e_point_in_octave_y", &cv::line_descriptor::KeyLine::ePointInOctaveY).
    define_attr("line_length", &cv::line_descriptor::KeyLine::lineLength).
    define_attr("num_of_pixels", &cv::line_descriptor::KeyLine::numOfPixels).
    define_method<cv::Point2f(cv::line_descriptor::KeyLine::*)() const>("get_start_point", &cv::line_descriptor::KeyLine::getStartPoint).
    define_method<cv::Point2f(cv::line_descriptor::KeyLine::*)() const>("get_end_point", &cv::line_descriptor::KeyLine::getEndPoint).
    define_method<cv::Point2f(cv::line_descriptor::KeyLine::*)() const>("get_start_point_in_octave", &cv::line_descriptor::KeyLine::getStartPointInOctave).
    define_method<cv::Point2f(cv::line_descriptor::KeyLine::*)() const>("get_end_point_in_octave", &cv::line_descriptor::KeyLine::getEndPointInOctave).
    define_constructor(Constructor<cv::line_descriptor::KeyLine>());

  Rice::Data_Type<cv::line_descriptor::BinaryDescriptor> rb_cCvLineDescriptorBinaryDescriptor = define_class_under<cv::line_descriptor::BinaryDescriptor, cv::Algorithm>(rb_mCvLineDescriptor, "BinaryDescriptor").
    define_constructor(Constructor<cv::line_descriptor::BinaryDescriptor, const cv::line_descriptor::BinaryDescriptor::Params&>(),
      Arg("parameters") = static_cast<const cv::line_descriptor::BinaryDescriptor::Params&>(cv::line_descriptor::BinaryDescriptor::Params())).
    define_method<int(cv::line_descriptor::BinaryDescriptor::*)()>("get_num_of_octaves", &cv::line_descriptor::BinaryDescriptor::getNumOfOctaves).
    define_method<void(cv::line_descriptor::BinaryDescriptor::*)(int)>("set_num_of_octaves", &cv::line_descriptor::BinaryDescriptor::setNumOfOctaves,
      Arg("octaves")).
    define_method<int(cv::line_descriptor::BinaryDescriptor::*)()>("get_width_of_band", &cv::line_descriptor::BinaryDescriptor::getWidthOfBand).
    define_method<void(cv::line_descriptor::BinaryDescriptor::*)(int)>("set_width_of_band", &cv::line_descriptor::BinaryDescriptor::setWidthOfBand,
      Arg("width")).
    define_method<int(cv::line_descriptor::BinaryDescriptor::*)()>("get_reduction_ratio", &cv::line_descriptor::BinaryDescriptor::getReductionRatio).
    define_method<void(cv::line_descriptor::BinaryDescriptor::*)(int)>("set_reduction_ratio", &cv::line_descriptor::BinaryDescriptor::setReductionRatio,
      Arg("r_ratio")).
    define_method<void(cv::line_descriptor::BinaryDescriptor::*)(const cv::FileNode&)>("read", &cv::line_descriptor::BinaryDescriptor::read,
      Arg("fn")).
    define_method<void(cv::line_descriptor::BinaryDescriptor::*)(cv::FileStorage&) const>("write", &cv::line_descriptor::BinaryDescriptor::write,
      Arg("fs")).
    define_method<void(cv::line_descriptor::BinaryDescriptor::*)(const cv::Mat&, std::vector<cv::line_descriptor::KeyLine>&, const cv::Mat&)>("detect", &cv::line_descriptor::BinaryDescriptor::detect,
      Arg("image"), Arg("keypoints"), Arg("mask") = static_cast<const cv::Mat&>(cv::Mat())).
    define_method<void(cv::line_descriptor::BinaryDescriptor::*)(const std::vector<cv::Mat>&, std::vector<std::vector<cv::line_descriptor::KeyLine>>&, const std::vector<cv::Mat>&) const>("detect", &cv::line_descriptor::BinaryDescriptor::detect,
      Arg("images"), Arg("keylines"), Arg("masks") = static_cast<const std::vector<cv::Mat>&>(std::vector<cv::Mat>())).
    define_method<void(cv::line_descriptor::BinaryDescriptor::*)(const cv::Mat&, std::vector<cv::line_descriptor::KeyLine>&, cv::Mat&, bool) const>("compute", &cv::line_descriptor::BinaryDescriptor::compute,
      Arg("image"), Arg("keylines"), Arg("descriptors"), Arg("return_float_descr") = static_cast<bool>(false)).
    define_method<void(cv::line_descriptor::BinaryDescriptor::*)(const std::vector<cv::Mat>&, std::vector<std::vector<cv::line_descriptor::KeyLine>>&, std::vector<cv::Mat>&, bool) const>("compute", &cv::line_descriptor::BinaryDescriptor::compute,
      Arg("images"), Arg("keylines"), Arg("descriptors"), Arg("return_float_descr") = static_cast<bool>(false)).
    define_method<int(cv::line_descriptor::BinaryDescriptor::*)() const>("descriptor_size", &cv::line_descriptor::BinaryDescriptor::descriptorSize).
    define_method<int(cv::line_descriptor::BinaryDescriptor::*)() const>("descriptor_type", &cv::line_descriptor::BinaryDescriptor::descriptorType).
    define_method<int(cv::line_descriptor::BinaryDescriptor::*)() const>("default_norm", &cv::line_descriptor::BinaryDescriptor::defaultNorm).
    define_method<void(cv::line_descriptor::BinaryDescriptor::*)(cv::InputArray, cv::InputArray, std::vector<cv::line_descriptor::KeyLine>&, cv::OutputArray, bool, bool) const>("call", &cv::line_descriptor::BinaryDescriptor::operator(),
      Arg("image"), Arg("mask"), Arg("keylines"), Arg("descriptors"), Arg("use_provided_key_lines") = static_cast<bool>(false), Arg("return_float_descr") = static_cast<bool>(false)).
    define_singleton_function<cv::Ptr<cv::line_descriptor::BinaryDescriptor>(*)()>("create_binary_descriptor", &cv::line_descriptor::BinaryDescriptor::createBinaryDescriptor).
    define_singleton_function<cv::Ptr<cv::line_descriptor::BinaryDescriptor>(*)(cv::line_descriptor::BinaryDescriptor::Params)>("create_binary_descriptor", &cv::line_descriptor::BinaryDescriptor::createBinaryDescriptor,
      Arg("parameters"));

  Rice::Data_Type<cv::line_descriptor::BinaryDescriptor::Params> rb_cCvLineDescriptorBinaryDescriptorParams = define_class_under<cv::line_descriptor::BinaryDescriptor::Params>(rb_cCvLineDescriptorBinaryDescriptor, "Params").
    define_constructor(Constructor<cv::line_descriptor::BinaryDescriptor::Params>()).
    define_attr("num_of_octave_", &cv::line_descriptor::BinaryDescriptor::Params::numOfOctave_).
    define_attr("width_of_band_", &cv::line_descriptor::BinaryDescriptor::Params::widthOfBand_).
    define_attr("reduction_ratio", &cv::line_descriptor::BinaryDescriptor::Params::reductionRatio).
    define_attr("ksize_", &cv::line_descriptor::BinaryDescriptor::Params::ksize_).
    define_method<void(cv::line_descriptor::BinaryDescriptor::Params::*)(const cv::FileNode&)>("read", &cv::line_descriptor::BinaryDescriptor::Params::read,
      Arg("fn")).
    define_method<void(cv::line_descriptor::BinaryDescriptor::Params::*)(cv::FileStorage&) const>("write", &cv::line_descriptor::BinaryDescriptor::Params::write,
      Arg("fs"));

  Rice::Data_Type<cv::line_descriptor::LSDParam> rb_cCvLineDescriptorLSDParam = define_class_under<cv::line_descriptor::LSDParam>(rb_mCvLineDescriptor, "LSDParam").
    define_attr("scale", &cv::line_descriptor::LSDParam::scale).
    define_attr("sigma_scale", &cv::line_descriptor::LSDParam::sigma_scale).
    define_attr("quant", &cv::line_descriptor::LSDParam::quant).
    define_attr("ang_th", &cv::line_descriptor::LSDParam::ang_th).
    define_attr("log_eps", &cv::line_descriptor::LSDParam::log_eps).
    define_attr("density_th", &cv::line_descriptor::LSDParam::density_th).
    define_attr("n_bins", &cv::line_descriptor::LSDParam::n_bins).
    define_constructor(Constructor<cv::line_descriptor::LSDParam>());

  Rice::Data_Type<cv::line_descriptor::LSDDetector> rb_cCvLineDescriptorLSDDetector = define_class_under<cv::line_descriptor::LSDDetector, cv::Algorithm>(rb_mCvLineDescriptor, "LSDDetector").
    define_constructor(Constructor<cv::line_descriptor::LSDDetector>()).
    define_constructor(Constructor<cv::line_descriptor::LSDDetector, cv::line_descriptor::LSDParam>(),
      Arg("_params")).
    define_method<void(cv::line_descriptor::LSDDetector::*)(const cv::Mat&, std::vector<cv::line_descriptor::KeyLine>&, int, int, const cv::Mat&)>("detect", &cv::line_descriptor::LSDDetector::detect,
      Arg("image"), Arg("keypoints"), Arg("scale"), Arg("num_octaves"), Arg("mask") = static_cast<const cv::Mat&>(cv::Mat())).
    define_method<void(cv::line_descriptor::LSDDetector::*)(const std::vector<cv::Mat>&, std::vector<std::vector<cv::line_descriptor::KeyLine>>&, int, int, const std::vector<cv::Mat>&) const>("detect", &cv::line_descriptor::LSDDetector::detect,
      Arg("images"), Arg("keylines"), Arg("scale"), Arg("num_octaves"), Arg("masks") = static_cast<const std::vector<cv::Mat>&>(std::vector<cv::Mat>())).
    define_singleton_function<cv::Ptr<cv::line_descriptor::LSDDetector>(*)()>("create_lsd_detector", &cv::line_descriptor::LSDDetector::createLSDDetector).
    define_singleton_function<cv::Ptr<cv::line_descriptor::LSDDetector>(*)(cv::line_descriptor::LSDParam)>("create_lsd_detector", &cv::line_descriptor::LSDDetector::createLSDDetector,
      Arg("params"));

  Rice::Data_Type<cv::line_descriptor::BinaryDescriptorMatcher> rb_cCvLineDescriptorBinaryDescriptorMatcher = define_class_under<cv::line_descriptor::BinaryDescriptorMatcher, cv::Algorithm>(rb_mCvLineDescriptor, "BinaryDescriptorMatcher").
    define_method<void(cv::line_descriptor::BinaryDescriptorMatcher::*)(const cv::Mat&, const cv::Mat&, std::vector<cv::DMatch>&, const cv::Mat&) const>("match", &cv::line_descriptor::BinaryDescriptorMatcher::match,
      Arg("query_descriptors"), Arg("train_descriptors"), Arg("matches"), Arg("mask") = static_cast<const cv::Mat&>(cv::Mat())).
    define_method<void(cv::line_descriptor::BinaryDescriptorMatcher::*)(const cv::Mat&, std::vector<cv::DMatch>&, const std::vector<cv::Mat>&)>("match", &cv::line_descriptor::BinaryDescriptorMatcher::match,
      Arg("query_descriptors"), Arg("matches"), Arg("masks") = static_cast<const std::vector<cv::Mat>&>(std::vector<cv::Mat>())).
    define_method<void(cv::line_descriptor::BinaryDescriptorMatcher::*)(const cv::Mat&, const cv::Mat&, std::vector<std::vector<cv::DMatch>>&, int, const cv::Mat&, bool) const>("knn_match", &cv::line_descriptor::BinaryDescriptorMatcher::knnMatch,
      Arg("query_descriptors"), Arg("train_descriptors"), Arg("matches"), Arg("k"), Arg("mask") = static_cast<const cv::Mat&>(cv::Mat()), Arg("compact_result") = static_cast<bool>(false)).
    define_method<void(cv::line_descriptor::BinaryDescriptorMatcher::*)(const cv::Mat&, std::vector<std::vector<cv::DMatch>>&, int, const std::vector<cv::Mat>&, bool)>("knn_match", &cv::line_descriptor::BinaryDescriptorMatcher::knnMatch,
      Arg("query_descriptors"), Arg("matches"), Arg("k"), Arg("masks") = static_cast<const std::vector<cv::Mat>&>(std::vector<cv::Mat>()), Arg("compact_result") = static_cast<bool>(false)).
    define_method<void(cv::line_descriptor::BinaryDescriptorMatcher::*)(const cv::Mat&, const cv::Mat&, std::vector<std::vector<cv::DMatch>>&, float, const cv::Mat&, bool) const>("radius_match", &cv::line_descriptor::BinaryDescriptorMatcher::radiusMatch,
      Arg("query_descriptors"), Arg("train_descriptors"), Arg("matches"), Arg("max_distance"), Arg("mask") = static_cast<const cv::Mat&>(cv::Mat()), Arg("compact_result") = static_cast<bool>(false)).
    define_method<void(cv::line_descriptor::BinaryDescriptorMatcher::*)(const cv::Mat&, std::vector<std::vector<cv::DMatch>>&, float, const std::vector<cv::Mat>&, bool)>("radius_match", &cv::line_descriptor::BinaryDescriptorMatcher::radiusMatch,
      Arg("query_descriptors"), Arg("matches"), Arg("max_distance"), Arg("masks") = static_cast<const std::vector<cv::Mat>&>(std::vector<cv::Mat>()), Arg("compact_result") = static_cast<bool>(false)).
    define_method<void(cv::line_descriptor::BinaryDescriptorMatcher::*)(const std::vector<cv::Mat>&)>("add", &cv::line_descriptor::BinaryDescriptorMatcher::add,
      Arg("descriptors")).
    define_method<void(cv::line_descriptor::BinaryDescriptorMatcher::*)()>("train", &cv::line_descriptor::BinaryDescriptorMatcher::train).
    define_method<void(cv::line_descriptor::BinaryDescriptorMatcher::*)()>("clear", &cv::line_descriptor::BinaryDescriptorMatcher::clear).
    define_constructor(Constructor<cv::line_descriptor::BinaryDescriptorMatcher>()).
    define_singleton_function<cv::Ptr<cv::line_descriptor::BinaryDescriptorMatcher>(*)()>("create_binary_descriptor_matcher", &cv::line_descriptor::BinaryDescriptorMatcher::createBinaryDescriptorMatcher);

  Rice::Data_Type<cv::line_descriptor::DrawLinesMatchesFlags> rb_cCvLineDescriptorDrawLinesMatchesFlags = define_class_under<cv::line_descriptor::DrawLinesMatchesFlags>(rb_mCvLineDescriptor, "DrawLinesMatchesFlags").
    define_constructor(Constructor<cv::line_descriptor::DrawLinesMatchesFlags>());

  rb_cCvLineDescriptorDrawLinesMatchesFlags.define_constant("DEFAULT", (int)cv::line_descriptor::DrawLinesMatchesFlags::DEFAULT);
  rb_cCvLineDescriptorDrawLinesMatchesFlags.define_constant("DRAW_OVER_OUTIMG", (int)cv::line_descriptor::DrawLinesMatchesFlags::DRAW_OVER_OUTIMG);
  rb_cCvLineDescriptorDrawLinesMatchesFlags.define_constant("NOT_DRAW_SINGLE_LINES", (int)cv::line_descriptor::DrawLinesMatchesFlags::NOT_DRAW_SINGLE_LINES);

  rb_mCvLineDescriptor.define_module_function<void(*)(const cv::Mat&, const std::vector<cv::line_descriptor::KeyLine>&, const cv::Mat&, const std::vector<cv::line_descriptor::KeyLine>&, const std::vector<cv::DMatch>&, cv::Mat&, const cv::Scalar&, const cv::Scalar&, const std::vector<char>&, int)>("draw_line_matches", &cv::line_descriptor::drawLineMatches,
    Arg("img1"), Arg("keylines1"), Arg("img2"), Arg("keylines2"), Arg("matches1to2"), Arg("out_img"), Arg("match_color") = static_cast<const cv::Scalar&>(cv::Scalar::all( -1 )), Arg("single_line_color") = static_cast<const cv::Scalar&>(cv::Scalar::all( -1 )), Arg("matches_mask") = static_cast<const std::vector<char>&>(std::vector<char>()), Arg("flags") = static_cast<int>(cv::line_descriptor::DrawLinesMatchesFlags::DEFAULT));

  rb_mCvLineDescriptor.define_module_function<void(*)(const cv::Mat&, const std::vector<cv::line_descriptor::KeyLine>&, cv::Mat&, const cv::Scalar&, int)>("draw_keylines", &cv::line_descriptor::drawKeylines,
    Arg("image"), Arg("keylines"), Arg("out_image"), Arg("color") = static_cast<const cv::Scalar&>(cv::Scalar::all( -1 )), Arg("flags") = static_cast<int>(cv::line_descriptor::DrawLinesMatchesFlags::DEFAULT));
}