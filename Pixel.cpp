#include "Pixel.h"

// Default Constructor
Pixel::Pixel() : R(0), G(0), B(0){}

// Copy Constructor
Pixel::Pixel(const Pixel& P) : R(P.R), G(P.G), B(P.B) {}

// Param Constructor
Pixel::Pixel (uint8_t r, uint8_t g, uint8_t b) : R(r), G(g), B(b) {}

// Destructor
Pixel::~Pixel() {}

// Getters
uint8_t Pixel::r () const { return this->R; }
uint8_t Pixel::g () const { return this->G; }
uint8_t Pixel::b () const { return this->B; }

// Setters
void Pixel::set_r (uint8_t r) { this->R = r; }
void Pixel::set_g (uint8_t g) { this->G = g; }
void Pixel::set_b (uint8_t b) { this->B = b; }

// Assignment
Pixel& Pixel::operator= (const Pixel& rhs) {
  if (this == &rhs) return *this;
  this->R = rhs.R;
  this->G = rhs.G;
  this->B = rhs.B;
  return *this;
}

// Output
std::ostream& operator<< (std::ostream& out, const Pixel& P) {
 return out  << "("
             << P.R << " "
             << P.G << " "
             << P.B << ")";
}
