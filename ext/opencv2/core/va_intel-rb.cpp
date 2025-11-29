#include <opencv2/core/va_intel.hpp>
#include "va_intel-rb.hpp"

using namespace Rice;


void Init_VaIntel()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvVaIntel = define_module_under(rb_mCv, "VaIntel");
  
  Module rb_mCvVaIntelOcl = define_module_under(rb_mCvVaIntel, "Ocl");
  
  rb_mCvVaIntelOcl.define_module_function("initialize_context_from_va", &cv::va_intel::ocl::initializeContextFromVA,
    Arg("display"), Arg("try_interop") = static_cast<bool>(true));
  
  rb_mCvVaIntel.define_module_function("convert_to_va_surface", &cv::va_intel::convertToVASurface,
    Arg("display"), Arg("src"), Arg("surface"), Arg("size"));
  
  rb_mCvVaIntel.define_module_function("convert_from_va_surface", &cv::va_intel::convertFromVASurface,
    Arg("display"), Arg("surface"), Arg("size"), Arg("dst"));

}