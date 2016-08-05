/**Marsupial - ANSI C with an object pouch.
 * Author: Trygve Utstumo, Adigo AS
 * Version 1.0
 * Copyright 2016 Adigo AS
 */

#include <stdarg.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "marsupial/marsupial.h"

#define PGM_HEADER_LINES 3

struct _marsupial_t {
  int img_width, img_height, img_maxval;
  char *img_data;
};

void check_error(bool error_condition, char *format, ...) {
  if (error_condition) {
    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);
    exit(EXIT_FAILURE);
  }
}

Marsupial *Marsupial_new() {
  Marsupial *self = malloc(sizeof(Marsupial));
  return self;
}

int Marsupial_open_image(Marsupial *self, char *filename) {
  FILE *fp;
  char mode[] = "r+";
  fp = fopen(filename, mode);
  check_error((fp == NULL), "Failed to open file %s\n", filename);

  char *header[PGM_HEADER_LINES] = {NULL};
  size_t len = 0;
  ssize_t read;
  int i;
  /* Read the first 3 lines of the image */
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
  /* Allocate image data */
  size_t img_size = self->img_width * self->img_height;
  self->img_data = malloc(img_size);
  /* Read image data */
  len = fread(self->img_data, sizeof(char), img_size, fp);
  check_error(len != img_size,
              "Expected %d bytes, read %d bytes.",
              img_size, len);
  return 0;
}

int Marsupial_grey_image(Marsupial *self) {
  // TODO: Loop all the pixels, and divide the value by 2.0.
  return 0;
}

int Marsupial_save_image(Marsupial *self, char *filename) {
  // TODO: Save the image.
  return 0;
}

int Marsupial_destroy(Marsupial **self) {
  if (self != NULL && *self != NULL) {
    free(*self);
    *self = NULL;
    return 0;
  } else {
    return 1;
  }
}
