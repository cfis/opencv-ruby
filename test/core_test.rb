#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class CoreTest < OpenCVTestCase
	def test_add_weighted
		mat1 = create_mat(3, 2, CV_8UC1) { |j, i, c| c + 1 }
		mat2 = create_mat(3, 2, CV_8UC1) { |j, i, c| (c + 1) * 10 }
		mat3 = Cv::Mat.new
		alpha = 2.0
		beta = 0.1
		gamma = 100
		Cv.add_weighted(mat1.input_array, alpha, mat2.input_array, beta, gamma, mat3.output_array)
		assert_equal(mat1.class, mat3.class)
		assert_equal(mat1.rows, mat3.rows)
		assert_equal(mat1.cols, mat3.cols)
		assert_equal(mat1.depth, mat3.depth)
		assert_equal(mat1.channels, mat3.channels)

		mat1.rows.times do |j|
			mat1.cols.times do |i|
				expected = mat1[j, i] * alpha + mat2[j, i] * beta + gamma
				assert_equal(expected, mat3[j, i])
			end
		end
	end

	def test_convert_scale_abs
		mat1 = create_mat(2, 3, CV_8UC4) do |j, i, c|
			Cv::Vec4b.new(c, c, c, c)
		end

		mat2 = mat1.convert_scale_abs
		assert_equal("dd671da8f8262597637b4b047464ccda", hash_img(mat2))
	end

	def test_eigen
		elems = [6.0, -2.0, -3.0, 7.0]
		mat1 = create_mat(2, 2, CV_32FC1) do |j, i, c|
			elems[c]
		end
		values, vectors = mat1.eigen
		assert_equal([8.561553001403809, 4.438446998596191], values.to_a)
		assert_equal([-0.615412175655365, 0.7882053852081299, 0.7882053852081299, 0.615412175655365], vectors.to_a)
	end

	def test_flip
		mat1 = create_mat(2, 3, CV_8UC1)
		mat2 = mat1.clone.flip(0)
		mat3 = mat1.clone.flip(1)
		mat4 = mat1.clone.flip(-1)

		expected = [1, 2, 3,
								4, 5, 6]
		assert_equal(expected, mat1.to_a)

		expected = [4, 5, 6,
		            1, 2, 3]
		assert_equal(expected, mat2.to_a)

		expected = [3, 2, 1,
								6, 5, 4]
		assert_equal(expected, mat3.to_a)

		expected = [6, 5, 4,
								3, 2, 1]
		assert_equal(expected, mat4.to_a)
	end

	def test_lut
		mat1 = create_mat(2, 3, CV_8UC3)
		lut_mat = create_mat(1, 256, CV_8UC3) do |j, i, c|
			Cv::Vec3b.new(255 - c, 255 - c, 255 - c)
		end
		mat2 = mat1.lut(lut_mat)

		mat1.rows.times do |j|
			mat1.cols.times do |i|
				r, g, b = mat1[j, i].to_a.map { |c| 255 - c }
				assert_equal(Cv::Vec3b.new(r, g, b), mat2[j, i])
			end
		end
	end

	def test_merge
		mat1 = create_mat(2, 3, CV_8UC4) do |j, i, c|
			Cv::Vec4b.new(c * 10, c * 20, c * 30, c * 40)
		end

		mat2 = create_mat(2, 3, CV_8UC1) do |j, i, c|
			c * 10
		end

		mat3 = create_mat(2, 3, CV_8UC1) do |j, i, c|
			c * 20
		end

		mat4 = create_mat(2, 3, CV_8UC1) do |j, i, c|
			c * 30
		end

		mat5 = create_mat(2, 3, CV_8UC1) do |j, i, c|
			c * 40
		end

		vector = Std::Vector≺cv꞉꞉Mat≻.new([mat2, mat3, mat4, mat5])
		input = Cv::InputArray.new(vector)
		mat6 = Cv::Mat.new(mat2.rows, mat2.cols, mat2.type)
		Cv::merge(input, mat6.output_array)

		assert_equal(mat1.to_a, mat6.to_a)
	end

	def test_merge_image
		image_path = self.sample_path("starry_night.jpg")
		image = Cv::imread(image_path, Cv::ImreadModes::IMREAD_COLOR)
		channels = image.split

		output_array = Cv::InputArray.new(channels)
		merged = Cv::Mat.new
		Cv.merge(output_array, merged.output_array)

		assert_equal(image.cols, merged.cols)
		assert_equal(image.rows, merged.rows)
		assert_equal(image.type, merged.type)
		assert_equal(image, merged)
	end



	def test_rand_shuffle
		mat1 = create_mat(2, 3, CV_8UC1)
		mat2 = mat1.clone.rand_shuffle(iter_factor: 123)
		assert_equal([5, 1, 6, 2, 4, 3], mat2.to_a)

		mat3 = mat1.clone.rand_shuffle(rng: Cv::RNG.new)
		assert_equal([5, 1, 6, 2, 4, 3], mat3.to_a)
	end

	def test_split
		mat1 = create_mat(2, 3, CV_8UC3) do |j, i, c|
			Cv::Vec3b.new(c * 10, c * 20, c * 30)
		end
		channels = mat1.split
		assert_equal(mat1.channels, channels.size)
		channels.each_with_index do |mat, idx|
			assert_equal(Cv::Mat, mat.class)
			assert_equal(mat1.rows, mat.rows)
			assert_equal(mat1.cols, mat.cols)
			assert_equal(1, mat.channels)
			c = 0
			mat1.rows.times do |row|
				mat1.cols.times do |col|
					expected = c * 10 * (idx + 1)
					actual = mat[row, col]
					assert_equal(expected, actual)
					c += 1
			  end
			end
		end
	end

	def test_split_image
		image_path = self.sample_path("starry_night.jpg")
		image = Cv::imread(image_path, Cv::ImreadModes::IMREAD_COLOR)
		channels = image.split
		assert_equal(3, channels.size)
		channels.each do |channel|
			assert_equal(channel.cols, image.cols)
			assert_equal(channel.rows, image.rows)
			assert_equal(CV_8UC1, channel.type)
		end
	end
end
