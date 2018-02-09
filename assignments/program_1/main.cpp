/**
* @ProgramName: Program-1
* @Author: Mika Morgan 
* @Description: 
*     This program reads in images stored as rgb values in a space delimited file format.
*     Various functions manipulate the images by flipping them vertically and horizontally, 
*     changing the images to grayscale, and inverting the image colors.
* @Course: 1063 Data Structures
* @Semester: Spring 2018
* @Date: 09 02 2018
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
    
    rgb(){
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
    //create a temp placeholder to store the row that will be replaced first
    rgb temp[width];

    for(int row = 0; row < (height / 2); row++){
        for(int col = 0; col < width; col++){
      
        //copy the row to be overwritten in the temp placeholder
          temp[col].r = image[row][col].r;
          temp[col].b = image[row][col].b;
          temp[col].g = image[row][col].g;
    
        //move the lower row into the higher row
          image[row][col].r = image[height - 1 - row][col].r;
          image[row][col].b = image[height - 1 - row][col].b;
          image[row][col].g = image[height - 1 - row][col].g;
      
        //move the stored higher row from the temp placeholder to the lower row
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
    //create a temp placeholder to store the col that will be replaced first
    rgb temp[height];

    for(int col = 0; col < (width / 2); col++){
     for(int row = 0; row < height; row++){
       
      //copy the col to be overwritten in the temp placeholder
        temp[row].r = image[row][col].r;
        temp[row].b = image[row][col].b;
        temp[row].g = image[row][col].g;
       
     //move the right col to be switched into the left col
        image[row][col].r = image[row][width - 1 - col].r;
        image[row][col].b = image[row][width - 1 - col].b;
        image[row][col].g = image[row][width - 1 - col].g;
       
    //move the stored left col from the temp placeholder to the right col
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
              
          //grab and store the current RGB values of each pixel
            int r = image[row][col].r;
            int g = image[row][col].g;
            int b = image[row][col].b;
              
          //find the average value of the RGB ints
            int gray = (r+g+b)/3;
              
          //reassign that average to each color in the pixel
            image[row][col].r = gray;
            image[row][col].g = gray;
            image[row][col].b = gray;
          }
      }
  }

/**
* @FunctionName: invert
* @Description: 
*     Loops through a 2D array and turns every RGB value to the color complement.
* @Params:
*    rgb** image - 2D array holding rgb values
*    int width - width of image
*    int height - height of image
* @Returns:
*    void
*/
void invert(rgb** image,int width,int height){
     for(int row = 0; row < height; row++){
        for(int col =0; col < width; col++){
              
          //grab and store the current RGB values of each pixel
            int r = image[row][col].r;
            int g = image[row][col].g;
            int b = image[row][col].b;
   
          //flip and reassign each RGB
            image[row][col].r = (255 - r);
            image[row][col].g = (255 - g);
            image[row][col].b = (255 - b);
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
    
    //Make the image grayscale
    grayScale(imgArray, width, height);
    
    //Flip the image vertically
    flipVert(imgArray, width, height);
    
    //Flip the image horizontally
    flipHorz(imgArray, width, height);
    
    //Invert each color to its complement
    invert(imgArray, width, height);
    
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
