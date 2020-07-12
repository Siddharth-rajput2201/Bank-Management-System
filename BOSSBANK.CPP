#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
class bank
{
int i;
char name[100],actype[10],password[20],acno[10];
float balance;

public:

void getinfo()
{
 cout<<"\ENTER NEW ACCOUNT NUMBER : ";
 gets(acno);
 cout<<"\nENTER NEW PASSWORD : ";
 gets(password);
 cout<<"\nENTER NEW ACCOUNT TYPE(S-SAVINGS,C-CURRENT) : ";
 gets(actype);
 cout<<"\nENTER NEW NAME : ";
 gets(name);
 cout<<"\nENTER NEW BALANCE : ";
 cin>>balance;
}
void withdraw()
{
float x;
cout<<"\nENTER THE AMOUNT TO BE WITHDRAWN : ";
cin>>x;
balance-=x;
}
void add()
{
float x;
cout<<"\nENTER THE AMOUNT TO BE DEPOSITED : ";
cin>>x;
balance+=x;
}

char* getname()
{
 return name;
}

char* getactype()
{
 return actype;
}

char* getpassword()
{
 return password;
}

char* getacno()
{
 return acno;
}

float getbal()
{
return balance;
}

void show()
{
i=0;
i++;
cout<<"===================================================================";
cout<<"\nACCOUNT NUMBER      ACCOUNT TYPE        BALANCE           NAME  "   ;
cout<<"\n===================================================================";
cout<<"\n"<<acno<<"\t\t|  \t"<<actype<<"\t   |\t "<<balance<<"\t   |\t"<<name;
}
};

void write()
{
 ofstream fout("bank.dat",ios::app|ios::binary);
 bank b;
 b.getinfo();
 fout.write((char*)&b,sizeof(b));
 fout.close();
}

void read()
{
 char nacno[10],i;
 char password[100];
 ifstream fin("bank.dat",ios::binary);
 bank b;
 cout<<"\nENTER ACCOUNT NUMBER : ";
 gets(nacno);
 cout<<"\nENTER PASSWORD : ";
 gets(password);
 int f=0;
 while(fin.read((char*)&b,sizeof(b)))
 {
 if(strcmpi(b.getacno(),nacno)==0 && strcmpi(b.getpassword(),password)==0)
 {
 f=1;
 b.show();
 }
}
if (f==0)
 {
 cout<<"\nINVALID ACCOUNT NUMBER OR PASSWORD";
 }
 fin.close();
}

void withdrawm()
{
 char nacno[10],i;
 char password[100];
 ifstream fin("bank.dat",ios::binary);
 ofstream fout("temp.dat",ios::binary);
 bank b;
 cout<<"\nENTER ACCOUNT NUMBER : ";
 gets(nacno);
 cout<<"\nENTER PASSWORD : ";
 gets(password);
 int f=0;
 float x;
 while(fin.read((char*)&b,sizeof(b)))
 {
 if(strcmpi(b.getacno(),nacno)==0 && strcmpi(b.getpassword(),password)==0)
 {
 f=1;
 b.withdraw();
 b.show();
 }
 fout.write((char*)&b,sizeof(b));
}
if (f==0)
 {
 cout<<"\nINVALID ACCOUNT NUMBER OR PASSWORD";
 }
 fin.close();
 fout.close();
 remove("bank.dat");
 rename("temp.dat","bank.dat");
}
void addm()
{
 char nacno[10],i;
 char password[100];
 ifstream fin("bank.dat",ios::binary);
 ofstream fout("temp.dat",ios::binary);
 bank b;
 cout<<"\nENTER ACCOUNT NUMBER : ";
 gets(nacno);
 cout<<"\nENTER PASSWORD : ";
 gets(password);
 int f=0;
 float x;
 while(fin.read((char*)&b,sizeof(b)))
 {
 if(strcmpi(b.getacno(),nacno)==0 && strcmpi(b.getpassword(),password)==0)
 {
 f=1;
 b.add();
 b.show();
 }
 fout.write((char*)&b,sizeof(b));
}
if (f==0)
 {
 cout<<"\nINVALID ACCOUNT NUMBER OR PASSWORD";
 }
 fin.close();
 fout.close();
 remove("bank.dat");
 rename("temp.dat","bank.dat");
}


void modify()
{
 char nacno[10],i;
 char password[100];
 ifstream fin("bank.dat",ios::binary);
 ofstream fout("temp.dat",ios::binary);
 bank b;
 cout<<"\nENTER ACCOUNT NUMBER : ";
 gets(nacno);
 cout<<"\nENTER PASSWORD : ";
 gets(password);
 int f=0;
 while(fin.read((char*)&b,sizeof(b)))
 {
 if(strcmpi(b.getacno(),nacno)==0 && strcmpi(b.getpassword(),password)==0)
 {
 f=1;
 b.show();
 b.getinfo();
 }
 fout.write((char*)&b,sizeof(b));
}
if (f==0)
 {
 cout<<"\nINVALID ACCOUNT NUMBER OR PASSWORD";
 }
 fin.close();
 fout.close();
 remove("bank.dat");
 rename("temp.dat","bank.dat");
}

void del()
{
 char nacno[10],i;
 char password[100];
 ifstream fin("bank.dat",ios::binary);
 ofstream fout("temp.dat",ios::binary);
 bank b;
 cout<<"\nENTER ACCOUNT NUMBER : ";
 gets(nacno);
 cout<<"\nENTER PASSWORD : ";
 gets(password);
 int f=0;
 while(fin.read((char*)&b,sizeof(b)))
 {
 if(strcmpi(b.getacno(),nacno)==0 && strcmpi(b.getpassword(),password)==0)
 {
 f=1;
 b.show();
 }
 else
 fout.write((char*)&b,sizeof(b));
}
if (f==0)
 {
 cout<<"\nINVALID ACCOUNT NUMBER OR PASSWORD";
 }
 fin.close();
 fout.close();
 remove("bank.dat");
 rename("temp.dat","bank.dat");
}

void main()
{
 clrscr();
 int ch;
  do
  {
  cout<<"\n";
  cout<<"\n";
  cout<<"\n1.TO CREATE NEW ACCOUNT";
  cout<<"\n2.TO DISPLAY CREDENTIALS";
  cout<<"\n3.TO MODIFY DETAILS";
  cout<<"\n4.TO DELETE ACCOUNT";
  cout<<"\n5.TO WITHDRAW MONEY";
  cout<<"\n6.TO DEPOSIT MONEY";
  cout<<"\n7.EXIT";
  cout<<"\nENTER YOUR CHOICE : ";
  cin>>ch;
  switch(ch)
   {
    case 1:write(); break;
    case 2:read(); break;
    case 3:modify(); break;
    case 4:del(); break;
    case 5:withdrawm(); break;
    case 6:addm(); break;
    case 7:break;
   }
  }
  while(ch!=7);
  cout<<"THANK YOU";
  getch();
}

