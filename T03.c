#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    char nama[50];
    float berat;   
    float total;   
} Transaksi;

#define FILE_NAME "data_laundry.dat"
#define TARIF_PER_KG 7000

int ambilIdTerakhir() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) return 0;

    Transaksi t;
    int last = 0;
    while (fread(&t, sizeof(Transaksi), 1, fp) == 1) {
        if (t.id > last) last = t.id;
    }
    fclose(fp);
    return last;
}

void tambahTransaksi() {
    Transaksi t;
    t.id = ambilIdTerakhir() + 1;

    printf("\nNama pelanggan: ");
    getchar();
    fgets(t.nama, sizeof(t.nama), stdin);

    for (int i = 0; t.nama[i]; i++) {
        if (t.nama[i] == '\n') {
            t.nama[i] = '\0';
            break;
        }
    }

    printf("Berat (kg): ");
    scanf("%f", &t.berat);

    t.total = t.berat * TARIF_PER_KG;

    FILE *fp = fopen(FILE_NAME, "ab");
    if (!fp) {
        printf("Gagal menyimpan data.\n");
        return;
    }
    fwrite(&t, sizeof(Transaksi), 1, fp);
    fclose(fp);

    printf("Transaksi tersimpan! ID=%d, Total=Rp%.0f\n", t.id, t.total);
}

void tampilkanSemua() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("\nBelum ada data.\n");
        return;
    }

    printf("\n=== DAFTAR TRANSAKSI ===\n");
    printf("%-4s %-20s %-8s %-10s\n", "ID", "Nama", "Kg", "Total");
    printf("-------------------------------------------\n");

    Transaksi t;
    while (fread(&t, sizeof(Transaksi), 1, fp) == 1) {
        printf("%-4d %-20s %-8.1f Rp%-10.0f\n",
               t.id, t.nama, t.berat, t.total);
    }
    fclose(fp);
}

void totalKeseluruhan() {
    FILE *fp = fopen(FILE_NAME, "rb");
    if (!fp) {
        printf("\nBelum ada data.\n");
        return;
    }

    Transaksi t;
    float totalSemua = 0;

    while (fread(&t, sizeof(Transaksi), 1, fp) == 1) {
        totalSemua += t.total;
    }
    fclose(fp);

    printf("\n=== TOTAL KESELURUHAN TRANSAKSI ===\n");
    printf("Total Pendapatan: Rp%.0f\n", totalSemua);
}

int main() {
    int pilih;

    do {
        printf("\n===== LAUNDRY DEL =====\n");
        printf("1. Tambah transaksi\n");
        printf("2. Lihat semua transaksi\n");
        printf("3. Total keseluruhan transaksi\n");
        printf("0. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilih);

        if (pilih == 1) tambahTransaksi();
        else if (pilih == 2) tampilkanSemua();
        else if (pilih == 3) totalKeseluruhan();
        else if (pilih == 0) printf("Keluar...\n");
        else printf("Pilihan tidak valid.\n");

    } while (pilih != 0);

    return 0;
}