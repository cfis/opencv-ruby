#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class VideoWriterTest < OpenCVTestCase
  OUTPUT_FILENAME = 'videowriter_result.avi'

  def test_initialize
    frame_size = Cv::Size.new(640, 480)
    frames_per_second = 10
    fourcc = Cv::VideoWriter.fourcc("m", "p", "4", "v")
    path = File.expand_path(File.join(__dir__, "samples", "test_initialize.mp4"))

    writer = Cv::VideoWriter.new(path, fourcc, frames_per_second, frame_size, true)
    assert(writer.opened?)
    writer.release

    assert(File.exist?(path))
    File.delete(path)
  end

  def test_capture
    camera = Cv::VideoCapture.new(0, Cv::VideoCaptureAPIs::CAP_MSMF)
    assert(camera.opened?)
    camera.release
  end

  def test_write
    camera = Cv::VideoCapture.new(0, Cv::VideoCaptureAPIs::CAP_MSMF)
    frame_width = camera.get(Cv::VideoCaptureProperties::CAP_PROP_FRAME_WIDTH)
    frame_height = camera.get(Cv::VideoCaptureProperties::CAP_PROP_FRAME_HEIGHT)
    frame_size = Cv::Size.new(frame_width.to_i, frame_height.to_i)
    frames_per_second = 10

    fourcc = Cv::VideoWriter.fourcc("m", "p", "4", "v")
    path = File.expand_path(File.join(__dir__, "test_write.mp4"))
    writer = Cv::VideoWriter.new(path, fourcc, frames_per_second, frame_size, true)
    assert(writer.opened?)

    10.times do
      frame = Cv::Mat.new
      camera >> frame
      writer.write(frame.input_array)
    end
    writer.release
    camera.release

    assert(File.exist?(path))
    File.delete(path)
  end
end
