module Cv
  class Mat
    def type_to_string
      case self.type
        when CV_8UC1
          "CV_8UC1"
        when CV_8UC2
          "CV_8UC2"
        when CV_8UC3
          "CV_8UC3"
        when CV_8UC4
          "CV_8UC4"
        when CV_8SC1
          "CV_8SC1"
        when CV_8SC2
          "CV_8SC2"
        when CV_8SC3
          "CV_8SC3"
        when CV_8SC4
          "CV_8SC4"
        when CV_16UC1
          "CV_16UC1"
        when CV_16UC2
          "CV_16UC2"
        when CV_16UC3
          "CV_16UC3"
        when CV_16UC4
          "CV_16UC4"
        when CV_16SC1
          "CV_16SC1"
        when CV_16SC2
          "CV_16SC2"
        when CV_16SC3
          "CV_16SC3"
        when CV_16SC4
          "CV_16SC4"
        when CV_32SC1
          "CV_32SC1"
        when CV_32SC2
          "CV_32SC2"
        when CV_32SC3
          "CV_32SC3"
        when CV_32SC4
          "CV_32SC4"
        when CV_32FC1
          "CV_32FC1"
        when CV_32FC2
          "CV_32FC2"
        when CV_32FC3
          "CV_32FC3"
        when CV_32FC4
          "CV_32FC4"
        when CV_64FC1
          "CV_64FC1"
        when CV_64FC2
          "CV_64FC2"
        when CV_64FC3
          "CV_64FC3"
        when CV_64FC4
          "CV_64FC4"
        when CV_16FC1
          "CV_16FC1"
        when CV_16FC2
          "CV_16FC2"
        when CV_16FC3
          "CV_16FC3"
        when CV_16FC4
          "CV_16FC4"
        else
          raise("Uknown type: #{self.type}")
      end
    end

    def mat_klass
      case self.type
        when CV_8UC1
          Cv::Mat1b
        when CV_8UC2
          Cv::Mat2b
        when CV_8UC3
          Cv::Mat3b
        when CV_8UC4
          Cv::Mat4b
        when CV_8SC1
          raise("CV_8SC1 has not corresponding Mat_ class")
        when CV_8SC2
          raise("CV_8SC2 has not corresponding Mat_ class")
        when CV_8SC3
          raise("CV_8SC3 has not corresponding Mat_ class")
        when CV_8SC4
          raise("CV_8SC4 has not corresponding Mat_ class")
        when CV_16UC1
          Cv::Mat1w
        when CV_16UC2
          Cv::Mat2w
        when CV_16UC3
          Cv::Mat3w
        when CV_16UC4
          Cv::Mat4w
        when CV_16SC1
          Cv::Mat1s
        when CV_16SC2
          Cv::Mat2s
        when CV_16SC3
          Cv::Mat3s
        when CV_16SC4
          Cv::Mat4s
        when CV_32SC1
          Cv::Mat1i
        when CV_32SC2
          Cv::Mat2i
        when CV_32SC3
          Cv::Mat3i
        when CV_32SC4
          Cv::Mat4i
        when CV_32FC1
          Cv::Mat1f
        when CV_32FC2
          Cv::Mat2f
        when CV_32FC3
          Cv::Mat3f
        when CV_32FC4
          Cv::Mat4f
        when CV_64FC1
          Cv::Mat1d
        when CV_64FC2
          Cv::Mat2d
        when CV_64FC3
          Cv::Mat3d
        when CV_64FC4
          Cv::Mat4d
        when CV_16FC1
          raise("CV_16FC1 has not corresponding Mat_ class")
        when CV_16FC2
          raise("CV_16FC2 has not corresponding Mat_ class")
        when CV_16FC3
          raise("CV_16FC3 has not corresponding Mat_ class")
        when CV_16FC4
          raise("CV_16FC4 has not corresponding Mat_ class")
        else
          raise("Uknown type: #{self.type}")
      end
    end

    def vec_klass
      case self.type
        when CV_8UC1
          Cv::Vec1b
        when CV_8UC2
          Cv::Vec2b
        when CV_8UC3
          Cv::Vec3b
        when CV_8UC4
          Cv::Vec4b
        when CV_8SC1
          raise("CV_8SC1 has not corresponding Mat_ class")
        when CV_8SC2
          raise("CV_8SC2 has not corresponding Mat_ class")
        when CV_8SC3
          raise("CV_8SC3 has not corresponding Mat_ class")
        when CV_8SC4
          raise("CV_8SC4 has not corresponding Mat_ class")
        when CV_16UC1
          Cv::Vec1w
        when CV_16UC2
          Cv::Vec2w
        when CV_16UC3
          Cv::Vec3w
        when CV_16UC4
          Cv::Vec4w
        when CV_16SC1
          Cv::Vec1s
        when CV_16SC2
          Cv::Vec2s
        when CV_16SC3
          Cv::Vec3s
        when CV_16SC4
          Cv::Vec4s
        when CV_32SC1
          Cv::Vec1i
        when CV_32SC2
          Cv::Vec2i
        when CV_32SC3
          Cv::Vec3i
        when CV_32SC4
          Cv::Vec4i
        when CV_32FC1
          Cv::Vec1f
        when CV_32FC2
          Cv::Vec2f
        when CV_32FC3
          Cv::Vec3f
        when CV_32FC4
          Cv::Vec4f
        when CV_64FC1
          Cv::Vec1d
        when CV_64FC2
          Cv::Vec2d
        when CV_64FC3
          Cv::Vec3d
        when CV_64FC4
          Cv::Vec4d
        when CV_16FC1
          raise("CV_16FC1 has not corresponding Mat_ class")
        when CV_16FC2
          raise("CV_16FC2 has not corresponding Mat_ class")
        when CV_16FC3
          raise("CV_16FC3 has not corresponding Mat_ class")
        when CV_16FC4
          raise("CV_16FC4 has not corresponding Mat_ class")
        else
          raise("Uknown type: #{self.type}")
      end
    end

    def to_s
      "<#{self.class.name}:#{self.rows}x#{self.cols},type=#{self.type_to_string},channel=#{self.channels}>"
    end

    # Provide more Ruby like API to OpenCV
    def compare(other, operation)
      dest = self.class.new(self.rows, self.cols, self.type)
    	Cv::compare(self.input_array, other.input_array, dest.output_array, operation)
			dest
		end

		def eql?(other)
			return false if self.class != other.class
			return false if self.dims != other.dims
			return false if self.size != other.size
			return false if self.elem_size != other.elem_size
			return false if self.continuous? != other.continuous?

			# Ok compare contents. A Google search shows various ways to do this.
			# We will use the built in comparison operators.
			#
			# The Mat== operator compares element by element. If two elements meet the criteria,
			# in this case ==, then the returned value is 255 otherwise 0. See
			# https://docs.opencv.org/4.x/d1/d10/classcv_1_1MatExpr.html#details
			#
			# So if we check for inequality, then pixels that are the same would return 0 and ones
			# that are not the same would return 255. It is a lot easier to check the sum if it
			# adds up to zero, so we use inequality.
			# Also see https://stackoverflow.com/a/32440830

			expr = self != other
			result = expr.to_mat.sum
			result == Cv::Scalar.new(0, 0, 0, 0) ? true : false
		end

		def eq(other)
			compare(other, Cv::CmpTypes::CMP_EQ)
		end

		def gt(other)
			compare(other, Cv::CmpTypes::CMP_GT)
		end

		def ge(other)
			compare(other, Cv::CmpTypes::CMP_GE)
		end

		def lt(other)
			compare(other, Cv::CmpTypes::CMP_LT)
		end

		def le(other)
			compare(other, Cv::CmpTypes::CMP_LE)
		end

		def ne(other)
			compare(other, Cv::CmpTypes::CMP_NE)
		end

		def bitwise_and(other, mask: nil)
			dest = self.clone
			Cv::bitwise_and(self.input_array, other.input_array, dest.output_array, mask&.input_array)
			dest
		end

		def bitwise_or(other, mask: nil)
			dest = self.clone
			Cv::bitwise_or(self.input_array, other.input_array, dest.output_array, mask&.input_array)
			dest
		end

		def bitwise_xor(other, mask: nil)
			dest = self.clone
			Cv::bitwise_xor(self.input_array, other.input_array, dest.output_array, mask&.input_array)
			dest
		end

		def bitwise_not(mask: nil)
			dest = self.clone
			Cv::bitwise_not(self.input_array, dest.output_array, mask&.input_array)
			dest
		end

		def absdiff(other)
			dest = self.class.new(self.rows, self.cols, self.type)
			Cv::absdiff(self.input_array, other.input_array, dest.output_array)
			dest
		end

		def adaptive_threshold(max_value, adaptive_method, threshold_type, block_size, c)
			dest = self.class.new(self.rows, self.cols, self.type)
			Cv::adaptive_threshold(self.input_array, dest.output_array, max_value, adaptive_method, threshold_type, block_size, c)
			dest
		end

		def apply_color_map(colormap)
			dest = self.class.new(self.rows, self.cols, self.type)
			Cv::apply_color_map(self.input_array, dest.output_array, colormap)
			dest
		end

		def bilateral_filter(d, sigma_color, sigma_space, border_type: Cv::BorderTypes::BORDER_DEFAULT)
			dest = self.class.new(self.rows, self.cols, self.type)
			Cv::bilateral_filter(self.input_array, dest.output_array, d, sigma_color, sigma_space, border_type)
			dest
		end

		def blur(ksize, anchor: Cv::Point.new(-1,-1), border_type: Cv::BorderTypes::BORDER_DEFAULT)
			dest = self.class.new(self.rows, self.cols, self.type)
			Cv::blur(self.input_array, dest.output_array, ksize, anchor, border_type)
			dest
		end

		def convert_scale_abs(alpha: 1, beta: 0)
			dest = self.class.new
			Cv::convert_scale_abs(self.input_array, dest.output_array, alpha, beta)
			dest
		end

		alias :convert_to_cpp :convert_to
		def convert_to(type, alpha, double, beta = 0)
			dest = self.class.new(self.rows, self.cols, self.type)
			self.convert_to_cpp(dest.output_array, alpha, double, beta)
			dest
		end

		def copy_make_border(top, bottom, left, right, border_type, value: Cv::Scalar.new)
			dest = self.class.new(self.rows, self.cols, self.type)
			Cv::copy_make_border(self.input_array, dest.output_array, top, bottom, left, right, border_type, value)
			dest
		end

		def corner_eigen_vals_and_vecs(block_size, ksize, border_type: Cv::BorderTypes::BORDER_DEFAULT)
			dest = Cv::Mat6f.new(self.rows, self.cols)
			Cv::corner_eigen_vals_and_vecs(self.input_array, dest.output_array, block_size, ksize, border_type)
			dest
		end

		def corner_harris(block_size, ksize, k, border_type: Cv::BorderTypes::BORDER_DEFAULT)
			dest = Cv::Mat1f.new(self.rows, self.cols)
			Cv::corner_harris(self.input_array, dest.output_array, block_size, ksize, k, border_type)
			dest
		end

		def corner_min_eigen_val(block_size, ksize: 3, border_type: Cv::BorderTypes::BORDER_DEFAULT)
			dest = Cv::Mat1f.new(self.rows, self.cols)
			Cv::corner_min_eigen_val(self.input_array, dest.output_array, block_size, ksize, border_type)
			dest
		end

		def corner_sub_pix(corners, win_size, zero_zone, criteria)
			Cv::corner_sub_pix(self.input_array, corners.input_output_array, win_size, zero_zone, criteria)
			corners
		end

		def count_non_zero
			Cv.count_non_zero(self.input_array)
		end

		def cvt_color(color_conversion_code, dst_cn: 0, hint: Cv::AlgorithmHint::ALGO_HINT_DEFAULT)
			dest = self.class.new(self.rows, self.cols, self.type)
			Cv::cvt_color(self.input_array, dest.output_array, color_conversion_code, dst_cn, hint)
			dest
		end

		def determinant
			Cv.determinant(self.input_array)
		end

		def dilate(kernel, anchor = Cv::Point.new(-1,-1), iterations = 1,
							 border_type = Cv::BorderTypes::BORDER_CONSTANT, border_value = Cv::morphology_default_border_value)
			dest = self.class.new(self.rows, self.cols, self.type)
			Cv::dilate(self.input_array, dest.output_array, kernel.input_array, anchor, iterations, border_type, border_value)
			dest
		end

		def draw_chessboard_corners(pattern_size, corners, pattern_was_found)
			Cv.draw_chessboard_corners(self.input_output_array, pattern_size, corners, pattern_was_found)
			self
		end

		def draw_contours(contours, contour_idx, color, thickness: 1, line_type: Cv::LineTypes::LINE_8,
											hierarchy: Cv::no_array, max_level: INT_MAX, offset: Cv::Point.new)
			contours_input = Cv::InputArray.new(contours)
			hierarchy_input = Cv::InputArray.new(hierarchy)
			Cv.draw_contours(self.input_output_array, contours_input, contour_idx, color, thickness, line_type,
											 hierarchy_input, max_level, offset)
		end

		def eigen
			eigen_values = self.class.new
			eigen_vectors = self.class.new(self.cols, self.rows, self.type)
			Cv.eigen(self.input_array, eigen_values.output_array, eigen_vectors.output_array)
			[eigen_values, eigen_vectors]
		end

		def equalize_hist
			dest = self.class.new(self.cols, self.rows, self.type)
			Cv.equalize_hist(self.input_array, dest.output_array)
			dest
		end

		def erode(kernel, anchor: Cv::Point.new(-1,-1), iterations: 1,
							border_type: Cv::BorderTypes::BORDER_CONSTANT, border_value: Cv::morphology_default_border_value)
			dest = self.class.new(self.rows, self.cols, self.type)
			Cv::erode(self.input_array, dest.output_array, kernel.input_array, anchor, iterations, border_type, border_value)
			dest
		end

		def filter_2d(ddepth, kernel, anchor: Cv::Point.new(-1,-1), delta: 0, border_type: Cv::BorderTypes::BORDER_DEFAULT)
			dest = self.class.new(self.rows, self.cols, self.type)
			Cv::filter_2d(self.input_array, dest.output_array, ddepth, kernel.input_array, anchor, delta, border_type)
			dest
		end

		def find_chessboard_corners(pattern_size, flags: Cv::CALIB_CB_ADAPTIVE_THRESH | Cv::CALIB_CB_NORMALIZE_IMAGE)
			mat = Cv::Mat2f.new
			corners = Cv::OutputArray.new(mat)
			found = Cv::find_chessboard_corners(self.input_array, pattern_size, corners, flags)
			[mat, found]
		end

		def find_contours(mode, method, offset: Cv::Point.new)
			contours = Std::Vector≺vector≺cv꞉꞉Point_≺int≻≻≻.new
			contours_output = Cv::OutputArray.new(contours)

			hierarchy = Std::Vector≺Cv꞉꞉Vec4i≻.new
			hierarchy_output = Cv::OutputArray.new(hierarchy)

			Cv.find_contours(self.input_array, contours_output, hierarchy_output, mode, method, offset)
			[contours, hierarchy]
		end

		def flip(flip_code)
			dest = self.class.new(self.cols, self.rows, self.type)
			Cv.flip(self.input_array, dest.output_array, flip_code)
			dest
		end

		def flood_fill(mask, seed_point, new_val, lo_diff: Cv::Scalar.new, up_diff: Cv::Scalar.new,
									 connectivity: 4, fill_value: 1, fill_flags: 0)
			rect = Cv::Rect.new
			flags = connectivity | (fill_value << 8) | fill_flags
			area = Cv::flood_fill(self.input_output_array, mask.input_output_array, seed_point, new_val,
						        			 rect, lo_diff, up_diff, flags)
			[area, rect]
		end

		def gaussian_blur(ksize, sigma_x, sigma_y: 0, border_type: Cv::BorderTypes::BORDER_DEFAULT, hint: Cv::AlgorithmHint::ALGO_HINT_DEFAULT)
			dest = self.class.new(self.rows, self.cols, self.type)
			Cv::gaussian_blur(self.input_array, dest.output_array, ksize, sigma_x, sigma_y, border_type, hint)
			dest
		end

		def get_rect_sub_pix(patch_size, center, patch_type: -1)
			patch = Cv::Mat.new
			Cv::get_rect_sub_pix(self.input_array, patch_size, center, patch.output_array, patch_type)
			patch
		end

		def good_features_to_track(max_corners, quality_level, min_distance,
															 mask: nil, block_size: 3, use_harris_detector: false, k: 0.04)
			corners = Cv::Mat.new
			Cv::good_features_to_track(self.input_array, corners.output_array, max_corners, quality_level, min_distance,
																 mask ? mask.input_array : Cv::no_array, block_size, use_harris_detector, k)
			corners
		end

		def hough_circles(method, dp, min_dist, param1: 100, param2: 100, min_radius: 0, max_radius: 0)
			result = Std::Vector≺Cv꞉꞉Vec3f≻.new
			circles = Cv::OutputArray.new(result)
			Cv::hough_circles(self.input_array, circles, method, dp, min_dist, param1, param2, min_radius, max_radius)
			result
		end

		def hough_lines(rho, theta, threshold, srn: 0, stn: 0, min_theta: 0, max_theta: CV_PI, use_edgeval: false)
			result = Std::Vector≺Cv꞉꞉Vec2f≻.new
			lines = Cv::OutputArray.new(result)
			Cv::hough_lines(self.input_array, lines, rho, theta, threshold, srn, stn, min_theta, max_theta, use_edgeval)
			result
		end

		def inpaint(mask, inpaint_radius, flags)
			dest = self.class.new(self.rows, self.cols, self.type)
			Cv::inpaint(self.input_array, mask.input_array, dest.output_array, inpaint_radius, flags)
			dest
		end

		def in_range(lowerb, upperb)
			dest = self.class.new(self.rows, self.cols, CV_8UC1)
			Cv::in_range(self.input_array, lowerb.input_array, upperb.input_array, dest.output_array)
			dest
		end

		def integral(sdepth: -1, sqdepth: -1)
			sum = Cv::Mat.new
			sqsum = Cv::Mat.new
			tilted = Cv::Mat.new

			Cv::integral(self.input_array, sum.output_array, sqsum.output_array, tilted.output_array, sdepth, sqdepth)
			[sum, sqsum, tilted]
		end

		def invert(flags: Cv::DecompTypes::DECOMP_LU)
			dest = self.class.new(self.cols, self.rows, self.type)
			Cv.invert(self.input_array, dest.output_array, flags)
			dest
		end

		def log_polar(center, m, flags)
			dest = self.class.new(self.rows, self.cols, self.type)
			Cv::log_polar(self.input_array, dest.output_array, center, m, flags)
			dest
		end

		def lut(lut)
			dest = self.class.new(self.rows, self.cols, lut.type)
			Cv::lut(self.input_array, lut.input_array, dest.output_array)
			dest
		end

		def match_template(template, method, mask: Cv::no_array)
			dest = Cv::Mat.new
			Cv::match_template(self.input_array, template.input_array, dest.output_array, method, mask = Cv::no_array)
			dest
		end

		def median_blur(ksize)
			dest = self.class.new(self.rows, self.cols, self.type)
			Cv::median_blur(self.input_array, dest.output_array, ksize)
			dest
		end

		def min_max_loc(mask: nil)
			Cv.min_max_loc(self.input_array, mask ? mask.input_array : Cv::no_array)
		end

		def morphology_ex(op, kernel, anchor: Cv::Point.new(-1,-1), iterations: 1,
							        border_type: Cv::BorderTypes::BORDER_CONSTANT, border_value: Cv::morphology_default_border_value)
			dest = self.class.new(self.rows, self.cols, self.type)
			Cv::morphology_ex(self.input_array, dest.output_array, op, kernel.input_array, anchor, iterations, border_type, border_value)
			dest
		end

		def mul_transposed(ata: true, delta: Cv::no_array, scale: 1, dtype: -1)
			dest = self.class.new(self.rows, self.cols, self.type)
			Cv.mul_transposed(self.input_array, dest.output_array, ata, delta, scale, dtype)
			dest
		end

		def normalize(alpha: 1, beta: 0, norm_type: Cv::NormTypes::NORM_L2, dtype: -1, mask: nil)
			dest = self.class.new(self.rows, self.cols, self.type)
			Cv.normalize(self.input_array, dest.input_output_array, alpha, beta, norm_type, dtype, mask ? mask.input_array : Cv::no_array)
			dest
		end

		def perspective_transform(matrix)
			dest = self.class.new(self.rows, self.cols, self.type)
			Cv.perspective_transform(self.input_array, dest.output_array, matrix.input_array)
			dest
		end

		def pre_corner_detect(ksize, border_type: Cv::BorderTypes::BORDER_DEFAULT)
			dest = self.class.new(self.rows, self.cols, self.type)
			Cv::pre_corner_detect(self.input_array, dest.output_array, ksize, border_type)
			dest
		end

		def pyr_down(dstsize: Cv::Size.new(), border_type: Cv::BorderTypes::BORDER_DEFAULT)
			dest = self.class.new(dstsize, self.type)
			Cv::pyr_down(self.input_array, dest.output_array, dstsize, border_type)
			dest
		end

		def pyr_mean_shift_filtering(sp, sr, max_level: 1, termcrit: Cv::TermCriteria.new(Cv::TermCriteria::Type::MAX_ITER | Cv::TermCriteria::Type::EPS, 5, 1))
			dest = self.class.new(self.rows, self.cols, self.type)
			Cv::pyr_mean_shift_filtering(self.input_array, dest.output_array, sp, sr, max_level, termcrit)
			dest
		end

		def pyr_up(dstsize: Cv::Size.new(), border_type: Cv::BorderTypes::BORDER_DEFAULT)
			dest = self.class.new(dstsize, self.type)
			Cv::pyr_up(self.input_array, dest.output_array, dstsize, border_type)
			dest
		end

		def rand_shuffle(iter_factor: 1.0, rng: nil)
			Cv::rand_shuffle(self.input_output_array, iter_factor, rng)
			self
 	 	end

		def remap(map1, map2, interpolation, border_mode: Cv::BorderTypes::BORDER_CONSTANT, border_value: Cv::Scalar.new)
			dest = self.class.new(map1.rows, map1.cols, self.type)
			Cv::remap(self.input_array, dest.output_array,
								map1.input_array, map2.input_array,
								interpolation, border_mode, border_value)
			dest
		end

		def split
			channels = Std::Vector≺cv꞉꞉Mat≻.new
			output_array = Cv::OutputArray.new(channels)
			Cv.split(self.input_array, output_array)
			channels
		end

		def sum
			Cv.sum(self.input_array)
		end

		def threshold(threshold, max_value, threshold_type)
			dest = self.class.new(self.rows, self.cols, self.type)
			computed = Cv::threshold(self.input_array, dest.output_array, threshold, max_value, threshold_type)
			[dest, computed]
		end

		def trace
			Cv.trace(self.input_array)
		end

		def transform(matrix)
			dest = self.class.new(self.rows, self.cols, self.type)
			Cv.transform(self.input_array, dest.output_array, matrix.input_array)
			dest
		end

		def transpose
			dest = self.class.new(self.rows, self.cols, self.type)
			Cv.transpose(self.input_array, dest.output_array)
			dest
		end

		def warp_affine(m, dsize, flags: Cv::InterpolationFlags::INTER_LINEAR,
										border_mode: Cv::BorderTypes::BORDER_CONSTANT, border_value: Cv::Scalar.new)
			result = Cv::Mat.new
			Cv::warp_affine(self.input_array, result.output_array, m.input_array,
											dsize, flags, border_mode, border_value)
			result
		end

		def warp_perspective(transformation, dsize, flags: Cv::InterpolationFlags::INTER_LINEAR, border_type: Cv::BorderTypes::BORDER_CONSTANT, border_value: Cv::Scalar.new)
			dest = Cv::Mat.new
			Cv::warp_perspective(self.input_array, dest.output_array, transformation.input_array, dsize, flags, border_type, border_value)
			dest
		end

		def watershed(markers)
			Cv::watershed(self.input_array, markers.input_output_array)
			markers
		end

		# Drawing functions
		def circle(center, radius, color, thickness: 1, line_type: Cv::LineTypes::LINE_8, shift: 0)
			Cv::circle(self.input_output_array, center, radius, color, thickness, line_type, shift)
			self
		end

		def ellipse(center, axes, angle, start_angle, end_angle,
								color, thickness: 1, line_type: Cv::LineTypes::LINE_8, shift: 0)
			Cv::ellipse(self.input_output_array, center, axes, angle, start_angle, end_angle,
									color, thickness, line_type, shift)
			self
		end

		def ellipse_box(box, color, thickness: 1, line_type: Cv::LineTypes::LINE_8)
			Cv::ellipse(self.input_output_array, box, color, thickness, line_type)
			self
		end

		def fill_convex_poly(pts, color, line_type: Cv::LineTypes::LINE_8, shift: 0)
			Cv::fill_convex_poly(self.input_output_array, pts, color, line_type, shift)
			self
		end

		def fill_poly(pts, color, line_type: Cv::LineTypes::LINE_8, shift: 0, offset: Cv::Point.new)
			Cv::fill_poly(self.input_output_array, pts, color, line_type, shift, offset)
			self
		end

		def line(pt1, pt2, color, thickness: 1, line_type: Cv::LineTypes::LINE_8, shift: 0)
			Cv::line(self.input_output_array, pt1, pt2, color, thickness, line_type, shift)
			self
		end

		def polylines(pts, is_closed, color, thickness: 1, line_type: Cv::LineTypes::LINE_8, shift: 0)
			Cv::polylines(self.input_output_array, pts, is_closed, color, thickness, line_type, shift)
			self
		end

		def put_text(text, org, font_face, font_scale, color, thickness: 1, line_type: Cv::LineTypes::LINE_8, bottom_left_origin: false)
			Cv::put_text(self.input_output_array, text, org, font_face, font_scale, color, thickness, line_type, bottom_left_origin)
			self
		end

		def rectangle(rect: nil, pt1: nil, pt2: nil, color:, thickness: 1, line_type: Cv::LineTypes::LINE_8, shift: 0)
			if rect.nil? && (pt1.nil? || pt2.nil?)
				raise("Must specify pt1 and pt2 or rect")
			elsif !rect.nil? && (!pt1.nil? && !pt2.nil?)
				raise("Must specify pt1 and pt2 or rect")
			end
			if rect.nil?
				Cv::rectangle(self.input_output_array, pt1, pt2, color, thickness, line_type, shift)
			else
				Cv::rectangle(self.input_output_array, rect, color, thickness, line_type, shift)
			end

			self
		end
	end
end
