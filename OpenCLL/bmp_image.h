#define _CRT_SECURE_NO_DEPRECATE
#ifndef OCL_BMP_IMAGE_H
#define OCL_BMP_IMAGE_H
#include <cstdlib>
#include <iostream>
#include <string.h>
#include <stdio.h>

#ifdef WIN32
__pragma( pack(push, 1) )
#else
#pragma pack(push, 1)
#define fopen_s(pFile,filename,mode) ((*(pFile))=fopen((filename),(mode)))==NULL
#endif
    


typedef struct
{
    unsigned char x;
    unsigned char y;
    unsigned char z;
    unsigned char w;
} ColorPalette;

typedef ColorPalette PixelColor;

typedef struct {
    short id;
    int size;
    short reserved1;
    short reserved2;
    int offset;
} BMPHeader ;

typedef struct {
    unsigned int sizeInfo;
    unsigned int width;
    unsigned int height;
    unsigned short planes;
    unsigned short bitsPerPixel;
    unsigned int compression;
    unsigned int imageSize;
    unsigned int xPelsPerMeter;
    unsigned int yPelsPerMeter;
    unsigned int clrUsed;
    unsigned int clrImportant;
}  BMPInfoHeader ;



#ifdef WIN32
__pragma( pack(pop) )
#else
#pragma pack(pop)
#endif
typedef struct {
    const char * filename;
    unsigned int height;
    unsigned int width;
    void        *pixels;
    BMPInfoHeader infoHeader;
    BMPHeader     header;
    void        *storeOffset;
    int         offsetSize;
}Imagee;



static const short bitMapID = 19778;

void ReadBMPImage(std::string filename,  Imagee **image);
void ReadBMPGrayscaleImageUchar(std::string filename,  Imagee **image);
void ReadBMPGrayscaleImageFloat(std::string filename,  Imagee **image);
void WriteBMPGrayscaleImageFloat(std::string filename,  Imagee **image, float*imgBuffer);
void ReleaseBMPImage(Imagee **image);
#endif