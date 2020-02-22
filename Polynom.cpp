//13518016
//Indra Febrio Nugroho
//19 Feb 2020

#include "Polynom.hpp"

vector<int> BruteForce (vector<int> p1, vector<int> p2, int* nSum, int* nMultiply) {
    //Make an array with p1+p2-1 size
    vector<int> hasil;
    for (int i=0; i < (p1.size() + p2.size() - 1); i++) {
        hasil.push_back(0);
    }

    //Do brute force algorithm by multiplying each coefficient
    for (int i=0; i<p1.size(); i++) {
        for (int j=0; j<p2.size(); j++) {
            hasil[i+j] += p1[i] * p2[j];
            (*nSum)++;
            (*nMultiply)++;
        }
    }
    return hasil;
}

vector<int> SumPoly(vector<int> p1, vector<int> p2) {
    vector<int> hasil;
    //first condition
    if (p1.size() <= p2.size()) {
        for (int i=0; i<p2.size(); i++) {
            hasil.push_back(0);
            if (i >= p1.size()) {
                hasil[i] = p2[i];
            } else {
                hasil[i] = p1[i] + p2[i];
            }
        }
    } //second condition
    else {
        for (int i=0; i<p1.size(); i++) {
            hasil.push_back(0);
            if (i >= p2.size()) {
                hasil[i] = p1[i];
            } else {
                hasil[i] = p1[i] + p2[i];
            }
        }
    } return hasil;
}

vector<int> SubstractPoly(vector<int> p1, vector<int> p2) {
    vector<int> hasil;
    //first condition
    if (p1.size() <= p2.size()) {
        for (int i=0; i<p2.size(); i++) {
            hasil.push_back(0);
            if (i >= p1.size()) {
                hasil[i] = 0 - p2[i];
            } else {
                hasil[i] = p1[i] - p2[i];
            }
        }
    } //second condition
    else {
        for (int i=0; i<p1.size(); i++) {
            hasil.push_back(0);
            if (i >= p2.size()) {
                hasil[i] = 0 - p1[i];
            } else {
                hasil[i] = p1[i] - p2[i];
            }
        }
    } return hasil;
}

void DividePoly (vector<int> basePoly, vector<int>* p1, vector<int>* p2) {
    for (int i=0; i<basePoly.size(); i++) {
        //first divide half of basePoly into p1
        if (i < (int) (basePoly.size()+1) / 2) {
            p1->push_back(basePoly[i]);
        } //then divide another half of basePoly into p2 
        else {
            p2->push_back(basePoly[i]);
        }
    }
}

vector<int> MergePoly(vector<int> p1, vector<int> p2, vector<int> p3) {
    return SumPoly(p1, SumPoly(p2, p3));
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
            if (f[i] == 0) continue;
            else cout << f[i];
        } else {
            if (f[i] > 0) {
                cout << " + " << f[i];
                if (i!=1) cout << "x^" << i;
                else cout << "x";
            } else if (f[i] < 0) {
                cout << " - " << f[i]*(-1);
                if (i!=1) cout << "x^" << i;
                else cout << "x";
            } else {
                continue;
            }
        }
    }
    cout << endl;
}

vector<int> DivideAndConquer(vector<int> f, vector<int> g, int* nSum, int* nMultiply) {
    int n = f.size();

    //Base
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
        return MergePoly(c0,c1,c2);
    }
}