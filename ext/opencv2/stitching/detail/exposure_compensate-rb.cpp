#include <opencv2/stitching/detail/exposure_compensate.hpp>
#include "exposure_compensate-rb.hpp"

using namespace Rice;

void Init_Stitching_Detail_ExposureCompensate()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvDetail = define_module_under(rb_mCv, "Detail");

  Rice::Data_Type<cv::detail::ExposureCompensator> rb_cCvDetailExposureCompensator = define_class_under<cv::detail::ExposureCompensator>(rb_mCvDetail, "ExposureCompensator").
    define_singleton_function<cv::Ptr<cv::detail::ExposureCompensator>(*)(int)>("create_default", &cv::detail::ExposureCompensator::createDefault,
      Arg("type")).
    define_method<void(cv::detail::ExposureCompensator::*)(const std::vector<cv::Point_<int>>&, const std::vector<cv::UMat>&, const std::vector<cv::UMat>&)>("feed", &cv::detail::ExposureCompensator::feed,
      Arg("corners"), Arg("images"), Arg("masks")).
    define_method<void(cv::detail::ExposureCompensator::*)(const std::vector<cv::Point_<int>>&, const std::vector<cv::UMat>&, const std::vector<std::pair<cv::UMat, unsigned char>>&)>("feed", &cv::detail::ExposureCompensator::feed,
      Arg("corners"), Arg("images"), Arg("masks")).
    define_method<void(cv::detail::ExposureCompensator::*)(int, cv::Point, cv::InputOutputArray, cv::InputArray)>("apply", &cv::detail::ExposureCompensator::apply,
      Arg("index"), Arg("corner"), Arg("image"), Arg("mask")).
    define_method<void(cv::detail::ExposureCompensator::*)(std::vector<cv::Mat>&)>("get_mat_gains", &cv::detail::ExposureCompensator::getMatGains,
      Arg("arg_0")).
    define_method<void(cv::detail::ExposureCompensator::*)(std::vector<cv::Mat>&)>("set_mat_gains", &cv::detail::ExposureCompensator::setMatGains,
      Arg("arg_0")).
    define_method<void(cv::detail::ExposureCompensator::*)(bool)>("set_update_gain", &cv::detail::ExposureCompensator::setUpdateGain,
      Arg("b")).
    define_method<bool(cv::detail::ExposureCompensator::*)()>("get_update_gain?", &cv::detail::ExposureCompensator::getUpdateGain);

  rb_cCvDetailExposureCompensator.define_constant("NO", (int)cv::detail::ExposureCompensator::NO);
  rb_cCvDetailExposureCompensator.define_constant("GAIN", (int)cv::detail::ExposureCompensator::GAIN);
  rb_cCvDetailExposureCompensator.define_constant("GAIN_BLOCKS", (int)cv::detail::ExposureCompensator::GAIN_BLOCKS);
  rb_cCvDetailExposureCompensator.define_constant("CHANNELS", (int)cv::detail::ExposureCompensator::CHANNELS);
  rb_cCvDetailExposureCompensator.define_constant("CHANNELS_BLOCKS", (int)cv::detail::ExposureCompensator::CHANNELS_BLOCKS);

  Rice::Data_Type<cv::detail::NoExposureCompensator> rb_cCvDetailNoExposureCompensator = define_class_under<cv::detail::NoExposureCompensator, cv::detail::ExposureCompensator>(rb_mCvDetail, "NoExposureCompensator").
    define_constructor(Constructor<cv::detail::NoExposureCompensator>()).
    define_method<void(cv::detail::NoExposureCompensator::*)(const std::vector<cv::Point_<int>>&, const std::vector<cv::UMat>&, const std::vector<std::pair<cv::UMat, unsigned char>>&)>("feed", &cv::detail::NoExposureCompensator::feed,
      Arg("arg_0"), Arg("arg_1"), Arg("arg_2")).
    define_method<void(cv::detail::NoExposureCompensator::*)(int, cv::Point, cv::InputOutputArray, cv::InputArray)>("apply", &cv::detail::NoExposureCompensator::apply,
      Arg("arg_0"), Arg("arg_1"), Arg("arg_2"), Arg("arg_3")).
    define_method<void(cv::detail::NoExposureCompensator::*)(std::vector<cv::Mat>&)>("get_mat_gains", &cv::detail::NoExposureCompensator::getMatGains,
      Arg("umv")).
    define_method<void(cv::detail::NoExposureCompensator::*)(std::vector<cv::Mat>&)>("set_mat_gains", &cv::detail::NoExposureCompensator::setMatGains,
      Arg("umv"));

  Rice::Data_Type<cv::detail::GainCompensator> rb_cCvDetailGainCompensator = define_class_under<cv::detail::GainCompensator, cv::detail::ExposureCompensator>(rb_mCvDetail, "GainCompensator").
    define_constructor(Constructor<cv::detail::GainCompensator>()).
    define_constructor(Constructor<cv::detail::GainCompensator, int>(),
      Arg("nr_feeds")).
    define_method<void(cv::detail::GainCompensator::*)(const std::vector<cv::Point_<int>>&, const std::vector<cv::UMat>&, const std::vector<std::pair<cv::UMat, unsigned char>>&)>("feed", &cv::detail::GainCompensator::feed,
      Arg("corners"), Arg("images"), Arg("masks")).
    define_method<void(cv::detail::GainCompensator::*)(const std::vector<cv::Point_<int>>&, const std::vector<cv::UMat>&, const std::vector<std::pair<cv::UMat, unsigned char>>&)>("single_feed", &cv::detail::GainCompensator::singleFeed,
      Arg("corners"), Arg("images"), Arg("masks")).
    define_method<void(cv::detail::GainCompensator::*)(int, cv::Point, cv::InputOutputArray, cv::InputArray)>("apply", &cv::detail::GainCompensator::apply,
      Arg("index"), Arg("corner"), Arg("image"), Arg("mask")).
    define_method<void(cv::detail::GainCompensator::*)(std::vector<cv::Mat>&)>("get_mat_gains", &cv::detail::GainCompensator::getMatGains,
      Arg("umv")).
    define_method<void(cv::detail::GainCompensator::*)(std::vector<cv::Mat>&)>("set_mat_gains", &cv::detail::GainCompensator::setMatGains,
      Arg("umv")).
    define_method<void(cv::detail::GainCompensator::*)(int)>("set_nr_feeds", &cv::detail::GainCompensator::setNrFeeds,
      Arg("nr_feeds")).
    define_method<int(cv::detail::GainCompensator::*)()>("get_nr_feeds", &cv::detail::GainCompensator::getNrFeeds).
    define_method<void(cv::detail::GainCompensator::*)(double)>("set_similarity_threshold", &cv::detail::GainCompensator::setSimilarityThreshold,
      Arg("similarity_threshold")).
    define_method<double(cv::detail::GainCompensator::*)() const>("get_similarity_threshold", &cv::detail::GainCompensator::getSimilarityThreshold).
    define_method<void(cv::detail::GainCompensator::*)(const std::vector<cv::Point_<int>>&, const std::vector<cv::UMat>&)>("prepare_similarity_mask", &cv::detail::GainCompensator::prepareSimilarityMask,
      Arg("corners"), Arg("images")).
    define_method<std::vector<double>(cv::detail::GainCompensator::*)() const>("gains", &cv::detail::GainCompensator::gains);

  Rice::Data_Type<cv::detail::ChannelsCompensator> rb_cCvDetailChannelsCompensator = define_class_under<cv::detail::ChannelsCompensator, cv::detail::ExposureCompensator>(rb_mCvDetail, "ChannelsCompensator").
    define_constructor(Constructor<cv::detail::ChannelsCompensator, int>(),
      Arg("nr_feeds") = static_cast<int>(1)).
    define_method<void(cv::detail::ChannelsCompensator::*)(const std::vector<cv::Point_<int>>&, const std::vector<cv::UMat>&, const std::vector<std::pair<cv::UMat, unsigned char>>&)>("feed", &cv::detail::ChannelsCompensator::feed,
      Arg("corners"), Arg("images"), Arg("masks")).
    define_method<void(cv::detail::ChannelsCompensator::*)(int, cv::Point, cv::InputOutputArray, cv::InputArray)>("apply", &cv::detail::ChannelsCompensator::apply,
      Arg("index"), Arg("corner"), Arg("image"), Arg("mask")).
    define_method<void(cv::detail::ChannelsCompensator::*)(std::vector<cv::Mat>&)>("get_mat_gains", &cv::detail::ChannelsCompensator::getMatGains,
      Arg("umv")).
    define_method<void(cv::detail::ChannelsCompensator::*)(std::vector<cv::Mat>&)>("set_mat_gains", &cv::detail::ChannelsCompensator::setMatGains,
      Arg("umv")).
    define_method<void(cv::detail::ChannelsCompensator::*)(int)>("set_nr_feeds", &cv::detail::ChannelsCompensator::setNrFeeds,
      Arg("nr_feeds")).
    define_method<int(cv::detail::ChannelsCompensator::*)()>("get_nr_feeds", &cv::detail::ChannelsCompensator::getNrFeeds).
    define_method<void(cv::detail::ChannelsCompensator::*)(double)>("set_similarity_threshold", &cv::detail::ChannelsCompensator::setSimilarityThreshold,
      Arg("similarity_threshold")).
    define_method<double(cv::detail::ChannelsCompensator::*)() const>("get_similarity_threshold", &cv::detail::ChannelsCompensator::getSimilarityThreshold).
    define_method<std::vector<cv::Scalar_<double>>(cv::detail::ChannelsCompensator::*)() const>("gains", &cv::detail::ChannelsCompensator::gains);

  Rice::Data_Type<cv::detail::BlocksCompensator> rb_cCvDetailBlocksCompensator = define_class_under<cv::detail::BlocksCompensator, cv::detail::ExposureCompensator>(rb_mCvDetail, "BlocksCompensator").
    define_method<void(cv::detail::BlocksCompensator::*)(int, cv::Point, cv::InputOutputArray, cv::InputArray)>("apply", &cv::detail::BlocksCompensator::apply,
      Arg("index"), Arg("corner"), Arg("image"), Arg("mask")).
    define_method<void(cv::detail::BlocksCompensator::*)(std::vector<cv::Mat>&)>("get_mat_gains", &cv::detail::BlocksCompensator::getMatGains,
      Arg("umv")).
    define_method<void(cv::detail::BlocksCompensator::*)(std::vector<cv::Mat>&)>("set_mat_gains", &cv::detail::BlocksCompensator::setMatGains,
      Arg("umv")).
    define_method<void(cv::detail::BlocksCompensator::*)(int)>("set_nr_feeds", &cv::detail::BlocksCompensator::setNrFeeds,
      Arg("nr_feeds")).
    define_method<int(cv::detail::BlocksCompensator::*)()>("get_nr_feeds", &cv::detail::BlocksCompensator::getNrFeeds).
    define_method<void(cv::detail::BlocksCompensator::*)(double)>("set_similarity_threshold", &cv::detail::BlocksCompensator::setSimilarityThreshold,
      Arg("similarity_threshold")).
    define_method<double(cv::detail::BlocksCompensator::*)() const>("get_similarity_threshold", &cv::detail::BlocksCompensator::getSimilarityThreshold).
    define_method<void(cv::detail::BlocksCompensator::*)(int, int)>("set_block_size", &cv::detail::BlocksCompensator::setBlockSize,
      Arg("width"), Arg("height")).
    define_method<void(cv::detail::BlocksCompensator::*)(cv::Size)>("set_block_size", &cv::detail::BlocksCompensator::setBlockSize,
      Arg("size")).
    define_method<cv::Size(cv::detail::BlocksCompensator::*)() const>("get_block_size", &cv::detail::BlocksCompensator::getBlockSize).
    define_method<void(cv::detail::BlocksCompensator::*)(int)>("set_nr_gains_filtering_iterations", &cv::detail::BlocksCompensator::setNrGainsFilteringIterations,
      Arg("nr_iterations")).
    define_method<int(cv::detail::BlocksCompensator::*)() const>("get_nr_gains_filtering_iterations", &cv::detail::BlocksCompensator::getNrGainsFilteringIterations);

  Rice::Data_Type<cv::detail::BlocksGainCompensator> rb_cCvDetailBlocksGainCompensator = define_class_under<cv::detail::BlocksGainCompensator, cv::detail::BlocksCompensator>(rb_mCvDetail, "BlocksGainCompensator").
    define_constructor(Constructor<cv::detail::BlocksGainCompensator, int, int>(),
      Arg("bl_width") = static_cast<int>(32), Arg("bl_height") = static_cast<int>(32)).
    define_constructor(Constructor<cv::detail::BlocksGainCompensator, int, int, int>(),
      Arg("bl_width"), Arg("bl_height"), Arg("nr_feeds")).
    define_method<void(cv::detail::BlocksGainCompensator::*)(const std::vector<cv::Point_<int>>&, const std::vector<cv::UMat>&, const std::vector<std::pair<cv::UMat, unsigned char>>&)>("feed", &cv::detail::BlocksGainCompensator::feed,
      Arg("corners"), Arg("images"), Arg("masks")).
    define_method<void(cv::detail::BlocksGainCompensator::*)(int, cv::Point, cv::InputOutputArray, cv::InputArray)>("apply", &cv::detail::BlocksGainCompensator::apply,
      Arg("index"), Arg("corner"), Arg("image"), Arg("mask")).
    define_method<void(cv::detail::BlocksGainCompensator::*)(std::vector<cv::Mat>&)>("get_mat_gains", &cv::detail::BlocksGainCompensator::getMatGains,
      Arg("umv")).
    define_method<void(cv::detail::BlocksGainCompensator::*)(std::vector<cv::Mat>&)>("set_mat_gains", &cv::detail::BlocksGainCompensator::setMatGains,
      Arg("umv"));

  Rice::Data_Type<cv::detail::BlocksChannelsCompensator> rb_cCvDetailBlocksChannelsCompensator = define_class_under<cv::detail::BlocksChannelsCompensator, cv::detail::BlocksCompensator>(rb_mCvDetail, "BlocksChannelsCompensator").
    define_constructor(Constructor<cv::detail::BlocksChannelsCompensator, int, int, int>(),
      Arg("bl_width") = static_cast<int>(32), Arg("bl_height") = static_cast<int>(32), Arg("nr_feeds") = static_cast<int>(1)).
    define_method<void(cv::detail::BlocksChannelsCompensator::*)(const std::vector<cv::Point_<int>>&, const std::vector<cv::UMat>&, const std::vector<std::pair<cv::UMat, unsigned char>>&)>("feed", &cv::detail::BlocksChannelsCompensator::feed,
      Arg("corners"), Arg("images"), Arg("masks"));
}