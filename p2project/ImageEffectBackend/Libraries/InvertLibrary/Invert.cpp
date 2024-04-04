#include "Invert.h"
//to invert the picture
void applyInvert(vector< vector<Pixel> > &imageVector)
{
    int imageWidth = imageVector.size();
    int imageHeight = imageVector[0].size();
    for(int j = 0; j < imageHeight; j++)
    {
        for(int i = 0; i < imageWidth; i++)
        {
            int r = imageVector[i][j].r;
            int g = imageVector[i][j].g;
            int b = imageVector[i][j].b;

            //calculate invertR,invertG,invertB
            int invertR = 255 - r;
            int invertG = 255 - g;
            int invertB = 255 - b;

            //Conditions to check if RGB values have exceeded 255
            if(invertR < 0)
            {
                imageVector[i][j].r = 0;
            }
            else
            {
                imageVector[i][j].r = invertR;
            }
            if(invertG < 0)
            {
                imageVector[i][j].g = 0;
                //when the value is less than 0 set it to 0
            }
            else
            {
                imageVector[i][j].g = invertG;
                //else set it to g
            }
            if(invertB < 0)
            {
                imageVector[i][j].b = 0;
            }
            else
            {
                imageVector[i][j].b = invertB;
            }
        }
    }
}
