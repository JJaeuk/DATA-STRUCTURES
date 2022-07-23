// Sort - Selection Sort (선택정렬)

#include <stdio.h>

void selection_sort(int a[], int cnt){
    int i, j, k, min;
    
    for(i=0; i<cnt-1; i++){         
        k = i;                     // 최솟값의 위치 k
        min = a[i];                // 최솟값 min
        
        for(j=i+1; j<cnt; j++){     // i+1에서부터 배열끝까지 비교
            if(a[j] < min){         // 비교해서 min보다 작으면 바꿔야지
                k = j;              // 현재 최솟값(min)은 a[j]에 있으니까 최솟값의 위치 k = j
                min = a[j];         // 최솟값도 a[j]
            }    
        }
        
        a[k] = a[i];                // 최솟값 있던 a[k]엔 a[i] 넣어주고  a[i]엔 최솟값 넣어줌
        a[i] = min;                 // min이 tmp 역할 대신함 (원래는 a[i]와 a[k]를 tmp를 이용해 swap)
    }
}


int main()
{
    int a[] = {6, 2, 7, 4, 9};
    int i, cnt;
    
    cnt = sizeof(a)/sizeof(int);    // 배열 원소갯수 cnt
    selection_sort(a, cnt);
    printf("\n Result of Sort : ");
    for(i=0; i<cnt; i++)
        printf("%4d", a[i]);
}
