#include <opencv2/cudev/ptr2d/deriv.hpp>
#include "deriv-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename SrcPtr>
inline void DerivXPtr_builder(Data_Type_T& klass)
{
  klass.define_attr("src", &cv::cudev::DerivXPtr<SrcPtr>::src).
    template define_method<typename PtrTraits<SrcPtr>::value_type(cv::cudev::DerivXPtr<SrcPtr>::*)(int, int) const>("call", &cv::cudev::DerivXPtr<SrcPtr>::operator(),
      Arg("y"), Arg("x"));
};

template<typename Data_Type_T, typename SrcPtr>
inline void DerivXPtrSz_builder(Data_Type_T& klass)
{
  klass.define_attr("rows", &cv::cudev::DerivXPtrSz<SrcPtr>::rows).
    define_attr("cols", &cv::cudev::DerivXPtrSz<SrcPtr>::cols);
};

template<typename Data_Type_T, typename SrcPtr>
inline void DerivYPtr_builder(Data_Type_T& klass)
{
  klass.define_attr("src", &cv::cudev::DerivYPtr<SrcPtr>::src).
    template define_method<typename PtrTraits<SrcPtr>::value_type(cv::cudev::DerivYPtr<SrcPtr>::*)(int, int) const>("call", &cv::cudev::DerivYPtr<SrcPtr>::operator(),
      Arg("y"), Arg("x"));
};

template<typename Data_Type_T, typename SrcPtr>
inline void DerivYPtrSz_builder(Data_Type_T& klass)
{
  klass.define_attr("rows", &cv::cudev::DerivYPtrSz<SrcPtr>::rows).
    define_attr("cols", &cv::cudev::DerivYPtrSz<SrcPtr>::cols);
};

template<typename Data_Type_T, typename SrcPtr>
inline void SobelXPtr_builder(Data_Type_T& klass)
{
  klass.define_attr("src", &cv::cudev::SobelXPtr<SrcPtr>::src).
    template define_method<typename PtrTraits<SrcPtr>::value_type(cv::cudev::SobelXPtr<SrcPtr>::*)(int, int) const>("call", &cv::cudev::SobelXPtr<SrcPtr>::operator(),
      Arg("y"), Arg("x"));
};

template<typename Data_Type_T, typename SrcPtr>
inline void SobelXPtrSz_builder(Data_Type_T& klass)
{
  klass.define_attr("rows", &cv::cudev::SobelXPtrSz<SrcPtr>::rows).
    define_attr("cols", &cv::cudev::SobelXPtrSz<SrcPtr>::cols);
};

template<typename Data_Type_T, typename SrcPtr>
inline void SobelYPtr_builder(Data_Type_T& klass)
{
  klass.define_attr("src", &cv::cudev::SobelYPtr<SrcPtr>::src).
    template define_method<typename PtrTraits<SrcPtr>::value_type(cv::cudev::SobelYPtr<SrcPtr>::*)(int, int) const>("call", &cv::cudev::SobelYPtr<SrcPtr>::operator(),
      Arg("y"), Arg("x"));
};

template<typename Data_Type_T, typename SrcPtr>
inline void SobelYPtrSz_builder(Data_Type_T& klass)
{
  klass.define_attr("rows", &cv::cudev::SobelYPtrSz<SrcPtr>::rows).
    define_attr("cols", &cv::cudev::SobelYPtrSz<SrcPtr>::cols);
};

template<typename Data_Type_T, typename SrcPtr>
inline void ScharrXPtr_builder(Data_Type_T& klass)
{
  klass.define_attr("src", &cv::cudev::ScharrXPtr<SrcPtr>::src).
    template define_method<typename PtrTraits<SrcPtr>::value_type(cv::cudev::ScharrXPtr<SrcPtr>::*)(int, int) const>("call", &cv::cudev::ScharrXPtr<SrcPtr>::operator(),
      Arg("y"), Arg("x"));
};

template<typename Data_Type_T, typename SrcPtr>
inline void ScharrXPtrSz_builder(Data_Type_T& klass)
{
  klass.define_attr("rows", &cv::cudev::ScharrXPtrSz<SrcPtr>::rows).
    define_attr("cols", &cv::cudev::ScharrXPtrSz<SrcPtr>::cols);
};

template<typename Data_Type_T, typename SrcPtr>
inline void ScharrYPtr_builder(Data_Type_T& klass)
{
  klass.define_attr("src", &cv::cudev::ScharrYPtr<SrcPtr>::src).
    template define_method<typename PtrTraits<SrcPtr>::value_type(cv::cudev::ScharrYPtr<SrcPtr>::*)(int, int) const>("call", &cv::cudev::ScharrYPtr<SrcPtr>::operator(),
      Arg("y"), Arg("x"));
};

template<typename Data_Type_T, typename SrcPtr>
inline void ScharrYPtrSz_builder(Data_Type_T& klass)
{
  klass.define_attr("rows", &cv::cudev::ScharrYPtrSz<SrcPtr>::rows).
    define_attr("cols", &cv::cudev::ScharrYPtrSz<SrcPtr>::cols);
};

template<typename Data_Type_T, int ksize, typename SrcPtr>
inline void LaplacianPtrSz_builder(Data_Type_T& klass)
{
  klass.define_attr("rows", &cv::cudev::LaplacianPtrSz<ksize, SrcPtr>::rows).
    define_attr("cols", &cv::cudev::LaplacianPtrSz<ksize, SrcPtr>::cols);
};

