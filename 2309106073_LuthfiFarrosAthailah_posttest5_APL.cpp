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
        for (const auto& jemaah : jemaah_list) {
            if (jemaah.nama == nama && jemaah.nim == nim) {
                ditemukan = true;
                return true;
            }
        }
        if (!ditemukan) {
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
    if (jemaah_list.empty()) {
        std::cout << "Belum ada jemaah yang ditambahkan.\n";
    } else {
        for (const auto& jemaah : jemaah_list) {
            std::cout << "Nama: " << jemaah.nama << ", NIM: " << jemaah.nim << "\n";
        }
    }
}

void update_jemaah() {
    if (jemaah_list.empty()) {
        std::cout << "Belum ada jemaah yang ditambahkan.\n";
        return;
    }

    std::string nama_lama, nim_lama, nama_baru, nim_baru;
    std::cout << "Masukkan nama jemaah yang ingin diupdate: ";
    std::cin >> nama_lama;
    std::cout << "Masukkan NIM jemaah yang ingin diupdate: ";
    std::cin >> nim_lama;
    std::cout << "Masukkan nama baru: ";
    std::cin >> nama_baru;
    std::cout << "Masukkan NIM baru: ";
    std::cin >> nim_baru;

    bool ditemukan = false;
    for (auto& jemaah : jemaah_list) {
        if (jemaah.nama == nama_lama && jemaah.nim == nim_lama) {
            jemaah.nama = nama_baru;
            jemaah.nim = nim_baru;
            std::cout << "Data jemaah berhasil diupdate.\n";
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        std::cout << "Jemaah tidak ditemukan.\n";
    }
}

void hapus_jemaah() {
    if (jemaah_list.empty()) {
        std::cout << "Belum ada jemaah yang ditambahkan.\n";
        return;
    }

    std::string nama, nim;
    std::cout << "Masukkan nama jemaah yang ingin dihapus: ";
    std::cin >> nama;
    std::cout << "Masukkan NIM jemaah yang ingin dihapus: ";
    std::cin >> nim;

    bool ditemukan = false;
    for (auto it = jemaah_list.begin(); it != jemaah_list.end(); ++it) {
        if (it->nama == nama && it->nim == nim) {
            jemaah_list.erase(it);
            std::cout << "Jemaah berhasil dihapus.\n";
            ditemukan = true;
            break;
        }
    }

    if (!ditemukan) {
        std::cout << "Jemaah tidak ditemukan.\n";
    }
}

void cari_jemaah_recursive(const std::string& keyword, int index = 0) {
    if (jemaah_list.empty() || index >= jemaah_list.size()) {
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

// Fungsi dengan parameter address-of
void tambah_jemaah_pointer(Jemaah* jemaah_ptr) {
    jemaah_list.push_back(*jemaah_ptr);
    std::cout << "Jemaah berhasil ditambahkan menggunakan pointer.\n";
}

// Fungsi dengan parameter dereference
void lihat_jemaah_pointer(Jemaah* jemaah_ptr) {
    std::cout << "Nama: " << jemaah_ptr->nama << ", NIM: " << jemaah_ptr->nim << "\n";
}

int main() {
    int pilihan;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Login\n";
        std::cout << "2. Tambah Jemaah\n";
        std::cout << "3. Lihat Jemaah\n";
        std::cout << "4. Update Jemaah\n";
        std::cout << "5. Hapus Jemaah\n";
        std::cout << "6. Cari Jemaah\n";
        std::cout << "7. Keluar\n";
        std::cout << "Pilih menu: ";
        std::cin >> pilihan;

        switch (pilihan) {
            case 1: {
                if (login()) {
                    std::cout << "Login berhasil.\n";
                } else {
                    std::cout << "Login gagal. Silakan coba lagi.\n";
                }
                break;
            }
            case 2: {
                Jemaah new_jemaah;
                std::cout << "Masukkan nama jemaah: ";
                std::cin >> new_jemaah.nama;
                std::cout << "Masukkan NIM jemaah: ";
                std::cin >> new_jemaah.nim;
                tambah_jemaah_pointer(&new_jemaah);
                break;
            }
            case 3: {
    if (jemaah_list.empty()) {
        std::cout << "Belum ada jemaah yang ditambahkan.\n";
    } else {
        std::cout << "Daftar Jemaah:\n";
        for (size_t i = 0; i < jemaah_list.size(); ++i) {
            lihat_jemaah_pointer(&jemaah_list[i]);
        }
    }
    break;
}
            case 4:
                update_jemaah();
                break;
            case 5:
                hapus_jemaah();
                break;
            case 6: {
                std::string keyword;
                std::cout << "Masukkan nama atau NIM jemaah yang ingin dicari: ";
                std::cin >> keyword;
                cari_jemaah_recursive(keyword);
                break;
            }
            case 7:
                std::cout << "Program berhenti.\n";
                break;
            default:
                std::cout << "Pilihan tidak valid. Coba lagi.\n";
        }
    } while (pilihan != 7);

    return 0;
}
