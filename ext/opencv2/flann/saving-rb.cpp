#include <opencv2/flann/saving.h>
#include "saving-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvflannDatatypeChar;
Rice::Class rb_cCvflannDatatypeDouble;
Rice::Class rb_cCvflannDatatypeFloat;
Rice::Class rb_cCvflannDatatypeInt;
Rice::Class rb_cCvflannDatatypeShort;
Rice::Class rb_cCvflannDatatypeUnsignedChar;
Rice::Class rb_cCvflannDatatypeUnsignedInt;
Rice::Class rb_cCvflannDatatypeUnsignedShort;
Rice::Class rb_cCvflannIndexHeader;

template<typename Data_Type_T, typename T>
inline void Datatype_builder(Data_Type_T& klass)
{
};
void Init_Saving()
{
  Class(rb_cObject).define_constant("FLANN_SIGNATURE_", FLANN_SIGNATURE_);
  
  Module rb_mCvflann = define_module("Cvflann");
  
  rb_cCvflannDatatypeChar = define_class_under<cvflann::Datatype<char>>(rb_mCvflann, "DatatypeChar").
    define_constructor(Constructor<cvflann::Datatype<char>>()).
    define_singleton_function("type", &cvflann::Datatype<char>::type);
  
  rb_cCvflannDatatypeShort = define_class_under<cvflann::Datatype<short>>(rb_mCvflann, "DatatypeShort").
    define_constructor(Constructor<cvflann::Datatype<short>>()).
    define_singleton_function("type", &cvflann::Datatype<short>::type);
  
  rb_cCvflannDatatypeInt = define_class_under<cvflann::Datatype<int>>(rb_mCvflann, "DatatypeInt").
    define_constructor(Constructor<cvflann::Datatype<int>>()).
    define_singleton_function("type", &cvflann::Datatype<int>::type);
  
  rb_cCvflannDatatypeUnsignedChar = define_class_under<cvflann::Datatype<unsigned char>>(rb_mCvflann, "DatatypeUnsignedChar").
    define_constructor(Constructor<cvflann::Datatype<unsigned char>>()).
    define_singleton_function("type", &cvflann::Datatype<unsigned char>::type);
  
  rb_cCvflannDatatypeUnsignedShort = define_class_under<cvflann::Datatype<unsigned short>>(rb_mCvflann, "DatatypeUnsignedShort").
    define_constructor(Constructor<cvflann::Datatype<unsigned short>>()).
    define_singleton_function("type", &cvflann::Datatype<unsigned short>::type);
  
  rb_cCvflannDatatypeUnsignedInt = define_class_under<cvflann::Datatype<unsigned int>>(rb_mCvflann, "DatatypeUnsignedInt").
    define_constructor(Constructor<cvflann::Datatype<unsigned int>>()).
    define_singleton_function("type", &cvflann::Datatype<unsigned int>::type);
  
  rb_cCvflannDatatypeFloat = define_class_under<cvflann::Datatype<float>>(rb_mCvflann, "DatatypeFloat").
    define_constructor(Constructor<cvflann::Datatype<float>>()).
    define_singleton_function("type", &cvflann::Datatype<float>::type);
  
  rb_cCvflannDatatypeDouble = define_class_under<cvflann::Datatype<double>>(rb_mCvflann, "DatatypeDouble").
    define_constructor(Constructor<cvflann::Datatype<double>>()).
    define_singleton_function("type", &cvflann::Datatype<double>::type);
  
  rb_cCvflannIndexHeader = define_class_under<cvflann::IndexHeader>(rb_mCvflann, "IndexHeader").
    define_constructor(Constructor<cvflann::IndexHeader>()).
    define_attr("data_type", &cvflann::IndexHeader::data_type).
    define_attr("index_type", &cvflann::IndexHeader::index_type).
    define_attr("rows", &cvflann::IndexHeader::rows).
    define_attr("cols", &cvflann::IndexHeader::cols);
  
  rb_mCvflann.define_module_function("load_header", &cvflann::load_header,
    Arg("stream"));

}