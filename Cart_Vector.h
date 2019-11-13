
#ifndef CART_VECTOR_H
#define CART_VECTOR_H
#include <ostream>

using namespace std;

class Cart_Vector

{

public:

    double x;
    double y;


    Cart_Vector();
    Cart_Vector(double, double);
};


Cart_Vector operator*(Cart_Vector, double);
Cart_Vector operator/(Cart_Vector, double);
ostream& operator<<(ostream&, const Cart_Vector&);

#endif
