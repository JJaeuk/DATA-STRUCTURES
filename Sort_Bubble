// Sort - Bubble Sort(버블정렬)

#include <stdio.h>
void bubble_sort(int a[], int cnt){
    int i, j, tmp, flag;
    int ccc=0;
    for(i=0; i<cnt-1; i++){
        flag = 0;
        for (j=0; j<cnt-i-1; j++){
            if(a[j] > a[j+1]){  // 앞이 뒤보다 클경우 swap
                tmp = a[j];     // a[j]와 a[j+1] swap을 위한 임시보관함 tmp
                a[j] = a[j+1];
                a[j+1] = tmp;
                flag = 1;       
            }
        }
        if(flag==0) break;     // j loop 한바퀴 돌때 한번도 안걸렸으면 정렬 다된거니까 그냥 빠져나옴   근데 시간복잡도상으로 의미없음
    }
}

int main()
{
    int a[] = {66, 32, 88, 6, 47, 8, 91, 87, 64, 31};
    int i, cnt;
    
    cnt = sizeof(a)/sizeof(int);  // 배열a의 원소갯수 cnt
    bubble_sort(a,cnt);
    printf("\n Result of Sort : ");
    for(i=0; i<cnt; i++)
        printf("%4d", a[i]);
    

    return 0;
}
