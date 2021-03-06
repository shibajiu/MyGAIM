// MyGAIM.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

#include "Define.h"

int main() {
	var impath = "f://liver_in_apple_d.jpg";
	var temppath = "";
	var templateimg = cv::imread(impath);
	var tsize = templateimg.size();
	cv::Mat dst;
	cv::Point2f srctri[3], dsttri[3];

	
	float origindegree = 45;
	float delta = 10;
	for (size_t i = 0; i < 5; i++) {
		var imcos = cosf((delta*i + origindegree)*3.14f / 180.f);
		if (imcos > 0) {
			srctri[0] = { 0,(float)tsize.height };
			srctri[1] = { 0,0 };
			srctri[2] = { (float)tsize.width,(float)tsize.height };
			dsttri[0] = { 0,(float)tsize.height };
			dsttri[1] = { imcos*(float)tsize.width,0 };
			dsttri[2] = { (float)tsize.width,(float)tsize.height };
		}
		else {
			srctri[0] = { 0,0 };
			srctri[1] = { (float)tsize.width,0 };
			srctri[2] = { (float)tsize.width,(float)tsize.height };
			dsttri[0] = { 0,0 };
			dsttri[1] = { (float)tsize.width,0 };
			dsttri[2] = { (float)tsize.width,(float)tsize.height };
		}
		var affinet = cv::getAffineTransform(srctri, dsttri);
		cv::Size dsize = templateimg.size() + cv::Size(abs(imcos*templateimg.size().width), 0);
		cv::warpAffine(templateimg, dst, affinet, dsize);
		cv::imshow("affine", dst);
		cv::waitKey();
	}
}
