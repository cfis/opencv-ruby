#ifndef MAT_REFINEMENTS_HPP
#define MAT_REFINEMENTS_HPP

#include <rice/rice.hpp>
#include <opencv2/core/mat.hpp>

// Apply manual refinements to cv::Mat class
// This includes [], []=, ptr, and each methods that require type dispatch
void Mat_refinements(Rice::Class& rb_cCvMat);

#endif // MAT_REFINEMENTS_HPP
