#include <opencv2/core.hpp>
#include <opencv2/core/matx.hpp>
#include "matx-rb.hpp"
#include "matx-rb.ipp"

using namespace Rice;

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

  Rice::Data_Type<cv::Matx<float, 1, 2>> rb_cMatx12f = Matx_instantiate<float, 1, 2>(rb_mCv, "Matx12f");

  Rice::Data_Type<cv::Matx<double, 1, 2>> rb_cMatx12d = Matx_instantiate<double, 1, 2>(rb_mCv, "Matx12d");

  Rice::Data_Type<cv::Matx<float, 1, 3>> rb_cMatx13f = Matx_instantiate<float, 1, 3>(rb_mCv, "Matx13f");

  Rice::Data_Type<cv::Matx<double, 1, 3>> rb_cMatx13d = Matx_instantiate<double, 1, 3>(rb_mCv, "Matx13d");

  Rice::Data_Type<cv::Matx<float, 1, 4>> rb_cMatx14f = Matx_instantiate<float, 1, 4>(rb_mCv, "Matx14f");

  Rice::Data_Type<cv::Matx<double, 1, 4>> rb_cMatx14d = Matx_instantiate<double, 1, 4>(rb_mCv, "Matx14d");

  Rice::Data_Type<cv::Matx<float, 1, 6>> rb_cMatx16f = Matx_instantiate<float, 1, 6>(rb_mCv, "Matx16f");

  Rice::Data_Type<cv::Matx<double, 1, 6>> rb_cMatx16d = Matx_instantiate<double, 1, 6>(rb_mCv, "Matx16d");

  Rice::Data_Type<cv::Matx<float, 2, 1>> rb_cMatx21f = Matx_instantiate<float, 2, 1>(rb_mCv, "Matx21f");

  Rice::Data_Type<cv::Matx<double, 2, 1>> rb_cMatx21d = Matx_instantiate<double, 2, 1>(rb_mCv, "Matx21d");

  Rice::Data_Type<cv::Matx<float, 3, 1>> rb_cMatx31f = Matx_instantiate<float, 3, 1>(rb_mCv, "Matx31f");

  Rice::Data_Type<cv::Matx<double, 3, 1>> rb_cMatx31d = Matx_instantiate<double, 3, 1>(rb_mCv, "Matx31d");

  Rice::Data_Type<cv::Matx<float, 4, 1>> rb_cMatx41f = Matx_instantiate<float, 4, 1>(rb_mCv, "Matx41f");

  Rice::Data_Type<cv::Matx<double, 4, 1>> rb_cMatx41d = Matx_instantiate<double, 4, 1>(rb_mCv, "Matx41d");

  Rice::Data_Type<cv::Matx<float, 6, 1>> rb_cMatx61f = Matx_instantiate<float, 6, 1>(rb_mCv, "Matx61f");

  Rice::Data_Type<cv::Matx<double, 6, 1>> rb_cMatx61d = Matx_instantiate<double, 6, 1>(rb_mCv, "Matx61d");

  Rice::Data_Type<cv::Matx<float, 2, 2>> rb_cMatx22f = Matx_instantiate<float, 2, 2>(rb_mCv, "Matx22f");

  Rice::Data_Type<cv::Matx<double, 2, 2>> rb_cMatx22d = Matx_instantiate<double, 2, 2>(rb_mCv, "Matx22d");

  Rice::Data_Type<cv::Matx<float, 2, 3>> rb_cMatx23f = Matx_instantiate<float, 2, 3>(rb_mCv, "Matx23f");

  Rice::Data_Type<cv::Matx<double, 2, 3>> rb_cMatx23d = Matx_instantiate<double, 2, 3>(rb_mCv, "Matx23d");

  Rice::Data_Type<cv::Matx<float, 3, 2>> rb_cMatx32f = Matx_instantiate<float, 3, 2>(rb_mCv, "Matx32f");

  Rice::Data_Type<cv::Matx<double, 3, 2>> rb_cMatx32d = Matx_instantiate<double, 3, 2>(rb_mCv, "Matx32d");

  Rice::Data_Type<cv::Matx<float, 3, 3>> rb_cMatx33f = Matx_instantiate<float, 3, 3>(rb_mCv, "Matx33f");

  Rice::Data_Type<cv::Matx<double, 3, 3>> rb_cMatx33d = Matx_instantiate<double, 3, 3>(rb_mCv, "Matx33d");

  Rice::Data_Type<cv::Matx<float, 3, 4>> rb_cMatx34f = Matx_instantiate<float, 3, 4>(rb_mCv, "Matx34f");

  Rice::Data_Type<cv::Matx<double, 3, 4>> rb_cMatx34d = Matx_instantiate<double, 3, 4>(rb_mCv, "Matx34d");

  Rice::Data_Type<cv::Matx<float, 4, 3>> rb_cMatx43f = Matx_instantiate<float, 4, 3>(rb_mCv, "Matx43f");

  Rice::Data_Type<cv::Matx<double, 4, 3>> rb_cMatx43d = Matx_instantiate<double, 4, 3>(rb_mCv, "Matx43d");

  Rice::Data_Type<cv::Matx<float, 4, 4>> rb_cMatx44f = Matx_instantiate<float, 4, 4>(rb_mCv, "Matx44f");

  Rice::Data_Type<cv::Matx<double, 4, 4>> rb_cMatx44d = Matx_instantiate<double, 4, 4>(rb_mCv, "Matx44d");

  Rice::Data_Type<cv::Matx<float, 6, 6>> rb_cMatx66f = Matx_instantiate<float, 6, 6>(rb_mCv, "Matx66f");

  Rice::Data_Type<cv::Matx<double, 6, 6>> rb_cMatx66d = Matx_instantiate<double, 6, 6>(rb_mCv, "Matx66d");

  Rice::Data_Type<cv::Matx<unsigned char, 2, 1>> rb_cMatx21b = Matx_instantiate<unsigned char, 2, 1>(rb_mCv, "Matx21b");
  Rice::Data_Type<cv::Vec<uchar, 2>> rb_cVec2b = Vec_instantiate<unsigned char, 2>(rb_mCv, "Vec2b");

  Rice::Data_Type<cv::Matx<unsigned char, 3, 1>> rb_cMatx31b = Matx_instantiate<unsigned char, 3, 1>(rb_mCv, "Matx31b");
  Rice::Data_Type<cv::Vec<uchar, 3>> rb_cVec3b = Vec_instantiate<unsigned char, 3>(rb_mCv, "Vec3b");

  Rice::Data_Type<cv::Matx<unsigned char, 4, 1>> rb_cMatx41b = Matx_instantiate<unsigned char, 4, 1>(rb_mCv, "Matx41b");
  Rice::Data_Type<cv::Vec<uchar, 4>> rb_cVec4b = Vec_instantiate<unsigned char, 4>(rb_mCv, "Vec4b");

  Rice::Data_Type<cv::Matx<short, 2, 1>> rb_cMatx21s = Matx_instantiate<short, 2, 1>(rb_mCv, "Matx21s");
  Rice::Data_Type<cv::Vec<short, 2>> rb_cVec2s = Vec_instantiate<short, 2>(rb_mCv, "Vec2s");

  Rice::Data_Type<cv::Matx<short, 3, 1>> rb_cMatx31s = Matx_instantiate<short, 3, 1>(rb_mCv, "Matx31s");
  Rice::Data_Type<cv::Vec<short, 3>> rb_cVec3s = Vec_instantiate<short, 3>(rb_mCv, "Vec3s");

  Rice::Data_Type<cv::Matx<short, 4, 1>> rb_cMatx41s = Matx_instantiate<short, 4, 1>(rb_mCv, "Matx41s");
  Rice::Data_Type<cv::Vec<short, 4>> rb_cVec4s = Vec_instantiate<short, 4>(rb_mCv, "Vec4s");

  Rice::Data_Type<cv::Matx<unsigned short, 2, 1>> rb_cMatx21w = Matx_instantiate<unsigned short, 2, 1>(rb_mCv, "Matx21w");
  Rice::Data_Type<cv::Vec<ushort, 2>> rb_cVec2w = Vec_instantiate<unsigned short, 2>(rb_mCv, "Vec2w");

  Rice::Data_Type<cv::Matx<unsigned short, 3, 1>> rb_cMatx31w = Matx_instantiate<unsigned short, 3, 1>(rb_mCv, "Matx31w");
  Rice::Data_Type<cv::Vec<ushort, 3>> rb_cVec3w = Vec_instantiate<unsigned short, 3>(rb_mCv, "Vec3w");

  Rice::Data_Type<cv::Matx<unsigned short, 4, 1>> rb_cMatx41w = Matx_instantiate<unsigned short, 4, 1>(rb_mCv, "Matx41w");
  Rice::Data_Type<cv::Vec<ushort, 4>> rb_cVec4w = Vec_instantiate<unsigned short, 4>(rb_mCv, "Vec4w");

  Rice::Data_Type<cv::Matx<int, 2, 1>> rb_cMatx21i = Matx_instantiate<int, 2, 1>(rb_mCv, "Matx21i");
  Rice::Data_Type<cv::Vec<int, 2>> rb_cVec2i = Vec_instantiate<int, 2>(rb_mCv, "Vec2i");

  Rice::Data_Type<cv::Matx<int, 3, 1>> rb_cMatx31i = Matx_instantiate<int, 3, 1>(rb_mCv, "Matx31i");
  Rice::Data_Type<cv::Vec<int, 3>> rb_cVec3i = Vec_instantiate<int, 3>(rb_mCv, "Vec3i");

  Rice::Data_Type<cv::Matx<int, 4, 1>> rb_cMatx41i = Matx_instantiate<int, 4, 1>(rb_mCv, "Matx41i");
  Rice::Data_Type<cv::Vec<int, 4>> rb_cVec4i = Vec_instantiate<int, 4>(rb_mCv, "Vec4i");

  Rice::Data_Type<cv::Matx<int, 6, 1>> rb_cMatx61i = Matx_instantiate<int, 6, 1>(rb_mCv, "Matx61i");
  Rice::Data_Type<cv::Vec<int, 6>> rb_cVec6i = Vec_instantiate<int, 6>(rb_mCv, "Vec6i");

  Rice::Data_Type<cv::Matx<int, 8, 1>> rb_cMatx81i = Matx_instantiate<int, 8, 1>(rb_mCv, "Matx81i");
  Rice::Data_Type<cv::Vec<int, 8>> rb_cVec8i = Vec_instantiate<int, 8>(rb_mCv, "Vec8i");

  Rice::Data_Type<cv::Vec<float, 2>> rb_cVec2f = Vec_instantiate<float, 2>(rb_mCv, "Vec2f");

  Rice::Data_Type<cv::Vec<float, 3>> rb_cVec3f = Vec_instantiate<float, 3>(rb_mCv, "Vec3f");

  Rice::Data_Type<cv::Vec<float, 4>> rb_cVec4f = Vec_instantiate<float, 4>(rb_mCv, "Vec4f");

  Rice::Data_Type<cv::Vec<float, 6>> rb_cVec6f = Vec_instantiate<float, 6>(rb_mCv, "Vec6f");

  Rice::Data_Type<cv::Vec<double, 2>> rb_cVec2d = Vec_instantiate<double, 2>(rb_mCv, "Vec2d");

  Rice::Data_Type<cv::Vec<double, 3>> rb_cVec3d = Vec_instantiate<double, 3>(rb_mCv, "Vec3d");

  Rice::Data_Type<cv::Vec<double, 4>> rb_cVec4d = Vec_instantiate<double, 4>(rb_mCv, "Vec4d");

  Rice::Data_Type<cv::Vec<double, 6>> rb_cVec6d = Vec_instantiate<double, 6>(rb_mCv, "Vec6d");
}