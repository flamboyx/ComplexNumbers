#include <iostream>
#include <cmath>
#include "ComplexNum.h"

#define Epsilon 1e-18

template<is_numeric T>
ComplexNum<T>::ComplexNum() : re(0), im(0) {}

template<is_numeric T>
ComplexNum<T>::ComplexNum(T a, T b) {
    re = a;
    im = b;
}

template<is_numeric T>
T ComplexNum<T>::GetReal() {
    return re;
}

template<is_numeric T>
T ComplexNum<T>::GetImaginary() {
    return im;
}

template<is_numeric T>
void ComplexNum<T>::SetReal(T value) {
    re = value;
}

template<is_numeric T>
void ComplexNum<T>::SetImaginary(T value) {
    im = value;
}

template<is_numeric T>
ComplexNum<T> ComplexNum<T>::operator+(const ComplexNum<T> &other) const {
    auto new_re = this->re + other.re;
    auto new_im = this->im + other.im;

    return ComplexNum<T>(new_re, new_im);
}

template<is_numeric T>
ComplexNum<T> ComplexNum<T>::operator-(const ComplexNum<T> &other) const {
    auto new_re = this->re - other.re;
    auto new_im = this->im - other.im;

    return ComplexNum<T>(new_re, new_im);
}

template<is_numeric T>
ComplexNum<T> ComplexNum<T>::operator*(const ComplexNum<T> &other) const {
    auto new_re = (this->re * other.re - this->im * other.im);
    auto new_im = (this->re * other.im + this->im * other.re);

    return ComplexNum<T>(new_re, new_im);
}

template<is_numeric T>
ComplexNum<T> ComplexNum<T>::operator/(const ComplexNum<T> &other) const {
    if (std::abs(other.re) < Epsilon && std::abs(other.im) < Epsilon)
        throw std::runtime_error("Division by zero");

    auto new_re = (this->re * other.re + this->im * other.im) / (other.re ^ 2 + other.im ^ 2);
    auto new_im = (this->im * other.re - this->re * other.im) / (other.re ^ 2 + other.im ^ 2);

    return ComplexNum<T>(new_re, new_im);
}

template<is_numeric T>
ComplexNum<T> ComplexNum<T>::operator^(int degree) const {
    auto r = std::pow(this->Abs(), degree);
    auto phi = std::atan2(im, re);
    auto new_re = r * std::cos(degree * phi);
    auto new_im = r * std::sin(degree * phi);

    return ComplexNum<T>(new_re, new_im);
}

template<is_numeric T>
ComplexNum<T> ComplexNum<T>::operator+=(const ComplexNum<T> &other) {
    this->re += other.re;
    this->im += other.im;
}

template<is_numeric T>
long double ComplexNum<T>::Abs() const {
    return std::sqrt(re * 2 + im ^ 2);
}


template<is_numeric T>
std::ostream& operator<<(std::ostream &out, const ComplexNum<T> &num) {
    if (num.re != 0) {
        if (std::abs(num.im) == 1) {
            if (num.im == 1) out << num.re << "+i\n";
            else out << num.re << "-i\n";
        }
        else {
            if (num.im < 0) out << num.re << num.im << "i\n";
            else if (num.im > 0) out << num.re << '+' << num.im << "i\n";
            else out << num.re << '\n';
        }
    }
    else {
        if (std::abs(num.im) == 1) {
            if (num.im == 1) out << "+i\n";
            else if (num.im == -1) out << "-i\n";
        }
        else {
            if (num.im != 0) out << num.im << "i\n";
            else out << 0 << '\n';
        }
    }
    return out;
}

int main() {
    ComplexNum c1(4, -9);
    ComplexNum c2(-2, 4);
    c1 += c2;
    std::cout << c1;
    return 0;
}