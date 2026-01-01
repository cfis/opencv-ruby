#!/usr/bin/env ruby
# To make testing/debugging easier test within this source tree versus an installed gem
require 'bundler/setup'

# Now load code
require 'digest'
require 'opencv-ruby'
require 'minitest/autorun'

class OpenCVTestCase < Minitest::Test
  #FILENAME_CAT = self.sample_path('cat.jpg')
  #FILENAME_FRUITS = self.sample_path('fruits.jpg')
  #FILENAME_CONTOURS = File.join(__dir__, 'samples', 'contours.jpg')
  #FILENAME_CHESSBOARD = self.sample_path('chessboard.jpg')
  #FILENAME_LINES = self.sample_path('lines.jpg')
  #HAARCASCADE_FRONTALFACE_ALT = self.sample_path('haarcascade_frontalface_alt.xml.gz')
  #AVI_SAMPLE = self.sample_path('movie_sample.avi')

  def self.sample_path(file_name)
    File.join(__dir__, 'samples', file_name)
  end

  def sample_path(file_name)
    File.join(__dir__, 'samples', file_name)
  end

  def hash_img(img)
    # This is assuming a 2d array
    size = img.step[0] * img.rows
    Digest::MD5.hexdigest(img.data.buffer.bytes(size))
  end

  def assert_cvscalar_equal(expected, actual, message = nil)
    assert_equal(Cv::Vec4b, actual.class, message)
    assert_array_equal(expected.to_a, actual.to_a, message)
  end

  def assert_array_equal(expected, actual, message = nil)
    assert_equal(expected.size, actual.size, message)
    expected.zip(actual) { |e, a|
      assert_equal(e, a, message)
    }
  end

  def assert_in_delta_array(expected, actual, delta = 0.001)
    assert_equal(expected.count, actual.count)
    expected.count.times do |i|
      assert_in_delta(expected[i], actual[i], delta)
    end
  end

  def populate_mat(mat, height, width, &block)
    count = 0
    height.times do |row|
      width.times do |column|
        mat[row, column] = block.call(row, column, count)
        count += 1
      end
    end
  end

  def create_mat(height, width, type = CV_8UC4, &block)
    mat = Cv::Mat.new(height, width, type)

    block = lambda do |j, i, count|
      if mat.channels > 1
        mat.vec_klass.new(*([count + 1] * mat.channels))
      else
        count + 1
      end
    end unless block_given?

    populate_mat(mat, height, width, &block)
    mat
  end

  def create_mat_(height, width, klass = Cv::Mat4b, &block)
    mat = klass.new(height, width, type)

    block = lambda do |j, i, count|
      vec_klass = Cv.const_get(klass.name.sub("Mat", "Vec").to_sym)
      vec_klass.new(*([count + 1] * mat.channels))
    end unless block_given?

    populate_mat(mat, height, width, &block)
    mat
  end

  def create_iplimage(width, height, depth = CV_8U, channel = 4, &block)
    m = IplImage.new(width, height, depth, channel)
    block = lambda { |j, i, c| Cv::Scalar.new(*([c + 1] * channel)) } unless block_given?
    count = 0
    height.times { |j|
      width.times { |i|
        m[j, i] = block.call(j, i, count)
        count += 1
      }
    }
    m
  end

  def assert_each_element(mat, delta = 0, &block)
    raise unless block_given?
    count = 0
    mat.rows.times do |row|
      mat.cols.times do |col|
        expected = block.call(row, col, count)
        actual = mat[row, col]
        if delta == 0
          assert_equal(expected, actual)
        else
          assert_in_delta_array(Array(expected), Array(actual), delta)
        end
        count += 1
      end
    end
  end

  def print_cvmat(mat)
    s = []
    mat.height.times { |j|
      a = []
      mat.width.times { |i|
        tmp = mat[j, i].to_ary.map {|m| m.to_f.round(2) }.join(',')
        a << "[#{tmp}]"
      }
      s << a.join(' ')
    }
    puts s.join("\n")
  end

  def count_threshold(mat, threshold, &block)
    n = 0
    block = lambda { |a, b| a > b } unless block_given?

    mat.rows.times do |row|
      mat.cols.times do |col|
        n += 1 if block.call(mat[row, col], threshold)
      end
    end
    n
  end

  def color_hists(mat)
    hists = [0] * mat.channels
    mat.rows.times do |row|
      mat.cols.times do |col|
        value = mat[row, col]
        hists.size.times do |c|
          hists[c] += value[c]
        end
      end
    end
    hists
  end

  def show_images(images, wait = 2500)
    images = images.is_a?(Array) ? images : [images]
    images.each.with_index do |image, i|
      window_name = "Image_#{i}"
      Cv::named_window(window_name, Cv::WindowFlags::WINDOW_AUTOSIZE)
      Cv::imshow(window_name, image.input_array)
    end
    Cv::wait_key(wait)
  end

  def snap(*images)
    n = -1
    images.map! { |val|
      n += 1
      if val.is_a? Hash
        val
      elsif val.is_a? Array
        {:title => val[0], :image => val[1] }
      else
        {:title => "snap-#{n}", :image => val }
      end
    }
    pos = Cv::Point.new(0, 0)
    images.each { |img|
      w = GUI::Window.new(img[:title])
      w.show(img[:image])
      w.move(pos)
      pos.x += img[:image].width
      if pos.x > 800
        pos.y += img[:image].height
        pos.x = 0
      end
    }

    GUI::wait_key
    GUI::Window::destroy_all
  end
end
