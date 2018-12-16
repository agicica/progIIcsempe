/** Kártya  4 oldala: [R G B]
            3 színe: [fent lent jobbra balra]

    Beolvasás:  forgatás (0/1)
                R G B (intek)
                új kártya, db szám **/

#include <iostream>
#include <vector>
#include <fstream>
#include <list>
#include <sstream>
using namespace std;

struct Fibonacci{
    vector<unsigned long long int> fibonacci;

    Fibonacci(){
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
        matrix.push_back(k.G);
        for (int i=0; i<3; i++){

struct Statisztika_1{
    int kanyar;
    int egyenes;

    Statisztika_1(list<Kartya> keszlet, int szin){
        kanyar = 0;
        egyenes = 0;
        for (list<Kartya> :: iterator it = keszlet.begin(); it!=keszlet.end(); it++){
            vector<bool> RGB;
            if (szin == 1){
                RGB = (*it).R;
            }
            else if (szin == 2){
                RGB = (*it).G;
            }
            else if (szin == 3){
                RGB = (*it).B;
            }
                if( RGB[1] + RGB[2] == RGB[3] + RGB[4]){
                    kanyar++;
                }
                else{
                    egyenes++;
                }
        }
    }
};

struct Statisztika_0{
    int FL;
    int FJ;
    int FB;
    int LJ;
    int LB;
    int JB;

    Statisztika_0(list<Kartya> keszlet, int szin){
        FL = 0;
        FJ = 0;
        FB = 0;
        LJ = 0;
        LB = 0;
        JB = 0;
        for (list<Kartya> :: iterator it = keszlet.begin(); it!=keszlet.end(); it++){
            vector<bool> RGB;
            if (szin == 1){
                RGB = (*it).R;
            }
            else if (szin == 2){
                RGB = (*it).G;
            }
            else if (szin == 3){
                RGB = (*it).B;
            }
            if(RGB[1] + RGB[2] == RGB[3] + RGB[4]){
                if ( RGB[1] == 1){
                    if(RGB[3] == 1){
                        FJ++;
                    }
                    else{
                        FB++;
                    }
                }
                else if ( RGB[2] == 1){
                    if(RGB[3] == 1){
                        LJ++;
                    }
                    else{
                        LB++;
                    }
                }
            }
            else{
                if (RGB[1] == 1){
                    FL++;
                }
                else{
                    JB++;
                }
            }
        }
    }
};

string kartyaszam(Kartya&k)
{
        vector<int> ertekek;
        vector<vector<bool> > matrix;
        matrix.push_back(k.R);
        matrix.push_back(k.G);
        matrix.push_back(k.B);
        string nul= "csempekepek\\0216.png";
        for (int i=0; i<3; i++){
            if (matrix[i][0]==1 && matrix[i][1]==1 && matrix[i][2]==0 && matrix[i][3]==0){
                ertekek.push_back(0);
            }
            else
            if (matrix[i][0]==0 && matrix[i][1]==0 && matrix[i][2]==1 && matrix[i][3]==1){
                ertekek.push_back(1);
            }
            else

            if (matrix[i][0]==1 && matrix[i][1]==0 && matrix[i][2]==0 && matrix[i][3]==1){
                ertekek.push_back(2);
            }
            else
            if (matrix[i][0]==0 && matrix[i][1]==1 && matrix[i][2]==0 && matrix[i][3]==1){
                ertekek.push_back(3);
            }
            else
            if (matrix[i][0]==0 && matrix[i][1]==1 && matrix[i][2]==1 && matrix[i][3]==0){
                ertekek.push_back(4);
            }
            else
            if (matrix[i][0]==1 && matrix[i][1]==0 && matrix[i][2]==1 && matrix[i][3]==0){
                ertekek.push_back(5);
            }
            else return nul;
        }
            stringstream s;
            string vege;
            int kesz=ertekek[0]*36+ertekek[1]*6+ertekek[2];
            s<<kesz;
            s>>vege;
            if(kesz<10)
            {
                vege="csempekepek\\000"+vege+".png";
                return vege;
            }
            else if(kesz<100)
            {
                vege="csempekepek\\00"+vege+".png";
                return vege;
            }
            else
            {
                vege="csempekepek\\0"+vege+".png";
                return vege;
            }
}

struct Allapot{
    vector<vector<Kartya>> allapot;
    list<Kartya> mi_van_meg;
    int suly;

    void kirajzolas(){
        ofstream eredmeny("eredmeny.html");
        eredmeny << "<html>" << endl;
        eredmeny << "<body>" << endl;
        eredmeny << "<table>" << endl;
        for(unsigned int i=0;i<allapot.size();i++){
            eredmeny << "<tr>" << endl;
            for(unsigned int j=0;j<allapot[i].size();j++){
               eredmeny << "<td><img src="<<'"'<<kartyaszam(allapot[i][j])<<'"'<<"/></td>" << endl;
            }
            eredmeny << "</tr>" << endl;
        }
        eredmeny.close();
    }
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
    list<Kartya> osszeselem;
    unsigned int Rvalue;
    unsigned int Gvalue;
    unsigned int Bvalue;
    bool forgatottsag;

    Tabla(){
        ifstream bf("test\\proba.txt");
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

    bool ellenorzo_0(Statisztika_0 s){
        return (s.FJ >= 1 && s.FB >= 1 && s.LJ >= 1 && s.LB >= 1);
    }

    bool ellenorzo_1(Statisztika_1 s){
        return (s.kanyar >= 4);
    }

    void lets_play(Fibonacci f){
        if (forgatottsag){
            Statisztika_1 sr(osszeselem, 1); // 1 = R
            Statisztika_1 sg (osszeselem, 2); // 2 = G
            Statisztika_1 sb (osszeselem, 3); // 3 = B
            bool r_kereshetsz = ellenorzo_1(sr);
            bool g_kereshetsz = ellenorzo_1(sg);
            bool b_kereshetsz = ellenorzo_1(sb);
            if (r_kereshetsz || g_kereshetsz || b_kereshetsz){
                legjobb(f);
            }
            else{
                cout << "Bocs, de itt nem lesz hurok..." << endl;
                return;
            }
        }
        else{
            Statisztika_0 sr (osszeselem, 1);
            Statisztika_0 sg (osszeselem, 2);
            Statisztika_0 sb (osszeselem, 3);
            bool r_kereshetsz = ellenorzo_0(sr);
            bool g_kereshetsz = ellenorzo_0(sg);
            bool b_kereshetsz = ellenorzo_0(sb);
            if (r_kereshetsz || g_kereshetsz || b_kereshetsz){
                legjobb(f);
            }
            else{
               cout << "Bocs, de itt nem lesz hurok..." << endl;
                return;
            }
        }
    }

    void legjobb(Fibonacci f){
        list<Allapot> probak;
        Allapot alap;
        vector<vector<Kartya>> ures_tabla;
        vector<Kartya> ures_sor (osszeselem.size()/2);
        for(unsigned int i=0; i<osszeselem.size()/2; i++){
            ures_tabla.push_back(ures_sor);
        }
        alap.allapot = ures_tabla;
        alap.mi_van_meg = osszeselem;
        alap.suly = 0;
    }
};

int main()
{
    Fibonacci f;
    Tabla t;
    //t.kiirat();
    t.lets_play(f);
    return 0;
}

