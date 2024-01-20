#include <iostream>
#include <cmath>
#include <string>
#include "ComplexNum.h"

#define Epsilon 1e-9

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
    auto new_re = re + other.re;
    auto new_im = im + other.im;

    return ComplexNum<T>(new_re, new_im);
}

template<is_numeric T>
ComplexNum<T> ComplexNum<T>::operator-(const ComplexNum<T> &other) const {
    auto new_re = re - other.re;
    auto new_im = im - other.im;

    return ComplexNum<T>(new_re, new_im);
}

template<is_numeric T>
ComplexNum<T> ComplexNum<T>::operator*(const ComplexNum<T> &other) const {
    auto new_re = (re * other.re - im * other.im);
    auto new_im = (re * other.im + im * other.re);

    return ComplexNum<T>(new_re, new_im);
}

template<is_numeric T>
ComplexNum<T> ComplexNum<T>::operator/(const ComplexNum<T> &other) const {
    if (std::abs(other.re) < Epsilon && std::abs(other.im) < Epsilon)
        throw std::runtime_error("Division by zero");

    auto new_re = re;
    auto new_im = im;

    if (std::is_integral<T>::value) {
        new_re = round(static_cast<long double>(re * other.re + im * other.im) / (other.re * other.re + other.im * other.im));
        new_im = round(static_cast<long double>(im * other.re - re * other.im) / (other.re * other.re + other.im * other.im));
    }
    else {
        new_re = (re * other.re + im * other.im) / (other.re * other.re + other.im * other.im);
        new_im = (im * other.re - re * other.im) / (other.re * other.re + other.im * other.im);
    }

    return ComplexNum<T>(new_re, new_im);
}

template<is_numeric T>
ComplexNum<T> ComplexNum<T>::operator^(int degree) const {
    return Pow(degree);
}

template<is_numeric T>
ComplexNum<T>& ComplexNum<T>::operator+=(const ComplexNum<T> &other) {
    re += other.re;
    im += other.im;
    return *this;
}

template<is_numeric T>
ComplexNum<T> &ComplexNum<T>::operator-=(const ComplexNum<T> &other) {
    re -= other.re;
    im -= other.im;
    return *this;
}

template<is_numeric T>
ComplexNum<T> &ComplexNum<T>::operator*=(const ComplexNum<T> &other) {
    auto new_re = (re * other.re - im * other.im);
    auto new_im = (re * other.im + im * other.re);

    re = new_re;
    im = new_im;

    return *this;
}

template<is_numeric T>
ComplexNum<T> &ComplexNum<T>::operator/=(const ComplexNum<T> &other) {
    if (std::abs(other.re) < Epsilon && std::abs(other.im) < Epsilon)
        throw std::runtime_error("Division by zero");

    auto new_re = re;
    auto new_im = im;

    if (std::is_integral<T>::value) {
        new_re = round(static_cast<long double>(re * other.re + im * other.im) / (other.re * other.re + other.im * other.im));
        new_im = round(static_cast<long double>(im * other.re - re * other.im) / (other.re * other.re + other.im * other.im));
    }
    else {
        new_re = (re * other.re + im * other.im) / (other.re * other.re + other.im * other.im);
        new_im = (im * other.re - re * other.im) / (other.re * other.re + other.im * other.im);
    }

    re = new_re;
    im = new_im;

    return *this;
}

template<is_numeric T>
ComplexNum<T> &ComplexNum<T>::operator^=(int degree) {
    ComplexNum num = Pow(degree);
    re = num.re;
    im = num.im;

    return *this;
}

template<is_numeric T>
ComplexNum<T> ComplexNum<T>::Pow(int degree) const {
    auto r = std::pow(Abs(), degree);
    auto phi = std::atan2(im, re);
    auto new_re = re;
    auto new_im = im;

    if (std::is_integral<T>::value) {
        new_re = round(r * std::cos(degree * phi));
        new_im = round(r * std::sin(degree * phi));
    }
    else {
        new_re = r * std::cos(degree * phi);
        new_im = r * std::sin(degree * phi);
    }

    return ComplexNum<T>(new_re, new_im);
}

template<is_numeric T>
long double ComplexNum<T>::Abs() const {
    return std::sqrt(re * re + im * im);
}

template<is_numeric T>
bool ComplexNum<T>::operator==(const ComplexNum<T> &other) const {
    return (std::abs(re - other.re) < Epsilon) && (std::abs(im - other.im) < Epsilon);
}

template<is_numeric T>
bool ComplexNum<T>::operator==(int other) const {
    return (std::abs(re - other) < Epsilon) && (std::abs(im) < Epsilon);
}

template<is_numeric T>
bool ComplexNum<T>::operator==(long int other) const {
    return (std::abs(re - other) < Epsilon) && (std::abs(im) < Epsilon);
}

template<is_numeric T>
bool ComplexNum<T>::operator==(float other) const {
    return (std::abs(re - other) < Epsilon) && (std::abs(im) < Epsilon);
}

template<is_numeric T>
bool ComplexNum<T>::operator==(double other) const {
    return (std::abs(re - other) < Epsilon) && (std::abs(im) < Epsilon);
}

template<is_numeric T>
bool ComplexNum<T>::operator==(long double other) const {
    return (std::abs(re - other) < Epsilon) && (std::abs(im) < Epsilon);
}

template<is_numeric T>
bool ComplexNum<T>::operator!=(const ComplexNum<T> &other) const {
    return !((std::abs(re - other.re) < Epsilon) && (std::abs(im - other.im) < Epsilon));
}

template<is_numeric T>
bool ComplexNum<T>::operator!=(int other) const {
    return !((std::abs(re - other) < Epsilon) && (std::abs(im) < Epsilon));
}

template<is_numeric T>
bool ComplexNum<T>::operator!=(long int other) const {
    return !((std::abs(re - other) < Epsilon) && (std::abs(im) < Epsilon));
}

template<is_numeric T>
bool ComplexNum<T>::operator!=(float other) const {
    return !((std::abs(re - other) < Epsilon) && (std::abs(im) < Epsilon));
}

template<is_numeric T>
bool ComplexNum<T>::operator!=(double other) const {
    return !((std::abs(re - other) < Epsilon) && (std::abs(im) < Epsilon));
}

template<is_numeric T>
bool ComplexNum<T>::operator!=(long double other) const {
    return !((std::abs(re - other) < Epsilon) && (std::abs(im) < Epsilon));
}

template<is_numeric T>
void ComplexNum<T>::Print() const {
    if (re != 0) {
        if (std::abs(im) == 1) {
            if (im == 1) std::cout << re << "+i\n";
            else std::cout << re << "-i\n";
        }
        else {
            if (im < 0) std::cout << re << im << "i\n";
            else if (im > 0) std::cout << re << '+' << im << "i\n";
            else std::cout << re << '\n';
        }
    }
    else {
        if (std::abs(im) == 1) {
            if (im == 1) std::cout << "i\n";
            else if (im == -1) std::cout << "-i\n";
        }
        else {
            if (im != 0) std::cout << im << "i\n";
            else std::cout << 0 << '\n';
        }
    }
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
            if (num.im == 1) out << "i\n";
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
    ComplexNum c1(6, 0);
    ComplexNum c2(5.4, 4.1);
    long int a = 5;
    std::cout << c2;

    return 0;
}