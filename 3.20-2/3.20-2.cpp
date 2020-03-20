// 3.20-2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;


int main()
{
	cv::Mat a = imread("D:\\coin.png", 0);
	cv::Mat b, c, d,e;
	cv::threshold(a, b, 0, 255, THRESH_OTSU);
	int z = cv::connectedComponentsWithStats(b,
		c,
		d,
		e,
		8,
		CV_32S);
	for (int i = 0; i < z; i++) {
		cout << "connectef Components NO." << i << endl;
		cout << "pixels=" << d.at<int>(i, 4) << endl;
		cout << "width=" << d.at<int>(i, 2) << endl;
		cout << "height=" << d.at<int>(i, 3) << endl;
		cout << endl;


}
	cout << "the total of connected Components=" << z - 1 << endl;
	imshow("d", d);
	waitKey(0);

    return 0;
}

