#include <string>
#include <opencv2/core/parallel/backend/parallel_for.openmp.hpp>
#include "parallel_for.openmp-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvParallelOpenmpParallelForBackend;

void Init_ParallelForOpenmp()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvParallel = define_module_under(rb_mCv, "Parallel");
  
  Module rb_mCvParallelOpenmp = define_module_under(rb_mCvParallel, "Openmp");
  
  rb_cCvParallelOpenmpParallelForBackend = define_class_under<cv::parallel::openmp::ParallelForBackend, cv::parallel::ParallelForAPI>(rb_mCvParallelOpenmp, "ParallelForBackend").
    define_constructor(Constructor<cv::parallel::openmp::ParallelForBackend>()).
    define_method("parallel_for", &cv::parallel::openmp::ParallelForBackend::parallel_for,
      Arg("tasks"), Arg("body_callback"), Arg("callback_data")).
    define_method("get_thread_num", &cv::parallel::openmp::ParallelForBackend::getThreadNum).
    define_method("get_num_threads", &cv::parallel::openmp::ParallelForBackend::getNumThreads).
    define_method("set_num_threads", &cv::parallel::openmp::ParallelForBackend::setNumThreads,
      Arg("n_threads")).
    define_method("get_name", &cv::parallel::openmp::ParallelForBackend::getName);

}