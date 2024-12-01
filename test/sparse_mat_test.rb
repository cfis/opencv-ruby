#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class SparseMatTest < OpenCVTestCase
	def test_initialize
		mat = Cv::SparseMat.new
		assert_equal(CV_8U, mat.depth)
		assert_equal(CV_8U, mat.type)
		assert_equal(1, mat.channels)
		assert_kind_of(Rice::Buffer≺int≻, mat.size)
		assert_equal(0, mat.dims)
		assert_equal(0, mat.nzcount)
	end

	def test_initialize_with_sizes
		sizes = [10, 10]
		buffer = Rice::Buffer≺int≻.new(sizes)
		mat = Cv::SparseMat.new(buffer.size, buffer, CV_32FC1)
		assert_equal(CV_32FC1, mat.depth)
		assert_equal(CV_32FC1, mat.type)
		assert_equal(1, mat.channels)
		assert_equal(2, mat.dims)
		assert_equal(0, mat.nzcount)
	end

	def test_header
		mat = create_mat(2, 2, CV_32SC1)
		sparse = Cv::SparseMat1i.new(mat)
		header = sparse.hdr

		assert_equal(1, header.refcount)
		assert_equal(2, header.dims)
		assert_equal(24, header.value_offset)
		assert_equal(32, header.node_size)
		assert_equal(4, header.node_count)
		assert_equal(160, header.free_list)

		pool = header.pool
		assert_kind_of(Std::Vector≺unsigned char≻, pool)
		assert_equal(256, pool.size)

		hashtab = header.hashtab
		assert_kind_of(Std::Vector≺unsigned Int64≻, hashtab)
		assert_equal(8, hashtab.size)
	end
end
