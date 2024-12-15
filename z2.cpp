#include <iostream>

using namespace std;

class adres
{
    string miasto_, ulica_;
     int numer_;
 public:
    adres() : miasto_("brak"), ulica_("brak"), numer_(0) {}
    adres(string miasto, string ulica, int numer) : miasto_(miasto), ulica_(ulica), numer_(numer) {}
    
    friend ostream& operator<<(ostream& os, const adres& a)
    {
        os << a.miasto_ << " " << a.ulica_ << " " << a.numer_ << endl;
        return os;
    }
};
class osoba
{
    string imie_;
    int wiek_;
    adres adr_;
public:
    osoba() : imie_("brak"), wiek_("brak"), adr_(new adres a) {}
};

int main() 
{
    adres* wsk = new adres("Częstochowa", "Dąbrowskiego", 73);
    cout <<  wsk << '\n';
    cout << *wsk << '\n';

    adres a1(*wsk);
    delete wsk;
    wsk=nullptr;
    const adres* wsk1 = new adres("Łódź", "Piotrkowska", 33);

    cout << a1 << '\n';
    cout << *wsk1 << '\n';
    adres a2;
    cout << a2 << '\n';
    a2 = a1; //zadziałał domyślny kopiujacy ...
    cout << a2 << '\n';

    osoba os1("Ala", 25, *wsk1);
    delete wsk1;
}