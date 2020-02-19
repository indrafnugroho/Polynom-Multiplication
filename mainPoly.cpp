//13518016
//Indra Febrio Nugroho
//19 Feb 2020

#include "Polynom.hpp"

int main() {
    vector<int> f, g, hasil;

    f.push_back(1);
    f.push_back(2);
    f.push_back(3);

    g.push_back(4);
    g.push_back(5);
    g.push_back(6);

    hasil = KaratsubaAlgorithm(f,g);

    for (int i=0; i<hasil.size(); i++) {
        cout << i << ". " << hasil[i] << endl;
    }
    return 0;
}