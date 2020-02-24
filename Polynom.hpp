//13518016
//Indra Febrio Nugroho
//19 Feb 2020

//A C++ library to multiply 2 polynomials
//using Brute Force & Divide and Conquer algorithms

#include <vector> //used for dynamic array
#include <iostream> //used for input output
#include <cstdlib> //used for randomizer
#include <chrono> //used for counting execution time
using namespace std::chrono;
using namespace std;

//Brute force algorithm
vector<int> BruteForce (vector<int> p1, vector<int> p2, int* nSum, int* nMultiply);

//Sum 2 polynomials
vector<int> SumPoly(vector<int> p1, vector<int> p2);

//Substract 2 polynomials
vector<int> SubstractPoly(vector<int> p1, vector<int> p2);

//Divide a polynomial into 2 separated polynomials
void DividePoly (vector<int> basePoly, vector<int>* p1, vector<int>* p2);

//Merge 2 polynomials into a polynomial
vector<int> MergePoly(vector<int> p1, vector<int> p2, vector<int> p3);

//Shift 2 polynomials c1 and c2
//by (n+1)/2 times and 2*(n+1)/2 times
void ShiftPoly(vector<int>* c1, vector<int>* c2, int n);

//Print a polynomial in a basic form
void PrintPoly(vector<int> p);

//Divide and conquer algorithm
vector<int> DivideAndConquer(vector<int> f, vector<int> g, int* nSum, int* nMultiply);