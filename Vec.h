#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <limits>
#include <numeric>
#include <random>
#include <fstream>
#include <sstream>
#include <chrono>

using std::cout;
using std::cin;
using std::endl;
using std::left;
using std::right;
using std::setw;
using std::setprecision;
using std::fixed;
using std::string;
using std::vector;
using std::numeric_limits;
using std::stringstream;
using std::setfill;
using std::stoi;

struct studentas{
    string vardas, pavarde;
    vector <int> paz;
    int egz;
};

void pild (studentas &temp);
void skaitymas (studentas &temp, vector <studentas> &mas);
double mediana (studentas& temp);
double vidurkis(studentas& temp, int a);
bool palyginimasv (studentas &a, studentas &b);
bool palyginimasp (studentas &a, studentas &b);
void isvedimas(vector<studentas> &temp);
