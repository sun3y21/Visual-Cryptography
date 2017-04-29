//
//  main.cpp
//
//
//  Created by Sunnny Saini & Sonali & Diksha  on 26/02/2017
//  Copyright © 2017 Sunnny Saini & Sonali & Diksha. All rights reserved.
//

#pragma clang diagnostic ignored "-Wdocumentation"
#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include <math.h>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
int countBlack(Mat &image,int x,int y)
{
    int count = 0;
    count+=image.at<Vec4b>(x,y)[3]/255;
    count+=image.at<Vec4b>(x,y+1)[3]/255;
    count+=image.at<Vec4b>(x+1,y)[3]/255;
    count+=image.at<Vec4b>(x+1,y+1)[3]/255;
    return count;
}

void createWhiteBlock(Mat arr[],int x,int y)
{
    int k=abs(rand()%6);
    switch (k) {
        case 0:
            arr[0].at<Vec4b>(x,y)[3]=255;
            arr[0].at<Vec4b>(x,y+1)[3]=0;
            arr[0].at<Vec4b>(x+1,y)[3]=255;
            arr[0].at<Vec4b>(x+1,y+1)[3]=0;
            
            arr[1].at<Vec4b>(x,y)[3]=255;
            arr[1].at<Vec4b>(x,y+1)[3]=0;
            arr[1].at<Vec4b>(x+1,y)[3]=255;
            arr[1].at<Vec4b>(x+1,y+1)[3]=0;
            
            
            break;
        case 1:
            arr[0].at<Vec4b>(x,y)[3]=0;
            arr[0].at<Vec4b>(x,y+1)[3]=255;
            arr[0].at<Vec4b>(x+1,y)[3]=0;
            arr[0].at<Vec4b>(x+1,y+1)[3]=255;
            
            arr[1].at<Vec4b>(x,y)[3]=0;
            arr[1].at<Vec4b>(x,y+1)[3]=255;
            arr[1].at<Vec4b>(x+1,y)[3]=0;
            arr[1].at<Vec4b>(x+1,y+1)[3]=255;
            
            break;
        case 2:
            arr[0].at<Vec4b>(x,y)[3]=0;
            arr[0].at<Vec4b>(x,y+1)[3]=0;
            arr[0].at<Vec4b>(x+1,y)[3]=255;
            arr[0].at<Vec4b>(x+1,y+1)[3]=255;
            
            arr[1].at<Vec4b>(x,y)[3]=0;
            arr[1].at<Vec4b>(x,y+1)[3]=0;
            arr[1].at<Vec4b>(x+1,y)[3]=255;
            arr[1].at<Vec4b>(x+1,y+1)[3]=255;
            
            break;
        case 3:
            arr[0].at<Vec4b>(x,y)[3]=255;
            arr[0].at<Vec4b>(x,y+1)[3]=255;
            arr[0].at<Vec4b>(x+1,y)[3]=0;
            arr[0].at<Vec4b>(x+1,y+1)[3]=0;
            
            arr[1].at<Vec4b>(x,y)[3]=255;
            arr[1].at<Vec4b>(x,y+1)[3]=255;
            arr[1].at<Vec4b>(x+1,y)[3]=0;
            arr[1].at<Vec4b>(x+1,y+1)[3]=0;
            break;
        case 4:
            arr[0].at<Vec4b>(x,y)[3]=0;
            arr[0].at<Vec4b>(x,y+1)[3]=255;
            arr[0].at<Vec4b>(x+1,y)[3]=255;
            arr[0].at<Vec4b>(x+1,y+1)[3]=0;
            
            arr[1].at<Vec4b>(x,y)[3]=0;
            arr[1].at<Vec4b>(x,y+1)[3]=255;
            arr[1].at<Vec4b>(x+1,y)[3]=255;
            arr[1].at<Vec4b>(x+1,y+1)[3]=0;
            
            break;
        case 5:
            arr[0].at<Vec4b>(x,y)[3]=255;
            arr[0].at<Vec4b>(x,y+1)[3]=0;
            arr[0].at<Vec4b>(x+1,y)[3]=0;
            arr[0].at<Vec4b>(x+1,y+1)[3]=255;
            
            arr[1].at<Vec4b>(x,y)[3]=255;
            arr[1].at<Vec4b>(x,y+1)[3]=0;
            arr[1].at<Vec4b>(x+1,y)[3]=0;
            arr[1].at<Vec4b>(x+1,y+1)[3]=255;
    }
}

void createBlackBlock(Mat arr[],int x,int y)
{
    int k=abs(rand()%6);
    switch (k) {
        case 0:
            arr[0].at<Vec4b>(x,y)[3]=255;
            arr[0].at<Vec4b>(x,y+1)[3]=0;
            arr[0].at<Vec4b>(x+1,y)[3]=255;
            arr[0].at<Vec4b>(x+1,y+1)[3]=0;
            
            arr[1].at<Vec4b>(x,y)[3]=0;
            arr[1].at<Vec4b>(x,y+1)[3]=255;
            arr[1].at<Vec4b>(x+1,y)[3]=0;
            arr[1].at<Vec4b>(x+1,y+1)[3]=255;
            
            break;
        case 1:
            arr[0].at<Vec4b>(x,y)[3]=0;
            arr[0].at<Vec4b>(x,y+1)[3]=255;
            arr[0].at<Vec4b>(x+1,y)[3]=0;
            arr[0].at<Vec4b>(x+1,y+1)[3]=255;
            
            arr[1].at<Vec4b>(x,y)[3]=255;
            arr[1].at<Vec4b>(x,y+1)[3]=0;
            arr[1].at<Vec4b>(x+1,y)[3]=255;
            arr[1].at<Vec4b>(x+1,y+1)[3]=0;

            break;
        case 2:
            arr[0].at<Vec4b>(x,y)[3]=0;
            arr[0].at<Vec4b>(x,y+1)[3]=0;
            arr[0].at<Vec4b>(x+1,y)[3]=255;
            arr[0].at<Vec4b>(x+1,y+1)[3]=255;
            
            arr[1].at<Vec4b>(x,y)[3]=255;
            arr[1].at<Vec4b>(x,y+1)[3]=255;
            arr[1].at<Vec4b>(x+1,y)[3]=0;
            arr[1].at<Vec4b>(x+1,y+1)[3]=0;

            break;
        case 3:
            arr[0].at<Vec4b>(x,y)[3]=255;
            arr[0].at<Vec4b>(x,y+1)[3]=255;
            arr[0].at<Vec4b>(x+1,y)[3]=0;
            arr[0].at<Vec4b>(x+1,y+1)[3]=0;
            
            arr[1].at<Vec4b>(x,y)[3]=0;
            arr[1].at<Vec4b>(x,y+1)[3]=0;
            arr[1].at<Vec4b>(x+1,y)[3]=255;
            arr[1].at<Vec4b>(x+1,y+1)[3]=255;

            break;
        case 4:
            arr[0].at<Vec4b>(x,y)[3]=0;
            arr[0].at<Vec4b>(x,y+1)[3]=255;
            arr[0].at<Vec4b>(x+1,y)[3]=255;
            arr[0].at<Vec4b>(x+1,y+1)[3]=0;
            
            arr[1].at<Vec4b>(x,y)[3]=255;
            arr[1].at<Vec4b>(x,y+1)[3]=0;
            arr[1].at<Vec4b>(x+1,y)[3]=0;
            arr[1].at<Vec4b>(x+1,y+1)[3]=255;

            break;
        case 5:
            arr[0].at<Vec4b>(x,y)[3]=255;
            arr[0].at<Vec4b>(x,y+1)[3]=0;
            arr[0].at<Vec4b>(x+1,y)[3]=0;
            arr[0].at<Vec4b>(x+1,y+1)[3]=255;
            
            arr[1].at<Vec4b>(x,y)[3]=0;
            arr[1].at<Vec4b>(x,y+1)[3]=255;
            arr[1].at<Vec4b>(x+1,y)[3]=255;
            arr[1].at<Vec4b>(x+1,y+1)[3]=0;
        }
}
int isAtBoundary(Mat &image,int x,int y)
{
    int row=image.rows-image.rows%2;
    int col=image.cols-image.cols%2;
    if(x==row-2||y==col-2)
        return 1;
    else
        return 0;
}

bool isDiagonallyBlack(Mat &image,int x,int y)
{
    if(image.at<Vec4b>(x,y)[3]==255&&image.at<Vec4b>(x+1,y+1)[3]==255)
        return 1;
    else if(image.at<Vec4b>(x,y+1)[3]==255&&image.at<Vec4b>(x+1,y)[3]==255)
        return 1;
    else
        return 0;
}

int countNeigborBlackPixelOfBlock(Mat &image,int x,int y)
{
    int count=0;
    count+=image.at<Vec4b>(x-1,y)[3]/255;
    count+=image.at<Vec4b>(x-1,y+1)[3]/255;
    count+=image.at<Vec4b>(x,y-1)[3]/255;
    count+=image.at<Vec4b>(x,y+2)[3]/255;
    count+=image.at<Vec4b>(x+1,y-1)[3]/255;
    count+=image.at<Vec4b>(x+1,y+2)[3]/255;
    count+=image.at<Vec4b>(x+2,y)[3]/255;
    count+=image.at<Vec4b>(x+2,y+1)[3]/255;
    return count;
}

int countNeigborBlack(Mat &img,int x,int y)
{
    int count=0;
    count+=img.at<Vec4b>(x-1,y-1)[3]/255;
    count+=img.at<Vec4b>(x-1,y)[3]/255;
    count+=img.at<Vec4b>(x-1,y+1)[3]/255;
    count+=img.at<Vec4b>(x,y-1)[3]/255;
    count+=img.at<Vec4b>(x,y+1)[3]/255;
    count+=img.at<Vec4b>(x+1,y-1)[3]/255;
    count+=img.at<Vec4b>(x+1,y)[3]/255;
    count+=img.at<Vec4b>(x+1,y+1)[3]/255;
    return count;
}

int countNeigborBlackPixelOfBlackPixels(Mat &image,int x,int y)
{
    int count=0;
    if(image.at<Vec4b>(x,y)[3]==255)
    {
        count+=countNeigborBlack(image,x,y);
    }
    else
    {
        count+=countNeigborBlack(image,x,y+1);
    }
    
    if(image.at<Vec4b>(x+1,y)[3]==255)
    {
        count+=countNeigborBlack(image,x+1,y);
    }
    else
    {
        count+=countNeigborBlack(image,x+1,y+1);
    }
    return count;
}

void generateShares(string image,int n=2)
{
    Mat original=imread(image,-1);
    if(original.data==NULL)
    {
        cout<<"Error: Unable to open file: "<<image<<endl;
        exit(1);
    }
    Mat *shares=new Mat[n];
    
    for(int i=0;i<n;i++)
    {
        shares[i]=Mat(original.rows,original.cols,CV_8UC(4));
    }
    
    srand((unsigned)clock());
    for(int i=0;i<original.rows-original.rows%2;i+=2)
    {
        for(int j=0;j<original.cols-original.cols%2;j+=2)
        {
            // count number of black pixel of block with starting index (i,j)
            int n=countBlack(original,i,j);
            if(n==4||n==3)
            {
                createBlackBlock(shares,i,j);
            }
            else if(n==0||n==1)
            {
                createWhiteBlock(shares,i,j);
            }
            else
            {
                // pixel is at boundary
                if(isAtBoundary(original,i,j))
                {
                    int z=abs(rand()%2);
                    if(z==0)
                    {
                        createWhiteBlock(shares,i,j);
                    }
                    else
                    {
                        createBlackBlock(shares,i,j);
                    }
                }
                else // pixels are not at boundary
                {
                    if(isDiagonallyBlack(original,i,j))
                    {
                        if(countNeigborBlackPixelOfBlackPixels(original,i,j)>8)
                        {
                            createBlackBlock(shares,i,j);
                        }
                        else
                        {
                            createWhiteBlock(shares,i,j);
                        }
                    }
                    else
                    {
                        if(countNeigborBlackPixelOfBlock(original,i, j)>4)
                        {
                            createBlackBlock(shares,i,j);
                        }
                        else
                        {
                            createWhiteBlock(shares,i,j);
                        }
                    }
                }
            }
        }
    }
    
    //write all shares
    string shareName="share";
    for(int i=0;i<n;i++)
    {
        string shareName="share";
        shareName+=to_string(i);
        shareName+=".png";
        imwrite(shareName,shares[i]);
    }
}

void convertToBinary(string image)
{
    Mat img=imread(image,-1);
    Mat g(img.rows,img.cols,CV_8UC(4));
    for(int i=0;i<img.rows;i++)
    {
        for(int j=0;j<img.cols;j++)
        {
            if(img.at<Vec4b>(i,j)[3]>=128)
            {
                g.at<Vec4b>(i,j)[3]=0;
            }
            else
            {
                g.at<Vec4b>(i,j)[3]=255;
            }
        }
    }
    imwrite("output.png",g);
}

int main(int argc, const char * argv[]) {
    
    //convertToBinary("abc.png");
    generateShares("abc.png");
    return 0;
}
