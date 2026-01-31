#include <opencv2/dnn/shape_utils.hpp>
#include "shape_utils-rb.hpp"

using namespace Rice;

void Init_Dnn_ShapeUtils()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvDnn = define_module_under(rb_mCv, "Dnn");

  Module rb_mCvDnnDnn4V20241223 = define_module_under(rb_mCvDnn, "Dnn4V20241223");

  Rice::Data_Type<cv::dnn::dnn4_v20241223::_Range> rb_cCvDnnDnn4V20241223Range = define_class_under<cv::dnn::dnn4_v20241223::_Range, cv::Range>(rb_mCvDnnDnn4V20241223, "Range").
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::_Range, const cv::Range&>(),
      Arg("r")).
    define_constructor(Constructor<cv::dnn::dnn4_v20241223::_Range, int, int>(),
      Arg("start_"), Arg("size_") = static_cast<int>(1));

  rb_mCvDnnDnn4V20241223.define_module_function<cv::Mat(*)(const cv::Mat&, const cv::dnn::dnn4_v20241223::_Range&)>("slice", &cv::dnn::dnn4_v20241223::slice,
    Arg("m"), Arg("r0"));

  rb_mCvDnnDnn4V20241223.define_module_function<cv::Mat(*)(const cv::Mat&, const cv::dnn::dnn4_v20241223::_Range&, const cv::dnn::dnn4_v20241223::_Range&)>("slice", &cv::dnn::dnn4_v20241223::slice,
    Arg("m"), Arg("r0"), Arg("r1"));

  rb_mCvDnnDnn4V20241223.define_module_function<cv::Mat(*)(const cv::Mat&, const cv::dnn::dnn4_v20241223::_Range&, const cv::dnn::dnn4_v20241223::_Range&, const cv::dnn::dnn4_v20241223::_Range&)>("slice", &cv::dnn::dnn4_v20241223::slice,
    Arg("m"), Arg("r0"), Arg("r1"), Arg("r2"));

  rb_mCvDnnDnn4V20241223.define_module_function<cv::Mat(*)(const cv::Mat&, const cv::dnn::dnn4_v20241223::_Range&, const cv::dnn::dnn4_v20241223::_Range&, const cv::dnn::dnn4_v20241223::_Range&, const cv::dnn::dnn4_v20241223::_Range&)>("slice", &cv::dnn::dnn4_v20241223::slice,
    Arg("m"), Arg("r0"), Arg("r1"), Arg("r2"), Arg("r3"));

  rb_mCvDnnDnn4V20241223.define_module_function<cv::Mat(*)(const cv::Mat&, int, int)>("get_plane", &cv::dnn::dnn4_v20241223::getPlane,
    Arg("m"), Arg("n"), Arg("cn"));

  rb_mCvDnnDnn4V20241223.define_module_function<cv::dnn::dnn4_v20241223::MatShape(*)(const int*, const int)>("shape", &cv::dnn::dnn4_v20241223::shape,
    ArgBuffer("dims"), Arg("n"));

  rb_mCvDnnDnn4V20241223.define_module_function<cv::dnn::dnn4_v20241223::MatShape(*)(const cv::Mat&)>("shape", &cv::dnn::dnn4_v20241223::shape,
    Arg("mat"));

  rb_mCvDnnDnn4V20241223.define_module_function<cv::dnn::dnn4_v20241223::MatShape(*)(const cv::MatSize&)>("shape", &cv::dnn::dnn4_v20241223::shape,
    Arg("sz"));

  rb_mCvDnnDnn4V20241223.define_module_function<cv::dnn::dnn4_v20241223::MatShape(*)(const cv::UMat&)>("shape", &cv::dnn::dnn4_v20241223::shape,
    Arg("mat"));

  rb_mCvDnnDnn4V20241223.define_module_function<cv::dnn::dnn4_v20241223::MatShape(*)(int, int, int, int)>("shape", &cv::dnn::dnn4_v20241223::shape,
    Arg("a0"), Arg("a1") = static_cast<int>(-1), Arg("a2") = static_cast<int>(-1), Arg("a3") = static_cast<int>(-1));

  rb_mCvDnnDnn4V20241223.define_module_function<int(*)(const cv::dnn::dnn4_v20241223::MatShape&, int, int)>("total", &cv::dnn::dnn4_v20241223::total,
    Arg("shape"), Arg("start") = static_cast<int>(-1), Arg("end") = static_cast<int>(-1));

  rb_mCvDnnDnn4V20241223.define_module_function<int(*)(const cv::Mat&, int, int)>("total", &cv::dnn::dnn4_v20241223::total,
    Arg("mat"), Arg("start") = static_cast<int>(-1), Arg("end") = static_cast<int>(-1));

  rb_mCvDnnDnn4V20241223.define_module_function<cv::dnn::dnn4_v20241223::MatShape(*)(const cv::dnn::dnn4_v20241223::MatShape&, const cv::dnn::dnn4_v20241223::MatShape&)>("concat", &cv::dnn::dnn4_v20241223::concat,
    Arg("a"), Arg("b"));

  rb_mCvDnnDnn4V20241223.define_module_function<int(*)(int, int)>("normalize_axis", &cv::dnn::dnn4_v20241223::normalize_axis,
    Arg("axis"), Arg("dims"));

  rb_mCvDnnDnn4V20241223.define_module_function<int(*)(int, const cv::dnn::dnn4_v20241223::MatShape&)>("normalize_axis", &cv::dnn::dnn4_v20241223::normalize_axis,
    Arg("axis"), Arg("shape"));

  rb_mCvDnnDnn4V20241223.define_module_function<cv::Range(*)(const cv::Range&, int)>("normalize_axis_range", &cv::dnn::dnn4_v20241223::normalize_axis_range,
    Arg("r"), Arg("axis_size"));

  rb_mCvDnnDnn4V20241223.define_module_function<bool(*)(const cv::dnn::dnn4_v20241223::MatShape&, int, int)>("all_ones?", &cv::dnn::dnn4_v20241223::isAllOnes,
    Arg("input_shape"), Arg("start_pos"), Arg("end_pos"));
}