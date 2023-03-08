#include<iostream>
#include<math.h>
using namespace std;

class node{
	public :
		int data;
		node* link;
};

class list{
	node* first;
	public:
		list(){
			first=NULL;
		}
		
		bool isEmpty()
		{
			if(first==NULL)
				return true;
			else return false;
		}
		
		void insert(int x, int index)
		{
			if(index<0||index>getsize())
			{
				cout<<"Invalid Index"<<endl;
				exit(0);
			}
			node *newnode=new node();
			newnode->data=x;
			newnode->link=NULL;
			if(index==0)
			{
				newnode->link=first;
				first=newnode;
				
			}
			else
			{
				node *prev=first;
				for(int i=1;i<=index;i++)
				    prev=prev->link;
				
				newnode->link=prev->link;
				prev->link=newnode;
			}
			
		}
		
		int del(int index)
		{
			if(first==NULL)
			{
			   cout<<"List is empty.Deletion Failed"<<endl;
			   exit(0);
		    }
			
			if(index<0|| index>=getsize())
			{
				cout<<"List is empty.Deletion Failed"<<endl;
			    exit(0);
			}
			
			int x;
			node *dl;
			if(index==0)
			{
				dl=first;
				x=dl->data;
				first=dl->link;
			}
			else{
				node *prev=first;
				for(int i=1;i<=index;i++)
				    prev=prev->link;
				dl=prev->link;
				x=dl->data;
				prev->link=dl->link;
			}
			dl->link=NULL;
			delete(dl);
			return x;
		}
		
		int getsize()
		{
			int n=0;
			node *cur=first;
			while(cur!=NULL)
			{
				n++;
				cur=cur->link;
			}
			
			return n;
		}
	
};

void read(int a[],int n)
{
	cout<<"Enter "<<n<<" positive integers:"<<endl;
	for(int i=0;i<n;i++)
	    cin>>a[i];
}

void print(int a[],int n)
{
	cout<<endl<<"The List is [";
	for(int i=0;i<n;i++)
	    cout<<a[i]<<",";
	cout<<"\b\b]";
}

int max(int a[],int n)
{
	int mx=a[0];
	for(int i=1;i<n;i++)
	    if(a[i]>mx) 
		    mx=a[i];
	return mx;
}

void radixsort(int a[],int n)
{   
    int mx=max(a,n);
	int digits = log10(mx) + 1;
	list l[10];
	int x=0;
	for(int i=0;i<digits;i++)
	{
		for(int j=0;j<n;j++)
		{
			x=((int(a[j]/pow(10,i)))%10);
			l[x].insert(a[j],0);
		}
		
		int k=0;
		
		for(int t=0;t<10;t++)
		{
			while(l[t].isEmpty()==false)
			{
				a[k++]=(l[t].del((l[t].getsize())-1));
				
			}
			
		}	
	}	
}

int main(){
	int n;
	cout<<"How many integer:"<<endl;
	cin>>n;
	int a[n];
	read(a,n);
	
	cout<<endl<<"Befor Sorting:"<<endl;
	print(a,n);
	
	radixsort(a,n);
	cout<<endl<<"After Sorting:"<<endl;
	print(a,n);
	
	return 0;
}