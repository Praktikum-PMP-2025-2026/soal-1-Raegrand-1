 //   Modul               : 02 – Data Manipulation and External Files
 //   Hari dan Tanggal    : Senin, 20 April 2026
 //   Nama (NIM)          : Raegrand Archamadeus (13224014)
 //   Nama File           : soal1.c
 //   Deskripsi           : 

# include <stdio.h>



int main(){
    int n; 
    int max = 0;
    scanf("%d", &n);
    int sense[100];
    for(int i = 0; i<n; i++){
        scanf("%d", &sense[i]);
    }
    for(int i = n-1; i >= 0; i--){
        if(sense[i] == -1){
            if(i == 0){sense[i] = sense[i+1];}
            else{
                sense[i] = (sense[i-1] == -1)? sense[i+1] : (sense[i+1]+sense[i-1])/2;
            }
        }
    }

    printf("RECOCVERED");
    for(int i = 0; i<n; i++){
        printf(" %d", sense[i]);
        max += sense[i];
    }
    printf("\nMAX_SUM %d", max);
    return 0;
}