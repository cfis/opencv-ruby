#include <opencv2/core/cvstd.hpp>
#include "cvstd-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename _Tp>
inline void Allocator_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::Allocator<_Tp>>()).
    define_constructor(Constructor<cv::Allocator<_Tp>, const cv::Allocator<_Tp>&>(),
      Arg("arg_0")).
    template define_method<typename cv::Allocator<_Tp>::pointer(cv::Allocator<_Tp>::*)(typename cv::Allocator<_Tp>::reference)>("address", &cv::Allocator<_Tp>::address,
      Arg("r")).
    template define_method<typename cv::Allocator<_Tp>::const_pointer(cv::Allocator<_Tp>::*)(typename cv::Allocator<_Tp>::const_reference)>("address", &cv::Allocator<_Tp>::address,
      Arg("r")).
    template define_method<typename cv::Allocator<_Tp>::pointer(cv::Allocator<_Tp>::*)(typename cv::Allocator<_Tp>::size_type, const void*)>("allocate", &cv::Allocator<_Tp>::allocate,
      Arg("count"), ArgBuffer("arg_1") = static_cast<const void*>(0)).
    template define_method<void(cv::Allocator<_Tp>::*)(typename cv::Allocator<_Tp>::pointer, typename cv::Allocator<_Tp>::size_type)>("deallocate", &cv::Allocator<_Tp>::deallocate,
      Arg("p"), Arg("arg_1")).
    template define_method<void(cv::Allocator<_Tp>::*)(typename cv::Allocator<_Tp>::pointer, const _Tp&)>("construct", &cv::Allocator<_Tp>::construct,
      Arg("p"), Arg("v")).
    template define_method<void(cv::Allocator<_Tp>::*)(typename cv::Allocator<_Tp>::pointer)>("destroy", &cv::Allocator<_Tp>::destroy,
      Arg("p")).
    template define_method<typename cv::Allocator<_Tp>::size_type(cv::Allocator<_Tp>::*)() const>("max_size", &cv::Allocator<_Tp>::max_size);
};

void Init_Core_Cvstd()
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

  rb_mCv.define_module_function<void*(*)(size_t)>("fast_malloc", &cv::fastMalloc,
    Arg("buf_size"), ReturnBuffer());

  rb_mCv.define_module_function<void(*)(void*)>("fast_free", &cv::fastFree,
    ArgBuffer("ptr"));

  Module rb_mCvDetails = define_module_under(rb_mCv, "Details");

  rb_mCvDetails.define_module_function<char(*)(char)>("char_tolower", &cv::details::char_tolower,
    Arg("ch"));

  rb_mCvDetails.define_module_function<char(*)(char)>("char_toupper", &cv::details::char_toupper,
    Arg("ch"));

  rb_mCv.define_module_function<std::string(*)(const std::string&)>("to_lower_case", &cv::toLowerCase,
    Arg("str"));

  rb_mCv.define_module_function<std::string(*)(const std::string&)>("to_upper_case", &cv::toUpperCase,
    Arg("str"));
}