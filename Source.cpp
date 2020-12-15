#include"Header.h"
#include<iostream>
int main()
{
    Rational r1, r(1, 2);
    Rational r3 = r;

    r1 = r3.add(r);
    if (r3.equal(r))
        std::cout << "r3 = r" << std::endl;

    return 0;
}