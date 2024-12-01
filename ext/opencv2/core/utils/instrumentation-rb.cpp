#include <opencv2/core/utils/instrumentation.hpp>
#include "../utility-rb.hpp"
#include "instrumentation-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvInstrNodeData;
Rice::Class rb_cCvInstrNodeDataTls;
Rice::Class rb_cInstrNode;

void Init_Instrumentation()
{
  Module rb_mCv = define_module("Cv");
  
  Module rb_mCvInstr = define_module_under(rb_mCv, "Instr");
  
  Enum<cv::instr::TYPE> rb_cCvInstrTYPE = define_enum_under<cv::instr::TYPE>("TYPE", rb_mCvInstr).
    define_value("TYPE_GENERAL", cv::instr::TYPE::TYPE_GENERAL).
    define_value("TYPE_MARKER", cv::instr::TYPE::TYPE_MARKER).
    define_value("TYPE_WRAPPER", cv::instr::TYPE::TYPE_WRAPPER).
    define_value("TYPE_FUN", cv::instr::TYPE::TYPE_FUN);
  
  Enum<cv::instr::IMPL> rb_cCvInstrIMPL = define_enum_under<cv::instr::IMPL>("IMPL", rb_mCvInstr).
    define_value("IMPL_PLAIN", cv::instr::IMPL::IMPL_PLAIN).
    define_value("IMPL_IPP", cv::instr::IMPL::IMPL_IPP).
    define_value("IMPL_OPENCL", cv::instr::IMPL::IMPL_OPENCL);
  
  rb_cCvInstrNodeDataTls = define_class_under<cv::instr::NodeDataTls>(rb_mCvInstr, "NodeDataTls").
    define_constructor(Constructor<cv::instr::NodeDataTls>()).
    define_attr("m_ticks_total", &cv::instr::NodeDataTls::m_ticksTotal);
  
  rb_cCvInstrNodeData = define_class_under<cv::instr::NodeData>(rb_mCvInstr, "NodeData").
    define_constructor(Constructor<cv::instr::NodeData, const char*, const char*, int, void*, bool, cv::instr::TYPE, cv::instr::IMPL>(),
      Arg("fun_name") = static_cast<const char *>(0), Arg("file_name") = static_cast<const char *>(NULL), Arg("line_num") = static_cast<int>(0), Arg("ret_address") = static_cast<void *>(NULL), Arg("always_expand") = static_cast<bool>(false), Arg("instr_type") = static_cast<cv::instr::TYPE>(cv::instr::TYPE::TYPE_GENERAL), Arg("impl_type") = static_cast<cv::instr::IMPL>(cv::instr::IMPL::IMPL_PLAIN)).
    //define_constructor(Constructor<cv::instr::NodeData, cv::instr::NodeData&>(),
    //  Arg("ref")).
    define_method("assign", &cv::instr::NodeData::operator=,
      Arg("")).
    define_attr("m_fun_name", &cv::instr::NodeData::m_funName).
    define_attr("m_instr_type", &cv::instr::NodeData::m_instrType).
    define_attr("m_impl_type", &cv::instr::NodeData::m_implType).
    define_attr("m_file_name", &cv::instr::NodeData::m_fileName).
    define_attr("m_line_num", &cv::instr::NodeData::m_lineNum).
    define_attr("m_ret_address", &cv::instr::NodeData::m_retAddress).
    define_attr("m_always_expand", &cv::instr::NodeData::m_alwaysExpand).
    define_attr("m_fun_error", &cv::instr::NodeData::m_funError).
    define_attr("m_counter", &cv::instr::NodeData::m_counter).
    define_attr("m_ticks_total", &cv::instr::NodeData::m_ticksTotal).
    //define_attr("m_tls", &cv::instr::NodeData::m_tls).
    define_attr("m_threads", &cv::instr::NodeData::m_threads).
    define_method("get_total_ms", &cv::instr::NodeData::getTotalMs).
    define_method("get_mean_ms", &cv::instr::NodeData::getMeanMs);
  
  rb_cCvInstrNodeData.define_method("==", [](const cv::instr::NodeData& self, const cv::instr::NodeData& other) -> bool
  {
    return self == other;
  });
  
  rb_cInstrNode = define_class_under<cv::Node<cv::instr::NodeData>>(rb_mCvInstr, "InstrNode").
    define(&Node_builder<Data_Type<cv::Node<cv::instr::NodeData>>, cv::instr::NodeData>);
  
  rb_mCvInstr.define_module_function("get_trace", &cv::instr::getTrace);
  
  rb_mCvInstr.define_module_function("use_instrumentation?", &cv::instr::useInstrumentation);
  
  rb_mCvInstr.define_module_function("set_use_instrumentation", &cv::instr::setUseInstrumentation,
    Arg("flag"));
  
  rb_mCvInstr.define_module_function("reset_trace", &cv::instr::resetTrace);
  
  Enum<cv::instr::FLAGS> rb_cCvInstrFLAGS = define_enum_under<cv::instr::FLAGS>("FLAGS", rb_mCvInstr).
    define_value("FLAGS_NONE", cv::instr::FLAGS::FLAGS_NONE).
    define_value("FLAGS_MAPPING", cv::instr::FLAGS::FLAGS_MAPPING).
    define_value("FLAGS_EXPAND_SAME_NAMES", cv::instr::FLAGS::FLAGS_EXPAND_SAME_NAMES);
  
  rb_mCvInstr.define_module_function<void(*)(cv::instr::FLAGS)>("set_flags", &cv::instr::setFlags,
    Arg("mode_flags"));
  
  rb_mCvInstr.define_module_function<void(*)(int)>("set_flags", &cv::instr::setFlags,
    Arg("mode_flags"));
  
  rb_mCvInstr.define_module_function("get_flags", &cv::instr::getFlags);

}