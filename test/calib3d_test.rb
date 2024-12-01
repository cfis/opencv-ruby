require File.join(__dir__, 'helper')

class Calib3dTest < OpenCVTestCase
	FILENAME_CHESSBOARD = self.sample_path('chessboard.jpg')

	def test_find_chessboard_corners
	  mat = Cv::imread(FILENAME_CHESSBOARD, Cv::ImreadModes::IMREAD_GRAYSCALE)
	  pattern_size = Cv::Size.new(4, 4)
	  corners1, found1 = mat.find_chessboard_corners(pattern_size)
	  corners2, found2 = mat.find_chessboard_corners(pattern_size, flags: Cv::CALIB_CB_ADAPTIVE_THRESH)
	  corners3, found3 = mat.find_chessboard_corners(pattern_size, flags: Cv::CALIB_CB_NORMALIZE_IMAGE)
	  corners4, found4 = mat.find_chessboard_corners(pattern_size, flags: Cv::CALIB_CB_FILTER_QUADS)
	  corners5, found5 = mat.find_chessboard_corners(pattern_size, flags: Cv::CALIB_CB_FAST_CHECK)

		assert([found1, found2, found3, found4, found5].all?(true))

	  expected = [[39, 39], [79, 39], [119, 39], [159, 39], [39, 79], [79, 79],
	              [119, 79], [159, 78], [38, 119], [79, 119], [119, 119], [158, 118],
	              [39, 159], [79, 159], [119, 159], [159, 159]]

	  [corners1, corners2, corners3, corners4, corners5].each do |corners|
	    assert_equal(Cv::Size.new(1, 16), corners.size.to_size)
	    expected.zip(corners).each do |e, corner|
	      assert_in_delta(e[0], corner[0], 3.0)
	      assert_in_delta(e[1], corner[1], 3.0)
 		  end
		end
	end

	def test_draw_chessboard_corners
		mat = Cv::imread(FILENAME_CHESSBOARD, Cv::ImreadModes::IMREAD_GRAYSCALE)
		pattern_size = Cv::Size.new(4, 4)
		corners, found = mat.find_chessboard_corners(pattern_size)
		mat.draw_chessboard_corners(pattern_size, corners.input_array, found)
		assert_equal("c762721cc77eca2031797843acc74586", hash_img(mat))
		show_images([mat])
	end

	def test_find_corner_sub_pix
	  mat = Cv::imread(FILENAME_CHESSBOARD, Cv::ImreadModes::IMREAD_GRAYSCALE)
	  pattern_size = Cv::Size.new(4, 4)
	  corners, found = mat.find_chessboard_corners(pattern_size)
		assert(found)
		assert_equal(Cv::Size.new(1, 16), corners.size.to_size)

		mat.corner_sub_pix(corners, Cv::Size.new(3, 3), Cv::Size.new(-1, -1),
		 							    Cv::TermCriteria.new(Cv::TermCriteria::Type::COUNT, 20, 0.03))

	  expected = [[39, 39], [79, 39], [119, 39], [159, 39], [39, 79], [79, 79],
	              [119, 79], [159, 78], [38, 119], [79, 119], [119, 119], [158, 118],
	              [39, 159], [79, 159], [119, 159], [159, 159]]

		expected.zip(corners).each do |e, corner|
	    assert_in_delta(e[0], corner[0], 3.0)
	    assert_in_delta(e[1], corner[1], 3.0)
		end
	end

	def test_find_fundamental_mat
		points1 = [[488.362, 169.911],
							 [449.488, 174.44],
							 [408.565, 179.669],
							 [364.512, 184.56],
							 [491.483, 122.366],
							 [451.512, 126.56],
							 [409.502, 130.342],
							 [365.5, 134.0],
							 [494.335, 74.544],
							 [453.5, 76.5],
							 [411.646, 79.5901],
							 [366.498, 81.6577],
							 [453.5, 76.5],
							 [411.646, 79.5901],
							 [366.498, 81.6577]]

		points2 =  [[526.605, 213.332],
								[470.485, 207.632],
								[417.5, 201.0],
								[367.485, 195.632],
								[530.673, 156.417],
								[473.749, 151.39],
								[419.503, 146.656],
								[368.669, 142.565],
								[534.632, 97.5152],
								[475.84, 94.6777],
								[421.16, 90.3223],
								[368.5, 87.5],
								[475.84, 94.6777],
								[421.16, 90.3223],
								[368.5, 87.5]]

		# 7 Points
		vec1 = Std::Vector≺Cv꞉꞉Point2f≻.new(points1[0...7].map {|points| Cv::Point2f.new(*points)})
		vec2 = Std::Vector≺Cv꞉꞉Point2f≻.new(points2[0...7].map {|points| Cv::Point2f.new(*points)})

		f_mat = Cv::find_fundamental_mat(Cv::InputArray.new(vec1), Cv::InputArray.new(vec2), Cv::FM_7POINT)
		expected = [0.000002, 0.000005, -0.001621,
								-0.000005, 0.000031, -0.002559,
								0.000527, -0.007424, 1.000000,
								0.000009, 0.000029, -0.010343,
								-0.000033, 0.000000, 0.014590,
								0.004415, -0.013420, 1.000000,
								0.000000, 0.000001, -0.000223,
								-0.000001, 0.000036, -0.005309,
								-0.000097, -0.006463, 1.000000]

		assert_equal(9, f_mat.rows)
		assert_equal(3, f_mat.cols)
		assert_equal(1, f_mat.channels)
		assert_in_delta_array(expected, f_mat.to_a)

		# 8 point
		vec1 = Std::Vector≺Cv꞉꞉Point2f≻.new(points1[0...8].map {|points| Cv::Point2f.new(*points)})
		vec2 = Std::Vector≺Cv꞉꞉Point2f≻.new(points2[0...8].map {|points| Cv::Point2f.new(*points)})

		f_mat = Cv::find_fundamental_mat(Cv::InputArray.new(vec1), Cv::InputArray.new(vec2), Cv::FM_8POINT)
		expected = [0.000001, 0.000004, -0.001127,
								-0.000005, 0.000038, -0.003778,
								0.000819, -0.008325, 1.000000]
		assert_equal(3, f_mat.rows)
		assert_equal(3, f_mat.cols)
		assert_equal(1, f_mat.channels)
		assert_in_delta_array(expected, f_mat.to_a)

		# RANSAC
		vec1 = Std::Vector≺Cv꞉꞉Point2f≻.new(points1.map {|points| Cv::Point2f.new(*points)})
		vec2 = Std::Vector≺Cv꞉꞉Point2f≻.new(points2.map {|points| Cv::Point2f.new(*points)})

		f_mat = Cv::find_fundamental_mat(Cv::InputArray.new(vec1), Cv::InputArray.new(vec2), Cv::FM_RANSAC)
		expected = [0.000009, 0.000028, -0.010347,
								-0.000028, -0.000001, 0.008549,
								0.004178, -0.008388, 1.000000]

		assert_equal(3, f_mat.rows)
		assert_equal(3, f_mat.cols)
		assert_equal(1, f_mat.channels)
		assert_in_delta_array(expected, f_mat.to_a)
	end

	def test_compute_correspond_epilines
		points1 = [[17, 175],
							 [370, 24],
							 [192, 456],
							 [614, 202],
							 [116, 111],
							 [305, 32],
							 [249, 268],
							 [464, 157],
							 [259, 333],
							 [460, 224]]

		points2 = [[295, 28],
							 [584, 221],
							 [67, 172],
							 [400, 443],
							 [330, 9],
							 [480, 140],
							 [181, 140],
							 [350, 265],
							 [176, 193],
							 [333, 313]]

		vec1 = Std::Vector≺Cv꞉꞉Point2f≻.new(points1.map {|points| Cv::Point2f.new(*points)})
		vec2 = Std::Vector≺Cv꞉꞉Point2f≻.new(points2.map {|points| Cv::Point2f.new(*points)})
		f_mat = Cv::find_fundamental_mat(Cv::InputArray.new(vec1), Cv::InputArray.new(vec2), Cv::FM_RANSAC)

		lines = Cv::Mat.new
		Cv::compute_correspond_epilines(Cv::InputArray.new(vec1), 1, f_mat.input_array, lines.output_array)
		assert_equal(points1.size, lines.rows)
		assert_equal(1, lines.cols)
		assert_equal(3, lines.channels)

		expected = [-0.7546336054801941, 0.6561464667320251, 204.24481201171875,
								-0.7910364270210266, 0.6117690205574036, 283.6960144042969,
								-0.5967671871185303, 0.8024144172668457, -98.03187561035156,
								-0.6034400463104248, 0.7974083423614502, -86.33197784423828,
								-0.7760567665100098, 0.6306630373001099, 250.4227752685547,
								-0.7975062131881714, 0.603310763835907, 298.3394470214844,
								-0.6616846323013306, 0.7497822642326355, 19.389528274536133,
								-0.6720855236053467, 0.7404735684394836, 39.004432678222656,
								-0.6299644112586975, 0.7766240239143372, -39.01469421386719,
								-0.6346242427825928, 0.7728208303451538, -30.563051223754883]

		assert_in_delta_array(expected, lines.map {|line| line.to_a}.flatten, 1.0e-3)
	end

	def test_find_homography
	  # Nx2
	  src = Cv::Mat.new(4, 2, CV_32FC1)
	  dst = Cv::Mat.new(4, 2, CV_32FC1)

	  # Nx3 (Homogeneous coordinates)
	  src2 = Cv::Mat.new(4, 3, CV_32FC1)
	  dst2 = Cv::Mat.new(4, 3, CV_32FC1)

	  # Homography
	  #   <src>     =>    <dst>
	  # (0, 0)      =>  (50, 0)
	  # (255, 0)    =>  (205, 0)
	  # (255, 255)  =>  (255, 220)
	  # (0, 255)    =>  (0, 275)
	  [[0, 0], [255, 0], [255, 255], [0, 255]].each_with_index do |coord, i|
	    src[i, 0] = coord[0].to_f
	    src[i, 1] = coord[1].to_f
	    src2[i, 0] = coord[0] * 2.0
	    src2[i, 1] = coord[1] * 2.0
	    src2[i, 2] = 2.0
 	  end

		[[50, 0], [205, 0], [255, 220], [0, 275]].each_with_index do |coord, i|
	    dst[i, 0] = coord[0].to_f
	    dst[i, 1] = coord[1].to_f
	    dst2[i, 0] = coord[0] * 2.0
	    dst2[i, 1] = coord[1] * 2.0
	    dst2[i, 2] = 2.0
		end

	  mat1 = Cv::find_homography(src.input_array, dst.input_array)
	  mat2 = Cv::find_homography(src.input_array, dst.input_array, Cv::RANSAC)
	  mat3 = Cv::find_homography(src.input_array, dst.input_array, Cv::LMEDS)
	  [mat1, mat2, mat3].each do |mat|
	    assert_equal(3, mat.rows)
	    assert_equal(3, mat.cols)
	    assert_equal(CV_64F, mat.depth)
	    assert_equal(1, mat.channels)

			expected = [0.7242990654205615, -0.1960784313725491, 49.99999999999994,
									7.295243760502908e-17, 0.6248854682059743, -5.315106168366404e-14,
									0.0005680776983690685, -0.001649257833974712, 1]
			assert_in_delta_array(expected, mat.to_a, 0.0001)
		end
	end
end
