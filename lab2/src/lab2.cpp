

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
	     	 //string buffer;
	     	// string key;

	     public :
	     	 string buffer;
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

	     	    	 temp=usn+'|'+name+'|'+branch+'|'+sem;
	     	    	 len=temp.size();

	     	    	 for(j=len+1;j<100;j++)

	     	    	 {
	     	    		temp+='$';

	     	    	 }
	     	    	 buffer=temp;
	     	     }
	     	     void write()
	     	     {
	     	    	fstream fp1;

	     	    	//char file1;
	     	    	//cout<<"enter the filename"<<endl;
	     	    	//cin>>file1;
	     	    	fp1.open("file1.txt",ios::out|ios::app);
	     	    	fp1<<buffer;
	     	    	fp1<<endl;
	     	    	fp1.close();

	     	     }
	     	     void unpack()
	     	     {
	     	    	 int i=0;

	     	    	 usn.erase();
	     	    	 while(buffer[i]!='|')
	     	    		 usn+=buffer[i++];
	     	    	 	 i++;
	     	    	 	 name.erase();
	     	    	 	 while(buffer[i]!='|')
	     	    	 	 name+=buffer[i++];
	     	    	 	 i++;
	     	    	 	 branch.erase();
	     	    	 	 while(buffer[i]!='|')
	     	    	 		 branch+=buffer[i++];
	     	    	 	 i++;
	     	    	 	 sem.erase();
	     	    	 	 while(buffer[i]!='|')
	     	    	 		 sem+=buffer[i++];
	     	    	 	 i++;

	     	     }
	     	     int search(string key)
	     	     {
	     	    	 fstream fp1;
	     	    	 int pos;
	     	    	 fp1.open("file1.txt",ios::in);
	     	    	 while(fp1.eof())
	     	    	 {
	     	    		 getline(fp1,buffer);
	     	    		 unpack();
	     	    		 if(usn==key)
	     	    		 {
	     	    			 cout<<"true";
	     	    			 return pos;
	     	    			 pos=fp1.tellp();
	     	    		 }
	     	    		 else
	     	    			 cout<<"false";
	     	    	 }
	     	    	 return 0;
	     	     }
	     	    void modify(string key)
	     	  	     {
	     	  	    	 	 int choice;
	     	  	    	 	 int pos;
	     	  	    	 	 //string key;
	     	  	    	 	 pos=search(key);
	     	  	    	 	 cout<<"do you want to modify?\n1.usn 2.name 3.branch 4.sem\n enter your choice\n";
	     	  	    	 	 cin>>choice;
	     	  	    	 	 switch(choice)
	     	  	    	 	 {
	     	  	    	 	 case 1:cout<<"usn";
	     	  	    	 	        cin>>usn;
	     	  	    	 	        break;
	     	  	    	 	 case 2:cout<<"name";
	     	  	    	 	        cin>>name;
	     	  	    	 	        break;
	     	  	    	 	 case 3:cout<<"branch";
	     	  	    	 	        cin>>branch;
	     	  	    	 	        break;
	     	  	    	 	 case 4:cout<<"sem";
	     	  	    	 	         cin>>sem;
	     	  	    	 	         break;
	     	  	    	 	 default :cout<<"wrong choice";
	     	  	    	 	 }
	     	  	    	 	 buffer.erase();
	     	  	    	 	 pack();

	     	  	  }
	     };

int main()
{
	student s;
	string key;
	int choice;
	while (1) {
		 cout<<"enter the choice"<<endl;
		 cout<<"1.INSERT"<<endl<<"2.SEARCH"<<endl<<"3.DELETE"<<endl<<"4.modify"<<endl;
		 cin>>choice;
		 switch(choice)
		 {
		 	 case 1:

			 	 s.readstudentfromconsole();
			 	 //s.show();
			 	 s.pack();
			 	 s.write();
			 	 break;
		 	 case 2:
		 		 	 	 cout<<"enter the key"<<endl;
				     	    	 cin>>key;
				     	    	 s.search(key);
			 	 //s.unpack();
				     	    	 break;
		 	 case 3:
		 		 	 	 	 	 cout<<"enter the key"<<endl;
						     	    	 cin>>key;
						     	         s.modify(key);
	}
	}
}
