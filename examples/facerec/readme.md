# Face recognition with opencv-ruby

This is a face recognition sample with opencv-ruby, which equivalent to the following OpenCV's tutorial.

[Face Recognition with OpenCV](http://docs.opencv.org/trunk/modules/contrib/doc/facerec/facerec_tutorial.html)


## Running samples

### 1. Get AT&T Facedatabase

Get AT&T Facedatabase from http://www.cl.cam.ac.uk/research/dtg/attarchive/facedatabase.html and unzip it.

```sh
$ wget http://www.cl.cam.ac.uk/Research/DTG/attarchive/pub/data/att_faces.zip
$ unzip att_faces.zip
```

### 2. Prepare the data

Create a CSV file to run samples.

```sh
$ ruby create_csv.rb att_faces > at.txt
```

You will get a CSV file which contains lines composed of a filename followed by a ; followed by the label (as integer number).

```sh
$ cat at.txt
att_faces/s34/2.pgm;0
att_faces/s34/3.pgm;0
att_faces/s34/8.pgm;0
att_faces/s34/4.pgm;0
att_faces/s34/5.pgm;0
att_faces/s34/10.pgm;0
att_faces/s34/9.pgm;0
att_faces/s34/7.pgm;0
att_faces/s34/6.pgm;0
att_faces/s34/1.pgm;0
...
```

### 3. Run sample codes

#### Eigenfaces

```sh
$ mkdir output-eigenfaces
$ ruby facerec_eigenfaces.rb at.txt output-eigenfaces
```

You will get the predicted class, actual class and eignvalues shown in console.

```sh
Predicted class: 39 / Actual class: 39
Eigenvalue #0 = 2823424.500638128
Eigenvalue #1 = 2062015.3818895558
Eigenvalue #2 = 1090171.0771557507
Eigenvalue #3 = 892019.3644237233
Eigenvalue #4 = 818537.7917991373
Eigenvalue #5 = 539058.2364753223
Eigenvalue #6 = 390359.3231975121
Eigenvalue #7 = 373809.5486713626
Eigenvalue #8 = 314658.94374918053
Eigenvalue #9 = 288764.63018440653
```

The result images will be stored in **output-eigenfaces** .


#### Fisherfaces

```sh
$ mkdir output-fisherfaces
$ ruby facerec_fisherfaces.rb at.txt output-fisherfaces
```

You will get the predicted class, actual class and eignvalues like Eigenfaces sample.

The result images will be stored in **output-fisherfaces** .


#### Local Binary Patterns Histograms

```sh
$ ruby facerec_lbph.rb at.txt
```

You will get the predicted class, actual class, model information and size of the histgrams.

```
Predicted class: 39 / Actual class: 39
Predicted class = -1
Model Information:
        LBPH(radius=1, neighbors=8, grid_x=8, grid_y=8, threshold=0.0)
Size of the histograms: 16384
```

## Credits

### The Database of Faces

The Database of Faces, formerly The ORL Database of Faces, contains a set of face images taken between April 1992 and April 1994. The database was used in the context of a face recognition project carried out in collaboration with the Speech, Vision and Robotics Group of the Cambridge University Engineering Department.

There are ten different images of each of 40 distinct subjects. For some subjects, the images were taken at different times, varying the lighting, facial expressions (open / closed eyes, smiling / not smiling) and facial details (glasses / no glasses). All the images were taken against a dark homogeneous background with the subjects in an upright, frontal position (with tolerance for some side movement).

The files are in PGM format. The size of each image is 92x112 pixels, with 256 grey levels per pixel. The images are organised in 40 directories (one for each subject), which have names of the form sX, where X indicates the subject number (between 1 and 40). In each of these directories, there are ten different images of that subject, which have names of the form Y.pgm, where Y is the image number for that subject (between 1 and 10).

A copy of the database can be retrieved from: http://www.cl.cam.ac.uk/research/dtg/attarchive/pub/data/att_faces.zip.

