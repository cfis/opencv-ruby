#include <opencv2/dnn/utils/inference_engine.hpp>
#include "inference_engine-rb.hpp"

using namespace Rice;


void Init_InferenceEngine()
{
  Class(rb_cObject).define_constant("CV_DNN_BACKEND_INFERENCE_ENGINE_NN_BUILDER_API", CV_DNN_BACKEND_INFERENCE_ENGINE_NN_BUILDER_API);
  
  Class(rb_cObject).define_constant("CV_DNN_BACKEND_INFERENCE_ENGINE_NGRAPH", CV_DNN_BACKEND_INFERENCE_ENGINE_NGRAPH);
  
  Class(rb_cObject).define_constant("CV_DNN_INFERENCE_ENGINE_VPU_TYPE_UNSPECIFIED", CV_DNN_INFERENCE_ENGINE_VPU_TYPE_UNSPECIFIED);
  
  Class(rb_cObject).define_constant("CV_DNN_INFERENCE_ENGINE_VPU_TYPE_MYRIAD_2", CV_DNN_INFERENCE_ENGINE_VPU_TYPE_MYRIAD_2);
  
  Class(rb_cObject).define_constant("CV_DNN_INFERENCE_ENGINE_VPU_TYPE_MYRIAD_X", CV_DNN_INFERENCE_ENGINE_VPU_TYPE_MYRIAD_X);
  
  Class(rb_cObject).define_constant("CV_DNN_INFERENCE_ENGINE_CPU_TYPE_ARM_COMPUTE", CV_DNN_INFERENCE_ENGINE_CPU_TYPE_ARM_COMPUTE);
  
  Class(rb_cObject).define_constant("CV_DNN_INFERENCE_ENGINE_CPU_TYPE_X86", CV_DNN_INFERENCE_ENGINE_CPU_TYPE_X86);
  
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDnn = define_module_under(rb_mCv, "Dnn");
  

}