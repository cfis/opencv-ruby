#include <opencv2/core/utils/allocator_stats.impl.hpp>
#include "allocator_stats.impl-rb.hpp"

using namespace Rice;

void Init_Core_Utils_AllocatorStatsImpl()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvUtils = define_module_under(rb_mCv, "Utils");

  Rice::Data_Type<cv::utils::AllocatorStatistics> rb_cCvUtilsAllocatorStatistics = define_class_under<cv::utils::AllocatorStatistics, cv::utils::AllocatorStatisticsInterface>(rb_mCvUtils, "AllocatorStatistics").
    define_constructor(Constructor<cv::utils::AllocatorStatistics>()).
    define_method<uint64_t(cv::utils::AllocatorStatistics::*)() const>("get_current_usage", &cv::utils::AllocatorStatistics::getCurrentUsage).
    define_method<uint64_t(cv::utils::AllocatorStatistics::*)() const>("get_total_usage", &cv::utils::AllocatorStatistics::getTotalUsage).
    define_method<uint64_t(cv::utils::AllocatorStatistics::*)() const>("get_number_of_allocations", &cv::utils::AllocatorStatistics::getNumberOfAllocations).
    define_method<uint64_t(cv::utils::AllocatorStatistics::*)() const>("get_peak_usage", &cv::utils::AllocatorStatistics::getPeakUsage).
    define_method<void(cv::utils::AllocatorStatistics::*)()>("reset_peak_usage", &cv::utils::AllocatorStatistics::resetPeakUsage).
    define_method<void(cv::utils::AllocatorStatistics::*)(size_t)>("on_allocate", &cv::utils::AllocatorStatistics::onAllocate,
      Arg("sz")).
    define_method<void(cv::utils::AllocatorStatistics::*)(size_t)>("on_free", &cv::utils::AllocatorStatistics::onFree,
      Arg("sz"));
}