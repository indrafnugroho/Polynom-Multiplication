//13518016
//Indra Febrio Nugroho
//19 Feb 2020

#include "Polynom.hpp"

int main() {
    int N;
    cout << "Input N: ";
    cin >> N;

    vector<int> f, g, hasil;

    srand(time(NULL));
    for (int i=0; i<N+1; i++) {
        f.push_back((rand() % 200) - 100);
        g.push_back((rand() % 200) - 100);
    }

    // f.push_back(69);
    // f.push_back(-48);
    // f.push_back(-64);

    // g.push_back(65);
    // g.push_back(-56);
    // g.push_back(76);

    cout << "Generated f is\n";
    PrintPoly(f);
    cout << "Generated g is\n";
    PrintPoly(g);

    int nSum = 0;
    int NMultiply = 0;
    hasil = KaratsubaAlgorithm(f,g,&nSum,&NMultiply);

    cout << "Result is\n";
    PrintPoly(hasil);
    return 0;
}