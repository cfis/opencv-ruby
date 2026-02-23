#include <opencv2/cudev/grid/reduce_to_vec.hpp>
#include "reduce_to_vec-rb.hpp"

using namespace Rice;

#include "reduce_to_vec-rb.ipp"

void Init_Cudev_Grid_ReduceToVec()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");

  Rice::Data_Type<cv::cudev::DefaultReduceToVecPolicy> rb_cCvCudevDefaultReduceToVecPolicy = define_class_under<cv::cudev::DefaultReduceToVecPolicy>(rb_mCvCudev, "DefaultReduceToVecPolicy").
    define_constructor(Constructor<cv::cudev::DefaultReduceToVecPolicy>());

  rb_cCvCudevDefaultReduceToVecPolicy.define_constant("Block_size_x", (int)cv::cudev::DefaultReduceToVecPolicy::block_size_x);
  rb_cCvCudevDefaultReduceToVecPolicy.define_constant("Block_size_y", (int)cv::cudev::DefaultReduceToVecPolicy::block_size_y);
}
