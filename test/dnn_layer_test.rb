#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class DnnLayerTest < OpenCVTestCase
  # LayerParams tests
  def test_layer_params_new
    params = Cv::Dnn::LayerParams.new
    assert_kind_of(Cv::Dnn::LayerParams, params)
  end

  def test_layer_params_name
    params = Cv::Dnn::LayerParams.new
    params.name = "conv1"
    assert_equal("conv1", params.name)
  end

  def test_layer_params_type
    params = Cv::Dnn::LayerParams.new
    params.type = "Convolution"
    assert_equal("Convolution", params.type)
  end

  def test_layer_params_blobs
    params = Cv::Dnn::LayerParams.new
    blobs = Std::Vector≺cv꞉꞉Mat≻.new
    blobs << Cv::Mat.new(3, 3, CV_32FC1, Cv::Scalar.new(1.0))
    params.blobs = blobs
    assert_equal(1, params.blobs.size)
  end

  def test_layer_params_blobs_multiple
    params = Cv::Dnn::LayerParams.new
    blobs = Std::Vector≺cv꞉꞉Mat≻.new
    blobs << Cv::Mat.new(3, 3, CV_32FC1, Cv::Scalar.new(1.0))
    blobs << Cv::Mat.new(1, 10, CV_32FC1, Cv::Scalar.new(0.5))
    params.blobs = blobs
    assert_equal(2, params.blobs.size)
  end

  def test_layer_params_set_all_fields
    params = Cv::Dnn::LayerParams.new
    params.name = "test_layer"
    params.type = "ReLU"

    blobs = Std::Vector≺cv꞉꞉Mat≻.new
    params.blobs = blobs

    assert_equal("test_layer", params.name)
    assert_equal("ReLU", params.type)
    assert_equal(0, params.blobs.size)
  end

  # LayerFactory tests
  def test_layer_factory_create_relu
    params = Cv::Dnn::LayerParams.new
    params.name = "my_relu"
    params.type = "ReLU"

    layer = Cv::Dnn::LayerFactory.create_layer_instance("ReLU", params)
    assert(layer)
  end

  def test_layer_factory_create_sigmoid
    params = Cv::Dnn::LayerParams.new
    params.name = "my_sigmoid"
    params.type = "Sigmoid"

    layer = Cv::Dnn::LayerFactory.create_layer_instance("Sigmoid", params)
    assert(layer)
  end

  def test_layer_factory_create_tanh
    params = Cv::Dnn::LayerParams.new
    params.name = "my_tanh"
    params.type = "TanH"

    layer = Cv::Dnn::LayerFactory.create_layer_instance("TanH", params)
    assert(layer)
  end

  def test_layer_factory_create_softmax
    params = Cv::Dnn::LayerParams.new
    params.name = "my_softmax"
    params.type = "Softmax"

    layer = Cv::Dnn::LayerFactory.create_layer_instance("Softmax", params)
    assert(layer)
  end

  # Multiple layers in network
  def test_add_multiple_layers
    net = Cv::Dnn::Net.new

    params1 = Cv::Dnn::LayerParams.new
    params1.name = "relu1"
    params1.type = "ReLU"
    id1 = net.add_layer("relu1", "ReLU", params1)

    params2 = Cv::Dnn::LayerParams.new
    params2.name = "relu2"
    params2.type = "ReLU"
    id2 = net.add_layer("relu2", "ReLU", params2)

    refute_equal(id1, id2)
    assert_equal(2, net.get_layers_count("ReLU"))
  end

  def test_add_different_layer_types
    net = Cv::Dnn::Net.new

    params1 = Cv::Dnn::LayerParams.new
    params1.name = "relu1"
    params1.type = "ReLU"
    net.add_layer("relu1", "ReLU", params1)

    params2 = Cv::Dnn::LayerParams.new
    params2.name = "sigmoid1"
    params2.type = "Sigmoid"
    net.add_layer("sigmoid1", "Sigmoid", params2)

    assert_equal(1, net.get_layers_count("ReLU"))
    assert_equal(1, net.get_layers_count("Sigmoid"))
  end

  def test_add_layer_with_blobs
    net = Cv::Dnn::Net.new

    params = Cv::Dnn::LayerParams.new
    params.name = "relu_with_blobs"
    params.type = "ReLU"

    blobs = Std::Vector≺cv꞉꞉Mat≻.new
    blobs << Cv::Mat.new(1, 10, CV_32FC1, Cv::Scalar.new(0.1))
    params.blobs = blobs

    layer_id = net.add_layer("relu_with_blobs", "ReLU", params)
    assert(layer_id >= 0)
  end

  def test_layer_factory_create_flatten
    params = Cv::Dnn::LayerParams.new
    params.name = "flatten1"
    params.type = "Flatten"

    layer = Cv::Dnn::LayerFactory.create_layer_instance("Flatten", params)
    assert(layer)
  end

  def test_layer_factory_create_elu
    params = Cv::Dnn::LayerParams.new
    params.name = "elu1"
    params.type = "ELU"

    layer = Cv::Dnn::LayerFactory.create_layer_instance("ELU", params)
    assert(layer)
  end

  def test_layer_factory_create_swish
    params = Cv::Dnn::LayerParams.new
    params.name = "swish1"
    params.type = "Swish"

    layer = Cv::Dnn::LayerFactory.create_layer_instance("Swish", params)
    assert(layer)
  end
end
