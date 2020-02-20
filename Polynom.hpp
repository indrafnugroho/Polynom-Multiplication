//13518016
//Indra Febrio Nugroho
//19 Feb 2020

#include <vector>
#include <iostream>
#include <cstdlib>
using namespace std;

vector<int> BruteForce (vector<int> f, vector<int> g);
vector<int> SumPoly(vector<int> f, vector<int> g);
vector<int> SubstractPoly(vector<int> f, vector<int> g);
void DividePoly (vector<int> f, vector<int>* g, vector<int>* h);
vector<int> CombinePoly(vector<int> g, vector<int> h, vector<int> i);
void ShiftPoly(vector<int>* c1, vector<int>* c2, int n);
void PrintPoly(vector<int> f);
vector<int> KaratsubaAlgorithm(vector<int> f, vector<int> g, int* nSum, int* nMultiply);