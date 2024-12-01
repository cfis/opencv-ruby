#include <opencv2/core/detail/exception_ptr.hpp>
#include "exception_ptr-rb.hpp"

using namespace Rice;


void Init_ExceptionPtr()
{
  Class(rb_cObject).define_constant("CV__EXCEPTION_PTR", CV__EXCEPTION_PTR);

}