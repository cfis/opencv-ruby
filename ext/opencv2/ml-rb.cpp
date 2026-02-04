#include <opencv2/ml.hpp>
#include "ml-rb.hpp"

using namespace Rice;

void Init_Ml()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvMl = define_module_under(rb_mCv, "Ml");

  Enum<cv::ml::VariableTypes> rb_cCvMlVariableTypes = define_enum_under<cv::ml::VariableTypes>("VariableTypes", rb_mCvMl).
    define_value("VAR_NUMERICAL", cv::ml::VariableTypes::VAR_NUMERICAL).
    define_value("VAR_ORDERED", cv::ml::VariableTypes::VAR_ORDERED).
    define_value("VAR_CATEGORICAL", cv::ml::VariableTypes::VAR_CATEGORICAL);

  Enum<cv::ml::ErrorTypes> rb_cCvMlErrorTypes = define_enum_under<cv::ml::ErrorTypes>("ErrorTypes", rb_mCvMl).
    define_value("TEST_ERROR", cv::ml::ErrorTypes::TEST_ERROR).
    define_value("TRAIN_ERROR", cv::ml::ErrorTypes::TRAIN_ERROR);

  Enum<cv::ml::SampleTypes> rb_cCvMlSampleTypes = define_enum_under<cv::ml::SampleTypes>("SampleTypes", rb_mCvMl).
    define_value("ROW_SAMPLE", cv::ml::SampleTypes::ROW_SAMPLE).
    define_value("COL_SAMPLE", cv::ml::SampleTypes::COL_SAMPLE);

  Rice::Data_Type<cv::ml::ParamGrid> rb_cCvMlParamGrid = define_class_under<cv::ml::ParamGrid>(rb_mCvMl, "ParamGrid").
    define_constructor(Constructor<cv::ml::ParamGrid>()).
    define_constructor(Constructor<cv::ml::ParamGrid, double, double, double>(),
      Arg("_min_val"), Arg("_max_val"), Arg("_log_step")).
    define_attr("min_val", &cv::ml::ParamGrid::minVal).
    define_attr("max_val", &cv::ml::ParamGrid::maxVal).
    define_attr("log_step", &cv::ml::ParamGrid::logStep).
    define_singleton_function<cv::Ptr<cv::ml::ParamGrid>(*)(double, double, double)>("create", &cv::ml::ParamGrid::create,
      Arg("min_val") = static_cast<double>(0.), Arg("max_val") = static_cast<double>(0.), Arg("logstep") = static_cast<double>(1.));

  Rice::Data_Type<cv::ml::TrainData> rb_cCvMlTrainData = define_class_under<cv::ml::TrainData>(rb_mCvMl, "TrainData").
    define_singleton_function<float(*)()>("missing_value", &cv::ml::TrainData::missingValue).
    define_method<int(cv::ml::TrainData::*)() const>("get_layout", &cv::ml::TrainData::getLayout).
    define_method<int(cv::ml::TrainData::*)() const>("get_n_train_samples", &cv::ml::TrainData::getNTrainSamples).
    define_method<int(cv::ml::TrainData::*)() const>("get_n_test_samples", &cv::ml::TrainData::getNTestSamples).
    define_method<int(cv::ml::TrainData::*)() const>("get_n_samples", &cv::ml::TrainData::getNSamples).
    define_method<int(cv::ml::TrainData::*)() const>("get_n_vars", &cv::ml::TrainData::getNVars).
    define_method<int(cv::ml::TrainData::*)() const>("get_n_all_vars", &cv::ml::TrainData::getNAllVars).
    define_method<void(cv::ml::TrainData::*)(cv::InputArray, int, float*) const>("get_sample", &cv::ml::TrainData::getSample,
      Arg("var_idx"), Arg("sidx"), ArgBuffer("buf")).
    define_method<cv::Mat(cv::ml::TrainData::*)() const>("get_samples", &cv::ml::TrainData::getSamples).
    define_method<cv::Mat(cv::ml::TrainData::*)() const>("get_missing", &cv::ml::TrainData::getMissing).
    define_method<cv::Mat(cv::ml::TrainData::*)(int, bool, bool) const>("get_train_samples", &cv::ml::TrainData::getTrainSamples,
      Arg("layout") = static_cast<int>(cv::ml::ROW_SAMPLE), Arg("compress_samples") = static_cast<bool>(true), Arg("compress_vars") = static_cast<bool>(true)).
    define_method<cv::Mat(cv::ml::TrainData::*)() const>("get_train_responses", &cv::ml::TrainData::getTrainResponses).
    define_method<cv::Mat(cv::ml::TrainData::*)() const>("get_train_norm_cat_responses", &cv::ml::TrainData::getTrainNormCatResponses).
    define_method<cv::Mat(cv::ml::TrainData::*)() const>("get_test_responses", &cv::ml::TrainData::getTestResponses).
    define_method<cv::Mat(cv::ml::TrainData::*)() const>("get_test_norm_cat_responses", &cv::ml::TrainData::getTestNormCatResponses).
    define_method<cv::Mat(cv::ml::TrainData::*)() const>("get_responses", &cv::ml::TrainData::getResponses).
    define_method<cv::Mat(cv::ml::TrainData::*)() const>("get_norm_cat_responses", &cv::ml::TrainData::getNormCatResponses).
    define_method<cv::Mat(cv::ml::TrainData::*)() const>("get_sample_weights", &cv::ml::TrainData::getSampleWeights).
    define_method<cv::Mat(cv::ml::TrainData::*)() const>("get_train_sample_weights", &cv::ml::TrainData::getTrainSampleWeights).
    define_method<cv::Mat(cv::ml::TrainData::*)() const>("get_test_sample_weights", &cv::ml::TrainData::getTestSampleWeights).
    define_method<cv::Mat(cv::ml::TrainData::*)() const>("get_var_idx", &cv::ml::TrainData::getVarIdx).
    define_method<cv::Mat(cv::ml::TrainData::*)() const>("get_var_type", &cv::ml::TrainData::getVarType).
    define_method<cv::Mat(cv::ml::TrainData::*)() const>("get_var_symbol_flags", &cv::ml::TrainData::getVarSymbolFlags).
    define_method<int(cv::ml::TrainData::*)() const>("get_response_type", &cv::ml::TrainData::getResponseType).
    define_method<cv::Mat(cv::ml::TrainData::*)() const>("get_train_sample_idx", &cv::ml::TrainData::getTrainSampleIdx).
    define_method<cv::Mat(cv::ml::TrainData::*)() const>("get_test_sample_idx", &cv::ml::TrainData::getTestSampleIdx).
    define_method<void(cv::ml::TrainData::*)(int, cv::InputArray, float*) const>("get_values", &cv::ml::TrainData::getValues,
      Arg("vi"), Arg("sidx"), ArgBuffer("values")).
    define_method<void(cv::ml::TrainData::*)(int, cv::InputArray, int*) const>("get_norm_cat_values", &cv::ml::TrainData::getNormCatValues,
      Arg("vi"), Arg("sidx"), ArgBuffer("values")).
    define_method<cv::Mat(cv::ml::TrainData::*)() const>("get_default_subst_values", &cv::ml::TrainData::getDefaultSubstValues).
    define_method<int(cv::ml::TrainData::*)(int) const>("get_cat_count", &cv::ml::TrainData::getCatCount,
      Arg("vi")).
    define_method<cv::Mat(cv::ml::TrainData::*)() const>("get_class_labels", &cv::ml::TrainData::getClassLabels).
    define_method<cv::Mat(cv::ml::TrainData::*)() const>("get_cat_ofs", &cv::ml::TrainData::getCatOfs).
    define_method<cv::Mat(cv::ml::TrainData::*)() const>("get_cat_map", &cv::ml::TrainData::getCatMap).
    define_method<void(cv::ml::TrainData::*)(int, bool)>("set_train_test_split", &cv::ml::TrainData::setTrainTestSplit,
      Arg("count"), Arg("shuffle") = static_cast<bool>(true)).
    define_method<void(cv::ml::TrainData::*)(double, bool)>("set_train_test_split_ratio", &cv::ml::TrainData::setTrainTestSplitRatio,
      Arg("ratio"), Arg("shuffle") = static_cast<bool>(true)).
    define_method<void(cv::ml::TrainData::*)()>("shuffle_train_test", &cv::ml::TrainData::shuffleTrainTest).
    define_method<cv::Mat(cv::ml::TrainData::*)() const>("get_test_samples", &cv::ml::TrainData::getTestSamples).
    define_method<void(cv::ml::TrainData::*)(std::vector<std::basic_string<char>>&) const>("get_names", &cv::ml::TrainData::getNames,
      Arg("names")).
    define_singleton_function<cv::Mat(*)(const cv::Mat&, const cv::Mat&)>("get_sub_vector", &cv::ml::TrainData::getSubVector,
      Arg("vec"), Arg("idx")).
    define_singleton_function<cv::Mat(*)(const cv::Mat&, const cv::Mat&, int)>("get_sub_matrix", &cv::ml::TrainData::getSubMatrix,
      Arg("matrix"), Arg("idx"), Arg("layout")).
    define_singleton_function<cv::Ptr<cv::ml::TrainData>(*)(const cv::String&, int, int, int, const cv::String&, char, char)>("load_from_csv", &cv::ml::TrainData::loadFromCSV,
      Arg("filename"), Arg("header_line_count"), Arg("response_start_idx") = static_cast<int>(-1), Arg("response_end_idx") = static_cast<int>(-1), Arg("var_type_spec") = static_cast<const cv::String&>(cv::String()), Arg("delimiter") = static_cast<char>(','), Arg("missch") = static_cast<char>('?')).
    define_singleton_function<cv::Ptr<cv::ml::TrainData>(*)(cv::InputArray, int, cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray)>("create", &cv::ml::TrainData::create,
      Arg("samples"), Arg("layout"), Arg("responses"), Arg("var_idx") = static_cast<cv::InputArray>(cv::noArray()), Arg("sample_idx") = static_cast<cv::InputArray>(cv::noArray()), Arg("sample_weights") = static_cast<cv::InputArray>(cv::noArray()), Arg("var_type") = static_cast<cv::InputArray>(cv::noArray()));

  Rice::Data_Type<cv::ml::StatModel> rb_cCvMlStatModel = define_class_under<cv::ml::StatModel, cv::Algorithm>(rb_mCvMl, "StatModel").
    define_method<int(cv::ml::StatModel::*)() const>("get_var_count", &cv::ml::StatModel::getVarCount).
    define_method<bool(cv::ml::StatModel::*)() const>("empty?", &cv::ml::StatModel::empty).
    define_method<bool(cv::ml::StatModel::*)() const>("trained?", &cv::ml::StatModel::isTrained).
    define_method<bool(cv::ml::StatModel::*)() const>("classifier?", &cv::ml::StatModel::isClassifier).
    define_method<bool(cv::ml::StatModel::*)(const cv::Ptr<cv::ml::TrainData>&, int)>("train", &cv::ml::StatModel::train,
      Arg("train_data"), Arg("flags") = static_cast<int>(0)).
    define_method<bool(cv::ml::StatModel::*)(cv::InputArray, int, cv::InputArray)>("train", &cv::ml::StatModel::train,
      Arg("samples"), Arg("layout"), Arg("responses")).
    define_method<float(cv::ml::StatModel::*)(const cv::Ptr<cv::ml::TrainData>&, bool, cv::OutputArray) const>("calc_error", &cv::ml::StatModel::calcError,
      Arg("data"), Arg("test"), Arg("resp")).
    define_method<float(cv::ml::StatModel::*)(cv::InputArray, cv::OutputArray, int) const>("predict", &cv::ml::StatModel::predict,
      Arg("samples"), Arg("results") = static_cast<cv::OutputArray>(cv::noArray()), Arg("flags") = static_cast<int>(0));

  Enum<cv::ml::StatModel::Flags> rb_cCvMlStatModelFlags = define_enum_under<cv::ml::StatModel::Flags>("Flags", rb_cCvMlStatModel).
    define_value("UPDATE_MODEL", cv::ml::StatModel::Flags::UPDATE_MODEL).
    define_value("RAW_OUTPUT", cv::ml::StatModel::Flags::RAW_OUTPUT).
    define_value("COMPRESSED_INPUT", cv::ml::StatModel::Flags::COMPRESSED_INPUT).
    define_value("PREPROCESSED_INPUT", cv::ml::StatModel::Flags::PREPROCESSED_INPUT);

  Rice::Data_Type<cv::ml::NormalBayesClassifier> rb_cCvMlNormalBayesClassifier = define_class_under<cv::ml::NormalBayesClassifier, cv::ml::StatModel>(rb_mCvMl, "NormalBayesClassifier").
    define_method<float(cv::ml::NormalBayesClassifier::*)(cv::InputArray, cv::OutputArray, cv::OutputArray, int) const>("predict_prob", &cv::ml::NormalBayesClassifier::predictProb,
      Arg("inputs"), Arg("outputs"), Arg("output_probs"), Arg("flags") = static_cast<int>(0)).
    define_singleton_function<cv::Ptr<cv::ml::NormalBayesClassifier>(*)()>("create", &cv::ml::NormalBayesClassifier::create).
    define_singleton_function<cv::Ptr<cv::ml::NormalBayesClassifier>(*)(const cv::String&, const cv::String&)>("load", &cv::ml::NormalBayesClassifier::load,
      Arg("filepath"), Arg("node_name") = static_cast<const cv::String&>(cv::String()));

  Rice::Data_Type<cv::ml::KNearest> rb_cCvMlKNearest = define_class_under<cv::ml::KNearest, cv::ml::StatModel>(rb_mCvMl, "KNearest").
    define_method<int(cv::ml::KNearest::*)() const>("get_default_k", &cv::ml::KNearest::getDefaultK).
    define_method<void(cv::ml::KNearest::*)(int)>("set_default_k", &cv::ml::KNearest::setDefaultK,
      Arg("val")).
    define_method<bool(cv::ml::KNearest::*)() const>("get_is_classifier?", &cv::ml::KNearest::getIsClassifier).
    define_method<void(cv::ml::KNearest::*)(bool)>("set_is_classifier", &cv::ml::KNearest::setIsClassifier,
      Arg("val")).
    define_method<int(cv::ml::KNearest::*)() const>("get_emax", &cv::ml::KNearest::getEmax).
    define_method<void(cv::ml::KNearest::*)(int)>("set_emax", &cv::ml::KNearest::setEmax,
      Arg("val")).
    define_method<int(cv::ml::KNearest::*)() const>("get_algorithm_type", &cv::ml::KNearest::getAlgorithmType).
    define_method<void(cv::ml::KNearest::*)(int)>("set_algorithm_type", &cv::ml::KNearest::setAlgorithmType,
      Arg("val")).
    define_method<float(cv::ml::KNearest::*)(cv::InputArray, int, cv::OutputArray, cv::OutputArray, cv::OutputArray) const>("find_nearest", &cv::ml::KNearest::findNearest,
      Arg("samples"), Arg("k"), Arg("results"), Arg("neighbor_responses") = static_cast<cv::OutputArray>(cv::noArray()), Arg("dist") = static_cast<cv::OutputArray>(cv::noArray())).
    define_singleton_function<cv::Ptr<cv::ml::KNearest>(*)()>("create", &cv::ml::KNearest::create).
    define_singleton_function<cv::Ptr<cv::ml::KNearest>(*)(const cv::String&)>("load", &cv::ml::KNearest::load,
      Arg("filepath"));

  Enum<cv::ml::KNearest::Types> rb_cCvMlKNearestTypes = define_enum_under<cv::ml::KNearest::Types>("Types", rb_cCvMlKNearest).
    define_value("BRUTE_FORCE", cv::ml::KNearest::Types::BRUTE_FORCE).
    define_value("KDTREE", cv::ml::KNearest::Types::KDTREE);

  Rice::Data_Type<cv::ml::SVM> rb_cCvMlSVM = define_class_under<cv::ml::SVM, cv::ml::StatModel>(rb_mCvMl, "SVM").
    define_method<int(cv::ml::SVM::*)() const>("get_type", &cv::ml::SVM::getType).
    define_method<void(cv::ml::SVM::*)(int)>("set_type", &cv::ml::SVM::setType,
      Arg("val")).
    define_method<double(cv::ml::SVM::*)() const>("get_gamma", &cv::ml::SVM::getGamma).
    define_method<void(cv::ml::SVM::*)(double)>("set_gamma", &cv::ml::SVM::setGamma,
      Arg("val")).
    define_method<double(cv::ml::SVM::*)() const>("get_coef0", &cv::ml::SVM::getCoef0).
    define_method<void(cv::ml::SVM::*)(double)>("set_coef0", &cv::ml::SVM::setCoef0,
      Arg("val")).
    define_method<double(cv::ml::SVM::*)() const>("get_degree", &cv::ml::SVM::getDegree).
    define_method<void(cv::ml::SVM::*)(double)>("set_degree", &cv::ml::SVM::setDegree,
      Arg("val")).
    define_method<double(cv::ml::SVM::*)() const>("get_c", &cv::ml::SVM::getC).
    define_method<void(cv::ml::SVM::*)(double)>("set_c", &cv::ml::SVM::setC,
      Arg("val")).
    define_method<double(cv::ml::SVM::*)() const>("get_nu", &cv::ml::SVM::getNu).
    define_method<void(cv::ml::SVM::*)(double)>("set_nu", &cv::ml::SVM::setNu,
      Arg("val")).
    define_method<double(cv::ml::SVM::*)() const>("get_p", &cv::ml::SVM::getP).
    define_method<void(cv::ml::SVM::*)(double)>("set_p", &cv::ml::SVM::setP,
      Arg("val")).
    define_method<cv::Mat(cv::ml::SVM::*)() const>("get_class_weights", &cv::ml::SVM::getClassWeights).
    define_method<void(cv::ml::SVM::*)(const cv::Mat&)>("set_class_weights", &cv::ml::SVM::setClassWeights,
      Arg("val")).
    define_method<cv::TermCriteria(cv::ml::SVM::*)() const>("get_term_criteria", &cv::ml::SVM::getTermCriteria).
    define_method<void(cv::ml::SVM::*)(const cv::TermCriteria&)>("set_term_criteria", &cv::ml::SVM::setTermCriteria,
      Arg("val")).
    define_method<int(cv::ml::SVM::*)() const>("get_kernel_type", &cv::ml::SVM::getKernelType).
    define_method<void(cv::ml::SVM::*)(int)>("set_kernel", &cv::ml::SVM::setKernel,
      Arg("kernel_type")).
    define_method<void(cv::ml::SVM::*)(const cv::Ptr<cv::ml::SVM::Kernel>&)>("set_custom_kernel", &cv::ml::SVM::setCustomKernel,
      Arg("_kernel")).
    define_method<bool(cv::ml::SVM::*)(const cv::Ptr<cv::ml::TrainData>&, int, cv::ml::ParamGrid, cv::ml::ParamGrid, cv::ml::ParamGrid, cv::ml::ParamGrid, cv::ml::ParamGrid, cv::ml::ParamGrid, bool)>("train_auto", &cv::ml::SVM::trainAuto,
      Arg("data"), Arg("k_fold") = static_cast<int>(10), Arg("cgrid") = static_cast<cv::ml::ParamGrid>(cv::ml::SVM::getDefaultGrid(cv::ml::SVM::ParamTypes::C)), Arg("gamma_grid") = static_cast<cv::ml::ParamGrid>(cv::ml::SVM::getDefaultGrid(cv::ml::SVM::ParamTypes::GAMMA)), Arg("p_grid") = static_cast<cv::ml::ParamGrid>(cv::ml::SVM::getDefaultGrid(cv::ml::SVM::ParamTypes::P)), Arg("nu_grid") = static_cast<cv::ml::ParamGrid>(cv::ml::SVM::getDefaultGrid(cv::ml::SVM::ParamTypes::NU)), Arg("coeff_grid") = static_cast<cv::ml::ParamGrid>(cv::ml::SVM::getDefaultGrid(cv::ml::SVM::ParamTypes::COEF)), Arg("degree_grid") = static_cast<cv::ml::ParamGrid>(cv::ml::SVM::getDefaultGrid(cv::ml::SVM::ParamTypes::DEGREE)), Arg("balanced") = static_cast<bool>(false)).
    define_method<bool(cv::ml::SVM::*)(cv::InputArray, int, cv::InputArray, int, cv::Ptr<cv::ml::ParamGrid>, cv::Ptr<cv::ml::ParamGrid>, cv::Ptr<cv::ml::ParamGrid>, cv::Ptr<cv::ml::ParamGrid>, cv::Ptr<cv::ml::ParamGrid>, cv::Ptr<cv::ml::ParamGrid>, bool)>("train_auto", &cv::ml::SVM::trainAuto,
      Arg("samples"), Arg("layout"), Arg("responses"), Arg("k_fold") = static_cast<int>(10), Arg("cgrid") = static_cast<cv::Ptr<cv::ml::ParamGrid>>(cv::ml::SVM::getDefaultGridPtr(cv::ml::SVM::ParamTypes::C)), Arg("gamma_grid") = static_cast<cv::Ptr<cv::ml::ParamGrid>>(cv::ml::SVM::getDefaultGridPtr(cv::ml::SVM::ParamTypes::GAMMA)), Arg("p_grid") = static_cast<cv::Ptr<cv::ml::ParamGrid>>(cv::ml::SVM::getDefaultGridPtr(cv::ml::SVM::ParamTypes::P)), Arg("nu_grid") = static_cast<cv::Ptr<cv::ml::ParamGrid>>(cv::ml::SVM::getDefaultGridPtr(cv::ml::SVM::ParamTypes::NU)), Arg("coeff_grid") = static_cast<cv::Ptr<cv::ml::ParamGrid>>(cv::ml::SVM::getDefaultGridPtr(cv::ml::SVM::ParamTypes::COEF)), Arg("degree_grid") = static_cast<cv::Ptr<cv::ml::ParamGrid>>(cv::ml::SVM::getDefaultGridPtr(cv::ml::SVM::ParamTypes::DEGREE)), Arg("balanced") = static_cast<bool>(false)).
    define_method<cv::Mat(cv::ml::SVM::*)() const>("get_support_vectors", &cv::ml::SVM::getSupportVectors).
    define_method<cv::Mat(cv::ml::SVM::*)() const>("get_uncompressed_support_vectors", &cv::ml::SVM::getUncompressedSupportVectors).
    define_method<double(cv::ml::SVM::*)(int, cv::OutputArray, cv::OutputArray) const>("get_decision_function", &cv::ml::SVM::getDecisionFunction,
      Arg("i"), Arg("alpha"), Arg("svidx")).
    define_singleton_function<cv::ml::ParamGrid(*)(int)>("get_default_grid", &cv::ml::SVM::getDefaultGrid,
      Arg("param_id")).
    define_singleton_function<cv::Ptr<cv::ml::ParamGrid>(*)(int)>("get_default_grid_ptr", &cv::ml::SVM::getDefaultGridPtr,
      Arg("param_id")).
    define_singleton_function<cv::Ptr<cv::ml::SVM>(*)()>("create", &cv::ml::SVM::create).
    define_singleton_function<cv::Ptr<cv::ml::SVM>(*)(const cv::String&)>("load", &cv::ml::SVM::load,
      Arg("filepath"));

  Rice::Data_Type<cv::ml::SVM::Kernel> rb_cCvMlSVMKernel = define_class_under<cv::ml::SVM::Kernel, cv::Algorithm>(rb_cCvMlSVM, "Kernel").
    define_method<int(cv::ml::SVM::Kernel::*)() const>("get_type", &cv::ml::SVM::Kernel::getType).
    define_method<void(cv::ml::SVM::Kernel::*)(int, int, const float*, const float*, float*)>("calc", &cv::ml::SVM::Kernel::calc,
      Arg("vcount"), Arg("n"), ArgBuffer("vecs"), ArgBuffer("another"), ArgBuffer("results"));

  Enum<cv::ml::SVM::Types> rb_cCvMlSVMTypes = define_enum_under<cv::ml::SVM::Types>("Types", rb_cCvMlSVM).
    define_value("C_SVC", cv::ml::SVM::Types::C_SVC).
    define_value("NU_SVC", cv::ml::SVM::Types::NU_SVC).
    define_value("ONE_CLASS", cv::ml::SVM::Types::ONE_CLASS).
    define_value("EPS_SVR", cv::ml::SVM::Types::EPS_SVR).
    define_value("NU_SVR", cv::ml::SVM::Types::NU_SVR);

  Enum<cv::ml::SVM::KernelTypes> rb_cCvMlSVMKernelTypes = define_enum_under<cv::ml::SVM::KernelTypes>("KernelTypes", rb_cCvMlSVM).
    define_value("CUSTOM", cv::ml::SVM::KernelTypes::CUSTOM).
    define_value("LINEAR", cv::ml::SVM::KernelTypes::LINEAR).
    define_value("POLY", cv::ml::SVM::KernelTypes::POLY).
    define_value("RBF", cv::ml::SVM::KernelTypes::RBF).
    define_value("SIGMOID", cv::ml::SVM::KernelTypes::SIGMOID).
    define_value("CHI2", cv::ml::SVM::KernelTypes::CHI2).
    define_value("INTER", cv::ml::SVM::KernelTypes::INTER);

  Enum<cv::ml::SVM::ParamTypes> rb_cCvMlSVMParamTypes = define_enum_under<cv::ml::SVM::ParamTypes>("ParamTypes", rb_cCvMlSVM).
    define_value("C", cv::ml::SVM::ParamTypes::C).
    define_value("GAMMA", cv::ml::SVM::ParamTypes::GAMMA).
    define_value("P", cv::ml::SVM::ParamTypes::P).
    define_value("NU", cv::ml::SVM::ParamTypes::NU).
    define_value("COEF", cv::ml::SVM::ParamTypes::COEF).
    define_value("DEGREE", cv::ml::SVM::ParamTypes::DEGREE);

  Rice::Data_Type<cv::ml::EM> rb_cCvMlEM = define_class_under<cv::ml::EM, cv::ml::StatModel>(rb_mCvMl, "EM").
    define_method<int(cv::ml::EM::*)() const>("get_clusters_number", &cv::ml::EM::getClustersNumber).
    define_method<void(cv::ml::EM::*)(int)>("set_clusters_number", &cv::ml::EM::setClustersNumber,
      Arg("val")).
    define_method<int(cv::ml::EM::*)() const>("get_covariance_matrix_type", &cv::ml::EM::getCovarianceMatrixType).
    define_method<void(cv::ml::EM::*)(int)>("set_covariance_matrix_type", &cv::ml::EM::setCovarianceMatrixType,
      Arg("val")).
    define_method<cv::TermCriteria(cv::ml::EM::*)() const>("get_term_criteria", &cv::ml::EM::getTermCriteria).
    define_method<void(cv::ml::EM::*)(const cv::TermCriteria&)>("set_term_criteria", &cv::ml::EM::setTermCriteria,
      Arg("val")).
    define_method<cv::Mat(cv::ml::EM::*)() const>("get_weights", &cv::ml::EM::getWeights).
    define_method<cv::Mat(cv::ml::EM::*)() const>("get_means", &cv::ml::EM::getMeans).
    define_method<void(cv::ml::EM::*)(std::vector<cv::Mat>&) const>("get_covs", &cv::ml::EM::getCovs,
      Arg("covs")).
    define_method<float(cv::ml::EM::*)(cv::InputArray, cv::OutputArray, int) const>("predict", &cv::ml::EM::predict,
      Arg("samples"), Arg("results") = static_cast<cv::OutputArray>(cv::noArray()), Arg("flags") = static_cast<int>(0)).
    define_method<cv::Vec2d(cv::ml::EM::*)(cv::InputArray, cv::OutputArray) const>("predict2", &cv::ml::EM::predict2,
      Arg("sample"), Arg("probs")).
    define_method<bool(cv::ml::EM::*)(cv::InputArray, cv::OutputArray, cv::OutputArray, cv::OutputArray)>("train_em", &cv::ml::EM::trainEM,
      Arg("samples"), Arg("log_likelihoods") = static_cast<cv::OutputArray>(cv::noArray()), Arg("labels") = static_cast<cv::OutputArray>(cv::noArray()), Arg("probs") = static_cast<cv::OutputArray>(cv::noArray())).
    define_method<bool(cv::ml::EM::*)(cv::InputArray, cv::InputArray, cv::InputArray, cv::InputArray, cv::OutputArray, cv::OutputArray, cv::OutputArray)>("train_e", &cv::ml::EM::trainE,
      Arg("samples"), Arg("means0"), Arg("covs0") = static_cast<cv::InputArray>(cv::noArray()), Arg("weights0") = static_cast<cv::InputArray>(cv::noArray()), Arg("log_likelihoods") = static_cast<cv::OutputArray>(cv::noArray()), Arg("labels") = static_cast<cv::OutputArray>(cv::noArray()), Arg("probs") = static_cast<cv::OutputArray>(cv::noArray())).
    define_method<bool(cv::ml::EM::*)(cv::InputArray, cv::InputArray, cv::OutputArray, cv::OutputArray, cv::OutputArray)>("train_m", &cv::ml::EM::trainM,
      Arg("samples"), Arg("probs0"), Arg("log_likelihoods") = static_cast<cv::OutputArray>(cv::noArray()), Arg("labels") = static_cast<cv::OutputArray>(cv::noArray()), Arg("probs") = static_cast<cv::OutputArray>(cv::noArray())).
    define_singleton_function<cv::Ptr<cv::ml::EM>(*)()>("create", &cv::ml::EM::create).
    define_singleton_function<cv::Ptr<cv::ml::EM>(*)(const cv::String&, const cv::String&)>("load", &cv::ml::EM::load,
      Arg("filepath"), Arg("node_name") = static_cast<const cv::String&>(cv::String()));

  Enum<cv::ml::EM::Types> rb_cCvMlEMTypes = define_enum_under<cv::ml::EM::Types>("Types", rb_cCvMlEM).
    define_value("COV_MAT_SPHERICAL", cv::ml::EM::Types::COV_MAT_SPHERICAL).
    define_value("COV_MAT_DIAGONAL", cv::ml::EM::Types::COV_MAT_DIAGONAL).
    define_value("COV_MAT_GENERIC", cv::ml::EM::Types::COV_MAT_GENERIC).
    define_value("COV_MAT_DEFAULT", cv::ml::EM::Types::COV_MAT_DEFAULT);

  rb_cCvMlEM.define_constant("DEFAULT_NCLUSTERS", (int)cv::ml::EM::DEFAULT_NCLUSTERS);
  rb_cCvMlEM.define_constant("DEFAULT_MAX_ITERS", (int)cv::ml::EM::DEFAULT_MAX_ITERS);

  rb_cCvMlEM.define_constant("START_E_STEP", (int)cv::ml::EM::START_E_STEP);
  rb_cCvMlEM.define_constant("START_M_STEP", (int)cv::ml::EM::START_M_STEP);
  rb_cCvMlEM.define_constant("START_AUTO_STEP", (int)cv::ml::EM::START_AUTO_STEP);

  Rice::Data_Type<cv::ml::DTrees> rb_cCvMlDTrees = define_class_under<cv::ml::DTrees, cv::ml::StatModel>(rb_mCvMl, "DTrees").
    define_method<int(cv::ml::DTrees::*)() const>("get_max_categories", &cv::ml::DTrees::getMaxCategories).
    define_method<void(cv::ml::DTrees::*)(int)>("set_max_categories", &cv::ml::DTrees::setMaxCategories,
      Arg("val")).
    define_method<int(cv::ml::DTrees::*)() const>("get_max_depth", &cv::ml::DTrees::getMaxDepth).
    define_method<void(cv::ml::DTrees::*)(int)>("set_max_depth", &cv::ml::DTrees::setMaxDepth,
      Arg("val")).
    define_method<int(cv::ml::DTrees::*)() const>("get_min_sample_count", &cv::ml::DTrees::getMinSampleCount).
    define_method<void(cv::ml::DTrees::*)(int)>("set_min_sample_count", &cv::ml::DTrees::setMinSampleCount,
      Arg("val")).
    define_method<int(cv::ml::DTrees::*)() const>("get_cv_folds", &cv::ml::DTrees::getCVFolds).
    define_method<void(cv::ml::DTrees::*)(int)>("set_cv_folds", &cv::ml::DTrees::setCVFolds,
      Arg("val")).
    define_method<bool(cv::ml::DTrees::*)() const>("get_use_surrogates?", &cv::ml::DTrees::getUseSurrogates).
    define_method<void(cv::ml::DTrees::*)(bool)>("set_use_surrogates", &cv::ml::DTrees::setUseSurrogates,
      Arg("val")).
    define_method<bool(cv::ml::DTrees::*)() const>("get_use_1se_rule?", &cv::ml::DTrees::getUse1SERule).
    define_method<void(cv::ml::DTrees::*)(bool)>("set_use_1se_rule", &cv::ml::DTrees::setUse1SERule,
      Arg("val")).
    define_method<bool(cv::ml::DTrees::*)() const>("get_truncate_pruned_tree?", &cv::ml::DTrees::getTruncatePrunedTree).
    define_method<void(cv::ml::DTrees::*)(bool)>("set_truncate_pruned_tree", &cv::ml::DTrees::setTruncatePrunedTree,
      Arg("val")).
    define_method<float(cv::ml::DTrees::*)() const>("get_regression_accuracy", &cv::ml::DTrees::getRegressionAccuracy).
    define_method<void(cv::ml::DTrees::*)(float)>("set_regression_accuracy", &cv::ml::DTrees::setRegressionAccuracy,
      Arg("val")).
    define_method<cv::Mat(cv::ml::DTrees::*)() const>("get_priors", &cv::ml::DTrees::getPriors).
    define_method<void(cv::ml::DTrees::*)(const cv::Mat&)>("set_priors", &cv::ml::DTrees::setPriors,
      Arg("val")).
    define_method<const std::vector<int>&(cv::ml::DTrees::*)() const>("get_roots", &cv::ml::DTrees::getRoots).
    define_method<const std::vector<cv::ml::DTrees::Node>&(cv::ml::DTrees::*)() const>("get_nodes", &cv::ml::DTrees::getNodes).
    define_method<const std::vector<cv::ml::DTrees::Split>&(cv::ml::DTrees::*)() const>("get_splits", &cv::ml::DTrees::getSplits).
    define_method<const std::vector<int>&(cv::ml::DTrees::*)() const>("get_subsets", &cv::ml::DTrees::getSubsets).
    define_singleton_function<cv::Ptr<cv::ml::DTrees>(*)()>("create", &cv::ml::DTrees::create).
    define_singleton_function<cv::Ptr<cv::ml::DTrees>(*)(const cv::String&, const cv::String&)>("load", &cv::ml::DTrees::load,
      Arg("filepath"), Arg("node_name") = static_cast<const cv::String&>(cv::String()));

  Rice::Data_Type<cv::ml::DTrees::Node> rb_cCvMlDTreesNode = define_class_under<cv::ml::DTrees::Node>(rb_cCvMlDTrees, "Node").
    define_constructor(Constructor<cv::ml::DTrees::Node>()).
    define_attr("value", &cv::ml::DTrees::Node::value).
    define_attr("class_idx", &cv::ml::DTrees::Node::classIdx).
    define_attr("parent", &cv::ml::DTrees::Node::parent).
    define_attr("left", &cv::ml::DTrees::Node::left).
    define_attr("right", &cv::ml::DTrees::Node::right).
    define_attr("default_dir", &cv::ml::DTrees::Node::defaultDir).
    define_attr("split", &cv::ml::DTrees::Node::split);

  Rice::Data_Type<cv::ml::DTrees::Split> rb_cCvMlDTreesSplit = define_class_under<cv::ml::DTrees::Split>(rb_cCvMlDTrees, "Split").
    define_constructor(Constructor<cv::ml::DTrees::Split>()).
    define_attr("var_idx", &cv::ml::DTrees::Split::varIdx).
    define_attr("inversed", &cv::ml::DTrees::Split::inversed).
    define_attr("quality", &cv::ml::DTrees::Split::quality).
    define_attr("next", &cv::ml::DTrees::Split::next).
    define_attr("c", &cv::ml::DTrees::Split::c).
    define_attr("subset_ofs", &cv::ml::DTrees::Split::subsetOfs);

  Enum<cv::ml::DTrees::Flags> rb_cCvMlDTreesFlags = define_enum_under<cv::ml::DTrees::Flags>("Flags", rb_cCvMlDTrees).
    define_value("PREDICT_AUTO", cv::ml::DTrees::Flags::PREDICT_AUTO).
    define_value("PREDICT_SUM", cv::ml::DTrees::Flags::PREDICT_SUM).
    define_value("PREDICT_MAX_VOTE", cv::ml::DTrees::Flags::PREDICT_MAX_VOTE).
    define_value("PREDICT_MASK", cv::ml::DTrees::Flags::PREDICT_MASK);

  Rice::Data_Type<cv::ml::RTrees> rb_cCvMlRTrees = define_class_under<cv::ml::RTrees, cv::ml::DTrees>(rb_mCvMl, "RTrees").
    define_method<bool(cv::ml::RTrees::*)() const>("get_calculate_var_importance?", &cv::ml::RTrees::getCalculateVarImportance).
    define_method<void(cv::ml::RTrees::*)(bool)>("set_calculate_var_importance", &cv::ml::RTrees::setCalculateVarImportance,
      Arg("val")).
    define_method<int(cv::ml::RTrees::*)() const>("get_active_var_count", &cv::ml::RTrees::getActiveVarCount).
    define_method<void(cv::ml::RTrees::*)(int)>("set_active_var_count", &cv::ml::RTrees::setActiveVarCount,
      Arg("val")).
    define_method<cv::TermCriteria(cv::ml::RTrees::*)() const>("get_term_criteria", &cv::ml::RTrees::getTermCriteria).
    define_method<void(cv::ml::RTrees::*)(const cv::TermCriteria&)>("set_term_criteria", &cv::ml::RTrees::setTermCriteria,
      Arg("val")).
    define_method<cv::Mat(cv::ml::RTrees::*)() const>("get_var_importance", &cv::ml::RTrees::getVarImportance).
    define_method<void(cv::ml::RTrees::*)(cv::InputArray, cv::OutputArray, int) const>("get_votes", &cv::ml::RTrees::getVotes,
      Arg("samples"), Arg("results"), Arg("flags")).
    define_method<double(cv::ml::RTrees::*)() const>("get_oob_error", &cv::ml::RTrees::getOOBError).
    define_singleton_function<cv::Ptr<cv::ml::RTrees>(*)()>("create", &cv::ml::RTrees::create).
    define_singleton_function<cv::Ptr<cv::ml::RTrees>(*)(const cv::String&, const cv::String&)>("load", &cv::ml::RTrees::load,
      Arg("filepath"), Arg("node_name") = static_cast<const cv::String&>(cv::String()));

  Rice::Data_Type<cv::ml::Boost> rb_cCvMlBoost = define_class_under<cv::ml::Boost, cv::ml::DTrees>(rb_mCvMl, "Boost").
    define_method<int(cv::ml::Boost::*)() const>("get_boost_type", &cv::ml::Boost::getBoostType).
    define_method<void(cv::ml::Boost::*)(int)>("set_boost_type", &cv::ml::Boost::setBoostType,
      Arg("val")).
    define_method<int(cv::ml::Boost::*)() const>("get_weak_count", &cv::ml::Boost::getWeakCount).
    define_method<void(cv::ml::Boost::*)(int)>("set_weak_count", &cv::ml::Boost::setWeakCount,
      Arg("val")).
    define_method<double(cv::ml::Boost::*)() const>("get_weight_trim_rate", &cv::ml::Boost::getWeightTrimRate).
    define_method<void(cv::ml::Boost::*)(double)>("set_weight_trim_rate", &cv::ml::Boost::setWeightTrimRate,
      Arg("val")).
    define_singleton_function<cv::Ptr<cv::ml::Boost>(*)()>("create", &cv::ml::Boost::create).
    define_singleton_function<cv::Ptr<cv::ml::Boost>(*)(const cv::String&, const cv::String&)>("load", &cv::ml::Boost::load,
      Arg("filepath"), Arg("node_name") = static_cast<const cv::String&>(cv::String()));

  Enum<cv::ml::Boost::Types> rb_cCvMlBoostTypes = define_enum_under<cv::ml::Boost::Types>("Types", rb_cCvMlBoost).
    define_value("DISCRETE", cv::ml::Boost::Types::DISCRETE).
    define_value("REAL", cv::ml::Boost::Types::REAL).
    define_value("LOGIT", cv::ml::Boost::Types::LOGIT).
    define_value("GENTLE", cv::ml::Boost::Types::GENTLE);

  Rice::Data_Type<cv::ml::ANN_MLP> rb_cCvMlANNMLP = define_class_under<cv::ml::ANN_MLP, cv::ml::StatModel>(rb_mCvMl, "ANN_MLP").
    define_method<void(cv::ml::ANN_MLP::*)(int, double, double)>("set_train_method", &cv::ml::ANN_MLP::setTrainMethod,
      Arg("method"), Arg("param1") = static_cast<double>(0), Arg("param2") = static_cast<double>(0)).
    define_method<int(cv::ml::ANN_MLP::*)() const>("get_train_method", &cv::ml::ANN_MLP::getTrainMethod).
    define_method<void(cv::ml::ANN_MLP::*)(int, double, double)>("set_activation_function", &cv::ml::ANN_MLP::setActivationFunction,
      Arg("type"), Arg("param1") = static_cast<double>(0), Arg("param2") = static_cast<double>(0)).
    define_method<void(cv::ml::ANN_MLP::*)(cv::InputArray)>("set_layer_sizes", &cv::ml::ANN_MLP::setLayerSizes,
      Arg("_layer_sizes")).
    define_method<cv::Mat(cv::ml::ANN_MLP::*)() const>("get_layer_sizes", &cv::ml::ANN_MLP::getLayerSizes).
    define_method<cv::TermCriteria(cv::ml::ANN_MLP::*)() const>("get_term_criteria", &cv::ml::ANN_MLP::getTermCriteria).
    define_method<void(cv::ml::ANN_MLP::*)(cv::TermCriteria)>("set_term_criteria", &cv::ml::ANN_MLP::setTermCriteria,
      Arg("val")).
    define_method<double(cv::ml::ANN_MLP::*)() const>("get_backprop_weight_scale", &cv::ml::ANN_MLP::getBackpropWeightScale).
    define_method<void(cv::ml::ANN_MLP::*)(double)>("set_backprop_weight_scale", &cv::ml::ANN_MLP::setBackpropWeightScale,
      Arg("val")).
    define_method<double(cv::ml::ANN_MLP::*)() const>("get_backprop_momentum_scale", &cv::ml::ANN_MLP::getBackpropMomentumScale).
    define_method<void(cv::ml::ANN_MLP::*)(double)>("set_backprop_momentum_scale", &cv::ml::ANN_MLP::setBackpropMomentumScale,
      Arg("val")).
    define_method<double(cv::ml::ANN_MLP::*)() const>("get_rprop_dw0", &cv::ml::ANN_MLP::getRpropDW0).
    define_method<void(cv::ml::ANN_MLP::*)(double)>("set_rprop_dw0", &cv::ml::ANN_MLP::setRpropDW0,
      Arg("val")).
    define_method<double(cv::ml::ANN_MLP::*)() const>("get_rprop_dw_plus", &cv::ml::ANN_MLP::getRpropDWPlus).
    define_method<void(cv::ml::ANN_MLP::*)(double)>("set_rprop_dw_plus", &cv::ml::ANN_MLP::setRpropDWPlus,
      Arg("val")).
    define_method<double(cv::ml::ANN_MLP::*)() const>("get_rprop_dw_minus", &cv::ml::ANN_MLP::getRpropDWMinus).
    define_method<void(cv::ml::ANN_MLP::*)(double)>("set_rprop_dw_minus", &cv::ml::ANN_MLP::setRpropDWMinus,
      Arg("val")).
    define_method<double(cv::ml::ANN_MLP::*)() const>("get_rprop_dw_min", &cv::ml::ANN_MLP::getRpropDWMin).
    define_method<void(cv::ml::ANN_MLP::*)(double)>("set_rprop_dw_min", &cv::ml::ANN_MLP::setRpropDWMin,
      Arg("val")).
    define_method<double(cv::ml::ANN_MLP::*)() const>("get_rprop_dw_max", &cv::ml::ANN_MLP::getRpropDWMax).
    define_method<void(cv::ml::ANN_MLP::*)(double)>("set_rprop_dw_max", &cv::ml::ANN_MLP::setRpropDWMax,
      Arg("val")).
    define_method<double(cv::ml::ANN_MLP::*)() const>("get_anneal_initial_t", &cv::ml::ANN_MLP::getAnnealInitialT).
    define_method<void(cv::ml::ANN_MLP::*)(double)>("set_anneal_initial_t", &cv::ml::ANN_MLP::setAnnealInitialT,
      Arg("val")).
    define_method<double(cv::ml::ANN_MLP::*)() const>("get_anneal_final_t", &cv::ml::ANN_MLP::getAnnealFinalT).
    define_method<void(cv::ml::ANN_MLP::*)(double)>("set_anneal_final_t", &cv::ml::ANN_MLP::setAnnealFinalT,
      Arg("val")).
    define_method<double(cv::ml::ANN_MLP::*)() const>("get_anneal_cooling_ratio", &cv::ml::ANN_MLP::getAnnealCoolingRatio).
    define_method<void(cv::ml::ANN_MLP::*)(double)>("set_anneal_cooling_ratio", &cv::ml::ANN_MLP::setAnnealCoolingRatio,
      Arg("val")).
    define_method<int(cv::ml::ANN_MLP::*)() const>("get_anneal_ite_per_step", &cv::ml::ANN_MLP::getAnnealItePerStep).
    define_method<void(cv::ml::ANN_MLP::*)(int)>("set_anneal_ite_per_step", &cv::ml::ANN_MLP::setAnnealItePerStep,
      Arg("val")).
    define_method<void(cv::ml::ANN_MLP::*)(const cv::RNG&)>("set_anneal_energy_rng", &cv::ml::ANN_MLP::setAnnealEnergyRNG,
      Arg("rng")).
    define_method<cv::Mat(cv::ml::ANN_MLP::*)(int) const>("get_weights", &cv::ml::ANN_MLP::getWeights,
      Arg("layer_idx")).
    define_singleton_function<cv::Ptr<cv::ml::ANN_MLP>(*)()>("create", &cv::ml::ANN_MLP::create).
    define_singleton_function<cv::Ptr<cv::ml::ANN_MLP>(*)(const cv::String&)>("load", &cv::ml::ANN_MLP::load,
      Arg("filepath"));

  Enum<cv::ml::ANN_MLP::TrainingMethods> rb_cCvMlANNMLPTrainingMethods = define_enum_under<cv::ml::ANN_MLP::TrainingMethods>("TrainingMethods", rb_cCvMlANNMLP).
    define_value("BACKPROP", cv::ml::ANN_MLP::TrainingMethods::BACKPROP).
    define_value("RPROP", cv::ml::ANN_MLP::TrainingMethods::RPROP).
    define_value("ANNEAL", cv::ml::ANN_MLP::TrainingMethods::ANNEAL);

  Enum<cv::ml::ANN_MLP::ActivationFunctions> rb_cCvMlANNMLPActivationFunctions = define_enum_under<cv::ml::ANN_MLP::ActivationFunctions>("ActivationFunctions", rb_cCvMlANNMLP).
    define_value("IDENTITY", cv::ml::ANN_MLP::ActivationFunctions::IDENTITY).
    define_value("SIGMOID_SYM", cv::ml::ANN_MLP::ActivationFunctions::SIGMOID_SYM).
    define_value("GAUSSIAN", cv::ml::ANN_MLP::ActivationFunctions::GAUSSIAN).
    define_value("RELU", cv::ml::ANN_MLP::ActivationFunctions::RELU).
    define_value("LEAKYRELU", cv::ml::ANN_MLP::ActivationFunctions::LEAKYRELU);

  Enum<cv::ml::ANN_MLP::TrainFlags> rb_cCvMlANNMLPTrainFlags = define_enum_under<cv::ml::ANN_MLP::TrainFlags>("TrainFlags", rb_cCvMlANNMLP).
    define_value("UPDATE_WEIGHTS", cv::ml::ANN_MLP::TrainFlags::UPDATE_WEIGHTS).
    define_value("NO_INPUT_SCALE", cv::ml::ANN_MLP::TrainFlags::NO_INPUT_SCALE).
    define_value("NO_OUTPUT_SCALE", cv::ml::ANN_MLP::TrainFlags::NO_OUTPUT_SCALE);

  Rice::Data_Type<cv::ml::LogisticRegression> rb_cCvMlLogisticRegression = define_class_under<cv::ml::LogisticRegression, cv::ml::StatModel>(rb_mCvMl, "LogisticRegression").
    define_method<double(cv::ml::LogisticRegression::*)() const>("get_learning_rate", &cv::ml::LogisticRegression::getLearningRate).
    define_method<void(cv::ml::LogisticRegression::*)(double)>("set_learning_rate", &cv::ml::LogisticRegression::setLearningRate,
      Arg("val")).
    define_method<int(cv::ml::LogisticRegression::*)() const>("get_iterations", &cv::ml::LogisticRegression::getIterations).
    define_method<void(cv::ml::LogisticRegression::*)(int)>("set_iterations", &cv::ml::LogisticRegression::setIterations,
      Arg("val")).
    define_method<int(cv::ml::LogisticRegression::*)() const>("get_regularization", &cv::ml::LogisticRegression::getRegularization).
    define_method<void(cv::ml::LogisticRegression::*)(int)>("set_regularization", &cv::ml::LogisticRegression::setRegularization,
      Arg("val")).
    define_method<int(cv::ml::LogisticRegression::*)() const>("get_train_method", &cv::ml::LogisticRegression::getTrainMethod).
    define_method<void(cv::ml::LogisticRegression::*)(int)>("set_train_method", &cv::ml::LogisticRegression::setTrainMethod,
      Arg("val")).
    define_method<int(cv::ml::LogisticRegression::*)() const>("get_mini_batch_size", &cv::ml::LogisticRegression::getMiniBatchSize).
    define_method<void(cv::ml::LogisticRegression::*)(int)>("set_mini_batch_size", &cv::ml::LogisticRegression::setMiniBatchSize,
      Arg("val")).
    define_method<cv::TermCriteria(cv::ml::LogisticRegression::*)() const>("get_term_criteria", &cv::ml::LogisticRegression::getTermCriteria).
    define_method<void(cv::ml::LogisticRegression::*)(cv::TermCriteria)>("set_term_criteria", &cv::ml::LogisticRegression::setTermCriteria,
      Arg("val")).
    define_method<float(cv::ml::LogisticRegression::*)(cv::InputArray, cv::OutputArray, int) const>("predict", &cv::ml::LogisticRegression::predict,
      Arg("samples"), Arg("results") = static_cast<cv::OutputArray>(cv::noArray()), Arg("flags") = static_cast<int>(0)).
    define_method<cv::Mat(cv::ml::LogisticRegression::*)() const>("get_learnt_thetas", &cv::ml::LogisticRegression::get_learnt_thetas).
    define_singleton_function<cv::Ptr<cv::ml::LogisticRegression>(*)()>("create", &cv::ml::LogisticRegression::create).
    define_singleton_function<cv::Ptr<cv::ml::LogisticRegression>(*)(const cv::String&, const cv::String&)>("load", &cv::ml::LogisticRegression::load,
      Arg("filepath"), Arg("node_name") = static_cast<const cv::String&>(cv::String()));

  Enum<cv::ml::LogisticRegression::RegKinds> rb_cCvMlLogisticRegressionRegKinds = define_enum_under<cv::ml::LogisticRegression::RegKinds>("RegKinds", rb_cCvMlLogisticRegression).
    define_value("REG_DISABLE", cv::ml::LogisticRegression::RegKinds::REG_DISABLE).
    define_value("REG_L1", cv::ml::LogisticRegression::RegKinds::REG_L1).
    define_value("REG_L2", cv::ml::LogisticRegression::RegKinds::REG_L2);

  Enum<cv::ml::LogisticRegression::Methods> rb_cCvMlLogisticRegressionMethods = define_enum_under<cv::ml::LogisticRegression::Methods>("Methods", rb_cCvMlLogisticRegression).
    define_value("BATCH", cv::ml::LogisticRegression::Methods::BATCH).
    define_value("MINI_BATCH", cv::ml::LogisticRegression::Methods::MINI_BATCH);

  Rice::Data_Type<cv::ml::SVMSGD> rb_cCvMlSVMSGD = define_class_under<cv::ml::SVMSGD, cv::ml::StatModel>(rb_mCvMl, "SVMSGD").
    define_method<cv::Mat(cv::ml::SVMSGD::*)()>("get_weights", &cv::ml::SVMSGD::getWeights).
    define_method<float(cv::ml::SVMSGD::*)()>("get_shift", &cv::ml::SVMSGD::getShift).
    define_singleton_function<cv::Ptr<cv::ml::SVMSGD>(*)()>("create", &cv::ml::SVMSGD::create).
    define_singleton_function<cv::Ptr<cv::ml::SVMSGD>(*)(const cv::String&, const cv::String&)>("load", &cv::ml::SVMSGD::load,
      Arg("filepath"), Arg("node_name") = static_cast<const cv::String&>(cv::String())).
    define_method<void(cv::ml::SVMSGD::*)(int, int)>("set_optimal_parameters", &cv::ml::SVMSGD::setOptimalParameters,
      Arg("svmsgd_type") = static_cast<int>(cv::ml::SVMSGD::SvmsgdType::ASGD), Arg("margin_type") = static_cast<int>(cv::ml::SVMSGD::MarginType::SOFT_MARGIN)).
    define_method<int(cv::ml::SVMSGD::*)() const>("get_svmsgd_type", &cv::ml::SVMSGD::getSvmsgdType).
    define_method<void(cv::ml::SVMSGD::*)(int)>("set_svmsgd_type", &cv::ml::SVMSGD::setSvmsgdType,
      Arg("svmsgd_type")).
    define_method<int(cv::ml::SVMSGD::*)() const>("get_margin_type", &cv::ml::SVMSGD::getMarginType).
    define_method<void(cv::ml::SVMSGD::*)(int)>("set_margin_type", &cv::ml::SVMSGD::setMarginType,
      Arg("margin_type")).
    define_method<float(cv::ml::SVMSGD::*)() const>("get_margin_regularization", &cv::ml::SVMSGD::getMarginRegularization).
    define_method<void(cv::ml::SVMSGD::*)(float)>("set_margin_regularization", &cv::ml::SVMSGD::setMarginRegularization,
      Arg("margin_regularization")).
    define_method<float(cv::ml::SVMSGD::*)() const>("get_initial_step_size", &cv::ml::SVMSGD::getInitialStepSize).
    define_method<void(cv::ml::SVMSGD::*)(float)>("set_initial_step_size", &cv::ml::SVMSGD::setInitialStepSize,
      Arg("initial_step_size")).
    define_method<float(cv::ml::SVMSGD::*)() const>("get_step_decreasing_power", &cv::ml::SVMSGD::getStepDecreasingPower).
    define_method<void(cv::ml::SVMSGD::*)(float)>("set_step_decreasing_power", &cv::ml::SVMSGD::setStepDecreasingPower,
      Arg("step_decreasing_power")).
    define_method<cv::TermCriteria(cv::ml::SVMSGD::*)() const>("get_term_criteria", &cv::ml::SVMSGD::getTermCriteria).
    define_method<void(cv::ml::SVMSGD::*)(const cv::TermCriteria&)>("set_term_criteria", &cv::ml::SVMSGD::setTermCriteria,
      Arg("val"));

  Enum<cv::ml::SVMSGD::SvmsgdType> rb_cCvMlSVMSGDSvmsgdType = define_enum_under<cv::ml::SVMSGD::SvmsgdType>("SvmsgdType", rb_cCvMlSVMSGD).
    define_value("SGD", cv::ml::SVMSGD::SvmsgdType::SGD).
    define_value("ASGD", cv::ml::SVMSGD::SvmsgdType::ASGD);

  Enum<cv::ml::SVMSGD::MarginType> rb_cCvMlSVMSGDMarginType = define_enum_under<cv::ml::SVMSGD::MarginType>("MarginType", rb_cCvMlSVMSGD).
    define_value("SOFT_MARGIN", cv::ml::SVMSGD::MarginType::SOFT_MARGIN).
    define_value("HARD_MARGIN", cv::ml::SVMSGD::MarginType::HARD_MARGIN);

  rb_mCvMl.define_module_function<void(*)(cv::InputArray, cv::InputArray, int, cv::OutputArray)>("rand_mv_normal", &cv::ml::randMVNormal,
    Arg("mean"), Arg("cov"), Arg("nsamples"), Arg("samples"));

  rb_mCvMl.define_module_function<void(*)(int, int, int, cv::OutputArray, cv::OutputArray)>("create_concentric_spheres_test_set", &cv::ml::createConcentricSpheresTestSet,
    Arg("nsamples"), Arg("nfeatures"), Arg("nclasses"), Arg("samples"), Arg("responses"));
}