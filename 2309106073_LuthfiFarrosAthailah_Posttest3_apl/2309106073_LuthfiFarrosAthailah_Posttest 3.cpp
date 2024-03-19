#include <iostream>
#include <vector>
#include <string>

struct Jemaah {
    std::string nama;
    std::string nim;
};

std::vector<Jemaah> jemaah_list;
bool login() {
    int salah = 0;
    while (salah < 3) {
        std::string nama, nim;
        std::cout << "Masukkan nama: ";
        std::cin >> nama;
        std::cout << "Masukkan NIM: ";
        std::cin >> nim;

        bool ditemukan = false;
        if ("Faros" == nama && "073" == nim) {
            ditemukan = true;
            return true;
        } else {
            std::cout << "Nama atau NIM salah. Coba lagi.\n";
            salah++;
        }
    }
    return false;
}

void tambah_jemaah() {
    std::string nama, nim;
    std::cout << "Masukkan nama jemaah: ";
    std::cin >> nama;
    std::cout << "Masukkan NIM jemaah: ";
    std::cin >> nim;
    jemaah_list.push_back({nama, nim});
    std::cout << "Jemaah berhasil ditambahkan.\n";
}

void lihat_jemaah() {
    for (const auto& jemaah : jemaah_list) {
        std::cout << "Nama: " << jemaah.nama << ", NIM: " << jemaah.nim << "\n";
    }
}

void update_jemaah() {
    std::string nama_lama, nim_lama, nama_baru, nim_baru;
    std::cout << "Masukkan nama jemaah yang ingin diupdate: ";
    std::cin >> nama_lama;
    std::cout << "Masukkan NIM jemaah yang ingin diupdate: ";
    std::cin >> nim_lama;
    std::cout << "Masukkan nama baru: ";
    std::cin >> nama_baru;
    std::cout << "Masukkan NIM baru: ";
    std::cin >> nim_baru;

    for (auto& jemaah : jemaah_list) {
        if (jemaah.nama == nama_lama && jemaah.nim == nim_lama) {
            jemaah.nama = nama_baru;
            jemaah.nim = nim_baru;
            std::cout << "Data jemaah berhasil diupdate.\n";
            return;
        }
    }
    std::cout << "Jemaah tidak ditemukan.\n";
}

void hapus_jemaah() {
    std::string nama, nim;
    std::cout << "Masukkan nama jemaah yang ingin dihapus: ";
    std::cin >> nama;
    std::cout << "Masukkan NIM jemaah yang ingin dihapus: ";
    std::cin >> nim;

    for (auto it = jemaah_list.begin(); it != jemaah_list.end(); ++it) {
        if (it->nama == nama && it->nim == nim) {
            jemaah_list.erase(it);
            std::cout << "Jemaah berhasil dihapus.\n";
            return;
        }
    }
    std::cout << "Jemaah tidak ditemukan.\n";
}

// Fungsi rekursif untuk pencarian jemaah berdasarkan nama atau NIM
void cari_jemaah_recursive(const std::string& keyword, int index = 0) {
    if (index >= jemaah_list.size()) {
        std::cout << "Jemaah tidak ditemukan.\n";
        return;
    }

    const Jemaah& jemaah = jemaah_list[index];
    if (jemaah.nama == keyword || jemaah.nim == keyword) {
        std::cout << "Nama: " << jemaah.nama << ", NIM: " << jemaah.nim << "\n";
        return;
    }

    cari_jemaah_recursive(keyword, index + 1);
}

int main() {
    if (login()) {
        int pilihan;
        do {
            std::cout << "\nMenu:\n";
            std::cout << "1. Tambah Jemaah\n";
            std::cout << "2. Lihat Jemaah\n";
            std::cout << "3. Update Jemaah\n";
            std::cout << "4. Hapus Jemaah\n";
            std::cout << "5. Cari Jemaah\n";
            std::cout << "6. Keluar\n";
            std::cout << "Pilih menu: ";
            std::cin >> pilihan;

            switch (pilihan) {
                case 1:
                    tambah_jemaah();
                    break;
                case 2:
                    lihat_jemaah();
                    break;
                case 3:
                    update_jemaah();
                    break;
                case 4:
                    hapus_jemaah();
                    break;
                case 5: {
                    std::string keyword;
                    std::cout << "Masukkan nama atau NIM jemaah yang ingin dicari: ";
                    std::cin >> keyword;
                    cari_jemaah_recursive(keyword);
                    break;
                }
                case 6:
                    std::cout << "Program berhenti.\n";
                    break;
                default:
                    std::cout << "Pilihan tidak valid. Coba lagi.\n";
            }
        } while (pilihan != 6);
    } else {
        std::cout << "Login gagal. Program berhenti.\n";
    }
    return 0;
}
