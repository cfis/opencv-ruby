#include <opencv2/cudev/ptr2d/lut.hpp>
#include "lut-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename SrcPtr, typename TablePtr>
inline void LutPtr_builder(Data_Type_T& klass)
{
  klass.define_attr("src", &cv::cudev::LutPtr<SrcPtr, TablePtr>::src).
    define_attr("tbl", &cv::cudev::LutPtr<SrcPtr, TablePtr>::tbl).
    template define_method<typename PtrTraits<TablePtr>::value_type(cv::cudev::LutPtr<SrcPtr, TablePtr>::*)(typename PtrTraits<SrcPtr>::index_type, typename PtrTraits<SrcPtr>::index_type) const>("call", &cv::cudev::LutPtr<SrcPtr, TablePtr>::operator(),
      Arg("y"), Arg("x"));
};

template<typename Data_Type_T, typename SrcPtr, typename TablePtr>
inline void LutPtrSz_builder(Data_Type_T& klass)
{
  klass.define_attr("rows", &cv::cudev::LutPtrSz<SrcPtr, TablePtr>::rows).
    define_attr("cols", &cv::cudev::LutPtrSz<SrcPtr, TablePtr>::cols);
};

void Init_Cudev_Ptr2d_Lut()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
}