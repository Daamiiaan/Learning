#include <iostream>

using namespace std;

class K1
{
    string *p1;

public:

    K1() : p1(new string[2]{"Brak", "Brak"}){}
    K1(string a, string b) : p1(new string[2]{a, b}){}
    K1(const K1 &K)
    {
        p1 = new string[2]{K.p1[0], K.p1[1]};
    }

    friend ostream &operator<<(ostream &out, const K1 &K);

    ostream &wypisz(ostream &out)const
    {
        return out << *p1 << " " << *(p1+1) << endl;
    }

    string &P(int i)
    {
        return p1[i];
    }

    K1 &operator=(const K1 &K)
    {
        p1[0] = K.p1[0];
        p1[1] = K.p1[1];

        return *this;
    }
};

ostream &operator<<(ostream &out, const K1 &K)
{
    return K.wypisz(out);
}

class K2
{
    K1 dane;

public:
    K2() : dane(){}
    K2(string a, string b) : dane(a, b){}

    friend ostream &operator<<(ostream &out, const K2 &K);

    ostream &wypisz(ostream &out)const
    {
        return out << dane << endl;
    }

    string &operator[](int i)
    {
        return dane.P(i);
    }
    
};

ostream &operator<<(ostream &out, const K2 &K)
{
    return K.wypisz(out);
}

int main()
{
    K2 o1, o2;
    const K2 *wsk1 =new K2("Ala", "Ola");
    const K2 o3(*wsk1);

    cout << "o2 : " << o2 << endl;
    cout << "o3 : " << o3 << endl;
    cout << "***********" << endl;

    delete wsk1;
    wsk1 = 0;

    wsk1 = new K2(o3);
    o2 = *wsk1;
    cout << "o1 : " << o1 << endl;
    cout << "o2 : " << o2 << endl;
    cout << "***********" << endl;

    delete wsk1;
    wsk1 = 0;

    o1 = K2("Ewa", "Iza");
    //cout << "o1 : " << o1 << endl;
    cout << o1[0] << ", " << o1[1] << endl;
    o1[1] = "Jan";
    cout << o1[0] << ", " << o1[1] << endl;
    
    return 0;
}
