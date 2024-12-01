#!/usr/bin/env ruby
require File.join(__dir__, 'helper')

class SparseMat_Test < OpenCVTestCase
	def test_initialize
		mat = Cv::SparseMat4f.new
		assert_equal(CV_32F, mat.depth)
		assert_equal(CV_32FC4, mat.type)
		assert_equal(4, mat.channels)
	end

	def test_initialize_with_sizes
		sizes = [10, 10]
		buffer = Rice::Buffer≺int≻.new(sizes)
		mat = Cv::SparseMat1f.new(buffer.size(), buffer)
		assert_equal(2, mat.dims)
		assert_equal(CV_32FC1, mat.depth)
		assert_equal(CV_32FC1, mat.type)
		assert_equal(1, mat.channels)
		assert_equal(0, mat.nzcount)
	end

	def test_getter
		sizes = [2, 2]
		buffer = Rice::Buffer≺int≻.new(sizes)
		sparse = Cv::SparseMat1b.new(buffer.size(), buffer)
		assert_equal(0, sparse[0, 0])

		sparse = Cv::SparseMat2b.new(buffer.size(), buffer)
		assert_equal(Cv::Vec2b.new(0, 0), sparse[0, 0])

		mat = create_mat(2, 2, CV_32SC1)
		sparse = Cv::SparseMat1i.new(mat)
		assert_equal(1, sparse[0, 0])
		assert_equal(2, sparse[0, 1])
		assert_equal(3, sparse[1, 0])
		assert_equal(4, sparse[1, 1])

		mat = create_mat(2, 2, CV_32SC2)
		sparse = Cv::SparseMat2i.new(mat)
		assert_equal(Cv::Vec2i.new(1, 1), sparse[0, 0])
		assert_equal(Cv::Vec2i.new(2, 2), sparse[0, 1])
		assert_equal(Cv::Vec2i.new(3, 3), sparse[1, 0])
		assert_equal(Cv::Vec2i.new(4, 4), sparse[1, 1])
  end

	def test_iterate
		mat = create_mat(2, 2, CV_32SC1)
		sparse = Cv::SparseMat1i.new(mat)
		assert_equal([1, 2, 3, 4], sparse.each.to_a)
	end

	def test_iterate_manual
		mat = create_mat(2, 2, CV_32SC1)
		sparse = Cv::SparseMat1i.new(mat)

		iter = sparse.begin
		finish = sparse.end

		actual = []
		while iter != finish
			actual << iter.dereference
			iter.increment
		end
		assert_equal([1, 2, 3, 4], sparse.each.to_a)
	end

	def test_node
		mat = create_mat(2, 2, CV_32SC1)
		sparse = Cv::SparseMat1i.new(mat)
		iter = sparse.begin

		node = iter.node
		assert_kind_of(Cv::SparseMat::Node, node)
		assert_equal(0, node.hashval)
		assert_equal(0, node.next)

		indexes = node.idx.to_ary(Cv::SparseMat::MAX_DIM)

		expected = [0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 2, 0, 1540483477,
								0, 0, 0, 1, 0, 3, 0, 1540483478,
								0, 0, 0, 1, 1, 4, 0, 0, 0, 192, 0]
		assert_equal(expected, indexes)
	end

	def test_test_update
		sizes = [2, 2]
		buffer = Rice::Buffer≺int≻.new(sizes)
		mat = Cv::SparseMat1b.new(buffer.size(), buffer)
		assert_equal([], mat.each.to_a)
		mat[2, 3] = 7
		mat[3, 4] = 8
		assert_equal([8, 7], mat.each.to_a)

		mat = Cv::SparseMat2b.new(buffer.size(), buffer)
		assert_equal([], mat.each.to_a)
		mat[2, 3] = Cv::Vec2b.new(4, 5)
		mat[3, 4] = Cv::Vec2b.new(6, 7)
		assert_equal([Cv::Vec2b.new(6, 7), Cv::Vec2b.new(4, 5)], mat.each.to_a)

		vec = mat[3, 4]
		vec[0] = 11
		vec[1] = 12
		assert_equal([Cv::Vec2b.new(11, 12), Cv::Vec2b.new(4, 5)], mat.each.to_a)
	end
end
