#include "type_traits_detail-rb.ipp"

void Init_Core_Cuda_Detail_TypeTraitsDetail()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");

  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");

  Module rb_mCvCudaDeviceTypeTraitsDetail = define_module_under(rb_mCvCudaDevice, "TypeTraitsDetail");

  Rice::Data_Type<cv::cuda::device::type_traits_detail::IsSignedIntergral<schar>> rb_cCvCudaDeviceTypeTraitsDetailIsSignedIntergralSchar = define_class_under<cv::cuda::device::type_traits_detail::IsSignedIntergral<schar>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsSignedIntergralSchar").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsSignedIntergral<schar>>());

  rb_cCvCudaDeviceTypeTraitsDetailIsSignedIntergralSchar.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsSignedIntergral<schar>::value);

  Rice::Data_Type<cv::cuda::device::type_traits_detail::IsSignedIntergral<char1>> rb_cCvCudaDeviceTypeTraitsDetailIsSignedIntergralChar1 = define_class_under<cv::cuda::device::type_traits_detail::IsSignedIntergral<char1>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsSignedIntergralChar1").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsSignedIntergral<char1>>());

  rb_cCvCudaDeviceTypeTraitsDetailIsSignedIntergralChar1.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsSignedIntergral<char1>::value);

  Rice::Data_Type<cv::cuda::device::type_traits_detail::IsSignedIntergral<short>> rb_cCvCudaDeviceTypeTraitsDetailIsSignedIntergralShort = define_class_under<cv::cuda::device::type_traits_detail::IsSignedIntergral<short>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsSignedIntergralShort").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsSignedIntergral<short>>());

  rb_cCvCudaDeviceTypeTraitsDetailIsSignedIntergralShort.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsSignedIntergral<short>::value);

  Rice::Data_Type<cv::cuda::device::type_traits_detail::IsSignedIntergral<short1>> rb_cCvCudaDeviceTypeTraitsDetailIsSignedIntergralShort1 = define_class_under<cv::cuda::device::type_traits_detail::IsSignedIntergral<short1>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsSignedIntergralShort1").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsSignedIntergral<short1>>());

  rb_cCvCudaDeviceTypeTraitsDetailIsSignedIntergralShort1.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsSignedIntergral<short1>::value);

  Rice::Data_Type<cv::cuda::device::type_traits_detail::IsSignedIntergral<int>> rb_cCvCudaDeviceTypeTraitsDetailIsSignedIntergralInt = define_class_under<cv::cuda::device::type_traits_detail::IsSignedIntergral<int>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsSignedIntergralInt").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsSignedIntergral<int>>());

  rb_cCvCudaDeviceTypeTraitsDetailIsSignedIntergralInt.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsSignedIntergral<int>::value);

  Rice::Data_Type<cv::cuda::device::type_traits_detail::IsSignedIntergral<int1>> rb_cCvCudaDeviceTypeTraitsDetailIsSignedIntergralInt1 = define_class_under<cv::cuda::device::type_traits_detail::IsSignedIntergral<int1>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsSignedIntergralInt1").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsSignedIntergral<int1>>());

  rb_cCvCudaDeviceTypeTraitsDetailIsSignedIntergralInt1.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsSignedIntergral<int1>::value);

  Rice::Data_Type<cv::cuda::device::type_traits_detail::IsUnsignedIntegral<uchar>> rb_cCvCudaDeviceTypeTraitsDetailIsUnsignedIntegralUchar = define_class_under<cv::cuda::device::type_traits_detail::IsUnsignedIntegral<uchar>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsUnsignedIntegralUchar").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsUnsignedIntegral<uchar>>());

  rb_cCvCudaDeviceTypeTraitsDetailIsUnsignedIntegralUchar.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsUnsignedIntegral<uchar>::value);

  Rice::Data_Type<cv::cuda::device::type_traits_detail::IsUnsignedIntegral<uchar1>> rb_cCvCudaDeviceTypeTraitsDetailIsUnsignedIntegralUchar1 = define_class_under<cv::cuda::device::type_traits_detail::IsUnsignedIntegral<uchar1>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsUnsignedIntegralUchar1").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsUnsignedIntegral<uchar1>>());

  rb_cCvCudaDeviceTypeTraitsDetailIsUnsignedIntegralUchar1.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsUnsignedIntegral<uchar1>::value);

  Rice::Data_Type<cv::cuda::device::type_traits_detail::IsUnsignedIntegral<ushort>> rb_cCvCudaDeviceTypeTraitsDetailIsUnsignedIntegralUshort = define_class_under<cv::cuda::device::type_traits_detail::IsUnsignedIntegral<ushort>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsUnsignedIntegralUshort").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsUnsignedIntegral<ushort>>());

  rb_cCvCudaDeviceTypeTraitsDetailIsUnsignedIntegralUshort.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsUnsignedIntegral<ushort>::value);

  Rice::Data_Type<cv::cuda::device::type_traits_detail::IsUnsignedIntegral<ushort1>> rb_cCvCudaDeviceTypeTraitsDetailIsUnsignedIntegralUshort1 = define_class_under<cv::cuda::device::type_traits_detail::IsUnsignedIntegral<ushort1>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsUnsignedIntegralUshort1").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsUnsignedIntegral<ushort1>>());

  rb_cCvCudaDeviceTypeTraitsDetailIsUnsignedIntegralUshort1.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsUnsignedIntegral<ushort1>::value);

  Rice::Data_Type<cv::cuda::device::type_traits_detail::IsUnsignedIntegral<uint>> rb_cCvCudaDeviceTypeTraitsDetailIsUnsignedIntegralUint = define_class_under<cv::cuda::device::type_traits_detail::IsUnsignedIntegral<uint>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsUnsignedIntegralUint").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsUnsignedIntegral<uint>>());

  rb_cCvCudaDeviceTypeTraitsDetailIsUnsignedIntegralUint.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsUnsignedIntegral<uint>::value);

  Rice::Data_Type<cv::cuda::device::type_traits_detail::IsUnsignedIntegral<uint1>> rb_cCvCudaDeviceTypeTraitsDetailIsUnsignedIntegralUint1 = define_class_under<cv::cuda::device::type_traits_detail::IsUnsignedIntegral<uint1>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsUnsignedIntegralUint1").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsUnsignedIntegral<uint1>>());

  rb_cCvCudaDeviceTypeTraitsDetailIsUnsignedIntegralUint1.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsUnsignedIntegral<uint1>::value);

  Rice::Data_Type<cv::cuda::device::type_traits_detail::IsIntegral<char>> rb_cCvCudaDeviceTypeTraitsDetailIsIntegralChar = define_class_under<cv::cuda::device::type_traits_detail::IsIntegral<char>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsIntegralChar").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsIntegral<char>>());

  rb_cCvCudaDeviceTypeTraitsDetailIsIntegralChar.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsIntegral<char>::value);

  Rice::Data_Type<cv::cuda::device::type_traits_detail::IsIntegral<bool>> rb_cCvCudaDeviceTypeTraitsDetailIsIntegralBool = define_class_under<cv::cuda::device::type_traits_detail::IsIntegral<bool>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsIntegralBool").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsIntegral<bool>>());

  rb_cCvCudaDeviceTypeTraitsDetailIsIntegralBool.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsIntegral<bool>::value);

  Rice::Data_Type<cv::cuda::device::type_traits_detail::IsFloat<float>> rb_cCvCudaDeviceTypeTraitsDetailIsFloatFloat = define_class_under<cv::cuda::device::type_traits_detail::IsFloat<float>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsFloatFloat").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsFloat<float>>());

  rb_cCvCudaDeviceTypeTraitsDetailIsFloatFloat.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsFloat<float>::value);

  Rice::Data_Type<cv::cuda::device::type_traits_detail::IsFloat<double>> rb_cCvCudaDeviceTypeTraitsDetailIsFloatDouble = define_class_under<cv::cuda::device::type_traits_detail::IsFloat<double>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsFloatDouble").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsFloat<double>>());

  rb_cCvCudaDeviceTypeTraitsDetailIsFloatDouble.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsFloat<double>::value);

  Rice::Data_Type<cv::cuda::device::type_traits_detail::IsVec<uchar1>> rb_cCvCudaDeviceTypeTraitsDetailIsVecUchar1 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<uchar1>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecUchar1").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsVec<uchar1>>());

  rb_cCvCudaDeviceTypeTraitsDetailIsVecUchar1.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsVec<uchar1>::value);

  Rice::Data_Type<cv::cuda::device::type_traits_detail::IsVec<uchar2>> rb_cCvCudaDeviceTypeTraitsDetailIsVecUchar2 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<uchar2>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecUchar2").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsVec<uchar2>>());

  rb_cCvCudaDeviceTypeTraitsDetailIsVecUchar2.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsVec<uchar2>::value);

  Rice::Data_Type<cv::cuda::device::type_traits_detail::IsVec<uchar3>> rb_cCvCudaDeviceTypeTraitsDetailIsVecUchar3 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<uchar3>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecUchar3").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsVec<uchar3>>());

  rb_cCvCudaDeviceTypeTraitsDetailIsVecUchar3.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsVec<uchar3>::value);

  Rice::Data_Type<cv::cuda::device::type_traits_detail::IsVec<uchar4>> rb_cCvCudaDeviceTypeTraitsDetailIsVecUchar4 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<uchar4>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecUchar4").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsVec<uchar4>>());

  rb_cCvCudaDeviceTypeTraitsDetailIsVecUchar4.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsVec<uchar4>::value);

  Rice::Data_Type<cv::cuda::device::type_traits_detail::IsVec<cv::cuda::device::uchar8>> rb_cCvCudaDeviceTypeTraitsDetailIsVecUchar8 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<cv::cuda::device::uchar8>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecUchar8").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsVec<cv::cuda::device::uchar8>>());

  rb_cCvCudaDeviceTypeTraitsDetailIsVecUchar8.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsVec<cv::cuda::device::uchar8>::value);

  Rice::Data_Type<cv::cuda::device::type_traits_detail::IsVec<char1>> rb_cCvCudaDeviceTypeTraitsDetailIsVecChar1 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<char1>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecChar1").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsVec<char1>>());

  rb_cCvCudaDeviceTypeTraitsDetailIsVecChar1.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsVec<char1>::value);

  Rice::Data_Type<cv::cuda::device::type_traits_detail::IsVec<char2>> rb_cCvCudaDeviceTypeTraitsDetailIsVecChar2 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<char2>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecChar2").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsVec<char2>>());

  rb_cCvCudaDeviceTypeTraitsDetailIsVecChar2.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsVec<char2>::value);

  Rice::Data_Type<cv::cuda::device::type_traits_detail::IsVec<char3>> rb_cCvCudaDeviceTypeTraitsDetailIsVecChar3 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<char3>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecChar3").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsVec<char3>>());

  rb_cCvCudaDeviceTypeTraitsDetailIsVecChar3.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsVec<char3>::value);

  Rice::Data_Type<cv::cuda::device::type_traits_detail::IsVec<char4>> rb_cCvCudaDeviceTypeTraitsDetailIsVecChar4 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<char4>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecChar4").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsVec<char4>>());

  rb_cCvCudaDeviceTypeTraitsDetailIsVecChar4.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsVec<char4>::value);

  Rice::Data_Type<cv::cuda::device::type_traits_detail::IsVec<cv::cuda::device::char8>> rb_cCvCudaDeviceTypeTraitsDetailIsVecChar8 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<cv::cuda::device::char8>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecChar8").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsVec<cv::cuda::device::char8>>());

  rb_cCvCudaDeviceTypeTraitsDetailIsVecChar8.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsVec<cv::cuda::device::char8>::value);

  Rice::Data_Type<cv::cuda::device::type_traits_detail::IsVec<ushort1>> rb_cCvCudaDeviceTypeTraitsDetailIsVecUshort1 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<ushort1>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecUshort1").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsVec<ushort1>>());

  rb_cCvCudaDeviceTypeTraitsDetailIsVecUshort1.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsVec<ushort1>::value);

  Rice::Data_Type<cv::cuda::device::type_traits_detail::IsVec<ushort2>> rb_cCvCudaDeviceTypeTraitsDetailIsVecUshort2 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<ushort2>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecUshort2").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsVec<ushort2>>());

  rb_cCvCudaDeviceTypeTraitsDetailIsVecUshort2.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsVec<ushort2>::value);

  Rice::Data_Type<cv::cuda::device::type_traits_detail::IsVec<ushort3>> rb_cCvCudaDeviceTypeTraitsDetailIsVecUshort3 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<ushort3>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecUshort3").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsVec<ushort3>>());

  rb_cCvCudaDeviceTypeTraitsDetailIsVecUshort3.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsVec<ushort3>::value);

  Rice::Data_Type<cv::cuda::device::type_traits_detail::IsVec<ushort4>> rb_cCvCudaDeviceTypeTraitsDetailIsVecUshort4 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<ushort4>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecUshort4").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsVec<ushort4>>());

  rb_cCvCudaDeviceTypeTraitsDetailIsVecUshort4.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsVec<ushort4>::value);

  Rice::Data_Type<cv::cuda::device::type_traits_detail::IsVec<cv::cuda::device::ushort8>> rb_cCvCudaDeviceTypeTraitsDetailIsVecUshort8 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<cv::cuda::device::ushort8>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecUshort8").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsVec<cv::cuda::device::ushort8>>());

  rb_cCvCudaDeviceTypeTraitsDetailIsVecUshort8.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsVec<cv::cuda::device::ushort8>::value);

  Rice::Data_Type<cv::cuda::device::type_traits_detail::IsVec<short1>> rb_cCvCudaDeviceTypeTraitsDetailIsVecShort1 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<short1>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecShort1").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsVec<short1>>());

  rb_cCvCudaDeviceTypeTraitsDetailIsVecShort1.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsVec<short1>::value);

  Rice::Data_Type<cv::cuda::device::type_traits_detail::IsVec<short2>> rb_cCvCudaDeviceTypeTraitsDetailIsVecShort2 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<short2>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecShort2").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsVec<short2>>());

  rb_cCvCudaDeviceTypeTraitsDetailIsVecShort2.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsVec<short2>::value);

  Rice::Data_Type<cv::cuda::device::type_traits_detail::IsVec<short3>> rb_cCvCudaDeviceTypeTraitsDetailIsVecShort3 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<short3>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecShort3").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsVec<short3>>());

  rb_cCvCudaDeviceTypeTraitsDetailIsVecShort3.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsVec<short3>::value);

  Rice::Data_Type<cv::cuda::device::type_traits_detail::IsVec<short4>> rb_cCvCudaDeviceTypeTraitsDetailIsVecShort4 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<short4>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecShort4").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsVec<short4>>());

  rb_cCvCudaDeviceTypeTraitsDetailIsVecShort4.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsVec<short4>::value);

  Rice::Data_Type<cv::cuda::device::type_traits_detail::IsVec<cv::cuda::device::short8>> rb_cCvCudaDeviceTypeTraitsDetailIsVecShort8 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<cv::cuda::device::short8>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecShort8").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsVec<cv::cuda::device::short8>>());

  rb_cCvCudaDeviceTypeTraitsDetailIsVecShort8.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsVec<cv::cuda::device::short8>::value);

  Rice::Data_Type<cv::cuda::device::type_traits_detail::IsVec<uint1>> rb_cCvCudaDeviceTypeTraitsDetailIsVecUint1 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<uint1>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecUint1").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsVec<uint1>>());

  rb_cCvCudaDeviceTypeTraitsDetailIsVecUint1.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsVec<uint1>::value);

  Rice::Data_Type<cv::cuda::device::type_traits_detail::IsVec<uint2>> rb_cCvCudaDeviceTypeTraitsDetailIsVecUint2 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<uint2>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecUint2").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsVec<uint2>>());

  rb_cCvCudaDeviceTypeTraitsDetailIsVecUint2.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsVec<uint2>::value);

  Rice::Data_Type<cv::cuda::device::type_traits_detail::IsVec<uint3>> rb_cCvCudaDeviceTypeTraitsDetailIsVecUint3 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<uint3>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecUint3").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsVec<uint3>>());

  rb_cCvCudaDeviceTypeTraitsDetailIsVecUint3.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsVec<uint3>::value);

  Rice::Data_Type<cv::cuda::device::type_traits_detail::IsVec<uint4>> rb_cCvCudaDeviceTypeTraitsDetailIsVecUint4 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<uint4>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecUint4").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsVec<uint4>>());

  rb_cCvCudaDeviceTypeTraitsDetailIsVecUint4.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsVec<uint4>::value);

  Rice::Data_Type<cv::cuda::device::type_traits_detail::IsVec<cv::cuda::device::uint8>> rb_cCvCudaDeviceTypeTraitsDetailIsVecUint8 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<cv::cuda::device::uint8>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecUint8").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsVec<cv::cuda::device::uint8>>());

  rb_cCvCudaDeviceTypeTraitsDetailIsVecUint8.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsVec<cv::cuda::device::uint8>::value);

  Rice::Data_Type<cv::cuda::device::type_traits_detail::IsVec<int1>> rb_cCvCudaDeviceTypeTraitsDetailIsVecInt1 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<int1>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecInt1").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsVec<int1>>());

  rb_cCvCudaDeviceTypeTraitsDetailIsVecInt1.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsVec<int1>::value);

  Rice::Data_Type<cv::cuda::device::type_traits_detail::IsVec<int2>> rb_cCvCudaDeviceTypeTraitsDetailIsVecInt2 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<int2>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecInt2").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsVec<int2>>());

  rb_cCvCudaDeviceTypeTraitsDetailIsVecInt2.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsVec<int2>::value);

  Rice::Data_Type<cv::cuda::device::type_traits_detail::IsVec<int3>> rb_cCvCudaDeviceTypeTraitsDetailIsVecInt3 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<int3>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecInt3").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsVec<int3>>());

  rb_cCvCudaDeviceTypeTraitsDetailIsVecInt3.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsVec<int3>::value);

  Rice::Data_Type<cv::cuda::device::type_traits_detail::IsVec<int4>> rb_cCvCudaDeviceTypeTraitsDetailIsVecInt4 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<int4>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecInt4").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsVec<int4>>());

  rb_cCvCudaDeviceTypeTraitsDetailIsVecInt4.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsVec<int4>::value);

  Rice::Data_Type<cv::cuda::device::type_traits_detail::IsVec<cv::cuda::device::int8>> rb_cCvCudaDeviceTypeTraitsDetailIsVecInt8 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<cv::cuda::device::int8>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecInt8").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsVec<cv::cuda::device::int8>>());

  rb_cCvCudaDeviceTypeTraitsDetailIsVecInt8.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsVec<cv::cuda::device::int8>::value);

  Rice::Data_Type<cv::cuda::device::type_traits_detail::IsVec<float1>> rb_cCvCudaDeviceTypeTraitsDetailIsVecFloat1 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<float1>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecFloat1").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsVec<float1>>());

  rb_cCvCudaDeviceTypeTraitsDetailIsVecFloat1.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsVec<float1>::value);

  Rice::Data_Type<cv::cuda::device::type_traits_detail::IsVec<float2>> rb_cCvCudaDeviceTypeTraitsDetailIsVecFloat2 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<float2>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecFloat2").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsVec<float2>>());

  rb_cCvCudaDeviceTypeTraitsDetailIsVecFloat2.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsVec<float2>::value);

  Rice::Data_Type<cv::cuda::device::type_traits_detail::IsVec<float3>> rb_cCvCudaDeviceTypeTraitsDetailIsVecFloat3 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<float3>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecFloat3").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsVec<float3>>());

  rb_cCvCudaDeviceTypeTraitsDetailIsVecFloat3.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsVec<float3>::value);

  Rice::Data_Type<cv::cuda::device::type_traits_detail::IsVec<float4>> rb_cCvCudaDeviceTypeTraitsDetailIsVecFloat4 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<float4>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecFloat4").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsVec<float4>>());

  rb_cCvCudaDeviceTypeTraitsDetailIsVecFloat4.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsVec<float4>::value);

  Rice::Data_Type<cv::cuda::device::type_traits_detail::IsVec<cv::cuda::device::float8>> rb_cCvCudaDeviceTypeTraitsDetailIsVecFloat8 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<cv::cuda::device::float8>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecFloat8").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsVec<cv::cuda::device::float8>>());

  rb_cCvCudaDeviceTypeTraitsDetailIsVecFloat8.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsVec<cv::cuda::device::float8>::value);

  Rice::Data_Type<cv::cuda::device::type_traits_detail::IsVec<double1>> rb_cCvCudaDeviceTypeTraitsDetailIsVecDouble1 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<double1>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecDouble1").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsVec<double1>>());

  rb_cCvCudaDeviceTypeTraitsDetailIsVecDouble1.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsVec<double1>::value);

  Rice::Data_Type<cv::cuda::device::type_traits_detail::IsVec<double2>> rb_cCvCudaDeviceTypeTraitsDetailIsVecDouble2 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<double2>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecDouble2").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsVec<double2>>());

  rb_cCvCudaDeviceTypeTraitsDetailIsVecDouble2.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsVec<double2>::value);

  Rice::Data_Type<cv::cuda::device::type_traits_detail::IsVec<double3>> rb_cCvCudaDeviceTypeTraitsDetailIsVecDouble3 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<double3>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecDouble3").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsVec<double3>>());

  rb_cCvCudaDeviceTypeTraitsDetailIsVecDouble3.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsVec<double3>::value);

  Rice::Data_Type<cv::cuda::device::type_traits_detail::IsVec<double4>> rb_cCvCudaDeviceTypeTraitsDetailIsVecDouble4 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<double4>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecDouble4").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsVec<double4>>());

  rb_cCvCudaDeviceTypeTraitsDetailIsVecDouble4.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsVec<double4>::value);

  Rice::Data_Type<cv::cuda::device::type_traits_detail::IsVec<cv::cuda::device::double8>> rb_cCvCudaDeviceTypeTraitsDetailIsVecDouble8 = define_class_under<cv::cuda::device::type_traits_detail::IsVec<cv::cuda::device::double8>>(rb_mCvCudaDeviceTypeTraitsDetail, "IsVecDouble8").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::IsVec<cv::cuda::device::double8>>());

  rb_cCvCudaDeviceTypeTraitsDetailIsVecDouble8.define_constant("Value", (int)cv::cuda::device::type_traits_detail::IsVec<cv::cuda::device::double8>::value);

  Rice::Data_Type<cv::cuda::device::type_traits_detail::AddParameterType<void>> rb_cCvCudaDeviceTypeTraitsDetailAddParameterTypeVoid = define_class_under<cv::cuda::device::type_traits_detail::AddParameterType<void>>(rb_mCvCudaDeviceTypeTraitsDetail, "AddParameterTypeVoid").
    define_constructor(Constructor<cv::cuda::device::type_traits_detail::AddParameterType<void>>());
}