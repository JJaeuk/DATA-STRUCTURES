// Sort - Merge Sort 1
/*
    반복 합병정렬 : 배열 a[10]를 정렬할건데, 배열 b[10]을 이용해 반복합병정렬 실시
                    단계수를 진행하면서 정렬된 서브리스트를 병합하여 더 큰 정렬된 서브리스트 생성
                    최종적으로 1개의 병합된 서브리스트가 될 때 까지 반복 수행
                        
*/
#include <stdio.h>
#define SIZE 10

void merge(int *a, int *b, int low, int mid, int cnt){
    int i, j, k, index;
    i = k = low;
    j = mid +1;
    while(i<=mid && j<=cnt){
        if(a[i] < a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    
    if(i>mid)
        for(index=j; index<=cnt; index++)
            b[k++] = a[index];
    else
        for(index=i; index<=mid; index++)
            b[k++] = a[index];
}


void merge_pass(int *a, int *b, int cnt, int len){    // 합병정렬의 1 pass 수행
    int i, j;
    for(i=0; i<=cnt-2*len; i+=2*len)                  // i=0부터 i=
        merge(a, b, i, i+len-1, i+2*len-1);         // 각 서브리스트 정렬
        
    if(i+len < cnt)
        merge(a, b, i, i+len-1, cnt-1);      
    else                                            // 서브리스트 수가 홀수개인 경우 마지막 서브리스트를 그냥 복사
        for(j=i; j<cnt; j++)
            b[j] = a[j];
}



void merge_sort(int *a, int cnt){
    int len = 1;        // 합병될 정렬리스트 크기(len = 1,2,4,8,...)

    int b[SIZE];        // 배열a크기의 배열b를 만듦
                        // pass 1에서는 배열a에서 len=1 크기의 정렬리스트로 합병되어 5개의 서브리스트 {a[0],a[1]}, {a[2],a[3]}, ......, {a[8],a[9]}로 나뉘며 배열b에 저장됨  <= 각각의 서브리스트는 정렬된 상태
                        // pass 2에서는 배열b에서 len=2 크기의 정렬리스트로 합병되어 3개의 서브리스트 {b[0],b[1],b[2],b[3]}, {b[4],b[5],b[6],b[7]}, {b[8],b[9]} 로 나뉘어 정렬되며 배열a에 저장됨
                        // pass 3에서는 배열a에서 len=4 크기의 정렬리스트로 합병되어 2개의 서브리스트 {b[0],b[1],b[2],b[3],b[4],b[5],b[6],b[7]}, {b[8],b[9]} 로 나뉘어 정렬되며 배열b에 저장됨
                        // pass 3에서는 배열b에서 len=8 크기의 정렬리스트로 합병되어 1개의 서브리스트 {b[0],b[1],b[2],b[3],b[4],b[5],b[6],b[7],b[8],b[9]} 로 정렬되며 배열a에 저장됨
                        // 서브리스트 수가 홀수개인 경우 마지막 서브리스트는 그냥 복사됨
    while(len<cnt){       
        merge_pass(a, b, cnt, len);        // 각 서브리스트가 배열 b에서 정렬됨
        len*=2;                            // len * 2
        merge_pass(b, a, cnt, len);        // 각 서브리스트가 배열 a에서 정렬됨
        len*=2;
    }
}


int main()
{
    int i, a[SIZE] = {3, 10, 21, 7, 30, 60, 50, 40, 5, 31};
    
    merge_sort(a, SIZE);
    
    printf("\n Result of Sort : ");
    for(i=0; i<SIZE; i++)
        printf("%3d",a[i]);
        
    return 0;
}
