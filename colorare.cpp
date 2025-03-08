#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


const int MOD = 1e9 + 7;

// functie care calculeaza puterea unui numar intr-un timp logaritmic
long long logaritmic_pow(long long base, int exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}



int main() {
    // deschidem fisierul de intrare
    ifstream fin("colorare.in");
    // deschidem fisierul de iesire
    ofstream fout("colorare.out");

    // citim datele de intrare
    int K, x;
    char t, prev;
    fin >> K;
    long long int result;

    for (int i = 0; i < K; ++i) {
        fin >> x >> t;
        if (i == 0) {
                // daca este primul element, se seteaza valoarea
                // lui result si prev
                if (t == 'H') {
                    result = 6;
                    prev = 'H';
                } else {
                    result = 3;
                    prev = 'V';
                }
                // se scade x pentru a nu se mai lua in
                // considerare primul element in for
                x--;
            }

        for (int j = 0; j <= x; ++j) {
            if (t == 'H') {
                // daca elementul curent este H si
                // precedentul este V, se adauga 2 orizontale
                if (prev == 'V') {
                    result = (2 * result) % MOD;
                    prev = 'H';
                    x--;

                } else {
                    // daca elementul curent este H si precedentul
                    // este H, se adauga 3 orizontale la fiecare pas
                    result = (result * logaritmic_pow(3, x, MOD)) % MOD;
                    prev = 'H';
                    break;
                }
            }

            if (t == 'V') {
                // daca elementul curent este V si precedentul este H,
                // se adauga doar o verticala, deci raman variantele precedente
                if (prev == 'H') {
                    prev = 'V';
                    x--;

                } else {
                    // daca elementul curent este V si precedentul este
                    // V, se adauga 2 verticale la fiecare pas
                    result = (result * logaritmic_pow(2, x, MOD)) % MOD;
                    prev = 'V';
                    break;
                }
            }
        }
    }

    fout << result << endl;

    // inchiderea fisierelor
    fin.close();
    fout.close();

    return 0;
}
