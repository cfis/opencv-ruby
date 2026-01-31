#include <opencv2/cudev/util/limits.hpp>
#include "limits-rb.hpp"

using namespace Rice;

void Init_Cudev_Util_Limits()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");

  Rice::Data_Type<cv::cudev::numeric_limits<bool>> rb_cCvCudevNumericLimitsBool = define_class_under<cv::cudev::numeric_limits<bool>>(rb_mCvCudev, "NumericLimitsBool").
    define_constructor(Constructor<cv::cudev::numeric_limits<bool>>()).
    define_constant("Is_signed", cv::cudev::numeric_limits<bool>::is_signed).
    define_singleton_function<bool(*)()>("min?", &cv::cudev::numeric_limits<bool>::min).
    define_singleton_function<bool(*)()>("max?", &cv::cudev::numeric_limits<bool>::max);

  Rice::Data_Type<cv::cudev::numeric_limits<schar>> rb_cCvCudevNumericLimitsSchar = define_class_under<cv::cudev::numeric_limits<schar>>(rb_mCvCudev, "NumericLimitsSchar").
    define_constructor(Constructor<cv::cudev::numeric_limits<schar>>()).
    define_constant("Is_signed", cv::cudev::numeric_limits<schar>::is_signed).
    define_singleton_function<schar(*)()>("min", &cv::cudev::numeric_limits<schar>::min).
    define_singleton_function<schar(*)()>("max", &cv::cudev::numeric_limits<schar>::max);

  Rice::Data_Type<cv::cudev::numeric_limits<uchar>> rb_cCvCudevNumericLimitsUchar = define_class_under<cv::cudev::numeric_limits<uchar>>(rb_mCvCudev, "NumericLimitsUchar").
    define_constructor(Constructor<cv::cudev::numeric_limits<uchar>>()).
    define_constant("Is_signed", cv::cudev::numeric_limits<uchar>::is_signed).
    define_singleton_function<uchar(*)()>("min", &cv::cudev::numeric_limits<uchar>::min).
    define_singleton_function<uchar(*)()>("max", &cv::cudev::numeric_limits<uchar>::max);

  Rice::Data_Type<cv::cudev::numeric_limits<short>> rb_cCvCudevNumericLimitsShort = define_class_under<cv::cudev::numeric_limits<short>>(rb_mCvCudev, "NumericLimitsShort").
    define_constructor(Constructor<cv::cudev::numeric_limits<short>>()).
    define_constant("Is_signed", cv::cudev::numeric_limits<short>::is_signed).
    define_singleton_function<short(*)()>("min", &cv::cudev::numeric_limits<short>::min).
    define_singleton_function<short(*)()>("max", &cv::cudev::numeric_limits<short>::max);

  Rice::Data_Type<cv::cudev::numeric_limits<ushort>> rb_cCvCudevNumericLimitsUshort = define_class_under<cv::cudev::numeric_limits<ushort>>(rb_mCvCudev, "NumericLimitsUshort").
    define_constructor(Constructor<cv::cudev::numeric_limits<ushort>>()).
    define_constant("Is_signed", cv::cudev::numeric_limits<ushort>::is_signed).
    define_singleton_function<ushort(*)()>("min", &cv::cudev::numeric_limits<ushort>::min).
    define_singleton_function<ushort(*)()>("max", &cv::cudev::numeric_limits<ushort>::max);

  Rice::Data_Type<cv::cudev::numeric_limits<int>> rb_cCvCudevNumericLimitsInt = define_class_under<cv::cudev::numeric_limits<int>>(rb_mCvCudev, "NumericLimitsInt").
    define_constructor(Constructor<cv::cudev::numeric_limits<int>>()).
    define_constant("Is_signed", cv::cudev::numeric_limits<int>::is_signed).
    define_singleton_function<int(*)()>("min", &cv::cudev::numeric_limits<int>::min).
    define_singleton_function<int(*)()>("max", &cv::cudev::numeric_limits<int>::max);

  Rice::Data_Type<cv::cudev::numeric_limits<uint>> rb_cCvCudevNumericLimitsUint = define_class_under<cv::cudev::numeric_limits<uint>>(rb_mCvCudev, "NumericLimitsUint").
    define_constructor(Constructor<cv::cudev::numeric_limits<uint>>()).
    define_constant("Is_signed", cv::cudev::numeric_limits<uint>::is_signed).
    define_singleton_function<uint(*)()>("min", &cv::cudev::numeric_limits<uint>::min).
    define_singleton_function<uint(*)()>("max", &cv::cudev::numeric_limits<uint>::max);

  Rice::Data_Type<cv::cudev::numeric_limits<float>> rb_cCvCudevNumericLimitsFloat = define_class_under<cv::cudev::numeric_limits<float>>(rb_mCvCudev, "NumericLimitsFloat").
    define_constructor(Constructor<cv::cudev::numeric_limits<float>>()).
    define_constant("Is_signed", cv::cudev::numeric_limits<float>::is_signed).
    define_singleton_function<float(*)()>("min", &cv::cudev::numeric_limits<float>::min).
    define_singleton_function<float(*)()>("max", &cv::cudev::numeric_limits<float>::max).
    define_singleton_function<float(*)()>("epsilon", &cv::cudev::numeric_limits<float>::epsilon);

  Rice::Data_Type<cv::cudev::numeric_limits<double>> rb_cCvCudevNumericLimitsDouble = define_class_under<cv::cudev::numeric_limits<double>>(rb_mCvCudev, "NumericLimitsDouble").
    define_constructor(Constructor<cv::cudev::numeric_limits<double>>()).
    define_constant("Is_signed", cv::cudev::numeric_limits<double>::is_signed).
    define_singleton_function<double(*)()>("min", &cv::cudev::numeric_limits<double>::min).
    define_singleton_function<double(*)()>("max", &cv::cudev::numeric_limits<double>::max).
    define_singleton_function<double(*)()>("epsilon", &cv::cudev::numeric_limits<double>::epsilon);
}