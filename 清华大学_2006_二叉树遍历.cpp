#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
string p_order, i_order;
void get_tree_from_order(string p_order, string i_order){
    int l = p_order.length();
    if(l > 0){
        char index = p_order[0];
        int i = 0;
        while(i < l){
            if(i_order[i] == index)
            break;
            i++;
        }
//        cout << "i = " << i << endl;
        get_tree_from_order(p_order.substr(1, i),i_order.substr(0, i));
        get_tree_from_order(p_order.substr(i + 1),i_order.substr(i + 1));
        cout << index;

    }

}
int main(){

    while(cin >> p_order >> i_order){
        get_tree_from_order(p_order, i_order);
        cout << endl;

    }

    return 0;
}
