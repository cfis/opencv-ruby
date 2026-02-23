#include <opencv2/ccalib/randpattern.hpp>
#include "randpattern-rb.hpp"

using namespace Rice;

void Init_Ccalib_Randpattern()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvRandpattern = define_module_under(rb_mCv, "Randpattern");

  Rice::Data_Type<cv::randpattern::RandomPatternCornerFinder> rb_cCvRandpatternRandomPatternCornerFinder = define_class_under<cv::randpattern::RandomPatternCornerFinder>(rb_mCvRandpattern, "RandomPatternCornerFinder").
    define_constructor(Constructor<cv::randpattern::RandomPatternCornerFinder, float, float, int, int, int, int, cv::Ptr<cv::Feature2D>, cv::Ptr<cv::Feature2D>, cv::Ptr<cv::DescriptorMatcher>>(),
      Arg("pattern_width"), Arg("pattern_height"), Arg("nmini_match") = static_cast<int>(20), Arg("depth") = static_cast<int>(CV_32F), Arg("verbose") = static_cast<int>(0), Arg("show_extraction") = static_cast<int>(0), Arg("detector") = static_cast<cv::Ptr<cv::Feature2D>>(cv::AKAZE::create(cv::AKAZE::DescriptorType::DESCRIPTOR_MLDB, 0, 3, 0.005f)), Arg("descriptor") = static_cast<cv::Ptr<cv::Feature2D>>(cv::AKAZE::create(cv::AKAZE::DescriptorType::DESCRIPTOR_MLDB,0, 3, 0.005f)), Arg("matcher") = static_cast<cv::Ptr<cv::DescriptorMatcher>>(cv::DescriptorMatcher::create("BruteForce-L1"))).
    define_method<void(cv::randpattern::RandomPatternCornerFinder::*)(const cv::Mat&)>("load_pattern", &cv::randpattern::RandomPatternCornerFinder::loadPattern,
      Arg("pattern_image")).
    define_method<void(cv::randpattern::RandomPatternCornerFinder::*)(const cv::Mat&, const std::vector<cv::KeyPoint>&, const cv::Mat&)>("load_pattern", &cv::randpattern::RandomPatternCornerFinder::loadPattern,
      Arg("pattern_image"), Arg("pattern_key_points"), Arg("pattern_descriptors")).
    define_method<void(cv::randpattern::RandomPatternCornerFinder::*)(std::vector<cv::Mat>)>("compute_object_image_points", &cv::randpattern::RandomPatternCornerFinder::computeObjectImagePoints,
      Arg("input_images")).
    define_method<std::vector<cv::Mat>(cv::randpattern::RandomPatternCornerFinder::*)(cv::Mat)>("compute_object_image_points_for_single", &cv::randpattern::RandomPatternCornerFinder::computeObjectImagePointsForSingle,
      Arg("input_image")).
    define_method<const std::vector<cv::Mat>&(cv::randpattern::RandomPatternCornerFinder::*)()>("get_object_points", &cv::randpattern::RandomPatternCornerFinder::getObjectPoints).
    define_method<const std::vector<cv::Mat>&(cv::randpattern::RandomPatternCornerFinder::*)()>("get_image_points", &cv::randpattern::RandomPatternCornerFinder::getImagePoints);

  Rice::Data_Type<cv::randpattern::RandomPatternGenerator> rb_cCvRandpatternRandomPatternGenerator = define_class_under<cv::randpattern::RandomPatternGenerator>(rb_mCvRandpattern, "RandomPatternGenerator").
    define_constructor(Constructor<cv::randpattern::RandomPatternGenerator, int, int>(),
      Arg("image_width"), Arg("image_height")).
    define_method<void(cv::randpattern::RandomPatternGenerator::*)()>("generate_pattern", &cv::randpattern::RandomPatternGenerator::generatePattern).
    define_method<cv::Mat(cv::randpattern::RandomPatternGenerator::*)()>("get_pattern", &cv::randpattern::RandomPatternGenerator::getPattern);
}
