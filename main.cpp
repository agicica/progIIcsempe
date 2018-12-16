/** Kártya  4 oldala: [R G B]
            3 színe: [fent lent jobbra balra]

    Beolvasás:  forgatás (0/1)
                R G B (intek)
                új kártya, db szám


                Ez egy unikornis!!!!! **/

#include <iostream>
#include <vector>
#include <fstream>
#include <list>
#include <sstream>
using namespace std;

struct Statisztika_1{
    int kanyar;
    int egyenes;

    Statisztika_1(){
        kanyar = 0;
        egyenes = 0;
    }
};

struct Statisztika_0{
    int FL;
    int FJ;
    int FB;
    int LJ;
    int LB;
    int JB;

    Statisztika_0(){
        FL = 0;
        FJ = 0;
        FB = 0;
        LJ = 0;
        LB = 0;
        JB = 0;
    }
};

struct Kartya{

    vector<bool> fennt;
    vector<bool> lennt;
    vector<bool> jobbra;
    vector<bool> balra;
    vector<bool> R;
    vector<bool> G;
    vector<bool> B;

};

ostream& operator<<(ostream &out, const Kartya &k){
    out<< k.fennt[0]<<" "<< k.fennt[1]<< " "<<k.fennt[2]<< ",";
    out<< k.lennt[0]<<" "<< k.lennt[1]<< " "<<k.lennt[2]<< ",";
    out<< k.jobbra[0]<<" "<< k.jobbra[1]<< " "<<k.jobbra[2]<< ",";
    out<< k.balra[0]<<" "<< k.balra[1]<< " "<<k.balra[2]<< ";      ";
    out<< k.R[0]<<" "<<k.R[1]<< " "<<k.R[2]<<" "<<k.R[3]<<",";
    out<< k.G[0]<<" "<<k.G[1]<< " "<<k.G[2]<<" "<<k.G[3]<<",";
    out<< k.B[0]<<" "<<k.B[1]<< " "<<k.B[2]<<" "<<k.B[3]<<endl;
    return out;
}

struct Tabla{
    list<Kartya>osszeselem;
    vector<unsigned long long int> fibonacci;
    unsigned int Rvalue;
    unsigned int Gvalue;
    unsigned int Bvalue;
    bool forgatottsag;

    Tabla(){
        unsigned long long int a, b, c;
        a=0;
        b=1;
        c=1;
        for (int i = 0; i<94; i++){
            fibonacci.push_back(c);
            c=a+b;
            a=b;
            b=c;
        }
        ifstream bf("proba.txt");
        if(bf.fail())
        {
            cerr<<"hiba"<<endl;
        }
        else{
            bf >> forgatottsag;
            bf >> Rvalue;
            bf >> Gvalue;
            bf >> Bvalue;
            string sor;
            while(getline(bf,sor,';'))
            {
                Kartya k;
                int bfhany;
                bf>>bfhany;
                k=darabolo(sor);
                for(int i=0;i<bfhany;i++)
                {
                     osszeselem.push_back(k);
                }
            }
        }
    }

    Kartya darabolo(string sor){
        Kartya k;
        string x;
        stringstream sss(sor);
        getline(sss,x,',');
        stringstream ss;
        ss<<x;
        for(int i=0;i<3;i++)
        {
            bool b;
            ss>>b;
            k.fennt.push_back(b);
        }
        ss.clear();
        k.R.push_back(k.fennt[0]);
        k.G.push_back(k.fennt[1]);
        k.B.push_back(k.fennt[2]);
        getline(sss,x,',');
        ss<<x;
        for(int i=0;i<3;i++)
        {
            bool z;
            ss>>z;
            k.lennt.push_back(z);
        }
        ss.clear();
        k.R.push_back(k.lennt[0]);
        k.G.push_back(k.lennt[1]);
        k.B.push_back(k.lennt[2]);
        getline(sss,x,',');
        ss<<x;
        for(int i=0;i<3;i++)
        {
            bool b;
            ss>>b;
            k.jobbra.push_back(b);
        }
        ss.clear();
        k.R.push_back(k.jobbra[0]);
        k.G.push_back(k.jobbra[1]);
        k.B.push_back(k.jobbra[2]);
        getline(sss,x,',');
        ss<<x;
        for(int i=0;i<3;i++)
        {
            bool b;
            ss>>b;
            k.balra.push_back(b);
        }
        ss.clear();
        k.R.push_back(k.balra[0]);
        k.G.push_back(k.balra[1]);
        k.B.push_back(k.balra[2]);
        return k;
    }

void kiirat(){
    for(list<Kartya> :: iterator it =osszeselem.begin();it!=osszeselem.end();it++)
    {
       cout<< *it;
    }
}

Statisztika_0 datas_0(int szin){
        Statisztika_0 s;
        for (list<Kartya> :: iterator it = osszeselem.begin(); it!=osszeselem.end(); it++){
            if (szin == 1){
                if( (*it).R[1] + (*it).R[2] == (*it).R[3] + (*it).R[4]){
                    if ( (*it).R[1] == 1){
                        if((*it).R[3] == 1){
                            s.FJ++;
                        }
                        else{
                            s.FB++;
                        }
                    }
                    else if ( (*it).R[2] == 1){
                        if((*it).R[3] == 1){
                            s.LJ++;
                        }
                        else{
                            s.LB++;
                        }
                    }
                }
                else{
                    if ( (*it).R[1] == 1){
                        s.FL++;
                    }
                    else{
                        s.JB++;
                    }
                }
            }
            else if (szin == 2){
                if( (*it).G[1] + (*it).G[2] == (*it).G[3] + (*it).G[4]){
                    if ( (*it).G[1] == 1){
                        if((*it).G[3] == 1){
                            s.FJ++;
                        }
                        else{
                            s.FB++;
                        }
                    }
                    else if ( (*it).G[2] == 1){
                        if((*it).G[3] == 1){
                            s.LJ++;
                        }
                        else{
                            s.LB++;
                        }
                    }
                }
                else{
                    if ( (*it).G[1] == 1){
                        s.FL++;
                    }
                    else{
                        s.JB++;
                    }
                }
            }
            else if (szin == 3){
                if( (*it).B[1] + (*it).B[2] == (*it).B[3] + (*it).B[4]){
                    if ( (*it).B[1] == 1){
                        if((*it).B[3] == 1){
                            s.FJ++;
                        }
                        else{
                            s.FB++;
                        }
                    }
                    else if ( (*it).B[2] == 1){
                        if((*it).B[3] == 1){
                            s.LJ++;
                        }
                        else{
                            s.LB++;
                        }
                    }
                }
                else{
                    if ( (*it).B[1] == 1){
                        s.FL++;
                    }
                    else{
                        s.JB++;
                    }
                }
            }
        }
        return s;
    }

    Statisztika_1 datas_1(int szin){
        Statisztika_1 s;
        for (list<Kartya> :: iterator it = osszeselem.begin(); it!=osszeselem.end(); it++){
            if (szin == 1){
                if( (*it).R[1] + (*it).R[2] == (*it).R[3] + (*it).R[4]){
                    s.kanyar++;
                }
                else{
                    s.egyenes++;
                }
            }
            else if (szin == 2){
                if( (*it).G[1] + (*it).G[2] == (*it).G[3] + (*it).G[4]){
                    s.kanyar++;
                }
                else{
                    s.egyenes++;
                }
            }
            else if (szin == 3){
                if( (*it).B[1] + (*it).B[2] == (*it).B[3] + (*it).B[4]){
                    s.kanyar++;
                }
                else{
                    s.egyenes++;
                }
            }
        }
        return s;
    }

    bool ellenorzo_0(Statisztika_0 s){
        return (s.FJ >= 1 && s.FB >= 1 && s.LJ >= 1 && s.LB >= 1);
    }

    bool ellenorzo_1(Statisztika_1 s){
        return (s.kanyar >= 4);
    }

    void lets_play(){
        if (forgatottsag){
            Statisztika_1 sr = datas_1(1); // 1 = R
            Statisztika_1 sg = datas_1(2); // 2 = G
            Statisztika_1 sb = datas_1(3); // 3 = B
            bool r_kereshetsz = ellenorzo_1(sr);
            bool g_kereshetsz = ellenorzo_1(sg);
            bool b_kereshetsz = ellenorzo_1(sb);
            if (r_kereshetsz || g_kereshetsz || b_kereshetsz){

            }
            else{
                cout << "Bocs, de itt nem lesz hurok..." << endl;
                return;
            }
        }
        else{
            Statisztika_0 sr = datas_0(1);
            Statisztika_0 sg = datas_0(2);
            Statisztika_0 sb = datas_0(3);
            bool r_kereshetsz = ellenorzo_0(sr);
            bool g_kereshetsz = ellenorzo_0(sg);
            bool b_kereshetsz = ellenorzo_0(sb);
            if (r_kereshetsz || g_kereshetsz || b_kereshetsz){

            }
            else{
                cout << "Bocs, de itt nem lesz hurok..." << endl;
                return;
            }
        }
    }
};

int main()
{
    Tabla t;
    t.kiirat();
    t.lets_play();
    cout << "Hello world!" << endl;
    return 0;
}

