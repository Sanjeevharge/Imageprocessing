#include "Flip.h"
#include<vector>
#include<math.h>
#include<algorithm>
#include "../Pixel.h"

using namespace std;

void ApplyFlip(std::vector<std::vector<Pixel>>& image, int horizontalFlipValue, int verticalFlipValue){
     if (verticalFlipValue != 0){
        reverse(image.begin(), image.end());
        //to reverse the whole picture when verticle flip value not equal to 0
    }

    if (horizontalFlipValue != 0){
        for (vector<Pixel>& row : image) {
            reverse(row.begin(), row.end());
            //to reverse the row values when horizontal flip value is not equal to 0
        }
    }


 }
