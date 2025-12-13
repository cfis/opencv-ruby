#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class DnnModelTest < OpenCVTestCase
  # Model base class tests
  def test_model_from_net
    net = Cv::Dnn::Net.new
    model = Cv::Dnn::Model.new(net)
    assert_kind_of(Cv::Dnn::Model, model)
  end

  def test_model_set_input_size
    net = Cv::Dnn::Net.new
    model = Cv::Dnn::Model.new(net)

    result = model.set_input_size(Cv::Size.new(224, 224))
    assert_kind_of(Cv::Dnn::Model, result)
  end

  def test_model_set_input_size_wh
    net = Cv::Dnn::Net.new
    model = Cv::Dnn::Model.new(net)

    result = model.set_input_size(224, 224)
    assert_kind_of(Cv::Dnn::Model, result)
  end

  def test_model_set_input_mean
    net = Cv::Dnn::Net.new
    model = Cv::Dnn::Model.new(net)

    result = model.set_input_mean(Cv::Scalar.new(104, 117, 123))
    assert_kind_of(Cv::Dnn::Model, result)
  end

  def test_model_set_input_scale
    net = Cv::Dnn::Net.new
    model = Cv::Dnn::Model.new(net)

    result = model.set_input_scale(Cv::Scalar.new(1.0 / 255.0))
    assert_kind_of(Cv::Dnn::Model, result)
  end

  def test_model_set_input_swap_rb
    net = Cv::Dnn::Net.new
    model = Cv::Dnn::Model.new(net)

    result = model.set_input_swap_rb(true)
    assert_kind_of(Cv::Dnn::Model, result)
  end

  def test_model_set_input_crop
    net = Cv::Dnn::Net.new
    model = Cv::Dnn::Model.new(net)

    result = model.set_input_crop(false)
    assert_kind_of(Cv::Dnn::Model, result)
  end

  def test_model_set_preferable_backend
    net = Cv::Dnn::Net.new
    model = Cv::Dnn::Model.new(net)

    result = model.set_preferable_backend(Cv::Dnn::Backend::DNN_BACKEND_OPENCV)
    assert_kind_of(Cv::Dnn::Model, result)
  end

  def test_model_set_preferable_target
    net = Cv::Dnn::Net.new
    model = Cv::Dnn::Model.new(net)

    result = model.set_preferable_target(Cv::Dnn::Target::DNN_TARGET_CPU)
    assert_kind_of(Cv::Dnn::Model, result)
  end

  def test_model_enable_winograd
    net = Cv::Dnn::Net.new
    model = Cv::Dnn::Model.new(net)

    result = model.enable_winograd(true)
    assert_kind_of(Cv::Dnn::Model, result)
  end

  def test_model_chained_configuration
    net = Cv::Dnn::Net.new
    model = Cv::Dnn::Model.new(net)

    # Test method chaining
    result = model
      .set_input_size(224, 224)
      .set_input_mean(Cv::Scalar.new(104, 117, 123))
      .set_input_scale(Cv::Scalar.new(1.0))
      .set_input_swap_rb(true)
      .set_input_crop(false)
      .set_preferable_backend(Cv::Dnn::Backend::DNN_BACKEND_OPENCV)
      .set_preferable_target(Cv::Dnn::Target::DNN_TARGET_CPU)

    assert_kind_of(Cv::Dnn::Model, result)
  end

  # ClassificationModel tests
  def test_classification_model_from_net
    net = Cv::Dnn::Net.new
    model = Cv::Dnn::ClassificationModel.new(net)
    assert_kind_of(Cv::Dnn::ClassificationModel, model)
  end

  def test_classification_model_enable_softmax
    net = Cv::Dnn::Net.new
    model = Cv::Dnn::ClassificationModel.new(net)

    result = model.set_enable_softmax_post_processing(true)
    assert_kind_of(Cv::Dnn::ClassificationModel, result)
  end

  def test_classification_model_disable_softmax
    net = Cv::Dnn::Net.new
    model = Cv::Dnn::ClassificationModel.new(net)

    result = model.set_enable_softmax_post_processing(false)
    assert_kind_of(Cv::Dnn::ClassificationModel, result)
  end

  # DetectionModel tests
  def test_detection_model_from_net
    net = Cv::Dnn::Net.new
    model = Cv::Dnn::DetectionModel.new(net)
    assert_kind_of(Cv::Dnn::DetectionModel, model)
  end

  def test_detection_model_set_nms_across_classes
    net = Cv::Dnn::Net.new
    model = Cv::Dnn::DetectionModel.new(net)

    result = model.set_nms_across_classes(true)
    assert_kind_of(Cv::Dnn::DetectionModel, result)
  end

  # SegmentationModel tests
  def test_segmentation_model_from_net
    net = Cv::Dnn::Net.new
    model = Cv::Dnn::SegmentationModel.new(net)
    assert_kind_of(Cv::Dnn::SegmentationModel, model)
  end

  # KeypointsModel tests
  def test_keypoints_model_from_net
    net = Cv::Dnn::Net.new
    model = Cv::Dnn::KeypointsModel.new(net)
    assert_kind_of(Cv::Dnn::KeypointsModel, model)
  end

  # Image2BlobParams tests
  def test_image2blob_params_new
    params = Cv::Dnn::Image2BlobParams.new
    assert_kind_of(Cv::Dnn::Image2BlobParams, params)
  end

  def test_image2blob_params_scalefactor
    params = Cv::Dnn::Image2BlobParams.new
    params.scalefactor = Cv::Scalar.new(1.0 / 255.0)
    assert_kind_of(Cv::Scalar, params.scalefactor)
  end

  def test_image2blob_params_size
    params = Cv::Dnn::Image2BlobParams.new
    params.size = Cv::Size.new(224, 224)
    assert_equal(224, params.size.width)
    assert_equal(224, params.size.height)
  end

  def test_image2blob_params_mean
    params = Cv::Dnn::Image2BlobParams.new
    params.mean = Cv::Scalar.new(104, 117, 123)
    assert_kind_of(Cv::Scalar, params.mean)
  end

  def test_image2blob_params_swap_rb_true
    params = Cv::Dnn::Image2BlobParams.new
    params.swap_rb = true
    assert(params.swap_rb)
  end

  def test_image2blob_params_swap_rb_false
    params = Cv::Dnn::Image2BlobParams.new
    params.swap_rb = false
    refute(params.swap_rb)
  end

  def test_image2blob_params_ddepth
    params = Cv::Dnn::Image2BlobParams.new
    params.ddepth = CV_32F
    assert_equal(CV_32F, params.ddepth)
  end

  def test_image2blob_params_datalayout
    params = Cv::Dnn::Image2BlobParams.new
    params.datalayout = Cv::Dnn::DataLayout::DNN_LAYOUT_NCHW
    assert_equal(Cv::Dnn::DataLayout::DNN_LAYOUT_NCHW, params.datalayout)
  end

  def test_image2blob_params_paddingmode
    params = Cv::Dnn::Image2BlobParams.new
    params.paddingmode = Cv::Dnn::ImagePaddingMode::DNN_PMODE_LETTERBOX
    assert_equal(Cv::Dnn::ImagePaddingMode::DNN_PMODE_LETTERBOX, params.paddingmode)
  end

  def test_blob_from_image_with_params
    image = Cv::Mat.new(300, 400, CV_8UC3, Cv::Scalar.new(128, 128, 128))

    params = Cv::Dnn::Image2BlobParams.new
    params.scalefactor = Cv::Scalar.new(1.0 / 255.0)
    params.size = Cv::Size.new(224, 224)
    params.mean = Cv::Scalar.new(0, 0, 0)
    params.swap_rb = true
    params.ddepth = CV_32F
    params.datalayout = Cv::Dnn::DataLayout::DNN_LAYOUT_NCHW
    params.paddingmode = Cv::Dnn::ImagePaddingMode::DNN_PMODE_NULL

    blob = Cv::Dnn.blob_from_image_with_params(image.input_array, params)
    assert_kind_of(Cv::Mat, blob)
    assert_equal(4, blob.dims)
  end

  def test_blob_from_images_with_params
    images = Std::Vector≺cv꞉꞉Mat≻.new
    2.times do
      images << Cv::Mat.new(300, 400, CV_8UC3, Cv::Scalar.new(128, 128, 128))
    end

    params = Cv::Dnn::Image2BlobParams.new
    params.scalefactor = Cv::Scalar.new(1.0 / 255.0)
    params.size = Cv::Size.new(224, 224)
    params.ddepth = CV_32F

    blob = Cv::Dnn.blob_from_images_with_params(Cv::InputArray.new(images), params)
    assert_kind_of(Cv::Mat, blob)
    assert_equal(4, blob.dims)
  end

  # DataLayout enum tests
  def test_data_layout_enum_unknown
    assert_kind_of(Cv::Dnn::DataLayout, Cv::Dnn::DataLayout::DNN_LAYOUT_UNKNOWN)
  end

  def test_data_layout_enum_nd
    assert_kind_of(Cv::Dnn::DataLayout, Cv::Dnn::DataLayout::DNN_LAYOUT_ND)
  end

  def test_data_layout_enum_nchw
    assert_kind_of(Cv::Dnn::DataLayout, Cv::Dnn::DataLayout::DNN_LAYOUT_NCHW)
  end

  def test_data_layout_enum_nhwc
    assert_kind_of(Cv::Dnn::DataLayout, Cv::Dnn::DataLayout::DNN_LAYOUT_NHWC)
  end

  # ImagePaddingMode enum tests
  def test_image_padding_mode_null
    assert_kind_of(Cv::Dnn::ImagePaddingMode, Cv::Dnn::ImagePaddingMode::DNN_PMODE_NULL)
  end

  def test_image_padding_mode_crop_center
    assert_kind_of(Cv::Dnn::ImagePaddingMode, Cv::Dnn::ImagePaddingMode::DNN_PMODE_CROP_CENTER)
  end

  def test_image_padding_mode_letterbox
    assert_kind_of(Cv::Dnn::ImagePaddingMode, Cv::Dnn::ImagePaddingMode::DNN_PMODE_LETTERBOX)
  end
end
