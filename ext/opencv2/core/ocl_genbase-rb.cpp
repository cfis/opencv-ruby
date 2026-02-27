#include <opencv2/core/ocl.hpp> // Manual
#include <opencv2/core/ocl_genbase.hpp>
#include "ocl_genbase-rb.hpp"

using namespace Rice;

void Init_Core_OclGenbase()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvOcl = define_module_under(rb_mCv, "Ocl");

  Rice::Data_Type<cv::ocl::ProgramSource> rb_cCvOclProgramSource = define_class_under<cv::ocl::ProgramSource>(rb_mCvOcl, "ProgramSource");

  Module rb_mCvOclInternal = define_module_under(rb_mCvOcl, "Internal");

  Rice::Data_Type<cv::ocl::internal::ProgramEntry> rb_cCvOclInternalProgramEntry = define_class_under<cv::ocl::internal::ProgramEntry>(rb_mCvOclInternal, "ProgramEntry").
    define_constructor(Constructor<cv::ocl::internal::ProgramEntry>()).
    define_attr("module", &cv::ocl::internal::ProgramEntry::module).
    define_attr("name", &cv::ocl::internal::ProgramEntry::name).
    define_attr("program_code", &cv::ocl::internal::ProgramEntry::programCode).
    define_attr("program_hash", &cv::ocl::internal::ProgramEntry::programHash).
    define_attr("p_program_source", &cv::ocl::internal::ProgramEntry::pProgramSource).
    define_method("to_program_source", [](const cv::ocl::internal::ProgramEntry& self) -> cv::ocl::ProgramSource&
    {
      return self;
    });
}
