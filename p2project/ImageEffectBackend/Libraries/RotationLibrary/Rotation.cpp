#include "Rotation.h"

// Function to transpose an image represented as a vector of pixels
void transpose(vector<vector<Pixel>> &imageVector)
{
    // Get the number of rows and columns in the image
    int r = imageVector.size();
    int c = imageVector[0].size();

    // Create a temporary vector to store the transposed image
    vector<vector<Pixel>> temp(c, vector<Pixel>(r));

    // Loop through each element in the original image and assign it to the transposed matrix
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            temp[j][i] = imageVector[i][j];

    // Update the original image vector with the transposed matrix
    imageVector = temp;
}

// Function to flip an image horizontally (left to right)
void flip(vector<vector<Pixel>> &imageVector)
{
    // Get the number of rows and columns in the image
    int r = imageVector.size();
    int c = imageVector[0].size();

    // Create a temporary vector to store the flipped image
    vector<vector<Pixel>> temp(r, vector<Pixel>(c));

    // Loop through each element in the original image and assign it to the flipped matrix
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            temp[i][j] = imageVector[i][c - j - 1];

    // Update the original image vector with the flipped matrix
    imageVector = temp;
}

// Function to apply rotation to an image (90 degrees increments)
void applyRotation(vector<vector<Pixel>> &imageVector, int val)
{
    // Rotate the image based on the specified rotation value
    if (val == 1)
    {
        // Transpose and flip the image once (90 degrees)
        transpose(imageVector);
        flip(imageVector);
    }
    else if (val == 2)
    {
        // Transpose and flip the image twice (180 degrees)
        transpose(imageVector);
        flip(imageVector);
        transpose(imageVector);
        flip(imageVector);
    }
    else if (val == 3)
    {
        // Transpose and flip the image thrice (270 degrees)
        transpose(imageVector);
        flip(imageVector);
        transpose(imageVector);
        flip(imageVector);
        transpose(imageVector);
        flip(imageVector);
    }
    else
    {
        // Do nothing if an invalid rotation value is provided
        return;
    }
}

