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
#include <map>
using namespace std;

struct Fibonacci
{
    vector<unsigned long long int> fibonacci;

    Fibonacci()
    {
        unsigned long long int a, b, c;
        a=0;
        b=1;
        c=1;
        for (int i = 0; i<94; i++)
        {
            fibonacci.push_back(c);
            c=a+b;
            a=b;
            b=c;
        }
    }
};

struct Pozicio
{
    int x;
    int y;

    Pozicio(int x_, int y_)
    {
        x = x_;
        y = y_;
    }
};

struct Kartya
{
    vector<bool> fennt;
    vector<bool> lennt;
    vector<bool> jobbra;
    vector<bool> balra;
    vector<bool> R;
    vector<bool> G;
    vector<bool> B;

    bool operator<(const Kartya& k) const
    {
        if(fennt[0]+fennt[1]+fennt[2] < k.fennt[0]+k.fennt[1]+k.fennt[2])
            return fennt[0]+fennt[1]+fennt[2] < k.fennt[0]+k.fennt[1]+k.fennt[2];
        else if (lennt[0]+lennt[1]+lennt[2] < k.lennt[0]+k.lennt[1]+k.lennt[2])
            return lennt[0]+lennt[1]+lennt[2] < k.lennt[0]+k.lennt[1]+k.lennt[2];
        else if(jobbra[0]+jobbra[1]+jobbra[2] < k.jobbra[0]+k.jobbra[1]+k.jobbra[2])
            return jobbra[0]+jobbra[1]+jobbra[2] < k.jobbra[0]+k.jobbra[1]+k.jobbra[2];
        else
            return balra[0]+balra[1]+balra[2] < k.balra[0]+k.balra[1]+k.balra[2];
    }

    Kartya forgatas(const Kartya& k)
    {
        Kartya f;
        f.fennt = k.jobbra;
        f.balra = k.fennt;
        f.lennt = k.balra;
        f.jobbra = k.lennt;
        f.R.push_back(f.fennt[0]);
        f.G.push_back(f.fennt[1]);
        f.B.push_back(f.fennt[2]);
        f.R.push_back(f.lennt[0]);
        f.G.push_back(f.lennt[1]);
        f.B.push_back(f.lennt[2]);
        f.R.push_back(f.jobbra[0]);
        f.G.push_back(f.jobbra[1]);
        f.B.push_back(f.jobbra[2]);
        f.R.push_back(f.balra[0]);
        f.G.push_back(f.balra[1]);
        f.B.push_back(f.balra[2]);
        return f;
    }
};

struct Statisztika_1
{
    int kanyar;
    int egyenes;

    Statisztika_1(map<Kartya, int> keszlet, int szin)
    {
        kanyar = 0;
        egyenes = 0;
        for (map<Kartya, int> :: iterator it = keszlet.begin(); it!=keszlet.end(); it++)
        {
            vector<bool> RGB;
            if (szin == 1)
            {
                RGB = (it -> first).R;
            }
            else if (szin == 2)
            {
                RGB = (it -> first).G;
            }
            else if (szin == 3)
            {
                RGB = (it -> first).B;
            }
            if( RGB[0] + RGB[1] == RGB[2] + RGB[3])
            {
                kanyar+= it->second;
            }
            else
            {
                egyenes+= it->second;
            }
        }
    }
};

struct Statisztika_0
{
    int FL;
    int FJ;
    int FB;
    int LJ;
    int LB;
    int JB;

    Statisztika_0(map<Kartya, int> keszlet, int szin)
    {
        FL = 0;
        FJ = 0;
        FB = 0;
        LJ = 0;
        LB = 0;
        JB = 0;
        for (map<Kartya, int> :: iterator it = keszlet.begin(); it!=keszlet.end(); it++)
        {
            vector<bool> RGB;
            if (szin == 1)
            {
                RGB = (it -> first).R;
            }
            else if (szin == 2)
            {
                RGB = (it -> first).G;
            }
            else if (szin == 3)
            {
                RGB = (it -> first).B;
            }
            if(RGB[0] + RGB[1] == RGB[2] + RGB[3])
            {
                if ( RGB[0] == 1)
                {
                    if(RGB[2] == 1)
                    {
                        FJ++;
                    }
                    else
                    {
                        FB++;
                    }
                }
                else if ( RGB[1] == 1)
                {
                    if(RGB[2] == 1)
                    {
                        LJ++;
                    }
                    else
                    {
                        LB++;
                    }
                }
            }
            else
            {
                if (RGB[0] == 1)
                {
                    FL++;
                }
                else
                {
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
    for (int i=0; i<3; i++)
    {
        if (matrix[i][0]==1 && matrix[i][1]==1 && matrix[i][2]==0 && matrix[i][3]==0)
        {
            ertekek.push_back(0);
        }
        else if (matrix[i][0]==0 && matrix[i][1]==0 && matrix[i][2]==1 && matrix[i][3]==1)
        {
            ertekek.push_back(1);
        }
        else

            if (matrix[i][0]==1 && matrix[i][1]==0 && matrix[i][2]==0 && matrix[i][3]==1)
            {
                ertekek.push_back(2);
            }
            else if (matrix[i][0]==0 && matrix[i][1]==1 && matrix[i][2]==0 && matrix[i][3]==1)
            {
                ertekek.push_back(3);
            }
            else if (matrix[i][0]==0 && matrix[i][1]==1 && matrix[i][2]==1 && matrix[i][3]==0)
            {
                ertekek.push_back(4);
            }
            else if (matrix[i][0]==1 && matrix[i][1]==0 && matrix[i][2]==1 && matrix[i][3]==0)
            {
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

struct Allapot
{
    vector<vector<Kartya>> allapot;
    list<Pozicio> ahol_van_csempe;
    map<Kartya, int> mi_van_meg;
    int suly;

    Allapot() {}

    Allapot(const Allapot& a)
    {
        allapot = a.allapot;
        mi_van_meg = a.mi_van_meg;
        suly = a.suly;
    }

    void kirajzolas()
    {
        ofstream eredmeny("eredmeny.html");
        eredmeny << "<html>" << endl;
        eredmeny << "<body>" << endl;
        eredmeny << "<table>" << endl;
        for(unsigned int i=0; i<allapot.size(); i++)
        {
            eredmeny << "<tr>" << endl;
            for(unsigned int j=0; j<allapot[i].size(); j++)
            {
                eredmeny << "<td><img src="<<'"'<<kartyaszam(allapot[i][j])<<'"'<<"/></td>" << endl;
            }
            eredmeny << "</tr>" << endl;
        }
        eredmeny.close();
    }
};

ostream& operator<<(ostream &out, const Kartya &k)
{
    out<< k.fennt[0]<<" "<< k.fennt[1]<< " "<<k.fennt[2]<< ",";
    out<< k.lennt[0]<<" "<< k.lennt[1]<< " "<<k.lennt[2]<< ",";
    out<< k.jobbra[0]<<" "<< k.jobbra[1]<< " "<<k.jobbra[2]<< ",";
    out<< k.balra[0]<<" "<< k.balra[1]<< " "<<k.balra[2]<< ";      ";
    out<< k.R[0]<<" "<<k.R[1]<< " "<<k.R[2]<<" "<<k.R[3]<<",";
    out<< k.G[0]<<" "<<k.G[1]<< " "<<k.G[2]<<" "<<k.G[3]<<",";
    out<< k.B[0]<<" "<<k.B[1]<< " "<<k.B[2]<<" "<<k.B[3]<<endl;
    return out;
}

struct Tabla
{
    map<Kartya, int> osszeselem;
    unsigned int Rvalue;
    unsigned int Gvalue;
    unsigned int Bvalue;
    bool forgatottsag;

    Tabla()
    {
        ifstream bf("test\\proba.txt");
        if(bf.fail())
        {
            cerr<<"hiba"<<endl;
        }
        else
        {
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
                osszeselem[k] = bfhany;
            }
        }
    }

    Kartya darabolo(string sor)
    {
        Kartya k;
        string x;
        stringstream sss(sor);
        getline(sss,x,',');
        stringstream ss;
        ss<<x;
        for(int i=0; i<3; i++)
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
        for(int i=0; i<3; i++)
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
        for(int i=0; i<3; i++)
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
        for(int i=0; i<3; i++)
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

    void kiirat()
    {
        for(map<Kartya, int> :: iterator it =osszeselem.begin(); it!=osszeselem.end(); it++)
        {
            cout<< it -> first;
        }
    }

        bool ellenorzo_0(Statisztika_0 s)
        {
            return (s.FJ >= 1 && s.FB >= 1 && s.LJ >= 1 && s.LB >= 1);
        }

        bool ellenorzo_1(Statisztika_1 s)
        {
            return (s.kanyar >= 4);
        }

        void lets_play(Fibonacci f)
        {
            if (forgatottsag)
            {
                Statisztika_1 sr(osszeselem, 1); // 1 = R
                Statisztika_1 sg (osszeselem, 2); // 2 = G
                Statisztika_1 sb (osszeselem, 3); // 3 = B
                bool r_kereshetsz = ellenorzo_1(sr);
                bool g_kereshetsz = ellenorzo_1(sg);
                bool b_kereshetsz = ellenorzo_1(sb);
                if (r_kereshetsz || g_kereshetsz || b_kereshetsz)
                {
                    legjobb(f);
                }
                else
                {
                    cout << "Bocs, de itt nem lesz hurok..." << endl;
                    return;
                }
            }
            else
            {
                Statisztika_0 sr (osszeselem, 1);
                Statisztika_0 sg (osszeselem, 2);
                Statisztika_0 sb (osszeselem, 3);
                bool r_kereshetsz = ellenorzo_0(sr);
                bool g_kereshetsz = ellenorzo_0(sg);
                bool b_kereshetsz = ellenorzo_0(sb);
                if (r_kereshetsz || g_kereshetsz || b_kereshetsz)
                {
                    legjobb(f);
                }
                else
                {
                    cout << "Bocs, de itt nem lesz hurok..." << endl;
                    return;
                }
            }
        }

        void legjobb(Fibonacci f)
        {
            int keszlet = 0;
            for(map<Kartya, int> ::iterator it = osszeselem.begin(); it!=osszeselem.end(); it++)
            {
                keszlet += it -> second;
            }
            list<Allapot> probak;
            Allapot alap;
            vector<vector<Kartya>> ures_tabla;
            vector<Kartya> ures_sor (keszlet*2);
            for(int i=0; i<keszlet*2; i++)
            {
                ures_tabla.push_back(ures_sor);
            }
            alap.allapot = ures_tabla;
            alap.mi_van_meg = osszeselem;
            alap.suly = 0;
            for(map<Kartya, int> ::iterator it = alap.mi_van_meg.begin(); it!=alap.mi_van_meg.end(); it++)
            {
                if (it -> second > 0)
                {
                    Allapot uj(alap);
                    uj.ahol_van_csempe.push_back(Pozicio (keszlet, keszlet));
                    uj.allapot[keszlet][keszlet] = it -> first;
                    uj.mi_van_meg[it -> first]--;
                    probak.push_back(uj);
                }
            }
            list<Allapot> mego;

            bool nincs_meg = true;
            while (nincs_meg || !probak.empty())
            {
                Allapot most = *probak.begin();
                probak.pop_front();

                for(list<Pozicio> :: iterator it = most.ahol_van_csempe.begin(); it!=most.ahol_van_csempe.end(); it++)
                {
                    if(most.allapot[(*it).y-1][(*it).x].fennt.empty())
                    {
                        for(map<Kartya, int> ::iterator it_m = alap.mi_van_meg.begin(); it_m!=alap.mi_van_meg.end(); it_m++)
                        {
                            if (it_m -> second > 0)
                            {
                                if (forgatottsag)
                                {
                                    Kartya f = it_m -> first;
                                    if(most.allapot[(*it).y][(*it).x].fennt == (f).lennt)
                                    {
                                        Allapot uj(most);
                                        uj.ahol_van_csempe.push_back(Pozicio ((*it).x, (*it).y-1));
                                        uj.allapot[(*it).y-1][(*it).x] = f;
                                        uj.mi_van_meg[it_m -> first]--;
                                        probak.push_back(uj);
                                    }
                                    for(int i=0; i<3; i++)
                                    {
                                        f = f.forgatas(f);
                                        if(most.allapot[(*it).y][(*it).x].fennt == (f).lennt)
                                        {
                                            Allapot uj(most);
                                            uj.ahol_van_csempe.push_back(Pozicio ((*it).x, (*it).y-1));
                                            uj.allapot[(*it).y-1][(*it).x] = f;
                                            uj.mi_van_meg[it_m -> first]--;
                                            probak.push_back(uj);
                                        }
                                    }
                                }
                                else
                                {
                                    if(most.allapot[(*it).y][(*it).x].fennt == (it_m -> first).lennt)
                                    {
                                        Allapot uj(most);
                                        uj.ahol_van_csempe.push_back(Pozicio ((*it).x, (*it).y-1));
                                        uj.allapot[(*it).y-1][(*it).x] = it_m -> first;
                                        uj.mi_van_meg[it_m -> first]--;
                                        probak.push_back(uj);
                                    }
                                }
                            }
                        }
                    }
                    if(most.allapot[(*it).y+1][(*it).x].fennt.empty())
                    {
                        for(map<Kartya, int> ::iterator it_m = alap.mi_van_meg.begin(); it_m!=alap.mi_van_meg.end(); it_m++)
                        {
                            if (it_m -> second > 0)
                            {
                                if (forgatottsag)
                                {
                                    Kartya f = it_m -> first;
                                    if(most.allapot[(*it).y][(*it).x].lennt == (f).fennt)
                                    {
                                        Allapot uj(most);
                                        uj.ahol_van_csempe.push_back(Pozicio ((*it).x, (*it).y+1));
                                        uj.allapot[(*it).y+1][(*it).x] = f;
                                        uj.mi_van_meg[it_m -> first]--;
                                        probak.push_back(uj);
                                    }
                                    for(int i=0; i<3; i++)
                                    {
                                        f = f.forgatas(f);
                                        if(most.allapot[(*it).y][(*it).x].lennt == (f).fennt)
                                        {
                                            Allapot uj(most);
                                            uj.ahol_van_csempe.push_back(Pozicio ((*it).x, (*it).y+1));
                                            uj.allapot[(*it).y+1][(*it).x] = f;
                                            uj.mi_van_meg[it_m -> first]--;
                                            probak.push_back(uj);
                                        }
                                    }
                                }
                                else
                                {
                                    if(most.allapot[(*it).y][(*it).x].lennt == (it_m -> first).fennt)
                                    {
                                        Allapot uj(most);
                                        uj.ahol_van_csempe.push_back(Pozicio ((*it).x, (*it).y+1));
                                        uj.allapot[(*it).y+1][(*it).x] = it_m -> first;
                                        uj.mi_van_meg[it_m -> first]--;
                                        probak.push_back(uj);
                                    }
                                }
                            }
                        }
                    }
                    if(most.allapot[(*it).y][(*it).x-1].fennt.empty())
                    {
                        for(map<Kartya, int> ::iterator it_m = alap.mi_van_meg.begin(); it_m!=alap.mi_van_meg.end(); it_m++)
                        {
                            if (it_m -> second > 0)
                            {
                                if (forgatottsag)
                                {
                                    Kartya f = it_m -> first;
                                    if(most.allapot[(*it).y][(*it).x].balra == (f).jobbra)
                                    {
                                        Allapot uj(most);
                                        uj.ahol_van_csempe.push_back(Pozicio ((*it).x-1, (*it).y));
                                        uj.allapot[(*it).y][(*it).x-1] = f;
                                        uj.mi_van_meg[it_m -> first]--;
                                        probak.push_back(uj);
                                    }
                                    for(int i=0; i<3; i++)
                                    {
                                        f = f.forgatas(f);
                                        if(most.allapot[(*it).y][(*it).x].balra == (f).jobbra)
                                        {
                                            Allapot uj(most);
                                            uj.ahol_van_csempe.push_back(Pozicio ((*it).x-1, (*it).y));
                                            uj.allapot[(*it).y][(*it).x-1] = f;
                                            uj.mi_van_meg[it_m -> first]--;
                                            probak.push_back(uj);
                                        }
                                    }
                                }
                                else
                                {
                                    if(most.allapot[(*it).y][(*it).x].balra == (it_m -> first).jobbra)
                                    {
                                        Allapot uj(most);
                                        uj.ahol_van_csempe.push_back(Pozicio ((*it).x-1, (*it).y));
                                        uj.allapot[(*it).y][(*it).x-1] = it_m -> first;
                                        uj.mi_van_meg[it_m -> first]--;
                                        probak.push_back(uj);
                                    }
                                }
                            }
                        }
                    }
                    if(most.allapot[(*it).y][(*it).x+1].fennt.empty())
                    {
                        for(map<Kartya, int> ::iterator it_m = alap.mi_van_meg.begin(); it_m!=alap.mi_van_meg.end(); it_m++)
                        {
                            if (it_m -> second > 0)
                            {
                                if (forgatottsag)
                                {
                                    Kartya f = it_m -> first;
                                    if(most.allapot[(*it).y][(*it).x].jobbra == (f).balra)
                                    {
                                        Allapot uj(most);
                                        uj.ahol_van_csempe.push_back(Pozicio ((*it).x+1, (*it).y));
                                        uj.allapot[(*it).y][(*it).x+1] = f;
                                        uj.mi_van_meg[it_m -> first]--;
                                        probak.push_back(uj);
                                    }
                                    for(int i=0; i<3; i++)
                                    {
                                        f = f.forgatas(f);
                                        if(most.allapot[(*it).y][(*it).x].jobbra == (f).balra)
                                        {
                                            Allapot uj(most);
                                            uj.ahol_van_csempe.push_back(Pozicio ((*it).x+1, (*it).y));
                                            uj.allapot[(*it).y][(*it).x+1] = f;
                                            uj.mi_van_meg[it_m -> first]--;
                                            probak.push_back(uj);
                                        }
                                    }
                                }
                                else
                                {
                                    if(most.allapot[(*it).y][(*it).x].jobbra == (it_m -> first).balra)
                                    {
                                        Allapot uj(most);
                                        uj.ahol_van_csempe.push_back(Pozicio ((*it).x+1, (*it).y));
                                        uj.allapot[(*it).y][(*it).x+1] = it_m -> first;
                                        uj.mi_van_meg[it_m -> first]--;
                                        probak.push_back(uj);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    };

    int main()
    {
        Fibonacci f;
        Tabla t;
        //t.kiirat();
        t.lets_play(f);
        cout << "Hello world!" << endl;
        return 0;
    }

