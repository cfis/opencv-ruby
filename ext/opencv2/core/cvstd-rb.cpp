#include <opencv2/core/cvstd.hpp>
#include "cvstd-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename _Tp>
inline void Allocator_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::Allocator<_Tp>>()).
    define_constructor(Constructor<cv::Allocator<_Tp>, const cv::Allocator<_Tp>&>(),
      Arg("")).
    template define_method<typename cv::Allocator<_Tp>::pointer(cv::Allocator<_Tp>::*)(typename cv::Allocator<_Tp>::reference)>("address", &cv::Allocator<_Tp>::address,
      Arg("r")).
    template define_method<typename cv::Allocator<_Tp>::const_pointer(cv::Allocator<_Tp>::*)(typename cv::Allocator<_Tp>::const_reference)>("address", &cv::Allocator<_Tp>::address,
      Arg("r")).
    template define_method("allocate", &cv::Allocator<_Tp>::allocate,
      Arg("count"), Arg("") = static_cast<const void *>(0)).
    template define_method("deallocate", &cv::Allocator<_Tp>::deallocate,
      Arg("p"), Arg("")).
    template define_method("construct", &cv::Allocator<_Tp>::construct,
      Arg("p"), Arg("v")).
    template define_method("destroy", &cv::Allocator<_Tp>::destroy,
      Arg("p")).
    template define_method("max_size", &cv::Allocator<_Tp>::max_size);
};

template<typename Data_Type_T, typename U>
inline void rebind_builder(Data_Type_T& klass)
{
};

void Init_Cvstd()
{
  Module rb_mCv = define_module("Cv");
  
  rb_mCv.define_module_function<uchar(*)(uchar)>("abs", &cv::abs,
    Arg("a"));
  
  rb_mCv.define_module_function<ushort(*)(ushort)>("abs", &cv::abs,
    Arg("a"));
  
  rb_mCv.define_module_function<unsigned int(*)(unsigned int)>("abs", &cv::abs,
    Arg("a"));
  
  rb_mCv.define_module_function<uint64(*)(uint64)>("abs", &cv::abs,
    Arg("a"));
  
  rb_mCv.define_module_function("fast_malloc", &cv::fastMalloc,
    Arg("buf_size"));
  
  rb_mCv.define_module_function("fast_free", &cv::fastFree,
    Arg("ptr"));
  
  Module rb_mCvDetails = define_module_under(rb_mCv, "Details");
  
  rb_mCvDetails.define_module_function("char_tolower", &cv::details::char_tolower,
    Arg("ch"));
  
  rb_mCvDetails.define_module_function("char_toupper", &cv::details::char_toupper,
    Arg("ch"));
  
  rb_mCv.define_module_function("to_lower_case", &cv::toLowerCase,
    Arg("str"));
  
  rb_mCv.define_module_function("to_upper_case", &cv::toUpperCase,
    Arg("str"));

}