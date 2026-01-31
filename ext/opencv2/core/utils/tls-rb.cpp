#include "tls-rb.ipp"

void Init_Core_Utils_Tls()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvDetails = define_module_under(rb_mCv, "Details");

  Rice::Data_Type<cv::details::TlsStorage> rb_cCvDetailsTlsStorage = define_class_under<cv::details::TlsStorage>(rb_mCvDetails, "TlsStorage");

  Rice::Data_Type<cv::TLSDataContainer> rb_cCvTLSDataContainer = define_class_under<cv::TLSDataContainer>(rb_mCv, "TLSDataContainer").
    define_method<void(cv::TLSDataContainer::*)()>("cleanup", &cv::TLSDataContainer::cleanup);
}