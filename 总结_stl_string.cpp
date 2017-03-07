#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> v;
int main(){
    string st = "123";
    cout << st << endl;
    string::iterator it = st.begin();
    reverse(it, it + 2);
    cout << st << endl;
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(8);
    v.push_back(9);
    vector<int>::iterator vt = v.begin();
    reverse(vt, vt + 3);
    for( ; vt != v.end() ; vt++)
    cout << *vt << endl;
    st = "1/2/3/4/5/6";
    cout << st << endl;
    int p = st.find('/', 2);
    cout << p << endl;
    cout << (string::npos == -1) << endl;



    // find all '/'
    p = st.find('/');
    while(p != -1){
        cout << "/ has been find in pos " << p << endl;
        p = st.find('/', p + 1);
    }


    // replace ;
    st = "0123456789";




    //replace(pos, len,new value);
    cout << st << endl;
    st.replace(9, 10, "new string");


    //replace (begin(), end(), new value);
    string::iterator a = st.begin();
    string::iterator b = st.begin() + 4;
    cout << "brefore replace :" << endl;
    cout << st << endl;
    st.replace(a, b, "new value");
    cout << "after replace :" << endl;
    cout << st << endl;



    //replace all

    //find all substring "123" in st
    //and replace them with new string "456"
    st = "123123123123";
    p = st.find("123");
    while(p != -1){
        st.replace(p, 3, "456");
        cout << st << endl;
        p = st.find("123", p + 1);
    }
    cout << st << endl;

    int pos[size] = {-1};
    int t = 0;
    st = "123123123";
    p = st.find("123");


    //fist find all places;
    while(p != -1){
        pos[t++] = p;
        p = st.find("123", p + 1);
    }







    return 0;
}
