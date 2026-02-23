#include <opencv2/cudev/grid/split_merge.hpp>
#include "split_merge-rb.hpp"

using namespace Rice;

void Init_Cudev_Grid_SplitMerge()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");

  Rice::Data_Type<cv::cudev::DefaultSplitMergePolicy> rb_cCvCudevDefaultSplitMergePolicy = define_class_under<cv::cudev::DefaultSplitMergePolicy>(rb_mCvCudev, "DefaultSplitMergePolicy").
    define_constructor(Constructor<cv::cudev::DefaultSplitMergePolicy>());

  rb_cCvCudevDefaultSplitMergePolicy.define_constant("Block_size_x", (int)cv::cudev::DefaultSplitMergePolicy::block_size_x);
  rb_cCvCudevDefaultSplitMergePolicy.define_constant("Block_size_y", (int)cv::cudev::DefaultSplitMergePolicy::block_size_y);
}
