#include <opencv2/core/version.hpp>

#define RUBY_CV_VERSION (CV_VERSION_MAJOR * 100 + CV_VERSION_MINOR)
static_assert(RUBY_CV_VERSION >= 406);
