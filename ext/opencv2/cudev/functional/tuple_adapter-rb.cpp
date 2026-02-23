#include <opencv2/cudev/functional/tuple_adapter.hpp>
#include "tuple_adapter-rb.hpp"

using namespace Rice;

#include "tuple_adapter-rb.ipp"

void Init_Cudev_Functional_TupleAdapter()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
}
