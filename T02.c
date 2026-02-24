#include <stdio.h>

int main() {
    int N, K;
    int nilai_awal;
    
    printf("Masukkan jumlah data: ");
    scanf("%d", &N);
    
    printf("Masukkan nilai pertama: ");
    scanf("%d", &nilai_awal);
    
    printf("Masukkan kode kelompok: ");
    scanf("%d", &K);
    
    int nilai[N];
    
    // Bentuk deret berdasarkan pola -10, +15
    nilai[0] = nilai_awal;
    for(int i = 1; i < N; i++) {
        if(i % 2 == 1)
            nilai[i] = nilai[i-1] - 10;
        else
            nilai[i] = nilai[i-1] + 15;
    }
    
    // Hitung batas kelompok
    int awal = K * (K - 1) / 2;
    int akhir = K * (K + 1) / 2 - 1;
    
    if(awal >= N) {
        printf("Kelompok tidak tersedia.\n");
        return 0;
    }
    
    if(akhir >= N)
        akhir = N - 1;
    
    // Hitung total
    int total = 0;
    for(int i = awal; i <= akhir; i++) {
        total += nilai[i];
    }
    
    printf("Total nilai kelompok %d = %d\n", K, total);
    
    return 0;
}