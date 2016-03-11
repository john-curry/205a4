#ifndef MATCH_HIST
#define MATCH_HIST
#include <cmath>
#include <vector>
#include <functional>
#include <algorithm>
#include <memory>

typedef std::vector<double> cumulative_histogram;
typedef std::vector<double> histogram;

histogram empty_histogram() {
  histogram ret(256, 0);
  return ret;
}

const histogram make_histogram(PNG_Canvas_BW& image) {
  using namespace std;
  auto hist = empty_histogram();
  for (int i = 0; i < image.get_width(); ++i) {
    for (int j = 0; j < image.get_height(); ++j) {
      int intensity = (int)image[i][j];
      double value = hist[intensity] + 1;
      hist[intensity] = value;
    }
  }
  return hist;
}

const cumulative_histogram make_cumulative(const histogram& h) {
  double accum = 0;
  auto cum_hist = empty_histogram();
  for (int i = 0; i < 265; ++i) {
    accum += h[i];
    cum_hist[i] = accum;
  }
  return cum_hist;
}

const histogram match_histogram(const histogram& h, const cumulative_histogram& ch_ref) {
  using namespace std;
  auto ch       = make_cumulative(h);
  auto new_hist = empty_histogram();
  
  return new_hist;
}
#endif
