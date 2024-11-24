#include <iostream>
#include <cmath>
using namespace std;

struct Angka {
    int input_angka[100];
    int n;
};

int penjumlahan(Angka A) {
    int hasil_jumlah = 0;
    for (int i = 0; i < A.n; i++) {
        hasil_jumlah += A.input_angka[i];
    }
    return hasil_jumlah;
}

int pengurangan(Angka A) {
    int hasil_jumlah = A.input_angka[0];
    for (int i = 1; i < A.n; i++) {
        hasil_jumlah -= A.input_angka[i];
    }
    return hasil_jumlah;
}

int perkalian(Angka A) {
    int hasil_jumlah = A.input_angka[0];
    for (int i = 1; i < A.n; i++) {
        hasil_jumlah *= A.input_angka[i];
    }
    return hasil_jumlah;
}

float pembagian(Angka A) {
    float hasil_jumlah = A.input_angka[0];
    for (int i = 1; i < A.n; i++) {
        if (A.input_angka[i] == 0) {
            cout << "Error: Pembagian dengan nol tidak diizinkan pada elemen ke-" << (i + 1) << "." << endl;
            return 0;
        }
        hasil_jumlah /= A.input_angka[i];
    }
    return hasil_jumlah;
}


int modulo(Angka A) {
    if (A.input_angka[1] != 0)
        return A.input_angka[0] % A.input_angka[1];
    else {
        cout << "Error: Modulo dengan nol tidak diizinkan." << endl;
        return 0;
    }
}

int akarpangkat(Angka A) {
    return pow(A.input_angka[0], A.input_angka[1]);
}

void akarKuadrat(Angka A) {
    if (A.input_angka[0] >= 0)
        cout << "Hasil Akar Kuadrat: " << sqrt(A.input_angka[0]) << endl;
    else {
        cout << "Error: Tidak bisa mengambil akar kuadrat dari bilangan negatif." << endl;
    }
}

const double PI = 3.14159265358979323846;

double toRadians(double degree) {
    return degree * (PI / 180.0);
}

double hasil_sin(double degree, double radian) {
    radian = toRadians(degree);
    return sin(radian);
}

double hasil_cos(double degree, double radian) {
    radian = toRadians(degree);
    return cos(radian);
}

void hasil_tan(double degree, double radian) {
    radian = toRadians(degree);
    if (cos(radian) != 0) {
        cout << "Hasil tan(" << degree << ") = " << tan(radian) << endl;
    } else {
        cout << "Hasil tan(" << degree << ") tidak terdefinisi (tak hingga)." << endl;
    }
}

void input1(Angka &A) {
    cout << "Masukkan jumlah angka yang ingin dihitung: ";
    cin >> A.n;
    for (int i = 0; i < A.n; i++) {
        cout << "Masukkan Angka [" << i + 1 << "]: ";
        cin >> A.input_angka[i];
    }
}

void input2(Angka &A) {
    A.n = 2;
    for (int n = 0; n < 2; n++) {
        cout << "Masukkan Angka [" << n + 1 << "]: ";
        cin >> A.input_angka[n];
    }
}

void input3(Angka &A) {
    cout << "Masukkan Angka: ";
    cin >> A.input_angka[0];
    cout << "Masukkan Pangkat: ";
    cin >> A.input_angka[1];
}

void input4(Angka &A) {
    cout << "Masukkan Angka: ";
    cin >> A.input_angka[0];
}

void input5(Angka &A, double degree) {
    cout << "Masukkan sudut dalam derajat: ";
    cin >> degree;
}

int main() {
    int pilihan;
    char t;
    bool tes = true;
    double degree;
    double radian;
    Angka A;

    do {
        cout << "=========================================" << endl;
        cout << "|         SCIENTIFIC CALCULATOR         |" << endl;
        cout << "=========================================" << endl;
        cout << "|     Anggota Kelompok 8 (Xeesoxee)     |" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "| No |          Nama Anggota            |" << endl;
        cout << "-----------------------------------------" << endl;
        cout << "| 1  |  Muhamad Rafy Ramadhan           |" << endl;
        cout << "| 2  |  Raihan Febriahdi                |" << endl;
        cout << "| 3  |  Ridho Arazisyah                 |" << endl;
        cout << "=========================================" << endl;
        cout << "|   Pilih jenis operasi yang tersedia:  |" << endl;
        cout << "|---------------------------------------|" << endl;
        cout << "|  1. Penjumlahan                       |" << endl;
        cout << "|  2. Pengurangan                       |" << endl;
        cout << "|  3. Perkalian                         |" << endl;
        cout << "|  4. Pembagian                         |" << endl;
        cout << "|  5. Modulo                            |" << endl;
        cout << "|  6. Akar Pangkat                      |" << endl;
        cout << "|  7. Akar Kuadrat                      |" << endl;
        cout << "|  8. Sinus                             |" << endl;
        cout << "|  9. Cosinus                           |" << endl;
        cout << "| 10. Tangen                            |" << endl;
        cout << "=========================================" << endl;
        cout << "Masukkan pilihan Anda [1-10]: ";
        cin >> pilihan;

        if (pilihan < 1 || pilihan > 10) {
            cout << "Pilihan tidak valid, silakan coba lagi." << endl;
            continue;
        }

        if (pilihan >= 1 && pilihan <= 4) {
            system("cls");
            input1(A);
        } else if (pilihan == 5) {
            system("cls");
            input2(A);
        } else if (pilihan == 6) {
            system("cls");
            input3(A);
        } else if (pilihan == 7) {
            system("cls");
            input4(A);
        } else if (pilihan >= 8 && pilihan <= 10) {
            system("cls");
            input5(A,degree);
        }

        switch (pilihan) {
            case 1:
                cout<<"Hasil Dari penjumlahan ";
                cout<<A.input_angka[0];
                for(int i = 1; i < A.n; i++){
                    cout<<" + "<<A.input_angka[i];
                }
                cout<<" adalah "<<penjumlahan(A)<<endl;
                break;
            case 2:
                cout<<"Hasil Dari pengurangan ";
                cout<<A.input_angka[0];
                for(int i = 1; i < A.n; i++){
                    cout<<" - "<<A.input_angka[i];
                }
                cout<<" adalah "<<pengurangan(A)<<endl;
                break;
            case 3:
                cout<<"Hasil Dari perkalian ";
                cout<<A.input_angka[0];
                for(int i = 1; i < A.n; i++){
                    cout<<" x "<<A.input_angka[i];
                }
                cout<<" adalah "<<perkalian(A)<<endl;
                break;

            case 4:
                cout<<"Hasil Dari pembagian ";
                cout<<A.input_angka[0];
                for(int i = 1; i < A.n; i++){
                    cout<<" : "<<A.input_angka[i];
                }
                cout<<" adalah "<<pembagian(A)<<endl;
                break;
            case 5:
                cout << "Hasil Modulo: " << modulo(A) << endl;
                break;

            case 6:
                cout << "Hasil Akar Pangkat: " << akarpangkat(A) << endl;
                break;

            case 7:
                akarKuadrat(A);
                break;

            case 8:
                cout << "Hasil sin(" << degree << ") = " << hasil_sin(degree,radian) << endl;
                break;

            case 9:
                cout << "Hasil cos(" << degree << ") = " << hasil_cos(degree,radian) << endl;
                break;

            case 10:
                hasil_tan(degree,radian);
                break;
        }
        cout << endl;
        cout << "Kembali ke menu utama? [y/n]: ";
        cin >> t;
        tes = (t == 'y' || t == 'Y');
        system("cls");
    } while (tes);
    system("cls");

    cout << "================ Program selesai ================" << endl;
    cout << "|                                               |" << endl;
    cout << "|                       ####                    |" << endl;
    cout << "|                     ##    ##                  |" << endl;
    cout << "|                     ##    ##                  |" << endl;
    cout << "|                     ##    ##                  |" << endl;
    cout << "|                   ##      ##                  |" << endl;
    cout << "|                   ##      ##                  |" << endl;
    cout << "|                   ##      ##                  |" << endl;
    cout << "|                 ##          ##############    |" << endl;
    cout << "|               ##                          ##  |" << endl;
    cout << "| ##########  ##                            ##  |" << endl;
    cout << "| ##******####                            ####  |" << endl;
    cout << "| ##******##                                ##  |" << endl;
    cout << "| ##******##                                ##  |" << endl;
    cout << "| ##******##                            ####    |" << endl;
    cout << "| ##******##                              ##    |" << endl;
    cout << "| ##******##                              ##    |" << endl;
    cout << "| ##******##                          ####      |" << endl;
    cout << "| ##******##                            ##      |" << endl;
    cout << "| ############                          ##      |" << endl;
    cout << "|             ##########################        |" << endl;
    cout << "|                                               |" << endl;
    cout << "================== Terima Kasih =================" << endl;

    return 0;
}
