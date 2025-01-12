
#include <stdio.h>
#include <stdlib.h>


typedef enum {
    G_2G = 0x00,
    G_4G = 0x01,
    G_8G = 0x02,
    G_16G = 0x03
} ivmeAraligi;

typedef enum {
    BW_7_81Hz = 0x00,
    BW_15_63Hz = 0x01,
    BW_31_25Hz = 0x02,
    BW_62_5Hz = 0x03
} bantGenisligi;

typedef enum {
    MODE_NORMAL = 0x00,
    MODE_LOW_POWER = 0x01,
    MODE_SUSPEND = 0x02
} islemModu;


typedef struct {
    ivmeAraligi aralik;
    bantGenisligi bantGenisligi;
    islemModu mod;
    unsigned char ivmeKonfigurasyonDegeri;
} IMUKonfigurasyonu;



unsigned char ivmeKonfigurasyonDegeriHesapla(ivmeAraligi aralik, bantGenisligi bw, islemModu mod) {
    return (aralik << 6) | (bw << 4) | mod;
}


void binaryYazdir(unsigned char deger) {
    for (int i = 7; i >= 0; i--) {
        printf("%c", (deger & (1 << i)) ? '1' : '0');
    }
    printf("\n");
}

int main() {

    IMUKonfigurasyonu imu = {G_4G, BW_31_25Hz, MODE_NORMAL, 0};


    imu.ivmeKonfigurasyonDegeri = ivmeKonfigurasyonDegeriHesapla(imu.aralik, imu.bantGenisligi, imu.mod);


    printf("Ondalik: %d\n", imu.ivmeKonfigurasyonDegeri);
    printf("Hexadecimal: 0x%X\n", imu.ivmeKonfigurasyonDegeri);
    printf("Binary: ");
    binaryYazdir(imu.ivmeKonfigurasyonDegeri);

    return 0;
}
