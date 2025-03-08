#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
    // deschiderea fisierului de intrare
    ifstream fin("oferta.in");
    // deschiderea fisierului de iesire
    ofstream fout("oferta.out");

    // citirea datelor de intrare
    int n, k;
    fin >> n >> k;
    // formam un vector de preturi
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        fin >> v[i];
    }

    // formam un vector de preturi minime
    vector<double> oferte(n + 1, 0);
    oferte[0] = 0;

    for (int i = 1; i <= n; ++i) {
        // calculam pretul de baza
        oferte[i] = oferte[i-1] + v[i-1];
        // aplicam reducerea pe 2 produse, daca avem cel putin 2 produse
        if (i > 1) {
            oferte[i] = min(oferte[i], oferte[i-2] + v[i-2] + v[i-1] -
            min(v[i-2], v[i-1]) / 2.0);
        }
        // aplicam reducerea pe 3 produse, daca avem cel putin 3 produse
        if (i > 2) {
            // gasim cel mai mic pret dintre cele 3 produse
            double minim = min({v[i-3], v[i-2], v[i-1]});
            // calculam pretul cu reducerea aplicata
            oferte[i] = min(oferte[i], oferte[i-3] + v[i-3] + v[i-2]
            + v[i-1] - minim);
        }
    }

    fout << fixed << setprecision(1) << oferte[n] << endl;

    fin.close();
    fout.close();

    return 0;
}
