#include <iostream>
using namespace std;

class K1
{
string* p1;
public:
K1() : p1(new string("brak")){}
K1(string wartosc) : p1(new string(wartosc)) {}
friend ostream operator<< (ostream& wy, const K1 c);
};
ostream operator<< (ostream& wy, const K1& c)
{
  wy << *c.p1 << endl;
  return wy;
}

class K2
{
  K1 tab[2];
  int w1;
  public:
  K2() : tab{K1(), K1()}, w1(0){}
  K2(string a, string b, int c) : tab{K1(a), K2(b)}, w1(c) {}
  friend ostream & operator<< (ostream& wy, const K2& c);
};
ostream & operator<<(ostream& out, const K2& wy)
{
  out << wy.tab[0] << wy.tab[1] << wy.w1 << endl;
  return out;
}
