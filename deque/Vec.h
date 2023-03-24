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
#include <stdio.h>

#include <deque>
using std::deque;

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
using std::to_string;

struct studentas{
    string vardas, pavarde;
    deque <int> paz;
    int egz;
    double bendr;
};

void pild (studentas &temp);
void skaitymas (studentas &temp, deque <studentas> &mas, double &skaitym, string failodydis);
double mediana (studentas& temp);
double vidurkis(studentas& temp, int a);
bool palyginimasv (studentas &a, studentas &b);
bool palyginimasp (studentas &a, studentas &b);
void isvedimas(deque<studentas> &temp);
void rusiavimas (deque <studentas> &temp, deque <studentas> &vargsas, deque <studentas> &kietas, string failodydis, double &rusiavim); 
void isvedimas2 (deque <studentas> &temp, string failodydis, string tipas, double &isved);
