class K1
{
string *P1;

public:

K1():P1(new string("brak")){}
K1(string a):P1(new string(a)){}
K1(const K1 &a)
{
P1=new string();
*P1=*a.P1;
}
~K1()
{
delete P1;
}

K1 &operator=(K1 c)
{
*P1=*c.P1;
return *this;
}

friend ostream &operator<< (ostream &wypisz,const K1 a);
};

ostream &operator<<(ostream &wypisz,const K1 a)
{
wypisz<<*a.P1< return wypisz;
}

class K2
{
K1 tab[2];
int w1;

public:

K2():tab{K1(),K1()},w1(0){}
K2(string a,string b, int c):tab{K1(a),K1(b)},w1(c){}

K2 operator+(int a)
{
this->w1=w1+a;
return *this;
}
friend ostream &operator<<(ostream &wypisz, const K2 b);
};

ostream &operator<<(ostream &wypisz, const K2 b)
{
wypisz< return wypisz;
}
