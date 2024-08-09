#include <stdio.h>
#include <string.h>

// Maksimum jumlah mahasiswa
#define MAX_MAHASISWA 100

// Mendefinisikan struktur data Mahasiswa
struct Mahasiswa {
    char npm[15];
    char nama[50];
    char tempat_lahir[50];
    char tanggal_lahir[15]; // Format: DD-MM-YYYY
    char prodi[50];
};

// Fungsi untuk menampilkan menu
void tampilkanMenu() {
    printf("\nMenu:\n");
    printf("1. Tambah Data Mahasiswa\n");
    printf("2. Tampilkan Data Mahasiswa\n");
    printf("3. Hapus Data Mahasiswa\n");
    printf("4. Keluar\n");
    printf("Pilih opsi: ");
}

// Fungsi untuk menambah data mahasiswa
void tambahDataMahasiswa(struct Mahasiswa mhs[], int *jumlah) {
    if (*jumlah >= MAX_MAHASISWA) {
        printf("Data mahasiswa penuh!\n");
        return;
    }

    printf("Masukkan NPM: ");
    fgets(mhs[*jumlah].npm, sizeof(mhs[*jumlah].npm), stdin);

    printf("Masukkan Nama: ");
    fgets(mhs[*jumlah].nama, sizeof(mhs[*jumlah].nama), stdin);

    printf("Masukkan Tempat Lahir: ");
    fgets(mhs[*jumlah].tempat_lahir, sizeof(mhs[*jumlah].tempat_lahir), stdin);

    printf("Masukkan Tanggal Lahir (DD-MM-YYYY): ");
    fgets(mhs[*jumlah].tanggal_lahir, sizeof(mhs[*jumlah].tanggal_lahir), stdin);

    printf("Masukkan Program Studi: ");
    fgets(mhs[*jumlah].prodi, sizeof(mhs[*jumlah].prodi), stdin);

    (*jumlah)++;
    printf("Data mahasiswa berhasil ditambahkan.\n");
}

// Fungsi untuk menampilkan data mahasiswa
void tampilkanDataMahasiswa(struct Mahasiswa mhs[], int jumlah) {
    if (jumlah == 0) {
        printf("Belum ada data mahasiswa.\n");
        return;
    }

    for (int i = 0; i < jumlah; i++) {
        printf("\nData Mahasiswa %d:\n", i + 1);
        printf("NPM: %s", mhs[i].npm);
        printf("Nama: %s", mhs[i].nama);
        printf("Tempat Lahir: %s", mhs[i].tempat_lahir);
        printf("Tanggal Lahir: %s", mhs[i].tanggal_lahir);
        printf("Program Studi: %s", mhs[i].prodi);
    }
}

// Fungsi untuk menghapus data mahasiswa berdasarkan NPM
void hapusDataMahasiswa(struct Mahasiswa mhs[], int *jumlah) {
    if (*jumlah == 0) {
        printf("Belum ada data mahasiswa.\n");
        return;
    }

    char npm[15];
    printf("Masukkan NPM mahasiswa yang ingin dihapus: ");
    fgets(npm, sizeof(npm), stdin);

    int found = 0;
    for (int i = 0; i < *jumlah; i++) {
        if (strcmp(mhs[i].npm, npm) == 0) {
            found = 1;
            // Geser data berikutnya ke posisi saat ini
            for (int j = i; j < *jumlah - 1; j++) {
                mhs[j] = mhs[j + 1];
            }
            (*jumlah)--;
            printf("Data mahasiswa dengan NPM %s telah dihapus.\n", npm);
            break;
        }
    }

    if (!found) {
        printf("Mahasiswa dengan NPM %s tidak ditemukan.\n", npm);
    }
}

int main() {
    struct Mahasiswa mahasiswa[MAX_MAHASISWA];
    int jumlahMahasiswa = 0;
    int pilihan;

    do {
        tampilkanMenu();
        scanf("%d", &pilihan);
        getchar(); // Menangkap newline setelah memasukkan pilihan

        switch(pilihan) {
            case 1:
                tambahDataMahasiswa(mahasiswa, &jumlahMahasiswa);
                break;

            case 2:
                tampilkanDataMahasiswa(mahasiswa, jumlahMahasiswa);
                break;

            case 3:
                hapusDataMahasiswa(mahasiswa, &jumlahMahasiswa);
                break;

            case 4:
                printf("Keluar dari program.\n");
                break;

            default:
                printf("Opsi tidak valid. Silakan coba lagi.\n");
        }
    } while(pilihan != 4);

    return 0;
}
