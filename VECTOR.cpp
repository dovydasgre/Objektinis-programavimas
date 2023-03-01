#include "Vec.h"

struct studentas{
    string vardas, pavarde;
    vector <int> paz;
    int egz;
};

std::chrono::duration<double> diff;

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

void skaitymas (studentas &temp, string df, vector <studentas> &mas) {
    vector<string> splited;
    string eil;
    auto start = std::chrono::high_resolution_clock::now(); auto st=start;
  //----------------------------------------------------------------------
    std::ifstream open_f(df);
    while (open_f){ 
      if (!open_f.eof()) {
          std::getline(open_f, eil);
          splited.push_back(eil);}
      else break;
    }
    open_f.close();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> dif = end - start;
    std::cout << "Failo nuskaitymas uztruko: "<< diff.count() << " s\n";

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

bool palyginimas (studentas &a, studentas &b) {
    return a.vardas < b.vardas;
}

void isvedimas(vector<studentas> &temp) {
    string galutinis;
    int x, y;
    cout<<"Jeigu norite matyti vidurki spauskite 1, jeigu norite matyti mediana spauskite 0: "; cin>>x;
    galutinis = x == 1 ? galutinis="(Vid.)" : galutinis="(Med.)";
    cout<<"Jeigu norite isvesti duomenis i konsole spauskite 1 jeigu i faila spauskite 0: "; cin>>y;

    sort(temp.begin(), temp.end(), palyginimas);

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

int main (){
    vector <studentas> mas;
    studentas tempas;
    string failas;

    cout<<"Spauskite 1 jeigu norite, kad nuskaitytu is failo arba 0 jeigu norite ranka vesti/generuoti duomenis: ";
    int sk;
    cin>>sk;
    if (sk==1)
    {
        cout<<"Iveskite failo pavadinima: "; cin>>failas;
        skaitymas(tempas, failas, mas);
    } else {
        char uzkl='n';
        do {
            pild(tempas);
            mas.push_back(tempas);
            tempas.paz.clear();
            cout<<"Baigti darba spausk n, testi - bet koks klavisas: ";
            cin>>uzkl;
        } while (uzkl != 'n' && uzkl!= 'N');
    }  
    isvedimas (mas);
    for (auto &i : mas) i.paz.clear();
    mas.clear();  
}