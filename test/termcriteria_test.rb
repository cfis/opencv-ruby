#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class TermCriteriaTest < OpenCVTestCase
  def test_initialize
    criteria1 = Cv::TermCriteria.new
    refute(criteria1.valid?)
    assert_equal(0, criteria1.type)
    assert_equal(0, criteria1.max_count)
    assert_equal(0, criteria1.epsilon)

    criteria2 = Cv::TermCriteria.new(Cv::TermCriteria::Type::EPS, 1, 0.01)
    assert(criteria2.valid?)
    assert_equal(Cv::TermCriteria::Type::EPS.to_i, criteria2.type)
    assert_equal(1, criteria2.max_count)
    assert_equal(0.01, criteria2.epsilon)
  end
end
