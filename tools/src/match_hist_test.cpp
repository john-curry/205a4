#ifndef MAIN_CPP
#define MAIN_CPP
#include "match_histogram.h"
#include "gauss.h"
#include "lodepng.h"
#include "png_canvas.h"

int main(int argc, char ** argv) {
  if (argc < 2) {
    exit(1);
  }
  for (int i = 1; i < argc; ++i) {
    int x = atoi(argv[i]);
    std::cout << gauss_cumulative(x) << std::endl;
  }
  return 0;
}
#endif
