#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class ImageCodesTest < OpenCVTestCase
  def test_read
    image_path = self.sample_path("starry_night.jpg")
    image = Cv::imread(image_path, Cv::ImreadModes::IMREAD_COLOR)

    refute(image.empty?)
    assert_equal(2, image.size.dims)

    assert_equal(752, image.cols)
    assert_equal(600, image.rows)
    assert_equal(Cv::Mat, image.class)
    assert_equal(CV_8U, image.depth)
    assert_equal(3, image.channels)
  end

  def test_write
    image_path = self.sample_path("starry_night.jpg")
    image = Cv::imread(image_path, Cv::ImreadModes::IMREAD_GRAYSCALE)

    data = Cv::InputArray.new(image)
    output_image_path = self.sample_path("starry_night_grayscale.jpg")
    image = Cv::imwrite(output_image_path, data, [])
  end

  def test_pixels
    image_path = self.sample_path("starry_night.jpg")
    image = Cv::imread(image_path, Cv::ImreadModes::IMREAD_COLOR)

    refute(image.empty?)
    assert_equal(2, image.size.dims)

    assert_equal(752, image.cols)
    assert_equal(600, image.rows)
  end

  def test_encode
    image_path = self.sample_path("cat.jpg")
    image = Cv::imread(image_path, Cv::ImreadModes::IMREAD_COLOR)

    buffer = Std::Vector≺unsigned char≻.new
    result = Cv::imencode('.jpg', image.input_array, buffer)
    assert(result)
    assert_equal('JFIF', buffer[6, 4].pack("c*"))

    options = [Cv::ImwriteFlags::IMWRITE_JPEG_QUALITY, 10]
    buffer = Std::Vector≺unsigned char≻.new
    result = Cv::imencode('.jpg', image.input_array, buffer, options)
    assert(result)
    assert_equal('JFIF', buffer[6, 4].pack("c*"))

    options = [Cv::ImwriteFlags::IMWRITE_PNG_COMPRESSION, 9]
    buffer = Std::Vector≺unsigned char≻.new
    result = Cv::imencode('.png', image.input_array, buffer, options)
    assert(result)
    assert_equal('PNG', buffer[1, 3].pack("c*"))
  end

  def test_decode
    image_path = self.sample_path("cat.jpg")
    data = File.binread(image_path)
    mat = Cv::Mat1b.new(1, data.size, data)
    image1 = Cv::imdecode(mat.input_array, Cv::ImreadModes::IMREAD_COLOR)
    image2 = Cv::imread(image_path, Cv::ImreadModes::IMREAD_COLOR)

    assert_equal(image1.type, image2.type)
    assert_equal(image1.size, image2.size)
    assert_equal(image1.rows, image2.rows)
    assert_equal(image1.cols, image2.cols)
    assert_equal(image1.channels, image2.channels)
  end

  def test_convert_to
    image_path = self.sample_path("starry_night.jpg")
    image = Cv::imread(image_path, Cv::ImreadModes::IMREAD_COLOR)

    # Make brighter
    brighter = image.convert_to(-1, 1, 50)
    refute(brighter.empty?)

    # Increase contrast
    contrast = image.convert_to(-1, 2, 0)
    refute(contrast.empty?)
  end
end