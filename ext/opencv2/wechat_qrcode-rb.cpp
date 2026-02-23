#include <opencv2/wechat_qrcode.hpp>
#include "wechat_qrcode-rb.hpp"

using namespace Rice;

void Init_WechatQrcode()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvWechatQrcode = define_module_under(rb_mCv, "WechatQrcode");

  Rice::Data_Type<cv::wechat_qrcode::WeChatQRCode> rb_cCvWechatQrcodeWeChatQRCode = define_class_under<cv::wechat_qrcode::WeChatQRCode>(rb_mCvWechatQrcode, "WeChatQRCode").
    define_constructor(Constructor<cv::wechat_qrcode::WeChatQRCode, const std::string&, const std::string&, const std::string&, const std::string&>(),
      Arg("detector_prototxt_path") = static_cast<const std::string&>(""), Arg("detector_caffe_model_path") = static_cast<const std::string&>(""), Arg("super_resolution_prototxt_path") = static_cast<const std::string&>(""), Arg("super_resolution_caffe_model_path") = static_cast<const std::string&>("")).
    define_method<std::vector<std::string>(cv::wechat_qrcode::WeChatQRCode::*)(cv::InputArray, cv::OutputArrayOfArrays)>("detect_and_decode", &cv::wechat_qrcode::WeChatQRCode::detectAndDecode,
      Arg("img"), Arg("points") = static_cast<cv::OutputArrayOfArrays>(cv::noArray())).
    define_method<void(cv::wechat_qrcode::WeChatQRCode::*)(float)>("set_scale_factor", &cv::wechat_qrcode::WeChatQRCode::setScaleFactor,
      Arg("_scaling_factor")).
    define_method<float(cv::wechat_qrcode::WeChatQRCode::*)()>("get_scale_factor", &cv::wechat_qrcode::WeChatQRCode::getScaleFactor);
}
