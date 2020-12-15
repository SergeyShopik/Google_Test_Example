#pragma once
#include<iostream>
#include<fstream>
int gcd(int a, int b)// greatest common divisor
{
    if (a == 0) return 0;
    a = (a > 0) ? a : -a;
    b = (b > 0) ? b : -b;
    while (a != b)
    {
        (a > b) ? a = a - b : b = b - a;
    }
    return a;
}

class Rational
{
public:
    Rational() :a(0), b(1) {}
    int get_a()const { return a; }
    int get_b()const { return b; }
    Rational(int _a, int _b) :a(_a), b(_b) {}
    Rational(const Rational& r)
    {
        a = r.a;
        b = r.b;
        std::cout << "Copy constructor created.\n";
    }
    ~Rational()
    {
        std::cout << "Default destructor created.\n";
    }
    Rational add(const Rational& obj);
    bool equal(const Rational&);
    void print(std::ostream&);
private:
    int a, b;
    void reduce();
};

Rational Rational::add(const Rational& obj)
{
    Rational sum(a * obj.b + b * obj.a, b * obj.b);
    sum.reduce();
    return sum;
}
bool Rational::equal(const Rational& obj)
{
    return (a * obj.b == obj.a * b) ? true : false;
}
void Rational::reduce()
{
    int GCD = gcd(a, b);
    if (GCD == 0)
    {
        a = 0;
        b = b;
        return;
    }
    a /= GCD;
    b /= GCD;
}
void Rational::print(std::ostream& out)
{
    if (b == 1)
    {
        out << a << "\n";
    }
    else
        out << a << "/" << b << "\n";
}