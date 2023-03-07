#include "funkcijos.cpp"

int main (){
    vector <studentas> mas;
    studentas tempas;
    vector <studentas> vargsas;
    vector <studentas> kietas;

    string failodydis="1000.txt";

    double skaitym, rusiavim, isved, bendras;

    skaitymas (tempas, mas, skaitym, failodydis);
    rusiavimas(mas, vargsas, kietas, failodydis, rusiavim);
    isvedimas2(vargsas, failodydis, "vargsai.txt", isved);
    bendras=skaitym+rusiavim+isved;
    isvedimas2(kietas, failodydis, "kietas.txt", isved);
    bendras+=isved;
    cout << failodydis << " Elementu failo visas laikas: " << bendras << endl;
    cout << setfill('-') << setw(50) << '-' << setfill(' ') << endl;

    for (auto &i : mas) i.paz.clear();
    mas.clear();
    for (auto &i : vargsas) i.paz.clear();
    vargsas.clear();
    for (auto &i : kietas) i.paz.clear();
    kietas.clear();

    remove("vargsai.txt");  
    remove("kietas.txt"); 

    failodydis="10000.txt";

    skaitymas (tempas, mas, skaitym, failodydis);
    rusiavimas(mas, vargsas, kietas, failodydis, rusiavim);
    isvedimas2(vargsas, failodydis, "vargsai.txt", isved);
    bendras=skaitym+rusiavim+isved;
    isvedimas2(kietas, failodydis, "kietas.txt", isved);
    bendras+=isved;
    cout << failodydis << " Elementu failo visas laikas: " << bendras << endl;
    cout << setfill('-') << setw(50) << '-' << setfill(' ') << endl;

    for (auto &i : mas) i.paz.clear();
    mas.clear();
    for (auto &i : vargsas) i.paz.clear();
    vargsas.clear();
    for (auto &i : kietas) i.paz.clear();
    kietas.clear();  

    remove("vargsai.txt");  
    remove("kietas.txt");  

    failodydis="100000.txt";

    skaitymas (tempas, mas, skaitym, failodydis);
    rusiavimas(mas, vargsas, kietas, failodydis, rusiavim);
    isvedimas2(vargsas, failodydis, "vargsai.txt", isved);
    bendras=skaitym+rusiavim+isved;
    isvedimas2(kietas, failodydis, "kietas.txt", isved);
    bendras+=isved;
    cout << failodydis << " Elementu failo visas laikas: " << bendras << endl;
    cout << setfill('-') << setw(50) << '-' << setfill(' ') << endl;

    for (auto &i : mas) i.paz.clear();
    mas.clear();
    for (auto &i : vargsas) i.paz.clear();
    vargsas.clear();
    for (auto &i : kietas) i.paz.clear();
    kietas.clear();

    remove("vargsai.txt");  
    remove("kietas.txt");

    failodydis="1000000.txt";

    skaitymas (tempas, mas, skaitym, failodydis);
    rusiavimas(mas, vargsas, kietas, failodydis, rusiavim);
    isvedimas2(vargsas, failodydis, "vargsai.txt", isved);
    bendras=skaitym+rusiavim+isved;
    isvedimas2(kietas, failodydis, "kietas.txt", isved);
    bendras+=isved;
    cout << failodydis << " Elementu failo visas laikas: " << bendras << endl;
    cout << setfill('-') << setw(50) << '-' << setfill(' ') << endl;

    for (auto &i : mas) i.paz.clear();
    mas.clear();
    for (auto &i : vargsas) i.paz.clear();
    vargsas.clear();
    for (auto &i : kietas) i.paz.clear();
    kietas.clear();

    remove("vargsai.txt");  
    remove("kietas.txt"); 

    failodydis="10000000.txt";

    skaitymas (tempas, mas, skaitym, failodydis);
    rusiavimas(mas, vargsas, kietas, failodydis, rusiavim);
    isvedimas2(vargsas, failodydis, "vargsai", isved);
    bendras=skaitym+rusiavim+isved;
    isvedimas2(kietas, failodydis, "kietas", isved);
    bendras+=isved;
    cout << failodydis << " Elementu failo visas laikas: " << bendras << endl;
    cout << setfill('-') << setw(50) << '-' << setfill(' ') << endl;

    for (auto &i : mas) i.paz.clear();
    mas.clear();
    for (auto &i : vargsas) i.paz.clear();
    vargsas.clear();
    for (auto &i : kietas) i.paz.clear();
    kietas.clear();

    remove("vargsai.txt");  
    remove("kietas.txt");


    //generavimas("1000.txt", 1000, 15);

    // cout<<"Spauskite 1 jeigu norite, kad nuskaitytu is failo arba 0 jeigu norite ranka vesti/generuoti duomenis: ";
    // int sk;
    // cin>>sk;
    // if (sk==1)
    // {
    //     skaitymas(tempas, mas);
    // } else {
    //     char uzkl='n';
    //     do {
    //         pild(tempas);
    //         mas.push_back(tempas);
    //         tempas.paz.clear();
    //         cout<<"Baigti darba spausk n, testi - bet koks klavisas: ";
    //         cin>>uzkl;
    //     } while (uzkl != 'n' && uzkl!= 'N');
    // }  
    // isvedimas (mas);
    for (auto &i : mas) i.paz.clear();
    mas.clear();  
}