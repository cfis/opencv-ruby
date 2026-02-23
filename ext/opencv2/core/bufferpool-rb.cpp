#include <opencv2/core/bufferpool.hpp>
#include "bufferpool-rb.hpp"

using namespace Rice;

void Init_Core_Bufferpool()
{
  Module rb_mCv = define_module("Cv");

  Rice::Data_Type<cv::BufferPoolController> rb_cCvBufferPoolController = define_class_under<cv::BufferPoolController>(rb_mCv, "BufferPoolController").
    define_method<size_t(cv::BufferPoolController::*)() const>("get_reserved_size", &cv::BufferPoolController::getReservedSize).
    define_method<size_t(cv::BufferPoolController::*)() const>("get_max_reserved_size", &cv::BufferPoolController::getMaxReservedSize).
    define_method<void(cv::BufferPoolController::*)(size_t)>("set_max_reserved_size", &cv::BufferPoolController::setMaxReservedSize,
      Arg("size")).
    define_method<void(cv::BufferPoolController::*)()>("free_all_reserved_buffers", &cv::BufferPoolController::freeAllReservedBuffers);
}
