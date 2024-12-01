#include <opencv2/dnn/layer.details.hpp>
#include "layer.details-rb.hpp"

using namespace Rice;


void Init_LayerDetails()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDnn = define_module_under(rb_mCv, "Dnn");
  

}