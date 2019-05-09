#include<iostream>
#include <bits/stdc++.h>
#include<string>
#include<fstream>

using namespace std;

class node{
	public:
		string data;
		node* next;
};
class stackk{
	deletestack()
	{
		if(head!=NULL)
		{
			node* temp;
			node* deleter;
			temp=head;
			while(temp!=NULL)
			{
				deleter=temp;
				temp=temp->next;
				delete [] deleter;
			}
			head->data="";
			head->next=NULL;
		}
		else
		{
			head->data="";
			head->next=NULL;
		}
	}
	public:
		node* head;
		int size;
	//CONSTRUCTOR
	stackk()							
	{
		size=0;
		head=NULL;
	}
	//INSERT AT FRONT
	void push(string d)			
	{
		//cout<<"Pushed value = "<<d<<endl;
		node* newnode=new node();
		newnode->data=d;
		if(head==NULL)
		head=newnode;
		else
		{
			newnode->next=head;
			head=newnode;
		}
		size++;
	}
	//RETURN AND REMOVE FROM FRONT
	string pop()
	{
		node* temp;
		temp= head;
		head=head->next;
		string value;
		temp->next=NULL;
		value=temp->data;
		size--;
		delete temp;
		//cout<<"Popped value = "<<value<<endl;
		return value;
	}
	//SIZE OF STACK
	int stacksize()
	{
		return size;
	}
	//RETURN TOP ELEMENT
	string top()
	{
		return(head->data);
	}
	//IS STACK EMPTY?
	bool isEmpty()
	{
		if(size==0)
		return 0;
		else
		return 1;
	}
	//DISPLAY STACK
	void display()
	{
		node* temp;
		temp=head;
		cout<<"List = ";
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}
	//DESTRUCTOR
	~stackk()
	{
		//deletestack();
	}
};

int searchNoun(string x)
{
	ifstream myFile;
	myFile.open("n.txt");
	if (!myFile) 
	{
		cout << "Unable to open file";
		//TERMINATE WITH ERROR
		exit(1); 
	}
	while(!myFile.eof())
	{
		string temp;
		while(getline(myFile,temp))
		{
			//IF MATCHED
			if(x.compare(temp)==0) 
			{
				myFile.close();
				return 1;
			}
		}
		myFile.close();
		return 0;	
	}
}

int searchVerb(string x)
{
	ifstream myFile;
	myFile.open("v.txt");
	if (!myFile) 
	{
		cout << "Unable to open file";
		//TERMINATE WITH ERROR
		exit(1); 
	}
	while(!myFile.eof())
	{
		string temp;
		while(getline(myFile,temp))
		{
			//IF MATCHED
			if(x.compare(temp)==0)
			{
				myFile.close();
				return 1;
			}
		}
		myFile.close();
		return 0;	
	}
}

int searchPronoun(string x)
{
	ifstream myFile;
	myFile.open("p.txt");
	if (!myFile) 
	{
		cout << "Unable to open file";
		//TERMINATE WITH ERROR
		exit(1); 
	}
	while(!myFile.eof())
	{
		string temp;
		while(getline(myFile,temp))
		{
			//IF MATCHED
			if(x.compare(temp)==0)
			{
				myFile.close();
				return 1;
			}
		}
		myFile.close();
		return 0;	
	}
}

int searchPropernoun(string x)
{
	ifstream myFile;
	myFile.open("pn.txt");
	if (!myFile) 
	{
		//TERMINATE WITH ERROR
		cout << "Unable to open file";
		exit(1); 
	}
	while(!myFile.eof())
	{
		string temp;
		while(getline(myFile,temp))
		{
			//IF MATCHED
			if(x.compare(temp)==0)
			{
				myFile.close();
				return 1;
			}
		}
		myFile.close();
		return 0;	
	}
}

int searchDeterminal(string x)
{
	ifstream myFile;
	myFile.open("d.txt");
	if (!myFile) 
	{
		//TERMINATE WITH ERROR
		cout << "Unable to open file";
		exit(1);
	}
	while(!myFile.eof())
	{
		string temp;
		while(getline(myFile,temp))
		{
			//IF MATCHED
			if(x.compare(temp)==0)
			{
				myFile.close();
				return 1;
			}
		}
		myFile.close();
		return 0;	
	}
}

int searchPreposition(string x)
{
	ifstream myFile;
	myFile.open("pp.txt");
	if (!myFile) 
	{
		//TERMINATE WITH ERROR
		cout << "Unable to open file";
		exit(1); 
	}
	while(!myFile.eof())
	{
		string temp;
		while(getline(myFile,temp))
		{
			//IF MATCHED
			if(x.compare(temp)==0)
			{
				myFile.close();
				return 1;
			}
		}
		myFile.close();
		return 0;	
	}
}

int searchConjunction(string x)
{
	ifstream myFile;
	myFile.open("c.txt");
	if (!myFile) 
	{
		cout << "Unable to open file";
		//TERMINATE WITH ERROR
		exit(1); 
	}
	while(!myFile.eof())
	{
		string temp;
		while(getline(myFile,temp))
		{
			//IF MATCHED
			if(x.compare(temp)==0)
			{
				myFile.close();
				return 1;
			}
		}
		myFile.close();
		return 0;	
	}
}

int main()
{
	//HEADING
	cout<<"\t\tTheory of Automata - ASSIGNMENT 2\n\n";
        
  	// INITIALIZING VARIABLE
	string sentence;
	string words[20];
	
	int nCount=0,vCount=0,pCount=0,pnCount=0,dCount=0,ppCount=0,cCount=0,wCount=0;
	string nArr[10],vArr[10],pArr[10],pnArr[10],dArr[10],ppArr[10],cArr[10];
	
	
	//sentence="a boy adopt";
	getline(cin,sentence);
//	if(sentence.empty() || sentence==" ")
//	{
//		cout<<"Valid: ";
//		return 1;
//	}
  
	//SEPERATING SENTENCE INTO WORDS
	//USED TO SPLIT SENTENCES AROUND SPACES
	istringstream ss(sentence); 
    do
	{
        string word;
        ss >> word;
        words[wCount++]=word;
    }while (ss);
    
    wCount--;
    cout<<"Word count is = "<<wCount<<endl;
    
  	//for(int i=0;i<10 && words[i]!="";i++)
	//cout<<words[i]<<" ";
	//cout<<endl;
	
	//FILLING APPROPRIATE ARRAY WITH THEIR WORDS
	for(int i=0;i<10 && words[i]!="";i++)
	{
		
		if(searchNoun(words[i])==1)
		{
			//cout<<"\nNouns---";
			nArr[nCount]=words[i];
			//cout<<endl<<words[i];
			nCount++;
		}
		
		if(searchVerb(words[i])==1)
		{
			//cout<<"\nVerbs---";
			vArr[vCount]=words[i];
			//cout<<endl<<words[i];
			vCount++;
		}
		
		if(searchPronoun(words[i])==1)
		{
			//cout<<"\nPronouns---";
			pArr[pCount]=words[i];
			//cout<<endl<<words[i];
			pCount++;
		}
		
		if(searchPropernoun(words[i])==1)
		{
			//cout<<"\nProperNouns---";
			pnArr[pnCount]=words[i];
			//cout<<endl<<words[i];
			pnCount++;
		}
		
		if(searchDeterminal(words[i])==1)
		{
			//cout<<"\nDeterminal---";
			dArr[dCount]=words[i];
			//cout<<endl<<words[i];
			dCount++;
		}
		
		if(searchPreposition(words[i])==1)
		{
			//cout<<"\nPreposition---";
			ppArr[ppCount]=words[i];
			//cout<<endl<<words[i];
			ppCount++;
		}
		
		if(searchConjunction(words[i])==1)
		{
			//cout<<"\nConjunction---";
			cArr[cCount]=words[i];
			//cout<<endl<<words[i];
			cCount++;
		}
	}
	cout<<endl;
	
	
	//STACK OPERATIONS
	stackk cfg,nps,vps;
	string start="S",np="NP",vp="VP",pr="Pronoun",pn="ProperNoun",d="Determiner",n="Noun",v="Verb",pp="Preposition";
	int i=0;
	
	cfg.push(start);
	cfg.display();
	
	cfg.pop();
	cfg.push(vp);
	cfg.push(np);
	cfg.display();
	
	if(cfg.pop()==np)
	{
		//CHECKING PRONOUN
		for(int j=0;j<pCount;j++)
		//PRONOUN FOUND		
		if(words[i]==pArr[j])
		{
			cfg.push(pr);						
			i++;
			break;
		}
		if(cfg.top()!=pr)
		//CHECKING PROPERNOUN			
		for(int j=0;j<pnCount;j++)
		//PROPERNOUN FOUND
		if(words[i]==pnArr[j])
		{
			cfg.push(pn);					
			i++;
			break;
		}
		if(cfg.top()!=pr && cfg.top()!=pn)
		// CHECKING DETERMINAL
		for(int j=0;j<dCount;j++)				
		{	
			//DETERMINAL FOUND
			if(words[i]==dArr[j])
			{
				cfg.push(d);				
				i++;
				//CHECKING NOUNS | NOUN NOMINAL
				for(int j=0;j<nCount;j++)					
				{
					// 3 NOUNS FOUND
					if(words[i]==nArr[j] && words[i+1]==nArr[j+1] && words[i+2]==nArr[j+2]  && i+2 < wCount) 
					{
						cfg.push(n);
						cfg.push(n);
						cfg.push(n);
						i=i+3;
						break;
					}
					//2 NOUNS FOUND
					else if(words[i]==nArr[j] && words[i+1]==nArr[j+1] && i+1<wCount)						
					{
						cfg.push(n);
						cfg.push(n);
						i=i+2;
						break;
					}
					//1 NOUN FOUND
					else if(words[i]==nArr[j] && i<wCount)												
					{
						cfg.push(n);
						i++;
						break;
					}
					//NO NOUN FOUND
					else																
					{
						cout<<"Invalid Sentence !! :_(";
						return 0;
					}
				}
			}
		}
		//IF NO NOUN PHRASE
		if(cfg.top()!=n && cfg.top()!=pr && cfg.top()!=pn )
		{
				cout<<"Invalid Sentence !! :_(";
				return 0;
		}
	}
	
	cfg.display();
	
	while(cfg.top()!=vp && cfg.isEmpty()==1)
	{
		nps.push(cfg.pop());
	}
	
		
	
	cfg.display();
	
	if(cfg.pop()==vp)
	{
		//CHECKING VERB
		for(int j=0;j<vCount;j++)
		//VERB NP PP			
		if(words[i]==vArr[j]) 
		{
			cfg.push(v);
			i++;
			break;
		}
		//CHECKING NP
		if(cfg.top()==v)						
		{
			//CHECKING PRONOUN
			for(int j=0;j<pCount;j++)
			//PRONOUN FOUND				
			if(words[i]==pArr[j])
			{
				cfg.push(pr);						
				i++;
				break;
			}
			//CHECKING PROPERNOUN	
			for(int j=0;j<pnCount;j++)
			//PROPERNOUN FOUND		
			if(words[i]==pnArr[j])
			{
				cfg.push(pn);						
				i++;
				break;
			}
			// CHECKING DETERMINAL
			for(int j=0;j<dCount;j++)				
			{
				//DETERMINAL FOUND
				if(words[i]==dArr[j])
				{
					cfg.push(d);					
					i++;
					//CHECKING NOUNS | NOUN NOMINAL
					for(int j=0;j<nCount;j++)					
					{
						//3 NOUNS FOUND
						if(words[i]==nArr[j] && words[i+1]==nArr[j+1] && words[i+2]==nArr[j+2] && i+2<wCount) 
						{
							cfg.push(n);
							cfg.push(n);
							cfg.push(n);
							i=i+3;
							break;
						}
						//2 NOUNS FOUND
						else if(words[i]==nArr[j] && words[i+1]==nArr[j+1] && i+1<wCount)						
						{
							cfg.push(n);
							cfg.push(n);
							i=i+2;
							break;
						}
						//1 NOUN FOUND
						else if(words[i]==nArr[j])												
						{
							cfg.push(n);
							i++;
							break;
						}
						//NO NOUN FOUND
						else																	
						{
							cout<<"Invalid Sentence !! :_(";
							return 0;
						}
					}
				}
				//IF NO NOUN PHRASE
				if(cfg.top()!=n && cfg.top()!=pr && cfg.top()!=pn && cfg.top()!=v )
				{
					cout<<"Invalid Sentence !! :_(";
					return 0;
				}
				else if(cfg.top()!=n)
				{
					break;
				}
			}
			//CHECKING PREPOSITION
			for(int j=0;j<ppCount;j++)							
			{
				//PREPOSITION FOUND
				if(words[i]==ppArr[j])
				{
					cfg.push(pp);
					i++;
					break;
				}
			}
			
			if(cfg.top()==pp)
			{
				//CHECKING PRONOUN
				for(int j=0;j<pCount;j++)
				//PRONOUN FOUND				
				if(words[i]==pArr[j])
				{
					cfg.push(pr);						
					i++;
					break;
				}
				if(cfg.top()!=pr)
				//CHECKING PROPERNOUN		
				for(int j=0;j<pnCount;j++)
				//PROPERNOUN FOUND				
				if(words[i]==pnArr[j])
				{
					cfg.push(pn);						
					i++;
					break;
				}
				if(cfg.top()!=pr && cfg.top()!=pn)
				// CHECKING DETERMINAL
				for(int j=0;j<dCount;j++)				
				{
					//DETERMINAL FOUND
					if(words[i]==dArr[j])
					{
						cfg.push(d);					
						i++;
						//CHECKING NOUNS | NOUN NOMINAL
						for(int j=0;i<nCount;j++)					
						{
							//3 NOUNS FOUND
							if(words[i]==nArr[j] && words[i+1]==nArr[j+1] && words[i+2]==nArr[j+2]) 
							{
								cfg.push(n);
								cfg.push(n);
								cfg.push(n);
								i=i+3;
								break;
							}
							//2 NOUNS FOUND
							else if(words[i]==nArr[j] && words[i+1]==nArr[j+1])						
							{
								cfg.push(n);
								cfg.push(n);
								i=i+2;
								break;
							}
							//1 NOUN FOUND
							else if(words[i]==nArr[j])												
							{
								cfg.push(n);
								i++;
								break;
							}
							//NO NOUN FOUND
							else																	
							{
								cout<<"Invalid Sentence !! :_(";
								return 0;
							}
						}
					}
					//IF NO NOUN PHRASE FOUND
					if(cfg.top()!=n && cfg.top()!=pr && cfg.top()!=pn )
					{
							cout<<"Invalid Sentence !! :_(";
							return 0;
					}
					else if (cfg.top()==n)
					{
						break;
					}
				}
			}
		}
		else
		{
			cout<<"Invalid Sentence !! :_(";
			return 0;
		}
	}
	cfg.display();
	while(cfg.isEmpty()==1)
	{
		vps.push(cfg.pop());
	}
	if(i==wCount)
	cout<<"\nVALID SENTENCE";
	else
	{
		cout<<"\nInvalid Sentence !! :_(";
		return 0;
	}
	
	
	cout<<"\nNps : ";
	nps.display();
	cout<<"Vps : ";
	vps.display();
	
	cout<<endl;
	int cn=0,cv=0,cp=0,cpn=0,cd=0,cpp=0;
	string w;
	while(nps.isEmpty()==1)
	{
		w=nps.pop();
		if(w.compare(n)==0)
		{
			cout<<nArr[cn]<<" ";
			cn++;
		}
		else if(w.compare(v)==0)
		{
			cout<<vArr[cv]<<" ";
			cv++;
		}
		else if(w.compare(pr)==0)
		{
			cout<<pArr[cp]<<" ";
			cp++;
		}
		else if(w.compare(pn)==0)
		{
			cout<<pnArr[cpn]<<" ";
			cpn++;
		}
		else if(w.compare(d)==0)
		{
			cout<<dArr[cd]<<" ";
			cd++;
		}
		else if(w.compare(pp)==0)
		{
			cout<<ppArr[cpp]<<" ";
			cpp++;
		}
	}
	
	while(vps.isEmpty()==1)
	{
		w=vps.pop();
		if(w.compare(n)==0)
		{
			cout<<nArr[cn]<<" ";
			cn++;
		}
		else if(w.compare(v)==0)
		{
			cout<<vArr[cv]<<" ";
			cv++;
		}
		else if(w.compare(pr)==0)
		{
			cout<<pArr[cp]<<" ";
			cp++;
		}
		else if(w.compare(pn)==0)
		{
			cout<<pnArr[cpn]<<" ";
			cpn++;
		}
		else if(w.compare(d)==0)
		{
			cout<<dArr[cd]<<" ";
			cd++;
		}
		else if(w.compare(pp)==0)
		{
			cout<<ppArr[cpp]<<" ";
			cpp++;
		}
	}	
	return 1;
}
