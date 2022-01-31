// @file Rectangle.h

#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle{
public:
    Rectangle() = default;                              // Use implicit defaults from initializers
    Rectangle(int l, int w) : length{l}, width{w} {  }  // or instantiate with dimensions.
    void set_length(int l)  { length = l;            }  // Thin mutators for the length
    void set_width (int w)  { width  = w;            }  // and width.  Better ones would validate!
    int  get_length() const { return length;         }  // Inline accessors for length,
    int  get_width () const { return width;          }  // width
    int  get_area  () const { return length * width; }  // and area.

private:
    int length = 1;                                     // length and width default to 1
    int width  = 1;                                     // to create a "unit square"
};

#endif