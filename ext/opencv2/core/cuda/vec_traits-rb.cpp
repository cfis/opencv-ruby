#include <opencv2/core/cuda/vec_traits.hpp>
#include "vec_traits-rb.hpp"

using namespace Rice;

void Init_Core_Cuda_VecTraits()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");

  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");

  Rice::Data_Type<cv::cuda::device::__align__> rb_cCvCudaDeviceAlign = define_class_under<cv::cuda::device::__align__>(rb_mCvCudaDevice, "Align");

  Rice::Data_Type<cv::cuda::device::double8> rb_cCvCudaDeviceDouble8 = define_class_under<cv::cuda::device::double8>(rb_mCvCudaDevice, "Double8").
    define_constructor(Constructor<cv::cuda::device::double8>()).
    define_attr("a0", &cv::cuda::device::double8::a0).
    define_attr("a1", &cv::cuda::device::double8::a1).
    define_attr("a2", &cv::cuda::device::double8::a2).
    define_attr("a3", &cv::cuda::device::double8::a3).
    define_attr("a4", &cv::cuda::device::double8::a4).
    define_attr("a5", &cv::cuda::device::double8::a5).
    define_attr("a6", &cv::cuda::device::double8::a6).
    define_attr("a7", &cv::cuda::device::double8::a7);

  Rice::Data_Type<cv::cuda::device::TypeVec<uchar, 1>> rb_cCvCudaDeviceTypeVecUchar1 = define_class_under<cv::cuda::device::TypeVec<uchar, 1>>(rb_mCvCudaDevice, "TypeVecUchar1").
    define_constructor(Constructor<cv::cuda::device::TypeVec<uchar, 1>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<uchar, 2>> rb_cCvCudaDeviceTypeVecUchar2 = define_class_under<cv::cuda::device::TypeVec<uchar, 2>>(rb_mCvCudaDevice, "TypeVecUchar2").
    define_constructor(Constructor<cv::cuda::device::TypeVec<uchar, 2>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<uchar, 3>> rb_cCvCudaDeviceTypeVecUchar3 = define_class_under<cv::cuda::device::TypeVec<uchar, 3>>(rb_mCvCudaDevice, "TypeVecUchar3").
    define_constructor(Constructor<cv::cuda::device::TypeVec<uchar, 3>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<uchar, 4>> rb_cCvCudaDeviceTypeVecUchar4 = define_class_under<cv::cuda::device::TypeVec<uchar, 4>>(rb_mCvCudaDevice, "TypeVecUchar4").
    define_constructor(Constructor<cv::cuda::device::TypeVec<uchar, 4>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<uchar, 8>> rb_cCvCudaDeviceTypeVecUchar8 = define_class_under<cv::cuda::device::TypeVec<uchar, 8>>(rb_mCvCudaDevice, "TypeVecUchar8").
    define_constructor(Constructor<cv::cuda::device::TypeVec<uchar, 8>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<char, 1>> rb_cCvCudaDeviceTypeVecChar1 = define_class_under<cv::cuda::device::TypeVec<char, 1>>(rb_mCvCudaDevice, "TypeVecChar1").
    define_constructor(Constructor<cv::cuda::device::TypeVec<char, 1>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<char, 2>> rb_cCvCudaDeviceTypeVecChar2 = define_class_under<cv::cuda::device::TypeVec<char, 2>>(rb_mCvCudaDevice, "TypeVecChar2").
    define_constructor(Constructor<cv::cuda::device::TypeVec<char, 2>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<char, 3>> rb_cCvCudaDeviceTypeVecChar3 = define_class_under<cv::cuda::device::TypeVec<char, 3>>(rb_mCvCudaDevice, "TypeVecChar3").
    define_constructor(Constructor<cv::cuda::device::TypeVec<char, 3>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<char, 4>> rb_cCvCudaDeviceTypeVecChar4 = define_class_under<cv::cuda::device::TypeVec<char, 4>>(rb_mCvCudaDevice, "TypeVecChar4").
    define_constructor(Constructor<cv::cuda::device::TypeVec<char, 4>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<char, 8>> rb_cCvCudaDeviceTypeVecChar8 = define_class_under<cv::cuda::device::TypeVec<char, 8>>(rb_mCvCudaDevice, "TypeVecChar8").
    define_constructor(Constructor<cv::cuda::device::TypeVec<char, 8>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<ushort, 1>> rb_cCvCudaDeviceTypeVecUshort1 = define_class_under<cv::cuda::device::TypeVec<ushort, 1>>(rb_mCvCudaDevice, "TypeVecUshort1").
    define_constructor(Constructor<cv::cuda::device::TypeVec<ushort, 1>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<ushort, 2>> rb_cCvCudaDeviceTypeVecUshort2 = define_class_under<cv::cuda::device::TypeVec<ushort, 2>>(rb_mCvCudaDevice, "TypeVecUshort2").
    define_constructor(Constructor<cv::cuda::device::TypeVec<ushort, 2>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<ushort, 3>> rb_cCvCudaDeviceTypeVecUshort3 = define_class_under<cv::cuda::device::TypeVec<ushort, 3>>(rb_mCvCudaDevice, "TypeVecUshort3").
    define_constructor(Constructor<cv::cuda::device::TypeVec<ushort, 3>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<ushort, 4>> rb_cCvCudaDeviceTypeVecUshort4 = define_class_under<cv::cuda::device::TypeVec<ushort, 4>>(rb_mCvCudaDevice, "TypeVecUshort4").
    define_constructor(Constructor<cv::cuda::device::TypeVec<ushort, 4>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<ushort, 8>> rb_cCvCudaDeviceTypeVecUshort8 = define_class_under<cv::cuda::device::TypeVec<ushort, 8>>(rb_mCvCudaDevice, "TypeVecUshort8").
    define_constructor(Constructor<cv::cuda::device::TypeVec<ushort, 8>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<short, 1>> rb_cCvCudaDeviceTypeVecShort1 = define_class_under<cv::cuda::device::TypeVec<short, 1>>(rb_mCvCudaDevice, "TypeVecShort1").
    define_constructor(Constructor<cv::cuda::device::TypeVec<short, 1>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<short, 2>> rb_cCvCudaDeviceTypeVecShort2 = define_class_under<cv::cuda::device::TypeVec<short, 2>>(rb_mCvCudaDevice, "TypeVecShort2").
    define_constructor(Constructor<cv::cuda::device::TypeVec<short, 2>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<short, 3>> rb_cCvCudaDeviceTypeVecShort3 = define_class_under<cv::cuda::device::TypeVec<short, 3>>(rb_mCvCudaDevice, "TypeVecShort3").
    define_constructor(Constructor<cv::cuda::device::TypeVec<short, 3>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<short, 4>> rb_cCvCudaDeviceTypeVecShort4 = define_class_under<cv::cuda::device::TypeVec<short, 4>>(rb_mCvCudaDevice, "TypeVecShort4").
    define_constructor(Constructor<cv::cuda::device::TypeVec<short, 4>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<short, 8>> rb_cCvCudaDeviceTypeVecShort8 = define_class_under<cv::cuda::device::TypeVec<short, 8>>(rb_mCvCudaDevice, "TypeVecShort8").
    define_constructor(Constructor<cv::cuda::device::TypeVec<short, 8>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<int, 1>> rb_cCvCudaDeviceTypeVecInt1 = define_class_under<cv::cuda::device::TypeVec<int, 1>>(rb_mCvCudaDevice, "TypeVecInt1").
    define_constructor(Constructor<cv::cuda::device::TypeVec<int, 1>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<int, 2>> rb_cCvCudaDeviceTypeVecInt2 = define_class_under<cv::cuda::device::TypeVec<int, 2>>(rb_mCvCudaDevice, "TypeVecInt2").
    define_constructor(Constructor<cv::cuda::device::TypeVec<int, 2>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<int, 3>> rb_cCvCudaDeviceTypeVecInt3 = define_class_under<cv::cuda::device::TypeVec<int, 3>>(rb_mCvCudaDevice, "TypeVecInt3").
    define_constructor(Constructor<cv::cuda::device::TypeVec<int, 3>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<int, 4>> rb_cCvCudaDeviceTypeVecInt4 = define_class_under<cv::cuda::device::TypeVec<int, 4>>(rb_mCvCudaDevice, "TypeVecInt4").
    define_constructor(Constructor<cv::cuda::device::TypeVec<int, 4>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<int, 8>> rb_cCvCudaDeviceTypeVecInt8 = define_class_under<cv::cuda::device::TypeVec<int, 8>>(rb_mCvCudaDevice, "TypeVecInt8").
    define_constructor(Constructor<cv::cuda::device::TypeVec<int, 8>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<uint, 1>> rb_cCvCudaDeviceTypeVecUint1 = define_class_under<cv::cuda::device::TypeVec<uint, 1>>(rb_mCvCudaDevice, "TypeVecUint1").
    define_constructor(Constructor<cv::cuda::device::TypeVec<uint, 1>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<uint, 2>> rb_cCvCudaDeviceTypeVecUint2 = define_class_under<cv::cuda::device::TypeVec<uint, 2>>(rb_mCvCudaDevice, "TypeVecUint2").
    define_constructor(Constructor<cv::cuda::device::TypeVec<uint, 2>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<uint, 3>> rb_cCvCudaDeviceTypeVecUint3 = define_class_under<cv::cuda::device::TypeVec<uint, 3>>(rb_mCvCudaDevice, "TypeVecUint3").
    define_constructor(Constructor<cv::cuda::device::TypeVec<uint, 3>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<uint, 4>> rb_cCvCudaDeviceTypeVecUint4 = define_class_under<cv::cuda::device::TypeVec<uint, 4>>(rb_mCvCudaDevice, "TypeVecUint4").
    define_constructor(Constructor<cv::cuda::device::TypeVec<uint, 4>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<uint, 8>> rb_cCvCudaDeviceTypeVecUint8 = define_class_under<cv::cuda::device::TypeVec<uint, 8>>(rb_mCvCudaDevice, "TypeVecUint8").
    define_constructor(Constructor<cv::cuda::device::TypeVec<uint, 8>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<float, 1>> rb_cCvCudaDeviceTypeVecFloat1 = define_class_under<cv::cuda::device::TypeVec<float, 1>>(rb_mCvCudaDevice, "TypeVecFloat1").
    define_constructor(Constructor<cv::cuda::device::TypeVec<float, 1>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<float, 2>> rb_cCvCudaDeviceTypeVecFloat2 = define_class_under<cv::cuda::device::TypeVec<float, 2>>(rb_mCvCudaDevice, "TypeVecFloat2").
    define_constructor(Constructor<cv::cuda::device::TypeVec<float, 2>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<float, 3>> rb_cCvCudaDeviceTypeVecFloat3 = define_class_under<cv::cuda::device::TypeVec<float, 3>>(rb_mCvCudaDevice, "TypeVecFloat3").
    define_constructor(Constructor<cv::cuda::device::TypeVec<float, 3>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<float, 4>> rb_cCvCudaDeviceTypeVecFloat4 = define_class_under<cv::cuda::device::TypeVec<float, 4>>(rb_mCvCudaDevice, "TypeVecFloat4").
    define_constructor(Constructor<cv::cuda::device::TypeVec<float, 4>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<float, 8>> rb_cCvCudaDeviceTypeVecFloat8 = define_class_under<cv::cuda::device::TypeVec<float, 8>>(rb_mCvCudaDevice, "TypeVecFloat8").
    define_constructor(Constructor<cv::cuda::device::TypeVec<float, 8>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<double, 1>> rb_cCvCudaDeviceTypeVecDouble1 = define_class_under<cv::cuda::device::TypeVec<double, 1>>(rb_mCvCudaDevice, "TypeVecDouble1").
    define_constructor(Constructor<cv::cuda::device::TypeVec<double, 1>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<double, 2>> rb_cCvCudaDeviceTypeVecDouble2 = define_class_under<cv::cuda::device::TypeVec<double, 2>>(rb_mCvCudaDevice, "TypeVecDouble2").
    define_constructor(Constructor<cv::cuda::device::TypeVec<double, 2>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<double, 3>> rb_cCvCudaDeviceTypeVecDouble3 = define_class_under<cv::cuda::device::TypeVec<double, 3>>(rb_mCvCudaDevice, "TypeVecDouble3").
    define_constructor(Constructor<cv::cuda::device::TypeVec<double, 3>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<double, 4>> rb_cCvCudaDeviceTypeVecDouble4 = define_class_under<cv::cuda::device::TypeVec<double, 4>>(rb_mCvCudaDevice, "TypeVecDouble4").
    define_constructor(Constructor<cv::cuda::device::TypeVec<double, 4>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<double, 8>> rb_cCvCudaDeviceTypeVecDouble8 = define_class_under<cv::cuda::device::TypeVec<double, 8>>(rb_mCvCudaDevice, "TypeVecDouble8").
    define_constructor(Constructor<cv::cuda::device::TypeVec<double, 8>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<cv::cuda::device::double8, 8>> rb_cCvCudaDeviceTypeVecDouble88 = define_class_under<cv::cuda::device::TypeVec<cv::cuda::device::double8, 8>>(rb_mCvCudaDevice, "TypeVecDouble88").
    define_constructor(Constructor<cv::cuda::device::TypeVec<cv::cuda::device::double8, 8>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<schar, 1>> rb_cCvCudaDeviceTypeVecSchar1 = define_class_under<cv::cuda::device::TypeVec<schar, 1>>(rb_mCvCudaDevice, "TypeVecSchar1").
    define_constructor(Constructor<cv::cuda::device::TypeVec<schar, 1>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<schar, 2>> rb_cCvCudaDeviceTypeVecSchar2 = define_class_under<cv::cuda::device::TypeVec<schar, 2>>(rb_mCvCudaDevice, "TypeVecSchar2").
    define_constructor(Constructor<cv::cuda::device::TypeVec<schar, 2>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<schar, 3>> rb_cCvCudaDeviceTypeVecSchar3 = define_class_under<cv::cuda::device::TypeVec<schar, 3>>(rb_mCvCudaDevice, "TypeVecSchar3").
    define_constructor(Constructor<cv::cuda::device::TypeVec<schar, 3>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<schar, 4>> rb_cCvCudaDeviceTypeVecSchar4 = define_class_under<cv::cuda::device::TypeVec<schar, 4>>(rb_mCvCudaDevice, "TypeVecSchar4").
    define_constructor(Constructor<cv::cuda::device::TypeVec<schar, 4>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<schar, 8>> rb_cCvCudaDeviceTypeVecSchar8 = define_class_under<cv::cuda::device::TypeVec<schar, 8>>(rb_mCvCudaDevice, "TypeVecSchar8").
    define_constructor(Constructor<cv::cuda::device::TypeVec<schar, 8>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<bool, 1>> rb_cCvCudaDeviceTypeVecBool1 = define_class_under<cv::cuda::device::TypeVec<bool, 1>>(rb_mCvCudaDevice, "TypeVecBool1").
    define_constructor(Constructor<cv::cuda::device::TypeVec<bool, 1>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<bool, 2>> rb_cCvCudaDeviceTypeVecBool2 = define_class_under<cv::cuda::device::TypeVec<bool, 2>>(rb_mCvCudaDevice, "TypeVecBool2").
    define_constructor(Constructor<cv::cuda::device::TypeVec<bool, 2>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<bool, 3>> rb_cCvCudaDeviceTypeVecBool3 = define_class_under<cv::cuda::device::TypeVec<bool, 3>>(rb_mCvCudaDevice, "TypeVecBool3").
    define_constructor(Constructor<cv::cuda::device::TypeVec<bool, 3>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<bool, 4>> rb_cCvCudaDeviceTypeVecBool4 = define_class_under<cv::cuda::device::TypeVec<bool, 4>>(rb_mCvCudaDevice, "TypeVecBool4").
    define_constructor(Constructor<cv::cuda::device::TypeVec<bool, 4>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<bool, 8>> rb_cCvCudaDeviceTypeVecBool8 = define_class_under<cv::cuda::device::TypeVec<bool, 8>>(rb_mCvCudaDevice, "TypeVecBool8").
    define_constructor(Constructor<cv::cuda::device::TypeVec<bool, 8>>());

  Rice::Data_Type<cv::cuda::device::VecTraits<uchar>> rb_cCvCudaDeviceVecTraitsUchar = define_class_under<cv::cuda::device::VecTraits<uchar>>(rb_mCvCudaDevice, "VecTraitsUchar").
    define_constructor(Constructor<cv::cuda::device::VecTraits<uchar>>());

  rb_cCvCudaDeviceVecTraitsUchar.define_constant("Cn", (int)cv::cuda::device::VecTraits<uchar>::cn);

  Rice::Data_Type<cv::cuda::device::VecTraits<ushort>> rb_cCvCudaDeviceVecTraitsUshort = define_class_under<cv::cuda::device::VecTraits<ushort>>(rb_mCvCudaDevice, "VecTraitsUshort").
    define_constructor(Constructor<cv::cuda::device::VecTraits<ushort>>());

  rb_cCvCudaDeviceVecTraitsUshort.define_constant("Cn", (int)cv::cuda::device::VecTraits<ushort>::cn);

  Rice::Data_Type<cv::cuda::device::VecTraits<short>> rb_cCvCudaDeviceVecTraitsShort = define_class_under<cv::cuda::device::VecTraits<short>>(rb_mCvCudaDevice, "VecTraitsShort").
    define_constructor(Constructor<cv::cuda::device::VecTraits<short>>());

  rb_cCvCudaDeviceVecTraitsShort.define_constant("Cn", (int)cv::cuda::device::VecTraits<short>::cn);

  Rice::Data_Type<cv::cuda::device::VecTraits<int>> rb_cCvCudaDeviceVecTraitsInt = define_class_under<cv::cuda::device::VecTraits<int>>(rb_mCvCudaDevice, "VecTraitsInt").
    define_constructor(Constructor<cv::cuda::device::VecTraits<int>>());

  rb_cCvCudaDeviceVecTraitsInt.define_constant("Cn", (int)cv::cuda::device::VecTraits<int>::cn);

  Rice::Data_Type<cv::cuda::device::VecTraits<uint>> rb_cCvCudaDeviceVecTraitsUint = define_class_under<cv::cuda::device::VecTraits<uint>>(rb_mCvCudaDevice, "VecTraitsUint").
    define_constructor(Constructor<cv::cuda::device::VecTraits<uint>>());

  rb_cCvCudaDeviceVecTraitsUint.define_constant("Cn", (int)cv::cuda::device::VecTraits<uint>::cn);

  Rice::Data_Type<cv::cuda::device::VecTraits<float>> rb_cCvCudaDeviceVecTraitsFloat = define_class_under<cv::cuda::device::VecTraits<float>>(rb_mCvCudaDevice, "VecTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::VecTraits<float>>());

  rb_cCvCudaDeviceVecTraitsFloat.define_constant("Cn", (int)cv::cuda::device::VecTraits<float>::cn);

  Rice::Data_Type<cv::cuda::device::VecTraits<double>> rb_cCvCudaDeviceVecTraitsDouble = define_class_under<cv::cuda::device::VecTraits<double>>(rb_mCvCudaDevice, "VecTraitsDouble").
    define_constructor(Constructor<cv::cuda::device::VecTraits<double>>());

  rb_cCvCudaDeviceVecTraitsDouble.define_constant("Cn", (int)cv::cuda::device::VecTraits<double>::cn);

  Rice::Data_Type<cv::cuda::device::VecTraits<cv::cuda::device::double8>> rb_cCvCudaDeviceVecTraitsDouble8 = define_class_under<cv::cuda::device::VecTraits<cv::cuda::device::double8>>(rb_mCvCudaDevice, "VecTraitsDouble8").
    define_constructor(Constructor<cv::cuda::device::VecTraits<cv::cuda::device::double8>>());

  rb_cCvCudaDeviceVecTraitsDouble8.define_constant("Cn", (int)cv::cuda::device::VecTraits<cv::cuda::device::double8>::cn);

  Rice::Data_Type<cv::cuda::device::VecTraits<char>> rb_cCvCudaDeviceVecTraitsChar = define_class_under<cv::cuda::device::VecTraits<char>>(rb_mCvCudaDevice, "VecTraitsChar").
    define_constructor(Constructor<cv::cuda::device::VecTraits<char>>());

  rb_cCvCudaDeviceVecTraitsChar.define_constant("Cn", (int)cv::cuda::device::VecTraits<char>::cn);

  Rice::Data_Type<cv::cuda::device::VecTraits<schar>> rb_cCvCudaDeviceVecTraitsSchar = define_class_under<cv::cuda::device::VecTraits<schar>>(rb_mCvCudaDevice, "VecTraitsSchar").
    define_constructor(Constructor<cv::cuda::device::VecTraits<schar>>());

  rb_cCvCudaDeviceVecTraitsSchar.define_constant("Cn", (int)cv::cuda::device::VecTraits<schar>::cn);
}