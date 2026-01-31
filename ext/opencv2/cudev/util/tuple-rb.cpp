#include <opencv2/cudev/util/tuple.hpp>
#include "tuple-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename T>
inline void TupleTraits_builder(Data_Type_T& klass)
{
  klass.define_constant("Is_tuple", (int)cv::cudev::TupleTraits<T>::is_tuple).
    define_constant("Size", (int)cv::cudev::TupleTraits<T>::size);
};

void Init_Cudev_Util_Tuple()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
}