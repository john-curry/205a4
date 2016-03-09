#ifndef GAUSS_H
#define GAUSS_H
#define _USE_MATH_DEFINES // for PI
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
double gaussian(double, double sigma = 40, double mu = 50);
double gaussian(double, double, double);

double gaussian(double x, double sigma, double mu) {
  using namespace std;
  // A e^-(B**2/C)
  double A = 1.0/(sigma*sqrt(2*3.14));
  double B = -pow(x - mu, 2.0);
  double C = 2*pow(sigma, 2.0);
  return A * exp(B/C);
}

double gauss_cumulative(double x, double sigma = 50, double mu = 128) {
  double accum = 0;
  for (int i = 0; i < x; ++i) {
    accum += gaussian(i, sigma, mu);
  }
  return accum;
}
#endif

