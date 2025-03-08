#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int findLongestTransformedSequence(vector<int>& A, vector<int>& B) {
    int n = A.size(), m = B.size();
    int i = 0, j = 0;

    int result = 0;

     while (i < n && j < m) {
        // daca elementele sunt egale trecem mai departe
        if (A[i] == B[j]) {
            result++;
            i++;
            j++;
            // daca elementele sunt diferite, facem suma
            // dintre elementul mai mic si urmatorul din secventa
            // din care face parte
        } else if (A[i] > B[j]) {
            B[j + 1] = B[j] + B[j+1];
            j++;
        } else if (A[i] < B[j]) {
            A[i + 1] = A[i] + A[i+1];
            i++;
        }
    }

    if (result == 1) {
        return -1;
    }

    return result;
}

int main() {
    // deschidem fisierele de intrare si iesire
    ifstream fin("compresie.in");
    ofstream fout("compresie.out");

    // citim datele de intrare
    int n, m;
    fin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        fin >> A[i];
    }

    fin >> m;
    vector<int> B(m);
    for (int j = 0; j < m; j++) {
        fin >> B[j];
    }

    // apelam functia care calculeaza lungimea secventei transformate
    int result = findLongestTransformedSequence(A, B);
    fout << result << endl;

    fin.close();
    fout.close();
    return 0;
}
