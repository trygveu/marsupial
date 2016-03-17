/**Marsupial - ANSI C with an object pouch.
 * Author: Trygve Utstumo, Adigo AS
 * Version 1.0
 * Copyright 2016 Adigo AS
 */

#include <stdlib.h>
#include <stdio.h>

#include "marsupial/marsupial.h"

struct _marsupial_t {
  int pouch_contents;
  FILE *file_pointer;
};

Marsupial* Marsupial_new() {
  Marsupial* self = malloc(sizeof(Marsupial));
  return self;
}

int Marsupial_open_image(Marsupial *self, char* filename){
  //TODO: Open the file.
  return 0;
}

int Marsupial_grey_image(Marsupial *self){
  //TODO: Loop all the pixels, and divide the value by 2.0.
  return 0;
}

int Marsupial_save_image(Marsupial *self, char* filename){
  //TODO: Save the image.
  return 0;
}

int Marsupial_destroy(Marsupial** self) {
  if (self != NULL && *self != NULL) {
    free(*self);
    *self = NULL;
    return 0;
  } else {
    return 1;
  }
}

