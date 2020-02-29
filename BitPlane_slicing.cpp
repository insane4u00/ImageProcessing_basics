#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include <iostream>
#include <stdio.h>
using namespace std;
using namespace cv;

int main(int argc, char const *argv[]) {
  Mat src = imread(argv[1], 1);

  namedWindow("src", 1);
  imshow("src", src);
  // Split the image into different channels
  vector<Mat> rgbChannels(3);
  split(src, rgbChannels);

  // Show individual channels
  Mat g;
  g = Mat::zeros(Size(src.cols, src.rows), CV_8UC1);

  // Showing Red Channel
  // G and B channels are kept as zero matrix for visual perception
  {
    Mat img_R;
    vector<Mat> channels;
    channels.push_back(g);
    channels.push_back(g);
    channels.push_back(rgbChannels[2]);

    vector<Mat> R = channels;

    /// Merge the three channels
    merge(R, img_R);
    namedWindow("R", 1);
    imshow("R", img_R);
    namedWindow("R2", 1);
    imshow("R2", rgbChannels[2]);
  }

  // Showing Green Channel
  {
    Mat img_G;
    vector<Mat> channels;
    channels.push_back(g);
    channels.push_back(rgbChannels[1]);
    channels.push_back(g);

    vector<Mat> G = channels;

    merge(G, img_G);
    namedWindow("G", 1);
    imshow("G", img_G);
    namedWindow("G2", 1);
    imshow("G2", rgbChannels[1]);
  }

  // Showing Blue Channel
  {
    Mat img_B;

    vector<Mat> channels;
    channels.push_back(rgbChannels[0]);
    channels.push_back(g);
    channels.push_back(g);

    vector<Mat> B = channels;

    merge(channels, img_B);
    namedWindow("B", 1);
    imshow("B", img_B);
    namedWindow("B2", 1);
    imshow("B2", rgbChannels[0]);
  }

  // Showing Red Blue Channel
  {
    Mat img_RB;
    vector<Mat> channels;
    channels.push_back(rgbChannels[0]);
    channels.push_back(g);
    channels.push_back(rgbChannels[2]);

    vector<Mat> RB = channels;

    merge(RB, img_RB);
    namedWindow("RB", 1);
    imshow("RB", img_RB);
  }

  waitKey(0);
  return 0;
}