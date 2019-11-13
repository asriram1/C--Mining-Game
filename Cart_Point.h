#ifndef CART_POINT_H
#define CART_POINT_H
#include <stdio.h>
#include <ostream>
#include "Cart_Vector.h"

using namespace std;

class Cart_Point

{

 public:
    double x;
    double y;

    Cart_Point();
    Cart_Point(double, double);
};


double cart_distance(Cart_Point, Cart_Point);
Cart_Point operator+(Cart_Point, Cart_Vector);
Cart_Vector operator-(Cart_Point, Cart_Point);
ostream& operator<<(ostream&, const Cart_Point&);

#endif
