#include "Brightness.h"
void applyBrightness(vector<vector<Pixel>> &imageVector,float &amount)
{
    int imageWidth = imageVector.size();
    int imageHeight = imageVector[0].size();
    amount -= 50.0f;
    for(int j = 0; j < imageHeight; j++)
    {
        for(int i = 0; i < imageWidth; i++)
        {
            int r = imageVector[i][j].r;
            int g = imageVector[i][j].g;
            int b = imageVector[i][j].b;

            //calculate brightR,brightG,brightB
            int brightG = static_cast<int> ( g + amount );
            int brightB = static_cast<int> ( b + amount );
            int brightR = static_cast<int> ( r + amount ) ;

            //Conditions to check if RGB values have exceeded 255
            try{
            if(brightR > 255)
            // for brightR when pixel value greater than 255
            {
                imageVector[i][j].r = 255;
            }
            else if(brightR < 0)
            {
                imageVector[i][j].r = 0;
                //when brightR isless than 0
            }
            }
            else
            {
                throw brightR;
            }
            }catch(int brightR){
                imageVector[i][j].r = brightR;
            }
            try{
            if(brightG > 255)
            {
                imageVector[i][j].g = 255;
                //when brightG is greater than 255
            }
            else if(brightG < 0)
            {
		//when brightG lesser than 0
                imageVector[i][j].g = 0;
            }
            else
            {
                imageVector[i][j].g = brightG;
            }
            }catch(int brightG){
                imageVector[i][j].g = brightG;
            }
            try{
            if(brightB > 255)
            {
            	//when brightB is greater than 255
                imageVector[i][j].b = 255;
            }
            else if(brightB < 0)
            {
                imageVector[i][j].b = 0;
                //when brightB is lesser than 0
            }
            else
            {
                imageVector[i][j].b = brightB;
            }
            }catch(int brightB){
                imageVector[i][j].b = brightB;
            }
        }
    }
}
