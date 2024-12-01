#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class ImgProcTest < OpenCVTestCase
  def circle_contour
    mat = create_mat(128, 128, CV_8UC1) do |j, i|
      (j - 64) ** 2 + (i - 64) ** 2 <= (32 ** 2) ? 255 : 0
    end
    contours, hierarchy = mat.find_contours(Cv::RetrievalModes::RETR_EXTERNAL, Cv::ContourApproximationModes::CHAIN_APPROX_NONE)
    contours.first
  end

  def test_adaptive_threshold
    mat = create_mat(5, 5, CV_8UC1) do |j, i, n|
      (n + 1) * 10
    end

    mat1 = mat.adaptive_threshold(128, Cv::AdaptiveThresholdTypes::ADAPTIVE_THRESH_MEAN_C,
                                  Cv::ThresholdTypes::THRESH_BINARY, 5, 10)
    expected = [0, 0, 0, 0, 0, 0, 0, 0, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128, 128]
    assert_equal(expected, mat1.to_a)

    mat2 = mat.adaptive_threshold(255, Cv::AdaptiveThresholdTypes::ADAPTIVE_THRESH_GAUSSIAN_C,
                                  Cv::ThresholdTypes::THRESH_BINARY_INV, 5, 10)
    expected = [255, 255, 255, 255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    assert_equal(expected, mat2.to_a)
  end

  def test_apply_color_map
    mat = Cv::Mat.new(64, 256, CV_8UC1)
    mat.rows.times do |row|
      mat.cols.times do |col|
        mat[row, col] = col
      end
    end

    cmap = mat.apply_color_map(Cv::ColormapTypes::COLORMAP_AUTUMN)
    assert_equal(Cv::Mat, cmap.class)
    assert_equal(mat.rows, cmap.rows)
    assert_equal(mat.cols, cmap.cols)
  end

  def test_bilateral_filter
    mat = create_mat(64, 64, CV_8UC1) do |j, i, c|
      if i > 32
        (i + j) % 15 != 0 ? 32 : 224
      else
        (i + j) % 15 != 0 ? 224 : 32
      end
    end
    mat2 = mat.bilateral_filter(10,3, 3)
  end

  def test_blur
    image_path = self.sample_path("starry_night.jpg")
    image = Cv.imread(image_path)
    blurred = image.blur(Cv::Size.new(5, 5))
    refute_equal(image, blurred)
    assert_equal(3, blurred.channels)
    assert_equal(CV_8UC1, blurred.depth)
    assert_equal('f7db5edda1f86bb8f6a62e011a60063a', hash_img(blurred))
  end

  def test_canny
    image = Cv::imread(self.sample_path('lena-256x256.jpg'), Cv::ImreadModes::IMREAD_GRAYSCALE)

    transformed = Cv::Mat.new
    Cv::canny(image.input_array, transformed.output_array, 50, 200)
    assert_equal('ec3e88035bb98b5c5f1a08c8e07ab0a8', hash_img(transformed))
  end

  def test_circle
    radius = 40
    center = Cv::Point.new(128, 128)
    mat = Cv::Mat.zeros(center.y * 2, center.x * 2, CV_8UC1).to_mat
    mat.circle(center, radius, Cv::Scalar.new(255, 255, 255), thickness: 1)
    assert_equal('d8c7e7892d89619a719d27da175e10e6', hash_img(mat))
  end

  def test_convex_hull
    contour = circle_contour

    result = Cv::Mat.new
    Cv::convex_hull(Cv::InputArray.new(contour), result.output_array)
    assert_equal(36, result.rows)
    assert_equal(1, result.cols)
    assert_equal(CV_32SC2, result.type)

    assert_equal(Cv::Vec2i, result[0, 0].class)
    assert_equal(Cv::Vec2i.new(71, 33), result[0, 0])
    assert_equal(Cv::Vec2i.new(64, 32), result[35, 0])
  end

  def test_convex_hull_indices
    contour = circle_contour

    result = Cv::Mat.new
    Cv::convex_hull(Cv::InputArray.new(contour), result.output_array, return_points: false)
    assert_equal(36, result.rows)
    assert_equal(1, result.cols)
    assert_equal(CV_32SC1, result.type)

    assert_equal(173, result[0, 0])
    assert_equal(0, result[35, 0])
  end

  def test_convexity_defects
    image_path = self.sample_path("star.jpg")
    image = Cv::imread(image_path, Cv::ImreadModes::IMREAD_GRAYSCALE)
    contours, hierarchy = image.find_contours(Cv::RetrievalModes::RETR_EXTERNAL, Cv::ContourApproximationModes::CHAIN_APPROX_NONE)
    contour = contours.first

    indices = Cv::Mat.new
    Cv::convex_hull(Cv::InputArray.new(contour), indices.output_array, return_points: false)

    defects = Cv::Mat.new
    Cv::convexity_defects(Cv::InputArray.new(contour), indices.input_array, defects.output_array)
    assert_equal(32, defects.rows)
    d = defects[0]
    assert_equal(33, d.start.x)
    assert_equal(57, d.start.y)
    assert_equal(33, d.depth_point.x)
    assert_equal(63, d.depth_point.y)
    assert_equal(32, d.end.x)
    assert_equal(64, d.end.y)
    assert_in_delta(0.8485, d.depth, 0.001)
  end

  def test_copy_make_border
    mat1 = Cv::Mat.new(32, 32, CV_8UC1, Cv::Scalar.new(128))
    mat2 = mat1.copy_make_border(16, 80, 8, 56, Cv::BorderTypes::BORDER_CONSTANT)
    assert_equal('540d2cdcdfba283a0af77524a5cc2c14', hash_img(mat2))
  end

  def test_corner_eigen_vals_and_vecs
    image = Cv::imread(self.sample_path('lena-256x256.jpg'), Cv::ImreadModes::IMREAD_GRAYSCALE)
    mat = image.corner_eigen_vals_and_vecs(3, 3)
    assert_equal('0acde3ab687fc363425532d5376b9542', hash_img(mat))
  end

  def test_corner_min_eigen_val
    image = Cv::imread(self.sample_path('lena-256x256.jpg'), Cv::ImreadModes::IMREAD_GRAYSCALE)
    mat = image.corner_min_eigen_val(3, ksize: 3)
    assert_equal('ee60589dfcfbfc6f78b2904181087d63', hash_img(mat))
  end

  def test_corner_harris
    mat = Cv::imread(self.sample_path('lena-256x256.jpg'), Cv::ImreadModes::IMREAD_GRAYSCALE)
    mat1 = mat.corner_harris(3, 3, 0.04)
    assert_equal('7bb617af15eb1c0c1f4eae545fea5696', hash_img(mat1))
  end

  def test_cvt_color
    image_path = self.sample_path("cafe_terrace_night.jpg")
    image = Cv.imread(image_path)
    gray_image = image.cvt_color(Cv::ColorConversionCodes::COLOR_BGR2GRAY)
    assert_equal(image.size, gray_image.size)
  end

  def test_dilate
    mat = create_mat(9, 9, CV_8UC1) do |j, i, c|
      if i == 4 and j == 4
        255
      else
        0
      end
    end

    mat1 = create_mat(5, 5, CV_8UC1) do |j, i, c|
      if i == 2 or j == 2
        200
      else
        0
      end
    end

    kernel = Cv::get_structuring_element(Cv::MorphShapes::MORPH_RECT, Cv::Size.new(3, 3))
    mat2 = mat.dilate(kernel)
    mat3 = mat.dilate(kernel, Cv::Point.new(-1,-1), 2)

    kernel = Cv::get_structuring_element(Cv::MorphShapes::MORPH_CROSS, Cv::Size.new(5, 5), Cv::Point.new(2, 2))
    mat4 = mat1.dilate(kernel)
    assert_equal('9f02fc4438b1d69fea75a10dfd2b66b0', hash_img(mat2))
    assert_equal('ebf07f2a0edd2fd0fe26ff5921c6871b', hash_img(mat3))
    assert_equal('80cf772f4e9f857d9542736506e50e48', hash_img(mat4))
  end

  def test_equalize_hist
    mat = Cv::imread(self.sample_path('lena-256x256.jpg'), Cv::ImreadModes::IMREAD_GRAYSCALE)
    result = mat.equalize_hist
    assert_equal(Cv::Mat, result.class)
    assert_equal(mat.rows, result.rows)
    assert_equal(mat.cols, result.cols)
    assert_equal('524b90babcb7e8568046349f7603c110', hash_img(result))
  end

  def test_erode
    mat = create_mat(9, 9, CV_8UC1) do |j, i, c|
      if i >= 3 and i < 6 and j >= 3 and j < 6
        255
      else
        0
      end
    end

    mat1 = create_mat(9, 9, CV_8UC1) do |j, i, c|
      if i >= 1 and i < 8 and j >= 1 and j < 8
        255
      else
        0
      end
    end

    mat2 = create_mat(5, 5, CV_8UC1) do |j, i, c|
      if i == 2 or j == 2
        255
      else
        0
      end
    end

    kernel = Cv::get_structuring_element(Cv::MorphShapes::MORPH_RECT, Cv::Size.new(3, 3))
    mat3 = mat.erode(kernel)
    mat4 = mat.erode(kernel)
    mat5 = mat1.erode(kernel, anchor: Cv::Point.new(-1,-1), iterations: 2)

    kernel = Cv::get_structuring_element(Cv::MorphShapes::MORPH_CROSS, Cv::Size.new(5, 5), Cv::Point.new(2, 2))
    mat6 = mat1.erode(kernel)
    mat7 = mat.clone
    mat7.erode(kernel)

    assert_equal('075eb0e281328f768eb862735d16979d', hash_img(mat3))
    assert_equal('075eb0e281328f768eb862735d16979d', hash_img(mat4))
    assert_equal('9f02fc4438b1d69fea75a10dfd2b66b0', hash_img(mat5))
    assert_equal('9f02fc4438b1d69fea75a10dfd2b66b0', hash_img(mat6))
    assert_equal('9f02fc4438b1d69fea75a10dfd2b66b0', hash_img(mat7))
  end

  def test_filter2d
    mat = Cv::imread(self.sample_path('lena-256x256.jpg'), Cv::ImreadModes::IMREAD_GRAYSCALE)
    kernel = Cv::Mat.new(3, 3, CV_32FC1)

    # Laplacian filter kernel
    laplace4 = [0, 1, 0,
                1, -4, 1,
                0, 1, 0]
    3.times do |row|
      3.times do |col|
        kernel[row, col] = laplace4[row * 3 + col] * 1.0
      end
    end
    mat2 = mat.filter_2d(-1, kernel)
    assert_equal('171632ddf1442d16e527fdd5e9a223c4', hash_img(mat2))

    mat3 = mat.filter_2d(CV_32FC1, kernel, anchor: Cv::Point.new(0, 0))
    assert_equal('cfb1597a099c6119a8f9e36718235516', hash_img(mat3))
  end

  def test_find_corner_sub_pix
    mat = Cv::imread(self.sample_path('chessboard.jpg'), Cv::ImreadModes::IMREAD_GRAYSCALE)
    pattern_size = Cv::Size.new(4, 4)
    corners, found = mat.find_chessboard_corners(pattern_size)
    assert(found)
    assert(16, corners.size)
    refined_corners = mat.corner_sub_pix(corners, Cv::Size.new(3, 3), Cv::Size.new(-1, -1),
                                         Cv::TermCriteria.new(Cv::TermCriteria::Type::COUNT, 20, 0.03))
    expected = [[39, 40], [79, 40], [119, 40], [159, 40], [39, 79], [79, 79],
                [119, 79], [159, 79], [39, 119], [79, 119], [119, 119], [159, 119],
                [39, 159], [79, 159], [119, 159], [159, 159]]

    expected.each.with_index do |expected_array, i|
      assert_in_delta_array(expected_array, refined_corners[i].to_a, 0.2)
    end
  end

  def test_fit_ellipse
    contour = circle_contour
    rotated_rect = Cv::fit_ellipse(Cv::InputArray.new(contour))
    center = rotated_rect.center
    assert_equal(64, center.x.to_i)
    assert_equal(64, center.y.to_i)
    size = rotated_rect.size
    assert_in_delta(63, size.width, 1.0)
    assert_in_delta(63, size.height, 1.0)
    angle = [rotated_rect.angle, 180 - rotated_rect.angle].min
    assert_in_delta(0, angle, 0.1)
  end

  def test_flood_fill
    mat = create_mat(128, 256, CV_8UC1) do |j, i, c|
      if (i >= 32 and i < 224) and (j >= 32 and j < 96)
        255
      elsif (i >= 16 and i < 240) and (j >= 16 and j < 112)
        192
      else
        128
      end
    end

    mask = Cv::Mat.new
    point = Cv::Point.new(20, 20)
    area, rect = mat.flood_fill(mask, point,  Cv::Scalar.new(0),
                                lo_diff: Cv::Scalar.new(0), up_diff: Cv::Scalar.new(64),
                                connectivity: 8, fill_value: 1, fill_flags: Cv::FloodFillFlags::FLOODFILL_MASK_ONLY)
    assert_equal(21504.0, area)
    assert_equal(16, rect.x)
    assert_equal(16, rect.y)
    assert_equal(224, rect.width)
    assert_equal(96, rect.height)
  end

  def test_gaussian_blur
    image_path = self.sample_path("starry_night.jpg")
    image = Cv.imread(image_path)
    blurred = image.gaussian_blur(Cv::Size.new(5, 5), 0)
    refute_equal(image, blurred)
    assert_equal('6d9daaa4fc11e1f656075da713dcaf92', hash_img(blurred))
  end

  def test_get_perspective_transform
    # Homography
    #   <src>     =>    <dst>
    # (0, 0)      =>  (50, 0)
    # (255, 0)    =>  (205, 0)
    # (255, 255)  =>  (255, 220)
    # (0, 255)    =>  (0, 275)

    from = Std::Vector≺Cv꞉꞉Point2f≻.new
    from << Cv::Point2f.new(0, 0) <<
      Cv::Point2f.new(255, 0) <<
      Cv::Point2f.new(255, 255) <<
      Cv::Point2f.new(0,255)

    to = Std::Vector≺Cv꞉꞉Point2f≻.new
    to << Cv::Point2f.new(50, 0) <<
      Cv::Point2f.new(205, 0) <<
      Cv::Point2f.new(255, 220) <<
      Cv::Point2f.new(0, 275)

    transform = Cv::get_perspective_transform(Cv::InputArray.new(from), Cv::InputArray.new(to))
    assert_equal(3, transform.rows)
    assert_equal(3, transform.cols)
    expected = [0.7242990654205607, -0.19607843137254904, 50.0,
                0.0, 0.6248854682059739, 0.0,
                0.0005680776983690672, -0.0016492578339747114, 1.0]
    assert_in_delta_array(expected, transform.to_a)
  end

  def test_get_structuring_element
    mat = Cv::get_structuring_element(Cv::MorphShapes::MORPH_RECT, Cv::Size.new(2, 2))
    assert_equal([1, 1, 1, 1], mat.to_a)
  end

  def test_good_features_to_track
    mat = Cv::imread(self.sample_path('lena-32x32.jpg'), Cv::ImreadModes::IMREAD_GRAYSCALE)
    mask = create_mat(mat.rows, mat.cols, CV_8UC1) do |j, i, c|
      if (i > 8 and i < 18) and (j > 8 and j < 18)
        1
      else
        0
      end
    end

    expected = [[24, 7], [20, 23], [17, 11], [26, 29], [30, 24],
                [19, 16], [28, 2], [13, 18], [14, 4]].map do |values|
      Cv::Vec2f.new(*values)
    end
    corners = mat.good_features_to_track(10, 0.2, 5)
    assert_equal(expected, corners.to_a)

    expected = [[17, 11], [17, 16]].map do |values|
      Cv::Vec2f.new(*values)
    end
    corners = mat.good_features_to_track(10, 0.2, 5, :mask => mask)
    assert_equal(expected, corners.to_a)

    expected = [[21, 7], [22, 23], [18, 12], [28, 4], [28, 26], [17, 27], [13, 20], [10, 11], [14, 5]].map do |values|
      Cv::Vec2f.new(*values)
    end
    corners = mat.good_features_to_track(10, 0.2, 5, :block_size => 7)
    assert_equal(expected, corners.to_a)

    expected = [[24, 8], [20, 23], [16, 11], [20, 16],[27, 28], [28, 2]].map do |values|
      Cv::Vec2f.new(*values)
    end
    corners = mat.good_features_to_track(10, 0.2, 5, :use_harris_detector => true)
    assert_equal(expected, corners.to_a)

    expected = [[24, 7], [20, 23], [17, 11], [26, 29], [30, 24], [19, 16], [28, 2], [13, 18], [14, 4]].map do |values|
      Cv::Vec2f.new(*values)
    end
    corners = mat.good_features_to_track(10, 0.2, 5, :k => 0.01)
    assert_equal(expected, corners.to_a)
  end

  def test_hough_lines
    mat1 = Cv::imread(self.sample_path('lines.jpg'), Cv::ImreadModes::IMREAD_GRAYSCALE)
    # make a binary image
    mat2 = Cv::Mat.new(mat1.rows, mat1.cols, CV_8UC1)
    mat1.rows.times do |row|
      mat1.cols.times do |col|
        mat2[row, col] = (mat1[row, col] <= 100) ? 0 : 255
      end
    end

    seq = mat2.hough_lines(1, Math::PI / 180, 65)
    assert_equal(4, seq.size)
    assert_in_delta_array([82, 1.5708], seq[0])
    assert_in_delta_array([17, 1.5708], seq[1])
    assert_in_delta_array([85, 0], seq[2])
    assert_in_delta_array([158, 0], seq[3])
  end

  def test_hough_circles
    mat1 = Cv::imread(self.sample_path('lines.jpg'), Cv::ImreadModes::IMREAD_GRAYSCALE)
    # make a binary image
    mat2 = Cv::Mat.new(mat1.rows, mat1.cols, CV_8UC1)
    mat1.rows.times do |row|
      mat1.cols.times do |col|
        mat2[row, col] = (mat1[row, col] <= 100) ? 0 : 255
      end
    end

    circles = mat2.hough_circles(Cv::HoughModes::HOUGH_GRADIENT, 1.5, 40,
                                 param1: 100, param2: 40, min_radius: 10, max_radius: 50)
    assert_equal(2, circles.size)
    assert_in_delta_array([117.75, 129.75, 26.65], circles[0])
    assert_in_delta_array([36.75, 87.75, 27.70], circles[1])
  end

  def test_inpaint
    mat = Cv::imread(self.sample_path('lena-inpaint.jpg'), Cv::ImreadModes::IMREAD_ANYCOLOR | Cv::ImreadModes::IMREAD_ANYDEPTH)
    mask = Cv::imread(self.sample_path('inpaint-mask.bmp'), Cv::ImreadModes::IMREAD_GRAYSCALE)

    result = mat.inpaint(mask, 10, Cv::INPAINT_NS)
    assert_equal('1eadd141b1fb54cdd624eaf81d692659', hash_img(result))

    result = mat.inpaint(mask, 10, Cv::INPAINT_TELEA)
    assert_equal('78db691b81e5799ff443100fff524369', hash_img(result))
  end

  def test_integral
    mat = create_mat(3, 3, CV_8UC1) do |j, i, n|
      n
    end
    result_sum = []
    result_sqsum = []
    result_tiled_sum = []

    sum, sqsum, tilted = mat.integral

    expected_sum = [0, 0, 0, 0,
                    0, 0, 1, 3,
                    0, 3, 8, 15,
                    0, 9, 21, 36]
    assert_equal(expected_sum, sum.to_a)

    expected_sqsum = [0.0, 0.0, 0.0, 0.0,
                      0.0, 0.0, 1.0, 5.0,
                      0.0, 9.0, 26.0, 55.0,
                      0.0, 45.0, 111.0, 204.0]
    assert_equal(expected_sqsum, sqsum.to_a)

    expected_tilted = [0, 0, 0, 0,
                       0, 0, 1, 2,
                       0, 4, 7, 8,
                       4, 16, 22, 20]
    assert_equal(expected_tilted, tilted.to_a)
  end

  def test_laplacian
    image = Cv::imread(self.sample_path('lena-256x256.jpg'), Cv::ImreadModes::IMREAD_GRAYSCALE)

    transformed = Cv::Mat.new
    Cv::laplacian(image.input_array, transformed.output_array, CV_8U, 1)
    assert_equal('171632ddf1442d16e527fdd5e9a223c4', hash_img(transformed))
  end

  def test_log_polar
    mat1 = Cv::imread(self.sample_path("fruits.jpg"), Cv::ImreadModes::IMREAD_ANYCOLOR | Cv::ImreadModes::IMREAD_ANYDEPTH)
    mat2 = mat1.log_polar(Cv::Point2f.new(mat1.cols / 2, mat1.rows / 2), 40, Cv::InterpolationFlags::INTER_LINEAR | Cv::InterpolationFlags::WARP_FILL_OUTLIERS)

    assert_equal(mat1.depth, mat2.depth)
    assert_equal(mat1.channels, mat2.channels)
    b, g, r =  color_hists(mat1)
    assert_equal(11361515, b)
    assert_equal(21041086, g)
    assert_equal(27233602, r)
  end

  def test_match_template
    mat = Cv::imread(self.sample_path('lena-256x256.jpg'), Cv::ImreadModes::IMREAD_ANYCOLOR | Cv::ImreadModes::IMREAD_ANYDEPTH)
    template = Cv::imread(self.sample_path('lena-eyes.jpg'), Cv::ImreadModes::IMREAD_ANYCOLOR | Cv::ImreadModes::IMREAD_ANYDEPTH)

    # sqdiff
    result = mat.match_template(template, Cv::TemplateMatchModes::TM_SQDIFF)
    assert_equal(228, result.rows)
    assert_equal(164, result.cols)
    assert_equal(CV_32FC1, result.type)
    pt = result.min_max_loc[2]
    expected_pt = Cv::Point.new(103, 119)
    assert_equal(expected_pt.x, pt.x)
    assert_equal(expected_pt.y, pt.y)

    # sqdiff_normed
    result = mat.match_template(template, Cv::TemplateMatchModes::TM_SQDIFF_NORMED)
    assert_equal(228, result.rows)
    assert_equal(164, result.cols)
    assert_equal(CV_32FC1, result.type)
    pt = result.min_max_loc[2]
    expected_pt = Cv::Point.new(103, 119)
    assert_equal(expected_pt.x, pt.x)
    assert_equal(expected_pt.y, pt.y)
  end

  def test_match_shapes
    mat_cv = Cv::imread(self.sample_path('str-cv.jpg'), Cv::ImreadModes::IMREAD_GRAYSCALE)
    mat_ov = Cv::imread(self.sample_path('str-ov.jpg'), Cv::ImreadModes::IMREAD_GRAYSCALE)
    mat_cv_rotated = Cv::imread(self.sample_path('str-cv-rotated.jpg'), Cv::ImreadModes::IMREAD_GRAYSCALE)

    result = Cv::match_shapes(mat_cv.input_array, mat_ov.input_array, Cv::ShapeMatchModes::CONTOURS_MATCH_I1, 0.00001)
    assert_in_delta(0.0010649, result)

    result = Cv::match_shapes(mat_cv.input_array, mat_cv_rotated.input_array, Cv::ShapeMatchModes::CONTOURS_MATCH_I1, 0.00001)
    assert_in_delta(0.0, result)
  end

  def test_median_blur
    mat = create_mat(64, 64, CV_8UC1) do |j, i, c|
      if (i + j) % 15 != 0
        255
      else
        0
      end
    end

    (-1..1).each do |dy|
      (-1..1).each do |dx|
        mat[32 + dy, 32 + dx] = 0
      end
    end

    mat1 = mat.median_blur(3)
    assert_equal('7343a41c542e034db356636c06134961', hash_img(mat1))
  end

  def test_min_area_rect
    contour = circle_contour
    rotated_rect = Cv::min_area_rect(Cv::InputArray.new(contour))
    assert_equal(Cv::RotatedRect, rotated_rect.class)
    center = rotated_rect.center
    assert_equal(64, center.x.to_i)
    assert_equal(64, center.y.to_i)
    size = rotated_rect.size
    assert_in_delta(63.356, size.width, 0.001)
    assert_in_delta(63.356, size.height, 0.001)
    assert_in_delta(81.870, rotated_rect.angle, 1.0)
  end

  def test_min_enclosing_circle
    contour = circle_contour

    center = Cv::Point2f.new(0, 0)
    radius = Rice::Buffer≺float≻.new(0.0)
    Cv::min_enclosing_circle(Cv::InputArray.new(contour), center, radius)
    assert_equal(64, center.x)
    assert_equal(64, center.y)
    assert_in_delta(32.0, radius[0], 0.001)
  end

  def test_morphology
    mat = create_mat(64, 64, CV_8UC1) do |j, i, c|
      if i >= 8 and i < 56 and j >= 8 and j < 56 and (i + j) % 15 != 0
        255
      else
        0
      end
    end

    # Open
    kernel = Cv::get_structuring_element(Cv::MorphShapes::MORPH_CROSS, Cv::Size.new(5, 5), Cv::Point.new(2, 2))
    mat1 = mat.morphology_ex(Cv::MorphTypes::MORPH_OPEN, kernel)
    assert_equal('63ccb07cb93efb1563657f51e3d89252', hash_img(mat1))

    # Close
    mat2 = mat.morphology_ex(Cv::MorphTypes::MORPH_CLOSE, kernel)
    assert_equal('831c513d6ed86bce3f15c697de4a72f8', hash_img(mat2))

    # Gradient
    mat3 = mat.morphology_ex(Cv::MorphTypes::MORPH_GRADIENT, kernel)
    assert_equal('1e8007c211d6f464cf8584e8e83b3c35', hash_img(mat3))

    # Top hat
    mat4 = mat.morphology_ex(Cv::MorphTypes::MORPH_TOPHAT, kernel)
    assert_equal('1760c5b63a52df37069164fe3e901aa4', hash_img(mat4))

    # Black hat
    mat5 = mat.morphology_ex(Cv::MorphTypes::MORPH_BLACKHAT, kernel)
    assert_equal('18b1d51637b912a38133341ee006c6ff', hash_img(mat5))
  end

  def test_pre_corner_detect
    image = Cv::imread(self.sample_path('lena-256x256.jpg'), Cv::ImreadModes::IMREAD_GRAYSCALE)
    transformed = image.pre_corner_detect(5)
    assert_equal('e7bd064b49762ebf7cfd325337ca0053', hash_img(transformed))
  end

  def test_pyr_down
    mat = Cv::imread(self.sample_path('lena-256x256.jpg'), Cv::ImreadModes::IMREAD_ANYCOLOR | Cv::ImreadModes::IMREAD_ANYDEPTH)
    mat1 = mat.pyr_down
    assert_equal('de9ff2ffcf8e43f28564a201cf90b7f4', hash_img(mat1))
  end

  def test_pyr_mean_shift_filtering
    mat = Cv::imread(self.sample_path('lena-256x256.jpg'), Cv::ImreadModes::IMREAD_ANYCOLOR | Cv::ImreadModes::IMREAD_ANYDEPTH)
    mat1 = mat.pyr_mean_shift_filtering(30, 30)
    b, g, r = color_hists(mat)
    assert_in_delta(6900000, b, 100000)
    assert_in_delta(6500000, g, 100000)
    assert_in_delta(11800000, r, 100000)
  end

  def test_pyr_up
    mat = Cv::imread(self.sample_path('lena-256x256.jpg'), Cv::ImreadModes::IMREAD_ANYCOLOR | Cv::ImreadModes::IMREAD_ANYDEPTH)
    mat1 = mat.pyr_up
    assert_equal('517688b9b241880c0c48684a9d3a772f', hash_img(mat1))
  end

  def test_rect_sub_pix
    mat = Cv::imread(self.sample_path('lena-256x256.jpg'), Cv::ImreadModes::IMREAD_ANYCOLOR | Cv::ImreadModes::IMREAD_ANYDEPTH)
    center = Cv::Point2f.new(mat.cols / 2.0, mat.rows / 2.0)

    mat1 = mat.get_rect_sub_pix(mat.size.to_size, center)
    assert_equal('ea9a4008afd89b73b518b9640942964f', hash_img(mat1))

    mat2 = mat.get_rect_sub_pix(Cv::Size.new(512, 512), center)
    assert_equal('30ace668b472d697df66a3af60ffce1f', hash_img(mat2))
  end

  def test_remap
    mat1 = Cv::imread(self.sample_path('lena-256x256.jpg'), Cv::ImreadModes::IMREAD_ANYCOLOR | Cv::ImreadModes::IMREAD_ANYDEPTH)
    matx = Cv::Mat.new(mat1.rows, mat1.cols, CV_32FC1)
    maty = Cv::Mat.new(mat1.rows, mat1.cols, CV_32FC1)
    cos30, sin30 = Math.cos(30 * Math::PI / 180), Math.sin(30 * Math::PI / 180)
    half_width, half_height = mat1.cols / 2, mat1.rows / 2
    mat1.rows.times do |j|
      mat1.cols.times do |i|
        x0 = i - half_width
        y0 = j - half_height
        x = x0 * cos30 - y0 * sin30 + half_width
        y = x0 * sin30 + y0 * cos30 + half_height
        matx[j, i] = x
        maty[j, i] = y
      end
    end

    mat2 = mat1.remap(matx, maty, Cv::InterpolationFlags::INTER_NEAREST)
    assert_equal(mat1.cols, mat2.cols)
    assert_equal(mat1.rows, mat2.rows)
    assert_equal(mat1.depth, mat2.depth)
    assert_equal(mat1.channels, mat2.channels)
  end

  def test_resize
    mat = Cv::imread(self.sample_path('lena-256x256.jpg'), Cv::ImreadModes::IMREAD_ANYCOLOR | Cv::ImreadModes::IMREAD_ANYDEPTH)
    size = Cv::Size.new(384, 384)
    mat1 = mat.resize(size)
    mat2 = mat.resize(size, interpolation: Cv::InterpolationFlags::INTER_LINEAR)
    mat3 = mat.resize(size, interpolation: Cv::InterpolationFlags::INTER_NEAREST)
    mat4 = mat.resize(size, interpolation: Cv::InterpolationFlags::INTER_AREA)
    mat5 = mat.resize(size, interpolation: Cv::InterpolationFlags::INTER_CUBIC)
    mat6 = mat.resize(size, interpolation: Cv::InterpolationFlags::INTER_LANCZOS4)

    [mat1, mat2, mat3, mat4, mat5, mat6].each do |m|
      assert_equal(size.width, m.cols)
      assert_equal(size.height, m.rows)
      assert_equal(mat.depth, m.depth)
      assert_equal(mat.channels, m.channels)
    end
  end

  def test_sobel
    image = Cv::imread(self.sample_path('lena-256x256.jpg'), Cv::ImreadModes::IMREAD_GRAYSCALE)

    transformed = Cv::Mat.new
    Cv::sobel(image.input_array, transformed.output_array, CV_8U, 1, 0)
    assert_equal('644d9c3b429c2033cf190c0e5b529e6e', hash_img(transformed))

    Cv::convert_scale_abs(transformed.input_array, transformed.output_array, 1, 0)
    assert_equal('644d9c3b429c2033cf190c0e5b529e6e', hash_img(transformed))
  end

  def test_rotation_matrix2D
    mat = Cv::get_rotation_matrix_2d(Cv::Point2f.new(10, 20), 60, 2.0)
    assert_equal(2, mat.rows)
    assert_equal(3, mat.cols)
    assert_equal(CV_64FC1, mat.depth)
    assert_equal(1, mat.channels)

    expected = [1.0, 1.73205, -34.64102,
                -1.73205, 1.0, 17.32051]
    assert_in_delta_array(expected, mat.to_a, 0.001)
  end

  def test_threshold
    mat = create_mat(3, 3, CV_8UC1) { |j, i, n| n }

    test_proc = lambda do |type, expected_mat, expected_threshold|
      mat_thresh, computed = mat.threshold(expected_threshold, 7, type)
      assert_equal(expected_mat, mat_thresh.to_a)
    end

    # Binary
    expected = [0, 0, 0,
                0, 0, 7,
                7, 7, 7]
    test_proc.call(Cv::ThresholdTypes::THRESH_BINARY, expected, 4)

    expected = [0, 0, 0,
                0, 7, 7,
                7, 7, 7]
    test_proc.call(Cv::ThresholdTypes::THRESH_BINARY | Cv::ThresholdTypes::THRESH_OTSU, expected, 3)

    # Binary inverse
    expected = [7, 7, 7,
                7, 7, 0,
                0, 0, 0]
    test_proc.call(Cv::ThresholdTypes::THRESH_BINARY_INV, expected, 4)

    expected = [7, 7, 7,
                7, 0, 0,
                0, 0, 0]
    test_proc.call(Cv::ThresholdTypes::THRESH_BINARY_INV | Cv::ThresholdTypes::THRESH_OTSU, expected, 3)

    # Trunc
    expected = [0, 1, 2,
                3, 4, 4,
                4, 4, 4]
    test_proc.call(Cv::ThresholdTypes::THRESH_TRUNC, expected, 4)

    expected = [0, 1, 2,
                3, 3, 3,
                3, 3, 3]
    test_proc.call(Cv::ThresholdTypes::THRESH_TRUNC | Cv::ThresholdTypes::THRESH_OTSU, expected, 3)

    # To zero
    expected = [0, 0, 0,
                0, 0, 5,
                6, 7, 8]
    test_proc.call(Cv::ThresholdTypes::THRESH_TOZERO, expected, 4)

    expected = [0, 0, 0,
                0, 4, 5,
                6, 7, 8]
    test_proc.call(Cv::ThresholdTypes::THRESH_TOZERO | Cv::ThresholdTypes::THRESH_OTSU, expected, 3)

    # To zero inverse
    expected = [0, 1, 2,
                3, 4, 0,
                0, 0, 0]
    test_proc.call(Cv::ThresholdTypes::THRESH_TOZERO_INV, expected, 4)

    expected = [0, 1, 2,
                3, 0, 0,
                0, 0, 0]
    test_proc.call(Cv::ThresholdTypes::THRESH_TOZERO_INV | Cv::ThresholdTypes::THRESH_OTSU, expected, 3)
  end

  def test_warp_affine
    mat = Cv::imread(self.sample_path('lena-256x256.jpg'), Cv::ImreadModes::IMREAD_ANYCOLOR | Cv::ImreadModes::IMREAD_ANYDEPTH)
    map_matrix = Cv::Mat.new(2, 3, CV_32FC1)
    # center: (128, 128), angle: 25 deg., scale: 1.0
    map_matrix[0, 0] = 0.90631
    map_matrix[0, 1] = 0.42262
    map_matrix[0, 2] = -42.10254
    map_matrix[1, 0] = -0.42262
    map_matrix[1, 1] = 0.90631
    map_matrix[1, 2] = 66.08774
    mat1 = mat.warp_affine(map_matrix, mat.size.to_size)
    mat2 = mat.warp_affine(map_matrix, mat.size.to_size, flags: Cv::InterpolationFlags::INTER_NEAREST | Cv::InterpolationFlags::WARP_FILL_OUTLIERS)
    mat3 = mat.warp_affine(map_matrix, mat.size.to_size, flags: Cv::InterpolationFlags::INTER_LINEAR | Cv::InterpolationFlags::WARP_FILL_OUTLIERS | Cv::InterpolationFlags::WARP_INVERSE_MAP)

    [mat1, mat2, mat3].each do |m|
      assert_equal(mat.cols, m.cols)
      assert_equal(mat.rows, m.rows)
      assert_equal(mat.depth, m.depth)
      assert_equal(mat.channels, m.channels)
    end
  end

  def test_warp_perspective
    # Homography
    #   <src>     =>    <dst>
    # (0, 0)      =>  (50, 0)
    # (255, 0)    =>  (205, 0)
    # (255, 255)  =>  (255, 220)
    # (0, 255)    =>  (0, 275)

    from = Std::Vector≺Cv꞉꞉Point2f≻.new
    from << Cv::Point2f.new(0, 0) <<
      Cv::Point2f.new(255, 0) <<
      Cv::Point2f.new(255, 255) <<
      Cv::Point2f.new(0,255)

    to = Std::Vector≺Cv꞉꞉Point2f≻.new
    to << Cv::Point2f.new(50, 0) <<
      Cv::Point2f.new(205, 0) <<
      Cv::Point2f.new(255, 220) <<
      Cv::Point2f.new(0, 275)

    transform = Cv::get_perspective_transform(Cv::InputArray.new(from), Cv::InputArray.new(to))
    warped_image_size = Cv::Size.new(300, 300)
    mat1 = Cv::imread(self.sample_path('lena-256x256.jpg'), Cv::ImreadModes::IMREAD_ANYCOLOR | Cv::ImreadModes::IMREAD_ANYDEPTH)
    mat2 = mat1.warp_perspective(transform, warped_image_size, flags: Cv::InterpolationFlags::INTER_NEAREST)
    assert_equal('1a9d34b835236dd7f020652e15c57286', hash_img(mat1))
  end

  def test_watershed
    mat = Cv::imread(self.sample_path('lena-256x256.jpg'), Cv::ImreadModes::IMREAD_ANYCOLOR | Cv::ImreadModes::IMREAD_ANYDEPTH)
    marker = Cv::Mat.new(mat.cols, mat.rows, CV_32SC1, Cv::Scalar.new(0))
    marker[150, 150] = 1
    marker[210, 210] = 2
    marker[40, 90] = 3
    mat1 = mat.watershed(marker)
    assert_equal('ee6bec03296039c8df1899d3edc4684e', hash_img(mat1))
  end
end
