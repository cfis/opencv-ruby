#include <opencv2/cudev/ptr2d/texture.hpp>
#include "texture-rb.hpp"

using namespace Rice;

#include "texture-rb.ipp"

void Init_Cudev_Ptr2d_Texture()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
}
