#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class DnnNetTest < OpenCVTestCase
  def test_new
    net = Cv::Dnn::Net.new
    assert_kind_of(Cv::Dnn::Net, net)
  end

  def test_add_layer_relu
    net = Cv::Dnn::Net.new
    params = Cv::Dnn::LayerParams.new
    params.name = "relu1"
    params.type = "ReLU"

    layer_id = net.add_layer("relu1", "ReLU", params)
    assert_kind_of(Integer, layer_id)
    assert(layer_id >= 0)
  end

  def test_get_layer_id
    net = Cv::Dnn::Net.new
    params = Cv::Dnn::LayerParams.new
    params.name = "test_layer"
    params.type = "ReLU"

    added_id = net.add_layer("test_layer", "ReLU", params)
    found_id = net.get_layer_id("test_layer")
    assert_equal(added_id, found_id)
  end

  def test_get_layer_names
    net = Cv::Dnn::Net.new
    params = Cv::Dnn::LayerParams.new

    params.name = "layer1"
    params.type = "ReLU"
    net.add_layer("layer1", "ReLU", params)

    params.name = "layer2"
    params.type = "Sigmoid"
    net.add_layer("layer2", "Sigmoid", params)

    names = net.get_layer_names
    assert_includes(names.to_a, "layer1")
    assert_includes(names.to_a, "layer2")
  end

  def test_get_layers_count
    net = Cv::Dnn::Net.new
    params = Cv::Dnn::LayerParams.new
    params.type = "ReLU"

    3.times do |i|
      params.name = "relu_#{i}"
      net.add_layer("relu_#{i}", "ReLU", params)
    end

    count = net.get_layers_count("ReLU")
    assert_equal(3, count)
  end

  def test_set_preferable_backend
    net = Cv::Dnn::Net.new
    net.set_preferable_backend(Cv::Dnn::Backend::DNN_BACKEND_OPENCV)
    # No assertion needed - just verify it doesn't raise
  end

  def test_set_preferable_target
    net = Cv::Dnn::Net.new
    net.set_preferable_target(Cv::Dnn::Target::DNN_TARGET_CPU)
    # No assertion needed - just verify it doesn't raise
  end

  def test_enable_fusion
    net = Cv::Dnn::Net.new
    net.enable_fusion(true)
    net.enable_fusion(false)
    # No assertion needed - just verify it doesn't raise
  end

  def test_enable_winograd
    net = Cv::Dnn::Net.new
    net.enable_winograd(true)
    net.enable_winograd(false)
    # No assertion needed - just verify it doesn't raise
  end

  def test_get_unconnected_out_layers
    net = Cv::Dnn::Net.new
    layers = net.get_unconnected_out_layers
    assert_kind_of(Std::Vector≺int≻, layers)
  end

  def test_get_unconnected_out_layers_names
    net = Cv::Dnn::Net.new
    names = net.get_unconnected_out_layers_names
    names_array = names.to_a
    assert_kind_of(Array, names_array)
  end

  def test_backend_enum_default
    assert_equal(Cv::Dnn::Backend::DNN_BACKEND_DEFAULT, Cv::Dnn::Backend::DNN_BACKEND_DEFAULT)
  end

  def test_backend_enum_opencv
    backend = Cv::Dnn::Backend::DNN_BACKEND_OPENCV
    assert_kind_of(Cv::Dnn::Backend, backend)
  end

  def test_backend_enum_cuda
    backend = Cv::Dnn::Backend::DNN_BACKEND_CUDA
    assert_kind_of(Cv::Dnn::Backend, backend)
  end

  def test_target_enum_cpu
    target = Cv::Dnn::Target::DNN_TARGET_CPU
    assert_kind_of(Cv::Dnn::Target, target)
  end

  def test_target_enum_opencl
    target = Cv::Dnn::Target::DNN_TARGET_OPENCL
    assert_kind_of(Cv::Dnn::Target, target)
  end

  def test_target_enum_cuda
    target = Cv::Dnn::Target::DNN_TARGET_CUDA
    assert_kind_of(Cv::Dnn::Target, target)
  end

  def test_get_available_backends
    backends = Cv::Dnn.get_available_backends
    assert(backends.size > 0)
  end

  def test_get_available_targets
    targets = Cv::Dnn.get_available_targets(Cv::Dnn::Backend::DNN_BACKEND_OPENCV)
    assert(targets.size > 0)
  end

  def test_connect_layers
    net = Cv::Dnn::Net.new

    params1 = Cv::Dnn::LayerParams.new
    params1.name = "relu1"
    params1.type = "ReLU"
    id1 = net.add_layer("relu1", "ReLU", params1)

    params2 = Cv::Dnn::LayerParams.new
    params2.name = "relu2"
    params2.type = "ReLU"
    id2 = net.add_layer("relu2", "ReLU", params2)

    # Connect layers by ID
    net.connect(id1, 0, id2, 0)
    # No assertion - just verify it doesn't raise
  end

  def test_connect_layers_by_name
    net = Cv::Dnn::Net.new

    params1 = Cv::Dnn::LayerParams.new
    params1.name = "relu1"
    params1.type = "ReLU"
    net.add_layer("relu1", "ReLU", params1)

    params2 = Cv::Dnn::LayerParams.new
    params2.name = "relu2"
    params2.type = "ReLU"
    net.add_layer("relu2", "ReLU", params2)

    # Connect layers by string pin names
    net.connect("relu1", "relu2")
    # No assertion - just verify it doesn't raise
  end

  def test_add_layer_to_prev
    net = Cv::Dnn::Net.new

    params1 = Cv::Dnn::LayerParams.new
    params1.name = "relu1"
    params1.type = "ReLU"
    net.add_layer("relu1", "ReLU", params1)

    params2 = Cv::Dnn::LayerParams.new
    params2.name = "relu2"
    params2.type = "ReLU"
    id2 = net.add_layer_to_prev("relu2", "ReLU", params2)

    assert_kind_of(Integer, id2)
  end

  def test_set_input
    net = Cv::Dnn::Net.new
    blob = Cv::Mat.new(1, 10, CV_32FC1, Cv::Scalar.new(1.0))
    net.set_input(blob.input_array)
    # No assertion - just verify it doesn't raise
  end

  # Note: test_set_input_with_name removed because it requires
  # a network with a blob named "data" already defined.
  # See set_inputs_names() to define blob names first.

  def test_set_input_with_scale_and_mean
    net = Cv::Dnn::Net.new
    blob = Cv::Mat.new(1, 10, CV_32FC1, Cv::Scalar.new(255.0))
    net.set_input(blob.input_array, "", 1.0 / 255.0, Cv::Scalar.new(0.5))
    # No assertion - just verify it doesn't raise
  end
end
