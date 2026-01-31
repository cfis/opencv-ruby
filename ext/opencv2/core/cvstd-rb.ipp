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

