#include <opencv2/core/optim.hpp>
#include "../../opencv_ruby_version.hpp"
#include "cvstd_wrapper-rb.hpp"
#include "optim-rb.hpp"

using namespace Rice;

Rice::Class rb_cCvConjGradSolver;
Rice::Class rb_cCvDownhillSolver;
Rice::Class rb_cCvMinProblemSolver;
Rice::Class rb_cCvMinProblemSolverFunction;

void Init_Optim()
{
  Module rb_mCv = define_module("Cv");

  rb_cCvMinProblemSolver = define_class_under<cv::MinProblemSolver, cv::Algorithm>(rb_mCv, "MinProblemSolver").
    define_method("get_function", &cv::MinProblemSolver::getFunction).
    define_method("set_function", &cv::MinProblemSolver::setFunction,
      Arg("f")).
    define_method("get_term_criteria", &cv::MinProblemSolver::getTermCriteria).
    define_method("set_term_criteria", &cv::MinProblemSolver::setTermCriteria,
      Arg("termcrit")).
    define_method("minimize", &cv::MinProblemSolver::minimize,
      Arg("x"));

  rb_cCvMinProblemSolverFunction = define_class_under<cv::MinProblemSolver::Function>(rb_cCvMinProblemSolver, "Function").
    define_method("get_dims", &cv::MinProblemSolver::Function::getDims).
    define_method("get_gradient_eps", &cv::MinProblemSolver::Function::getGradientEps).
    define_method("calc", &cv::MinProblemSolver::Function::calc,
      Arg("x")).
    define_method("get_gradient", &cv::MinProblemSolver::Function::getGradient,
      Arg("x"), Arg("grad"));

  rb_cCvDownhillSolver = define_class_under<cv::DownhillSolver, cv::MinProblemSolver>(rb_mCv, "DownhillSolver").
    define_method("get_init_step", &cv::DownhillSolver::getInitStep,
      Arg("step")).
    define_method("set_init_step", &cv::DownhillSolver::setInitStep,
      Arg("step")).
    define_singleton_function("create", &cv::DownhillSolver::create,
      Arg("f") = static_cast<const cv::Ptr<cv::MinProblemSolver::Function>&>(cv::Ptr<cv::MinProblemSolver::Function>()), Arg("init_step") = static_cast<cv::InputArray>(cv::Mat_<double>(1,1,0.0)), Arg("termcrit") = static_cast<cv::TermCriteria>(cv::TermCriteria(cv::TermCriteria::MAX_ITER+cv::TermCriteria::EPS,5000,0.000001)));

  rb_cCvConjGradSolver = define_class_under<cv::ConjGradSolver, cv::MinProblemSolver>(rb_mCv, "ConjGradSolver").
    define_singleton_function("create", &cv::ConjGradSolver::create,
      Arg("f") = static_cast<const cv::Ptr<cv::MinProblemSolver::Function>&>(cv::Ptr<cv::ConjGradSolver::Function>()), Arg("termcrit") = static_cast<cv::TermCriteria>(cv::TermCriteria(cv::TermCriteria::MAX_ITER+cv::TermCriteria::EPS,5000,0.000001)));

  Enum<cv::SolveLPResult> rb_cCvSolveLPResult = define_enum_under<cv::SolveLPResult>("SolveLPResult", rb_mCv).
    define_value("SOLVELP_UNBOUNDED", cv::SolveLPResult::SOLVELP_UNBOUNDED).
    define_value("SOLVELP_UNFEASIBLE", cv::SolveLPResult::SOLVELP_UNFEASIBLE).
    define_value("SOLVELP_SINGLE", cv::SolveLPResult::SOLVELP_SINGLE).
    define_value("SOLVELP_MULTI", cv::SolveLPResult::SOLVELP_MULTI);

#if RUBY_CV_VERSION >= 408
  rb_cCvSolveLPResult.
    define_value("SOLVELP_LOST", cv::SolveLPResult::SOLVELP_LOST);

  rb_mCv.define_module_function<int(*)(cv::InputArray, cv::InputArray, cv::OutputArray, double)>("solve_lp", &cv::solveLP,
    Arg("func"), Arg("constr"), Arg("z"), Arg("constr_eps"));
#endif

  rb_mCv.define_module_function<int(*)(cv::InputArray, cv::InputArray, cv::OutputArray)>("solve_lp", &cv::solveLP,
    Arg("func"), Arg("constr"), Arg("z"));
}