#include <opencv2/core/cvstd_wrapper.hpp>
#include "cvstd_wrapper-rb.hpp"

Rice::Class rb_cCvPtrFloat;

using namespace Rice;

template<typename Data_Type_T, typename C, typename Ret, typename Args>
inline void has_parenthesis_operator_builder(Data_Type_T& klass)
{
  klass.define_constant("Value", cv::sfinae::has_parenthesis_operator<C, Ret, Args>::value);
};

template<typename Data_Type_T, typename T, typename >
inline void has_custom_delete_builder(Data_Type_T& klass)
{
};

void Init_CvstdWrapper()
{
}