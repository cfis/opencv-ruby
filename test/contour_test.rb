#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class ContourTest < OpenCVTestCase
  BLACK = 0
  WHITE = 255

  def circle_contours
    mat = create_mat(128, 128, CV_8UC1) do |j, i|
      (j - 64) ** 2 + (i - 64) ** 2 <= (32 ** 2) ? WHITE : BLACK
    end
    contours, hierarchy = mat.find_contours(Cv::RetrievalModes::RETR_EXTERNAL, Cv::ContourApproximationModes::CHAIN_APPROX_NONE)
    [mat, contours, hierarchy]
  end

  def test_contours_circle
    mat, contours, hierarchy = circle_contours

    assert_equal(1, contours.size)
    assert_equal(180, contours.first.size)

    assert_equal(1, hierarchy.size)
    assert_equal([-1, -1, -1, -1], hierarchy.first.to_a)
  end

  def test_countour_area
    mat, contours, hierarchy = circle_contours
    area = Cv::contour_area(Cv::InputArray.new(contours.first))
    assert_in_delta(3118.0, area)
  end

  def test_approx_poly_dp
    mat, contours, hierarchy = circle_contours
    contour = contours.first
    puts contour.class
    approximate = Cv::Mat.new
    Cv.approx_poly_dp(Cv::InputArray.new(contour), approximate.output_array, 2, false)

    expected = "[64, 32;\n 47, 37;\n 34, 53;\n 33, 71;\n 40, 85;\n 53, 94;\n 71, 95;\n 85, 88;\n 94, 75;\n 96, 64;\n 91, 47;\n 81, 37;\n 65, 33]"
    assert_equal(expected, approximate.inspect)
  end

  def test_draw_contours
    mat, contours, hierarchy = circle_contours
    assert_equal(1, contours.size)
    assert_equal(180, contours.first.size)

    drawing = Cv::Mat::zeros(mat.rows, mat.cols, CV_8UC3).to_mat
    rng = Cv::RNG.new
    contours.each.with_index do |contour, i|
      color = Cv::Scalar.new(rng.uniform(0, 256), rng.uniform(0, 256), rng.uniform(0, 256))
      drawing.draw_contours(contours, i, color, thickness: 2, line_type: Cv::LineTypes::LINE_8,
                            hierarchy: hierarchy, max_level: 0)
    end

    Cv::named_window("Contours", Cv::WindowFlags::WINDOW_AUTOSIZE)
    Cv::imshow("Contours", drawing.input_array)
    Cv::wait_key(1000)
  end

  def test_bounding_rect
    mat, contours, hierarchy = circle_contours

    rect = Cv::bounding_rect(Cv::InputArray.new(contours.first))
    assert_equal(Cv::Rect, rect.class)
    assert_equal(32, rect.x)
    assert_equal(32, rect.y)
    assert_equal(65, rect.width)
    assert_equal(65, rect.height)
  end

  def test_point_polyon
    mat, contours, hierarchy = circle_contours
    contour = contours.first
    dist = Cv::point_polygon_test(Cv::InputArray.new(contour), Cv::Point2f.new(0, 0), true)
    assert_in_delta(-58.69, dist)

    dist = Cv::point_polygon_test(Cv::InputArray.new(contour), Cv::Point2f.new(64, 32), true)
    assert_in_delta(0, dist)

    dist = Cv::point_polygon_test(Cv::InputArray.new(contour), Cv::Point2f.new(64, 64), true)
    assert_in_delta(31.016, dist)
  end

  def test_match_shapes
    img1 = Cv::imread(self.sample_path("contours.jpg"), Cv::ImreadModes::IMREAD_GRAYSCALE)
    img2 = Cv::imread(self.sample_path("lines.jpg"), Cv::ImreadModes::IMREAD_GRAYSCALE)

    [Cv::ShapeMatchModes::CONTOURS_MATCH_I1, Cv::ShapeMatchModes::CONTOURS_MATCH_I2, Cv::ShapeMatchModes::CONTOURS_MATCH_I3].each do |match_method|
      value = Cv::match_shapes(img1.input_array, img1.input_array, match_method, 0.01)
      assert_in_delta(0, value, 0.01)

      value = Cv::match_shapes(img1.input_array, img2.input_array, match_method, 0.01)
      assert(value > 0)
    end
  end

  def test_find_contours
    mat = Cv::imread(self.sample_path("contours.jpg"), Cv::ImreadModes::IMREAD_GRAYSCALE)

    # Make binary image
    mat.rows.times do |j|
      mat.cols.times do |i|
        mat[j, i] = (mat[j, i] < 128) ? BLACK : WHITE
      end
    end

    contours, hierarchy = mat.find_contours(Cv::RetrievalModes::RETR_TREE, Cv::ContourApproximationModes::CHAIN_APPROX_SIMPLE)

    assert_equal(4, contours.size)

    expected = [[2, -1, 1, -1], [-1, -1, -1, 0], [-1, 0, 3, -1], [-1, -1, -1, 2]]

    hierarchy.each.with_index do |vec4, i|
      assert_equal(expected[i], vec4.to_a)
    end
  end
end
