#!/usr/bin/env ruby
#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class VideoIoTest < OpenCVTestCase
  def teardown
    super
    # We need to give time for the OS to release the camera/video
    sleep 2
  end

  def test_backend_name
    capture = Cv::VideoCapture.new(0, Cv::VideoCaptureAPIs::CAP_ANY)

    if RUBY_PLATFORM =~ /mswin/
      assert_equal("MSMF", capture.get_backend_name)
    elsif RUBY_PLATFORM =~ /mingw/
      assert_equal("DSHOW", capture::get_backend_name)
    elsif RUBY_PLATFORM =~ /darwin/
      assert_equal("AVFOUNDATION", capture::get_backend_name)
    else
      assert_equal("GSTREAMER", capture.get_backend_name)
    end
    capture.release
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

    video.release
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
    assert_equal(324, i)

    video.release
  end

  def test_grab_and_retrieve_frame
    image_path = self.sample_path("stone_pine.mp4")
    video = Cv::VideoCapture.new(image_path)
    assert(video.opened?)

    frame = Cv::Mat.new
    assert(video.grab)
    assert(video.retrieve(frame.output_array))

    video.release
  end

  def test_camera
    camera = Cv::VideoCapture.new
    camera.open(0, Cv::VideoCaptureAPIs::CAP_ANY)
    assert(camera.opened?)

    width = camera.get(Cv::VideoCaptureProperties::CAP_PROP_FRAME_WIDTH)
    assert(width > 0)

    height = camera.get(Cv::VideoCaptureProperties::CAP_PROP_FRAME_HEIGHT)
    assert(height > 0)

    camera.release
  end

  def test_read_frame
    camera = Cv::VideoCapture.new(0, Cv::VideoCaptureAPIs::CAP_ANY)
    assert(camera.opened?)

    frame = Cv::Mat.new
    camera >> frame
    refute(frame.empty?)

    show_images([frame])

    camera.release
  end

  def test_open
    camera = Cv::VideoCapture.new
    camera.open(0, Cv::VideoCaptureAPIs::CAP_ANY)
    assert(camera.opened?)

    frame = Cv::Mat.new
    camera >> frame
    refute(frame.empty?)

    show_images(frame)

    camera.release
  end

  def test_wait_any
    unless RUBY_PLATFORM =~ /mingw|mswin/
      # Wait any only work with CAP_V4L.
      camera = Cv::VideoCapture.new(0, Cv::VideoCaptureAPIs::CAP_V4L)
      assert(camera.opened?)

      streams = Std::Vector≺cv꞉꞉VideoCapture≻.new
      streams.push(camera)

      indexes = Std::Vector≺int≻.new
      indexes.push(0)

      camera.grab
      # Wait time is in nanoseconds
      wait = Cv::VideoCapture::wait_any?(streams, indexes, 1_000_000_000)
      assert(wait)

      frame = Cv::Mat.new
      result = camera.retrieve(frame.output_array)
      assert(result)

      camera.release
    end
  end
end
