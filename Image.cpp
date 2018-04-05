#include "Image.h"

// Param constructor
Image::Image (ifstream& in) {
   this->HDR = Image::read_header(in);
   this->PIX = Image::read_pixels(this->HDR, in);
}
Image::Image(ifstream& in) : HDR(Image::read_header(in)),
                             PIX(Image::read_pixels(HDR, in)) {}

// Copy constructor ORIGINAL, NOT IN USE
/* Image::Image (const Image& img) {
  this->HDR = img.HDR;  // Assignment operator is really useful!
  // We have to allocate new memory here
  int num_pixels = img.HDR.width() * img.HDR.height();
  this->PIX.reserve(num_pixels);
  this->PIX = img.PIX;
} */


//Copy Initialized List Constructor
Image::Image(const Image& img) : HDR(img.HDR), PIX(img.PIX){ }

// Destructor
Image::~Image () {
  PIX.clear();
}

/*
  Parameters: in - an ifstream containing a ppm image 
  Return: A Header object containing the Magic Number, height, width, and max
          color of the header

          This function takes an ifstream, and reads in all of the header
          information associated, while skipping the comments 
*/
Header Image::read_header (ifstream& in) {
  string magic;
  int w, h, mc;

  in >> magic;
  Image::ignore_comments(in);
  in >> w;
  Image::ignore_comments(in);
  in >> h;
  Image::ignore_comments(in);
  in >> mc;
  in.ignore(256, '\n');
  return Header(magic, w, h, mc);
}

/*
  Paramters: in - an ifstream containing a ppm image
  Returns: void

           This function reads a character from the ppm image, and if the character
           is a space, it will continue to read until it finds a number or a # symbol.
           If it finds a # symbol, it ignores all other characters until it 
           reaches a newline. It the ungets the last character, and returns 
           void, leaving the ifstream at the correct character
*/
void Image::ignore_comments (ifstream& in) {
  char c;
  in.get(c);

  while ( isspace(c) || c == '#') {
    if (c == '#')
      in.ignore(256, '\n');
    in.get(c);
  }

  in.unget();
}

// This function allocates memory!
std::vector<Pixel> Image::read_pixels (const Header& hdr, ifstream& in) {
  int num_pixels = hdr.width() * hdr.height();
  vector<Pixel> pixels;
  pixels.reserve(num_pixels);

  if (hdr.magic() == "P3") {
    uint r,g,b;
    for (int i = 0; i < num_pixels; i++) {
      in >> r >> g >> b;
      pixels[i] = Pixel(r, g, b); // Assignment operator to the rescue again!
    }
  } else {
    uint8_t r,g,b;
    for (int i = 0; i < num_pixels; i++) {
      r = in.get();
      g = in.get();
      b = in.get();
      pixels[i] = Pixel(r, g, b);
    }
  }

  return pixels;
}

// accessors
const Header& Image::header () const { return this->HDR; }
const std::vector<Pixel> Image::pixels () const { return this->PIX; }

// If someone wants to change the header, the Image controls
// which fields it will to expose
void Image::make_p3 () { this->HDR.magic() = "P3"; }
void Image::make_p6 () { this->HDR.magic() = "P6"; }

void Image::write_header (ofstream& out) const {
  out << this->HDR.magic() << " "
      << this->HDR.width() << " "
      << this->HDR.height() << " "
      << this->HDR.max_color() << "\n";
}

void Image::write_to (ofstream& out) const {
  write_header(out);

  int num_pixels = this->HDR.width() * this->HDR.height();

  if (this->HDR.magic() == "P3") {
    for (int i = 0; i < num_pixels; i++) {
      Pixel p = this->PIX[i];
      out << (int) p.r() << ' '
          << (int) p.g() << ' '
          << (int) p.b() << ' ';
    }
  } else {
    for (int i = 0; i < num_pixels; i++) {
      Pixel p = this->PIX[i];
      out << p.r() << p.g() << p.b();
    }
  }
}

// This function is important!
Image& Image::operator=(const Image& rhs) {
  if (this == &rhs) return *this; // Why do we need this? Hint: delete[]
  // Header is simple
  this->HDR = rhs.HDR;  // Assignment operator

  // Pixels are not, we need to make sure there is enough room
  int num_pixels = rhs.HDR.width() * rhs.HDR.height();
  this->PIX.clear();
  this->PIX.reserve(num_pixels);
  this->PIX = rhs.PIX;

  return *this;
}

// Get one pixel
Pixel& Image::operator() (int x, int y) {
  int ndx = (this->HDR.width() * y) + x;
  return this->PIX[ndx];
}
