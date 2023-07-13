#include<bits/stdc++.h>
using namespace std;
vector<int> q;
int front=-1, rear = -1;
void push(int element){
    if(rear == q.size()-1){
        cout<<"queue is full"<<endl;
        return;
    }
    if(front == -1) front = 0;
    rear ++;
    q[rear] = element;
}

void pop(){
   if(front == -1 || front>rear){
       cout<<"queue is empty"<<endl;
       return;
   }
   front++;
}
int main(){
    int n = 10;
    q = vector<int>(n,0);
   
   push(5);
   push(10);
   push(15);
   
   pop();
   pop();
   
   push(21);
   
    for(int i=front;i<=rear;i++){
        cout<<q[i]<<endl;
    }
}
