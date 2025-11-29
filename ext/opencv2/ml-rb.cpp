#include <opencv2/ml.hpp>
#include "core/cvstd_wrapper-rb.hpp"
#include "ml-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvMlANNMLP;
Rice::Class rb_cCvMlBoost;
Rice::Class rb_cCvMlDTrees;
Rice::Class rb_cCvMlDTreesNode;
Rice::Class rb_cCvMlDTreesSplit;
Rice::Class rb_cCvMlEM;
Rice::Class rb_cCvMlKNearest;
Rice::Class rb_cCvMlLogisticRegression;
Rice::Class rb_cCvMlNormalBayesClassifier;
Rice::Class rb_cCvMlParamGrid;
Rice::Class rb_cCvMlRTrees;
Rice::Class rb_cCvMlSVM;
Rice::Class rb_cCvMlSVMKernel;
Rice::Class rb_cCvMlSVMSGD;
Rice::Class rb_cCvMlStatModel;
Rice::Class rb_cCvMlTrainData;

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
  
  rb_cCvMlParamGrid = define_class_under<cv::ml::ParamGrid>(rb_mCvMl, "ParamGrid").
    define_constructor(Constructor<cv::ml::ParamGrid>()).
    define_constructor(Constructor<cv::ml::ParamGrid, double, double, double>(),
      Arg("_min_val"), Arg("_max_val"), Arg("_log_step")).
    define_attr("min_val", &cv::ml::ParamGrid::minVal).
    define_attr("max_val", &cv::ml::ParamGrid::maxVal).
    define_attr("log_step", &cv::ml::ParamGrid::logStep).
    define_singleton_function("create", &cv::ml::ParamGrid::create,
      Arg("min_val") = static_cast<double>(0.), Arg("max_val") = static_cast<double>(0.), Arg("logstep") = static_cast<double>(1.));
  
  rb_cCvMlTrainData = define_class_under<cv::ml::TrainData>(rb_mCvMl, "TrainData").
    define_singleton_function("missing_value", &cv::ml::TrainData::missingValue).
    define_method("get_layout", &cv::ml::TrainData::getLayout).
    define_method("get_n_train_samples", &cv::ml::TrainData::getNTrainSamples).
    define_method("get_n_test_samples", &cv::ml::TrainData::getNTestSamples).
    define_method("get_n_samples", &cv::ml::TrainData::getNSamples).
    define_method("get_n_vars", &cv::ml::TrainData::getNVars).
    define_method("get_n_all_vars", &cv::ml::TrainData::getNAllVars).
    define_method("get_sample", &cv::ml::TrainData::getSample,
      Arg("var_idx"), Arg("sidx"), Arg("buf")).
    define_method("get_samples", &cv::ml::TrainData::getSamples).
    define_method("get_missing", &cv::ml::TrainData::getMissing).
    define_method("get_train_samples", &cv::ml::TrainData::getTrainSamples,
      Arg("layout") = static_cast<int>(cv::ml::SampleTypes::ROW_SAMPLE), Arg("compress_samples") = static_cast<bool>(true), Arg("compress_vars") = static_cast<bool>(true)).
    define_method("get_train_responses", &cv::ml::TrainData::getTrainResponses).
    define_method("get_train_norm_cat_responses", &cv::ml::TrainData::getTrainNormCatResponses).
    define_method("get_test_responses", &cv::ml::TrainData::getTestResponses).
    define_method("get_test_norm_cat_responses", &cv::ml::TrainData::getTestNormCatResponses).
    define_method("get_responses", &cv::ml::TrainData::getResponses).
    define_method("get_norm_cat_responses", &cv::ml::TrainData::getNormCatResponses).
    define_method("get_sample_weights", &cv::ml::TrainData::getSampleWeights).
    define_method("get_train_sample_weights", &cv::ml::TrainData::getTrainSampleWeights).
    define_method("get_test_sample_weights", &cv::ml::TrainData::getTestSampleWeights).
    define_method("get_var_idx", &cv::ml::TrainData::getVarIdx).
    define_method("get_var_type", &cv::ml::TrainData::getVarType).
    define_method("get_var_symbol_flags", &cv::ml::TrainData::getVarSymbolFlags).
    define_method("get_response_type", &cv::ml::TrainData::getResponseType).
    define_method("get_train_sample_idx", &cv::ml::TrainData::getTrainSampleIdx).
    define_method("get_test_sample_idx", &cv::ml::TrainData::getTestSampleIdx).
    define_method("get_values", &cv::ml::TrainData::getValues,
      Arg("vi"), Arg("sidx"), Arg("values")).
    define_method("get_norm_cat_values", &cv::ml::TrainData::getNormCatValues,
      Arg("vi"), Arg("sidx"), Arg("values")).
    define_method("get_default_subst_values", &cv::ml::TrainData::getDefaultSubstValues).
    define_method("get_cat_count", &cv::ml::TrainData::getCatCount,
      Arg("vi")).
    define_method("get_class_labels", &cv::ml::TrainData::getClassLabels).
    define_method("get_cat_ofs", &cv::ml::TrainData::getCatOfs).
    define_method("get_cat_map", &cv::ml::TrainData::getCatMap).
    define_method("set_train_test_split", &cv::ml::TrainData::setTrainTestSplit,
      Arg("count"), Arg("shuffle") = static_cast<bool>(true)).
    define_method("set_train_test_split_ratio", &cv::ml::TrainData::setTrainTestSplitRatio,
      Arg("ratio"), Arg("shuffle") = static_cast<bool>(true)).
    define_method("shuffle_train_test", &cv::ml::TrainData::shuffleTrainTest).
    define_method("get_test_samples", &cv::ml::TrainData::getTestSamples).
    define_method("get_names", &cv::ml::TrainData::getNames,
      Arg("names")).
    define_singleton_function("get_sub_vector", &cv::ml::TrainData::getSubVector,
      Arg("vec"), Arg("idx")).
    define_singleton_function("get_sub_matrix", &cv::ml::TrainData::getSubMatrix,
      Arg("matrix"), Arg("idx"), Arg("layout")).
    define_singleton_function("load_from_csv", &cv::ml::TrainData::loadFromCSV,
      Arg("filename"), Arg("header_line_count"), Arg("response_start_idx") = static_cast<int>(-1), Arg("response_end_idx") = static_cast<int>(-1), Arg("var_type_spec") = static_cast<const String &>(String()), Arg("delimiter") = static_cast<char>(','), Arg("missch") = static_cast<char>('?')).
    define_singleton_function("create", &cv::ml::TrainData::create,
      Arg("samples"), Arg("layout"), Arg("responses"), Arg("var_idx") = static_cast<cv::InputArray>(cv::noArray()), Arg("sample_idx") = static_cast<cv::InputArray>(cv::noArray()), Arg("sample_weights") = static_cast<cv::InputArray>(cv::noArray()), Arg("var_type") = static_cast<cv::InputArray>(cv::noArray()));
  
  rb_cCvMlStatModel = define_class_under<cv::ml::StatModel, cv::Algorithm>(rb_mCvMl, "StatModel").
    define_method("get_var_count", &cv::ml::StatModel::getVarCount).
    define_method("empty?", &cv::ml::StatModel::empty).
    define_method("trained?", &cv::ml::StatModel::isTrained).
    define_method("classifier?", &cv::ml::StatModel::isClassifier).
    define_method<bool(cv::ml::StatModel::*)(const cv::Ptr<cv::ml::TrainData>&, int)>("train?", &cv::ml::StatModel::train,
      Arg("train_data"), Arg("flags") = static_cast<int>(0)).
    define_method<bool(cv::ml::StatModel::*)(cv::InputArray, int, cv::InputArray)>("train?", &cv::ml::StatModel::train,
      Arg("samples"), Arg("layout"), Arg("responses")).
    define_method("calc_error", &cv::ml::StatModel::calcError,
      Arg("data"), Arg("test"), Arg("resp")).
    define_method("predict", &cv::ml::StatModel::predict,
      Arg("samples"), Arg("results") = static_cast<cv::OutputArray>(cv::noArray()), Arg("flags") = static_cast<int>(0));
  
  Enum<cv::ml::StatModel::Flags> rb_cCvMlStatModelFlags = define_enum_under<cv::ml::StatModel::Flags>("Flags", rb_cCvMlStatModel).
    define_value("UPDATE_MODEL", cv::ml::StatModel::Flags::UPDATE_MODEL).
    define_value("RAW_OUTPUT", cv::ml::StatModel::Flags::RAW_OUTPUT).
    define_value("COMPRESSED_INPUT", cv::ml::StatModel::Flags::COMPRESSED_INPUT).
    define_value("PREPROCESSED_INPUT", cv::ml::StatModel::Flags::PREPROCESSED_INPUT);
  
  rb_cCvMlNormalBayesClassifier = define_class_under<cv::ml::NormalBayesClassifier, cv::ml::StatModel>(rb_mCvMl, "NormalBayesClassifier").
    define_method("predict_prob", &cv::ml::NormalBayesClassifier::predictProb,
      Arg("inputs"), Arg("outputs"), Arg("output_probs"), Arg("flags") = static_cast<int>(0)).
    define_singleton_function("create", &cv::ml::NormalBayesClassifier::create).
    define_singleton_function("load", &cv::ml::NormalBayesClassifier::load,
      Arg("filepath"), Arg("node_name") = static_cast<const String &>(String()));
  
  rb_cCvMlKNearest = define_class_under<cv::ml::KNearest, cv::ml::StatModel>(rb_mCvMl, "KNearest").
    define_method("get_default_k", &cv::ml::KNearest::getDefaultK).
    define_method("set_default_k", &cv::ml::KNearest::setDefaultK,
      Arg("val")).
    define_method("get_is_classifier?", &cv::ml::KNearest::getIsClassifier).
    define_method("set_is_classifier", &cv::ml::KNearest::setIsClassifier,
      Arg("val")).
    define_method("get_emax", &cv::ml::KNearest::getEmax).
    define_method("set_emax", &cv::ml::KNearest::setEmax,
      Arg("val")).
    define_method("get_algorithm_type", &cv::ml::KNearest::getAlgorithmType).
    define_method("set_algorithm_type", &cv::ml::KNearest::setAlgorithmType,
      Arg("val")).
    define_method("find_nearest", &cv::ml::KNearest::findNearest,
      Arg("samples"), Arg("k"), Arg("results"), Arg("neighbor_responses") = static_cast<cv::OutputArray>(cv::noArray()), Arg("dist") = static_cast<cv::OutputArray>(cv::noArray())).
    define_singleton_function("create", &cv::ml::KNearest::create).
    define_singleton_function("load", &cv::ml::KNearest::load,
      Arg("filepath"));
  
  Enum<cv::ml::KNearest::Types> rb_cCvMlKNearestTypes = define_enum_under<cv::ml::KNearest::Types>("Types", rb_cCvMlKNearest).
    define_value("BRUTE_FORCE", cv::ml::KNearest::Types::BRUTE_FORCE).
    define_value("KDTREE", cv::ml::KNearest::Types::KDTREE);
  
  rb_cCvMlSVM = define_class_under<cv::ml::SVM, cv::ml::StatModel>(rb_mCvMl, "SVM").
    define_method("get_type", &cv::ml::SVM::getType).
    define_method("set_type", &cv::ml::SVM::setType,
      Arg("val")).
    define_method("get_gamma", &cv::ml::SVM::getGamma).
    define_method("set_gamma", &cv::ml::SVM::setGamma,
      Arg("val")).
    define_method("get_coef0", &cv::ml::SVM::getCoef0).
    define_method("set_coef0", &cv::ml::SVM::setCoef0,
      Arg("val")).
    define_method("get_degree", &cv::ml::SVM::getDegree).
    define_method("set_degree", &cv::ml::SVM::setDegree,
      Arg("val")).
    define_method("get_c", &cv::ml::SVM::getC).
    define_method("set_c", &cv::ml::SVM::setC,
      Arg("val")).
    define_method("get_nu", &cv::ml::SVM::getNu).
    define_method("set_nu", &cv::ml::SVM::setNu,
      Arg("val")).
    define_method("get_p", &cv::ml::SVM::getP).
    define_method("set_p", &cv::ml::SVM::setP,
      Arg("val")).
    define_method("get_class_weights", &cv::ml::SVM::getClassWeights).
    define_method("set_class_weights", &cv::ml::SVM::setClassWeights,
      Arg("val")).
    define_method("get_term_criteria", &cv::ml::SVM::getTermCriteria).
    define_method("set_term_criteria", &cv::ml::SVM::setTermCriteria,
      Arg("val")).
    define_method("get_kernel_type", &cv::ml::SVM::getKernelType).
    define_method("set_kernel", &cv::ml::SVM::setKernel,
      Arg("kernel_type")).
    define_method("set_custom_kernel", &cv::ml::SVM::setCustomKernel,
      Arg("_kernel")).
    define_method<bool(cv::ml::SVM::*)(const cv::Ptr<cv::ml::TrainData>&, int, cv::ml::ParamGrid, cv::ml::ParamGrid, cv::ml::ParamGrid, cv::ml::ParamGrid, cv::ml::ParamGrid, cv::ml::ParamGrid, bool)>("train_auto?", &cv::ml::SVM::trainAuto,
      Arg("data"), Arg("k_fold") = static_cast<int>(10), Arg("cgrid") = static_cast<cv::ml::ParamGrid> (cv::ml::SVM::getDefaultGrid(cv::ml::SVM::ParamTypes::C)), Arg("gamma_grid") = static_cast<cv::ml::ParamGrid>(cv::ml::SVM::getDefaultGrid(cv::ml::SVM::ParamTypes::GAMMA)), Arg("p_grid") = static_cast<cv::ml::ParamGrid>(cv::ml::SVM::getDefaultGrid(cv::ml::SVM::ParamTypes::P)), Arg("nu_grid") = static_cast<cv::ml::ParamGrid>(cv::ml::SVM::getDefaultGrid(cv::ml::SVM::ParamTypes::NU)), Arg("coeff_grid") = static_cast<cv::ml::ParamGrid>(cv::ml::SVM::getDefaultGrid(cv::ml::SVM::ParamTypes::COEF)), Arg("degree_grid") = static_cast<cv::ml::ParamGrid>(cv::ml::SVM::getDefaultGrid(cv::ml::SVM::ParamTypes::DEGREE)), Arg("balanced") = static_cast<bool>(false)).
    define_method<bool(cv::ml::SVM::*)(cv::InputArray, int, cv::InputArray, int, cv::Ptr<cv::ml::ParamGrid>, cv::Ptr<cv::ml::ParamGrid>, cv::Ptr<cv::ml::ParamGrid>, cv::Ptr<cv::ml::ParamGrid>, cv::Ptr<cv::ml::ParamGrid>, cv::Ptr<cv::ml::ParamGrid>, bool)>("train_auto?", &cv::ml::SVM::trainAuto,
      Arg("samples"), Arg("layout"), Arg("responses"), Arg("k_fold") = static_cast<int>(10), Arg("cgrid") = static_cast<cv::Ptr<cv::ml::ParamGrid>>(cv::ml::SVM::getDefaultGridPtr(cv::ml::SVM::C)), Arg("gamma_grid") = static_cast<cv::Ptr<cv::ml::ParamGrid>>(cv::ml::SVM::getDefaultGridPtr(cv::ml::SVM::GAMMA)), Arg("p_grid") = static_cast<cv::Ptr<cv::ml::ParamGrid>>(cv::ml::SVM::getDefaultGridPtr(cv::ml::SVM::P)), Arg("nu_grid") = static_cast<cv::Ptr<cv::ml::ParamGrid>>(cv::ml::SVM::getDefaultGridPtr(cv::ml::SVM::NU)), Arg("coeff_grid") = static_cast<cv::Ptr<cv::ml::ParamGrid>>(cv::ml::SVM::getDefaultGridPtr(cv::ml::SVM::COEF)), Arg("degree_grid") = static_cast<cv::Ptr<cv::ml::ParamGrid>>(cv::ml::SVM::getDefaultGridPtr(cv::ml::SVM::DEGREE)), Arg("balanced") = static_cast<bool>(false)).
    define_method("get_support_vectors", &cv::ml::SVM::getSupportVectors).
    define_method("get_uncompressed_support_vectors", &cv::ml::SVM::getUncompressedSupportVectors).
    define_method("get_decision_function", &cv::ml::SVM::getDecisionFunction,
      Arg("i"), Arg("alpha"), Arg("svidx")).
    define_singleton_function("get_default_grid", &cv::ml::SVM::getDefaultGrid,
      Arg("param_id")).
    define_singleton_function("get_default_grid_ptr", &cv::ml::SVM::getDefaultGridPtr,
      Arg("param_id")).
    define_singleton_function("create", &cv::ml::SVM::create).
    define_singleton_function("load", &cv::ml::SVM::load,
      Arg("filepath"));
  
  rb_cCvMlSVMKernel = define_class_under<cv::ml::SVM::Kernel, cv::Algorithm>(rb_cCvMlSVM, "Kernel").
    define_method("get_type", &cv::ml::SVM::Kernel::getType).
    define_method("calc", &cv::ml::SVM::Kernel::calc,
      Arg("vcount"), Arg("n"), Arg("vecs"), Arg("another"), Arg("results"));
  
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
  
  rb_cCvMlEM = define_class_under<cv::ml::EM, cv::ml::StatModel>(rb_mCvMl, "EM").
    define_method("get_clusters_number", &cv::ml::EM::getClustersNumber).
    define_method("set_clusters_number", &cv::ml::EM::setClustersNumber,
      Arg("val")).
    define_method("get_covariance_matrix_type", &cv::ml::EM::getCovarianceMatrixType).
    define_method("set_covariance_matrix_type", &cv::ml::EM::setCovarianceMatrixType,
      Arg("val")).
    define_method("get_term_criteria", &cv::ml::EM::getTermCriteria).
    define_method("set_term_criteria", &cv::ml::EM::setTermCriteria,
      Arg("val")).
    define_method("get_weights", &cv::ml::EM::getWeights).
    define_method("get_means", &cv::ml::EM::getMeans).
    define_method("get_covs", &cv::ml::EM::getCovs,
      Arg("covs")).
    define_method("predict", &cv::ml::EM::predict,
      Arg("samples"), Arg("results") = static_cast<cv::OutputArray>(cv::noArray()), Arg("flags") = static_cast<int>(0)).
    define_method("predict2", &cv::ml::EM::predict2,
      Arg("sample"), Arg("probs")).
    define_method("train_em?", &cv::ml::EM::trainEM,
      Arg("samples"), Arg("log_likelihoods") = static_cast<cv::OutputArray>(cv::noArray()), Arg("labels") = static_cast<cv::OutputArray>(cv::noArray()), Arg("probs") = static_cast<cv::OutputArray>(cv::noArray())).
    define_method("train_e?", &cv::ml::EM::trainE,
      Arg("samples"), Arg("means0"), Arg("covs0") = static_cast<cv::InputArray>(cv::noArray()), Arg("weights0") = static_cast<cv::InputArray>(cv::noArray()), Arg("log_likelihoods") = static_cast<cv::OutputArray>(cv::noArray()), Arg("labels") = static_cast<cv::OutputArray>(cv::noArray()), Arg("probs") = static_cast<cv::OutputArray>(cv::noArray())).
    define_method("train_m?", &cv::ml::EM::trainM,
      Arg("samples"), Arg("probs0"), Arg("log_likelihoods") = static_cast<cv::OutputArray>(cv::noArray()), Arg("labels") = static_cast<cv::OutputArray>(cv::noArray()), Arg("probs") = static_cast<cv::OutputArray>(cv::noArray())).
    define_singleton_function("create", &cv::ml::EM::create).
    define_singleton_function("load", &cv::ml::EM::load,
      Arg("filepath"), Arg("node_name") = static_cast<const String &>(String()));
  
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
  
  rb_cCvMlDTrees = define_class_under<cv::ml::DTrees, cv::ml::StatModel>(rb_mCvMl, "DTrees").
    define_method("get_max_categories", &cv::ml::DTrees::getMaxCategories).
    define_method("set_max_categories", &cv::ml::DTrees::setMaxCategories,
      Arg("val")).
    define_method("get_max_depth", &cv::ml::DTrees::getMaxDepth).
    define_method("set_max_depth", &cv::ml::DTrees::setMaxDepth,
      Arg("val")).
    define_method("get_min_sample_count", &cv::ml::DTrees::getMinSampleCount).
    define_method("set_min_sample_count", &cv::ml::DTrees::setMinSampleCount,
      Arg("val")).
    define_method("get_cv_folds", &cv::ml::DTrees::getCVFolds).
    define_method("set_cv_folds", &cv::ml::DTrees::setCVFolds,
      Arg("val")).
    define_method("get_use_surrogates?", &cv::ml::DTrees::getUseSurrogates).
    define_method("set_use_surrogates", &cv::ml::DTrees::setUseSurrogates,
      Arg("val")).
    define_method("get_use1_se_rule?", &cv::ml::DTrees::getUse1SERule).
    define_method("set_use1_se_rule", &cv::ml::DTrees::setUse1SERule,
      Arg("val")).
    define_method("get_truncate_pruned_tree?", &cv::ml::DTrees::getTruncatePrunedTree).
    define_method("set_truncate_pruned_tree", &cv::ml::DTrees::setTruncatePrunedTree,
      Arg("val")).
    define_method("get_regression_accuracy", &cv::ml::DTrees::getRegressionAccuracy).
    define_method("set_regression_accuracy", &cv::ml::DTrees::setRegressionAccuracy,
      Arg("val")).
    define_method("get_priors", &cv::ml::DTrees::getPriors).
    define_method("set_priors", &cv::ml::DTrees::setPriors,
      Arg("val")).
    define_method("get_roots", &cv::ml::DTrees::getRoots).
    define_method("get_nodes", &cv::ml::DTrees::getNodes).
    define_method("get_splits", &cv::ml::DTrees::getSplits).
    define_method("get_subsets", &cv::ml::DTrees::getSubsets).
    define_singleton_function("create", &cv::ml::DTrees::create).
    define_singleton_function("load", &cv::ml::DTrees::load,
      Arg("filepath"), Arg("node_name") = static_cast<const String &>(String()));
  
  rb_cCvMlDTreesNode = define_class_under<cv::ml::DTrees::Node>(rb_cCvMlDTrees, "Node").
    define_constructor(Constructor<cv::ml::DTrees::Node>()).
    define_attr("value", &cv::ml::DTrees::Node::value).
    define_attr("class_idx", &cv::ml::DTrees::Node::classIdx).
    define_attr("parent", &cv::ml::DTrees::Node::parent).
    define_attr("left", &cv::ml::DTrees::Node::left).
    define_attr("right", &cv::ml::DTrees::Node::right).
    define_attr("default_dir", &cv::ml::DTrees::Node::defaultDir).
    define_attr("split", &cv::ml::DTrees::Node::split);
  
  rb_cCvMlDTreesSplit = define_class_under<cv::ml::DTrees::Split>(rb_cCvMlDTrees, "Split").
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
  
  rb_cCvMlRTrees = define_class_under<cv::ml::RTrees, cv::ml::DTrees>(rb_mCvMl, "RTrees").
    define_method("get_calculate_var_importance?", &cv::ml::RTrees::getCalculateVarImportance).
    define_method("set_calculate_var_importance", &cv::ml::RTrees::setCalculateVarImportance,
      Arg("val")).
    define_method("get_active_var_count", &cv::ml::RTrees::getActiveVarCount).
    define_method("set_active_var_count", &cv::ml::RTrees::setActiveVarCount,
      Arg("val")).
    define_method("get_term_criteria", &cv::ml::RTrees::getTermCriteria).
    define_method("set_term_criteria", &cv::ml::RTrees::setTermCriteria,
      Arg("val")).
    define_method("get_var_importance", &cv::ml::RTrees::getVarImportance).
    define_method("get_votes", &cv::ml::RTrees::getVotes,
      Arg("samples"), Arg("results"), Arg("flags")).
    define_method("get_oob_error", &cv::ml::RTrees::getOOBError).
    define_singleton_function("create", &cv::ml::RTrees::create).
    define_singleton_function("load", &cv::ml::RTrees::load,
      Arg("filepath"), Arg("node_name") = static_cast<const String &>(String()));
  
  rb_cCvMlBoost = define_class_under<cv::ml::Boost, cv::ml::DTrees>(rb_mCvMl, "Boost").
    define_method("get_boost_type", &cv::ml::Boost::getBoostType).
    define_method("set_boost_type", &cv::ml::Boost::setBoostType,
      Arg("val")).
    define_method("get_weak_count", &cv::ml::Boost::getWeakCount).
    define_method("set_weak_count", &cv::ml::Boost::setWeakCount,
      Arg("val")).
    define_method("get_weight_trim_rate", &cv::ml::Boost::getWeightTrimRate).
    define_method("set_weight_trim_rate", &cv::ml::Boost::setWeightTrimRate,
      Arg("val")).
    define_singleton_function("create", &cv::ml::Boost::create).
    define_singleton_function("load", &cv::ml::Boost::load,
      Arg("filepath"), Arg("node_name") = static_cast<const String &>(String()));
  
  Enum<cv::ml::Boost::Types> rb_cCvMlBoostTypes = define_enum_under<cv::ml::Boost::Types>("Types", rb_cCvMlBoost).
    define_value("DISCRETE", cv::ml::Boost::Types::DISCRETE).
    define_value("REAL", cv::ml::Boost::Types::REAL).
    define_value("LOGIT", cv::ml::Boost::Types::LOGIT).
    define_value("GENTLE", cv::ml::Boost::Types::GENTLE);
  
  rb_cCvMlANNMLP = define_class_under<cv::ml::ANN_MLP, cv::ml::StatModel>(rb_mCvMl, "ANN_MLP").
    define_method("set_train_method", &cv::ml::ANN_MLP::setTrainMethod,
      Arg("method"), Arg("param1") = static_cast<double>(0), Arg("param2") = static_cast<double>(0)).
    define_method("get_train_method", &cv::ml::ANN_MLP::getTrainMethod).
    define_method("set_activation_function", &cv::ml::ANN_MLP::setActivationFunction,
      Arg("type"), Arg("param1") = static_cast<double>(0), Arg("param2") = static_cast<double>(0)).
    define_method("set_layer_sizes", &cv::ml::ANN_MLP::setLayerSizes,
      Arg("_layer_sizes")).
    define_method("get_layer_sizes", &cv::ml::ANN_MLP::getLayerSizes).
    define_method("get_term_criteria", &cv::ml::ANN_MLP::getTermCriteria).
    define_method("set_term_criteria", &cv::ml::ANN_MLP::setTermCriteria,
      Arg("val")).
    define_method("get_backprop_weight_scale", &cv::ml::ANN_MLP::getBackpropWeightScale).
    define_method("set_backprop_weight_scale", &cv::ml::ANN_MLP::setBackpropWeightScale,
      Arg("val")).
    define_method("get_backprop_momentum_scale", &cv::ml::ANN_MLP::getBackpropMomentumScale).
    define_method("set_backprop_momentum_scale", &cv::ml::ANN_MLP::setBackpropMomentumScale,
      Arg("val")).
    define_method("get_rprop_dw0", &cv::ml::ANN_MLP::getRpropDW0).
    define_method("set_rprop_dw0", &cv::ml::ANN_MLP::setRpropDW0,
      Arg("val")).
    define_method("get_rprop_dw_plus", &cv::ml::ANN_MLP::getRpropDWPlus).
    define_method("set_rprop_dw_plus", &cv::ml::ANN_MLP::setRpropDWPlus,
      Arg("val")).
    define_method("get_rprop_dw_minus", &cv::ml::ANN_MLP::getRpropDWMinus).
    define_method("set_rprop_dw_minus", &cv::ml::ANN_MLP::setRpropDWMinus,
      Arg("val")).
    define_method("get_rprop_dw_min", &cv::ml::ANN_MLP::getRpropDWMin).
    define_method("set_rprop_dw_min", &cv::ml::ANN_MLP::setRpropDWMin,
      Arg("val")).
    define_method("get_rprop_dw_max", &cv::ml::ANN_MLP::getRpropDWMax).
    define_method("set_rprop_dw_max", &cv::ml::ANN_MLP::setRpropDWMax,
      Arg("val")).
    define_method("get_anneal_initial_t", &cv::ml::ANN_MLP::getAnnealInitialT).
    define_method("set_anneal_initial_t", &cv::ml::ANN_MLP::setAnnealInitialT,
      Arg("val")).
    define_method("get_anneal_final_t", &cv::ml::ANN_MLP::getAnnealFinalT).
    define_method("set_anneal_final_t", &cv::ml::ANN_MLP::setAnnealFinalT,
      Arg("val")).
    define_method("get_anneal_cooling_ratio", &cv::ml::ANN_MLP::getAnnealCoolingRatio).
    define_method("set_anneal_cooling_ratio", &cv::ml::ANN_MLP::setAnnealCoolingRatio,
      Arg("val")).
    define_method("get_anneal_ite_per_step", &cv::ml::ANN_MLP::getAnnealItePerStep).
    define_method("set_anneal_ite_per_step", &cv::ml::ANN_MLP::setAnnealItePerStep,
      Arg("val")).
    define_method("set_anneal_energy_rng", &cv::ml::ANN_MLP::setAnnealEnergyRNG,
      Arg("rng")).
    define_method("get_weights", &cv::ml::ANN_MLP::getWeights,
      Arg("layer_idx")).
    define_singleton_function("create", &cv::ml::ANN_MLP::create).
    define_singleton_function("load", &cv::ml::ANN_MLP::load,
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
  
  rb_cCvMlLogisticRegression = define_class_under<cv::ml::LogisticRegression, cv::ml::StatModel>(rb_mCvMl, "LogisticRegression").
    define_method("get_learning_rate", &cv::ml::LogisticRegression::getLearningRate).
    define_method("set_learning_rate", &cv::ml::LogisticRegression::setLearningRate,
      Arg("val")).
    define_method("get_iterations", &cv::ml::LogisticRegression::getIterations).
    define_method("set_iterations", &cv::ml::LogisticRegression::setIterations,
      Arg("val")).
    define_method("get_regularization", &cv::ml::LogisticRegression::getRegularization).
    define_method("set_regularization", &cv::ml::LogisticRegression::setRegularization,
      Arg("val")).
    define_method("get_train_method", &cv::ml::LogisticRegression::getTrainMethod).
    define_method("set_train_method", &cv::ml::LogisticRegression::setTrainMethod,
      Arg("val")).
    define_method("get_mini_batch_size", &cv::ml::LogisticRegression::getMiniBatchSize).
    define_method("set_mini_batch_size", &cv::ml::LogisticRegression::setMiniBatchSize,
      Arg("val")).
    define_method("get_term_criteria", &cv::ml::LogisticRegression::getTermCriteria).
    define_method("set_term_criteria", &cv::ml::LogisticRegression::setTermCriteria,
      Arg("val")).
    define_method("predict", &cv::ml::LogisticRegression::predict,
      Arg("samples"), Arg("results") = static_cast<cv::OutputArray>(cv::noArray()), Arg("flags") = static_cast<int>(0)).
    define_method("get_learnt_thetas", &cv::ml::LogisticRegression::get_learnt_thetas).
    define_singleton_function("create", &cv::ml::LogisticRegression::create).
    define_singleton_function("load", &cv::ml::LogisticRegression::load,
      Arg("filepath"), Arg("node_name") = static_cast<const String &>(String()));
  
  Enum<cv::ml::LogisticRegression::RegKinds> rb_cCvMlLogisticRegressionRegKinds = define_enum_under<cv::ml::LogisticRegression::RegKinds>("RegKinds", rb_cCvMlLogisticRegression).
    define_value("REG_DISABLE", cv::ml::LogisticRegression::RegKinds::REG_DISABLE).
    define_value("REG_L1", cv::ml::LogisticRegression::RegKinds::REG_L1).
    define_value("REG_L2", cv::ml::LogisticRegression::RegKinds::REG_L2);
  
  Enum<cv::ml::LogisticRegression::Methods> rb_cCvMlLogisticRegressionMethods = define_enum_under<cv::ml::LogisticRegression::Methods>("Methods", rb_cCvMlLogisticRegression).
    define_value("BATCH", cv::ml::LogisticRegression::Methods::BATCH).
    define_value("MINI_BATCH", cv::ml::LogisticRegression::Methods::MINI_BATCH);
  
  rb_cCvMlSVMSGD = define_class_under<cv::ml::SVMSGD, cv::ml::StatModel>(rb_mCvMl, "SVMSGD").
    define_method("get_weights", &cv::ml::SVMSGD::getWeights).
    define_method("get_shift", &cv::ml::SVMSGD::getShift).
    define_singleton_function("create", &cv::ml::SVMSGD::create).
    define_singleton_function("load", &cv::ml::SVMSGD::load,
      Arg("filepath"), Arg("node_name") = static_cast<const String &>(String())).
    define_method("set_optimal_parameters", &cv::ml::SVMSGD::setOptimalParameters,
      Arg("svmsgd_type") = static_cast<int>(cv::ml::SVMSGD::ASGD), Arg("margin_type") = static_cast<int>(cv::ml::SVMSGD::SOFT_MARGIN)).
    define_method("get_svmsgd_type", &cv::ml::SVMSGD::getSvmsgdType).
    define_method("set_svmsgd_type", &cv::ml::SVMSGD::setSvmsgdType,
      Arg("svmsgd_type")).
    define_method("get_margin_type", &cv::ml::SVMSGD::getMarginType).
    define_method("set_margin_type", &cv::ml::SVMSGD::setMarginType,
      Arg("margin_type")).
    define_method("get_margin_regularization", &cv::ml::SVMSGD::getMarginRegularization).
    define_method("set_margin_regularization", &cv::ml::SVMSGD::setMarginRegularization,
      Arg("margin_regularization")).
    define_method("get_initial_step_size", &cv::ml::SVMSGD::getInitialStepSize).
    define_method("set_initial_step_size", &cv::ml::SVMSGD::setInitialStepSize,
      Arg("initial_step_size")).
    define_method("get_step_decreasing_power", &cv::ml::SVMSGD::getStepDecreasingPower).
    define_method("set_step_decreasing_power", &cv::ml::SVMSGD::setStepDecreasingPower,
      Arg("step_decreasing_power")).
    define_method("get_term_criteria", &cv::ml::SVMSGD::getTermCriteria).
    define_method("set_term_criteria", &cv::ml::SVMSGD::setTermCriteria,
      Arg("val"));
  
  Enum<cv::ml::SVMSGD::SvmsgdType> rb_cCvMlSVMSGDSvmsgdType = define_enum_under<cv::ml::SVMSGD::SvmsgdType>("SvmsgdType", rb_cCvMlSVMSGD).
    define_value("SGD", cv::ml::SVMSGD::SvmsgdType::SGD).
    define_value("ASGD", cv::ml::SVMSGD::SvmsgdType::ASGD);
  
  Enum<cv::ml::SVMSGD::MarginType> rb_cCvMlSVMSGDMarginType = define_enum_under<cv::ml::SVMSGD::MarginType>("MarginType", rb_cCvMlSVMSGD).
    define_value("SOFT_MARGIN", cv::ml::SVMSGD::MarginType::SOFT_MARGIN).
    define_value("HARD_MARGIN", cv::ml::SVMSGD::MarginType::HARD_MARGIN);
  
  rb_mCvMl.define_module_function("rand_mv_normal", &cv::ml::randMVNormal,
    Arg("mean"), Arg("cov"), Arg("nsamples"), Arg("samples"));
  
  rb_mCvMl.define_module_function("create_concentric_spheres_test_set", &cv::ml::createConcentricSpheresTestSet,
    Arg("nsamples"), Arg("nfeatures"), Arg("nclasses"), Arg("samples"), Arg("responses"));

}