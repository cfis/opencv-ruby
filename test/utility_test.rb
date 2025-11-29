#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class UtilityTest < OpenCVTestCase
  def test_build_information
    info = Cv::get_build_information
    assert_kind_of(String, info)
    puts info
    assert(info =~ /^\s+General configuration for OpenCV #{CV_VERSION}/)
  end
end