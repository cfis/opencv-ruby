#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class Mat_drawingTest < OpenCVTestCase
  def test_line
    mat = create_mat(240, 320, CV_8UC3) { Cv::Vec3b.new(255, 255, 255) }
    mat.line(Cv::Point.new(1, 0), Cv::Point.new(mat.cols - 1, mat.rows - 1),
            Cv::Scalar.new(255, 0, 0), thickness: 3, line_type: Cv::LineTypes::LINE_AA)
    assert_equal("c4c6a44b0c5747c00da409a1cf703cb8", hash_img(mat))
    # show_images([mat])
  end

  def test_rectangle
    mat = create_mat(240, 320, CV_8UC3) { Cv::Vec3b.new(255, 255, 255) }
    mat.rectangle(Cv::Point.new(20, 20), Cv::Point.new(mat.cols - 20, mat.rows - 20),
                      Cv::Scalar.new(255, 0, 0), thickness: 3, line_type: Cv::LineTypes::LINE_AA)
    assert_equal("9388c1f1baeae8b32dfbf29307d1e6fa", hash_img(mat))
    #show_images([mat])
  end

  def test_circle
    mat = create_mat(240, 320, CV_8UC3) { Cv::Vec3b.new(255, 255, 255) }
    mat.circle(Cv::Point.new(mat.cols / 2, mat.rows / 2), 80,
               Cv::Scalar.new(255, 0, 0), thickness: 3, line_type: Cv::LineTypes::LINE_AA)
    assert_equal("f7b36c3e8bb5974b8e05f2a12d339b38", hash_img(mat))
    # show_images([mat])
  end

  def test_ellipse
    mat = create_mat(240, 320, CV_8UC3) { Cv::Vec3b.new(255, 255, 255) }
    mat.ellipse(Cv::Point.new(mat.cols / 2, mat.rows / 2), Cv::Size.new(100, 60), 30, 0, 360,
                    Cv::Scalar.new(255, 0, 0), thickness: 3, line_type: Cv::LineTypes::LINE_AA)
    assert_equal("a2077b2dc799d26747326b6ad018a734", hash_img(mat))
    #show_images([mat])
  end

  def test_ellipse_box
    mat = create_mat(240, 320, CV_8UC3) { Cv::Vec3b.new(255, 255, 255) }
    box = Cv::RotatedRect.new(Cv::Point2f.new(mat.cols / 2, mat.rows / 2), Cv::Size2f.new(120, 160), 30)
    mat.ellipse_box(box, Cv::Scalar.new(255, 0, 0), thickness: 3, line_type: Cv::LineTypes::LINE_AA)
    assert_equal("9a65aa6213fdc440f8e42b8c97f84c00", hash_img(mat))
    #show_images([mat])
  end

  def test_fill_convex_poly
    mat = create_mat(240, 320, CV_8UC3) { Cv::Vec3b.new(255, 255, 255) }
    points = [[10, 20],[10, 150], [100, 50]].map do |x, y|
      Cv::Point.new(x, y)
    end
    vector = Std::Vector≺Cv꞉꞉Point2i≻.new(points)
    input = Cv::InputArray.new(vector)
    mat.fill_convex_poly(input, Cv::Scalar.new(255, 0, 0), line_type: Cv::LineTypes::LINE_AA)
    assert_equal("81dcf109880086ff1b26ad099de9c138", hash_img(mat))
    #show_images([mat])
  end

  def test_fill_poly
    mat = create_mat(240, 320, CV_8UC3) { Cv::Vec3b.new(255, 255, 255) }
    vectors = [[[10, 20], [10, 150], [100, 50]],
               [[200, 10], [200, 200], [170, 200]],
               [[30, 10], [0, 0], [90, 150]]].map do |elements|
      points = elements.map do |x, y|
        Cv::Point.new(x, y)
      end
      Std::Vector≺Cv꞉꞉Point2i≻.new(points)
    end

    vector = Std::Vector≺vector≺cv꞉꞉Point_≺int≻≻≻.new(vectors)
    input = Cv::InputArray.new(vector)
    mat.fill_poly(input, Cv::Scalar.new(255, 0, 0), line_type: Cv::LineTypes::LINE_AA)
    assert_equal("645e898afa3fce0755e3aa0f4d1142de", hash_img(mat))
    #show_images([mat])
  end

  def test_poly_line
    mat = create_mat(240, 320, CV_8UC3) { Cv::Vec3b.new(255, 255, 255) }
    vectors = [[[10, 20], [10, 150], [100, 150], [10, 20]],
               [[100, 200], [200, 190], [180, 50], [100, 200]]].map do |line|
      points = line.map do |x, y|
        Cv::Point.new(x, y)
      end
      Std::Vector≺Cv꞉꞉Point2i≻.new(points)
    end
    vector = Std::Vector≺vector≺cv꞉꞉Point_≺int≻≻≻.new(vectors)
    input = Cv::InputArray.new(vector)
    mat.polylines(input, true, Cv::Scalar.new(255, 0, 0), thickness: 3, line_type: Cv::LineTypes::LINE_AA)
    assert_equal("61ad1499a338c585e610c0e762fd4554", hash_img(mat))
    #show_images([mat])
  end

  def test_put_text
    mat = create_mat(240, 320, CV_8UC3) { Cv::Vec3b.new(255, 255, 255) }

    mat.put_text('Hello World 1', Cv::Point.new(60, 90), Cv::HersheyFonts::FONT_HERSHEY_SIMPLEX,
                 1.0, Cv::Scalar.new(180, 220, 180), thickness: 3)
    assert_equal("6e0f11aa06ae1db6a94038097dc16bb4", hash_img(mat))
    #show_images([mat])
  end
end