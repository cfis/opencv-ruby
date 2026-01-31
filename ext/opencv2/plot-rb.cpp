#include <opencv2/plot.hpp>
#include "plot-rb.hpp"

using namespace Rice;

void Init_Plot()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvPlot = define_module_under(rb_mCv, "Plot");

  Rice::Data_Type<cv::plot::Plot2d> rb_cCvPlotPlot2d = define_class_under<cv::plot::Plot2d, cv::Algorithm>(rb_mCvPlot, "Plot2d").
    define_method<void(cv::plot::Plot2d::*)(double)>("set_min_x", &cv::plot::Plot2d::setMinX,
      Arg("_plot_min_x")).
    define_method<void(cv::plot::Plot2d::*)(double)>("set_min_y", &cv::plot::Plot2d::setMinY,
      Arg("_plot_min_y")).
    define_method<void(cv::plot::Plot2d::*)(double)>("set_max_x", &cv::plot::Plot2d::setMaxX,
      Arg("_plot_max_x")).
    define_method<void(cv::plot::Plot2d::*)(double)>("set_max_y", &cv::plot::Plot2d::setMaxY,
      Arg("_plot_max_y")).
    define_method<void(cv::plot::Plot2d::*)(int)>("set_plot_line_width", &cv::plot::Plot2d::setPlotLineWidth,
      Arg("_plot_line_width")).
    define_method<void(cv::plot::Plot2d::*)(bool)>("set_need_plot_line", &cv::plot::Plot2d::setNeedPlotLine,
      Arg("_need_plot_line")).
    define_method<void(cv::plot::Plot2d::*)(cv::Scalar)>("set_plot_line_color", &cv::plot::Plot2d::setPlotLineColor,
      Arg("_plot_line_color")).
    define_method<void(cv::plot::Plot2d::*)(cv::Scalar)>("set_plot_background_color", &cv::plot::Plot2d::setPlotBackgroundColor,
      Arg("_plot_background_color")).
    define_method<void(cv::plot::Plot2d::*)(cv::Scalar)>("set_plot_axis_color", &cv::plot::Plot2d::setPlotAxisColor,
      Arg("_plot_axis_color")).
    define_method<void(cv::plot::Plot2d::*)(cv::Scalar)>("set_plot_grid_color", &cv::plot::Plot2d::setPlotGridColor,
      Arg("_plot_grid_color")).
    define_method<void(cv::plot::Plot2d::*)(cv::Scalar)>("set_plot_text_color", &cv::plot::Plot2d::setPlotTextColor,
      Arg("_plot_text_color")).
    define_method<void(cv::plot::Plot2d::*)(int, int)>("set_plot_size", &cv::plot::Plot2d::setPlotSize,
      Arg("_plot_size_width"), Arg("_plot_size_height")).
    define_method<void(cv::plot::Plot2d::*)(bool)>("set_show_grid", &cv::plot::Plot2d::setShowGrid,
      Arg("need_show_grid")).
    define_method<void(cv::plot::Plot2d::*)(bool)>("set_show_text", &cv::plot::Plot2d::setShowText,
      Arg("need_show_text")).
    define_method<void(cv::plot::Plot2d::*)(int)>("set_grid_lines_number", &cv::plot::Plot2d::setGridLinesNumber,
      Arg("grid_lines_number")).
    define_method<void(cv::plot::Plot2d::*)(bool)>("set_invert_orientation", &cv::plot::Plot2d::setInvertOrientation,
      Arg("_invert_orientation")).
    define_method<void(cv::plot::Plot2d::*)(int)>("set_point_idx_to_print", &cv::plot::Plot2d::setPointIdxToPrint,
      Arg("point_idx")).
    define_method<void(cv::plot::Plot2d::*)(cv::OutputArray)>("render", &cv::plot::Plot2d::render,
      Arg("_plot_result")).
    define_singleton_function<cv::Ptr<cv::plot::Plot2d>(*)(cv::InputArray)>("create", &cv::plot::Plot2d::create,
      Arg("data")).
    define_singleton_function<cv::Ptr<cv::plot::Plot2d>(*)(cv::InputArray, cv::InputArray)>("create", &cv::plot::Plot2d::create,
      Arg("data_x"), Arg("data_y"));
}