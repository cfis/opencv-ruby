#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class ObjectDetectionTest < OpenCVTestCase
  def get_classifier
    data = self.sample_path('haarcascade_frontalface_alt.xml.gz')
    Cv::CascadeClassifier.new(data)
  end

  def test_load
    classifier = get_classifier
    refute(classifier.empty?)
    refute(classifier.old_format_cascade?)
  end

  def test_detect_objects
    path = self.sample_path('lena-256x256.jpg')
    image = Cv::imread(path)

    classifier = get_classifier

    objects = Std::Vector≺cv꞉꞉Rect_≺int≻≻.new
    classifier.detect_multi_scale(image.input_array, objects)
    assert_equal(1, objects.size)
    assert_equal(108, objects[0].x)
    assert_equal(102, objects[0].y)
    assert_equal(86, objects[0].width)
    assert_equal(86, objects[0].height)

    objects = Std::Vector≺cv꞉꞉Rect_≺int≻≻.new
    classifier.detect_multi_scale(image.input_array, objects,
                                  scale_factor: 2.0, min_neighbors: 5,
                                  min_size: Cv::Size.new(10, 10), max_size: Cv::Size.new(100, 100))
    assert_equal(1, objects.size)
    assert_equal(110, objects[0].x)
    assert_equal(103, objects[0].y)
    assert_equal(80, objects[0].width)
    assert_equal(80, objects[0].height)
  end
end
