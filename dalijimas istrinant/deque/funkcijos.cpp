#include "Vec.h"

void pild (studentas &temp){
    cout<<"Iveskite varda ir pavarde: "; cin>>temp.vardas>>temp.pavarde;
    int x, a;
    cout<<"Iveskite 1, jeigu norite kad pazymiai butu generuojami atsitiktinai, jeigu nenorite paspauskite bet kuri klavisa: "; cin>>a;
    if (a != 1){
        cout<<"Iveskite paz.";
        while (cin>>x) {
            if (x<0 || x>10) {
                cout<<"Ivedete bloga skaiciu, iveskite is naujo ";
            } else temp.paz.push_back(x);
        }
        cin.clear();
        cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        cout<<"Iveskite egzamino paz."; cin>>temp.egz;
        while (temp.egz<0 || temp.egz>10) {
            if (temp.egz<0 || temp.egz>10) {
                cout<<"Ivedete bloga skaiciu, iveskite is naujo ";
                cin>>temp.egz;
         }
        }
    } else {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> dist (0, 10);

        int n;
        cout<<"Kiek pazymiu sugeneruoti? "; cin>>n;
        for (int i=0 ; i<n ; i++) temp.paz.push_back(dist(mt));
        temp.egz=dist((mt));
    }
}

void skaitymas (studentas &temp, deque <studentas> &mas, double &skaitym, string failodydis) {
    deque <string> splited;
    string eil, df=failodydis;

    skaitym=0;

    std::ifstream open_f(df);
    auto start = std::chrono::high_resolution_clock::now(); auto st=start;
    //----------------------------------------------------------------------
    while (open_f){ 
    if (!open_f.eof()) {
        std::getline(open_f, eil);
        splited.push_back(eil);}
    else break;
    }
    open_f.close();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;

    failodydis.erase(std::remove(failodydis.begin(), failodydis.end(), '.'), failodydis.end());
    failodydis.erase(std::remove(failodydis.begin(), failodydis.end(), 't'), failodydis.end());
    failodydis.erase(std::remove(failodydis.begin(), failodydis.end(), 'x'), failodydis.end());


    std::cout << failodydis << " elementu failo nuskaitymas uztruko: "<< fixed << setprecision(2)<< diff.count() << " s\n";

    skaitym=diff.count();

    stringstream ss(splited[0]);
    string word;
    int count = 0;
    while (ss >> word)
        count++;
    int pazymys;
    for (int i=1;i<splited.size();i++){
        stringstream ss(splited[i]);
        ss >> temp.vardas >> temp.pavarde;
        for (int i=0;i<count-3;i++){
            ss >> pazymys;
            temp.paz.push_back(pazymys);
        }
        ss >> temp.egz;
        mas.push_back(temp);
        temp.paz.clear();
        } 

}

double mediana (studentas& temp) {
    double mediana;
    int size = temp.paz.size();
    int vid=size/2;
    sort(temp.paz.begin(), temp.paz.end());
    mediana = size % 2 == 0 ? double((temp.paz[vid-1]+temp.paz[vid]))/2: temp.paz[vid];
    return mediana;
}

double vidurkis(studentas& temp, int a) {
  double v=0;
  if (temp.paz.size() > 0) {
    if (a == 1) {
      v = std::accumulate(temp.paz.begin(), temp.paz.end(), v) * 1.0 / temp.paz.size();
    }
    else v = mediana(temp);
  }
  
  return v*0.4 + 0.6*temp.egz;
}

bool palyginimasv (studentas &a, studentas &b) {
    return a.vardas < b.vardas;
}

bool palyginimasp (studentas &a, studentas &b) {
    return a.pavarde < b.pavarde;
}

bool palyginimas (studentas &a, studentas &b) {
    return a.bendr > b.bendr;
}

void isvedimas(deque <studentas> &temp) {
    string galutinis;
    int x, y;
    cout<<"Jeigu norite matyti vidurki spauskite 1, jeigu norite matyti mediana spauskite 0: "; cin>>x;
    galutinis = x == 1 ? galutinis="(Vid.)" : galutinis="(Med.)";

    cout<<"Jeigu norite kad rusiuotu pagal varda spauskite 1 jeigu pagal pavarde 0: "; cin>>y;
    if (y == 1) {
        sort(temp.begin(), temp.end(), palyginimasv);
    } else sort(temp.begin(), temp.end(), palyginimasp);

    cout<<"Jeigu norite isvesti duomenis i konsole spauskite 1 jeigu i faila spauskite 0: "; cin>>y;

    if (y == 1) {
        cout<<setw(10)<<left<<"Vardas"<<setw(15)<<left<<"Pavarde"<<"Galutinis "<<galutinis<<endl;
        cout << setfill('-') << setw(50) << '-' << setfill(' ') << endl;
        cout << setfill('-') << setw(50) << '-' << setfill(' ') << endl;
        cout << left << setw(14) << "Vardas" << left << setw(18) << "Pavarde" << left << setw(16) << "Galutinis "<<galutinis<<endl;
        cout << setfill('-') << setw(50) << '-' << setfill(' ') << endl;
        for(int i = 0; i < temp.size(); i ++) {
            cout << setw(15) << temp[i].vardas << setw(15) << temp[i].pavarde << setw(19) << fixed << setprecision(2) << vidurkis(temp[i], x) << endl;
        }
    }

    else {
        string pavadinimas;
        cout<<"Iveskite rezultatu failo pavadinima: ";cin>>pavadinimas;
        std::ofstream out(pavadinimas);

        auto start = std::chrono::high_resolution_clock::now();

        out<<setw(10)<<left<<"Vardas"<<setw(15)<<left<<"Pavarde"<<"Galutinis "<<galutinis<<endl;
        out << setfill('-') << setw(50) << '-' << setfill(' ') << endl;
        for(int i = 0; i < temp.size(); i ++) {
            out << setw(15) << temp[i].vardas << setw(15) << temp[i].pavarde << setw(19) << fixed << setprecision(2) << vidurkis(temp[i], x) << endl;
            }
        out.close();

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;
        std::cout << "Failo isvedimas truko:  "<< diff.count() << " s\n";
    }
}

void generavimas (string filename, int studKiek, int kiek) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist (0, 10);

    std::ofstream rf (filename);

    rf << setw(25) << left << "Vardas" << setw(25) << left << "Pavarde";
    for (int i=0 ; i<kiek ; i++){
        rf << setw(5) << left << "ND"+to_string(i+1);
    }

    rf << "Egz." << endl;

    char eil[1000];
    string laikeilute;

    for (int i=0; i<studKiek ; i++) {
        //rf << setw(25) << left << "Vardas"+to_string(i+1) << setw(25) << left << "Pavarde"+to_string(i+1);
        sprintf (eil, "%-s%-19d%-s%-18d", "Vardas", i+1, "Pavarde", i+1);
        laikeilute=eil;
        for (int j=0 ; j<kiek+1 ; j++) {
            //rf << setw(5) << left << dist(mt);
            laikeilute+="   "+to_string(dist(mt));
        }
        rf << laikeilute << endl;
        laikeilute.clear();
    }
}

void rusiavimas (deque <studentas> &temp, deque <studentas> &vargsas, string failodydis, double &rusiavim) {

    rusiavim=0;

    failodydis.erase(std::remove(failodydis.begin(), failodydis.end(), '.'), failodydis.end());
    failodydis.erase(std::remove(failodydis.begin(), failodydis.end(), 't'), failodydis.end());
    failodydis.erase(std::remove(failodydis.begin(), failodydis.end(), 'x'), failodydis.end());

    for (int i=0; i <temp.size() ; i++) {
        temp[i].bendr=vidurkis(temp[i], 1);
    }

    auto start = std::chrono::high_resolution_clock::now();

    sort(temp.begin(), temp.end(), palyginimas);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << failodydis << " elementu failo rusiavimas uztruko: "<< fixed << setprecision(2)<< diff.count() << " s\n";

    rusiavim=diff.count();

    start = std::chrono::high_resolution_clock::now();

    for (int i=temp.size()-1; i>=0; i--) {
        if (temp.at(i).bendr <= 5) {
            vargsas.push_back(temp.at(i));
            temp.pop_back();
        }
    }
    vargsas.shrink_to_fit();

    end = std::chrono::high_resolution_clock::now();
    diff = end - start;
    std::cout << failodydis << " elementu failo priskirimas prie vargsu ir istrinimas is kietu: "<< fixed << setprecision(2) << diff.count() << " s\n";

    rusiavim+=diff.count();

}

void isvedimas2 (deque <studentas> &temp, string failodydis, string tipas, double &isved) {
    
    std::ofstream out(tipas);

    isved=0;

    auto start = std::chrono::high_resolution_clock::now();

    char eil[100];
    string laikeilute;

    out<<setw(15)<<left<<"Vardas"<<setw(15)<<left<<"Pavarde"<<"Galutinis (Vid.)" <<endl;
    out << setfill('-') << setw(50) << '-' << setfill(' ') << endl;
    for(int i = 0; i < temp.size(); i ++) {
        sprintf(eil, "%-15s%-15s", temp[i].vardas.c_str(), temp[i].pavarde.c_str());
        laikeilute=eil;
        laikeilute+="   "+to_string(temp[i].bendr);
        out << laikeilute << endl;
        //out << setw(15) << temp[i].vardas << setw(15) << temp[i].pavarde << setw(19) << fixed << setprecision(2) << temp[i].bendr << endl;
        }
    out.close();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;

    failodydis.erase(std::remove(failodydis.begin(), failodydis.end(), '.'), failodydis.end());
    failodydis.erase(std::remove(failodydis.begin(), failodydis.end(), 't'), failodydis.end());
    failodydis.erase(std::remove(failodydis.begin(), failodydis.end(), 'x'), failodydis.end());

    std::cout << failodydis << " failu elemento " << tipas << " isvedimas uztruko: " << fixed << setprecision(2)<< diff.count() << " s\n";

    isved=diff.count();
}