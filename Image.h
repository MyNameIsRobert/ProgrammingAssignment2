#ifndef IMAGE_H
#define IMAGE_H 1

#include "Header.h"
#include "Pixel.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <vector>
using namespace std;

class Image {
  private:
    Header HDR;
    std::vector<Pixel> PIX;
    

    // Disallow default constructor, why?
    Image ();

    // Used by Constructors to build Image
    static std::vector<Pixel> read_pixels(const Header&, std::ifstream&);
    static Header read_header(std::ifstream&);
    static void ignore_comments(std::ifstream&);

    // Private helper methods
    void write_header(std::ofstream&) const;

  public:
    // Constructors
    Image (std::ifstream&);
    Image (const Image& i);
    ~Image ();

    // Public member functions
    void write_to(std::ofstream&) const;
    void make_p3();
    void make_p6();

    // Don't let someone change the header arbitrarily,
    // Image should control what fields are allowed to change
    const Header& header() const;
    // Const accessor, dont let someone change the Pixel*
    // otherwise memory leaks!
    const std::vector<Pixel> pixels() const;

    // Assignment - More complicated than you think!
    Image& operator=(const Image& rhs);

    // Cool Pixel grabber
    // What does returning by non-const ref let us do?
    Pixel& operator()(int, int);
};

#endif
