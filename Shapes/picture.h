#include<iostream>
#include<fstream>
#include"rgbtriple.h"

using namespace std;

#pragma once

struct FileHeader
{
	char fileType[2];
	unsigned long bfSize;
	unsigned short bfReserved1;
	unsigned short bfReserved2;
	unsigned long bfOffBits;
};

struct InfoHeader
{
	unsigned long biSize;
	unsigned long biWidth;
	unsigned long biHeight;
	unsigned short biPlanes;
	unsigned short biBitCount;
	unsigned long biCompression;
	unsigned long biSizeImage;
	unsigned long biXPixelsPerMeter;
	unsigned long biYPixelsPerMeter;
	unsigned long biClrUsed;
	unsigned long biClrImportant;
	
	unsigned long PixelCount;	//# of pixles in file
};

const RGBTriple fillColor(255, 255, 255);
const int shapeWidth = 500;
const int shapeHeight = 500;

class Picture
{
	private:

		Picture();

		static Picture* picture;
		Picture(Picture& junk); //disable copy constructor

		FileHeader fileHeader;
		InfoHeader infoHeader;
		RGBTriple* pixels;

		void InitializeFileHeader(int height, int width);
		void InitializeInfoHeader(int height, int width);
		void WriteFileHeader(ofstream& fout) const;
		void WriteInfoHeader(ofstream& fout) const;
	public:
		static Picture& getInstance();
		void WriteToFile(const char* FileName) const;
		void SetPixelColor(int x, int y, RGBTriple color);
		void AddLine(int xStart, int yStart, int xEnd, int yEnd, RGBTriple color);
		int width();
		int height();
};

