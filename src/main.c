#include <stdio.h>

#include "marsupial/marsupial.h"

void print_info();

int main(int argc, char ** argv) {
  print_info();

  Marsupial* kang = Marsupial_new();
  Marsupial_destroy(&kang);
  return 0;
}

void print_info() {
  char marsupial_definition[] = "\
    Marsupials are an infraclass of mammals living primarily in Australasia \n\
    and the Americas. A distinctive characteristic, common to many species,\n\
    is that most of the young are carried in a pouch. Well-known marsupials \n\
    include kangaroos, wallabies, the koala, possums, opossums, wombats and \n\
    the Tasmanian devil.\n\
    \n\
      _,'   ___         \n\
     <__\\__/   \\      \n\
        \\_  /  _\\     \n\
          \\,\\ / \\\\  \n\
            //   \\\\   \n\
          ,/'     `\\_, \n\
    We like keeping things in pouches, so they can't make such a mess. Much\n\
    like objects and private variables.\n";
  fprintf(stderr, "\nHello, have you ever wondered what a Marsupial is?\n");
  fprintf(stderr, "\n%s\n", marsupial_definition);
}

