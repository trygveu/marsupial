#include <stdio.h>
#include <stdlib.h>

#include "marsupial/marsupial.h"

void print_info();
enum info_type { INFO_USAGE, INFO_MARSUPIAL, INFO_LAST};

int main(int argc, char ** argv) {
  if (argc < 3) {
    fprintf(stderr, "Takes an input image, reduces brightness and does gaussian blur.");
    fprintf(stderr, "Usage: %s input_image.pgm output_image.pgm.\n", argv[0]);
    fprintf(stderr, "\nError: Not enough arguments.\n");
    exit(EXIT_FAILURE);
  }
  Marsupial* kang = marsupial_new();
  marsupial_open_image(kang, argv[1]);
  marsupial_grey_image(kang);
  marsupial_gaussian3x3(kang);
  marsupial_save_image(kang, argv[2]);
  marsupial_destroy(&kang);
  return 0;
}

