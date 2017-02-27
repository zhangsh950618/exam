//基数排序
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int getdigit(int x,int d){
    int a[] = {1, 1, 10, 100};
    return (x/a[d])%10;
}

void PrintArr(int a[], int len){
    for(int i = 0; i < len; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void jishu_sort(int arr[], int from, int to, int d){
    const int radix = 10;
    int c[radix];
    int *bucket = new int[to-from+1];
    for(int k = 1; k <= d; ++k){  //有多少位排几次序
        for(int i = 0; i < radix; i++) c[i] = 0;  //清0
        for(int i = from; i <= to; i++) c[getdigit(arr[i], k)]++; //将该位对应的数字下标的位置增加1.
        for(int i = 1; i < radix; i++) c[i] += c[i-1]; //c[i]表示第i个桶的右边界索引
        //数据依次入桶
        for(int i = to; i >= from; i--){ //从右往左扫描，保证排序稳定性
            int j = getdigit(arr[i], k); //求出关键码的第k位数字
            bucket[c[j]-1] = arr[i];  //放入对应桶中，c[j]-1是第j个桶的右边界索引。
            --c[j]; //对应桶中装入数据索引减一
        }
        //注意此时c[i]为第i个桶左边界
        //从各个桶收集数据
        for(int i = from, j = 0; i <= to; i++,j++) arr[i] = bucket[j];  //
    }
    delete [] bucket;
}


int main(){
    int br[10] = {278, 109, 63, 930, 589, 184, 505, 269, 8, 83};
    cout << "inital digit" << endl;
    PrintArr(br, 10);
    jishu_sort(br, 0, 9, 3);
    cout << "after sort" << endl;
    PrintArr(br, 10);
    return 0;
}
