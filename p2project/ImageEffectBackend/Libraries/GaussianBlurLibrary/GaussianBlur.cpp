#include "GaussianBlur.h"

void gaussianBlur(std::vector<std::vector<Pixel>> &img, float radius)
{
    int radius_int = static_cast<int>(radius);
    int kernel_size = 2 * radius_int + 1;

    std::vector<std::vector<Pixel>> img_padded(img.size() + 2, std::vector<Pixel>(img[0].size() + 2));

    // Creating the kernel for gaussian blur
    std::vector<std::vector<float>> kernel(kernel_size, std::vector<float>(kernel_size));
    float sigma = radius / 3.0;
    float s = 2.0 * sigma * sigma;
    float sum = 0.0;

    // Generating (2r+1 x 2r+1) kernel (from -r to r) by sampling from a 2-D gaussian distribution
    for (int x = -radius_int; x <= radius_int; x++)
    {
        for (int y = -radius_int; y <= radius_int; y++)
        {
            // 2-D Gaussian distribution: (1/(2*pi*sigma^2)) * exp(-(x^2+y^2)/(2*sigma^2))
            float r_squared = static_cast<float>(x * x + y * y);
            kernel[x + radius_int][y + radius_int] = std::exp(-r_squared / s) / (M_PI * s);
            sum += kernel[x + radius_int][y + radius_int];
        }
    }

    // Normalizing the Kernel
    for (int i = 0; i < kernel_size; i++)
    {
        for (int j = 0; j < kernel_size; j++)
        {
            kernel[i][j] /= sum;
        }
    }

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

            for (int k = 0; k < kernel_size; k++)
            {
                for (int l = 0; l < kernel_size; l++)
                {
                    // Element-wise multiplication of the kernel and the image with boundary checks
                    int row_idx = i + k;
                    int col_idx = j + l;

                    if (row_idx >= 0 && row_idx < img_padded.size() && col_idx >= 0 && col_idx < img_padded[0].size()) {
                        conv_sum.r += kernel[k][l] * img_padded[row_idx][col_idx].r;
                        conv_sum.g += kernel[k][l] * img_padded[row_idx][col_idx].g;
                        conv_sum.b += kernel[k][l] * img_padded[row_idx][col_idx].b;
                    }
                }
            }

            // Clipping the values to [0, 255]
            conv_sum.r = std::max(0, std::min(255, static_cast<int>(conv_sum.r + 0.5))); // Round to nearest integer
            conv_sum.g = std::max(0, std::min(255, static_cast<int>(conv_sum.g + 0.5)));
            conv_sum.b = std::max(0, std::min(255, static_cast<int>(conv_sum.b + 0.5)));

            img[i][j] = conv_sum;
        }
    }
}