#include <iostream>

using namespace std;

class adres
{
private:
string miasto_, ulica_;
int numer_;
public:
     adres() : miasto_("brak"), ulica_("brak"), numer_(0) {}
     adres(string miasto, string ulica, int numer) : miasto_(miasto), ulica_(ulica), numer_(numer) {}
     adres( const adres& a) : miasto_(a.miasto_), ulica_(a.ulica_), numer_(a.numer_) {} // kopia


     friend ostream& operator<<(ostream& os, const adres& a)
     {
          os << "adres: " << a.miasto_ <<" " << a.ulica_ << " " << a.numer_; 
          return os;
     }     

};
class osoba
{
private:
string imie_;
int wiek_;
const adres& adres_;
public:
     osoba() : imie_("brak"), wiek_(0), adres_( adres("brak", "brak", 0)) {}
     osoba(string imie, int wiek, adres& a) : imie_(imie), wiek_(wiek), adres_(const adres ()) {}

};

int main()
{
     adres* wsk = new adres("Częstochowa", "Dąbrowskiego", 73);
     cout <<  wsk << '\n'; // wskazuje na adres
     cout << *wsk << '\n'; // wskazuje na zawartość adresu wsk
     adres a1(*wsk); //tworzy obiekt a1 z danymi, ktore wskazuje wskaznik
     cout << a1 <<"a1" << endl;
     delete wsk;
     wsk=nullptr; // czyszcznie do 0
     const adres* wsk1 = new adres("Łódź", "Piotrkowska", 33); //tworzy staly obiekt wsk1 ktory jest wskaznikiem do nowego adresu
     
     cout << a1 << "czwa,dabra,73" << endl; //adres a1 przechowuje wartosci pomimo usuniecia wskaznika
     cout << *wsk1 << "wskaznik na obiekt stały typu adres" << endl;
     cout << wsk1 << "wskaznik" << endl;
     adres a2;
     cout << a2 << '\n';
     a2 = a1; //zadziałał, ale czy powinien? dodane kopiujacy
     cout << a2 << '\n';
     osoba os1("Ala", 25, *wsk1);



     return 0;
}