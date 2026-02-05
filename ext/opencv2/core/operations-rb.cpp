#include <opencv2/core/core.hpp> // Manual
#include <opencv2/core/operations.hpp>
#include "mat-rb.hpp" // Manual
#include "operations-rb.hpp"

using namespace Rice;

#include "operations-rb.ipp"

void Init_Core_Operations()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvInternal = define_module_under(rb_mCv, "Internal");

  rb_mCv.define_module_function<cv::Ptr<cv::Formatted>(*)(cv::InputArray, cv::Formatter::FormatType)>("format", &cv::format,
    Arg("mtx"), Arg("fmt"));

  rb_mCv.define_module_function<int(*)(cv::Ptr<cv::Formatted>, FILE*)>("print", &cv::print,
    Arg("fmtd"), Arg("stream") = static_cast<FILE*>(stdout));

  rb_mCv.define_module_function<int(*)(const cv::Mat&, FILE*)>("print", &cv::print,
    Arg("mtx"), Arg("stream") = static_cast<FILE*>(stdout));

  rb_mCv.define_module_function<int(*)(const cv::UMat&, FILE*)>("print", &cv::print,
    Arg("mtx"), Arg("stream") = static_cast<FILE*>(stdout));

  Data_Type<cv::Mat>().
    define_method("assign_plus", [](cv::Mat& self, const cv::Mat& other) -> cv::Mat&
    {
      self += other;
      return self;
    }).
    define_method("assign_plus", [](const cv::Mat& self, const cv::Mat& other) -> const cv::Mat&
    {
      return self += other;
    }).
    define_method("assign_plus", [](cv::Mat& self, const cv::Scalar& other) -> cv::Mat&
    {
      self += other;
      return self;
    }).
    define_method("assign_plus", [](const cv::Mat& self, const cv::Scalar& other) -> const cv::Mat&
    {
      return self += other;
    }).
    define_method("assign_minus", [](cv::Mat& self, const cv::Mat& other) -> cv::Mat&
    {
      self -= other;
      return self;
    }).
    define_method("assign_minus", [](const cv::Mat& self, const cv::Mat& other) -> const cv::Mat&
    {
      return self -= other;
    }).
    define_method("assign_minus", [](cv::Mat& self, const cv::Scalar& other) -> cv::Mat&
    {
      self -= other;
      return self;
    }).
    define_method("assign_minus", [](const cv::Mat& self, const cv::Scalar& other) -> const cv::Mat&
    {
      return self -= other;
    }).
    define_method("assign_multiply", [](cv::Mat& self, const cv::Mat& other) -> cv::Mat&
    {
      self *= other;
      return self;
    }).
    define_method("assign_multiply", [](const cv::Mat& self, const cv::Mat& other) -> const cv::Mat&
    {
      return self *= other;
    }).
    define_method("assign_multiply", [](cv::Mat& self, const double& other) -> cv::Mat&
    {
      self *= other;
      return self;
    }).
    define_method("assign_multiply", [](const cv::Mat& self, const double& other) -> const cv::Mat&
    {
      return self *= other;
    }).
    define_method("assign_divide", [](cv::Mat& self, const cv::Mat& other) -> cv::Mat&
    {
      self /= other;
      return self;
    }).
    define_method("assign_divide", [](const cv::Mat& self, const cv::Mat& other) -> const cv::Mat&
    {
      return self /= other;
    }).
    define_method("assign_divide", [](cv::Mat& self, const double& other) -> cv::Mat&
    {
      self /= other;
      return self;
    }).
    define_method("assign_divide", [](const cv::Mat& self, const double& other) -> const cv::Mat&
    {
      return self /= other;
    }).
    define_method("assign_and", [](cv::Mat& self, const cv::Mat& other) -> cv::Mat&
    {
      self &= other;
      return self;
    }).
    define_method("assign_and", [](const cv::Mat& self, const cv::Mat& other) -> const cv::Mat&
    {
      return self &= other;
    }).
    define_method("assign_and", [](cv::Mat& self, const cv::Scalar& other) -> cv::Mat&
    {
      self &= other;
      return self;
    }).
    define_method("assign_and", [](const cv::Mat& self, const cv::Scalar& other) -> const cv::Mat&
    {
      return self &= other;
    }).
    define_method("assign_or", [](cv::Mat& self, const cv::Mat& other) -> cv::Mat&
    {
      self |= other;
      return self;
    }).
    define_method("assign_or", [](const cv::Mat& self, const cv::Mat& other) -> const cv::Mat&
    {
      return self |= other;
    }).
    define_method("assign_or", [](cv::Mat& self, const cv::Scalar& other) -> cv::Mat&
    {
      self |= other;
      return self;
    }).
    define_method("assign_or", [](const cv::Mat& self, const cv::Scalar& other) -> const cv::Mat&
    {
      return self |= other;
    }).
    define_method("assign_xor", [](cv::Mat& self, const cv::Mat& other) -> cv::Mat&
    {
      self ^= other;
      return self;
    }).
    define_method("assign_xor", [](const cv::Mat& self, const cv::Mat& other) -> const cv::Mat&
    {
      return self ^= other;
    }).
    define_method("assign_xor", [](cv::Mat& self, const cv::Scalar& other) -> cv::Mat&
    {
      self ^= other;
      return self;
    }).
    define_method("assign_xor", [](const cv::Mat& self, const cv::Scalar& other) -> const cv::Mat&
    {
      return self ^= other;
    });
}