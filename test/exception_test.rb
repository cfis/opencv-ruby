#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class ExceptionTest < OpenCVTestCase
  def test_exception
    assert_equal(Std::Exception, Cv::Exception.superclass)
    begin
      raise Cv::Exception
    rescue
      assert_equal(Cv::Exception, $!.class)
    end
  end
  
  def test_subclass
    errors = [Cv::StsBackTrace, Cv::StsError, Cv::StsInternal, Cv::StsNoMem,
              Cv::StsBadArg, Cv::StsBadFunc, Cv::StsNoConv, Cv::StsAutoTrace,
              Cv::HeaderIsNull, Cv::BadImageSize, Cv::BadOffset, Cv::BadDataPtr,
              Cv::BadStep, Cv::BadModelOrChSeq, Cv::BadNumChannels, Cv::BadNumChannel1U,
              Cv::BadDepth, Cv::BadAlphaChannel, Cv::BadOrder, Cv::BadOrigin, Cv::BadAlign,
              Cv::BadCallBack, Cv::BadTileSize, Cv::BadCOI, Cv::BadROISize, Cv::MaskIsTiled,
              Cv::StsNullPtr, Cv::StsVecLengthErr, Cv::StsFilterStructContentErr,
              Cv::StsKernelStructContentErr, Cv::StsFilterOffsetErr, Cv::StsBadSize,
              Cv::StsDivByZero, Cv::StsInplaceNotSupported, Cv::StsObjectNotFound,
              Cv::StsUnmatchedFormats, Cv::StsBadFlag, Cv::StsBadPoint, Cv::StsBadMask,
              Cv::StsUnmatchedSizes, Cv::StsUnsupportedFormat, Cv::StsOutOfRange,
              Cv::StsParseError, Cv::StsNotImplemented, Cv::StsBadMemBlock, Cv::StsAssert,
              Cv::GpuNotSupported, Cv::GpuApiCallError]

    errors.each do |exception|
      assert_equal(Cv::Exception, exception.superclass)
      begin
        raise exception
      rescue exception
        assert_equal(exception, $!.class)
      rescue
        flunk("Failed to catch #{exception}")
      end
      begin
        raise exception
      rescue Cv::Exception
        assert_equal(exception, $!.class)
      rescue
        flunk("Failed to catch #{exception}")
      end
      begin
        raise exception
      rescue
        assert_equal(exception, $!.class)
      end
    end
  end
end
