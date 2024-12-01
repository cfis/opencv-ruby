#!/usr/bin/env ruby
# -*- mode: ruby; coding: utf-8 -*-

# Eigenfaces sample in opencv-ruby, equivalent to http://docs.opencv.org/trunk/_downloads/facerec_eigenfaces.cpp
# See http://docs.opencv.org/trunk/modules/contrib/doc/facerec/facerec_tutorial.html
require 'opencv'
include OpenCV

def norm_0_255(src)
  dst = nil
  case src.channel
  when 1
    dst = src.normalize(0, 255, CV_NORM_MINMAX, CV_8UC1)
  when 2
    dst = src.normalize(0, 255, CV_NORM_MINMAX, CV_8UC3)
  else
    dst = src.copy
  end

  dst
end

def read_csv(filename, sepalator = ';')
  images = []
  labels = []
  open(filename, 'r') { |f|
    f.each { |line|
      path, label = line.chomp.split(sepalator)
      images << CvMat.load(path, CV_LOAD_IMAGE_GRAYSCALE)
      labels << label.to_i
    }
  }

  [images, labels]
end

if ARGV.size < 1
  puts "usage: ruby #{__FILE__} <csv.ext> <output_folder>"
  exit 1
end
fn_csv = ARGV.shift
output_folder = ARGV.shift

images, labels = read_csv(fn_csv);

height = images[0].rows;

# The following lines simply get the last images from your dataset and remove it
# from the vector. This is done, so that the training data (which we learn the
# cv::FaceRecognizer on) and the test data we test the model with, do not overlap.
test_sample = images.pop
test_label = labels.pop

# The following lines create an Eigenfaces model for
# face recognition and train it with the images and
# labels read from the given CSV file.
# This here is a full PCA, if you just want to keep
# 10 principal components (read Eigenfaces), then call
# the factory method like this:
#
#      EigenFaces.new(10)
#
# If you want to create a FaceRecognizer with a
# confidence threshold (e.g. 123.0), call it with:
#
#      EigenFaces.new(10, 123.0)
#
# If you want to use _all_ Eigenfaces and have a threshold,
# then call the method like this:
#
#      EigenFaces.new(0, 123.0)
#
model = EigenFaces.new
model.train(images, labels)

# The following line predicts the label of a given test image:
predicted_label, predicted_confidence = model.predict(test_sample)

puts "Predicted class: #{predicted_label} / Actual class: #{test_label}"

eigenvalues = model.get_mat('eigenvalues')
w = model.get_mat('eigenvectors');
mean = model.get_mat('mean')

if output_folder
  norm_0_255(mean.reshape(1, images[0].rows)).save("#{output_folder}/mean.png")
else
  w1 = GUI::Window.new('Predicted')
  w2 = GUI::Window.new('Actual')
  w3 = GUI::Window.new('mean')

  w1.show images[predicted_label]
  w2.show images[test_label]
  w3.show norm_0_255(mean.reshape(1, images[0].rows))
end

# Display or save the Eigenfaces:
[w.cols, 10].min.times { |i|
  puts "Eigenvalue ##{i} = #{eigenvalues[i][0]}"
  ev = w.get_cols(i).clone()
  grayscale = norm_0_255(ev.reshape(1, height))

  # Show the image & apply a Jet colormap for better sensing.
  cgrayscale = grayscale.apply_color_map(COLORMAP_JET)
  if output_folder
    norm_0_255(cgrayscale).save("#{output_folder}/eigenface_#{i}.png")
  else
    w4 = GUI::Window.new("eigenface_#{i}")
    w4.show norm_0_255(cgrayscale)
  end
}

[w.cols, 10].min.step([w.cols, 300].min, 15) { |num_components|
  # slice the eigenvectors from the model
  evs = w.get_cols(0..num_components)
  projection = images[0].reshape(1, 1).subspace_project(evs, mean)
  reconstruction = projection.subspace_reconstruct(evs, mean)

  # Normalize the result:
  reconstruction = norm_0_255(reconstruction.reshape(1, images[0].rows))

  # Display or save:
  if output_folder
    norm_0_255(reconstruction).save("#{output_folder}/eigenface_reconstruction_#{num_components}.png")
  else
    w5 = GUI::Window.new("eigenface_reconstruction_#{num_components}")
    w5.show norm_0_255(reconstruction)
  end
}

GUI::wait_key unless output_folder

