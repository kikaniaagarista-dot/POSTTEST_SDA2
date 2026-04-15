#include <iostream>
#include <string>

using namespace std;

// Nama : Kikania Agarista
// NIM  : 2509106086
// Kelas: B2 ' 25

struct Kereta {
    int nomor;
    string nama;
    string asal;
    string tujuan;
    int harga;
};

struct Transaksi {
    string namaPenumpang;
    Kereta kereta;
    int jumlahTiket;
    int totalHarga;
};

struct NodeQueue {
    Transaksi data;
    NodeQueue* next;  
};

struct NodeStack {
    Transaksi data;
    NodeStack* next;  
};


NodeQueue* front = nullptr;
NodeQueue* rear = nullptr;

NodeStack* top = nullptr;


string tambahSpasiKanan(string teks, int lebar) {
    while (teks.length() < lebar) {
        teks = teks + " ";
    }
    return teks;
}

string tambahSpasiKiri(string teks, int lebar) {
    while (teks.length() < lebar) {
        teks = " " + teks;
    }
    return teks;
}

void tukarData(Kereta* a, Kereta* b) {
    Kereta temp = *a; 
    *a = *b;          
    *b = temp;        
}


bool isEmptyQueue() {
    return front == nullptr;
}

void enqueue(Transaksi* data) {
    NodeQueue* newNode = new NodeQueue;
    newNode->data = *data;
    newNode->next = nullptr;
    
    if (isEmptyQueue()) {
        front = rear = newNode;
    } else {

        rear->next = newNode;
        rear = newNode;
    }
    cout << data->namaPenumpang << " berhasil masuk antrian!" << endl;
}

Transaksi* dequeue() {
    // ⚠️ Handle underflow
    if (isEmptyQueue()) {
        cout << "Queue underflow - Antrian kosong!" << endl;
        return nullptr;
    }
    
    Transaksi* value = new Transaksi(front->data);
    
    NodeQueue* temp = front;
    
    front = front->next;
    
    if (front == nullptr) {
        rear = nullptr;
    }
    
    delete temp;
    
    return value;
}

Transaksi* peekQueue() {
    if (isEmptyQueue()) {
        cout << "Queue is empty" << endl;
        return nullptr;
    }
    return &(front->data);  
}

void displayQueue() {
    if (isEmptyQueue()) {
        cout << "Antrian kosong." << endl;
        return;
    }
    
    cout << "\n-- ANTRIAN PEMBELIAN TIKET (Front -> Rear) --" << endl;
    cout << "No\tNama Penumpang\t\tKereta\t\tRute\t\t\tTiket\tTotal" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    
    NodeQueue* temp = front;
    int no = 1;
    while (temp != nullptr) {
        cout << no << "\t";
        cout << temp->data.namaPenumpang << "\t\t";
        cout << temp->data.kereta.nama << "\t\t";
        cout << temp->data.kereta.asal << " -> " << temp->data.kereta.tujuan << "\t";
        cout << temp->data.jumlahTiket << "\t";
        cout << "Rp " << temp->data.totalHarga << endl;
        temp = temp->next;  
        no++;
    }
    cout << "--------------------------------------------------------------------------------" << endl;
}

bool isEmptyStack() {
    return top == nullptr;
}

void push(Transaksi* data) {

    NodeStack* newNode = new NodeStack;
    newNode->data = *data;
    
    newNode->next = top;

    top = newNode;
    
    cout << "Transaksi " << data->namaPenumpang << " dicatat ke riwayat!" << endl;
}

Transaksi* pop() {
    if (isEmptyStack()) {
        cout << "Stack underflow - Riwayat kosong!" << endl;
        return nullptr;
    }
    
    Transaksi* value = new Transaksi(top->data);
    NodeStack* temp = top;
    
    top = top->next;
    
    delete temp;
    
    return value;
}

Transaksi* peekStack() {
    if (isEmptyStack()) {
        cout << "Stack is empty" << endl;
        return nullptr;
    }
    return &(top->data);  
}

void displayStack() {
    if (isEmptyStack()) {
        cout << "Riwayat transaksi kosong." << endl;
        return;
    }
    
    cout << "\n-- RIWAYAT TRANSAKSI (Bottom -> Top) --" << endl;
    cout << "No\tNama Penumpang\t\tKereta\t\tRute\t\t\tTiket\tTotal" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    

    int count = 0;
    NodeStack* temp = top;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    
    Transaksi* arr = new Transaksi[count];
    temp = top;
    for (int i = count - 1; i >= 0; i--) {
        arr[i] = temp->data;
        temp = temp->next;
    }
    
    for (int i = 0; i < count; i++) {
        cout << (i + 1) << "\t";
        cout << arr[i].namaPenumpang << "\t\t";
        cout << arr[i].kereta.nama << "\t\t";
        cout << arr[i].kereta.asal << " -> " << arr[i].kereta.tujuan << "\t";
        cout << arr[i].jumlahTiket << "\t";
        cout << "Rp " << arr[i].totalHarga << endl;
    }
    
    delete[] arr;
    cout << "--------------------------------------------------------------------------------" << endl;
}

void lihatJadwal(Kereta* data, int n) {
    cout << "\n-- DAFTAR KERETA --" << endl;
    cout << "No\tNama\t\tRute\t\t\tHarga" << endl;
    cout << "---------------------------------------------------------" << endl;
    
    if (n == 0) {
        cout << "Belum ada data." << endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        cout << (data + i)->nomor << "\t"; 
        cout << (data + i)->nama << "\t\t";
        cout << (data + i)->asal << " -> " << (data + i)->tujuan << "\t";
        cout << "Rp " << (data + i)->harga << endl;
    }
    cout << "---------------------------------------------------------" << endl;

}

void inputKereta(Kereta* data, int &n) {

    if (n >= 100) {
        cout << "Data penuh !" << endl;
        return;
    }

    cout << "\n-- Input Kereta Baru --" << endl;
    cout << "Nomor Kereta: "; cin >> (data + n)->nomor;
    cout << "Nama Kereta : "; cin >> (data + n)->nama;
    cout << "Asal        : "; cin >> (data + n)->asal;
    cout << "Tujuan      : "; cin >> (data + n)->tujuan;
    cout << "Harga       : "; cin >> (data + n)->harga;
    
    n++; 
    cout << "Oke, data masuk!" << endl;

}


void cariRute(Kereta* data, int n, string asal, string tujuan) {
    cout << "\n-- Cari Rute: " << asal << " -> " << tujuan << " --" << endl;
    bool ketemu = false;
    
    for (int i = 0; i < n; i++) {
        if ((data + i)->asal == asal && (data + i)->tujuan == tujuan) {
            cout << "Ada nih: " << (data + i)->nama << " (Rp " << (data + i)->harga << ")" << endl;
            ketemu = true;
        }
    }
    if (!ketemu) {
        cout << "Gak ada rute itu." << endl;
    }
}

void cariNomor(Kereta* data, int n, int kunci) {
    cout << "\n-- Binary Search Nomor: " << kunci << " --" << endl;
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((data + j)->nomor > (data + j + 1)->nomor) {
                tukarData(&data[j], &data[j + 1]);  
            }
        }
    }
    cout << "Mengurutkan data . . ." << endl;

    int low = 0, high = n - 1;
    bool ketemu = false;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if ((data + mid)->nomor == kunci) {
            cout << ">> Ketemu di index " << mid << endl;
            ketemu = true;
            break;
        }
        if ((data + mid)->nomor < kunci) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    if (!ketemu) {
        cout << ">> Nomor gak ditemukan." << endl;
    }
}

void merge(Kereta* data, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Kereta* L = new Kereta[n1];
    Kereta* R = new Kereta[n2];

    for (int i = 0; i < n1; i++) *(L + i) = *(data + left + i);
    for (int j = 0; j < n2; j++) *(R + j) = *(data + mid + 1 + j);

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if ((L + i)->nama <= (R + j)->nama) {
            *(data + k) = *(L + i);
            i++;
        } else {
            *(data + k) = *(R + j);
            j++;
        }
        k++;
    }
    while (i < n1) { *(data + k) = *(L + i); i++; k++; }
    while (j < n2) { *(data + k) = *(R + j); j++; k++; }

    delete[] L;
    delete[] R;
}

void urutNama(Kereta* data, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        urutNama(data, left, mid);
        urutNama(data, mid + 1, right);
        merge(data, left, mid, right);
    }
}

void urutHarga(Kereta* data, int n) {
    for (int i = 0; i < n - 1; i++) {
        int idxMin = i;
        for (int j = i + 1; j < n; j++) {
            if ((data + j)->harga < (data + idxMin)->harga) {
                idxMin = j;
            }
        }
        tukarData(&data[idxMin], &data[i]);  
    }
    cout << "Berhasil urut harga termurah!" << endl;
}

void beliTiket(Kereta* dataKereta, int n) {
    cout << "\n-- PEMESANAN TIKET --" << endl;
    
    Transaksi transaksi;
    cout << "Nama Penumpang: "; cin.ignore(); getline(cin, transaksi.namaPenumpang);
    
    cout << "\nPilih Kereta:" << endl;
    lihatJadwal(dataKereta, n);
    cout << "Masukkan Nomor Kereta: ";
    int nomor;
    cin >> nomor;
    
    bool found = false;
    for (int i = 0; i < n; i++) {
        if ((dataKereta + i)->nomor == nomor) {
            transaksi.kereta = *(dataKereta + i);
            found = true;
            break;
        }
    }
    
    if (!found) {
        cout << "Kereta tidak ditemukan!" << endl;
        return;
    }
    
    cout << "Jumlah Tiket: "; cin >> transaksi.jumlahTiket;
    transaksi.totalHarga = transaksi.kereta.harga * transaksi.jumlahTiket;
    
    enqueue(&transaksi);
}

void prosesTiket() {
    cout << "\n-- PROSES PEMESANAN --" << endl;
    
    Transaksi* transaksi = dequeue();
    if (transaksi != nullptr) {
        cout << "\n Memproses:" << endl;
        cout << "  Nama Penumpang : " << transaksi->namaPenumpang << endl;
        cout << "  Kereta         : " << transaksi->kereta.nama << endl;
        cout << "  Rute           : " << transaksi->kereta.asal << " -> " << transaksi->kereta.tujuan << endl;
        cout << "  Jumlah Tiket   : " << transaksi->jumlahTiket << endl;
        cout << "  Total Harga    : Rp " << transaksi->totalHarga << endl;
        cout << "\n Pemesanan berhasil!" << endl;
        
        push(transaksi);
        
        delete transaksi;
    }
}

void batalTransaksi() {
    cout << "\n-- MEMBATALKAN TRANSAKSI TERAKHIR --" << endl;
    
    Transaksi* transaksi = pop();
    if (transaksi != nullptr) {
        cout << "\n Membatalkan:" << endl;
        cout << "  Nama Penumpang : " << transaksi->namaPenumpang << endl;
        cout << "  Kereta         : " << transaksi->kereta.nama << endl;
        cout << "  Rute           : " << transaksi->kereta.asal << " -> " << transaksi->kereta.tujuan << endl;
        cout << "  Total          : Rp " << transaksi->totalHarga << endl;
        cout << "\n Transaksi dibatalkan!" << endl;
        
        delete transaksi;
    }
}

void peekSemua() {
    cout << "\n-- PEEK STATUS --" << endl;
    
    cout << "\n[Antrian - Depan (Front)]" << endl;
    Transaksi* qPeek = peekQueue();
    if (qPeek != nullptr) {
        cout << "  Nama: " << qPeek->namaPenumpang << endl;
        cout << "  Kereta: " << qPeek->kereta.nama << endl;
        cout << "  Rute: " << qPeek->kereta.asal << " -> " << qPeek->kereta.tujuan << endl;
    }
    
    cout << "\n[Riwayat - Terakhir (Top)]" << endl;
    Transaksi* sPeek = peekStack();
    if (sPeek != nullptr) {
        cout << "  Nama: " << sPeek->namaPenumpang << endl;
        cout << "  Kereta: " << sPeek->kereta.nama << endl;
        cout << "  Rute: " << sPeek->kereta.asal << " -> " << sPeek->kereta.tujuan << endl;
        cout << "  Total: Rp " << sPeek->totalHarga << endl;
    }
}

void cleanupMemory() {
    while (!isEmptyQueue()) {
        delete dequeue();
    }
    while (!isEmptyStack()) {
        delete pop();
    }
}

int main() {
    Kereta dataKereta[100]; 
    int jmlData = 0;        
    int pil;                

    dataKereta[0] = {101, "Argo Bromo", "Surabaya", "Jakarta", 500000};
    dataKereta[1] = {102, "Taksaka", "Yogyakarta", "Jakarta", 450000};
    dataKereta[2] = {103, "Gajayana", "Malang", "Jakarta", 550000};
    dataKereta[3] = {104, "Argo Lawu", "Solo", "Jakarta", 475000};
    dataKereta[4] = {105, "Bima", "Surabaya", "Jakarta", 525000};
    dataKereta[5] = {106, "Turangga", "Bandung", "Surabaya", 380000};
    dataKereta[6] = {107, "Mutiara Selatan", "Bandung", "Yogyakarta", 320000};
    dataKereta[7] = {108, "Sancaka", "Surabaya", "Yogyakarta", 290000};
    dataKereta[8] = {109, "Fajar Utama", "Jakarta", "Yogyakarta", 460000};
    dataKereta[9] = {110, "Matarmaja", "Malang", "Jakarta", 420000};
    dataKereta[10] = {111, "Kertajaya", "Surabaya", "Jakarta", 350000};
    dataKereta[11] = {112, "Argo Wilis", "Bandung", "Surabaya", 410000};
    dataKereta[12] = {113, "Lodaya", "Solo", "Bandung", 340000};
    dataKereta[13] = {114, "Sawunggalih", "Kutoarjo", "Jakarta", 380000};
    dataKereta[14] = {115, "Kahuripan", "Blitar", "Jakarta", 400000};
    jmlData = 15;

    do {
        cout << "\n======================================" << endl;
        cout << "   SISTEM KERETA API + LINKED LIST    " << endl;
        cout << "======================================" << endl;
        cout << "   MANAJEMEN DATA KERETA:             " << endl;
        cout << "   1. Lihat Jadwal                    " << endl;
        cout << "   2. Tambah Data Kereta              " << endl;
        cout << "   3. Cari Rute                       " << endl;
        cout << "   4. Cari Nomor Kereta               " << endl;
        cout << "   5. Urut Nama Kereta                " << endl;
        cout << "   6. Urut Harga Kereta               " << endl;
        cout << "   QUEUE  :                           " << endl;
        cout << "   7. Beli Tiket                      " << endl;
        cout << "   8. Proses Tiket                    " << endl;
        cout << "   10. Tampil Antrian                 " << endl;
        cout << "   STACK  :                           " << endl;
        cout << "   9. Batal Transaksi                 " << endl;
        cout << "   11. Tampil Riwayat                 " << endl;
        cout << "   12. Peek Status                    " << endl;
        cout << "   0. Keluar                          " << endl;
        cout << "======================================" << endl;
        cout << "Pilih: ";
        cin >> pil;

        switch (pil) {
            case 1:
                lihatJadwal(dataKereta, jmlData);
                break;
            case 2:
                inputKereta(dataKereta, jmlData); 
                break;
            case 3: {
                string asal, tujuan;
                cout << "Asal: "; cin >> asal;
                cout << "Tujuan: "; cin >> tujuan;
                cariRute(dataKereta, jmlData, asal, tujuan);
                break;
            }
            case 4: {
                int nomor;
                cout << "Nomor Kereta: "; cin >> nomor;
                cariNomor(dataKereta, jmlData, nomor);
                break;
            }
            case 5:
                urutNama(dataKereta, 0, jmlData - 1);
                cout << "Nama diurutkan A-Z" << endl;
                lihatJadwal(dataKereta, jmlData);
                break;
            case 6:
                urutHarga(dataKereta, jmlData);
                lihatJadwal(dataKereta, jmlData);
                break;
            case 7:
                beliTiket(dataKereta, jmlData);
                break;
            case 8:
                prosesTiket();
                break;
            case 9:
                batalTransaksi();
                break;
            case 10:
                displayQueue();
                break;
            case 11:
                displayStack();
                break;
            case 12:
                peekSemua();
                break;
            case 0:
                cout << "Terima kasih! Bye!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pil != 0);

    cleanupMemory();
    
    return 0;
}