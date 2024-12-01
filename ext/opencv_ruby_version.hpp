#include <opencv2/core/version.hpp>

//extern constexpr int RUBY_CV_VERSION;
//extern constexpr int RUBY_CV_VERSION = CV_VERSION_MAJOR * 100 + CV_VERSION_MINOR;
#define RUBY_CV_VERSION (CV_VERSION_MAJOR * 100 + CV_VERSION_MINOR)
static_assert(RUBY_CV_VERSION >= 406);
