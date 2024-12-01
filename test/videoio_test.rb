#!/usr/bin/env ruby
#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class VideoIoTest < OpenCVTestCase
  def test_backend_name
    capture = Cv::VideoCapture.new(0, Cv::VideoCaptureAPIs::CAP_MSMF)
    assert_equal("MSMF", capture.get_backend_name)
  end

  def test_file_read
    image_path = self.sample_path("stone_pine.mp4")
    video = Cv::VideoCapture.new(image_path)
    assert(video.opened?)

    width = video.get(Cv::VideoCaptureProperties::CAP_PROP_FRAME_WIDTH)
    assert_equal(640.0, width)

    height = video.get(Cv::VideoCaptureProperties::CAP_PROP_FRAME_HEIGHT)
    assert_equal(360.0, height)

    frames_per_second = video.get(Cv::VideoCaptureProperties::CAP_PROP_FPS)
    assert_equal(29.97, frames_per_second)
  end

  def test_read_frames
    image_path = self.sample_path("stone_pine.mp4")
    video = Cv::VideoCapture.new(image_path)

    # Read frames
    frame = Cv::Mat.new
    i = 0
    while video.read(frame.output_array)
      i+=1
    end
    video.release
    assert_equal(324, i)
  end

  def test_grab_and_retrieve_frame
    image_path = self.sample_path("stone_pine.mp4")
    video = Cv::VideoCapture.new(image_path)
    assert(video.opened?)

    frame = Cv::Mat.new
    assert(video.grab)
    assert(video.retrieve(frame.output_array))
  end

  def test_camera
    camera = Cv::VideoCapture.new
    camera.open(0)
    assert(camera.opened?)

    width = camera.get(Cv::VideoCaptureProperties::CAP_PROP_FRAME_WIDTH)
    assert(width > 0)

    height = camera.get(Cv::VideoCaptureProperties::CAP_PROP_FRAME_HEIGHT)
    assert(height > 0)

    camera.release
  end

  def test_read_frame
    camera = Cv::VideoCapture.new(0)
    assert(camera.opened?)

    frame = Cv::Mat.new
    camera >> frame
    refute(frame.empty?)

    Cv::named_window("Video", Cv::WindowFlags::WINDOW_AUTOSIZE)
    Cv::imshow("Video", frame.input_array)
    Cv::wait_key
  end

  def test_open
    camera = Cv::VideoCapture.new
    camera.open(0)
    assert(camera.opened?)

    frame = Cv::Mat.new
    camera >> frame
    refute(frame.empty?)

    Cv::named_window("Video", Cv::WindowFlags::WINDOW_AUTOSIZE)
    Cv::imshow("Video", frame.input_array)
    Cv::wait_key
  end

  def test_wait_any
    unless RUBY_PLATFORM =~ /mingw|mswin/
      camera = Cv::VideoCapture.new(0, Cv::VideoCaptureAPIs::CAP_V4L)
      assert(camera.opened?)

      streams = Std::Vector≺cv꞉꞉VideoCapture≻.new
      streams.push(camera)

      indexes = Std::Vector≺int≻.new
      indexes.push(0)

      assert(Cv::VideoCapture::wait_any?(streams, indexes, 100))

      result = camera.retrieve(frame.output_array)
      assert(result)
    end
  end
end
