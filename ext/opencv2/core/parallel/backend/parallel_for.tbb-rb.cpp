#include <string>
#include <opencv2/core/parallel/backend/parallel_for.tbb.hpp>
#include "parallel_for.tbb-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvParallelTbbParallelForBackend;
Rice::Class rb_cCvParallelTbbParallelForBackendCallbackProxy;

void Init_ParallelForTbb()
{
  Class(rb_cObject).define_constant("TBB_SUPPRESS_DEPRECATED_MESSAGES", TBB_SUPPRESS_DEPRECATED_MESSAGES);
  
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvParallel = define_module_under(rb_mCv, "Parallel");
  
  Module rb_mCvParallelTbb = define_module_under(rb_mCvParallel, "Tbb");
  
  rb_mCvParallelTbb.define_module_function("get_scheduler", &cv::parallel::tbb::getScheduler);
  
  rb_cCvParallelTbbParallelForBackend = define_class_under<cv::parallel::tbb::ParallelForBackend, cv::parallel::ParallelForAPI>(rb_mCvParallelTbb, "ParallelForBackend").
    define_constructor(Constructor<cv::parallel::tbb::ParallelForBackend>()).
    define_method("parallel_for", &cv::parallel::tbb::ParallelForBackend::parallel_for,
      Arg("tasks"), Arg("body_callback"), Arg("callback_data")).
    define_method("get_thread_num", &cv::parallel::tbb::ParallelForBackend::getThreadNum).
    define_method("get_num_threads", &cv::parallel::tbb::ParallelForBackend::getNumThreads).
    define_method("set_num_threads", &cv::parallel::tbb::ParallelForBackend::setNumThreads,
      Arg("n_threads")).
    define_method("get_name", &cv::parallel::tbb::ParallelForBackend::getName);
  
  rb_cCvParallelTbbParallelForBackendCallbackProxy = define_class_under<cv::parallel::tbb::ParallelForBackend::CallbackProxy>(rb_cCvParallelTbbParallelForBackend, "CallbackProxy").
    define_constructor(Constructor<cv::parallel::tbb::ParallelForBackend::CallbackProxy, int, cv::parallel::ParallelForAPI::FN_parallel_for_body_cb_t&, void*>(),
      Arg("tasks_"), Arg("callback_"), Arg("callback_data_")).
    define_method<void(cv::parallel::tbb::ParallelForBackend::CallbackProxy::*)(const int&) const>("call", &cv::parallel::tbb::ParallelForBackend::CallbackProxy::operator(),
      Arg("range")).
    define_method<void(cv::parallel::tbb::ParallelForBackend::CallbackProxy::*)() const>("call", &cv::parallel::tbb::ParallelForBackend::CallbackProxy::operator());

}