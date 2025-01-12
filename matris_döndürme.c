#include <stdio.h>
#include <stdlib.h>


void matrisYazdir(int matris[10][10], int N){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            printf(" %d ", matris[i][j]);

    }
    printf("\n");
  }
}

void matrisSoladondur(int matris[10][10], int N){
    int yenimatris[10][10];
  for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            yenimatris[N-j-1][i]=matris[i][j];
    }
  }
    matrisYazdir(yenimatris, N);
}


void matrisSagadondur(int matris[10][10], int N){
    int yenimatris[10][10];
  for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            yenimatris[j][N-i-1]=matris[i][j];
    }
  }
    matrisYazdir(yenimatris, N);
}

int main()
{
 int N,i,j,yon;
 int matris[10][10];

 printf("Matrisin boyutunu giriniz(N): ");
 scanf("%d",&N);

 printf("Matrisin elemanlarini giriniz:\n");
   for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
        printf("Matris[%d][%d]: ",i, j);
        scanf("%d",&matris[i][j]);
    }
   }
 printf("Matris hangi yonde dondurulsun(1:Saga veya 2:Sola): ");
 scanf("%d", &yon);

 if(yon==1){
    printf("Matrisin saga dondurulmus hali:\n");
    matrisSagadondur(matris,N);
     }else if(yon==2){
     printf("Matrisin sola dondurulmus hali:\n");
     matrisSoladondur(matris,N);
     }else{
     printf("Gecersiz yon!\n");
     }

    return 0;
}
