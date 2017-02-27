#include<iostrmea>
#include<string.h>
#include<math.h>
using namespace std;
const int maxn  = 100;
int n;
int number[maxn];

//
int get_dig(int num, int d){
    int index = pow(d - 1, 10);
    cout << "index = " << index << endl;
    return num/index%10;
}

void radix_sort(){
    int c[maxn] = {0};
    int bucket[maxn] = {0};
    //最大的位数为3所以排3次
    for(int k = 1 ; k <= 3 ; k++){
        memset(c, 0, sizeof(c));
        for(int i = 0 ; i < n ; i++){
            int t = getdigit(number[i], k);
            c[t]++;
        }

        for(int i = 1 ; i < 10 ; i++) c[t] += c[t - 1];

        for(int i = n - 1 ; i >= 0 ; i--){
            int t = getdigit(number[i], k);
            bucket[c[t] - 1] = index[i];
            c[t]--;
        }

        for(int i = 0 , j = 0 ; i < n ;i++, j++) number[i] = bucket[j];


    }

}
int main(){
    while( cin >> n){

        for(int i = 0 ; i < n ; i++)
        cin >> number[i];
        radix_sort();
    }
    return 0;
}
