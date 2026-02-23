#include <opencv2/flann/lsh_table.h>
#include "lsh_table-rb.hpp"

using namespace Rice;

#include "lsh_table-rb.ipp"

void Init_Flann_LshTable()
{
  Class(rb_cObject).define_constant("USE_UNORDERED_MAP", USE_UNORDERED_MAP);

  Module rb_mCvflann = define_module("Cvflann");

  Module rb_mCvflannLsh = define_module_under(rb_mCvflann, "Lsh");

  Rice::Data_Type<cvflann::lsh::LshStats> rb_cCvflannLshLshStats = define_class_under<cvflann::lsh::LshStats>(rb_mCvflannLsh, "LshStats").
    define_constructor(Constructor<cvflann::lsh::LshStats>()).
    define_attr("bucket_sizes_", &cvflann::lsh::LshStats::bucket_sizes_).
    define_attr("n_buckets_", &cvflann::lsh::LshStats::n_buckets_).
    define_attr("bucket_size_mean_", &cvflann::lsh::LshStats::bucket_size_mean_).
    define_attr("bucket_size_median_", &cvflann::lsh::LshStats::bucket_size_median_).
    define_attr("bucket_size_min_", &cvflann::lsh::LshStats::bucket_size_min_).
    define_attr("bucket_size_max_", &cvflann::lsh::LshStats::bucket_size_max_).
    define_attr("bucket_size_std_dev", &cvflann::lsh::LshStats::bucket_size_std_dev).
    define_attr("size_histogram_", &cvflann::lsh::LshStats::size_histogram_);

  rb_cCvflannLshLshStats.
    define_method("inspect", [](const cvflann::lsh::LshStats& self) -> std::string
    {
      std::ostringstream stream;
      stream << self;
      return stream.str();
    });
}
