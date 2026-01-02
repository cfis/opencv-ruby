#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class DnnUtilsTest < OpenCVTestCase
  # NMS (Non-Maximum Suppression) tests with Rect (int)
  def test_nms_boxes_rect_basic
    bboxes = Std::Vector≺cv꞉꞉Rect_≺int≻≻.new
    bboxes << Cv::Rect.new(10, 10, 100, 100)
    bboxes << Cv::Rect.new(15, 15, 100, 100)
    bboxes << Cv::Rect.new(200, 200, 100, 100)

    scores = Std::Vector≺float≻.new
    scores << 0.9 << 0.8 << 0.7

    indices = Std::Vector≺int≻.new
    Cv::Dnn.nms_boxes(bboxes, scores, 0.5, 0.4, indices)

    assert_kind_of(Std::Vector≺int≻, indices)
    assert(indices.size > 0)
  end

  def test_nms_boxes_rect_high_threshold
    bboxes = Std::Vector≺cv꞉꞉Rect_≺int≻≻.new
    bboxes << Cv::Rect.new(10, 10, 100, 100)
    bboxes << Cv::Rect.new(15, 15, 100, 100)

    scores = Std::Vector≺float≻.new
    scores << 0.9 << 0.85

    indices = Std::Vector≺int≻.new
    # High NMS threshold keeps overlapping boxes
    Cv::Dnn.nms_boxes(bboxes, scores, 0.5, 0.99, indices)

    assert_equal(2, indices.size)
  end

  def test_nms_boxes_rect_low_threshold
    bboxes = Std::Vector≺cv꞉꞉Rect_≺int≻≻.new
    bboxes << Cv::Rect.new(10, 10, 100, 100)
    bboxes << Cv::Rect.new(15, 15, 100, 100)

    scores = Std::Vector≺float≻.new
    scores << 0.9 << 0.85

    indices = Std::Vector≺int≻.new
    # Low NMS threshold removes overlapping boxes
    Cv::Dnn.nms_boxes(bboxes, scores, 0.5, 0.1, indices)

    assert_equal(1, indices.size)
    assert_equal(0, indices[0]) # Highest score box kept
  end

  def test_nms_boxes_score_threshold
    bboxes = Std::Vector≺cv꞉꞉Rect_≺int≻≻.new
    bboxes << Cv::Rect.new(10, 10, 100, 100)
    bboxes << Cv::Rect.new(200, 200, 100, 100)

    scores = Std::Vector≺float≻.new
    scores << 0.9 << 0.3

    indices = Std::Vector≺int≻.new
    # Score threshold filters low confidence boxes
    Cv::Dnn.nms_boxes(bboxes, scores, 0.5, 0.4, indices)

    assert_equal(1, indices.size)
  end

  def test_nms_boxes_with_eta
    bboxes = Std::Vector≺cv꞉꞉Rect_≺int≻≻.new
    3.times do |i|
      bboxes << Cv::Rect.new(i * 10, i * 10, 100, 100)
    end

    scores = Std::Vector≺float≻.new
    scores << 0.9 << 0.8 << 0.7

    indices = Std::Vector≺int≻.new
    Cv::Dnn.nms_boxes(bboxes, scores, 0.5, 0.4, indices, 0.9)

    assert(indices.size > 0)
  end

  def test_nms_boxes_with_top_k
    bboxes = Std::Vector≺cv꞉꞉Rect_≺int≻≻.new
    10.times do |i|
      bboxes << Cv::Rect.new(i * 110, i * 110, 100, 100)
    end

    scores = Std::Vector≺float≻.new
    10.times { |i| scores << (0.9 - i * 0.05) }

    indices = Std::Vector≺int≻.new
    Cv::Dnn.nms_boxes(bboxes, scores, 0.3, 0.5, indices, 1.0, 3)

    assert(indices.size <= 3)
  end


  # NMS with RotatedRect
  def test_nms_boxes_rotated
    bboxes = Std::Vector≺cv꞉꞉RotatedRect≻.new
    bboxes << Cv::RotatedRect.new(Cv::Point2f.new(50, 50), Cv::Size2f.new(100, 100), 0)
    bboxes << Cv::RotatedRect.new(Cv::Point2f.new(55, 55), Cv::Size2f.new(100, 100), 0)
    bboxes << Cv::RotatedRect.new(Cv::Point2f.new(200, 200), Cv::Size2f.new(100, 100), 0)

    scores = Std::Vector≺float≻.new
    scores << 0.9 << 0.8 << 0.7

    indices = Std::Vector≺int≻.new
    Cv::Dnn.nms_boxes(bboxes, scores, 0.5, 0.4, indices)

    assert(indices.size > 0)
  end

  # Batched NMS
  def test_nms_boxes_batched_rect
    bboxes = Std::Vector≺cv꞉꞉Rect_≺int≻≻.new
    bboxes << Cv::Rect.new(10, 10, 100, 100)
    bboxes << Cv::Rect.new(15, 15, 100, 100)
    bboxes << Cv::Rect.new(200, 200, 100, 100)
    bboxes << Cv::Rect.new(205, 205, 100, 100)

    scores = Std::Vector≺float≻.new
    scores << 0.9 << 0.8 << 0.85 << 0.75

    class_ids = Std::Vector≺int≻.new
    class_ids << 0 << 0 << 1 << 1

    indices = Std::Vector≺int≻.new
    Cv::Dnn.nms_boxes_batched(bboxes, scores, class_ids, 0.5, 0.4, indices)

    assert(indices.size > 0)
  end


  # Soft NMS
  def test_soft_nms_boxes
    bboxes = Std::Vector≺cv꞉꞉Rect_≺int≻≻.new
    bboxes << Cv::Rect.new(10, 10, 100, 100)
    bboxes << Cv::Rect.new(15, 15, 100, 100)
    bboxes << Cv::Rect.new(200, 200, 100, 100)

    scores = Std::Vector≺float≻.new
    scores << 0.9 << 0.8 << 0.7

    updated_scores = Std::Vector≺float≻.new
    indices = Std::Vector≺int≻.new

    Cv::Dnn.soft_nms_boxes(bboxes, scores, updated_scores, 0.5, 0.4, indices)

    assert(indices.size > 0)
    assert(updated_scores.size > 0)
  end

  def test_soft_nms_boxes_linear
    bboxes = Std::Vector≺cv꞉꞉Rect_≺int≻≻.new
    bboxes << Cv::Rect.new(10, 10, 100, 100)
    bboxes << Cv::Rect.new(20, 20, 100, 100)

    scores = Std::Vector≺float≻.new
    scores << 0.9 << 0.85

    updated_scores = Std::Vector≺float≻.new
    indices = Std::Vector≺int≻.new

    Cv::Dnn.soft_nms_boxes(bboxes, scores, updated_scores, 0.5, 0.3, indices,
                           0, 0.5, Cv::Dnn::SoftNMSMethod::SOFTNMS_LINEAR)

    assert(indices.size > 0)
  end

  def test_soft_nms_boxes_gaussian
    bboxes = Std::Vector≺cv꞉꞉Rect_≺int≻≻.new
    bboxes << Cv::Rect.new(10, 10, 100, 100)
    bboxes << Cv::Rect.new(20, 20, 100, 100)

    scores = Std::Vector≺float≻.new
    scores << 0.9 << 0.85

    updated_scores = Std::Vector≺float≻.new
    indices = Std::Vector≺int≻.new

    Cv::Dnn.soft_nms_boxes(bboxes, scores, updated_scores, 0.5, 0.3, indices,
                           0, 0.5, Cv::Dnn::SoftNMSMethod::SOFTNMS_GAUSSIAN)

    assert(indices.size > 0)
  end

  # SoftNMSMethod enum tests
  def test_soft_nms_method_linear
    assert_kind_of(Cv::Dnn::SoftNMSMethod, Cv::Dnn::SoftNMSMethod::SOFTNMS_LINEAR)
  end

  def test_soft_nms_method_gaussian
    assert_kind_of(Cv::Dnn::SoftNMSMethod, Cv::Dnn::SoftNMSMethod::SOFTNMS_GAUSSIAN)
  end

  # Empty inputs
  def test_nms_boxes_empty
    bboxes = Std::Vector≺cv꞉꞉Rect_≺int≻≻.new
    scores = Std::Vector≺float≻.new
    indices = Std::Vector≺int≻.new

    Cv::Dnn.nms_boxes(bboxes, scores, 0.5, 0.4, indices)

    assert_equal(0, indices.size)
  end

  # Network reading tests (file-based - expected to raise for non-existent files)
  def test_read_net_from_caffe_invalid
    assert_raises(StandardError) do
      Cv::Dnn.read_net_from_caffe("nonexistent.prototxt", "nonexistent.caffemodel")
    end
  end

  def test_read_net_from_tensorflow_invalid
    assert_raises(StandardError) do
      Cv::Dnn.read_net_from_tensorflow("nonexistent.pb")
    end
  end

  def test_read_net_from_onnx_invalid
    assert_raises(StandardError) do
      Cv::Dnn.read_net_from_onnx("nonexistent.onnx")
    end
  end

  def test_read_net_from_darknet_invalid
    assert_raises(StandardError) do
      Cv::Dnn.read_net_from_darknet("nonexistent.cfg", "nonexistent.weights")
    end
  end

  def test_read_net_invalid
    assert_raises(StandardError) do
      Cv::Dnn.read_net("nonexistent.model")
    end
  end

  # Utility function tests
  def test_get_available_backends
    backends = Cv::Dnn.get_available_backends
    assert(backends.size > 0)
  end

  def test_get_available_targets_opencv
    # Note this fails if you don't have Vulcan installed and a GPU
    targets = Cv::Dnn.get_available_targets(Cv::Dnn::Backend::DNN_BACKEND_OPENCV)
    assert(targets.size > 0)
  end

  def test_get_available_targets_default
    targets = Cv::Dnn.get_available_targets(Cv::Dnn::Backend::DNN_BACKEND_DEFAULT)
    assert(targets.size > 0)
  end
end
