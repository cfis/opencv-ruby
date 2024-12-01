# DEVELOPER'S NOTE

## Requirement to develop opencv-ruby

* OpenCV
* Git
* Microsoft Visual C++ (for mswin32)
  * <http://www.microsoft.com/visualstudio/eng/downloads#d-2010-express>
* MinGW and MSYS (for mingw32)
  * gcc, g++ and MSYS are needed.
  * <http://www.mingw.org>
* Some gems (see Gemfile)
  * [bundler](https://github.com/carlhuda/bundler/)
  * [hoe](https://github.com/seattlerb/hoe)
  * [hoe-gemspec](https://github.com/flavorjones/hoe-gemspec)
  * [rake-compiler](https://github.com/luislavena/rake-compiler)


## Create opencv-ruby gem
Run the following commands.
When you use mingw32, use **MSYS console**, or when you use mswin32,
use [**Visual Studio Command Prompt**](http://msdn.microsoft.com/en-us/library/ms229859.aspx)
instead of cmd.exe.

```
$ git clone git://github.com/opencv-ruby/opencv-ruby.git
$ cd opencv-ruby
$ git checkout master
$ bundle install
$ git ls-files > Manifest.txt
$ rake gem:spec
$ rake gem
```
**opencv-ruby-x.y.z.gem** will be created in **pkg** directory.

To create pre-build binaries, create a config file firstly:

```yml
# config.yml
platform: mingw32
rubies:
  - C:/ruby-1.9.3-p392-mingw32/bin/ruby.exe
  - C:/ruby-2.0.0-p0-mingw32/bin/ruby.exe
extopts:
  - --with-opencv-include=C:/opencv/build/include
  - --with-opencv-lib=C:/opencv/build/x86/mingw/lib
```

Entries are below:

- **platform**: Target platform (e.g. mingw32, mswin32)
- **rubies**: Array of target versions of ruby's paths (You can create fat gems if you specify multiple versions of ruby)
- **extopts**: Array of options to be passed to **extconf.rb**

Then, run the following command:

```
$ rake gem:precompile CONFIG=config.yml
```

**opencv-ruby-x.y.z-mingw32.gem** will be created when you use mingw32, or
**opencv-ruby-x.y.z-x86-mswin32.gem** when you use mswin32.


## Install opencv-ruby manually
### Linux/Mac

```
$ git clone git://github.com/opencv-ruby/opencv-ruby.git
$ cd opencv-ruby
$ git checkout master
$ ruby ext/opencv/extconf.rb --with-opencv-dir=/path/to/opencvdir
$ make
$ make install
```

Note: **/path/to/opencvdir** is the directory where you installed OpenCV.


### Windows (mswin32)

Run the following commands on [**Visual Studio Command Prompt**](http://msdn.microsoft.com/en-us/library/ms229859.aspx).

```
$ git clone git://github.com/opencv-ruby/opencv-ruby.git
$ cd opencv-ruby
$ git checkout master
$ ruby ext/opencv/extconf.rb --with-opencv-dir=C:\path\to\opencvdir\install  # for your own built OpenCV library
$ nmake
$ nmake install
```

To use pre-built OpenCV libraries, set the following option to extconf.rb.

```
$ ruby ext/opencv/extconf.rb --with-opencv-include=C:\path\to\opencvdir\build\include --with-opencv-lib=C:\path\to\opencvdir\build\x86\vc10\lib
```


### Windows (mingw32)

Run the following commands on **MSYS console**.

```
$ git clone git://github.com/opencv-ruby/opencv-ruby.git
$ cd opencv-ruby
$ git checkout master
$ ruby ext/opencv/extconf.rb --with-opencv-dir=/C/path/to/opencvdir/install  # for your own built OpenCV library
$ make
$ make install
```

To use pre-built OpenCV libraries, set the following option to extconf.rb.

```
$ ruby ext/opencv/extconf.rb --with-opencv-include=/c/path/to/opencvdir/build/include --with-opencv-lib=/c/path/to/opencvdir/build/x86/mingw/lib
```


## Run tests

To run all tests, run **test/runner.rb**

```
$ cd opencv-ruby/test
$ ruby runner.rb
```

To run tests of the specified function, run a specific test with --name option.

The following sample runs tests for CvMat#initialize

```
$ cd opencv-ruby/test
$ ruby test_cvmat.rb --name=test_initialize
```

