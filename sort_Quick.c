// Sort - Quick Sort
/*
    quick sort(퀵정렬)은 1. 배열의 맨 앞에있는 값을 key(제어키)로 두고  <- 맨뒤의값을 제어키로 해도 됨
                         2. a피봇은 배열의 앞에서 뒤로가며(++i) 제어키와 비교, 제어키보다 작은값이 있다면 멈춤 (오름차순정렬에서)
                         3. b피봇은 배열의 뒤에서 앞으로가며(--j) 제어키와 비교, 제어키보다 큰값이 있다면 멈춤 
                         4. a피봇과 b피봇 swap
                         5. 만약 a피봇의 인덱스가 b피봇의 인덱스와 겹치거나 커지면 swap하기전에 while문 멈춤
                        
*/
#include <stdio.h>

void quick_sort(int a[], int cnt){
    int i, j, key, tmp;             // a피봇의 인덱스 i, b피봇의 인덱스 j, 제어키 key, swap용 tmp
    if(cnt > 1){                    // 배열 크기가 1이면 정렬 끝난거라서 멈춰도 됨
        key = a[0];                 // 첫 제어키는 배열 맨처음으로 잡음(오름차순정렬)
        i = 0;                      // i=0이라고 해놓는데 밑에보면 a[++i]라서 a[1]부터 시작함
        j = cnt;                    // j=cnt면 배열 벗어나는데 밑에보면 a[--j]라서 배열끝에서 시작
        while(1){                   // break 걸릴때까지 계속돌려!
            while(a[++i] < key);    // a[i]가 key보다 작으면 계속돌려! -> 같거나 커지면 멈춤
            while(a[--j] > key);    // a[j]가 key보다 크면 계속돌려! -> 같거나 작아지면 멈춤
            if(i >= j)              // 위에 while 두개 돌리다가 a피봇의 인덱스가 b피봇의 인덱스보다 같거나 커지면 break
                break;
            tmp = a[i];             // break에 안걸리게 a피봇의 인덱스가 b피봇의 인덱스보다 작은 경우
            a[i] = a[j];            // a[i] 와 a[j] swap
            a[j] = tmp;
        }
        
        a[0] = a[j];                // while 끝나면 a[0]자리에 a[j]값 넣고 (a[j]는 key보다 작은 상태)
        a[j] = key;                 // a[j] 값엔 맨 앞의 값(기존에 제어키로 설정한 값)을 넣어라
        
        quick_sort(a,j);            // 제어키 기준으로 앞뒤 분할해서 다시 들어감. 먼저 a[0]부터 a[j-1] 퀵정렬
        quick_sort(a+j+1, cnt-j-1); // a[j+1]부터 a배열 끝까지 퀵정렬 (a[j]에는 이전 제어키 값이 들어가있음. 제어키 기준 앞에는 제어키보다 작고, 뒤에는 제어키보다 큼
                                    //                              두번째 인자는 원소갯수기 때문에 a[j+1]부터 끝까지가 cnt-j-1개임)
    }
}


int main()
{
    int a[] = {3, 10, 21, 7, 30, 60, 50, 40, 5, 31, 22, 19, 16,  2, 15, 9, 88, 47, 1, 16, 8};
    int i, cnt;                 
    
    cnt = sizeof(a)/sizeof(int);
    quick_sort(a,cnt);
    
    printf("\n Result of Sort : ");
    for(i=0; i<cnt; i++)
        printf("%3d",a[i]);
        
    return 0;
}
