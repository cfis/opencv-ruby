#include <opencv2/cudev/ptr2d/traits.hpp>
#include "traits-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename Ptr2DSz, typename Ptr2D>
inline void PtrTraitsBase_builder(Data_Type_T& klass)
{
  klass.template define_singleton_function<Ptr2D(*)(const Ptr2DSz&)>("shrink_ptr", &cv::cudev::PtrTraitsBase<Ptr2DSz, Ptr2D>::shrinkPtr,
      Arg("ptr")).
    template define_singleton_function<int(*)(const Ptr2DSz&)>("get_rows", &cv::cudev::PtrTraitsBase<Ptr2DSz, Ptr2D>::getRows,
      Arg("ptr")).
    template define_singleton_function<int(*)(const Ptr2DSz&)>("get_cols", &cv::cudev::PtrTraitsBase<Ptr2DSz, Ptr2D>::getCols,
      Arg("ptr"));
};

void Init_Cudev_Ptr2d_Traits()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
}