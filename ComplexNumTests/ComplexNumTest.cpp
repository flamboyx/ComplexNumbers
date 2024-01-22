#include <gtest/gtest.h>
#include "ComplexNum.h"

TEST(ComplexNumTestSuite, DefaultConstructor) {
    ComplexNum<int> num;

    EXPECT_EQ(num.GetReal(), 0);
    EXPECT_EQ(num.GetImaginary(), 0);
}

TEST(ComplexNumTestSuite, ParametrizedConstructor) {
    ComplexNum<double> num(5.0, 4.0);

    EXPECT_DOUBLE_EQ(num.GetReal(), 5.0);
    EXPECT_DOUBLE_EQ(num.GetImaginary(), 4.0);
}

TEST(ComplexNumTestSuite, GetReal) {
    ComplexNum<float> num(-3.0, -4.0);

    EXPECT_FLOAT_EQ(num.GetReal(), -3.0);
}

TEST(ComplexNumTestSuite, GetImaginary) {
    ComplexNum<int> num(77, 38);

    EXPECT_EQ(num.GetImaginary(), 38);
}

TEST(ComplexNumTestSuite, SetReal) {
    ComplexNum<float> num(-42.42, 4.6);

    num.SetReal(55.55);

    EXPECT_FLOAT_EQ(num.GetReal(), 55.55);
}

TEST(ComplexNumTestSuite, SetImaginary) {
    ComplexNum<int> num(54, 228);

    num.SetImaginary(27);

    EXPECT_EQ(num.GetImaginary(), 27);
}

TEST(ComplexNumTestSuite, Addition) {
    ComplexNum<double> a(8.0, 4.0);
    ComplexNum<double> b(22.0, 16.0);

    ComplexNum<double> res = a + b;

    EXPECT_DOUBLE_EQ(res.GetReal(), 30.0);
    EXPECT_DOUBLE_EQ(res.GetImaginary(), 20.0);
}

TEST(ComplexNumTestSuite, Subtraction) {
    ComplexNum<int> a(52, 1);
    ComplexNum<int> b(42, -5);

    ComplexNum<int> res = a - b;

    EXPECT_EQ(res.GetReal(), 10);
    EXPECT_EQ(res.GetImaginary(), 6);
}

TEST(ComplexNumTestSuite, Multiplication) {
    ComplexNum<double> a(3.0, 4.4);
    ComplexNum<double> b(-2.0, 5.5);

    ComplexNum<double> res = a * b;

    EXPECT_DOUBLE_EQ(res.GetReal(), -30.2);
    EXPECT_DOUBLE_EQ(res.GetImaginary(), 7.7);
}

TEST(ComplexNumTestSuite, Division) {
    ComplexNum<double> a(5.0, -4.0);
    ComplexNum<double> b(-3.0, 4.0);
    ComplexNum<double> c(0.0, 0.0);

    ComplexNum<double> res = a / b;

    EXPECT_DOUBLE_EQ(res.GetReal(), -1.24);
    EXPECT_DOUBLE_EQ(res.GetImaginary(), -0.32);
    EXPECT_THROW(a / c, std::runtime_error);
}

TEST(ComplexNumTestSuite, Exponentiation) {
    ComplexNum<int> a(5, -5);

    ComplexNum<int> res = a ^ 3;

    EXPECT_EQ(res.GetReal(), -250);
    EXPECT_EQ(res.GetImaginary(), -250);
}

TEST(ComplexNumTestSuite, AdditionEqual) {
    ComplexNum<double> a(8.0, 4.0);
    ComplexNum<double> b(22.0, 16.0);

    a += b;

    EXPECT_DOUBLE_EQ(a.GetReal(), 30.0);
    EXPECT_DOUBLE_EQ(a.GetImaginary(), 20.0);
}

TEST(ComplexNumTestSuite, SubtractionEqual) {
    ComplexNum<int> a(52, 1);
    ComplexNum<int> b(42, -5);

    a -= b;

    EXPECT_EQ(a.GetReal(), 10);
    EXPECT_EQ(a.GetImaginary(), 6);
}

TEST(ComplexNumTestSuite, MultiplicationEqual) {
    ComplexNum<double> a(3.0, 1.2);
    ComplexNum<double> b(-2.0, 0.5);

    a *= b;

    EXPECT_DOUBLE_EQ(a.GetReal(), -6.6);
    EXPECT_DOUBLE_EQ(a.GetImaginary(), -0.9);
}

TEST(ComplexNumTestSuite, DivisionEqual) {
    ComplexNum<double> a(5.0, -4.0);
    ComplexNum<double> b(-3.0, 4.0);
    ComplexNum<double> c(0.0, 0.0);

    a /= b;

    EXPECT_DOUBLE_EQ(a.GetReal(), -1.24);
    EXPECT_DOUBLE_EQ(a.GetImaginary(), -0.32);
    EXPECT_THROW(a /= c, std::runtime_error);
}

TEST(ComplexNumTestSuite, ExponentiationEqual) {
    ComplexNum<int> a(5, -5);

    a ^= 3;

    EXPECT_EQ(a.GetReal(), -250);
    EXPECT_EQ(a.GetImaginary(), -250);
}

TEST(ComplexNumTestSuite, Pow) {
    ComplexNum<int> a(6, 6);

    ComplexNum<int> res = a.Pow(4);

    EXPECT_EQ(res.GetReal(), -5184);
    EXPECT_EQ(res.GetImaginary(), 0);
}

TEST(ComplexNumTestSuite, AbsoluteValue) {
    ComplexNum<int> a(6, -8);

    long double res = a.Abs();

    EXPECT_EQ(res, 10);
}

TEST(ComplexNumTestSuite, IsEqualToComplexNum) {
    ComplexNum<int> a(5, -5);
    ComplexNum<int> b(5, -5);
    ComplexNum<int> c(5, 3);

    EXPECT_TRUE(a == b);
    EXPECT_FALSE(a == c);
}

TEST(ComplexNumTestSuite, IsEqualToInt) {
    ComplexNum<float> a(5.0, 0.0);
    ComplexNum<float> a2(5.0, 4.0);
    int b = 5;
    int c = -5;

    EXPECT_TRUE(a == b);
    EXPECT_FALSE(a == c);
    EXPECT_FALSE(a2 == b);
}

TEST(ComplexNumTestSuite, IsEqualToLongInt) {
    ComplexNum<int> a(100, 0);
    ComplexNum<int> a2(100, 1);
    long int b = 100;
    long int c = 1000;

    EXPECT_TRUE(a == b);
    EXPECT_FALSE(a == c);
    EXPECT_FALSE(a2 == b);
}

TEST(ComplexNumTestSuite, IsEqualToFloat) {
    ComplexNum<float> a(5.5, 0.0);
    ComplexNum<float> a2(5.5, 0.0001);
    float b = 5.5;
    float c = 5.4;

    EXPECT_TRUE(a == b);
    EXPECT_FALSE(a == c);
    EXPECT_FALSE(a2 == b);
}

TEST(ComplexNumTestSuite, IsEqualToDouble) {
    ComplexNum<double> a(1.234, 0.0);
    ComplexNum<double> a2(1.234, -0.001);
    double b = 1.234;
    double c = 1234.0;

    EXPECT_TRUE(a == b);
    EXPECT_FALSE(a == c);
    EXPECT_FALSE(a2 == b);
}

TEST(ComplexNumTestSuite, IsEqualToLongDouble) {
    ComplexNum<long double> a(5.6765, 0.0);
    ComplexNum<long double> a2(5.6765, 1.355);
    long double b = 5.6765;
    long double c = 5.6766;

    EXPECT_TRUE(a == b);
    EXPECT_FALSE(a == c);
    EXPECT_FALSE(a2 == b);
}

TEST(ComplexNumTestSuite, IsNotEqualToComplexNum) {
    ComplexNum<int> a(2, -5);
    ComplexNum<int> b(5, -5);
    ComplexNum<int> c(2, -5);

    EXPECT_TRUE(a != b);
    EXPECT_FALSE(a != c);
}

TEST(ComplexNumTestSuite, IsNotEqualToInt) {
    ComplexNum<float> a(44.0, 0.0);
    ComplexNum<float> a2(44.0, 0.01);
    int b = 55;
    int c = 44;

    EXPECT_TRUE(a != b);
    EXPECT_TRUE(a2 != c);
    EXPECT_FALSE(a != c);
}

TEST(ComplexNumTestSuite, IsNotEqualToLongInt) {
    ComplexNum<int> a(98765, 0);
    ComplexNum<int> a2(98765, -1);
    long int b = 56789;
    long int c = 98765;

    EXPECT_TRUE(a != b);
    EXPECT_TRUE(a2 != c);
    EXPECT_FALSE(a != c);
}

TEST(ComplexNumTestSuite, IsNotEqualToFloat) {
    ComplexNum<float> a(5.55, 0.0);
    ComplexNum<float> a2(5.55, 5.001);
    float b = 5.5;
    float c = 5.55;

    EXPECT_TRUE(a != b);
    EXPECT_TRUE(a2 != c);
    EXPECT_FALSE(a != c);
}

TEST(ComplexNumTestSuite, IsNotEqualToDouble) {
    ComplexNum<double> a(4.321, 0.0);
    ComplexNum<double> a2(4.321, 1.001);
    double b = 1.234;
    double c = 4.321;

    EXPECT_TRUE(a != b);
    EXPECT_TRUE(a2 != c);
    EXPECT_FALSE(a != c);
}

TEST(ComplexNumTestSuite, IsNotEqualToLongDouble) {
    ComplexNum<long double> a(648.94, 0.0);
    ComplexNum<long double> a2(648.94, -0.00004);
    long double b = 4618.543;
    long double c = 648.94;

    EXPECT_TRUE(a != b);
    EXPECT_TRUE(a2 != c);
    EXPECT_FALSE(a != c);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}