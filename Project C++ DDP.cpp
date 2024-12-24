#include <string>
#include <iostream>
#include <limits>
#include <iomanip>
using namespace std;

int pasien = 0;
int noantrian = 0;
int LoketA[200];
int LoketB[200];
int LoketC[200];
int LoketD[200];
int LoketE[200];

string waktudaftar() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", ltm);
    return string(buffer);
}

struct BiodataPasien {
    int noantrian;
    string nama;
    string alamat;
    string telp;
    string umur;
    string jamdaftar;
};

struct BiodataPasien arrpasien[200];

void tampilkandataPasien(){
    if (pasien < 1){
        cout << " ========== DATA PASIEN RUMAH SAKIT CINTA KASIH ==========" << endl;
        cout << "!! DATA PASIEN RUMAH SAKIT CINTA KASIH MASIH KOSONG !!" << endl;
    } else {
        cout << "\n\t\t========== DATA PASIEN RUMAH SAKIT CINTA KASIH ==========" << endl;
        cout << "-------------------------------------------------------------------------------------------" << endl;
        cout << left << setw(5) << "| No" 
        << left << setw(22) << "| Nama" 
        << left << setw(7) << "| Umur" 
        << left << setw(16) << "| Domisili"  
        << left << setw(17) << "| No.Telpon" 
        << left << setw(10) << "| Waktu Pendaftaran    |" << endl;
        cout << "|----|---------------------|------|---------------|----------------|----------------------|" << endl;

        for (int i = 0; i < pasien; i++) {
            cout << "| " << left << setw(3) << arrpasien[i].noantrian
                << "| " << left << setw(20) << arrpasien[i].nama 
                << "| " << left << setw(5) << arrpasien[i].umur
                << "| " << left << setw(14) << arrpasien[i].alamat
                << "| " << left << setw(15) << arrpasien[i].telp 
                << "| " << left << setw(21) << arrpasien[i].jamdaftar
                << "|" << endl;
        }

        cout << "-------------------------------------------------------------------------------------------" << endl;
    }
}

void TekanEnter(){
    cout << "Tekan Enter Untuk Melanjutkan...";
    cin.ignore();
    cin.get();
}

void PanggilPasien() {
    char pilih;
    int noantrianInput;

    if (pasien < 1) {
        cout << "!! DATA PASIEN RUMAH SAKIT CINTA KASIH MASIH KOSONG !!" << endl;
        cout << "Tekan Enter Untuk Melanjutkan...";
        cin.ignore();
        cin.get();
        return;
    } else {
        cout << "=== Memanggil Pasien Dari Loket ===" << endl;
        cout << "Masukan Nomor Pasien Terdaftar (1-" << pasien << "): ";
        cin >> noantrianInput;

        // Validate the input for noantrian
        if (noantrianInput < 1 || noantrianInput > pasien) {
            cout << "Nomor pasien tidak valid." << endl;
            TekanEnter();
            return;
        }

        int index = noantrianInput - 1; // KARENA INDEX DI MULAI DARI NOL

        cout << "\nDetail Pasien:" << endl;
        cout << "No Antrian: " << arrpasien[index].noantrian << endl;
        cout << "Nama: " << arrpasien[index].nama << endl;
        cout << "Umur: " << arrpasien[index].umur << endl;
        cout << "Alamat: " << arrpasien[index].alamat << endl;
        cout << "No Telepon: " << arrpasien[index].telp << endl;

        cout << "Masukan Loket (A/B/C/D) : ";
        cin >> pilih;

        if (pilih == 'A' || pilih == 'a') {
            LoketA[index] = arrpasien[index].noantrian;
            cout << "Pasien Ke Atas Nama " << arrpasien[index].nama << " Berhasil Ditambahkan ke Loket A :)" << endl;
        } else if (pilih == 'B' || pilih == 'b') {
            LoketB[index] = arrpasien[index].noantrian;
            cout << "Pasien Ke Atas Nama " << arrpasien[index].nama << " Berhasil Ditambahkan ke Loket B :)" << endl;
        } else if (pilih == 'C' || pilih == 'c') {
            LoketC[index] = arrpasien[index].noantrian;
            cout << "Pasien Ke Atas Nama " << arrpasien[index].nama << " Berhasil Ditambahkan ke Loket C :)" << endl;
        } else if (pilih == 'D' || pilih == 'd') {
            LoketD[index] = arrpasien[index].noantrian;
            cout << "Pasien Ke Atas Nama " << arrpasien[index].nama << " Berhasil Ditambahkan ke Loket D :)" << endl;
        } else {
            cout << "Loket Tidak Tersedia" << endl;
            cout << "Tekan Enter Untuk Melanjutkan...";
            cin.ignore();
            cin.get();
            return;
        }

        TekanEnter();
    }
}

void printStrukAntrian() {
    cout << "\n==============================================" << endl;
    cout << "=                 Struk Antrian              =    " << endl;
    cout << "=         Rumah Sakit Cinta Kasih UAD        =    " << endl;
    cout << "==============================================" << endl;
    cout << "= Nomor Antrian       : " << setw(20) << arrpasien[pasien - 1].noantrian << " =" << endl;
    cout << "= Nama Pasien         : " << setw(20) << arrpasien[pasien - 1].nama << " =" << endl;
    cout << "= Umur                : " << setw(20) << arrpasien[pasien - 1].umur << " =" << endl;
    cout << "= Domisili            : " << setw(20) << arrpasien[pasien - 1].alamat << " =" << endl;
    cout << "= No Telepon          : " << setw(20) << arrpasien[pasien - 1].telp << " =" << endl;
    cout << "= Tanggal dan Waktu   : " << setw(20) << arrpasien[pasien - 1].jamdaftar << " =" << endl;
    cout << "==============================================\n";
}

void inputpasien(){
    cout << "Masukan Nama Pasien : ";
    cin.ignore();
    getline(cin, arrpasien[pasien].nama);

    cout << "Masukan Umur Pasien : ";
    cin >> arrpasien[pasien].umur;

    cout << "Masukan Alamat Pasien : ";
    cin.ignore();
    getline(cin, arrpasien[pasien].alamat);

    cout << "Masukan No Telepon Pasien : ";
    cin >> arrpasien[pasien].telp;

    arrpasien[pasien].noantrian = noantrian + 1;
    arrpasien[pasien].jamdaftar = waktudaftar();
    noantrian++;
    pasien++;

    cout << endl;

    printStrukAntrian();
   
    cout << "Tekan Enter Untuk Melanjutkan...";
    cin.ignore();
    cin.get();
}



int main(){

    int pilih;

    do {
          system("cls");
    cout << "=====================================================================" << endl;
    cout << "\t\tProgram Antrean Rumah Sakit Cinta Kasih" << endl;
    cout << "\t\t\tUniversitas Ahmad Dahlan" << endl;
    cout << "=====================================================================" << endl << endl;
    cout << "Nomor Antrian Saat Ini    : " << noantrian << endl;
    cout << "Nomor Antrian Selanjutnya : " << noantrian + 1 << endl;
    cout << "Jumlah Pasien Terdaftar   : " << pasien << endl << endl;

    cout << left << setw(15) << "+-------------------+ "
         << left << setw(15) << "+-------------------+ "
         << left << setw(15) << "+-------------------+ "
         << left << setw(15) << "+-------------------+ " << endl;

    cout << left << setw(15) << "|      Loket - A    | "
         << left << setw(15) << "|      Loket - B    | "
         << left << setw(15) << "|      Loket - C    | "
         << left << setw(15) << "|      Loket - D    | " << endl;

    // Display the latest patient number in each loket
    cout << left << setw(6) << "|    " << "NO.PAS - " << "    | "
         << left << setw(6) << "|    " << "NO.PAS - "   << "    | "
         << left << setw(6) << "|    " << "NO.PAS - "   << "    | "
         << left << setw(6) << "|    " << "NO.PAS - "   << "    |" << endl;

    cout << left << setw(15) << "+-------------------+ "
         << left << setw(15) << "+-------------------+ "
         << left << setw(15) << "+-------------------+ "
         << left << setw(15) << "+-------------------+ " << endl << endl;

        cout << " --- Dashboard Admin ---" << endl;
        cout << "1. Menambahkan Data Pasien" << endl;
        cout << "2. Memanggil Pelanggan" << endl;
        cout << "3. Melihat Daftar Pasien" << endl;
        cout << "4. Keluar" << endl;
        cout << "Masukkan pilihan (1-4): ";
        cin >> pilih;

        switch(pilih){
            case 1:
                cout << "--- Menambahkan Data Pasien ---" << endl;
                inputpasien();
                break;
            case 2:
                tampilkandataPasien();
                PanggilPasien();
                break;
            case 3:
                tampilkandataPasien();
                TekanEnter();
                break;
            case 4:
                cout << "Terimakasih Telah Menggunakan Program" << endl;
                cout << "Selamat Beristirahat" << endl;
                break;
            default:
                cout << "Pilihan tidak valid" << endl;
        }
    } while (pilih != 4);

    return 0;
}
