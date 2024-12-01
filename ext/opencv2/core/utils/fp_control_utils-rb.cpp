#include <opencv2/core/utils/fp_control_utils.hpp>
#include "fp_control_utils-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvDetailsFPDenormalsIgnoreHintScope;
Rice::Class rb_cCvDetailsFPDenormalsIgnoreHintScopeNOOP;
Rice::Class rb_cCvDetailsFPDenormalsModeState;

void Init_FpControlUtils()
{
  Class(rb_cObject).define_constant("OPENCV_SUPPORTS_FP_DENORMALS_HINT", OPENCV_SUPPORTS_FP_DENORMALS_HINT);
  
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDetails = define_module_under(rb_mCv, "Details");
  
  rb_cCvDetailsFPDenormalsModeState = define_class_under<cv::details::FPDenormalsModeState>(rb_mCvDetails, "FPDenormalsModeState").
    define_constructor(Constructor<cv::details::FPDenormalsModeState>());
  
  rb_mCvDetails.define_module_function("set_fp_denormals_ignore_hint", &cv::details::setFPDenormalsIgnoreHint,
    Arg("ignore"), Arg("fp_denormals_mode_state"));
  
  rb_mCvDetails.define_module_function("save_fp_denormals_state", &cv::details::saveFPDenormalsState,
    Arg("fp_denormals_mode_state"));
  
  rb_mCvDetails.define_module_function("restore_fp_denormals_state", &cv::details::restoreFPDenormalsState,
    Arg("state"));
  
  rb_cCvDetailsFPDenormalsIgnoreHintScope = define_class_under<cv::details::FPDenormalsIgnoreHintScope>(rb_mCvDetails, "FPDenormalsIgnoreHintScope").
    define_constructor(Constructor<cv::details::FPDenormalsIgnoreHintScope, bool>(),
      Arg("ignore") = static_cast<bool>(true)).
    define_constructor(Constructor<cv::details::FPDenormalsIgnoreHintScope, const cv::details::FPDenormalsModeState&>(),
      Arg("state"));
  
  rb_cCvDetailsFPDenormalsIgnoreHintScopeNOOP = define_class_under<cv::details::FPDenormalsIgnoreHintScopeNOOP>(rb_mCvDetails, "FPDenormalsIgnoreHintScopeNOOP").
    define_constructor(Constructor<cv::details::FPDenormalsIgnoreHintScopeNOOP, bool>(),
      Arg("ignore") = static_cast<bool>(true)).
    define_constructor(Constructor<cv::details::FPDenormalsIgnoreHintScopeNOOP, const cv::details::FPDenormalsModeState&>(),
      Arg("state"));

}