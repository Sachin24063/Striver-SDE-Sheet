#include <bits/stdc++.h> 
void solve(int element, stack<int>& stack){
	if(stack.size()==0 || stack.top()<element){
		stack.push(element);
	}
	else{
		int a = stack.top();
		stack.pop();
		solve(element, stack);
		stack.push(a);
	}
}
void sortStack(stack<int> &stack)
{
	if(stack.size()>0){
		int element = stack.top();
		stack.pop();
		sortStack(stack);
		solve(element, stack);
	}
}
