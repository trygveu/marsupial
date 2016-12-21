/**Marsupial - ANSI C with an object pouch.
 * Author: Trygve Utstumo, Adigo AS
 * Version 1.0
 * Copyright 2016 Adigo AS
 */

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "marsupial/marsupial.h"

#define PGM_HEADER_LINES 3

/** Marsupial object.
 *  The opaque object struct, with image data.
 */
struct _marsupial_t {
  int img_width, img_height, img_maxval;
  size_t img_size;
  uint8_t *img_data;
};

/** Utility function to check error, print message and exit.
 *  @param check_condition Trigger error if this is true.
 *  @param format printf style format string, allows additional vargs.
 */
void check_error(bool error_condition, char *format, ...) {
  if (error_condition) {
    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
    exit(EXIT_FAILURE);
  }
}

/** Object constructor */
Marsupial *marsupial_new() {
  Marsupial *self = calloc(1, sizeof(Marsupial));
  return self;
}

/** Open a pgm image.
 *  We support standard pgm format without comments.
 *  @param self Marsupial object.
 *  @param filename Pgm filepath, read only. */
int marsupial_open_image(Marsupial *self, char *filename) {
  FILE *fp;
  char mode[] = "r";
  fp = fopen(filename, mode);
  check_error((fp == NULL), "Failed to open file %s\n", filename);

  char *header[PGM_HEADER_LINES] = {NULL};
  size_t len = 0;
  ssize_t read;
  int i;
  /* Read the first 3 lines of the image */
  // TODO: Support comment lines starting with #.
  for (i = 0; i < PGM_HEADER_LINES; i++) {
    read = getline(&header[i], &len, fp);
    check_error(read == -1, "Failed to read image header.\n");
  }
  /* Check image type, if this is correct we assume the image is valid
   * and continue with less caution. */
  check_error((sizeof(header[0]) < 3 || header[0][0] != 'P' ||
               !(header[0][1] == '2' || header[0][1] == '5')),
              "Invalid PGM header: %s", header[0]);
  /* Read height and width. */
  char *width_s = strsep(&header[1], " ");
  char *height_s = strsep(&header[1], " ");
  self->img_width = atoi(width_s);
  self->img_height = atoi(height_s);
  self->img_maxval = atoi(header[2]);
  /* Allocate image data. */
  self->img_size = self->img_width * self->img_height;
  self->img_data = malloc(self->img_size);
  /* Read image data. */
  len = fread(self->img_data, sizeof(uint8_t), self->img_size, fp);
  check_error(len != self->img_size, "Expected %d bytes, read %d bytes.",
              self->img_size, len);
  fprintf(stderr, "Successfully loaded image: %d by %d with %d bytes.\n",
          self->img_width, self->img_height, self->img_size);
  return 0;
}

/** Write the pgm image.
 *  @param self Marsupial object.
 *  @param filename Pgm filepath. */
int marsupial_save_image(Marsupial *self, char *filename) {
  FILE *fp;
  char mode[] = "w";
  fp = fopen(filename, mode);
  check_error((fp == NULL), "Failed to open file %s\n", filename);
  size_t len;
  /* Write header */
  fprintf(fp, "P5\n%d %d\n%d\n", self->img_width, self->img_height, 255);
  /* Write data */
  len = fwrite(self->img_data, sizeof(uint8_t), self->img_size, fp);
  check_error(len != self->img_size,
              "Write image, expected %d bytes, wrote %d bytes.", self->img_size,
              len);
  fprintf(stderr, "Successfully saved image: %d by %d with %d bytes.\n",
          self->img_width, self->img_height, self->img_size);
  return 0;
}

/** Divide all pixels by 2 */
int marsupial_grey_image(Marsupial *self) {
  int r, c; /** row and column indices. */
  /* Cast the img data to a two dimensional array, for convenient looping. */
  uint8_t (*img_data)[self->img_width] =
      (uint8_t(*)[self->img_width])self->img_data;
  for (r = 0; r < self->img_height; r++) {   /* Loop rows */
    for (c = 0; c < self->img_width; c++) {  /* Loop pixels in row */
      img_data[r][c] = img_data[r][c] / 2;
    }
  }
  return 0;
}
/** Convolution of the image with a given 3x3 kernel.
 *  @param self Marsupial object.
 *  @param kernel 3x3 convolution kernel. */
int marsupial_convolution3x3(Marsupial *self, double (*kernel)[3] ) {
  //TODO: Implement the image convolution.
  fprintf(stderr, "Warning: Image convolution not yet implemented.\n");
  return 0;
}

/** Gaussian blur the image with a 3x3 kernel.
 *  @param self Marsupial object. */
int marsupial_gaussian3x3(Marsupial *self) {
  /* The Gaussian blur 3x3 kernel. */
  double gaussian_kernel[3][3] = {
    {1/16.0, 1/8.0, 1/16.0},
    {1/8.0,  1/4.0, 1/8.0},
    {1/16.0, 1/8.0, 1/16.0},
  };
  return marsupial_convolution3x3(self, gaussian_kernel);
}

/** Destroy the object and free allocated memory.
 *  @param self Double-pointer to the Marsupial object.
 *  NB: We have forgotten one thing here. */
int marsupial_destroy(Marsupial **self) {
  if (self != NULL && *self != NULL) {
    free(*self);
    *self = NULL;
    return 0;
  } else {
    return 1;
  }
}
