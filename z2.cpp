class punkt{
public:
double* dane;
punkt():dane(new double[2]{0,0}){}
punkt(const double d1,const double d2):dane(new double[2]){
    dane[0]=d1;
    dane[1]=d2;}
punkt(const punkt& pe):dane(new double[2]){
    dane[0]=pe.dane[0];
    dane[1]=pe.dane[1];}
virtual ~punkt(){delete []dane;}
virtual ostream& show(ostream& out) const{
    return out<<"( "<<dane[0]<<" "<<dane[1]<<" )"<<endl;};
punkt& operator=(const punkt& pu){
    if(this!=&pu){
        dane[0]=pu.dane[0];
        dane[1]=pu.dane[1];}
    return *this;}};
ostream& operator<<(ostream& out, const punkt& pi){
    return pi.show(out);}
class wierzcholek:public punkt{
protected:
string kolor;
public:
wierzcholek():punkt(),kolor("brak"){}
wierzcholek(const double p1,const double p2, const string& x):punkt(p1,p2),kolor(x){}
wierzcholek(const wierzcholek& wi):punkt(wi.dane[0],wi.dane[1]),kolor(wi.kolor){}
~wierzcholek(){}
ostream& show(ostream& out) const override{
    return out<<"( "<<dane[0]<<" "<<dane[1]<<" - "<<kolor<<" )"<<endl;}
wierzcholek& operator=(const wierzcholek& wietnam){
    if(this!=&wietnam){
        dane[0]=wietnam.dane[0];
        dane[1]=wietnam.dane[1];
        kolor=wietnam.kolor;}
    return *this;}
double operator[](const int pos){
    if(pos>1){
        throw string("Indeks poza zakresem");}
    return dane[pos];}};
