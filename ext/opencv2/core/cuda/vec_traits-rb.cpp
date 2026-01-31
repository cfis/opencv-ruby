#include <opencv2/core/cuda/vec_traits.hpp>
#include "vec_traits-rb.hpp"

using namespace Rice;

void Init_Core_Cuda_VecTraits()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");

  Module rb_mCvCudaDevice = define_module_under(rb_mCvCuda, "Device");

  Rice::Data_Type<cv::cuda::device::uchar8> rb_cCvCudaDeviceUchar8 = define_class_under<cv::cuda::device::uchar8>(rb_mCvCudaDevice, "Uchar8").
    define_constructor(Constructor<cv::cuda::device::uchar8>()).
    define_attr("a0", &cv::cuda::device::uchar8::a0).
    define_attr("a1", &cv::cuda::device::uchar8::a1).
    define_attr("a2", &cv::cuda::device::uchar8::a2).
    define_attr("a3", &cv::cuda::device::uchar8::a3).
    define_attr("a4", &cv::cuda::device::uchar8::a4).
    define_attr("a5", &cv::cuda::device::uchar8::a5).
    define_attr("a6", &cv::cuda::device::uchar8::a6).
    define_attr("a7", &cv::cuda::device::uchar8::a7);

  rb_mCvCudaDevice.define_module_function<cv::cuda::device::uchar8(*)(uchar, uchar, uchar, uchar, uchar, uchar, uchar, uchar)>("make_uchar8", &cv::cuda::device::make_uchar8,
    Arg("a0"), Arg("a1"), Arg("a2"), Arg("a3"), Arg("a4"), Arg("a5"), Arg("a6"), Arg("a7"));

  Rice::Data_Type<cv::cuda::device::char8> rb_cCvCudaDeviceChar8 = define_class_under<cv::cuda::device::char8>(rb_mCvCudaDevice, "Char8").
    define_constructor(Constructor<cv::cuda::device::char8>()).
    define_attr("a0", &cv::cuda::device::char8::a0).
    define_attr("a1", &cv::cuda::device::char8::a1).
    define_attr("a2", &cv::cuda::device::char8::a2).
    define_attr("a3", &cv::cuda::device::char8::a3).
    define_attr("a4", &cv::cuda::device::char8::a4).
    define_attr("a5", &cv::cuda::device::char8::a5).
    define_attr("a6", &cv::cuda::device::char8::a6).
    define_attr("a7", &cv::cuda::device::char8::a7);

  rb_mCvCudaDevice.define_module_function<cv::cuda::device::char8(*)(schar, schar, schar, schar, schar, schar, schar, schar)>("make_char8", &cv::cuda::device::make_char8,
    Arg("a0"), Arg("a1"), Arg("a2"), Arg("a3"), Arg("a4"), Arg("a5"), Arg("a6"), Arg("a7"));

  Rice::Data_Type<cv::cuda::device::ushort8> rb_cCvCudaDeviceUshort8 = define_class_under<cv::cuda::device::ushort8>(rb_mCvCudaDevice, "Ushort8").
    define_constructor(Constructor<cv::cuda::device::ushort8>()).
    define_attr("a0", &cv::cuda::device::ushort8::a0).
    define_attr("a1", &cv::cuda::device::ushort8::a1).
    define_attr("a2", &cv::cuda::device::ushort8::a2).
    define_attr("a3", &cv::cuda::device::ushort8::a3).
    define_attr("a4", &cv::cuda::device::ushort8::a4).
    define_attr("a5", &cv::cuda::device::ushort8::a5).
    define_attr("a6", &cv::cuda::device::ushort8::a6).
    define_attr("a7", &cv::cuda::device::ushort8::a7);

  rb_mCvCudaDevice.define_module_function<cv::cuda::device::ushort8(*)(ushort, ushort, ushort, ushort, ushort, ushort, ushort, ushort)>("make_ushort8", &cv::cuda::device::make_ushort8,
    Arg("a0"), Arg("a1"), Arg("a2"), Arg("a3"), Arg("a4"), Arg("a5"), Arg("a6"), Arg("a7"));

  Rice::Data_Type<cv::cuda::device::short8> rb_cCvCudaDeviceShort8 = define_class_under<cv::cuda::device::short8>(rb_mCvCudaDevice, "Short8").
    define_constructor(Constructor<cv::cuda::device::short8>()).
    define_attr("a0", &cv::cuda::device::short8::a0).
    define_attr("a1", &cv::cuda::device::short8::a1).
    define_attr("a2", &cv::cuda::device::short8::a2).
    define_attr("a3", &cv::cuda::device::short8::a3).
    define_attr("a4", &cv::cuda::device::short8::a4).
    define_attr("a5", &cv::cuda::device::short8::a5).
    define_attr("a6", &cv::cuda::device::short8::a6).
    define_attr("a7", &cv::cuda::device::short8::a7);

  rb_mCvCudaDevice.define_module_function<cv::cuda::device::short8(*)(short, short, short, short, short, short, short, short)>("make_short8", &cv::cuda::device::make_short8,
    Arg("a0"), Arg("a1"), Arg("a2"), Arg("a3"), Arg("a4"), Arg("a5"), Arg("a6"), Arg("a7"));

  Rice::Data_Type<cv::cuda::device::uint8> rb_cCvCudaDeviceUint8 = define_class_under<cv::cuda::device::uint8>(rb_mCvCudaDevice, "Uint8").
    define_constructor(Constructor<cv::cuda::device::uint8>()).
    define_attr("a0", &cv::cuda::device::uint8::a0).
    define_attr("a1", &cv::cuda::device::uint8::a1).
    define_attr("a2", &cv::cuda::device::uint8::a2).
    define_attr("a3", &cv::cuda::device::uint8::a3).
    define_attr("a4", &cv::cuda::device::uint8::a4).
    define_attr("a5", &cv::cuda::device::uint8::a5).
    define_attr("a6", &cv::cuda::device::uint8::a6).
    define_attr("a7", &cv::cuda::device::uint8::a7);

  rb_mCvCudaDevice.define_module_function<cv::cuda::device::uint8(*)(uint, uint, uint, uint, uint, uint, uint, uint)>("make_uint8", &cv::cuda::device::make_uint8,
    Arg("a0"), Arg("a1"), Arg("a2"), Arg("a3"), Arg("a4"), Arg("a5"), Arg("a6"), Arg("a7"));

  Rice::Data_Type<cv::cuda::device::int8> rb_cCvCudaDeviceInt8 = define_class_under<cv::cuda::device::int8>(rb_mCvCudaDevice, "Int8").
    define_constructor(Constructor<cv::cuda::device::int8>()).
    define_attr("a0", &cv::cuda::device::int8::a0).
    define_attr("a1", &cv::cuda::device::int8::a1).
    define_attr("a2", &cv::cuda::device::int8::a2).
    define_attr("a3", &cv::cuda::device::int8::a3).
    define_attr("a4", &cv::cuda::device::int8::a4).
    define_attr("a5", &cv::cuda::device::int8::a5).
    define_attr("a6", &cv::cuda::device::int8::a6).
    define_attr("a7", &cv::cuda::device::int8::a7);

  rb_mCvCudaDevice.define_module_function<cv::cuda::device::int8(*)(int, int, int, int, int, int, int, int)>("make_int8", &cv::cuda::device::make_int8,
    Arg("a0"), Arg("a1"), Arg("a2"), Arg("a3"), Arg("a4"), Arg("a5"), Arg("a6"), Arg("a7"));

  Rice::Data_Type<cv::cuda::device::float8> rb_cCvCudaDeviceFloat8 = define_class_under<cv::cuda::device::float8>(rb_mCvCudaDevice, "Float8").
    define_constructor(Constructor<cv::cuda::device::float8>()).
    define_attr("a0", &cv::cuda::device::float8::a0).
    define_attr("a1", &cv::cuda::device::float8::a1).
    define_attr("a2", &cv::cuda::device::float8::a2).
    define_attr("a3", &cv::cuda::device::float8::a3).
    define_attr("a4", &cv::cuda::device::float8::a4).
    define_attr("a5", &cv::cuda::device::float8::a5).
    define_attr("a6", &cv::cuda::device::float8::a6).
    define_attr("a7", &cv::cuda::device::float8::a7);

  rb_mCvCudaDevice.define_module_function<cv::cuda::device::float8(*)(float, float, float, float, float, float, float, float)>("make_float8", &cv::cuda::device::make_float8,
    Arg("a0"), Arg("a1"), Arg("a2"), Arg("a3"), Arg("a4"), Arg("a5"), Arg("a6"), Arg("a7"));

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

  rb_mCvCudaDevice.define_module_function<cv::cuda::device::double8(*)(double, double, double, double, double, double, double, double)>("make_double8", &cv::cuda::device::make_double8,
    Arg("a0"), Arg("a1"), Arg("a2"), Arg("a3"), Arg("a4"), Arg("a5"), Arg("a6"), Arg("a7"));

  Rice::Data_Type<cv::cuda::device::TypeVec<uchar, 1>> rb_cCvCudaDeviceTypeVecUchar1 = define_class_under<cv::cuda::device::TypeVec<uchar, 1>>(rb_mCvCudaDevice, "TypeVecUchar1").
    define_constructor(Constructor<cv::cuda::device::TypeVec<uchar, 1>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<uchar1, 1>> rb_cCvCudaDeviceTypeVecUchar11 = define_class_under<cv::cuda::device::TypeVec<uchar1, 1>>(rb_mCvCudaDevice, "TypeVecUchar11").
    define_constructor(Constructor<cv::cuda::device::TypeVec<uchar1, 1>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<uchar, 2>> rb_cCvCudaDeviceTypeVecUchar2 = define_class_under<cv::cuda::device::TypeVec<uchar, 2>>(rb_mCvCudaDevice, "TypeVecUchar2").
    define_constructor(Constructor<cv::cuda::device::TypeVec<uchar, 2>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<uchar2, 2>> rb_cCvCudaDeviceTypeVecUchar22 = define_class_under<cv::cuda::device::TypeVec<uchar2, 2>>(rb_mCvCudaDevice, "TypeVecUchar22").
    define_constructor(Constructor<cv::cuda::device::TypeVec<uchar2, 2>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<uchar, 3>> rb_cCvCudaDeviceTypeVecUchar3 = define_class_under<cv::cuda::device::TypeVec<uchar, 3>>(rb_mCvCudaDevice, "TypeVecUchar3").
    define_constructor(Constructor<cv::cuda::device::TypeVec<uchar, 3>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<uchar3, 3>> rb_cCvCudaDeviceTypeVecUchar33 = define_class_under<cv::cuda::device::TypeVec<uchar3, 3>>(rb_mCvCudaDevice, "TypeVecUchar33").
    define_constructor(Constructor<cv::cuda::device::TypeVec<uchar3, 3>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<uchar, 4>> rb_cCvCudaDeviceTypeVecUchar4 = define_class_under<cv::cuda::device::TypeVec<uchar, 4>>(rb_mCvCudaDevice, "TypeVecUchar4").
    define_constructor(Constructor<cv::cuda::device::TypeVec<uchar, 4>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<uchar4, 4>> rb_cCvCudaDeviceTypeVecUchar44 = define_class_under<cv::cuda::device::TypeVec<uchar4, 4>>(rb_mCvCudaDevice, "TypeVecUchar44").
    define_constructor(Constructor<cv::cuda::device::TypeVec<uchar4, 4>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<uchar, 8>> rb_cCvCudaDeviceTypeVecUchar8 = define_class_under<cv::cuda::device::TypeVec<uchar, 8>>(rb_mCvCudaDevice, "TypeVecUchar8").
    define_constructor(Constructor<cv::cuda::device::TypeVec<uchar, 8>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<cv::cuda::device::uchar8, 8>> rb_cCvCudaDeviceTypeVecUchar88 = define_class_under<cv::cuda::device::TypeVec<cv::cuda::device::uchar8, 8>>(rb_mCvCudaDevice, "TypeVecUchar88").
    define_constructor(Constructor<cv::cuda::device::TypeVec<cv::cuda::device::uchar8, 8>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<char, 1>> rb_cCvCudaDeviceTypeVecChar1 = define_class_under<cv::cuda::device::TypeVec<char, 1>>(rb_mCvCudaDevice, "TypeVecChar1").
    define_constructor(Constructor<cv::cuda::device::TypeVec<char, 1>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<char1, 1>> rb_cCvCudaDeviceTypeVecChar11 = define_class_under<cv::cuda::device::TypeVec<char1, 1>>(rb_mCvCudaDevice, "TypeVecChar11").
    define_constructor(Constructor<cv::cuda::device::TypeVec<char1, 1>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<char, 2>> rb_cCvCudaDeviceTypeVecChar2 = define_class_under<cv::cuda::device::TypeVec<char, 2>>(rb_mCvCudaDevice, "TypeVecChar2").
    define_constructor(Constructor<cv::cuda::device::TypeVec<char, 2>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<char2, 2>> rb_cCvCudaDeviceTypeVecChar22 = define_class_under<cv::cuda::device::TypeVec<char2, 2>>(rb_mCvCudaDevice, "TypeVecChar22").
    define_constructor(Constructor<cv::cuda::device::TypeVec<char2, 2>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<char, 3>> rb_cCvCudaDeviceTypeVecChar3 = define_class_under<cv::cuda::device::TypeVec<char, 3>>(rb_mCvCudaDevice, "TypeVecChar3").
    define_constructor(Constructor<cv::cuda::device::TypeVec<char, 3>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<char3, 3>> rb_cCvCudaDeviceTypeVecChar33 = define_class_under<cv::cuda::device::TypeVec<char3, 3>>(rb_mCvCudaDevice, "TypeVecChar33").
    define_constructor(Constructor<cv::cuda::device::TypeVec<char3, 3>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<char, 4>> rb_cCvCudaDeviceTypeVecChar4 = define_class_under<cv::cuda::device::TypeVec<char, 4>>(rb_mCvCudaDevice, "TypeVecChar4").
    define_constructor(Constructor<cv::cuda::device::TypeVec<char, 4>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<char4, 4>> rb_cCvCudaDeviceTypeVecChar44 = define_class_under<cv::cuda::device::TypeVec<char4, 4>>(rb_mCvCudaDevice, "TypeVecChar44").
    define_constructor(Constructor<cv::cuda::device::TypeVec<char4, 4>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<char, 8>> rb_cCvCudaDeviceTypeVecChar8 = define_class_under<cv::cuda::device::TypeVec<char, 8>>(rb_mCvCudaDevice, "TypeVecChar8").
    define_constructor(Constructor<cv::cuda::device::TypeVec<char, 8>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<cv::cuda::device::char8, 8>> rb_cCvCudaDeviceTypeVecChar88 = define_class_under<cv::cuda::device::TypeVec<cv::cuda::device::char8, 8>>(rb_mCvCudaDevice, "TypeVecChar88").
    define_constructor(Constructor<cv::cuda::device::TypeVec<cv::cuda::device::char8, 8>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<ushort, 1>> rb_cCvCudaDeviceTypeVecUshort1 = define_class_under<cv::cuda::device::TypeVec<ushort, 1>>(rb_mCvCudaDevice, "TypeVecUshort1").
    define_constructor(Constructor<cv::cuda::device::TypeVec<ushort, 1>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<ushort1, 1>> rb_cCvCudaDeviceTypeVecUshort11 = define_class_under<cv::cuda::device::TypeVec<ushort1, 1>>(rb_mCvCudaDevice, "TypeVecUshort11").
    define_constructor(Constructor<cv::cuda::device::TypeVec<ushort1, 1>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<ushort, 2>> rb_cCvCudaDeviceTypeVecUshort2 = define_class_under<cv::cuda::device::TypeVec<ushort, 2>>(rb_mCvCudaDevice, "TypeVecUshort2").
    define_constructor(Constructor<cv::cuda::device::TypeVec<ushort, 2>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<ushort2, 2>> rb_cCvCudaDeviceTypeVecUshort22 = define_class_under<cv::cuda::device::TypeVec<ushort2, 2>>(rb_mCvCudaDevice, "TypeVecUshort22").
    define_constructor(Constructor<cv::cuda::device::TypeVec<ushort2, 2>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<ushort, 3>> rb_cCvCudaDeviceTypeVecUshort3 = define_class_under<cv::cuda::device::TypeVec<ushort, 3>>(rb_mCvCudaDevice, "TypeVecUshort3").
    define_constructor(Constructor<cv::cuda::device::TypeVec<ushort, 3>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<ushort3, 3>> rb_cCvCudaDeviceTypeVecUshort33 = define_class_under<cv::cuda::device::TypeVec<ushort3, 3>>(rb_mCvCudaDevice, "TypeVecUshort33").
    define_constructor(Constructor<cv::cuda::device::TypeVec<ushort3, 3>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<ushort, 4>> rb_cCvCudaDeviceTypeVecUshort4 = define_class_under<cv::cuda::device::TypeVec<ushort, 4>>(rb_mCvCudaDevice, "TypeVecUshort4").
    define_constructor(Constructor<cv::cuda::device::TypeVec<ushort, 4>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<ushort4, 4>> rb_cCvCudaDeviceTypeVecUshort44 = define_class_under<cv::cuda::device::TypeVec<ushort4, 4>>(rb_mCvCudaDevice, "TypeVecUshort44").
    define_constructor(Constructor<cv::cuda::device::TypeVec<ushort4, 4>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<ushort, 8>> rb_cCvCudaDeviceTypeVecUshort8 = define_class_under<cv::cuda::device::TypeVec<ushort, 8>>(rb_mCvCudaDevice, "TypeVecUshort8").
    define_constructor(Constructor<cv::cuda::device::TypeVec<ushort, 8>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<cv::cuda::device::ushort8, 8>> rb_cCvCudaDeviceTypeVecUshort88 = define_class_under<cv::cuda::device::TypeVec<cv::cuda::device::ushort8, 8>>(rb_mCvCudaDevice, "TypeVecUshort88").
    define_constructor(Constructor<cv::cuda::device::TypeVec<cv::cuda::device::ushort8, 8>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<short, 1>> rb_cCvCudaDeviceTypeVecShort1 = define_class_under<cv::cuda::device::TypeVec<short, 1>>(rb_mCvCudaDevice, "TypeVecShort1").
    define_constructor(Constructor<cv::cuda::device::TypeVec<short, 1>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<short1, 1>> rb_cCvCudaDeviceTypeVecShort11 = define_class_under<cv::cuda::device::TypeVec<short1, 1>>(rb_mCvCudaDevice, "TypeVecShort11").
    define_constructor(Constructor<cv::cuda::device::TypeVec<short1, 1>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<short, 2>> rb_cCvCudaDeviceTypeVecShort2 = define_class_under<cv::cuda::device::TypeVec<short, 2>>(rb_mCvCudaDevice, "TypeVecShort2").
    define_constructor(Constructor<cv::cuda::device::TypeVec<short, 2>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<short2, 2>> rb_cCvCudaDeviceTypeVecShort22 = define_class_under<cv::cuda::device::TypeVec<short2, 2>>(rb_mCvCudaDevice, "TypeVecShort22").
    define_constructor(Constructor<cv::cuda::device::TypeVec<short2, 2>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<short, 3>> rb_cCvCudaDeviceTypeVecShort3 = define_class_under<cv::cuda::device::TypeVec<short, 3>>(rb_mCvCudaDevice, "TypeVecShort3").
    define_constructor(Constructor<cv::cuda::device::TypeVec<short, 3>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<short3, 3>> rb_cCvCudaDeviceTypeVecShort33 = define_class_under<cv::cuda::device::TypeVec<short3, 3>>(rb_mCvCudaDevice, "TypeVecShort33").
    define_constructor(Constructor<cv::cuda::device::TypeVec<short3, 3>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<short, 4>> rb_cCvCudaDeviceTypeVecShort4 = define_class_under<cv::cuda::device::TypeVec<short, 4>>(rb_mCvCudaDevice, "TypeVecShort4").
    define_constructor(Constructor<cv::cuda::device::TypeVec<short, 4>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<short4, 4>> rb_cCvCudaDeviceTypeVecShort44 = define_class_under<cv::cuda::device::TypeVec<short4, 4>>(rb_mCvCudaDevice, "TypeVecShort44").
    define_constructor(Constructor<cv::cuda::device::TypeVec<short4, 4>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<short, 8>> rb_cCvCudaDeviceTypeVecShort8 = define_class_under<cv::cuda::device::TypeVec<short, 8>>(rb_mCvCudaDevice, "TypeVecShort8").
    define_constructor(Constructor<cv::cuda::device::TypeVec<short, 8>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<cv::cuda::device::short8, 8>> rb_cCvCudaDeviceTypeVecShort88 = define_class_under<cv::cuda::device::TypeVec<cv::cuda::device::short8, 8>>(rb_mCvCudaDevice, "TypeVecShort88").
    define_constructor(Constructor<cv::cuda::device::TypeVec<cv::cuda::device::short8, 8>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<int, 1>> rb_cCvCudaDeviceTypeVecInt1 = define_class_under<cv::cuda::device::TypeVec<int, 1>>(rb_mCvCudaDevice, "TypeVecInt1").
    define_constructor(Constructor<cv::cuda::device::TypeVec<int, 1>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<int1, 1>> rb_cCvCudaDeviceTypeVecInt11 = define_class_under<cv::cuda::device::TypeVec<int1, 1>>(rb_mCvCudaDevice, "TypeVecInt11").
    define_constructor(Constructor<cv::cuda::device::TypeVec<int1, 1>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<int, 2>> rb_cCvCudaDeviceTypeVecInt2 = define_class_under<cv::cuda::device::TypeVec<int, 2>>(rb_mCvCudaDevice, "TypeVecInt2").
    define_constructor(Constructor<cv::cuda::device::TypeVec<int, 2>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<int2, 2>> rb_cCvCudaDeviceTypeVecInt22 = define_class_under<cv::cuda::device::TypeVec<int2, 2>>(rb_mCvCudaDevice, "TypeVecInt22").
    define_constructor(Constructor<cv::cuda::device::TypeVec<int2, 2>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<int, 3>> rb_cCvCudaDeviceTypeVecInt3 = define_class_under<cv::cuda::device::TypeVec<int, 3>>(rb_mCvCudaDevice, "TypeVecInt3").
    define_constructor(Constructor<cv::cuda::device::TypeVec<int, 3>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<int3, 3>> rb_cCvCudaDeviceTypeVecInt33 = define_class_under<cv::cuda::device::TypeVec<int3, 3>>(rb_mCvCudaDevice, "TypeVecInt33").
    define_constructor(Constructor<cv::cuda::device::TypeVec<int3, 3>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<int, 4>> rb_cCvCudaDeviceTypeVecInt4 = define_class_under<cv::cuda::device::TypeVec<int, 4>>(rb_mCvCudaDevice, "TypeVecInt4").
    define_constructor(Constructor<cv::cuda::device::TypeVec<int, 4>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<int4, 4>> rb_cCvCudaDeviceTypeVecInt44 = define_class_under<cv::cuda::device::TypeVec<int4, 4>>(rb_mCvCudaDevice, "TypeVecInt44").
    define_constructor(Constructor<cv::cuda::device::TypeVec<int4, 4>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<int, 8>> rb_cCvCudaDeviceTypeVecInt8 = define_class_under<cv::cuda::device::TypeVec<int, 8>>(rb_mCvCudaDevice, "TypeVecInt8").
    define_constructor(Constructor<cv::cuda::device::TypeVec<int, 8>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<cv::cuda::device::int8, 8>> rb_cCvCudaDeviceTypeVecInt88 = define_class_under<cv::cuda::device::TypeVec<cv::cuda::device::int8, 8>>(rb_mCvCudaDevice, "TypeVecInt88").
    define_constructor(Constructor<cv::cuda::device::TypeVec<cv::cuda::device::int8, 8>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<uint, 1>> rb_cCvCudaDeviceTypeVecUint1 = define_class_under<cv::cuda::device::TypeVec<uint, 1>>(rb_mCvCudaDevice, "TypeVecUint1").
    define_constructor(Constructor<cv::cuda::device::TypeVec<uint, 1>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<uint1, 1>> rb_cCvCudaDeviceTypeVecUint11 = define_class_under<cv::cuda::device::TypeVec<uint1, 1>>(rb_mCvCudaDevice, "TypeVecUint11").
    define_constructor(Constructor<cv::cuda::device::TypeVec<uint1, 1>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<uint, 2>> rb_cCvCudaDeviceTypeVecUint2 = define_class_under<cv::cuda::device::TypeVec<uint, 2>>(rb_mCvCudaDevice, "TypeVecUint2").
    define_constructor(Constructor<cv::cuda::device::TypeVec<uint, 2>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<uint2, 2>> rb_cCvCudaDeviceTypeVecUint22 = define_class_under<cv::cuda::device::TypeVec<uint2, 2>>(rb_mCvCudaDevice, "TypeVecUint22").
    define_constructor(Constructor<cv::cuda::device::TypeVec<uint2, 2>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<uint, 3>> rb_cCvCudaDeviceTypeVecUint3 = define_class_under<cv::cuda::device::TypeVec<uint, 3>>(rb_mCvCudaDevice, "TypeVecUint3").
    define_constructor(Constructor<cv::cuda::device::TypeVec<uint, 3>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<uint3, 3>> rb_cCvCudaDeviceTypeVecUint33 = define_class_under<cv::cuda::device::TypeVec<uint3, 3>>(rb_mCvCudaDevice, "TypeVecUint33").
    define_constructor(Constructor<cv::cuda::device::TypeVec<uint3, 3>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<uint, 4>> rb_cCvCudaDeviceTypeVecUint4 = define_class_under<cv::cuda::device::TypeVec<uint, 4>>(rb_mCvCudaDevice, "TypeVecUint4").
    define_constructor(Constructor<cv::cuda::device::TypeVec<uint, 4>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<uint4, 4>> rb_cCvCudaDeviceTypeVecUint44 = define_class_under<cv::cuda::device::TypeVec<uint4, 4>>(rb_mCvCudaDevice, "TypeVecUint44").
    define_constructor(Constructor<cv::cuda::device::TypeVec<uint4, 4>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<uint, 8>> rb_cCvCudaDeviceTypeVecUint8 = define_class_under<cv::cuda::device::TypeVec<uint, 8>>(rb_mCvCudaDevice, "TypeVecUint8").
    define_constructor(Constructor<cv::cuda::device::TypeVec<uint, 8>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<cv::cuda::device::uint8, 8>> rb_cCvCudaDeviceTypeVecUint88 = define_class_under<cv::cuda::device::TypeVec<cv::cuda::device::uint8, 8>>(rb_mCvCudaDevice, "TypeVecUint88").
    define_constructor(Constructor<cv::cuda::device::TypeVec<cv::cuda::device::uint8, 8>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<float, 1>> rb_cCvCudaDeviceTypeVecFloat1 = define_class_under<cv::cuda::device::TypeVec<float, 1>>(rb_mCvCudaDevice, "TypeVecFloat1").
    define_constructor(Constructor<cv::cuda::device::TypeVec<float, 1>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<float1, 1>> rb_cCvCudaDeviceTypeVecFloat11 = define_class_under<cv::cuda::device::TypeVec<float1, 1>>(rb_mCvCudaDevice, "TypeVecFloat11").
    define_constructor(Constructor<cv::cuda::device::TypeVec<float1, 1>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<float, 2>> rb_cCvCudaDeviceTypeVecFloat2 = define_class_under<cv::cuda::device::TypeVec<float, 2>>(rb_mCvCudaDevice, "TypeVecFloat2").
    define_constructor(Constructor<cv::cuda::device::TypeVec<float, 2>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<float2, 2>> rb_cCvCudaDeviceTypeVecFloat22 = define_class_under<cv::cuda::device::TypeVec<float2, 2>>(rb_mCvCudaDevice, "TypeVecFloat22").
    define_constructor(Constructor<cv::cuda::device::TypeVec<float2, 2>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<float, 3>> rb_cCvCudaDeviceTypeVecFloat3 = define_class_under<cv::cuda::device::TypeVec<float, 3>>(rb_mCvCudaDevice, "TypeVecFloat3").
    define_constructor(Constructor<cv::cuda::device::TypeVec<float, 3>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<float3, 3>> rb_cCvCudaDeviceTypeVecFloat33 = define_class_under<cv::cuda::device::TypeVec<float3, 3>>(rb_mCvCudaDevice, "TypeVecFloat33").
    define_constructor(Constructor<cv::cuda::device::TypeVec<float3, 3>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<float, 4>> rb_cCvCudaDeviceTypeVecFloat4 = define_class_under<cv::cuda::device::TypeVec<float, 4>>(rb_mCvCudaDevice, "TypeVecFloat4").
    define_constructor(Constructor<cv::cuda::device::TypeVec<float, 4>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<float4, 4>> rb_cCvCudaDeviceTypeVecFloat44 = define_class_under<cv::cuda::device::TypeVec<float4, 4>>(rb_mCvCudaDevice, "TypeVecFloat44").
    define_constructor(Constructor<cv::cuda::device::TypeVec<float4, 4>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<float, 8>> rb_cCvCudaDeviceTypeVecFloat8 = define_class_under<cv::cuda::device::TypeVec<float, 8>>(rb_mCvCudaDevice, "TypeVecFloat8").
    define_constructor(Constructor<cv::cuda::device::TypeVec<float, 8>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<cv::cuda::device::float8, 8>> rb_cCvCudaDeviceTypeVecFloat88 = define_class_under<cv::cuda::device::TypeVec<cv::cuda::device::float8, 8>>(rb_mCvCudaDevice, "TypeVecFloat88").
    define_constructor(Constructor<cv::cuda::device::TypeVec<cv::cuda::device::float8, 8>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<double, 1>> rb_cCvCudaDeviceTypeVecDouble1 = define_class_under<cv::cuda::device::TypeVec<double, 1>>(rb_mCvCudaDevice, "TypeVecDouble1").
    define_constructor(Constructor<cv::cuda::device::TypeVec<double, 1>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<double1, 1>> rb_cCvCudaDeviceTypeVecDouble11 = define_class_under<cv::cuda::device::TypeVec<double1, 1>>(rb_mCvCudaDevice, "TypeVecDouble11").
    define_constructor(Constructor<cv::cuda::device::TypeVec<double1, 1>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<double, 2>> rb_cCvCudaDeviceTypeVecDouble2 = define_class_under<cv::cuda::device::TypeVec<double, 2>>(rb_mCvCudaDevice, "TypeVecDouble2").
    define_constructor(Constructor<cv::cuda::device::TypeVec<double, 2>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<double2, 2>> rb_cCvCudaDeviceTypeVecDouble22 = define_class_under<cv::cuda::device::TypeVec<double2, 2>>(rb_mCvCudaDevice, "TypeVecDouble22").
    define_constructor(Constructor<cv::cuda::device::TypeVec<double2, 2>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<double, 3>> rb_cCvCudaDeviceTypeVecDouble3 = define_class_under<cv::cuda::device::TypeVec<double, 3>>(rb_mCvCudaDevice, "TypeVecDouble3").
    define_constructor(Constructor<cv::cuda::device::TypeVec<double, 3>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<double3, 3>> rb_cCvCudaDeviceTypeVecDouble33 = define_class_under<cv::cuda::device::TypeVec<double3, 3>>(rb_mCvCudaDevice, "TypeVecDouble33").
    define_constructor(Constructor<cv::cuda::device::TypeVec<double3, 3>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<double, 4>> rb_cCvCudaDeviceTypeVecDouble4 = define_class_under<cv::cuda::device::TypeVec<double, 4>>(rb_mCvCudaDevice, "TypeVecDouble4").
    define_constructor(Constructor<cv::cuda::device::TypeVec<double, 4>>());

  Rice::Data_Type<cv::cuda::device::TypeVec<double4, 4>> rb_cCvCudaDeviceTypeVecDouble44 = define_class_under<cv::cuda::device::TypeVec<double4, 4>>(rb_mCvCudaDevice, "TypeVecDouble44").
    define_constructor(Constructor<cv::cuda::device::TypeVec<double4, 4>>());

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
    define_constructor(Constructor<cv::cuda::device::VecTraits<uchar>>()).
    define_singleton_function<uchar(*)(uchar)>("all", &cv::cuda::device::VecTraits<uchar>::all,
      Arg("v")).
    define_singleton_function<uchar(*)(uchar)>("make", &cv::cuda::device::VecTraits<uchar>::make,
      Arg("x")).
    define_singleton_function<uchar(*)(const uchar*)>("make", &cv::cuda::device::VecTraits<uchar>::make,
      ArgBuffer("v"));

  rb_cCvCudaDeviceVecTraitsUchar.define_constant("Cn", (int)cv::cuda::device::VecTraits<uchar>::cn);

  Rice::Data_Type<cv::cuda::device::VecTraits<uchar1>> rb_cCvCudaDeviceVecTraitsUchar1 = define_class_under<cv::cuda::device::VecTraits<uchar1>>(rb_mCvCudaDevice, "VecTraitsUchar1").
    define_constructor(Constructor<cv::cuda::device::VecTraits<uchar1>>()).
    define_singleton_function<uchar1(*)(uchar)>("all", &cv::cuda::device::VecTraits<uchar1>::all,
      Arg("v")).
    define_singleton_function<uchar1(*)(uchar)>("make", &cv::cuda::device::VecTraits<uchar1>::make,
      Arg("x")).
    define_singleton_function<uchar1(*)(const uchar*)>("make", &cv::cuda::device::VecTraits<uchar1>::make,
      ArgBuffer("v"));

  rb_cCvCudaDeviceVecTraitsUchar1.define_constant("Cn", (int)cv::cuda::device::VecTraits<uchar1>::cn);

  Rice::Data_Type<cv::cuda::device::VecTraits<uchar2>> rb_cCvCudaDeviceVecTraitsUchar2 = define_class_under<cv::cuda::device::VecTraits<uchar2>>(rb_mCvCudaDevice, "VecTraitsUchar2").
    define_constructor(Constructor<cv::cuda::device::VecTraits<uchar2>>()).
    define_singleton_function<uchar2(*)(uchar)>("all", &cv::cuda::device::VecTraits<uchar2>::all,
      Arg("v")).
    define_singleton_function<uchar2(*)(uchar, uchar)>("make", &cv::cuda::device::VecTraits<uchar2>::make,
      Arg("x"), Arg("y")).
    define_singleton_function<uchar2(*)(const uchar*)>("make", &cv::cuda::device::VecTraits<uchar2>::make,
      ArgBuffer("v"));

  rb_cCvCudaDeviceVecTraitsUchar2.define_constant("Cn", (int)cv::cuda::device::VecTraits<uchar2>::cn);

  Rice::Data_Type<cv::cuda::device::VecTraits<uchar3>> rb_cCvCudaDeviceVecTraitsUchar3 = define_class_under<cv::cuda::device::VecTraits<uchar3>>(rb_mCvCudaDevice, "VecTraitsUchar3").
    define_constructor(Constructor<cv::cuda::device::VecTraits<uchar3>>()).
    define_singleton_function<uchar3(*)(uchar)>("all", &cv::cuda::device::VecTraits<uchar3>::all,
      Arg("v")).
    define_singleton_function<uchar3(*)(uchar, uchar, uchar)>("make", &cv::cuda::device::VecTraits<uchar3>::make,
      Arg("x"), Arg("y"), Arg("z")).
    define_singleton_function<uchar3(*)(const uchar*)>("make", &cv::cuda::device::VecTraits<uchar3>::make,
      ArgBuffer("v"));

  rb_cCvCudaDeviceVecTraitsUchar3.define_constant("Cn", (int)cv::cuda::device::VecTraits<uchar3>::cn);

  Rice::Data_Type<cv::cuda::device::VecTraits<uchar4>> rb_cCvCudaDeviceVecTraitsUchar4 = define_class_under<cv::cuda::device::VecTraits<uchar4>>(rb_mCvCudaDevice, "VecTraitsUchar4").
    define_constructor(Constructor<cv::cuda::device::VecTraits<uchar4>>()).
    define_singleton_function<uchar4(*)(uchar)>("all", &cv::cuda::device::VecTraits<uchar4>::all,
      Arg("v")).
    define_singleton_function<uchar4(*)(uchar, uchar, uchar, uchar)>("make", &cv::cuda::device::VecTraits<uchar4>::make,
      Arg("x"), Arg("y"), Arg("z"), Arg("w")).
    define_singleton_function<uchar4(*)(const uchar*)>("make", &cv::cuda::device::VecTraits<uchar4>::make,
      ArgBuffer("v"));

  rb_cCvCudaDeviceVecTraitsUchar4.define_constant("Cn", (int)cv::cuda::device::VecTraits<uchar4>::cn);

  Rice::Data_Type<cv::cuda::device::VecTraits<cv::cuda::device::uchar8>> rb_cCvCudaDeviceVecTraitsUchar8 = define_class_under<cv::cuda::device::VecTraits<cv::cuda::device::uchar8>>(rb_mCvCudaDevice, "VecTraitsUchar8").
    define_constructor(Constructor<cv::cuda::device::VecTraits<cv::cuda::device::uchar8>>()).
    define_singleton_function<cv::cuda::device::uchar8(*)(uchar)>("all", &cv::cuda::device::VecTraits<uchar8>::all,
      Arg("v")).
    define_singleton_function<cv::cuda::device::uchar8(*)(uchar, uchar, uchar, uchar, uchar, uchar, uchar, uchar)>("make", &cv::cuda::device::VecTraits<uchar8>::make,
      Arg("a0"), Arg("a1"), Arg("a2"), Arg("a3"), Arg("a4"), Arg("a5"), Arg("a6"), Arg("a7")).
    define_singleton_function<cv::cuda::device::uchar8(*)(const uchar*)>("make", &cv::cuda::device::VecTraits<uchar8>::make,
      ArgBuffer("v"));

  rb_cCvCudaDeviceVecTraitsUchar8.define_constant("Cn", (int)cv::cuda::device::VecTraits<cv::cuda::device::uchar8>::cn);

  Rice::Data_Type<cv::cuda::device::VecTraits<ushort>> rb_cCvCudaDeviceVecTraitsUshort = define_class_under<cv::cuda::device::VecTraits<ushort>>(rb_mCvCudaDevice, "VecTraitsUshort").
    define_constructor(Constructor<cv::cuda::device::VecTraits<ushort>>()).
    define_singleton_function<ushort(*)(ushort)>("all", &cv::cuda::device::VecTraits<ushort>::all,
      Arg("v")).
    define_singleton_function<ushort(*)(ushort)>("make", &cv::cuda::device::VecTraits<ushort>::make,
      Arg("x")).
    define_singleton_function<ushort(*)(const ushort*)>("make", &cv::cuda::device::VecTraits<ushort>::make,
      ArgBuffer("v"));

  rb_cCvCudaDeviceVecTraitsUshort.define_constant("Cn", (int)cv::cuda::device::VecTraits<ushort>::cn);

  Rice::Data_Type<cv::cuda::device::VecTraits<ushort1>> rb_cCvCudaDeviceVecTraitsUshort1 = define_class_under<cv::cuda::device::VecTraits<ushort1>>(rb_mCvCudaDevice, "VecTraitsUshort1").
    define_constructor(Constructor<cv::cuda::device::VecTraits<ushort1>>()).
    define_singleton_function<ushort1(*)(ushort)>("all", &cv::cuda::device::VecTraits<ushort1>::all,
      Arg("v")).
    define_singleton_function<ushort1(*)(ushort)>("make", &cv::cuda::device::VecTraits<ushort1>::make,
      Arg("x")).
    define_singleton_function<ushort1(*)(const ushort*)>("make", &cv::cuda::device::VecTraits<ushort1>::make,
      ArgBuffer("v"));

  rb_cCvCudaDeviceVecTraitsUshort1.define_constant("Cn", (int)cv::cuda::device::VecTraits<ushort1>::cn);

  Rice::Data_Type<cv::cuda::device::VecTraits<ushort2>> rb_cCvCudaDeviceVecTraitsUshort2 = define_class_under<cv::cuda::device::VecTraits<ushort2>>(rb_mCvCudaDevice, "VecTraitsUshort2").
    define_constructor(Constructor<cv::cuda::device::VecTraits<ushort2>>()).
    define_singleton_function<ushort2(*)(ushort)>("all", &cv::cuda::device::VecTraits<ushort2>::all,
      Arg("v")).
    define_singleton_function<ushort2(*)(ushort, ushort)>("make", &cv::cuda::device::VecTraits<ushort2>::make,
      Arg("x"), Arg("y")).
    define_singleton_function<ushort2(*)(const ushort*)>("make", &cv::cuda::device::VecTraits<ushort2>::make,
      ArgBuffer("v"));

  rb_cCvCudaDeviceVecTraitsUshort2.define_constant("Cn", (int)cv::cuda::device::VecTraits<ushort2>::cn);

  Rice::Data_Type<cv::cuda::device::VecTraits<ushort3>> rb_cCvCudaDeviceVecTraitsUshort3 = define_class_under<cv::cuda::device::VecTraits<ushort3>>(rb_mCvCudaDevice, "VecTraitsUshort3").
    define_constructor(Constructor<cv::cuda::device::VecTraits<ushort3>>()).
    define_singleton_function<ushort3(*)(ushort)>("all", &cv::cuda::device::VecTraits<ushort3>::all,
      Arg("v")).
    define_singleton_function<ushort3(*)(ushort, ushort, ushort)>("make", &cv::cuda::device::VecTraits<ushort3>::make,
      Arg("x"), Arg("y"), Arg("z")).
    define_singleton_function<ushort3(*)(const ushort*)>("make", &cv::cuda::device::VecTraits<ushort3>::make,
      ArgBuffer("v"));

  rb_cCvCudaDeviceVecTraitsUshort3.define_constant("Cn", (int)cv::cuda::device::VecTraits<ushort3>::cn);

  Rice::Data_Type<cv::cuda::device::VecTraits<ushort4>> rb_cCvCudaDeviceVecTraitsUshort4 = define_class_under<cv::cuda::device::VecTraits<ushort4>>(rb_mCvCudaDevice, "VecTraitsUshort4").
    define_constructor(Constructor<cv::cuda::device::VecTraits<ushort4>>()).
    define_singleton_function<ushort4(*)(ushort)>("all", &cv::cuda::device::VecTraits<ushort4>::all,
      Arg("v")).
    define_singleton_function<ushort4(*)(ushort, ushort, ushort, ushort)>("make", &cv::cuda::device::VecTraits<ushort4>::make,
      Arg("x"), Arg("y"), Arg("z"), Arg("w")).
    define_singleton_function<ushort4(*)(const ushort*)>("make", &cv::cuda::device::VecTraits<ushort4>::make,
      ArgBuffer("v"));

  rb_cCvCudaDeviceVecTraitsUshort4.define_constant("Cn", (int)cv::cuda::device::VecTraits<ushort4>::cn);

  Rice::Data_Type<cv::cuda::device::VecTraits<cv::cuda::device::ushort8>> rb_cCvCudaDeviceVecTraitsUshort8 = define_class_under<cv::cuda::device::VecTraits<cv::cuda::device::ushort8>>(rb_mCvCudaDevice, "VecTraitsUshort8").
    define_constructor(Constructor<cv::cuda::device::VecTraits<cv::cuda::device::ushort8>>()).
    define_singleton_function<cv::cuda::device::ushort8(*)(ushort)>("all", &cv::cuda::device::VecTraits<ushort8>::all,
      Arg("v")).
    define_singleton_function<cv::cuda::device::ushort8(*)(ushort, ushort, ushort, ushort, ushort, ushort, ushort, ushort)>("make", &cv::cuda::device::VecTraits<ushort8>::make,
      Arg("a0"), Arg("a1"), Arg("a2"), Arg("a3"), Arg("a4"), Arg("a5"), Arg("a6"), Arg("a7")).
    define_singleton_function<cv::cuda::device::ushort8(*)(const ushort*)>("make", &cv::cuda::device::VecTraits<ushort8>::make,
      ArgBuffer("v"));

  rb_cCvCudaDeviceVecTraitsUshort8.define_constant("Cn", (int)cv::cuda::device::VecTraits<cv::cuda::device::ushort8>::cn);

  Rice::Data_Type<cv::cuda::device::VecTraits<short>> rb_cCvCudaDeviceVecTraitsShort = define_class_under<cv::cuda::device::VecTraits<short>>(rb_mCvCudaDevice, "VecTraitsShort").
    define_constructor(Constructor<cv::cuda::device::VecTraits<short>>()).
    define_singleton_function<short(*)(short)>("all", &cv::cuda::device::VecTraits<short>::all,
      Arg("v")).
    define_singleton_function<short(*)(short)>("make", &cv::cuda::device::VecTraits<short>::make,
      Arg("x")).
    define_singleton_function<short(*)(const short*)>("make", &cv::cuda::device::VecTraits<short>::make,
      ArgBuffer("v"));

  rb_cCvCudaDeviceVecTraitsShort.define_constant("Cn", (int)cv::cuda::device::VecTraits<short>::cn);

  Rice::Data_Type<cv::cuda::device::VecTraits<short1>> rb_cCvCudaDeviceVecTraitsShort1 = define_class_under<cv::cuda::device::VecTraits<short1>>(rb_mCvCudaDevice, "VecTraitsShort1").
    define_constructor(Constructor<cv::cuda::device::VecTraits<short1>>()).
    define_singleton_function<short1(*)(short)>("all", &cv::cuda::device::VecTraits<short1>::all,
      Arg("v")).
    define_singleton_function<short1(*)(short)>("make", &cv::cuda::device::VecTraits<short1>::make,
      Arg("x")).
    define_singleton_function<short1(*)(const short*)>("make", &cv::cuda::device::VecTraits<short1>::make,
      ArgBuffer("v"));

  rb_cCvCudaDeviceVecTraitsShort1.define_constant("Cn", (int)cv::cuda::device::VecTraits<short1>::cn);

  Rice::Data_Type<cv::cuda::device::VecTraits<short2>> rb_cCvCudaDeviceVecTraitsShort2 = define_class_under<cv::cuda::device::VecTraits<short2>>(rb_mCvCudaDevice, "VecTraitsShort2").
    define_constructor(Constructor<cv::cuda::device::VecTraits<short2>>()).
    define_singleton_function<short2(*)(short)>("all", &cv::cuda::device::VecTraits<short2>::all,
      Arg("v")).
    define_singleton_function<short2(*)(short, short)>("make", &cv::cuda::device::VecTraits<short2>::make,
      Arg("x"), Arg("y")).
    define_singleton_function<short2(*)(const short*)>("make", &cv::cuda::device::VecTraits<short2>::make,
      ArgBuffer("v"));

  rb_cCvCudaDeviceVecTraitsShort2.define_constant("Cn", (int)cv::cuda::device::VecTraits<short2>::cn);

  Rice::Data_Type<cv::cuda::device::VecTraits<short3>> rb_cCvCudaDeviceVecTraitsShort3 = define_class_under<cv::cuda::device::VecTraits<short3>>(rb_mCvCudaDevice, "VecTraitsShort3").
    define_constructor(Constructor<cv::cuda::device::VecTraits<short3>>()).
    define_singleton_function<short3(*)(short)>("all", &cv::cuda::device::VecTraits<short3>::all,
      Arg("v")).
    define_singleton_function<short3(*)(short, short, short)>("make", &cv::cuda::device::VecTraits<short3>::make,
      Arg("x"), Arg("y"), Arg("z")).
    define_singleton_function<short3(*)(const short*)>("make", &cv::cuda::device::VecTraits<short3>::make,
      ArgBuffer("v"));

  rb_cCvCudaDeviceVecTraitsShort3.define_constant("Cn", (int)cv::cuda::device::VecTraits<short3>::cn);

  Rice::Data_Type<cv::cuda::device::VecTraits<short4>> rb_cCvCudaDeviceVecTraitsShort4 = define_class_under<cv::cuda::device::VecTraits<short4>>(rb_mCvCudaDevice, "VecTraitsShort4").
    define_constructor(Constructor<cv::cuda::device::VecTraits<short4>>()).
    define_singleton_function<short4(*)(short)>("all", &cv::cuda::device::VecTraits<short4>::all,
      Arg("v")).
    define_singleton_function<short4(*)(short, short, short, short)>("make", &cv::cuda::device::VecTraits<short4>::make,
      Arg("x"), Arg("y"), Arg("z"), Arg("w")).
    define_singleton_function<short4(*)(const short*)>("make", &cv::cuda::device::VecTraits<short4>::make,
      ArgBuffer("v"));

  rb_cCvCudaDeviceVecTraitsShort4.define_constant("Cn", (int)cv::cuda::device::VecTraits<short4>::cn);

  Rice::Data_Type<cv::cuda::device::VecTraits<cv::cuda::device::short8>> rb_cCvCudaDeviceVecTraitsShort8 = define_class_under<cv::cuda::device::VecTraits<cv::cuda::device::short8>>(rb_mCvCudaDevice, "VecTraitsShort8").
    define_constructor(Constructor<cv::cuda::device::VecTraits<cv::cuda::device::short8>>()).
    define_singleton_function<cv::cuda::device::short8(*)(short)>("all", &cv::cuda::device::VecTraits<short8>::all,
      Arg("v")).
    define_singleton_function<cv::cuda::device::short8(*)(short, short, short, short, short, short, short, short)>("make", &cv::cuda::device::VecTraits<short8>::make,
      Arg("a0"), Arg("a1"), Arg("a2"), Arg("a3"), Arg("a4"), Arg("a5"), Arg("a6"), Arg("a7")).
    define_singleton_function<cv::cuda::device::short8(*)(const short*)>("make", &cv::cuda::device::VecTraits<short8>::make,
      ArgBuffer("v"));

  rb_cCvCudaDeviceVecTraitsShort8.define_constant("Cn", (int)cv::cuda::device::VecTraits<cv::cuda::device::short8>::cn);

  Rice::Data_Type<cv::cuda::device::VecTraits<int>> rb_cCvCudaDeviceVecTraitsInt = define_class_under<cv::cuda::device::VecTraits<int>>(rb_mCvCudaDevice, "VecTraitsInt").
    define_constructor(Constructor<cv::cuda::device::VecTraits<int>>()).
    define_singleton_function<int(*)(int)>("all", &cv::cuda::device::VecTraits<int>::all,
      Arg("v")).
    define_singleton_function<int(*)(int)>("make", &cv::cuda::device::VecTraits<int>::make,
      Arg("x")).
    define_singleton_function<int(*)(const int*)>("make", &cv::cuda::device::VecTraits<int>::make,
      ArgBuffer("v"));

  rb_cCvCudaDeviceVecTraitsInt.define_constant("Cn", (int)cv::cuda::device::VecTraits<int>::cn);

  Rice::Data_Type<cv::cuda::device::VecTraits<int1>> rb_cCvCudaDeviceVecTraitsInt1 = define_class_under<cv::cuda::device::VecTraits<int1>>(rb_mCvCudaDevice, "VecTraitsInt1").
    define_constructor(Constructor<cv::cuda::device::VecTraits<int1>>()).
    define_singleton_function<int1(*)(int)>("all", &cv::cuda::device::VecTraits<int1>::all,
      Arg("v")).
    define_singleton_function<int1(*)(int)>("make", &cv::cuda::device::VecTraits<int1>::make,
      Arg("x")).
    define_singleton_function<int1(*)(const int*)>("make", &cv::cuda::device::VecTraits<int1>::make,
      ArgBuffer("v"));

  rb_cCvCudaDeviceVecTraitsInt1.define_constant("Cn", (int)cv::cuda::device::VecTraits<int1>::cn);

  Rice::Data_Type<cv::cuda::device::VecTraits<int2>> rb_cCvCudaDeviceVecTraitsInt2 = define_class_under<cv::cuda::device::VecTraits<int2>>(rb_mCvCudaDevice, "VecTraitsInt2").
    define_constructor(Constructor<cv::cuda::device::VecTraits<int2>>()).
    define_singleton_function<int2(*)(int)>("all", &cv::cuda::device::VecTraits<int2>::all,
      Arg("v")).
    define_singleton_function<int2(*)(int, int)>("make", &cv::cuda::device::VecTraits<int2>::make,
      Arg("x"), Arg("y")).
    define_singleton_function<int2(*)(const int*)>("make", &cv::cuda::device::VecTraits<int2>::make,
      ArgBuffer("v"));

  rb_cCvCudaDeviceVecTraitsInt2.define_constant("Cn", (int)cv::cuda::device::VecTraits<int2>::cn);

  Rice::Data_Type<cv::cuda::device::VecTraits<int3>> rb_cCvCudaDeviceVecTraitsInt3 = define_class_under<cv::cuda::device::VecTraits<int3>>(rb_mCvCudaDevice, "VecTraitsInt3").
    define_constructor(Constructor<cv::cuda::device::VecTraits<int3>>()).
    define_singleton_function<int3(*)(int)>("all", &cv::cuda::device::VecTraits<int3>::all,
      Arg("v")).
    define_singleton_function<int3(*)(int, int, int)>("make", &cv::cuda::device::VecTraits<int3>::make,
      Arg("x"), Arg("y"), Arg("z")).
    define_singleton_function<int3(*)(const int*)>("make", &cv::cuda::device::VecTraits<int3>::make,
      ArgBuffer("v"));

  rb_cCvCudaDeviceVecTraitsInt3.define_constant("Cn", (int)cv::cuda::device::VecTraits<int3>::cn);

  Rice::Data_Type<cv::cuda::device::VecTraits<int4>> rb_cCvCudaDeviceVecTraitsInt4 = define_class_under<cv::cuda::device::VecTraits<int4>>(rb_mCvCudaDevice, "VecTraitsInt4").
    define_constructor(Constructor<cv::cuda::device::VecTraits<int4>>()).
    define_singleton_function<int4(*)(int)>("all", &cv::cuda::device::VecTraits<int4>::all,
      Arg("v")).
    define_singleton_function<int4(*)(int, int, int, int)>("make", &cv::cuda::device::VecTraits<int4>::make,
      Arg("x"), Arg("y"), Arg("z"), Arg("w")).
    define_singleton_function<int4(*)(const int*)>("make", &cv::cuda::device::VecTraits<int4>::make,
      ArgBuffer("v"));

  rb_cCvCudaDeviceVecTraitsInt4.define_constant("Cn", (int)cv::cuda::device::VecTraits<int4>::cn);

  Rice::Data_Type<cv::cuda::device::VecTraits<cv::cuda::device::int8>> rb_cCvCudaDeviceVecTraitsInt8 = define_class_under<cv::cuda::device::VecTraits<cv::cuda::device::int8>>(rb_mCvCudaDevice, "VecTraitsInt8").
    define_constructor(Constructor<cv::cuda::device::VecTraits<cv::cuda::device::int8>>()).
    define_singleton_function<cv::cuda::device::int8(*)(int)>("all", &cv::cuda::device::VecTraits<int8>::all,
      Arg("v")).
    define_singleton_function<cv::cuda::device::int8(*)(int, int, int, int, int, int, int, int)>("make", &cv::cuda::device::VecTraits<int8>::make,
      Arg("a0"), Arg("a1"), Arg("a2"), Arg("a3"), Arg("a4"), Arg("a5"), Arg("a6"), Arg("a7")).
    define_singleton_function<cv::cuda::device::int8(*)(const int*)>("make", &cv::cuda::device::VecTraits<int8>::make,
      ArgBuffer("v"));

  rb_cCvCudaDeviceVecTraitsInt8.define_constant("Cn", (int)cv::cuda::device::VecTraits<cv::cuda::device::int8>::cn);

  Rice::Data_Type<cv::cuda::device::VecTraits<uint>> rb_cCvCudaDeviceVecTraitsUint = define_class_under<cv::cuda::device::VecTraits<uint>>(rb_mCvCudaDevice, "VecTraitsUint").
    define_constructor(Constructor<cv::cuda::device::VecTraits<uint>>()).
    define_singleton_function<uint(*)(uint)>("all", &cv::cuda::device::VecTraits<uint>::all,
      Arg("v")).
    define_singleton_function<uint(*)(uint)>("make", &cv::cuda::device::VecTraits<uint>::make,
      Arg("x")).
    define_singleton_function<uint(*)(const uint*)>("make", &cv::cuda::device::VecTraits<uint>::make,
      ArgBuffer("v"));

  rb_cCvCudaDeviceVecTraitsUint.define_constant("Cn", (int)cv::cuda::device::VecTraits<uint>::cn);

  Rice::Data_Type<cv::cuda::device::VecTraits<uint1>> rb_cCvCudaDeviceVecTraitsUint1 = define_class_under<cv::cuda::device::VecTraits<uint1>>(rb_mCvCudaDevice, "VecTraitsUint1").
    define_constructor(Constructor<cv::cuda::device::VecTraits<uint1>>()).
    define_singleton_function<uint1(*)(uint)>("all", &cv::cuda::device::VecTraits<uint1>::all,
      Arg("v")).
    define_singleton_function<uint1(*)(uint)>("make", &cv::cuda::device::VecTraits<uint1>::make,
      Arg("x")).
    define_singleton_function<uint1(*)(const uint*)>("make", &cv::cuda::device::VecTraits<uint1>::make,
      ArgBuffer("v"));

  rb_cCvCudaDeviceVecTraitsUint1.define_constant("Cn", (int)cv::cuda::device::VecTraits<uint1>::cn);

  Rice::Data_Type<cv::cuda::device::VecTraits<uint2>> rb_cCvCudaDeviceVecTraitsUint2 = define_class_under<cv::cuda::device::VecTraits<uint2>>(rb_mCvCudaDevice, "VecTraitsUint2").
    define_constructor(Constructor<cv::cuda::device::VecTraits<uint2>>()).
    define_singleton_function<uint2(*)(uint)>("all", &cv::cuda::device::VecTraits<uint2>::all,
      Arg("v")).
    define_singleton_function<uint2(*)(uint, uint)>("make", &cv::cuda::device::VecTraits<uint2>::make,
      Arg("x"), Arg("y")).
    define_singleton_function<uint2(*)(const uint*)>("make", &cv::cuda::device::VecTraits<uint2>::make,
      ArgBuffer("v"));

  rb_cCvCudaDeviceVecTraitsUint2.define_constant("Cn", (int)cv::cuda::device::VecTraits<uint2>::cn);

  Rice::Data_Type<cv::cuda::device::VecTraits<uint3>> rb_cCvCudaDeviceVecTraitsUint3 = define_class_under<cv::cuda::device::VecTraits<uint3>>(rb_mCvCudaDevice, "VecTraitsUint3").
    define_constructor(Constructor<cv::cuda::device::VecTraits<uint3>>()).
    define_singleton_function<uint3(*)(uint)>("all", &cv::cuda::device::VecTraits<uint3>::all,
      Arg("v")).
    define_singleton_function<uint3(*)(uint, uint, uint)>("make", &cv::cuda::device::VecTraits<uint3>::make,
      Arg("x"), Arg("y"), Arg("z")).
    define_singleton_function<uint3(*)(const uint*)>("make", &cv::cuda::device::VecTraits<uint3>::make,
      ArgBuffer("v"));

  rb_cCvCudaDeviceVecTraitsUint3.define_constant("Cn", (int)cv::cuda::device::VecTraits<uint3>::cn);

  Rice::Data_Type<cv::cuda::device::VecTraits<uint4>> rb_cCvCudaDeviceVecTraitsUint4 = define_class_under<cv::cuda::device::VecTraits<uint4>>(rb_mCvCudaDevice, "VecTraitsUint4").
    define_constructor(Constructor<cv::cuda::device::VecTraits<uint4>>()).
    define_singleton_function<uint4(*)(uint)>("all", &cv::cuda::device::VecTraits<uint4>::all,
      Arg("v")).
    define_singleton_function<uint4(*)(uint, uint, uint, uint)>("make", &cv::cuda::device::VecTraits<uint4>::make,
      Arg("x"), Arg("y"), Arg("z"), Arg("w")).
    define_singleton_function<uint4(*)(const uint*)>("make", &cv::cuda::device::VecTraits<uint4>::make,
      ArgBuffer("v"));

  rb_cCvCudaDeviceVecTraitsUint4.define_constant("Cn", (int)cv::cuda::device::VecTraits<uint4>::cn);

  Rice::Data_Type<cv::cuda::device::VecTraits<cv::cuda::device::uint8>> rb_cCvCudaDeviceVecTraitsUint8 = define_class_under<cv::cuda::device::VecTraits<cv::cuda::device::uint8>>(rb_mCvCudaDevice, "VecTraitsUint8").
    define_constructor(Constructor<cv::cuda::device::VecTraits<cv::cuda::device::uint8>>()).
    define_singleton_function<cv::cuda::device::uint8(*)(uint)>("all", &cv::cuda::device::VecTraits<uint8>::all,
      Arg("v")).
    define_singleton_function<cv::cuda::device::uint8(*)(uint, uint, uint, uint, uint, uint, uint, uint)>("make", &cv::cuda::device::VecTraits<uint8>::make,
      Arg("a0"), Arg("a1"), Arg("a2"), Arg("a3"), Arg("a4"), Arg("a5"), Arg("a6"), Arg("a7")).
    define_singleton_function<cv::cuda::device::uint8(*)(const uint*)>("make", &cv::cuda::device::VecTraits<uint8>::make,
      ArgBuffer("v"));

  rb_cCvCudaDeviceVecTraitsUint8.define_constant("Cn", (int)cv::cuda::device::VecTraits<cv::cuda::device::uint8>::cn);

  Rice::Data_Type<cv::cuda::device::VecTraits<float>> rb_cCvCudaDeviceVecTraitsFloat = define_class_under<cv::cuda::device::VecTraits<float>>(rb_mCvCudaDevice, "VecTraitsFloat").
    define_constructor(Constructor<cv::cuda::device::VecTraits<float>>()).
    define_singleton_function<float(*)(float)>("all", &cv::cuda::device::VecTraits<float>::all,
      Arg("v")).
    define_singleton_function<float(*)(float)>("make", &cv::cuda::device::VecTraits<float>::make,
      Arg("x")).
    define_singleton_function<float(*)(const float*)>("make", &cv::cuda::device::VecTraits<float>::make,
      ArgBuffer("v"));

  rb_cCvCudaDeviceVecTraitsFloat.define_constant("Cn", (int)cv::cuda::device::VecTraits<float>::cn);

  Rice::Data_Type<cv::cuda::device::VecTraits<float1>> rb_cCvCudaDeviceVecTraitsFloat1 = define_class_under<cv::cuda::device::VecTraits<float1>>(rb_mCvCudaDevice, "VecTraitsFloat1").
    define_constructor(Constructor<cv::cuda::device::VecTraits<float1>>()).
    define_singleton_function<float1(*)(float)>("all", &cv::cuda::device::VecTraits<float1>::all,
      Arg("v")).
    define_singleton_function<float1(*)(float)>("make", &cv::cuda::device::VecTraits<float1>::make,
      Arg("x")).
    define_singleton_function<float1(*)(const float*)>("make", &cv::cuda::device::VecTraits<float1>::make,
      ArgBuffer("v"));

  rb_cCvCudaDeviceVecTraitsFloat1.define_constant("Cn", (int)cv::cuda::device::VecTraits<float1>::cn);

  Rice::Data_Type<cv::cuda::device::VecTraits<float2>> rb_cCvCudaDeviceVecTraitsFloat2 = define_class_under<cv::cuda::device::VecTraits<float2>>(rb_mCvCudaDevice, "VecTraitsFloat2").
    define_constructor(Constructor<cv::cuda::device::VecTraits<float2>>()).
    define_singleton_function<float2(*)(float)>("all", &cv::cuda::device::VecTraits<float2>::all,
      Arg("v")).
    define_singleton_function<float2(*)(float, float)>("make", &cv::cuda::device::VecTraits<float2>::make,
      Arg("x"), Arg("y")).
    define_singleton_function<float2(*)(const float*)>("make", &cv::cuda::device::VecTraits<float2>::make,
      ArgBuffer("v"));

  rb_cCvCudaDeviceVecTraitsFloat2.define_constant("Cn", (int)cv::cuda::device::VecTraits<float2>::cn);

  Rice::Data_Type<cv::cuda::device::VecTraits<float3>> rb_cCvCudaDeviceVecTraitsFloat3 = define_class_under<cv::cuda::device::VecTraits<float3>>(rb_mCvCudaDevice, "VecTraitsFloat3").
    define_constructor(Constructor<cv::cuda::device::VecTraits<float3>>()).
    define_singleton_function<float3(*)(float)>("all", &cv::cuda::device::VecTraits<float3>::all,
      Arg("v")).
    define_singleton_function<float3(*)(float, float, float)>("make", &cv::cuda::device::VecTraits<float3>::make,
      Arg("x"), Arg("y"), Arg("z")).
    define_singleton_function<float3(*)(const float*)>("make", &cv::cuda::device::VecTraits<float3>::make,
      ArgBuffer("v"));

  rb_cCvCudaDeviceVecTraitsFloat3.define_constant("Cn", (int)cv::cuda::device::VecTraits<float3>::cn);

  Rice::Data_Type<cv::cuda::device::VecTraits<float4>> rb_cCvCudaDeviceVecTraitsFloat4 = define_class_under<cv::cuda::device::VecTraits<float4>>(rb_mCvCudaDevice, "VecTraitsFloat4").
    define_constructor(Constructor<cv::cuda::device::VecTraits<float4>>()).
    define_singleton_function<float4(*)(float)>("all", &cv::cuda::device::VecTraits<float4>::all,
      Arg("v")).
    define_singleton_function<float4(*)(float, float, float, float)>("make", &cv::cuda::device::VecTraits<float4>::make,
      Arg("x"), Arg("y"), Arg("z"), Arg("w")).
    define_singleton_function<float4(*)(const float*)>("make", &cv::cuda::device::VecTraits<float4>::make,
      ArgBuffer("v"));

  rb_cCvCudaDeviceVecTraitsFloat4.define_constant("Cn", (int)cv::cuda::device::VecTraits<float4>::cn);

  Rice::Data_Type<cv::cuda::device::VecTraits<cv::cuda::device::float8>> rb_cCvCudaDeviceVecTraitsFloat8 = define_class_under<cv::cuda::device::VecTraits<cv::cuda::device::float8>>(rb_mCvCudaDevice, "VecTraitsFloat8").
    define_constructor(Constructor<cv::cuda::device::VecTraits<cv::cuda::device::float8>>()).
    define_singleton_function<cv::cuda::device::float8(*)(float)>("all", &cv::cuda::device::VecTraits<float8>::all,
      Arg("v")).
    define_singleton_function<cv::cuda::device::float8(*)(float, float, float, float, float, float, float, float)>("make", &cv::cuda::device::VecTraits<float8>::make,
      Arg("a0"), Arg("a1"), Arg("a2"), Arg("a3"), Arg("a4"), Arg("a5"), Arg("a6"), Arg("a7")).
    define_singleton_function<cv::cuda::device::float8(*)(const float*)>("make", &cv::cuda::device::VecTraits<float8>::make,
      ArgBuffer("v"));

  rb_cCvCudaDeviceVecTraitsFloat8.define_constant("Cn", (int)cv::cuda::device::VecTraits<cv::cuda::device::float8>::cn);

  Rice::Data_Type<cv::cuda::device::VecTraits<double>> rb_cCvCudaDeviceVecTraitsDouble = define_class_under<cv::cuda::device::VecTraits<double>>(rb_mCvCudaDevice, "VecTraitsDouble").
    define_constructor(Constructor<cv::cuda::device::VecTraits<double>>()).
    define_singleton_function<double(*)(double)>("all", &cv::cuda::device::VecTraits<double>::all,
      Arg("v")).
    define_singleton_function<double(*)(double)>("make", &cv::cuda::device::VecTraits<double>::make,
      Arg("x")).
    define_singleton_function<double(*)(const double*)>("make", &cv::cuda::device::VecTraits<double>::make,
      ArgBuffer("v"));

  rb_cCvCudaDeviceVecTraitsDouble.define_constant("Cn", (int)cv::cuda::device::VecTraits<double>::cn);

  Rice::Data_Type<cv::cuda::device::VecTraits<double1>> rb_cCvCudaDeviceVecTraitsDouble1 = define_class_under<cv::cuda::device::VecTraits<double1>>(rb_mCvCudaDevice, "VecTraitsDouble1").
    define_constructor(Constructor<cv::cuda::device::VecTraits<double1>>()).
    define_singleton_function<double1(*)(double)>("all", &cv::cuda::device::VecTraits<double1>::all,
      Arg("v")).
    define_singleton_function<double1(*)(double)>("make", &cv::cuda::device::VecTraits<double1>::make,
      Arg("x")).
    define_singleton_function<double1(*)(const double*)>("make", &cv::cuda::device::VecTraits<double1>::make,
      ArgBuffer("v"));

  rb_cCvCudaDeviceVecTraitsDouble1.define_constant("Cn", (int)cv::cuda::device::VecTraits<double1>::cn);

  Rice::Data_Type<cv::cuda::device::VecTraits<double2>> rb_cCvCudaDeviceVecTraitsDouble2 = define_class_under<cv::cuda::device::VecTraits<double2>>(rb_mCvCudaDevice, "VecTraitsDouble2").
    define_constructor(Constructor<cv::cuda::device::VecTraits<double2>>()).
    define_singleton_function<double2(*)(double)>("all", &cv::cuda::device::VecTraits<double2>::all,
      Arg("v")).
    define_singleton_function<double2(*)(double, double)>("make", &cv::cuda::device::VecTraits<double2>::make,
      Arg("x"), Arg("y")).
    define_singleton_function<double2(*)(const double*)>("make", &cv::cuda::device::VecTraits<double2>::make,
      ArgBuffer("v"));

  rb_cCvCudaDeviceVecTraitsDouble2.define_constant("Cn", (int)cv::cuda::device::VecTraits<double2>::cn);

  Rice::Data_Type<cv::cuda::device::VecTraits<double3>> rb_cCvCudaDeviceVecTraitsDouble3 = define_class_under<cv::cuda::device::VecTraits<double3>>(rb_mCvCudaDevice, "VecTraitsDouble3").
    define_constructor(Constructor<cv::cuda::device::VecTraits<double3>>()).
    define_singleton_function<double3(*)(double)>("all", &cv::cuda::device::VecTraits<double3>::all,
      Arg("v")).
    define_singleton_function<double3(*)(double, double, double)>("make", &cv::cuda::device::VecTraits<double3>::make,
      Arg("x"), Arg("y"), Arg("z")).
    define_singleton_function<double3(*)(const double*)>("make", &cv::cuda::device::VecTraits<double3>::make,
      ArgBuffer("v"));

  rb_cCvCudaDeviceVecTraitsDouble3.define_constant("Cn", (int)cv::cuda::device::VecTraits<double3>::cn);

  Rice::Data_Type<cv::cuda::device::VecTraits<double4>> rb_cCvCudaDeviceVecTraitsDouble4 = define_class_under<cv::cuda::device::VecTraits<double4>>(rb_mCvCudaDevice, "VecTraitsDouble4").
    define_constructor(Constructor<cv::cuda::device::VecTraits<double4>>()).
    define_singleton_function<double4(*)(double)>("all", &cv::cuda::device::VecTraits<double4>::all,
      Arg("v")).
    define_singleton_function<double4(*)(double, double, double, double)>("make", &cv::cuda::device::VecTraits<double4>::make,
      Arg("x"), Arg("y"), Arg("z"), Arg("w")).
    define_singleton_function<double4(*)(const double*)>("make", &cv::cuda::device::VecTraits<double4>::make,
      ArgBuffer("v"));

  rb_cCvCudaDeviceVecTraitsDouble4.define_constant("Cn", (int)cv::cuda::device::VecTraits<double4>::cn);

  Rice::Data_Type<cv::cuda::device::VecTraits<cv::cuda::device::double8>> rb_cCvCudaDeviceVecTraitsDouble8 = define_class_under<cv::cuda::device::VecTraits<cv::cuda::device::double8>>(rb_mCvCudaDevice, "VecTraitsDouble8").
    define_constructor(Constructor<cv::cuda::device::VecTraits<cv::cuda::device::double8>>()).
    define_singleton_function<cv::cuda::device::double8(*)(double)>("all", &cv::cuda::device::VecTraits<double8>::all,
      Arg("v")).
    define_singleton_function<cv::cuda::device::double8(*)(double, double, double, double, double, double, double, double)>("make", &cv::cuda::device::VecTraits<double8>::make,
      Arg("a0"), Arg("a1"), Arg("a2"), Arg("a3"), Arg("a4"), Arg("a5"), Arg("a6"), Arg("a7")).
    define_singleton_function<cv::cuda::device::double8(*)(const double*)>("make", &cv::cuda::device::VecTraits<double8>::make,
      ArgBuffer("v"));

  rb_cCvCudaDeviceVecTraitsDouble8.define_constant("Cn", (int)cv::cuda::device::VecTraits<cv::cuda::device::double8>::cn);

  Rice::Data_Type<cv::cuda::device::VecTraits<char>> rb_cCvCudaDeviceVecTraitsChar = define_class_under<cv::cuda::device::VecTraits<char>>(rb_mCvCudaDevice, "VecTraitsChar").
    define_constructor(Constructor<cv::cuda::device::VecTraits<char>>()).
    define_singleton_function<char(*)(char)>("all", &cv::cuda::device::VecTraits<char>::all,
      Arg("v")).
    define_singleton_function<char(*)(char)>("make", &cv::cuda::device::VecTraits<char>::make,
      Arg("x")).
    define_singleton_function<char(*)(const char*)>("make", &cv::cuda::device::VecTraits<char>::make,
      Arg("x"));

  rb_cCvCudaDeviceVecTraitsChar.define_constant("Cn", (int)cv::cuda::device::VecTraits<char>::cn);

  Rice::Data_Type<cv::cuda::device::VecTraits<schar>> rb_cCvCudaDeviceVecTraitsSchar = define_class_under<cv::cuda::device::VecTraits<schar>>(rb_mCvCudaDevice, "VecTraitsSchar").
    define_constructor(Constructor<cv::cuda::device::VecTraits<schar>>()).
    define_singleton_function<schar(*)(schar)>("all", &cv::cuda::device::VecTraits<schar>::all,
      Arg("v")).
    define_singleton_function<schar(*)(schar)>("make", &cv::cuda::device::VecTraits<schar>::make,
      Arg("x")).
    define_singleton_function<schar(*)(const schar*)>("make", &cv::cuda::device::VecTraits<schar>::make,
      ArgBuffer("x"));

  rb_cCvCudaDeviceVecTraitsSchar.define_constant("Cn", (int)cv::cuda::device::VecTraits<schar>::cn);

  Rice::Data_Type<cv::cuda::device::VecTraits<char1>> rb_cCvCudaDeviceVecTraitsChar1 = define_class_under<cv::cuda::device::VecTraits<char1>>(rb_mCvCudaDevice, "VecTraitsChar1").
    define_constructor(Constructor<cv::cuda::device::VecTraits<char1>>()).
    define_singleton_function<char1(*)(schar)>("all", &cv::cuda::device::VecTraits<char1>::all,
      Arg("v")).
    define_singleton_function<char1(*)(schar)>("make", &cv::cuda::device::VecTraits<char1>::make,
      Arg("x")).
    define_singleton_function<char1(*)(const schar*)>("make", &cv::cuda::device::VecTraits<char1>::make,
      ArgBuffer("v"));

  rb_cCvCudaDeviceVecTraitsChar1.define_constant("Cn", (int)cv::cuda::device::VecTraits<char1>::cn);

  Rice::Data_Type<cv::cuda::device::VecTraits<char2>> rb_cCvCudaDeviceVecTraitsChar2 = define_class_under<cv::cuda::device::VecTraits<char2>>(rb_mCvCudaDevice, "VecTraitsChar2").
    define_constructor(Constructor<cv::cuda::device::VecTraits<char2>>()).
    define_singleton_function<char2(*)(schar)>("all", &cv::cuda::device::VecTraits<char2>::all,
      Arg("v")).
    define_singleton_function<char2(*)(schar, schar)>("make", &cv::cuda::device::VecTraits<char2>::make,
      Arg("x"), Arg("y")).
    define_singleton_function<char2(*)(const schar*)>("make", &cv::cuda::device::VecTraits<char2>::make,
      ArgBuffer("v"));

  rb_cCvCudaDeviceVecTraitsChar2.define_constant("Cn", (int)cv::cuda::device::VecTraits<char2>::cn);

  Rice::Data_Type<cv::cuda::device::VecTraits<char3>> rb_cCvCudaDeviceVecTraitsChar3 = define_class_under<cv::cuda::device::VecTraits<char3>>(rb_mCvCudaDevice, "VecTraitsChar3").
    define_constructor(Constructor<cv::cuda::device::VecTraits<char3>>()).
    define_singleton_function<char3(*)(schar)>("all", &cv::cuda::device::VecTraits<char3>::all,
      Arg("v")).
    define_singleton_function<char3(*)(schar, schar, schar)>("make", &cv::cuda::device::VecTraits<char3>::make,
      Arg("x"), Arg("y"), Arg("z")).
    define_singleton_function<char3(*)(const schar*)>("make", &cv::cuda::device::VecTraits<char3>::make,
      ArgBuffer("v"));

  rb_cCvCudaDeviceVecTraitsChar3.define_constant("Cn", (int)cv::cuda::device::VecTraits<char3>::cn);

  Rice::Data_Type<cv::cuda::device::VecTraits<char4>> rb_cCvCudaDeviceVecTraitsChar4 = define_class_under<cv::cuda::device::VecTraits<char4>>(rb_mCvCudaDevice, "VecTraitsChar4").
    define_constructor(Constructor<cv::cuda::device::VecTraits<char4>>()).
    define_singleton_function<char4(*)(schar)>("all", &cv::cuda::device::VecTraits<char4>::all,
      Arg("v")).
    define_singleton_function<char4(*)(schar, schar, schar, schar)>("make", &cv::cuda::device::VecTraits<char4>::make,
      Arg("x"), Arg("y"), Arg("z"), Arg("w")).
    define_singleton_function<char4(*)(const schar*)>("make", &cv::cuda::device::VecTraits<char4>::make,
      ArgBuffer("v"));

  rb_cCvCudaDeviceVecTraitsChar4.define_constant("Cn", (int)cv::cuda::device::VecTraits<char4>::cn);

  Rice::Data_Type<cv::cuda::device::VecTraits<cv::cuda::device::char8>> rb_cCvCudaDeviceVecTraitsChar8 = define_class_under<cv::cuda::device::VecTraits<cv::cuda::device::char8>>(rb_mCvCudaDevice, "VecTraitsChar8").
    define_constructor(Constructor<cv::cuda::device::VecTraits<cv::cuda::device::char8>>()).
    define_singleton_function<cv::cuda::device::char8(*)(schar)>("all", &cv::cuda::device::VecTraits<char8>::all,
      Arg("v")).
    define_singleton_function<cv::cuda::device::char8(*)(schar, schar, schar, schar, schar, schar, schar, schar)>("make", &cv::cuda::device::VecTraits<char8>::make,
      Arg("a0"), Arg("a1"), Arg("a2"), Arg("a3"), Arg("a4"), Arg("a5"), Arg("a6"), Arg("a7")).
    define_singleton_function<cv::cuda::device::char8(*)(const schar*)>("make", &cv::cuda::device::VecTraits<char8>::make,
      ArgBuffer("v"));

  rb_cCvCudaDeviceVecTraitsChar8.define_constant("Cn", (int)cv::cuda::device::VecTraits<cv::cuda::device::char8>::cn);
}