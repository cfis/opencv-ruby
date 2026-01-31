#include <opencv2/cudev/util/vec_traits.hpp>
#include "vec_traits-rb.hpp"

using namespace Rice;

void Init_Cudev_Util_VecTraits()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");

  Rice::Data_Type<cv::cudev::MakeVec<uchar, 1>> rb_cCvCudevMakeVecUchar1 = define_class_under<cv::cudev::MakeVec<uchar, 1>>(rb_mCvCudev, "MakeVecUchar1").
    define_constructor(Constructor<cv::cudev::MakeVec<uchar, 1>>());

  Rice::Data_Type<cv::cudev::MakeVec<uchar, 2>> rb_cCvCudevMakeVecUchar2 = define_class_under<cv::cudev::MakeVec<uchar, 2>>(rb_mCvCudev, "MakeVecUchar2").
    define_constructor(Constructor<cv::cudev::MakeVec<uchar, 2>>());

  Rice::Data_Type<cv::cudev::MakeVec<uchar, 3>> rb_cCvCudevMakeVecUchar3 = define_class_under<cv::cudev::MakeVec<uchar, 3>>(rb_mCvCudev, "MakeVecUchar3").
    define_constructor(Constructor<cv::cudev::MakeVec<uchar, 3>>());

  Rice::Data_Type<cv::cudev::MakeVec<uchar, 4>> rb_cCvCudevMakeVecUchar4 = define_class_under<cv::cudev::MakeVec<uchar, 4>>(rb_mCvCudev, "MakeVecUchar4").
    define_constructor(Constructor<cv::cudev::MakeVec<uchar, 4>>());

  Rice::Data_Type<cv::cudev::MakeVec<ushort, 1>> rb_cCvCudevMakeVecUshort1 = define_class_under<cv::cudev::MakeVec<ushort, 1>>(rb_mCvCudev, "MakeVecUshort1").
    define_constructor(Constructor<cv::cudev::MakeVec<ushort, 1>>());

  Rice::Data_Type<cv::cudev::MakeVec<ushort, 2>> rb_cCvCudevMakeVecUshort2 = define_class_under<cv::cudev::MakeVec<ushort, 2>>(rb_mCvCudev, "MakeVecUshort2").
    define_constructor(Constructor<cv::cudev::MakeVec<ushort, 2>>());

  Rice::Data_Type<cv::cudev::MakeVec<ushort, 3>> rb_cCvCudevMakeVecUshort3 = define_class_under<cv::cudev::MakeVec<ushort, 3>>(rb_mCvCudev, "MakeVecUshort3").
    define_constructor(Constructor<cv::cudev::MakeVec<ushort, 3>>());

  Rice::Data_Type<cv::cudev::MakeVec<ushort, 4>> rb_cCvCudevMakeVecUshort4 = define_class_under<cv::cudev::MakeVec<ushort, 4>>(rb_mCvCudev, "MakeVecUshort4").
    define_constructor(Constructor<cv::cudev::MakeVec<ushort, 4>>());

  Rice::Data_Type<cv::cudev::MakeVec<short, 1>> rb_cCvCudevMakeVecShort1 = define_class_under<cv::cudev::MakeVec<short, 1>>(rb_mCvCudev, "MakeVecShort1").
    define_constructor(Constructor<cv::cudev::MakeVec<short, 1>>());

  Rice::Data_Type<cv::cudev::MakeVec<short, 2>> rb_cCvCudevMakeVecShort2 = define_class_under<cv::cudev::MakeVec<short, 2>>(rb_mCvCudev, "MakeVecShort2").
    define_constructor(Constructor<cv::cudev::MakeVec<short, 2>>());

  Rice::Data_Type<cv::cudev::MakeVec<short, 3>> rb_cCvCudevMakeVecShort3 = define_class_under<cv::cudev::MakeVec<short, 3>>(rb_mCvCudev, "MakeVecShort3").
    define_constructor(Constructor<cv::cudev::MakeVec<short, 3>>());

  Rice::Data_Type<cv::cudev::MakeVec<short, 4>> rb_cCvCudevMakeVecShort4 = define_class_under<cv::cudev::MakeVec<short, 4>>(rb_mCvCudev, "MakeVecShort4").
    define_constructor(Constructor<cv::cudev::MakeVec<short, 4>>());

  Rice::Data_Type<cv::cudev::MakeVec<int, 1>> rb_cCvCudevMakeVecInt1 = define_class_under<cv::cudev::MakeVec<int, 1>>(rb_mCvCudev, "MakeVecInt1").
    define_constructor(Constructor<cv::cudev::MakeVec<int, 1>>());

  Rice::Data_Type<cv::cudev::MakeVec<int, 2>> rb_cCvCudevMakeVecInt2 = define_class_under<cv::cudev::MakeVec<int, 2>>(rb_mCvCudev, "MakeVecInt2").
    define_constructor(Constructor<cv::cudev::MakeVec<int, 2>>());

  Rice::Data_Type<cv::cudev::MakeVec<int, 3>> rb_cCvCudevMakeVecInt3 = define_class_under<cv::cudev::MakeVec<int, 3>>(rb_mCvCudev, "MakeVecInt3").
    define_constructor(Constructor<cv::cudev::MakeVec<int, 3>>());

  Rice::Data_Type<cv::cudev::MakeVec<int, 4>> rb_cCvCudevMakeVecInt4 = define_class_under<cv::cudev::MakeVec<int, 4>>(rb_mCvCudev, "MakeVecInt4").
    define_constructor(Constructor<cv::cudev::MakeVec<int, 4>>());

  Rice::Data_Type<cv::cudev::MakeVec<uint, 1>> rb_cCvCudevMakeVecUint1 = define_class_under<cv::cudev::MakeVec<uint, 1>>(rb_mCvCudev, "MakeVecUint1").
    define_constructor(Constructor<cv::cudev::MakeVec<uint, 1>>());

  Rice::Data_Type<cv::cudev::MakeVec<uint, 2>> rb_cCvCudevMakeVecUint2 = define_class_under<cv::cudev::MakeVec<uint, 2>>(rb_mCvCudev, "MakeVecUint2").
    define_constructor(Constructor<cv::cudev::MakeVec<uint, 2>>());

  Rice::Data_Type<cv::cudev::MakeVec<uint, 3>> rb_cCvCudevMakeVecUint3 = define_class_under<cv::cudev::MakeVec<uint, 3>>(rb_mCvCudev, "MakeVecUint3").
    define_constructor(Constructor<cv::cudev::MakeVec<uint, 3>>());

  Rice::Data_Type<cv::cudev::MakeVec<uint, 4>> rb_cCvCudevMakeVecUint4 = define_class_under<cv::cudev::MakeVec<uint, 4>>(rb_mCvCudev, "MakeVecUint4").
    define_constructor(Constructor<cv::cudev::MakeVec<uint, 4>>());

  Rice::Data_Type<cv::cudev::MakeVec<float, 1>> rb_cCvCudevMakeVecFloat1 = define_class_under<cv::cudev::MakeVec<float, 1>>(rb_mCvCudev, "MakeVecFloat1").
    define_constructor(Constructor<cv::cudev::MakeVec<float, 1>>());

  Rice::Data_Type<cv::cudev::MakeVec<float, 2>> rb_cCvCudevMakeVecFloat2 = define_class_under<cv::cudev::MakeVec<float, 2>>(rb_mCvCudev, "MakeVecFloat2").
    define_constructor(Constructor<cv::cudev::MakeVec<float, 2>>());

  Rice::Data_Type<cv::cudev::MakeVec<float, 3>> rb_cCvCudevMakeVecFloat3 = define_class_under<cv::cudev::MakeVec<float, 3>>(rb_mCvCudev, "MakeVecFloat3").
    define_constructor(Constructor<cv::cudev::MakeVec<float, 3>>());

  Rice::Data_Type<cv::cudev::MakeVec<float, 4>> rb_cCvCudevMakeVecFloat4 = define_class_under<cv::cudev::MakeVec<float, 4>>(rb_mCvCudev, "MakeVecFloat4").
    define_constructor(Constructor<cv::cudev::MakeVec<float, 4>>());

  Rice::Data_Type<cv::cudev::MakeVec<double, 1>> rb_cCvCudevMakeVecDouble1 = define_class_under<cv::cudev::MakeVec<double, 1>>(rb_mCvCudev, "MakeVecDouble1").
    define_constructor(Constructor<cv::cudev::MakeVec<double, 1>>());

  Rice::Data_Type<cv::cudev::MakeVec<double, 2>> rb_cCvCudevMakeVecDouble2 = define_class_under<cv::cudev::MakeVec<double, 2>>(rb_mCvCudev, "MakeVecDouble2").
    define_constructor(Constructor<cv::cudev::MakeVec<double, 2>>());

  Rice::Data_Type<cv::cudev::MakeVec<double, 3>> rb_cCvCudevMakeVecDouble3 = define_class_under<cv::cudev::MakeVec<double, 3>>(rb_mCvCudev, "MakeVecDouble3").
    define_constructor(Constructor<cv::cudev::MakeVec<double, 3>>());

  Rice::Data_Type<cv::cudev::MakeVec<double, 4>> rb_cCvCudevMakeVecDouble4 = define_class_under<cv::cudev::MakeVec<double, 4>>(rb_mCvCudev, "MakeVecDouble4").
    define_constructor(Constructor<cv::cudev::MakeVec<double, 4>>());

  Rice::Data_Type<cv::cudev::MakeVec<schar, 1>> rb_cCvCudevMakeVecSchar1 = define_class_under<cv::cudev::MakeVec<schar, 1>>(rb_mCvCudev, "MakeVecSchar1").
    define_constructor(Constructor<cv::cudev::MakeVec<schar, 1>>());

  Rice::Data_Type<cv::cudev::MakeVec<schar, 2>> rb_cCvCudevMakeVecSchar2 = define_class_under<cv::cudev::MakeVec<schar, 2>>(rb_mCvCudev, "MakeVecSchar2").
    define_constructor(Constructor<cv::cudev::MakeVec<schar, 2>>());

  Rice::Data_Type<cv::cudev::MakeVec<schar, 3>> rb_cCvCudevMakeVecSchar3 = define_class_under<cv::cudev::MakeVec<schar, 3>>(rb_mCvCudev, "MakeVecSchar3").
    define_constructor(Constructor<cv::cudev::MakeVec<schar, 3>>());

  Rice::Data_Type<cv::cudev::MakeVec<schar, 4>> rb_cCvCudevMakeVecSchar4 = define_class_under<cv::cudev::MakeVec<schar, 4>>(rb_mCvCudev, "MakeVecSchar4").
    define_constructor(Constructor<cv::cudev::MakeVec<schar, 4>>());

  Rice::Data_Type<cv::cudev::MakeVec<bool, 1>> rb_cCvCudevMakeVecBool1 = define_class_under<cv::cudev::MakeVec<bool, 1>>(rb_mCvCudev, "MakeVecBool1").
    define_constructor(Constructor<cv::cudev::MakeVec<bool, 1>>());

  Rice::Data_Type<cv::cudev::MakeVec<bool, 2>> rb_cCvCudevMakeVecBool2 = define_class_under<cv::cudev::MakeVec<bool, 2>>(rb_mCvCudev, "MakeVecBool2").
    define_constructor(Constructor<cv::cudev::MakeVec<bool, 2>>());

  Rice::Data_Type<cv::cudev::MakeVec<bool, 3>> rb_cCvCudevMakeVecBool3 = define_class_under<cv::cudev::MakeVec<bool, 3>>(rb_mCvCudev, "MakeVecBool3").
    define_constructor(Constructor<cv::cudev::MakeVec<bool, 3>>());

  Rice::Data_Type<cv::cudev::MakeVec<bool, 4>> rb_cCvCudevMakeVecBool4 = define_class_under<cv::cudev::MakeVec<bool, 4>>(rb_mCvCudev, "MakeVecBool4").
    define_constructor(Constructor<cv::cudev::MakeVec<bool, 4>>());

  Rice::Data_Type<cv::cudev::VecTraits<uchar>> rb_cCvCudevVecTraitsUchar = define_class_under<cv::cudev::VecTraits<uchar>>(rb_mCvCudev, "VecTraitsUchar").
    define_constructor(Constructor<cv::cudev::VecTraits<uchar>>()).
    define_singleton_function<uchar(*)(uchar)>("all", &cv::cudev::VecTraits<uchar>::all,
      Arg("v")).
    define_singleton_function<uchar(*)(uchar)>("make", &cv::cudev::VecTraits<uchar>::make,
      Arg("x")).
    define_singleton_function<uchar(*)(const uchar*)>("make", &cv::cudev::VecTraits<uchar>::make,
      ArgBuffer("v"));

  rb_cCvCudevVecTraitsUchar.define_constant("Cn", (int)cv::cudev::VecTraits<uchar>::cn);

  Rice::Data_Type<cv::cudev::VecTraits<uchar1>> rb_cCvCudevVecTraitsUchar1 = define_class_under<cv::cudev::VecTraits<uchar1>>(rb_mCvCudev, "VecTraitsUchar1").
    define_constructor(Constructor<cv::cudev::VecTraits<uchar1>>()).
    define_singleton_function<uchar1(*)(uchar)>("all", &cv::cudev::VecTraits<uchar1>::all,
      Arg("v")).
    define_singleton_function<uchar1(*)(uchar)>("make", &cv::cudev::VecTraits<uchar1>::make,
      Arg("x")).
    define_singleton_function<uchar1(*)(const uchar*)>("make", &cv::cudev::VecTraits<uchar1>::make,
      ArgBuffer("v"));

  rb_cCvCudevVecTraitsUchar1.define_constant("Cn", (int)cv::cudev::VecTraits<uchar1>::cn);

  Rice::Data_Type<cv::cudev::VecTraits<uchar2>> rb_cCvCudevVecTraitsUchar2 = define_class_under<cv::cudev::VecTraits<uchar2>>(rb_mCvCudev, "VecTraitsUchar2").
    define_constructor(Constructor<cv::cudev::VecTraits<uchar2>>()).
    define_singleton_function<uchar2(*)(uchar)>("all", &cv::cudev::VecTraits<uchar2>::all,
      Arg("v")).
    define_singleton_function<uchar2(*)(uchar, uchar)>("make", &cv::cudev::VecTraits<uchar2>::make,
      Arg("x"), Arg("y")).
    define_singleton_function<uchar2(*)(const uchar*)>("make", &cv::cudev::VecTraits<uchar2>::make,
      ArgBuffer("v"));

  rb_cCvCudevVecTraitsUchar2.define_constant("Cn", (int)cv::cudev::VecTraits<uchar2>::cn);

  Rice::Data_Type<cv::cudev::VecTraits<uchar3>> rb_cCvCudevVecTraitsUchar3 = define_class_under<cv::cudev::VecTraits<uchar3>>(rb_mCvCudev, "VecTraitsUchar3").
    define_constructor(Constructor<cv::cudev::VecTraits<uchar3>>()).
    define_singleton_function<uchar3(*)(uchar)>("all", &cv::cudev::VecTraits<uchar3>::all,
      Arg("v")).
    define_singleton_function<uchar3(*)(uchar, uchar, uchar)>("make", &cv::cudev::VecTraits<uchar3>::make,
      Arg("x"), Arg("y"), Arg("z")).
    define_singleton_function<uchar3(*)(const uchar*)>("make", &cv::cudev::VecTraits<uchar3>::make,
      ArgBuffer("v"));

  rb_cCvCudevVecTraitsUchar3.define_constant("Cn", (int)cv::cudev::VecTraits<uchar3>::cn);

  Rice::Data_Type<cv::cudev::VecTraits<uchar4>> rb_cCvCudevVecTraitsUchar4 = define_class_under<cv::cudev::VecTraits<uchar4>>(rb_mCvCudev, "VecTraitsUchar4").
    define_constructor(Constructor<cv::cudev::VecTraits<uchar4>>()).
    define_singleton_function<uchar4(*)(uchar)>("all", &cv::cudev::VecTraits<uchar4>::all,
      Arg("v")).
    define_singleton_function<uchar4(*)(uchar, uchar, uchar, uchar)>("make", &cv::cudev::VecTraits<uchar4>::make,
      Arg("x"), Arg("y"), Arg("z"), Arg("w")).
    define_singleton_function<uchar4(*)(const uchar*)>("make", &cv::cudev::VecTraits<uchar4>::make,
      ArgBuffer("v"));

  rb_cCvCudevVecTraitsUchar4.define_constant("Cn", (int)cv::cudev::VecTraits<uchar4>::cn);

  Rice::Data_Type<cv::cudev::VecTraits<ushort>> rb_cCvCudevVecTraitsUshort = define_class_under<cv::cudev::VecTraits<ushort>>(rb_mCvCudev, "VecTraitsUshort").
    define_constructor(Constructor<cv::cudev::VecTraits<ushort>>()).
    define_singleton_function<ushort(*)(ushort)>("all", &cv::cudev::VecTraits<ushort>::all,
      Arg("v")).
    define_singleton_function<ushort(*)(ushort)>("make", &cv::cudev::VecTraits<ushort>::make,
      Arg("x")).
    define_singleton_function<ushort(*)(const ushort*)>("make", &cv::cudev::VecTraits<ushort>::make,
      ArgBuffer("v"));

  rb_cCvCudevVecTraitsUshort.define_constant("Cn", (int)cv::cudev::VecTraits<ushort>::cn);

  Rice::Data_Type<cv::cudev::VecTraits<ushort1>> rb_cCvCudevVecTraitsUshort1 = define_class_under<cv::cudev::VecTraits<ushort1>>(rb_mCvCudev, "VecTraitsUshort1").
    define_constructor(Constructor<cv::cudev::VecTraits<ushort1>>()).
    define_singleton_function<ushort1(*)(ushort)>("all", &cv::cudev::VecTraits<ushort1>::all,
      Arg("v")).
    define_singleton_function<ushort1(*)(ushort)>("make", &cv::cudev::VecTraits<ushort1>::make,
      Arg("x")).
    define_singleton_function<ushort1(*)(const ushort*)>("make", &cv::cudev::VecTraits<ushort1>::make,
      ArgBuffer("v"));

  rb_cCvCudevVecTraitsUshort1.define_constant("Cn", (int)cv::cudev::VecTraits<ushort1>::cn);

  Rice::Data_Type<cv::cudev::VecTraits<ushort2>> rb_cCvCudevVecTraitsUshort2 = define_class_under<cv::cudev::VecTraits<ushort2>>(rb_mCvCudev, "VecTraitsUshort2").
    define_constructor(Constructor<cv::cudev::VecTraits<ushort2>>()).
    define_singleton_function<ushort2(*)(ushort)>("all", &cv::cudev::VecTraits<ushort2>::all,
      Arg("v")).
    define_singleton_function<ushort2(*)(ushort, ushort)>("make", &cv::cudev::VecTraits<ushort2>::make,
      Arg("x"), Arg("y")).
    define_singleton_function<ushort2(*)(const ushort*)>("make", &cv::cudev::VecTraits<ushort2>::make,
      ArgBuffer("v"));

  rb_cCvCudevVecTraitsUshort2.define_constant("Cn", (int)cv::cudev::VecTraits<ushort2>::cn);

  Rice::Data_Type<cv::cudev::VecTraits<ushort3>> rb_cCvCudevVecTraitsUshort3 = define_class_under<cv::cudev::VecTraits<ushort3>>(rb_mCvCudev, "VecTraitsUshort3").
    define_constructor(Constructor<cv::cudev::VecTraits<ushort3>>()).
    define_singleton_function<ushort3(*)(ushort)>("all", &cv::cudev::VecTraits<ushort3>::all,
      Arg("v")).
    define_singleton_function<ushort3(*)(ushort, ushort, ushort)>("make", &cv::cudev::VecTraits<ushort3>::make,
      Arg("x"), Arg("y"), Arg("z")).
    define_singleton_function<ushort3(*)(const ushort*)>("make", &cv::cudev::VecTraits<ushort3>::make,
      ArgBuffer("v"));

  rb_cCvCudevVecTraitsUshort3.define_constant("Cn", (int)cv::cudev::VecTraits<ushort3>::cn);

  Rice::Data_Type<cv::cudev::VecTraits<ushort4>> rb_cCvCudevVecTraitsUshort4 = define_class_under<cv::cudev::VecTraits<ushort4>>(rb_mCvCudev, "VecTraitsUshort4").
    define_constructor(Constructor<cv::cudev::VecTraits<ushort4>>()).
    define_singleton_function<ushort4(*)(ushort)>("all", &cv::cudev::VecTraits<ushort4>::all,
      Arg("v")).
    define_singleton_function<ushort4(*)(ushort, ushort, ushort, ushort)>("make", &cv::cudev::VecTraits<ushort4>::make,
      Arg("x"), Arg("y"), Arg("z"), Arg("w")).
    define_singleton_function<ushort4(*)(const ushort*)>("make", &cv::cudev::VecTraits<ushort4>::make,
      ArgBuffer("v"));

  rb_cCvCudevVecTraitsUshort4.define_constant("Cn", (int)cv::cudev::VecTraits<ushort4>::cn);

  Rice::Data_Type<cv::cudev::VecTraits<short>> rb_cCvCudevVecTraitsShort = define_class_under<cv::cudev::VecTraits<short>>(rb_mCvCudev, "VecTraitsShort").
    define_constructor(Constructor<cv::cudev::VecTraits<short>>()).
    define_singleton_function<short(*)(short)>("all", &cv::cudev::VecTraits<short>::all,
      Arg("v")).
    define_singleton_function<short(*)(short)>("make", &cv::cudev::VecTraits<short>::make,
      Arg("x")).
    define_singleton_function<short(*)(const short*)>("make", &cv::cudev::VecTraits<short>::make,
      ArgBuffer("v"));

  rb_cCvCudevVecTraitsShort.define_constant("Cn", (int)cv::cudev::VecTraits<short>::cn);

  Rice::Data_Type<cv::cudev::VecTraits<short1>> rb_cCvCudevVecTraitsShort1 = define_class_under<cv::cudev::VecTraits<short1>>(rb_mCvCudev, "VecTraitsShort1").
    define_constructor(Constructor<cv::cudev::VecTraits<short1>>()).
    define_singleton_function<short1(*)(short)>("all", &cv::cudev::VecTraits<short1>::all,
      Arg("v")).
    define_singleton_function<short1(*)(short)>("make", &cv::cudev::VecTraits<short1>::make,
      Arg("x")).
    define_singleton_function<short1(*)(const short*)>("make", &cv::cudev::VecTraits<short1>::make,
      ArgBuffer("v"));

  rb_cCvCudevVecTraitsShort1.define_constant("Cn", (int)cv::cudev::VecTraits<short1>::cn);

  Rice::Data_Type<cv::cudev::VecTraits<short2>> rb_cCvCudevVecTraitsShort2 = define_class_under<cv::cudev::VecTraits<short2>>(rb_mCvCudev, "VecTraitsShort2").
    define_constructor(Constructor<cv::cudev::VecTraits<short2>>()).
    define_singleton_function<short2(*)(short)>("all", &cv::cudev::VecTraits<short2>::all,
      Arg("v")).
    define_singleton_function<short2(*)(short, short)>("make", &cv::cudev::VecTraits<short2>::make,
      Arg("x"), Arg("y")).
    define_singleton_function<short2(*)(const short*)>("make", &cv::cudev::VecTraits<short2>::make,
      ArgBuffer("v"));

  rb_cCvCudevVecTraitsShort2.define_constant("Cn", (int)cv::cudev::VecTraits<short2>::cn);

  Rice::Data_Type<cv::cudev::VecTraits<short3>> rb_cCvCudevVecTraitsShort3 = define_class_under<cv::cudev::VecTraits<short3>>(rb_mCvCudev, "VecTraitsShort3").
    define_constructor(Constructor<cv::cudev::VecTraits<short3>>()).
    define_singleton_function<short3(*)(short)>("all", &cv::cudev::VecTraits<short3>::all,
      Arg("v")).
    define_singleton_function<short3(*)(short, short, short)>("make", &cv::cudev::VecTraits<short3>::make,
      Arg("x"), Arg("y"), Arg("z")).
    define_singleton_function<short3(*)(const short*)>("make", &cv::cudev::VecTraits<short3>::make,
      ArgBuffer("v"));

  rb_cCvCudevVecTraitsShort3.define_constant("Cn", (int)cv::cudev::VecTraits<short3>::cn);

  Rice::Data_Type<cv::cudev::VecTraits<short4>> rb_cCvCudevVecTraitsShort4 = define_class_under<cv::cudev::VecTraits<short4>>(rb_mCvCudev, "VecTraitsShort4").
    define_constructor(Constructor<cv::cudev::VecTraits<short4>>()).
    define_singleton_function<short4(*)(short)>("all", &cv::cudev::VecTraits<short4>::all,
      Arg("v")).
    define_singleton_function<short4(*)(short, short, short, short)>("make", &cv::cudev::VecTraits<short4>::make,
      Arg("x"), Arg("y"), Arg("z"), Arg("w")).
    define_singleton_function<short4(*)(const short*)>("make", &cv::cudev::VecTraits<short4>::make,
      ArgBuffer("v"));

  rb_cCvCudevVecTraitsShort4.define_constant("Cn", (int)cv::cudev::VecTraits<short4>::cn);

  Rice::Data_Type<cv::cudev::VecTraits<int>> rb_cCvCudevVecTraitsInt = define_class_under<cv::cudev::VecTraits<int>>(rb_mCvCudev, "VecTraitsInt").
    define_constructor(Constructor<cv::cudev::VecTraits<int>>()).
    define_singleton_function<int(*)(int)>("all", &cv::cudev::VecTraits<int>::all,
      Arg("v")).
    define_singleton_function<int(*)(int)>("make", &cv::cudev::VecTraits<int>::make,
      Arg("x")).
    define_singleton_function<int(*)(const int*)>("make", &cv::cudev::VecTraits<int>::make,
      ArgBuffer("v"));

  rb_cCvCudevVecTraitsInt.define_constant("Cn", (int)cv::cudev::VecTraits<int>::cn);

  Rice::Data_Type<cv::cudev::VecTraits<int1>> rb_cCvCudevVecTraitsInt1 = define_class_under<cv::cudev::VecTraits<int1>>(rb_mCvCudev, "VecTraitsInt1").
    define_constructor(Constructor<cv::cudev::VecTraits<int1>>()).
    define_singleton_function<int1(*)(int)>("all", &cv::cudev::VecTraits<int1>::all,
      Arg("v")).
    define_singleton_function<int1(*)(int)>("make", &cv::cudev::VecTraits<int1>::make,
      Arg("x")).
    define_singleton_function<int1(*)(const int*)>("make", &cv::cudev::VecTraits<int1>::make,
      ArgBuffer("v"));

  rb_cCvCudevVecTraitsInt1.define_constant("Cn", (int)cv::cudev::VecTraits<int1>::cn);

  Rice::Data_Type<cv::cudev::VecTraits<int2>> rb_cCvCudevVecTraitsInt2 = define_class_under<cv::cudev::VecTraits<int2>>(rb_mCvCudev, "VecTraitsInt2").
    define_constructor(Constructor<cv::cudev::VecTraits<int2>>()).
    define_singleton_function<int2(*)(int)>("all", &cv::cudev::VecTraits<int2>::all,
      Arg("v")).
    define_singleton_function<int2(*)(int, int)>("make", &cv::cudev::VecTraits<int2>::make,
      Arg("x"), Arg("y")).
    define_singleton_function<int2(*)(const int*)>("make", &cv::cudev::VecTraits<int2>::make,
      ArgBuffer("v"));

  rb_cCvCudevVecTraitsInt2.define_constant("Cn", (int)cv::cudev::VecTraits<int2>::cn);

  Rice::Data_Type<cv::cudev::VecTraits<int3>> rb_cCvCudevVecTraitsInt3 = define_class_under<cv::cudev::VecTraits<int3>>(rb_mCvCudev, "VecTraitsInt3").
    define_constructor(Constructor<cv::cudev::VecTraits<int3>>()).
    define_singleton_function<int3(*)(int)>("all", &cv::cudev::VecTraits<int3>::all,
      Arg("v")).
    define_singleton_function<int3(*)(int, int, int)>("make", &cv::cudev::VecTraits<int3>::make,
      Arg("x"), Arg("y"), Arg("z")).
    define_singleton_function<int3(*)(const int*)>("make", &cv::cudev::VecTraits<int3>::make,
      ArgBuffer("v"));

  rb_cCvCudevVecTraitsInt3.define_constant("Cn", (int)cv::cudev::VecTraits<int3>::cn);

  Rice::Data_Type<cv::cudev::VecTraits<int4>> rb_cCvCudevVecTraitsInt4 = define_class_under<cv::cudev::VecTraits<int4>>(rb_mCvCudev, "VecTraitsInt4").
    define_constructor(Constructor<cv::cudev::VecTraits<int4>>()).
    define_singleton_function<int4(*)(int)>("all", &cv::cudev::VecTraits<int4>::all,
      Arg("v")).
    define_singleton_function<int4(*)(int, int, int, int)>("make", &cv::cudev::VecTraits<int4>::make,
      Arg("x"), Arg("y"), Arg("z"), Arg("w")).
    define_singleton_function<int4(*)(const int*)>("make", &cv::cudev::VecTraits<int4>::make,
      ArgBuffer("v"));

  rb_cCvCudevVecTraitsInt4.define_constant("Cn", (int)cv::cudev::VecTraits<int4>::cn);

  Rice::Data_Type<cv::cudev::VecTraits<uint>> rb_cCvCudevVecTraitsUint = define_class_under<cv::cudev::VecTraits<uint>>(rb_mCvCudev, "VecTraitsUint").
    define_constructor(Constructor<cv::cudev::VecTraits<uint>>()).
    define_singleton_function<uint(*)(uint)>("all", &cv::cudev::VecTraits<uint>::all,
      Arg("v")).
    define_singleton_function<uint(*)(uint)>("make", &cv::cudev::VecTraits<uint>::make,
      Arg("x")).
    define_singleton_function<uint(*)(const uint*)>("make", &cv::cudev::VecTraits<uint>::make,
      ArgBuffer("v"));

  rb_cCvCudevVecTraitsUint.define_constant("Cn", (int)cv::cudev::VecTraits<uint>::cn);

  Rice::Data_Type<cv::cudev::VecTraits<uint1>> rb_cCvCudevVecTraitsUint1 = define_class_under<cv::cudev::VecTraits<uint1>>(rb_mCvCudev, "VecTraitsUint1").
    define_constructor(Constructor<cv::cudev::VecTraits<uint1>>()).
    define_singleton_function<uint1(*)(uint)>("all", &cv::cudev::VecTraits<uint1>::all,
      Arg("v")).
    define_singleton_function<uint1(*)(uint)>("make", &cv::cudev::VecTraits<uint1>::make,
      Arg("x")).
    define_singleton_function<uint1(*)(const uint*)>("make", &cv::cudev::VecTraits<uint1>::make,
      ArgBuffer("v"));

  rb_cCvCudevVecTraitsUint1.define_constant("Cn", (int)cv::cudev::VecTraits<uint1>::cn);

  Rice::Data_Type<cv::cudev::VecTraits<uint2>> rb_cCvCudevVecTraitsUint2 = define_class_under<cv::cudev::VecTraits<uint2>>(rb_mCvCudev, "VecTraitsUint2").
    define_constructor(Constructor<cv::cudev::VecTraits<uint2>>()).
    define_singleton_function<uint2(*)(uint)>("all", &cv::cudev::VecTraits<uint2>::all,
      Arg("v")).
    define_singleton_function<uint2(*)(uint, uint)>("make", &cv::cudev::VecTraits<uint2>::make,
      Arg("x"), Arg("y")).
    define_singleton_function<uint2(*)(const uint*)>("make", &cv::cudev::VecTraits<uint2>::make,
      ArgBuffer("v"));

  rb_cCvCudevVecTraitsUint2.define_constant("Cn", (int)cv::cudev::VecTraits<uint2>::cn);

  Rice::Data_Type<cv::cudev::VecTraits<uint3>> rb_cCvCudevVecTraitsUint3 = define_class_under<cv::cudev::VecTraits<uint3>>(rb_mCvCudev, "VecTraitsUint3").
    define_constructor(Constructor<cv::cudev::VecTraits<uint3>>()).
    define_singleton_function<uint3(*)(uint)>("all", &cv::cudev::VecTraits<uint3>::all,
      Arg("v")).
    define_singleton_function<uint3(*)(uint, uint, uint)>("make", &cv::cudev::VecTraits<uint3>::make,
      Arg("x"), Arg("y"), Arg("z")).
    define_singleton_function<uint3(*)(const uint*)>("make", &cv::cudev::VecTraits<uint3>::make,
      ArgBuffer("v"));

  rb_cCvCudevVecTraitsUint3.define_constant("Cn", (int)cv::cudev::VecTraits<uint3>::cn);

  Rice::Data_Type<cv::cudev::VecTraits<uint4>> rb_cCvCudevVecTraitsUint4 = define_class_under<cv::cudev::VecTraits<uint4>>(rb_mCvCudev, "VecTraitsUint4").
    define_constructor(Constructor<cv::cudev::VecTraits<uint4>>()).
    define_singleton_function<uint4(*)(uint)>("all", &cv::cudev::VecTraits<uint4>::all,
      Arg("v")).
    define_singleton_function<uint4(*)(uint, uint, uint, uint)>("make", &cv::cudev::VecTraits<uint4>::make,
      Arg("x"), Arg("y"), Arg("z"), Arg("w")).
    define_singleton_function<uint4(*)(const uint*)>("make", &cv::cudev::VecTraits<uint4>::make,
      ArgBuffer("v"));

  rb_cCvCudevVecTraitsUint4.define_constant("Cn", (int)cv::cudev::VecTraits<uint4>::cn);

  Rice::Data_Type<cv::cudev::VecTraits<float>> rb_cCvCudevVecTraitsFloat = define_class_under<cv::cudev::VecTraits<float>>(rb_mCvCudev, "VecTraitsFloat").
    define_constructor(Constructor<cv::cudev::VecTraits<float>>()).
    define_singleton_function<float(*)(float)>("all", &cv::cudev::VecTraits<float>::all,
      Arg("v")).
    define_singleton_function<float(*)(float)>("make", &cv::cudev::VecTraits<float>::make,
      Arg("x")).
    define_singleton_function<float(*)(const float*)>("make", &cv::cudev::VecTraits<float>::make,
      ArgBuffer("v"));

  rb_cCvCudevVecTraitsFloat.define_constant("Cn", (int)cv::cudev::VecTraits<float>::cn);

  Rice::Data_Type<cv::cudev::VecTraits<float1>> rb_cCvCudevVecTraitsFloat1 = define_class_under<cv::cudev::VecTraits<float1>>(rb_mCvCudev, "VecTraitsFloat1").
    define_constructor(Constructor<cv::cudev::VecTraits<float1>>()).
    define_singleton_function<float1(*)(float)>("all", &cv::cudev::VecTraits<float1>::all,
      Arg("v")).
    define_singleton_function<float1(*)(float)>("make", &cv::cudev::VecTraits<float1>::make,
      Arg("x")).
    define_singleton_function<float1(*)(const float*)>("make", &cv::cudev::VecTraits<float1>::make,
      ArgBuffer("v"));

  rb_cCvCudevVecTraitsFloat1.define_constant("Cn", (int)cv::cudev::VecTraits<float1>::cn);

  Rice::Data_Type<cv::cudev::VecTraits<float2>> rb_cCvCudevVecTraitsFloat2 = define_class_under<cv::cudev::VecTraits<float2>>(rb_mCvCudev, "VecTraitsFloat2").
    define_constructor(Constructor<cv::cudev::VecTraits<float2>>()).
    define_singleton_function<float2(*)(float)>("all", &cv::cudev::VecTraits<float2>::all,
      Arg("v")).
    define_singleton_function<float2(*)(float, float)>("make", &cv::cudev::VecTraits<float2>::make,
      Arg("x"), Arg("y")).
    define_singleton_function<float2(*)(const float*)>("make", &cv::cudev::VecTraits<float2>::make,
      ArgBuffer("v"));

  rb_cCvCudevVecTraitsFloat2.define_constant("Cn", (int)cv::cudev::VecTraits<float2>::cn);

  Rice::Data_Type<cv::cudev::VecTraits<float3>> rb_cCvCudevVecTraitsFloat3 = define_class_under<cv::cudev::VecTraits<float3>>(rb_mCvCudev, "VecTraitsFloat3").
    define_constructor(Constructor<cv::cudev::VecTraits<float3>>()).
    define_singleton_function<float3(*)(float)>("all", &cv::cudev::VecTraits<float3>::all,
      Arg("v")).
    define_singleton_function<float3(*)(float, float, float)>("make", &cv::cudev::VecTraits<float3>::make,
      Arg("x"), Arg("y"), Arg("z")).
    define_singleton_function<float3(*)(const float*)>("make", &cv::cudev::VecTraits<float3>::make,
      ArgBuffer("v"));

  rb_cCvCudevVecTraitsFloat3.define_constant("Cn", (int)cv::cudev::VecTraits<float3>::cn);

  Rice::Data_Type<cv::cudev::VecTraits<float4>> rb_cCvCudevVecTraitsFloat4 = define_class_under<cv::cudev::VecTraits<float4>>(rb_mCvCudev, "VecTraitsFloat4").
    define_constructor(Constructor<cv::cudev::VecTraits<float4>>()).
    define_singleton_function<float4(*)(float)>("all", &cv::cudev::VecTraits<float4>::all,
      Arg("v")).
    define_singleton_function<float4(*)(float, float, float, float)>("make", &cv::cudev::VecTraits<float4>::make,
      Arg("x"), Arg("y"), Arg("z"), Arg("w")).
    define_singleton_function<float4(*)(const float*)>("make", &cv::cudev::VecTraits<float4>::make,
      ArgBuffer("v"));

  rb_cCvCudevVecTraitsFloat4.define_constant("Cn", (int)cv::cudev::VecTraits<float4>::cn);

  Rice::Data_Type<cv::cudev::VecTraits<double>> rb_cCvCudevVecTraitsDouble = define_class_under<cv::cudev::VecTraits<double>>(rb_mCvCudev, "VecTraitsDouble").
    define_constructor(Constructor<cv::cudev::VecTraits<double>>()).
    define_singleton_function<double(*)(double)>("all", &cv::cudev::VecTraits<double>::all,
      Arg("v")).
    define_singleton_function<double(*)(double)>("make", &cv::cudev::VecTraits<double>::make,
      Arg("x")).
    define_singleton_function<double(*)(const double*)>("make", &cv::cudev::VecTraits<double>::make,
      ArgBuffer("v"));

  rb_cCvCudevVecTraitsDouble.define_constant("Cn", (int)cv::cudev::VecTraits<double>::cn);

  Rice::Data_Type<cv::cudev::VecTraits<double1>> rb_cCvCudevVecTraitsDouble1 = define_class_under<cv::cudev::VecTraits<double1>>(rb_mCvCudev, "VecTraitsDouble1").
    define_constructor(Constructor<cv::cudev::VecTraits<double1>>()).
    define_singleton_function<double1(*)(double)>("all", &cv::cudev::VecTraits<double1>::all,
      Arg("v")).
    define_singleton_function<double1(*)(double)>("make", &cv::cudev::VecTraits<double1>::make,
      Arg("x")).
    define_singleton_function<double1(*)(const double*)>("make", &cv::cudev::VecTraits<double1>::make,
      ArgBuffer("v"));

  rb_cCvCudevVecTraitsDouble1.define_constant("Cn", (int)cv::cudev::VecTraits<double1>::cn);

  Rice::Data_Type<cv::cudev::VecTraits<double2>> rb_cCvCudevVecTraitsDouble2 = define_class_under<cv::cudev::VecTraits<double2>>(rb_mCvCudev, "VecTraitsDouble2").
    define_constructor(Constructor<cv::cudev::VecTraits<double2>>()).
    define_singleton_function<double2(*)(double)>("all", &cv::cudev::VecTraits<double2>::all,
      Arg("v")).
    define_singleton_function<double2(*)(double, double)>("make", &cv::cudev::VecTraits<double2>::make,
      Arg("x"), Arg("y")).
    define_singleton_function<double2(*)(const double*)>("make", &cv::cudev::VecTraits<double2>::make,
      ArgBuffer("v"));

  rb_cCvCudevVecTraitsDouble2.define_constant("Cn", (int)cv::cudev::VecTraits<double2>::cn);

  Rice::Data_Type<cv::cudev::VecTraits<double3>> rb_cCvCudevVecTraitsDouble3 = define_class_under<cv::cudev::VecTraits<double3>>(rb_mCvCudev, "VecTraitsDouble3").
    define_constructor(Constructor<cv::cudev::VecTraits<double3>>()).
    define_singleton_function<double3(*)(double)>("all", &cv::cudev::VecTraits<double3>::all,
      Arg("v")).
    define_singleton_function<double3(*)(double, double, double)>("make", &cv::cudev::VecTraits<double3>::make,
      Arg("x"), Arg("y"), Arg("z")).
    define_singleton_function<double3(*)(const double*)>("make", &cv::cudev::VecTraits<double3>::make,
      ArgBuffer("v"));

  rb_cCvCudevVecTraitsDouble3.define_constant("Cn", (int)cv::cudev::VecTraits<double3>::cn);

  Rice::Data_Type<cv::cudev::VecTraits<double4>> rb_cCvCudevVecTraitsDouble4 = define_class_under<cv::cudev::VecTraits<double4>>(rb_mCvCudev, "VecTraitsDouble4").
    define_constructor(Constructor<cv::cudev::VecTraits<double4>>()).
    define_singleton_function<double4(*)(double)>("all", &cv::cudev::VecTraits<double4>::all,
      Arg("v")).
    define_singleton_function<double4(*)(double, double, double, double)>("make", &cv::cudev::VecTraits<double4>::make,
      Arg("x"), Arg("y"), Arg("z"), Arg("w")).
    define_singleton_function<double4(*)(const double*)>("make", &cv::cudev::VecTraits<double4>::make,
      ArgBuffer("v"));

  rb_cCvCudevVecTraitsDouble4.define_constant("Cn", (int)cv::cudev::VecTraits<double4>::cn);

  Rice::Data_Type<cv::cudev::VecTraits<schar>> rb_cCvCudevVecTraitsSchar = define_class_under<cv::cudev::VecTraits<schar>>(rb_mCvCudev, "VecTraitsSchar").
    define_constructor(Constructor<cv::cudev::VecTraits<schar>>()).
    define_singleton_function<schar(*)(schar)>("all", &cv::cudev::VecTraits<schar>::all,
      Arg("v")).
    define_singleton_function<schar(*)(schar)>("make", &cv::cudev::VecTraits<schar>::make,
      Arg("x")).
    define_singleton_function<schar(*)(const schar*)>("make", &cv::cudev::VecTraits<schar>::make,
      ArgBuffer("x"));

  rb_cCvCudevVecTraitsSchar.define_constant("Cn", (int)cv::cudev::VecTraits<schar>::cn);

  Rice::Data_Type<cv::cudev::VecTraits<char1>> rb_cCvCudevVecTraitsChar1 = define_class_under<cv::cudev::VecTraits<char1>>(rb_mCvCudev, "VecTraitsChar1").
    define_constructor(Constructor<cv::cudev::VecTraits<char1>>()).
    define_singleton_function<char1(*)(schar)>("all", &cv::cudev::VecTraits<char1>::all,
      Arg("v")).
    define_singleton_function<char1(*)(schar)>("make", &cv::cudev::VecTraits<char1>::make,
      Arg("x")).
    define_singleton_function<char1(*)(const schar*)>("make", &cv::cudev::VecTraits<char1>::make,
      ArgBuffer("v"));

  rb_cCvCudevVecTraitsChar1.define_constant("Cn", (int)cv::cudev::VecTraits<char1>::cn);

  Rice::Data_Type<cv::cudev::VecTraits<char2>> rb_cCvCudevVecTraitsChar2 = define_class_under<cv::cudev::VecTraits<char2>>(rb_mCvCudev, "VecTraitsChar2").
    define_constructor(Constructor<cv::cudev::VecTraits<char2>>()).
    define_singleton_function<char2(*)(schar)>("all", &cv::cudev::VecTraits<char2>::all,
      Arg("v")).
    define_singleton_function<char2(*)(schar, schar)>("make", &cv::cudev::VecTraits<char2>::make,
      Arg("x"), Arg("y")).
    define_singleton_function<char2(*)(const schar*)>("make", &cv::cudev::VecTraits<char2>::make,
      ArgBuffer("v"));

  rb_cCvCudevVecTraitsChar2.define_constant("Cn", (int)cv::cudev::VecTraits<char2>::cn);

  Rice::Data_Type<cv::cudev::VecTraits<char3>> rb_cCvCudevVecTraitsChar3 = define_class_under<cv::cudev::VecTraits<char3>>(rb_mCvCudev, "VecTraitsChar3").
    define_constructor(Constructor<cv::cudev::VecTraits<char3>>()).
    define_singleton_function<char3(*)(schar)>("all", &cv::cudev::VecTraits<char3>::all,
      Arg("v")).
    define_singleton_function<char3(*)(schar, schar, schar)>("make", &cv::cudev::VecTraits<char3>::make,
      Arg("x"), Arg("y"), Arg("z")).
    define_singleton_function<char3(*)(const schar*)>("make", &cv::cudev::VecTraits<char3>::make,
      ArgBuffer("v"));

  rb_cCvCudevVecTraitsChar3.define_constant("Cn", (int)cv::cudev::VecTraits<char3>::cn);

  Rice::Data_Type<cv::cudev::VecTraits<char4>> rb_cCvCudevVecTraitsChar4 = define_class_under<cv::cudev::VecTraits<char4>>(rb_mCvCudev, "VecTraitsChar4").
    define_constructor(Constructor<cv::cudev::VecTraits<char4>>()).
    define_singleton_function<char4(*)(schar)>("all", &cv::cudev::VecTraits<char4>::all,
      Arg("v")).
    define_singleton_function<char4(*)(schar, schar, schar, schar)>("make", &cv::cudev::VecTraits<char4>::make,
      Arg("x"), Arg("y"), Arg("z"), Arg("w")).
    define_singleton_function<char4(*)(const schar*)>("make", &cv::cudev::VecTraits<char4>::make,
      ArgBuffer("v"));

  rb_cCvCudevVecTraitsChar4.define_constant("Cn", (int)cv::cudev::VecTraits<char4>::cn);

  Rice::Data_Type<cv::DataType<uint>> rb_cCvDataTypeUint = define_class_under<cv::DataType<uint>>(rb_mCv, "DataTypeUint").
    define_constructor(Constructor<cv::DataType<uint>>());

  rb_cCvDataTypeUint.define_constant("Generic_type", (int)cv::DataType<uint>::generic_type);
  rb_cCvDataTypeUint.define_constant("Depth", (int)cv::DataType<uint>::depth);
  rb_cCvDataTypeUint.define_constant("Channels", (int)cv::DataType<uint>::channels);
  rb_cCvDataTypeUint.define_constant("Fmt", (int)cv::DataType<uint>::fmt);
  rb_cCvDataTypeUint.define_constant("Type", (int)cv::DataType<uint>::type);

  Rice::Data_Type<cv::DataType<uchar1>> rb_cCvDataTypeUchar1 = define_class_under<cv::DataType<uchar1>>(rb_mCv, "DataTypeUchar1").
    define_constructor(Constructor<cv::DataType<uchar1>>());

  rb_cCvDataTypeUchar1.define_constant("Generic_type", (int)cv::DataType<uchar1>::generic_type);
  rb_cCvDataTypeUchar1.define_constant("Depth", (int)cv::DataType<uchar1>::depth);
  rb_cCvDataTypeUchar1.define_constant("Channels", (int)cv::DataType<uchar1>::channels);
  rb_cCvDataTypeUchar1.define_constant("Fmt", (int)cv::DataType<uchar1>::fmt);
  rb_cCvDataTypeUchar1.define_constant("Type", (int)cv::DataType<uchar1>::type);

  Rice::Data_Type<cv::DataType<uchar2>> rb_cCvDataTypeUchar2 = define_class_under<cv::DataType<uchar2>>(rb_mCv, "DataTypeUchar2").
    define_constructor(Constructor<cv::DataType<uchar2>>());

  rb_cCvDataTypeUchar2.define_constant("Generic_type", (int)cv::DataType<uchar2>::generic_type);
  rb_cCvDataTypeUchar2.define_constant("Depth", (int)cv::DataType<uchar2>::depth);
  rb_cCvDataTypeUchar2.define_constant("Channels", (int)cv::DataType<uchar2>::channels);
  rb_cCvDataTypeUchar2.define_constant("Fmt", (int)cv::DataType<uchar2>::fmt);
  rb_cCvDataTypeUchar2.define_constant("Type", (int)cv::DataType<uchar2>::type);

  Rice::Data_Type<cv::DataType<uchar3>> rb_cCvDataTypeUchar3 = define_class_under<cv::DataType<uchar3>>(rb_mCv, "DataTypeUchar3").
    define_constructor(Constructor<cv::DataType<uchar3>>());

  rb_cCvDataTypeUchar3.define_constant("Generic_type", (int)cv::DataType<uchar3>::generic_type);
  rb_cCvDataTypeUchar3.define_constant("Depth", (int)cv::DataType<uchar3>::depth);
  rb_cCvDataTypeUchar3.define_constant("Channels", (int)cv::DataType<uchar3>::channels);
  rb_cCvDataTypeUchar3.define_constant("Fmt", (int)cv::DataType<uchar3>::fmt);
  rb_cCvDataTypeUchar3.define_constant("Type", (int)cv::DataType<uchar3>::type);

  Rice::Data_Type<cv::DataType<uchar4>> rb_cCvDataTypeUchar4 = define_class_under<cv::DataType<uchar4>>(rb_mCv, "DataTypeUchar4").
    define_constructor(Constructor<cv::DataType<uchar4>>());

  rb_cCvDataTypeUchar4.define_constant("Generic_type", (int)cv::DataType<uchar4>::generic_type);
  rb_cCvDataTypeUchar4.define_constant("Depth", (int)cv::DataType<uchar4>::depth);
  rb_cCvDataTypeUchar4.define_constant("Channels", (int)cv::DataType<uchar4>::channels);
  rb_cCvDataTypeUchar4.define_constant("Fmt", (int)cv::DataType<uchar4>::fmt);
  rb_cCvDataTypeUchar4.define_constant("Type", (int)cv::DataType<uchar4>::type);

  Rice::Data_Type<cv::DataType<ushort1>> rb_cCvDataTypeUshort1 = define_class_under<cv::DataType<ushort1>>(rb_mCv, "DataTypeUshort1").
    define_constructor(Constructor<cv::DataType<ushort1>>());

  rb_cCvDataTypeUshort1.define_constant("Generic_type", (int)cv::DataType<ushort1>::generic_type);
  rb_cCvDataTypeUshort1.define_constant("Depth", (int)cv::DataType<ushort1>::depth);
  rb_cCvDataTypeUshort1.define_constant("Channels", (int)cv::DataType<ushort1>::channels);
  rb_cCvDataTypeUshort1.define_constant("Fmt", (int)cv::DataType<ushort1>::fmt);
  rb_cCvDataTypeUshort1.define_constant("Type", (int)cv::DataType<ushort1>::type);

  Rice::Data_Type<cv::DataType<ushort2>> rb_cCvDataTypeUshort2 = define_class_under<cv::DataType<ushort2>>(rb_mCv, "DataTypeUshort2").
    define_constructor(Constructor<cv::DataType<ushort2>>());

  rb_cCvDataTypeUshort2.define_constant("Generic_type", (int)cv::DataType<ushort2>::generic_type);
  rb_cCvDataTypeUshort2.define_constant("Depth", (int)cv::DataType<ushort2>::depth);
  rb_cCvDataTypeUshort2.define_constant("Channels", (int)cv::DataType<ushort2>::channels);
  rb_cCvDataTypeUshort2.define_constant("Fmt", (int)cv::DataType<ushort2>::fmt);
  rb_cCvDataTypeUshort2.define_constant("Type", (int)cv::DataType<ushort2>::type);

  Rice::Data_Type<cv::DataType<ushort3>> rb_cCvDataTypeUshort3 = define_class_under<cv::DataType<ushort3>>(rb_mCv, "DataTypeUshort3").
    define_constructor(Constructor<cv::DataType<ushort3>>());

  rb_cCvDataTypeUshort3.define_constant("Generic_type", (int)cv::DataType<ushort3>::generic_type);
  rb_cCvDataTypeUshort3.define_constant("Depth", (int)cv::DataType<ushort3>::depth);
  rb_cCvDataTypeUshort3.define_constant("Channels", (int)cv::DataType<ushort3>::channels);
  rb_cCvDataTypeUshort3.define_constant("Fmt", (int)cv::DataType<ushort3>::fmt);
  rb_cCvDataTypeUshort3.define_constant("Type", (int)cv::DataType<ushort3>::type);

  Rice::Data_Type<cv::DataType<ushort4>> rb_cCvDataTypeUshort4 = define_class_under<cv::DataType<ushort4>>(rb_mCv, "DataTypeUshort4").
    define_constructor(Constructor<cv::DataType<ushort4>>());

  rb_cCvDataTypeUshort4.define_constant("Generic_type", (int)cv::DataType<ushort4>::generic_type);
  rb_cCvDataTypeUshort4.define_constant("Depth", (int)cv::DataType<ushort4>::depth);
  rb_cCvDataTypeUshort4.define_constant("Channels", (int)cv::DataType<ushort4>::channels);
  rb_cCvDataTypeUshort4.define_constant("Fmt", (int)cv::DataType<ushort4>::fmt);
  rb_cCvDataTypeUshort4.define_constant("Type", (int)cv::DataType<ushort4>::type);

  Rice::Data_Type<cv::DataType<short1>> rb_cCvDataTypeShort1 = define_class_under<cv::DataType<short1>>(rb_mCv, "DataTypeShort1").
    define_constructor(Constructor<cv::DataType<short1>>());

  rb_cCvDataTypeShort1.define_constant("Generic_type", (int)cv::DataType<short1>::generic_type);
  rb_cCvDataTypeShort1.define_constant("Depth", (int)cv::DataType<short1>::depth);
  rb_cCvDataTypeShort1.define_constant("Channels", (int)cv::DataType<short1>::channels);
  rb_cCvDataTypeShort1.define_constant("Fmt", (int)cv::DataType<short1>::fmt);
  rb_cCvDataTypeShort1.define_constant("Type", (int)cv::DataType<short1>::type);

  Rice::Data_Type<cv::DataType<short2>> rb_cCvDataTypeShort2 = define_class_under<cv::DataType<short2>>(rb_mCv, "DataTypeShort2").
    define_constructor(Constructor<cv::DataType<short2>>());

  rb_cCvDataTypeShort2.define_constant("Generic_type", (int)cv::DataType<short2>::generic_type);
  rb_cCvDataTypeShort2.define_constant("Depth", (int)cv::DataType<short2>::depth);
  rb_cCvDataTypeShort2.define_constant("Channels", (int)cv::DataType<short2>::channels);
  rb_cCvDataTypeShort2.define_constant("Fmt", (int)cv::DataType<short2>::fmt);
  rb_cCvDataTypeShort2.define_constant("Type", (int)cv::DataType<short2>::type);

  Rice::Data_Type<cv::DataType<short3>> rb_cCvDataTypeShort3 = define_class_under<cv::DataType<short3>>(rb_mCv, "DataTypeShort3").
    define_constructor(Constructor<cv::DataType<short3>>());

  rb_cCvDataTypeShort3.define_constant("Generic_type", (int)cv::DataType<short3>::generic_type);
  rb_cCvDataTypeShort3.define_constant("Depth", (int)cv::DataType<short3>::depth);
  rb_cCvDataTypeShort3.define_constant("Channels", (int)cv::DataType<short3>::channels);
  rb_cCvDataTypeShort3.define_constant("Fmt", (int)cv::DataType<short3>::fmt);
  rb_cCvDataTypeShort3.define_constant("Type", (int)cv::DataType<short3>::type);

  Rice::Data_Type<cv::DataType<short4>> rb_cCvDataTypeShort4 = define_class_under<cv::DataType<short4>>(rb_mCv, "DataTypeShort4").
    define_constructor(Constructor<cv::DataType<short4>>());

  rb_cCvDataTypeShort4.define_constant("Generic_type", (int)cv::DataType<short4>::generic_type);
  rb_cCvDataTypeShort4.define_constant("Depth", (int)cv::DataType<short4>::depth);
  rb_cCvDataTypeShort4.define_constant("Channels", (int)cv::DataType<short4>::channels);
  rb_cCvDataTypeShort4.define_constant("Fmt", (int)cv::DataType<short4>::fmt);
  rb_cCvDataTypeShort4.define_constant("Type", (int)cv::DataType<short4>::type);

  Rice::Data_Type<cv::DataType<int1>> rb_cCvDataTypeInt1 = define_class_under<cv::DataType<int1>>(rb_mCv, "DataTypeInt1").
    define_constructor(Constructor<cv::DataType<int1>>());

  rb_cCvDataTypeInt1.define_constant("Generic_type", (int)cv::DataType<int1>::generic_type);
  rb_cCvDataTypeInt1.define_constant("Depth", (int)cv::DataType<int1>::depth);
  rb_cCvDataTypeInt1.define_constant("Channels", (int)cv::DataType<int1>::channels);
  rb_cCvDataTypeInt1.define_constant("Fmt", (int)cv::DataType<int1>::fmt);
  rb_cCvDataTypeInt1.define_constant("Type", (int)cv::DataType<int1>::type);

  Rice::Data_Type<cv::DataType<int2>> rb_cCvDataTypeInt2 = define_class_under<cv::DataType<int2>>(rb_mCv, "DataTypeInt2").
    define_constructor(Constructor<cv::DataType<int2>>());

  rb_cCvDataTypeInt2.define_constant("Generic_type", (int)cv::DataType<int2>::generic_type);
  rb_cCvDataTypeInt2.define_constant("Depth", (int)cv::DataType<int2>::depth);
  rb_cCvDataTypeInt2.define_constant("Channels", (int)cv::DataType<int2>::channels);
  rb_cCvDataTypeInt2.define_constant("Fmt", (int)cv::DataType<int2>::fmt);
  rb_cCvDataTypeInt2.define_constant("Type", (int)cv::DataType<int2>::type);

  Rice::Data_Type<cv::DataType<int3>> rb_cCvDataTypeInt3 = define_class_under<cv::DataType<int3>>(rb_mCv, "DataTypeInt3").
    define_constructor(Constructor<cv::DataType<int3>>());

  rb_cCvDataTypeInt3.define_constant("Generic_type", (int)cv::DataType<int3>::generic_type);
  rb_cCvDataTypeInt3.define_constant("Depth", (int)cv::DataType<int3>::depth);
  rb_cCvDataTypeInt3.define_constant("Channels", (int)cv::DataType<int3>::channels);
  rb_cCvDataTypeInt3.define_constant("Fmt", (int)cv::DataType<int3>::fmt);
  rb_cCvDataTypeInt3.define_constant("Type", (int)cv::DataType<int3>::type);

  Rice::Data_Type<cv::DataType<int4>> rb_cCvDataTypeInt4 = define_class_under<cv::DataType<int4>>(rb_mCv, "DataTypeInt4").
    define_constructor(Constructor<cv::DataType<int4>>());

  rb_cCvDataTypeInt4.define_constant("Generic_type", (int)cv::DataType<int4>::generic_type);
  rb_cCvDataTypeInt4.define_constant("Depth", (int)cv::DataType<int4>::depth);
  rb_cCvDataTypeInt4.define_constant("Channels", (int)cv::DataType<int4>::channels);
  rb_cCvDataTypeInt4.define_constant("Fmt", (int)cv::DataType<int4>::fmt);
  rb_cCvDataTypeInt4.define_constant("Type", (int)cv::DataType<int4>::type);

  Rice::Data_Type<cv::DataType<uint1>> rb_cCvDataTypeUint1 = define_class_under<cv::DataType<uint1>>(rb_mCv, "DataTypeUint1").
    define_constructor(Constructor<cv::DataType<uint1>>());

  rb_cCvDataTypeUint1.define_constant("Generic_type", (int)cv::DataType<uint1>::generic_type);
  rb_cCvDataTypeUint1.define_constant("Depth", (int)cv::DataType<uint1>::depth);
  rb_cCvDataTypeUint1.define_constant("Channels", (int)cv::DataType<uint1>::channels);
  rb_cCvDataTypeUint1.define_constant("Fmt", (int)cv::DataType<uint1>::fmt);
  rb_cCvDataTypeUint1.define_constant("Type", (int)cv::DataType<uint1>::type);

  Rice::Data_Type<cv::DataType<uint2>> rb_cCvDataTypeUint2 = define_class_under<cv::DataType<uint2>>(rb_mCv, "DataTypeUint2").
    define_constructor(Constructor<cv::DataType<uint2>>());

  rb_cCvDataTypeUint2.define_constant("Generic_type", (int)cv::DataType<uint2>::generic_type);
  rb_cCvDataTypeUint2.define_constant("Depth", (int)cv::DataType<uint2>::depth);
  rb_cCvDataTypeUint2.define_constant("Channels", (int)cv::DataType<uint2>::channels);
  rb_cCvDataTypeUint2.define_constant("Fmt", (int)cv::DataType<uint2>::fmt);
  rb_cCvDataTypeUint2.define_constant("Type", (int)cv::DataType<uint2>::type);

  Rice::Data_Type<cv::DataType<uint3>> rb_cCvDataTypeUint3 = define_class_under<cv::DataType<uint3>>(rb_mCv, "DataTypeUint3").
    define_constructor(Constructor<cv::DataType<uint3>>());

  rb_cCvDataTypeUint3.define_constant("Generic_type", (int)cv::DataType<uint3>::generic_type);
  rb_cCvDataTypeUint3.define_constant("Depth", (int)cv::DataType<uint3>::depth);
  rb_cCvDataTypeUint3.define_constant("Channels", (int)cv::DataType<uint3>::channels);
  rb_cCvDataTypeUint3.define_constant("Fmt", (int)cv::DataType<uint3>::fmt);
  rb_cCvDataTypeUint3.define_constant("Type", (int)cv::DataType<uint3>::type);

  Rice::Data_Type<cv::DataType<uint4>> rb_cCvDataTypeUint4 = define_class_under<cv::DataType<uint4>>(rb_mCv, "DataTypeUint4").
    define_constructor(Constructor<cv::DataType<uint4>>());

  rb_cCvDataTypeUint4.define_constant("Generic_type", (int)cv::DataType<uint4>::generic_type);
  rb_cCvDataTypeUint4.define_constant("Depth", (int)cv::DataType<uint4>::depth);
  rb_cCvDataTypeUint4.define_constant("Channels", (int)cv::DataType<uint4>::channels);
  rb_cCvDataTypeUint4.define_constant("Fmt", (int)cv::DataType<uint4>::fmt);
  rb_cCvDataTypeUint4.define_constant("Type", (int)cv::DataType<uint4>::type);

  Rice::Data_Type<cv::DataType<float1>> rb_cCvDataTypeFloat1 = define_class_under<cv::DataType<float1>>(rb_mCv, "DataTypeFloat1").
    define_constructor(Constructor<cv::DataType<float1>>());

  rb_cCvDataTypeFloat1.define_constant("Generic_type", (int)cv::DataType<float1>::generic_type);
  rb_cCvDataTypeFloat1.define_constant("Depth", (int)cv::DataType<float1>::depth);
  rb_cCvDataTypeFloat1.define_constant("Channels", (int)cv::DataType<float1>::channels);
  rb_cCvDataTypeFloat1.define_constant("Fmt", (int)cv::DataType<float1>::fmt);
  rb_cCvDataTypeFloat1.define_constant("Type", (int)cv::DataType<float1>::type);

  Rice::Data_Type<cv::DataType<float2>> rb_cCvDataTypeFloat2 = define_class_under<cv::DataType<float2>>(rb_mCv, "DataTypeFloat2").
    define_constructor(Constructor<cv::DataType<float2>>());

  rb_cCvDataTypeFloat2.define_constant("Generic_type", (int)cv::DataType<float2>::generic_type);
  rb_cCvDataTypeFloat2.define_constant("Depth", (int)cv::DataType<float2>::depth);
  rb_cCvDataTypeFloat2.define_constant("Channels", (int)cv::DataType<float2>::channels);
  rb_cCvDataTypeFloat2.define_constant("Fmt", (int)cv::DataType<float2>::fmt);
  rb_cCvDataTypeFloat2.define_constant("Type", (int)cv::DataType<float2>::type);

  Rice::Data_Type<cv::DataType<float3>> rb_cCvDataTypeFloat3 = define_class_under<cv::DataType<float3>>(rb_mCv, "DataTypeFloat3").
    define_constructor(Constructor<cv::DataType<float3>>());

  rb_cCvDataTypeFloat3.define_constant("Generic_type", (int)cv::DataType<float3>::generic_type);
  rb_cCvDataTypeFloat3.define_constant("Depth", (int)cv::DataType<float3>::depth);
  rb_cCvDataTypeFloat3.define_constant("Channels", (int)cv::DataType<float3>::channels);
  rb_cCvDataTypeFloat3.define_constant("Fmt", (int)cv::DataType<float3>::fmt);
  rb_cCvDataTypeFloat3.define_constant("Type", (int)cv::DataType<float3>::type);

  Rice::Data_Type<cv::DataType<float4>> rb_cCvDataTypeFloat4 = define_class_under<cv::DataType<float4>>(rb_mCv, "DataTypeFloat4").
    define_constructor(Constructor<cv::DataType<float4>>());

  rb_cCvDataTypeFloat4.define_constant("Generic_type", (int)cv::DataType<float4>::generic_type);
  rb_cCvDataTypeFloat4.define_constant("Depth", (int)cv::DataType<float4>::depth);
  rb_cCvDataTypeFloat4.define_constant("Channels", (int)cv::DataType<float4>::channels);
  rb_cCvDataTypeFloat4.define_constant("Fmt", (int)cv::DataType<float4>::fmt);
  rb_cCvDataTypeFloat4.define_constant("Type", (int)cv::DataType<float4>::type);

  Rice::Data_Type<cv::DataType<double1>> rb_cCvDataTypeDouble1 = define_class_under<cv::DataType<double1>>(rb_mCv, "DataTypeDouble1").
    define_constructor(Constructor<cv::DataType<double1>>());

  rb_cCvDataTypeDouble1.define_constant("Generic_type", (int)cv::DataType<double1>::generic_type);
  rb_cCvDataTypeDouble1.define_constant("Depth", (int)cv::DataType<double1>::depth);
  rb_cCvDataTypeDouble1.define_constant("Channels", (int)cv::DataType<double1>::channels);
  rb_cCvDataTypeDouble1.define_constant("Fmt", (int)cv::DataType<double1>::fmt);
  rb_cCvDataTypeDouble1.define_constant("Type", (int)cv::DataType<double1>::type);

  Rice::Data_Type<cv::DataType<double2>> rb_cCvDataTypeDouble2 = define_class_under<cv::DataType<double2>>(rb_mCv, "DataTypeDouble2").
    define_constructor(Constructor<cv::DataType<double2>>());

  rb_cCvDataTypeDouble2.define_constant("Generic_type", (int)cv::DataType<double2>::generic_type);
  rb_cCvDataTypeDouble2.define_constant("Depth", (int)cv::DataType<double2>::depth);
  rb_cCvDataTypeDouble2.define_constant("Channels", (int)cv::DataType<double2>::channels);
  rb_cCvDataTypeDouble2.define_constant("Fmt", (int)cv::DataType<double2>::fmt);
  rb_cCvDataTypeDouble2.define_constant("Type", (int)cv::DataType<double2>::type);

  Rice::Data_Type<cv::DataType<double3>> rb_cCvDataTypeDouble3 = define_class_under<cv::DataType<double3>>(rb_mCv, "DataTypeDouble3").
    define_constructor(Constructor<cv::DataType<double3>>());

  rb_cCvDataTypeDouble3.define_constant("Generic_type", (int)cv::DataType<double3>::generic_type);
  rb_cCvDataTypeDouble3.define_constant("Depth", (int)cv::DataType<double3>::depth);
  rb_cCvDataTypeDouble3.define_constant("Channels", (int)cv::DataType<double3>::channels);
  rb_cCvDataTypeDouble3.define_constant("Fmt", (int)cv::DataType<double3>::fmt);
  rb_cCvDataTypeDouble3.define_constant("Type", (int)cv::DataType<double3>::type);

  Rice::Data_Type<cv::DataType<double4>> rb_cCvDataTypeDouble4 = define_class_under<cv::DataType<double4>>(rb_mCv, "DataTypeDouble4").
    define_constructor(Constructor<cv::DataType<double4>>());

  rb_cCvDataTypeDouble4.define_constant("Generic_type", (int)cv::DataType<double4>::generic_type);
  rb_cCvDataTypeDouble4.define_constant("Depth", (int)cv::DataType<double4>::depth);
  rb_cCvDataTypeDouble4.define_constant("Channels", (int)cv::DataType<double4>::channels);
  rb_cCvDataTypeDouble4.define_constant("Fmt", (int)cv::DataType<double4>::fmt);
  rb_cCvDataTypeDouble4.define_constant("Type", (int)cv::DataType<double4>::type);

  Rice::Data_Type<cv::DataType<char1>> rb_cCvDataTypeChar1 = define_class_under<cv::DataType<char1>>(rb_mCv, "DataTypeChar1").
    define_constructor(Constructor<cv::DataType<char1>>());

  rb_cCvDataTypeChar1.define_constant("Generic_type", (int)cv::DataType<char1>::generic_type);
  rb_cCvDataTypeChar1.define_constant("Depth", (int)cv::DataType<char1>::depth);
  rb_cCvDataTypeChar1.define_constant("Channels", (int)cv::DataType<char1>::channels);
  rb_cCvDataTypeChar1.define_constant("Fmt", (int)cv::DataType<char1>::fmt);
  rb_cCvDataTypeChar1.define_constant("Type", (int)cv::DataType<char1>::type);

  Rice::Data_Type<cv::DataType<char2>> rb_cCvDataTypeChar2 = define_class_under<cv::DataType<char2>>(rb_mCv, "DataTypeChar2").
    define_constructor(Constructor<cv::DataType<char2>>());

  rb_cCvDataTypeChar2.define_constant("Generic_type", (int)cv::DataType<char2>::generic_type);
  rb_cCvDataTypeChar2.define_constant("Depth", (int)cv::DataType<char2>::depth);
  rb_cCvDataTypeChar2.define_constant("Channels", (int)cv::DataType<char2>::channels);
  rb_cCvDataTypeChar2.define_constant("Fmt", (int)cv::DataType<char2>::fmt);
  rb_cCvDataTypeChar2.define_constant("Type", (int)cv::DataType<char2>::type);

  Rice::Data_Type<cv::DataType<char3>> rb_cCvDataTypeChar3 = define_class_under<cv::DataType<char3>>(rb_mCv, "DataTypeChar3").
    define_constructor(Constructor<cv::DataType<char3>>());

  rb_cCvDataTypeChar3.define_constant("Generic_type", (int)cv::DataType<char3>::generic_type);
  rb_cCvDataTypeChar3.define_constant("Depth", (int)cv::DataType<char3>::depth);
  rb_cCvDataTypeChar3.define_constant("Channels", (int)cv::DataType<char3>::channels);
  rb_cCvDataTypeChar3.define_constant("Fmt", (int)cv::DataType<char3>::fmt);
  rb_cCvDataTypeChar3.define_constant("Type", (int)cv::DataType<char3>::type);

  Rice::Data_Type<cv::DataType<char4>> rb_cCvDataTypeChar4 = define_class_under<cv::DataType<char4>>(rb_mCv, "DataTypeChar4").
    define_constructor(Constructor<cv::DataType<char4>>());

  rb_cCvDataTypeChar4.define_constant("Generic_type", (int)cv::DataType<char4>::generic_type);
  rb_cCvDataTypeChar4.define_constant("Depth", (int)cv::DataType<char4>::depth);
  rb_cCvDataTypeChar4.define_constant("Channels", (int)cv::DataType<char4>::channels);
  rb_cCvDataTypeChar4.define_constant("Fmt", (int)cv::DataType<char4>::fmt);
  rb_cCvDataTypeChar4.define_constant("Type", (int)cv::DataType<char4>::type);
}