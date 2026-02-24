#include <opencv2/core/mat.hpp>
#include <opencv2/core/mat.inl.hpp>
#include "mat.inl-rb.hpp"

using namespace Rice;

void Init_Core_MatInl()
{
  Module rb_mCv = define_module("Cv");

  rb_mCv.define_module_function<void(*)(cv::MatExpr&, cv::MatExpr&)>("swap", &cv::swap,
    Arg("a"), Arg("b"));

  Data_Type<cv::MatConstIterator>().
    define_method("==", [](const cv::MatConstIterator& self, const cv::MatConstIterator& other) -> bool
    {
      return self == other;
    }).
    define_method("!=", [](const cv::MatConstIterator& self, const cv::MatConstIterator& other) -> bool
    {
      return self != other;
    }).
    define_method("<", [](const cv::MatConstIterator& self, const cv::MatConstIterator& other) -> bool
    {
      return self < other;
    }).
    define_method(">", [](const cv::MatConstIterator& self, const cv::MatConstIterator& other) -> bool
    {
      return self > other;
    }).
    define_method("<=", [](const cv::MatConstIterator& self, const cv::MatConstIterator& other) -> bool
    {
      return self <= other;
    }).
    define_method(">=", [](const cv::MatConstIterator& self, const cv::MatConstIterator& other) -> bool
    {
      return self >= other;
    }).
    define_method("-", [](const cv::MatConstIterator& self, const cv::MatConstIterator& other) -> ptrdiff_t
    {
      return self - other;
    }).
    define_method("+", [](const cv::MatConstIterator& self, ptrdiff_t other) -> cv::MatConstIterator
    {
      return self + other;
    }).
    define_method("-", [](const cv::MatConstIterator& self, ptrdiff_t other) -> cv::MatConstIterator
    {
      return self - other;
    });

  Data_Type<cv::SparseMatConstIterator>().
    define_method("==", [](const cv::SparseMatConstIterator& self, const cv::SparseMatConstIterator& other) -> bool
    {
      return self == other;
    }).
    define_method("!=", [](const cv::SparseMatConstIterator& self, const cv::SparseMatConstIterator& other) -> bool
    {
      return self != other;
    });
  
  Data_Type<cv::Mat>().
    define_method("assign_plus", [](cv::Mat& self, const cv::MatExpr& other) -> cv::Mat&
    {
      self += other;
      return self;
    }).
    define_method("assign_plus", [](const cv::Mat& self, const cv::MatExpr& other) -> const cv::Mat&
    {
      return self += other;
    }).
    define_method("assign_minus", [](cv::Mat& self, const cv::MatExpr& other) -> cv::Mat&
    {
      self -= other;
      return self;
    }).
    define_method("assign_minus", [](const cv::Mat& self, const cv::MatExpr& other) -> const cv::Mat&
    {
      return self -= other;
    }).
    define_method("assign_multiply", [](cv::Mat& self, const cv::MatExpr& other) -> cv::Mat&
    {
      self *= other;
      return self;
    }).
    define_method("assign_multiply", [](const cv::Mat& self, const cv::MatExpr& other) -> const cv::Mat&
    {
      return self *= other;
    }).
    define_method("assign_divide", [](cv::Mat& self, const cv::MatExpr& other) -> cv::Mat&
    {
      self /= other;
      return self;
    }).
    define_method("assign_divide", [](const cv::Mat& self, const cv::MatExpr& other) -> const cv::Mat&
    {
      return self /= other;
    });
}
