#include<iostream>
#include<string>
using namespace std;
string mon_dict[] = {"","January", "February", "March", "April", "May", "June",
"July", "August", "September", "October", "November", "December"};
string week_dict[] = {"Monday", "Tuesday", "Wednesday",
"Thursday", "Friday", "Saturday","Sunday"};
int mon2int(string mon){
  for(int i = 0 ; i < 13 ; i++)
    if(mon == mon_dict[i])
    return i;
  return 1;
}
int main(){
int y,m,d,w;
string mon;
while(cin >> d >> mon >> y){
  m = mon2int(mon);
  // cout << " m = " << m << endl;
  if(m<3){
    m+=12;
    y-=1;
  }
  w = (y + y / 4 + y / 400 - y / 100 + 2 * m + 3 * (m + 1) / 5 + d) % 7;
  cout<<week_dict[w]<<endl;
  }


}
