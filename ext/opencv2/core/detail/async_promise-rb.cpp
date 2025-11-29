#include <opencv2/core/core.hpp>
#include <opencv2/core/detail/async_promise.hpp>
#include "async_promise-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvAsyncPromise;

void Init_AsyncPromise()
{
  Module rb_mCv = define_module("Cv");
  
  rb_cCvAsyncPromise = define_class_under<cv::AsyncPromise>(rb_mCv, "AsyncPromise").
    define_constructor(Constructor<cv::AsyncPromise>()).
    define_constructor(Constructor<cv::AsyncPromise, const cv::AsyncPromise&>(),
      Arg("o")).
    define_method<cv::AsyncPromise&(cv::AsyncPromise::*)(const cv::AsyncPromise&) noexcept>("assign", &cv::AsyncPromise::operator=,
      Arg("o")).
    define_method("release", &cv::AsyncPromise::release).
    define_method("get_array_result", &cv::AsyncPromise::getArrayResult).
    define_method("set_value", &cv::AsyncPromise::setValue,
      Arg("value")).
    define_method<void(cv::AsyncPromise::*)(std::exception_ptr)>("set_exception", &cv::AsyncPromise::setException,
      Arg("exception")).
    define_method<void(cv::AsyncPromise::*)(const cv::Exception&)>("set_exception", &cv::AsyncPromise::setException,
      Arg("exception")).
    define_method<cv::AsyncPromise&(cv::AsyncPromise::*)(cv::AsyncPromise&&) noexcept>("assign", &cv::AsyncPromise::operator=,
      Arg("o")).
    define_method("_get_impl", &cv::AsyncPromise::_getImpl);

}