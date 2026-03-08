#include "Renderer.h"
#include "../Float.h"

#include <iostream>
#include <fstream>

constexpr int DEFAULT_IMAGE_SIZE = 256;
constexpr int MAX_COLOR = 255;

int main(int argc, char** argv){
    if (argc < 2 || argc > 4){
        std::cerr << "Usage Options: \n";
        std::cerr << "Option 1: sky <out_file_name> \n";
        std::cerr << "  Note: this will output a 256 x 256 image\n";
        std::cerr << "Option 2: sky <out_file_name> [size]\n";
        std::cerr << "  Note: this will output an image of size x size\n";
        std::cerr << "Option 3: sky <out_file_name> [width] [height]\n";
        std::cerr << "  Note: this will output an image of width x height\n";
        return 1;
    }

    int image_width = (argc >= 3) ? std::stoi(argv[2]) : DEFAULT_IMAGE_SIZE;
    int image_height = (argc >= 4) ? std::stoi(argv[3]) : image_width;
    
    std::ofstream image(argv[1]);
    if (!image) {
        std::cerr << "Error: Could not open file " << argv[1] << "\n";
        return 1;
    }

   Renderer renderer(image_width, image_height, ONE);
   renderer.render(image);
}