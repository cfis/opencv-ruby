#include <opencv2/core/base.hpp>
#include <opencv2/core/utils/trace.hpp>
#include "trace-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvUtilsTraceDetailsRegion;
Rice::Class rb_cCvUtilsTraceDetailsRegionLocationStaticStorage;
Rice::Class rb_cCvUtilsTraceDetailsTraceArg;

void Init_Trace()
{
  Class(rb_cObject).define_constant("__OPENCV_TRACE", __OPENCV_TRACE);
  
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvUtils = define_module_under(rb_mCv, "Utils");
  
  Module rb_mCvUtilsTrace = define_module_under(rb_mCvUtils, "Trace");
  
  Module rb_mCvUtilsTraceDetails = define_module_under(rb_mCvUtilsTrace, "Details");
  
  rb_cCvUtilsTraceDetailsRegion = define_class_under<cv::utils::trace::details::Region>(rb_mCvUtilsTraceDetails, "Region").
    define_constructor(Constructor<cv::utils::trace::details::Region, const cv::utils::trace::details::Region::LocationStaticStorage&>(),
      Arg("location")).
 //   define_attr("p_impl", &cv::utils::trace::details::Region::pImpl).
    define_attr("impl_flags", &cv::utils::trace::details::Region::implFlags).
    define_method("active?", &cv::utils::trace::details::Region::isActive).
    define_method("destroy", &cv::utils::trace::details::Region::destroy);
  
  
  
  rb_cCvUtilsTraceDetailsRegionLocationStaticStorage = define_class_under<cv::utils::trace::details::Region::LocationStaticStorage>(rb_cCvUtilsTraceDetailsRegion, "LocationStaticStorage").
    define_constructor(Constructor<cv::utils::trace::details::Region::LocationStaticStorage>()).
//    define_attr("pp_extra", &cv::utils::trace::details::Region::LocationStaticStorage::ppExtra).
    define_attr("name", &cv::utils::trace::details::Region::LocationStaticStorage::name).
    define_attr("filename", &cv::utils::trace::details::Region::LocationStaticStorage::filename).
    define_attr("line", &cv::utils::trace::details::Region::LocationStaticStorage::line).
    define_attr("flags", &cv::utils::trace::details::Region::LocationStaticStorage::flags);
  
  Enum<cv::utils::trace::details::RegionLocationFlag> rb_cCvUtilsTraceDetailsRegionLocationFlag = define_enum_under<cv::utils::trace::details::RegionLocationFlag>("RegionLocationFlag", rb_mCvUtilsTraceDetails).
    define_value("REGION_FLAG_FUNCTION", cv::utils::trace::details::RegionLocationFlag::REGION_FLAG_FUNCTION).
    define_value("REGION_FLAG_APP_CODE", cv::utils::trace::details::RegionLocationFlag::REGION_FLAG_APP_CODE).
    define_value("REGION_FLAG_SKIP_NESTED", cv::utils::trace::details::RegionLocationFlag::REGION_FLAG_SKIP_NESTED).
    define_value("REGION_FLAG_IMPL_IPP", cv::utils::trace::details::RegionLocationFlag::REGION_FLAG_IMPL_IPP).
    define_value("REGION_FLAG_IMPL_OPENCL", cv::utils::trace::details::RegionLocationFlag::REGION_FLAG_IMPL_OPENCL).
    define_value("REGION_FLAG_IMPL_OPENVX", cv::utils::trace::details::RegionLocationFlag::REGION_FLAG_IMPL_OPENVX).
    define_value("REGION_FLAG_IMPL_MASK", cv::utils::trace::details::RegionLocationFlag::REGION_FLAG_IMPL_MASK).
    define_value("REGION_FLAG_REGION_FORCE", cv::utils::trace::details::RegionLocationFlag::REGION_FLAG_REGION_FORCE).
    define_value("REGION_FLAG_REGION_NEXT", cv::utils::trace::details::RegionLocationFlag::REGION_FLAG_REGION_NEXT).
    define_value("ENUM_REGION_FLAG_FORCE_INT", cv::utils::trace::details::RegionLocationFlag::ENUM_REGION_FLAG_FORCE_INT);
  
  rb_cCvUtilsTraceDetailsTraceArg = define_class_under<cv::utils::trace::details::TraceArg>(rb_mCvUtilsTraceDetails, "TraceArg").
    define_constructor(Constructor<cv::utils::trace::details::TraceArg>()).
//    define_attr("pp_extra", &cv::utils::trace::details::TraceArg::ppExtra).
    define_attr("name", &cv::utils::trace::details::TraceArg::name).
    define_attr("flags", &cv::utils::trace::details::TraceArg::flags);
  
  
  rb_mCvUtilsTraceDetails.define_module_function<void(*)(const cv::utils::trace::details::TraceArg&, const char*)>("trace_arg", &cv::utils::trace::details::traceArg,
    Arg("arg"), Arg("value"));
  
  rb_mCvUtilsTraceDetails.define_module_function<void(*)(const cv::utils::trace::details::TraceArg&, int)>("trace_arg", &cv::utils::trace::details::traceArg,
    Arg("arg"), Arg("value"));
  
  rb_mCvUtilsTraceDetails.define_module_function<void(*)(const cv::utils::trace::details::TraceArg&, int64)>("trace_arg", &cv::utils::trace::details::traceArg,
    Arg("arg"), Arg("value"));
  
  rb_mCvUtilsTraceDetails.define_module_function<void(*)(const cv::utils::trace::details::TraceArg&, double)>("trace_arg", &cv::utils::trace::details::traceArg,
    Arg("arg"), Arg("value"));
}