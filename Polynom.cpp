//13518016
//Indra Febrio Nugroho
//19 Feb 2020

#include "Polynom.hpp"

vector<int> BruteForce (vector<int> f, vector<int> g, int* nSum, int* nMultiply) {
    vector<int> hasil;
    for (int i=0; i < (f.size() + g.size() - 1); i++) {
        hasil.push_back(0);
    }
    for (int i=0; i<f.size(); i++) {
        for (int j=0; j<g.size(); j++) {
            hasil[i+j] += f[i] * g[j];
            (*nSum)++;
            (*nMultiply)++;
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

void DividePoly (vector<int> f, vector<int>* g, vector<int>* h) {
    for (int i=0; i<f.size(); i++) {
        if (i < (int) (f.size()+1) / 2) {
            g->push_back(f[i]);
        }
        else {
            h->push_back(f[i]);
        }
    }
}

vector<int> CombinePoly(vector<int> g, vector<int> h, vector<int> i) {
    return SumPoly(g, SumPoly(h, i));
}

void ShiftPoly(vector<int>* c1, vector<int>* c2, int n) {
    int s1 = c1->size();
    int s2 = c2->size();

    int m1 = ((int) (n+1) / 2);
    int m2 = 2* ((int) (n+1) / 2);
    
    //Move array c1 element to the right m1 times
    c1->resize(s1+m1);
    for (int i = s1 + m1 - 1; i >= 0; i--) {
        if (i >= m1) {
            (*c1)[i] = (*c1)[i - m1];
        } else {
            (*c1)[i] = 0;
        }
    }
    //Move array c2 element to the right m2 times
    c2->resize(s2+m2);
    for (int i = s2 + m2 - 1; i >= 0; i--) {
        if (i >= m2) {
            (*c2)[i] = (*c2)[i - m2];
        } else {
            (*c2)[i] = 0;
        }
    }
}

void PrintPoly(vector<int> f) {
    for (int i=0; i < f.size(); i++) {
        if (i==0) {
            cout << f[i];
        }
        else {
            if (f[i] > 0) {
                cout << " + " << f[i] << "x^" << i;
            } else if (f[i] < 0) {
                cout << " - " << f[i]*(-1) << "x^" << i;
            } else {
                continue;
            }
        }
    }
    cout << endl;
}

vector<int> DivideAndConquer(vector<int> f, vector<int> g, int* nSum, int* nMultiply) {
    int n = f.size();

    //Basis
    if (n == 1) {
        vector<int> result;
        result.push_back(f[0] * g[0]);
        (*nMultiply)++;
        return result;
    }
    else {
        //Divide
        vector<int> f0,f1;
        vector<int> g0,g1;

        DividePoly(f, &f0, &f1);
        DividePoly(g, &g0, &g1);

        //Count c0, c1, c2
        vector<int> c0 = DivideAndConquer(f0, g0, nSum, nMultiply);
        vector<int> c1;
        vector<int> c2 = DivideAndConquer(f1, g1, nSum, nMultiply);
    
        vector<int> temp0 = SumPoly(f0,f1);
        vector<int> temp1 = SumPoly(g0,g1);
        vector<int> temp2 = DivideAndConquer (temp0, temp1, nSum, nMultiply);
        (*nSum) += 2;
    
        c1 = SubstractPoly(temp2, SumPoly(c2,c0));

        //Merge c0, c1, c2
        ShiftPoly(&c1,&c2,n);
        // PrintPoly(CombinePoly(c1,c2));
        // PrintPoly(SumPoly(c1,c2));
        return CombinePoly(c0,c1,c2);
    }
}