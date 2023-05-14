#include<iostream>
#include<fstream>

using namespace std;

class TrieNode{
	
	public:
		
		TrieNode *links[52];
		int frequency;
		int word_count;
	
		TrieNode(){
			frequency = 0;
			
			
			for(int i = 0; i < 52; i++)
			links[i] = NULL;
		}
		
		bool ispresent(char c)
		{
		 return (c >= 'a') ?  links[c - 'a' + 26] != NULL : links[c - 'A'] != NULL;
        }
     	
		void put(char c)
		{
		  TrieNode * node = new TrieNode();
		 (c >= 'a') ?  links[c - 'a' + 26] = node : links[c - 'A'] = node;	
		}
		
		TrieNode * move(char c){
			return (c >= 'a') ?  links[c - 'a' + 26]: links[c - 'A'];
		}
		
		void setfreq(){
			frequency++;
		}
		
		int getfreq(){
			return frequency;
		}	
};

class Trie{
		
	public:
		TrieNode * root;
		int word_count;
		
		Trie(){
			root = new TrieNode() ;
			word_count = 0;
		}
		
		void insert(string word){
			TrieNode * node = root;
			
			for(int i = 0; i < word.length(); i++)
			{
				if(!node->ispresent(word[i]))
					node->put(word[i]);
					
				node = node->move(word[i]);
			} 
			node->setfreq();
			word_count++;
		}
		
		int search(string word){
			TrieNode * node = root;
			
			for(int i = 0; i < word.length(); i++)
			{
				if(!node->ispresent(word[i]))
				return false;
				
				node = node->move(word[i]);
			}
			
			return node->getfreq();
		}
		
		int calculate_height(TrieNode * node){
			
			if(node == NULL)
			return 0;
			
			int max_height = 0;
			for(int i = 0; i < 52; i++)
			{
				int cur_height = calculate_height(node->links[i]);
				
				if(cur_height > max_height)
				max_height = cur_height;
				
			}
			
			return 1 + max_height;
			
		}
		
		int getword_count(){
			return word_count;
		}
		
};

int main(){
	Trie trie;
	string s;
	ifstream filetovar;
	
	filetovar.open("words_alpha.txt");
	
	while(filetovar>>s)
	trie.insert(s);
	
	filetovar.close();
	ifstream tosearch;
	
	int ch=0;
	do{
	cout<<":: Trie Menu ::"<<endl;
	cout<<"1.Insert"<<endl;
	cout<<"2.Search"<<endl;
	cout<<"3.Height"<<endl;
	cout<<"4.Word Count"<<endl;
	cout<<"5.Search by file"<<endl;
	cout<<"Enter your choice : ";
	cin>>ch;
	cout<<endl;
	
	switch(ch){
		case 1:
		        cout<<"Enter the word : ";
		    	cin>>s;
		    	trie.insert(s);
		    	break;
		case 2:
			    cout<<"Enter the word : ";
			    cin>>s;
			    if(trie.search(s)) cout<<"Word is present with frquency "<<trie.search(s)<<endl;
			    else cout<<"Word not found"<<endl;
			    break;
	    case 3:
	    	    cout<<"Height : "<<trie.calculate_height(trie.root)<<endl;
	    	    break;
	    case 4:
	    		cout<<"Word Count : "<<trie.getword_count()<<endl;
	    	    break;
	    case 5:
	    	    tosearch.open("search.txt");
	    	    
	    	    while(tosearch>>s)
	    	    {
	    	    	cout<<":: "<<s<<"-> ";
	    	    	
	    	    	if(trie.search(s)) cout<<" is present with frequency "<<trie.search(s)<<endl;
			    	else cout<<" not found"<<endl;
			    	cout<<endl;
				}
				tosearch.close();
				break;
	    default:
	    	    cout<<"Invalid Option"<<endl;
	    	    break;
	}
	
	cout<<"Do you wish to perform more operations(press 1)"<<endl;
	cin>>ch;
    }while(ch==1);
    
	return 0;
}












