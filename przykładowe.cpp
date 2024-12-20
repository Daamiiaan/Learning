//w klasie k1 składowa p1 jest wskaznikiem do dwuelementowej dynamicznej tablicy obiektow typu string
//klasa k2 zawiera pole w1 typu k1 oraz pole w2 typu double

#include <iostream>

using namespace std;

class k1
{
    string * p1;
public:
    k1() : p1(new string[2]{"brak", "brak"}) {}
    k1(string a, string b) : p1(new string[2] {a, b}) {}
    
    k1& operator=(const k1 &a1)
    {
    this-> p1[0] = a1.p1[0];
    this-> p1[1] = a1.p1[1];

    return *this;
    }
    friend ostream& operator<<(ostream& os, const k1 &a);
};

ostream& operator<<(ostream & os, const k1 &a)
{
    os <<a.p1[0] << " " << a.p1[1];
    return os;
}


class k2
{
    k1 w1;
    double w2;
public:
    k2() : w1(k1()), w2(0.0) {}
    k2(string a, string b, double c) : w1(a, b), w2(c) {};

    k2 operator-(const double &a)
    {
        this->w2=w2-a;
        return *this;
    }

    friend ostream& operator<<(ostream& os, const k2& a);
};

    ostream& operator<<(ostream& os, const k2& a)
    {
        os << a.w1 << " " << a.w2 <<endl;
        return os;
    }

int main()
{
    k2 ob1, ob2;
    const k2 * wsk1 = new k2("kawa", " z mlekiem", 4.50);
    const k2 ob3(*wsk1);
    delete wsk1;
    wsk1 = 0;

     const k2 *wsk2 = new k2(ob3);
     ob2=*wsk2;
     cout<<ob1<<*wsk2;
     delete wsk2;
     wsk2=0;

     cout<<ob2;
     cout<<(ob2-1.25);
     cout<< "***************** 3 *****************"<<endl;
}


