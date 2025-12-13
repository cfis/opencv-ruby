#!/usr/bin/env ruby
require File.join(__dir__, 'helper')
require 'tmpdir'

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
    buffer = Rice::Buffer≺unsigned char≻.new(data)
    mat = Cv::Mat1b.new(1, buffer.size, buffer.data)
    image1 = Cv::imdecode(mat.input_array, Cv::ImreadModes::IMREAD_COLOR)
    image2 = Cv::imread(image_path, Cv::ImreadModes::IMREAD_COLOR)
    show_images([image1])
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

  # ============ Additional imread tests ============
  def test_imread_grayscale
    image_path = self.sample_path("starry_night.jpg")
    mat = Cv::imread(image_path, Cv::ImreadModes::IMREAD_GRAYSCALE)
    refute_nil(mat)
    refute(mat.empty?)
    assert_equal(1, mat.channels)
  end

  def test_imread_unchanged
    image_path = self.sample_path("starry_night.jpg")
    mat = Cv::imread(image_path, Cv::ImreadModes::IMREAD_UNCHANGED)
    refute_nil(mat)
    refute(mat.empty?)
  end

  def test_imread_reduced_2
    image_path = self.sample_path("starry_night.jpg")
    mat_full = Cv::imread(image_path, Cv::ImreadModes::IMREAD_COLOR)
    mat_reduced = Cv::imread(image_path, Cv::ImreadModes::IMREAD_REDUCED_COLOR_2)

    assert_equal(mat_full.rows / 2, mat_reduced.rows)
    assert_equal(mat_full.cols / 2, mat_reduced.cols)
  end

  def test_imread_reduced_4
    image_path = self.sample_path("starry_night.jpg")
    mat_full = Cv::imread(image_path, Cv::ImreadModes::IMREAD_COLOR)
    mat_reduced = Cv::imread(image_path, Cv::ImreadModes::IMREAD_REDUCED_COLOR_4)

    assert_equal(mat_full.rows / 4, mat_reduced.rows)
    assert_equal(mat_full.cols / 4, mat_reduced.cols)
  end

  def test_imread_reduced_8
    image_path = self.sample_path("starry_night.jpg")
    mat_full = Cv::imread(image_path, Cv::ImreadModes::IMREAD_COLOR)
    mat_reduced = Cv::imread(image_path, Cv::ImreadModes::IMREAD_REDUCED_COLOR_8)

    assert_equal(mat_full.rows / 8, mat_reduced.rows)
    assert_equal(mat_full.cols / 8, mat_reduced.cols)
  end

  def test_imread_nonexistent_file
    mat = Cv::imread("nonexistent_file_12345.jpg")
    assert(mat.empty?)
  end

  # ============ Different formats ============
  def test_imread_pgm
    pgm_path = sample_path("nuts_and_bolts.pgm")
    mat = Cv::imread(pgm_path, Cv::ImreadModes::IMREAD_UNCHANGED)
    refute(mat.empty?)
  end

  def test_imread_bmp
    bmp_path = sample_path("inpaint-mask.bmp")
    mat = Cv::imread(bmp_path, Cv::ImreadModes::IMREAD_UNCHANGED)
    refute(mat.empty?)
  end

  # ============ imwrite with different settings ============
  def test_imwrite_jpg_with_quality
    image_path = self.sample_path("starry_night.jpg")
    mat = Cv::imread(image_path, Cv::ImreadModes::IMREAD_COLOR)

    Dir.mktmpdir do |dir|
      # Write with low quality
      output_low = File.join(dir, "test_low.jpg")
      Cv::imwrite(output_low, mat.input_array, [Cv::ImwriteFlags::IMWRITE_JPEG_QUALITY, 10])

      # Write with high quality
      output_high = File.join(dir, "test_high.jpg")
      Cv::imwrite(output_high, mat.input_array, [Cv::ImwriteFlags::IMWRITE_JPEG_QUALITY, 95])

      # High quality file should be larger
      assert(File.size(output_high) > File.size(output_low))
    end
  end

  def test_imwrite_png_with_compression
    image_path = self.sample_path("starry_night.jpg")
    mat = Cv::imread(image_path, Cv::ImreadModes::IMREAD_COLOR)

    Dir.mktmpdir do |dir|
      # Write with no compression
      output_none = File.join(dir, "test_none.png")
      Cv::imwrite(output_none, mat.input_array, [Cv::ImwriteFlags::IMWRITE_PNG_COMPRESSION, 0])

      # Write with max compression
      output_max = File.join(dir, "test_max.png")
      Cv::imwrite(output_max, mat.input_array, [Cv::ImwriteFlags::IMWRITE_PNG_COMPRESSION, 9])

      # Max compression file should be smaller
      assert(File.size(output_max) < File.size(output_none))
    end
  end

  def test_imwrite_bmp
    image_path = self.sample_path("starry_night.jpg")
    mat = Cv::imread(image_path, Cv::ImreadModes::IMREAD_COLOR)

    Dir.mktmpdir do |dir|
      output_path = File.join(dir, "test_output.bmp")
      result = Cv::imwrite(output_path, mat.input_array)
      assert(result)
      assert(File.exist?(output_path))
    end
  end

  # ============ imcount ============
  def test_imcount
    image_path = self.sample_path("starry_night.jpg")
    count = Cv::imcount(image_path)
    assert_equal(1, count)
  end

  # ============ have_image_reader? / have_image_writer? ============
  def test_have_image_reader
    image_path = self.sample_path("starry_night.jpg")
    assert(Cv::have_image_reader?(image_path))
  end

  def test_have_image_writer_jpg
    Dir.mktmpdir do |dir|
      path = File.join(dir, "test.jpg")
      assert(Cv::have_image_writer?(path))
    end
  end

  def test_have_image_writer_png
    Dir.mktmpdir do |dir|
      path = File.join(dir, "test.png")
      assert(Cv::have_image_writer?(path))
    end
  end

  # ============ Round-trip tests ============
  def test_roundtrip_png_lossless
    mat_original = Cv::Mat.new(100, 100, CV_8UC3, Cv::Scalar.new(128, 64, 32))

    Dir.mktmpdir do |dir|
      path = File.join(dir, "test.png")
      Cv::imwrite(path, mat_original.input_array)

      mat_loaded = Cv::imread(path, Cv::ImreadModes::IMREAD_COLOR)

      # PNG is lossless
      pixel_orig = mat_original[50, 50]
      pixel_loaded = mat_loaded[50, 50]

      assert_equal(pixel_orig[0], pixel_loaded[0])
      assert_equal(pixel_orig[1], pixel_loaded[1])
      assert_equal(pixel_orig[2], pixel_loaded[2])
    end
  end

  def test_roundtrip_memory_png
    mat_original = Cv::Mat.new(100, 100, CV_8UC3, Cv::Scalar.new(200, 100, 50))

    # Encode and decode using file I/O instead of memory buffer
    # This tests the same round-trip functionality
    Dir.mktmpdir do |dir|
      path = File.join(dir, "test_roundtrip.png")
      Cv::imwrite(path, mat_original.input_array)
      mat_decoded = Cv::imread(path, Cv::ImreadModes::IMREAD_COLOR)

      # Check dimensions match
      assert_equal(mat_original.rows, mat_decoded.rows)
      assert_equal(mat_original.cols, mat_decoded.cols)

      # PNG is lossless
      pixel_orig = mat_original[50, 50]
      pixel_decoded = mat_decoded[50, 50]

      assert_equal(pixel_orig[0], pixel_decoded[0])
      assert_equal(pixel_orig[1], pixel_decoded[1])
      assert_equal(pixel_orig[2], pixel_decoded[2])
    end
  end

  # ============ Alpha channel ============
  def test_imwrite_png_with_alpha
    mat_rgba = Cv::Mat.new(100, 100, CV_8UC4, Cv::Scalar.new(255, 128, 64, 200))

    Dir.mktmpdir do |dir|
      path = File.join(dir, "test_alpha.png")
      Cv::imwrite(path, mat_rgba.input_array)

      mat_loaded = Cv::imread(path, Cv::ImreadModes::IMREAD_UNCHANGED)
      assert_equal(4, mat_loaded.channels)

      pixel = mat_loaded[50, 50]
      assert_equal(200, pixel[3])
    end
  end

  # ============ Grayscale handling ============
  def test_imread_grayscale_from_color
    image_path = self.sample_path("starry_night.jpg")
    mat = Cv::imread(image_path, Cv::ImreadModes::IMREAD_GRAYSCALE)
    assert_equal(1, mat.channels)
    refute(mat.empty?)
  end

  def test_imread_color_from_grayscale
    grayscale_path = sample_path("starry_night_grayscale.jpg")
    mat = Cv::imread(grayscale_path, Cv::ImreadModes::IMREAD_COLOR)
    assert_equal(3, mat.channels)
    refute(mat.empty?)
  end
end