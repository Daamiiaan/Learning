#include <iostream>

using namespace std;

class point
{
private:
    double x_, y_, z_;

public:
    point() : x_(0.0), y_(0.0), z_(0.0) {}
    point(const double wiersz[3]) 
    : x_(wiersz[0]), y_(wiersz[1]), z_(wiersz[2]) {}
    point(const double x, const double y, const double z)
    : x_(x), y_(y), z_(z) {}

    friend ostream& operator<<(ostream& os, const point& p)
    {
        os << p.x_ << " " << p.y_ << " " << p.z_;
        return os;
    }
    double operator[](int index) const {
        if (index < 0 || index >= 3) {
        throw out_of_range("Index out of range!");
        }
        return point[index];  // Zwraca Swartość współrzędnej
    }
    

};

int main()
{
    double x[2][3] = {{1.0, 1.0, 1.0},
                    {1.0, 2.0, 3.0}};

    point p1(x[0]), p2(x[1]); 
    const point p3(0.4, 0.2, 0.1);
    cout << p1 << ", " << p2 << '\n';
    cout << p3[0] << ' ' << p3[1] << ' ' << p3[2] << '\n'; // damn operator []

}