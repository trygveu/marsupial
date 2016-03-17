/**Marsupial - ANSI with an object pouch.
 * Author: Trygve Utstumo, Adigo AS
 * Version 1.0
 * Copyright 2016 Adigo AS
 */

#include <stdlib.h>

#include "marsupial/marsupial.h"

struct _marsupial_t {
  int pouch_contents;
};

Marsupial* Marsupial_new() {
  Marsupial* self = malloc(sizeof(Marsupial));
  return self;
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

