#include<iostream>
#include<string>

using namespace std;


int tockenise(string s, string t[])
{
	int n = s.length();
	int flag = 0;
	int k = 0;
	
	for(int i=0; i<n ;i++)
	{
		
		if( i < n && (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '(' || s[i] == ')') )
			t[k++] = s[i];
	    
	    
	    while(i < n && ( s[i] - '0' >= 0 &&  s[i] - '0' <= 9 ))
		{
			t[k] = t[k] + s[i];
			i++;
			flag = 1;	
		}
		
		if(flag) 
		{
			k++;
			i--;
			flag = 0;
		}
			    
	}
	
	return k;
}


int main(){
	string s;
	getline(cin,s);
	
	int n = s.length();
	string *t = new string[n];
	
	int last = tockenise(s,t);
	for(int i=0; i < last; i++)
	cout<<t[i]<<endl;
	
	
}