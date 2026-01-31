#include <opencv2/cudev/ptr2d/glob.hpp>
#include "glob-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename T>
inline void GlobPtr_builder(Data_Type_T& klass)
{
  klass.define_attr("data", &cv::cudev::GlobPtr<T>::data).
    define_attr("step", &cv::cudev::GlobPtr<T>::step).
    template define_method<T*(cv::cudev::GlobPtr<T>::*)(int)>("row", &cv::cudev::GlobPtr<T>::row,
      Arg("y")).
    template define_method<const T*(cv::cudev::GlobPtr<T>::*)(int) const>("row", &cv::cudev::GlobPtr<T>::row,
      Arg("y")).
    template define_method<T&(cv::cudev::GlobPtr<T>::*)(int, int)>("call", &cv::cudev::GlobPtr<T>::operator(),
      Arg("y"), Arg("x")).
    template define_method<const T&(cv::cudev::GlobPtr<T>::*)(int, int) const>("call", &cv::cudev::GlobPtr<T>::operator(),
      Arg("y"), Arg("x"));
};

template<typename Data_Type_T, typename T>
inline void GlobPtrSz_builder(Data_Type_T& klass)
{
  klass.define_attr("rows", &cv::cudev::GlobPtrSz<T>::rows).
    define_attr("cols", &cv::cudev::GlobPtrSz<T>::cols);
};

void Init_Cudev_Ptr2d_Glob()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
}