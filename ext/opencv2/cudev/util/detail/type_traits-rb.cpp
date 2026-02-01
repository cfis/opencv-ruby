#include <opencv2/cudev/util/detail/type_traits.hpp>
#include "type_traits-rb.hpp"

using namespace Rice;

#include "type_traits-rb.ipp"

void Init_Cudev_Util_Detail_TypeTraits()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");

  Module rb_mCvCudevTypeTraitsDetail = define_module_under(rb_mCvCudev, "TypeTraitsDetail");

  Rice::Data_Type<cv::cudev::type_traits_detail::IsSignedIntergral<schar>> rb_cCvCudevTypeTraitsDetailIsSignedIntergralSchar = define_class_under<cv::cudev::type_traits_detail::IsSignedIntergral<schar>>(rb_mCvCudevTypeTraitsDetail, "IsSignedIntergralSchar").
    define_constructor(Constructor<cv::cudev::type_traits_detail::IsSignedIntergral<schar>>());

  rb_cCvCudevTypeTraitsDetailIsSignedIntergralSchar.define_constant("Value", (int)cv::cudev::type_traits_detail::IsSignedIntergral<schar>::value);

  Rice::Data_Type<cv::cudev::type_traits_detail::IsSignedIntergral<short>> rb_cCvCudevTypeTraitsDetailIsSignedIntergralShort = define_class_under<cv::cudev::type_traits_detail::IsSignedIntergral<short>>(rb_mCvCudevTypeTraitsDetail, "IsSignedIntergralShort").
    define_constructor(Constructor<cv::cudev::type_traits_detail::IsSignedIntergral<short>>());

  rb_cCvCudevTypeTraitsDetailIsSignedIntergralShort.define_constant("Value", (int)cv::cudev::type_traits_detail::IsSignedIntergral<short>::value);

  Rice::Data_Type<cv::cudev::type_traits_detail::IsSignedIntergral<int>> rb_cCvCudevTypeTraitsDetailIsSignedIntergralInt = define_class_under<cv::cudev::type_traits_detail::IsSignedIntergral<int>>(rb_mCvCudevTypeTraitsDetail, "IsSignedIntergralInt").
    define_constructor(Constructor<cv::cudev::type_traits_detail::IsSignedIntergral<int>>());

  rb_cCvCudevTypeTraitsDetailIsSignedIntergralInt.define_constant("Value", (int)cv::cudev::type_traits_detail::IsSignedIntergral<int>::value);

  Rice::Data_Type<cv::cudev::type_traits_detail::IsUnsignedIntegral<uchar>> rb_cCvCudevTypeTraitsDetailIsUnsignedIntegralUchar = define_class_under<cv::cudev::type_traits_detail::IsUnsignedIntegral<uchar>>(rb_mCvCudevTypeTraitsDetail, "IsUnsignedIntegralUchar").
    define_constructor(Constructor<cv::cudev::type_traits_detail::IsUnsignedIntegral<uchar>>());

  rb_cCvCudevTypeTraitsDetailIsUnsignedIntegralUchar.define_constant("Value", (int)cv::cudev::type_traits_detail::IsUnsignedIntegral<uchar>::value);

  Rice::Data_Type<cv::cudev::type_traits_detail::IsUnsignedIntegral<ushort>> rb_cCvCudevTypeTraitsDetailIsUnsignedIntegralUshort = define_class_under<cv::cudev::type_traits_detail::IsUnsignedIntegral<ushort>>(rb_mCvCudevTypeTraitsDetail, "IsUnsignedIntegralUshort").
    define_constructor(Constructor<cv::cudev::type_traits_detail::IsUnsignedIntegral<ushort>>());

  rb_cCvCudevTypeTraitsDetailIsUnsignedIntegralUshort.define_constant("Value", (int)cv::cudev::type_traits_detail::IsUnsignedIntegral<ushort>::value);

  Rice::Data_Type<cv::cudev::type_traits_detail::IsUnsignedIntegral<uint>> rb_cCvCudevTypeTraitsDetailIsUnsignedIntegralUint = define_class_under<cv::cudev::type_traits_detail::IsUnsignedIntegral<uint>>(rb_mCvCudevTypeTraitsDetail, "IsUnsignedIntegralUint").
    define_constructor(Constructor<cv::cudev::type_traits_detail::IsUnsignedIntegral<uint>>());

  rb_cCvCudevTypeTraitsDetailIsUnsignedIntegralUint.define_constant("Value", (int)cv::cudev::type_traits_detail::IsUnsignedIntegral<uint>::value);

  Rice::Data_Type<cv::cudev::type_traits_detail::IsIntegral<char>> rb_cCvCudevTypeTraitsDetailIsIntegralChar = define_class_under<cv::cudev::type_traits_detail::IsIntegral<char>>(rb_mCvCudevTypeTraitsDetail, "IsIntegralChar").
    define_constructor(Constructor<cv::cudev::type_traits_detail::IsIntegral<char>>());

  rb_cCvCudevTypeTraitsDetailIsIntegralChar.define_constant("Value", (int)cv::cudev::type_traits_detail::IsIntegral<char>::value);

  Rice::Data_Type<cv::cudev::type_traits_detail::IsIntegral<bool>> rb_cCvCudevTypeTraitsDetailIsIntegralBool = define_class_under<cv::cudev::type_traits_detail::IsIntegral<bool>>(rb_mCvCudevTypeTraitsDetail, "IsIntegralBool").
    define_constructor(Constructor<cv::cudev::type_traits_detail::IsIntegral<bool>>());

  rb_cCvCudevTypeTraitsDetailIsIntegralBool.define_constant("Value", (int)cv::cudev::type_traits_detail::IsIntegral<bool>::value);

  Rice::Data_Type<cv::cudev::type_traits_detail::IsFloat<float>> rb_cCvCudevTypeTraitsDetailIsFloatFloat = define_class_under<cv::cudev::type_traits_detail::IsFloat<float>>(rb_mCvCudevTypeTraitsDetail, "IsFloatFloat").
    define_constructor(Constructor<cv::cudev::type_traits_detail::IsFloat<float>>());

  rb_cCvCudevTypeTraitsDetailIsFloatFloat.define_constant("Value", (int)cv::cudev::type_traits_detail::IsFloat<float>::value);

  Rice::Data_Type<cv::cudev::type_traits_detail::IsFloat<double>> rb_cCvCudevTypeTraitsDetailIsFloatDouble = define_class_under<cv::cudev::type_traits_detail::IsFloat<double>>(rb_mCvCudevTypeTraitsDetail, "IsFloatDouble").
    define_constructor(Constructor<cv::cudev::type_traits_detail::IsFloat<double>>());

  rb_cCvCudevTypeTraitsDetailIsFloatDouble.define_constant("Value", (int)cv::cudev::type_traits_detail::IsFloat<double>::value);

  Rice::Data_Type<cv::cudev::type_traits_detail::IsVec<uchar1>> rb_cCvCudevTypeTraitsDetailIsVecUchar1 = define_class_under<cv::cudev::type_traits_detail::IsVec<uchar1>>(rb_mCvCudevTypeTraitsDetail, "IsVecUchar1").
    define_constructor(Constructor<cv::cudev::type_traits_detail::IsVec<uchar1>>());

  rb_cCvCudevTypeTraitsDetailIsVecUchar1.define_constant("Value", (int)cv::cudev::type_traits_detail::IsVec<uchar1>::value);

  Rice::Data_Type<cv::cudev::type_traits_detail::IsVec<uchar2>> rb_cCvCudevTypeTraitsDetailIsVecUchar2 = define_class_under<cv::cudev::type_traits_detail::IsVec<uchar2>>(rb_mCvCudevTypeTraitsDetail, "IsVecUchar2").
    define_constructor(Constructor<cv::cudev::type_traits_detail::IsVec<uchar2>>());

  rb_cCvCudevTypeTraitsDetailIsVecUchar2.define_constant("Value", (int)cv::cudev::type_traits_detail::IsVec<uchar2>::value);

  Rice::Data_Type<cv::cudev::type_traits_detail::IsVec<uchar3>> rb_cCvCudevTypeTraitsDetailIsVecUchar3 = define_class_under<cv::cudev::type_traits_detail::IsVec<uchar3>>(rb_mCvCudevTypeTraitsDetail, "IsVecUchar3").
    define_constructor(Constructor<cv::cudev::type_traits_detail::IsVec<uchar3>>());

  rb_cCvCudevTypeTraitsDetailIsVecUchar3.define_constant("Value", (int)cv::cudev::type_traits_detail::IsVec<uchar3>::value);

  Rice::Data_Type<cv::cudev::type_traits_detail::IsVec<uchar4>> rb_cCvCudevTypeTraitsDetailIsVecUchar4 = define_class_under<cv::cudev::type_traits_detail::IsVec<uchar4>>(rb_mCvCudevTypeTraitsDetail, "IsVecUchar4").
    define_constructor(Constructor<cv::cudev::type_traits_detail::IsVec<uchar4>>());

  rb_cCvCudevTypeTraitsDetailIsVecUchar4.define_constant("Value", (int)cv::cudev::type_traits_detail::IsVec<uchar4>::value);

  Rice::Data_Type<cv::cudev::type_traits_detail::IsVec<char1>> rb_cCvCudevTypeTraitsDetailIsVecChar1 = define_class_under<cv::cudev::type_traits_detail::IsVec<char1>>(rb_mCvCudevTypeTraitsDetail, "IsVecChar1").
    define_constructor(Constructor<cv::cudev::type_traits_detail::IsVec<char1>>());

  rb_cCvCudevTypeTraitsDetailIsVecChar1.define_constant("Value", (int)cv::cudev::type_traits_detail::IsVec<char1>::value);

  Rice::Data_Type<cv::cudev::type_traits_detail::IsVec<char2>> rb_cCvCudevTypeTraitsDetailIsVecChar2 = define_class_under<cv::cudev::type_traits_detail::IsVec<char2>>(rb_mCvCudevTypeTraitsDetail, "IsVecChar2").
    define_constructor(Constructor<cv::cudev::type_traits_detail::IsVec<char2>>());

  rb_cCvCudevTypeTraitsDetailIsVecChar2.define_constant("Value", (int)cv::cudev::type_traits_detail::IsVec<char2>::value);

  Rice::Data_Type<cv::cudev::type_traits_detail::IsVec<char3>> rb_cCvCudevTypeTraitsDetailIsVecChar3 = define_class_under<cv::cudev::type_traits_detail::IsVec<char3>>(rb_mCvCudevTypeTraitsDetail, "IsVecChar3").
    define_constructor(Constructor<cv::cudev::type_traits_detail::IsVec<char3>>());

  rb_cCvCudevTypeTraitsDetailIsVecChar3.define_constant("Value", (int)cv::cudev::type_traits_detail::IsVec<char3>::value);

  Rice::Data_Type<cv::cudev::type_traits_detail::IsVec<char4>> rb_cCvCudevTypeTraitsDetailIsVecChar4 = define_class_under<cv::cudev::type_traits_detail::IsVec<char4>>(rb_mCvCudevTypeTraitsDetail, "IsVecChar4").
    define_constructor(Constructor<cv::cudev::type_traits_detail::IsVec<char4>>());

  rb_cCvCudevTypeTraitsDetailIsVecChar4.define_constant("Value", (int)cv::cudev::type_traits_detail::IsVec<char4>::value);

  Rice::Data_Type<cv::cudev::type_traits_detail::IsVec<ushort1>> rb_cCvCudevTypeTraitsDetailIsVecUshort1 = define_class_under<cv::cudev::type_traits_detail::IsVec<ushort1>>(rb_mCvCudevTypeTraitsDetail, "IsVecUshort1").
    define_constructor(Constructor<cv::cudev::type_traits_detail::IsVec<ushort1>>());

  rb_cCvCudevTypeTraitsDetailIsVecUshort1.define_constant("Value", (int)cv::cudev::type_traits_detail::IsVec<ushort1>::value);

  Rice::Data_Type<cv::cudev::type_traits_detail::IsVec<ushort2>> rb_cCvCudevTypeTraitsDetailIsVecUshort2 = define_class_under<cv::cudev::type_traits_detail::IsVec<ushort2>>(rb_mCvCudevTypeTraitsDetail, "IsVecUshort2").
    define_constructor(Constructor<cv::cudev::type_traits_detail::IsVec<ushort2>>());

  rb_cCvCudevTypeTraitsDetailIsVecUshort2.define_constant("Value", (int)cv::cudev::type_traits_detail::IsVec<ushort2>::value);

  Rice::Data_Type<cv::cudev::type_traits_detail::IsVec<ushort3>> rb_cCvCudevTypeTraitsDetailIsVecUshort3 = define_class_under<cv::cudev::type_traits_detail::IsVec<ushort3>>(rb_mCvCudevTypeTraitsDetail, "IsVecUshort3").
    define_constructor(Constructor<cv::cudev::type_traits_detail::IsVec<ushort3>>());

  rb_cCvCudevTypeTraitsDetailIsVecUshort3.define_constant("Value", (int)cv::cudev::type_traits_detail::IsVec<ushort3>::value);

  Rice::Data_Type<cv::cudev::type_traits_detail::IsVec<ushort4>> rb_cCvCudevTypeTraitsDetailIsVecUshort4 = define_class_under<cv::cudev::type_traits_detail::IsVec<ushort4>>(rb_mCvCudevTypeTraitsDetail, "IsVecUshort4").
    define_constructor(Constructor<cv::cudev::type_traits_detail::IsVec<ushort4>>());

  rb_cCvCudevTypeTraitsDetailIsVecUshort4.define_constant("Value", (int)cv::cudev::type_traits_detail::IsVec<ushort4>::value);

  Rice::Data_Type<cv::cudev::type_traits_detail::IsVec<short1>> rb_cCvCudevTypeTraitsDetailIsVecShort1 = define_class_under<cv::cudev::type_traits_detail::IsVec<short1>>(rb_mCvCudevTypeTraitsDetail, "IsVecShort1").
    define_constructor(Constructor<cv::cudev::type_traits_detail::IsVec<short1>>());

  rb_cCvCudevTypeTraitsDetailIsVecShort1.define_constant("Value", (int)cv::cudev::type_traits_detail::IsVec<short1>::value);

  Rice::Data_Type<cv::cudev::type_traits_detail::IsVec<short2>> rb_cCvCudevTypeTraitsDetailIsVecShort2 = define_class_under<cv::cudev::type_traits_detail::IsVec<short2>>(rb_mCvCudevTypeTraitsDetail, "IsVecShort2").
    define_constructor(Constructor<cv::cudev::type_traits_detail::IsVec<short2>>());

  rb_cCvCudevTypeTraitsDetailIsVecShort2.define_constant("Value", (int)cv::cudev::type_traits_detail::IsVec<short2>::value);

  Rice::Data_Type<cv::cudev::type_traits_detail::IsVec<short3>> rb_cCvCudevTypeTraitsDetailIsVecShort3 = define_class_under<cv::cudev::type_traits_detail::IsVec<short3>>(rb_mCvCudevTypeTraitsDetail, "IsVecShort3").
    define_constructor(Constructor<cv::cudev::type_traits_detail::IsVec<short3>>());

  rb_cCvCudevTypeTraitsDetailIsVecShort3.define_constant("Value", (int)cv::cudev::type_traits_detail::IsVec<short3>::value);

  Rice::Data_Type<cv::cudev::type_traits_detail::IsVec<short4>> rb_cCvCudevTypeTraitsDetailIsVecShort4 = define_class_under<cv::cudev::type_traits_detail::IsVec<short4>>(rb_mCvCudevTypeTraitsDetail, "IsVecShort4").
    define_constructor(Constructor<cv::cudev::type_traits_detail::IsVec<short4>>());

  rb_cCvCudevTypeTraitsDetailIsVecShort4.define_constant("Value", (int)cv::cudev::type_traits_detail::IsVec<short4>::value);

  Rice::Data_Type<cv::cudev::type_traits_detail::IsVec<uint1>> rb_cCvCudevTypeTraitsDetailIsVecUint1 = define_class_under<cv::cudev::type_traits_detail::IsVec<uint1>>(rb_mCvCudevTypeTraitsDetail, "IsVecUint1").
    define_constructor(Constructor<cv::cudev::type_traits_detail::IsVec<uint1>>());

  rb_cCvCudevTypeTraitsDetailIsVecUint1.define_constant("Value", (int)cv::cudev::type_traits_detail::IsVec<uint1>::value);

  Rice::Data_Type<cv::cudev::type_traits_detail::IsVec<uint2>> rb_cCvCudevTypeTraitsDetailIsVecUint2 = define_class_under<cv::cudev::type_traits_detail::IsVec<uint2>>(rb_mCvCudevTypeTraitsDetail, "IsVecUint2").
    define_constructor(Constructor<cv::cudev::type_traits_detail::IsVec<uint2>>());

  rb_cCvCudevTypeTraitsDetailIsVecUint2.define_constant("Value", (int)cv::cudev::type_traits_detail::IsVec<uint2>::value);

  Rice::Data_Type<cv::cudev::type_traits_detail::IsVec<uint3>> rb_cCvCudevTypeTraitsDetailIsVecUint3 = define_class_under<cv::cudev::type_traits_detail::IsVec<uint3>>(rb_mCvCudevTypeTraitsDetail, "IsVecUint3").
    define_constructor(Constructor<cv::cudev::type_traits_detail::IsVec<uint3>>());

  rb_cCvCudevTypeTraitsDetailIsVecUint3.define_constant("Value", (int)cv::cudev::type_traits_detail::IsVec<uint3>::value);

  Rice::Data_Type<cv::cudev::type_traits_detail::IsVec<uint4>> rb_cCvCudevTypeTraitsDetailIsVecUint4 = define_class_under<cv::cudev::type_traits_detail::IsVec<uint4>>(rb_mCvCudevTypeTraitsDetail, "IsVecUint4").
    define_constructor(Constructor<cv::cudev::type_traits_detail::IsVec<uint4>>());

  rb_cCvCudevTypeTraitsDetailIsVecUint4.define_constant("Value", (int)cv::cudev::type_traits_detail::IsVec<uint4>::value);

  Rice::Data_Type<cv::cudev::type_traits_detail::IsVec<int1>> rb_cCvCudevTypeTraitsDetailIsVecInt1 = define_class_under<cv::cudev::type_traits_detail::IsVec<int1>>(rb_mCvCudevTypeTraitsDetail, "IsVecInt1").
    define_constructor(Constructor<cv::cudev::type_traits_detail::IsVec<int1>>());

  rb_cCvCudevTypeTraitsDetailIsVecInt1.define_constant("Value", (int)cv::cudev::type_traits_detail::IsVec<int1>::value);

  Rice::Data_Type<cv::cudev::type_traits_detail::IsVec<int2>> rb_cCvCudevTypeTraitsDetailIsVecInt2 = define_class_under<cv::cudev::type_traits_detail::IsVec<int2>>(rb_mCvCudevTypeTraitsDetail, "IsVecInt2").
    define_constructor(Constructor<cv::cudev::type_traits_detail::IsVec<int2>>());

  rb_cCvCudevTypeTraitsDetailIsVecInt2.define_constant("Value", (int)cv::cudev::type_traits_detail::IsVec<int2>::value);

  Rice::Data_Type<cv::cudev::type_traits_detail::IsVec<int3>> rb_cCvCudevTypeTraitsDetailIsVecInt3 = define_class_under<cv::cudev::type_traits_detail::IsVec<int3>>(rb_mCvCudevTypeTraitsDetail, "IsVecInt3").
    define_constructor(Constructor<cv::cudev::type_traits_detail::IsVec<int3>>());

  rb_cCvCudevTypeTraitsDetailIsVecInt3.define_constant("Value", (int)cv::cudev::type_traits_detail::IsVec<int3>::value);

  Rice::Data_Type<cv::cudev::type_traits_detail::IsVec<int4>> rb_cCvCudevTypeTraitsDetailIsVecInt4 = define_class_under<cv::cudev::type_traits_detail::IsVec<int4>>(rb_mCvCudevTypeTraitsDetail, "IsVecInt4").
    define_constructor(Constructor<cv::cudev::type_traits_detail::IsVec<int4>>());

  rb_cCvCudevTypeTraitsDetailIsVecInt4.define_constant("Value", (int)cv::cudev::type_traits_detail::IsVec<int4>::value);

  Rice::Data_Type<cv::cudev::type_traits_detail::IsVec<float1>> rb_cCvCudevTypeTraitsDetailIsVecFloat1 = define_class_under<cv::cudev::type_traits_detail::IsVec<float1>>(rb_mCvCudevTypeTraitsDetail, "IsVecFloat1").
    define_constructor(Constructor<cv::cudev::type_traits_detail::IsVec<float1>>());

  rb_cCvCudevTypeTraitsDetailIsVecFloat1.define_constant("Value", (int)cv::cudev::type_traits_detail::IsVec<float1>::value);

  Rice::Data_Type<cv::cudev::type_traits_detail::IsVec<float2>> rb_cCvCudevTypeTraitsDetailIsVecFloat2 = define_class_under<cv::cudev::type_traits_detail::IsVec<float2>>(rb_mCvCudevTypeTraitsDetail, "IsVecFloat2").
    define_constructor(Constructor<cv::cudev::type_traits_detail::IsVec<float2>>());

  rb_cCvCudevTypeTraitsDetailIsVecFloat2.define_constant("Value", (int)cv::cudev::type_traits_detail::IsVec<float2>::value);

  Rice::Data_Type<cv::cudev::type_traits_detail::IsVec<float3>> rb_cCvCudevTypeTraitsDetailIsVecFloat3 = define_class_under<cv::cudev::type_traits_detail::IsVec<float3>>(rb_mCvCudevTypeTraitsDetail, "IsVecFloat3").
    define_constructor(Constructor<cv::cudev::type_traits_detail::IsVec<float3>>());

  rb_cCvCudevTypeTraitsDetailIsVecFloat3.define_constant("Value", (int)cv::cudev::type_traits_detail::IsVec<float3>::value);

  Rice::Data_Type<cv::cudev::type_traits_detail::IsVec<float4>> rb_cCvCudevTypeTraitsDetailIsVecFloat4 = define_class_under<cv::cudev::type_traits_detail::IsVec<float4>>(rb_mCvCudevTypeTraitsDetail, "IsVecFloat4").
    define_constructor(Constructor<cv::cudev::type_traits_detail::IsVec<float4>>());

  rb_cCvCudevTypeTraitsDetailIsVecFloat4.define_constant("Value", (int)cv::cudev::type_traits_detail::IsVec<float4>::value);

  Rice::Data_Type<cv::cudev::type_traits_detail::IsVec<double1>> rb_cCvCudevTypeTraitsDetailIsVecDouble1 = define_class_under<cv::cudev::type_traits_detail::IsVec<double1>>(rb_mCvCudevTypeTraitsDetail, "IsVecDouble1").
    define_constructor(Constructor<cv::cudev::type_traits_detail::IsVec<double1>>());

  rb_cCvCudevTypeTraitsDetailIsVecDouble1.define_constant("Value", (int)cv::cudev::type_traits_detail::IsVec<double1>::value);

  Rice::Data_Type<cv::cudev::type_traits_detail::IsVec<double2>> rb_cCvCudevTypeTraitsDetailIsVecDouble2 = define_class_under<cv::cudev::type_traits_detail::IsVec<double2>>(rb_mCvCudevTypeTraitsDetail, "IsVecDouble2").
    define_constructor(Constructor<cv::cudev::type_traits_detail::IsVec<double2>>());

  rb_cCvCudevTypeTraitsDetailIsVecDouble2.define_constant("Value", (int)cv::cudev::type_traits_detail::IsVec<double2>::value);

  Rice::Data_Type<cv::cudev::type_traits_detail::IsVec<double3>> rb_cCvCudevTypeTraitsDetailIsVecDouble3 = define_class_under<cv::cudev::type_traits_detail::IsVec<double3>>(rb_mCvCudevTypeTraitsDetail, "IsVecDouble3").
    define_constructor(Constructor<cv::cudev::type_traits_detail::IsVec<double3>>());

  rb_cCvCudevTypeTraitsDetailIsVecDouble3.define_constant("Value", (int)cv::cudev::type_traits_detail::IsVec<double3>::value);

  Rice::Data_Type<cv::cudev::type_traits_detail::IsVec<double4>> rb_cCvCudevTypeTraitsDetailIsVecDouble4 = define_class_under<cv::cudev::type_traits_detail::IsVec<double4>>(rb_mCvCudevTypeTraitsDetail, "IsVecDouble4").
    define_constructor(Constructor<cv::cudev::type_traits_detail::IsVec<double4>>());

  rb_cCvCudevTypeTraitsDetailIsVecDouble4.define_constant("Value", (int)cv::cudev::type_traits_detail::IsVec<double4>::value);

  Rice::Data_Type<cv::cudev::type_traits_detail::AddParameterType<void>> rb_cCvCudevTypeTraitsDetailAddParameterTypeVoid = define_class_under<cv::cudev::type_traits_detail::AddParameterType<void>>(rb_mCvCudevTypeTraitsDetail, "AddParameterTypeVoid").
    define_constructor(Constructor<cv::cudev::type_traits_detail::AddParameterType<void>>());

  Rice::Data_Type<cv::cudev::type_traits_detail::LargerDepth<float, float>> rb_cCvCudevTypeTraitsDetailLargerDepthFloatFloat = define_class_under<cv::cudev::type_traits_detail::LargerDepth<float, float>>(rb_mCvCudevTypeTraitsDetail, "LargerDepthFloatFloat").
    define_constructor(Constructor<cv::cudev::type_traits_detail::LargerDepth<float, float>>());

  Rice::Data_Type<cv::cudev::type_traits_detail::LargerDepth<float, double>> rb_cCvCudevTypeTraitsDetailLargerDepthFloatDouble = define_class_under<cv::cudev::type_traits_detail::LargerDepth<float, double>>(rb_mCvCudevTypeTraitsDetail, "LargerDepthFloatDouble").
    define_constructor(Constructor<cv::cudev::type_traits_detail::LargerDepth<float, double>>());

  Rice::Data_Type<cv::cudev::type_traits_detail::LargerDepth<double, float>> rb_cCvCudevTypeTraitsDetailLargerDepthDoubleFloat = define_class_under<cv::cudev::type_traits_detail::LargerDepth<double, float>>(rb_mCvCudevTypeTraitsDetail, "LargerDepthDoubleFloat").
    define_constructor(Constructor<cv::cudev::type_traits_detail::LargerDepth<double, float>>());

  Rice::Data_Type<cv::cudev::type_traits_detail::LargerDepth<double, double>> rb_cCvCudevTypeTraitsDetailLargerDepthDoubleDouble = define_class_under<cv::cudev::type_traits_detail::LargerDepth<double, double>>(rb_mCvCudevTypeTraitsDetail, "LargerDepthDoubleDouble").
    define_constructor(Constructor<cv::cudev::type_traits_detail::LargerDepth<double, double>>());
}