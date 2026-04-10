
#include<iostream>
using namespace std;

void menukar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main() {
    int m,n;
    cout << "Masukkan nilai 1: ";
    cin >> m;
    cout << "Masukkan nilai 2: ";
    cin >> n;
    cout << "Sebelum ditukar: 1 = " << m << ", 2 = " << n << endl;
    menukar(&m, &n);
    cout << "Setelah ditukar: 1 = " << m << ", 2 = " << n << endl;
    return 0;  
}