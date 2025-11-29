#include <opencv2/flann/hdf5.h>
#include "hdf5-rb.hpp"

using namespace Rice;


void Init_Hdf5()
{
  Module rb_mCvflann = define_module("Cvflann");
  
  Module rb_mCvflannAnonymous = define_module_under(rb_mCvflann, "Anonymous");
  
  /*rb_mCvflannAnonymous.define_module_function<hid_t(*)()>("get_hdf5_type", &cvflann::::get_hdf5_type);
  
  rb_mCvflannAnonymous.define_module_function<hid_t(*)()>("get_hdf5_type", &cvflann::::get_hdf5_type);
  
  rb_mCvflannAnonymous.define_module_function<hid_t(*)()>("get_hdf5_type", &cvflann::::get_hdf5_type);
  
  rb_mCvflannAnonymous.define_module_function<hid_t(*)()>("get_hdf5_type", &cvflann::::get_hdf5_type);
  
  rb_mCvflannAnonymous.define_module_function<hid_t(*)()>("get_hdf5_type", &cvflann::::get_hdf5_type);
  
  rb_mCvflannAnonymous.define_module_function<hid_t(*)()>("get_hdf5_type", &cvflann::::get_hdf5_type);
  
  rb_mCvflannAnonymous.define_module_function<hid_t(*)()>("get_hdf5_type", &cvflann::::get_hdf5_type);
  
  rb_mCvflannAnonymous.define_module_function<hid_t(*)()>("get_hdf5_type", &cvflann::::get_hdf5_type);
  
  rb_mCvflannAnonymous.define_module_function<hid_t(*)()>("get_hdf5_type", &cvflann::::get_hdf5_type);
  
  rb_mCvflannAnonymous.define_module_function<hid_t(*)()>("get_hdf5_type", &cvflann::::get_hdf5_type);
  */
}