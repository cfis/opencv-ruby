#include <opencv2/core/persistence.hpp>
#include "cvstd_wrapper-rb.hpp"
#include "persistence-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvFileNode;
Rice::Class rb_cCvFileNodeIterator;
Rice::Class rb_cCvFileStorage;
Rice::Class rb_cCvInternalWriteStructContext;

template<typename Data_Type_T, typename _Tp, int numflag>
inline void VecWriterProxy_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::internal::VecWriterProxy<_Tp, numflag>, cv::FileStorage*>(),
      Arg("_fs")).
    template define_method("call", &cv::internal::VecWriterProxy<_Tp, numflag>::operator(),
      Arg("vec"));
};

template<typename Data_Type_T, typename _Tp, int numflag>
inline void VecReaderProxy_builder(Data_Type_T& klass)
{
  klass.define_constructor(Constructor<cv::internal::VecReaderProxy<_Tp, numflag>, cv::FileNodeIterator*>(),
      Arg("_it")).
    template define_method("call", &cv::internal::VecReaderProxy<_Tp, numflag>::operator(),
      Arg("vec"), Arg("count"));
};

// Manually define FileNodeIterator traits
namespace std
{
  template<>
  struct iterator_traits<cv::FileNodeIterator>
  {
    using iterator_category = forward_iterator_tag;
    using value_type = cv::FileNode;
    using difference_type = ptrdiff_t;
    using pointer = cv::FileNode*;
    using reference = cv::FileNode; // The iterator returns values not references!
  };
}

void Init_Persistence()
{
  Module rb_mCv = define_module("Cv");
  
  rb_cCvFileStorage = define_class_under<cv::FileStorage>(rb_mCv, "FileStorage").
    define_constructor(Constructor<cv::FileStorage>()).
    define_constructor(Constructor<cv::FileStorage, const cv::String&, int, const cv::String&>(),
      Arg("filename"), Arg("flags"), Arg("encoding") = static_cast<const cv::String&>(cv::String())).
    define_method("open?", &cv::FileStorage::open,
      Arg("filename"), Arg("flags"), Arg("encoding") = static_cast<const cv::String&>(cv::String())).
    define_method("opened?", &cv::FileStorage::isOpened).
    define_method("release", &cv::FileStorage::release).
    define_method("release_and_get_string", &cv::FileStorage::releaseAndGetString).
    define_method("get_first_top_level_node", &cv::FileStorage::getFirstTopLevelNode).
    define_method("root", &cv::FileStorage::root,
      Arg("streamidx") = static_cast<int>(0)).
    define_method<cv::FileNode(cv::FileStorage::*)(const cv::String&) const>("[]", &cv::FileStorage::operator[],
      Arg("nodename")).
    define_method<cv::FileNode(cv::FileStorage::*)(const char*) const>("[]", &cv::FileStorage::operator[],
      Arg("nodename")).
    define_method<void(cv::FileStorage::*)(const cv::String&, int)>("write", &cv::FileStorage::write,
      Arg("name"), Arg("val")).
    define_method<void(cv::FileStorage::*)(const cv::String&, double)>("write", &cv::FileStorage::write,
      Arg("name"), Arg("val")).
    define_method<void(cv::FileStorage::*)(const cv::String&, const cv::String&)>("write", &cv::FileStorage::write,
      Arg("name"), Arg("val")).
    define_method<void(cv::FileStorage::*)(const cv::String&, const cv::Mat&)>("write", &cv::FileStorage::write,
      Arg("name"), Arg("val")).
    define_method<void(cv::FileStorage::*)(const cv::String&, const std::vector<std::basic_string<char>>&)>("write", &cv::FileStorage::write,
      Arg("name"), Arg("val")).
    define_method("write_raw", &cv::FileStorage::writeRaw,
      Arg("fmt"), Arg("vec"), Arg("len")).
    define_method("write_comment", &cv::FileStorage::writeComment,
      Arg("comment"), Arg("append") = static_cast<bool>(false)).
    define_method("start_write_struct", &cv::FileStorage::startWriteStruct,
      Arg("name"), Arg("flags"), Arg("type_name") = static_cast<const String&>(String())).
    define_method("end_write_struct", &cv::FileStorage::endWriteStruct).
    define_singleton_function("get_default_object_name", &cv::FileStorage::getDefaultObjectName,
      Arg("filename")).
    define_method("get_format", &cv::FileStorage::getFormat).
    define_attr("state", &cv::FileStorage::state).
    define_attr("elname", &cv::FileStorage::elname);
    //define_attr("p", &cv::FileStorage::p);

  rb_cCvFileStorage.define_method("<<", [](cv::FileStorage& self, const cv::String& str) ->cv::FileStorage&
  {
    self << str;
    return self;
  }).
  define_method("<<", [](cv::FileStorage& self, const char* str) ->cv::FileStorage&
  {
    self << str;
    return self;
  }).
  define_method("<<", [](cv::FileStorage& self, char* str) ->cv::FileStorage&
  {
    self << str;
    return self;
  }).
  define_method("<<", [](cv::FileStorage& self, bool& value) ->cv::FileStorage&
  {
    self << value;
    return self;
  }).
  define_method("<<", [](cv::FileStorage& self, double& value) ->cv::FileStorage&
  {
    self << value;
    return self;
  }).
  define_method("<<", [](cv::FileStorage& self, float& value) ->cv::FileStorage&
  {
    self << value;
    return self;
  }).
  define_method("<<", [](cv::FileStorage& self, short& value) ->cv::FileStorage&
  {
    self << value;
    return self;
  }).
  define_method("<<", [](cv::FileStorage& self, int& value) ->cv::FileStorage&
  {
    self << value;
    return self;
  }).
  define_method("<<", [](cv::FileStorage& self, const cv::Mat& value) ->cv::FileStorage&
  {
    self << value;
    return self;
  }).
  define_method("<<", [](cv::FileStorage& self, const std::vector<cv::String>& value) ->cv::FileStorage&
  {
    self << value;
    return self;
  });

 
  Enum<cv::FileStorage::Mode> rb_cCvFileStorageMode = define_enum_under<cv::FileStorage::Mode>("Mode", rb_cCvFileStorage).
    define_value("READ", cv::FileStorage::Mode::READ).
    define_value("WRITE", cv::FileStorage::Mode::WRITE).
    define_value("APPEND", cv::FileStorage::Mode::APPEND).
    define_value("MEMORY", cv::FileStorage::Mode::MEMORY).
    define_value("FORMAT_MASK", cv::FileStorage::Mode::FORMAT_MASK).
    define_value("FORMAT_AUTO", cv::FileStorage::Mode::FORMAT_AUTO).
    define_value("FORMAT_XML", cv::FileStorage::Mode::FORMAT_XML).
    define_value("FORMAT_YAML", cv::FileStorage::Mode::FORMAT_YAML).
    define_value("FORMAT_JSON", cv::FileStorage::Mode::FORMAT_JSON).
    define_value("BASE64", cv::FileStorage::Mode::BASE64).
    define_value("WRITE_BASE64", cv::FileStorage::Mode::WRITE_BASE64);
  
  Enum<cv::FileStorage::State> rb_cCvFileStorageState = define_enum_under<cv::FileStorage::State>("State", rb_cCvFileStorage).
    define_value("UNDEFINED", cv::FileStorage::State::UNDEFINED).
    define_value("VALUE_EXPECTED", cv::FileStorage::State::VALUE_EXPECTED).
    define_value("NAME_EXPECTED", cv::FileStorage::State::NAME_EXPECTED).
    define_value("INSIDE_MAP", cv::FileStorage::State::INSIDE_MAP);
  
  rb_cCvFileNode = define_class_under<cv::FileNode>(rb_mCv, "FileNode").
    define_constructor(Constructor<cv::FileNode>()).
    define_constructor(Constructor<cv::FileNode, const cv::FileStorage*, ::size_t, ::size_t>(),
      Arg("fs"), Arg("block_idx"), Arg("ofs")).
    define_constructor(Constructor<cv::FileNode, const cv::FileNode&>(),
      Arg("node")).
    define_method("assign", &cv::FileNode::operator=,
      Arg("node")).
    define_method<cv::FileNode(cv::FileNode::*)(const cv::String&) const>("[]", &cv::FileNode::operator[],
      Arg("nodename")).
    define_method<cv::FileNode(cv::FileNode::*)(const char*) const>("[]", &cv::FileNode::operator[],
      Arg("nodename")).
    define_method<cv::FileNode(cv::FileNode::*)(int) const>("[]", &cv::FileNode::operator[],
      Arg("i")).
    define_method("keys", &cv::FileNode::keys).
    define_method("type", &cv::FileNode::type).
    define_method("empty?", &cv::FileNode::empty).
    define_method("none?", &cv::FileNode::isNone).
    define_method<bool(cv::FileNode::*)() const>("seq?", &cv::FileNode::isSeq).
    define_method<bool(cv::FileNode::*)() const>("map?", &cv::FileNode::isMap).
    define_method("int?", &cv::FileNode::isInt).
    define_method("real?", &cv::FileNode::isReal).
    define_method("string?", &cv::FileNode::isString).
    define_method("named?", &cv::FileNode::isNamed).
    define_method("name", &cv::FileNode::name).
    define_method("size", &cv::FileNode::size).
    define_method("raw_size", &cv::FileNode::rawSize).
    define_method("to_int", [](const cv::FileNode& self) -> int
    {
      return self;
    }).
    define_method("to_float", [](const cv::FileNode& self) -> float
    {
      return self;
    }).
    define_method("to_double", [](const cv::FileNode& self) -> double
    {
      return self;
    }).
    define_method("to_string", [](const cv::FileNode& self) -> std::string
    {
      return self;
    }).
    define_singleton_function<bool(*)(int)>("map?", &cv::FileNode::isMap,
      Arg("flags")).
    define_singleton_function<bool(*)(int)>("seq?", &cv::FileNode::isSeq,
      Arg("flags")).
    define_singleton_function("collection?", &cv::FileNode::isCollection,
      Arg("flags")).
    define_singleton_function("empty_collection?", &cv::FileNode::isEmptyCollection,
      Arg("flags")).
    define_singleton_function("flow?", &cv::FileNode::isFlow,
      Arg("flags")).
    //define_method<uchar*(cv::FileNode::*)()>("ptr", &cv::FileNode::ptr).
   // define_method<const uchar*(cv::FileNode::*)() const>("ptr", &cv::FileNode::ptr).
    define_iterator<cv::FileNodeIterator(cv::FileNode::*)() const>(&cv::FileNode::begin, &cv::FileNode::end, "each").
    define_method("read_raw", &cv::FileNode::readRaw,
      Arg("fmt"), Arg("vec"), Arg("len")).
    define_method("set_value", &cv::FileNode::setValue,
      Arg("type"), Arg("value"), Arg("len") = static_cast<int>(-1)).
//    define_constructor(Constructor<cv::FileNode, cv::FileStorage::Impl*, ::size_t, ::size_t>(),
//      Arg("fs"), Arg("block_idx"), Arg("ofs")).
   // define_attr("fs", &cv::FileNode::fs).
    define_method("real", &cv::FileNode::real).
    define_method("string", &cv::FileNode::string).
    define_method("mat", &cv::FileNode::mat).
    define_attr("block_idx", &cv::FileNode::blockIdx).
    define_attr("ofs", &cv::FileNode::ofs);
  
  rb_cCvFileNode.define_constant("NONE", (int)cv::FileNode::NONE);
  rb_cCvFileNode.define_constant("INT", (int)cv::FileNode::INT);
  rb_cCvFileNode.define_constant("REAL", (int)cv::FileNode::REAL);
  rb_cCvFileNode.define_constant("FLOAT", (int)cv::FileNode::FLOAT);
  rb_cCvFileNode.define_constant("STR", (int)cv::FileNode::STR);
  rb_cCvFileNode.define_constant("STRING", (int)cv::FileNode::STRING);
  rb_cCvFileNode.define_constant("SEQ", (int)cv::FileNode::SEQ);
  rb_cCvFileNode.define_constant("MAP", (int)cv::FileNode::MAP);
  rb_cCvFileNode.define_constant("TYPE_MASK", (int)cv::FileNode::TYPE_MASK);
  rb_cCvFileNode.define_constant("FLOW", (int)cv::FileNode::FLOW);
  rb_cCvFileNode.define_constant("UNIFORM", (int)cv::FileNode::UNIFORM);
  rb_cCvFileNode.define_constant("EMPTY", (int)cv::FileNode::EMPTY);
  rb_cCvFileNode.define_constant("NAMED", (int)cv::FileNode::NAMED);
  
  rb_cCvFileNodeIterator = define_class_under<cv::FileNodeIterator>(rb_mCv, "FileNodeIterator").
    define_constructor(Constructor<cv::FileNodeIterator>()).
    define_constructor(Constructor<cv::FileNodeIterator, const cv::FileNode&, bool>(),
      Arg("node"), Arg("seek_end")).
    define_constructor(Constructor<cv::FileNodeIterator, const cv::FileNodeIterator&>(),
      Arg("it")).
    define_method("assign", &cv::FileNodeIterator::operator=,
      Arg("it")).
    define_method("dereference", &cv::FileNodeIterator::operator*).
    define_method<cv::FileNodeIterator&(cv::FileNodeIterator::*)()>("increment", &cv::FileNodeIterator::operator++).
    define_method<cv::FileNodeIterator(cv::FileNodeIterator::*)(int)>("increment", &cv::FileNodeIterator::operator++,
      Arg("")).
    define_method("assign_plus", &cv::FileNodeIterator::operator+=,
      Arg("ofs")).
    define_method("read_raw", &cv::FileNodeIterator::readRaw,
      Arg("fmt"), Arg("vec"), Arg("len") = static_cast<size_t>((size_t)INT_MAX)).
    define_method("remaining", &cv::FileNodeIterator::remaining).
    define_method("equal_to?", &cv::FileNodeIterator::equalTo,
      Arg("it"));
      
  rb_mCv.define_module_function<void(*)(cv::FileStorage&, const cv::String&, int)>("write", &cv::write,
    Arg("fs"), Arg("name"), Arg("value"));
  
  rb_mCv.define_module_function<void(*)(cv::FileStorage&, const cv::String&, float)>("write", &cv::write,
    Arg("fs"), Arg("name"), Arg("value"));
  
  rb_mCv.define_module_function<void(*)(cv::FileStorage&, const cv::String&, double)>("write", &cv::write,
    Arg("fs"), Arg("name"), Arg("value"));
  
  rb_mCv.define_module_function<void(*)(cv::FileStorage&, const cv::String&, const cv::String&)>("write", &cv::write,
    Arg("fs"), Arg("name"), Arg("value"));
  
  rb_mCv.define_module_function<void(*)(cv::FileStorage&, const cv::String&, const cv::Mat&)>("write", &cv::write,
    Arg("fs"), Arg("name"), Arg("value"));
  
  rb_mCv.define_module_function<void(*)(cv::FileStorage&, const cv::String&, const cv::SparseMat&)>("write", &cv::write,
    Arg("fs"), Arg("name"), Arg("value"));
  
  rb_mCv.define_module_function<void(*)(cv::FileStorage&, const cv::String&, const std::vector<cv::KeyPoint>&)>("write", &cv::write,
    Arg("fs"), Arg("name"), Arg("value"));
  
  rb_mCv.define_module_function<void(*)(cv::FileStorage&, const cv::String&, const std::vector<cv::DMatch>&)>("write", &cv::write,
    Arg("fs"), Arg("name"), Arg("value"));
  
  rb_mCv.define_module_function<void(*)(cv::FileStorage&, int)>("write_scalar", &cv::writeScalar,
    Arg("fs"), Arg("value"));
  
  rb_mCv.define_module_function<void(*)(cv::FileStorage&, float)>("write_scalar", &cv::writeScalar,
    Arg("fs"), Arg("value"));
  
  rb_mCv.define_module_function<void(*)(cv::FileStorage&, double)>("write_scalar", &cv::writeScalar,
    Arg("fs"), Arg("value"));
  
  rb_mCv.define_module_function<void(*)(cv::FileStorage&, const cv::String&)>("write_scalar", &cv::writeScalar,
    Arg("fs"), Arg("value"));
  
  rb_mCv.define_module_function<void(*)(const cv::FileNode&, int&, int)>("read", &cv::read,
    Arg("node"), Arg("value"), Arg("default_value"));
  
  rb_mCv.define_module_function<void(*)(const cv::FileNode&, float&, float)>("read", &cv::read,
    Arg("node"), Arg("value"), Arg("default_value"));
  
  rb_mCv.define_module_function<void(*)(const cv::FileNode&, double&, double)>("read", &cv::read,
    Arg("node"), Arg("value"), Arg("default_value"));
  
  rb_mCv.define_module_function<void(*)(const cv::FileNode&, std::string&, const std::string&)>("read", &cv::read,
    Arg("node"), Arg("value"), Arg("default_value"));
  
  rb_mCv.define_module_function<void(*)(const cv::FileNode&, cv::Mat&, const cv::Mat&)>("read", &cv::read,
    Arg("node"), Arg("mat"), Arg("default_mat") = static_cast<const cv::Mat &>(cv::Mat()));
  
  rb_mCv.define_module_function<void(*)(const cv::FileNode&, cv::SparseMat&, const cv::SparseMat&)>("read", &cv::read,
    Arg("node"), Arg("mat"), Arg("default_mat") = static_cast<const cv::SparseMat &>(cv::SparseMat()));
  
  rb_mCv.define_module_function<void(*)(const cv::FileNode&, std::vector<cv::KeyPoint>&)>("read", &cv::read,
    Arg("node"), Arg("keypoints"));
  
  rb_mCv.define_module_function<void(*)(const cv::FileNode&, std::vector<cv::DMatch>&)>("read", &cv::read,
    Arg("node"), Arg("matches"));
  
  rb_mCv.define_module_function<void(*)(const cv::FileNode&, cv::KeyPoint&, const cv::KeyPoint&)>("read", &cv::read,
    Arg("node"), Arg("value"), Arg("default_value"));
  
  rb_mCv.define_module_function<void(*)(const cv::FileNode&, cv::DMatch&, const cv::DMatch&)>("read", &cv::read,
    Arg("node"), Arg("value"), Arg("default_value"));
  
  rb_mCv.define_module_function<void(*)(const cv::FileNode&, cv::Range&, const cv::Range&)>("read", &cv::read,
    Arg("node"), Arg("value"), Arg("default_value"));
  
  Module rb_mCvInternal = define_module_under(rb_mCv, "Internal");
  
  rb_cCvInternalWriteStructContext = define_class_under<cv::internal::WriteStructContext>(rb_mCvInternal, "WriteStructContext").
    define_constructor(Constructor<cv::internal::WriteStructContext, cv::FileStorage&, const cv::String&, int, const cv::String&>(),
      Arg("_fs"), Arg("name"), Arg("flags"), Arg("type_name") = static_cast<const String &>(String()));
  
  rb_mCv.define_module_function<void(*)(cv::FileStorage&, const int&)>("write", &cv::write,
    Arg("fs"), Arg("value"));
  
  rb_mCv.define_module_function<void(*)(cv::FileStorage&, const float&)>("write", &cv::write,
    Arg("fs"), Arg("value"));
  
  rb_mCv.define_module_function<void(*)(cv::FileStorage&, const double&)>("write", &cv::write,
    Arg("fs"), Arg("value"));
  
  rb_mCv.define_module_function<void(*)(cv::FileStorage&, const cv::String&)>("write", &cv::write,
    Arg("fs"), Arg("value"));
  
  rb_mCv.define_module_function<void(*)(cv::FileStorage&, const cv::Range&)>("write", &cv::write,
    Arg("fs"), Arg("r"));
  
  rb_mCv.define_module_function<void(*)(cv::FileStorage&, const cv::String&, const cv::Range&)>("write", &cv::write,
    Arg("fs"), Arg("name"), Arg("r"));
  
  rb_mCv.define_module_function<void(*)(cv::FileStorage&, const cv::String&, const cv::KeyPoint&)>("write", &cv::write,
    Arg("fs"), Arg("name"), Arg("kpt"));
  
  rb_mCv.define_module_function<void(*)(cv::FileStorage&, const cv::String&, const cv::DMatch&)>("write", &cv::write,
    Arg("fs"), Arg("name"), Arg("m"));
  
  rb_mCv.define_module_function<void(*)(cv::FileStorage&, const cv::KeyPoint&)>("write", &cv::write,
    Arg("fs"), Arg("kpt"));
  
  rb_mCv.define_module_function<void(*)(cv::FileStorage&, const cv::DMatch&)>("write", &cv::write,
    Arg("fs"), Arg("m"));
  
  rb_mCv.define_module_function<void(*)(cv::FileStorage&, const std::vector<cv::KeyPoint>&)>("write", &cv::write,
    Arg("fs"), Arg("vec"));
  
  rb_mCv.define_module_function<void(*)(cv::FileStorage&, const std::vector<cv::DMatch>&)>("write", &cv::write,
    Arg("fs"), Arg("vec"));
  
  rb_mCv.define_module_function<void(*)(const cv::FileNode&, bool&, bool)>("read", &cv::read,
    Arg("node"), Arg("value"), Arg("default_value"));
  
  rb_mCv.define_module_function<void(*)(const cv::FileNode&, uchar&, uchar)>("read", &cv::read,
    Arg("node"), Arg("value"), Arg("default_value"));
  
  //rb_mCv.define_module_function<void(*)(const cv::FileNode&, schar&, schar)>("read", &cv::read,
  //  Arg("node"), Arg("value"), Arg("default_value"));
  
  rb_mCv.define_module_function<void(*)(const cv::FileNode&, ushort&, ushort)>("read", &cv::read,
    Arg("node"), Arg("value"), Arg("default_value"));
  
  rb_mCv.define_module_function<void(*)(const cv::FileNode&, short&, short)>("read", &cv::read,
    Arg("node"), Arg("value"), Arg("default_value"));
  
  rb_mCv.define_module_function<void(*)(const cv::FileNode&, std::vector<cv::KeyPoint>&, const std::vector<cv::KeyPoint>&)>("read", &cv::read,
    Arg("node"), Arg("vec"), Arg("default_value"));
  
  rb_mCv.define_module_function<void(*)(const cv::FileNode&, std::vector<cv::DMatch>&, const std::vector<cv::DMatch>&)>("read", &cv::read,
    Arg("node"), Arg("vec"), Arg("default_value"));
  
  rb_cCvFileNode.define_method(">>", [](const cv::FileNode& self, cv::KeyPoint& other) -> void
  {
    return self >> other;
  });
  
  rb_cCvFileNode.define_method(">>", [](const cv::FileNode& self, std::vector<cv::KeyPoint>& other) -> void
  {
    return self >> other;
  });
  
  rb_cCvFileNode.define_method(">>", [](const cv::FileNode& self, std::vector<cv::DMatch>& other) -> void
  {
    return self >> other;
  });
  
  rb_cCvFileNode.define_method(">>", [](const cv::FileNode& self, cv::DMatch& other) -> void
  {
    return self >> other;
  });
  
  rb_cCvFileNodeIterator.define_method("==", [](const cv::FileNodeIterator& self, const cv::FileNodeIterator& other) -> bool
  {
    return self == other;
  });
  
  rb_cCvFileNodeIterator.define_method("!=", [](const cv::FileNodeIterator& self, const cv::FileNodeIterator& other) -> bool
  {
    return self != other;
  });
  
  rb_cCvFileNodeIterator.define_method("-", [](const cv::FileNodeIterator& self, const cv::FileNodeIterator& other) -> ::ptrdiff_t
  {
    return self - other;
  });
  
  rb_cCvFileNodeIterator.define_method("<", [](const cv::FileNodeIterator& self, const cv::FileNodeIterator& other) -> bool
  {
    return self < other;
  });

}