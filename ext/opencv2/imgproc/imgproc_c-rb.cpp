#include <opencv2/imgproc/imgproc_c.h>
#include "imgproc_c-rb.hpp"

using namespace Rice;

void Init_Imgproc_ImgprocC()
{
  Class(rb_cObject).define_constant("CV_AA", CV_AA);

  Class(rb_cObject).define_constant("CV_FONT_HERSHEY_SIMPLEX", CV_FONT_HERSHEY_SIMPLEX);

  Class(rb_cObject).define_constant("CV_FONT_HERSHEY_PLAIN", CV_FONT_HERSHEY_PLAIN);

  Class(rb_cObject).define_constant("CV_FONT_HERSHEY_DUPLEX", CV_FONT_HERSHEY_DUPLEX);

  Class(rb_cObject).define_constant("CV_FONT_HERSHEY_COMPLEX", CV_FONT_HERSHEY_COMPLEX);

  Class(rb_cObject).define_constant("CV_FONT_HERSHEY_TRIPLEX", CV_FONT_HERSHEY_TRIPLEX);

  Class(rb_cObject).define_constant("CV_FONT_HERSHEY_COMPLEX_SMALL", CV_FONT_HERSHEY_COMPLEX_SMALL);

  Class(rb_cObject).define_constant("CV_FONT_HERSHEY_SCRIPT_SIMPLEX", CV_FONT_HERSHEY_SCRIPT_SIMPLEX);

  Class(rb_cObject).define_constant("CV_FONT_HERSHEY_SCRIPT_COMPLEX", CV_FONT_HERSHEY_SCRIPT_COMPLEX);

  Class(rb_cObject).define_constant("CV_FONT_ITALIC", CV_FONT_ITALIC);
}
