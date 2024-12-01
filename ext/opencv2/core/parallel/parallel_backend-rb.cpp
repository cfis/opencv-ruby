#include <string>
#include <memory>
#include <opencv2/core/parallel/parallel_backend.hpp>
#include "parallel_backend-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvParallelParallelForAPI;

void Init_ParallelBackend()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvParallel = define_module_under(rb_mCv, "Parallel");
  
  rb_cCvParallelParallelForAPI = define_class_under<cv::parallel::ParallelForAPI>(rb_mCvParallel, "ParallelForAPI").
    define_method("parallel_for", &cv::parallel::ParallelForAPI::parallel_for,
      Arg("tasks"), Arg("body_callback"), Arg("callback_data")).
    define_method("get_thread_num", &cv::parallel::ParallelForAPI::getThreadNum).
    define_method("get_num_threads", &cv::parallel::ParallelForAPI::getNumThreads).
    define_method("set_num_threads", &cv::parallel::ParallelForAPI::setNumThreads,
      Arg("n_threads")).
    define_method("get_name", &cv::parallel::ParallelForAPI::getName);
  
  rb_mCvParallel.define_module_function<void(*)(const std::shared_ptr<cv::parallel::ParallelForAPI>&, bool)>("set_parallel_for_backend", &cv::parallel::setParallelForBackend,
    Arg("api"), Arg("propagate_num_threads") = static_cast<bool>(true));
  
  rb_mCvParallel.define_module_function<bool(*)(const int&, bool)>("set_parallel_for_backend?", &cv::parallel::setParallelForBackend,
    Arg("backend_name"), Arg("propagate_num_threads") = static_cast<bool>(true));

}