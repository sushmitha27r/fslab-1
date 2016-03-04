 //============================================================================
// Name  : hello.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include<fstream>
using namespace std;
class student {
	 string name;
	 string usn;
	 string branch;
	 string sem;
	 string buffer;
	 string key;

public :
	     void readstudentfromconsole(){
	    	        cin.clear();
	    	        cin.ignore(255,'\n');
	    	  	  	 cout<<"enter the name";
	    		     getline(cin,name);
	    		     cin.clear();
	    		     cin.ignore(255,'\n');
	    		     cout<<"enter the USN";
	    		     cin>>usn;
	    		     cout<<"enter the branch";
	    		     cin>>branch;
	    		     cout<<"enter the sem\n";
	    		     cin>>sem;

	     }

	     void show (){
	    	 cout<<name<<endl<<usn<<endl<<branch<<endl<<sem;

		}
	     void pack()
	     {
	    	 string temp;
	    	 int j,len;
	    	 string buffer;
	    	 temp=usn+'|'+name+'|'+branch+'|'+sem;
	    	 len=temp.size();
	    	 buffer=temp;
	    	 for(j=len+1;j<100;j++)

	    	 {
	    		temp+='$';

	    	 }
	     }
	     void write()
	     {
	    	fstream fp1;
	    	string buffer;
	    	char file1;
	    	cout<<"enter the filename"<<endl;
	    	cin>>file1;
	    	fp1.open("file1.txt",ios::out|ios::app);
	    	fp1<<buffer;
	    	fp1<<endl;
	    	fp1.close();

	     }
	     int unpack()
	     {
	    	 int i=0;
	    	 char pos;


	    	 cin>>key;

	    	 while(buffer[i]!='|')
	    		 usn+=buffer[i++];
	    	 	 i++;
	    	 	 while(buffer[i]!='|')
	    	 	 {
	    	 		 name+=buffer[i++];
	    	 	 if(usn==key)
	    	 		cout<<"true";

	    	 	 else
	    	 		 cout<<"false";
	    	 	 }
	    	 	 return pos;
	     }
	     void search()
	     {
	    	 fstream fp1;
	    	 cout<<"enter the key"<<endl;
	    	 cin>>key;
	    	 fp1.open("file1.txt",ios::in);
	    	 getline(fp1,buffer);
	     }
};

int main()
{
	int choice;
	while (1) {
		 cout<<"enter the choice"<<endl;
		 cout<<"1.INSERT"<<endl<<"2.SEARCH"<<endl<<"3.DELETE"<<endl<<"4.modify"<<endl;
		 cin>>choice;
		 switch(choice)
		 {
		 case 1:
			 student s;
			 s.readstudentfromconsole();
			 s.show();
			 break;
		 case 2:
			 s.search();
			 s.unpack();
			 break;
	}
	}
}
