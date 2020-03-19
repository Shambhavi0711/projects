//CODING

#include<iostream.h>
#include<process.h>
#include<conio.h>
#include<fstream.h>
#include<stdio.h>
class student
{  int rollno;
   char name[50];
   int clas;
   int marks;
   char grade;
   public:
   void getdata();
   void putdata();
   int getrollno()
   { return rollno;
   }
}stu;
void student::getdata()

{  clrscr();
   cout<<"---------------------------------------------------";
   cout<<"\n Enter roll number===";
   cin>>rollno;
   cout<<"\n Enter name===";
   gets(name);
   cout<<"\n Enter class===";
   cin>>clas;
   cout<<"\n Enter marks===";
   cin>>marks;
   if(marks>=90) grade='A';
   else if(marks>=80) grade='B';
   else if(marks>=70) grade='C';
   else if(marks>=60) grade='D';
   else grade='E';
}
void student::putdata()
{

   clrscr();
   cout<<"-------------------------------------------------";
   cout<<"\n Roll no  :"<<rollno;
   cout<<"\n Name     :"<<name;
   cout<<"\n Class    :"<<clas;
   cout<<"\n Marks    :"<<marks;
   cout<<"\n Grade    :"<<grade;
}
void add();
void menu();
void displayall();
void deleete();
void modify();
void search();
void main()
{  textcolor(BLUE);
   textbackground(WHITE);
   menu();
}
void menu()
{
  int choice;
  clrscr();
  cout<<"Enter your choice:-:-\n 1= Add\n 2= Search\n 3= Modify\n 4= Delete\n 5= Display all\n";
  cin>>choice;
  clrscr();
    if(choice==1)
     add();
    if(choice==2)
     search();
    if(choice==3)
     modify();
    if(choice==4)
     deleete();
    if(choice==5)
     displayall();
}
void search()
{  ifstream fin("stud.dat",ios::in|ios::binary);
   int rno;        char m='y';
   cout<<"\nEnter roll no to be searched for==\n";
   cin>>rno;
   while(!fin.eof())
   {   fin.read((char*)&stu,sizeof(stu));
       if(stu.getrollno()==rno)
       stu.putdata();
   }
   fin.close();
   cout<<"\n Want to enter menu(press y)==";
   cin>>m;
   if(m=='y')
   menu();
   else
   exit(0);
}
void add()
{  char ch='y',m='y';
   ofstream fout("stud.dat",ios::out|ios::app|ios::binary);
   while(ch=='y'||ch=='Y')
   {  stu.getdata();
      fout.write((char*)&stu,sizeof(stu));
      cout<<"\n Want to add more(press y)==\n";
      cin>>ch;
   }
   fout.close();
   cout<<"\n Want to enter menu(press y)==";
   cin>>m;
   if(m=='y')
   menu();
   else
   exit(0);
}
void deleete()
{  int rno;
   fstream fio("stud.dat",ios::in|ios::in|ios::binary);
   ofstream file("temp.dat",ios::out|ios::binary);
   char confirm='n', m='y';
   cout<<"\nEnter roll no to be deleted==";
   cin>>rno;
   while(!fio.eof())
   {  fio.read((char*)&stu,sizeof(stu));
      if(stu.getrollno()==rno)
      {   stu.putdata();
	  cout<<"\n Are you sure you want to delete(press y)==";
	  cin>>confirm;
	  if(confirm=='n')
	  {   file.write((char*)&stu,sizeof(stu));
	  }
      }
      else
      file.write((char*)&stu,sizeof(stu));
   }
  remove("stud.dat");
  rename("temp.dat","stud.dat");
  cout<<"\n Data deleted";
  cout<<"\n Want to enter menu(press y)==";
  cin>>m;
  if(m=='y')
  menu();
  else
  exit(0);
}
void modify()
{   fstream fio("stud.dat",ios::in|ios::out|ios::binary);
    int rno; long pos; char m='y';
    fio.seekg(0);
    cout<<"\n Enter the roll no whose record is to be modified==";
    cin>>rno;
    while(!fio.eof())
    {    int loc=fio.tellg();
	 fio.read((char*)&stu,sizeof(stu));
	 if(stu.getrollno()==rno)
	 {   stu.getdata();
	 fio.seekg(loc);
	 fio.write((char*)&stu,sizeof(stu));
	 cout<<"\n Your record of roll no "<<rno<<" has been updated";
	 }
    }
    fio.close();
    cout<<"\n Want to enter menu(press y)==";
    cin>>m;
    if(m=='y')
    menu();
    else
    exit(0);
}
void displayall()
{   char m='y';
    ifstream fin("stud.dat",ios::in|ios::binary);
    while(!fin.eof())
    {   fin.read((char*)&stu,sizeof(stu));
	stu.putdata();
	getch();
    }
    fin.close();
    cout<<"\n Want to enter menu(press y)==";
    cin>>m;
    if(m=='y')
    menu();
    else
    exit(0);
}

