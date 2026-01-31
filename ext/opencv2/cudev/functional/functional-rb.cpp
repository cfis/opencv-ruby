#include "functional-rb.ipp"

void Init_Cudev_Functional_Functional()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");

  Rice::Data_Type<cv::cudev::binary_function<unsigned char, unsigned char, unsigned char>> rb_cBinaryFunctionUnsignedCharUnsignedCharUnsignedChar = define_class_under<cv::cudev::binary_function<unsigned char, unsigned char, unsigned char>>(rb_mCvCudev, "BinaryFunctionUnsignedCharUnsignedCharUnsignedChar").
    define(&binary_function_builder<Data_Type<cv::cudev::binary_function<unsigned char, unsigned char, unsigned char>>, unsigned char, unsigned char, unsigned char>);
  Rice::Data_Type<cv::cudev::maximum<uchar>> rb_cCvCudevMaximumUchar = define_class_under<cv::cudev::maximum<uchar>, cv::cudev::binary_function<unsigned char, unsigned char, unsigned char>>(rb_mCvCudev, "MaximumUchar").
    define_constructor(Constructor<cv::cudev::maximum<uchar>>()).
    define_method<uchar(cv::cudev::maximum<uchar>::*)(uchar, uchar) const>("call", &cv::cudev::maximum<uchar>::operator(),
      Arg("a"), Arg("b"));

  Rice::Data_Type<cv::cudev::minimum<uchar>> rb_cCvCudevMinimumUchar = define_class_under<cv::cudev::minimum<uchar>, cv::cudev::binary_function<unsigned char, unsigned char, unsigned char>>(rb_mCvCudev, "MinimumUchar").
    define_constructor(Constructor<cv::cudev::minimum<uchar>>()).
    define_method<uchar(cv::cudev::minimum<uchar>::*)(uchar, uchar) const>("call", &cv::cudev::minimum<uchar>::operator(),
      Arg("a"), Arg("b"));

  Rice::Data_Type<cv::cudev::binary_function<signed char, signed char, signed char>> rb_cBinaryFunctionSignedCharSignedCharSignedChar = define_class_under<cv::cudev::binary_function<signed char, signed char, signed char>>(rb_mCvCudev, "BinaryFunctionSignedCharSignedCharSignedChar").
    define(&binary_function_builder<Data_Type<cv::cudev::binary_function<signed char, signed char, signed char>>, signed char, signed char, signed char>);
  Rice::Data_Type<cv::cudev::maximum<schar>> rb_cCvCudevMaximumSchar = define_class_under<cv::cudev::maximum<schar>, cv::cudev::binary_function<signed char, signed char, signed char>>(rb_mCvCudev, "MaximumSchar").
    define_constructor(Constructor<cv::cudev::maximum<schar>>()).
    define_method<schar(cv::cudev::maximum<schar>::*)(schar, schar) const>("call", &cv::cudev::maximum<schar>::operator(),
      Arg("a"), Arg("b"));

  Rice::Data_Type<cv::cudev::minimum<schar>> rb_cCvCudevMinimumSchar = define_class_under<cv::cudev::minimum<schar>, cv::cudev::binary_function<signed char, signed char, signed char>>(rb_mCvCudev, "MinimumSchar").
    define_constructor(Constructor<cv::cudev::minimum<schar>>()).
    define_method<schar(cv::cudev::minimum<schar>::*)(schar, schar) const>("call", &cv::cudev::minimum<schar>::operator(),
      Arg("a"), Arg("b"));

  Rice::Data_Type<cv::cudev::binary_function<unsigned short, unsigned short, unsigned short>> rb_cBinaryFunctionUnsignedShortUnsignedShortUnsignedShort = define_class_under<cv::cudev::binary_function<unsigned short, unsigned short, unsigned short>>(rb_mCvCudev, "BinaryFunctionUnsignedShortUnsignedShortUnsignedShort").
    define(&binary_function_builder<Data_Type<cv::cudev::binary_function<unsigned short, unsigned short, unsigned short>>, unsigned short, unsigned short, unsigned short>);
  Rice::Data_Type<cv::cudev::maximum<ushort>> rb_cCvCudevMaximumUshort = define_class_under<cv::cudev::maximum<ushort>, cv::cudev::binary_function<unsigned short, unsigned short, unsigned short>>(rb_mCvCudev, "MaximumUshort").
    define_constructor(Constructor<cv::cudev::maximum<ushort>>()).
    define_method<ushort(cv::cudev::maximum<ushort>::*)(ushort, ushort) const>("call", &cv::cudev::maximum<ushort>::operator(),
      Arg("a"), Arg("b"));

  Rice::Data_Type<cv::cudev::minimum<ushort>> rb_cCvCudevMinimumUshort = define_class_under<cv::cudev::minimum<ushort>, cv::cudev::binary_function<unsigned short, unsigned short, unsigned short>>(rb_mCvCudev, "MinimumUshort").
    define_constructor(Constructor<cv::cudev::minimum<ushort>>()).
    define_method<ushort(cv::cudev::minimum<ushort>::*)(ushort, ushort) const>("call", &cv::cudev::minimum<ushort>::operator(),
      Arg("a"), Arg("b"));

  Rice::Data_Type<cv::cudev::binary_function<short, short, short>> rb_cBinaryFunctionShortShortShort = define_class_under<cv::cudev::binary_function<short, short, short>>(rb_mCvCudev, "BinaryFunctionShortShortShort").
    define(&binary_function_builder<Data_Type<cv::cudev::binary_function<short, short, short>>, short, short, short>);
  Rice::Data_Type<cv::cudev::maximum<short>> rb_cCvCudevMaximumShort = define_class_under<cv::cudev::maximum<short>, cv::cudev::binary_function<short, short, short>>(rb_mCvCudev, "MaximumShort").
    define_constructor(Constructor<cv::cudev::maximum<short>>()).
    define_method<short(cv::cudev::maximum<short>::*)(short, short) const>("call", &cv::cudev::maximum<short>::operator(),
      Arg("a"), Arg("b"));

  Rice::Data_Type<cv::cudev::minimum<short>> rb_cCvCudevMinimumShort = define_class_under<cv::cudev::minimum<short>, cv::cudev::binary_function<short, short, short>>(rb_mCvCudev, "MinimumShort").
    define_constructor(Constructor<cv::cudev::minimum<short>>()).
    define_method<short(cv::cudev::minimum<short>::*)(short, short) const>("call", &cv::cudev::minimum<short>::operator(),
      Arg("a"), Arg("b"));

  Rice::Data_Type<cv::cudev::binary_function<int, int, int>> rb_cBinaryFunctionIntIntInt = define_class_under<cv::cudev::binary_function<int, int, int>>(rb_mCvCudev, "BinaryFunctionIntIntInt").
    define(&binary_function_builder<Data_Type<cv::cudev::binary_function<int, int, int>>, int, int, int>);
  Rice::Data_Type<cv::cudev::maximum<int>> rb_cCvCudevMaximumInt = define_class_under<cv::cudev::maximum<int>, cv::cudev::binary_function<int, int, int>>(rb_mCvCudev, "MaximumInt").
    define_constructor(Constructor<cv::cudev::maximum<int>>()).
    define_method<int(cv::cudev::maximum<int>::*)(int, int) const>("call", &cv::cudev::maximum<int>::operator(),
      Arg("a"), Arg("b"));

  Rice::Data_Type<cv::cudev::minimum<int>> rb_cCvCudevMinimumInt = define_class_under<cv::cudev::minimum<int>, cv::cudev::binary_function<int, int, int>>(rb_mCvCudev, "MinimumInt").
    define_constructor(Constructor<cv::cudev::minimum<int>>()).
    define_method<int(cv::cudev::minimum<int>::*)(int, int) const>("call", &cv::cudev::minimum<int>::operator(),
      Arg("a"), Arg("b"));

  Rice::Data_Type<cv::cudev::binary_function<unsigned int, unsigned int, unsigned int>> rb_cBinaryFunctionUnsignedIntUnsignedIntUnsignedInt = define_class_under<cv::cudev::binary_function<unsigned int, unsigned int, unsigned int>>(rb_mCvCudev, "BinaryFunctionUnsignedIntUnsignedIntUnsignedInt").
    define(&binary_function_builder<Data_Type<cv::cudev::binary_function<unsigned int, unsigned int, unsigned int>>, unsigned int, unsigned int, unsigned int>);
  Rice::Data_Type<cv::cudev::maximum<uint>> rb_cCvCudevMaximumUint = define_class_under<cv::cudev::maximum<uint>, cv::cudev::binary_function<unsigned int, unsigned int, unsigned int>>(rb_mCvCudev, "MaximumUint").
    define_constructor(Constructor<cv::cudev::maximum<uint>>()).
    define_method<uint(cv::cudev::maximum<uint>::*)(uint, uint) const>("call", &cv::cudev::maximum<uint>::operator(),
      Arg("a"), Arg("b"));

  Rice::Data_Type<cv::cudev::minimum<uint>> rb_cCvCudevMinimumUint = define_class_under<cv::cudev::minimum<uint>, cv::cudev::binary_function<unsigned int, unsigned int, unsigned int>>(rb_mCvCudev, "MinimumUint").
    define_constructor(Constructor<cv::cudev::minimum<uint>>()).
    define_method<uint(cv::cudev::minimum<uint>::*)(uint, uint) const>("call", &cv::cudev::minimum<uint>::operator(),
      Arg("a"), Arg("b"));

  Rice::Data_Type<cv::cudev::binary_function<float, float, float>> rb_cBinaryFunctionFloatFloatFloat = define_class_under<cv::cudev::binary_function<float, float, float>>(rb_mCvCudev, "BinaryFunctionFloatFloatFloat").
    define(&binary_function_builder<Data_Type<cv::cudev::binary_function<float, float, float>>, float, float, float>);
  Rice::Data_Type<cv::cudev::maximum<float>> rb_cCvCudevMaximumFloat = define_class_under<cv::cudev::maximum<float>, cv::cudev::binary_function<float, float, float>>(rb_mCvCudev, "MaximumFloat").
    define_constructor(Constructor<cv::cudev::maximum<float>>()).
    define_method<float(cv::cudev::maximum<float>::*)(float, float) const>("call", &cv::cudev::maximum<float>::operator(),
      Arg("a"), Arg("b"));

  Rice::Data_Type<cv::cudev::minimum<float>> rb_cCvCudevMinimumFloat = define_class_under<cv::cudev::minimum<float>, cv::cudev::binary_function<float, float, float>>(rb_mCvCudev, "MinimumFloat").
    define_constructor(Constructor<cv::cudev::minimum<float>>()).
    define_method<float(cv::cudev::minimum<float>::*)(float, float) const>("call", &cv::cudev::minimum<float>::operator(),
      Arg("a"), Arg("b"));

  Rice::Data_Type<cv::cudev::binary_function<double, double, double>> rb_cBinaryFunctionDoubleDoubleDouble = define_class_under<cv::cudev::binary_function<double, double, double>>(rb_mCvCudev, "BinaryFunctionDoubleDoubleDouble").
    define(&binary_function_builder<Data_Type<cv::cudev::binary_function<double, double, double>>, double, double, double>);
  Rice::Data_Type<cv::cudev::maximum<double>> rb_cCvCudevMaximumDouble = define_class_under<cv::cudev::maximum<double>, cv::cudev::binary_function<double, double, double>>(rb_mCvCudev, "MaximumDouble").
    define_constructor(Constructor<cv::cudev::maximum<double>>()).
    define_method<double(cv::cudev::maximum<double>::*)(double, double) const>("call", &cv::cudev::maximum<double>::operator(),
      Arg("a"), Arg("b"));

  Rice::Data_Type<cv::cudev::minimum<double>> rb_cCvCudevMinimumDouble = define_class_under<cv::cudev::minimum<double>, cv::cudev::binary_function<double, double, double>>(rb_mCvCudev, "MinimumDouble").
    define_constructor(Constructor<cv::cudev::minimum<double>>()).
    define_method<double(cv::cudev::minimum<double>::*)(double, double) const>("call", &cv::cudev::minimum<double>::operator(),
      Arg("a"), Arg("b"));

  Rice::Data_Type<cv::cudev::unary_function<unsigned char, unsigned char>> rb_cUnaryFunctionUnsignedCharUnsignedChar = define_class_under<cv::cudev::unary_function<unsigned char, unsigned char>>(rb_mCvCudev, "UnaryFunctionUnsignedCharUnsignedChar").
    define(&unary_function_builder<Data_Type<cv::cudev::unary_function<unsigned char, unsigned char>>, unsigned char, unsigned char>);
  Rice::Data_Type<cv::cudev::abs_func<uchar>> rb_cCvCudevAbsFuncUchar = define_class_under<cv::cudev::abs_func<uchar>, cv::cudev::unary_function<unsigned char, unsigned char>>(rb_mCvCudev, "AbsFuncUchar").
    define_constructor(Constructor<cv::cudev::abs_func<uchar>>()).
    define_method<uchar(cv::cudev::abs_func<uchar>::*)(uchar) const>("call", &cv::cudev::abs_func<uchar>::operator(),
      Arg("x"));

  Rice::Data_Type<cv::cudev::unary_function<signed char, signed char>> rb_cUnaryFunctionSignedCharSignedChar = define_class_under<cv::cudev::unary_function<signed char, signed char>>(rb_mCvCudev, "UnaryFunctionSignedCharSignedChar").
    define(&unary_function_builder<Data_Type<cv::cudev::unary_function<signed char, signed char>>, signed char, signed char>);
  Rice::Data_Type<cv::cudev::abs_func<schar>> rb_cCvCudevAbsFuncSchar = define_class_under<cv::cudev::abs_func<schar>, cv::cudev::unary_function<signed char, signed char>>(rb_mCvCudev, "AbsFuncSchar").
    define_constructor(Constructor<cv::cudev::abs_func<schar>>()).
    define_method<schar(cv::cudev::abs_func<schar>::*)(schar) const>("call", &cv::cudev::abs_func<schar>::operator(),
      Arg("x"));

  Rice::Data_Type<cv::cudev::unary_function<unsigned short, unsigned short>> rb_cUnaryFunctionUnsignedShortUnsignedShort = define_class_under<cv::cudev::unary_function<unsigned short, unsigned short>>(rb_mCvCudev, "UnaryFunctionUnsignedShortUnsignedShort").
    define(&unary_function_builder<Data_Type<cv::cudev::unary_function<unsigned short, unsigned short>>, unsigned short, unsigned short>);
  Rice::Data_Type<cv::cudev::abs_func<ushort>> rb_cCvCudevAbsFuncUshort = define_class_under<cv::cudev::abs_func<ushort>, cv::cudev::unary_function<unsigned short, unsigned short>>(rb_mCvCudev, "AbsFuncUshort").
    define_constructor(Constructor<cv::cudev::abs_func<ushort>>()).
    define_method<ushort(cv::cudev::abs_func<ushort>::*)(ushort) const>("call", &cv::cudev::abs_func<ushort>::operator(),
      Arg("x"));

  Rice::Data_Type<cv::cudev::unary_function<short, short>> rb_cUnaryFunctionShortShort = define_class_under<cv::cudev::unary_function<short, short>>(rb_mCvCudev, "UnaryFunctionShortShort").
    define(&unary_function_builder<Data_Type<cv::cudev::unary_function<short, short>>, short, short>);
  Rice::Data_Type<cv::cudev::abs_func<short>> rb_cCvCudevAbsFuncShort = define_class_under<cv::cudev::abs_func<short>, cv::cudev::unary_function<short, short>>(rb_mCvCudev, "AbsFuncShort").
    define_constructor(Constructor<cv::cudev::abs_func<short>>()).
    define_method<short(cv::cudev::abs_func<short>::*)(short) const>("call", &cv::cudev::abs_func<short>::operator(),
      Arg("x"));

  Rice::Data_Type<cv::cudev::unary_function<unsigned int, unsigned int>> rb_cUnaryFunctionUnsignedIntUnsignedInt = define_class_under<cv::cudev::unary_function<unsigned int, unsigned int>>(rb_mCvCudev, "UnaryFunctionUnsignedIntUnsignedInt").
    define(&unary_function_builder<Data_Type<cv::cudev::unary_function<unsigned int, unsigned int>>, unsigned int, unsigned int>);
  Rice::Data_Type<cv::cudev::abs_func<uint>> rb_cCvCudevAbsFuncUint = define_class_under<cv::cudev::abs_func<uint>, cv::cudev::unary_function<unsigned int, unsigned int>>(rb_mCvCudev, "AbsFuncUint").
    define_constructor(Constructor<cv::cudev::abs_func<uint>>()).
    define_method<uint(cv::cudev::abs_func<uint>::*)(uint) const>("call", &cv::cudev::abs_func<uint>::operator(),
      Arg("x"));

  Rice::Data_Type<cv::cudev::unary_function<int, int>> rb_cUnaryFunctionIntInt = define_class_under<cv::cudev::unary_function<int, int>>(rb_mCvCudev, "UnaryFunctionIntInt").
    define(&unary_function_builder<Data_Type<cv::cudev::unary_function<int, int>>, int, int>);
  Rice::Data_Type<cv::cudev::abs_func<int>> rb_cCvCudevAbsFuncInt = define_class_under<cv::cudev::abs_func<int>, cv::cudev::unary_function<int, int>>(rb_mCvCudev, "AbsFuncInt").
    define_constructor(Constructor<cv::cudev::abs_func<int>>()).
    define_method<int(cv::cudev::abs_func<int>::*)(int) const>("call", &cv::cudev::abs_func<int>::operator(),
      Arg("x"));

  Rice::Data_Type<cv::cudev::unary_function<float, float>> rb_cUnaryFunctionFloatFloat = define_class_under<cv::cudev::unary_function<float, float>>(rb_mCvCudev, "UnaryFunctionFloatFloat").
    define(&unary_function_builder<Data_Type<cv::cudev::unary_function<float, float>>, float, float>);
  Rice::Data_Type<cv::cudev::abs_func<float>> rb_cCvCudevAbsFuncFloat = define_class_under<cv::cudev::abs_func<float>, cv::cudev::unary_function<float, float>>(rb_mCvCudev, "AbsFuncFloat").
    define_constructor(Constructor<cv::cudev::abs_func<float>>()).
    define_method<float(cv::cudev::abs_func<float>::*)(float) const>("call", &cv::cudev::abs_func<float>::operator(),
      Arg("x"));

  Rice::Data_Type<cv::cudev::unary_function<double, double>> rb_cUnaryFunctionDoubleDouble = define_class_under<cv::cudev::unary_function<double, double>>(rb_mCvCudev, "UnaryFunctionDoubleDouble").
    define(&unary_function_builder<Data_Type<cv::cudev::unary_function<double, double>>, double, double>);
  Rice::Data_Type<cv::cudev::abs_func<double>> rb_cCvCudevAbsFuncDouble = define_class_under<cv::cudev::abs_func<double>, cv::cudev::unary_function<double, double>>(rb_mCvCudev, "AbsFuncDouble").
    define_constructor(Constructor<cv::cudev::abs_func<double>>()).
    define_method<double(cv::cudev::abs_func<double>::*)(double) const>("call", &cv::cudev::abs_func<double>::operator(),
      Arg("x"));

  Module rb_mCvCudevFunctionalDetail = define_module_under(rb_mCvCudev, "FunctionalDetail");

  Rice::Data_Type<cv::cudev::unary_function<unsigned char, float>> rb_cUnaryFunctionUnsignedCharFloat = define_class_under<cv::cudev::unary_function<unsigned char, float>>(rb_mCvCudev, "UnaryFunctionUnsignedCharFloat").
    define(&unary_function_builder<Data_Type<cv::cudev::unary_function<unsigned char, float>>, unsigned char, float>);
  Rice::Data_Type<cv::cudev::sqrt_func<uchar>> rb_cCvCudevSqrtFuncUchar = define_class_under<cv::cudev::sqrt_func<uchar>, cv::cudev::unary_function<unsigned char, float>>(rb_mCvCudev, "SqrtFuncUchar").
    define_constructor(Constructor<cv::cudev::sqrt_func<uchar>>()).
    define_method<float(cv::cudev::sqrt_func<uchar>::*)(uchar) const>("call", &cv::cudev::sqrt_func<uchar>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::unary_function<signed char, float>> rb_cUnaryFunctionSignedCharFloat = define_class_under<cv::cudev::unary_function<signed char, float>>(rb_mCvCudev, "UnaryFunctionSignedCharFloat").
    define(&unary_function_builder<Data_Type<cv::cudev::unary_function<signed char, float>>, signed char, float>);
  Rice::Data_Type<cv::cudev::sqrt_func<schar>> rb_cCvCudevSqrtFuncSchar = define_class_under<cv::cudev::sqrt_func<schar>, cv::cudev::unary_function<signed char, float>>(rb_mCvCudev, "SqrtFuncSchar").
    define_constructor(Constructor<cv::cudev::sqrt_func<schar>>()).
    define_method<float(cv::cudev::sqrt_func<schar>::*)(schar) const>("call", &cv::cudev::sqrt_func<schar>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::unary_function<unsigned short, float>> rb_cUnaryFunctionUnsignedShortFloat = define_class_under<cv::cudev::unary_function<unsigned short, float>>(rb_mCvCudev, "UnaryFunctionUnsignedShortFloat").
    define(&unary_function_builder<Data_Type<cv::cudev::unary_function<unsigned short, float>>, unsigned short, float>);
  Rice::Data_Type<cv::cudev::sqrt_func<ushort>> rb_cCvCudevSqrtFuncUshort = define_class_under<cv::cudev::sqrt_func<ushort>, cv::cudev::unary_function<unsigned short, float>>(rb_mCvCudev, "SqrtFuncUshort").
    define_constructor(Constructor<cv::cudev::sqrt_func<ushort>>()).
    define_method<float(cv::cudev::sqrt_func<ushort>::*)(ushort) const>("call", &cv::cudev::sqrt_func<ushort>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::unary_function<short, float>> rb_cUnaryFunctionShortFloat = define_class_under<cv::cudev::unary_function<short, float>>(rb_mCvCudev, "UnaryFunctionShortFloat").
    define(&unary_function_builder<Data_Type<cv::cudev::unary_function<short, float>>, short, float>);
  Rice::Data_Type<cv::cudev::sqrt_func<short>> rb_cCvCudevSqrtFuncShort = define_class_under<cv::cudev::sqrt_func<short>, cv::cudev::unary_function<short, float>>(rb_mCvCudev, "SqrtFuncShort").
    define_constructor(Constructor<cv::cudev::sqrt_func<short>>()).
    define_method<float(cv::cudev::sqrt_func<short>::*)(short) const>("call", &cv::cudev::sqrt_func<short>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::unary_function<unsigned int, float>> rb_cUnaryFunctionUnsignedIntFloat = define_class_under<cv::cudev::unary_function<unsigned int, float>>(rb_mCvCudev, "UnaryFunctionUnsignedIntFloat").
    define(&unary_function_builder<Data_Type<cv::cudev::unary_function<unsigned int, float>>, unsigned int, float>);
  Rice::Data_Type<cv::cudev::sqrt_func<uint>> rb_cCvCudevSqrtFuncUint = define_class_under<cv::cudev::sqrt_func<uint>, cv::cudev::unary_function<unsigned int, float>>(rb_mCvCudev, "SqrtFuncUint").
    define_constructor(Constructor<cv::cudev::sqrt_func<uint>>()).
    define_method<float(cv::cudev::sqrt_func<uint>::*)(uint) const>("call", &cv::cudev::sqrt_func<uint>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::unary_function<int, float>> rb_cUnaryFunctionIntFloat = define_class_under<cv::cudev::unary_function<int, float>>(rb_mCvCudev, "UnaryFunctionIntFloat").
    define(&unary_function_builder<Data_Type<cv::cudev::unary_function<int, float>>, int, float>);
  Rice::Data_Type<cv::cudev::sqrt_func<int>> rb_cCvCudevSqrtFuncInt = define_class_under<cv::cudev::sqrt_func<int>, cv::cudev::unary_function<int, float>>(rb_mCvCudev, "SqrtFuncInt").
    define_constructor(Constructor<cv::cudev::sqrt_func<int>>()).
    define_method<float(cv::cudev::sqrt_func<int>::*)(int) const>("call", &cv::cudev::sqrt_func<int>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::sqrt_func<float>> rb_cCvCudevSqrtFuncFloat = define_class_under<cv::cudev::sqrt_func<float>, cv::cudev::unary_function<float, float>>(rb_mCvCudev, "SqrtFuncFloat").
    define_constructor(Constructor<cv::cudev::sqrt_func<float>>()).
    define_method<float(cv::cudev::sqrt_func<float>::*)(float) const>("call", &cv::cudev::sqrt_func<float>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::sqrt_func<double>> rb_cCvCudevSqrtFuncDouble = define_class_under<cv::cudev::sqrt_func<double>, cv::cudev::unary_function<double, double>>(rb_mCvCudev, "SqrtFuncDouble").
    define_constructor(Constructor<cv::cudev::sqrt_func<double>>()).
    define_method<double(cv::cudev::sqrt_func<double>::*)(double) const>("call", &cv::cudev::sqrt_func<double>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::exp_func<uchar>> rb_cCvCudevExpFuncUchar = define_class_under<cv::cudev::exp_func<uchar>, cv::cudev::unary_function<unsigned char, float>>(rb_mCvCudev, "ExpFuncUchar").
    define_constructor(Constructor<cv::cudev::exp_func<uchar>>()).
    define_method<float(cv::cudev::exp_func<uchar>::*)(uchar) const>("call", &cv::cudev::exp_func<uchar>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::exp_func<schar>> rb_cCvCudevExpFuncSchar = define_class_under<cv::cudev::exp_func<schar>, cv::cudev::unary_function<signed char, float>>(rb_mCvCudev, "ExpFuncSchar").
    define_constructor(Constructor<cv::cudev::exp_func<schar>>()).
    define_method<float(cv::cudev::exp_func<schar>::*)(schar) const>("call", &cv::cudev::exp_func<schar>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::exp_func<ushort>> rb_cCvCudevExpFuncUshort = define_class_under<cv::cudev::exp_func<ushort>, cv::cudev::unary_function<unsigned short, float>>(rb_mCvCudev, "ExpFuncUshort").
    define_constructor(Constructor<cv::cudev::exp_func<ushort>>()).
    define_method<float(cv::cudev::exp_func<ushort>::*)(ushort) const>("call", &cv::cudev::exp_func<ushort>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::exp_func<short>> rb_cCvCudevExpFuncShort = define_class_under<cv::cudev::exp_func<short>, cv::cudev::unary_function<short, float>>(rb_mCvCudev, "ExpFuncShort").
    define_constructor(Constructor<cv::cudev::exp_func<short>>()).
    define_method<float(cv::cudev::exp_func<short>::*)(short) const>("call", &cv::cudev::exp_func<short>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::exp_func<uint>> rb_cCvCudevExpFuncUint = define_class_under<cv::cudev::exp_func<uint>, cv::cudev::unary_function<unsigned int, float>>(rb_mCvCudev, "ExpFuncUint").
    define_constructor(Constructor<cv::cudev::exp_func<uint>>()).
    define_method<float(cv::cudev::exp_func<uint>::*)(uint) const>("call", &cv::cudev::exp_func<uint>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::exp_func<int>> rb_cCvCudevExpFuncInt = define_class_under<cv::cudev::exp_func<int>, cv::cudev::unary_function<int, float>>(rb_mCvCudev, "ExpFuncInt").
    define_constructor(Constructor<cv::cudev::exp_func<int>>()).
    define_method<float(cv::cudev::exp_func<int>::*)(int) const>("call", &cv::cudev::exp_func<int>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::exp_func<float>> rb_cCvCudevExpFuncFloat = define_class_under<cv::cudev::exp_func<float>, cv::cudev::unary_function<float, float>>(rb_mCvCudev, "ExpFuncFloat").
    define_constructor(Constructor<cv::cudev::exp_func<float>>()).
    define_method<float(cv::cudev::exp_func<float>::*)(float) const>("call", &cv::cudev::exp_func<float>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::exp_func<double>> rb_cCvCudevExpFuncDouble = define_class_under<cv::cudev::exp_func<double>, cv::cudev::unary_function<double, double>>(rb_mCvCudev, "ExpFuncDouble").
    define_constructor(Constructor<cv::cudev::exp_func<double>>()).
    define_method<double(cv::cudev::exp_func<double>::*)(double) const>("call", &cv::cudev::exp_func<double>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::exp2_func<uchar>> rb_cCvCudevExp2FuncUchar = define_class_under<cv::cudev::exp2_func<uchar>, cv::cudev::unary_function<unsigned char, float>>(rb_mCvCudev, "Exp2FuncUchar").
    define_constructor(Constructor<cv::cudev::exp2_func<uchar>>()).
    define_method<float(cv::cudev::exp2_func<uchar>::*)(uchar) const>("call", &cv::cudev::exp2_func<uchar>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::exp2_func<schar>> rb_cCvCudevExp2FuncSchar = define_class_under<cv::cudev::exp2_func<schar>, cv::cudev::unary_function<signed char, float>>(rb_mCvCudev, "Exp2FuncSchar").
    define_constructor(Constructor<cv::cudev::exp2_func<schar>>()).
    define_method<float(cv::cudev::exp2_func<schar>::*)(schar) const>("call", &cv::cudev::exp2_func<schar>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::exp2_func<ushort>> rb_cCvCudevExp2FuncUshort = define_class_under<cv::cudev::exp2_func<ushort>, cv::cudev::unary_function<unsigned short, float>>(rb_mCvCudev, "Exp2FuncUshort").
    define_constructor(Constructor<cv::cudev::exp2_func<ushort>>()).
    define_method<float(cv::cudev::exp2_func<ushort>::*)(ushort) const>("call", &cv::cudev::exp2_func<ushort>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::exp2_func<short>> rb_cCvCudevExp2FuncShort = define_class_under<cv::cudev::exp2_func<short>, cv::cudev::unary_function<short, float>>(rb_mCvCudev, "Exp2FuncShort").
    define_constructor(Constructor<cv::cudev::exp2_func<short>>()).
    define_method<float(cv::cudev::exp2_func<short>::*)(short) const>("call", &cv::cudev::exp2_func<short>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::exp2_func<uint>> rb_cCvCudevExp2FuncUint = define_class_under<cv::cudev::exp2_func<uint>, cv::cudev::unary_function<unsigned int, float>>(rb_mCvCudev, "Exp2FuncUint").
    define_constructor(Constructor<cv::cudev::exp2_func<uint>>()).
    define_method<float(cv::cudev::exp2_func<uint>::*)(uint) const>("call", &cv::cudev::exp2_func<uint>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::exp2_func<int>> rb_cCvCudevExp2FuncInt = define_class_under<cv::cudev::exp2_func<int>, cv::cudev::unary_function<int, float>>(rb_mCvCudev, "Exp2FuncInt").
    define_constructor(Constructor<cv::cudev::exp2_func<int>>()).
    define_method<float(cv::cudev::exp2_func<int>::*)(int) const>("call", &cv::cudev::exp2_func<int>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::exp2_func<float>> rb_cCvCudevExp2FuncFloat = define_class_under<cv::cudev::exp2_func<float>, cv::cudev::unary_function<float, float>>(rb_mCvCudev, "Exp2FuncFloat").
    define_constructor(Constructor<cv::cudev::exp2_func<float>>()).
    define_method<float(cv::cudev::exp2_func<float>::*)(float) const>("call", &cv::cudev::exp2_func<float>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::exp2_func<double>> rb_cCvCudevExp2FuncDouble = define_class_under<cv::cudev::exp2_func<double>, cv::cudev::unary_function<double, double>>(rb_mCvCudev, "Exp2FuncDouble").
    define_constructor(Constructor<cv::cudev::exp2_func<double>>()).
    define_method<double(cv::cudev::exp2_func<double>::*)(double) const>("call", &cv::cudev::exp2_func<double>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::exp10_func<uchar>> rb_cCvCudevExp10FuncUchar = define_class_under<cv::cudev::exp10_func<uchar>, cv::cudev::unary_function<unsigned char, float>>(rb_mCvCudev, "Exp10FuncUchar").
    define_constructor(Constructor<cv::cudev::exp10_func<uchar>>()).
    define_method<float(cv::cudev::exp10_func<uchar>::*)(uchar) const>("call", &cv::cudev::exp10_func<uchar>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::exp10_func<schar>> rb_cCvCudevExp10FuncSchar = define_class_under<cv::cudev::exp10_func<schar>, cv::cudev::unary_function<signed char, float>>(rb_mCvCudev, "Exp10FuncSchar").
    define_constructor(Constructor<cv::cudev::exp10_func<schar>>()).
    define_method<float(cv::cudev::exp10_func<schar>::*)(schar) const>("call", &cv::cudev::exp10_func<schar>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::exp10_func<ushort>> rb_cCvCudevExp10FuncUshort = define_class_under<cv::cudev::exp10_func<ushort>, cv::cudev::unary_function<unsigned short, float>>(rb_mCvCudev, "Exp10FuncUshort").
    define_constructor(Constructor<cv::cudev::exp10_func<ushort>>()).
    define_method<float(cv::cudev::exp10_func<ushort>::*)(ushort) const>("call", &cv::cudev::exp10_func<ushort>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::exp10_func<short>> rb_cCvCudevExp10FuncShort = define_class_under<cv::cudev::exp10_func<short>, cv::cudev::unary_function<short, float>>(rb_mCvCudev, "Exp10FuncShort").
    define_constructor(Constructor<cv::cudev::exp10_func<short>>()).
    define_method<float(cv::cudev::exp10_func<short>::*)(short) const>("call", &cv::cudev::exp10_func<short>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::exp10_func<uint>> rb_cCvCudevExp10FuncUint = define_class_under<cv::cudev::exp10_func<uint>, cv::cudev::unary_function<unsigned int, float>>(rb_mCvCudev, "Exp10FuncUint").
    define_constructor(Constructor<cv::cudev::exp10_func<uint>>()).
    define_method<float(cv::cudev::exp10_func<uint>::*)(uint) const>("call", &cv::cudev::exp10_func<uint>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::exp10_func<int>> rb_cCvCudevExp10FuncInt = define_class_under<cv::cudev::exp10_func<int>, cv::cudev::unary_function<int, float>>(rb_mCvCudev, "Exp10FuncInt").
    define_constructor(Constructor<cv::cudev::exp10_func<int>>()).
    define_method<float(cv::cudev::exp10_func<int>::*)(int) const>("call", &cv::cudev::exp10_func<int>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::exp10_func<float>> rb_cCvCudevExp10FuncFloat = define_class_under<cv::cudev::exp10_func<float>, cv::cudev::unary_function<float, float>>(rb_mCvCudev, "Exp10FuncFloat").
    define_constructor(Constructor<cv::cudev::exp10_func<float>>()).
    define_method<float(cv::cudev::exp10_func<float>::*)(float) const>("call", &cv::cudev::exp10_func<float>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::exp10_func<double>> rb_cCvCudevExp10FuncDouble = define_class_under<cv::cudev::exp10_func<double>, cv::cudev::unary_function<double, double>>(rb_mCvCudev, "Exp10FuncDouble").
    define_constructor(Constructor<cv::cudev::exp10_func<double>>()).
    define_method<double(cv::cudev::exp10_func<double>::*)(double) const>("call", &cv::cudev::exp10_func<double>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::log_func<uchar>> rb_cCvCudevLogFuncUchar = define_class_under<cv::cudev::log_func<uchar>, cv::cudev::unary_function<unsigned char, float>>(rb_mCvCudev, "LogFuncUchar").
    define_constructor(Constructor<cv::cudev::log_func<uchar>>()).
    define_method<float(cv::cudev::log_func<uchar>::*)(uchar) const>("call", &cv::cudev::log_func<uchar>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::log_func<schar>> rb_cCvCudevLogFuncSchar = define_class_under<cv::cudev::log_func<schar>, cv::cudev::unary_function<signed char, float>>(rb_mCvCudev, "LogFuncSchar").
    define_constructor(Constructor<cv::cudev::log_func<schar>>()).
    define_method<float(cv::cudev::log_func<schar>::*)(schar) const>("call", &cv::cudev::log_func<schar>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::log_func<ushort>> rb_cCvCudevLogFuncUshort = define_class_under<cv::cudev::log_func<ushort>, cv::cudev::unary_function<unsigned short, float>>(rb_mCvCudev, "LogFuncUshort").
    define_constructor(Constructor<cv::cudev::log_func<ushort>>()).
    define_method<float(cv::cudev::log_func<ushort>::*)(ushort) const>("call", &cv::cudev::log_func<ushort>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::log_func<short>> rb_cCvCudevLogFuncShort = define_class_under<cv::cudev::log_func<short>, cv::cudev::unary_function<short, float>>(rb_mCvCudev, "LogFuncShort").
    define_constructor(Constructor<cv::cudev::log_func<short>>()).
    define_method<float(cv::cudev::log_func<short>::*)(short) const>("call", &cv::cudev::log_func<short>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::log_func<uint>> rb_cCvCudevLogFuncUint = define_class_under<cv::cudev::log_func<uint>, cv::cudev::unary_function<unsigned int, float>>(rb_mCvCudev, "LogFuncUint").
    define_constructor(Constructor<cv::cudev::log_func<uint>>()).
    define_method<float(cv::cudev::log_func<uint>::*)(uint) const>("call", &cv::cudev::log_func<uint>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::log_func<int>> rb_cCvCudevLogFuncInt = define_class_under<cv::cudev::log_func<int>, cv::cudev::unary_function<int, float>>(rb_mCvCudev, "LogFuncInt").
    define_constructor(Constructor<cv::cudev::log_func<int>>()).
    define_method<float(cv::cudev::log_func<int>::*)(int) const>("call", &cv::cudev::log_func<int>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::log_func<float>> rb_cCvCudevLogFuncFloat = define_class_under<cv::cudev::log_func<float>, cv::cudev::unary_function<float, float>>(rb_mCvCudev, "LogFuncFloat").
    define_constructor(Constructor<cv::cudev::log_func<float>>()).
    define_method<float(cv::cudev::log_func<float>::*)(float) const>("call", &cv::cudev::log_func<float>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::log_func<double>> rb_cCvCudevLogFuncDouble = define_class_under<cv::cudev::log_func<double>, cv::cudev::unary_function<double, double>>(rb_mCvCudev, "LogFuncDouble").
    define_constructor(Constructor<cv::cudev::log_func<double>>()).
    define_method<double(cv::cudev::log_func<double>::*)(double) const>("call", &cv::cudev::log_func<double>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::log2_func<uchar>> rb_cCvCudevLog2FuncUchar = define_class_under<cv::cudev::log2_func<uchar>, cv::cudev::unary_function<unsigned char, float>>(rb_mCvCudev, "Log2FuncUchar").
    define_constructor(Constructor<cv::cudev::log2_func<uchar>>()).
    define_method<float(cv::cudev::log2_func<uchar>::*)(uchar) const>("call", &cv::cudev::log2_func<uchar>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::log2_func<schar>> rb_cCvCudevLog2FuncSchar = define_class_under<cv::cudev::log2_func<schar>, cv::cudev::unary_function<signed char, float>>(rb_mCvCudev, "Log2FuncSchar").
    define_constructor(Constructor<cv::cudev::log2_func<schar>>()).
    define_method<float(cv::cudev::log2_func<schar>::*)(schar) const>("call", &cv::cudev::log2_func<schar>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::log2_func<ushort>> rb_cCvCudevLog2FuncUshort = define_class_under<cv::cudev::log2_func<ushort>, cv::cudev::unary_function<unsigned short, float>>(rb_mCvCudev, "Log2FuncUshort").
    define_constructor(Constructor<cv::cudev::log2_func<ushort>>()).
    define_method<float(cv::cudev::log2_func<ushort>::*)(ushort) const>("call", &cv::cudev::log2_func<ushort>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::log2_func<short>> rb_cCvCudevLog2FuncShort = define_class_under<cv::cudev::log2_func<short>, cv::cudev::unary_function<short, float>>(rb_mCvCudev, "Log2FuncShort").
    define_constructor(Constructor<cv::cudev::log2_func<short>>()).
    define_method<float(cv::cudev::log2_func<short>::*)(short) const>("call", &cv::cudev::log2_func<short>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::log2_func<uint>> rb_cCvCudevLog2FuncUint = define_class_under<cv::cudev::log2_func<uint>, cv::cudev::unary_function<unsigned int, float>>(rb_mCvCudev, "Log2FuncUint").
    define_constructor(Constructor<cv::cudev::log2_func<uint>>()).
    define_method<float(cv::cudev::log2_func<uint>::*)(uint) const>("call", &cv::cudev::log2_func<uint>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::log2_func<int>> rb_cCvCudevLog2FuncInt = define_class_under<cv::cudev::log2_func<int>, cv::cudev::unary_function<int, float>>(rb_mCvCudev, "Log2FuncInt").
    define_constructor(Constructor<cv::cudev::log2_func<int>>()).
    define_method<float(cv::cudev::log2_func<int>::*)(int) const>("call", &cv::cudev::log2_func<int>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::log2_func<float>> rb_cCvCudevLog2FuncFloat = define_class_under<cv::cudev::log2_func<float>, cv::cudev::unary_function<float, float>>(rb_mCvCudev, "Log2FuncFloat").
    define_constructor(Constructor<cv::cudev::log2_func<float>>()).
    define_method<float(cv::cudev::log2_func<float>::*)(float) const>("call", &cv::cudev::log2_func<float>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::log2_func<double>> rb_cCvCudevLog2FuncDouble = define_class_under<cv::cudev::log2_func<double>, cv::cudev::unary_function<double, double>>(rb_mCvCudev, "Log2FuncDouble").
    define_constructor(Constructor<cv::cudev::log2_func<double>>()).
    define_method<double(cv::cudev::log2_func<double>::*)(double) const>("call", &cv::cudev::log2_func<double>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::log10_func<uchar>> rb_cCvCudevLog10FuncUchar = define_class_under<cv::cudev::log10_func<uchar>, cv::cudev::unary_function<unsigned char, float>>(rb_mCvCudev, "Log10FuncUchar").
    define_constructor(Constructor<cv::cudev::log10_func<uchar>>()).
    define_method<float(cv::cudev::log10_func<uchar>::*)(uchar) const>("call", &cv::cudev::log10_func<uchar>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::log10_func<schar>> rb_cCvCudevLog10FuncSchar = define_class_under<cv::cudev::log10_func<schar>, cv::cudev::unary_function<signed char, float>>(rb_mCvCudev, "Log10FuncSchar").
    define_constructor(Constructor<cv::cudev::log10_func<schar>>()).
    define_method<float(cv::cudev::log10_func<schar>::*)(schar) const>("call", &cv::cudev::log10_func<schar>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::log10_func<ushort>> rb_cCvCudevLog10FuncUshort = define_class_under<cv::cudev::log10_func<ushort>, cv::cudev::unary_function<unsigned short, float>>(rb_mCvCudev, "Log10FuncUshort").
    define_constructor(Constructor<cv::cudev::log10_func<ushort>>()).
    define_method<float(cv::cudev::log10_func<ushort>::*)(ushort) const>("call", &cv::cudev::log10_func<ushort>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::log10_func<short>> rb_cCvCudevLog10FuncShort = define_class_under<cv::cudev::log10_func<short>, cv::cudev::unary_function<short, float>>(rb_mCvCudev, "Log10FuncShort").
    define_constructor(Constructor<cv::cudev::log10_func<short>>()).
    define_method<float(cv::cudev::log10_func<short>::*)(short) const>("call", &cv::cudev::log10_func<short>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::log10_func<uint>> rb_cCvCudevLog10FuncUint = define_class_under<cv::cudev::log10_func<uint>, cv::cudev::unary_function<unsigned int, float>>(rb_mCvCudev, "Log10FuncUint").
    define_constructor(Constructor<cv::cudev::log10_func<uint>>()).
    define_method<float(cv::cudev::log10_func<uint>::*)(uint) const>("call", &cv::cudev::log10_func<uint>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::log10_func<int>> rb_cCvCudevLog10FuncInt = define_class_under<cv::cudev::log10_func<int>, cv::cudev::unary_function<int, float>>(rb_mCvCudev, "Log10FuncInt").
    define_constructor(Constructor<cv::cudev::log10_func<int>>()).
    define_method<float(cv::cudev::log10_func<int>::*)(int) const>("call", &cv::cudev::log10_func<int>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::log10_func<float>> rb_cCvCudevLog10FuncFloat = define_class_under<cv::cudev::log10_func<float>, cv::cudev::unary_function<float, float>>(rb_mCvCudev, "Log10FuncFloat").
    define_constructor(Constructor<cv::cudev::log10_func<float>>()).
    define_method<float(cv::cudev::log10_func<float>::*)(float) const>("call", &cv::cudev::log10_func<float>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::log10_func<double>> rb_cCvCudevLog10FuncDouble = define_class_under<cv::cudev::log10_func<double>, cv::cudev::unary_function<double, double>>(rb_mCvCudev, "Log10FuncDouble").
    define_constructor(Constructor<cv::cudev::log10_func<double>>()).
    define_method<double(cv::cudev::log10_func<double>::*)(double) const>("call", &cv::cudev::log10_func<double>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::sin_func<uchar>> rb_cCvCudevSinFuncUchar = define_class_under<cv::cudev::sin_func<uchar>, cv::cudev::unary_function<unsigned char, float>>(rb_mCvCudev, "SinFuncUchar").
    define_constructor(Constructor<cv::cudev::sin_func<uchar>>()).
    define_method<float(cv::cudev::sin_func<uchar>::*)(uchar) const>("call", &cv::cudev::sin_func<uchar>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::sin_func<schar>> rb_cCvCudevSinFuncSchar = define_class_under<cv::cudev::sin_func<schar>, cv::cudev::unary_function<signed char, float>>(rb_mCvCudev, "SinFuncSchar").
    define_constructor(Constructor<cv::cudev::sin_func<schar>>()).
    define_method<float(cv::cudev::sin_func<schar>::*)(schar) const>("call", &cv::cudev::sin_func<schar>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::sin_func<ushort>> rb_cCvCudevSinFuncUshort = define_class_under<cv::cudev::sin_func<ushort>, cv::cudev::unary_function<unsigned short, float>>(rb_mCvCudev, "SinFuncUshort").
    define_constructor(Constructor<cv::cudev::sin_func<ushort>>()).
    define_method<float(cv::cudev::sin_func<ushort>::*)(ushort) const>("call", &cv::cudev::sin_func<ushort>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::sin_func<short>> rb_cCvCudevSinFuncShort = define_class_under<cv::cudev::sin_func<short>, cv::cudev::unary_function<short, float>>(rb_mCvCudev, "SinFuncShort").
    define_constructor(Constructor<cv::cudev::sin_func<short>>()).
    define_method<float(cv::cudev::sin_func<short>::*)(short) const>("call", &cv::cudev::sin_func<short>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::sin_func<uint>> rb_cCvCudevSinFuncUint = define_class_under<cv::cudev::sin_func<uint>, cv::cudev::unary_function<unsigned int, float>>(rb_mCvCudev, "SinFuncUint").
    define_constructor(Constructor<cv::cudev::sin_func<uint>>()).
    define_method<float(cv::cudev::sin_func<uint>::*)(uint) const>("call", &cv::cudev::sin_func<uint>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::sin_func<int>> rb_cCvCudevSinFuncInt = define_class_under<cv::cudev::sin_func<int>, cv::cudev::unary_function<int, float>>(rb_mCvCudev, "SinFuncInt").
    define_constructor(Constructor<cv::cudev::sin_func<int>>()).
    define_method<float(cv::cudev::sin_func<int>::*)(int) const>("call", &cv::cudev::sin_func<int>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::sin_func<float>> rb_cCvCudevSinFuncFloat = define_class_under<cv::cudev::sin_func<float>, cv::cudev::unary_function<float, float>>(rb_mCvCudev, "SinFuncFloat").
    define_constructor(Constructor<cv::cudev::sin_func<float>>()).
    define_method<float(cv::cudev::sin_func<float>::*)(float) const>("call", &cv::cudev::sin_func<float>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::sin_func<double>> rb_cCvCudevSinFuncDouble = define_class_under<cv::cudev::sin_func<double>, cv::cudev::unary_function<double, double>>(rb_mCvCudev, "SinFuncDouble").
    define_constructor(Constructor<cv::cudev::sin_func<double>>()).
    define_method<double(cv::cudev::sin_func<double>::*)(double) const>("call", &cv::cudev::sin_func<double>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::cos_func<uchar>> rb_cCvCudevCosFuncUchar = define_class_under<cv::cudev::cos_func<uchar>, cv::cudev::unary_function<unsigned char, float>>(rb_mCvCudev, "CosFuncUchar").
    define_constructor(Constructor<cv::cudev::cos_func<uchar>>()).
    define_method<float(cv::cudev::cos_func<uchar>::*)(uchar) const>("call", &cv::cudev::cos_func<uchar>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::cos_func<schar>> rb_cCvCudevCosFuncSchar = define_class_under<cv::cudev::cos_func<schar>, cv::cudev::unary_function<signed char, float>>(rb_mCvCudev, "CosFuncSchar").
    define_constructor(Constructor<cv::cudev::cos_func<schar>>()).
    define_method<float(cv::cudev::cos_func<schar>::*)(schar) const>("call", &cv::cudev::cos_func<schar>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::cos_func<ushort>> rb_cCvCudevCosFuncUshort = define_class_under<cv::cudev::cos_func<ushort>, cv::cudev::unary_function<unsigned short, float>>(rb_mCvCudev, "CosFuncUshort").
    define_constructor(Constructor<cv::cudev::cos_func<ushort>>()).
    define_method<float(cv::cudev::cos_func<ushort>::*)(ushort) const>("call", &cv::cudev::cos_func<ushort>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::cos_func<short>> rb_cCvCudevCosFuncShort = define_class_under<cv::cudev::cos_func<short>, cv::cudev::unary_function<short, float>>(rb_mCvCudev, "CosFuncShort").
    define_constructor(Constructor<cv::cudev::cos_func<short>>()).
    define_method<float(cv::cudev::cos_func<short>::*)(short) const>("call", &cv::cudev::cos_func<short>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::cos_func<uint>> rb_cCvCudevCosFuncUint = define_class_under<cv::cudev::cos_func<uint>, cv::cudev::unary_function<unsigned int, float>>(rb_mCvCudev, "CosFuncUint").
    define_constructor(Constructor<cv::cudev::cos_func<uint>>()).
    define_method<float(cv::cudev::cos_func<uint>::*)(uint) const>("call", &cv::cudev::cos_func<uint>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::cos_func<int>> rb_cCvCudevCosFuncInt = define_class_under<cv::cudev::cos_func<int>, cv::cudev::unary_function<int, float>>(rb_mCvCudev, "CosFuncInt").
    define_constructor(Constructor<cv::cudev::cos_func<int>>()).
    define_method<float(cv::cudev::cos_func<int>::*)(int) const>("call", &cv::cudev::cos_func<int>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::cos_func<float>> rb_cCvCudevCosFuncFloat = define_class_under<cv::cudev::cos_func<float>, cv::cudev::unary_function<float, float>>(rb_mCvCudev, "CosFuncFloat").
    define_constructor(Constructor<cv::cudev::cos_func<float>>()).
    define_method<float(cv::cudev::cos_func<float>::*)(float) const>("call", &cv::cudev::cos_func<float>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::cos_func<double>> rb_cCvCudevCosFuncDouble = define_class_under<cv::cudev::cos_func<double>, cv::cudev::unary_function<double, double>>(rb_mCvCudev, "CosFuncDouble").
    define_constructor(Constructor<cv::cudev::cos_func<double>>()).
    define_method<double(cv::cudev::cos_func<double>::*)(double) const>("call", &cv::cudev::cos_func<double>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::tan_func<uchar>> rb_cCvCudevTanFuncUchar = define_class_under<cv::cudev::tan_func<uchar>, cv::cudev::unary_function<unsigned char, float>>(rb_mCvCudev, "TanFuncUchar").
    define_constructor(Constructor<cv::cudev::tan_func<uchar>>()).
    define_method<float(cv::cudev::tan_func<uchar>::*)(uchar) const>("call", &cv::cudev::tan_func<uchar>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::tan_func<schar>> rb_cCvCudevTanFuncSchar = define_class_under<cv::cudev::tan_func<schar>, cv::cudev::unary_function<signed char, float>>(rb_mCvCudev, "TanFuncSchar").
    define_constructor(Constructor<cv::cudev::tan_func<schar>>()).
    define_method<float(cv::cudev::tan_func<schar>::*)(schar) const>("call", &cv::cudev::tan_func<schar>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::tan_func<ushort>> rb_cCvCudevTanFuncUshort = define_class_under<cv::cudev::tan_func<ushort>, cv::cudev::unary_function<unsigned short, float>>(rb_mCvCudev, "TanFuncUshort").
    define_constructor(Constructor<cv::cudev::tan_func<ushort>>()).
    define_method<float(cv::cudev::tan_func<ushort>::*)(ushort) const>("call", &cv::cudev::tan_func<ushort>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::tan_func<short>> rb_cCvCudevTanFuncShort = define_class_under<cv::cudev::tan_func<short>, cv::cudev::unary_function<short, float>>(rb_mCvCudev, "TanFuncShort").
    define_constructor(Constructor<cv::cudev::tan_func<short>>()).
    define_method<float(cv::cudev::tan_func<short>::*)(short) const>("call", &cv::cudev::tan_func<short>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::tan_func<uint>> rb_cCvCudevTanFuncUint = define_class_under<cv::cudev::tan_func<uint>, cv::cudev::unary_function<unsigned int, float>>(rb_mCvCudev, "TanFuncUint").
    define_constructor(Constructor<cv::cudev::tan_func<uint>>()).
    define_method<float(cv::cudev::tan_func<uint>::*)(uint) const>("call", &cv::cudev::tan_func<uint>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::tan_func<int>> rb_cCvCudevTanFuncInt = define_class_under<cv::cudev::tan_func<int>, cv::cudev::unary_function<int, float>>(rb_mCvCudev, "TanFuncInt").
    define_constructor(Constructor<cv::cudev::tan_func<int>>()).
    define_method<float(cv::cudev::tan_func<int>::*)(int) const>("call", &cv::cudev::tan_func<int>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::tan_func<float>> rb_cCvCudevTanFuncFloat = define_class_under<cv::cudev::tan_func<float>, cv::cudev::unary_function<float, float>>(rb_mCvCudev, "TanFuncFloat").
    define_constructor(Constructor<cv::cudev::tan_func<float>>()).
    define_method<float(cv::cudev::tan_func<float>::*)(float) const>("call", &cv::cudev::tan_func<float>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::tan_func<double>> rb_cCvCudevTanFuncDouble = define_class_under<cv::cudev::tan_func<double>, cv::cudev::unary_function<double, double>>(rb_mCvCudev, "TanFuncDouble").
    define_constructor(Constructor<cv::cudev::tan_func<double>>()).
    define_method<double(cv::cudev::tan_func<double>::*)(double) const>("call", &cv::cudev::tan_func<double>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::asin_func<uchar>> rb_cCvCudevAsinFuncUchar = define_class_under<cv::cudev::asin_func<uchar>, cv::cudev::unary_function<unsigned char, float>>(rb_mCvCudev, "AsinFuncUchar").
    define_constructor(Constructor<cv::cudev::asin_func<uchar>>()).
    define_method<float(cv::cudev::asin_func<uchar>::*)(uchar) const>("call", &cv::cudev::asin_func<uchar>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::asin_func<schar>> rb_cCvCudevAsinFuncSchar = define_class_under<cv::cudev::asin_func<schar>, cv::cudev::unary_function<signed char, float>>(rb_mCvCudev, "AsinFuncSchar").
    define_constructor(Constructor<cv::cudev::asin_func<schar>>()).
    define_method<float(cv::cudev::asin_func<schar>::*)(schar) const>("call", &cv::cudev::asin_func<schar>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::asin_func<ushort>> rb_cCvCudevAsinFuncUshort = define_class_under<cv::cudev::asin_func<ushort>, cv::cudev::unary_function<unsigned short, float>>(rb_mCvCudev, "AsinFuncUshort").
    define_constructor(Constructor<cv::cudev::asin_func<ushort>>()).
    define_method<float(cv::cudev::asin_func<ushort>::*)(ushort) const>("call", &cv::cudev::asin_func<ushort>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::asin_func<short>> rb_cCvCudevAsinFuncShort = define_class_under<cv::cudev::asin_func<short>, cv::cudev::unary_function<short, float>>(rb_mCvCudev, "AsinFuncShort").
    define_constructor(Constructor<cv::cudev::asin_func<short>>()).
    define_method<float(cv::cudev::asin_func<short>::*)(short) const>("call", &cv::cudev::asin_func<short>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::asin_func<uint>> rb_cCvCudevAsinFuncUint = define_class_under<cv::cudev::asin_func<uint>, cv::cudev::unary_function<unsigned int, float>>(rb_mCvCudev, "AsinFuncUint").
    define_constructor(Constructor<cv::cudev::asin_func<uint>>()).
    define_method<float(cv::cudev::asin_func<uint>::*)(uint) const>("call", &cv::cudev::asin_func<uint>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::asin_func<int>> rb_cCvCudevAsinFuncInt = define_class_under<cv::cudev::asin_func<int>, cv::cudev::unary_function<int, float>>(rb_mCvCudev, "AsinFuncInt").
    define_constructor(Constructor<cv::cudev::asin_func<int>>()).
    define_method<float(cv::cudev::asin_func<int>::*)(int) const>("call", &cv::cudev::asin_func<int>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::asin_func<float>> rb_cCvCudevAsinFuncFloat = define_class_under<cv::cudev::asin_func<float>, cv::cudev::unary_function<float, float>>(rb_mCvCudev, "AsinFuncFloat").
    define_constructor(Constructor<cv::cudev::asin_func<float>>()).
    define_method<float(cv::cudev::asin_func<float>::*)(float) const>("call", &cv::cudev::asin_func<float>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::asin_func<double>> rb_cCvCudevAsinFuncDouble = define_class_under<cv::cudev::asin_func<double>, cv::cudev::unary_function<double, double>>(rb_mCvCudev, "AsinFuncDouble").
    define_constructor(Constructor<cv::cudev::asin_func<double>>()).
    define_method<double(cv::cudev::asin_func<double>::*)(double) const>("call", &cv::cudev::asin_func<double>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::acos_func<uchar>> rb_cCvCudevAcosFuncUchar = define_class_under<cv::cudev::acos_func<uchar>, cv::cudev::unary_function<unsigned char, float>>(rb_mCvCudev, "AcosFuncUchar").
    define_constructor(Constructor<cv::cudev::acos_func<uchar>>()).
    define_method<float(cv::cudev::acos_func<uchar>::*)(uchar) const>("call", &cv::cudev::acos_func<uchar>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::acos_func<schar>> rb_cCvCudevAcosFuncSchar = define_class_under<cv::cudev::acos_func<schar>, cv::cudev::unary_function<signed char, float>>(rb_mCvCudev, "AcosFuncSchar").
    define_constructor(Constructor<cv::cudev::acos_func<schar>>()).
    define_method<float(cv::cudev::acos_func<schar>::*)(schar) const>("call", &cv::cudev::acos_func<schar>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::acos_func<ushort>> rb_cCvCudevAcosFuncUshort = define_class_under<cv::cudev::acos_func<ushort>, cv::cudev::unary_function<unsigned short, float>>(rb_mCvCudev, "AcosFuncUshort").
    define_constructor(Constructor<cv::cudev::acos_func<ushort>>()).
    define_method<float(cv::cudev::acos_func<ushort>::*)(ushort) const>("call", &cv::cudev::acos_func<ushort>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::acos_func<short>> rb_cCvCudevAcosFuncShort = define_class_under<cv::cudev::acos_func<short>, cv::cudev::unary_function<short, float>>(rb_mCvCudev, "AcosFuncShort").
    define_constructor(Constructor<cv::cudev::acos_func<short>>()).
    define_method<float(cv::cudev::acos_func<short>::*)(short) const>("call", &cv::cudev::acos_func<short>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::acos_func<uint>> rb_cCvCudevAcosFuncUint = define_class_under<cv::cudev::acos_func<uint>, cv::cudev::unary_function<unsigned int, float>>(rb_mCvCudev, "AcosFuncUint").
    define_constructor(Constructor<cv::cudev::acos_func<uint>>()).
    define_method<float(cv::cudev::acos_func<uint>::*)(uint) const>("call", &cv::cudev::acos_func<uint>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::acos_func<int>> rb_cCvCudevAcosFuncInt = define_class_under<cv::cudev::acos_func<int>, cv::cudev::unary_function<int, float>>(rb_mCvCudev, "AcosFuncInt").
    define_constructor(Constructor<cv::cudev::acos_func<int>>()).
    define_method<float(cv::cudev::acos_func<int>::*)(int) const>("call", &cv::cudev::acos_func<int>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::acos_func<float>> rb_cCvCudevAcosFuncFloat = define_class_under<cv::cudev::acos_func<float>, cv::cudev::unary_function<float, float>>(rb_mCvCudev, "AcosFuncFloat").
    define_constructor(Constructor<cv::cudev::acos_func<float>>()).
    define_method<float(cv::cudev::acos_func<float>::*)(float) const>("call", &cv::cudev::acos_func<float>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::acos_func<double>> rb_cCvCudevAcosFuncDouble = define_class_under<cv::cudev::acos_func<double>, cv::cudev::unary_function<double, double>>(rb_mCvCudev, "AcosFuncDouble").
    define_constructor(Constructor<cv::cudev::acos_func<double>>()).
    define_method<double(cv::cudev::acos_func<double>::*)(double) const>("call", &cv::cudev::acos_func<double>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::atan_func<uchar>> rb_cCvCudevAtanFuncUchar = define_class_under<cv::cudev::atan_func<uchar>, cv::cudev::unary_function<unsigned char, float>>(rb_mCvCudev, "AtanFuncUchar").
    define_constructor(Constructor<cv::cudev::atan_func<uchar>>()).
    define_method<float(cv::cudev::atan_func<uchar>::*)(uchar) const>("call", &cv::cudev::atan_func<uchar>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::atan_func<schar>> rb_cCvCudevAtanFuncSchar = define_class_under<cv::cudev::atan_func<schar>, cv::cudev::unary_function<signed char, float>>(rb_mCvCudev, "AtanFuncSchar").
    define_constructor(Constructor<cv::cudev::atan_func<schar>>()).
    define_method<float(cv::cudev::atan_func<schar>::*)(schar) const>("call", &cv::cudev::atan_func<schar>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::atan_func<ushort>> rb_cCvCudevAtanFuncUshort = define_class_under<cv::cudev::atan_func<ushort>, cv::cudev::unary_function<unsigned short, float>>(rb_mCvCudev, "AtanFuncUshort").
    define_constructor(Constructor<cv::cudev::atan_func<ushort>>()).
    define_method<float(cv::cudev::atan_func<ushort>::*)(ushort) const>("call", &cv::cudev::atan_func<ushort>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::atan_func<short>> rb_cCvCudevAtanFuncShort = define_class_under<cv::cudev::atan_func<short>, cv::cudev::unary_function<short, float>>(rb_mCvCudev, "AtanFuncShort").
    define_constructor(Constructor<cv::cudev::atan_func<short>>()).
    define_method<float(cv::cudev::atan_func<short>::*)(short) const>("call", &cv::cudev::atan_func<short>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::atan_func<uint>> rb_cCvCudevAtanFuncUint = define_class_under<cv::cudev::atan_func<uint>, cv::cudev::unary_function<unsigned int, float>>(rb_mCvCudev, "AtanFuncUint").
    define_constructor(Constructor<cv::cudev::atan_func<uint>>()).
    define_method<float(cv::cudev::atan_func<uint>::*)(uint) const>("call", &cv::cudev::atan_func<uint>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::atan_func<int>> rb_cCvCudevAtanFuncInt = define_class_under<cv::cudev::atan_func<int>, cv::cudev::unary_function<int, float>>(rb_mCvCudev, "AtanFuncInt").
    define_constructor(Constructor<cv::cudev::atan_func<int>>()).
    define_method<float(cv::cudev::atan_func<int>::*)(int) const>("call", &cv::cudev::atan_func<int>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::atan_func<float>> rb_cCvCudevAtanFuncFloat = define_class_under<cv::cudev::atan_func<float>, cv::cudev::unary_function<float, float>>(rb_mCvCudev, "AtanFuncFloat").
    define_constructor(Constructor<cv::cudev::atan_func<float>>()).
    define_method<float(cv::cudev::atan_func<float>::*)(float) const>("call", &cv::cudev::atan_func<float>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::atan_func<double>> rb_cCvCudevAtanFuncDouble = define_class_under<cv::cudev::atan_func<double>, cv::cudev::unary_function<double, double>>(rb_mCvCudev, "AtanFuncDouble").
    define_constructor(Constructor<cv::cudev::atan_func<double>>()).
    define_method<double(cv::cudev::atan_func<double>::*)(double) const>("call", &cv::cudev::atan_func<double>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::sinh_func<uchar>> rb_cCvCudevSinhFuncUchar = define_class_under<cv::cudev::sinh_func<uchar>, cv::cudev::unary_function<unsigned char, float>>(rb_mCvCudev, "SinhFuncUchar").
    define_constructor(Constructor<cv::cudev::sinh_func<uchar>>()).
    define_method<float(cv::cudev::sinh_func<uchar>::*)(uchar) const>("call", &cv::cudev::sinh_func<uchar>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::sinh_func<schar>> rb_cCvCudevSinhFuncSchar = define_class_under<cv::cudev::sinh_func<schar>, cv::cudev::unary_function<signed char, float>>(rb_mCvCudev, "SinhFuncSchar").
    define_constructor(Constructor<cv::cudev::sinh_func<schar>>()).
    define_method<float(cv::cudev::sinh_func<schar>::*)(schar) const>("call", &cv::cudev::sinh_func<schar>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::sinh_func<ushort>> rb_cCvCudevSinhFuncUshort = define_class_under<cv::cudev::sinh_func<ushort>, cv::cudev::unary_function<unsigned short, float>>(rb_mCvCudev, "SinhFuncUshort").
    define_constructor(Constructor<cv::cudev::sinh_func<ushort>>()).
    define_method<float(cv::cudev::sinh_func<ushort>::*)(ushort) const>("call", &cv::cudev::sinh_func<ushort>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::sinh_func<short>> rb_cCvCudevSinhFuncShort = define_class_under<cv::cudev::sinh_func<short>, cv::cudev::unary_function<short, float>>(rb_mCvCudev, "SinhFuncShort").
    define_constructor(Constructor<cv::cudev::sinh_func<short>>()).
    define_method<float(cv::cudev::sinh_func<short>::*)(short) const>("call", &cv::cudev::sinh_func<short>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::sinh_func<uint>> rb_cCvCudevSinhFuncUint = define_class_under<cv::cudev::sinh_func<uint>, cv::cudev::unary_function<unsigned int, float>>(rb_mCvCudev, "SinhFuncUint").
    define_constructor(Constructor<cv::cudev::sinh_func<uint>>()).
    define_method<float(cv::cudev::sinh_func<uint>::*)(uint) const>("call", &cv::cudev::sinh_func<uint>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::sinh_func<int>> rb_cCvCudevSinhFuncInt = define_class_under<cv::cudev::sinh_func<int>, cv::cudev::unary_function<int, float>>(rb_mCvCudev, "SinhFuncInt").
    define_constructor(Constructor<cv::cudev::sinh_func<int>>()).
    define_method<float(cv::cudev::sinh_func<int>::*)(int) const>("call", &cv::cudev::sinh_func<int>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::sinh_func<float>> rb_cCvCudevSinhFuncFloat = define_class_under<cv::cudev::sinh_func<float>, cv::cudev::unary_function<float, float>>(rb_mCvCudev, "SinhFuncFloat").
    define_constructor(Constructor<cv::cudev::sinh_func<float>>()).
    define_method<float(cv::cudev::sinh_func<float>::*)(float) const>("call", &cv::cudev::sinh_func<float>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::sinh_func<double>> rb_cCvCudevSinhFuncDouble = define_class_under<cv::cudev::sinh_func<double>, cv::cudev::unary_function<double, double>>(rb_mCvCudev, "SinhFuncDouble").
    define_constructor(Constructor<cv::cudev::sinh_func<double>>()).
    define_method<double(cv::cudev::sinh_func<double>::*)(double) const>("call", &cv::cudev::sinh_func<double>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::cosh_func<uchar>> rb_cCvCudevCoshFuncUchar = define_class_under<cv::cudev::cosh_func<uchar>, cv::cudev::unary_function<unsigned char, float>>(rb_mCvCudev, "CoshFuncUchar").
    define_constructor(Constructor<cv::cudev::cosh_func<uchar>>()).
    define_method<float(cv::cudev::cosh_func<uchar>::*)(uchar) const>("call", &cv::cudev::cosh_func<uchar>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::cosh_func<schar>> rb_cCvCudevCoshFuncSchar = define_class_under<cv::cudev::cosh_func<schar>, cv::cudev::unary_function<signed char, float>>(rb_mCvCudev, "CoshFuncSchar").
    define_constructor(Constructor<cv::cudev::cosh_func<schar>>()).
    define_method<float(cv::cudev::cosh_func<schar>::*)(schar) const>("call", &cv::cudev::cosh_func<schar>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::cosh_func<ushort>> rb_cCvCudevCoshFuncUshort = define_class_under<cv::cudev::cosh_func<ushort>, cv::cudev::unary_function<unsigned short, float>>(rb_mCvCudev, "CoshFuncUshort").
    define_constructor(Constructor<cv::cudev::cosh_func<ushort>>()).
    define_method<float(cv::cudev::cosh_func<ushort>::*)(ushort) const>("call", &cv::cudev::cosh_func<ushort>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::cosh_func<short>> rb_cCvCudevCoshFuncShort = define_class_under<cv::cudev::cosh_func<short>, cv::cudev::unary_function<short, float>>(rb_mCvCudev, "CoshFuncShort").
    define_constructor(Constructor<cv::cudev::cosh_func<short>>()).
    define_method<float(cv::cudev::cosh_func<short>::*)(short) const>("call", &cv::cudev::cosh_func<short>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::cosh_func<uint>> rb_cCvCudevCoshFuncUint = define_class_under<cv::cudev::cosh_func<uint>, cv::cudev::unary_function<unsigned int, float>>(rb_mCvCudev, "CoshFuncUint").
    define_constructor(Constructor<cv::cudev::cosh_func<uint>>()).
    define_method<float(cv::cudev::cosh_func<uint>::*)(uint) const>("call", &cv::cudev::cosh_func<uint>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::cosh_func<int>> rb_cCvCudevCoshFuncInt = define_class_under<cv::cudev::cosh_func<int>, cv::cudev::unary_function<int, float>>(rb_mCvCudev, "CoshFuncInt").
    define_constructor(Constructor<cv::cudev::cosh_func<int>>()).
    define_method<float(cv::cudev::cosh_func<int>::*)(int) const>("call", &cv::cudev::cosh_func<int>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::cosh_func<float>> rb_cCvCudevCoshFuncFloat = define_class_under<cv::cudev::cosh_func<float>, cv::cudev::unary_function<float, float>>(rb_mCvCudev, "CoshFuncFloat").
    define_constructor(Constructor<cv::cudev::cosh_func<float>>()).
    define_method<float(cv::cudev::cosh_func<float>::*)(float) const>("call", &cv::cudev::cosh_func<float>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::cosh_func<double>> rb_cCvCudevCoshFuncDouble = define_class_under<cv::cudev::cosh_func<double>, cv::cudev::unary_function<double, double>>(rb_mCvCudev, "CoshFuncDouble").
    define_constructor(Constructor<cv::cudev::cosh_func<double>>()).
    define_method<double(cv::cudev::cosh_func<double>::*)(double) const>("call", &cv::cudev::cosh_func<double>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::tanh_func<uchar>> rb_cCvCudevTanhFuncUchar = define_class_under<cv::cudev::tanh_func<uchar>, cv::cudev::unary_function<unsigned char, float>>(rb_mCvCudev, "TanhFuncUchar").
    define_constructor(Constructor<cv::cudev::tanh_func<uchar>>()).
    define_method<float(cv::cudev::tanh_func<uchar>::*)(uchar) const>("call", &cv::cudev::tanh_func<uchar>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::tanh_func<schar>> rb_cCvCudevTanhFuncSchar = define_class_under<cv::cudev::tanh_func<schar>, cv::cudev::unary_function<signed char, float>>(rb_mCvCudev, "TanhFuncSchar").
    define_constructor(Constructor<cv::cudev::tanh_func<schar>>()).
    define_method<float(cv::cudev::tanh_func<schar>::*)(schar) const>("call", &cv::cudev::tanh_func<schar>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::tanh_func<ushort>> rb_cCvCudevTanhFuncUshort = define_class_under<cv::cudev::tanh_func<ushort>, cv::cudev::unary_function<unsigned short, float>>(rb_mCvCudev, "TanhFuncUshort").
    define_constructor(Constructor<cv::cudev::tanh_func<ushort>>()).
    define_method<float(cv::cudev::tanh_func<ushort>::*)(ushort) const>("call", &cv::cudev::tanh_func<ushort>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::tanh_func<short>> rb_cCvCudevTanhFuncShort = define_class_under<cv::cudev::tanh_func<short>, cv::cudev::unary_function<short, float>>(rb_mCvCudev, "TanhFuncShort").
    define_constructor(Constructor<cv::cudev::tanh_func<short>>()).
    define_method<float(cv::cudev::tanh_func<short>::*)(short) const>("call", &cv::cudev::tanh_func<short>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::tanh_func<uint>> rb_cCvCudevTanhFuncUint = define_class_under<cv::cudev::tanh_func<uint>, cv::cudev::unary_function<unsigned int, float>>(rb_mCvCudev, "TanhFuncUint").
    define_constructor(Constructor<cv::cudev::tanh_func<uint>>()).
    define_method<float(cv::cudev::tanh_func<uint>::*)(uint) const>("call", &cv::cudev::tanh_func<uint>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::tanh_func<int>> rb_cCvCudevTanhFuncInt = define_class_under<cv::cudev::tanh_func<int>, cv::cudev::unary_function<int, float>>(rb_mCvCudev, "TanhFuncInt").
    define_constructor(Constructor<cv::cudev::tanh_func<int>>()).
    define_method<float(cv::cudev::tanh_func<int>::*)(int) const>("call", &cv::cudev::tanh_func<int>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::tanh_func<float>> rb_cCvCudevTanhFuncFloat = define_class_under<cv::cudev::tanh_func<float>, cv::cudev::unary_function<float, float>>(rb_mCvCudev, "TanhFuncFloat").
    define_constructor(Constructor<cv::cudev::tanh_func<float>>()).
    define_method<float(cv::cudev::tanh_func<float>::*)(float) const>("call", &cv::cudev::tanh_func<float>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::tanh_func<double>> rb_cCvCudevTanhFuncDouble = define_class_under<cv::cudev::tanh_func<double>, cv::cudev::unary_function<double, double>>(rb_mCvCudev, "TanhFuncDouble").
    define_constructor(Constructor<cv::cudev::tanh_func<double>>()).
    define_method<double(cv::cudev::tanh_func<double>::*)(double) const>("call", &cv::cudev::tanh_func<double>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::asinh_func<uchar>> rb_cCvCudevAsinhFuncUchar = define_class_under<cv::cudev::asinh_func<uchar>, cv::cudev::unary_function<unsigned char, float>>(rb_mCvCudev, "AsinhFuncUchar").
    define_constructor(Constructor<cv::cudev::asinh_func<uchar>>()).
    define_method<float(cv::cudev::asinh_func<uchar>::*)(uchar) const>("call", &cv::cudev::asinh_func<uchar>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::asinh_func<schar>> rb_cCvCudevAsinhFuncSchar = define_class_under<cv::cudev::asinh_func<schar>, cv::cudev::unary_function<signed char, float>>(rb_mCvCudev, "AsinhFuncSchar").
    define_constructor(Constructor<cv::cudev::asinh_func<schar>>()).
    define_method<float(cv::cudev::asinh_func<schar>::*)(schar) const>("call", &cv::cudev::asinh_func<schar>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::asinh_func<ushort>> rb_cCvCudevAsinhFuncUshort = define_class_under<cv::cudev::asinh_func<ushort>, cv::cudev::unary_function<unsigned short, float>>(rb_mCvCudev, "AsinhFuncUshort").
    define_constructor(Constructor<cv::cudev::asinh_func<ushort>>()).
    define_method<float(cv::cudev::asinh_func<ushort>::*)(ushort) const>("call", &cv::cudev::asinh_func<ushort>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::asinh_func<short>> rb_cCvCudevAsinhFuncShort = define_class_under<cv::cudev::asinh_func<short>, cv::cudev::unary_function<short, float>>(rb_mCvCudev, "AsinhFuncShort").
    define_constructor(Constructor<cv::cudev::asinh_func<short>>()).
    define_method<float(cv::cudev::asinh_func<short>::*)(short) const>("call", &cv::cudev::asinh_func<short>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::asinh_func<uint>> rb_cCvCudevAsinhFuncUint = define_class_under<cv::cudev::asinh_func<uint>, cv::cudev::unary_function<unsigned int, float>>(rb_mCvCudev, "AsinhFuncUint").
    define_constructor(Constructor<cv::cudev::asinh_func<uint>>()).
    define_method<float(cv::cudev::asinh_func<uint>::*)(uint) const>("call", &cv::cudev::asinh_func<uint>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::asinh_func<int>> rb_cCvCudevAsinhFuncInt = define_class_under<cv::cudev::asinh_func<int>, cv::cudev::unary_function<int, float>>(rb_mCvCudev, "AsinhFuncInt").
    define_constructor(Constructor<cv::cudev::asinh_func<int>>()).
    define_method<float(cv::cudev::asinh_func<int>::*)(int) const>("call", &cv::cudev::asinh_func<int>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::asinh_func<float>> rb_cCvCudevAsinhFuncFloat = define_class_under<cv::cudev::asinh_func<float>, cv::cudev::unary_function<float, float>>(rb_mCvCudev, "AsinhFuncFloat").
    define_constructor(Constructor<cv::cudev::asinh_func<float>>()).
    define_method<float(cv::cudev::asinh_func<float>::*)(float) const>("call", &cv::cudev::asinh_func<float>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::asinh_func<double>> rb_cCvCudevAsinhFuncDouble = define_class_under<cv::cudev::asinh_func<double>, cv::cudev::unary_function<double, double>>(rb_mCvCudev, "AsinhFuncDouble").
    define_constructor(Constructor<cv::cudev::asinh_func<double>>()).
    define_method<double(cv::cudev::asinh_func<double>::*)(double) const>("call", &cv::cudev::asinh_func<double>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::acosh_func<uchar>> rb_cCvCudevAcoshFuncUchar = define_class_under<cv::cudev::acosh_func<uchar>, cv::cudev::unary_function<unsigned char, float>>(rb_mCvCudev, "AcoshFuncUchar").
    define_constructor(Constructor<cv::cudev::acosh_func<uchar>>()).
    define_method<float(cv::cudev::acosh_func<uchar>::*)(uchar) const>("call", &cv::cudev::acosh_func<uchar>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::acosh_func<schar>> rb_cCvCudevAcoshFuncSchar = define_class_under<cv::cudev::acosh_func<schar>, cv::cudev::unary_function<signed char, float>>(rb_mCvCudev, "AcoshFuncSchar").
    define_constructor(Constructor<cv::cudev::acosh_func<schar>>()).
    define_method<float(cv::cudev::acosh_func<schar>::*)(schar) const>("call", &cv::cudev::acosh_func<schar>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::acosh_func<ushort>> rb_cCvCudevAcoshFuncUshort = define_class_under<cv::cudev::acosh_func<ushort>, cv::cudev::unary_function<unsigned short, float>>(rb_mCvCudev, "AcoshFuncUshort").
    define_constructor(Constructor<cv::cudev::acosh_func<ushort>>()).
    define_method<float(cv::cudev::acosh_func<ushort>::*)(ushort) const>("call", &cv::cudev::acosh_func<ushort>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::acosh_func<short>> rb_cCvCudevAcoshFuncShort = define_class_under<cv::cudev::acosh_func<short>, cv::cudev::unary_function<short, float>>(rb_mCvCudev, "AcoshFuncShort").
    define_constructor(Constructor<cv::cudev::acosh_func<short>>()).
    define_method<float(cv::cudev::acosh_func<short>::*)(short) const>("call", &cv::cudev::acosh_func<short>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::acosh_func<uint>> rb_cCvCudevAcoshFuncUint = define_class_under<cv::cudev::acosh_func<uint>, cv::cudev::unary_function<unsigned int, float>>(rb_mCvCudev, "AcoshFuncUint").
    define_constructor(Constructor<cv::cudev::acosh_func<uint>>()).
    define_method<float(cv::cudev::acosh_func<uint>::*)(uint) const>("call", &cv::cudev::acosh_func<uint>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::acosh_func<int>> rb_cCvCudevAcoshFuncInt = define_class_under<cv::cudev::acosh_func<int>, cv::cudev::unary_function<int, float>>(rb_mCvCudev, "AcoshFuncInt").
    define_constructor(Constructor<cv::cudev::acosh_func<int>>()).
    define_method<float(cv::cudev::acosh_func<int>::*)(int) const>("call", &cv::cudev::acosh_func<int>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::acosh_func<float>> rb_cCvCudevAcoshFuncFloat = define_class_under<cv::cudev::acosh_func<float>, cv::cudev::unary_function<float, float>>(rb_mCvCudev, "AcoshFuncFloat").
    define_constructor(Constructor<cv::cudev::acosh_func<float>>()).
    define_method<float(cv::cudev::acosh_func<float>::*)(float) const>("call", &cv::cudev::acosh_func<float>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::acosh_func<double>> rb_cCvCudevAcoshFuncDouble = define_class_under<cv::cudev::acosh_func<double>, cv::cudev::unary_function<double, double>>(rb_mCvCudev, "AcoshFuncDouble").
    define_constructor(Constructor<cv::cudev::acosh_func<double>>()).
    define_method<double(cv::cudev::acosh_func<double>::*)(double) const>("call", &cv::cudev::acosh_func<double>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::atanh_func<uchar>> rb_cCvCudevAtanhFuncUchar = define_class_under<cv::cudev::atanh_func<uchar>, cv::cudev::unary_function<unsigned char, float>>(rb_mCvCudev, "AtanhFuncUchar").
    define_constructor(Constructor<cv::cudev::atanh_func<uchar>>()).
    define_method<float(cv::cudev::atanh_func<uchar>::*)(uchar) const>("call", &cv::cudev::atanh_func<uchar>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::atanh_func<schar>> rb_cCvCudevAtanhFuncSchar = define_class_under<cv::cudev::atanh_func<schar>, cv::cudev::unary_function<signed char, float>>(rb_mCvCudev, "AtanhFuncSchar").
    define_constructor(Constructor<cv::cudev::atanh_func<schar>>()).
    define_method<float(cv::cudev::atanh_func<schar>::*)(schar) const>("call", &cv::cudev::atanh_func<schar>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::atanh_func<ushort>> rb_cCvCudevAtanhFuncUshort = define_class_under<cv::cudev::atanh_func<ushort>, cv::cudev::unary_function<unsigned short, float>>(rb_mCvCudev, "AtanhFuncUshort").
    define_constructor(Constructor<cv::cudev::atanh_func<ushort>>()).
    define_method<float(cv::cudev::atanh_func<ushort>::*)(ushort) const>("call", &cv::cudev::atanh_func<ushort>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::atanh_func<short>> rb_cCvCudevAtanhFuncShort = define_class_under<cv::cudev::atanh_func<short>, cv::cudev::unary_function<short, float>>(rb_mCvCudev, "AtanhFuncShort").
    define_constructor(Constructor<cv::cudev::atanh_func<short>>()).
    define_method<float(cv::cudev::atanh_func<short>::*)(short) const>("call", &cv::cudev::atanh_func<short>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::atanh_func<uint>> rb_cCvCudevAtanhFuncUint = define_class_under<cv::cudev::atanh_func<uint>, cv::cudev::unary_function<unsigned int, float>>(rb_mCvCudev, "AtanhFuncUint").
    define_constructor(Constructor<cv::cudev::atanh_func<uint>>()).
    define_method<float(cv::cudev::atanh_func<uint>::*)(uint) const>("call", &cv::cudev::atanh_func<uint>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::atanh_func<int>> rb_cCvCudevAtanhFuncInt = define_class_under<cv::cudev::atanh_func<int>, cv::cudev::unary_function<int, float>>(rb_mCvCudev, "AtanhFuncInt").
    define_constructor(Constructor<cv::cudev::atanh_func<int>>()).
    define_method<float(cv::cudev::atanh_func<int>::*)(int) const>("call", &cv::cudev::atanh_func<int>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::atanh_func<float>> rb_cCvCudevAtanhFuncFloat = define_class_under<cv::cudev::atanh_func<float>, cv::cudev::unary_function<float, float>>(rb_mCvCudev, "AtanhFuncFloat").
    define_constructor(Constructor<cv::cudev::atanh_func<float>>()).
    define_method<float(cv::cudev::atanh_func<float>::*)(float) const>("call", &cv::cudev::atanh_func<float>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::atanh_func<double>> rb_cCvCudevAtanhFuncDouble = define_class_under<cv::cudev::atanh_func<double>, cv::cudev::unary_function<double, double>>(rb_mCvCudev, "AtanhFuncDouble").
    define_constructor(Constructor<cv::cudev::atanh_func<double>>()).
    define_method<double(cv::cudev::atanh_func<double>::*)(double) const>("call", &cv::cudev::atanh_func<double>::operator(),
      Arg("a"));

  Rice::Data_Type<cv::cudev::binary_function<unsigned char, unsigned char, float>> rb_cBinaryFunctionUnsignedCharUnsignedCharFloat = define_class_under<cv::cudev::binary_function<unsigned char, unsigned char, float>>(rb_mCvCudev, "BinaryFunctionUnsignedCharUnsignedCharFloat").
    define(&binary_function_builder<Data_Type<cv::cudev::binary_function<unsigned char, unsigned char, float>>, unsigned char, unsigned char, float>);
  Rice::Data_Type<cv::cudev::hypot_func<uchar>> rb_cCvCudevHypotFuncUchar = define_class_under<cv::cudev::hypot_func<uchar>, cv::cudev::binary_function<unsigned char, unsigned char, float>>(rb_mCvCudev, "HypotFuncUchar").
    define_constructor(Constructor<cv::cudev::hypot_func<uchar>>()).
    define_method<float(cv::cudev::hypot_func<uchar>::*)(uchar, uchar) const>("call", &cv::cudev::hypot_func<uchar>::operator(),
      Arg("a"), Arg("b"));

  Rice::Data_Type<cv::cudev::binary_function<signed char, signed char, float>> rb_cBinaryFunctionSignedCharSignedCharFloat = define_class_under<cv::cudev::binary_function<signed char, signed char, float>>(rb_mCvCudev, "BinaryFunctionSignedCharSignedCharFloat").
    define(&binary_function_builder<Data_Type<cv::cudev::binary_function<signed char, signed char, float>>, signed char, signed char, float>);
  Rice::Data_Type<cv::cudev::hypot_func<schar>> rb_cCvCudevHypotFuncSchar = define_class_under<cv::cudev::hypot_func<schar>, cv::cudev::binary_function<signed char, signed char, float>>(rb_mCvCudev, "HypotFuncSchar").
    define_constructor(Constructor<cv::cudev::hypot_func<schar>>()).
    define_method<float(cv::cudev::hypot_func<schar>::*)(schar, schar) const>("call", &cv::cudev::hypot_func<schar>::operator(),
      Arg("a"), Arg("b"));

  Rice::Data_Type<cv::cudev::binary_function<unsigned short, unsigned short, float>> rb_cBinaryFunctionUnsignedShortUnsignedShortFloat = define_class_under<cv::cudev::binary_function<unsigned short, unsigned short, float>>(rb_mCvCudev, "BinaryFunctionUnsignedShortUnsignedShortFloat").
    define(&binary_function_builder<Data_Type<cv::cudev::binary_function<unsigned short, unsigned short, float>>, unsigned short, unsigned short, float>);
  Rice::Data_Type<cv::cudev::hypot_func<ushort>> rb_cCvCudevHypotFuncUshort = define_class_under<cv::cudev::hypot_func<ushort>, cv::cudev::binary_function<unsigned short, unsigned short, float>>(rb_mCvCudev, "HypotFuncUshort").
    define_constructor(Constructor<cv::cudev::hypot_func<ushort>>()).
    define_method<float(cv::cudev::hypot_func<ushort>::*)(ushort, ushort) const>("call", &cv::cudev::hypot_func<ushort>::operator(),
      Arg("a"), Arg("b"));

  Rice::Data_Type<cv::cudev::binary_function<short, short, float>> rb_cBinaryFunctionShortShortFloat = define_class_under<cv::cudev::binary_function<short, short, float>>(rb_mCvCudev, "BinaryFunctionShortShortFloat").
    define(&binary_function_builder<Data_Type<cv::cudev::binary_function<short, short, float>>, short, short, float>);
  Rice::Data_Type<cv::cudev::hypot_func<short>> rb_cCvCudevHypotFuncShort = define_class_under<cv::cudev::hypot_func<short>, cv::cudev::binary_function<short, short, float>>(rb_mCvCudev, "HypotFuncShort").
    define_constructor(Constructor<cv::cudev::hypot_func<short>>()).
    define_method<float(cv::cudev::hypot_func<short>::*)(short, short) const>("call", &cv::cudev::hypot_func<short>::operator(),
      Arg("a"), Arg("b"));

  Rice::Data_Type<cv::cudev::binary_function<unsigned int, unsigned int, float>> rb_cBinaryFunctionUnsignedIntUnsignedIntFloat = define_class_under<cv::cudev::binary_function<unsigned int, unsigned int, float>>(rb_mCvCudev, "BinaryFunctionUnsignedIntUnsignedIntFloat").
    define(&binary_function_builder<Data_Type<cv::cudev::binary_function<unsigned int, unsigned int, float>>, unsigned int, unsigned int, float>);
  Rice::Data_Type<cv::cudev::hypot_func<uint>> rb_cCvCudevHypotFuncUint = define_class_under<cv::cudev::hypot_func<uint>, cv::cudev::binary_function<unsigned int, unsigned int, float>>(rb_mCvCudev, "HypotFuncUint").
    define_constructor(Constructor<cv::cudev::hypot_func<uint>>()).
    define_method<float(cv::cudev::hypot_func<uint>::*)(uint, uint) const>("call", &cv::cudev::hypot_func<uint>::operator(),
      Arg("a"), Arg("b"));

  Rice::Data_Type<cv::cudev::binary_function<int, int, float>> rb_cBinaryFunctionIntIntFloat = define_class_under<cv::cudev::binary_function<int, int, float>>(rb_mCvCudev, "BinaryFunctionIntIntFloat").
    define(&binary_function_builder<Data_Type<cv::cudev::binary_function<int, int, float>>, int, int, float>);
  Rice::Data_Type<cv::cudev::hypot_func<int>> rb_cCvCudevHypotFuncInt = define_class_under<cv::cudev::hypot_func<int>, cv::cudev::binary_function<int, int, float>>(rb_mCvCudev, "HypotFuncInt").
    define_constructor(Constructor<cv::cudev::hypot_func<int>>()).
    define_method<float(cv::cudev::hypot_func<int>::*)(int, int) const>("call", &cv::cudev::hypot_func<int>::operator(),
      Arg("a"), Arg("b"));

  Rice::Data_Type<cv::cudev::hypot_func<float>> rb_cCvCudevHypotFuncFloat = define_class_under<cv::cudev::hypot_func<float>, cv::cudev::binary_function<float, float, float>>(rb_mCvCudev, "HypotFuncFloat").
    define_constructor(Constructor<cv::cudev::hypot_func<float>>()).
    define_method<float(cv::cudev::hypot_func<float>::*)(float, float) const>("call", &cv::cudev::hypot_func<float>::operator(),
      Arg("a"), Arg("b"));

  Rice::Data_Type<cv::cudev::hypot_func<double>> rb_cCvCudevHypotFuncDouble = define_class_under<cv::cudev::hypot_func<double>, cv::cudev::binary_function<double, double, double>>(rb_mCvCudev, "HypotFuncDouble").
    define_constructor(Constructor<cv::cudev::hypot_func<double>>()).
    define_method<double(cv::cudev::hypot_func<double>::*)(double, double) const>("call", &cv::cudev::hypot_func<double>::operator(),
      Arg("a"), Arg("b"));

  Rice::Data_Type<cv::cudev::atan2_func<uchar>> rb_cCvCudevAtan2FuncUchar = define_class_under<cv::cudev::atan2_func<uchar>, cv::cudev::binary_function<unsigned char, unsigned char, float>>(rb_mCvCudev, "Atan2FuncUchar").
    define_constructor(Constructor<cv::cudev::atan2_func<uchar>>()).
    define_method<float(cv::cudev::atan2_func<uchar>::*)(uchar, uchar) const>("call", &cv::cudev::atan2_func<uchar>::operator(),
      Arg("a"), Arg("b"));

  Rice::Data_Type<cv::cudev::atan2_func<schar>> rb_cCvCudevAtan2FuncSchar = define_class_under<cv::cudev::atan2_func<schar>, cv::cudev::binary_function<signed char, signed char, float>>(rb_mCvCudev, "Atan2FuncSchar").
    define_constructor(Constructor<cv::cudev::atan2_func<schar>>()).
    define_method<float(cv::cudev::atan2_func<schar>::*)(schar, schar) const>("call", &cv::cudev::atan2_func<schar>::operator(),
      Arg("a"), Arg("b"));

  Rice::Data_Type<cv::cudev::atan2_func<ushort>> rb_cCvCudevAtan2FuncUshort = define_class_under<cv::cudev::atan2_func<ushort>, cv::cudev::binary_function<unsigned short, unsigned short, float>>(rb_mCvCudev, "Atan2FuncUshort").
    define_constructor(Constructor<cv::cudev::atan2_func<ushort>>()).
    define_method<float(cv::cudev::atan2_func<ushort>::*)(ushort, ushort) const>("call", &cv::cudev::atan2_func<ushort>::operator(),
      Arg("a"), Arg("b"));

  Rice::Data_Type<cv::cudev::atan2_func<short>> rb_cCvCudevAtan2FuncShort = define_class_under<cv::cudev::atan2_func<short>, cv::cudev::binary_function<short, short, float>>(rb_mCvCudev, "Atan2FuncShort").
    define_constructor(Constructor<cv::cudev::atan2_func<short>>()).
    define_method<float(cv::cudev::atan2_func<short>::*)(short, short) const>("call", &cv::cudev::atan2_func<short>::operator(),
      Arg("a"), Arg("b"));

  Rice::Data_Type<cv::cudev::atan2_func<uint>> rb_cCvCudevAtan2FuncUint = define_class_under<cv::cudev::atan2_func<uint>, cv::cudev::binary_function<unsigned int, unsigned int, float>>(rb_mCvCudev, "Atan2FuncUint").
    define_constructor(Constructor<cv::cudev::atan2_func<uint>>()).
    define_method<float(cv::cudev::atan2_func<uint>::*)(uint, uint) const>("call", &cv::cudev::atan2_func<uint>::operator(),
      Arg("a"), Arg("b"));

  Rice::Data_Type<cv::cudev::atan2_func<int>> rb_cCvCudevAtan2FuncInt = define_class_under<cv::cudev::atan2_func<int>, cv::cudev::binary_function<int, int, float>>(rb_mCvCudev, "Atan2FuncInt").
    define_constructor(Constructor<cv::cudev::atan2_func<int>>()).
    define_method<float(cv::cudev::atan2_func<int>::*)(int, int) const>("call", &cv::cudev::atan2_func<int>::operator(),
      Arg("a"), Arg("b"));

  Rice::Data_Type<cv::cudev::atan2_func<float>> rb_cCvCudevAtan2FuncFloat = define_class_under<cv::cudev::atan2_func<float>, cv::cudev::binary_function<float, float, float>>(rb_mCvCudev, "Atan2FuncFloat").
    define_constructor(Constructor<cv::cudev::atan2_func<float>>()).
    define_method<float(cv::cudev::atan2_func<float>::*)(float, float) const>("call", &cv::cudev::atan2_func<float>::operator(),
      Arg("a"), Arg("b"));

  Rice::Data_Type<cv::cudev::atan2_func<double>> rb_cCvCudevAtan2FuncDouble = define_class_under<cv::cudev::atan2_func<double>, cv::cudev::binary_function<double, double, double>>(rb_mCvCudev, "Atan2FuncDouble").
    define_constructor(Constructor<cv::cudev::atan2_func<double>>()).
    define_method<double(cv::cudev::atan2_func<double>::*)(double, double) const>("call", &cv::cudev::atan2_func<double>::operator(),
      Arg("a"), Arg("b"));

  Rice::Data_Type<cv::cudev::pow_func<double>> rb_cCvCudevPowFuncDouble = define_class_under<cv::cudev::pow_func<double>, cv::cudev::binary_function<double, double, double>>(rb_mCvCudev, "PowFuncDouble").
    define_constructor(Constructor<cv::cudev::pow_func<double>>()).
    define_method<double(cv::cudev::pow_func<double>::*)(double, double) const>("call", &cv::cudev::pow_func<double>::operator(),
      Arg("val"), Arg("power"));

  Rice::Data_Type<cv::cudev::unary_function<float, short>> rb_cUnaryFunctionFloatShort = define_class_under<cv::cudev::unary_function<float, short>>(rb_mCvCudev, "UnaryFunctionFloatShort").
    define(&unary_function_builder<Data_Type<cv::cudev::unary_function<float, short>>, float, short>);
  Rice::Data_Type<cv::cudev::saturate_cast_fp16_func<float, short>> rb_cCvCudevSaturateCastFp16FuncFloatShort = define_class_under<cv::cudev::saturate_cast_fp16_func<float, short>, cv::cudev::unary_function<float, short>>(rb_mCvCudev, "SaturateCastFp16FuncFloatShort").
    define_constructor(Constructor<cv::cudev::saturate_cast_fp16_func<float, short>>()).
    define_method<short(cv::cudev::saturate_cast_fp16_func<float, short>::*)(float) const>("call", &cv::cudev::saturate_cast_fp16_func<float, short>::operator(),
      Arg("v"));

  Rice::Data_Type<cv::cudev::saturate_cast_fp16_func<short, float>> rb_cCvCudevSaturateCastFp16FuncShortFloat = define_class_under<cv::cudev::saturate_cast_fp16_func<short, float>, cv::cudev::unary_function<short, float>>(rb_mCvCudev, "SaturateCastFp16FuncShortFloat").
    define_constructor(Constructor<cv::cudev::saturate_cast_fp16_func<short, float>>()).
    define_method<float(cv::cudev::saturate_cast_fp16_func<short, float>::*)(short) const>("call", &cv::cudev::saturate_cast_fp16_func<short, float>::operator(),
      Arg("v"));
}