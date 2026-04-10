#include<iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float ipk;

};
int main() {
    Mahasiswa mahasiswa[5];
    float ipkTertinggi = mahasiswa[0].ipk;
    int indexMahasiswaTertinggi = 0;
    for (int i = 0;i<5;i++){
        cout << "Masukkan nama mahasiswa ke-" << i+1 << ": ";
        cin.ignore();
        getline(cin,mahasiswa[i].nama);
        cout << "Masukkan NIM mahasiswa ke-" << i+1 << ": ";
        cin >> mahasiswa[i].nim;
        cout << "Masukkan IPK mahasiswa ke-" << i+1 << ": ";
        cin >> mahasiswa[i].ipk;
    }
    for (int i=0;i<5;i++){
        if (mahasiswa[i].ipk > ipkTertinggi){
            ipkTertinggi = mahasiswa[i].ipk;
            indexMahasiswaTertinggi = i;
        }
    }
    cout << "Mahasiswa dengan IPK tertinggi:" << endl;
    cout << "Nama: " << mahasiswa[indexMahasiswaTertinggi].nama << endl;
    cout << "NIM: " << mahasiswa[indexMahasiswaTertinggi].nim << endl;
    cout << "IPK: " << mahasiswa[indexMahasiswaTertinggi].ipk << endl;

}