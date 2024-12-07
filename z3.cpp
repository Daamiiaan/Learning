#include <iostream>
#include <cmath>
using namespace std;

class punkt
{
 private:
 double x_, y_;

public:
    //punkt() : x_(0), y_(0) {}
    punkt(double x = 0, double y = 0) : x_(x), y_(y) {}

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

class wielobok {
private:
    std::size_t rozmiar; // Liczba punktów w wieloboku
    punkt* punkty;       // Dynamicznie alokowana tablica punktów
public:

    wielobok() : rozmiar(0), punkty(nullptr) {}
    wielobok(const punkt* start, const punkt* end) 
        : rozmiar(end - start), punkty(new punkt[rozmiar]) {
        for (std::size_t i = 0; i < rozmiar; ++i) {
            punkty[i] = start[i];
        }
    }
    wielobok(wielobok& other)
    : rozmiar(other.rozmiar), punkty(new punkt[rozmiar]){
    for (size_t i = 0; i < rozmiar; i++)
    {
        punkty[i] = other.punkty[i];
    }
    }
    
        
        
        
        
        wielobok& operator=(const wielobok& other) {
        if (this != &other) {
            delete[] punkty; // Zwolnienie poprzedniej pamięci
            rozmiar = other.rozmiar;
            punkty = new punkt[rozmiar];
            for (std::size_t i = 0; i < rozmiar; ++i) {
                punkty[i] = other.punkty[i];
            }
        }
        return *this;
    }
    
    ~wielobok() {
        delete[] punkty; 
    }
    double obwod() const {
        if (rozmiar < 2) return 0.0;
        double wynik = 0.0;
        for (std::size_t i = 0; i < rozmiar; ++i) {
            wynik += punkty[i].odleglosc(punkty[(i + 1) % rozmiar]); // Ostatni łączy się z pierwszym
        }
        return wynik;
    }
    size_t ilosc() const {
        return rozmiar;
    }
        punkt& operator[](std::size_t index) {
        if (index >= rozmiar) throw std::out_of_range("Indeks poza zakresem!");
        return punkty[index];
    }
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
    cout << w1.obwod() << '\n';
    w1[1] = punkt(0.5, 0.5); // przeciaznei operator [] //
    cout << w1.obwod() << '\n';
    cout << "***\n\n";  
    wielobok w2;
    w2 = wielobok(t, t+3);
    cout << w2.obwod() << '\n';
    for (size_t i = 0; i < w2.ilosc(); ++i)
    cout << w2[i].x() << ' ' << w2[i].y() << '\n';
    cout << "\n*****\n";
    wielobok w3(w2);
    w3[1] = punkt(0, -1);
    w3[2] = punkt(-1, -1);
    for (size_t i = 0; i < w3.ilosc(); ++i)
    cout << w3[i] << endl;
    cout << "***\n\n";
    cout << "***\n\n";

    cout << "\n*****\n";
    //cout << w2 << "***\n" << w3;
    cout << "*****\n\n";

    cout << w2.obwod() - w3.obwod() << "\n\n";
}