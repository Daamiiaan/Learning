#include <iostream>
#include <cmath>

using namespace std;

class punkt{
private:
    double x_, y_;
public:
    punkt() : x_(0.0), y_(0.0) {}
    punkt(double x, double y) : x_(x), y_(y) {}

    double& x() {return x_;}
    double& y() {return y_;}

    double odleglosc( punkt other)
    {
        return sqrt((x_ - other.x())*(x_ - other.x()) + ((y_ - other.y()) * (y_ - other.y())));
    }
};

int main() {
  punkt p(2, 3);
  cout << p.x() << ' ' << p.y() << '\n';
  p.x() = 1;
  p.y() = 1;
  cout << p.x() << ' ' << p.y() << '\n';
  cout << p.odleglosc(punkt()) << "\n\n";
  const punkt t[] = { punkt(0, 0), punkt(0, 1), punkt(1, 1), punkt(1, 0) };
  for(size_t i=0; i < sizeof(t)/sizeof(punkt); ++i)
    cout << i+1 << ")  " << t[i] << endl;

  cout << "\n*****\n";
  wielobok w1(t, t+4);
}