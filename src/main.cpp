/*
 * Copyright (c) 2011. Philipp Wagner <bytefish[at]gmx[dot]de>.
 * Released to public domain under terms of the BSD Simplified license.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the name of the organization nor the names of its contributors
 *     may be used to endorse or promote products derived from this software
 *     without specific prior written permission.
 *
 *   See <http://www.opensource.org/licenses/bsd-license>
 */
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include "colormap.hpp"

using namespace cv;
using namespace std;

void save_image(const string filename, const Mat& src, int colormap);

int main(int argc, const char *argv[]) {
    // The following lines generate the color scales for
    // the
    Mat img1 = Mat::zeros(30, 256, CV_8UC1);
	for(int i = 0; i < 256; i++) {
		Mat roi = Mat(img1, Range::all(), Range(i,i+1));
		roi += i;
	}

	string prefix("colorscale_");
	save_image(prefix + string("autumn.jpg"), img1, COLORMAP_AUTUMN);
	save_image(prefix + string("bone.jpg"), img1, COLORMAP_BONE);
	save_image(prefix + string("jet.jpg"), img1, COLORMAP_JET);
	save_image(prefix + string("winter.jpg"), img1, COLORMAP_WINTER);
	save_image(prefix + string("rainbow.jpg"), img1, COLORMAP_RAINBOW);
	save_image(prefix + string("ocean.jpg"), img1, COLORMAP_OCEAN);
	save_image(prefix + string("summer.jpg"), img1, COLORMAP_SUMMER);
	save_image(prefix + string("spring.jpg"), img1, COLORMAP_SPRING);
	save_image(prefix + string("cool.jpg"), img1, COLORMAP_COOL);
	save_image(prefix + string("hsv.jpg"), img1, COLORMAP_HSV);
	save_image(prefix + string("pink.jpg"), img1, COLORMAP_PINK);
	save_image(prefix + string("hot.jpg"), img1, COLORMAP_HOT);

	// The following lines show how to apply a colormap on a given image
	// and show it with cv::imshow example with an image
    Mat img0 = imread("img/lena.jpg");
    if(img0.empty()) {
        CV_Error(CV_StsBadArg, "The sample image for this demo seems to be empty. Please adjust your path to point to a valid image!");
    }
    Mat cm_img0;
    applyColorMap(img0, cm_img0, COLORMAP_JET);
    imshow("cm_img0", cm_img0);

    waitKey(0);

	return 0; // success!
}


void save_image(const string filename, const Mat& src, int colormap) {
    Mat cm_dst;
    applyColorMap(src, cm_dst, colormap);
    cm_dst.convertTo(cm_dst, CV_8UC3, 255.0);
    imwrite(filename, cm_dst);
}
