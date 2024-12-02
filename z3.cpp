#include <iostream>
#include <cmath>
using namespace std;

class punkt
{
 private:
 double x_, y_;

public:
    punkt() : x_(0), y_(0) {}
    punkt(double x, double y) : x_(x), y_(y) {}

//dostep
double& x() {return x_;}
double& y() {return y_;}
double x() const {return x_;}
double y() const {return y_;}

double odleglosc( punkt other)
{
    return sqrt((x_ - other.x())*(x_ - other.x()) + ((y_ - other.y()) * (y_ - other.y())));
}
    
friend ostream& operator<<(ostream& os, const punkt& p)
    {
        os << p.x_ << " " << p.y_;
        return os;
    }
};

class wielobok 
{
private:
    punkt t[4]; //!?!//
    size_t roz;
public:
    wielobok(size_t roz) : {} 
};

int main()
{
    punkt p(2, 3);\
    cout << p.x() << ' ' << p.y() << '\n';
    p.x() = 1;
    p.y() = 1;
    cout << p.x() << ' ' << p.y() << '\n';
    cout << p.odleglosc(punkt()) << "\n\n";
    const punkt t[] = { punkt(0, 0), punkt(0, 1), punkt(1, 1), punkt(1, 0) };
    for(size_t i=0; i < sizeof(t)/sizeof(punkt); ++i)
    {
        cout << i+1 << ")  " << t[i] << endl;
    }
    //indeks od zera do 3 !
    cout << "\n*****\n";
wielobok w1(t, t+4); // is that dynamic alocationm?! https://www.fuw.edu.pl/~kpias/pzfmni/wyklad78.pdf// page 18.

}