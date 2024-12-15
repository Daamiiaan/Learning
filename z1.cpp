#include <iostream>

using namespace std;
class punkt{
private:
    double x_, y_, z_;
public:
    punkt() : x_(0.0), y_(0.0), z_(0.0) {}
    punkt(double x, double y, double z) : x_(x), y_(y), z_(z) {}

    double x() const { return x_;}
    double y() const { return y_;}
    double z() const { return z_;}
    double& x() {return x_;}
    double& y() {return y_;}
    double& z() {return z_;}
};
class prostokat
{
private:
    double x_, y_, z_, a_, b_;
public:
    prostokat() : x_(0.0), y_(0.0), z_(0.0), a_(0.0), b_(0.0) {}
    prostokat(double x, double y, double z, double a, double b) :
    x_(x), y_(y), z_(z), a_(a), b_(b) {}
    prostokat(const punkt& p, double a, double b) : 
    x_(p.x()), y_(p.y()), z_(p.z()), a_(a), b_(b) {}

    double x() const { return x_;}
    double y() const { return y_;}
    double z() const { return z_;}
    double a() const { return a_;}
    double b() const { return b_;}
    double& x() {return x_;}
    double& y() {return y_;}
    double& z() {return z_;}
    double& a() {return a_;}
    double& b() {return b_;}

    double pole() const {
        return a_ * b_;
    }
};
class graniastoslup
{
private:
    double x_, y_, z_, a_, b_, h_;
public:
    graniastoslup() : 
    x_(0.0), y_(0.0), z_(0.0), a_(0.0), b_(0.0), h_(0.0) {}
    graniastoslup(double x, double y, double z, double a, double b, double h):
    x_(x), y_(y), z_(z), a_(a), b_(b), h_(h){}
    graniastoslup(const punkt& p, double a, double b, double h) : 
    x_(p.x()), y_(p.y()), z_(p.z()), a_(a), b_(b), h_(h) {}
    graniastoslup(const prostokat& pr, double h) : 
    x_(pr.x()), y_(pr.y()), z_(pr.z()), a_(pr.a()), b_(pr.b()), h_(h) {}

    double x() const { return x_;}
    double y() const { return y_;}
    double z() const { return z_;}
    double a() const { return a_;}
    double b() const { return b_;}
    double h() const { return h_;}
    double& x() {return x_;}
    double& y() {return y_;}
    double& z() {return z_;}
    double& a() {return a_;}
    double& b() {return b_;}
    double& h() {return h_;}

    double objetosc() const {
        return a_ * b_ * h_;
    }

};
int main()
{
    punkt p1, p2(1,2,3);         
    const punkt p3(1.1,2.2,3.3);
    cout << p1.x() << endl;
    cout << p2.x() << endl;
 
    cout << p3.x() << endl;     

    cout << p3.x() << '\t' << p3.y() << '\t' << p3.z() << endl;
 
    p1.x()=1; p1.y()=10; p1.z()=100;  
    cout << p1.x() << '\t' << p1.y() << '\t' << p1.z() << endl;
 
    prostokat pr1, pr2(1,2,3,10.5, 20.5);
    const prostokat pr3(p2,5,5);
    pr1.x()=2; pr1.y()=20; pr1.z()=200; pr1.a()= 10; pr1.b()=10;
    cout << pr1.x() << '\t' << pr1.y() << '\t' << pr1.z() << '\t'
       << pr1.a() << '\t' << pr1.b() << '\t' << endl;
    cout << pr1.pole() << endl;
    cout << "pr3" << endl;
    cout << pr3.x() << '\t' << pr3.y() << '\t' << pr3.z() << '\t'
       << pr3.a() << '\t' << pr3.b() << '\t' << endl;

    cout << pr3.pole() << endl;  
    graniastoslup g1, g2(1,2,3,10.5,20.5,30.5), g3(p2,100,200,300);
    const graniastoslup g4(pr3,5);

    cout << g4.x() << '\t' << g4.y() << '\t' << g4.z() << '\n'
       << g4.a() << '\t' << g4.b() << '\t' << g4.h() << '\n'
       << g4.objetosc() << endl; 
    g1.a()=10; g1.b()=10; g1.h()=10;
 
    cout << g1.x() << '\t' << g1.y() << '\t' << g1.z() << '\n'
       << g1.a() << '\t' << g1.b() << '\t' << g1.h() << '\n'
       << g1.objetosc() << endl;
}