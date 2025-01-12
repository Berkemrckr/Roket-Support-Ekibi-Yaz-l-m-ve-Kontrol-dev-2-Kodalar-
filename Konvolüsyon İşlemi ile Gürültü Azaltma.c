#include <stdio.h>
#include <stdlib.h>



void konvolusyon(int G[][100], int F[][100], int S[][100], int M, int N, int k) {
    for(int i = 0; i <= M - k; i++) {
        for(int j = 0; j <= N - k; j++) {
            int toplam = 0;

            for(int x = 0; x < k; x++) {
                for(int y = 0; y < k; y++) {
                    toplam += G[i + x][j + y] * F[x][y];
                }
            }
            S[i][j] = toplam / (k * k);
        }
    }
}

void matrisYazdir(int matris[][100], int M, int N) {
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            printf("%d ", matris[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int M, N, k;
    printf("Goruntu matrisin boyutlarini giriniz (M N): ");
    scanf("%d %d", &M, &N);

    int G[100][100];
    printf("Goruntu matrisinin elemanlarini giriniz:\n");
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &G[i][j]);
        }
    }

    printf("Filtre matrisinin boyutunu giriniz (k): ");
    scanf("%d", &k);

    int F[100][100];
    printf("Filtre matrisinin elemanlarini giriniz:\n");
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            scanf("%d", &F[i][j]);
        }
    }

    int S[100][100];
    konvolusyon(G, F, S, M, N, k);

    printf("Konvolusyon sonrasi elde edilen matris:\n");
    matrisYazdir(S, M - k + 1, N - k + 1);
    return 0;
}


