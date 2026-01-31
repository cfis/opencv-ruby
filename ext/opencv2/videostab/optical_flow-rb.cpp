#include <opencv2/videostab/optical_flow.hpp>
#include "optical_flow-rb.hpp"

using namespace Rice;

void Init_Videostab_OpticalFlow()
{
  Module rb_mCv = define_module("Cv");

  Module rb_mCvVideostab = define_module_under(rb_mCv, "Videostab");

  Rice::Data_Type<cv::videostab::ISparseOptFlowEstimator> rb_cCvVideostabISparseOptFlowEstimator = define_class_under<cv::videostab::ISparseOptFlowEstimator>(rb_mCvVideostab, "ISparseOptFlowEstimator").
    define_method<void(cv::videostab::ISparseOptFlowEstimator::*)(cv::InputArray, cv::InputArray, cv::InputArray, cv::InputOutputArray, cv::OutputArray, cv::OutputArray)>("run", &cv::videostab::ISparseOptFlowEstimator::run,
      Arg("frame0"), Arg("frame1"), Arg("points0"), Arg("points1"), Arg("status"), Arg("errors"));

  Rice::Data_Type<cv::videostab::IDenseOptFlowEstimator> rb_cCvVideostabIDenseOptFlowEstimator = define_class_under<cv::videostab::IDenseOptFlowEstimator>(rb_mCvVideostab, "IDenseOptFlowEstimator").
    define_method<void(cv::videostab::IDenseOptFlowEstimator::*)(cv::InputArray, cv::InputArray, cv::InputOutputArray, cv::InputOutputArray, cv::OutputArray)>("run", &cv::videostab::IDenseOptFlowEstimator::run,
      Arg("frame0"), Arg("frame1"), Arg("flow_x"), Arg("flow_y"), Arg("errors"));

  Rice::Data_Type<cv::videostab::PyrLkOptFlowEstimatorBase> rb_cCvVideostabPyrLkOptFlowEstimatorBase = define_class_under<cv::videostab::PyrLkOptFlowEstimatorBase>(rb_mCvVideostab, "PyrLkOptFlowEstimatorBase").
    define_constructor(Constructor<cv::videostab::PyrLkOptFlowEstimatorBase>()).
    define_method<void(cv::videostab::PyrLkOptFlowEstimatorBase::*)(cv::Size)>("set_win_size", &cv::videostab::PyrLkOptFlowEstimatorBase::setWinSize,
      Arg("val")).
    define_method<cv::Size(cv::videostab::PyrLkOptFlowEstimatorBase::*)() const>("win_size", &cv::videostab::PyrLkOptFlowEstimatorBase::winSize).
    define_method<void(cv::videostab::PyrLkOptFlowEstimatorBase::*)(int)>("set_max_level", &cv::videostab::PyrLkOptFlowEstimatorBase::setMaxLevel,
      Arg("val")).
    define_method<int(cv::videostab::PyrLkOptFlowEstimatorBase::*)() const>("max_level", &cv::videostab::PyrLkOptFlowEstimatorBase::maxLevel);

  Rice::Data_Type<cv::videostab::SparsePyrLkOptFlowEstimator> rb_cCvVideostabSparsePyrLkOptFlowEstimator = define_class_under<cv::videostab::SparsePyrLkOptFlowEstimator, cv::videostab::PyrLkOptFlowEstimatorBase>(rb_mCvVideostab, "SparsePyrLkOptFlowEstimator").
    define_constructor(Constructor<cv::videostab::SparsePyrLkOptFlowEstimator>()).
    define_method<void(cv::videostab::SparsePyrLkOptFlowEstimator::*)(cv::InputArray, cv::InputArray, cv::InputArray, cv::InputOutputArray, cv::OutputArray, cv::OutputArray)>("run", &cv::videostab::SparsePyrLkOptFlowEstimator::run,
      Arg("frame0"), Arg("frame1"), Arg("points0"), Arg("points1"), Arg("status"), Arg("errors"));

  Rice::Data_Type<cv::videostab::SparsePyrLkOptFlowEstimatorGpu> rb_cCvVideostabSparsePyrLkOptFlowEstimatorGpu = define_class_under<cv::videostab::SparsePyrLkOptFlowEstimatorGpu, cv::videostab::PyrLkOptFlowEstimatorBase>(rb_mCvVideostab, "SparsePyrLkOptFlowEstimatorGpu").
    define_constructor(Constructor<cv::videostab::SparsePyrLkOptFlowEstimatorGpu>()).
    define_method<void(cv::videostab::SparsePyrLkOptFlowEstimatorGpu::*)(cv::InputArray, cv::InputArray, cv::InputArray, cv::InputOutputArray, cv::OutputArray, cv::OutputArray)>("run", &cv::videostab::SparsePyrLkOptFlowEstimatorGpu::run,
      Arg("frame0"), Arg("frame1"), Arg("points0"), Arg("points1"), Arg("status"), Arg("errors")).
    define_method<void(cv::videostab::SparsePyrLkOptFlowEstimatorGpu::*)(const cv::cuda::GpuMat&, const cv::cuda::GpuMat&, const cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::GpuMat&)>("run", &cv::videostab::SparsePyrLkOptFlowEstimatorGpu::run,
      Arg("frame0"), Arg("frame1"), Arg("points0"), Arg("points1"), Arg("status"), Arg("errors")).
    define_method<void(cv::videostab::SparsePyrLkOptFlowEstimatorGpu::*)(const cv::cuda::GpuMat&, const cv::cuda::GpuMat&, const cv::cuda::GpuMat&, cv::cuda::GpuMat&, cv::cuda::GpuMat&)>("run", &cv::videostab::SparsePyrLkOptFlowEstimatorGpu::run,
      Arg("frame0"), Arg("frame1"), Arg("points0"), Arg("points1"), Arg("status"));

  Rice::Data_Type<cv::videostab::DensePyrLkOptFlowEstimatorGpu> rb_cCvVideostabDensePyrLkOptFlowEstimatorGpu = define_class_under<cv::videostab::DensePyrLkOptFlowEstimatorGpu, cv::videostab::PyrLkOptFlowEstimatorBase>(rb_mCvVideostab, "DensePyrLkOptFlowEstimatorGpu").
    define_constructor(Constructor<cv::videostab::DensePyrLkOptFlowEstimatorGpu>()).
    define_method<void(cv::videostab::DensePyrLkOptFlowEstimatorGpu::*)(cv::InputArray, cv::InputArray, cv::InputOutputArray, cv::InputOutputArray, cv::OutputArray)>("run", &cv::videostab::DensePyrLkOptFlowEstimatorGpu::run,
      Arg("frame0"), Arg("frame1"), Arg("flow_x"), Arg("flow_y"), Arg("errors"));
}