#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
class automat
{
    char ***matrix;
    int litere,stari;
public:
    automat();
    friend istream& operator>>(istream&,automat&);
    friend ostream& operator<<(ostream&,automat&);
    void transformare();
    void lamda();
    int verificare_lamda();
    void adaug();
    void interschimba();
    void matrice_de_stari(automat&);
    void elimin_stari();
    void afisare();
    ~automat();
};
automat::automat()
{
    litere=0;
    stari=0;
}
istream& operator>>(istream& in,automat& v)
{
    char*s,*a;
    s=new char[1000];
    a=new char[1000];
    in.getline(s,1000);
    int k=0,m=0;
    for(int i=0;i<strlen(s);i++)
        if(s[i]==' ')
            k++;
    v.litere=k+1;
    in.getline(a,1000);
    for(int i=0;i<strlen(a);i++)
        if(a[i]==' ')
            m++;
    v.stari=m+1;
    v.matrix=new char**[v.stari*10];
    for(int i=0;i<=v.stari;i++)
        v.matrix[i]=new char*[v.litere+2];
    for(int i=0;i<=v.stari;i++)
        for(int j=0;j<=v.litere+1;j++)
            v.matrix[i][j]=new char[30];
    char *cuv,*aux;
    int nr=1;
    cuv=strtok(a," ");
    while(cuv)
    {
        strcpy(v.matrix[nr][0],cuv);
        nr++;
        cuv=strtok(NULL," ");
    }
    nr=1;
    aux=strtok(s," ");
    while(aux)
    {
        strcpy(v.matrix[0][nr],aux);
        nr++;
        aux=strtok(NULL," ");
    }
    strcpy(v.matrix[0][0],"-");
    for(int i=1;i<=v.stari;i++)
        for(int j=1;j<=v.litere+1;j++)
            strcpy(v.matrix[i][j],"-");
    in.getline(s,1000);
    cuv=strtok(s," ");
    while(cuv)
    {
        int i;
        for(i=1;i<=v.stari;i++)
            if(strcmp(v.matrix[i][0],cuv)==0)
                break;
        strcpy(v.matrix[i][v.litere+1],"I");
        cuv=strtok(NULL," ");
    }
    in.getline(s,1000);
    cuv=strtok(s," ");
    while(cuv)
    {
        int i;
        for(i=1;i<=v.stari;i++)
            if(strcmp(v.matrix[i][0],cuv)==0)
                break;
        if(strcmp(v.matrix[i][v.litere+1],"-")==0)
            strcpy(v.matrix[i][v.litere+1],"F");
        else strcat(v.matrix[i][v.litere+1],"F");
        cuv=strtok(NULL," ");
    }
    cuv=new char[1000];
    while(in>>cuv>>s>>a)
    {
        int i,j;
        for(i=1;i<=v.stari;i++)
            if(strcmp(cuv,v.matrix[i][0])==0)
                break;
        for(j=1;j<=v.litere;j++)
            if(strcmp(a,v.matrix[0][j])==0)
                break;
        if(strcmp(v.matrix[i][j],"-")==0)
            strcpy(v.matrix[i][j],s);
        else
        {
            strcat(v.matrix[i][j]," ");
            strcat(v.matrix[i][j],s);
        }
    }
    delete[]s;
    delete[]a;
    delete[]cuv;
    return in;
}
void automat::transformare()
{
    for(int i=1;i<=stari;i++)
        for(int j=1;j<=litere;j++)
        {
            int k;
            for(k=1;k<=stari;k++)
                if(strcmp(matrix[i][j],matrix[k][0])==0||strcmp(matrix[i][j],"-")==0)
                    break;
            if(k>stari)
            {
                stari++;
                matrix[stari]=new char*[litere+2];
                matrix[stari][0]=new char[30];
                strcpy(matrix[stari][0],matrix[i][j]);
                for(k=1;k<=litere+1;k++)
                {
                    matrix[stari][k]=new char[30];
                    strcpy(matrix[stari][k],"-");
                }
                char *ax,az[30];
                strcpy(az,matrix[stari][0]);
                ax=strtok(az," ");
                while(ax)
                {
                    int h;
                    for(h=1;h<stari;h++)
                    {
                        if(strcmp(matrix[h][0],ax)==0)
                            break;
                    }
                    for(int p=1;p<=litere;p++)
                    {
                        if(strcmp(matrix[h][p],"-")!=0)
                            if(strcmp(matrix[stari][p],"-")==0)
                                strcpy(matrix[stari][p],matrix[h][p]);
                            else
                            {
                                strcat(matrix[stari][p]," ");
                                strcat(matrix[stari][p],matrix[h][p]);
                            }
                    }
                    if(strcmp(matrix[h][litere+1],"-")!=0)
                        if(strcmp(matrix[stari][litere+1],"-")==0)
                            strcpy(matrix[stari][litere+1],matrix[h][litere+1]);
                        else strcat(matrix[stari][litere+1],matrix[h][litere+1]);
                    ax=strtok(NULL," ");
                }
            }
        }
}
void automat::lamda()
{
    for(int i=1;i<=stari;i++)
    {
        if(strcmp(matrix[i][litere+1],"I")!=0)
            if(strcmp(matrix[i][litere],"-")!=0)
            {
                int j;
                for(j=1;j<=stari;j++)
                    if(strcmp(matrix[i][litere],matrix[j][0])==0)
                        break;
                for(int k=1;k<litere;k++)
                {
                    if(strcmp(matrix[i][k],"-")==0)
                        strcpy(matrix[i][k],matrix[j][k]);
                    else if(strcmp(matrix[j][k],"-")!=0)
                         {
                            strcat(matrix[i][k]," ");
                            strcat(matrix[i][k],matrix[j][k]);
                         }
                }
                strcpy(matrix[i][litere],matrix[j][litere]);
                if(strcmp(matrix[i][litere+1],"-")==0)
                    strcpy(matrix[i][litere+1],matrix[j][litere+1]);
            }
    }
}
int automat::verificare_lamda()
{
    for(int i=1;i<=stari;i++)
        if(strcmp(matrix[i][litere],"-")!=0&&strcmp(matrix[i][litere+1],"I")!=0)
            return 0;
    return 1;
}
ostream& operator<<(ostream& out,automat &v)
{
    for(int i=0;i<=v.stari;i++)
    {
        for(int j=0;j<=v.litere+1;j++)
            out<<v.matrix[i][j]<<"              ";
        out<<endl;
    }
    return out;
}
void automat::adaug()
{
    int i;
    for(i=1;i<=stari;i++)
        if(strchr(matrix[i][litere+1],'I'))
            break;
    stari++;
    matrix[stari]=new char*[litere+2];
    matrix[stari][0]=new char[30];
    strcpy(matrix[stari][0],"start");
    for(int j=1;j<litere;j++)
    {
        matrix[stari][j]=new char[30];
        strcpy(matrix[stari][j],"-");
    }
    matrix[stari][litere]=new char[30];
    strcpy(matrix[stari][litere],matrix[i][0]);
    matrix[stari][litere+1]=new char[30];
    strcpy(matrix[stari][litere+1],"I");
    if(strcmp(matrix[stari][litere],matrix[stari][0])==0)
        strcpy(matrix[stari][litere],matrix[i][0]);

    stari++;
    matrix[stari]=new char*[litere+2];
    matrix[stari][0]=new char[30];
    strcpy(matrix[stari][0],"stop");
    matrix[stari][litere+1]=new char[30];
    strcpy(matrix[stari][litere+1],"F");
    for(i=1;i<stari;i++)
        if(strchr(matrix[i][litere+1],'F')!=0)
        {
            strcpy(matrix[i][litere+1],"-");
            strcpy(matrix[i][litere],matrix[stari][0]);
        }
    for(i=1;i<=litere;i++)
    {
        matrix[stari][i]=new char[30];
        strcpy(matrix[stari][i],"-");
    }
    matrix[stari][litere+1]=new char[30];
    strcpy(matrix[stari][litere+1],"F");
}
void automat::interschimba()
{
    if(strcmp(matrix[1][0],"start")!=0)
    {
        char*aux;
        aux=new char[30];
        for(int i=0;i<=litere+1;i++)
        {
            strcpy(aux,matrix[1][i]);
            strcpy(matrix[1][i],matrix[stari-1][i]);
            strcpy(matrix[stari-1][i],aux);
        }
    }
}
void automat::matrice_de_stari(automat &v)
{
    int i,*vec;
    vec=new int[v.stari+1];
    for(i=0;i<=v.stari;i++)
        vec[i]=0;
    vec[1]=1;
    int j=1;
    while(j!=v.stari+1)
    {
        for(i=1;i<=v.litere;i++)
            if(strcmp(v.matrix[j][i],"-")!=0)
                for(int k=1;k<=v.stari;k++)
                    if(strcmp(v.matrix[j][i],v.matrix[k][0])==0)
                    {
                        if(vec[k]==0)
                            vec[k]=1;
                    }
        vec[j]=2;
        for(j=1;j<=v.stari&&vec[j]!=1;j++);
    }
    int k=0;
    for(i=0;i<=v.stari;i++)
        if(vec[i]==2)
            k++;
    stari=k;
    litere=k-1;
    matrix=new char**[stari+1];
    for(i=0;i<=stari;i++)
        matrix[i]=new char*[litere+2];
    for(i=0;i<=stari;i++)
        for(j=0;j<=litere+1;j++)
            matrix[i][j]=new char[1000];
    for(i=0;i<=stari;i++)
        for(j=0;j<=litere+1;j++)
            strcpy(matrix[i][j],"-");
    k=0;
    for(i=1;i<=stari;i++)
    {
        while(vec[k]!=2&&k<=v.stari)
            k++;
        strcpy(matrix[i][0],v.matrix[k][0]);
        strcpy(matrix[0][i],v.matrix[k][0]);
        k++;
    }
    k=0;
    for(i=1;i<=stari;i++)
    {
        while(vec[k]!=2&&k<=v.stari)
            k++;
        for(j=1;j<=v.litere;j++)
            if(strcmp(v.matrix[k][j],"-")!=0)
            {
                int h;
                for(h=1;h<=stari;h++)
                    if(strcmp(matrix[0][h],v.matrix[k][j])==0)
                        strcpy(matrix[i][h],v.matrix[0][j]);
            }
        k++;
    }
    delete[]vec;
}
void automat::elimin_stari()
{
    for(int i=2;i<=stari;i++)
    {
        int star=0;
        if(strcmp(matrix[i][i],"-")!=0)
            star=1;
        for(int j=i+1;j<stari;j++)
        {
            if(strcmp(matrix[j][i],"-")!=0)
            {
                for(int k=i+1;k<=stari;k++)
                {
                    if(strcmp(matrix[i][k],"-")!=0)
                    {
                        if(strcmp(matrix[i][k],"^")!=0)
                        {
                            if(star==1)
                            {
                                if(strcmp(matrix[j][k],"-")==0)
                                {
                                    strcpy(matrix[j][k],matrix[j][i]);
                                    if(strlen(matrix[i][i])>1)
                                        strcat(matrix[j][k],"[");
                                    strcat(matrix[j][k],matrix[i][i]);
                                    if(strlen(matrix[i][i])>1)
                                        strcat(matrix[j][k],"]");
                                    strcat(matrix[j][k],"*");
                                    strcat(matrix[j][k],matrix[i][k]);
                                }
                                else
                                {
                                    char aux[1000];
                                    if(strcmp(matrix[j][k],"^")!=0)
                                    {
                                        strcpy(aux,"[");
                                        strcat(aux,matrix[j][k]);
                                        strcat(aux,"+");
                                    }
                                    strcat(aux,matrix[j][i]);
                                    if(strlen(matrix[i][i])>1)
                                        strcat(matrix[j][k],"[");
                                    strcat(aux,matrix[i][i]);
                                    if(strlen(matrix[i][i])>1)
                                        strcat(matrix[j][k],"]");
                                    strcat(aux,"*");
                                    strcat(aux,matrix[i][k]);
                                    if(strcmp(matrix[j][k],"^")!=0)
                                        strcat(aux,"]");
                                    strcpy(matrix[j][k],aux);
                                }
                            }
                            else
                            {
                                if(strcmp(matrix[j][k],"-")==0)
                                {
                                    strcpy(matrix[j][k],matrix[j][i]);
                                    strcat(matrix[j][k],matrix[i][k]);
                                }
                                else
                                {
                                    char aux[100];
                                    strcpy(aux,"[");
                                    strcat(aux,matrix[j][k]);
                                    strcat(aux,"+");
                                    strcat(aux,matrix[j][i]);
                                    strcat(aux,matrix[i][k]);
                                    strcat(aux,"]");
                                    strcpy(matrix[j][k],aux);
                                }
                            }
                        }
                        else
                        {
                            if(strcmp(matrix[j][k],"-")==0)
                            {
                                strcpy(matrix[j][k],matrix[j][i]);
                                if(star==1)
                                {
                                    if(strlen(matrix[i][i])>1)
                                        strcat(matrix[j][k],"[");
                                    strcat(matrix[j][k],matrix[i][i]);
                                    if(strlen(matrix[i][i])>1)
                                        strcat(matrix[j][k],"]");
                                    strcat(matrix[j][k],"*");
                                }
                            }
                            else
                                if(strcmp(matrix[j][k],"^")!=0)
                                {
                                    char aux[1000];
                                    strcpy(aux,"[");
                                    strcat(aux,matrix[j][k]);
                                    strcat(aux,"+");
                                    strcat(aux,matrix[j][i]);
                                    if(star==1)
                                    {
                                        if(strlen(matrix[i][i])>1)
                                            strcat(aux,"[");
                                        strcat(aux,matrix[i][i]);
                                        if(strlen(matrix[i][i])>1)
                                            strcat(aux,"]");
                                        strcat(aux,"*");
                                    }
                                    strcat(aux,"]");
                                    strcpy(matrix[j][k],aux);
                                }
                                else
                                {
                                    strcpy(matrix[j][k],matrix[j][i]);
                                    if(star==1)
                                    {
                                        if(strlen(matrix[i][i])>1)
                                            strcat(matrix[j][k],"[");
                                        strcat(matrix[j][k],matrix[i][i]);
                                        if(strlen(matrix[i][i])>1)
                                            strcat(matrix[j][k],"]");
                                        strcat(matrix[j][k],"*");
                                    }
                                }
                        }
                    }
                }
            }
        }
    }
}
void automat::afisare()
{
    int start;
    for(start=1;start<=stari;start++)
        if(strcmp(matrix[1][start],"-")!=0)
            break;
    if(strcmp(matrix[start][start],"-")!=0)
        cout<<matrix[start][start]<<"*"<<matrix[start][stari];
    else cout<<matrix[start][stari];
}
automat::~automat()
{
    for(int i=0;i<=stari;i++)
        {
            for(int j=0;j<=litere+1;j++)
                delete[]matrix[i][j];
            delete[]matrix[i];
        }
    delete[]matrix;
}
int main()
{
    ifstream fin("date.in");
    //citesc automatul
    automat v;
    fin>>v;
    //nfa->dfa
    v.transformare();
    //lamda(^)->dfa
    while(v.verificare_lamda()!=1)
    {
        v.lamda();
        v.transformare();
    }
    //adaug lamda final si lamda inceput
    v.adaug();
    v.interschimba();
    //am un automat finit si ii trec toate starile in care se ajunge in alta matrice
    automat w;
    w.matrice_de_stari(v);
    w.elimin_stari();
    w.afisare();
    cout<<endl<<"Final";
    fin.close();
    return 0;
}
