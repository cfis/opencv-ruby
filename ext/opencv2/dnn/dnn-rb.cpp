#include <opencv2/dnn/dnn.hpp>
#include "dnn-rb.hpp"

using namespace Rice;


void Init_Dnn()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDnn = define_module_under(rb_mCv, "Dnn");
  
  Module rb_mCvDnnAccessor = define_module_under(rb_mCvDnn, "Accessor");
  

}