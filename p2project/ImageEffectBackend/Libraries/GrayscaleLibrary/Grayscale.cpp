#include "Grayscale.h"

void grayscale(vector<vector<Pixel>> &img)
{
    // Function to convert an image to grayscale
    for (int i = 0; i < img.size(); i++)
    {
        for (int j = 0; j < img[0].size(); j++)
        {
            int gray = (img[i][j].r + img[i][j].g + img[i][j].b) / 3;
            img[i][j].r = gray;
            img[i][j].g = gray;
            img[i][j].b = gray;
            //setting the values of pixel to grey
        }
    }
}
