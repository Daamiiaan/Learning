#include <iostream>
#include <cmath>

using namespace std;


class punkt
{
	double x_, y_;
public:
	punkt() : x_(0.0), y_(0.0){} // domyslny
	punkt(const double x, const double y) : x_(x), y_(y) {}
	//get&set//
	double& x() { return x_; }
	double& y() { return y_; }

	double odleglosc(const punkt& inny) const
	{
		return std::sqrt((x_ - inny.x_) * (x_ - inny.x_) + (y_ - inny.y_) * (y_ - inny.y_));
	}

	friend ostream& operator<<(ostream& os, const punkt& a);
	friend class wielobok; //CZY TO JEST POPRAWNE?!
};
	ostream& operator<<(ostream & os, const punkt & a) 
	{
		os << a.x_ << " " << a.y_ << endl;
		return os;
	}
class wielobok
{
	punkt* punkty_;
	punkt* p;
	int rozmiar_;
public:
	wielobok() {}
	wielobok(const punkt* start, const punkt* stop)
	{	
		if (stop > start)
		{
			rozmiar_ = stop - start;
		}
		else
		{
			rozmiar_ = start - stop;
		}

		punkty_ = new punkt[rozmiar_];  //alokacja pamieci
		for (int i = 0; i < rozmiar_; ++i) {
			punkty_[i] = start[i];
		}
	}
	~wielobok() {
		delete[] punkty_;
	}


double odleglosc(const punkt& p1, const punkt& p2) const {
	return sqrt((p2.x_ - p1.x_) * (p2.x_ - p1.x_) + (p2.y_ - p1.y_) * (p2.y_ - p1.y_));
}

double obwod() const {
	double suma = 0.0;
	for (int i = 0; i < rozmiar_ - 1; ++i) {
		suma += odleglosc(punkty_[i], punkty_[i + 1]);
	}
	suma += odleglosc(punkty_[rozmiar_ - 1], punkty_[0]);
	return suma;
}
punkt& operator[](int index) {
	return punkty_[index]; // czarna magia
}
};

int main()
{
	punkt p(2, 3);
	cout << p.x() << ' ' << p.y() << '\n';
	p.x() = 1;
	p.y() = 1;
	cout << p.x() << ' ' << p.y() << '\n';
	cout << p.odleglosc(punkt()) << "\n\n";
	const punkt t[] = { punkt(0, 0), punkt(0, 1), punkt(1, 1), punkt(1, 0) };
	for (size_t i = 0; i < sizeof(t) / sizeof(punkt); ++i)
		cout << i + 1 << ")  " << t[i] << endl;
	cout << "\n*****\n";
	wielobok w1(t, t + 4);
	cout << w1.obwod() << '\n'; //friend class wielobok?!
	w1[1] = punkt(0.5, 0.5);
	cout << w1.obwod() << '\n';
	cout << "***\n\n";


	return 0;
}