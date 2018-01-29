/**
* @ProgramName: Program-1
* @Author: Mika Morgan 
* @Description: 
*     This program reads in images stored as rgb values in a space delimited file format.
* @Course: 1063 Data Structures
* @Semester: Spring 2018
* @Date: 28 01 2018
*/

/**
* TXT Image Manipulation Starter
* 
* This code is a simple way to read in color information stored in a space
* delimited txt format. The expected file format is:
*                ---------------------------
*                | width height            |
*                | R G B R G B R G B R G B |
*                | R G B R G B R G B R G B |
*                | R G B R G B R G B R G B |
*                | R G B R G B R G B R G B |
*                | R G B R G B R G B R G B |
*                | R G B R G B R G B R G B |
*                ---------------------------
* So a 10x10 img would have 11 total rows, 10 rows of data, with 30 values in row.
*/

#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

/**
Structure to hold an rgb value
*/
struct rgb{
    int r;
    int g;
    int b;
};

/**
* @FunctionName: flipVert
* @Description: 
*     Loops through a 2D array and swaps the rows vertically.
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
* @Returns:
*    void
*/
void flipVert(rgb** image,int width,int height){
    int temp[width] = {0};

for(int row = 0; row < (height / 2); row++){
  for(int col = 0; col < width; col++){
    temp[col] = image[row][col];
    image[row][col] = image[height - 1 - row][col];
    image[height - 1 - row][col] = temp[col];
  }
}
}

/**
* @FunctionName: flipHorz
* @Description: 
*     Loops through a 2D array and swaps the columns horizontally.
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
* @Returns:
*    void
*/

void flipHorz(rgb** image,int width,int height){
    int temp[height] = {0};

for(int col = 0; col < (width / 2); col++){
   for(int row = 0; row < height; row++){
    temp[row] = image[col][row];
    image[col][row] = image[15 - 1 - col][row];
    image[width - 1 - col][row] = temp[row];
  }
}
}

/**
* @FunctionName: grayScale
* @Description: 
*     Loops through a 2D array and turns every RGB value into its grayscale equivalent.
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
* @Returns:
*    void
*/
void grayScale(rgb** image,int width,int height){
    // your code
}

int main(){
    ifstream ifile;          //Input / output files
    ofstream ofile;
    ifile.open("bot.txt");
    ofile.open("bot2.txt");   
    
    int width;               //width of image
    int height;              //height of image
    
    rgb **imgArray;         //Pointer var for our 2D array because we         
                            //don't know how big the image will be!

    ifile>>width>>height;   //Read in width and height from top of input file
                            //We need this so we can make the array the right 
                            //size. After we get these two values, we can
                            //now allocate memory for our 2D array.

    imgArray = new rgb*[height];    //This array points to every row

    for(int i=0;i<height;i++){
        imgArray[i] = new rgb[width]; //Now allocate each row of rgb's
    }
    
    //Read the color data in from our txt file
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            ifile>>imgArray[i][j].r>>imgArray[i][j].g>>imgArray[i][j].b;            
        }
    }
    
    //We could make any changes we want to the color image here
    
    //Write out our color data to a new file
    ofile<<width<<" "<<height<<endl;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            ofile<<imgArray[i][j].r<<" "<<imgArray[i][j].g<<" "<<imgArray[i][j].b<<" ";
        }
        ofile<<endl;
    }
    
    
  return 0;
}
