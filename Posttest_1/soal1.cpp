
#include<iostream>
using namespace std;

int A[8] = {1,1,2,3,5,8,13,21};
int FindMin(int A[], int n, int &indexMin) {
    int min = A[0];
    indexMin = 0;
    for (int i = 1; i < n; i++){
        if (A[i] < min){
            min = A[i];
            indexMin = i;
        }
    }
    return min;
}

int main() {
    int indexMin;
    int min = FindMin(A, 8, indexMin);
    cout << "Nilai minimum: " << min << endl;
    cout << "Index minimum: " << indexMin << endl;
    return 0;
}

/*
HASIL ANALISIS

pseudocode                             Tmin   Tmax
procedure FindMin                  C1   1      1
min ← A[0]                         C2   1      1
for i ← 1 to n - 1 do              C3   n      n
if A[i] < min then                 C4  n-1    n-1
min ← A[i]                         C5   0     n-1
end if                             C6  n-1    n-1 
end for                            C7   n      n
return min                         C8   1      1
end procedure                      C9   1      1

BEST CASE:
Best case terjadi saat elemen pertama memang sudah merupakan nilai terkecil di dalam array.
Akibatnya, kondisi A[i] < min selalu bernilai salah sehingga proses pembaruan nilai minimum tidak pernah dilakukan.

Tmin(n) = C1 + C2 + C3n + C4(n-1) + C5 0 + C6(n-1) + C7n + C8 + C9
        = (C1 + C2 + C8 + C9) + (C3 + C4 + C6 + C7)n - (C4)n
        = O(n)

WORST CASE:
Worst case terjadi ketika setiap elemen yang diperiksa selalu lebih kecil dari nilai minimum sebelumnya.
Dengan kata lain, setiap iterasi menghasilkan pembaruan nilai minimum.
Tmax(n) = C1 + C2 + C3n + C4(n-1) + C5(n-1) + C6(n-1) + C7n + C8 + C9
        = (C1 + C2 + C8 + C9) + (C3 + C4 + C5 + C6 + C7)n - (C4)n
        = O(n)

Best Case  : O(n)
Worst Case : O(n)
*/