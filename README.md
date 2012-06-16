# Colormaps in OpenCV #

## Description ##

This repository implements colormaps for use in OpenCV. This version now has the same interface as the colormaps in OpenCV 2.4+, so supporting multiple versions of OpenCV is easier. 

Currently the following GNU Octave/MATLAB equivalent colormaps are implemented:

* Autumn
* Bone
* Cool
* Hot
* HSV
* Jet
* Ocean
* Pink
* Rainbow
* Spring
* Summer
* Winter

Feel free to fork the project and add your own colormaps. Please make a pull request to this branch then, so everybody can use your work.



## API ##

You only need `applyColorMap` to apply a colormap on a given image:

```cpp
void applyColorMap(InputArray src, OutputArray dst, int colormap)
```

So the following line reads an image and applies a Jet colormap on it:

```cpp
// You'll need to include the colormaps of course:
#include "colormap.hpp"

// Use the cv namespace:
using namespace cv;

// Read a sample image:
string filename = "/path/to/some/file";
Mat img0 = imread(filename);
if(img0.empty()) {
    CV_Error(CV_StsBadArg, "The sample image for this demo seems to be empty. Please adjust your path to point to a valid image!");
}

// Apply the colormap:
Mat cm_img0;
applyColorMap(img0, cm_img0, COLORMAP_JET);
imshow("cm_img0", cm_img0);

// Show the result:
waitKey(0);
```

The available colormaps are:

```cpp
enum
{
    COLORMAP_AUTUMN = 0,
    COLORMAP_BONE = 1,
    COLORMAP_JET = 2,
    COLORMAP_WINTER = 3,
    COLORMAP_RAINBOW = 4,
    COLORMAP_OCEAN = 5,
    COLORMAP_SUMMER = 6,
    COLORMAP_SPRING = 7,
    COLORMAP_COOL = 8,
    COLORMAP_HSV = 9,
    COLORMAP_PINK = 10,
    COLORMAP_HOT = 11
}
```

## Demo ##

Please have a look at the demo, to see the colormaps in action and learn how to use the colormaps. If you want to apply a Jet colormap on a given image, then call the demo with:

```
./cm_demo /path/to/your/image.ext
```

Or if you just want to generate the color scales, then call the demo with:


```
./cm_demo
```

(Replace ./cm_demo with cm_demo.exe if you are running Windows!)

## Building the demo ##

The project comes as a CMake project, so building it is as simple as:

```
philipp@mango:~/some/dir/colormaps-opencv$ mkdir build
philipp@mango:~/some/dir/colormaps-opencv$ cd build
philipp@mango:~/some/dir/colormaps-opencv/build$ cmake ..
philipp@mango:~/some/dir/colormaps-opencv/build$ make
philipp@mango:~/some/dir/colormaps-opencv/build$ ./cm_demo path/to/your/image.ext
```

Or if you use MinGW on Windows:

```
C:\some\dir\colormaps-opencv> mkdir build
C:\some\dir\colormaps-opencv> cd build
C:\some\dir\colormaps-opencv\build> cmake -G "MinGW Makefiles" ..
C:\some\dir\colormaps-opencv\build> mingw32-make
C:\some\dir\colormaps-opencv\build> cm_demo.exe /path/to/your/image.ext
```

Or if you are using Visual Studio, you can generate yourself a solution like this (please adjust to your version):

```
C:\some\dir\colormaps-opencv> mkdir build
C:\some\dir\colormaps-opencv> cd build
C:\some\dir\colormaps-opencv\build> cmake -G "Visual Studio 9 2008" ..
```
