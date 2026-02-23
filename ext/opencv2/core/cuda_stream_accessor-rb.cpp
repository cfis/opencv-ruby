#include <opencv2/core/cuda_stream_accessor.hpp>
#include "cuda_stream_accessor-rb.hpp"

using namespace Rice;

void Init_Core_CudaStreamAccessor()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");

  Rice::Data_Type<cv::cuda::StreamAccessor> rb_cCvCudaStreamAccessor = define_class_under<cv::cuda::StreamAccessor>(rb_mCvCuda, "StreamAccessor").
    define_constructor(Constructor<cv::cuda::StreamAccessor>()).
    define_singleton_function<cudaStream_t(*)(const cv::cuda::Stream&)>("get_stream", &cv::cuda::StreamAccessor::getStream,
      Arg("stream")).
    define_singleton_function<cv::cuda::Stream(*)(cudaStream_t)>("wrap_stream", &cv::cuda::StreamAccessor::wrapStream,
      Arg("stream"));

  Rice::Data_Type<cv::cuda::EventAccessor> rb_cCvCudaEventAccessor = define_class_under<cv::cuda::EventAccessor>(rb_mCvCuda, "EventAccessor").
    define_constructor(Constructor<cv::cuda::EventAccessor>()).
    define_singleton_function<cudaEvent_t(*)(const cv::cuda::Event&)>("get_event", &cv::cuda::EventAccessor::getEvent,
      Arg("event")).
    define_singleton_function<cv::cuda::Event(*)(cudaEvent_t)>("wrap_event", &cv::cuda::EventAccessor::wrapEvent,
      Arg("event"));
}
