#include <opencv2/dnn/all_layers.hpp>
#include "all_layers-rb.hpp"

using namespace Rice;


void Init_AllLayers()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvDnn = define_module_under(rb_mCv, "Dnn");
  

}