#include <opencv2/core/cuda_stream_accessor.hpp>
#include "cuda_stream_accessor-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvCudaEventAccessor;
Rice::Class rb_cCvCudaStreamAccessor;

void Init_CudaStreamAccessor()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  rb_cCvCudaStreamAccessor = define_class_under<cv::cuda::StreamAccessor>(rb_mCvCuda, "StreamAccessor").
    define_constructor(Constructor<cv::cuda::StreamAccessor>());
//    define_singleton_function("get_stream", &cv::cuda::StreamAccessor::getStream,
  //    Arg("stream")).
   // define_singleton_function("wrap_stream", &cv::cuda::StreamAccessor::wrapStream,
     // Arg("stream"));
  
  rb_cCvCudaEventAccessor = define_class_under<cv::cuda::EventAccessor>(rb_mCvCuda, "EventAccessor").
    define_constructor(Constructor<cv::cuda::EventAccessor>());
    //define_singleton_function("get_event", &cv::cuda::EventAccessor::getEvent,
    //  Arg("event")).
    //define_singleton_function("wrap_event", &cv::cuda::EventAccessor::wrapEvent,
    //  Arg("event"));
}