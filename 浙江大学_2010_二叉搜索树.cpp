#include<iostream>
#include<cstring>
using namespace std;
string p, t;
int n;
struct node{
    char c;
    bool has_mark;
    struct node* l;
    struct node* r;
};
node* create_node(){
    node* n = new node;
    n->c = 0;
    n->has_mark = false;
    n->l = NULL;
    n->r = NULL;
    return n;
}
void insert_node(node* root, char c){
    node* n = root;
    while(true){
        if(n->c > c){
            if(n->l != NULL) n = n->l;
            else {
                node* l = create_node();
                l->c = c;
                n->l = l;
                break;
            }
        }
        else{
            if(n->r != NULL) n = n->r;
            else {
                node* r = create_node();
                r->c = c;
                n->r = r;
                break;
            }
        }
    }
}
node* create_tree(string p){
    int len = p.length();
    if(len > 0){
        node* root = create_node();
        root->c = p[0];
        for(int i = 1 ; i < len ; i++)
        insert_node(root, p[i]);
        return root;
    }
}

void pre_order(node* root){
    if(root != NULL){
        root->has_mark = false;
        pre_order(root->l);
        pre_order(root->r);
    }

}
bool judge_node(node* root, char c){
    node* n = root;
    while(n->has_mark == true){
        if(n->c > c)n = n->l;
        else n = n->r;
    }
    if(n->c == c){n->has_mark = true; return true;}
    else return false;
}
bool judge_tree(node* root, string t){
    int len = t.length();
    for(int i = 0 ; i < len ; i++)
    if(judge_node(root, t[i]) == false) return false;
    return true;
}
int main(){
    while(cin >> n){
        if(n == 0) break;
        cin >> p;
        node* root = create_tree(p);
        pre_order(root);
        for(int i = 0 ;i < n ; i++){
            cin >> t;
            pre_order(root);
            if(judge_tree(root,t))cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}
