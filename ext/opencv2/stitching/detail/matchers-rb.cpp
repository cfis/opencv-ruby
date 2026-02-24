#include <opencv2/stitching/detail/matchers.hpp>
#include "matchers-rb.hpp"

using namespace Rice;

void Init_Stitching_Detail_Matchers()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvDetail = define_module_under(rb_mCv, "Detail");

  Rice::Data_Type<cv::detail::ImageFeatures> rb_cCvDetailImageFeatures = define_class_under<cv::detail::ImageFeatures>(rb_mCvDetail, "ImageFeatures").
    define_constructor(Constructor<cv::detail::ImageFeatures>()).
    define_attr("img_idx", &cv::detail::ImageFeatures::img_idx).
    define_attr("img_size", &cv::detail::ImageFeatures::img_size).
    define_attr("keypoints", &cv::detail::ImageFeatures::keypoints).
    define_attr("descriptors", &cv::detail::ImageFeatures::descriptors).
    define_method<std::vector<cv::KeyPoint>(cv::detail::ImageFeatures::*)()>("get_keypoints", &cv::detail::ImageFeatures::getKeypoints);

  rb_mCvDetail.define_module_function<void(*)(const cv::Ptr<cv::Feature2D>&, cv::InputArrayOfArrays, std::vector<cv::detail::ImageFeatures>&, cv::InputArrayOfArrays)>("compute_image_features", &cv::detail::computeImageFeatures,
    Arg("features_finder"), Arg("images"), Arg("features"), Arg("masks") = static_cast<cv::InputArrayOfArrays>(cv::noArray()));

  rb_mCvDetail.define_module_function<void(*)(const cv::Ptr<cv::Feature2D>&, cv::InputArray, cv::detail::ImageFeatures&, cv::InputArray)>("compute_image_features", &cv::detail::computeImageFeatures,
    Arg("features_finder"), Arg("image"), Arg("features"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()));

  Rice::Data_Type<cv::detail::MatchesInfo> rb_cCvDetailMatchesInfo = define_class_under<cv::detail::MatchesInfo>(rb_mCvDetail, "MatchesInfo").
    define_constructor(Constructor<cv::detail::MatchesInfo>()).
    define_constructor(Constructor<cv::detail::MatchesInfo, const cv::detail::MatchesInfo&>(),
      Arg("other")).
    define_method<cv::detail::MatchesInfo&(cv::detail::MatchesInfo::*)(const cv::detail::MatchesInfo&)>("assign", &cv::detail::MatchesInfo::operator=,
      Arg("other")).
    define_attr("src_img_idx", &cv::detail::MatchesInfo::src_img_idx).
    define_attr("dst_img_idx", &cv::detail::MatchesInfo::dst_img_idx).
    define_attr("matches", &cv::detail::MatchesInfo::matches).
    define_attr("inliers_mask", &cv::detail::MatchesInfo::inliers_mask).
    define_attr("num_inliers", &cv::detail::MatchesInfo::num_inliers).
    define_attr("h", &cv::detail::MatchesInfo::H).
    define_attr("confidence", &cv::detail::MatchesInfo::confidence).
    define_method<std::vector<cv::DMatch>(cv::detail::MatchesInfo::*)()>("get_matches", &cv::detail::MatchesInfo::getMatches).
    define_method<std::vector<uchar>(cv::detail::MatchesInfo::*)()>("get_inliers", &cv::detail::MatchesInfo::getInliers);

  Rice::Data_Type<cv::detail::FeaturesMatcher> rb_cCvDetailFeaturesMatcher = define_class_under<cv::detail::FeaturesMatcher>(rb_mCvDetail, "FeaturesMatcher").
    define_method<void(cv::detail::FeaturesMatcher::*)(const cv::detail::ImageFeatures&, const cv::detail::ImageFeatures&, cv::detail::MatchesInfo&)>("call", &cv::detail::FeaturesMatcher::operator(),
      Arg("features1"), Arg("features2"), Arg("matches_info")).
    define_method<void(cv::detail::FeaturesMatcher::*)(const std::vector<cv::detail::ImageFeatures>&, std::vector<cv::detail::MatchesInfo>&, const cv::UMat&)>("call", &cv::detail::FeaturesMatcher::operator(),
      Arg("features"), Arg("pairwise_matches"), Arg("mask") = static_cast<const cv::UMat&>(cv::UMat())).
    define_method<bool(cv::detail::FeaturesMatcher::*)() const>("thread_safe?", &cv::detail::FeaturesMatcher::isThreadSafe).
    define_method<void(cv::detail::FeaturesMatcher::*)()>("collect_garbage", &cv::detail::FeaturesMatcher::collectGarbage);

  Rice::Data_Type<cv::detail::BestOf2NearestMatcher> rb_cCvDetailBestOf2NearestMatcher = define_class_under<cv::detail::BestOf2NearestMatcher, cv::detail::FeaturesMatcher>(rb_mCvDetail, "BestOf2NearestMatcher").
#if RUBY_CV_VERSION >= 407
    define_constructor(Constructor<cv::detail::BestOf2NearestMatcher, bool, float, int, int, double>(),
      Arg("try_use_gpu") = static_cast<bool>(false), Arg("match_conf") = static_cast<float>(0.3f), Arg("num_matches_thresh1") = static_cast<int>(6), Arg("num_matches_thresh2") = static_cast<int>(6), Arg("matches_confindece_thresh") = static_cast<double>(3.)).
#endif
    define_method<void(cv::detail::BestOf2NearestMatcher::*)()>("collect_garbage", &cv::detail::BestOf2NearestMatcher::collectGarbage).
    define_singleton_function<cv::Ptr<cv::detail::BestOf2NearestMatcher>(*)(bool, float, int, int, double)>("create", &cv::detail::BestOf2NearestMatcher::create,
      Arg("try_use_gpu") = static_cast<bool>(false), Arg("match_conf") = static_cast<float>(0.3f), Arg("num_matches_thresh1") = static_cast<int>(6), Arg("num_matches_thresh2") = static_cast<int>(6), Arg("matches_confindece_thresh") = static_cast<double>(3.));

  Rice::Data_Type<cv::detail::BestOf2NearestRangeMatcher> rb_cCvDetailBestOf2NearestRangeMatcher = define_class_under<cv::detail::BestOf2NearestRangeMatcher, cv::detail::BestOf2NearestMatcher>(rb_mCvDetail, "BestOf2NearestRangeMatcher").
    define_constructor(Constructor<cv::detail::BestOf2NearestRangeMatcher, int, bool, float, int, int>(),
      Arg("range_width") = static_cast<int>(5), Arg("try_use_gpu") = static_cast<bool>(false), Arg("match_conf") = static_cast<float>(0.3f), Arg("num_matches_thresh1") = static_cast<int>(6), Arg("num_matches_thresh2") = static_cast<int>(6));

  Rice::Data_Type<cv::detail::AffineBestOf2NearestMatcher> rb_cCvDetailAffineBestOf2NearestMatcher = define_class_under<cv::detail::AffineBestOf2NearestMatcher, cv::detail::BestOf2NearestMatcher>(rb_mCvDetail, "AffineBestOf2NearestMatcher").
    define_constructor(Constructor<cv::detail::AffineBestOf2NearestMatcher, bool, bool, float, int>(),
      Arg("full_affine") = static_cast<bool>(false), Arg("try_use_gpu") = static_cast<bool>(false), Arg("match_conf") = static_cast<float>(0.3f), Arg("num_matches_thresh1") = static_cast<int>(6));
}
