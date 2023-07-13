#include<bits/stdc++.h>
using namespace std;
vector<int> st;
void push(int &top, int element){
    top++;
    st[top] = element;
}
int pop(int &top){
    top--;
    return st[top];
}
int main(){
    int n = 10;
    st = vector<int>(n,0);
    int top = -1;
    push(top, 4);
    push(top, 8);
    push(top, 2);
    
    pop(top);
    for(int i=0;i<top+1;i++){
        cout<<st[i]<<endl;
    }
}
