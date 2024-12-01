#include <opencv2/core/core.hpp>
#include <opencv2/core/operations.hpp>
#include "cvstd_wrapper-rb.hpp"
#include "operations-rb.hpp"

using namespace Rice;
template<typename Data_Type_T, typename _Tp, int m, int n>
inline void Matx_FastInvOp_builder(Data_Type_T& klass)
{
  klass.template define_method("call", &cv::internal::Matx_FastInvOp<_Tp, m, n>::operator(),
      Arg("a"), Arg("b"), Arg("method"));
};

template<typename Data_Type_T, typename _Tp, int m, int l, int n>
inline void Matx_FastSolveOp_builder(Data_Type_T& klass)
{
  klass.template define_method("call", &cv::internal::Matx_FastSolveOp<_Tp, m, l, n>::operator(),
      Arg("a"), Arg("b"), Arg("x"), Arg("method"));
};

void Init_Operations()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvInternal = define_module_under(rb_mCv, "Internal");
  
  rb_mCv.define_module_function<cv::Ptr<cv::Formatted>(*)(cv::InputArray, cv::Formatter::FormatType)>("format", &cv::format,
    Arg("mtx"), Arg("fmt"));

  //rb_mCv.define_module_function<int(*)(cv::Ptr<cv::Formatted>, ::FILE*)>("print", &cv::print,
  //  Arg("fmtd"), Arg("stream") = static_cast<FILE *>(stdout));
  
  //rb_mCv.define_module_function<int(*)(const cv::Mat&, ::FILE*)>("print", &cv::print,
  //  Arg("mtx"), Arg("stream") = static_cast<FILE *>(stdout));
  
  //rb_mCv.define_module_function<int(*)(const cv::UMat&, ::FILE*)>("print", &cv::print,
  //  Arg("mtx"), Arg("stream") = static_cast<FILE *>(stdout));
  
  //rb_mCv.define_module_function<cv::String(*)(const char*)>("format", &cv::format,
   // Arg("fmt"));

}