#include "reduce_key_val-rb.ipp"

void Init_Cudev_Block_Detail_ReduceKeyVal()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvCudev = define_module_under(rb_mCv, "Cudev");

  Module rb_mCvCudevBlockReduceKeyValDetail = define_module_under(rb_mCvCudev, "BlockReduceKeyValDetail");
}