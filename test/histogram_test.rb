#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class HistogramTest < OpenCVTestCase
  def create_histogram(image, channels, hist_sizes, hist_ranges)
    mask = Cv::no_array
    histogram = Cv::Mat.new
    images = Cv::OutputArray.new([image])
    Cv::calc_hist(images, channels, mask, histogram.output_array, hist_sizes, hist_ranges)
    histogram
  end

  def create_sparse_histogram(channels, hist_sizes, hist_ranges, mask=Cv::no_array)
    image_path = self.sample_path("sky.jpg")
    image = Cv::imread(image_path, Cv::ImreadModes::IMREAD_COLOR)

    channels_buffer = Rice::Buffer≺int≻.new(channels)
    hist_sizes_buffer = Rice::Buffer≺int≻.new(hist_sizes)
    hist_ranges_buffer = Rice::Buffer≺float∗≻.new(hist_ranges)

    histogram = Cv::SparseMat1f.new
    Cv::calc_hist(image, 1, channels_buffer.data, mask,
                  histogram,
                  hist_ranges_buffer.size, hist_sizes_buffer.data, hist_ranges_buffer.data)
    histogram
  end

  def test_calc_histogram
    hist_sizes = [8]
    hist_ranges = [0, 255] # The upper boundary is exclusive
    image = Cv::imread(self.sample_path("starry_night.jpg"), Cv::ImreadModes::IMREAD_COLOR)
    histograms = 3.times.map do |i|
      create_histogram(image, [i], hist_sizes, hist_ranges)
    end

    histogram = histograms[0]
    assert_equal([32578.0, 60741.0, 65602.0, 81889.0, 119619.0, 65918.0, 20806.0, 4047.0],
                 histogram.to_a)

    histogram = histograms[1]
    assert_equal([48658.0, 96129.0, 107347.0, 80564.0, 47791.0, 34150.0, 25558.0, 11003.0],
                 histogram.to_a)

    histogram = histograms[2]
    assert_equal([124693.0, 123976.0, 85588.0, 45821.0, 29036.0, 19945.0, 16249.0, 5892.0],
                 histogram.to_a)
  end

  def test_normalize_histogram
    channels = [0]
    hist_sizes = [8]
    hist_ranges = [0, 255] # The upper boundary is exclusive
    image = Cv::imread(self.sample_path("starry_night.jpg"), Cv::ImreadModes::IMREAD_COLOR)
    histogram = create_histogram(image, channels, hist_sizes, hist_ranges)

    assert_equal([32578.0, 60741.0, 65602.0, 81889.0, 119619.0, 65918.0, 20806.0, 4047.0],
                 histogram.to_a)

    expected = [0.07220301777124405, 0.1346210241317749, 0.14539450407028198, 0.18149158358573914, 0.26511305570602417, 0.14609485864639282, 0.04611258953809738, 0.008969414979219437]

    normalized = histogram / histogram.sum[0]
    assert_in_delta_array(expected, normalized.to_mat.to_a, 0.01)

    normalized = histogram.normalize(alpha: 1, beta: 0, norm_type: Cv::NormTypes::NORM_L1)
    assert_in_delta_array(expected, normalized.to_a, 0.01)
  end

  def test_threshold_histogram
    channels = [0]
    hist_sizes = [8]
    hist_ranges = [0, 255] # The upper boundary is exclusive
    image = Cv::imread(self.sample_path("starry_night.jpg"), Cv::ImreadModes::IMREAD_COLOR)
    histogram = create_histogram(image, channels, hist_sizes, hist_ranges)

    expected = [0.0, 60741.0, 65602.0, 81889.0, 119619.0, 65918.0, 0.0, 0.0]
    filtered, threshold = histogram.threshold(35_000, 0, Cv::ThresholdTypes::THRESH_TOZERO)
    assert_equal(35_000, threshold)
    assert_in_delta_array(expected, filtered.to_a, 0.01)
  end

  def test_compare_histograms
    hist_sizes = [8]
    hist_ranges = [0, 255] # The upper boundary is exclusive

    image = Cv::imread(self.sample_path("starry_night.jpg"), Cv::ImreadModes::IMREAD_COLOR)
    histograms = 2.times.map do |i|
      create_histogram(image, [i], hist_sizes, hist_ranges)
    end

    distance = Cv::compare_hist(histograms[0].input_array, histograms[1].input_array,
                                Cv::HistCompMethods::HISTCMP_CORREL)
    assert_in_delta(0.4677952811687655, distance)
  end

  def test_draw_histogram
    channels = [0, 1]
    hist_sizes = [32, 32]
    hist_ranges = [0, 255, 0, 255]
    image = Cv::imread(self.sample_path("starry_night.jpg"), Cv::ImreadModes::IMREAD_COLOR)
    histogram = create_histogram(image, channels, hist_sizes, hist_ranges)
    histogram.normalize(alpha: 0, beta: 255, norm_type: Cv::NormTypes::NORM_MINMAX)

    scale = 20
    image = Cv::Mat.new(hist_sizes[0] * scale, hist_sizes[1] * scale, CV_8UC3)

    hist_sizes[0].times do |i|
      hist_sizes[1].times do |j|
        value = histogram[i, j]
        scalar = Cv::Scalar.all(value)
        rect = Cv::Rect.new(i * scale, j * scale, scale, scale)
        image.rectangle(rect: rect, color: scalar, thickness: -1)
      end
    end
  end

  def test_calc_histogram_sparse
    channels = [0]
    hist_sizes = [8]
    hist_ranges = [[0, 255]]
    histogram = create_sparse_histogram(channels, hist_sizes, hist_ranges)
    assert_equal(CV_32FC1, histogram.type)
    expected = [133266.0, 114832.0, 13168.0, 878.0]
    assert_equal(expected, histogram.each.to_a)
  end

  def test_sparse_min_max_loc
    channels = [0]
    hist_sizes = [8]
    hist_ranges = [[0, 255]]
    histogram = create_sparse_histogram(channels, hist_sizes, hist_ranges)

    min_val, max_val, min_idx, max_idx = histogram.min_max_loc
    assert_equal(878.0, min_val)
    assert_equal(133266.0, max_val)
    assert_equal(7, min_idx)
    assert_equal(4, max_idx)
  end

  def test_compare_sparse_histograms
    hist_sizes = [8]
    hist_ranges = [[0, 255]]

    histograms = 2.times.map do |i|
      create_sparse_histogram([i], hist_sizes, hist_ranges)
    end

    distance = Cv::compare_hist(histograms[0], histograms[1],
                                Cv::HistCompMethods::HISTCMP_CORREL)
    assert_in_delta(0.10425867585561967, distance)
  end

  def test_emd
    histograms = []
    channels = [0, 1]
    hbins = 32
    sbins = 32
    hist_sizes = [hbins, sbins]
    hist_ranges = [0, 255, 0, 255] # The upper boundary is exclusive

    image = Cv::imread(self.sample_path("starry_night.jpg"), Cv::ImreadModes::IMREAD_COLOR)
    hsv_image = image.cvt_color(Cv::ColorConversionCodes::COLOR_BGR2HSV)
    histograms << create_histogram(hsv_image, channels, hist_sizes, hist_ranges)

    image = Cv::imread(self.sample_path("cafe_terrace_night.jpg"), Cv::ImreadModes::IMREAD_COLOR)
    hsv_image = image.cvt_color(Cv::ColorConversionCodes::COLOR_BGR2HSV)
    histograms << create_histogram(hsv_image, channels, hist_sizes, hist_ranges)

    normalized = histograms.map do |histogram|
      histogram.normalize
    end

    signatures = normalized.map do |histogram|
      numrows = hist_sizes[0] * hist_sizes[1]
      signature = Cv::Mat1f.new(numrows, 3)

      hbins.times do |h|
        sbins.times do |s|
          binval = histogram[h, s]
          signature[h * sbins + s, 0] = binval
          signature[h * sbins + s, 1] = h
          signature[h * sbins + s, 2] = s
        end
      end
      signature
    end

    cost = Cv.no_array
    lower_bound = Rice::Buffer≺float≻.new(0.0)
    flow = Cv.no_array
    result, lower_bound = Cv.emd(signatures[0].input_array, signatures[1].input_array,
                                 Cv::DistanceTypes::DIST_L1,
                                 cost, lower_bound.data, flow)

    assert_in_delta(3.5648324489593506, result)
    assert_equal(0, lower_bound)

    buffer = Rice::Buffer≺float≻.new(0)
    lower_bound_ptr = Cv::PtrFloat.new(buffer.release)
    result = Cv.wrapper_emd(signatures[0].input_array, signatures[1].input_array,
                            Cv::DistanceTypes::DIST_L1,
                            cost, lower_bound_ptr, flow)

    lower_bound = lower_bound_ptr.dereference
    assert_in_delta(3.5648324489593506, result)
    assert_equal(0, lower_bound)
  end

  def test_calc_back_project
    channels = [0, 1]
    hbins = 32
    sbins = 32
    hist_sizes = [hbins, sbins]
    hist_ranges = [0, 255, 0, 255] # The upper boundary is exclusive

    image = Cv::imread(self.sample_path("starry_night.jpg"), Cv::ImreadModes::IMREAD_COLOR)
    hsv_image = image.cvt_color(Cv::ColorConversionCodes::COLOR_BGR2HSV)
    histogram = create_histogram(hsv_image, channels, hist_sizes, hist_ranges)

    #input = Cv::InputArray.new([hsv_image])
    result = Cv::Mat.new(hsv_image.rows, hsv_image.cols, hsv_image.type)
    Cv::calc_back_project(hsv_image.input_array, [0, 1], histogram.input_array, result.output_array, hist_ranges, 1.0)
    assert_equal('1ff8101fe8a07c88a14718a1d8237879', hash_img(result))
  end

  def test_compare_hist
    channels = [0]
    hist_sizes = [8]
    hist_ranges = [0, 255] # The upper boundary is exclusive

    histogram1, histogram2 = ["cat.jpg", "happy_fish.jpg"].map do |image_name|
      image = Cv::imread(self.sample_path(image_name), Cv::ImreadModes::IMREAD_COLOR)
      create_histogram(image, channels, hist_sizes, hist_ranges)
    end

    result = Cv::compare_hist(histogram1.input_array, histogram2.input_array, Cv::HistCompMethods::HISTCMP_CORREL)
    assert_in_delta(0.594180, result)

    result = Cv::compare_hist(histogram1.input_array, histogram2.input_array, Cv::HistCompMethods::HISTCMP_CHISQR)
    assert_in_delta(102046, result, 1)

    result = Cv::compare_hist(histogram1.input_array, histogram2.input_array, Cv::HistCompMethods::HISTCMP_INTERSECT)
    assert_in_delta(64918.0, result)

    result = Cv::compare_hist(histogram1.input_array, histogram2.input_array, Cv::HistCompMethods::HISTCMP_BHATTACHARYYA)
    assert_in_delta(0.2416, result)
  end

  def test_calc_prob_density
    img = IplImage.load(FILENAME_CAT, 0)
    dim, sizes = @hist1.dims
    ranges = [[0, 255]]
    hist = Cv::Histogram.new(dim, sizes, CV_HIST_ARRAY, ranges).calc_hist!([img])
    dst = Cv::Histogram.calc_prob_density(hist, @hist1)
    assert_equal(Cv::Histogram, dst.class)
    dim, sizes = dst.dims
    expected_dim, expected_sizes = @hist1.dims
    assert_equal(expected_dim, dim)
    expected_sizes.each_with_index { |x, i|
      assert_equal(x, sizes[i])
    }
    expected = [0.0, 1.437, 1.135, 1.092, 2.323, 3.712, 3.103, 0.0]
    expected.each_with_index { |x, i|
      assert_in_delta(x, dst[i], 0.001)
    }
    assert_raise(TypeError) {
      Cv::Histogram.calc_prob_density(DUMMY_OBJ, @hist1)
    }
    assert_raise(TypeError) {
      Cv::Histogram.calc_prob_density(hist, DUMMY_OBJ)
    }
  end
end