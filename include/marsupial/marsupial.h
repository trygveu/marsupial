/**Marsupial - ANSI with an object pouch.
 * Author: Trygve Utstumo, Adigo AS
 * Version 1.0
 * Copyright 2016 Adigo AS
 */

#ifndef INCLUDE_MARSUPIAL_MARSUPIAL_H_
#define INCLUDE_MARSUPIAL_MARSUPIAL_H_

/** The Marsupial object. */
typedef struct _marsupial_t Marsupial;

Marsupial* Marsupial_new();

int Marsupial_destroy(Marsupial** self);


#endif  // INCLUDE_MARSUPIAL_MARSUPIAL_H_
