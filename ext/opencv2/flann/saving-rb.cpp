#include <opencv2/flann/saving.h>
#include "saving-rb.hpp"

using namespace Rice;

template<typename Data_Type_T, typename T>
inline void Datatype_builder(Data_Type_T& klass)
{
};

void Init_Flann_Saving()
{
  Class(rb_cObject).define_constant("FLANN_SIGNATURE_", FLANN_SIGNATURE_);

  Module rb_mCvflann = define_module("Cvflann");

  Rice::Data_Type<cvflann::Datatype<char>> rb_cCvflannDatatypeChar = define_class_under<cvflann::Datatype<char>>(rb_mCvflann, "DatatypeChar").
    define_constructor(Constructor<cvflann::Datatype<char>>()).
    define_singleton_function("type", &cvflann::Datatype<char>::type);

  Rice::Data_Type<cvflann::Datatype<short>> rb_cCvflannDatatypeShort = define_class_under<cvflann::Datatype<short>>(rb_mCvflann, "DatatypeShort").
    define_constructor(Constructor<cvflann::Datatype<short>>()).
    define_singleton_function("type", &cvflann::Datatype<short>::type);

  Rice::Data_Type<cvflann::Datatype<int>> rb_cCvflannDatatypeInt = define_class_under<cvflann::Datatype<int>>(rb_mCvflann, "DatatypeInt").
    define_constructor(Constructor<cvflann::Datatype<int>>()).
    define_singleton_function("type", &cvflann::Datatype<int>::type);

  Rice::Data_Type<cvflann::Datatype<unsigned char>> rb_cCvflannDatatypeUnsignedChar = define_class_under<cvflann::Datatype<unsigned char>>(rb_mCvflann, "DatatypeUnsignedChar").
    define_constructor(Constructor<cvflann::Datatype<unsigned char>>()).
    define_singleton_function("type", &cvflann::Datatype<unsigned char>::type);

  Rice::Data_Type<cvflann::Datatype<unsigned short>> rb_cCvflannDatatypeUnsignedShort = define_class_under<cvflann::Datatype<unsigned short>>(rb_mCvflann, "DatatypeUnsignedShort").
    define_constructor(Constructor<cvflann::Datatype<unsigned short>>()).
    define_singleton_function("type", &cvflann::Datatype<unsigned short>::type);

  Rice::Data_Type<cvflann::Datatype<unsigned int>> rb_cCvflannDatatypeUnsignedInt = define_class_under<cvflann::Datatype<unsigned int>>(rb_mCvflann, "DatatypeUnsignedInt").
    define_constructor(Constructor<cvflann::Datatype<unsigned int>>()).
    define_singleton_function("type", &cvflann::Datatype<unsigned int>::type);

  Rice::Data_Type<cvflann::Datatype<float>> rb_cCvflannDatatypeFloat = define_class_under<cvflann::Datatype<float>>(rb_mCvflann, "DatatypeFloat").
    define_constructor(Constructor<cvflann::Datatype<float>>()).
    define_singleton_function("type", &cvflann::Datatype<float>::type);

  Rice::Data_Type<cvflann::Datatype<double>> rb_cCvflannDatatypeDouble = define_class_under<cvflann::Datatype<double>>(rb_mCvflann, "DatatypeDouble").
    define_constructor(Constructor<cvflann::Datatype<double>>()).
    define_singleton_function("type", &cvflann::Datatype<double>::type);

  Rice::Data_Type<cvflann::IndexHeader> rb_cCvflannIndexHeader = define_class_under<cvflann::IndexHeader>(rb_mCvflann, "IndexHeader").
    define_constructor(Constructor<cvflann::IndexHeader>()).
    define_attr("data_type", &cvflann::IndexHeader::data_type).
    define_attr("index_type", &cvflann::IndexHeader::index_type).
    define_attr("rows", &cvflann::IndexHeader::rows).
    define_attr("cols", &cvflann::IndexHeader::cols);

  rb_mCvflann.define_module_function("load_header", &cvflann::load_header,
    Arg("stream"));
}