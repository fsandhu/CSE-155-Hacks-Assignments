/**
  * Author: Fateh Karan Singh Sandhu & SungHa Park
  * Date: 27 September 2018
  *
  * This is a header file containing all the function
  * prototypes.
  *
  **/

  typedef enum {
    AVERAGE,
    LIGHTNESS,
    LUMINOSITY
  } Mode;

  double max (double a, double b, double c);

  double min (double a, double b, double c);

  int rgbToCMYK (int r, int g, int b, double *c, double *m, double *y, double *k);

  int cmykToRGB (double c, double m, double y, double k, int *r, int *g, int *b);

  int toGrayScale (int *r, int *g, int *b, Mode m);
