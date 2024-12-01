#!/usr/bin/env ruby
require File.join(__dir__, 'helper')
require 'date'

class FileStorageTest < OpenCVTestCase
  def test_write
    path = File.join(Dir.tmpdir, "test.yml")
    fs = Cv::FileStorage.new(path, Cv::FileStorage::Mode::WRITE)

    fs << "frameCount" << 5
    fs << "calibrationDate" << DateTime.new(2024, 01, 27).iso8601

    buffer1 = Rice::Buffer≺double≻.new([1000, 0, 320, 0, 1000, 240, 0, 0, 1])
    camera_matrix = Cv::Mat1d.new(3, 3, buffer1)

    buffer2 = Rice::Buffer≺double≻.new([0.1, 0.01, -0.001, 0, 0])
    dist_coeffs = Cv::Mat1d.new(5, 1, buffer2)
    fs << "cameraMatrix" << camera_matrix << "distCoeffs" << dist_coeffs
    fs << "features" << "["

    3.times do |i|
      x = i
      y = i
      lbp = i

      fs << "{:" << "x" << x << "y" << y << "lbp" << "[:"
      8.times do |j|
        fs << (j & 1)
      end
      fs << "]" << "}"
    end
    fs << "]"
    fs.release

    expected = File.read(self.sample_path("file_storage.yml"))
    data = File.read(path)
    assert_equal(expected, data)
  end

  def test_read
    path = self.sample_path("file_storage.yml")
    fs = Cv::FileStorage.new(path, Cv::FileStorage::Mode::READ)

    frame_count_node = fs["frameCount"]
    assert_kind_of(Cv::FileNode, frame_count_node)
    assert_equal(Cv::FileNode::INT, frame_count_node.type)
    refute(frame_count_node.empty?)
    frame_count = frame_count_node.to_int
    assert_equal(5, frame_count)

    date_node = fs["calibrationDate"]
    assert_equal(Cv::FileNode::STRING, date_node.type)
    date = date_node.to_string
    assert_equal("2024-01-27T00:00:00+00:00", date)

    # Mat cameraMatrix, distCoeffs;
    camera_matrix_node = fs["cameraMatrix"]
    assert_equal(Cv::FileNode::MAP, camera_matrix_node.type)
    assert(camera_matrix_node.map?)
    assert_equal(["rows", "cols", "dt", "data"], camera_matrix_node.keys.to_a)

    rows_node = camera_matrix_node["rows"]
    assert_equal(Cv::FileNode::INT, rows_node.type)
    assert_equal(3, rows_node.to_int)

    cols_node = camera_matrix_node["cols"]
    assert_equal(Cv::FileNode::INT, cols_node.type)
    assert_equal(3, cols_node.to_int)

    dt_node = camera_matrix_node["dt"]
    assert_equal(Cv::FileNode::STRING, dt_node.type)
    assert_equal("d", dt_node.to_string)

    data_node = camera_matrix_node["data"]
    assert_equal(Cv::FileNode::SEQ, data_node.type)
    assert(data_node.seq?)
    assert_equal(9, data_node.size)

    element_node = data_node[0]
    assert_equal(Cv::FileNode::FLOAT, element_node.type)
    element = element_node.to_double
    assert_in_delta(1000, element)

    dist_coeffs_node = fs["distCoeffs"]
    assert_equal(Cv::FileNode::MAP, dist_coeffs_node.type)
    assert(camera_matrix_node.map?)
    assert_equal(["rows", "cols", "dt", "data"], dist_coeffs_node.keys.to_a)

    features_node = fs["features"]
    assert(features_node.seq?)
    feature_nodes = features_node.to_a
    assert_equal(3, feature_nodes.size)

    features_node.each do |feature_node|
      assert_equal(Cv::FileNode::MAP, feature_node.type)
      assert(feature_node.map?)

      x_node = feature_node["x"]
      assert_equal(Cv::FileNode::INT, x_node.type)

      y_node = feature_node["y"]
      assert_equal(Cv::FileNode::INT, y_node.type)

      lbp_node = feature_node["lbp"]
      assert_equal(Cv::FileNode::SEQ, lbp_node.type)
      values = lbp_node.map(&:to_int)
      assert(values.all? {|value| value == 0 || value == 1})
    end
  end
end
