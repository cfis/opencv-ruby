#include <opencv2/core/base.hpp>
#include "base-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvHamming;

void Init_Base()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvError = define_module_under(rb_mCv, "Error");
  
  Enum<cv::Error::Code> rb_cCvErrorCode = define_enum_under<cv::Error::Code>("Code", rb_mCvError).
    define_value("StsOk", cv::Error::Code::StsOk).
    define_value("StsBackTrace", cv::Error::Code::StsBackTrace).
    define_value("StsError", cv::Error::Code::StsError).
    define_value("StsInternal", cv::Error::Code::StsInternal).
    define_value("StsNoMem", cv::Error::Code::StsNoMem).
    define_value("StsBadArg", cv::Error::Code::StsBadArg).
    define_value("StsBadFunc", cv::Error::Code::StsBadFunc).
    define_value("StsNoConv", cv::Error::Code::StsNoConv).
    define_value("StsAutoTrace", cv::Error::Code::StsAutoTrace).
    define_value("HeaderIsNull", cv::Error::Code::HeaderIsNull).
    define_value("BadImageSize", cv::Error::Code::BadImageSize).
    define_value("BadOffset", cv::Error::Code::BadOffset).
    define_value("BadDataPtr", cv::Error::Code::BadDataPtr).
    define_value("BadStep", cv::Error::Code::BadStep).
    define_value("BadModelOrChSeq", cv::Error::Code::BadModelOrChSeq).
    define_value("BadNumChannels", cv::Error::Code::BadNumChannels).
    define_value("BadNumChannel1U", cv::Error::Code::BadNumChannel1U).
    define_value("BadDepth", cv::Error::Code::BadDepth).
    define_value("BadAlphaChannel", cv::Error::Code::BadAlphaChannel).
    define_value("BadOrder", cv::Error::Code::BadOrder).
    define_value("BadOrigin", cv::Error::Code::BadOrigin).
    define_value("BadAlign", cv::Error::Code::BadAlign).
    define_value("BadCallBack", cv::Error::Code::BadCallBack).
    define_value("BadTileSize", cv::Error::Code::BadTileSize).
    define_value("BadCOI", cv::Error::Code::BadCOI).
    define_value("BadROISize", cv::Error::Code::BadROISize).
    define_value("MaskIsTiled", cv::Error::Code::MaskIsTiled).
    define_value("StsNullPtr", cv::Error::Code::StsNullPtr).
    define_value("StsVecLengthErr", cv::Error::Code::StsVecLengthErr).
    define_value("StsFilterStructContentErr", cv::Error::Code::StsFilterStructContentErr).
    define_value("StsKernelStructContentErr", cv::Error::Code::StsKernelStructContentErr).
    define_value("StsFilterOffsetErr", cv::Error::Code::StsFilterOffsetErr).
    define_value("StsBadSize", cv::Error::Code::StsBadSize).
    define_value("StsDivByZero", cv::Error::Code::StsDivByZero).
    define_value("StsInplaceNotSupported", cv::Error::Code::StsInplaceNotSupported).
    define_value("StsObjectNotFound", cv::Error::Code::StsObjectNotFound).
    define_value("StsUnmatchedFormats", cv::Error::Code::StsUnmatchedFormats).
    define_value("StsBadFlag", cv::Error::Code::StsBadFlag).
    define_value("StsBadPoint", cv::Error::Code::StsBadPoint).
    define_value("StsBadMask", cv::Error::Code::StsBadMask).
    define_value("StsUnmatchedSizes", cv::Error::Code::StsUnmatchedSizes).
    define_value("StsUnsupportedFormat", cv::Error::Code::StsUnsupportedFormat).
    define_value("StsOutOfRange", cv::Error::Code::StsOutOfRange).
    define_value("StsParseError", cv::Error::Code::StsParseError).
    define_value("StsNotImplemented", cv::Error::Code::StsNotImplemented).
    define_value("StsBadMemBlock", cv::Error::Code::StsBadMemBlock).
    define_value("StsAssert", cv::Error::Code::StsAssert).
    define_value("GpuNotSupported", cv::Error::Code::GpuNotSupported).
    define_value("GpuApiCallError", cv::Error::Code::GpuApiCallError).
    define_value("OpenGlNotSupported", cv::Error::Code::OpenGlNotSupported).
    define_value("OpenGlApiCallError", cv::Error::Code::OpenGlApiCallError).
    define_value("OpenCLApiCallError", cv::Error::Code::OpenCLApiCallError).
    define_value("OpenCLDoubleNotSupported", cv::Error::Code::OpenCLDoubleNotSupported).
    define_value("OpenCLInitError", cv::Error::Code::OpenCLInitError).
    define_value("OpenCLNoAMDBlasFft", cv::Error::Code::OpenCLNoAMDBlasFft);
  
  Enum<cv::DecompTypes> rb_cCvDecompTypes = define_enum_under<cv::DecompTypes>("DecompTypes", rb_mCv).
    define_value("DECOMP_LU", cv::DecompTypes::DECOMP_LU).
    define_value("DECOMP_SVD", cv::DecompTypes::DECOMP_SVD).
    define_value("DECOMP_EIG", cv::DecompTypes::DECOMP_EIG).
    define_value("DECOMP_CHOLESKY", cv::DecompTypes::DECOMP_CHOLESKY).
    define_value("DECOMP_QR", cv::DecompTypes::DECOMP_QR).
    define_value("DECOMP_NORMAL", cv::DecompTypes::DECOMP_NORMAL);
  
  Enum<cv::NormTypes> rb_cCvNormTypes = define_enum_under<cv::NormTypes>("NormTypes", rb_mCv).
    define_value("NORM_INF", cv::NormTypes::NORM_INF).
    define_value("NORM_L1", cv::NormTypes::NORM_L1).
    define_value("NORM_L2", cv::NormTypes::NORM_L2).
    define_value("NORM_L2SQR", cv::NormTypes::NORM_L2SQR).
    define_value("NORM_HAMMING", cv::NormTypes::NORM_HAMMING).
    define_value("NORM_HAMMING2", cv::NormTypes::NORM_HAMMING2).
    define_value("NORM_TYPE_MASK", cv::NormTypes::NORM_TYPE_MASK).
    define_value("NORM_RELATIVE", cv::NormTypes::NORM_RELATIVE).
    define_value("NORM_MINMAX", cv::NormTypes::NORM_MINMAX);
  
  Enum<cv::CmpTypes> rb_cCvCmpTypes = define_enum_under<cv::CmpTypes>("CmpTypes", rb_mCv).
    define_value("CMP_EQ", cv::CmpTypes::CMP_EQ).
    define_value("CMP_GT", cv::CmpTypes::CMP_GT).
    define_value("CMP_GE", cv::CmpTypes::CMP_GE).
    define_value("CMP_LT", cv::CmpTypes::CMP_LT).
    define_value("CMP_LE", cv::CmpTypes::CMP_LE).
    define_value("CMP_NE", cv::CmpTypes::CMP_NE);
  
  Enum<cv::GemmFlags> rb_cCvGemmFlags = define_enum_under<cv::GemmFlags>("GemmFlags", rb_mCv).
    define_value("GEMM_1_T", cv::GemmFlags::GEMM_1_T).
    define_value("GEMM_2_T", cv::GemmFlags::GEMM_2_T).
    define_value("GEMM_3_T", cv::GemmFlags::GEMM_3_T);
  
  Enum<cv::DftFlags> rb_cCvDftFlags = define_enum_under<cv::DftFlags>("DftFlags", rb_mCv).
    define_value("DFT_INVERSE", cv::DftFlags::DFT_INVERSE).
    define_value("DFT_SCALE", cv::DftFlags::DFT_SCALE).
    define_value("DFT_ROWS", cv::DftFlags::DFT_ROWS).
    define_value("DFT_COMPLEX_OUTPUT", cv::DftFlags::DFT_COMPLEX_OUTPUT).
    define_value("DFT_REAL_OUTPUT", cv::DftFlags::DFT_REAL_OUTPUT).
    define_value("DFT_COMPLEX_INPUT", cv::DftFlags::DFT_COMPLEX_INPUT).
    define_value("DCT_INVERSE", cv::DftFlags::DCT_INVERSE).
    define_value("DCT_ROWS", cv::DftFlags::DCT_ROWS);
  
  Enum<cv::BorderTypes> rb_cCvBorderTypes = define_enum_under<cv::BorderTypes>("BorderTypes", rb_mCv).
    define_value("BORDER_CONSTANT", cv::BorderTypes::BORDER_CONSTANT).
    define_value("BORDER_REPLICATE", cv::BorderTypes::BORDER_REPLICATE).
    define_value("BORDER_REFLECT", cv::BorderTypes::BORDER_REFLECT).
    define_value("BORDER_WRAP", cv::BorderTypes::BORDER_WRAP).
    define_value("BORDER_REFLECT_101", cv::BorderTypes::BORDER_REFLECT_101).
    define_value("BORDER_TRANSPARENT", cv::BorderTypes::BORDER_TRANSPARENT).
    define_value("BORDER_REFLECT101", cv::BorderTypes::BORDER_REFLECT101).
    define_value("BORDER_DEFAULT", cv::BorderTypes::BORDER_DEFAULT).
    define_value("BORDER_ISOLATED", cv::BorderTypes::BORDER_ISOLATED);
  
  rb_mCv.define_module_function("error", &cv::error,
    Arg("_code"), Arg("_err"), Arg("_func"), Arg("_file"), Arg("_line"));
  
  rb_cCvHamming = define_class_under<cv::Hamming>(rb_mCv, "Hamming").
    define_constructor(Constructor<cv::Hamming>()).
    define_constant("NormType", cv::Hamming::normType).
    define_method("call", &cv::Hamming::operator(),
      Arg("a"), Arg("b"), Arg("size"));
  
  rb_mCv.define_module_function<int(*)(uchar)>("cv_abs", &cv::cv_abs,
    Arg("x"));
  
  rb_mCv.define_module_function<int(*)(schar)>("cv_abs", &cv::cv_abs,
    Arg("x"));
  
  rb_mCv.define_module_function<int(*)(ushort)>("cv_abs", &cv::cv_abs,
    Arg("x"));
  
  rb_mCv.define_module_function<int(*)(short)>("cv_abs", &cv::cv_abs,
    Arg("x"));
  
//  rb_mCv.define_module_function("norm_l2_sqr", &cv::normL2Sqr,
//    Arg("a"), Arg("b"), Arg("n"));
  
  rb_mCv.define_module_function<float(*)(const float*, const float*, int)>("norm_l1", &cv::normL1,
    Arg("a"), Arg("b"), Arg("n"));
  
  rb_mCv.define_module_function<int(*)(const uchar*, const uchar*, int)>("norm_l1", &cv::normL1,
    Arg("a"), Arg("b"), Arg("n"));
  
  rb_mCv.define_module_function<float(*)(float)>("cube_root", &cv::cubeRoot,
    Arg("val"));
  
  rb_mCv.define_module_function<double(*)(double)>("cube_root", &cv::cubeRoot,
    Arg("val"));
  
  rb_mCv.define_module_function("fast_atan2", &cv::fastAtan2,
    Arg("y"), Arg("x"));
  
  rb_mCv.define_module_function<int(*)(float*, ::size_t, int, float*, ::size_t, int)>("lu", &cv::LU,
    Arg("a"), Arg("astep"), Arg("m"), Arg("b"), Arg("bstep"), Arg("n"));
  
  rb_mCv.define_module_function<int(*)(double*, ::size_t, int, double*, ::size_t, int)>("lu", &cv::LU,
    Arg("a"), Arg("astep"), Arg("m"), Arg("b"), Arg("bstep"), Arg("n"));
  
  rb_mCv.define_module_function<bool(*)(float*, ::size_t, int, float*, ::size_t, int)>("cholesky?", &cv::Cholesky,
    Arg("a"), Arg("astep"), Arg("m"), Arg("b"), Arg("bstep"), Arg("n"));
  
  rb_mCv.define_module_function<bool(*)(double*, ::size_t, int, double*, ::size_t, int)>("cholesky?", &cv::Cholesky,
    Arg("a"), Arg("astep"), Arg("m"), Arg("b"), Arg("bstep"), Arg("n"));
  
  Module rb_mCvOgl = define_module_under(rb_mCv, "Ogl");
  
  
  Module rb_mCvCuda = define_module_under(rb_mCv, "Cuda");
  
  
  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");
  
  
  Module rb_mCvIpp = define_module_under(rb_mCv, "Ipp");
  
  rb_mCvIpp.define_module_function("get_ipp_features", &cv::ipp::getIppFeatures);
  
  rb_mCvIpp.define_module_function("set_ipp_status", &cv::ipp::setIppStatus,
    Arg("status"), Arg("funcname") = static_cast<const char *const>(NULL), Arg("filename") = static_cast<const char *const>(NULL), Arg("line") = static_cast<int>(0));
  
  rb_mCvIpp.define_module_function("get_ipp_status", &cv::ipp::getIppStatus);
  
  rb_mCvIpp.define_module_function("get_ipp_error_location", &cv::ipp::getIppErrorLocation);
  
  rb_mCvIpp.define_module_function("use_ipp?", &cv::ipp::useIPP);
  
  rb_mCvIpp.define_module_function("set_use_ipp", &cv::ipp::setUseIPP,
    Arg("flag"));
  
  rb_mCvIpp.define_module_function("get_ipp_version", &cv::ipp::getIppVersion);
  
  rb_mCvIpp.define_module_function("use_ipp_not_exact?", &cv::ipp::useIPP_NotExact);
  
  rb_mCvIpp.define_module_function("set_use_ipp_not_exact", &cv::ipp::setUseIPP_NotExact,
    Arg("flag"));
  
  rb_mCvIpp.define_module_function("use_ipp_ne?", &cv::ipp::useIPP_NE);
  
  rb_mCvIpp.define_module_function("set_use_ipp_ne", &cv::ipp::setUseIPP_NE,
    Arg("flag"));

}