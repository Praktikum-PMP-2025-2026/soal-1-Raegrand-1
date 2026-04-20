 //   Modul               : 02 – Data Manipulation and External Files
 //   Hari dan Tanggal    : Senin, 20 April 2026
 //   Nama (NIM)          : Raegrand Archamadeus (13224014)
 //   Nama File           : soal1.c
 //   Deskripsi           : 

# include <stdio.h>
# include <stdlib.h>

int floor_keren(float n){
    if(n<0 && (n - (int)n) != 0) return ((int)(n))-1;
    else return (int)n;
}

int main(){
    int n; 
    int max = -999999;
    int boundCheck = 0;
    int status;// 0 = std, 1 = left, 2 = right, 3 = empty
    int up;
    int down;
    scanf("%d", &n);
    int sense[100];
    for(int i = 0; i<n; i++){
        scanf("%d", &sense[i]);
    }
    for(int i = 0; i < n; i++){
        if(sense[i] == -1){
            up = -1;
            down = -1;
            boundCheck = 0;
            status = 0;
            for(int j = i; j < n; j++){
                if(sense[j] != -1){
                    boundCheck = 1;
                    up = sense[j];
                    break;
                }
            }

            if(boundCheck == 0) status = 1;
            boundCheck = 0;
            for(int j = i; j >= 0; j--){
                if(sense[j] != -1){
                    boundCheck = 1;
                    down = sense[j];
                    break;
                }
            }
            
            if(boundCheck == 0 && status == 1)status = 3;
            else if (boundCheck == 0 && status == 0) status = 2;
            
            if (status == 0)sense[i] = floor_keren((float)(down + up)/2.0);
            else if(status == 1)sense[i] = down;
            else if(status == 2)sense[i] = up;
            else if(status ==3) sense[i] = 0;
        }
    }

    printf("RECOVERED");
    int temp = 0;
    for(int i = 0; i<n; i++){
        for(int j = i; j<n; j++){
            temp += sense[j];
            max = (temp > max)? temp: max;
        }
        temp = 0;
    }
    printf("\nMAX_SUM %d", max);
    return 0;
}