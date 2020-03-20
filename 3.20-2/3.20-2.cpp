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
	cv::Mat b, out, status,e,otsu;
	cv::threshold(a, b, 0, 255, THRESH_OTSU);
	std::vector<Mat>SrcMatpart(otsu.channels());
	split(otsu, SrcMatpart);
	int z = cv::connectedComponentsWithStats(b,
		out,
		status,
		e,
		8,
		CV_32S);
	for (int i = 0; i < z; i++) {
		cout << "connectef Components NO." << i << endl;
		cout << "pixels=" << status.at<int>(i, 4) << endl;
		cout << "width=" << status.at<int>(i, 2) << endl;
		cout << "height=" << status.at<int>(i, 3) << endl;
		cout << endl;


}
	cout << "the total of connected Components=" << z - 1 << endl;
	imshow("otsu", otsu); 
	waitKey(0);

    return 0;
}

