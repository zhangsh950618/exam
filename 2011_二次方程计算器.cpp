#include<fstream>
#include<iostream>
#include<math.h>
#include<string.h>
#include<cstdio>
using namespace std;
ifstream fin("1.in");
// ofstream cout("1.out");




int str2num(string str,int s,int e){
  int sum = 0;
  for(int j = s ; j <= e ; j++){
    sum *= 10;
    sum += (str[j] - '0');
  }
  if(sum == 0)
    return 1;
  return  sum;
}
int is_num(char a){
  if(a >= '0' && a <= '9'){
    return 1;
  }else{
    return 0;
  }
}



int main(){
  string str;
  while (fin >> str) {
    cout << str << endl;
    int a = 0,b = 0,c = 0;
    //利用公式法
    int len = str.length();
    //在等号左侧则表示与原来的符号相同
    //在等号右侧则与原来的符号相反
    int flag = 1;
    for(int i = 0  ; i < len ; i++){

      if(str[i] == 'x'){
        //判断二次项前面的系数
        if(i + 1 < len && str[i + 1] == '^'){
            int e = i - 1;
            while(e>=0 && is_num(str[e]))
              e--;
            int s = e + 1;
            cout << " s = " <<s <<" e = " << e << endl;
            int temp_a = str2num(str,s,e);
            if(e < 0 || str[e] == '+' || str[e] == '='){
                temp_a = temp_a;
            }else{
                temp_a = -temp_a;
            }
            if(flag){
              a += temp_a;
            }else{
              a -= temp_a;
            }
        //剩下的必然是一次项
        }else{




        }




      }else if(str[i] == '='){
        //如果是等号右侧，将flag翻转
        flag = 0;

      }


    }
    cout << a << endl;
    // int d = pow(b,2) - 4 * a * c;
    //
    // //d < 0 表示无解
    // if(d < 0){
    //   cout << "No Solution" << endl;
    // }else{
    //   int x1 = (-b - sqrt(d))/ (2 * a);
    //   int x2 = (-b + sqrt(d))/ (2 * a);
    //   printf("%.2f %.2f\n",x1,x2);
    // }

  }
}
