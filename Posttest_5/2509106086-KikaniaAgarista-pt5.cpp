#include <iostream>
#include <string>
using namespace std;


struct BukuNode {
    string judulBuku;
    BukuNode* next;


    BukuNode(string judul) {
        judulBuku = judul;
        next = nullptr;
    }
};

BukuNode* tambahBuku(BukuNode* head, string judul) {
    BukuNode* newNode = new BukuNode(judul);
    if (head == nullptr) {
        newNode->next = newNode;
        return newNode;
    }
    
    BukuNode* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    return head;
}

bool cariBuku(BukuNode* head, string judulDicari) {
    
    // 1. Jika list kosong, kembalikan false
    if (head == nullptr) {
        return false;
    }
    
    // 2. Mulai penelusuran dari head menggunakan pointer temp
    BukuNode* temp = head;
    
    // 3. & 4. Loop dengan do-while untuk circular list
    do {
        // Cek apakah judul buku cocok dengan yang dicari
        if (temp->judulBuku == judulDicari) {
            return true;  // Buku ditemukan, langsung return true
        }
        // Lanjutkan ke node berikutnya
        temp = temp->next;
    } while (temp != head);  // Berhenti jika temp kembali mencapai head
    
    // 5. Jika seluruh list sudah ditelusuri dan tidak ditemukan
    return false;
    
}

int main() {
    BukuNode* head = nullptr;
    
    head = tambahBuku(head, "Struktur Data dengan C++");
    head = tambahBuku(head, "Pengantar Algoritma");
    head = tambahBuku(head, "Pemrograman Berorientasi Objek");
    head = tambahBuku(head, "Sistem Basis Data");

    string buku1 = "Pengantar Algoritma";
    string buku2 = "Kalkulus Lanjut";

    cout << "Mencari buku '" << buku1 << "': " 
         << (cariBuku(head, buku1) ? "Ditemukan" : "Tidak Ditemukan") << endl; 

    cout << "Mencari buku '" << buku2 << "': " 
         << (cariBuku(head, buku2) ? "Ditemukan" : "Tidak Ditemukan") << endl; 

    return 0;
}