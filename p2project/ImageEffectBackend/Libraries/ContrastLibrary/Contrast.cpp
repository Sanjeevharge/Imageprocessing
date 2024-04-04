#include "Contrast.h"
#include <vector>
using namespace std;

void applyContrast(vector< vector<Pixel> > &imageVector,float &amount)
{
    int imageWidth = imageVector.size();
    int imageHeight = imageVector[0].size();
    for(int j = 0; j < imageHeight; j++)
    {
        for(int i = 0; i < imageWidth; i++)
        {
        //storing the values
            int r = imageVector[i][j].r;
            int g = imageVector[i][j].g;
            int b = imageVector[i][j].b;

            //calculate contrastR,contrastG,contrastB
            int contrastR = (int)( amount * ( r - 128 ) + 128 );
            int contrastG = (int)( amount * ( g - 128 ) + 128 );
            int contrastB = (int)( amount * ( b - 128 ) + 128 );

            //Conditions to check if RGB values have exceeded 255
            if(contrastR > 255)
            {
                imageVector[i][j].r = 255;
                //when value of contrastR greater than 255 set it back to 255
            }
            else
            {
                imageVector[i][j].r = contrastR;
                //when otherwise set it to that value only
            }
            if(contrastG > 255)
            {
                imageVector[i][j].g = 255;
                //when value of contrastR greater than 255 set it back to 255
            }
            else
            {
                imageVector[i][j].g = contrastG;
                //when otherwise set it to that value only
            }
            if(contrastB > 255)
            {
                imageVector[i][j].b = 255;
                //when value of contrastR greater than 255 set it back to 255
            }
            else
            {
                imageVector[i][j].b = contrastB;
                //when otherwise set it to that value only
            }
        }
    }
}
