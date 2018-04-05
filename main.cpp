#include <iostream>
#include <string>
#include "image/Pixel.h"
#include "image/Header.h"
#include "image/Image.h"

int main(int argc, char const *argv[]) {
  if (argc != 4) {
    std::cerr << "USAGE: ./out <in.ppm> <in2.ppm> <out.ppm>";
    return 1;
  }

  // Open files
  std::ifstream in(argv[1]);
  std::ifstream in2(argv[2]);
  std::ofstream out(argv[3]);

  if (!(in && in2 && out)) {
    std::cerr << "Could not open input/output\n";
    return 1;
  }

  // ifstream constructor, let's read the file twice!
  Image puppy(in);
  Image other_puppy(in2);

  puppy = other_puppy;  // Spooky Assignment

  puppy.make_p3();
  puppy.write_to(out);

  in.close();
  in2.close();
  out.close();

  return 0;
}
