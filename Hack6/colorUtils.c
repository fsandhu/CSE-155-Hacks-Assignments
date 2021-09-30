/**
  * Author: Fateh Karan Singh Sandhu & SungHa Park
  * Date:   September 27, 2018
  *
  * This file contains all the function codes.
  *
  **/

#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include "colorUtils.h"

double max (double a, double b, double c) {

    double maxValue;

    if (a>=b && a>=c) {
      maxValue = a;
    } else if (b>=c && b>=a) {
      maxValue = b;
    } else {
      maxValue = c;
    }

    return maxValue;

}

double min (double a, double b, double c) {

  double minValue;

  if (a<=b && a<=c) {
    minValue = a;
  } else if (b<=c && b<=a) {
    minValue = b;
  } else {
    minValue = c;
  }

  return minValue;

}

int rgbToCMYK (int r, int g, int b, double *c, double *m, double *y, double *k) {

  if (c == NULL || m == NULL || y == NULL || k == NULL) {
    return 1;
  }
  
  double r1 = (double) r/255;
  double g1 = (double) g/255;
  double b1 = (double) b/255;

  if (r > 255 || g > 255 || b > 255) {
    return 1;
  }


  if (r < 0 || g < 0 || b < 0) {
    return 1;
  }

  *k =  1 - ( max (r1, g1, b1) );
  *c = (1 - r1 - (*k)) / (1 - (*k));
  *m = (1 - g1 - (*k)) / (1 - (*k));
  *y = (1 - b1 - (*k)) / (1 - (*k));

  return 0;

}

int cmykToRGB (double c, double m, double y, double k, int *r, int *g, int *b) {

  if (r == NULL || g == NULL || b == NULL) {
    return 1;
  }

    if (c < 0 || m < 0 || y < 0 || k < 0) {
      return 1;
    }

    if (c > 1 || m > 1 || y > 1 || k > 1) {
      return 1;
    }

   *r = round (255 * (1 - c) * (1 - k));
   *g = round (255 * (1 - m) * (1 - k));
   *b = round (255 * (1 - y) * (1 - k));

   return 0;

}

int toGrayScale (int *r, int *g, int *b, Mode m) {

    int grayScale;

    if (r == NULL || g == NULL || b == NULL) {
      return 1;
    }

    if (*r > 255 || *r < 0) {
      return 1;
    }

    if (*g > 255 || *g < 0) {
      return 1;
    }

    if (*b > 255 || *b < 0) {
      return 1;
    }



    if (m == AVERAGE) {

      grayScale = round (( (*r) + (*g) + (*b) ) / 3.0);

      (*r) = grayScale;
      (*g) = grayScale;
      (*b) = grayScale;

      return 0;

   } else if (m == LIGHTNESS) {

    grayScale = round (( max (*r, *g, *b) + min (*r, *g, *b) ) / 2.0);

    (*r) = grayScale;
    (*g) = grayScale;
    (*b) = grayScale;

    return 0;

  } else if (m == LUMINOSITY) {

    grayScale = round (0.21 * (*r) + 0.72 * (*g) + 0.07 * (*b));

    (*r) = grayScale;
    (*g) = grayScale;
    (*b) = grayScale;

    return 0;

  } else {
    return 1;
  }

}
