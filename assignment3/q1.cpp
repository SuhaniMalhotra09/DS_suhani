#include <iostream>
using namespace std;

stack push(Stack S,int ele){
	if(isFull(S)){
	
	cout<<"overflow";
}
	else{
		++S.top;
		S.element[S.top]=ele;
	}
	return S;

}
stack pop(Stack S,String rev){
	if(isEmpty(S)){
		cout<<"underflow";
	}
		else{
		
			int ele=S.element[S.top];
			S.top--;
		}
		for(int i=0;i<rev.length();i++){
			rev=S.top[i];
		}
		return rev;
	
}
void display(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack elements: ";
        for (int i = S.top; i >= 0; i--) {
            cout << S.element[i] << " ";
        }
        cout << endl;
    }
}
int peek(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack is empty" << endl;
        return -1; 
    } else {
        return S.element[S.top];  
    }
}
