
#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class SVDTest < OpenCVTestCase
	def test_svd
		rows = 2
		cols = 3
		mat = create_mat(rows, cols, CV_32FC1) do |j, i, c|
			c + 1.0
		end

		svd = Cv::SVD.new(mat.input_array)
		assert_equal([9.508031845092773, 0.7728697657585144], svd.w.to_a)
		assert_equal([0.3863177001476288, -0.9223657846450806, 0.9223657846450806, 0.3863177001476288], svd.u.to_a)
		assert_equal([0.4286671280860901, 0.5663068890571594, 0.7039467692375183, 0.8059637546539307, 0.11238240450620651, -0.5811992287635803], svd.vt.to_a)
	end
end
