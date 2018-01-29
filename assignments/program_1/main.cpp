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
    
    rbg(){
        r = 0;
        g = 0;
        b = 0;
    }
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
    rgb temp[width] = {0};

for(int row = 0; row < (height / 2); row++){
  for(int col = 0; col < width; col++){
    temp[col].r = image[row][col].r;
    temp[col].b = image[row][col].b;
    temp[col].g = image[row][col].g;
      
    image[row][col].r = image[height - 1 - row][col].r;
    image[row][col].b = image[height - 1 - row][col].b;
    image[row][col].g = image[height - 1 - row][col].g;
      
    image[height - 1 - row][col].r = temp[col].r;
    image[height - 1 - row][col].b = temp[col].b;
    image[height - 1 - row][col].g = temp[col].g;
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
    temp[row].r = image[row][col].r;
    temp[row].b = image[row][col].b;
    temp[row].g = image[row][col].g;
       
    image[row][col].r = image[row][width - 1 - col].r;
    image[row][col].b = image[row][width - 1 - col].b;
    image[row][col].g = image[row][width - 1 - col].g;
       
    image[row][width - 1 - col].r = temp[row].r;
    image[row][width - 1 - col].b = temp[row].b;
    image[row][width - 1 - col].g = temp[row].g;
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
        for(int row = 0; row < height; row++){
          for(int col =0; col < width; col++){
              int r = image[row][col].r;
              int g = image[row][col].g;
              int b = image[row][col].b;
              
              int gray = (r+g+b)/3;
              
              image[row][col].r = gray;
              image[row][col].g = gray;
              image[row][col].b = gray;
          }
      }
  }
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
