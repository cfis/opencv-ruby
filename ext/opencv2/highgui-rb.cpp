#include <opencv2/core/opengl.hpp>
#include <opencv2/highgui.hpp>
#include "../opencv_ruby_version.hpp"
#include "highgui-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvQtFont;

void Init_Highgui()
{
  Module rb_mCv = define_module("Cv");

  Enum<cv::WindowFlags> rb_cCvWindowFlags = define_enum_under<cv::WindowFlags>("WindowFlags", rb_mCv).
    define_value("WINDOW_NORMAL", cv::WindowFlags::WINDOW_NORMAL).
    define_value("WINDOW_AUTOSIZE", cv::WindowFlags::WINDOW_AUTOSIZE).
    define_value("WINDOW_OPENGL", cv::WindowFlags::WINDOW_OPENGL).
    define_value("WINDOW_FULLSCREEN", cv::WindowFlags::WINDOW_FULLSCREEN).
    define_value("WINDOW_FREERATIO", cv::WindowFlags::WINDOW_FREERATIO).
    define_value("WINDOW_KEEPRATIO", cv::WindowFlags::WINDOW_KEEPRATIO).
    define_value("WINDOW_GUI_EXPANDED", cv::WindowFlags::WINDOW_GUI_EXPANDED).
    define_value("WINDOW_GUI_NORMAL", cv::WindowFlags::WINDOW_GUI_NORMAL);

  Enum<cv::WindowPropertyFlags> rb_cCvWindowPropertyFlags = define_enum_under<cv::WindowPropertyFlags>("WindowPropertyFlags", rb_mCv).
    define_value("WND_PROP_FULLSCREEN", cv::WindowPropertyFlags::WND_PROP_FULLSCREEN).
    define_value("WND_PROP_AUTOSIZE", cv::WindowPropertyFlags::WND_PROP_AUTOSIZE).
    define_value("WND_PROP_ASPECT_RATIO", cv::WindowPropertyFlags::WND_PROP_ASPECT_RATIO).
    define_value("WND_PROP_OPENGL", cv::WindowPropertyFlags::WND_PROP_OPENGL).
    define_value("WND_PROP_VISIBLE", cv::WindowPropertyFlags::WND_PROP_VISIBLE).
    define_value("WND_PROP_TOPMOST", cv::WindowPropertyFlags::WND_PROP_TOPMOST).
    define_value("WND_PROP_VSYNC", cv::WindowPropertyFlags::WND_PROP_VSYNC);

  Enum<cv::MouseEventTypes> rb_cCvMouseEventTypes = define_enum_under<cv::MouseEventTypes>("MouseEventTypes", rb_mCv).
    define_value("EVENT_MOUSEMOVE", cv::MouseEventTypes::EVENT_MOUSEMOVE).
    define_value("EVENT_LBUTTONDOWN", cv::MouseEventTypes::EVENT_LBUTTONDOWN).
    define_value("EVENT_RBUTTONDOWN", cv::MouseEventTypes::EVENT_RBUTTONDOWN).
    define_value("EVENT_MBUTTONDOWN", cv::MouseEventTypes::EVENT_MBUTTONDOWN).
    define_value("EVENT_LBUTTONUP", cv::MouseEventTypes::EVENT_LBUTTONUP).
    define_value("EVENT_RBUTTONUP", cv::MouseEventTypes::EVENT_RBUTTONUP).
    define_value("EVENT_MBUTTONUP", cv::MouseEventTypes::EVENT_MBUTTONUP).
    define_value("EVENT_LBUTTONDBLCLK", cv::MouseEventTypes::EVENT_LBUTTONDBLCLK).
    define_value("EVENT_RBUTTONDBLCLK", cv::MouseEventTypes::EVENT_RBUTTONDBLCLK).
    define_value("EVENT_MBUTTONDBLCLK", cv::MouseEventTypes::EVENT_MBUTTONDBLCLK).
    define_value("EVENT_MOUSEWHEEL", cv::MouseEventTypes::EVENT_MOUSEWHEEL).
    define_value("EVENT_MOUSEHWHEEL", cv::MouseEventTypes::EVENT_MOUSEHWHEEL);

  Enum<cv::MouseEventFlags> rb_cCvMouseEventFlags = define_enum_under<cv::MouseEventFlags>("MouseEventFlags", rb_mCv).
    define_value("EVENT_FLAG_LBUTTON", cv::MouseEventFlags::EVENT_FLAG_LBUTTON).
    define_value("EVENT_FLAG_RBUTTON", cv::MouseEventFlags::EVENT_FLAG_RBUTTON).
    define_value("EVENT_FLAG_MBUTTON", cv::MouseEventFlags::EVENT_FLAG_MBUTTON).
    define_value("EVENT_FLAG_CTRLKEY", cv::MouseEventFlags::EVENT_FLAG_CTRLKEY).
    define_value("EVENT_FLAG_SHIFTKEY", cv::MouseEventFlags::EVENT_FLAG_SHIFTKEY).
    define_value("EVENT_FLAG_ALTKEY", cv::MouseEventFlags::EVENT_FLAG_ALTKEY);

  Enum<cv::QtFontWeights> rb_cCvQtFontWeights = define_enum_under<cv::QtFontWeights>("QtFontWeights", rb_mCv).
    define_value("QT_FONT_LIGHT", cv::QtFontWeights::QT_FONT_LIGHT).
    define_value("QT_FONT_NORMAL", cv::QtFontWeights::QT_FONT_NORMAL).
    define_value("QT_FONT_DEMIBOLD", cv::QtFontWeights::QT_FONT_DEMIBOLD).
    define_value("QT_FONT_BOLD", cv::QtFontWeights::QT_FONT_BOLD).
    define_value("QT_FONT_BLACK", cv::QtFontWeights::QT_FONT_BLACK);

  Enum<cv::QtFontStyles> rb_cCvQtFontStyles = define_enum_under<cv::QtFontStyles>("QtFontStyles", rb_mCv).
    define_value("QT_STYLE_NORMAL", cv::QtFontStyles::QT_STYLE_NORMAL).
    define_value("QT_STYLE_ITALIC", cv::QtFontStyles::QT_STYLE_ITALIC).
    define_value("QT_STYLE_OBLIQUE", cv::QtFontStyles::QT_STYLE_OBLIQUE);

  Enum<cv::QtButtonTypes> rb_cCvQtButtonTypes = define_enum_under<cv::QtButtonTypes>("QtButtonTypes", rb_mCv).
    define_value("QT_PUSH_BUTTON", cv::QtButtonTypes::QT_PUSH_BUTTON).
    define_value("QT_CHECKBOX", cv::QtButtonTypes::QT_CHECKBOX).
    define_value("QT_RADIOBOX", cv::QtButtonTypes::QT_RADIOBOX).
    define_value("QT_NEW_BUTTONBAR", cv::QtButtonTypes::QT_NEW_BUTTONBAR);

  rb_mCv.define_module_function("named_window", &cv::namedWindow,
    Arg("winname"), Arg("flags") = static_cast<int>(cv::WINDOW_AUTOSIZE));

  rb_mCv.define_module_function("destroy_window", &cv::destroyWindow,
    Arg("winname"));

  rb_mCv.define_module_function("destroy_all_windows", &cv::destroyAllWindows);

#if RUBY_CV_VERSION >= 410
  rb_mCv.define_module_function("current_ui_framework", &cv::currentUIFramework);
#endif

  rb_mCv.define_module_function("start_window_thread", &cv::startWindowThread);

  rb_mCv.define_module_function("wait_key_ex", &cv::waitKeyEx,
    Arg("delay") = static_cast<int>(0));

  rb_mCv.define_module_function("wait_key", &cv::waitKey,
    Arg("delay") = static_cast<int>(0));

  rb_mCv.define_module_function("poll_key", &cv::pollKey);

  rb_mCv.define_module_function<void(*)(const cv::String&, cv::InputArray)>("imshow", &cv::imshow,
    Arg("winname"), Arg("mat"));

  rb_mCv.define_module_function<void(*)(const cv::String&, int, int)>("resize_window", &cv::resizeWindow,
    Arg("winname"), Arg("width"), Arg("height"));

  rb_mCv.define_module_function<void(*)(const cv::String&, const cv::Size&)>("resize_window", &cv::resizeWindow,
    Arg("winname"), Arg("size"));

  rb_mCv.define_module_function("move_window", &cv::moveWindow,
    Arg("winname"), Arg("x"), Arg("y"));

  rb_mCv.define_module_function("set_window_property", &cv::setWindowProperty,
    Arg("winname"), Arg("prop_id"), Arg("prop_value"));

  rb_mCv.define_module_function("set_window_title", &cv::setWindowTitle,
    Arg("winname"), Arg("title"));

  rb_mCv.define_module_function("get_window_property", &cv::getWindowProperty,
    Arg("winname"), Arg("prop_id"));

  rb_mCv.define_module_function("get_window_image_rect", &cv::getWindowImageRect,
    Arg("winname"));

  rb_mCv.define_module_function("set_mouse_callback", &cv::setMouseCallback,
    Arg("winname"), Arg("on_mouse"), Arg("userdata").setOpaque() = static_cast<void*>(0));

  rb_mCv.define_module_function("get_mouse_wheel_delta", &cv::getMouseWheelDelta,
    Arg("flags"));

#if RUBY_CV_VERSION >= 408
  rb_mCv.define_module_function<cv::Rect(*)(const cv::String&, cv::InputArray, bool, bool, bool)>("select_roi", &cv::selectROI,
    Arg("window_name"), Arg("img"), Arg("show_crosshair") = static_cast<bool>(true), Arg("from_center") = static_cast<bool>(false), Arg("print_notice") = static_cast<bool>(true));

  rb_mCv.define_module_function<cv::Rect(*)(cv::InputArray, bool, bool, bool)>("select_roi", &cv::selectROI,
    Arg("img"), Arg("show_crosshair") = static_cast<bool>(true), Arg("from_center") = static_cast<bool>(false), Arg("print_notice") = static_cast<bool>(true));
#endif

  rb_mCv.define_module_function("select_ro_is", &cv::selectROIs,
    Arg("window_name"), Arg("img"), Arg("bounding_boxes"), Arg("show_crosshair") = static_cast<bool>(true), Arg("from_center") = static_cast<bool>(false), Arg("print_notice") = static_cast<bool>(true));

  rb_mCv.define_module_function("create_trackbar", &cv::createTrackbar,
    Arg("trackbarname"), Arg("winname"), Arg("value"), Arg("count"), Arg("on_change") = static_cast<cv::TrackbarCallback>(0), Arg("userdata").setOpaque() = static_cast<void*>(0));

  rb_mCv.define_module_function("get_trackbar_pos", &cv::getTrackbarPos,
    Arg("trackbarname"), Arg("winname"));

  rb_mCv.define_module_function("set_trackbar_pos", &cv::setTrackbarPos,
    Arg("trackbarname"), Arg("winname"), Arg("pos"));

  rb_mCv.define_module_function("set_trackbar_max", &cv::setTrackbarMax,
    Arg("trackbarname"), Arg("winname"), Arg("maxval"));

  rb_mCv.define_module_function("set_trackbar_min", &cv::setTrackbarMin,
    Arg("trackbarname"), Arg("winname"), Arg("minval"));

  rb_mCv.define_module_function<void(*)(const cv::String&, const cv::ogl::Texture2D&)>("imshow", &cv::imshow,
    Arg("winname"), Arg("tex"));

  rb_mCv.define_module_function("set_open_gl_draw_callback", &cv::setOpenGlDrawCallback,
    Arg("winname"), Arg("on_open_gl_draw"), Arg("userdata").setOpaque() = static_cast<void*>(0));

  rb_mCv.define_module_function("set_open_gl_context", &cv::setOpenGlContext,
    Arg("winname"));

  rb_mCv.define_module_function("update_window", &cv::updateWindow,
    Arg("winname"));

  rb_cCvQtFont = define_class_under<cv::QtFont>(rb_mCv, "QtFont").
    define_constructor(Constructor<cv::QtFont>()).
    define_attr("name_font", &cv::QtFont::nameFont).
    define_attr("color", &cv::QtFont::color).
    define_attr("font_face", &cv::QtFont::font_face).
    //define_attr("ascii", &cv::QtFont::ascii).
    //define_attr("greek", &cv::QtFont::greek).
    //define_attr("cyrillic", &cv::QtFont::cyrillic).
    define_attr("hscale", &cv::QtFont::hscale).
    define_attr("vscale", &cv::QtFont::vscale).
    define_attr("shear", &cv::QtFont::shear).
    define_attr("thickness", &cv::QtFont::thickness).
    define_attr("dx", &cv::QtFont::dx).
    define_attr("line_type", &cv::QtFont::line_type);

  rb_mCv.define_module_function("font_qt", &cv::fontQt,
    Arg("name_font"), Arg("point_size") = static_cast<int>(-1), Arg("color") = static_cast<cv::Scalar>(cv::Scalar::all(0)), Arg("weight") = static_cast<int>(cv::QT_FONT_NORMAL), Arg("style") = static_cast<int>(cv::QT_STYLE_NORMAL), Arg("spacing") = static_cast<int>(0));

  rb_mCv.define_module_function<void(*)(const cv::Mat&, const cv::String&, cv::Point, const cv::QtFont&)>("add_text", &cv::addText,
    Arg("img"), Arg("text"), Arg("org"), Arg("font"));

  rb_mCv.define_module_function<void(*)(const cv::Mat&, const cv::String&, cv::Point, const cv::String&, int, cv::Scalar, int, int, int)>("add_text", &cv::addText,
    Arg("img"), Arg("text"), Arg("org"), Arg("name_font"), Arg("point_size") = static_cast<int>(-1), Arg("color") = static_cast<cv::Scalar>(cv::Scalar::all(0)), Arg("weight") = static_cast<int>(cv::QT_FONT_NORMAL), Arg("style") = static_cast<int>(cv::QT_STYLE_NORMAL), Arg("spacing") = static_cast<int>(0));

  rb_mCv.define_module_function("display_overlay", &cv::displayOverlay,
    Arg("winname"), Arg("text"), Arg("delayms") = static_cast<int>(0));

  rb_mCv.define_module_function("display_status_bar", &cv::displayStatusBar,
    Arg("winname"), Arg("text"), Arg("delayms") = static_cast<int>(0));

  rb_mCv.define_module_function("save_window_parameters", &cv::saveWindowParameters,
    Arg("window_name"));

  rb_mCv.define_module_function("load_window_parameters", &cv::loadWindowParameters,
    Arg("window_name"));

  //rb_mCv.define_module_function("start_loop", &cv::startLoop,
  //  Arg("pt2_func"), Arg("argc"), Arg("argv"));

  rb_mCv.define_module_function("stop_loop", &cv::stopLoop);

  rb_mCv.define_module_function("create_button", &cv::createButton,
    Arg("bar_name"), Arg("on_change"), Arg("userdata") = static_cast<void*>(0), Arg("type") = static_cast<int>(cv::QT_PUSH_BUTTON), Arg("initial_button_state") = static_cast<bool>(false));

  // Callbacks
  define_callback<cv::MouseCallback>(Arg("event"), Arg("x"), Arg("y"), Arg("flags"), Arg("user_data").setOpaque());
  define_callback<cv::TrackbarCallback>(Arg("pos"), Arg("user_data").setOpaque());
  define_callback<cv::OpenGlDrawCallback>(Arg("user_data").setOpaque());
  define_callback<cv::ButtonCallback>(Arg("state"), Arg("user_data").setOpaque());
}