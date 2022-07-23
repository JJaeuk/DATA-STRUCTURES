// sort - Insertion Sort(삽입정렬)

#include <stdio.h>

void insert_sort(int a[], int cnt){
    int i, j, k;
    
    for(i=1; i<cnt; i++){               // 일단 두번째원소부터 start. 
        k = a[i];                       // k에는 a[i]의 원소 (두번째부터 끝까지 들어가봄) ... 앞이랑 비교해서 옮겨지게 될 경우 대비
        j = i-1;                        // j는 i-1로 시작
        while(j>=0 && k<a[j]){          // j가 0보다 작으면 이미 제일 앞에 온거.  j보다 뒤에 위치했던 k가 a[j]보다 작으면 a[j]값을 한칸 뒤로 보냄
            a[j+1] = a[j];              // 뒤에 더 작은 수가 있으면 한칸 앞으로 보내줌 -> a[j] 자리에 있던걸 a[j+1]로 보냄    -> a[j] 값이 의미없는 상태
            j--;                        // 앞으로 땡겨서 앞에 더 큰 수가 있나 확인
        }
                                        // 다돌았지? 제일 작은수는 제일 앞에 와있음
        a[j+1] = k;                     // 제일 앞에다가 최솟값 집어넣음
    }
}

                                        //  3 5 2 9 8    ->  3보다 5가 커서 i=1 패스.. while 안돌면 배열은 그대로임  k=a[i];  j=i-1;  a[j+1] = k;  --> a[i]=a[i]
                                        //  i=2일때 일단 k=a[2]=2 저장해두고, (a[j=1])5가 2보다 커서(k<a[j])  5를 한칸뒤에 저장 -> 3 5 5 9 8  
                                        //                                  한칸 앞으로 와보니(j=0) 3도 2보다 커서 3을 한칸 뒤에 저장 -> 3 3 5 9 8
                                        //                                  한칸 앞으로 와보니(j=-1) while 못들어감 -> a[j+1] 자리(a[0])에 k 저장 -> 2 3 5 9 8
                                        //   ~~~ i<cnt까지 반복

int main()
{
    int a[] = {3, 5, 2, 9, 8};
    int i, cnt;
    
    cnt = sizeof(a)/sizeof(int);
    insert_sort(a,cnt);
    
    printf("\n Result of Sort : ");
    for(i=0; i<cnt; i++)
        printf("%3d",a[i]);
        
        
    return 0;
}
