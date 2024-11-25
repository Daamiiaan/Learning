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
     adres& operator=(const adres& a) {
        if (this != &a) {
            miasto_ = a.miasto_;
            ulica_ = a.ulica_;
            numer_ = a.numer_;
        }
        return *this;
     }

     friend ostream& operator<<(ostream& os, const adres& a)
     {
          os << "adres: " << a.miasto_ <<" " << a.ulica_ << " " << a.numer_; 
          return os;
     }  
     void setmiasto(string a){
          miasto_ = a;
     }
         string& miasto() {
        return miasto_;
    }

    const string& miasto() const {
        return miasto_;
    }  
};
class osoba
{
private:
     string imie_;
     int wiek_;
     adres adres_;
public:
     osoba() : imie_("brak"), wiek_(0), adres_("brak", "brak", 0) {}
     osoba(string imie, int wiek, adres a) : imie_(imie), wiek_(wiek), adres_(a){}
     osoba(osoba& inna) : imie_(inna.imie_), wiek_(inna.wiek_), adres_(inna.adres_) {}

     friend ostream& operator<<(ostream& os, const osoba& a)
     {
          os << a.imie_ << " " << a.wiek_ << " " << a.adres_ << endl;
          return os;
     }
     void miasto(string a)
     {
          adres_.setmiasto(a);
     }
     //dostepy do składowych
     string& miasto() {
        return adres_.miasto();
    }

    const string& miasto() const {
        return adres_.miasto();
    }
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
     adres a2; //git
     cout << a2 << '\n'; //git
     a2 = a1; //zadziałał, ale czy powinien? 
     cout << a2 << '\n';
     //osoba test;
     //cout << test;
     osoba os1("Ala", 25, *wsk1);
     delete wsk1;
     cout << os1 << '\n';
     osoba os2(os1); // kopiujacy domysliny działa, ale czy moze tak byc?
     cout << os2;
     os1.miasto()="Zmieniono miasto osoby 1."; //dostęp do zmiennej miasto????
     //czy zapis os1.miasto("Zmieniono miasto osoby 1.") nie jest lepszy? 
     cout << os1 << '\n';
     osoba os3;
     cout << os3 << '\n';
     os3 = os2;

     os1.miasto()="Drugi raz zmieniono miasto osoby 1.";
     cout << os1 << '\n';

}