#include <opencv2/dnn/shape_utils.hpp>
#include "shape_utils-rb.hpp"

using namespace Rice;


void Init_ShapeUtils()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDnn = define_module_under(rb_mCv, "Dnn");
  

}