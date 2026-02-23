#include <opencv2/features2d/hal/interface.h>
#include "interface-rb.hpp"

using namespace Rice;

void Init_Features2d_Hal_Interface()
{
  Class(rb_cObject).define_constant("CV_HAL_TYPE_5_8", CV_HAL_TYPE_5_8);

  Class(rb_cObject).define_constant("CV_HAL_TYPE_7_12", CV_HAL_TYPE_7_12);

  Class(rb_cObject).define_constant("CV_HAL_TYPE_9_16", CV_HAL_TYPE_9_16);

  Rice::Data_Type<cvhalKeyPoint> rb_cCvhalKeyPoint = define_class<cvhalKeyPoint>("CvhalKeyPoint").
    define_constructor(Constructor<cvhalKeyPoint>()).
    define_attr("x", &cvhalKeyPoint::x).
    define_attr("y", &cvhalKeyPoint::y).
    define_attr("size", &cvhalKeyPoint::size).
    define_attr("angle", &cvhalKeyPoint::angle).
    define_attr("response", &cvhalKeyPoint::response).
    define_attr("octave", &cvhalKeyPoint::octave).
    define_attr("class_id", &cvhalKeyPoint::class_id);
}
