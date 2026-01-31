#include <opencv2/calib3d/calib3d_c.h>
#include "calib3d_c-rb.hpp"

using namespace Rice;

void Init_Calib3d_Calib3dC()
{
  Class(rb_cObject).define_constant("CV_FM_7POINT", CV_FM_7POINT);

  Class(rb_cObject).define_constant("CV_FM_8POINT", CV_FM_8POINT);

  Class(rb_cObject).define_constant("CV_LMEDS", CV_LMEDS);

  Class(rb_cObject).define_constant("CV_RANSAC", CV_RANSAC);

  Class(rb_cObject).define_constant("CV_CALIB_CB_ADAPTIVE_THRESH", CV_CALIB_CB_ADAPTIVE_THRESH);

  Class(rb_cObject).define_constant("CV_CALIB_CB_NORMALIZE_IMAGE", CV_CALIB_CB_NORMALIZE_IMAGE);

  Class(rb_cObject).define_constant("CV_CALIB_CB_FILTER_QUADS", CV_CALIB_CB_FILTER_QUADS);

  Class(rb_cObject).define_constant("CV_CALIB_CB_FAST_CHECK", CV_CALIB_CB_FAST_CHECK);

  Class(rb_cObject).define_constant("CV_CALIB_USE_INTRINSIC_GUESS", CV_CALIB_USE_INTRINSIC_GUESS);

  Class(rb_cObject).define_constant("CV_CALIB_FIX_ASPECT_RATIO", CV_CALIB_FIX_ASPECT_RATIO);

  Class(rb_cObject).define_constant("CV_CALIB_FIX_PRINCIPAL_POINT", CV_CALIB_FIX_PRINCIPAL_POINT);

  Class(rb_cObject).define_constant("CV_CALIB_ZERO_TANGENT_DIST", CV_CALIB_ZERO_TANGENT_DIST);

  Class(rb_cObject).define_constant("CV_CALIB_FIX_FOCAL_LENGTH", CV_CALIB_FIX_FOCAL_LENGTH);

  Class(rb_cObject).define_constant("CV_CALIB_FIX_K1", CV_CALIB_FIX_K1);

  Class(rb_cObject).define_constant("CV_CALIB_FIX_K2", CV_CALIB_FIX_K2);

  Class(rb_cObject).define_constant("CV_CALIB_FIX_K3", CV_CALIB_FIX_K3);

  Class(rb_cObject).define_constant("CV_CALIB_FIX_K4", CV_CALIB_FIX_K4);

  Class(rb_cObject).define_constant("CV_CALIB_FIX_K5", CV_CALIB_FIX_K5);

  Class(rb_cObject).define_constant("CV_CALIB_FIX_K6", CV_CALIB_FIX_K6);

  Class(rb_cObject).define_constant("CV_CALIB_RATIONAL_MODEL", CV_CALIB_RATIONAL_MODEL);

  Class(rb_cObject).define_constant("CV_CALIB_THIN_PRISM_MODEL", CV_CALIB_THIN_PRISM_MODEL);

  Class(rb_cObject).define_constant("CV_CALIB_FIX_S1_S2_S3_S4", CV_CALIB_FIX_S1_S2_S3_S4);

  Class(rb_cObject).define_constant("CV_CALIB_TILTED_MODEL", CV_CALIB_TILTED_MODEL);

  Class(rb_cObject).define_constant("CV_CALIB_FIX_TAUX_TAUY", CV_CALIB_FIX_TAUX_TAUY);

  Class(rb_cObject).define_constant("CV_CALIB_FIX_TANGENT_DIST", CV_CALIB_FIX_TANGENT_DIST);

  Class(rb_cObject).define_constant("CV_CALIB_NINTRINSIC", CV_CALIB_NINTRINSIC);

  Class(rb_cObject).define_constant("CV_CALIB_FIX_INTRINSIC", CV_CALIB_FIX_INTRINSIC);

  Class(rb_cObject).define_constant("CV_CALIB_SAME_FOCAL_LENGTH", CV_CALIB_SAME_FOCAL_LENGTH);

  Class(rb_cObject).define_constant("CV_CALIB_ZERO_DISPARITY", CV_CALIB_ZERO_DISPARITY);

  Class(rb_cObject).define_constant("CV_STEREO_BM_NORMALIZED_RESPONSE", CV_STEREO_BM_NORMALIZED_RESPONSE);

  Class(rb_cObject).define_constant("CV_STEREO_BM_XSOBEL", CV_STEREO_BM_XSOBEL);

  Rice::Data_Type<CvLevMarq> rb_cCvLevMarq = define_class<CvLevMarq>("CvLevMarq").
    define_constructor(Constructor<CvLevMarq>()).
    define_constructor(Constructor<CvLevMarq, int, int, CvTermCriteria, bool>(),
      Arg("nparams"), Arg("nerrs"), Arg("criteria") = static_cast<CvTermCriteria>(cvTermCriteria(CV_TERMCRIT_EPS+CV_TERMCRIT_ITER,30,DBL_EPSILON)), Arg("complete_symm_flag") = static_cast<bool>(false)).
    define_method<void(CvLevMarq::*)(int, int, CvTermCriteria, bool)>("init", &CvLevMarq::init,
      Arg("nparams"), Arg("nerrs"), Arg("criteria") = static_cast<CvTermCriteria>(cvTermCriteria(CV_TERMCRIT_EPS+CV_TERMCRIT_ITER,30,DBL_EPSILON)), Arg("complete_symm_flag") = static_cast<bool>(false)).
    define_method<bool(CvLevMarq::*)(const CvMat*&, CvMat*&, CvMat*&)>("update", &CvLevMarq::update,
      Arg("param"), Arg("j"), Arg("err")).
    define_method<bool(CvLevMarq::*)(const CvMat*&, CvMat*&, CvMat*&, double*&)>("update_alt", &CvLevMarq::updateAlt,
      Arg("param"), Arg("jt_j"), Arg("jt_err"), Arg("err_norm")).
    define_method<void(CvLevMarq::*)()>("clear", &CvLevMarq::clear).
    define_method<void(CvLevMarq::*)()>("step", &CvLevMarq::step).
    define_attr("mask", &CvLevMarq::mask).
    define_attr("prev_param", &CvLevMarq::prevParam).
    define_attr("param", &CvLevMarq::param).
    define_attr("j", &CvLevMarq::J).
    define_attr("err", &CvLevMarq::err).
    define_attr("jt_j", &CvLevMarq::JtJ).
    define_attr("jt_jn", &CvLevMarq::JtJN).
    define_attr("jt_err", &CvLevMarq::JtErr).
    define_attr("jt_jv", &CvLevMarq::JtJV).
    define_attr("jt_jw", &CvLevMarq::JtJW).
    define_attr("prev_err_norm", &CvLevMarq::prevErrNorm).
    define_attr("err_norm", &CvLevMarq::errNorm).
    define_attr("lambda_lg10", &CvLevMarq::lambdaLg10).
    define_attr("criteria", &CvLevMarq::criteria).
    define_attr("state", &CvLevMarq::state).
    define_attr("iters", &CvLevMarq::iters).
    define_attr("complete_symm_flag", &CvLevMarq::completeSymmFlag).
    define_attr("solve_method", &CvLevMarq::solveMethod);

  rb_cCvLevMarq.define_constant("DONE", (int)CvLevMarq::DONE);
  rb_cCvLevMarq.define_constant("STARTED", (int)CvLevMarq::STARTED);
  rb_cCvLevMarq.define_constant("CALC_J", (int)CvLevMarq::CALC_J);
  rb_cCvLevMarq.define_constant("CHECK_ERR", (int)CvLevMarq::CHECK_ERR);
}