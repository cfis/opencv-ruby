#include <opencv2/opencv.hpp>
#include <opencv2/core/bufferpool.hpp>
#include "bufferpool-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvBufferPoolController;

void Init_Bufferpool()
{
  Module rb_mCv = define_module("Cv");
  
  rb_cCvBufferPoolController = define_class_under<cv::BufferPoolController>(rb_mCv, "BufferPoolController").
    define_method("get_reserved_size", &cv::BufferPoolController::getReservedSize).
    define_method("get_max_reserved_size", &cv::BufferPoolController::getMaxReservedSize).
    define_method("set_max_reserved_size", &cv::BufferPoolController::setMaxReservedSize,
      Arg("size")).
    define_method("free_all_reserved_buffers", &cv::BufferPoolController::freeAllReservedBuffers);

}