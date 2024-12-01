#include <rice/rice.hpp>
#include <rice/stl.hpp>

#include <opencv2/core/traits.hpp>
#include "hal/interface-rb.hpp"

// From OpenCV5. See https://github.com/opencv/opencv/pull/23865/. Just a hack for defining cv::Vec<int64, 2>
template<>
class cv::DataType<int64_t>
{
public:
  typedef unsigned    value_type;
  typedef value_type  work_type;
  typedef value_type  channel_type;
  typedef value_type  vec_type;
  enum {
    generic_type = 0,
    depth = CV_64S,
    channels = 1,
    fmt = (int)'L',
    type = CV_MAKETYPE(depth, channels)
  };
};

void Init_Traits();