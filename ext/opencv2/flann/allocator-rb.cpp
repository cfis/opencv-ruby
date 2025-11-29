#include <opencv2/flann/allocator.h>
#include "allocator-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvflannPooledAllocator;

void Init_Allocator()
{
  Module rb_mCvflann = define_module("Cvflann");
  
  rb_mCvflann.define_constant("WORDSIZE", cvflann::WORDSIZE);
  
  rb_mCvflann.define_constant("BLOCKSIZE", cvflann::BLOCKSIZE);
  
  rb_cCvflannPooledAllocator = define_class_under<cvflann::PooledAllocator>(rb_mCvflann, "PooledAllocator").
    define_attr("used_memory", &cvflann::PooledAllocator::usedMemory).
    define_attr("wasted_memory", &cvflann::PooledAllocator::wastedMemory).
    define_constructor(Constructor<cvflann::PooledAllocator, int>(),
      Arg("block_size") = static_cast<int>(cvflann::BLOCKSIZE)).
    define_method("allocate_memory", &cvflann::PooledAllocator::allocateMemory,
      Arg("size"));

}