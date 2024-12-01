#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class VideoWriterTest < OpenCVTestCase
  OUTPUT_FILENAME = 'videowriter_result.avi'

  # def test_initialize
  #   fourcc = Cv::VideoWriter.fourcc("M", "J", "P", "G")
  #   vw = Cv::VideoWriter.new(OUTPUT_FILENAME, fourcc, 15, Cv::Size.new(320, 240))
  #   assert_kind_of(Cv::VideoWriter, vw)
  #   vw.release
  # end

  def test_write_camera
    #image_path = self.sample_path("stone_pine.mp4")
    #camera = Cv::VideoCapture.new(image_path)
    camera = Cv::VideoCapture.new(0, Cv::VideoCaptureAPIs::CAP_MSMF)
    assert(camera.opened?)

    frame_width = camera.get(Cv::VideoCaptureProperties::CAP_PROP_FRAME_WIDTH)
    frame_height = camera.get(Cv::VideoCaptureProperties::CAP_PROP_FRAME_HEIGHT)

    frame_size = Cv::Size.new(frame_width.to_i, frame_height.to_i)
    frames_per_second = 10
    fourcc = Cv::VideoWriter.fourcc("m", "p", "4", "v")
    path = File.join(File.expand_path("./samples"), "test_camera.mp4")
    puts path
    path = "C:\\Source\\opencv-ruby\\samples\\test_camera.mp4"
    writer = Cv::VideoWriter.new(path, fourcc, frames_per_second, frame_size, true)
    assert(writer.opened?)

    10.times do
      frame = Cv::Mat.new
      camera >> frame
      writer.write(frame.input_array)
    end
    camera.release
    writer.release

    assert(File.exist?(path))
    File.delete(path)
  end
end
