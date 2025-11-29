#include <rice/rice.hpp>
#include <rice/stl.hpp>
#include <opencv2/core/hal/interface.h>

// From OpenCV5. See https://github.com/opencv/opencv/pull/23865
#define CV_16BF 8
#define CV_Bool 9
#define CV_64U  10
#define CV_64S  11
#define CV_32U  12

extern "C"
void Init_Interface();