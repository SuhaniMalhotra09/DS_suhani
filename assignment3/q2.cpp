int main(){
	vector <int> S;
	String rev="";
	String word="Data";
	int len=word.length();
	for(int i=0;i<len;i++){
		push(S,word[i])
	}
	 while (!isEmpty(S)) {
        char ch = pop(S);
        if (ch != '\0') {
            rev += ch;
        }
    }
	cout<<rev;
	
	
	return 0;
}
