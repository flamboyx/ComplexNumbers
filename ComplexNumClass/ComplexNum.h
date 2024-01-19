template<typename T>
class ComplexNum {

private:
    T re, im;
    const double epsilon = 1e-9;

public:
    ComplexNum();
    ComplexNum(int a, int b);
    ComplexNum(float a, float b);
    ComplexNum(double a, double b);
    ComplexNum(long double a, long double b);
    ComplexNum(int a);
    ComplexNum(float a);
    ComplexNum(double a);
    ComplexNum(long double a);
    T GetReal();
    T GetImaginary();
    void SetReal();
    void SetImaginary();
    ComplexNum operator + (ComplexNum other);
    ComplexNum operator - (ComplexNum other);
    ComplexNum operator * (ComplexNum other);
    ComplexNum operator / (ComplexNum other);
    ComplexNum operator ^ (T degree);
    ComplexNum operator += (ComplexNum other);
    ComplexNum operator -= (ComplexNum other);
    ComplexNum operator *= (ComplexNum other);
    ComplexNum operator /= (ComplexNum other);
    ComplexNum operator ^= (T degree);
    bool operator == (ComplexNum other);
    bool operator == (int other);
    bool operator == (float other);
    bool operator == (double other);
    bool operator == (long double other);
    bool operator != (ComplexNum other);
    bool operator != (int other);
    bool operator != (float other);
    bool operator != (double other);
    bool operator != (long double other);
    
};