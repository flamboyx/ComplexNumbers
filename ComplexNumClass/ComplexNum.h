#pragma once

#include <concepts>
#include <iostream>

template<typename T>
concept is_numeric = std::is_arithmetic<T>::value && !std::same_as<T, bool> && !std::same_as<T, char> \
    && !std::same_as<T, void>;

template<is_numeric T>
class ComplexNum {

private:
    T re, im;

public:
    ComplexNum();
    ComplexNum(T a, T b);
    T GetReal();
    T GetImaginary();
    void SetReal(T value);
    void SetImaginary(T value);
    ComplexNum<T> operator + (const ComplexNum<T> &other) const;
    ComplexNum<T> operator - (const ComplexNum<T> &other) const;
    ComplexNum<T> operator * (const ComplexNum<T> &other) const;
    template<is_numeric K> ComplexNum<K> operator / (const ComplexNum<T> &other) const;
    ComplexNum<T> operator ^ (int degree) const;
    ComplexNum<T>& operator += (const ComplexNum<T> &other);
    ComplexNum<T>& operator -= (const ComplexNum<T> &other);
    ComplexNum<T>& operator *= (const ComplexNum<T> &other);
    template<is_numeric K> ComplexNum<K>& operator /= (const ComplexNum<T> &other);
    ComplexNum<T>& operator ^= (int degree);
    ComplexNum<T> Pow(int degree) const;
    long double Abs() const;
    bool operator == (const ComplexNum<T> &other) const;
    bool operator == (T other) const;
    bool operator != (const ComplexNum<T> &other) const;
    bool operator != (T other) const;
    void Print() const;

    template<is_numeric K>
    friend std::ostream& operator << (std::ostream &out, const ComplexNum<K> &num);
};

