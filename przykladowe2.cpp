#include <iostream>

using namespace std;

class k1
{
private:
    string* p1;
public:
    k1() : p1(new string[2] {"brak", "brak"}) {}
    k1(string a, string b) : p1(new string[2] {a, b}) {}
    k1(const k1 &a)
    {
        p1 = new string[2];
        p1[0] = a.p1[0];
        p1[1] = a.p1[1];
    }
    k1& operator=(const k1 &r)
    {
        this->p1[0] = r.p1[0];
        this->p1[1] = r.p1[1];
        return *this;
    }

    friend ostream& operator<<(ostream& os, const k1& a)
    {
        os << a.p1[0] << " " << a.p1[1];
        return os;
    }
        
    string& operator[](size_t index)
    {
        if (index >= 2) {
            throw out_of_range("poza");
        }
        return p1[index];
    }   
};
class k2
{
    k1 dane;
public:
    k2() : dane() {}
    k2(string a, string b) : dane(a, b) {}

    friend ostream& operator<<(ostream& os, const k2 &a)
    {
        os << a.dane << endl;
        return os;
    }
 
    string& operator[](size_t index)
    {
        return dane[index];
    }   
};



int main()
{
    k2 o1, o2;
    const k2 * wsk1 = new k2("ala", "koala");
    const k2 o3(*wsk1);
    cout << "o2: " << o2 <<endl;
    cout << "o3: " << o3 <<endl;

    delete wsk1;
    wsk1 = 0;

    wsk1 = new k2(o3);
    o2 = *wsk1;
    cout << "*wsk1 " <<*wsk1;
    cout << o3;

    cout << "o1: " << o1 <<endl;
    cout << "o2: " << o2 << endl;

    delete wsk1;
    wsk1 = 0;

    o1 = k2("ewa", "iza");
    cout << o1[0] << " " << o1[1];
}