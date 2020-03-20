// 3.20-2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include<opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;


int main()
{
	cv::Mat a = imread("D:\\coin.png", 0);
	cv::Mat d, out, s,e,otsu;
	cv::threshold(a, d, 0, 255, THRESH_OTSU);
	int z = cv::connectedComponentsWithStats(d,
		out,
		s,
		e,
		8,
		CV_32S);
	for (int i = 0; i < z; i++) {
		Rect b;
		b.x = s.at<int>(i, 0);
		b.y = s.at<int>(i, 1);
		b.width = s.at<int>(i, 2);
		b.height = s.at<int>(i, 3);
		rectangle(d, b, CV_RGB(255, 255, 255), 1, 8, 0);


}
	cout << "the total of connected Components=" << z - 1 << endl;
	imshow("���",d ); 
	waitKey(0);
    return 0;
}

