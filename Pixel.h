#ifndef PIXEL_H
#define PIXEL_H 1

#include <ostream>

using namespace std;

class Pixel {
  private:
    uint8_t R, G, B;

  public:
    Pixel ();
    Pixel (const Pixel&);
    Pixel (uint8_t, uint8_t, uint8_t);
    ~Pixel ();

    // Plain getters, use only these for immutable pixels
    uint8_t r () const;
    uint8_t g () const;
    uint8_t b () const;

    // Plain setters, use these for mutable pixels
    void set_r(uint8_t);
    void set_g(uint8_t);
    void set_b(uint8_t);

    // Assignment operator
    Pixel& operator=(const Pixel&);

    // Output operator
    friend std::ostream& operator<<(std::ostream&, const Pixel&);
};

#endif
