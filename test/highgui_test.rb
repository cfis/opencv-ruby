#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class HighguiTest < OpenCVTestCase
  attr_reader :image

  def setup
    image_path = self.sample_path("starry_night.jpg")
    @image = Cv::imread(image_path, Cv::ImreadModes::IMREAD_COLOR)
    Cv::named_window("Starry", Cv::WindowFlags::WINDOW_AUTOSIZE)
  end

  def teardown
    Cv::destroy_window("Starry")
  end

  def test_ui_framework
    assert_equal("WIN32", Cv::current_ui_framework)
  end

  def test_show_image
    refute(image.empty?)
    Cv::imshow("Starry", image.input_array)
    Cv::wait_key(1000)
  end

  def test_resize
    Cv::imshow("Starry", image.input_array)
    Cv::wait_key(2000)
    Cv::resize_window("Starry", Cv::Size.new(80, 80))
    Cv::wait_key(1000)
  end

  def test_move
    Cv::imshow("Starry", image.input_array)
    Cv::wait_key(2000)
    Cv::move_window("Starry", 400, 400)
    Cv::wait_key(1000)
  end

  def test_trackbar_event
    on_trackbar_change = Proc.new do |position, user_data|
      if position > 0
        image_blurred = Cv::Mat.new
        Cv::blur(user_data.input_array, image_blurred.output_array, Cv::Size.new(position, position))
        Cv::imshow("Starry", image_blurred.input_array)
      end
    end

    Cv::create_trackbar("Trackbar", "Starry", nil, 100, on_trackbar_change, image)
    Cv::imshow("Starry", image.input_array)
    Cv::wait_key(1000)
  end

  def test_mouseevent
    on_mouse_event = Proc.new do |event, x, y, flags,user_data|
      if event == Cv::MouseEventTypes::EVENT_LBUTTONDOWN.to_i
        Cv::circle(user_data.input_output_array, Cv::Point.new(x, y), 20, Cv::Scalar.new(0, 0, 255), 3)
        Cv::imshow("Starry", user_data.input_array)
      end
    end

    Cv::imshow("Starry", image.input_array)
    Cv::set_mouse_callback("Starry", on_mouse_event, image)
    Cv::wait_key(1000)
  end
end
