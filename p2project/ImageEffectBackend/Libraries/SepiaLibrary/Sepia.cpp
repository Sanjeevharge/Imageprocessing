#include "Sepia.h"
#include <vector>
using namespace std;
// tr = 0.393 * r + 0.769 * g + 0.189 * b
// tg = 0.349 * r + 0.686 * g + 0.168 * b
// tb = 0.272 * r + 0.534 * g + 0.131 * b


// Function to apply sepia tone effect to an image represented as a vector of pixels
void applySepia(vector<vector<Pixel>> &imageVector)
{
    // Get the dimensions of the image
    int imageWidth = imageVector.size();
    int imageHeight = imageVector[0].size();

    // Loop through each pixel in the image
    for (int j = 0; j < imageHeight; j++)
    {
        for (int i = 0; i < imageWidth; i++)
        {
            // Extract RGB values of the current pixel
            int r = imageVector[i][j].r;
            int g = imageVector[i][j].g;
            int b = imageVector[i][j].b;

            // Calculate sepia-toned RGB values using weighted averages
            int sepiaR = (int)(0.393 * r + 0.769 * g + 0.189 * b);
            int sepiaG = (int)(0.349 * r + 0.686 * g + 0.168 * b);
            int sepiaB = (int)(0.272 * r + 0.534 * g + 0.131 * b);

            // Check if sepia RGB values exceed 255, and update accordingly
            if (sepiaR > 255)
            {
                imageVector[i][j].r = 255;
            }
            else
            {
                imageVector[i][j].r = sepiaR;
            }

            if (sepiaG > 255)
            {
                imageVector[i][j].g = 255;
            }
            else
            {
                imageVector[i][j].g = sepiaG;
            }

            if (sepiaB > 255)
            {
                imageVector[i][j].b = 255;
            }
            else
            {
                imageVector[i][j].b = sepiaB;
            }
        }
    }
}

