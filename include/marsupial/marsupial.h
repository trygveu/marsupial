/**Marsupial - ANSI C with an object pouch.
 * Author: Trygve Utstumo, Adigo AS
 * Version 1.0
 * Copyright 2016 Adigo AS
 */

#ifndef INCLUDE_MARSUPIAL_MARSUPIAL_H_
#define INCLUDE_MARSUPIAL_MARSUPIAL_H_

/** Marsupial object.
 *  The opaque object struct, with image data.
 */
typedef struct _marsupial_t Marsupial;

/** Object constructor */
Marsupial* Marsupial_new();

/** Open a pgm image.
 *  We support standard pgm format without comments.
 *  @param self Marsupial object.
 *  @param filename Pgm filepath, read only. */
int Marsupial_open_image(Marsupial *self, char* filename);

/** Write the pgm image.
 *  @param self Marsupial object.
 *  @param filename Pgm filepath. */
int Marsupial_save_image(Marsupial *self, char* filename);

/** Divide all pixels by 2.
 *  @param self Marsupial object. */
int Marsupial_grey_image(Marsupial *self);

/** Gaussian blur the image with a 3x3 kernel.
 *  @param self Marsupial object. */
int Marsupial_gaussian3x3(Marsupial *self);

/** Destroy the object and free allocated memory.
 *  @param self Double-pointer to the Marsupial object.
 *  NB: We have forgotten one thing here. */
int Marsupial_destroy(Marsupial** self);


#endif  // INCLUDE_MARSUPIAL_MARSUPIAL_H_
