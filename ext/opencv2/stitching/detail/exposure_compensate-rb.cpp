#include <opencv2/stitching/detail/exposure_compensate.hpp>
#include "../../core/cvstd_wrapper-rb.hpp"
#include "exposure_compensate-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvDetailBlocksChannelsCompensator;
Rice::Class rb_cCvDetailBlocksCompensator;
Rice::Class rb_cCvDetailBlocksGainCompensator;
Rice::Class rb_cCvDetailChannelsCompensator;
Rice::Class rb_cCvDetailExposureCompensator;
Rice::Class rb_cCvDetailGainCompensator;
Rice::Class rb_cCvDetailNoExposureCompensator;

void Init_ExposureCompensate()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDetail = define_module_under(rb_mCv, "Detail");
  
  rb_cCvDetailExposureCompensator = define_class_under<cv::detail::ExposureCompensator>(rb_mCvDetail, "ExposureCompensator").
    define_singleton_function("create_default", &cv::detail::ExposureCompensator::createDefault,
      Arg("type")).
    define_method<void(cv::detail::ExposureCompensator::*)(const std::vector<cv::Point_<int>>&, const std::vector<cv::UMat>&, const std::vector<cv::UMat>&)>("feed", &cv::detail::ExposureCompensator::feed,
      Arg("corners"), Arg("images"), Arg("masks")).
    define_method<void(cv::detail::ExposureCompensator::*)(const std::vector<cv::Point_<int>>&, const std::vector<cv::UMat>&, const std::vector<std::pair<cv::UMat, unsigned char>>&)>("feed", &cv::detail::ExposureCompensator::feed,
      Arg("corners"), Arg("images"), Arg("masks")).
    define_method("apply", &cv::detail::ExposureCompensator::apply,
      Arg("index"), Arg("corner"), Arg("image"), Arg("mask")).
    define_method("get_mat_gains", &cv::detail::ExposureCompensator::getMatGains,
      Arg("")).
    define_method("set_mat_gains", &cv::detail::ExposureCompensator::setMatGains,
      Arg("")).
    define_method("set_update_gain", &cv::detail::ExposureCompensator::setUpdateGain,
      Arg("b")).
    define_method("get_update_gain?", &cv::detail::ExposureCompensator::getUpdateGain);
  
  rb_cCvDetailExposureCompensator.define_constant("NO", (int)cv::detail::ExposureCompensator::NO);
  rb_cCvDetailExposureCompensator.define_constant("GAIN", (int)cv::detail::ExposureCompensator::GAIN);
  rb_cCvDetailExposureCompensator.define_constant("GAIN_BLOCKS", (int)cv::detail::ExposureCompensator::GAIN_BLOCKS);
  rb_cCvDetailExposureCompensator.define_constant("CHANNELS", (int)cv::detail::ExposureCompensator::CHANNELS);
  rb_cCvDetailExposureCompensator.define_constant("CHANNELS_BLOCKS", (int)cv::detail::ExposureCompensator::CHANNELS_BLOCKS);
  
  rb_cCvDetailNoExposureCompensator = define_class_under<cv::detail::NoExposureCompensator, cv::detail::ExposureCompensator>(rb_mCvDetail, "NoExposureCompensator").
    define_constructor(Constructor<cv::detail::NoExposureCompensator>()).
    define_method("feed", &cv::detail::NoExposureCompensator::feed,
      Arg(""), Arg(""), Arg("")).
    define_method("apply", &cv::detail::NoExposureCompensator::apply,
      Arg(""), Arg(""), Arg(""), Arg("")).
    define_method("get_mat_gains", &cv::detail::NoExposureCompensator::getMatGains,
      Arg("umv")).
    define_method("set_mat_gains", &cv::detail::NoExposureCompensator::setMatGains,
      Arg("umv"));
  
  rb_cCvDetailGainCompensator = define_class_under<cv::detail::GainCompensator, cv::detail::ExposureCompensator>(rb_mCvDetail, "GainCompensator").
    define_constructor(Constructor<cv::detail::GainCompensator>()).
    define_constructor(Constructor<cv::detail::GainCompensator, int>(),
      Arg("nr_feeds")).
    define_method("feed", &cv::detail::GainCompensator::feed,
      Arg("corners"), Arg("images"), Arg("masks")).
    define_method("single_feed", &cv::detail::GainCompensator::singleFeed,
      Arg("corners"), Arg("images"), Arg("masks")).
    define_method("apply", &cv::detail::GainCompensator::apply,
      Arg("index"), Arg("corner"), Arg("image"), Arg("mask")).
    define_method("get_mat_gains", &cv::detail::GainCompensator::getMatGains,
      Arg("umv")).
    define_method("set_mat_gains", &cv::detail::GainCompensator::setMatGains,
      Arg("umv")).
    define_method("set_nr_feeds", &cv::detail::GainCompensator::setNrFeeds,
      Arg("nr_feeds")).
    define_method("get_nr_feeds", &cv::detail::GainCompensator::getNrFeeds).
    define_method("set_similarity_threshold", &cv::detail::GainCompensator::setSimilarityThreshold,
      Arg("similarity_threshold")).
    define_method("get_similarity_threshold", &cv::detail::GainCompensator::getSimilarityThreshold).
    define_method("prepare_similarity_mask", &cv::detail::GainCompensator::prepareSimilarityMask,
      Arg("corners"), Arg("images")).
    define_method("gains", &cv::detail::GainCompensator::gains);
  
  rb_cCvDetailChannelsCompensator = define_class_under<cv::detail::ChannelsCompensator, cv::detail::ExposureCompensator>(rb_mCvDetail, "ChannelsCompensator").
    define_constructor(Constructor<cv::detail::ChannelsCompensator, int>(),
      Arg("nr_feeds") = static_cast<int>(1)).
    define_method("feed", &cv::detail::ChannelsCompensator::feed,
      Arg("corners"), Arg("images"), Arg("masks")).
    define_method("apply", &cv::detail::ChannelsCompensator::apply,
      Arg("index"), Arg("corner"), Arg("image"), Arg("mask")).
    define_method("get_mat_gains", &cv::detail::ChannelsCompensator::getMatGains,
      Arg("umv")).
    define_method("set_mat_gains", &cv::detail::ChannelsCompensator::setMatGains,
      Arg("umv")).
    define_method("set_nr_feeds", &cv::detail::ChannelsCompensator::setNrFeeds,
      Arg("nr_feeds")).
    define_method("get_nr_feeds", &cv::detail::ChannelsCompensator::getNrFeeds).
    define_method("set_similarity_threshold", &cv::detail::ChannelsCompensator::setSimilarityThreshold,
      Arg("similarity_threshold")).
    define_method("get_similarity_threshold", &cv::detail::ChannelsCompensator::getSimilarityThreshold).
    define_method("gains", &cv::detail::ChannelsCompensator::gains);
  
  rb_cCvDetailBlocksCompensator = define_class_under<cv::detail::BlocksCompensator, cv::detail::ExposureCompensator>(rb_mCvDetail, "BlocksCompensator").
    define_method("apply", &cv::detail::BlocksCompensator::apply,
      Arg("index"), Arg("corner"), Arg("image"), Arg("mask")).
    define_method("get_mat_gains", &cv::detail::BlocksCompensator::getMatGains,
      Arg("umv")).
    define_method("set_mat_gains", &cv::detail::BlocksCompensator::setMatGains,
      Arg("umv")).
    define_method("set_nr_feeds", &cv::detail::BlocksCompensator::setNrFeeds,
      Arg("nr_feeds")).
    define_method("get_nr_feeds", &cv::detail::BlocksCompensator::getNrFeeds).
    define_method("set_similarity_threshold", &cv::detail::BlocksCompensator::setSimilarityThreshold,
      Arg("similarity_threshold")).
    define_method("get_similarity_threshold", &cv::detail::BlocksCompensator::getSimilarityThreshold).
    define_method<void(cv::detail::BlocksCompensator::*)(int, int)>("set_block_size", &cv::detail::BlocksCompensator::setBlockSize,
      Arg("width"), Arg("height")).
    define_method<void(cv::detail::BlocksCompensator::*)(cv::Size)>("set_block_size", &cv::detail::BlocksCompensator::setBlockSize,
      Arg("size")).
    define_method("get_block_size", &cv::detail::BlocksCompensator::getBlockSize).
    define_method("set_nr_gains_filtering_iterations", &cv::detail::BlocksCompensator::setNrGainsFilteringIterations,
      Arg("nr_iterations")).
    define_method("get_nr_gains_filtering_iterations", &cv::detail::BlocksCompensator::getNrGainsFilteringIterations);
  
  rb_cCvDetailBlocksGainCompensator = define_class_under<cv::detail::BlocksGainCompensator, cv::detail::BlocksCompensator>(rb_mCvDetail, "BlocksGainCompensator").
    define_constructor(Constructor<cv::detail::BlocksGainCompensator, int, int>(),
      Arg("bl_width") = static_cast<int>(32), Arg("bl_height") = static_cast<int>(32)).
    define_constructor(Constructor<cv::detail::BlocksGainCompensator, int, int, int>(),
      Arg("bl_width"), Arg("bl_height"), Arg("nr_feeds")).
    define_method("feed", &cv::detail::BlocksGainCompensator::feed,
      Arg("corners"), Arg("images"), Arg("masks")).
    define_method("apply", &cv::detail::BlocksGainCompensator::apply,
      Arg("index"), Arg("corner"), Arg("image"), Arg("mask")).
    define_method("get_mat_gains", &cv::detail::BlocksGainCompensator::getMatGains,
      Arg("umv")).
    define_method("set_mat_gains", &cv::detail::BlocksGainCompensator::setMatGains,
      Arg("umv"));
  
  rb_cCvDetailBlocksChannelsCompensator = define_class_under<cv::detail::BlocksChannelsCompensator, cv::detail::BlocksCompensator>(rb_mCvDetail, "BlocksChannelsCompensator").
    define_constructor(Constructor<cv::detail::BlocksChannelsCompensator, int, int, int>(),
      Arg("bl_width") = static_cast<int>(32), Arg("bl_height") = static_cast<int>(32), Arg("nr_feeds") = static_cast<int>(1)).
    define_method("feed", &cv::detail::BlocksChannelsCompensator::feed,
      Arg("corners"), Arg("images"), Arg("masks"));

}