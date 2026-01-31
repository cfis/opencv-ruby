#include <opencv2/videostab/ring_buffer.hpp>
#include "ring_buffer-rb.hpp"

using namespace Rice;

void Init_Videostab_RingBuffer()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvVideostab = define_module_under(rb_mCv, "Videostab");
}