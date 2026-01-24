#include <opencv2/cudaarithm.hpp>
#include "cudaarithm-rb.hpp"

using namespace Rice;

void Init_Cudaarithm()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");

  rb_mCvCuda.define_module_function("add", &cv::cuda::add,
    Arg("src1"), Arg("src2"), Arg("dst"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()), Arg("dtype") = static_cast<int>(-1), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function("add_with_scalar", &cv::cuda::addWithScalar,
    Arg("src1"), Arg("src2"), Arg("dst"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()), Arg("dtype") = static_cast<int>(-1), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function("subtract", &cv::cuda::subtract,
    Arg("src1"), Arg("src2"), Arg("dst"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()), Arg("dtype") = static_cast<int>(-1), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function("subtract_with_scalar", &cv::cuda::subtractWithScalar,
    Arg("src1"), Arg("src2"), Arg("dst"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()), Arg("dtype") = static_cast<int>(-1), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function("multiply", &cv::cuda::multiply,
    Arg("src1"), Arg("src2"), Arg("dst"), Arg("scale") = static_cast<double>(1), Arg("dtype") = static_cast<int>(-1), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function("multiply_with_scalar", &cv::cuda::multiplyWithScalar,
    Arg("src1"), Arg("src2"), Arg("dst"), Arg("scale") = static_cast<double>(1), Arg("dtype") = static_cast<int>(-1), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function("divide", &cv::cuda::divide,
    Arg("src1"), Arg("src2"), Arg("dst"), Arg("scale") = static_cast<double>(1), Arg("dtype") = static_cast<int>(-1), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function("divide_with_scalar", &cv::cuda::divideWithScalar,
    Arg("src1"), Arg("src2"), Arg("dst"), Arg("scale") = static_cast<double>(1), Arg("dtype") = static_cast<int>(-1), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function("absdiff", &cv::cuda::absdiff,
    Arg("src1"), Arg("src2"), Arg("dst"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function("absdiff_with_scalar", &cv::cuda::absdiffWithScalar,
    Arg("src1"), Arg("src2"), Arg("dst"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function("abs", &cv::cuda::abs,
    Arg("src"), Arg("dst"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function("sqr", &cv::cuda::sqr,
    Arg("src"), Arg("dst"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function("sqrt", &cv::cuda::sqrt,
    Arg("src"), Arg("dst"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function("exp", &cv::cuda::exp,
    Arg("src"), Arg("dst"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function("log", &cv::cuda::log,
    Arg("src"), Arg("dst"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function("pow", &cv::cuda::pow,
    Arg("src"), Arg("power"), Arg("dst"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function("compare", &cv::cuda::compare,
    Arg("src1"), Arg("src2"), Arg("dst"), Arg("cmpop"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function("compare_with_scalar", &cv::cuda::compareWithScalar,
    Arg("src1"), Arg("src2"), Arg("dst"), Arg("cmpop"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function("bitwise_not", &cv::cuda::bitwise_not,
    Arg("src"), Arg("dst"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function("bitwise_or", &cv::cuda::bitwise_or,
    Arg("src1"), Arg("src2"), Arg("dst"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function("bitwise_or_with_scalar", &cv::cuda::bitwise_or_with_scalar,
    Arg("src1"), Arg("src2"), Arg("dst"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function("bitwise_and", &cv::cuda::bitwise_and,
    Arg("src1"), Arg("src2"), Arg("dst"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function("bitwise_and_with_scalar", &cv::cuda::bitwise_and_with_scalar,
    Arg("src1"), Arg("src2"), Arg("dst"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function("bitwise_xor", &cv::cuda::bitwise_xor,
    Arg("src1"), Arg("src2"), Arg("dst"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function("bitwise_xor_with_scalar", &cv::cuda::bitwise_xor_with_scalar,
    Arg("src1"), Arg("src2"), Arg("dst"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, cv::Scalar_<int>, cv::OutputArray, cv::cuda::Stream&)>("rshift", &cv::cuda::rshift,
    Arg("src"), Arg("val"), Arg("dst"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, cv::Scalar, cv::OutputArray, cv::cuda::Stream&)>("rshift", &cv::cuda::rshift,
    Arg("src"), Arg("val"), Arg("dst"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, cv::Scalar_<int>, cv::OutputArray, cv::cuda::Stream&)>("lshift", &cv::cuda::lshift,
    Arg("src"), Arg("val"), Arg("dst"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, cv::Scalar, cv::OutputArray, cv::cuda::Stream&)>("lshift", &cv::cuda::lshift,
    Arg("src"), Arg("val"), Arg("dst"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function("min", &cv::cuda::min,
    Arg("src1"), Arg("src2"), Arg("dst"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function("min_with_scalar", &cv::cuda::minWithScalar,
    Arg("src1"), Arg("src2"), Arg("dst"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function("max", &cv::cuda::max,
    Arg("src1"), Arg("src2"), Arg("dst"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function("max_with_scalar", &cv::cuda::maxWithScalar,
    Arg("src1"), Arg("src2"), Arg("dst"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function("add_weighted", &cv::cuda::addWeighted,
    Arg("src1"), Arg("alpha"), Arg("src2"), Arg("beta"), Arg("gamma"), Arg("dst"), Arg("dtype") = static_cast<int>(-1), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function("scale_add", &cv::cuda::scaleAdd,
    Arg("src1"), Arg("alpha"), Arg("src2"), Arg("dst"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function("threshold", &cv::cuda::threshold,
    Arg("src"), Arg("dst"), Arg("thresh"), Arg("maxval"), Arg("type"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function("in_range", &cv::cuda::inRange,
    Arg("src"), Arg("lowerb"), Arg("upperb"), Arg("dst"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::cuda::Stream&)>("magnitude", &cv::cuda::magnitude,
    Arg("xy"), Arg("magnitude"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::cuda::Stream&)>("magnitude_sqr", &cv::cuda::magnitudeSqr,
    Arg("xy"), Arg("magnitude"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray, cv::cuda::Stream&)>("magnitude", &cv::cuda::magnitude,
    Arg("x"), Arg("y"), Arg("magnitude"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray, cv::cuda::Stream&)>("magnitude_sqr", &cv::cuda::magnitudeSqr,
    Arg("x"), Arg("y"), Arg("magnitude"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray, bool, cv::cuda::Stream&)>("phase", &cv::cuda::phase,
    Arg("x"), Arg("y"), Arg("angle"), Arg("angle_in_degrees") = static_cast<bool>(false), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, cv::OutputArray, bool, cv::cuda::Stream&)>("phase", &cv::cuda::phase,
    Arg("xy"), Arg("angle"), Arg("angle_in_degrees") = static_cast<bool>(false), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray, cv::OutputArray, bool, cv::cuda::Stream&)>("cart_to_polar", &cv::cuda::cartToPolar,
    Arg("x"), Arg("y"), Arg("magnitude"), Arg("angle"), Arg("angle_in_degrees") = static_cast<bool>(false), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::OutputArray, bool, cv::cuda::Stream&)>("cart_to_polar", &cv::cuda::cartToPolar,
    Arg("xy"), Arg("magnitude"), Arg("angle"), Arg("angle_in_degrees") = static_cast<bool>(false), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, cv::OutputArray, bool, cv::cuda::Stream&)>("cart_to_polar", &cv::cuda::cartToPolar,
    Arg("xy"), Arg("magnitude_angle"), Arg("angle_in_degrees") = static_cast<bool>(false), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray, cv::OutputArray, bool, cv::cuda::Stream&)>("polar_to_cart", &cv::cuda::polarToCart,
    Arg("magnitude"), Arg("angle"), Arg("x"), Arg("y"), Arg("angle_in_degrees") = static_cast<bool>(false), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray, bool, cv::cuda::Stream&)>("polar_to_cart", &cv::cuda::polarToCart,
    Arg("magnitude"), Arg("angle"), Arg("xy"), Arg("angle_in_degrees") = static_cast<bool>(false), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, cv::OutputArray, bool, cv::cuda::Stream&)>("polar_to_cart", &cv::cuda::polarToCart,
    Arg("magnitude_angle"), Arg("xy"), Arg("angle_in_degrees") = static_cast<bool>(false), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(const cv::cuda::GpuMat*, size_t, cv::OutputArray, cv::cuda::Stream&)>("merge", &cv::cuda::merge,
    Arg("src"), Arg("n"), Arg("dst"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(const std::vector<cv::cuda::GpuMat>&, cv::OutputArray, cv::cuda::Stream&)>("merge", &cv::cuda::merge,
    Arg("src"), Arg("dst"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, cv::cuda::GpuMat*, cv::cuda::Stream&)>("split", &cv::cuda::split,
    Arg("src"), Arg("dst"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, std::vector<cv::cuda::GpuMat>&, cv::cuda::Stream&)>("split", &cv::cuda::split,
    Arg("src"), Arg("dst"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function("transpose", &cv::cuda::transpose,
    Arg("src1"), Arg("dst"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function("flip", &cv::cuda::flip,
    Arg("src"), Arg("dst"), Arg("flip_code"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  Rice::Data_Type<cv::cuda::LookUpTable> rb_cCvCudaLookUpTable = define_class_under<cv::cuda::LookUpTable, cv::Algorithm>(rb_mCvCuda, "LookUpTable").
    define_method("transform", &cv::cuda::LookUpTable::transform,
      Arg("src"), Arg("dst"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function("create_look_up_table", &cv::cuda::createLookUpTable,
    Arg("lut"));

  rb_mCvCuda.define_module_function("copy_make_border", &cv::cuda::copyMakeBorder,
    Arg("src"), Arg("dst"), Arg("top"), Arg("bottom"), Arg("left"), Arg("right"), Arg("border_type"), Arg("value") = static_cast<cv::Scalar>(cv::Scalar()), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<double(*)(cv::InputArray, int, cv::InputArray)>("norm", &cv::cuda::norm,
    Arg("src1"), Arg("norm_type"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()));

  rb_mCvCuda.define_module_function("calc_norm", &cv::cuda::calcNorm,
    Arg("src"), Arg("dst"), Arg("norm_type"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<double(*)(cv::InputArray, cv::InputArray, int)>("norm", &cv::cuda::norm,
    Arg("src1"), Arg("src2"), Arg("norm_type") = static_cast<int>(cv::NORM_L2));

  rb_mCvCuda.define_module_function("calc_norm_diff", &cv::cuda::calcNormDiff,
    Arg("src1"), Arg("src2"), Arg("dst"), Arg("norm_type") = static_cast<int>(cv::NORM_L2), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function("sum", &cv::cuda::sum,
    Arg("src"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()));

  rb_mCvCuda.define_module_function("calc_sum", &cv::cuda::calcSum,
    Arg("src"), Arg("dst"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function("abs_sum", &cv::cuda::absSum,
    Arg("src"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()));

  rb_mCvCuda.define_module_function("calc_abs_sum", &cv::cuda::calcAbsSum,
    Arg("src"), Arg("dst"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function("sqr_sum", &cv::cuda::sqrSum,
    Arg("src"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()));

  rb_mCvCuda.define_module_function("calc_sqr_sum", &cv::cuda::calcSqrSum,
    Arg("src"), Arg("dst"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function("min_max", &cv::cuda::minMax,
    Arg("src"), ArgBuffer("min_val"), ArgBuffer("max_val"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()));

  rb_mCvCuda.define_module_function("find_min_max", &cv::cuda::findMinMax,
    Arg("src"), Arg("dst"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function("min_max_loc", &cv::cuda::minMaxLoc,
    Arg("src"), ArgBuffer("min_val"), ArgBuffer("max_val"), Arg("min_loc"), Arg("max_loc"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()));

  rb_mCvCuda.define_module_function("find_min_max_loc", &cv::cuda::findMinMaxLoc,
    Arg("src"), Arg("min_max_vals"), Arg("loc"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<int(*)(cv::InputArray)>("count_non_zero", &cv::cuda::countNonZero,
    Arg("src"));

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::cuda::Stream&)>("count_non_zero", &cv::cuda::countNonZero,
    Arg("src"), Arg("dst"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function("reduce", &cv::cuda::reduce,
    Arg("mtx"), Arg("vec"), Arg("dim"), Arg("reduce_op"), Arg("dtype") = static_cast<int>(-1), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::InputArray, cv::cuda::Stream&)>("mean_std_dev", &cv::cuda::meanStdDev,
    Arg("src"), Arg("dst"), Arg("mask"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::cuda::Stream&)>("mean_std_dev", &cv::cuda::meanStdDev,
    Arg("mtx"), Arg("dst"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, cv::Scalar&, cv::Scalar&, cv::InputArray)>("mean_std_dev", &cv::cuda::meanStdDev,
    Arg("src"), Arg("mean"), Arg("stddev"), Arg("mask"));

  rb_mCvCuda.define_module_function<void(*)(cv::InputArray, cv::Scalar&, cv::Scalar&)>("mean_std_dev", &cv::cuda::meanStdDev,
    Arg("mtx"), Arg("mean"), Arg("stddev"));

  rb_mCvCuda.define_module_function("rect_std_dev", &cv::cuda::rectStdDev,
    Arg("src"), Arg("sqr"), Arg("dst"), Arg("rect"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function("normalize", &cv::cuda::normalize,
    Arg("src"), Arg("dst"), Arg("alpha"), Arg("beta"), Arg("norm_type"), Arg("dtype"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function("integral", &cv::cuda::integral,
    Arg("src"), Arg("sum"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function("sqr_integral", &cv::cuda::sqrIntegral,
    Arg("src"), Arg("sqsum"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function("gemm", &cv::cuda::gemm,
    Arg("src1"), Arg("src2"), Arg("alpha"), Arg("src3"), Arg("beta"), Arg("dst"), Arg("flags") = static_cast<int>(0), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function("mul_spectrums", &cv::cuda::mulSpectrums,
    Arg("src1"), Arg("src2"), Arg("dst"), Arg("flags"), Arg("conj_b") = static_cast<bool>(false), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function("mul_and_scale_spectrums", &cv::cuda::mulAndScaleSpectrums,
    Arg("src1"), Arg("src2"), Arg("dst"), Arg("flags"), Arg("scale"), Arg("conj_b") = static_cast<bool>(false), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function("dft", &cv::cuda::dft,
    Arg("src"), Arg("dst"), Arg("dft_size"), Arg("flags") = static_cast<int>(0), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  Rice::Data_Type<cv::cuda::DFT> rb_cCvCudaDFT = define_class_under<cv::cuda::DFT, cv::Algorithm>(rb_mCvCuda, "DFT").
    define_method("compute", &cv::cuda::DFT::compute,
      Arg("image"), Arg("result"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function("create_dft", &cv::cuda::createDFT,
    Arg("dft_size"), Arg("flags"));

  Rice::Data_Type<cv::cuda::Convolution> rb_cCvCudaConvolution = define_class_under<cv::cuda::Convolution, cv::Algorithm>(rb_mCvCuda, "Convolution").
    define_method("convolve", &cv::cuda::Convolution::convolve,
      Arg("image"), Arg("templ"), Arg("result"), Arg("ccorr") = static_cast<bool>(false), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function("create_convolution", &cv::cuda::createConvolution,
    Arg("user_block_size") = static_cast<cv::Size>(cv::Size()));
}