#include "matx-rb.ipp"

void Init_Core_Matx()
{
  Module rb_mCv = define_module("Cv");

  Rice::Data_Type<cv::Matx_AddOp> rb_cCvMatxAddOp = define_class_under<cv::Matx_AddOp>(rb_mCv, "MatxAddOp").
    define_constructor(Constructor<cv::Matx_AddOp>()).
    define_constructor(Constructor<cv::Matx_AddOp, const cv::Matx_AddOp&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::Matx_SubOp> rb_cCvMatxSubOp = define_class_under<cv::Matx_SubOp>(rb_mCv, "MatxSubOp").
    define_constructor(Constructor<cv::Matx_SubOp>()).
    define_constructor(Constructor<cv::Matx_SubOp, const cv::Matx_SubOp&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::Matx_ScaleOp> rb_cCvMatxScaleOp = define_class_under<cv::Matx_ScaleOp>(rb_mCv, "MatxScaleOp").
    define_constructor(Constructor<cv::Matx_ScaleOp>()).
    define_constructor(Constructor<cv::Matx_ScaleOp, const cv::Matx_ScaleOp&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::Matx_MulOp> rb_cCvMatxMulOp = define_class_under<cv::Matx_MulOp>(rb_mCv, "MatxMulOp").
    define_constructor(Constructor<cv::Matx_MulOp>()).
    define_constructor(Constructor<cv::Matx_MulOp, const cv::Matx_MulOp&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::Matx_DivOp> rb_cCvMatxDivOp = define_class_under<cv::Matx_DivOp>(rb_mCv, "MatxDivOp").
    define_constructor(Constructor<cv::Matx_DivOp>()).
    define_constructor(Constructor<cv::Matx_DivOp, const cv::Matx_DivOp&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::Matx_MatMulOp> rb_cCvMatxMatMulOp = define_class_under<cv::Matx_MatMulOp>(rb_mCv, "MatxMatMulOp").
    define_constructor(Constructor<cv::Matx_MatMulOp>()).
    define_constructor(Constructor<cv::Matx_MatMulOp, const cv::Matx_MatMulOp&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::Matx_TOp> rb_cCvMatxTOp = define_class_under<cv::Matx_TOp>(rb_mCv, "MatxTOp").
    define_constructor(Constructor<cv::Matx_TOp>()).
    define_constructor(Constructor<cv::Matx_TOp, const cv::Matx_TOp&>(),
      Arg("arg_0"));

  Rice::Data_Type<cv::Matx<float, 1, 2>> rb_cMatx12f = define_class_under<cv::Matx<float, 1, 2>>(rb_mCv, "Matx12f").
    define(&Matx_builder<Data_Type<cv::Matx<float, 1, 2>>, float, 1, 2>);

  Rice::Data_Type<cv::Matx<double, 1, 2>> rb_cMatx12d = define_class_under<cv::Matx<double, 1, 2>>(rb_mCv, "Matx12d").
    define(&Matx_builder<Data_Type<cv::Matx<double, 1, 2>>, double, 1, 2>);

  Rice::Data_Type<cv::Matx<float, 1, 3>> rb_cMatx13f = define_class_under<cv::Matx<float, 1, 3>>(rb_mCv, "Matx13f").
    define(&Matx_builder<Data_Type<cv::Matx<float, 1, 3>>, float, 1, 3>);

  Rice::Data_Type<cv::Matx<double, 1, 3>> rb_cMatx13d = define_class_under<cv::Matx<double, 1, 3>>(rb_mCv, "Matx13d").
    define(&Matx_builder<Data_Type<cv::Matx<double, 1, 3>>, double, 1, 3>);

  Rice::Data_Type<cv::Matx<float, 1, 4>> rb_cMatx14f = define_class_under<cv::Matx<float, 1, 4>>(rb_mCv, "Matx14f").
    define(&Matx_builder<Data_Type<cv::Matx<float, 1, 4>>, float, 1, 4>);

  Rice::Data_Type<cv::Matx<double, 1, 4>> rb_cMatx14d = define_class_under<cv::Matx<double, 1, 4>>(rb_mCv, "Matx14d").
    define(&Matx_builder<Data_Type<cv::Matx<double, 1, 4>>, double, 1, 4>);

  Rice::Data_Type<cv::Matx<float, 1, 6>> rb_cMatx16f = define_class_under<cv::Matx<float, 1, 6>>(rb_mCv, "Matx16f").
    define(&Matx_builder<Data_Type<cv::Matx<float, 1, 6>>, float, 1, 6>);

  Rice::Data_Type<cv::Matx<double, 1, 6>> rb_cMatx16d = define_class_under<cv::Matx<double, 1, 6>>(rb_mCv, "Matx16d").
    define(&Matx_builder<Data_Type<cv::Matx<double, 1, 6>>, double, 1, 6>);

  Rice::Data_Type<cv::Matx<float, 2, 1>> rb_cMatx21f = define_class_under<cv::Matx<float, 2, 1>>(rb_mCv, "Matx21f").
    define(&Matx_builder<Data_Type<cv::Matx<float, 2, 1>>, float, 2, 1>);

  Rice::Data_Type<cv::Matx<double, 2, 1>> rb_cMatx21d = define_class_under<cv::Matx<double, 2, 1>>(rb_mCv, "Matx21d").
    define(&Matx_builder<Data_Type<cv::Matx<double, 2, 1>>, double, 2, 1>);

  Rice::Data_Type<cv::Matx<float, 3, 1>> rb_cMatx31f = define_class_under<cv::Matx<float, 3, 1>>(rb_mCv, "Matx31f").
    define(&Matx_builder<Data_Type<cv::Matx<float, 3, 1>>, float, 3, 1>);

  Rice::Data_Type<cv::Matx<double, 3, 1>> rb_cMatx31d = define_class_under<cv::Matx<double, 3, 1>>(rb_mCv, "Matx31d").
    define(&Matx_builder<Data_Type<cv::Matx<double, 3, 1>>, double, 3, 1>);

  Rice::Data_Type<cv::Matx<float, 4, 1>> rb_cMatx41f = define_class_under<cv::Matx<float, 4, 1>>(rb_mCv, "Matx41f").
    define(&Matx_builder<Data_Type<cv::Matx<float, 4, 1>>, float, 4, 1>);

  Rice::Data_Type<cv::Matx<double, 4, 1>> rb_cMatx41d = define_class_under<cv::Matx<double, 4, 1>>(rb_mCv, "Matx41d").
    define(&Matx_builder<Data_Type<cv::Matx<double, 4, 1>>, double, 4, 1>);

  Rice::Data_Type<cv::Matx<float, 6, 1>> rb_cMatx61f = define_class_under<cv::Matx<float, 6, 1>>(rb_mCv, "Matx61f").
    define(&Matx_builder<Data_Type<cv::Matx<float, 6, 1>>, float, 6, 1>);

  Rice::Data_Type<cv::Matx<double, 6, 1>> rb_cMatx61d = define_class_under<cv::Matx<double, 6, 1>>(rb_mCv, "Matx61d").
    define(&Matx_builder<Data_Type<cv::Matx<double, 6, 1>>, double, 6, 1>);

  Rice::Data_Type<cv::Matx<float, 2, 2>> rb_cMatx22f = define_class_under<cv::Matx<float, 2, 2>>(rb_mCv, "Matx22f").
    define(&Matx_builder<Data_Type<cv::Matx<float, 2, 2>>, float, 2, 2>);

  Rice::Data_Type<cv::Matx<double, 2, 2>> rb_cMatx22d = define_class_under<cv::Matx<double, 2, 2>>(rb_mCv, "Matx22d").
    define(&Matx_builder<Data_Type<cv::Matx<double, 2, 2>>, double, 2, 2>);

  Rice::Data_Type<cv::Matx<float, 2, 3>> rb_cMatx23f = define_class_under<cv::Matx<float, 2, 3>>(rb_mCv, "Matx23f").
    define(&Matx_builder<Data_Type<cv::Matx<float, 2, 3>>, float, 2, 3>);

  Rice::Data_Type<cv::Matx<double, 2, 3>> rb_cMatx23d = define_class_under<cv::Matx<double, 2, 3>>(rb_mCv, "Matx23d").
    define(&Matx_builder<Data_Type<cv::Matx<double, 2, 3>>, double, 2, 3>);

  Rice::Data_Type<cv::Matx<float, 3, 2>> rb_cMatx32f = define_class_under<cv::Matx<float, 3, 2>>(rb_mCv, "Matx32f").
    define(&Matx_builder<Data_Type<cv::Matx<float, 3, 2>>, float, 3, 2>);

  Rice::Data_Type<cv::Matx<double, 3, 2>> rb_cMatx32d = define_class_under<cv::Matx<double, 3, 2>>(rb_mCv, "Matx32d").
    define(&Matx_builder<Data_Type<cv::Matx<double, 3, 2>>, double, 3, 2>);

  Rice::Data_Type<cv::Matx<float, 3, 3>> rb_cMatx33f = define_class_under<cv::Matx<float, 3, 3>>(rb_mCv, "Matx33f").
    define(&Matx_builder<Data_Type<cv::Matx<float, 3, 3>>, float, 3, 3>);

  Rice::Data_Type<cv::Matx<double, 3, 3>> rb_cMatx33d = define_class_under<cv::Matx<double, 3, 3>>(rb_mCv, "Matx33d").
    define(&Matx_builder<Data_Type<cv::Matx<double, 3, 3>>, double, 3, 3>);

  Rice::Data_Type<cv::Matx<float, 3, 4>> rb_cMatx34f = define_class_under<cv::Matx<float, 3, 4>>(rb_mCv, "Matx34f").
    define(&Matx_builder<Data_Type<cv::Matx<float, 3, 4>>, float, 3, 4>);

  Rice::Data_Type<cv::Matx<double, 3, 4>> rb_cMatx34d = define_class_under<cv::Matx<double, 3, 4>>(rb_mCv, "Matx34d").
    define(&Matx_builder<Data_Type<cv::Matx<double, 3, 4>>, double, 3, 4>);

  Rice::Data_Type<cv::Matx<float, 4, 3>> rb_cMatx43f = define_class_under<cv::Matx<float, 4, 3>>(rb_mCv, "Matx43f").
    define(&Matx_builder<Data_Type<cv::Matx<float, 4, 3>>, float, 4, 3>);

  Rice::Data_Type<cv::Matx<double, 4, 3>> rb_cMatx43d = define_class_under<cv::Matx<double, 4, 3>>(rb_mCv, "Matx43d").
    define(&Matx_builder<Data_Type<cv::Matx<double, 4, 3>>, double, 4, 3>);

  Rice::Data_Type<cv::Matx<float, 4, 4>> rb_cMatx44f = define_class_under<cv::Matx<float, 4, 4>>(rb_mCv, "Matx44f").
    define(&Matx_builder<Data_Type<cv::Matx<float, 4, 4>>, float, 4, 4>);

  Rice::Data_Type<cv::Matx<double, 4, 4>> rb_cMatx44d = define_class_under<cv::Matx<double, 4, 4>>(rb_mCv, "Matx44d").
    define(&Matx_builder<Data_Type<cv::Matx<double, 4, 4>>, double, 4, 4>);

  Rice::Data_Type<cv::Matx<float, 6, 6>> rb_cMatx66f = define_class_under<cv::Matx<float, 6, 6>>(rb_mCv, "Matx66f").
    define(&Matx_builder<Data_Type<cv::Matx<float, 6, 6>>, float, 6, 6>);

  Rice::Data_Type<cv::Matx<double, 6, 6>> rb_cMatx66d = define_class_under<cv::Matx<double, 6, 6>>(rb_mCv, "Matx66d").
    define(&Matx_builder<Data_Type<cv::Matx<double, 6, 6>>, double, 6, 6>);

  Rice::Data_Type<cv::Matx<unsigned char, 2, 1>> rb_cMatxUnsignedChar21 = define_class_under<cv::Matx<unsigned char, 2, 1>>(rb_mCv, "MatxUnsignedChar21").
    define(&Matx_builder<Data_Type<cv::Matx<unsigned char, 2, 1>>, unsigned char, 2, 1>);
  Rice::Data_Type<cv::Vec<uchar, 2>> rb_cVec2b = define_class_under<cv::Vec<uchar, 2>, cv::Matx<unsigned char, 2, 1>>(rb_mCv, "Vec2b").
    define(&Vec_builder<Data_Type<cv::Vec<uchar, 2>>, unsigned char, 2>);

  Rice::Data_Type<cv::Matx<unsigned char, 3, 1>> rb_cMatxUnsignedChar31 = define_class_under<cv::Matx<unsigned char, 3, 1>>(rb_mCv, "MatxUnsignedChar31").
    define(&Matx_builder<Data_Type<cv::Matx<unsigned char, 3, 1>>, unsigned char, 3, 1>);
  Rice::Data_Type<cv::Vec<uchar, 3>> rb_cVec3b = define_class_under<cv::Vec<uchar, 3>, cv::Matx<unsigned char, 3, 1>>(rb_mCv, "Vec3b").
    define(&Vec_builder<Data_Type<cv::Vec<uchar, 3>>, unsigned char, 3>);

  Rice::Data_Type<cv::Matx<unsigned char, 4, 1>> rb_cMatxUnsignedChar41 = define_class_under<cv::Matx<unsigned char, 4, 1>>(rb_mCv, "MatxUnsignedChar41").
    define(&Matx_builder<Data_Type<cv::Matx<unsigned char, 4, 1>>, unsigned char, 4, 1>);
  Rice::Data_Type<cv::Vec<uchar, 4>> rb_cVec4b = define_class_under<cv::Vec<uchar, 4>, cv::Matx<unsigned char, 4, 1>>(rb_mCv, "Vec4b").
    define(&Vec_builder<Data_Type<cv::Vec<uchar, 4>>, unsigned char, 4>);

  Rice::Data_Type<cv::Matx<short, 2, 1>> rb_cMatxShort21 = define_class_under<cv::Matx<short, 2, 1>>(rb_mCv, "MatxShort21").
    define(&Matx_builder<Data_Type<cv::Matx<short, 2, 1>>, short, 2, 1>);
  Rice::Data_Type<cv::Vec<short, 2>> rb_cVec2s = define_class_under<cv::Vec<short, 2>, cv::Matx<short, 2, 1>>(rb_mCv, "Vec2s").
    define(&Vec_builder<Data_Type<cv::Vec<short, 2>>, short, 2>);

  Rice::Data_Type<cv::Matx<short, 3, 1>> rb_cMatxShort31 = define_class_under<cv::Matx<short, 3, 1>>(rb_mCv, "MatxShort31").
    define(&Matx_builder<Data_Type<cv::Matx<short, 3, 1>>, short, 3, 1>);
  Rice::Data_Type<cv::Vec<short, 3>> rb_cVec3s = define_class_under<cv::Vec<short, 3>, cv::Matx<short, 3, 1>>(rb_mCv, "Vec3s").
    define(&Vec_builder<Data_Type<cv::Vec<short, 3>>, short, 3>);

  Rice::Data_Type<cv::Matx<short, 4, 1>> rb_cMatxShort41 = define_class_under<cv::Matx<short, 4, 1>>(rb_mCv, "MatxShort41").
    define(&Matx_builder<Data_Type<cv::Matx<short, 4, 1>>, short, 4, 1>);
  Rice::Data_Type<cv::Vec<short, 4>> rb_cVec4s = define_class_under<cv::Vec<short, 4>, cv::Matx<short, 4, 1>>(rb_mCv, "Vec4s").
    define(&Vec_builder<Data_Type<cv::Vec<short, 4>>, short, 4>);

  Rice::Data_Type<cv::Matx<unsigned short, 2, 1>> rb_cMatxUnsignedShort21 = define_class_under<cv::Matx<unsigned short, 2, 1>>(rb_mCv, "MatxUnsignedShort21").
    define(&Matx_builder<Data_Type<cv::Matx<unsigned short, 2, 1>>, unsigned short, 2, 1>);
  Rice::Data_Type<cv::Vec<ushort, 2>> rb_cVec2w = define_class_under<cv::Vec<ushort, 2>, cv::Matx<unsigned short, 2, 1>>(rb_mCv, "Vec2w").
    define(&Vec_builder<Data_Type<cv::Vec<ushort, 2>>, unsigned short, 2>);

  Rice::Data_Type<cv::Matx<unsigned short, 3, 1>> rb_cMatxUnsignedShort31 = define_class_under<cv::Matx<unsigned short, 3, 1>>(rb_mCv, "MatxUnsignedShort31").
    define(&Matx_builder<Data_Type<cv::Matx<unsigned short, 3, 1>>, unsigned short, 3, 1>);
  Rice::Data_Type<cv::Vec<ushort, 3>> rb_cVec3w = define_class_under<cv::Vec<ushort, 3>, cv::Matx<unsigned short, 3, 1>>(rb_mCv, "Vec3w").
    define(&Vec_builder<Data_Type<cv::Vec<ushort, 3>>, unsigned short, 3>);

  Rice::Data_Type<cv::Matx<unsigned short, 4, 1>> rb_cMatxUnsignedShort41 = define_class_under<cv::Matx<unsigned short, 4, 1>>(rb_mCv, "MatxUnsignedShort41").
    define(&Matx_builder<Data_Type<cv::Matx<unsigned short, 4, 1>>, unsigned short, 4, 1>);
  Rice::Data_Type<cv::Vec<ushort, 4>> rb_cVec4w = define_class_under<cv::Vec<ushort, 4>, cv::Matx<unsigned short, 4, 1>>(rb_mCv, "Vec4w").
    define(&Vec_builder<Data_Type<cv::Vec<ushort, 4>>, unsigned short, 4>);

  Rice::Data_Type<cv::Matx<int, 2, 1>> rb_cMatxInt21 = define_class_under<cv::Matx<int, 2, 1>>(rb_mCv, "MatxInt21").
    define(&Matx_builder<Data_Type<cv::Matx<int, 2, 1>>, int, 2, 1>);
  Rice::Data_Type<cv::Vec<int, 2>> rb_cVec2i = define_class_under<cv::Vec<int, 2>, cv::Matx<int, 2, 1>>(rb_mCv, "Vec2i").
    define(&Vec_builder<Data_Type<cv::Vec<int, 2>>, int, 2>);

  Rice::Data_Type<cv::Matx<int, 3, 1>> rb_cMatxInt31 = define_class_under<cv::Matx<int, 3, 1>>(rb_mCv, "MatxInt31").
    define(&Matx_builder<Data_Type<cv::Matx<int, 3, 1>>, int, 3, 1>);
  Rice::Data_Type<cv::Vec<int, 3>> rb_cVec3i = define_class_under<cv::Vec<int, 3>, cv::Matx<int, 3, 1>>(rb_mCv, "Vec3i").
    define(&Vec_builder<Data_Type<cv::Vec<int, 3>>, int, 3>);

  Rice::Data_Type<cv::Matx<int, 4, 1>> rb_cMatxInt41 = define_class_under<cv::Matx<int, 4, 1>>(rb_mCv, "MatxInt41").
    define(&Matx_builder<Data_Type<cv::Matx<int, 4, 1>>, int, 4, 1>);
  Rice::Data_Type<cv::Vec<int, 4>> rb_cVec4i = define_class_under<cv::Vec<int, 4>, cv::Matx<int, 4, 1>>(rb_mCv, "Vec4i").
    define(&Vec_builder<Data_Type<cv::Vec<int, 4>>, int, 4>);

  Rice::Data_Type<cv::Matx<int, 6, 1>> rb_cMatxInt61 = define_class_under<cv::Matx<int, 6, 1>>(rb_mCv, "MatxInt61").
    define(&Matx_builder<Data_Type<cv::Matx<int, 6, 1>>, int, 6, 1>);
  Rice::Data_Type<cv::Vec<int, 6>> rb_cVec6i = define_class_under<cv::Vec<int, 6>, cv::Matx<int, 6, 1>>(rb_mCv, "Vec6i").
    define(&Vec_builder<Data_Type<cv::Vec<int, 6>>, int, 6>);

  Rice::Data_Type<cv::Matx<int, 8, 1>> rb_cMatxInt81 = define_class_under<cv::Matx<int, 8, 1>>(rb_mCv, "MatxInt81").
    define(&Matx_builder<Data_Type<cv::Matx<int, 8, 1>>, int, 8, 1>);
  Rice::Data_Type<cv::Vec<int, 8>> rb_cVec8i = define_class_under<cv::Vec<int, 8>, cv::Matx<int, 8, 1>>(rb_mCv, "Vec8i").
    define(&Vec_builder<Data_Type<cv::Vec<int, 8>>, int, 8>);

  Rice::Data_Type<cv::Vec<float, 2>> rb_cVec2f = define_class_under<cv::Vec<float, 2>, cv::Matx<float, 2, 1>>(rb_mCv, "Vec2f").
    define(&Vec_builder<Data_Type<cv::Vec<float, 2>>, float, 2>);

  Rice::Data_Type<cv::Vec<float, 3>> rb_cVec3f = define_class_under<cv::Vec<float, 3>, cv::Matx<float, 3, 1>>(rb_mCv, "Vec3f").
    define(&Vec_builder<Data_Type<cv::Vec<float, 3>>, float, 3>);

  Rice::Data_Type<cv::Vec<float, 4>> rb_cVec4f = define_class_under<cv::Vec<float, 4>, cv::Matx<float, 4, 1>>(rb_mCv, "Vec4f").
    define(&Vec_builder<Data_Type<cv::Vec<float, 4>>, float, 4>);

  Rice::Data_Type<cv::Vec<float, 6>> rb_cVec6f = define_class_under<cv::Vec<float, 6>, cv::Matx<float, 6, 1>>(rb_mCv, "Vec6f").
    define(&Vec_builder<Data_Type<cv::Vec<float, 6>>, float, 6>);

  Rice::Data_Type<cv::Vec<double, 2>> rb_cVec2d = define_class_under<cv::Vec<double, 2>, cv::Matx<double, 2, 1>>(rb_mCv, "Vec2d").
    define(&Vec_builder<Data_Type<cv::Vec<double, 2>>, double, 2>);

  Rice::Data_Type<cv::Vec<double, 3>> rb_cVec3d = define_class_under<cv::Vec<double, 3>, cv::Matx<double, 3, 1>>(rb_mCv, "Vec3d").
    define(&Vec_builder<Data_Type<cv::Vec<double, 3>>, double, 3>);

  Rice::Data_Type<cv::Vec<double, 4>> rb_cVec4d = define_class_under<cv::Vec<double, 4>, cv::Matx<double, 4, 1>>(rb_mCv, "Vec4d").
    define(&Vec_builder<Data_Type<cv::Vec<double, 4>>, double, 4>);

  Rice::Data_Type<cv::Vec<double, 6>> rb_cVec6d = define_class_under<cv::Vec<double, 6>, cv::Matx<double, 6, 1>>(rb_mCv, "Vec6d").
    define(&Vec_builder<Data_Type<cv::Vec<double, 6>>, double, 6>);
}