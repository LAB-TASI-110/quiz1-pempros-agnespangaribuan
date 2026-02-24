#include <stdio.h>
#include <string.h>

int main() {

    char kode[10];
    int porsi;
    int harga = 0;
    int subtotal;
    int total = 0;

    printf("Menu\t\t\tPorsi\tHarga\tTotal\n");
    printf("==============================================\n");

    while (1) {

        scanf("%s", kode);

        if (strcmp(kode, "END") == 0) {
            break;
        }

        scanf("%d", &porsi);

        if (strcmp(kode, "NGS") == 0) {
            harga = 15000;
            printf("Nasi Goreng Spesial\t");
        }
        else if (strcmp(kode, "AP") == 0) {
            harga = 20000;
            printf("Ayam Penyet\t\t");
        }
        else if (strcmp(kode, "SA") == 0) {
            harga = 25000;
            printf("Sate Ayam\t\t");
        }
        else if (strcmp(kode, "BU") == 0) {
            harga = 18000;
            printf("Bakso Urat\t\t");
        }
        else if (strcmp(kode, "MAP") == 0) {
            harga = 15000;
            printf("Mie Ayam Pangsit\t");
        }
        else if (strcmp(kode, "GG") == 0) {
            harga = 15000;
            printf("Gado-Gado\t\t");
        }
        else if (strcmp(kode, "SAY") == 0) {
            harga = 17000;
            printf("Soto Ayam\t\t");
        }
        else if (strcmp(kode, "RD") == 0) {
            harga = 25000;
            printf("Rendang Daging\t\t");
        }
        else if (strcmp(kode, "IB") == 0) {
            harga = 35000;
            printf("Ikan Bakar\t\t");
        }
        else if (strcmp(kode, "NUK") == 0) {
            harga = 20000;
            printf("Nasi Uduk Komplit\t");
        }

        subtotal = harga * porsi;
        total = total + subtotal;

        printf("%d\t%d\t%d\n", porsi, harga, subtotal);
    }

    // Hitung diskon
    int diskon_persen = 0;

    if (total >= 500000) diskon_persen = 25;
    else if (total >= 400000) diskon_persen = 20;
    else if (total >= 300000) diskon_persen = 15;
    else if (total >= 200000) diskon_persen = 10;
    else if (total >= 100000) diskon_persen = 5;

    int diskon = total * diskon_persen / 100;
    int total_bayar = total - diskon;

    printf("==============================================\n");
    printf("Total : %d\n", total);
    printf("Diskon : %d\n", diskon);
    printf("Total Pembayaran : %d\n", total_bayar);

    return 0;
}