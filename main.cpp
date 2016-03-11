/* image_processor_bw.cpp
   CSC 205 - Spring 2016
   
   Template for a grayscale PNG image processor.
   
   B. Bird - 03/02/2016
*/
#define SHARED_LIBRARY
#define _USE_MATH_DEFINES // for PI
#define MAIN_CPP
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include "lodepng.h"
#include "png_canvas.h"
#include "gauss.h"
#include "match_histogram.h"

using namespace std;

void process_image(PNG_Canvas_BW& image){
	int width = image.get_width();
	int height = image.get_height();
	
	//Make a new image canvas for the output to avoid conflicts
	PNG_Canvas_BW outputImage(width,height);
  int number_of_pixels = width*height;
  
  auto c_gauss = [number_of_pixels] (int i) { return number_of_pixels*gauss_cumulative(i); };

  vector<double> c_g(265, 0);

  for (int i = 0; i < 256; ++i) {
    c_g[i] = c_gauss(i);
  }

  auto img_hist = make_histogram(image);

  cumulative_histogram c_img_hist(make_cumulative(img_hist));

  vector<double> ret_hist(265, 0);

  int j = 0;
  int c = 0;
  for (int i = 0; i < 256; ++i) {
    if (img_hist[j] + c <= c_g[i]) {
      c += img_hist[j];
      ret_hist[i] = img_hist[j];
      j++;
    }
  }

	for (int x = 0; x < width; x++)
		for (int y = 0; y < height; y++)
			outputImage[x][y] = ret_hist[image[x][y]];
			
			
	//Copy the result back into the provided image
	image = outputImage;
}


int main(int argc, char** argv){
	if (argc < 3){
		cerr << "Usage: " << argv[0] << " <input file> <output file>" << endl;
		return 0;
	}
	string input_filename = argv[1];
	string output_filename = argv[2];
	
	PNG_Canvas_BW canvas;
	if (!canvas.load_image(input_filename)){
		cerr << "Unable to load " << input_filename << ". Exiting..." << endl;
		return 0;
	}
	
	process_image(canvas);
	canvas.save_image(output_filename);
	
	
}
