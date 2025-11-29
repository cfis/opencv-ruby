#include <opencv2/flann/lsh_table.h>
#include "lsh_table-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvflannLshLshStats;

template<typename Data_Type_T, typename ElementType>
inline void LshTable_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cvflann::lsh::LshTable::LshTable<ElementType>>()).
    define_constructor(Constructor<cvflann::lsh::LshTable::LshTable<ElementType>, unsigned int, unsigned int>(),
      Arg("feature_size"), Arg("key_size")).
    template define_method<void(cvflann::lsh::LshTable<ElementType>::*)(unsigned int, const ElementType*)>("add", &cvflann::lsh::LshTable<ElementType>::add,
      Arg("value"), Arg("feature")).
    template define_method<void(cvflann::lsh::LshTable<ElementType>::*)(cvflann::Matrix<ElementType>)>("add", &cvflann::lsh::LshTable<ElementType>::add,
      Arg("dataset")).
    template define_method("get_bucket_from_key", &cvflann::lsh::LshTable<ElementType>::getBucketFromKey,
      Arg("key")).
    template define_method("get_key", &cvflann::lsh::LshTable<ElementType>::getKey,
      Arg("")).
    template define_method("get_stats", &cvflann::lsh::LshTable<ElementType>::getStats);
};
void Init_LshTable()
{
  Class(rb_cObject).define_constant("USE_UNORDERED_MAP", USE_UNORDERED_MAP);
  
  Module rb_mCvflann = define_module("Cvflann");
  
  Module rb_mCvflannLsh = define_module_under(rb_mCvflann, "Lsh");
  
  rb_cCvflannLshLshStats = define_class_under<cvflann::lsh::LshStats>(rb_mCvflannLsh, "LshStats").
    define_constructor(Constructor<cvflann::lsh::LshStats>()).
    define_attr("bucket_sizes_", &cvflann::lsh::LshStats::bucket_sizes_).
    define_attr("n_buckets_", &cvflann::lsh::LshStats::n_buckets_).
    define_attr("bucket_size_mean_", &cvflann::lsh::LshStats::bucket_size_mean_).
    define_attr("bucket_size_median_", &cvflann::lsh::LshStats::bucket_size_median_).
    define_attr("bucket_size_min_", &cvflann::lsh::LshStats::bucket_size_min_).
    define_attr("bucket_size_max_", &cvflann::lsh::LshStats::bucket_size_max_).
    define_attr("bucket_size_std_dev", &cvflann::lsh::LshStats::bucket_size_std_dev);
  
  
  rb_cCvflannLshLshStats.define_method("inspect", [](const cvflann::lsh::LshStats& self) -> std::string
  {
    std::ostringstream stream;
    stream << self;
    return stream.str();
  });

}