#include<iostream>
using namespace std;

void read(int **a, int n)
{
	cout<<"Enter the non zero elements"<<endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<(n-i);j++)
		{
			cout<<"a["<<i<<"]["<<j+i<<"]="<<endl;
			cin>>a[i][j];
		}
	}
	
}

void readDM(int *b,int n)
{
	cout<<"Enter the non zero elements"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"b["<<i<<"]["<<i<<"]="<<endl;
		cin>>b[i];
		
	}
}

void print(int **a,int n)
{
	cout<<"UTN"<<endl;
	for(int i=0;i<n;i++)
  {
    	for(int j=0;j<n;j++)
    	{
	    	if(j>=i)
		    cout<<a[i][j-i]<<" ";
		    else
		    cout<<0<<" ";
		}
	    cout<<endl;
  }
}


void printDM(int *b,int n)
{
	cout<<"DM"<<endl;
	for(int i=0;i<n;i++)
  {
    	for(int j=0;j<n;j++)
    	{
	    	if(j==i)
		    cout<<b[i]<<" ";
		    else
		    cout<<0<<" ";
		}
	    cout<<endl;
  }
}

int **mul(int **a,int *b, int n)
{
	int **c= new int*[n];
	for(int i=0;i<n;i++)
	c[i]=new int(n-i);
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<(n-i);j++)
		{
			c[i][j]=a[i][j]*b[j+i];
		}
	}
	
	return c;
}







int main()
{
	int n;
	cout<<"Enter the order"<<endl;
	cin>>n;
	
	int **a=new int *[n];
	for(int i=0;i<n;i++)
	a[i]=new int(n-i);
	
	read(a,n);
	print(a,n);
	
	int *b=new int [n];
	
	readDM(b,n);
	printDM(b,n);
	
	int **res=mul(a,b,n);
	print(res,n);
		
	return 0;
}