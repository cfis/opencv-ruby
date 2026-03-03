#include <opencv2/core/traits.hpp>
#include "traits-rb.hpp"

using namespace Rice;

#include "traits-rb.ipp"

void Init_Core_Traits()
{
  Module rb_mCv = define_module("Cv");

  Rice::Data_Type<cv::DataType<bool>> rb_cCvDataTypeBool = define_class_under<cv::DataType<bool>>(rb_mCv, "DataTypeBool")
    .define_constructor(Constructor<cv::DataType<bool>>())
    .define_constant("Generic_type", (int)cv::DataType<bool>::generic_type)
    .define_constant("Depth", (int)cv::DataType<bool>::depth)
    .define_constant("Channels", (int)cv::DataType<bool>::channels)
    .define_constant("Fmt", (int)cv::DataType<bool>::fmt)
    .define_constant("Type", (int)cv::DataType<bool>::type);

  Rice::Data_Type<cv::DataType<uchar>> rb_cCvDataTypeUchar = define_class_under<cv::DataType<uchar>>(rb_mCv, "DataTypeUchar")
    .define_constructor(Constructor<cv::DataType<uchar>>())
    .define_constant("Generic_type", (int)cv::DataType<uchar>::generic_type)
    .define_constant("Depth", (int)cv::DataType<uchar>::depth)
    .define_constant("Channels", (int)cv::DataType<uchar>::channels)
    .define_constant("Fmt", (int)cv::DataType<uchar>::fmt)
    .define_constant("Type", (int)cv::DataType<uchar>::type);

  Rice::Data_Type<cv::DataType<schar>> rb_cCvDataTypeSchar = define_class_under<cv::DataType<schar>>(rb_mCv, "DataTypeSchar")
    .define_constructor(Constructor<cv::DataType<schar>>())
    .define_constant("Generic_type", (int)cv::DataType<schar>::generic_type)
    .define_constant("Depth", (int)cv::DataType<schar>::depth)
    .define_constant("Channels", (int)cv::DataType<schar>::channels)
    .define_constant("Fmt", (int)cv::DataType<schar>::fmt)
    .define_constant("Type", (int)cv::DataType<schar>::type);

  Rice::Data_Type<cv::DataType<char>> rb_cCvDataTypeChar = define_class_under<cv::DataType<char>>(rb_mCv, "DataTypeChar")
    .define_constructor(Constructor<cv::DataType<char>>())
    .define_constant("Generic_type", (int)cv::DataType<char>::generic_type)
    .define_constant("Depth", (int)cv::DataType<char>::depth)
    .define_constant("Channels", (int)cv::DataType<char>::channels)
    .define_constant("Fmt", (int)cv::DataType<char>::fmt)
    .define_constant("Type", (int)cv::DataType<char>::type);

  Rice::Data_Type<cv::DataType<ushort>> rb_cCvDataTypeUshort = define_class_under<cv::DataType<ushort>>(rb_mCv, "DataTypeUshort")
    .define_constructor(Constructor<cv::DataType<ushort>>())
    .define_constant("Generic_type", (int)cv::DataType<ushort>::generic_type)
    .define_constant("Depth", (int)cv::DataType<ushort>::depth)
    .define_constant("Channels", (int)cv::DataType<ushort>::channels)
    .define_constant("Fmt", (int)cv::DataType<ushort>::fmt)
    .define_constant("Type", (int)cv::DataType<ushort>::type);

  Rice::Data_Type<cv::DataType<short>> rb_cCvDataTypeShort = define_class_under<cv::DataType<short>>(rb_mCv, "DataTypeShort")
    .define_constructor(Constructor<cv::DataType<short>>())
    .define_constant("Generic_type", (int)cv::DataType<short>::generic_type)
    .define_constant("Depth", (int)cv::DataType<short>::depth)
    .define_constant("Channels", (int)cv::DataType<short>::channels)
    .define_constant("Fmt", (int)cv::DataType<short>::fmt)
    .define_constant("Type", (int)cv::DataType<short>::type);

  Rice::Data_Type<cv::DataType<int>> rb_cCvDataTypeInt = define_class_under<cv::DataType<int>>(rb_mCv, "DataTypeInt")
    .define_constructor(Constructor<cv::DataType<int>>())
    .define_constant("Generic_type", (int)cv::DataType<int>::generic_type)
    .define_constant("Depth", (int)cv::DataType<int>::depth)
    .define_constant("Channels", (int)cv::DataType<int>::channels)
    .define_constant("Fmt", (int)cv::DataType<int>::fmt)
    .define_constant("Type", (int)cv::DataType<int>::type);

  Rice::Data_Type<cv::DataType<float>> rb_cCvDataTypeFloat = define_class_under<cv::DataType<float>>(rb_mCv, "DataTypeFloat")
    .define_constructor(Constructor<cv::DataType<float>>())
    .define_constant("Generic_type", (int)cv::DataType<float>::generic_type)
    .define_constant("Depth", (int)cv::DataType<float>::depth)
    .define_constant("Channels", (int)cv::DataType<float>::channels)
    .define_constant("Fmt", (int)cv::DataType<float>::fmt)
    .define_constant("Type", (int)cv::DataType<float>::type);

  Rice::Data_Type<cv::DataType<double>> rb_cCvDataTypeDouble = define_class_under<cv::DataType<double>>(rb_mCv, "DataTypeDouble")
    .define_constructor(Constructor<cv::DataType<double>>())
    .define_constant("Generic_type", (int)cv::DataType<double>::generic_type)
    .define_constant("Depth", (int)cv::DataType<double>::depth)
    .define_constant("Channels", (int)cv::DataType<double>::channels)
    .define_constant("Fmt", (int)cv::DataType<double>::fmt)
    .define_constant("Type", (int)cv::DataType<double>::type);

  Module rb_mCvTraits = define_module_under(rb_mCv, "Traits");

  Module rb_mCvTraitsInternal = define_module_under(rb_mCvTraits, "Internal");

  #if RUBY_CV_VERSION >= 410

  Rice::Data_Type<cv::DataType<cv::hfloat>> rb_cCvDataTypeHfloat = define_class_under<cv::DataType<cv::hfloat>>(rb_mCv, "DataTypeHfloat")
    .define_constructor(Constructor<cv::DataType<cv::hfloat>>())
    .define_constant("Generic_type", (int)cv::DataType<cv::hfloat>::generic_type)
    .define_constant("Depth", (int)cv::DataType<cv::hfloat>::depth)
    .define_constant("Channels", (int)cv::DataType<cv::hfloat>::channels)
    .define_constant("Fmt", (int)cv::DataType<cv::hfloat>::fmt)
    .define_constant("Type", (int)cv::DataType<cv::hfloat>::type);

  #endif
}
