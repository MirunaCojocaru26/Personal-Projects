#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
#include <typeinfo>
using namespace std;

//prima clasa
class farmacie_abstracta
{
public:
    farmacie_abstracta(){}
    farmacie_abstracta(farmacie_abstracta&x){}
    farmacie_abstracta& operator=(farmacie_abstracta&x){return *this;}
    friend istream&operator>>(istream&in,farmacie_abstracta&x){return in;}
    friend ostream&operator<<(ostream&out,farmacie_abstracta&x){return out;}
    virtual void afisare(){cout<<"Ce naiba cauti aici?";}
    virtual ~farmacie_abstracta(){}
};

//a doua clasa
class farmacie: public farmacie_abstracta
{
protected:
    int nr_angajati;
    char *denumire;
    double *profit;
public:
     farmacie();
    farmacie(int,char*,double*);
    farmacie(farmacie&);
    farmacie&operator=(farmacie&);
    friend istream& operator>>(istream&,farmacie&);
    friend ostream&operator<<(ostream&,farmacie&);
    void afisare();
    ~farmacie();
};
farmacie::farmacie()
{
    nr_angajati=0;
    if(denumire=new char[100]);
    else throw 3;
    strcpy(denumire,"\0");
    profit=new double[12];
    for(int i=0;i<12;i++)
        profit[i]=0;
}
farmacie::farmacie(int a, char*s, double *d)
{
    nr_angajati=a;
    if(denumire=new char[strlen(s)]);
    else throw 3;
    strcpy(denumire,s);
    profit=new double[12];
    for(int i=0;i<12;i++)
        profit[i]=d[i];
}
farmacie::farmacie(farmacie& x)
{
    nr_angajati=x.nr_angajati;
    if(denumire=new char[strlen(x.denumire)]);
    else throw 3;
    strcpy(denumire,x.denumire);
    profit=new double[12];
    for(int i=0;i<12;i++)
        profit[i]=x.profit[i];
}
farmacie& farmacie::operator=(farmacie& x)
{
    if(this!=&x)
    {
        nr_angajati=x.nr_angajati;
        if(denumire=new char[strlen(x.denumire)]);
        else throw 3;
        strcpy(denumire,x.denumire);
        if(profit=new double[12]);
        else throw 3;
        for(int i=0;i<12;i++)
            profit[i]=x.profit[i];
    }
    return *this;
}
istream& operator>>(istream&in,farmacie&x)
{
    cout<<"Nr angajati=";
    in>>x.nr_angajati;
    cout<<"Denumire=";
    cin>>x.denumire;
    if(x.profit=new double[12]);
    else throw 3;
    cout<<"Profit pe 12 luni: ";
    for(int i=0;i<12;i++)
        in>>x.profit[i];
    return in;
}
ostream& operator<<(ostream& out,farmacie &x)
{
    out<<"Nr de angajati: "<<x.nr_angajati<<endl;
    out<<"Denumire: "<<x.denumire<<endl;
    out<<"Profit pe luni: ";
    for(int i=0;i<12;i++)
        out<<x.profit[i]<<" ";
    out<<endl;
    return out;
}
void farmacie::afisare()
{
    cout<<"Nr de angajati: "<<nr_angajati<<endl;
    cout<<"Denumire: "<<denumire<<endl;
    cout<<"Profit pe luni: ";
    for(int i=0;i<12;i++)
        cout<<profit[i]<<" ";
    cout<<endl;
}
farmacie::~farmacie()
{
    nr_angajati=0;
    delete[]denumire;
    delete[]profit;
}

//a treia clasa
class farmacie_online:public farmacie_abstracta
{
    char *adresa_web;
    int nr_vizitatori;
    float discount;
public:
     farmacie_online();
    farmacie_online(int,float,char*);
    farmacie_online(farmacie_online&);
    farmacie_online& operator=(farmacie_online&);
    friend istream&operator>>(istream&,farmacie_online&);
    friend ostream&operator<<(ostream&,farmacie_online&);
    void afisare();
    int get_viz(){return nr_vizitatori;}
    ~farmacie_online();
};
farmacie_online::farmacie_online()
{
    if(adresa_web=new char[100]);
    else throw 3;
    strcpy(adresa_web,"\0");
    nr_vizitatori=0;
    discount=0;
}
farmacie_online::farmacie_online(int a,float b,char s[])
{
    nr_vizitatori=a;
    discount=b;
    if( adresa_web=new char[strlen(s)]);
    else throw 3;
    strcpy(adresa_web,s);
}
farmacie_online::farmacie_online(farmacie_online&x)
{
    nr_vizitatori=x.nr_vizitatori;
    discount=x.discount;
    if(adresa_web=new char[strlen(x.adresa_web)]);
    else throw 3;
    strcpy(adresa_web,x.adresa_web);
}
farmacie_online&farmacie_online::operator=(farmacie_online& x)
{
    if(this!=&x)
    {
        nr_vizitatori=x.nr_vizitatori;
        discount=x.discount;
        adresa_web=new char[strlen(x.adresa_web)];
        strcpy(adresa_web,x.adresa_web);
    }
    return *this;
}
istream& operator>>(istream&in,farmacie_online&x)
{
    cout<<"Adresa web=";
    if(x.adresa_web=new char[100]);
    else throw 3;
    in>>x.adresa_web;
    cout<<"Nr vizitatori=";
    in>>x.nr_vizitatori;
    cout<<"Discount=";
    in>>x.discount;
    return in;
}
ostream& operator<<(ostream&out,farmacie_online&x)
{
    out<<"Adresa: "<<x.adresa_web<<endl;
    out<<"Nr vizitatori: "<<x.nr_vizitatori<<endl;
    out<<"Discount: "<<x.discount<<endl;
    return out;
}
void farmacie_online::afisare()
{
    cout<<"Adresa: "<<adresa_web<<endl;
    cout<<"Nr vizitatori: "<<nr_vizitatori<<endl;
    cout<<"Discount: "<<discount<<endl;
}
farmacie_online::~farmacie_online()
{
    delete[]adresa_web;
}

template<class T> class GestionareFarmacii;
template<class T> ostream& operator <<(ostream&,GestionareFarmacii<T>&);
template<class T> istream& operator >>(istream&,GestionareFarmacii<T>&);

//clasa template
template <class T>
class GestionareFarmacii
{
    int index;
    const int id;
    vector<T*> v;
public:
    GestionareFarmacii(int i=0):id(i){index=0;}
    GestionareFarmacii(int idd, vector<T*> w):id(idd)
    {
            index=0;
            for(int i=0;i<w.size();i++)
                v.push_back(w[i]);
    }
    GestionareFarmacii(GestionareFarmacii&x):id(x.id)
    {
        index=x.index;
        for(int i=0;i<x.v.size();i++)
            v.push_back(x.v[i]);
    }
    GestionareFarmacii<T>&operator=(GestionareFarmacii<T>&);
    GestionareFarmacii<T>&operator+=(T&);
    friend ostream& operator<< <>(ostream&,GestionareFarmacii<T>&);
    friend istream& operator>> <>(istream&,GestionareFarmacii<T>&);
    void afisare();
    ~GestionareFarmacii(){v.clear();}
};
template <class T>
GestionareFarmacii<T>&GestionareFarmacii<T>::operator=(GestionareFarmacii<T>&x)
{
    index=x.index;
    for(int i=0;i<x.v.size();i++)
        v.push_back(x.v[i]);
    return *this;
}
template <class T>
GestionareFarmacii<T>&GestionareFarmacii<T>::operator+=(T&x)
{
    v.push_back(&x);
    index ++;
    return *this;
}
template <class T>
ostream&operator<<(ostream&out,GestionareFarmacii<T>&x)
{
    out<<"ID: "<<x.id<<endl;
    out<<"Index: "<<x.index<<endl;
    out<<"Obiecte:"<<endl;
    for(int i=0;i<x.v.size();i++)
        (*x.v[i]).afisare();
    return out;
}
template <class T>
istream&operator>>(istream&in,GestionareFarmacii<T>&x)
{
    int nr;
    cout<<"Nr obiecte=";
    in>>nr;
    for(int i=0;i<nr;i++)
    {
        T *a;
        if(a= new T);
        else throw 3;
        in>>(*a);
        x.v.push_back(a);
    }
    return in;
}
template <class T>
void GestionareFarmacii<T>::afisare()
{
    cout<<"ID: "<<id<<endl;
    cout<<"Index: "<<index<<endl;
    cout<<"Obiecte:"<<endl;
    for(int i=0;i<v.size();i++)
        (*v[i]).afisare();
}

//specializare
template <>
class GestionareFarmacii<farmacie_online>
{
    int index;
    const int id;
    vector<farmacie_online*> v;
public:
    GestionareFarmacii(int i=0):id(i){index=0;}
    GestionareFarmacii(int idd, vector<farmacie_online*> w):id(idd)
    {
        index=0;
        for(int i=0;i<w.size();i++)
        {
            v.push_back(w[i]);
            index++;
        }
    }
    GestionareFarmacii(GestionareFarmacii&x):id(x.id)
    {
        index=x.index;
        for(int i=0;i<x.v.size();i++)
            v.push_back(x.v[i]);
    }
    GestionareFarmacii<farmacie_online>&operator=(GestionareFarmacii<farmacie_online>&);
    GestionareFarmacii<farmacie_online>&operator+=(farmacie_online&);
    friend ostream& operator<< <>(ostream&,GestionareFarmacii<farmacie_online>&);
    friend istream& operator>> <>(istream&,GestionareFarmacii<farmacie_online>&);
    ~GestionareFarmacii(){v.clear();}
};
GestionareFarmacii<farmacie_online>& GestionareFarmacii<farmacie_online>:: operator=(GestionareFarmacii<farmacie_online>&x)
{
    index=x.index;
    for(int i=0;i<x.v.size();i++)
        v.push_back(x.v[i]);
    return *this;
}
GestionareFarmacii<farmacie_online>&GestionareFarmacii<farmacie_online>::operator+=(farmacie_online&x)
{
    v.push_back(&x);
    index++;
    return *this;
}
template <>
ostream&operator<<(ostream&out,GestionareFarmacii<farmacie_online>&x)
{
    int sum=0;
    for(int i=0;i<x.v.size();i++)
    {
        sum=sum+(*x.v[i]).get_viz();
    }
    out<<sum;
    return out;
}
template <>
istream&operator>>(istream&in,GestionareFarmacii<farmacie_online>&x)
{
    int nr;
    cout<<"Nr obiecte=";
    in>>nr;
    for(int i=0;i<nr;i++)
    {
        x.index++;
        farmacie_online *a;
        if(a= new farmacie_online);
        else throw 3;
        cin>>(*a);
        x.v.push_back(a);
    }
    return in;
}


int main()
{
    try
    {
        int x=1;
        while(x!=5)
        {
            cout<<"1-Utilizati clasa Farmacie"<<endl;
            cout<<"2-Utilizati clasa Farmacie online"<<endl;
            cout<<"3-Utilizati clasa Farmacie abstracta(clasa de baza)"<<endl;
            cout<<"4-Utilizati clasa template GestiuneFarmacii"<<endl;
            cout<<"5-Iesiti din meniu"<<endl;
            cout<<endl<<"Comanda: ";
            cin>>x;
            cout<<endl;
            switch(x)
            {
                case 1:{int a=1;
                        cout<<"1-Citirea si afisarea unui obiect"<<endl;
                        cout<<"2-Utilizarea constructorului de copiere"<<endl;
                        cout<<"3-Utilizarea operatorului ="<<endl;
                        cout<<"4-Citirea si afisarea a n obiecte"<<endl;
                        cout<<"5-Revenirea la meniul anterior"<<endl;
                        while(a!=5)
                        {
                            cout<<endl<<"Comanda: ";
                            cin>>a;
                            cout<<endl;
                            switch(a)
                            {
                                case 1:{farmacie f;
                                        cin>>f;
                                        cout<<f;
                                        break;}
                                case 2:{farmacie f1;
                                        cin>>f1;
                                        farmacie f2(f1);
                                        cout<<f2;
                                        break;}
                                case 3:{farmacie f1,f2;
                                        cin>>f1;
                                        f2=f1;
                                        cout<<f2;
                                        break;}
                                case 4:{int n;
                                        cout<<"Numarul de obiecte=";
                                        cin>>n;
                                        farmacie *f;
                                        if(f=new farmacie[n]);
                                        else throw 3;
                                        for(int i=0;i<n;i++)
                                            cin>>f[i];
                                        cout<<endl;
                                        for(int i=0;i<n;i++)
                                            cout<<f[i];
                                        delete[]f;}
                                case 5:{break;}
                                default:{throw 2;
                                        break;}
                            }
                        }
                        break;
                        }
                case 2:{int a=1;
                        cout<<"1-Citirea si afisarea unui obiect"<<endl;
                        cout<<"2-Utilizarea constructorului de copiere"<<endl;
                        cout<<"3-Utilizarea operatorului ="<<endl;
                        cout<<"4-Citirea si afisarea a n obiecte"<<endl;
                        cout<<"5-Revenirea la meniul anterior"<<endl;
                        while(a!=5)
                        {
                            cout<<endl<<"Comanda: ";
                            cin>>a;
                            cout<<endl;
                            switch(a)
                            {
                                case 1:{farmacie_online f;
                                        cin>>f;
                                        cout<<f;
                                        break;}
                                case 2:{farmacie_online f1;
                                        cin>>f1;
                                        farmacie_online f2(f1);
                                        cout<<f2;
                                        break;}
                                case 3:{farmacie_online f1,f2;
                                        cin>>f2;
                                        f2=f1;
                                        cout<<f2;
                                        break;}
                                case 4:{int n;
                                        cout<<"Numarul de obiecte=";
                                        cin>>n;
                                        farmacie_online *f;
                                        if(f=new farmacie_online[n]);
                                        else throw 3;
                                        for(int i=0;i<n;i++)
                                            cin>>f[i];
                                        cout<<endl;
                                        for(int i=0;i<n;i++)
                                            cout<<f[i];
                                        break;}
                                case 5:{break;}
                                default: {throw 2;
                                        break;}
                            }
                        }
                        break;
                        }
                case 3:{int n, a;
                        cout<<"Nr de obiecte:";
                        cin>>n;
                        farmacie_abstracta **v;
                        if(v=new farmacie_abstracta*[n]);
                        else throw 3;
                        for(int i=0;i<n;i++)
                        {
                            cout<<"Pentru un obiect de tip farmacie apasati 1"<<endl;
                            cout<<"Pentru un obiect de tip farmacie online apasati 2"<<endl;
                            cin>>a;
                            if(a==1)
                            {
                                farmacie *x;
                                if(x=new farmacie);
                                else throw 3;
                                cin>>(*x);
                                v[i]=static_cast<farmacie_abstracta*>(x);
                            }
                            else
                            {
                                farmacie_online *x;
                                if(x=new farmacie_online);
                                else throw 3;
                                cin>>(*x);
                                v[i]=static_cast<farmacie_abstracta*>(x);
                            }
                        }
                        cout<<endl;
                        for(int i=0;i<n;i++)
                            v[i]->afisare();
                        delete[]v;
                        break;
                        }
                case 4:{int a=1;
                        cout<<"template<class T>"<<endl;
                        cout<<"1-T=Farmacie"<<endl;
                        cout<<"2-T=Farmacie online(specializare)"<<endl;
                        cout<<"3-T=Farmacie abstracta"<<endl;
                        cout<<"4-Revenirea la meniul anterior"<<endl;
                        while(a!=4)
                        {
                            cout<<endl<<"Comanda:";
                            cin>>a;
                            cout<<endl;
                            switch(a)
                            {
                                case 1:{int b=1;
                                        cout<<"1-Citirea si afisarea unui obiect"<<endl;
                                        cout<<"2-Utilizarea constructorului de copiere"<<endl;
                                        cout<<"3-Utilizarea operatorului ="<<endl;
                                        cout<<"4-Utilizarea operatorului +="<<endl;
                                        cout<<"5-Revenirea la meniul anterior"<<endl;
                                        while(b!=5)
                                        {
                                            cout<<endl<<"Comanda:";
                                            cin>>b;
                                            cout<<endl;
                                            switch(b)
                                            {
                                                case 1:{int idd;
                                                        cout<<"Introduceti id-ul: ";
                                                        cin>>idd;
                                                        GestionareFarmacii<farmacie> f(idd);
                                                        cin>>f;
                                                        cout<<f;
                                                        break;}
                                                case 2:{int idd;
                                                        cout<<"Introduceti id-ul: ";
                                                        cin>>idd;
                                                        GestionareFarmacii<farmacie> f1(idd);
                                                        cin>>f1;
                                                        GestionareFarmacii<farmacie> f2(f1);
                                                        cout<<f2;
                                                        break;}
                                                case 3:{int idd;
                                                        cout<<"Introduceti id-ul: ";
                                                        cin>>idd;
                                                        GestionareFarmacii<farmacie> f1(idd),f2(idd);
                                                        cin>>f1;
                                                        f2=f1;
                                                        if(typeid(f1)!=typeid(f2)) throw 1;
                                                        cout<<f2;
                                                        break;}
                                                case 4:{int idd;
                                                        cout<<"Introduceti id-ul: ";
                                                        cin>>idd;
                                                        GestionareFarmacii<farmacie>f(idd);
                                                        farmacie y;
                                                        cin>>y;
                                                        f+=y;
                                                        cout<<f;
                                                        break;}
                                                case 5:{break;}
                                                default:{throw 2;
                                                        break;}
                                            }
                                        }
                                        }
                                case 2:{int b=1;
                                        cout<<"1-Citirea si afisarea unui obiect"<<endl;
                                        cout<<"2-Utilizarea constructorului de copiere"<<endl;
                                        cout<<"3-Utilizarea operatorului ="<<endl;
                                        cout<<"4-Utilizarea operatorului +="<<endl;
                                        cout<<"5-Revenirea la meniul anterior"<<endl;
                                        while(b!=5)
                                        {
                                            cout<<endl<<"Comanda:";
                                            cin>>b;
                                            cout<<endl;
                                            switch(b)
                                            {
                                                case 1:{int idd;
                                                        cout<<"Introduceti id-ul: ";
                                                        cin>>idd;
                                                        GestionareFarmacii<farmacie_online> f(idd);
                                                        cin>>f;
                                                        cout<<f;
                                                        break;}
                                                case 2:{int idd;
                                                        cout<<"Introduceti id-ul: ";
                                                        cin>>idd;
                                                        GestionareFarmacii<farmacie_online> f1(idd);
                                                        cin>>f1;
                                                        GestionareFarmacii<farmacie_online> f2(f1);
                                                        cout<<f2;
                                                        break;}
                                                case 3:{int idd;
                                                        cout<<"Introduceti id-ul: ";
                                                        cin>>idd;
                                                        GestionareFarmacii<farmacie_online> f1(idd),f2(idd);
                                                        cin>>f1;
                                                        f2=f1;
                                                        if(typeid(f1)!=typeid(f2)) throw 1;
                                                        cout<<f2;
                                                        break;}
                                                case 4:{int idd;
                                                        cout<<"Introduceti id-ul: ";
                                                        cin>>idd;
                                                        GestionareFarmacii<farmacie_online>f(idd);
                                                        farmacie_online y;
                                                        cin>>y;
                                                        f+=y;
                                                        cout<<f;
                                                        break;}
                                                case 5:{break;}
                                                default:{throw 2;
                                                        break;}
                                        }
                                    }
                                    }
                                case 3:{int b=1;
                                        cout<<"1-Citirea si afisarea unui obiect"<<endl;
                                        cout<<"2-Citirea a n obiecte"<<endl;
                                        cout<<"3-Revenirea la meniul anterior"<<endl;
                                        while(b!=3)
                                        {
                                            cout<<endl<<"Comanda: ";
                                            cin>>b;
                                            cout<<endl;
                                            switch(b)
                                            {
                                                case 1:{cout<<"Introduceti ID: ";
                                                        int idd;
                                                        cin>>idd;
                                                        GestionareFarmacii<farmacie_abstracta> exemplu(idd);
                                                        cout<<"Pentru a introduce un element de tip Farmacie apasati 1"<<endl;
                                                        cout<<"Pentru a introduce un element de tip Farmacie online apasati 2"<<endl;
                                                        int nr;
                                                        cout<<"nr=";
                                                        cin>>nr;
                                                        while(nr==1||nr==2)
                                                        {
                                                            if(nr==1)
                                                            {
                                                                farmacie *x;
                                                                if(x=new farmacie);
                                                                else throw 3;
                                                                cin>>(*x);
                                                                exemplu+=(*static_cast<farmacie_abstracta*>(x));
                                                            }
                                                            else
                                                                if(nr==2)
                                                                {
                                                                    farmacie_online *y;
                                                                    if(y=new farmacie_online);
                                                                    else throw 3;
                                                                    cin>>(*y);
                                                                    exemplu+=(*static_cast<farmacie_abstracta*>(y));
                                                                }
                                                            cout<<"nr=";
                                                            cin>>nr;
                                                        }
                                                        cout<<endl<<exemplu;
                                                        break;}
                                                case 2:{cout<<"Cate obiecte doriti sa cititi? ";
                                                        int n;
                                                        cin>>n;
                                                        GestionareFarmacii<farmacie_abstracta> *vec;
                                                        if(vec=new GestionareFarmacii<farmacie_abstracta>[n]);
                                                        else throw 3;
                                                        for(int i=0;i<n;i++)
                                                        {
                                                            cout<<"Pentru a introduce un element de tip Farmacie apasati 1"<<endl;
                                                            cout<<"Pentru a introduce un element de tip Farmacie online apasati 2"<<endl;
                                                            int nr;
                                                            cout<<"nr=";
                                                            cin>>nr;
                                                            while(nr==1||nr==2)
                                                            {
                                                                if(nr==1)
                                                                {
                                                                    farmacie *x;
                                                                    x=new farmacie;
                                                                    cin>>(*x);
                                                                    vec[i]+=(*static_cast<farmacie_abstracta*>(x));
                                                                }
                                                                else
                                                                    if(nr==2)
                                                                    {
                                                                        farmacie_online *y;
                                                                        y=new farmacie_online;
                                                                        cin>>(*y);
                                                                        vec[i]+=(*static_cast<farmacie_abstracta*>(y));
                                                                    }
                                                                cout<<"nr=";
                                                                cin>>nr;
                                                            }
                                                        }
                                                        cout<<endl;
                                                        for(int i=0;i<n;i++)
                                                            cout<<vec[i]<<endl;
                                                        delete[]vec;
                                                        break;}
                                                case 3:{break;}
                                                default:{throw 2;
                                                        break;}
                                            }
                                        }
                                        }
                                case 4:{break;}
                                default:{throw 2;
                                        break;}
                            }
                        }
                }
                case 5:{break;}
                default:{throw 2;;
                        break;}
            }
        }
    }
    catch(int e){if(e==1)cout<<"Tipuri de date incorecte";
                if(e==2)cout<<"Caz incorect";
                if(e==3)cout<<"Nu s-a putut aloca spatiu";}
    return 0;
}
