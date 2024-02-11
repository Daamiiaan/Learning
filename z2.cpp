int main(){
    const punkt* wsk1=new punkt(1.1,2.2);
    const wierzcholek* wsk2= new wierzcholek(3.3,4.4,"red");

    wierzcholek ob1=wierzcholek(7,7,"green");
    cout<< ob1[0]<<" "<<ob1[1]<<endl;

    punkt ob2= *wsk1; delete wsk1; wsk1=0;
    wierzcholek ob3 = *wsk2; delete wsk2; wsk2=0;

    punkt* tab1[4];

    tab1[0]=new wierzcholek(ob1);
    tab1[1]=new punkt(ob2);
    tab1[2]=new wierzcholek(ob3);
    tab1[3]=new wierzcholek;

    for (int i=0;i<4;++i)
    {
        cout<<*tab1[i];
        delete tab1[i];

    }
    cout<<"****3****"<<endl;
return 0;
