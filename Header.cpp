#include "Header.h"

// Default constructor
Header::Header() : MAGIC(""), W(0), H(0), MC(0){}

// Copy constructor
Header::Header (const Header& HDR) : MAGIC(HDR.MAGIC), W(HDR.W), H(HDR.H), MC(HDR.MC) {}

// Param constructor
Header::Header (std::string m, int w, int h, int mc) : MAGIC(m), W(w), H(h), MC(mc) {}

// Destructor
Header::~Header () {}

// Simple getter
std::string Header::magic () const { return this->MAGIC; }
int Header::width () const { return this->W; }
int Header::height () const { return this->H; }
int Header::max_color () const { return this->MC; }

// Simple setter
void Header::set_magic(string magic) { this->MAGIC = magic; }
void Header::set_width(int w) { this->W = w; }
void Header::set_height(int h) { this->H = h; }
void Header::set_max_color(int mc) { this->MC = mc; }

// Assignment
Header& Header::operator= (const Header& hdr) {
  if (this == &hdr) return *this; 
  this->MAGIC = hdr.MAGIC;
  this->W     = hdr.W;
  this->H     = hdr.H;
  this->MC    = hdr.MC;
  return *this;
}

// Output
std::ostream& operator<< (std::ostream& out, const Header& hdr) {
  return out  << hdr.magic() << std::endl
              << hdr.width() << std::endl
              << hdr.height() << std::endl
              << hdr.max_color() << std::endl;
}
