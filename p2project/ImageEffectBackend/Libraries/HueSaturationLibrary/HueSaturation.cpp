#include "HueSaturation.h"
#include<math.h>
#include<algorithm>
//void rgb to hsv
//make changes in hsv
//reconvert back to rgb

//HSV rgbToHSV( int &r, int &g, int &b)
//{
//    HSV hsv;
//    double tempR = r / 255.0;
//    double tempG = g / 255.0;
//    double tempB = b / 255.0;
//
//    //Following are the operations on pixel values to convert from rgb to hsv
//    double colorMax = max(tempR, max(tempG, tempB));
//    double colorMin = min(tempR, min(tempG, tempB));
//    double delta = colorMax - colorMin;
//
//    //Initial Values of hue,saturaion and value
//    hsv.h = -1;
//    hsv.s = -1;
//    hsv.v = -1;
//
//    //Hue Calculation
//    if (delta == 0)
//        hsv.h = 0;
//    else if (colorMax == tempR)
//        hsv.h = fmod(60 * ((tempG - tempB) / delta) + 360, 360);
//    else if (colorMax == tempR)
//        hsv.h = fmod(60 * ((tempB - tempR) / delta) + 360, 360);
//    else if (colorMax == tempR)
//        hsv.h = fmod(60 * ((tempR - tempG) / delta) + 360, 360);
//
//    //Saturation Calculation
//    if(colorMax == 0)
//        hsv.s = 0;
//    else
//        hsv.s = (delta / colorMax) * 100;
//
//    //Value Calculation
//    hsv.v = colorMax * 100;
//
//    return hsv;
//}
//
//Pixel hsvToRGB(HSV &hsv)
//{
//    Pixel rgb;
//    float l = (max({}))
//    int cCheck = static_cast<int>(( hsv.v / 100.0 ) * ( hsv.s / 100.0 ));
//    int xCheck = static_cast<int>(cCheck * ( 1 - abs(fmod(hsv.h / 60.0, 2) - 1)));
//    int mCheck = static_cast<int>(hsv.v / 100.0 - cCheck);
//
//    //Conversion as per the conditions
//    if(hsv.h >= 0 && hsv.h < 60)
//    {
//        rgb.r = cCheck;
//        rgb.g = xCheck;
//        rgb.b = 0;
//    }
//    else if(hsv.h < 120)
//    {
//        rgb.r = xCheck;
//        rgb.g = cCheck;
//        rgb.b = 0;
//    }
//    else if(hsv.h < 180)
//    {
//        rgb.r = 0;
//        rgb.g = cCheck;
//        rgb.b = xCheck;
//    }
//    else if(hsv.h < 240)
//    {
//        rgb.r = 0;
//        rgb.g = xCheck;
//        rgb.b = cCheck;
//    }
//    else if(hsv.h < 300)
//    {
//        rgb.r = xCheck;
//        rgb.g = 0;
//        rgb.b = cCheck;
//    }
//    else if(hsv.h < 360)
//    {
//        rgb.r = cCheck;
//        rgb.g = 0;
//        rgb.b = xCheck;
//    }
//
//    rgb.r = (rgb.r + mCheck) * 255;
//    rgb.g = (rgb.g + mCheck) * 255;
//    rgb.b = (rgb.b + mCheck) * 255;
//
//    return rgb;
//}
//


// Function to apply hue and saturation adjustments to an image represented as a vector of pixels
void applyHueSaturation(vector< vector<Pixel> > &imageVector, float &saturationValue, float &hueValue)
{
    // Get the dimensions of the image
    int imageWidth = imageVector.size();
    int imageHeight = imageVector[0].size();

    // Normalize saturation value to the range [0, 1]
    float s = saturationValue / 100.0;

    // Convert hue value from degrees to the range [0, 360)
    hueValue = hueValue * 3.6;

    // Loop through each pixel in the image
    for(int j = 0; j < imageHeight; j++)
    {
        for(int i = 0; i < imageWidth; i++)
        {
            // Calculate lightness value for the current pixel
            float l = (max({imageVector[i][j].r, imageVector[i][j].g, imageVector[i][j].b}) +
                       min({imageVector[i][j].r, imageVector[i][j].g, imageVector[i][j].b})) / 200.0;

            // Calculate chroma and intermediate values for hue conversion
            float cCheck = (1 - abs(2 * l - 1)) * s;
            float xCheck = (cCheck * (1 - abs(fmod(hueValue / 60.0, 2) - 1)));
            float m = (l - cCheck);

            // Initialize variables for RGB components
            float r, g, b;

            // Apply hue transformation based on the hue value
            try
            {
                if(hueValue >= 0 && hueValue < 60)
                {
                    r = cCheck;
                    g = xCheck;
                    b = 0;
                }
                else if(hueValue < 120)
                {
                    r = xCheck;
                    g = cCheck;
                    b = 0;
                }
                else if(hueValue < 180)
                {
                    r = 0;
                    g = cCheck;
                    b = xCheck;
                }
                else if(hueValue < 240)
                {
                    r = 0;
                    g = xCheck;
                    b = cCheck;
                }
                else if(hueValue < 300)
                {
                    r = xCheck;
                    g = 0;
                    b = cCheck;
                }
                else if(hueValue < 360)
                {
                    r = cCheck;
                    g = 0;
                    b = xCheck;
                }
                else if(hueValue >= 360)
                {
                    // Throw an exception if the hue value exceeds 360
                    throw hueValue;
                    cout << "hueValue Exceeded!!!\n";
                }

                // Update the pixel's RGB components after hue transformation
                imageVector[i][j].r = (min(255, static_cast<int>(abs(r + m) * 255)));
                imageVector[i][j].g = (min(255, static_cast<int>(abs(g + m) * 255)));
                imageVector[i][j].b = (min(255, static_cast<int>(abs(b + m) * 255)));
            }
            catch(float hueValue)
            {
                // Catch and handle the exception for hue value exceeding 360
                cout << "Exception caught!!!\n";
            }
        }
    }
}

