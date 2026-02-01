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
    Rice::Class rubyExceptionClass;

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

void Init_Core_Refinements()
{
  Module rb_mCv = define_module("Cv");

  Rice::Data_Type<cv::Exception> rb_eCvException;
  rb_eCvException.
    // Manual marshalling needed for RubyMine debugger
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
  
  rb_mCv.define_module_function<void(*)(const cv::Exception&)>("error", &cv::error,
    Arg("exc"));

  rb_mCv.define_module_function("min_max_loc",
    [](cv::InputArray src, cv::InputArray mask = cv::noArray()) -> std::tuple<double, double, cv::Point, cv::Point>
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

  rb_mCv.define_module_function("min_max_loc", [](const cv::SparseMat& src) -> std::tuple<double, double, int, int>
  {
    double minVal = 0;
    double maxVal = 0;
    int minIdx = 0;
    int maxIdx = 0;

    cv::minMaxLoc(src, &minVal, &maxVal, &minIdx, &maxIdx);
    return std::forward_as_tuple(minVal, maxVal, minIdx, maxIdx);
  }, Arg("src"));

  // Manual
  Rice::Data_Type<cv::Formatted>().
    define_method("to_s", [](cv::Formatted& self) -> cv::String
    {
      cv::String result;

      self.reset();
      for (const char* str = self.next(); str; str = self.next())
        result += cv::String(str);

      return result;
    });
}
  
