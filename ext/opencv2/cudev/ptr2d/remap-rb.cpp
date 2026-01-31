#include <opencv2/cudev/ptr2d/remap.hpp>
#include "remap-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename SrcPtr, typename MapPtr>
inline void RemapPtr1_builder(Data_Type_T& klass)
{
  klass.define_attr("src", &cv::cudev::RemapPtr1<SrcPtr, MapPtr>::src).
    define_attr("map", &cv::cudev::RemapPtr1<SrcPtr, MapPtr>::map).
    template define_method<typename PtrTraits<SrcPtr>::value_type(cv::cudev::RemapPtr1<SrcPtr, MapPtr>::*)(typename PtrTraits<MapPtr>::index_type, typename PtrTraits<MapPtr>::index_type) const>("call", &cv::cudev::RemapPtr1<SrcPtr, MapPtr>::operator(),
      Arg("y"), Arg("x"));
};

template<typename Data_Type_T, typename SrcPtr, typename MapXPtr, typename MapYPtr>
inline void RemapPtr2_builder(Data_Type_T& klass)
{
  klass.define_attr("src", &cv::cudev::RemapPtr2<SrcPtr, MapXPtr, MapYPtr>::src).
    define_attr("mapx", &cv::cudev::RemapPtr2<SrcPtr, MapXPtr, MapYPtr>::mapx).
    define_attr("mapy", &cv::cudev::RemapPtr2<SrcPtr, MapXPtr, MapYPtr>::mapy).
    template define_method<typename PtrTraits<SrcPtr>::value_type(cv::cudev::RemapPtr2<SrcPtr, MapXPtr, MapYPtr>::*)(typename PtrTraits<MapXPtr>::index_type, typename PtrTraits<MapXPtr>::index_type) const>("call", &cv::cudev::RemapPtr2<SrcPtr, MapXPtr, MapYPtr>::operator(),
      Arg("y"), Arg("x"));
};

template<typename Data_Type_T, typename SrcPtr, typename MapPtr>
inline void RemapPtr1Sz_builder(Data_Type_T& klass)
{
  klass.define_attr("rows", &cv::cudev::RemapPtr1Sz<SrcPtr, MapPtr>::rows).
    define_attr("cols", &cv::cudev::RemapPtr1Sz<SrcPtr, MapPtr>::cols);
};

template<typename Data_Type_T, typename SrcPtr, typename MapXPtr, typename MapYPtr>
inline void RemapPtr2Sz_builder(Data_Type_T& klass)
{
  klass.define_attr("rows", &cv::cudev::RemapPtr2Sz<SrcPtr, MapXPtr, MapYPtr>::rows).
    define_attr("cols", &cv::cudev::RemapPtr2Sz<SrcPtr, MapXPtr, MapYPtr>::cols);
};

void Init_Cudev_Ptr2d_Remap()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
}