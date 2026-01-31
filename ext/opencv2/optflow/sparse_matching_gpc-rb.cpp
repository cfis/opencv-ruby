#include "sparse_matching_gpc-rb.ipp"

void Init_Optflow_SparseMatchingGpc()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvOptflow = define_module_under(rb_mCv, "Optflow");

  Rice::Data_Type<cv::optflow::GPCPatchDescriptor> rb_cCvOptflowGPCPatchDescriptor = define_class_under<cv::optflow::GPCPatchDescriptor>(rb_mCvOptflow, "GPCPatchDescriptor").
    define_constructor(Constructor<cv::optflow::GPCPatchDescriptor>()).
    define_constant("NFeatures", cv::optflow::GPCPatchDescriptor::nFeatures).
    define_attr("feature", &cv::optflow::GPCPatchDescriptor::feature).
    define_method<double(cv::optflow::GPCPatchDescriptor::*)(const cv::Vec<double, nFeatures>&) const>("dot", &cv::optflow::GPCPatchDescriptor::dot,
      Arg("coef")).
    define_method<void(cv::optflow::GPCPatchDescriptor::*)()>("mark_as_separated", &cv::optflow::GPCPatchDescriptor::markAsSeparated).
    define_method<bool(cv::optflow::GPCPatchDescriptor::*)() const>("separated?", &cv::optflow::GPCPatchDescriptor::isSeparated);

  Rice::Data_Type<cv::optflow::GPCPatchSample> rb_cCvOptflowGPCPatchSample = define_class_under<cv::optflow::GPCPatchSample>(rb_mCvOptflow, "GPCPatchSample").
    define_constructor(Constructor<cv::optflow::GPCPatchSample>()).
    define_attr("ref", &cv::optflow::GPCPatchSample::ref).
    define_attr("pos", &cv::optflow::GPCPatchSample::pos).
    define_attr("neg", &cv::optflow::GPCPatchSample::neg).
    define_method<void(cv::optflow::GPCPatchSample::*)(bool&, bool&, bool&, const cv::Vec<double, GPCPatchDescriptor::nFeatures>&, double) const>("get_directions", &cv::optflow::GPCPatchSample::getDirections,
      Arg("refdir"), Arg("posdir"), Arg("negdir"), Arg("coef"), Arg("rhs"));

  Enum<cv::optflow::GPCDescType> rb_cCvOptflowGPCDescType = define_enum_under<cv::optflow::GPCDescType>("GPCDescType", rb_mCvOptflow).
    define_value("GPC_DESCRIPTOR_DCT", cv::optflow::GPCDescType::GPC_DESCRIPTOR_DCT).
    define_value("GPC_DESCRIPTOR_WHT", cv::optflow::GPCDescType::GPC_DESCRIPTOR_WHT);

  Rice::Data_Type<cv::optflow::GPCTrainingSamples> rb_cCvOptflowGPCTrainingSamples = define_class_under<cv::optflow::GPCTrainingSamples>(rb_mCvOptflow, "GPCTrainingSamples").
    define_constructor(Constructor<cv::optflow::GPCTrainingSamples>()).
    define_method<size_t(cv::optflow::GPCTrainingSamples::*)() const>("size", &cv::optflow::GPCTrainingSamples::size).
    define_method<int(cv::optflow::GPCTrainingSamples::*)() const>("type", &cv::optflow::GPCTrainingSamples::type).
    define_method("to_gpc_samples_vector", [](cv::optflow::GPCTrainingSamples& self) -> cv::optflow::GPCSamplesVector&
    {
      return self;
    }).
    define_singleton_function<cv::Ptr<cv::optflow::GPCTrainingSamples>(*)(const std::vector<std::basic_string<char>>&, const std::vector<std::basic_string<char>>&, const std::vector<std::basic_string<char>>&, int)>("create", &cv::optflow::GPCTrainingSamples::create,
      Arg("images_from"), Arg("images_to"), Arg("gt"), Arg("descriptor_type")).
    define_singleton_function<cv::Ptr<cv::optflow::GPCTrainingSamples>(*)(cv::InputArrayOfArrays, cv::InputArrayOfArrays, cv::InputArrayOfArrays, int)>("create", &cv::optflow::GPCTrainingSamples::create,
      Arg("images_from"), Arg("images_to"), Arg("gt"), Arg("descriptor_type"));

  Rice::Data_Type<cv::optflow::GPCTrainingParams> rb_cCvOptflowGPCTrainingParams = define_class_under<cv::optflow::GPCTrainingParams>(rb_mCvOptflow, "GPCTrainingParams").
    define_attr("max_tree_depth", &cv::optflow::GPCTrainingParams::maxTreeDepth).
    define_attr("min_number_of_samples", &cv::optflow::GPCTrainingParams::minNumberOfSamples).
    define_attr("descriptor_type", &cv::optflow::GPCTrainingParams::descriptorType).
    define_attr("print_progress", &cv::optflow::GPCTrainingParams::printProgress).
    define_constructor(Constructor<cv::optflow::GPCTrainingParams, unsigned int, int, cv::optflow::GPCDescType, bool>(),
      Arg("_max_tree_depth") = static_cast<unsigned int>(20), Arg("_min_number_of_samples") = static_cast<int>(3), Arg("_descriptor_type") = static_cast<cv::optflow::GPCDescType>(cv::optflow::GPC_DESCRIPTOR_DCT), Arg("_print_progress") = static_cast<bool>(true)).
    define_method<bool(cv::optflow::GPCTrainingParams::*)() const>("check?", &cv::optflow::GPCTrainingParams::check);

  Rice::Data_Type<cv::optflow::GPCMatchingParams> rb_cCvOptflowGPCMatchingParams = define_class_under<cv::optflow::GPCMatchingParams>(rb_mCvOptflow, "GPCMatchingParams").
    define_attr("use_open_cl", &cv::optflow::GPCMatchingParams::useOpenCL).
    define_constructor(Constructor<cv::optflow::GPCMatchingParams, bool>(),
      Arg("_use_open_cl") = static_cast<bool>(false)).
    define_constructor(Constructor<cv::optflow::GPCMatchingParams, const cv::optflow::GPCMatchingParams&>(),
      Arg("params"));

  Rice::Data_Type<cv::optflow::GPCTree> rb_cCvOptflowGPCTree = define_class_under<cv::optflow::GPCTree, cv::Algorithm>(rb_mCvOptflow, "GPCTree").
    define_constructor(Constructor<cv::optflow::GPCTree>()).
    define_method<void(cv::optflow::GPCTree::*)(cv::optflow::GPCTrainingSamples&, const cv::optflow::GPCTrainingParams)>("train", &cv::optflow::GPCTree::train,
      Arg("samples"), Arg("params") = static_cast<const cv::optflow::GPCTrainingParams>(cv::optflow::GPCTrainingParams())).
    define_method<void(cv::optflow::GPCTree::*)(cv::FileStorage&) const>("write", &cv::optflow::GPCTree::write,
      Arg("fs")).
    define_method<void(cv::optflow::GPCTree::*)(const cv::FileNode&)>("read", &cv::optflow::GPCTree::read,
      Arg("fn")).
    define_method<unsigned int(cv::optflow::GPCTree::*)(const cv::optflow::GPCPatchDescriptor&) const>("find_leaf_for_patch", &cv::optflow::GPCTree::findLeafForPatch,
      Arg("descr")).
    define_method<bool(cv::optflow::GPCTree::*)(const cv::optflow::GPCTree&) const>("==", &cv::optflow::GPCTree::operator==,
      Arg("t")).
    define_method<int(cv::optflow::GPCTree::*)() const>("get_descriptor_type", &cv::optflow::GPCTree::getDescriptorType).
    define_singleton_function<cv::Ptr<cv::optflow::GPCTree>(*)()>("create", &cv::optflow::GPCTree::create);

  Rice::Data_Type<cv::optflow::GPCTree::Node> rb_cCvOptflowGPCTreeNode = define_class_under<cv::optflow::GPCTree::Node>(rb_cCvOptflowGPCTree, "Node").
    define_constructor(Constructor<cv::optflow::GPCTree::Node>()).
    define_attr("coef", &cv::optflow::GPCTree::Node::coef).
    define_attr("rhs", &cv::optflow::GPCTree::Node::rhs).
    define_attr("left", &cv::optflow::GPCTree::Node::left).
    define_attr("right", &cv::optflow::GPCTree::Node::right).
    define_method<bool(cv::optflow::GPCTree::Node::*)(const cv::optflow::GPCTree::Node&) const>("==", &cv::optflow::GPCTree::Node::operator==,
      Arg("n"));

  Rice::Data_Type<cv::optflow::GPCDetails> rb_cCvOptflowGPCDetails = define_class_under<cv::optflow::GPCDetails>(rb_mCvOptflow, "GPCDetails").
    define_constructor(Constructor<cv::optflow::GPCDetails>()).
    define_singleton_function<void(*)(std::vector<std::pair<cv::Point_<int>, cv::Point_<int>>>&)>("drop_outliers", &cv::optflow::GPCDetails::dropOutliers,
      Arg("corr")).
    define_singleton_function<void(*)(const cv::Mat*, std::vector<cv::optflow::GPCPatchDescriptor>&, const cv::optflow::GPCMatchingParams&, int)>("get_all_descriptors_for_image", &cv::optflow::GPCDetails::getAllDescriptorsForImage,
      Arg("img_ch"), Arg("descr"), Arg("mp"), Arg("type")).
    define_singleton_function<void(*)(size_t, cv::Size, int&, int&)>("get_coordinates_from_index", &cv::optflow::GPCDetails::getCoordinatesFromIndex,
      Arg("index"), Arg("sz"), Arg("x"), Arg("y"));

  rb_mCv.define_module_function<void(*)(cv::FileStorage&, const cv::String&, const cv::optflow::GPCTree::Node&)>("write", &cv::write,
    Arg("fs"), Arg("name"), Arg("node"));

  rb_mCv.define_module_function<void(*)(const cv::FileNode&, cv::optflow::GPCTree::Node&, cv::optflow::GPCTree::Node)>("read", &cv::read,
    Arg("fn"), Arg("node"), Arg("arg_2"));
}