#include <opencv2/core/utils/allocator_stats.hpp>
#include "allocator_stats-rb.hpp"

using namespace Rice;

void Init_Core_Utils_AllocatorStats()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvUtils = define_module_under(rb_mCv, "Utils");

  Rice::Data_Type<cv::utils::AllocatorStatisticsInterface> rb_cCvUtilsAllocatorStatisticsInterface = define_class_under<cv::utils::AllocatorStatisticsInterface>(rb_mCvUtils, "AllocatorStatisticsInterface").
    define_method<uint64_t(cv::utils::AllocatorStatisticsInterface::*)() const>("get_current_usage", &cv::utils::AllocatorStatisticsInterface::getCurrentUsage).
    define_method<uint64_t(cv::utils::AllocatorStatisticsInterface::*)() const>("get_total_usage", &cv::utils::AllocatorStatisticsInterface::getTotalUsage).
    define_method<uint64_t(cv::utils::AllocatorStatisticsInterface::*)() const>("get_number_of_allocations", &cv::utils::AllocatorStatisticsInterface::getNumberOfAllocations).
    define_method<uint64_t(cv::utils::AllocatorStatisticsInterface::*)() const>("get_peak_usage", &cv::utils::AllocatorStatisticsInterface::getPeakUsage).
    define_method<void(cv::utils::AllocatorStatisticsInterface::*)()>("reset_peak_usage", &cv::utils::AllocatorStatisticsInterface::resetPeakUsage);
}