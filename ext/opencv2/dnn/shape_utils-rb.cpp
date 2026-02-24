#include <opencv2/dnn/shape_utils.hpp>
#include "shape_utils-rb.hpp"

using namespace Rice;

void Init_Dnn_ShapeUtils()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvDnn = define_module_under(rb_mCv, "Dnn");


  Rice::Data_Type<cv::dnn::_Range> rb_cCvDnnRange = define_class_under<cv::dnn::_Range, cv::Range>(rb_mCvDnn, "Range").
    define_constructor(Constructor<cv::dnn::_Range, const cv::Range&>(),
      Arg("r")).
    define_constructor(Constructor<cv::dnn::_Range, int, int>(),
      Arg("start_"), Arg("size_") = static_cast<int>(1));

  rb_mCvDnn.define_module_function<cv::Mat(*)(const cv::Mat&, const cv::dnn::_Range&)>("slice", &cv::dnn::slice,
    Arg("m"), Arg("r0"));

  rb_mCvDnn.define_module_function<cv::Mat(*)(const cv::Mat&, const cv::dnn::_Range&, const cv::dnn::_Range&)>("slice", &cv::dnn::slice,
    Arg("m"), Arg("r0"), Arg("r1"));

  rb_mCvDnn.define_module_function<cv::Mat(*)(const cv::Mat&, const cv::dnn::_Range&, const cv::dnn::_Range&, const cv::dnn::_Range&)>("slice", &cv::dnn::slice,
    Arg("m"), Arg("r0"), Arg("r1"), Arg("r2"));

  rb_mCvDnn.define_module_function<cv::Mat(*)(const cv::Mat&, const cv::dnn::_Range&, const cv::dnn::_Range&, const cv::dnn::_Range&, const cv::dnn::_Range&)>("slice", &cv::dnn::slice,
    Arg("m"), Arg("r0"), Arg("r1"), Arg("r2"), Arg("r3"));

  rb_mCvDnn.define_module_function<cv::Mat(*)(const cv::Mat&, int, int)>("get_plane", &cv::dnn::getPlane,
    Arg("m"), Arg("n"), Arg("cn"));

  rb_mCvDnn.define_module_function<cv::dnn::MatShape(*)(const int*, const int)>("shape", &cv::dnn::shape,
    ArgBuffer("dims"), Arg("n"));

  rb_mCvDnn.define_module_function<cv::dnn::MatShape(*)(const cv::Mat&)>("shape", &cv::dnn::shape,
    Arg("mat"));

  rb_mCvDnn.define_module_function<cv::dnn::MatShape(*)(const cv::MatSize&)>("shape", &cv::dnn::shape,
    Arg("sz"));

  rb_mCvDnn.define_module_function<cv::dnn::MatShape(*)(const cv::UMat&)>("shape", &cv::dnn::shape,
    Arg("mat"));

  rb_mCvDnn.define_module_function<cv::dnn::MatShape(*)(int, int, int, int)>("shape", &cv::dnn::shape,
    Arg("a0"), Arg("a1") = static_cast<int>(-1), Arg("a2") = static_cast<int>(-1), Arg("a3") = static_cast<int>(-1));

  rb_mCvDnn.define_module_function<int(*)(const cv::dnn::MatShape&, int, int)>("total", &cv::dnn::total,
    Arg("shape"), Arg("start") = static_cast<int>(-1), Arg("end") = static_cast<int>(-1));

  rb_mCvDnn.define_module_function<int(*)(const cv::Mat&, int, int)>("total", &cv::dnn::total,
    Arg("mat"), Arg("start") = static_cast<int>(-1), Arg("end") = static_cast<int>(-1));

  rb_mCvDnn.define_module_function<cv::dnn::MatShape(*)(const cv::dnn::MatShape&, const cv::dnn::MatShape&)>("concat", &cv::dnn::concat,
    Arg("a"), Arg("b"));

  rb_mCvDnn.define_module_function<int(*)(int, int)>("normalize_axis", &cv::dnn::normalize_axis,
    Arg("axis"), Arg("dims"));

  rb_mCvDnn.define_module_function<int(*)(int, const cv::dnn::MatShape&)>("normalize_axis", &cv::dnn::normalize_axis,
    Arg("axis"), Arg("shape"));

  rb_mCvDnn.define_module_function<cv::Range(*)(const cv::Range&, int)>("normalize_axis_range", &cv::dnn::normalize_axis_range,
    Arg("r"), Arg("axis_size"));

  rb_mCvDnn.define_module_function<bool(*)(const cv::dnn::MatShape&, int, int)>("all_ones?", &cv::dnn::isAllOnes,
    Arg("input_shape"), Arg("start_pos"), Arg("end_pos"));
}
