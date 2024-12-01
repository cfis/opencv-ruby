#include <opencv2/dnn/layer.hpp>
#include "layer-rb.hpp"

using namespace Rice;


void Init_Layer()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDnn = define_module_under(rb_mCv, "Dnn");
  

}