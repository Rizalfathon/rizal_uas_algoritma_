#include <iostream>
#include <queue>

using namespace std;

// Struktur untuk menyimpan informasi lagu
struct Lagu {
    string judul;
    string artis;
};

int main() {
    // Deklarasi Queue untuk menyimpan lagu
    queue<Lagu> playlist;

    // Nama pengguna untuk playlist
    string namaPengguna;
    cout << "Masukkan nama pengguna: ";
    getline(cin, namaPengguna);

    // Playlist pengguna
    string namaPlaylistPengguna = namaPengguna + "'s Playlist";
    string namaPlaylistFavorit = "Favorite Playlist";

    // Pilihan menu
    int pilihan;
    do {
        // Menampilkan menu
        cout << "\nMenu:\n";
        cout << "1. Tambah Lagu ke " << namaPlaylistPengguna << endl;
        cout << "2. Tambah Lagu ke " << namaPlaylistFavorit << endl;
        cout << "3. Tampilkan Playlist\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore(); // Membersihkan newline di buffer

        switch (pilihan) {
            case 1:
            case 2: {
                // Menambah lagu ke playlist
                Lagu lagu;
                cout << "Masukkan judul lagu: ";
                getline(cin, lagu.judul);
                cout << "Masukkan nama artis: ";
                getline(cin, lagu.artis);

                // Menambahkan lagu ke playlist sesuai pilihan
                if (pilihan == 1) {
                    playlist.push(lagu);
                    cout << "Lagu ditambahkan ke " << namaPlaylistPengguna << endl;
                } else {
                    playlist.push(lagu);
                    cout << "Lagu ditambahkan ke " << namaPlaylistFavorit << endl;
                }
                break;
            }
            case 3:
                // Menampilkan playlist
                if (playlist.empty()) {
                    cout << "Playlist kosong.\n";
                } else {
                    cout << "Playlist " << namaPlaylistPengguna << " dan " << namaPlaylistFavorit << ":\n";
                    int nomorLagu = 1;
                    while (!playlist.empty()) {
                        Lagu lagu = playlist.front();
                        playlist.pop();
                        cout << nomorLagu << ". " << lagu.judul << " - " << lagu.artis << endl;
                        nomorLagu++;
                    }
                }
                break;
            case 0:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
                break;
        }

    } while (pilihan != 0);

    return 0;
}