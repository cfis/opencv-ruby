#include <opencv2/core.hpp>
#include "core-rb.hpp"

using namespace Rice;

// Manual
Rice::Class rb_eCvStsBackTrace;
Rice::Class rb_eCvStsError;
Rice::Class rb_eCvStsInternal;
Rice::Class rb_eCvStsNoMem;
Rice::Class rb_eCvStsBadArg;
Rice::Class rb_eCvStsBadFunc;
Rice::Class rb_eCvStsNoConv;
Rice::Class rb_eCvStsAutoTrace;
Rice::Class rb_eCvHeaderIsNull;
Rice::Class rb_eCvBadImageSize;
Rice::Class rb_eCvBadOffset;
Rice::Class rb_eCvBadDataPtr;
Rice::Class rb_eCvBadStep;
Rice::Class rb_eCvBadModelOrChSeq;
Rice::Class rb_eCvBadNumChannels;
Rice::Class rb_eCvBadNumChannel1U;
Rice::Class rb_eCvBadDepth;
Rice::Class rb_eCvBadAlphaChannel;
Rice::Class rb_eCvBadOrder;
Rice::Class rb_eCvBadOrigin;
Rice::Class rb_eCvBadAlign;
Rice::Class rb_eCvBadCallBack;
Rice::Class rb_eCvBadTileSize;
Rice::Class rb_eCvBadCOI;
Rice::Class rb_eCvBadROISize;
Rice::Class rb_eCvMaskIsTiled;
Rice::Class rb_eCvStsNullPtr;
Rice::Class rb_eCvStsVecLengthErr;
Rice::Class rb_eCvStsFilterStructContentErr;
Rice::Class rb_eCvStsKernelStructContentErr;
Rice::Class rb_eCvStsFilterOffsetErr;
Rice::Class rb_eCvStsBadSize;
Rice::Class rb_eCvStsDivByZero;
Rice::Class rb_eCvStsInplaceNotSupported;
Rice::Class rb_eCvStsObjectNotFound;
Rice::Class rb_eCvStsUnmatchedFormats;
Rice::Class rb_eCvStsBadFlag;
Rice::Class rb_eCvStsBadPoint;
Rice::Class rb_eCvStsBadMask;
Rice::Class rb_eCvStsUnmatchedSizes;
Rice::Class rb_eCvStsUnsupportedFormat;
Rice::Class rb_eCvStsOutOfRange;
Rice::Class rb_eCvStsParseError;
Rice::Class rb_eCvStsNotImplemented;
Rice::Class rb_eCvStsBadMemBlock;
Rice::Class rb_eCvStsAssert;
Rice::Class rb_eCvGpuNotSupported;
Rice::Class rb_eCvGpuApiCallError;
Rice::Class rb_eCvOpenGlNotSupported;
Rice::Class rb_eCvOpenGlApiCallError;
Rice::Class rb_eCvOpenCLApiCallError;
Rice::Class rb_eCvOpenCLDoubleNotSupported;
Rice::Class rb_eCvOpenCLInitError;
Rice::Class rb_eCvOpenCLNoAMDBlasFft;

void handleCvException()
{
  try
  {
    throw;
  }
  catch (const cv::Exception& exception)
  {
    Class rubyExceptionClass = rb_eCvException;

    switch (exception.code)
    {
      case cv::Error::StsBackTrace:
        rubyExceptionClass = rb_eCvStsBackTrace;
        break;
      case cv::Error::StsError:
        rubyExceptionClass = rb_eCvStsError;
        break;
      case cv::Error::StsInternal:
        rubyExceptionClass = rb_eCvStsInternal;
        break;
      case cv::Error::StsNoMem:
        rubyExceptionClass = rb_eCvStsNoMem;
        break;
      case cv::Error::StsBadArg:
        rubyExceptionClass = rb_eCvStsBadArg;
        break;
      case cv::Error::StsBadFunc:
        rubyExceptionClass = rb_eCvStsBadFunc;
        break;
      case cv::Error::StsNoConv:
        rubyExceptionClass = rb_eCvStsNoConv;
        break;
      case cv::Error::StsAutoTrace:
        rubyExceptionClass = rb_eCvStsAutoTrace;
        break;
      case cv::Error::HeaderIsNull:
        rubyExceptionClass = rb_eCvHeaderIsNull;
        break;
      case cv::Error::BadImageSize:
        rubyExceptionClass = rb_eCvBadImageSize;
        break;
      case cv::Error::BadOffset:
        rubyExceptionClass = rb_eCvBadOffset;
        break;
      case cv::Error::BadDataPtr:
        rubyExceptionClass = rb_eCvBadDataPtr;
        break;
      case cv::Error::BadStep:
        rubyExceptionClass = rb_eCvBadStep;
        break;
      case cv::Error::BadModelOrChSeq:
        rubyExceptionClass = rb_eCvBadModelOrChSeq;
        break;
      case cv::Error::BadNumChannels:
        rubyExceptionClass = rb_eCvBadNumChannels;
        break;
      case cv::Error::BadNumChannel1U:
        rubyExceptionClass = rb_eCvBadNumChannel1U;
        break;
      case cv::Error::BadDepth:
        rubyExceptionClass = rb_eCvBadDepth;
        break;
      case cv::Error::BadAlphaChannel:
        rubyExceptionClass = rb_eCvBadAlphaChannel;
        break;
      case cv::Error::BadOrder:
        rubyExceptionClass = rb_eCvBadOrder;
        break;
      case cv::Error::BadOrigin:
        rubyExceptionClass = rb_eCvBadOrigin;
        break;
      case cv::Error::BadAlign:
        rubyExceptionClass = rb_eCvBadAlign;
        break;
      case cv::Error::BadCallBack:
        rubyExceptionClass = rb_eCvBadCallBack;
        break;
      case cv::Error::BadTileSize:
        rubyExceptionClass = rb_eCvBadTileSize;
        break;
      case cv::Error::BadCOI:
        rubyExceptionClass = rb_eCvBadCOI;
        break;
      case cv::Error::BadROISize:
        rubyExceptionClass = rb_eCvBadROISize;
        break;
      case cv::Error::MaskIsTiled:
        rubyExceptionClass = rb_eCvMaskIsTiled;
        break;
      case cv::Error::StsNullPtr:
        rubyExceptionClass = rb_eCvStsNullPtr;
        break;
      case cv::Error::StsVecLengthErr:
        rubyExceptionClass = rb_eCvStsVecLengthErr;
        break;
      case cv::Error::StsFilterStructContentErr:
        rubyExceptionClass = rb_eCvStsFilterStructContentErr;
        break;
      case cv::Error::StsKernelStructContentErr:
        rubyExceptionClass = rb_eCvStsKernelStructContentErr;
        break;
      case cv::Error::StsFilterOffsetErr:
        rubyExceptionClass = rb_eCvStsFilterOffsetErr;
        break;
      case cv::Error::StsBadSize:
        rubyExceptionClass = rb_eCvStsBadSize;
        break;
      case cv::Error::StsDivByZero:
        rubyExceptionClass = rb_eCvStsDivByZero;
        break;
      case cv::Error::StsInplaceNotSupported:
        rubyExceptionClass = rb_eCvStsInplaceNotSupported;
        break;
      case cv::Error::StsObjectNotFound:
        rubyExceptionClass = rb_eCvStsObjectNotFound;
        break;
      case cv::Error::StsUnmatchedFormats:
        rubyExceptionClass = rb_eCvStsUnmatchedFormats;
        break;
      case cv::Error::StsBadFlag:
        rubyExceptionClass = rb_eCvStsBadFlag;
        break;
      case cv::Error::StsBadPoint:
        rubyExceptionClass = rb_eCvStsBadPoint;
        break;
      case cv::Error::StsBadMask:
        rubyExceptionClass = rb_eCvStsBadMask;
        break;
      case cv::Error::StsUnmatchedSizes:
        rubyExceptionClass = rb_eCvStsUnmatchedSizes;
        break;
      case cv::Error::StsUnsupportedFormat:
        rubyExceptionClass = rb_eCvStsUnsupportedFormat;
        break;
      case cv::Error::StsOutOfRange:
        rubyExceptionClass = rb_eCvStsOutOfRange;
        break;
      case cv::Error::StsParseError:
        rubyExceptionClass = rb_eCvStsParseError;
        break;
      case cv::Error::StsNotImplemented:
        rubyExceptionClass = rb_eCvStsNotImplemented;
        break;
      case cv::Error::StsBadMemBlock:
        rubyExceptionClass = rb_eCvStsBadMemBlock;
        break;
      case cv::Error::StsAssert:
        rubyExceptionClass = rb_eCvStsAssert;
        break;
      case cv::Error::GpuNotSupported:
        rubyExceptionClass = rb_eCvGpuNotSupported;
        break;
      case cv::Error::GpuApiCallError:
        rubyExceptionClass = rb_eCvGpuApiCallError;
        break;
      case cv::Error::OpenGlNotSupported:
        rubyExceptionClass = rb_eCvOpenGlNotSupported;
        break;
      case cv::Error::OpenGlApiCallError:
        rubyExceptionClass = rb_eCvOpenGlApiCallError;
        break;
      case cv::Error::OpenCLApiCallError:
        rubyExceptionClass = rb_eCvOpenCLApiCallError;
        break;
      case cv::Error::OpenCLDoubleNotSupported:
        rubyExceptionClass = rb_eCvOpenCLDoubleNotSupported;
        break;
      case cv::Error::OpenCLInitError:
        rubyExceptionClass = rb_eCvOpenCLInitError;
        break;
      case cv::Error::OpenCLNoAMDBlasFft:
        rubyExceptionClass = rb_eCvOpenCLNoAMDBlasFft;
        break;
    }

    // Take ownership of the exception (meaning a copy will be made). Also 
    // specify the exception class we want to use
    Data_Object<cv::Exception> wrapped(exception, true, rubyExceptionClass);
    rb_exc_raise(wrapped.value());
  }
}

void Init_Core()
{
  Module rb_mCv = define_module("Cv");

  Rice::Data_Type<cv::Exception> rb_cCvException = define_class_under<cv::Exception, std::exception>(rb_mCv, "Exception").
    define_constructor(Constructor<cv::Exception>()).
    define_constructor(Constructor<cv::Exception, int, const cv::String&, const cv::String&, const cv::String&, int>(),
      Arg("_code"), Arg("_err"), Arg("_func"), Arg("_file"), Arg("_line")).
    define_method("what", &cv::Exception::what).
    define_method("format_message", &cv::Exception::formatMessage).
    define_attr("msg", &cv::Exception::msg).
    define_attr("code", &cv::Exception::code).
    define_attr("err", &cv::Exception::err).
    define_attr("func", &cv::Exception::func).
    define_attr("file", &cv::Exception::file).
    define_attr("line", &cv::Exception::line);

  // Manual marshalling needed for RubyMine debugger
  rb_cCvException.
    define_method("_dump_data", [](const cv::Exception& self) -> Rice::Hash
      {
        Rice::Hash result;
        result["msg"] = self.msg;
        result["code"] = self.code;
        result["err"] = self.err;
        result["func"] = self.func;
        result["file"] = self.file;
        result["line"] = self.line;

        return result;
      });

  // Define separate exception classes for each error code
  rb_eCvStsBackTrace = define_class_under(rb_mCv, "StsBackTrace", rb_eCvException);
  rb_eCvStsError = define_class_under(rb_mCv, "StsError", rb_eCvException);
  rb_eCvStsInternal = define_class_under(rb_mCv, "StsInternal", rb_eCvException);
  rb_eCvStsNoMem = define_class_under(rb_mCv, "StsNoMem", rb_eCvException);
  rb_eCvStsBadArg = define_class_under(rb_mCv, "StsBadArg", rb_eCvException);
  rb_eCvStsBadFunc = define_class_under(rb_mCv, "StsBadFunc", rb_eCvException);
  rb_eCvStsNoConv = define_class_under(rb_mCv, "StsNoConv", rb_eCvException);
  rb_eCvStsAutoTrace = define_class_under(rb_mCv, "StsAutoTrace", rb_eCvException);
  rb_eCvHeaderIsNull = define_class_under(rb_mCv, "HeaderIsNull", rb_eCvException);
  rb_eCvBadImageSize = define_class_under(rb_mCv, "BadImageSize", rb_eCvException);
  rb_eCvBadOffset = define_class_under(rb_mCv, "BadOffset", rb_eCvException);
  rb_eCvBadDataPtr = define_class_under(rb_mCv, "BadDataPtr", rb_eCvException);
  rb_eCvBadStep = define_class_under(rb_mCv, "BadStep", rb_eCvException);
  rb_eCvBadModelOrChSeq = define_class_under(rb_mCv, "BadModelOrChSeq", rb_eCvException);
  rb_eCvBadNumChannels = define_class_under(rb_mCv, "BadNumChannels", rb_eCvException);
  rb_eCvBadNumChannel1U = define_class_under(rb_mCv, "BadNumChannel1U", rb_eCvException);
  rb_eCvBadDepth = define_class_under(rb_mCv, "BadDepth", rb_eCvException);
  rb_eCvBadAlphaChannel = define_class_under(rb_mCv, "BadAlphaChannel", rb_eCvException);
  rb_eCvBadOrder = define_class_under(rb_mCv, "BadOrder", rb_eCvException);
  rb_eCvBadOrigin = define_class_under(rb_mCv, "BadOrigin", rb_eCvException);
  rb_eCvBadAlign = define_class_under(rb_mCv, "BadAlign", rb_eCvException);
  rb_eCvBadCallBack = define_class_under(rb_mCv, "BadCallBack", rb_eCvException);
  rb_eCvBadTileSize = define_class_under(rb_mCv, "BadTileSize", rb_eCvException);
  rb_eCvBadCOI = define_class_under(rb_mCv, "BadCOI", rb_eCvException);
  rb_eCvBadROISize = define_class_under(rb_mCv, "BadROISize", rb_eCvException);
  rb_eCvMaskIsTiled = define_class_under(rb_mCv, "MaskIsTiled", rb_eCvException);
  rb_eCvStsNullPtr = define_class_under(rb_mCv, "StsNullPtr", rb_eCvException);
  rb_eCvStsVecLengthErr = define_class_under(rb_mCv, "StsVecLengthErr", rb_eCvException);
  rb_eCvStsFilterStructContentErr = define_class_under(rb_mCv, "StsFilterStructContentErr", rb_eCvException);
  rb_eCvStsKernelStructContentErr = define_class_under(rb_mCv, "StsKernelStructContentErr", rb_eCvException);
  rb_eCvStsFilterOffsetErr = define_class_under(rb_mCv, "StsFilterOffsetErr", rb_eCvException);
  rb_eCvStsBadSize = define_class_under(rb_mCv, "StsBadSize", rb_eCvException);
  rb_eCvStsDivByZero = define_class_under(rb_mCv, "StsDivByZero", rb_eCvException);
  rb_eCvStsInplaceNotSupported = define_class_under(rb_mCv, "StsInplaceNotSupported", rb_eCvException);
  rb_eCvStsObjectNotFound = define_class_under(rb_mCv, "StsObjectNotFound", rb_eCvException);
  rb_eCvStsUnmatchedFormats = define_class_under(rb_mCv, "StsUnmatchedFormats", rb_eCvException);
  rb_eCvStsBadFlag = define_class_under(rb_mCv, "StsBadFlag", rb_eCvException);
  rb_eCvStsBadPoint = define_class_under(rb_mCv, "StsBadPoint", rb_eCvException);
  rb_eCvStsBadMask = define_class_under(rb_mCv, "StsBadMask", rb_eCvException);
  rb_eCvStsUnmatchedSizes = define_class_under(rb_mCv, "StsUnmatchedSizes", rb_eCvException);
  rb_eCvStsUnsupportedFormat = define_class_under(rb_mCv, "StsUnsupportedFormat", rb_eCvException);
  rb_eCvStsOutOfRange = define_class_under(rb_mCv, "StsOutOfRange", rb_eCvException);
  rb_eCvStsParseError = define_class_under(rb_mCv, "StsParseError", rb_eCvException);
  rb_eCvStsNotImplemented = define_class_under(rb_mCv, "StsNotImplemented", rb_eCvException);
  rb_eCvStsBadMemBlock = define_class_under(rb_mCv, "StsBadMemBlock", rb_eCvException);
  rb_eCvStsAssert = define_class_under(rb_mCv, "StsAssert", rb_eCvException);
  rb_eCvGpuNotSupported = define_class_under(rb_mCv, "GpuNotSupported", rb_eCvException);
  rb_eCvGpuApiCallError = define_class_under(rb_mCv, "GpuApiCallError", rb_eCvException);
  rb_eCvOpenGlNotSupported = define_class_under(rb_mCv, "OpenGlNotSupported", rb_eCvException);
  rb_eCvOpenGlApiCallError = define_class_under(rb_mCv, "OpenGlApiCallError", rb_eCvException);
  rb_eCvOpenCLApiCallError = define_class_under(rb_mCv, "OpenCLApiCallError", rb_eCvException);
  rb_eCvOpenCLDoubleNotSupported = define_class_under(rb_mCv, "OpenCLDoubleNotSupported", rb_eCvException);
  rb_eCvOpenCLInitError = define_class_under(rb_mCv, "OpenCLInitError", rb_eCvException);
  rb_eCvOpenCLNoAMDBlasFft = define_class_under(rb_mCv, "OpenCLNoAMDBlasFft", rb_eCvException);

  // Install custom exception handler
  detail::Registries::instance.handlers.set(handleCvException);

  rb_mCv.define_module_function("error", &cv::error,
    Arg("exc"));

  Enum<cv::SortFlags> rb_cCvSortFlags = define_enum_under<cv::SortFlags>("SortFlags", rb_mCv).
    define_value("SORT_EVERY_ROW", cv::SortFlags::SORT_EVERY_ROW).
    define_value("SORT_EVERY_COLUMN", cv::SortFlags::SORT_EVERY_COLUMN).
    define_value("SORT_ASCENDING", cv::SortFlags::SORT_ASCENDING).
    define_value("SORT_DESCENDING", cv::SortFlags::SORT_DESCENDING);

  Enum<cv::CovarFlags> rb_cCvCovarFlags = define_enum_under<cv::CovarFlags>("CovarFlags", rb_mCv).
    define_value("COVAR_SCRAMBLED", cv::CovarFlags::COVAR_SCRAMBLED).
    define_value("COVAR_NORMAL", cv::CovarFlags::COVAR_NORMAL).
    define_value("COVAR_USE_AVG", cv::CovarFlags::COVAR_USE_AVG).
    define_value("COVAR_SCALE", cv::CovarFlags::COVAR_SCALE).
    define_value("COVAR_ROWS", cv::CovarFlags::COVAR_ROWS).
    define_value("COVAR_COLS", cv::CovarFlags::COVAR_COLS);

  Enum<cv::ReduceTypes> rb_cCvReduceTypes = define_enum_under<cv::ReduceTypes>("ReduceTypes", rb_mCv).
    define_value("REDUCE_SUM", cv::ReduceTypes::REDUCE_SUM).
    define_value("REDUCE_AVG", cv::ReduceTypes::REDUCE_AVG).
    define_value("REDUCE_MAX", cv::ReduceTypes::REDUCE_MAX).
    define_value("REDUCE_MIN", cv::ReduceTypes::REDUCE_MIN);

#if RUBY_CV_VERSION >= 408
  rb_cCvReduceTypes.
    define_value("REDUCE_SUM2", cv::ReduceTypes::REDUCE_SUM2);
#endif

  rb_mCv.define_module_function<void(*)(cv::Mat&, cv::Mat&)>("swap", &cv::swap,
    Arg("a"), Arg("b"));

  rb_mCv.define_module_function<void(*)(cv::UMat&, cv::UMat&)>("swap", &cv::swap,
    Arg("a"), Arg("b"));

  rb_mCv.define_module_function("border_interpolate", &cv::borderInterpolate,
    Arg("p"), Arg("len"), Arg("border_type"));

  rb_mCv.define_module_function("copy_make_border", &cv::copyMakeBorder,
    Arg("src"), Arg("dst"), Arg("top"), Arg("bottom"), Arg("left"), Arg("right"), Arg("border_type"), Arg("value") = static_cast<const cv::Scalar&>(cv::Scalar()));

  rb_mCv.define_module_function("add", &cv::add,
    Arg("src1"), Arg("src2"), Arg("dst"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()), Arg("dtype") = static_cast<int>(-1));

  rb_mCv.define_module_function("subtract", &cv::subtract,
    Arg("src1"), Arg("src2"), Arg("dst"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()), Arg("dtype") = static_cast<int>(-1));

  rb_mCv.define_module_function("multiply", &cv::multiply,
    Arg("src1"), Arg("src2"), Arg("dst"), Arg("scale") = static_cast<double>(1), Arg("dtype") = static_cast<int>(-1));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray, double, int)>("divide", &cv::divide,
    Arg("src1"), Arg("src2"), Arg("dst"), Arg("scale") = static_cast<double>(1), Arg("dtype") = static_cast<int>(-1));

  rb_mCv.define_module_function<void(*)(double, cv::InputArray, cv::OutputArray, int)>("divide", &cv::divide,
    Arg("scale"), Arg("src2"), Arg("dst"), Arg("dtype") = static_cast<int>(-1));

  rb_mCv.define_module_function("scale_add", &cv::scaleAdd,
    Arg("src1"), Arg("alpha"), Arg("src2"), Arg("dst"));

  rb_mCv.define_module_function("add_weighted", &cv::addWeighted,
    Arg("src1"), Arg("alpha"), Arg("src2"), Arg("beta"), Arg("gamma"), Arg("dst"), Arg("dtype") = static_cast<int>(-1));

  rb_mCv.define_module_function("convert_scale_abs", &cv::convertScaleAbs,
    Arg("src"), Arg("dst"), Arg("alpha") = static_cast<double>(1), Arg("beta") = static_cast<double>(0));

  rb_mCv.define_module_function("convert_fp16", &cv::convertFp16,
    Arg("src"), Arg("dst"));

  rb_mCv.define_module_function("lut", &cv::LUT,
    Arg("src"), Arg("lut"), Arg("dst"));

  rb_mCv.define_module_function("sum", &cv::sum,
    Arg("src"));

#if RUBY_CV_VERSION >= 408
  rb_mCv.define_module_function("has_non_zero", &cv::hasNonZero,
    Arg("src"));
#endif

  rb_mCv.define_module_function("count_non_zero", &cv::countNonZero,
    Arg("src"));

  rb_mCv.define_module_function("find_non_zero", &cv::findNonZero,
    Arg("src"), Arg("idx"));

  rb_mCv.define_module_function("mean", &cv::mean,
    Arg("src"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()));

  rb_mCv.define_module_function("mean_std_dev", &cv::meanStdDev,
    Arg("src"), Arg("mean"), Arg("stddev"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()));

  rb_mCv.define_module_function<double(*)(cv::InputArray, int, cv::InputArray)>("norm", &cv::norm,
    Arg("src1"), Arg("norm_type") = static_cast<int>(cv::NORM_L2), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()));

  rb_mCv.define_module_function<double(*)(cv::InputArray, cv::InputArray, int, cv::InputArray)>("norm", &cv::norm,
    Arg("src1"), Arg("src2"), Arg("norm_type") = static_cast<int>(cv::NORM_L2), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()));

  rb_mCv.define_module_function<double(*)(const cv::SparseMat&, int)>("norm", &cv::norm,
    Arg("src"), Arg("norm_type"));

  rb_mCv.define_module_function("psnr", &cv::PSNR,
    Arg("src1"), Arg("src2"), Arg("r") = static_cast<double>(255.));

  rb_mCv.define_module_function("batch_distance", &cv::batchDistance,
    Arg("src1"), Arg("src2"), Arg("dist"), Arg("dtype"), Arg("nidx"), Arg("norm_type") = static_cast<int>(cv::NORM_L2), Arg("k") = static_cast<int>(0), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()), Arg("update") = static_cast<int>(0), Arg("crosscheck") = static_cast<bool>(false));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::InputOutputArray, double, double, int, int, cv::InputArray)>("normalize", &cv::normalize,
    Arg("src"), Arg("dst"), Arg("alpha") = static_cast<double>(1), Arg("beta") = static_cast<double>(0), Arg("norm_type") = static_cast<int>(cv::NORM_L2), Arg("dtype") = static_cast<int>(-1), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()));

  rb_mCv.define_module_function<void(*)(const cv::SparseMat&, cv::SparseMat&, double, int)>("normalize", &cv::normalize,
    Arg("src"), Arg("dst"), Arg("alpha"), Arg("norm_type"));

  rb_mCv.define_module_function<void(*)(cv::InputArray, double*, double*, cv::Point*, cv::Point*, cv::InputArray)>("min_max_loc", &cv::minMaxLoc,
    Arg("src"), ArgBuffer("min_val"), ArgBuffer("max_val") = static_cast<double*>(0), Arg("min_loc") = static_cast<cv::Point*>(0), Arg("max_loc") = static_cast<cv::Point*>(0), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()));

  rb_mCv.define_module_function("min_max_loc", [](cv::InputArray src, cv::InputArray mask = cv::noArray()) -> std::tuple<double, double, cv::Point, cv::Point>
  {
    double minVal = 0;
    double maxVal = 0;
    cv::Point minLoc;
    cv::Point maxLoc;

    int type = src.type();
    int cn = CV_MAT_CN(type);

    if (cn == 1)
    {
      cv::minMaxLoc(src, &minVal, &maxVal, &minLoc, &maxLoc, mask);
    }
    else
    {
      cv::minMaxLoc(src, &minVal, &maxVal, nullptr, nullptr, cv::noArray());
    }
    return std::forward_as_tuple(minVal, maxVal, minLoc, maxLoc);
  },
  Arg("src"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()));

  rb_mCv.define_module_function("reduce_arg_min", &cv::reduceArgMin,
    Arg("src"), Arg("dst"), Arg("axis"), Arg("last_index") = static_cast<bool>(false));

  rb_mCv.define_module_function("reduce_arg_max", &cv::reduceArgMax,
    Arg("src"), Arg("dst"), Arg("axis"), Arg("last_index") = static_cast<bool>(false));

  rb_mCv.define_module_function("min_max_idx", &cv::minMaxIdx,
    Arg("src"), ArgBuffer("min_val"), ArgBuffer("max_val") = static_cast<double*>(0), ArgBuffer("min_idx") = static_cast<int*>(0), ArgBuffer("max_idx") = static_cast<int*>(0), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()));

  rb_mCv.define_module_function<void(*)(const cv::SparseMat&, double*, double*, int*, int*)>("min_max_loc", &cv::minMaxLoc,
    Arg("a"), ArgBuffer("min_val"), ArgBuffer("max_val"), ArgBuffer("min_idx") = static_cast<int*>(0), ArgBuffer("max_idx") = static_cast<int*>(0));

  rb_mCv.define_module_function("min_max_loc", [](const cv::SparseMat& src) -> std::tuple<double, double, int, int>
  {
    double minVal = 0;
    double maxVal = 0;
    int minIdx = 0;
    int maxIdx = 0;

    cv::minMaxLoc(src, &minVal, &maxVal, &minIdx, &maxIdx);
    return std::forward_as_tuple(minVal, maxVal, minIdx, maxIdx);
  },
  Arg("src"));

  rb_mCv.define_module_function("reduce", &cv::reduce,
    Arg("src"), Arg("dst"), Arg("dim"), Arg("rtype"), Arg("dtype") = static_cast<int>(-1));

  rb_mCv.define_module_function<void(*)(const cv::Mat*, size_t, cv::OutputArray)>("merge", &cv::merge,
    Arg("mv"), Arg("count"), Arg("dst"));

  rb_mCv.define_module_function<void(*)(cv::InputArrayOfArrays, cv::OutputArray)>("merge", &cv::merge,
    Arg("mv"), Arg("dst"));

  rb_mCv.define_module_function<void(*)(const cv::Mat&, cv::Mat*)>("split", &cv::split,
    Arg("src"), Arg("mvbegin"));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArrayOfArrays)>("split", &cv::split,
    Arg("m"), Arg("mv"));

  rb_mCv.define_module_function<void(*)(const cv::Mat*, size_t, cv::Mat*, size_t, const int*, size_t)>("mix_channels", &cv::mixChannels,
    Arg("src"), Arg("nsrcs"), Arg("dst"), Arg("ndsts"), ArgBuffer("from_to"), Arg("npairs"));

  rb_mCv.define_module_function<void(*)(cv::InputArrayOfArrays, cv::InputOutputArrayOfArrays, const int*, size_t)>("mix_channels", &cv::mixChannels,
    Arg("src"), Arg("dst"), ArgBuffer("from_to"), Arg("npairs"));

  rb_mCv.define_module_function<void(*)(cv::InputArrayOfArrays, cv::InputOutputArrayOfArrays, const std::vector<int>&)>("mix_channels", &cv::mixChannels,
    Arg("src"), Arg("dst"), Arg("from_to"));

  rb_mCv.define_module_function("extract_channel", &cv::extractChannel,
    Arg("src"), Arg("dst"), Arg("coi"));

  rb_mCv.define_module_function("insert_channel", &cv::insertChannel,
    Arg("src"), Arg("dst"), Arg("coi"));

  rb_mCv.define_module_function("flip", &cv::flip,
    Arg("src"), Arg("dst"), Arg("flip_code"));

#if RUBY_CV_VERSION >= 407
  rb_mCv.define_module_function("flip_nd", &cv::flipND,
    Arg("src"), Arg("dst"), Arg("axis"));
#endif

#if RUBY_CV_VERSION >= 409
  rb_mCv.define_module_function("broadcast", &cv::broadcast,
    Arg("src"), Arg("shape"), Arg("dst"));
#endif

  Enum<cv::RotateFlags> rb_cCvRotateFlags = define_enum_under<cv::RotateFlags>("RotateFlags", rb_mCv).
    define_value("ROTATE_90_CLOCKWISE", cv::RotateFlags::ROTATE_90_CLOCKWISE).
    define_value("ROTATE_180", cv::RotateFlags::ROTATE_180).
    define_value("ROTATE_90_COUNTERCLOCKWISE", cv::RotateFlags::ROTATE_90_COUNTERCLOCKWISE);

  rb_mCv.define_module_function("rotate", &cv::rotate,
    Arg("src"), Arg("dst"), Arg("rotate_code"));

  rb_mCv.define_module_function<void(*)(cv::InputArray, int, int, cv::OutputArray)>("repeat", &cv::repeat,
    Arg("src"), Arg("ny"), Arg("nx"), Arg("dst"));

  rb_mCv.define_module_function<cv::Mat(*)(const cv::Mat&, int, int)>("repeat", &cv::repeat,
    Arg("src"), Arg("ny"), Arg("nx"));

  rb_mCv.define_module_function<void(*)(const cv::Mat*, size_t, cv::OutputArray)>("hconcat", &cv::hconcat,
    Arg("src"), Arg("nsrc"), Arg("dst"));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray)>("hconcat", &cv::hconcat,
    Arg("src1"), Arg("src2"), Arg("dst"));

  rb_mCv.define_module_function<void(*)(cv::InputArrayOfArrays, cv::OutputArray)>("hconcat", &cv::hconcat,
    Arg("src"), Arg("dst"));

  rb_mCv.define_module_function<void(*)(const cv::Mat*, size_t, cv::OutputArray)>("vconcat", &cv::vconcat,
    Arg("src"), Arg("nsrc"), Arg("dst"));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray)>("vconcat", &cv::vconcat,
    Arg("src1"), Arg("src2"), Arg("dst"));

  rb_mCv.define_module_function<void(*)(cv::InputArrayOfArrays, cv::OutputArray)>("vconcat", &cv::vconcat,
    Arg("src"), Arg("dst"));

  rb_mCv.define_module_function("bitwise_and", &cv::bitwise_and,
    Arg("src1"), Arg("src2"), Arg("dst"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()));

  rb_mCv.define_module_function("bitwise_or", &cv::bitwise_or,
    Arg("src1"), Arg("src2"), Arg("dst"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()));

  rb_mCv.define_module_function("bitwise_xor", &cv::bitwise_xor,
    Arg("src1"), Arg("src2"), Arg("dst"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()));

  rb_mCv.define_module_function("bitwise_not", &cv::bitwise_not,
    Arg("src"), Arg("dst"), Arg("mask") = static_cast<cv::InputArray>(cv::noArray()));

  rb_mCv.define_module_function("absdiff", &cv::absdiff,
    Arg("src1"), Arg("src2"), Arg("dst"));

  rb_mCv.define_module_function("copy_to", &cv::copyTo,
    Arg("src"), Arg("dst"), Arg("mask"));

  rb_mCv.define_module_function("in_range", &cv::inRange,
    Arg("src"), Arg("lowerb"), Arg("upperb"), Arg("dst"));

  rb_mCv.define_module_function("compare", &cv::compare,
    Arg("src1"), Arg("src2"), Arg("dst"), Arg("cmpop"));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray)>("min", &cv::min,
    Arg("src1"), Arg("src2"), Arg("dst"));

  rb_mCv.define_module_function<void(*)(const cv::Mat&, const cv::Mat&, cv::Mat&)>("min", &cv::min,
    Arg("src1"), Arg("src2"), Arg("dst"));

  rb_mCv.define_module_function<void(*)(const cv::UMat&, const cv::UMat&, cv::UMat&)>("min", &cv::min,
    Arg("src1"), Arg("src2"), Arg("dst"));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::InputArray, cv::OutputArray)>("max", &cv::max,
    Arg("src1"), Arg("src2"), Arg("dst"));

  rb_mCv.define_module_function<void(*)(const cv::Mat&, const cv::Mat&, cv::Mat&)>("max", &cv::max,
    Arg("src1"), Arg("src2"), Arg("dst"));

  rb_mCv.define_module_function<void(*)(const cv::UMat&, const cv::UMat&, cv::UMat&)>("max", &cv::max,
    Arg("src1"), Arg("src2"), Arg("dst"));

  rb_mCv.define_module_function("sqrt", &cv::sqrt,
    Arg("src"), Arg("dst"));

  rb_mCv.define_module_function("pow", &cv::pow,
    Arg("src"), Arg("power"), Arg("dst"));

  rb_mCv.define_module_function("exp", &cv::exp,
    Arg("src"), Arg("dst"));

  rb_mCv.define_module_function("log", &cv::log,
    Arg("src"), Arg("dst"));

  rb_mCv.define_module_function("polar_to_cart", &cv::polarToCart,
    Arg("magnitude"), Arg("angle"), Arg("x"), Arg("y"), Arg("angle_in_degrees") = static_cast<bool>(false));

  rb_mCv.define_module_function("cart_to_polar", &cv::cartToPolar,
    Arg("x"), Arg("y"), Arg("magnitude"), Arg("angle"), Arg("angle_in_degrees") = static_cast<bool>(false));

  rb_mCv.define_module_function("phase", &cv::phase,
    Arg("x"), Arg("y"), Arg("angle"), Arg("angle_in_degrees") = static_cast<bool>(false));

  rb_mCv.define_module_function("magnitude", &cv::magnitude,
    Arg("x"), Arg("y"), Arg("magnitude"));

  rb_mCv.define_module_function("check_range", &cv::checkRange,
    Arg("a"), Arg("quiet") = static_cast<bool>(true), Arg("pos") = static_cast<cv::Point*>(0), Arg("min_val") = static_cast<double>(-DBL_MAX), Arg("max_val") = static_cast<double>(DBL_MAX));

  rb_mCv.define_module_function("patch_na_ns", &cv::patchNaNs,
    Arg("a"), Arg("val") = static_cast<double>(0));

  rb_mCv.define_module_function("gemm", &cv::gemm,
    Arg("src1"), Arg("src2"), Arg("alpha"), Arg("src3"), Arg("beta"), Arg("dst"), Arg("flags") = static_cast<int>(0));

  rb_mCv.define_module_function("mul_transposed", &cv::mulTransposed,
    Arg("src"), Arg("dst"), Arg("a_ta"), Arg("delta") = static_cast<cv::InputArray>(cv::noArray()), Arg("scale") = static_cast<double>(1), Arg("dtype") = static_cast<int>(-1));

  rb_mCv.define_module_function("transpose", &cv::transpose,
    Arg("src"), Arg("dst"));

  rb_mCv.define_module_function("transpose_nd", &cv::transposeND,
    Arg("src"), Arg("order"), Arg("dst"));

  rb_mCv.define_module_function("transform", &cv::transform,
    Arg("src"), Arg("dst"), Arg("m"));

  rb_mCv.define_module_function("perspective_transform", &cv::perspectiveTransform,
    Arg("src"), Arg("dst"), Arg("m"));

  rb_mCv.define_module_function("complete_symm", &cv::completeSymm,
    Arg("m"), Arg("lower_to_upper") = static_cast<bool>(false));

  rb_mCv.define_module_function("set_identity", &cv::setIdentity,
    Arg("mtx"), Arg("s") = static_cast<const cv::Scalar&>(cv::Scalar(1)));

  rb_mCv.define_module_function("determinant", &cv::determinant,
    Arg("mtx"));

  rb_mCv.define_module_function("trace", &cv::trace,
    Arg("mtx"));

  rb_mCv.define_module_function("invert", &cv::invert,
    Arg("src"), Arg("dst"), Arg("flags") = static_cast<int>(cv::DECOMP_LU));

  rb_mCv.define_module_function("solve", &cv::solve,
    Arg("src1"), Arg("src2"), Arg("dst"), Arg("flags") = static_cast<int>(cv::DECOMP_LU));

  rb_mCv.define_module_function("sort", &cv::sort,
    Arg("src"), Arg("dst"), Arg("flags"));

  rb_mCv.define_module_function("sort_idx", &cv::sortIdx,
    Arg("src"), Arg("dst"), Arg("flags"));

  rb_mCv.define_module_function("solve_cubic", &cv::solveCubic,
    Arg("coeffs"), Arg("roots"));

  rb_mCv.define_module_function("solve_poly", &cv::solvePoly,
    Arg("coeffs"), Arg("roots"), Arg("max_iters") = static_cast<int>(300));

  rb_mCv.define_module_function("eigen", &cv::eigen,
    Arg("src"), Arg("eigenvalues"), Arg("eigenvectors") = static_cast<cv::OutputArray>(cv::noArray()));

  rb_mCv.define_module_function("eigen_non_symmetric", &cv::eigenNonSymmetric,
    Arg("src"), Arg("eigenvalues"), Arg("eigenvectors"));

  rb_mCv.define_module_function<void(*)(const cv::Mat*, int, cv::Mat&, cv::Mat&, int, int)>("calc_covar_matrix", &cv::calcCovarMatrix,
    Arg("samples"), Arg("nsamples"), Arg("covar"), Arg("mean"), Arg("flags"), Arg("ctype") = static_cast<int>(CV_64F));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::OutputArray, cv::InputOutputArray, int, int)>("calc_covar_matrix", &cv::calcCovarMatrix,
    Arg("samples"), Arg("covar"), Arg("mean"), Arg("flags"), Arg("ctype") = static_cast<int>(CV_64F));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::InputOutputArray, cv::OutputArray, int)>("pca_compute", &cv::PCACompute,
    Arg("data"), Arg("mean"), Arg("eigenvectors"), Arg("max_components") = static_cast<int>(0));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::InputOutputArray, cv::OutputArray, cv::OutputArray, int)>("pca_compute", &cv::PCACompute,
    Arg("data"), Arg("mean"), Arg("eigenvectors"), Arg("eigenvalues"), Arg("max_components") = static_cast<int>(0));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::InputOutputArray, cv::OutputArray, double)>("pca_compute", &cv::PCACompute,
    Arg("data"), Arg("mean"), Arg("eigenvectors"), Arg("retained_variance"));

  rb_mCv.define_module_function<void(*)(cv::InputArray, cv::InputOutputArray, cv::OutputArray, cv::OutputArray, double)>("pca_compute", &cv::PCACompute,
    Arg("data"), Arg("mean"), Arg("eigenvectors"), Arg("eigenvalues"), Arg("retained_variance"));

  rb_mCv.define_module_function("pca_project", &cv::PCAProject,
    Arg("data"), Arg("mean"), Arg("eigenvectors"), Arg("result"));

  rb_mCv.define_module_function("pca_back_project", &cv::PCABackProject,
    Arg("data"), Arg("mean"), Arg("eigenvectors"), Arg("result"));

  rb_mCv.define_module_function("sv_decomp", &cv::SVDecomp,
    Arg("src"), Arg("w"), Arg("u"), Arg("vt"), Arg("flags") = static_cast<int>(0));

  rb_mCv.define_module_function("sv_back_subst", &cv::SVBackSubst,
    Arg("w"), Arg("u"), Arg("vt"), Arg("rhs"), Arg("dst"));

  rb_mCv.define_module_function("mahalanobis", &cv::Mahalanobis,
    Arg("v1"), Arg("v2"), Arg("icovar"));

  rb_mCv.define_module_function("dft", &cv::dft,
    Arg("src"), Arg("dst"), Arg("flags") = static_cast<int>(0), Arg("nonzero_rows") = static_cast<int>(0));

  rb_mCv.define_module_function("idft", &cv::idft,
    Arg("src"), Arg("dst"), Arg("flags") = static_cast<int>(0), Arg("nonzero_rows") = static_cast<int>(0));

  rb_mCv.define_module_function("dct", &cv::dct,
    Arg("src"), Arg("dst"), Arg("flags") = static_cast<int>(0));

  rb_mCv.define_module_function("idct", &cv::idct,
    Arg("src"), Arg("dst"), Arg("flags") = static_cast<int>(0));

  rb_mCv.define_module_function("mul_spectrums", &cv::mulSpectrums,
    Arg("a"), Arg("b"), Arg("c"), Arg("flags"), Arg("conj_b") = static_cast<bool>(false));

  rb_mCv.define_module_function("get_optimal_dft_size", &cv::getOptimalDFTSize,
    Arg("vecsize"));

  rb_mCv.define_module_function("the_rng", &cv::theRNG);

  rb_mCv.define_module_function("set_rng_seed", &cv::setRNGSeed,
    Arg("seed"));

  rb_mCv.define_module_function("randu", &cv::randu,
    Arg("dst"), Arg("low"), Arg("high"));

  rb_mCv.define_module_function("randn", &cv::randn,
    Arg("dst"), Arg("mean"), Arg("stddev"));

  rb_mCv.define_module_function("rand_shuffle", &cv::randShuffle,
    Arg("dst"), Arg("iter_factor") = static_cast<double>(1.), Arg("rng") = static_cast<cv::RNG*>(0));

  Rice::Data_Type<cv::PCA> rb_cCvPCA = define_class_under<cv::PCA>(rb_mCv, "PCA").
    define_constructor(Constructor<cv::PCA>()).
    define_constructor(Constructor<cv::PCA, cv::InputArray, cv::InputArray, int, int>(),
      Arg("data"), Arg("mean"), Arg("flags"), Arg("max_components") = static_cast<int>(0)).
    define_constructor(Constructor<cv::PCA, cv::InputArray, cv::InputArray, int, double>(),
      Arg("data"), Arg("mean"), Arg("flags"), Arg("retained_variance")).
    define_method<cv::PCA&(cv::PCA::*)(cv::InputArray, cv::InputArray, int, int)>("call", &cv::PCA::operator(),
      Arg("data"), Arg("mean"), Arg("flags"), Arg("max_components") = static_cast<int>(0)).
    define_method<cv::PCA&(cv::PCA::*)(cv::InputArray, cv::InputArray, int, double)>("call", &cv::PCA::operator(),
      Arg("data"), Arg("mean"), Arg("flags"), Arg("retained_variance")).
    define_method<cv::Mat(cv::PCA::*)(cv::InputArray) const>("project", &cv::PCA::project,
      Arg("vec")).
    define_method<void(cv::PCA::*)(cv::InputArray, cv::OutputArray) const>("project", &cv::PCA::project,
      Arg("vec"), Arg("result")).
    define_method<cv::Mat(cv::PCA::*)(cv::InputArray) const>("back_project", &cv::PCA::backProject,
      Arg("vec")).
    define_method<void(cv::PCA::*)(cv::InputArray, cv::OutputArray) const>("back_project", &cv::PCA::backProject,
      Arg("vec"), Arg("result")).
    define_method("write", &cv::PCA::write,
      Arg("fs")).
    define_method("read", &cv::PCA::read,
      Arg("fn")).
    define_attr("eigenvectors", &cv::PCA::eigenvectors).
    define_attr("eigenvalues", &cv::PCA::eigenvalues).
    define_attr("mean", &cv::PCA::mean);

  Enum<cv::PCA::Flags> rb_cCvPCAFlags = define_enum_under<cv::PCA::Flags>("Flags", rb_cCvPCA).
    define_value("DATA_AS_ROW", cv::PCA::Flags::DATA_AS_ROW).
    define_value("DATA_AS_COL", cv::PCA::Flags::DATA_AS_COL).
    define_value("USE_AVG", cv::PCA::Flags::USE_AVG);

  Rice::Data_Type<cv::LDA> rb_cCvLDA = define_class_under<cv::LDA>(rb_mCv, "LDA").
    define_constructor(Constructor<cv::LDA, int>(),
      Arg("num_components") = static_cast<int>(0)).
    define_constructor(Constructor<cv::LDA, cv::InputArrayOfArrays, cv::InputArray, int>(),
      Arg("src"), Arg("labels"), Arg("num_components") = static_cast<int>(0)).
    define_method<void(cv::LDA::*)(const cv::String&) const>("save", &cv::LDA::save,
      Arg("filename")).
    define_method<void(cv::LDA::*)(const cv::String&)>("load", &cv::LDA::load,
      Arg("filename")).
    define_method<void(cv::LDA::*)(cv::FileStorage&) const>("save", &cv::LDA::save,
      Arg("fs")).
    define_method<void(cv::LDA::*)(const cv::FileStorage&)>("load", &cv::LDA::load,
      Arg("node")).
    define_method("compute", &cv::LDA::compute,
      Arg("src"), Arg("labels")).
    define_method("project", &cv::LDA::project,
      Arg("src")).
    define_method("reconstruct", &cv::LDA::reconstruct,
      Arg("src")).
    define_method("eigenvectors", &cv::LDA::eigenvectors).
    define_method("eigenvalues", &cv::LDA::eigenvalues).
    define_singleton_function("subspace_project", &cv::LDA::subspaceProject,
      Arg("w"), Arg("mean"), Arg("src")).
    define_singleton_function("subspace_reconstruct", &cv::LDA::subspaceReconstruct,
      Arg("w"), Arg("mean"), Arg("src"));

  Rice::Data_Type<cv::SVD> rb_cCvSVD = define_class_under<cv::SVD>(rb_mCv, "SVD").
    define_constructor(Constructor<cv::SVD>()).
    define_constructor(Constructor<cv::SVD, cv::InputArray, int>(),
      Arg("src"), Arg("flags") = static_cast<int>(0)).
    define_method("call", &cv::SVD::operator(),
      Arg("src"), Arg("flags") = static_cast<int>(0)).
    define_method<void(cv::SVD::*)(cv::InputArray, cv::OutputArray) const>("back_subst", &cv::SVD::backSubst,
      Arg("rhs"), Arg("dst")).
    define_attr("u", &cv::SVD::u).
    define_attr("w", &cv::SVD::w).
    define_attr("vt", &cv::SVD::vt).
    define_singleton_function<void(*)(cv::InputArray, cv::OutputArray, cv::OutputArray, cv::OutputArray, int)>("compute", &cv::SVD::compute,
      Arg("src"), Arg("w"), Arg("u"), Arg("vt"), Arg("flags") = static_cast<int>(0)).
    define_singleton_function<void(*)(cv::InputArray, cv::OutputArray, int)>("compute", &cv::SVD::compute,
      Arg("src"), Arg("w"), Arg("flags") = static_cast<int>(0)).
    define_singleton_function<void(*)(cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, cv::OutputArray)>("back_subst", &cv::SVD::backSubst,
      Arg("w"), Arg("u"), Arg("vt"), Arg("rhs"), Arg("dst")).
    define_singleton_function("solve_z", &cv::SVD::solveZ,
      Arg("src"), Arg("dst"));

  Enum<cv::SVD::Flags> rb_cCvSVDFlags = define_enum_under<cv::SVD::Flags>("Flags", rb_cCvSVD).
    define_value("MODIFY_A", cv::SVD::Flags::MODIFY_A).
    define_value("NO_UV", cv::SVD::Flags::NO_UV).
    define_value("FULL_UV", cv::SVD::Flags::FULL_UV);

  Rice::Data_Type<cv::RNG> rb_cCvRNG = define_class_under<cv::RNG>(rb_mCv, "RNG").
    define_constructor(Constructor<cv::RNG>()).
    define_constructor(Constructor<cv::RNG, uint64>(),
      Arg("state")).
    define_method("next", &cv::RNG::next).
    define_method("to_unsigned char", [](cv::RNG& self) -> uchar
    {
      return self;
    }).
    define_method("to_signed char", [](cv::RNG& self) -> schar
    {
      return self;
    }).
    define_method("to_u16", [](cv::RNG& self) -> ushort
    {
      return self;
    }).
    define_method("to_i16", [](cv::RNG& self) -> short
    {
      return self;
    }).
    define_method("to_u", [](cv::RNG& self) -> unsigned int
    {
      return self;
    }).
    define_method("to_i", [](cv::RNG& self) -> int
    {
      return self;
    }).
    define_method("to_f32", [](cv::RNG& self) -> float
    {
      return self;
    }).
    define_method("to_f", [](cv::RNG& self) -> double
    {
      return self;
    }).
    define_method<unsigned int(cv::RNG::*)()>("call", &cv::RNG::operator()).
    define_method<unsigned int(cv::RNG::*)(unsigned int)>("call", &cv::RNG::operator(),
      Arg("n")).
    define_method<int(cv::RNG::*)(int, int)>("uniform", &cv::RNG::uniform,
      Arg("a"), Arg("b")).
    define_method<float(cv::RNG::*)(float, float)>("uniform", &cv::RNG::uniform,
      Arg("a"), Arg("b")).
    define_method<double(cv::RNG::*)(double, double)>("uniform", &cv::RNG::uniform,
      Arg("a"), Arg("b")).
    define_method("fill", &cv::RNG::fill,
      Arg("mat"), Arg("dist_type"), Arg("a"), Arg("b"), Arg("saturate_range") = static_cast<bool>(false)).
    define_method("gaussian", &cv::RNG::gaussian,
      Arg("sigma")).
    define_attr("state", &cv::RNG::state).
    define_method("==", &cv::RNG::operator==,
      Arg("other"));

  rb_cCvRNG.define_constant("UNIFORM", (int)cv::RNG::UNIFORM);
  rb_cCvRNG.define_constant("NORMAL", (int)cv::RNG::NORMAL);

  Rice::Data_Type<cv::RNG_MT19937> rb_cCvRNGMT19937 = define_class_under<cv::RNG_MT19937>(rb_mCv, "RNG_MT19937").
    define_constructor(Constructor<cv::RNG_MT19937>()).
    define_constructor(Constructor<cv::RNG_MT19937, unsigned int>(),
      Arg("s")).
    define_method("seed", &cv::RNG_MT19937::seed,
      Arg("s")).
    define_method("next", &cv::RNG_MT19937::next).
    define_method("to_i", [](cv::RNG_MT19937& self) -> int
    {
      return self;
    }).
    define_method("to_u", [](cv::RNG_MT19937& self) -> unsigned int
    {
      return self;
    }).
    define_method("to_f32", [](cv::RNG_MT19937& self) -> float
    {
      return self;
    }).
    define_method("to_f", [](cv::RNG_MT19937& self) -> double
    {
      return self;
    }).
    define_method<unsigned int(cv::RNG_MT19937::*)(unsigned int)>("call", &cv::RNG_MT19937::operator(),
      Arg("n")).
    define_method<unsigned int(cv::RNG_MT19937::*)()>("call", &cv::RNG_MT19937::operator()).
    define_method<int(cv::RNG_MT19937::*)(int, int)>("uniform", &cv::RNG_MT19937::uniform,
      Arg("a"), Arg("b")).
    define_method<float(cv::RNG_MT19937::*)(float, float)>("uniform", &cv::RNG_MT19937::uniform,
      Arg("a"), Arg("b")).
    define_method<double(cv::RNG_MT19937::*)(double, double)>("uniform", &cv::RNG_MT19937::uniform,
      Arg("a"), Arg("b"));

  Enum<cv::KmeansFlags> rb_cCvKmeansFlags = define_enum_under<cv::KmeansFlags>("KmeansFlags", rb_mCv).
    define_value("KMEANS_RANDOM_CENTERS", cv::KmeansFlags::KMEANS_RANDOM_CENTERS).
    define_value("KMEANS_PP_CENTERS", cv::KmeansFlags::KMEANS_PP_CENTERS).
    define_value("KMEANS_USE_INITIAL_LABELS", cv::KmeansFlags::KMEANS_USE_INITIAL_LABELS);

  rb_mCv.define_module_function("kmeans", &cv::kmeans,
    Arg("data"), Arg("k"), Arg("best_labels"), Arg("criteria"), Arg("attempts"), Arg("flags"), Arg("centers") = static_cast<cv::OutputArray>(cv::noArray()));

  Rice::Data_Type<cv::Formatted> rb_cCvFormatted = define_class_under<cv::Formatted>(rb_mCv, "Formatted").
    define_method("next", &cv::Formatted::next).
    define_method("reset", &cv::Formatted::reset);

  // Manual
  rb_cCvFormatted.
    define_method("to_s", [](cv::Formatted& self) -> cv::String
      {
        cv::String result;

        self.reset();
        for (const char* str = self.next(); str; str = self.next())
          result += cv::String(str);

        return result;
      });

  Rice::Data_Type<cv::Formatter> rb_cCvFormatter = define_class_under<cv::Formatter>(rb_mCv, "Formatter").
    define_method("format", &cv::Formatter::format,
      Arg("mtx")).
    define_method("set16f_precision", &cv::Formatter::set16fPrecision,
      Arg("p") = static_cast<int>(4)).
    define_method("set32f_precision", &cv::Formatter::set32fPrecision,
      Arg("p") = static_cast<int>(8)).
    define_method("set64f_precision", &cv::Formatter::set64fPrecision,
      Arg("p") = static_cast<int>(16)).
    define_method("set_multiline", &cv::Formatter::setMultiline,
      Arg("ml") = static_cast<bool>(true)).
    define_singleton_function("get", &cv::Formatter::get,
      Arg("fmt") = static_cast<cv::Formatter::FormatType>(cv::Formatter::FormatType::FMT_DEFAULT));

  Enum<cv::Formatter::FormatType> rb_cCvFormatterFormatType = define_enum_under<cv::Formatter::FormatType>("FormatType", rb_cCvFormatter).
    define_value("FMT_DEFAULT", cv::Formatter::FormatType::FMT_DEFAULT).
    define_value("FMT_MATLAB", cv::Formatter::FormatType::FMT_MATLAB).
    define_value("FMT_CSV", cv::Formatter::FormatType::FMT_CSV).
    define_value("FMT_PYTHON", cv::Formatter::FormatType::FMT_PYTHON).
    define_value("FMT_NUMPY", cv::Formatter::FormatType::FMT_NUMPY).
    define_value("FMT_C", cv::Formatter::FormatType::FMT_C);

  Rice::Data_Type<cv::Algorithm> rb_cCvAlgorithm = define_class_under<cv::Algorithm>(rb_mCv, "Algorithm").
    define_constructor(Constructor<cv::Algorithm>()).
    define_method("clear", &cv::Algorithm::clear).
    define_method<void(cv::Algorithm::*)(cv::FileStorage&) const>("write", &cv::Algorithm::write,
      Arg("fs")).
#if RUBY_CV_VERSION >= 407
    define_method<void(cv::Algorithm::*)(cv::FileStorage&, const cv::String&) const>("write", &cv::Algorithm::write,
      Arg("fs"), Arg("name")).
#endif
    define_method<void(cv::Algorithm::*)(const cv::Ptr<cv::FileStorage>&, const cv::String&) const>("write", &cv::Algorithm::write,
      Arg("fs"), Arg("name") = static_cast<const cv::String&>(cv::String())).
    define_method<void(cv::Algorithm::*)(const cv::FileNode&)>("read", &cv::Algorithm::read,
      Arg("fn")).
    define_method("empty?", &cv::Algorithm::empty).
    define_method("save", &cv::Algorithm::save,
      Arg("filename")).
    define_method("get_default_name", &cv::Algorithm::getDefaultName);

  Enum<cv::Param> rb_cCvParam = define_enum_under<cv::Param>("Param", rb_mCv).
    define_value("INT", cv::Param::INT).
    define_value("BOOLEAN", cv::Param::BOOLEAN).
    define_value("REAL", cv::Param::REAL).
    define_value("STRING", cv::Param::STRING).
    define_value("MAT", cv::Param::MAT).
    define_value("MAT_VECTOR", cv::Param::MAT_VECTOR).
    define_value("ALGORITHM", cv::Param::ALGORITHM).
    define_value("FLOAT", cv::Param::FLOAT).
    define_value("UNSIGNED_INT", cv::Param::UNSIGNED_INT).
    define_value("UINT64", cv::Param::UINT64).
    define_value("UCHAR", cv::Param::UCHAR).
    define_value("SCALAR", cv::Param::SCALAR);

  Rice::Data_Type<cv::ParamType<bool>> rb_cCvParamTypeBool = define_class_under<cv::ParamType<bool>>(rb_mCv, "ParamTypeBool").
    define_constructor(Constructor<cv::ParamType<bool>>()).
    define_constant("Type", cv::ParamType<bool>::type);

  Rice::Data_Type<cv::ParamType<int>> rb_cCvParamTypeInt = define_class_under<cv::ParamType<int>>(rb_mCv, "ParamTypeInt").
    define_constructor(Constructor<cv::ParamType<int>>()).
    define_constant("Type", cv::ParamType<int>::type);

  Rice::Data_Type<cv::ParamType<double>> rb_cCvParamTypeDouble = define_class_under<cv::ParamType<double>>(rb_mCv, "ParamTypeDouble").
    define_constructor(Constructor<cv::ParamType<double>>()).
    define_constant("Type", cv::ParamType<double>::type);

  Rice::Data_Type<cv::ParamType<cv::String>> rb_cCvParamTypeString = define_class_under<cv::ParamType<cv::String>>(rb_mCv, "ParamTypeString").
    define_constructor(Constructor<cv::ParamType<cv::String>>()).
    define_constant("Type", cv::ParamType<String>::type);

  Rice::Data_Type<cv::ParamType<cv::Mat>> rb_cCvParamTypeMat = define_class_under<cv::ParamType<cv::Mat>>(rb_mCv, "ParamTypeMat").
    define_constructor(Constructor<cv::ParamType<cv::Mat>>()).
    define_constant("Type", cv::ParamType<Mat>::type);

  Rice::Data_Type<cv::ParamType<std::vector<cv::Mat>>> rb_cCvParamTypeStdVectorMat = define_class_under<cv::ParamType<std::vector<cv::Mat>>>(rb_mCv, "VectorMat").
    define_constructor(Constructor<cv::ParamType<std::vector<Mat>>>()).
    define_constant("Type", cv::ParamType<std::vector<Mat>>::type);

  Rice::Data_Type<cv::ParamType<cv::Algorithm>> rb_cCvParamTypeAlgorithm = define_class_under<cv::ParamType<cv::Algorithm>>(rb_mCv, "ParamTypeAlgorithm").
    define_constructor(Constructor<cv::ParamType<cv::Algorithm>>()).
    define_constant("Type", cv::ParamType<Algorithm>::type);

  Rice::Data_Type<cv::ParamType<float>> rb_cCvParamTypeFloat = define_class_under<cv::ParamType<float>>(rb_mCv, "ParamTypeFloat").
    define_constructor(Constructor<cv::ParamType<float>>()).
    define_constant("Type", cv::ParamType<float>::type);

  Rice::Data_Type<cv::ParamType<unsigned int>> rb_cCvParamTypeUnsignedInt = define_class_under<cv::ParamType<unsigned int>>(rb_mCv, "ParamTypeUnsignedInt").
    define_constructor(Constructor<cv::ParamType<unsigned int>>()).
    define_constant("Type", cv::ParamType<unsigned int>::type);

  Rice::Data_Type<cv::ParamType<uint64>> rb_cCvParamTypeUint64 = define_class_under<cv::ParamType<uint64>>(rb_mCv, "ParamTypeUint64").
    define_constructor(Constructor<cv::ParamType<uint64>>()).
    define_constant("Type", cv::ParamType<uint64>::type);

  Rice::Data_Type<cv::ParamType<uchar>> rb_cCvParamTypeUchar = define_class_under<cv::ParamType<uchar>>(rb_mCv, "ParamTypeUchar").
    define_constructor(Constructor<cv::ParamType<uchar>>()).
    define_constant("Type", cv::ParamType<uchar>::type);

  Rice::Data_Type<cv::ParamType<cv::Scalar>> rb_cCvParamTypeScalar = define_class_under<cv::ParamType<cv::Scalar>>(rb_mCv, "ParamTypeScalar").
    define_constructor(Constructor<cv::ParamType<cv::Scalar>>()).
    define_constant("Type", cv::ParamType<Scalar>::type);

  rb_cString.
    define_method("<<", [](cv::String& self, cv::Ptr<cv::Formatted> other) -> cv::String&
  {
    self << other;
    return self;
  }).
    define_method("<<", [](cv::String& self, const cv::Mat& other) -> cv::String&
  {
    self << other;
    return self;
  });
}