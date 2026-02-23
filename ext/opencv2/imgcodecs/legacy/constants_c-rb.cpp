#include <opencv2/imgcodecs/legacy/constants_c.h>
#include "constants_c-rb.hpp"

using namespace Rice;

void Init_Imgcodecs_Legacy_ConstantsC()
{
  Class(rb_cObject).define_constant("CV_LOAD_IMAGE_UNCHANGED", (int)::CV_LOAD_IMAGE_UNCHANGED);
  Class(rb_cObject).define_constant("CV_LOAD_IMAGE_GRAYSCALE", (int)::CV_LOAD_IMAGE_GRAYSCALE);
  Class(rb_cObject).define_constant("CV_LOAD_IMAGE_COLOR", (int)::CV_LOAD_IMAGE_COLOR);
  Class(rb_cObject).define_constant("CV_LOAD_IMAGE_ANYDEPTH", (int)::CV_LOAD_IMAGE_ANYDEPTH);
  Class(rb_cObject).define_constant("CV_LOAD_IMAGE_ANYCOLOR", (int)::CV_LOAD_IMAGE_ANYCOLOR);
  Class(rb_cObject).define_constant("CV_LOAD_IMAGE_IGNORE_ORIENTATION", (int)::CV_LOAD_IMAGE_IGNORE_ORIENTATION);

  Class(rb_cObject).define_constant("CV_IMWRITE_JPEG_QUALITY", (int)::CV_IMWRITE_JPEG_QUALITY);
  Class(rb_cObject).define_constant("CV_IMWRITE_JPEG_PROGRESSIVE", (int)::CV_IMWRITE_JPEG_PROGRESSIVE);
  Class(rb_cObject).define_constant("CV_IMWRITE_JPEG_OPTIMIZE", (int)::CV_IMWRITE_JPEG_OPTIMIZE);
  Class(rb_cObject).define_constant("CV_IMWRITE_JPEG_RST_INTERVAL", (int)::CV_IMWRITE_JPEG_RST_INTERVAL);
  Class(rb_cObject).define_constant("CV_IMWRITE_JPEG_LUMA_QUALITY", (int)::CV_IMWRITE_JPEG_LUMA_QUALITY);
  Class(rb_cObject).define_constant("CV_IMWRITE_JPEG_CHROMA_QUALITY", (int)::CV_IMWRITE_JPEG_CHROMA_QUALITY);
  Class(rb_cObject).define_constant("CV_IMWRITE_PNG_COMPRESSION", (int)::CV_IMWRITE_PNG_COMPRESSION);
  Class(rb_cObject).define_constant("CV_IMWRITE_PNG_STRATEGY", (int)::CV_IMWRITE_PNG_STRATEGY);
  Class(rb_cObject).define_constant("CV_IMWRITE_PNG_BILEVEL", (int)::CV_IMWRITE_PNG_BILEVEL);
  Class(rb_cObject).define_constant("CV_IMWRITE_PNG_STRATEGY_DEFAULT", (int)::CV_IMWRITE_PNG_STRATEGY_DEFAULT);
  Class(rb_cObject).define_constant("CV_IMWRITE_PNG_STRATEGY_FILTERED", (int)::CV_IMWRITE_PNG_STRATEGY_FILTERED);
  Class(rb_cObject).define_constant("CV_IMWRITE_PNG_STRATEGY_HUFFMAN_ONLY", (int)::CV_IMWRITE_PNG_STRATEGY_HUFFMAN_ONLY);
  Class(rb_cObject).define_constant("CV_IMWRITE_PNG_STRATEGY_RLE", (int)::CV_IMWRITE_PNG_STRATEGY_RLE);
  Class(rb_cObject).define_constant("CV_IMWRITE_PNG_STRATEGY_FIXED", (int)::CV_IMWRITE_PNG_STRATEGY_FIXED);
  Class(rb_cObject).define_constant("CV_IMWRITE_PXM_BINARY", (int)::CV_IMWRITE_PXM_BINARY);
  Class(rb_cObject).define_constant("CV_IMWRITE_EXR_TYPE", (int)::CV_IMWRITE_EXR_TYPE);
  Class(rb_cObject).define_constant("CV_IMWRITE_WEBP_QUALITY", (int)::CV_IMWRITE_WEBP_QUALITY);
  Class(rb_cObject).define_constant("CV_IMWRITE_PAM_TUPLETYPE", (int)::CV_IMWRITE_PAM_TUPLETYPE);
  Class(rb_cObject).define_constant("CV_IMWRITE_PAM_FORMAT_NULL", (int)::CV_IMWRITE_PAM_FORMAT_NULL);
  Class(rb_cObject).define_constant("CV_IMWRITE_PAM_FORMAT_BLACKANDWHITE", (int)::CV_IMWRITE_PAM_FORMAT_BLACKANDWHITE);
  Class(rb_cObject).define_constant("CV_IMWRITE_PAM_FORMAT_GRAYSCALE", (int)::CV_IMWRITE_PAM_FORMAT_GRAYSCALE);
  Class(rb_cObject).define_constant("CV_IMWRITE_PAM_FORMAT_GRAYSCALE_ALPHA", (int)::CV_IMWRITE_PAM_FORMAT_GRAYSCALE_ALPHA);
  Class(rb_cObject).define_constant("CV_IMWRITE_PAM_FORMAT_RGB", (int)::CV_IMWRITE_PAM_FORMAT_RGB);
  Class(rb_cObject).define_constant("CV_IMWRITE_PAM_FORMAT_RGB_ALPHA", (int)::CV_IMWRITE_PAM_FORMAT_RGB_ALPHA);
}
