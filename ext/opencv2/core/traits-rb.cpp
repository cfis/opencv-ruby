#include <opencv2/core/traits.hpp>
#include "traits-rb.hpp"

using namespace Rice;

#include "traits-rb.ipp"

void Init_Core_Traits()
{
  Module rb_mCv = define_module("Cv");

  Rice::Data_Type<cv::DataType<bool>> rb_cCvDataTypeBool = define_class_under<cv::DataType<bool>>(rb_mCv, "DataTypeBool").
    define_constructor(Constructor<cv::DataType<bool>>());

  rb_cCvDataTypeBool.define_constant("Generic_type", (int)cv::DataType<bool>::generic_type);
  rb_cCvDataTypeBool.define_constant("Depth", (int)cv::DataType<bool>::depth);
  rb_cCvDataTypeBool.define_constant("Channels", (int)cv::DataType<bool>::channels);
  rb_cCvDataTypeBool.define_constant("Fmt", (int)cv::DataType<bool>::fmt);
  rb_cCvDataTypeBool.define_constant("Type", (int)cv::DataType<bool>::type);

  Rice::Data_Type<cv::DataType<uchar>> rb_cCvDataTypeUchar = define_class_under<cv::DataType<uchar>>(rb_mCv, "DataTypeUchar").
    define_constructor(Constructor<cv::DataType<uchar>>());

  rb_cCvDataTypeUchar.define_constant("Generic_type", (int)cv::DataType<uchar>::generic_type);
  rb_cCvDataTypeUchar.define_constant("Depth", (int)cv::DataType<uchar>::depth);
  rb_cCvDataTypeUchar.define_constant("Channels", (int)cv::DataType<uchar>::channels);
  rb_cCvDataTypeUchar.define_constant("Fmt", (int)cv::DataType<uchar>::fmt);
  rb_cCvDataTypeUchar.define_constant("Type", (int)cv::DataType<uchar>::type);

  Rice::Data_Type<cv::DataType<schar>> rb_cCvDataTypeSchar = define_class_under<cv::DataType<schar>>(rb_mCv, "DataTypeSchar").
    define_constructor(Constructor<cv::DataType<schar>>());

  rb_cCvDataTypeSchar.define_constant("Generic_type", (int)cv::DataType<schar>::generic_type);
  rb_cCvDataTypeSchar.define_constant("Depth", (int)cv::DataType<schar>::depth);
  rb_cCvDataTypeSchar.define_constant("Channels", (int)cv::DataType<schar>::channels);
  rb_cCvDataTypeSchar.define_constant("Fmt", (int)cv::DataType<schar>::fmt);
  rb_cCvDataTypeSchar.define_constant("Type", (int)cv::DataType<schar>::type);

  Rice::Data_Type<cv::DataType<char>> rb_cCvDataTypeChar = define_class_under<cv::DataType<char>>(rb_mCv, "DataTypeChar").
    define_constructor(Constructor<cv::DataType<char>>());

  rb_cCvDataTypeChar.define_constant("Generic_type", (int)cv::DataType<char>::generic_type);
  rb_cCvDataTypeChar.define_constant("Depth", (int)cv::DataType<char>::depth);
  rb_cCvDataTypeChar.define_constant("Channels", (int)cv::DataType<char>::channels);
  rb_cCvDataTypeChar.define_constant("Fmt", (int)cv::DataType<char>::fmt);
  rb_cCvDataTypeChar.define_constant("Type", (int)cv::DataType<char>::type);

  Rice::Data_Type<cv::DataType<ushort>> rb_cCvDataTypeUshort = define_class_under<cv::DataType<ushort>>(rb_mCv, "DataTypeUshort").
    define_constructor(Constructor<cv::DataType<ushort>>());

  rb_cCvDataTypeUshort.define_constant("Generic_type", (int)cv::DataType<ushort>::generic_type);
  rb_cCvDataTypeUshort.define_constant("Depth", (int)cv::DataType<ushort>::depth);
  rb_cCvDataTypeUshort.define_constant("Channels", (int)cv::DataType<ushort>::channels);
  rb_cCvDataTypeUshort.define_constant("Fmt", (int)cv::DataType<ushort>::fmt);
  rb_cCvDataTypeUshort.define_constant("Type", (int)cv::DataType<ushort>::type);

  Rice::Data_Type<cv::DataType<short>> rb_cCvDataTypeShort = define_class_under<cv::DataType<short>>(rb_mCv, "DataTypeShort").
    define_constructor(Constructor<cv::DataType<short>>());

  rb_cCvDataTypeShort.define_constant("Generic_type", (int)cv::DataType<short>::generic_type);
  rb_cCvDataTypeShort.define_constant("Depth", (int)cv::DataType<short>::depth);
  rb_cCvDataTypeShort.define_constant("Channels", (int)cv::DataType<short>::channels);
  rb_cCvDataTypeShort.define_constant("Fmt", (int)cv::DataType<short>::fmt);
  rb_cCvDataTypeShort.define_constant("Type", (int)cv::DataType<short>::type);

  Rice::Data_Type<cv::DataType<int>> rb_cCvDataTypeInt = define_class_under<cv::DataType<int>>(rb_mCv, "DataTypeInt").
    define_constructor(Constructor<cv::DataType<int>>());

  rb_cCvDataTypeInt.define_constant("Generic_type", (int)cv::DataType<int>::generic_type);
  rb_cCvDataTypeInt.define_constant("Depth", (int)cv::DataType<int>::depth);
  rb_cCvDataTypeInt.define_constant("Channels", (int)cv::DataType<int>::channels);
  rb_cCvDataTypeInt.define_constant("Fmt", (int)cv::DataType<int>::fmt);
  rb_cCvDataTypeInt.define_constant("Type", (int)cv::DataType<int>::type);

  Rice::Data_Type<cv::DataType<float>> rb_cCvDataTypeFloat = define_class_under<cv::DataType<float>>(rb_mCv, "DataTypeFloat").
    define_constructor(Constructor<cv::DataType<float>>());

  rb_cCvDataTypeFloat.define_constant("Generic_type", (int)cv::DataType<float>::generic_type);
  rb_cCvDataTypeFloat.define_constant("Depth", (int)cv::DataType<float>::depth);
  rb_cCvDataTypeFloat.define_constant("Channels", (int)cv::DataType<float>::channels);
  rb_cCvDataTypeFloat.define_constant("Fmt", (int)cv::DataType<float>::fmt);
  rb_cCvDataTypeFloat.define_constant("Type", (int)cv::DataType<float>::type);

  Rice::Data_Type<cv::DataType<double>> rb_cCvDataTypeDouble = define_class_under<cv::DataType<double>>(rb_mCv, "DataTypeDouble").
    define_constructor(Constructor<cv::DataType<double>>());

  rb_cCvDataTypeDouble.define_constant("Generic_type", (int)cv::DataType<double>::generic_type);
  rb_cCvDataTypeDouble.define_constant("Depth", (int)cv::DataType<double>::depth);
  rb_cCvDataTypeDouble.define_constant("Channels", (int)cv::DataType<double>::channels);
  rb_cCvDataTypeDouble.define_constant("Fmt", (int)cv::DataType<double>::fmt);
  rb_cCvDataTypeDouble.define_constant("Type", (int)cv::DataType<double>::type);

#if RUBY_CV_VERSION >= 410
  Rice::Data_Type<cv::DataType<cv::hfloat>> rb_cCvDataTypeHfloat = define_class_under<cv::DataType<cv::hfloat>>(rb_mCv, "DataTypeHfloat").
    define_constructor(Constructor<cv::DataType<cv::hfloat>>());

  rb_cCvDataTypeHfloat.define_constant("Generic_type", (int)cv::DataType<cv::hfloat>::generic_type);
  rb_cCvDataTypeHfloat.define_constant("Depth", (int)cv::DataType<cv::hfloat>::depth);
  rb_cCvDataTypeHfloat.define_constant("Channels", (int)cv::DataType<cv::hfloat>::channels);
  rb_cCvDataTypeHfloat.define_constant("Fmt", (int)cv::DataType<cv::hfloat>::fmt);
  rb_cCvDataTypeHfloat.define_constant("Type", (int)cv::DataType<cv::hfloat>::type);
#endif

  Module rb_mCvTraits = define_module_under(rb_mCv, "Traits");

  Module rb_mCvTraitsInternal = define_module_under(rb_mCvTraits, "Internal");
}
