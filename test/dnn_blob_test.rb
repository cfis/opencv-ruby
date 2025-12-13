#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class DnnBlobTest < OpenCVTestCase
  def test_blob_from_image_basic
    image = Cv::Mat.new(224, 224, CV_8UC3, Cv::Scalar.new(128, 128, 128))
    blob = Cv::Dnn.blob_from_image(image.input_array)

    assert_kind_of(Cv::Mat, blob)
    assert_equal(4, blob.dims)
  end

  def test_blob_from_image_with_scale
    image = Cv::Mat.new(224, 224, CV_8UC3, Cv::Scalar.new(255, 255, 255))
    blob = Cv::Dnn.blob_from_image(image.input_array, 1.0 / 255.0)

    assert_kind_of(Cv::Mat, blob)
    assert_equal(CV_32F, blob.depth)
  end

  def test_blob_from_image_with_size
    image = Cv::Mat.new(480, 640, CV_8UC3, Cv::Scalar.new(100, 150, 200))
    target_size = Cv::Size.new(224, 224)
    blob = Cv::Dnn.blob_from_image(image.input_array, 1.0, target_size)

    assert_kind_of(Cv::Mat, blob)
    assert_equal(4, blob.dims)
  end

  def test_blob_from_image_with_mean
    image = Cv::Mat.new(224, 224, CV_8UC3, Cv::Scalar.new(128, 128, 128))
    mean = Cv::Scalar.new(104, 117, 123)
    blob = Cv::Dnn.blob_from_image(image.input_array, 1.0, Cv::Size.new, mean)

    assert_kind_of(Cv::Mat, blob)
  end

  def test_blob_from_image_swap_rb_false
    image = Cv::Mat.new(100, 100, CV_8UC3, Cv::Scalar.new(255, 0, 0))
    blob = Cv::Dnn.blob_from_image(image.input_array, 1.0, Cv::Size.new, Cv::Scalar.new, false)

    assert_kind_of(Cv::Mat, blob)
  end

  def test_blob_from_image_swap_rb_true
    image = Cv::Mat.new(100, 100, CV_8UC3, Cv::Scalar.new(255, 0, 0))
    blob = Cv::Dnn.blob_from_image(image.input_array, 1.0, Cv::Size.new, Cv::Scalar.new, true)

    assert_kind_of(Cv::Mat, blob)
  end

  def test_blob_from_image_crop_false
    image = Cv::Mat.new(300, 400, CV_8UC3, Cv::Scalar.new(128, 128, 128))
    target_size = Cv::Size.new(224, 224)
    blob = Cv::Dnn.blob_from_image(image.input_array, 1.0, target_size, Cv::Scalar.new, false, false)

    assert_kind_of(Cv::Mat, blob)
  end

  def test_blob_from_image_crop_true
    image = Cv::Mat.new(300, 400, CV_8UC3, Cv::Scalar.new(128, 128, 128))
    target_size = Cv::Size.new(224, 224)
    blob = Cv::Dnn.blob_from_image(image.input_array, 1.0, target_size, Cv::Scalar.new, false, true)

    assert_kind_of(Cv::Mat, blob)
  end

  def test_blob_from_image_ddepth_32f
    image = Cv::Mat.new(224, 224, CV_8UC3, Cv::Scalar.new(128, 128, 128))
    blob = Cv::Dnn.blob_from_image(image.input_array, 1.0, Cv::Size.new, Cv::Scalar.new, false, false, CV_32F)

    assert_equal(CV_32F, blob.depth)
  end

  def test_blob_from_image_ddepth_8u
    image = Cv::Mat.new(224, 224, CV_8UC3, Cv::Scalar.new(128, 128, 128))
    blob = Cv::Dnn.blob_from_image(image.input_array, 1.0, Cv::Size.new, Cv::Scalar.new, false, false, CV_8U)

    assert_equal(CV_8U, blob.depth)
  end

  def test_blob_from_image_grayscale
    image = Cv::Mat.new(224, 224, CV_8UC1, Cv::Scalar.new(128))
    blob = Cv::Dnn.blob_from_image(image.input_array)

    assert_kind_of(Cv::Mat, blob)
    assert_equal(4, blob.dims)
  end

  def test_blob_from_image_all_params
    image = Cv::Mat.new(300, 300, CV_8UC3, Cv::Scalar.new(128, 128, 128))
    blob = Cv::Dnn.blob_from_image(
      image.input_array,
      1.0 / 127.5,
      Cv::Size.new(224, 224),
      Cv::Scalar.new(127.5, 127.5, 127.5),
      true,
      false,
      CV_32F
    )

    assert_kind_of(Cv::Mat, blob)
    assert_equal(4, blob.dims)
    assert_equal(CV_32F, blob.depth)
  end

  def test_blob_from_images_basic
    images = Std::Vector≺cv꞉꞉Mat≻.new
    3.times do
      images << Cv::Mat.new(224, 224, CV_8UC3, Cv::Scalar.new(128, 128, 128))
    end

    blob = Cv::Dnn.blob_from_images(Cv::InputArray.new(images))
    assert_kind_of(Cv::Mat, blob)
    assert_equal(4, blob.dims)
  end

  def test_blob_from_images_with_scale
    images = Std::Vector≺cv꞉꞉Mat≻.new
    2.times do
      images << Cv::Mat.new(224, 224, CV_8UC3, Cv::Scalar.new(255, 255, 255))
    end

    blob = Cv::Dnn.blob_from_images(Cv::InputArray.new(images), 1.0 / 255.0)
    assert_kind_of(Cv::Mat, blob)
    assert_equal(CV_32F, blob.depth)
  end

  def test_blob_from_images_with_size
    images = Std::Vector≺cv꞉꞉Mat≻.new
    images << Cv::Mat.new(480, 640, CV_8UC3, Cv::Scalar.new(100, 100, 100))
    images << Cv::Mat.new(240, 320, CV_8UC3, Cv::Scalar.new(200, 200, 200))

    target_size = Cv::Size.new(224, 224)
    blob = Cv::Dnn.blob_from_images(Cv::InputArray.new(images), 1.0, target_size)

    assert_kind_of(Cv::Mat, blob)
  end

  def test_images_from_blob
    image = Cv::Mat.new(224, 224, CV_8UC3, Cv::Scalar.new(128, 64, 32))
    blob = Cv::Dnn.blob_from_image(image.input_array)

    images = Std::Vector≺cv꞉꞉Mat≻.new
    Cv::Dnn.images_from_blob(blob, Cv::OutputArray.new(images))

    assert_equal(1, images.size)
    assert_equal(224, images[0].rows)
    assert_equal(224, images[0].cols)
  end

  def test_images_from_blob_multiple
    input_images = Std::Vector≺cv꞉꞉Mat≻.new
    4.times do |i|
      input_images << Cv::Mat.new(100, 100, CV_8UC3, Cv::Scalar.new(i * 50, i * 50, i * 50))
    end

    blob = Cv::Dnn.blob_from_images(Cv::InputArray.new(input_images))

    output_images = Std::Vector≺cv꞉꞉Mat≻.new
    Cv::Dnn.images_from_blob(blob, Cv::OutputArray.new(output_images))

    assert_equal(4, output_images.size)
  end

  def test_blob_from_image_real_image
    image_path = sample_path("lena-256x256.jpg")
    return skip("Sample image not found") unless File.exist?(image_path)

    image = Cv::imread(image_path)
    blob = Cv::Dnn.blob_from_image(
      image.input_array,
      1.0 / 255.0,
      Cv::Size.new(224, 224),
      Cv::Scalar.new(0.485, 0.456, 0.406),
      true
    )

    assert_kind_of(Cv::Mat, blob)
    assert_equal(4, blob.dims)
    assert_equal(CV_32F, blob.depth)
  end
end
