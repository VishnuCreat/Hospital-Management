#include<iostream>
#include<conio.h>
#include<string.h>
#include<fstream>
#include<iomanip>
using namespace std;
fstream fin,fout;
class student
{
	char name[20],rollno[20],section[10];
	int marks;
	public:
    void getdata();
    void showdata();
    void menu();
    void read();
    void search();
    void search1();
    void delete1();
    void update1();
    void mainmenu();
    void Password();
    char *getname()
	{ 
	return name; 
	}
    char *getrollno()
	{ 
	return rollno;
	}
  
        
};


//to get the data of students  from the admin
void student::getdata()
{
	cout<<"\nEnter the name:";
	cin>>name;
	cout<<"\nEnter the roll number: ";
	cin>>rollno;
	cout<<"\nEnter the section:";
	cin>>section;
	cout<<"\n Enter the total percentage:";
	cin>>marks;
	
}

//to display the details of students to the admin

void student::showdata()
{
	cout<<"\n\n\n"<<"Name:"<<name<<"\t"<<"Roll no.:"<<rollno<<"\t"<<"Section:"<<section<<"\tPercentage:"<<marks<<"%";
	
}

//to get the data and save the information of the user to the file

void student::menu()
{
	fout.open("student.dat",ios::out|ios::app);
        getdata();
	    fout.write((char*)this,sizeof(student));
    fout.close();
    cout<<endl<<"\n";
	 printf("PRESS ANY KEY TO CONTINUE........");
	   getch();
	  system("cls");
	    mainmenu();
}

//to display all the data to the admin

void student:: read()
{
    fin.open("student.dat",ios::in);
    fin.read((char*)this, sizeof(student));
     while(!fin.eof())
	{
       
		showdata();
		 fin.read((char*)this,sizeof(student));
	}
	fin.close();
	cout<<endl<<"\n";
	 printf("PRESS ANY KEY TO CONTINUE........");
	   getch();
	  system("cls");
	    mainmenu();

}

//to search a specific student using the rollno and if the rollno is not present than display "no result found"

void student::search()
{
	char nm[50];
	cout<<"\n\nEnter The  Roll no To Be Searched : ";
    cin>>nm;
    fin.open("student.dat",ios::in);
                 
                fin.seekg(0,ios::beg);
                 int found=0;
                
                 while(fin.read((char*)this,sizeof(student)))
                 {
                 	
                    if(strcmp(nm,getrollno())==0)
                       {
                        found=1;
                        showdata();
                       }
                 }
                 if(found==0)
                    cout<<"\n\n---Record Not found---\n";
         fin.close();
         
         cout<<endl;
	 printf("PRESS ANY KEY TO CONTINUE........");
	   getch();
	  system("cls");
	    mainmenu();
}

//to update the student details using rollno 
void student::update1()
{
	 
            	char n[100];
	
	   fin.open("student.dat",ios::in);
	   fout.open("student1.dat",ios::out);
                 //found=0;
     cout<<"\nEnter  Rollno. that should be modified:";
	cin>>n;
    while(!fin.eof())
    { 
     fin.read((char*)this, sizeof(student));
		if(strcmp(n,getrollno())==0)
		       	{
				//fin.seekg(0,ios::cur);
				cout<<"Enter New Record.."<<endl;
				getdata();
				}
			  if(!fin.eof())
			  {
				
				fout.write((char*)this, sizeof(student));
			    }
			    else
			     break;
			
		}
	
	fin.close();
	fout.close();
	remove("student.dat");
	rename("student1.dat","student.dat");
	
	cout<<endl<<"\n";
	 printf("PRESS ANY KEY TO CONTINUE........");
	   getch();
	  system("cls");
	    mainmenu();
			
}
void student::delete1()
{
	 
            	char n[100];
	
	   fin.open("student.dat",ios::in);
	   fout.open("student1.dat",ios::out);
                 //found=0;
     cout<<"\nEnter rollno. that should be deleted:";
	cin>>n;
	 fin.read((char*)this, sizeof(student));
    while(!fin.eof())
    { 
     
		if(strcmp(n,getrollno())!=0)
		       	{
			
					fout.write((char*)this, sizeof(student));
				}
			 
			   
			fin.read((char*)this, sizeof(student));
		}
	
	fin.close();
	fout.close();
		remove("student.dat");
	rename("student1.dat","student.dat");
	
	cout<<endl<<"\n";
	 printf("PRESS ANY KEY TO CONTINUE........");
	   getch();
	  system("cls");
	    mainmenu();
}

void student:: mainmenu()
{
 char ch;
 int i;
 cout<<endl;
 cout<<"\t\t\tMAIN MENU\t\t\t";
 cout<<endl;
 cout<<"\t\t\t1.INSERT A ADD DATA\t\t\t";
 cout<<endl;
 cout<<"\t\t\t2.SHOW ALL DIRECTORY DATA \t\t\t";
 cout<<endl;
 cout<<"\t\t\t3.DELETE A DATA \t\t\t";
 cout<<endl;
 cout<<"\t\t\t4.SEARCH A DATA BY NAME\t\t\t";
 cout<<endl;
 cout<<"\t\t\t5.MODIFY  A DATA\t\t\t";
 cout<<endl;
 cout<<"\t\t\t6.EXIT\t\t\t";
 cout<<endl;
 cout<<"Enter Your Choice :";
 cin>>ch;
   switch(ch)
 {
 		case '1':
		 menu();
		 
		break;
	case '2':
		read();
	
		break;
		case '3':
			 delete1();
		
	    break;
	case '4':
		  search();
	      break;
	    case '5':
	    	update1();
	    	break;
	   
	    
		  case '6':exit(0);
		      break;
		      default:{
		      	
				 
	         
	            system("cls");
	           mainmenu();
	        
	    }
					  
		      	  
		      	  
		    		 
	 }	
}
char password[20]={"vishnu"};
void student:: Password() 
{

      char ch;
	  string pass;
   int i=0,j;
        
   cout<<"ENTER THE PASSWORD:";
cin>>pass;
  
   if(pass==password)
   {
    printf("Password match\n");
   mainmenu();
   }
   else
   {
	 system("cls");
	 printf("\nWarning!! Incorrect Password\n");
	 Password();
   }
}







main()
{
	student s;

     s.Password(); 


}

