#ifndef HEADER_T
#define HEADER_T 1

#include <string>
#include <iostream>

using namespace std;

class Header {
private:
    std::string MAGIC;
    int W, H, MC;

  public:
    Header ();
    Header (const Header& HDR);
    Header (std::string m, int w, int h, int mc);
    ~Header ();

    // Value getter, use only these for immutable headers
    std::string magic() const;
    int width() const;
    int height() const;
    int max_color() const;

    // Setter, use for mutable headers - or use references!
    void set_magic(string);
    void set_width(int);
    void set_height(int);
    void set_max_color(int);

    // Assignment
    Header& operator= (const Header&);

    // Output
    friend std::ostream& operator<< (std::ostream&, const Header&);
};

#endif
