#include <opencv2/photo/legacy/constants_c.h>
#include "constants_c-rb.hpp"

using namespace Rice;

void Init_Photo_Legacy_ConstantsC()
{
  Enum<InpaintingModes> rb_cInpaintingModes = define_enum<InpaintingModes>("InpaintingModes").
    define_value("CV_INPAINT_NS", InpaintingModes::CV_INPAINT_NS).
    define_value("CV_INPAINT_TELEA", InpaintingModes::CV_INPAINT_TELEA);
}
