#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class MLTest < OpenCVTestCase
  def setup
    # Create simple training data: 2D points with 2 classes
    # Class 0: points near (0,0), Class 1: points near (10,10)
    @samples = Cv::Mat.new(20, 2, CV_32FC1)
    @responses = Cv::Mat.new(20, 1, CV_32SC1)

    10.times do |i|
      @samples[i, 0] = rand * 2.0           # x near 0
      @samples[i, 1] = rand * 2.0           # y near 0
      @responses[i, 0] = 0
    end
    10.times do |i|
      @samples[10 + i, 0] = 10.0 + rand * 2.0  # x near 10
      @samples[10 + i, 1] = 10.0 + rand * 2.0  # y near 10
      @responses[10 + i, 0] = 1
    end
  end

  # ============ ParamGrid ============
  def test_param_grid_new
    grid = Cv::Ml::ParamGrid.new
    assert_instance_of(Cv::Ml::ParamGrid, grid)
  end

  def test_param_grid_new_with_params
    grid = Cv::Ml::ParamGrid.new(0.1, 100.0, 2.0)
    assert_in_delta(0.1, grid.min_val, 0.01)
    assert_in_delta(100.0, grid.max_val, 0.01)
    assert_in_delta(2.0, grid.log_step, 0.01)
  end

  def test_param_grid_attributes
    grid = Cv::Ml::ParamGrid.new
    grid.min_val = 1.0
    grid.max_val = 10.0
    grid.log_step = 1.5

    assert_in_delta(1.0, grid.min_val, 0.01)
    assert_in_delta(10.0, grid.max_val, 0.01)
    assert_in_delta(1.5, grid.log_step, 0.01)
  end

  def test_param_grid_create
      grid = Cv::Ml::ParamGrid.create(0.5, 50.0, 3.0)
    assert_in_delta(0.5, grid.min_val, 0.01)
    assert_in_delta(50.0, grid.max_val, 0.01)
    assert_in_delta(3.0, grid.log_step, 0.01)
  end

  # ============ TrainData ============
  def test_train_data_missing_value
    val = Cv::Ml::TrainData.missing_value
    # Should return FLT_MAX or similar sentinel value
    refute_nil(val)
  end

  def test_train_data_create
    train_data = Cv::Ml::TrainData.create(
      @samples.input_array,
      Cv::Ml::SampleTypes::ROW_SAMPLE.to_i,
      @responses.input_array
    )
    refute_nil(train_data)
    assert_equal(20, train_data.get_n_samples)
    assert_equal(2, train_data.get_n_vars)
  end

  def test_train_data_get_layout
    train_data = Cv::Ml::TrainData.create(
      @samples.input_array,
      Cv::Ml::SampleTypes::ROW_SAMPLE.to_i,
      @responses.input_array
    )
    assert_equal(Cv::Ml::SampleTypes::ROW_SAMPLE.to_i, train_data.get_layout)
  end

  def test_train_data_get_train_samples
    train_data = Cv::Ml::TrainData.create(
      @samples.input_array,
      Cv::Ml::SampleTypes::ROW_SAMPLE.to_i,
      @responses.input_array
    )
    samples = train_data.get_train_samples
    assert_equal(20, samples.rows)
    assert_equal(2, samples.cols)
  end

  def test_train_data_get_responses
    train_data = Cv::Ml::TrainData.create(
      @samples.input_array,
      Cv::Ml::SampleTypes::ROW_SAMPLE.to_i,
      @responses.input_array
    )
    responses = train_data.get_responses
    assert_equal(20, responses.rows)
  end

  def test_train_data_set_train_test_split
    train_data = Cv::Ml::TrainData.create(
      @samples.input_array,
      Cv::Ml::SampleTypes::ROW_SAMPLE.to_i,
      @responses.input_array
    )
    train_data.set_train_test_split(15, true)
    assert_equal(15, train_data.get_n_train_samples)
    assert_equal(5, train_data.get_n_test_samples)
  end

  def test_train_data_set_train_test_split_ratio
    train_data = Cv::Ml::TrainData.create(
      @samples.input_array,
      Cv::Ml::SampleTypes::ROW_SAMPLE.to_i,
      @responses.input_array
    )
    train_data.set_train_test_split_ratio(0.8, true)
    assert_equal(16, train_data.get_n_train_samples)
    assert_equal(4, train_data.get_n_test_samples)
  end

  # ============ NormalBayesClassifier ============
  def test_normal_bayes_classifier_create
    classifier = Cv::Ml::NormalBayesClassifier.create
    refute_nil(classifier)
  end

  def test_normal_bayes_classifier_empty
    classifier = Cv::Ml::NormalBayesClassifier.create
    refute(classifier.empty?)
  end

  def test_normal_bayes_classifier_train
    classifier = Cv::Ml::NormalBayesClassifier.create
    result = classifier.train(@samples.input_array, Cv::Ml::SampleTypes::ROW_SAMPLE.to_i, @responses.input_array)
    assert(result)
    assert(classifier.trained?)
  end

  def test_normal_bayes_classifier_predict
    classifier = Cv::Ml::NormalBayesClassifier.create
    classifier.train(@samples.input_array, Cv::Ml::SampleTypes::ROW_SAMPLE.to_i, @responses.input_array)

    # Create test sample near class 0
    test_sample = Cv::Mat.new(1, 2, CV_32FC1)
    test_sample[0, 0] = 1.0
    test_sample[0, 1] = 1.0

    result = Cv::Mat.new
    classifier.predict(test_sample.input_array, result.output_array)

    assert_equal(1, result.rows)
    # Result should be close to 0 (class 0)
    assert_in_delta(0.0, result[0, 0], 1.0)
  end

  def test_normal_bayes_classifier_is_classifier
    classifier = Cv::Ml::NormalBayesClassifier.create
    assert(classifier.classifier?)
  end

  # ============ KNearest ============
  def test_knearest_create
    knn = Cv::Ml::KNearest.create
    refute_nil(knn)
  end

  def test_knearest_get_set_default_k
    knn = Cv::Ml::KNearest.create
    knn.set_default_k(5)
    assert_equal(5, knn.get_default_k)
  end

  def test_knearest_get_set_is_classifier
    knn = Cv::Ml::KNearest.create
    knn.set_is_classifier(true)
    assert(knn.get_is_classifier?)
  end

  def test_knearest_get_set_algorithm_type
    knn = Cv::Ml::KNearest.create
    knn.set_algorithm_type(Cv::Ml::KNearest::Types::KDTREE.to_i)
    assert_equal(Cv::Ml::KNearest::Types::KDTREE.to_i, knn.get_algorithm_type)
  end

  def test_knearest_train
    knn = Cv::Ml::KNearest.create
    knn.set_default_k(3)
    result = knn.train(@samples.input_array, Cv::Ml::SampleTypes::ROW_SAMPLE.to_i, @responses.input_array)
    assert(result)
  end

  def test_knearest_find_nearest
    knn = Cv::Ml::KNearest.create
    knn.set_default_k(3)
    knn.train(@samples.input_array, Cv::Ml::SampleTypes::ROW_SAMPLE.to_i, @responses.input_array)

    test_sample = Cv::Mat.new(1, 2, CV_32FC1)
    test_sample[0, 0] = 1.0
    test_sample[0, 1] = 1.0

    results = Cv::Mat.new
    retval = knn.find_nearest(test_sample.input_array, 3, results.output_array)

    refute_nil(retval)
    assert_equal(1, results.rows)
  end

  # ============ SVM ============
  def test_svm_create
    svm = Cv::Ml::SVM.create
    refute_nil(svm)
  end

  def test_svm_get_set_type
    svm = Cv::Ml::SVM.create
    svm.set_type(Cv::Ml::SVM::Types::NU_SVC.to_i)
    assert_equal(Cv::Ml::SVM::Types::NU_SVC.to_i, svm.get_type)
  end

  def test_svm_get_set_kernel
    svm = Cv::Ml::SVM.create
    svm.set_kernel(Cv::Ml::SVM::KernelTypes::RBF.to_i)
    assert_equal(Cv::Ml::SVM::KernelTypes::RBF.to_i, svm.get_kernel_type)
  end

  def test_svm_get_set_gamma
    svm = Cv::Ml::SVM.create
    svm.set_gamma(0.5)
    assert_in_delta(0.5, svm.get_gamma, 0.01)
  end

  def test_svm_get_set_c
    svm = Cv::Ml::SVM.create
    svm.set_c(10.0)
    assert_in_delta(10.0, svm.get_c, 0.01)
  end

  def test_svm_get_set_nu
    svm = Cv::Ml::SVM.create
    svm.set_nu(0.3)
    assert_in_delta(0.3, svm.get_nu, 0.01)
  end

  def test_svm_get_set_degree
    svm = Cv::Ml::SVM.create
    svm.set_degree(3.0)
    assert_in_delta(3.0, svm.get_degree, 0.01)
  end

  def test_svm_get_set_coef0
    svm = Cv::Ml::SVM.create
    svm.set_coef0(1.0)
    assert_in_delta(1.0, svm.get_coef0, 0.01)
  end

  def test_svm_get_set_p
    svm = Cv::Ml::SVM.create
    svm.set_p(0.5)
    assert_in_delta(0.5, svm.get_p, 0.01)
  end

  def test_svm_get_set_term_criteria
    svm = Cv::Ml::SVM.create
    tc = Cv::TermCriteria.new(Cv::TermCriteria::Type::COUNT.to_i | Cv::TermCriteria::Type::EPS.to_i, 100, 0.001)
    svm.set_term_criteria(tc)

    result = svm.get_term_criteria
    assert_equal(100, result.max_count)
    assert_in_delta(0.001, result.epsilon, 0.0001)
  end

  def test_svm_train
    svm = Cv::Ml::SVM.create
    svm.set_type(Cv::Ml::SVM::Types::C_SVC.to_i)
    svm.set_kernel(Cv::Ml::SVM::KernelTypes::LINEAR.to_i)
    svm.set_c(1.0)

    # SVM classification requires integer responses
    result = svm.train(@samples.input_array, Cv::Ml::SampleTypes::ROW_SAMPLE.to_i, @responses.input_array)
    assert(result)
    assert(svm.trained?)
  end

  def test_svm_predict
    svm = Cv::Ml::SVM.create
    svm.set_type(Cv::Ml::SVM::Types::C_SVC.to_i)
    svm.set_kernel(Cv::Ml::SVM::KernelTypes::LINEAR.to_i)
    svm.set_c(1.0)

    # SVM classification requires integer responses
    svm.train(@samples.input_array, Cv::Ml::SampleTypes::ROW_SAMPLE.to_i, @responses.input_array)

    test_sample = Cv::Mat.new(1, 2, CV_32FC1)
    test_sample[0, 0] = 1.0
    test_sample[0, 1] = 1.0

    result = Cv::Mat.new
    svm.predict(test_sample.input_array, result.output_array)

    assert_equal(1, result.rows)
  end

  def test_svm_get_support_vectors
    svm = Cv::Ml::SVM.create
    svm.set_type(Cv::Ml::SVM::Types::C_SVC.to_i)
    svm.set_kernel(Cv::Ml::SVM::KernelTypes::LINEAR.to_i)
    svm.set_c(1.0)

    # SVM classification requires integer responses
    svm.train(@samples.input_array, Cv::Ml::SampleTypes::ROW_SAMPLE.to_i, @responses.input_array)

    sv = svm.get_support_vectors
    assert_operator(sv.rows, :>=, 1)
    assert_equal(2, sv.cols)
  end

  def test_svm_get_default_grid
    grid = Cv::Ml::SVM.get_default_grid(Cv::Ml::SVM::ParamTypes::C.to_i)
    refute_nil(grid)
    assert_operator(grid.min_val, :>, 0)
  end

  # ============ EM ============
  def test_em_create
    em = Cv::Ml::EM.create
    refute_nil(em)
  end

  def test_em_get_set_clusters_number
    em = Cv::Ml::EM.create
    em.set_clusters_number(3)
    assert_equal(3, em.get_clusters_number)
  end

  def test_em_get_set_covariance_matrix_type
    em = Cv::Ml::EM.create
    em.set_covariance_matrix_type(Cv::Ml::EM::Types::COV_MAT_DIAGONAL.to_i)
    assert_equal(Cv::Ml::EM::Types::COV_MAT_DIAGONAL.to_i, em.get_covariance_matrix_type)
  end

  def test_em_get_set_term_criteria
    em = Cv::Ml::EM.create
    tc = Cv::TermCriteria.new(Cv::TermCriteria::Type::COUNT.to_i, 50, 0.01)
    em.set_term_criteria(tc)

    result = em.get_term_criteria
    assert_equal(50, result.max_count)
  end

  def test_em_train
    em = Cv::Ml::EM.create
    em.set_clusters_number(2)

    result = em.train_em(@samples.input_array)
    assert(result)
  end

  def test_em_predict
    em = Cv::Ml::EM.create
    em.set_clusters_number(2)
    em.train_em(@samples.input_array)

    test_sample = Cv::Mat.new(1, 2, CV_32FC1)
    test_sample[0, 0] = 1.0
    test_sample[0, 1] = 1.0

    result = Cv::Mat.new
    retval = em.predict(test_sample.input_array, result.output_array)

    refute_nil(retval)
  end

  def test_em_get_means
    em = Cv::Ml::EM.create
    em.set_clusters_number(2)
    em.train_em(@samples.input_array)

    means = em.get_means
    assert_equal(2, means.rows)
    assert_equal(2, means.cols)
  end

  def test_em_get_weights
    em = Cv::Ml::EM.create
    em.set_clusters_number(2)
    em.train_em(@samples.input_array)

    weights = em.get_weights
    assert_equal(1, weights.rows)
    assert_equal(2, weights.cols)
  end

  # ============ DTrees ============
  def test_dtrees_create
    dtrees = Cv::Ml::DTrees.create
    refute_nil(dtrees)
  end

  def test_dtrees_get_set_max_depth
    dtrees = Cv::Ml::DTrees.create
    dtrees.set_max_depth(10)
    assert_equal(10, dtrees.get_max_depth)
  end

  def test_dtrees_get_set_min_sample_count
    dtrees = Cv::Ml::DTrees.create
    dtrees.set_min_sample_count(5)
    assert_equal(5, dtrees.get_min_sample_count)
  end

  def test_dtrees_get_set_max_categories
    dtrees = Cv::Ml::DTrees.create
    dtrees.set_max_categories(15)
    assert_equal(15, dtrees.get_max_categories)
  end

  def test_dtrees_get_set_cv_folds
    dtrees = Cv::Ml::DTrees.create
    # OpenCV 4.x doesn't implement tree pruning with cross-validation (cv_folds > 1).
    # Setting cv_folds to 1 normalizes it to 0 (disabled). Only 0 is effectively valid.
    assert_equal(10, dtrees.get_cv_folds)  # Default is 10 (even though it's not implemented)
    dtrees.set_cv_folds(0)
    assert_equal(0, dtrees.get_cv_folds)
  end

  def test_dtrees_get_set_use_surrogates
    dtrees = Cv::Ml::DTrees.create
    dtrees.set_use_surrogates(true)
    assert(dtrees.get_use_surrogates?)
  end

  def test_dtrees_get_set_use1_se_rule
    dtrees = Cv::Ml::DTrees.create
    dtrees.set_use_1se_rule(true)
    assert(dtrees.get_use_1se_rule?)
  end

  def test_dtrees_get_set_truncate_pruned_tree
    dtrees = Cv::Ml::DTrees.create
    dtrees.set_truncate_pruned_tree(true)
    assert(dtrees.get_truncate_pruned_tree?)
  end

  def test_dtrees_get_set_regression_accuracy
    dtrees = Cv::Ml::DTrees.create
    dtrees.set_regression_accuracy(0.01)
    assert_in_delta(0.01, dtrees.get_regression_accuracy, 0.001)
  end

  def test_dtrees_train
    dtrees = Cv::Ml::DTrees.create
    dtrees.set_max_depth(5)

    # DTrees defaults to cv_folds=10 (unlike RTrees/Boost which default to 0).
    # Cross-validation with more folds than samples per class causes OpenCV to
    # crash with an empty sample index vector. Disable CV for small test datasets.
    dtrees.set_cv_folds(0)

    # DTrees uses integer responses for classification
    result = dtrees.train(@samples.input_array, Cv::Ml::SampleTypes::ROW_SAMPLE.to_i, @responses.input_array)
    assert(result)
  end

  def test_dtrees_node
    node = Cv::Ml::DTrees::Node.new
    assert_instance_of(Cv::Ml::DTrees::Node, node)

    node.value = 1.5
    node.class_idx = 0
    node.parent = -1
    node.left = 1
    node.right = 2

    assert_in_delta(1.5, node.value, 0.01)
    assert_equal(0, node.class_idx)
    assert_equal(-1, node.parent)
    assert_equal(1, node.left)
    assert_equal(2, node.right)
  end

  def test_dtrees_split
    split = Cv::Ml::DTrees::Split.new
    assert_instance_of(Cv::Ml::DTrees::Split, split)

    split.var_idx = 0
    split.quality = 0.95

    assert_equal(0, split.var_idx)
    assert_in_delta(0.95, split.quality, 0.01)
  end

  # ============ RTrees ============
  def test_rtrees_create
    rtrees = Cv::Ml::RTrees.create
    refute_nil(rtrees)
  end

  def test_rtrees_get_set_calculate_var_importance
    rtrees = Cv::Ml::RTrees.create
    rtrees.set_calculate_var_importance(true)
    assert(rtrees.get_calculate_var_importance?)
  end

  def test_rtrees_get_set_active_var_count
    rtrees = Cv::Ml::RTrees.create
    rtrees.set_active_var_count(1)
    assert_equal(1, rtrees.get_active_var_count)
  end

  def test_rtrees_get_set_term_criteria
    rtrees = Cv::Ml::RTrees.create
    tc = Cv::TermCriteria.new(Cv::TermCriteria::Type::COUNT.to_i, 50, 0.01)
    rtrees.set_term_criteria(tc)

    result = rtrees.get_term_criteria
    assert_equal(50, result.max_count)
  end

  def test_rtrees_train
    rtrees = Cv::Ml::RTrees.create
    rtrees.set_term_criteria(Cv::TermCriteria.new(Cv::TermCriteria::Type::COUNT.to_i, 10, 0.01))

    # RTrees uses integer responses for classification
    result = rtrees.train(@samples.input_array, Cv::Ml::SampleTypes::ROW_SAMPLE.to_i, @responses.input_array)
    assert(result)
  end

  def test_rtrees_get_var_importance
    rtrees = Cv::Ml::RTrees.create
    rtrees.set_calculate_var_importance(true)
    rtrees.set_term_criteria(Cv::TermCriteria.new(Cv::TermCriteria::Type::COUNT.to_i, 10, 0.01))

    # RTrees uses integer responses for classification
    rtrees.train(@samples.input_array, Cv::Ml::SampleTypes::ROW_SAMPLE.to_i, @responses.input_array)

    importance = rtrees.get_var_importance
    refute(importance.empty?)
  end

  # ============ Boost ============
  def test_boost_create
    boost = Cv::Ml::Boost.create
    refute_nil(boost)
  end

  def test_boost_get_set_boost_type
    boost = Cv::Ml::Boost.create
    boost.set_boost_type(Cv::Ml::Boost::Types::REAL.to_i)
    assert_equal(Cv::Ml::Boost::Types::REAL.to_i, boost.get_boost_type)
  end

  def test_boost_get_set_weak_count
    boost = Cv::Ml::Boost.create
    boost.set_weak_count(50)
    assert_equal(50, boost.get_weak_count)
  end

  def test_boost_get_set_weight_trim_rate
    boost = Cv::Ml::Boost.create
    boost.set_weight_trim_rate(0.9)
    assert_in_delta(0.9, boost.get_weight_trim_rate, 0.01)
  end

  # ============ ANN_MLP ============
  def test_ann_mlp_create
    ann = Cv::Ml::ANN_MLP.create
    refute_nil(ann)
  end

  def test_ann_mlp_set_layer_sizes
    ann = Cv::Ml::ANN_MLP.create
    layer_sizes = Cv::Mat.new(1, 3, CV_32SC1)
    layer_sizes[0, 0] = 2   # input layer
    layer_sizes[0, 1] = 4   # hidden layer
    layer_sizes[0, 2] = 2   # output layer

    ann.set_layer_sizes(layer_sizes.input_array)
    result = ann.get_layer_sizes

    # OpenCV returns layer_sizes as a column vector (3x1), not row vector (1x3)
    assert_equal(3, result.rows)
    assert_equal(1, result.cols)
    assert_equal(2, result[0, 0])
    assert_equal(4, result[1, 0])
    assert_equal(2, result[2, 0])
  end

  def test_ann_mlp_set_activation_function
    ann = Cv::Ml::ANN_MLP.create
    ann.set_activation_function(Cv::Ml::ANN_MLP::ActivationFunctions::SIGMOID_SYM.to_i, 1.0, 1.0)
    # Just verify it doesn't crash
    assert_instance_of(Cv::Ptr≺cv꞉꞉ml꞉꞉ANNMLP≻, ann)
  end

  def test_ann_mlp_set_train_method
    ann = Cv::Ml::ANN_MLP.create
    ann.set_train_method(Cv::Ml::ANN_MLP::TrainingMethods::RPROP.to_i)
    assert_equal(Cv::Ml::ANN_MLP::TrainingMethods::RPROP.to_i, ann.get_train_method)
  end

  def test_ann_mlp_get_set_term_criteria
    ann = Cv::Ml::ANN_MLP.create
    tc = Cv::TermCriteria.new(Cv::TermCriteria::Type::COUNT.to_i, 100, 0.01)
    ann.set_term_criteria(tc)

    result = ann.get_term_criteria
    assert_equal(100, result.max_count)
  end

  def test_ann_mlp_backprop_params
    ann = Cv::Ml::ANN_MLP.create
    ann.set_backprop_weight_scale(0.1)
    ann.set_backprop_momentum_scale(0.1)

    assert_in_delta(0.1, ann.get_backprop_weight_scale, 0.01)
    assert_in_delta(0.1, ann.get_backprop_momentum_scale, 0.01)
  end

  def test_ann_mlp_rprop_params
    ann = Cv::Ml::ANN_MLP.create
    ann.set_rprop_dw0(0.1)
    ann.set_rprop_dw_plus(1.2)
    ann.set_rprop_dw_minus(0.5)
    ann.set_rprop_dw_min(0.01)
    ann.set_rprop_dw_max(50.0)

    assert_in_delta(0.1, ann.get_rprop_dw0, 0.01)
    assert_in_delta(1.2, ann.get_rprop_dw_plus, 0.01)
    assert_in_delta(0.5, ann.get_rprop_dw_minus, 0.01)
    assert_in_delta(0.01, ann.get_rprop_dw_min, 0.001)
    assert_in_delta(50.0, ann.get_rprop_dw_max, 0.01)
  end

  # ============ LogisticRegression ============
  def test_logistic_regression_create
    lr = Cv::Ml::LogisticRegression.create
    refute_nil(lr)
  end

  def test_logistic_regression_get_set_learning_rate
    lr = Cv::Ml::LogisticRegression.create
    lr.set_learning_rate(0.01)
    assert_in_delta(0.01, lr.get_learning_rate, 0.001)
  end

  def test_logistic_regression_get_set_iterations
    lr = Cv::Ml::LogisticRegression.create
    lr.set_iterations(100)
    assert_equal(100, lr.get_iterations)
  end

  def test_logistic_regression_get_set_regularization
    lr = Cv::Ml::LogisticRegression.create
    lr.set_regularization(Cv::Ml::LogisticRegression::RegKinds::REG_L2.to_i)
    assert_equal(Cv::Ml::LogisticRegression::RegKinds::REG_L2.to_i, lr.get_regularization)
  end

  def test_logistic_regression_get_set_train_method
    lr = Cv::Ml::LogisticRegression.create
    lr.set_train_method(Cv::Ml::LogisticRegression::Methods::MINI_BATCH.to_i)
    assert_equal(Cv::Ml::LogisticRegression::Methods::MINI_BATCH.to_i, lr.get_train_method)
  end

  def test_logistic_regression_get_set_mini_batch_size
    lr = Cv::Ml::LogisticRegression.create
    lr.set_mini_batch_size(10)
    assert_equal(10, lr.get_mini_batch_size)
  end

  def test_logistic_regression_get_set_term_criteria
    lr = Cv::Ml::LogisticRegression.create
    tc = Cv::TermCriteria.new(Cv::TermCriteria::Type::COUNT.to_i, 50, 0.01)
    lr.set_term_criteria(tc)

    result = lr.get_term_criteria
    assert_equal(50, result.max_count)
  end

  # ============ SVMSGD ============
  def test_svmsgd_create
    svmsgd = Cv::Ml::SVMSGD.create
    refute_nil(svmsgd)
  end

  def test_svmsgd_get_set_svmsgd_type
    svmsgd = Cv::Ml::SVMSGD.create
    svmsgd.set_svmsgd_type(Cv::Ml::SVMSGD::SvmsgdType::ASGD.to_i)
    assert_equal(Cv::Ml::SVMSGD::SvmsgdType::ASGD.to_i, svmsgd.get_svmsgd_type)
  end

  def test_svmsgd_get_set_margin_type
    svmsgd = Cv::Ml::SVMSGD.create
    svmsgd.set_margin_type(Cv::Ml::SVMSGD::MarginType::HARD_MARGIN.to_i)
    assert_equal(Cv::Ml::SVMSGD::MarginType::HARD_MARGIN.to_i, svmsgd.get_margin_type)
  end

  def test_svmsgd_get_set_margin_regularization
    svmsgd = Cv::Ml::SVMSGD.create
    svmsgd.set_margin_regularization(0.0001)
    assert_in_delta(0.0001, svmsgd.get_margin_regularization, 0.00001)
  end

  def test_svmsgd_get_set_initial_step_size
    svmsgd = Cv::Ml::SVMSGD.create
    svmsgd.set_initial_step_size(0.05)
    assert_in_delta(0.05, svmsgd.get_initial_step_size, 0.001)
  end

  def test_svmsgd_get_set_step_decreasing_power
    svmsgd = Cv::Ml::SVMSGD.create
    svmsgd.set_step_decreasing_power(0.75)
    assert_in_delta(0.75, svmsgd.get_step_decreasing_power, 0.01)
  end

  def test_svmsgd_get_set_term_criteria
    svmsgd = Cv::Ml::SVMSGD.create
    tc = Cv::TermCriteria.new(Cv::TermCriteria::Type::COUNT.to_i, 100, 0.001)
    svmsgd.set_term_criteria(tc)

    result = svmsgd.get_term_criteria
    assert_equal(100, result.max_count)
  end

  def test_svmsgd_set_optimal_parameters
    svmsgd = Cv::Ml::SVMSGD.create
    svmsgd.set_optimal_parameters(Cv::Ml::SVMSGD::SvmsgdType::ASGD.to_i, Cv::Ml::SVMSGD::MarginType::SOFT_MARGIN.to_i)
    # Just verify it doesn't crash
    assert_instance_of(Cv::Ptr≺cv꞉꞉ml꞉꞉SVMSGD≻, svmsgd)
  end

  # ============ Module Functions ============
  def test_rand_mv_normal
    # Note: rand_mv_normal requires CV_32FC1 type
    mean = Cv::Mat.new(1, 2, CV_32FC1)
    mean[0, 0] = 0.0
    mean[0, 1] = 0.0

    cov = Cv::Mat.eye(2, 2, CV_32FC1).to_mat
    samples = Cv::Mat.new

    Cv::Ml.rand_mv_normal(mean.input_array, cov.input_array, 100, samples.output_array)

    assert_equal(100, samples.rows)
    assert_equal(2, samples.cols)
  end
end
