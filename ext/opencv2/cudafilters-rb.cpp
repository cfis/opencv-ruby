#include <opencv2/cudafilters.hpp>
#include "cudafilters-rb.hpp"

using namespace Rice;

void Init_Cudafilters()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");

  Rice::Data_Type<cv::cuda::Filter> rb_cCvCudaFilter = define_class_under<cv::cuda::Filter, cv::Algorithm>(rb_mCvCuda, "Filter").
    define_method("apply", &cv::cuda::Filter::apply,
      Arg("src"), Arg("dst"), Arg("stream") = static_cast<cv::cuda::Stream&>(cv::cuda::Stream::Null()));

  rb_mCvCuda.define_module_function("create_box_filter", &cv::cuda::createBoxFilter,
    Arg("src_type"), Arg("dst_type"), Arg("ksize"), Arg("anchor") = static_cast<cv::Point>(cv::Point(-1, -1)), Arg("border_mode") = static_cast<int>(cv::BORDER_DEFAULT), Arg("border_val") = static_cast<cv::Scalar>(cv::Scalar::all(0)));

  rb_mCvCuda.define_module_function("create_linear_filter", &cv::cuda::createLinearFilter,
    Arg("src_type"), Arg("dst_type"), Arg("kernel"), Arg("anchor") = static_cast<cv::Point>(cv::Point(-1, -1)), Arg("border_mode") = static_cast<int>(cv::BORDER_DEFAULT), Arg("border_val") = static_cast<cv::Scalar>(cv::Scalar::all(0)));

  rb_mCvCuda.define_module_function("create_laplacian_filter", &cv::cuda::createLaplacianFilter,
    Arg("src_type"), Arg("dst_type"), Arg("ksize") = static_cast<int>(1), Arg("scale") = static_cast<double>(1), Arg("border_mode") = static_cast<int>(cv::BORDER_DEFAULT), Arg("border_val") = static_cast<cv::Scalar>(cv::Scalar::all(0)));

  rb_mCvCuda.define_module_function("create_separable_linear_filter", &cv::cuda::createSeparableLinearFilter,
    Arg("src_type"), Arg("dst_type"), Arg("row_kernel"), Arg("column_kernel"), Arg("anchor") = static_cast<cv::Point>(cv::Point(-1,-1)), Arg("row_border_mode") = static_cast<int>(cv::BORDER_DEFAULT), Arg("column_border_mode") = static_cast<int>(-1));

  rb_mCvCuda.define_module_function("create_deriv_filter", &cv::cuda::createDerivFilter,
    Arg("src_type"), Arg("dst_type"), Arg("dx"), Arg("dy"), Arg("ksize"), Arg("normalize") = static_cast<bool>(false), Arg("scale") = static_cast<double>(1), Arg("row_border_mode") = static_cast<int>(cv::BORDER_DEFAULT), Arg("column_border_mode") = static_cast<int>(-1));

  rb_mCvCuda.define_module_function("create_sobel_filter", &cv::cuda::createSobelFilter,
    Arg("src_type"), Arg("dst_type"), Arg("dx"), Arg("dy"), Arg("ksize") = static_cast<int>(3), Arg("scale") = static_cast<double>(1), Arg("row_border_mode") = static_cast<int>(cv::BORDER_DEFAULT), Arg("column_border_mode") = static_cast<int>(-1));

  rb_mCvCuda.define_module_function("create_scharr_filter", &cv::cuda::createScharrFilter,
    Arg("src_type"), Arg("dst_type"), Arg("dx"), Arg("dy"), Arg("scale") = static_cast<double>(1), Arg("row_border_mode") = static_cast<int>(cv::BORDER_DEFAULT), Arg("column_border_mode") = static_cast<int>(-1));

  rb_mCvCuda.define_module_function("create_gaussian_filter", &cv::cuda::createGaussianFilter,
    Arg("src_type"), Arg("dst_type"), Arg("ksize"), Arg("sigma1"), Arg("sigma2") = static_cast<double>(0), Arg("row_border_mode") = static_cast<int>(cv::BORDER_DEFAULT), Arg("column_border_mode") = static_cast<int>(-1));

  rb_mCvCuda.define_module_function("create_morphology_filter", &cv::cuda::createMorphologyFilter,
    Arg("op"), Arg("src_type"), Arg("kernel"), Arg("anchor") = static_cast<cv::Point>(cv::Point(-1, -1)), Arg("iterations") = static_cast<int>(1));

  rb_mCvCuda.define_module_function("create_box_max_filter", &cv::cuda::createBoxMaxFilter,
    Arg("src_type"), Arg("ksize"), Arg("anchor") = static_cast<cv::Point>(cv::Point(-1, -1)), Arg("border_mode") = static_cast<int>(cv::BORDER_DEFAULT), Arg("border_val") = static_cast<cv::Scalar>(cv::Scalar::all(0)));

  rb_mCvCuda.define_module_function("create_box_min_filter", &cv::cuda::createBoxMinFilter,
    Arg("src_type"), Arg("ksize"), Arg("anchor") = static_cast<cv::Point>(cv::Point(-1, -1)), Arg("border_mode") = static_cast<int>(cv::BORDER_DEFAULT), Arg("border_val") = static_cast<cv::Scalar>(cv::Scalar::all(0)));

  rb_mCvCuda.define_module_function("create_row_sum_filter", &cv::cuda::createRowSumFilter,
    Arg("src_type"), Arg("dst_type"), Arg("ksize"), Arg("anchor") = static_cast<int>(-1), Arg("border_mode") = static_cast<int>(cv::BORDER_DEFAULT), Arg("border_val") = static_cast<cv::Scalar>(cv::Scalar::all(0)));

  rb_mCvCuda.define_module_function("create_column_sum_filter", &cv::cuda::createColumnSumFilter,
    Arg("src_type"), Arg("dst_type"), Arg("ksize"), Arg("anchor") = static_cast<int>(-1), Arg("border_mode") = static_cast<int>(cv::BORDER_DEFAULT), Arg("border_val") = static_cast<cv::Scalar>(cv::Scalar::all(0)));

  rb_mCvCuda.define_module_function("create_median_filter", &cv::cuda::createMedianFilter,
    Arg("src_type"), Arg("window_size"), Arg("partition") = static_cast<int>(128));
}