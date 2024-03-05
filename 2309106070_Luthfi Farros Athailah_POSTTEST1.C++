#include <iostream>
#include <string>

using namespace std;

bool login() {
    int attempts = 0;
    while (attempts < 3) {
        string username, password;
        cout << "Masukkan Nama: ";
        cin >> username;
        cout << "Masukkan NIM: ";
        cin >> password;
        if (username == "admin" && password == "123456") {
            return true;
        } else {
            cout << "Username atau Password salah. Coba lagi." << endl;
            attempts++;
        }
    }
    return false;
}

void konversi_kecepatan() {
    while (true) {
        cout << "\nMenu Konversi Kecepatan:" << endl;
        cout << "1. Kilometer/jam ke (Centimeter/detik, Meter/detik, Mil/jam)" << endl;
        cout << "2. Centimeter/detik ke (Kilometer/jam, Meter/detik, Mil/jam)" << endl;
        cout << "3. Meter/detik ke (Kilometer/jam, Centimeter/detik, Mil/jam)" << endl;
        cout << "4. Mil/jam ke (Kilometer/jam, Centimeter/detik, Meter/detik)" << endl;
        cout << "5. Keluar" << endl;
        int pilihan;
        cout << "Pilih menu (1-5): ";
        cin >> pilihan;
        if (pilihan == 5) {
            break;
        } else if (pilihan < 1 || pilihan > 4) {
            cout << "Pilihan tidak valid. Coba lagi." << endl;
            continue;
        }

        double kecepatan;
        cout << "Masukkan kecepatan: ";
        cin >> kecepatan;
        if (pilihan == 1) {
            cout << "Konversi Kilometer/jam ke:" << endl;
            cout << "Centimeter/detik: " << kecepatan * 100000 << endl;
            cout << "Meter/detik: " << kecepatan * 1000 << endl;
            cout << "Mil/jam: " << kecepatan * 0.621371 << endl;
        } else if (pilihan == 2) {
            cout << "Konversi Centimeter/detik ke:" << endl;
            cout << "Kilometer/jam: " << kecepatan / 100000 << endl;
            cout << "Meter/detik: " << kecepatan / 100 << endl;
            cout << "Mil/jam: " << kecepatan / 100000 * 0.621371 << endl;
        } else if (pilihan == 3) {
            cout << "Konversi Meter/detik ke:" << endl;
            cout << "Kilometer/jam: " << kecepatan / 1000 << endl;
            cout << "Centimeter/detik: " << kecepatan * 100 << endl;
            cout << "Mil/jam: " << kecepatan / 1000 * 0.621371 << endl;
        } else if (pilihan == 4) {
            cout << "Konversi Mil/jam ke:" << endl;
            cout << "Kilometer/jam: " << kecepatan * 1.60934 << endl;
            cout << "Centimeter/detik: " << kecepatan * 1.60934 * 100000 << endl;
            cout << "Meter/detik: " << kecepatan * 1.60934 * 1000 << endl;
        }
    }
}

int main() {
    if (!login()) {
        cout << "Login gagal. Program berhenti." << endl;
        return 0;
    }
    konversi_kecepatan();
    return 0;
}
