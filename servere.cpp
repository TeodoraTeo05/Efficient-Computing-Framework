#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <limits>

using namespace std;

int main() {
    // deschidem fisierul de intrare
    ifstream fin("servere.in");
    // deschidem fisierul de iesire
    ofstream fout("servere.out");

    // citim datele de intrare
    int n;
    vector<int> power;
    fin >> n;

    // citim puterile pentru fiecare server
    for (int i = 0; i < n; i++) {
        int a;
        fin >> a;
        power.push_back(a);
    }

    vector<int> limits;

    // folosim minim si maxim pentru a gasi cantitatea de
    // curent maxima si minima
    double minim = numeric_limits<int>::max();
    double maxim = numeric_limits<int>::lowest();
    int counter = 0;
    int current;
    // citim limitele de curent pentru fiecare server
    while (counter <= n) {
        fin >> current;
        limits.push_back(current);
        // daca curentul curent este mai mic decat minimul,
        // il setam pe minim
        if (current > maxim)
            maxim = current;
        // daca curentul curent este mai mare decat maximul,
        // il setam pe maxim
        if (current < minim)
            minim = current;
        counter++;
    }
    // dam o valoare foarte mica puterii pentru a o gasi pe cea mai mare
    double the_power = -10000000000;
    // facem cautare binara
    while (minim <= maxim) {
        double mid;
        // cautam valoarea din mijloc
        if (fmod(minim + maxim, 2) == 0) {
            mid = (minim + maxim) / 2.0;
        } else {
            mid = (minim + maxim - fmod(minim + maxim, 2)) / 2.0 + 0.5;
        }

        double min_power = 100000000000;
        bool obs = false;
        // cautam puterea minima
        for (int i = 0; i < n; i++) {
            double dif = power[i] - abs(mid - limits[i]);
            if (dif < min_power) {
                min_power = dif;
                obs = limits[i] < mid;
            }
        }

        if (the_power < min_power)
            the_power = min_power;
        // modificam intervalul pentru cautarea binara
        if (obs)
            maxim = mid - 0.5;
        if (!obs)
            minim = mid + 0.5;
    }

    fout << fixed << setprecision(1) << the_power;

    fin.close();
    fout.close();

    return 0;
}
