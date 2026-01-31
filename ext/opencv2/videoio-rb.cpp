#include <opencv2/videoio.hpp>
#include "videoio-rb.hpp"

using namespace Rice;

void Init_Videoio()
{
  Rice::Data_Type<CvCapture> rb_cCvCapture = define_class<CvCapture>("CvCapture");

  Module rb_mCv = define_module("Cv");

  Enum<cv::VideoCaptureAPIs> rb_cCvVideoCaptureAPIs = define_enum_under<cv::VideoCaptureAPIs>("VideoCaptureAPIs", rb_mCv).
    define_value("CAP_ANY", cv::VideoCaptureAPIs::CAP_ANY).
    define_value("CAP_VFW", cv::VideoCaptureAPIs::CAP_VFW).
    define_value("CAP_V4L", cv::VideoCaptureAPIs::CAP_V4L).
    define_value("CAP_V4L2", cv::VideoCaptureAPIs::CAP_V4L2).
    define_value("CAP_FIREWIRE", cv::VideoCaptureAPIs::CAP_FIREWIRE).
    define_value("CAP_FIREWARE", cv::VideoCaptureAPIs::CAP_FIREWARE).
    define_value("CAP_IEEE1394", cv::VideoCaptureAPIs::CAP_IEEE1394).
    define_value("CAP_DC1394", cv::VideoCaptureAPIs::CAP_DC1394).
    define_value("CAP_CMU1394", cv::VideoCaptureAPIs::CAP_CMU1394).
    define_value("CAP_QT", cv::VideoCaptureAPIs::CAP_QT).
    define_value("CAP_UNICAP", cv::VideoCaptureAPIs::CAP_UNICAP).
    define_value("CAP_DSHOW", cv::VideoCaptureAPIs::CAP_DSHOW).
    define_value("CAP_PVAPI", cv::VideoCaptureAPIs::CAP_PVAPI).
    define_value("CAP_OPENNI", cv::VideoCaptureAPIs::CAP_OPENNI).
    define_value("CAP_OPENNI_ASUS", cv::VideoCaptureAPIs::CAP_OPENNI_ASUS).
    define_value("CAP_ANDROID", cv::VideoCaptureAPIs::CAP_ANDROID).
    define_value("CAP_XIAPI", cv::VideoCaptureAPIs::CAP_XIAPI).
    define_value("CAP_AVFOUNDATION", cv::VideoCaptureAPIs::CAP_AVFOUNDATION).
    define_value("CAP_GIGANETIX", cv::VideoCaptureAPIs::CAP_GIGANETIX).
    define_value("CAP_MSMF", cv::VideoCaptureAPIs::CAP_MSMF).
    define_value("CAP_WINRT", cv::VideoCaptureAPIs::CAP_WINRT).
    define_value("CAP_INTELPERC", cv::VideoCaptureAPIs::CAP_INTELPERC).
    define_value("CAP_REALSENSE", cv::VideoCaptureAPIs::CAP_REALSENSE).
    define_value("CAP_OPENNI2", cv::VideoCaptureAPIs::CAP_OPENNI2).
    define_value("CAP_OPENNI2_ASUS", cv::VideoCaptureAPIs::CAP_OPENNI2_ASUS).
    define_value("CAP_OPENNI2_ASTRA", cv::VideoCaptureAPIs::CAP_OPENNI2_ASTRA).
    define_value("CAP_GPHOTO2", cv::VideoCaptureAPIs::CAP_GPHOTO2).
    define_value("CAP_GSTREAMER", cv::VideoCaptureAPIs::CAP_GSTREAMER).
    define_value("CAP_FFMPEG", cv::VideoCaptureAPIs::CAP_FFMPEG).
    define_value("CAP_IMAGES", cv::VideoCaptureAPIs::CAP_IMAGES).
    define_value("CAP_ARAVIS", cv::VideoCaptureAPIs::CAP_ARAVIS).
    define_value("CAP_OPENCV_MJPEG", cv::VideoCaptureAPIs::CAP_OPENCV_MJPEG).
    define_value("CAP_INTEL_MFX", cv::VideoCaptureAPIs::CAP_INTEL_MFX).
    define_value("CAP_XINE", cv::VideoCaptureAPIs::CAP_XINE).
    define_value("CAP_UEYE", cv::VideoCaptureAPIs::CAP_UEYE).
    define_value("CAP_OBSENSOR", cv::VideoCaptureAPIs::CAP_OBSENSOR);

  Enum<cv::VideoCaptureProperties> rb_cCvVideoCaptureProperties = define_enum_under<cv::VideoCaptureProperties>("VideoCaptureProperties", rb_mCv).
    define_value("CAP_PROP_POS_MSEC", cv::VideoCaptureProperties::CAP_PROP_POS_MSEC).
    define_value("CAP_PROP_POS_FRAMES", cv::VideoCaptureProperties::CAP_PROP_POS_FRAMES).
    define_value("CAP_PROP_POS_AVI_RATIO", cv::VideoCaptureProperties::CAP_PROP_POS_AVI_RATIO).
    define_value("CAP_PROP_FRAME_WIDTH", cv::VideoCaptureProperties::CAP_PROP_FRAME_WIDTH).
    define_value("CAP_PROP_FRAME_HEIGHT", cv::VideoCaptureProperties::CAP_PROP_FRAME_HEIGHT).
    define_value("CAP_PROP_FPS", cv::VideoCaptureProperties::CAP_PROP_FPS).
    define_value("CAP_PROP_FOURCC", cv::VideoCaptureProperties::CAP_PROP_FOURCC).
    define_value("CAP_PROP_FRAME_COUNT", cv::VideoCaptureProperties::CAP_PROP_FRAME_COUNT).
    define_value("CAP_PROP_FORMAT", cv::VideoCaptureProperties::CAP_PROP_FORMAT).
    define_value("CAP_PROP_MODE", cv::VideoCaptureProperties::CAP_PROP_MODE).
    define_value("CAP_PROP_BRIGHTNESS", cv::VideoCaptureProperties::CAP_PROP_BRIGHTNESS).
    define_value("CAP_PROP_CONTRAST", cv::VideoCaptureProperties::CAP_PROP_CONTRAST).
    define_value("CAP_PROP_SATURATION", cv::VideoCaptureProperties::CAP_PROP_SATURATION).
    define_value("CAP_PROP_HUE", cv::VideoCaptureProperties::CAP_PROP_HUE).
    define_value("CAP_PROP_GAIN", cv::VideoCaptureProperties::CAP_PROP_GAIN).
    define_value("CAP_PROP_EXPOSURE", cv::VideoCaptureProperties::CAP_PROP_EXPOSURE).
    define_value("CAP_PROP_CONVERT_RGB", cv::VideoCaptureProperties::CAP_PROP_CONVERT_RGB).
    define_value("CAP_PROP_WHITE_BALANCE_BLUE_U", cv::VideoCaptureProperties::CAP_PROP_WHITE_BALANCE_BLUE_U).
    define_value("CAP_PROP_RECTIFICATION", cv::VideoCaptureProperties::CAP_PROP_RECTIFICATION).
    define_value("CAP_PROP_MONOCHROME", cv::VideoCaptureProperties::CAP_PROP_MONOCHROME).
    define_value("CAP_PROP_SHARPNESS", cv::VideoCaptureProperties::CAP_PROP_SHARPNESS).
    define_value("CAP_PROP_AUTO_EXPOSURE", cv::VideoCaptureProperties::CAP_PROP_AUTO_EXPOSURE).
    define_value("CAP_PROP_GAMMA", cv::VideoCaptureProperties::CAP_PROP_GAMMA).
    define_value("CAP_PROP_TEMPERATURE", cv::VideoCaptureProperties::CAP_PROP_TEMPERATURE).
    define_value("CAP_PROP_TRIGGER", cv::VideoCaptureProperties::CAP_PROP_TRIGGER).
    define_value("CAP_PROP_TRIGGER_DELAY", cv::VideoCaptureProperties::CAP_PROP_TRIGGER_DELAY).
    define_value("CAP_PROP_WHITE_BALANCE_RED_V", cv::VideoCaptureProperties::CAP_PROP_WHITE_BALANCE_RED_V).
    define_value("CAP_PROP_ZOOM", cv::VideoCaptureProperties::CAP_PROP_ZOOM).
    define_value("CAP_PROP_FOCUS", cv::VideoCaptureProperties::CAP_PROP_FOCUS).
    define_value("CAP_PROP_GUID", cv::VideoCaptureProperties::CAP_PROP_GUID).
    define_value("CAP_PROP_ISO_SPEED", cv::VideoCaptureProperties::CAP_PROP_ISO_SPEED).
    define_value("CAP_PROP_BACKLIGHT", cv::VideoCaptureProperties::CAP_PROP_BACKLIGHT).
    define_value("CAP_PROP_PAN", cv::VideoCaptureProperties::CAP_PROP_PAN).
    define_value("CAP_PROP_TILT", cv::VideoCaptureProperties::CAP_PROP_TILT).
    define_value("CAP_PROP_ROLL", cv::VideoCaptureProperties::CAP_PROP_ROLL).
    define_value("CAP_PROP_IRIS", cv::VideoCaptureProperties::CAP_PROP_IRIS).
    define_value("CAP_PROP_SETTINGS", cv::VideoCaptureProperties::CAP_PROP_SETTINGS).
    define_value("CAP_PROP_BUFFERSIZE", cv::VideoCaptureProperties::CAP_PROP_BUFFERSIZE).
    define_value("CAP_PROP_AUTOFOCUS", cv::VideoCaptureProperties::CAP_PROP_AUTOFOCUS).
    define_value("CAP_PROP_SAR_NUM", cv::VideoCaptureProperties::CAP_PROP_SAR_NUM).
    define_value("CAP_PROP_SAR_DEN", cv::VideoCaptureProperties::CAP_PROP_SAR_DEN).
    define_value("CAP_PROP_BACKEND", cv::VideoCaptureProperties::CAP_PROP_BACKEND).
    define_value("CAP_PROP_CHANNEL", cv::VideoCaptureProperties::CAP_PROP_CHANNEL).
    define_value("CAP_PROP_AUTO_WB", cv::VideoCaptureProperties::CAP_PROP_AUTO_WB).
    define_value("CAP_PROP_WB_TEMPERATURE", cv::VideoCaptureProperties::CAP_PROP_WB_TEMPERATURE).
    define_value("CAP_PROP_CODEC_PIXEL_FORMAT", cv::VideoCaptureProperties::CAP_PROP_CODEC_PIXEL_FORMAT).
    define_value("CAP_PROP_BITRATE", cv::VideoCaptureProperties::CAP_PROP_BITRATE).
    define_value("CAP_PROP_ORIENTATION_META", cv::VideoCaptureProperties::CAP_PROP_ORIENTATION_META).
    define_value("CAP_PROP_ORIENTATION_AUTO", cv::VideoCaptureProperties::CAP_PROP_ORIENTATION_AUTO).
    define_value("CAP_PROP_HW_ACCELERATION", cv::VideoCaptureProperties::CAP_PROP_HW_ACCELERATION).
    define_value("CAP_PROP_HW_DEVICE", cv::VideoCaptureProperties::CAP_PROP_HW_DEVICE).
    define_value("CAP_PROP_HW_ACCELERATION_USE_OPENCL", cv::VideoCaptureProperties::CAP_PROP_HW_ACCELERATION_USE_OPENCL).
    define_value("CAP_PROP_OPEN_TIMEOUT_MSEC", cv::VideoCaptureProperties::CAP_PROP_OPEN_TIMEOUT_MSEC).
    define_value("CAP_PROP_READ_TIMEOUT_MSEC", cv::VideoCaptureProperties::CAP_PROP_READ_TIMEOUT_MSEC).
    define_value("CAP_PROP_STREAM_OPEN_TIME_USEC", cv::VideoCaptureProperties::CAP_PROP_STREAM_OPEN_TIME_USEC).
    define_value("CAP_PROP_VIDEO_TOTAL_CHANNELS", cv::VideoCaptureProperties::CAP_PROP_VIDEO_TOTAL_CHANNELS).
    define_value("CAP_PROP_VIDEO_STREAM", cv::VideoCaptureProperties::CAP_PROP_VIDEO_STREAM).
    define_value("CAP_PROP_AUDIO_STREAM", cv::VideoCaptureProperties::CAP_PROP_AUDIO_STREAM).
    define_value("CAP_PROP_AUDIO_POS", cv::VideoCaptureProperties::CAP_PROP_AUDIO_POS).
    define_value("CAP_PROP_AUDIO_SHIFT_NSEC", cv::VideoCaptureProperties::CAP_PROP_AUDIO_SHIFT_NSEC).
    define_value("CAP_PROP_AUDIO_DATA_DEPTH", cv::VideoCaptureProperties::CAP_PROP_AUDIO_DATA_DEPTH).
    define_value("CAP_PROP_AUDIO_SAMPLES_PER_SECOND", cv::VideoCaptureProperties::CAP_PROP_AUDIO_SAMPLES_PER_SECOND).
    define_value("CAP_PROP_AUDIO_BASE_INDEX", cv::VideoCaptureProperties::CAP_PROP_AUDIO_BASE_INDEX).
    define_value("CAP_PROP_AUDIO_TOTAL_CHANNELS", cv::VideoCaptureProperties::CAP_PROP_AUDIO_TOTAL_CHANNELS).
    define_value("CAP_PROP_AUDIO_TOTAL_STREAMS", cv::VideoCaptureProperties::CAP_PROP_AUDIO_TOTAL_STREAMS).
    define_value("CAP_PROP_AUDIO_SYNCHRONIZE", cv::VideoCaptureProperties::CAP_PROP_AUDIO_SYNCHRONIZE).
    define_value("CAP_PROP_LRF_HAS_KEY_FRAME", cv::VideoCaptureProperties::CAP_PROP_LRF_HAS_KEY_FRAME).
    define_value("CAP_PROP_CODEC_EXTRADATA_INDEX", cv::VideoCaptureProperties::CAP_PROP_CODEC_EXTRADATA_INDEX).
    define_value("CAP_PROP_FRAME_TYPE", cv::VideoCaptureProperties::CAP_PROP_FRAME_TYPE).
    define_value("CAP_PROP_N_THREADS", cv::VideoCaptureProperties::CAP_PROP_N_THREADS).
    define_value("CAP_PROP_PTS", cv::VideoCaptureProperties::CAP_PROP_PTS).
    define_value("CAP_PROP_DTS_DELAY", cv::VideoCaptureProperties::CAP_PROP_DTS_DELAY).
    define_value("CV__CAP_PROP_LATEST", cv::VideoCaptureProperties::CV__CAP_PROP_LATEST);

  Enum<cv::VideoWriterProperties> rb_cCvVideoWriterProperties = define_enum_under<cv::VideoWriterProperties>("VideoWriterProperties", rb_mCv).
    define_value("VIDEOWRITER_PROP_QUALITY", cv::VideoWriterProperties::VIDEOWRITER_PROP_QUALITY).
    define_value("VIDEOWRITER_PROP_FRAMEBYTES", cv::VideoWriterProperties::VIDEOWRITER_PROP_FRAMEBYTES).
    define_value("VIDEOWRITER_PROP_NSTRIPES", cv::VideoWriterProperties::VIDEOWRITER_PROP_NSTRIPES).
    define_value("VIDEOWRITER_PROP_IS_COLOR", cv::VideoWriterProperties::VIDEOWRITER_PROP_IS_COLOR).
    define_value("VIDEOWRITER_PROP_DEPTH", cv::VideoWriterProperties::VIDEOWRITER_PROP_DEPTH).
    define_value("VIDEOWRITER_PROP_HW_ACCELERATION", cv::VideoWriterProperties::VIDEOWRITER_PROP_HW_ACCELERATION).
    define_value("VIDEOWRITER_PROP_HW_DEVICE", cv::VideoWriterProperties::VIDEOWRITER_PROP_HW_DEVICE).
    define_value("VIDEOWRITER_PROP_HW_ACCELERATION_USE_OPENCL", cv::VideoWriterProperties::VIDEOWRITER_PROP_HW_ACCELERATION_USE_OPENCL).
    define_value("VIDEOWRITER_PROP_RAW_VIDEO", cv::VideoWriterProperties::VIDEOWRITER_PROP_RAW_VIDEO).
    define_value("VIDEOWRITER_PROP_KEY_INTERVAL", cv::VideoWriterProperties::VIDEOWRITER_PROP_KEY_INTERVAL).
    define_value("VIDEOWRITER_PROP_KEY_FLAG", cv::VideoWriterProperties::VIDEOWRITER_PROP_KEY_FLAG).
    define_value("VIDEOWRITER_PROP_PTS", cv::VideoWriterProperties::VIDEOWRITER_PROP_PTS).
    define_value("VIDEOWRITER_PROP_DTS_DELAY", cv::VideoWriterProperties::VIDEOWRITER_PROP_DTS_DELAY).
    define_value("CV__VIDEOWRITER_PROP_LATEST", cv::VideoWriterProperties::CV__VIDEOWRITER_PROP_LATEST);

  Enum<cv::VideoAccelerationType> rb_cCvVideoAccelerationType = define_enum_under<cv::VideoAccelerationType>("VideoAccelerationType", rb_mCv).
    define_value("VIDEO_ACCELERATION_NONE", cv::VideoAccelerationType::VIDEO_ACCELERATION_NONE).
    define_value("VIDEO_ACCELERATION_ANY", cv::VideoAccelerationType::VIDEO_ACCELERATION_ANY).
    define_value("VIDEO_ACCELERATION_D3D11", cv::VideoAccelerationType::VIDEO_ACCELERATION_D3D11).
    define_value("VIDEO_ACCELERATION_VAAPI", cv::VideoAccelerationType::VIDEO_ACCELERATION_VAAPI).
    define_value("VIDEO_ACCELERATION_MFX", cv::VideoAccelerationType::VIDEO_ACCELERATION_MFX);

  rb_mCv.define_constant("CAP_PROP_DC1394_OFF", (int)cv::CAP_PROP_DC1394_OFF);
  rb_mCv.define_constant("CAP_PROP_DC1394_MODE_MANUAL", (int)cv::CAP_PROP_DC1394_MODE_MANUAL);
  rb_mCv.define_constant("CAP_PROP_DC1394_MODE_AUTO", (int)cv::CAP_PROP_DC1394_MODE_AUTO);
  rb_mCv.define_constant("CAP_PROP_DC1394_MODE_ONE_PUSH_AUTO", (int)cv::CAP_PROP_DC1394_MODE_ONE_PUSH_AUTO);
  rb_mCv.define_constant("CAP_PROP_DC1394_MAX", (int)cv::CAP_PROP_DC1394_MAX);

  rb_mCv.define_constant("CAP_OPENNI_DEPTH_GENERATOR", (int)cv::CAP_OPENNI_DEPTH_GENERATOR);
  rb_mCv.define_constant("CAP_OPENNI_IMAGE_GENERATOR", (int)cv::CAP_OPENNI_IMAGE_GENERATOR);
  rb_mCv.define_constant("CAP_OPENNI_IR_GENERATOR", (int)cv::CAP_OPENNI_IR_GENERATOR);
  rb_mCv.define_constant("CAP_OPENNI_GENERATORS_MASK", (int)cv::CAP_OPENNI_GENERATORS_MASK);

  rb_mCv.define_constant("CAP_PROP_OPENNI_OUTPUT_MODE", (int)cv::CAP_PROP_OPENNI_OUTPUT_MODE);
  rb_mCv.define_constant("CAP_PROP_OPENNI_FRAME_MAX_DEPTH", (int)cv::CAP_PROP_OPENNI_FRAME_MAX_DEPTH);
  rb_mCv.define_constant("CAP_PROP_OPENNI_BASELINE", (int)cv::CAP_PROP_OPENNI_BASELINE);
  rb_mCv.define_constant("CAP_PROP_OPENNI_FOCAL_LENGTH", (int)cv::CAP_PROP_OPENNI_FOCAL_LENGTH);
  rb_mCv.define_constant("CAP_PROP_OPENNI_REGISTRATION", (int)cv::CAP_PROP_OPENNI_REGISTRATION);
  rb_mCv.define_constant("CAP_PROP_OPENNI_REGISTRATION_ON", (int)cv::CAP_PROP_OPENNI_REGISTRATION_ON);
  rb_mCv.define_constant("CAP_PROP_OPENNI_APPROX_FRAME_SYNC", (int)cv::CAP_PROP_OPENNI_APPROX_FRAME_SYNC);
  rb_mCv.define_constant("CAP_PROP_OPENNI_MAX_BUFFER_SIZE", (int)cv::CAP_PROP_OPENNI_MAX_BUFFER_SIZE);
  rb_mCv.define_constant("CAP_PROP_OPENNI_CIRCLE_BUFFER", (int)cv::CAP_PROP_OPENNI_CIRCLE_BUFFER);
  rb_mCv.define_constant("CAP_PROP_OPENNI_MAX_TIME_DURATION", (int)cv::CAP_PROP_OPENNI_MAX_TIME_DURATION);
  rb_mCv.define_constant("CAP_PROP_OPENNI_GENERATOR_PRESENT", (int)cv::CAP_PROP_OPENNI_GENERATOR_PRESENT);
  rb_mCv.define_constant("CAP_PROP_OPENNI2_SYNC", (int)cv::CAP_PROP_OPENNI2_SYNC);
  rb_mCv.define_constant("CAP_PROP_OPENNI2_MIRROR", (int)cv::CAP_PROP_OPENNI2_MIRROR);

  rb_mCv.define_constant("CAP_OPENNI_IMAGE_GENERATOR_PRESENT", (int)cv::CAP_OPENNI_IMAGE_GENERATOR_PRESENT);
  rb_mCv.define_constant("CAP_OPENNI_IMAGE_GENERATOR_OUTPUT_MODE", (int)cv::CAP_OPENNI_IMAGE_GENERATOR_OUTPUT_MODE);
  rb_mCv.define_constant("CAP_OPENNI_DEPTH_GENERATOR_PRESENT", (int)cv::CAP_OPENNI_DEPTH_GENERATOR_PRESENT);
  rb_mCv.define_constant("CAP_OPENNI_DEPTH_GENERATOR_BASELINE", (int)cv::CAP_OPENNI_DEPTH_GENERATOR_BASELINE);
  rb_mCv.define_constant("CAP_OPENNI_DEPTH_GENERATOR_FOCAL_LENGTH", (int)cv::CAP_OPENNI_DEPTH_GENERATOR_FOCAL_LENGTH);
  rb_mCv.define_constant("CAP_OPENNI_DEPTH_GENERATOR_REGISTRATION", (int)cv::CAP_OPENNI_DEPTH_GENERATOR_REGISTRATION);
  rb_mCv.define_constant("CAP_OPENNI_DEPTH_GENERATOR_REGISTRATION_ON", (int)cv::CAP_OPENNI_DEPTH_GENERATOR_REGISTRATION_ON);
  rb_mCv.define_constant("CAP_OPENNI_IR_GENERATOR_PRESENT", (int)cv::CAP_OPENNI_IR_GENERATOR_PRESENT);

  rb_mCv.define_constant("CAP_OPENNI_DEPTH_MAP", (int)cv::CAP_OPENNI_DEPTH_MAP);
  rb_mCv.define_constant("CAP_OPENNI_POINT_CLOUD_MAP", (int)cv::CAP_OPENNI_POINT_CLOUD_MAP);
  rb_mCv.define_constant("CAP_OPENNI_DISPARITY_MAP", (int)cv::CAP_OPENNI_DISPARITY_MAP);
  rb_mCv.define_constant("CAP_OPENNI_DISPARITY_MAP_32F", (int)cv::CAP_OPENNI_DISPARITY_MAP_32F);
  rb_mCv.define_constant("CAP_OPENNI_VALID_DEPTH_MASK", (int)cv::CAP_OPENNI_VALID_DEPTH_MASK);
  rb_mCv.define_constant("CAP_OPENNI_BGR_IMAGE", (int)cv::CAP_OPENNI_BGR_IMAGE);
  rb_mCv.define_constant("CAP_OPENNI_GRAY_IMAGE", (int)cv::CAP_OPENNI_GRAY_IMAGE);
  rb_mCv.define_constant("CAP_OPENNI_IR_IMAGE", (int)cv::CAP_OPENNI_IR_IMAGE);

  rb_mCv.define_constant("CAP_OPENNI_VGA_30HZ", (int)cv::CAP_OPENNI_VGA_30HZ);
  rb_mCv.define_constant("CAP_OPENNI_SXGA_15HZ", (int)cv::CAP_OPENNI_SXGA_15HZ);
  rb_mCv.define_constant("CAP_OPENNI_SXGA_30HZ", (int)cv::CAP_OPENNI_SXGA_30HZ);
  rb_mCv.define_constant("CAP_OPENNI_QVGA_30HZ", (int)cv::CAP_OPENNI_QVGA_30HZ);
  rb_mCv.define_constant("CAP_OPENNI_QVGA_60HZ", (int)cv::CAP_OPENNI_QVGA_60HZ);

  rb_mCv.define_constant("CAP_PROP_GSTREAMER_QUEUE_LENGTH", (int)cv::CAP_PROP_GSTREAMER_QUEUE_LENGTH);

  rb_mCv.define_constant("CAP_PROP_PVAPI_MULTICASTIP", (int)cv::CAP_PROP_PVAPI_MULTICASTIP);
  rb_mCv.define_constant("CAP_PROP_PVAPI_FRAMESTARTTRIGGERMODE", (int)cv::CAP_PROP_PVAPI_FRAMESTARTTRIGGERMODE);
  rb_mCv.define_constant("CAP_PROP_PVAPI_DECIMATIONHORIZONTAL", (int)cv::CAP_PROP_PVAPI_DECIMATIONHORIZONTAL);
  rb_mCv.define_constant("CAP_PROP_PVAPI_DECIMATIONVERTICAL", (int)cv::CAP_PROP_PVAPI_DECIMATIONVERTICAL);
  rb_mCv.define_constant("CAP_PROP_PVAPI_BINNINGX", (int)cv::CAP_PROP_PVAPI_BINNINGX);
  rb_mCv.define_constant("CAP_PROP_PVAPI_BINNINGY", (int)cv::CAP_PROP_PVAPI_BINNINGY);
  rb_mCv.define_constant("CAP_PROP_PVAPI_PIXELFORMAT", (int)cv::CAP_PROP_PVAPI_PIXELFORMAT);

  rb_mCv.define_constant("CAP_PVAPI_FSTRIGMODE_FREERUN", (int)cv::CAP_PVAPI_FSTRIGMODE_FREERUN);
  rb_mCv.define_constant("CAP_PVAPI_FSTRIGMODE_SYNCIN1", (int)cv::CAP_PVAPI_FSTRIGMODE_SYNCIN1);
  rb_mCv.define_constant("CAP_PVAPI_FSTRIGMODE_SYNCIN2", (int)cv::CAP_PVAPI_FSTRIGMODE_SYNCIN2);
  rb_mCv.define_constant("CAP_PVAPI_FSTRIGMODE_FIXEDRATE", (int)cv::CAP_PVAPI_FSTRIGMODE_FIXEDRATE);
  rb_mCv.define_constant("CAP_PVAPI_FSTRIGMODE_SOFTWARE", (int)cv::CAP_PVAPI_FSTRIGMODE_SOFTWARE);

  rb_mCv.define_constant("CAP_PVAPI_DECIMATION_OFF", (int)cv::CAP_PVAPI_DECIMATION_OFF);
  rb_mCv.define_constant("CAP_PVAPI_DECIMATION_2OUTOF4", (int)cv::CAP_PVAPI_DECIMATION_2OUTOF4);
  rb_mCv.define_constant("CAP_PVAPI_DECIMATION_2OUTOF8", (int)cv::CAP_PVAPI_DECIMATION_2OUTOF8);
  rb_mCv.define_constant("CAP_PVAPI_DECIMATION_2OUTOF16", (int)cv::CAP_PVAPI_DECIMATION_2OUTOF16);

  rb_mCv.define_constant("CAP_PVAPI_PIXELFORMAT_MONO8", (int)cv::CAP_PVAPI_PIXELFORMAT_MONO8);
  rb_mCv.define_constant("CAP_PVAPI_PIXELFORMAT_MONO16", (int)cv::CAP_PVAPI_PIXELFORMAT_MONO16);
  rb_mCv.define_constant("CAP_PVAPI_PIXELFORMAT_BAYER8", (int)cv::CAP_PVAPI_PIXELFORMAT_BAYER8);
  rb_mCv.define_constant("CAP_PVAPI_PIXELFORMAT_BAYER16", (int)cv::CAP_PVAPI_PIXELFORMAT_BAYER16);
  rb_mCv.define_constant("CAP_PVAPI_PIXELFORMAT_RGB24", (int)cv::CAP_PVAPI_PIXELFORMAT_RGB24);
  rb_mCv.define_constant("CAP_PVAPI_PIXELFORMAT_BGR24", (int)cv::CAP_PVAPI_PIXELFORMAT_BGR24);
  rb_mCv.define_constant("CAP_PVAPI_PIXELFORMAT_RGBA32", (int)cv::CAP_PVAPI_PIXELFORMAT_RGBA32);
  rb_mCv.define_constant("CAP_PVAPI_PIXELFORMAT_BGRA32", (int)cv::CAP_PVAPI_PIXELFORMAT_BGRA32);

  rb_mCv.define_constant("CAP_PROP_XI_DOWNSAMPLING", (int)cv::CAP_PROP_XI_DOWNSAMPLING);
  rb_mCv.define_constant("CAP_PROP_XI_DATA_FORMAT", (int)cv::CAP_PROP_XI_DATA_FORMAT);
  rb_mCv.define_constant("CAP_PROP_XI_OFFSET_X", (int)cv::CAP_PROP_XI_OFFSET_X);
  rb_mCv.define_constant("CAP_PROP_XI_OFFSET_Y", (int)cv::CAP_PROP_XI_OFFSET_Y);
  rb_mCv.define_constant("CAP_PROP_XI_TRG_SOURCE", (int)cv::CAP_PROP_XI_TRG_SOURCE);
  rb_mCv.define_constant("CAP_PROP_XI_TRG_SOFTWARE", (int)cv::CAP_PROP_XI_TRG_SOFTWARE);
  rb_mCv.define_constant("CAP_PROP_XI_GPI_SELECTOR", (int)cv::CAP_PROP_XI_GPI_SELECTOR);
  rb_mCv.define_constant("CAP_PROP_XI_GPI_MODE", (int)cv::CAP_PROP_XI_GPI_MODE);
  rb_mCv.define_constant("CAP_PROP_XI_GPI_LEVEL", (int)cv::CAP_PROP_XI_GPI_LEVEL);
  rb_mCv.define_constant("CAP_PROP_XI_GPO_SELECTOR", (int)cv::CAP_PROP_XI_GPO_SELECTOR);
  rb_mCv.define_constant("CAP_PROP_XI_GPO_MODE", (int)cv::CAP_PROP_XI_GPO_MODE);
  rb_mCv.define_constant("CAP_PROP_XI_LED_SELECTOR", (int)cv::CAP_PROP_XI_LED_SELECTOR);
  rb_mCv.define_constant("CAP_PROP_XI_LED_MODE", (int)cv::CAP_PROP_XI_LED_MODE);
  rb_mCv.define_constant("CAP_PROP_XI_MANUAL_WB", (int)cv::CAP_PROP_XI_MANUAL_WB);
  rb_mCv.define_constant("CAP_PROP_XI_AUTO_WB", (int)cv::CAP_PROP_XI_AUTO_WB);
  rb_mCv.define_constant("CAP_PROP_XI_AEAG", (int)cv::CAP_PROP_XI_AEAG);
  rb_mCv.define_constant("CAP_PROP_XI_EXP_PRIORITY", (int)cv::CAP_PROP_XI_EXP_PRIORITY);
  rb_mCv.define_constant("CAP_PROP_XI_AE_MAX_LIMIT", (int)cv::CAP_PROP_XI_AE_MAX_LIMIT);
  rb_mCv.define_constant("CAP_PROP_XI_AG_MAX_LIMIT", (int)cv::CAP_PROP_XI_AG_MAX_LIMIT);
  rb_mCv.define_constant("CAP_PROP_XI_AEAG_LEVEL", (int)cv::CAP_PROP_XI_AEAG_LEVEL);
  rb_mCv.define_constant("CAP_PROP_XI_TIMEOUT", (int)cv::CAP_PROP_XI_TIMEOUT);
  rb_mCv.define_constant("CAP_PROP_XI_EXPOSURE", (int)cv::CAP_PROP_XI_EXPOSURE);
  rb_mCv.define_constant("CAP_PROP_XI_EXPOSURE_BURST_COUNT", (int)cv::CAP_PROP_XI_EXPOSURE_BURST_COUNT);
  rb_mCv.define_constant("CAP_PROP_XI_GAIN_SELECTOR", (int)cv::CAP_PROP_XI_GAIN_SELECTOR);
  rb_mCv.define_constant("CAP_PROP_XI_GAIN", (int)cv::CAP_PROP_XI_GAIN);
  rb_mCv.define_constant("CAP_PROP_XI_DOWNSAMPLING_TYPE", (int)cv::CAP_PROP_XI_DOWNSAMPLING_TYPE);
  rb_mCv.define_constant("CAP_PROP_XI_BINNING_SELECTOR", (int)cv::CAP_PROP_XI_BINNING_SELECTOR);
  rb_mCv.define_constant("CAP_PROP_XI_BINNING_VERTICAL", (int)cv::CAP_PROP_XI_BINNING_VERTICAL);
  rb_mCv.define_constant("CAP_PROP_XI_BINNING_HORIZONTAL", (int)cv::CAP_PROP_XI_BINNING_HORIZONTAL);
  rb_mCv.define_constant("CAP_PROP_XI_BINNING_PATTERN", (int)cv::CAP_PROP_XI_BINNING_PATTERN);
  rb_mCv.define_constant("CAP_PROP_XI_DECIMATION_SELECTOR", (int)cv::CAP_PROP_XI_DECIMATION_SELECTOR);
  rb_mCv.define_constant("CAP_PROP_XI_DECIMATION_VERTICAL", (int)cv::CAP_PROP_XI_DECIMATION_VERTICAL);
  rb_mCv.define_constant("CAP_PROP_XI_DECIMATION_HORIZONTAL", (int)cv::CAP_PROP_XI_DECIMATION_HORIZONTAL);
  rb_mCv.define_constant("CAP_PROP_XI_DECIMATION_PATTERN", (int)cv::CAP_PROP_XI_DECIMATION_PATTERN);
  rb_mCv.define_constant("CAP_PROP_XI_TEST_PATTERN_GENERATOR_SELECTOR", (int)cv::CAP_PROP_XI_TEST_PATTERN_GENERATOR_SELECTOR);
  rb_mCv.define_constant("CAP_PROP_XI_TEST_PATTERN", (int)cv::CAP_PROP_XI_TEST_PATTERN);
  rb_mCv.define_constant("CAP_PROP_XI_IMAGE_DATA_FORMAT", (int)cv::CAP_PROP_XI_IMAGE_DATA_FORMAT);
  rb_mCv.define_constant("CAP_PROP_XI_SHUTTER_TYPE", (int)cv::CAP_PROP_XI_SHUTTER_TYPE);
  rb_mCv.define_constant("CAP_PROP_XI_SENSOR_TAPS", (int)cv::CAP_PROP_XI_SENSOR_TAPS);
  rb_mCv.define_constant("CAP_PROP_XI_AEAG_ROI_OFFSET_X", (int)cv::CAP_PROP_XI_AEAG_ROI_OFFSET_X);
  rb_mCv.define_constant("CAP_PROP_XI_AEAG_ROI_OFFSET_Y", (int)cv::CAP_PROP_XI_AEAG_ROI_OFFSET_Y);
  rb_mCv.define_constant("CAP_PROP_XI_AEAG_ROI_WIDTH", (int)cv::CAP_PROP_XI_AEAG_ROI_WIDTH);
  rb_mCv.define_constant("CAP_PROP_XI_AEAG_ROI_HEIGHT", (int)cv::CAP_PROP_XI_AEAG_ROI_HEIGHT);
  rb_mCv.define_constant("CAP_PROP_XI_BPC", (int)cv::CAP_PROP_XI_BPC);
  rb_mCv.define_constant("CAP_PROP_XI_WB_KR", (int)cv::CAP_PROP_XI_WB_KR);
  rb_mCv.define_constant("CAP_PROP_XI_WB_KG", (int)cv::CAP_PROP_XI_WB_KG);
  rb_mCv.define_constant("CAP_PROP_XI_WB_KB", (int)cv::CAP_PROP_XI_WB_KB);
  rb_mCv.define_constant("CAP_PROP_XI_WIDTH", (int)cv::CAP_PROP_XI_WIDTH);
  rb_mCv.define_constant("CAP_PROP_XI_HEIGHT", (int)cv::CAP_PROP_XI_HEIGHT);
  rb_mCv.define_constant("CAP_PROP_XI_REGION_SELECTOR", (int)cv::CAP_PROP_XI_REGION_SELECTOR);
  rb_mCv.define_constant("CAP_PROP_XI_REGION_MODE", (int)cv::CAP_PROP_XI_REGION_MODE);
  rb_mCv.define_constant("CAP_PROP_XI_LIMIT_BANDWIDTH", (int)cv::CAP_PROP_XI_LIMIT_BANDWIDTH);
  rb_mCv.define_constant("CAP_PROP_XI_SENSOR_DATA_BIT_DEPTH", (int)cv::CAP_PROP_XI_SENSOR_DATA_BIT_DEPTH);
  rb_mCv.define_constant("CAP_PROP_XI_OUTPUT_DATA_BIT_DEPTH", (int)cv::CAP_PROP_XI_OUTPUT_DATA_BIT_DEPTH);
  rb_mCv.define_constant("CAP_PROP_XI_IMAGE_DATA_BIT_DEPTH", (int)cv::CAP_PROP_XI_IMAGE_DATA_BIT_DEPTH);
  rb_mCv.define_constant("CAP_PROP_XI_OUTPUT_DATA_PACKING", (int)cv::CAP_PROP_XI_OUTPUT_DATA_PACKING);
  rb_mCv.define_constant("CAP_PROP_XI_OUTPUT_DATA_PACKING_TYPE", (int)cv::CAP_PROP_XI_OUTPUT_DATA_PACKING_TYPE);
  rb_mCv.define_constant("CAP_PROP_XI_IS_COOLED", (int)cv::CAP_PROP_XI_IS_COOLED);
  rb_mCv.define_constant("CAP_PROP_XI_COOLING", (int)cv::CAP_PROP_XI_COOLING);
  rb_mCv.define_constant("CAP_PROP_XI_TARGET_TEMP", (int)cv::CAP_PROP_XI_TARGET_TEMP);
  rb_mCv.define_constant("CAP_PROP_XI_CHIP_TEMP", (int)cv::CAP_PROP_XI_CHIP_TEMP);
  rb_mCv.define_constant("CAP_PROP_XI_HOUS_TEMP", (int)cv::CAP_PROP_XI_HOUS_TEMP);
  rb_mCv.define_constant("CAP_PROP_XI_HOUS_BACK_SIDE_TEMP", (int)cv::CAP_PROP_XI_HOUS_BACK_SIDE_TEMP);
  rb_mCv.define_constant("CAP_PROP_XI_SENSOR_BOARD_TEMP", (int)cv::CAP_PROP_XI_SENSOR_BOARD_TEMP);
  rb_mCv.define_constant("CAP_PROP_XI_CMS", (int)cv::CAP_PROP_XI_CMS);
  rb_mCv.define_constant("CAP_PROP_XI_APPLY_CMS", (int)cv::CAP_PROP_XI_APPLY_CMS);
  rb_mCv.define_constant("CAP_PROP_XI_IMAGE_IS_COLOR", (int)cv::CAP_PROP_XI_IMAGE_IS_COLOR);
  rb_mCv.define_constant("CAP_PROP_XI_COLOR_FILTER_ARRAY", (int)cv::CAP_PROP_XI_COLOR_FILTER_ARRAY);
  rb_mCv.define_constant("CAP_PROP_XI_GAMMAY", (int)cv::CAP_PROP_XI_GAMMAY);
  rb_mCv.define_constant("CAP_PROP_XI_GAMMAC", (int)cv::CAP_PROP_XI_GAMMAC);
  rb_mCv.define_constant("CAP_PROP_XI_SHARPNESS", (int)cv::CAP_PROP_XI_SHARPNESS);
  rb_mCv.define_constant("CAP_PROP_XI_CC_MATRIX_00", (int)cv::CAP_PROP_XI_CC_MATRIX_00);
  rb_mCv.define_constant("CAP_PROP_XI_CC_MATRIX_01", (int)cv::CAP_PROP_XI_CC_MATRIX_01);
  rb_mCv.define_constant("CAP_PROP_XI_CC_MATRIX_02", (int)cv::CAP_PROP_XI_CC_MATRIX_02);
  rb_mCv.define_constant("CAP_PROP_XI_CC_MATRIX_03", (int)cv::CAP_PROP_XI_CC_MATRIX_03);
  rb_mCv.define_constant("CAP_PROP_XI_CC_MATRIX_10", (int)cv::CAP_PROP_XI_CC_MATRIX_10);
  rb_mCv.define_constant("CAP_PROP_XI_CC_MATRIX_11", (int)cv::CAP_PROP_XI_CC_MATRIX_11);
  rb_mCv.define_constant("CAP_PROP_XI_CC_MATRIX_12", (int)cv::CAP_PROP_XI_CC_MATRIX_12);
  rb_mCv.define_constant("CAP_PROP_XI_CC_MATRIX_13", (int)cv::CAP_PROP_XI_CC_MATRIX_13);
  rb_mCv.define_constant("CAP_PROP_XI_CC_MATRIX_20", (int)cv::CAP_PROP_XI_CC_MATRIX_20);
  rb_mCv.define_constant("CAP_PROP_XI_CC_MATRIX_21", (int)cv::CAP_PROP_XI_CC_MATRIX_21);
  rb_mCv.define_constant("CAP_PROP_XI_CC_MATRIX_22", (int)cv::CAP_PROP_XI_CC_MATRIX_22);
  rb_mCv.define_constant("CAP_PROP_XI_CC_MATRIX_23", (int)cv::CAP_PROP_XI_CC_MATRIX_23);
  rb_mCv.define_constant("CAP_PROP_XI_CC_MATRIX_30", (int)cv::CAP_PROP_XI_CC_MATRIX_30);
  rb_mCv.define_constant("CAP_PROP_XI_CC_MATRIX_31", (int)cv::CAP_PROP_XI_CC_MATRIX_31);
  rb_mCv.define_constant("CAP_PROP_XI_CC_MATRIX_32", (int)cv::CAP_PROP_XI_CC_MATRIX_32);
  rb_mCv.define_constant("CAP_PROP_XI_CC_MATRIX_33", (int)cv::CAP_PROP_XI_CC_MATRIX_33);
  rb_mCv.define_constant("CAP_PROP_XI_DEFAULT_CC_MATRIX", (int)cv::CAP_PROP_XI_DEFAULT_CC_MATRIX);
  rb_mCv.define_constant("CAP_PROP_XI_TRG_SELECTOR", (int)cv::CAP_PROP_XI_TRG_SELECTOR);
  rb_mCv.define_constant("CAP_PROP_XI_ACQ_FRAME_BURST_COUNT", (int)cv::CAP_PROP_XI_ACQ_FRAME_BURST_COUNT);
  rb_mCv.define_constant("CAP_PROP_XI_DEBOUNCE_EN", (int)cv::CAP_PROP_XI_DEBOUNCE_EN);
  rb_mCv.define_constant("CAP_PROP_XI_DEBOUNCE_T0", (int)cv::CAP_PROP_XI_DEBOUNCE_T0);
  rb_mCv.define_constant("CAP_PROP_XI_DEBOUNCE_T1", (int)cv::CAP_PROP_XI_DEBOUNCE_T1);
  rb_mCv.define_constant("CAP_PROP_XI_DEBOUNCE_POL", (int)cv::CAP_PROP_XI_DEBOUNCE_POL);
  rb_mCv.define_constant("CAP_PROP_XI_LENS_MODE", (int)cv::CAP_PROP_XI_LENS_MODE);
  rb_mCv.define_constant("CAP_PROP_XI_LENS_APERTURE_VALUE", (int)cv::CAP_PROP_XI_LENS_APERTURE_VALUE);
  rb_mCv.define_constant("CAP_PROP_XI_LENS_FOCUS_MOVEMENT_VALUE", (int)cv::CAP_PROP_XI_LENS_FOCUS_MOVEMENT_VALUE);
  rb_mCv.define_constant("CAP_PROP_XI_LENS_FOCUS_MOVE", (int)cv::CAP_PROP_XI_LENS_FOCUS_MOVE);
  rb_mCv.define_constant("CAP_PROP_XI_LENS_FOCUS_DISTANCE", (int)cv::CAP_PROP_XI_LENS_FOCUS_DISTANCE);
  rb_mCv.define_constant("CAP_PROP_XI_LENS_FOCAL_LENGTH", (int)cv::CAP_PROP_XI_LENS_FOCAL_LENGTH);
  rb_mCv.define_constant("CAP_PROP_XI_LENS_FEATURE_SELECTOR", (int)cv::CAP_PROP_XI_LENS_FEATURE_SELECTOR);
  rb_mCv.define_constant("CAP_PROP_XI_LENS_FEATURE", (int)cv::CAP_PROP_XI_LENS_FEATURE);
  rb_mCv.define_constant("CAP_PROP_XI_DEVICE_MODEL_ID", (int)cv::CAP_PROP_XI_DEVICE_MODEL_ID);
  rb_mCv.define_constant("CAP_PROP_XI_DEVICE_SN", (int)cv::CAP_PROP_XI_DEVICE_SN);
  rb_mCv.define_constant("CAP_PROP_XI_IMAGE_DATA_FORMAT_RGB32_ALPHA", (int)cv::CAP_PROP_XI_IMAGE_DATA_FORMAT_RGB32_ALPHA);
  rb_mCv.define_constant("CAP_PROP_XI_IMAGE_PAYLOAD_SIZE", (int)cv::CAP_PROP_XI_IMAGE_PAYLOAD_SIZE);
  rb_mCv.define_constant("CAP_PROP_XI_TRANSPORT_PIXEL_FORMAT", (int)cv::CAP_PROP_XI_TRANSPORT_PIXEL_FORMAT);
  rb_mCv.define_constant("CAP_PROP_XI_SENSOR_CLOCK_FREQ_HZ", (int)cv::CAP_PROP_XI_SENSOR_CLOCK_FREQ_HZ);
  rb_mCv.define_constant("CAP_PROP_XI_SENSOR_CLOCK_FREQ_INDEX", (int)cv::CAP_PROP_XI_SENSOR_CLOCK_FREQ_INDEX);
  rb_mCv.define_constant("CAP_PROP_XI_SENSOR_OUTPUT_CHANNEL_COUNT", (int)cv::CAP_PROP_XI_SENSOR_OUTPUT_CHANNEL_COUNT);
  rb_mCv.define_constant("CAP_PROP_XI_FRAMERATE", (int)cv::CAP_PROP_XI_FRAMERATE);
  rb_mCv.define_constant("CAP_PROP_XI_COUNTER_SELECTOR", (int)cv::CAP_PROP_XI_COUNTER_SELECTOR);
  rb_mCv.define_constant("CAP_PROP_XI_COUNTER_VALUE", (int)cv::CAP_PROP_XI_COUNTER_VALUE);
  rb_mCv.define_constant("CAP_PROP_XI_ACQ_TIMING_MODE", (int)cv::CAP_PROP_XI_ACQ_TIMING_MODE);
  rb_mCv.define_constant("CAP_PROP_XI_AVAILABLE_BANDWIDTH", (int)cv::CAP_PROP_XI_AVAILABLE_BANDWIDTH);
  rb_mCv.define_constant("CAP_PROP_XI_BUFFER_POLICY", (int)cv::CAP_PROP_XI_BUFFER_POLICY);
  rb_mCv.define_constant("CAP_PROP_XI_LUT_EN", (int)cv::CAP_PROP_XI_LUT_EN);
  rb_mCv.define_constant("CAP_PROP_XI_LUT_INDEX", (int)cv::CAP_PROP_XI_LUT_INDEX);
  rb_mCv.define_constant("CAP_PROP_XI_LUT_VALUE", (int)cv::CAP_PROP_XI_LUT_VALUE);
  rb_mCv.define_constant("CAP_PROP_XI_TRG_DELAY", (int)cv::CAP_PROP_XI_TRG_DELAY);
  rb_mCv.define_constant("CAP_PROP_XI_TS_RST_MODE", (int)cv::CAP_PROP_XI_TS_RST_MODE);
  rb_mCv.define_constant("CAP_PROP_XI_TS_RST_SOURCE", (int)cv::CAP_PROP_XI_TS_RST_SOURCE);
  rb_mCv.define_constant("CAP_PROP_XI_IS_DEVICE_EXIST", (int)cv::CAP_PROP_XI_IS_DEVICE_EXIST);
  rb_mCv.define_constant("CAP_PROP_XI_ACQ_BUFFER_SIZE", (int)cv::CAP_PROP_XI_ACQ_BUFFER_SIZE);
  rb_mCv.define_constant("CAP_PROP_XI_ACQ_BUFFER_SIZE_UNIT", (int)cv::CAP_PROP_XI_ACQ_BUFFER_SIZE_UNIT);
  rb_mCv.define_constant("CAP_PROP_XI_ACQ_TRANSPORT_BUFFER_SIZE", (int)cv::CAP_PROP_XI_ACQ_TRANSPORT_BUFFER_SIZE);
  rb_mCv.define_constant("CAP_PROP_XI_BUFFERS_QUEUE_SIZE", (int)cv::CAP_PROP_XI_BUFFERS_QUEUE_SIZE);
  rb_mCv.define_constant("CAP_PROP_XI_ACQ_TRANSPORT_BUFFER_COMMIT", (int)cv::CAP_PROP_XI_ACQ_TRANSPORT_BUFFER_COMMIT);
  rb_mCv.define_constant("CAP_PROP_XI_RECENT_FRAME", (int)cv::CAP_PROP_XI_RECENT_FRAME);
  rb_mCv.define_constant("CAP_PROP_XI_DEVICE_RESET", (int)cv::CAP_PROP_XI_DEVICE_RESET);
  rb_mCv.define_constant("CAP_PROP_XI_COLUMN_FPN_CORRECTION", (int)cv::CAP_PROP_XI_COLUMN_FPN_CORRECTION);
  rb_mCv.define_constant("CAP_PROP_XI_ROW_FPN_CORRECTION", (int)cv::CAP_PROP_XI_ROW_FPN_CORRECTION);
  rb_mCv.define_constant("CAP_PROP_XI_SENSOR_MODE", (int)cv::CAP_PROP_XI_SENSOR_MODE);
  rb_mCv.define_constant("CAP_PROP_XI_HDR", (int)cv::CAP_PROP_XI_HDR);
  rb_mCv.define_constant("CAP_PROP_XI_HDR_KNEEPOINT_COUNT", (int)cv::CAP_PROP_XI_HDR_KNEEPOINT_COUNT);
  rb_mCv.define_constant("CAP_PROP_XI_HDR_T1", (int)cv::CAP_PROP_XI_HDR_T1);
  rb_mCv.define_constant("CAP_PROP_XI_HDR_T2", (int)cv::CAP_PROP_XI_HDR_T2);
  rb_mCv.define_constant("CAP_PROP_XI_KNEEPOINT1", (int)cv::CAP_PROP_XI_KNEEPOINT1);
  rb_mCv.define_constant("CAP_PROP_XI_KNEEPOINT2", (int)cv::CAP_PROP_XI_KNEEPOINT2);
  rb_mCv.define_constant("CAP_PROP_XI_IMAGE_BLACK_LEVEL", (int)cv::CAP_PROP_XI_IMAGE_BLACK_LEVEL);
  rb_mCv.define_constant("CAP_PROP_XI_HW_REVISION", (int)cv::CAP_PROP_XI_HW_REVISION);
  rb_mCv.define_constant("CAP_PROP_XI_DEBUG_LEVEL", (int)cv::CAP_PROP_XI_DEBUG_LEVEL);
  rb_mCv.define_constant("CAP_PROP_XI_AUTO_BANDWIDTH_CALCULATION", (int)cv::CAP_PROP_XI_AUTO_BANDWIDTH_CALCULATION);
  rb_mCv.define_constant("CAP_PROP_XI_FFS_FILE_ID", (int)cv::CAP_PROP_XI_FFS_FILE_ID);
  rb_mCv.define_constant("CAP_PROP_XI_FFS_FILE_SIZE", (int)cv::CAP_PROP_XI_FFS_FILE_SIZE);
  rb_mCv.define_constant("CAP_PROP_XI_FREE_FFS_SIZE", (int)cv::CAP_PROP_XI_FREE_FFS_SIZE);
  rb_mCv.define_constant("CAP_PROP_XI_USED_FFS_SIZE", (int)cv::CAP_PROP_XI_USED_FFS_SIZE);
  rb_mCv.define_constant("CAP_PROP_XI_FFS_ACCESS_KEY", (int)cv::CAP_PROP_XI_FFS_ACCESS_KEY);
  rb_mCv.define_constant("CAP_PROP_XI_SENSOR_FEATURE_SELECTOR", (int)cv::CAP_PROP_XI_SENSOR_FEATURE_SELECTOR);
  rb_mCv.define_constant("CAP_PROP_XI_SENSOR_FEATURE_VALUE", (int)cv::CAP_PROP_XI_SENSOR_FEATURE_VALUE);

  rb_mCv.define_constant("CAP_PROP_ARAVIS_AUTOTRIGGER", (int)cv::CAP_PROP_ARAVIS_AUTOTRIGGER);

  rb_mCv.define_constant("CAP_PROP_ANDROID_DEVICE_TORCH", (int)cv::CAP_PROP_ANDROID_DEVICE_TORCH);

  rb_mCv.define_constant("CAP_PROP_IOS_DEVICE_FOCUS", (int)cv::CAP_PROP_IOS_DEVICE_FOCUS);
  rb_mCv.define_constant("CAP_PROP_IOS_DEVICE_EXPOSURE", (int)cv::CAP_PROP_IOS_DEVICE_EXPOSURE);
  rb_mCv.define_constant("CAP_PROP_IOS_DEVICE_FLASH", (int)cv::CAP_PROP_IOS_DEVICE_FLASH);
  rb_mCv.define_constant("CAP_PROP_IOS_DEVICE_WHITEBALANCE", (int)cv::CAP_PROP_IOS_DEVICE_WHITEBALANCE);
  rb_mCv.define_constant("CAP_PROP_IOS_DEVICE_TORCH", (int)cv::CAP_PROP_IOS_DEVICE_TORCH);

  rb_mCv.define_constant("CAP_PROP_GIGA_FRAME_OFFSET_X", (int)cv::CAP_PROP_GIGA_FRAME_OFFSET_X);
  rb_mCv.define_constant("CAP_PROP_GIGA_FRAME_OFFSET_Y", (int)cv::CAP_PROP_GIGA_FRAME_OFFSET_Y);
  rb_mCv.define_constant("CAP_PROP_GIGA_FRAME_WIDTH_MAX", (int)cv::CAP_PROP_GIGA_FRAME_WIDTH_MAX);
  rb_mCv.define_constant("CAP_PROP_GIGA_FRAME_HEIGH_MAX", (int)cv::CAP_PROP_GIGA_FRAME_HEIGH_MAX);
  rb_mCv.define_constant("CAP_PROP_GIGA_FRAME_SENS_WIDTH", (int)cv::CAP_PROP_GIGA_FRAME_SENS_WIDTH);
  rb_mCv.define_constant("CAP_PROP_GIGA_FRAME_SENS_HEIGH", (int)cv::CAP_PROP_GIGA_FRAME_SENS_HEIGH);

  rb_mCv.define_constant("CAP_PROP_INTELPERC_PROFILE_COUNT", (int)cv::CAP_PROP_INTELPERC_PROFILE_COUNT);
  rb_mCv.define_constant("CAP_PROP_INTELPERC_PROFILE_IDX", (int)cv::CAP_PROP_INTELPERC_PROFILE_IDX);
  rb_mCv.define_constant("CAP_PROP_INTELPERC_DEPTH_LOW_CONFIDENCE_VALUE", (int)cv::CAP_PROP_INTELPERC_DEPTH_LOW_CONFIDENCE_VALUE);
  rb_mCv.define_constant("CAP_PROP_INTELPERC_DEPTH_SATURATION_VALUE", (int)cv::CAP_PROP_INTELPERC_DEPTH_SATURATION_VALUE);
  rb_mCv.define_constant("CAP_PROP_INTELPERC_DEPTH_CONFIDENCE_THRESHOLD", (int)cv::CAP_PROP_INTELPERC_DEPTH_CONFIDENCE_THRESHOLD);
  rb_mCv.define_constant("CAP_PROP_INTELPERC_DEPTH_FOCAL_LENGTH_HORZ", (int)cv::CAP_PROP_INTELPERC_DEPTH_FOCAL_LENGTH_HORZ);
  rb_mCv.define_constant("CAP_PROP_INTELPERC_DEPTH_FOCAL_LENGTH_VERT", (int)cv::CAP_PROP_INTELPERC_DEPTH_FOCAL_LENGTH_VERT);

  rb_mCv.define_constant("CAP_INTELPERC_DEPTH_GENERATOR", (int)cv::CAP_INTELPERC_DEPTH_GENERATOR);
  rb_mCv.define_constant("CAP_INTELPERC_IMAGE_GENERATOR", (int)cv::CAP_INTELPERC_IMAGE_GENERATOR);
  rb_mCv.define_constant("CAP_INTELPERC_IR_GENERATOR", (int)cv::CAP_INTELPERC_IR_GENERATOR);
  rb_mCv.define_constant("CAP_INTELPERC_GENERATORS_MASK", (int)cv::CAP_INTELPERC_GENERATORS_MASK);

  rb_mCv.define_constant("CAP_INTELPERC_DEPTH_MAP", (int)cv::CAP_INTELPERC_DEPTH_MAP);
  rb_mCv.define_constant("CAP_INTELPERC_UVDEPTH_MAP", (int)cv::CAP_INTELPERC_UVDEPTH_MAP);
  rb_mCv.define_constant("CAP_INTELPERC_IR_MAP", (int)cv::CAP_INTELPERC_IR_MAP);
  rb_mCv.define_constant("CAP_INTELPERC_IMAGE", (int)cv::CAP_INTELPERC_IMAGE);

  rb_mCv.define_constant("CAP_PROP_GPHOTO2_PREVIEW", (int)cv::CAP_PROP_GPHOTO2_PREVIEW);
  rb_mCv.define_constant("CAP_PROP_GPHOTO2_WIDGET_ENUMERATE", (int)cv::CAP_PROP_GPHOTO2_WIDGET_ENUMERATE);
  rb_mCv.define_constant("CAP_PROP_GPHOTO2_RELOAD_CONFIG", (int)cv::CAP_PROP_GPHOTO2_RELOAD_CONFIG);
  rb_mCv.define_constant("CAP_PROP_GPHOTO2_RELOAD_ON_CHANGE", (int)cv::CAP_PROP_GPHOTO2_RELOAD_ON_CHANGE);
  rb_mCv.define_constant("CAP_PROP_GPHOTO2_COLLECT_MSGS", (int)cv::CAP_PROP_GPHOTO2_COLLECT_MSGS);
  rb_mCv.define_constant("CAP_PROP_GPHOTO2_FLUSH_MSGS", (int)cv::CAP_PROP_GPHOTO2_FLUSH_MSGS);
  rb_mCv.define_constant("CAP_PROP_SPEED", (int)cv::CAP_PROP_SPEED);
  rb_mCv.define_constant("CAP_PROP_APERTURE", (int)cv::CAP_PROP_APERTURE);
  rb_mCv.define_constant("CAP_PROP_EXPOSUREPROGRAM", (int)cv::CAP_PROP_EXPOSUREPROGRAM);
  rb_mCv.define_constant("CAP_PROP_VIEWFINDER", (int)cv::CAP_PROP_VIEWFINDER);

  rb_mCv.define_constant("CAP_PROP_IMAGES_BASE", (int)cv::CAP_PROP_IMAGES_BASE);
  rb_mCv.define_constant("CAP_PROP_IMAGES_LAST", (int)cv::CAP_PROP_IMAGES_LAST);

  Enum<cv::VideoCaptureOBSensorDataType> rb_cCvVideoCaptureOBSensorDataType = define_enum_under<cv::VideoCaptureOBSensorDataType>("VideoCaptureOBSensorDataType", rb_mCv).
    define_value("CAP_OBSENSOR_DEPTH_MAP", cv::VideoCaptureOBSensorDataType::CAP_OBSENSOR_DEPTH_MAP).
    define_value("CAP_OBSENSOR_BGR_IMAGE", cv::VideoCaptureOBSensorDataType::CAP_OBSENSOR_BGR_IMAGE).
    define_value("CAP_OBSENSOR_IR_IMAGE", cv::VideoCaptureOBSensorDataType::CAP_OBSENSOR_IR_IMAGE);

  Enum<cv::VideoCaptureOBSensorGenerators> rb_cCvVideoCaptureOBSensorGenerators = define_enum_under<cv::VideoCaptureOBSensorGenerators>("VideoCaptureOBSensorGenerators", rb_mCv).
    define_value("CAP_OBSENSOR_DEPTH_GENERATOR", cv::VideoCaptureOBSensorGenerators::CAP_OBSENSOR_DEPTH_GENERATOR).
    define_value("CAP_OBSENSOR_IMAGE_GENERATOR", cv::VideoCaptureOBSensorGenerators::CAP_OBSENSOR_IMAGE_GENERATOR).
    define_value("CAP_OBSENSOR_IR_GENERATOR", cv::VideoCaptureOBSensorGenerators::CAP_OBSENSOR_IR_GENERATOR).
    define_value("CAP_OBSENSOR_GENERATORS_MASK", cv::VideoCaptureOBSensorGenerators::CAP_OBSENSOR_GENERATORS_MASK);

  Enum<cv::VideoCaptureOBSensorProperties> rb_cCvVideoCaptureOBSensorProperties = define_enum_under<cv::VideoCaptureOBSensorProperties>("VideoCaptureOBSensorProperties", rb_mCv).
    define_value("CAP_PROP_OBSENSOR_INTRINSIC_FX", cv::VideoCaptureOBSensorProperties::CAP_PROP_OBSENSOR_INTRINSIC_FX).
    define_value("CAP_PROP_OBSENSOR_INTRINSIC_FY", cv::VideoCaptureOBSensorProperties::CAP_PROP_OBSENSOR_INTRINSIC_FY).
    define_value("CAP_PROP_OBSENSOR_INTRINSIC_CX", cv::VideoCaptureOBSensorProperties::CAP_PROP_OBSENSOR_INTRINSIC_CX).
    define_value("CAP_PROP_OBSENSOR_INTRINSIC_CY", cv::VideoCaptureOBSensorProperties::CAP_PROP_OBSENSOR_INTRINSIC_CY);

  Rice::Data_Type<cv::IStreamReader> rb_cCvIStreamReader = define_class_under<cv::IStreamReader>(rb_mCv, "IStreamReader").
    define_method<long long(cv::IStreamReader::*)(char*, long long)>("read", &cv::IStreamReader::read,
      Arg("buffer"), Arg("size")).
    define_method<long long(cv::IStreamReader::*)(long long, int)>("seek", &cv::IStreamReader::seek,
      Arg("offset"), Arg("origin"));

  Rice::Data_Type<cv::IVideoCapture> rb_cCvIVideoCapture = define_class_under<cv::IVideoCapture>(rb_mCv, "IVideoCapture");

  Module rb_mCvInternal = define_module_under(rb_mCv, "Internal");

  Rice::Data_Type<cv::internal::VideoCapturePrivateAccessor> rb_cCvInternalVideoCapturePrivateAccessor = define_class_under<cv::internal::VideoCapturePrivateAccessor>(rb_mCvInternal, "VideoCapturePrivateAccessor");

  Rice::Data_Type<cv::VideoCapture> rb_cCvVideoCapture = define_class_under<cv::VideoCapture>(rb_mCv, "VideoCapture").
    define_constructor(Constructor<cv::VideoCapture>()).
    define_constructor(Constructor<cv::VideoCapture, const cv::String&, int>(),
      Arg("filename"), Arg("api_preference") = static_cast<int>(cv::CAP_ANY)).
    define_constructor(Constructor<cv::VideoCapture, const cv::String&, int, const std::vector<int>&>(),
      Arg("filename"), Arg("api_preference"), Arg("params")).
    define_constructor(Constructor<cv::VideoCapture, int, int>(),
      Arg("index"), Arg("api_preference") = static_cast<int>(cv::CAP_ANY)).
    define_constructor(Constructor<cv::VideoCapture, int, int, const std::vector<int>&>(),
      Arg("index"), Arg("api_preference"), Arg("params")).
    define_constructor(Constructor<cv::VideoCapture, const cv::Ptr<cv::IStreamReader>&, int, const std::vector<int>&>(),
      Arg("source"), Arg("api_preference"), Arg("params")).
    define_method<bool(cv::VideoCapture::*)(const cv::String&, int)>("open", &cv::VideoCapture::open,
      Arg("filename"), Arg("api_preference") = static_cast<int>(cv::CAP_ANY)).
    define_method<bool(cv::VideoCapture::*)(const cv::String&, int, const std::vector<int>&)>("open", &cv::VideoCapture::open,
      Arg("filename"), Arg("api_preference"), Arg("params")).
    define_method<bool(cv::VideoCapture::*)(int, int)>("open", &cv::VideoCapture::open,
      Arg("index"), Arg("api_preference") = static_cast<int>(cv::CAP_ANY)).
    define_method<bool(cv::VideoCapture::*)(int, int, const std::vector<int>&)>("open", &cv::VideoCapture::open,
      Arg("index"), Arg("api_preference"), Arg("params")).
    define_method<bool(cv::VideoCapture::*)(const cv::Ptr<cv::IStreamReader>&, int, const std::vector<int>&)>("open", &cv::VideoCapture::open,
      Arg("source"), Arg("api_preference"), Arg("params")).
    define_method<bool(cv::VideoCapture::*)() const>("opened?", &cv::VideoCapture::isOpened).
    define_method<void(cv::VideoCapture::*)()>("release", &cv::VideoCapture::release).
    define_method<bool(cv::VideoCapture::*)()>("grab?", &cv::VideoCapture::grab).
    define_method<bool(cv::VideoCapture::*)(cv::OutputArray, int)>("retrieve", &cv::VideoCapture::retrieve,
      Arg("image"), Arg("flag") = static_cast<int>(0)).
    define_method<cv::VideoCapture&(cv::VideoCapture::*)(cv::Mat&)>(">>", &cv::VideoCapture::operator>>,
      Arg("image")).
    define_method<cv::VideoCapture&(cv::VideoCapture::*)(cv::UMat&)>(">>", &cv::VideoCapture::operator>>,
      Arg("image")).
    define_method<bool(cv::VideoCapture::*)(cv::OutputArray)>("read", &cv::VideoCapture::read,
      Arg("image")).
    define_method<bool(cv::VideoCapture::*)(int, double)>("set", &cv::VideoCapture::set,
      Arg("prop_id"), Arg("value")).
    define_method<double(cv::VideoCapture::*)(int) const>("get", &cv::VideoCapture::get,
      Arg("prop_id")).
    define_method<cv::String(cv::VideoCapture::*)() const>("get_backend_name", &cv::VideoCapture::getBackendName).
    define_method<void(cv::VideoCapture::*)(bool)>("set_exception_mode", &cv::VideoCapture::setExceptionMode,
      Arg("enable")).
    define_method<bool(cv::VideoCapture::*)() const>("get_exception_mode?", &cv::VideoCapture::getExceptionMode).
    define_singleton_function<bool(*)(const std::vector<cv::VideoCapture>&, std::vector<int>&, int64)>("wait_any", &cv::VideoCapture::waitAny,
      Arg("streams"), Arg("ready_index"), Arg("timeout_ns") = static_cast<int64>(0));

  Rice::Data_Type<cv::IVideoWriter> rb_cCvIVideoWriter = define_class_under<cv::IVideoWriter>(rb_mCv, "IVideoWriter");

  Rice::Data_Type<cv::VideoWriter> rb_cCvVideoWriter = define_class_under<cv::VideoWriter>(rb_mCv, "VideoWriter").
    define_constructor(Constructor<cv::VideoWriter>()).
    define_constructor(Constructor<cv::VideoWriter, const cv::String&, int, double, cv::Size, bool>(),
      Arg("filename"), Arg("fourcc"), Arg("fps"), Arg("frame_size"), Arg("is_color") = static_cast<bool>(true)).
    define_constructor(Constructor<cv::VideoWriter, const cv::String&, int, int, double, cv::Size, bool>(),
      Arg("filename"), Arg("api_preference"), Arg("fourcc"), Arg("fps"), Arg("frame_size"), Arg("is_color") = static_cast<bool>(true)).
    define_constructor(Constructor<cv::VideoWriter, const cv::String&, int, double, const cv::Size&, const std::vector<int>&>(),
      Arg("filename"), Arg("fourcc"), Arg("fps"), Arg("frame_size"), Arg("params")).
    define_constructor(Constructor<cv::VideoWriter, const cv::String&, int, int, double, const cv::Size&, const std::vector<int>&>(),
      Arg("filename"), Arg("api_preference"), Arg("fourcc"), Arg("fps"), Arg("frame_size"), Arg("params")).
    define_method<bool(cv::VideoWriter::*)(const cv::String&, int, double, cv::Size, bool)>("open", &cv::VideoWriter::open,
      Arg("filename"), Arg("fourcc"), Arg("fps"), Arg("frame_size"), Arg("is_color") = static_cast<bool>(true)).
    define_method<bool(cv::VideoWriter::*)(const cv::String&, int, int, double, cv::Size, bool)>("open", &cv::VideoWriter::open,
      Arg("filename"), Arg("api_preference"), Arg("fourcc"), Arg("fps"), Arg("frame_size"), Arg("is_color") = static_cast<bool>(true)).
    define_method<bool(cv::VideoWriter::*)(const cv::String&, int, double, const cv::Size&, const std::vector<int>&)>("open", &cv::VideoWriter::open,
      Arg("filename"), Arg("fourcc"), Arg("fps"), Arg("frame_size"), Arg("params")).
    define_method<bool(cv::VideoWriter::*)(const cv::String&, int, int, double, const cv::Size&, const std::vector<int>&)>("open", &cv::VideoWriter::open,
      Arg("filename"), Arg("api_preference"), Arg("fourcc"), Arg("fps"), Arg("frame_size"), Arg("params")).
    define_method<bool(cv::VideoWriter::*)() const>("opened?", &cv::VideoWriter::isOpened).
    define_method<void(cv::VideoWriter::*)()>("release", &cv::VideoWriter::release).
    define_method<cv::VideoWriter&(cv::VideoWriter::*)(const cv::Mat&)>("<<", &cv::VideoWriter::operator<<,
      Arg("image")).
    define_method<cv::VideoWriter&(cv::VideoWriter::*)(const cv::UMat&)>("<<", &cv::VideoWriter::operator<<,
      Arg("image")).
    define_method<void(cv::VideoWriter::*)(cv::InputArray)>("write", &cv::VideoWriter::write,
      Arg("image")).
    define_method<bool(cv::VideoWriter::*)(int, double)>("set", &cv::VideoWriter::set,
      Arg("prop_id"), Arg("value")).
    define_method<double(cv::VideoWriter::*)(int) const>("get", &cv::VideoWriter::get,
      Arg("prop_id")).
    define_method<cv::String(cv::VideoWriter::*)() const>("get_backend_name", &cv::VideoWriter::getBackendName).
    define_singleton_function<int(*)(char, char, char, char)>("fourcc", &cv::VideoWriter::fourcc,
      Arg("c1"), Arg("c2"), Arg("c3"), Arg("c4"));

  Rice::Data_Type<cv::DefaultDeleter<CvCapture>> rb_cCvDefaultDeleterCvCapture = define_class_under<cv::DefaultDeleter<CvCapture>>(rb_mCv, "DefaultDeleterCvCapture").
    define_constructor(Constructor<cv::DefaultDeleter<CvCapture>>()).
    define_method<void(cv::DefaultDeleter<CvCapture>::*)(CvCapture*) const>("call", &cv::DefaultDeleter<CvCapture>::operator(),
      Arg("obj"));
}