#include <opencv2/cudev/block/block.hpp>
#include "block-rb.hpp"

using namespace Rice;

void Init_Cudev_Block_Block()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");

  Rice::Data_Type<cv::cudev::Block> rb_cCvCudevBlock = define_class_under<cv::cudev::Block>(rb_mCvCudev, "Block").
    define_constructor(Constructor<cv::cudev::Block>()).
    define_singleton_function<uint(*)()>("block_id", &cv::cudev::Block::blockId).
    define_singleton_function<uint(*)()>("block_size", &cv::cudev::Block::blockSize).
    define_singleton_function<uint(*)()>("thread_line_id", &cv::cudev::Block::threadLineId);
}
