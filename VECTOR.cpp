#include "funkcijos.cpp"

int main (){
    vector <studentas> mas;
    studentas tempas;

    cout<<"Spauskite 1 jeigu norite, kad nuskaitytu is failo arba 0 jeigu norite ranka vesti/generuoti duomenis: ";
    int sk;
    cin>>sk;
    if (sk==1)
    {
        skaitymas(tempas, mas);
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