//13518016
//Indra Febrio Nugroho
//19 Feb 2020

#include "Polynom.hpp"

int main() {
    int N;
    cout << "Input N: ";
    cin >> N;
    cout << endl;

    vector<int> f, g, resultBF, resultDNC;

    srand(time(NULL));
    for (int i=0; i<N+1; i++) {
        //randomize coefficient between (-100) and 100
        f.push_back((rand() % 200) - 100);
        g.push_back((rand() % 200) - 100);
    }

    cout << "1st Generated Polynom is\n";
    PrintPoly(f);
    cout << "2nd Generated Polynom is\n";
    PrintPoly(g);
    cout << endl;

    //Brute Force
    int nSum = 0;
    int NMultiply = 0;

    //Time execution by brute force
    auto startBF = high_resolution_clock::now();
    resultBF = BruteForce(f,g,&nSum,&NMultiply);
    auto endBF = high_resolution_clock::now();
    auto durationBF = duration_cast<microseconds> (endBF - startBF);

    cout << "Result of Polynom Multiplication by Brute Force is\n";
    PrintPoly(resultBF);
    cout << "Total Sum Operation: " << nSum << endl;
    cout << "Total Multiplication Operation: " << NMultiply << endl;
    cout << "Executed Time: " << durationBF.count() << " ms" << endl << endl;

    //Divide and Conquer
    nSum = 0;
    NMultiply = 0;

    //Time execution by divide and conquer
    auto startDNC = high_resolution_clock::now();
    resultDNC = DivideAndConquer(f,g,&nSum,&NMultiply);
    auto endDNC = high_resolution_clock::now();
    auto durationDNC = duration_cast<microseconds> (endDNC - startDNC);

    cout << "Result of Polynom Multiplication by Divide and Conquer is\n";
    PrintPoly(resultDNC);
    cout << "Total Sum Operation: " << nSum << endl;
    cout << "Total Multiplication Operation: " << NMultiply << endl;
    cout << "Executed Time: " << durationDNC.count() << " ms" << endl << endl;

    cout << "Program is executed in a computer with spesification below\n" ;
    cout << "Processor: AMD E-300 APU with Radeon HD Graphics 1.30 GHz\n";
    cout << "RAM: 2GB\n";
    cout << "Operating system: Ubuntu 19.10\n";
    return 0;
}