#include <iostream>

using namespace std;

union D {
    double ld;
    char uc[sizeof(ld)];
};

void getShortIntInfo(short int si, int vector, int size) {
    cout << "Before: " << endl;
    for (int i = 15; i >= 0; --i)
        std::cout << ((si >> i) & 1);

    vector == 0 ? (si <<= size) : (si >>= size);

    cout << endl << "After: " << endl;
    for (int i = 15; i >= 0; --i)
        std::cout << ((si >> i) & 1);
}

void getDoubleInfo(D d, int vector, int size) {
    char T[64];
    int t = 63;
    cout << "Before: " << endl;
    unsigned char c;
    for (int i = 0; i < sizeof(d); ++i) {
        c = d.uc[i];
        for (int j = 0; j < 8; ++j) {
            T[t] = (c & 1);
            t--;
            c >>= 1;
        }
    }

    for(int i = 0; i < 63; i++) {
        cout << (int) T[i];
    }

    cout  << endl << "After: " << endl;
    if(vector == 0) {
        for (int i = size; i < 63; i++) {
            cout << (int) T[i];
        }
        for (int i = 0; i < size; i++) cout << "0";
    } else {
        for (int i = 0; i < size; i++) cout << "0";
        for (int i = 0; i < 63 - size; i++) {
            cout << (int) T[i];
        }
    }
}

int main() {
    int type = -1, vector = -1, size;

    while (type != 0 && type != 1) {
        cout << "Enter type: (0 - short int, 1 - double): " << endl;
        cin >> type;
    }
    while (vector != 0 && vector != 1) {
        cout << "Enter vector: (0 - left, 1 - right): " << endl;
        cin >> vector;
    }
    cout << "Enter size: " << endl;
    cin >> size;

    if (type == 0) {
        short int si;
        cout << "Enter short int: " << endl;
        cin >> si;
        getShortIntInfo(si, vector, size);
    } else {
        D d;
        cout << "Enter double: " << endl;
        cin >> d.ld;
        getDoubleInfo(d, vector, size);
    }
    return 0;
}