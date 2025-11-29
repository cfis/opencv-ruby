#include <opencv2/core/hal/interface.h>
#include "interface-rb.hpp"

using namespace Rice;

void Init_Interface()
{
  Class(rb_cObject).define_constant("CV_HAL_ERROR_OK", CV_HAL_ERROR_OK);
  Class(rb_cObject).define_constant("CV_HAL_ERROR_NOT_IMPLEMENTED", CV_HAL_ERROR_NOT_IMPLEMENTED);
  Class(rb_cObject).define_constant("CV_CN_MAX", CV_CN_MAX);
  Class(rb_cObject).define_constant("CV_CN_SHIFT", CV_CN_SHIFT);
  Class(rb_cObject).define_constant("CV_8U", CV_8U);
  Class(rb_cObject).define_constant("CV_8S", CV_8S);
  Class(rb_cObject).define_constant("CV_16U", CV_16U);
  Class(rb_cObject).define_constant("CV_16S", CV_16S);
  Class(rb_cObject).define_constant("CV_32S", CV_32S);
  Class(rb_cObject).define_constant("CV_32F", CV_32F);
  Class(rb_cObject).define_constant("CV_64F", CV_64F);
  Class(rb_cObject).define_constant("CV_16F", CV_16F);

  Class(rb_cObject).define_constant("CV_8UC1", CV_8UC1);
  Class(rb_cObject).define_constant("CV_8UC2", CV_8UC2);
  Class(rb_cObject).define_constant("CV_8UC3", CV_8UC3);
  Class(rb_cObject).define_constant("CV_8UC4", CV_8UC4);

  Class(rb_cObject).define_constant("CV_8SC1", CV_8SC1);
  Class(rb_cObject).define_constant("CV_8SC2", CV_8SC2);
  Class(rb_cObject).define_constant("CV_8SC3", CV_8SC3);
  Class(rb_cObject).define_constant("CV_8SC4", CV_8SC4);

  Class(rb_cObject).define_constant("CV_16UC1", CV_16UC1);
  Class(rb_cObject).define_constant("CV_16UC2", CV_16UC2);
  Class(rb_cObject).define_constant("CV_16UC3", CV_16UC3);
  Class(rb_cObject).define_constant("CV_16UC4", CV_16UC4);

  Class(rb_cObject).define_constant("CV_16SC1", CV_16SC1);
  Class(rb_cObject).define_constant("CV_16SC2", CV_16SC2);
  Class(rb_cObject).define_constant("CV_16SC3", CV_16SC3);
  Class(rb_cObject).define_constant("CV_16SC4", CV_16SC4);

  Class(rb_cObject).define_constant("CV_32SC1", CV_32SC1);
  Class(rb_cObject).define_constant("CV_32SC2", CV_32SC2);
  Class(rb_cObject).define_constant("CV_32SC3", CV_32SC3);
  Class(rb_cObject).define_constant("CV_32SC4", CV_32SC4);

  Class(rb_cObject).define_constant("CV_32FC1", CV_32FC1);
  Class(rb_cObject).define_constant("CV_32FC2", CV_32FC2);
  Class(rb_cObject).define_constant("CV_32FC3", CV_32FC3);
  Class(rb_cObject).define_constant("CV_32FC4", CV_32FC4);

  // For corner_eigen_vals_and_vecs
  Class(rb_cObject).define_constant("CV_32FC6", CV_32FC(6));

  Class(rb_cObject).define_constant("CV_64FC1", CV_64FC1);
  Class(rb_cObject).define_constant("CV_64FC2", CV_64FC2);
  Class(rb_cObject).define_constant("CV_64FC3", CV_64FC3);
  Class(rb_cObject).define_constant("CV_64FC4", CV_64FC4);

  Class(rb_cObject).define_constant("CV_16FC1", CV_16FC1);
  Class(rb_cObject).define_constant("CV_16FC2", CV_16FC2);
  Class(rb_cObject).define_constant("CV_16FC3", CV_16FC3);
  Class(rb_cObject).define_constant("CV_16FC4", CV_16FC4);

  Class(rb_cObject).define_constant("CV_HAL_CMP_EQ", CV_HAL_CMP_EQ);
  Class(rb_cObject).define_constant("CV_HAL_CMP_GT", CV_HAL_CMP_GT);
  Class(rb_cObject).define_constant("CV_HAL_CMP_GE", CV_HAL_CMP_GE);
  Class(rb_cObject).define_constant("CV_HAL_CMP_LT", CV_HAL_CMP_LT);
  Class(rb_cObject).define_constant("CV_HAL_CMP_LE", CV_HAL_CMP_LE);
  Class(rb_cObject).define_constant("CV_HAL_CMP_NE", CV_HAL_CMP_NE);
  Class(rb_cObject).define_constant("CV_HAL_BORDER_CONSTANT", CV_HAL_BORDER_CONSTANT);
  Class(rb_cObject).define_constant("CV_HAL_BORDER_REPLICATE", CV_HAL_BORDER_REPLICATE);
  Class(rb_cObject).define_constant("CV_HAL_BORDER_REFLECT", CV_HAL_BORDER_REFLECT);
  Class(rb_cObject).define_constant("CV_HAL_BORDER_WRAP", CV_HAL_BORDER_WRAP);
  Class(rb_cObject).define_constant("CV_HAL_BORDER_REFLECT_101", CV_HAL_BORDER_REFLECT_101);
  Class(rb_cObject).define_constant("CV_HAL_BORDER_TRANSPARENT", CV_HAL_BORDER_TRANSPARENT);
  Class(rb_cObject).define_constant("CV_HAL_BORDER_ISOLATED", CV_HAL_BORDER_ISOLATED);
  Class(rb_cObject).define_constant("CV_HAL_DFT_INVERSE", CV_HAL_DFT_INVERSE);
  Class(rb_cObject).define_constant("CV_HAL_DFT_SCALE", CV_HAL_DFT_SCALE);
  Class(rb_cObject).define_constant("CV_HAL_DFT_ROWS", CV_HAL_DFT_ROWS);
  Class(rb_cObject).define_constant("CV_HAL_DFT_COMPLEX_OUTPUT", CV_HAL_DFT_COMPLEX_OUTPUT);
  Class(rb_cObject).define_constant("CV_HAL_DFT_REAL_OUTPUT", CV_HAL_DFT_REAL_OUTPUT);
  Class(rb_cObject).define_constant("CV_HAL_DFT_TWO_STAGE", CV_HAL_DFT_TWO_STAGE);
  Class(rb_cObject).define_constant("CV_HAL_DFT_STAGE_COLS", CV_HAL_DFT_STAGE_COLS);
  Class(rb_cObject).define_constant("CV_HAL_DFT_IS_CONTINUOUS", CV_HAL_DFT_IS_CONTINUOUS);
  Class(rb_cObject).define_constant("CV_HAL_DFT_IS_INPLACE", CV_HAL_DFT_IS_INPLACE);
  Class(rb_cObject).define_constant("CV_HAL_SVD_NO_UV", CV_HAL_SVD_NO_UV);
  Class(rb_cObject).define_constant("CV_HAL_SVD_SHORT_UV", CV_HAL_SVD_SHORT_UV);
  Class(rb_cObject).define_constant("CV_HAL_SVD_MODIFY_A", CV_HAL_SVD_MODIFY_A);
  Class(rb_cObject).define_constant("CV_HAL_SVD_FULL_UV", CV_HAL_SVD_FULL_UV);
  Class(rb_cObject).define_constant("CV_HAL_GEMM_1_T", CV_HAL_GEMM_1_T);
  Class(rb_cObject).define_constant("CV_HAL_GEMM_2_T", CV_HAL_GEMM_2_T);
  Class(rb_cObject).define_constant("CV_HAL_GEMM_3_T", CV_HAL_GEMM_3_T);
}