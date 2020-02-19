//13518016
//Indra Febrio Nugroho
//19 Feb 2020

#include "Polynom.hpp"

vector<int> BruteForce (vector<int> f, vector<int> g) {
    vector<int> hasil;
    hasil.resize(f.size() + g.size() - 1);
    for (int i=0; i<hasil.size(); i++) {
        hasil[i] = 0;
    }
    for (int i=0; i<f.size(); i++) {
        for (int j=0; j<g.size(); j++) {
            hasil[i+j] += f[i] * g[j];
        }
    }
    return hasil;
}

vector<int> SumPoly(vector<int> f, vector<int> g) {
    vector<int> hasil;
    if (f.size() <= g.size()) {
        for (int i=0; i<g.size(); i++) {
            hasil.push_back(0);
            if (i >= f.size()) {
                hasil[i] = g[i];
            } else {
                hasil[i] = f[i] + g[i];
            }
        }
    } else {
        for (int i=0; i<f.size(); i++) {
            hasil.push_back(0);
            if (i >= g.size()) {
                hasil[i] = f[i];
            } else {
                hasil[i] = f[i] + g[i];
            }
        }
    } return hasil;
}

vector<int> SubstractPoly(vector<int> f, vector<int> g) {
    vector<int> hasil;
    if (f.size() <= g.size()) {
        for (int i=0; i<g.size(); i++) {
            hasil.push_back(0);
            if (i >= f.size()) {
                hasil[i] = 0 - g[i];
            } else {
                hasil[i] = f[i] - g[i];
            }
        }
    } else {
        for (int i=0; i<f.size(); i++) {
            hasil.push_back(0);
            if (i >= g.size()) {
                hasil[i] = 0 - f[i];
            } else {
                hasil[i] = f[i] - g[i];
            }
        }
    } return hasil;
}

void DividePoly (vector<int> f, vector<int> g, vector<int> h) {
    g.resize((int) (f.size()+1) / 2);
    h.resize((int) (f.size()+1) / 2);
    for (int i=0; i<g.size(); i++) {
        g[i] = 0;
        h[i] = 0;
    }

    for (int i=0; i<f.size(); i++) {
        if (i < (int) (f.size()+1) / 2) {
            g[i] = f[i];
        }
        else {
            h[i - (int) (f.size()+1) / 2] = f[i];
        }
    }
}

void CombinePoly(vector<int> g, vector<int> h, vector<int> f) {
    f.resize(g.size() + h.size() - 1);
    for (int i=0; i<g.size(); i++) {
        f[i] = g[i];
    }
    for (int i=g.size(); i<g.size()+h.size()-1; i++) {
        f[i] = h[i - g.size()];
    }
}

vector<int> KaratsubaAlgorithm(vector<int> f, vector<int> g) {
    //Make size of f and size of g same
    while (f.size() < g.size()) {
        f.push_back(0);
    } 
    while (g.size() < f.size()) {
        g.push_back(0);
    }
    int n = f.size();

    //Basis
    if (n<=3) {
        vector<int> hasil = BruteForce(f, g);
        return hasil;
    }
    else {
        //Divide
        vector<int> f0;
        vector<int> f1;
        vector<int> g0;
        vector<int> g1;

        DividePoly(f, f0, f1);
        DividePoly(g, g0, g1);

        //Count c0, c1, c2
        vector<int> c0 = KaratsubaAlgorithm(f0, g0);
        vector<int> c1;
        vector<int> c2 = KaratsubaAlgorithm(f1, g1);
    
        vector<int> temp0 = SumPoly(f0,f1);
        vector<int> temp1 = SumPoly(g0,g1);
        vector<int> temp2 = KaratsubaAlgorithm (temp0, temp1);
    
        c1 = SubstractPoly(temp2, SumPoly(c2,c0));

        //Merge c0, c1, c2
        vector<int> shiftedC1;
        vector<int> shiftedC2;

        int m1 = ((int) (n+1) / 2) + c1.size();
        int m2 = 2* ((int) (n+1) / 2) + c2.size();
        
        for (int i=0; i<m1; i++) {
            shiftedC1.push_back(0);
            if (i >= (int) (n+1) / 2) {
                shiftedC1[i] = c1[i - ((int) (n+1) / 2)];
            }
        }
        for (int i=0; i<m2; i++) {
            shiftedC2.push_back(0);
            if (i >= 2 * ((int) (n+1) / 2)) {
                shiftedC2[i] = c2[i - 2 * ((int) (n+1) / 2)];
            }
        }

        return SumPoly(c0, SumPoly(shiftedC1, shiftedC2));
    }
}