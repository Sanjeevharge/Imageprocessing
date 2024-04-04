#include "Sharpen.h"

void sharpen(std::vector<std::vector<Pixel>> &img, float amt)
{
    amt -= 50;
    // Vector of dimensions height+2 and width+2 (Original vector padded with zeros)
    std::vector<std::vector<Pixel>> img_padded(img.size() + 2, std::vector<Pixel>(img[0].size() + 2));

    // Sharpen kernel used in convolution
    std::vector<std::vector<float>> kernel = {
        {-amt, -amt, -amt},
        {-amt, 1 + 8 * amt, -amt},
        {-amt, -amt, -amt}
    };

    // Copying the image into the padded vector
    for (int i = 0; i < img.size(); i++)
    {
        for (int j = 0; j < img[0].size(); j++)
        {
            img_padded[i + 1][j + 1] = img[i][j];
        }
    }

    // Applying convolution
    for (int i = 0; i < img.size(); i++)
    {
        for (int j = 0; j < img[0].size(); j++)
        {
            // Convolution output for a particular pixel
            Pixel conv_sum;
            conv_sum.r = 0;
            conv_sum.g = 0;
            conv_sum.b = 0;

            for (int k = 0; k < kernel.size(); k++)
            {
                for (int l = 0; l < kernel[0].size(); l++)
                {
                    conv_sum.r += kernel[k][l] * img_padded[i + k][j + l].r;
                    conv_sum.g += kernel[k][l] * img_padded[i + k][j + l].g;
                    conv_sum.b += kernel[k][l] * img_padded[i + k][j + l].b;
                }
            }

            // Clipping the values to [0, 255]
            conv_sum.r = std::max(0, std::min(255, static_cast<int>(conv_sum.r)));
            conv_sum.g = std::max(0, std::min(255, static_cast<int>(conv_sum.g)));
            conv_sum.b = std::max(0, std::min(255, static_cast<int>(conv_sum.b)));

            img[i][j] = conv_sum;
        }
    }
}
