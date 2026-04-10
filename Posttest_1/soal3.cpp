
#include<iostream>
using namespace std;

void reverseArray(int* arr, int n)
{
    int* start = arr;
    int* end = arr + n - 1;
    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}
int main (){
    int Bprima[7] = {2,3,5,7,11,13,17};
    int *p = Bprima;
    cout << "Array sebelum dibalik: "<<endl;
    for(int i=0;i<7;i++){
        cout << "Nilai: "<< *p << ", Alamat: " << p << endl;
        p++;    
    }
    reverseArray(Bprima, 7);
    p = Bprima; // untuk reset 
    cout << "Array setelah dibalik: "<<endl;
    for(int i=0;i<7;i++){
        cout << "Nilai: "<< *p << ", Alamat: " << p << endl;
        p++;
    }
}