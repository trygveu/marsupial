/**Marsupial - ANSI C with an object pouch.
 * Author: Trygve Utstumo, Adigo AS
 * Version 1.0
 * Copyright 2016 Adigo AS
 */

#ifndef INCLUDE_MARSUPIAL_MARSUPIAL_H_
#define INCLUDE_MARSUPIAL_MARSUPIAL_H_

typedef struct _marsupial_t Marsupial;

Marsupial* Marsupial_new();

int Marsupial_open_image(Marsupial *self, char* filename);
int Marsupial_grey_image(Marsupial *self);
int Marsupial_save_image(Marsupial *self, char* filename);

int Marsupial_destroy(Marsupial** self);


#endif  // INCLUDE_MARSUPIAL_MARSUPIAL_H_
