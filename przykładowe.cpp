//w klasie k1 składowa p1 jest wskaznikiem do dwuelementowej dynamicznej tablicy obiektow typu string
//klasa k2 zawiera pole w1 typu k1 oraz pole w2 typu double

#include <iostream>

using namespace std;

class k1
{
    string * p1;
public:
    k1() {
        p1 = new string[2];
        p1[0] = "brak";
        p1[1] = "brak";
    }
    k1(string a, string b)
    {
        p1 = new string[2];
        p1[0] = a;
        p1[1] = b;
    }

    ~k1(){delete [] p1;}

    friend ostream& operator<<(ostream& os, const k1& b)
    {
        os << b.p1[0] << " " << b.p1[1] << endl;
        return os;

    }
    void ustaw(string a, string b)
    {
        p1[0] = a;
        p1[1] = b;
    }


};
class k2
{
    k1 w1;
    double w2;
public:
    k2() : w1(), w2(0.0) {}
    k2(string a, string b, double c) : w1(a, b), w2(c) {};
    k2(const k2& other) : w1(other.w1), w2(other.w2) {}

    friend ostream& operator<<(ostream& os, const k2& a)
    {
        cout << a.w1 << " " << a.w2 <<endl;
        return os;
    }
};

int main()
{
    k2 ob1, ob2;
    const k2 * wsk1 = new k2("kawa", " z mlekiem", 4.50);
    const k2 ob3(*wsk1);
    delete wsk1;
    wsk1 = 0;

    const k2 * wsk2 = new k2(ob3);
    ob2 = *wsk2;
    wsk2=0;
    cout << ob2;
    cout << "here" <<endl;
    //cout << (ob2-1.25);
}


