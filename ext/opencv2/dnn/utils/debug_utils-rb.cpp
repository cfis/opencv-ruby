#include <opencv2/dnn/utils/debug_utils.hpp>
#include "debug_utils-rb.hpp"

using namespace Rice;

void Init_Dnn_Utils_DebugUtils()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvDnn = define_module_under(rb_mCv, "Dnn");

  Module rb_mCvDnnDnn4V20241223 = define_module_under(rb_mCvDnn, "Dnn4V20241223");

  rb_mCvDnnDnn4V20241223.define_module_function<void(*)(bool)>("skip_model_import", &cv::dnn::dnn4_v20241223::skipModelImport,
    Arg("skip"));
}
