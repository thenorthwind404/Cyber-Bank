#include<conio.h>
#include<fstream.h>
#include<iostream.h>
#include<stdio.h>
#include<process.h>
#include<string.h>
#include<stdlib.h>
class account
{
public:
char name[20],pass[20];
unsigned long accno;
float balance;
}a;
void line()
{
cout<<"____________________________________________________";
cout<<"\n             Cyber Bank                                ";
cout<<"\n__________________________________________________";
}
int car(float p)
{
float r;
if(p>250000)
r=5;
else if(p>500000)
r=5.7;
else if(p>1000000)
r=6.1;
else
r=6.7;
return r;
}
int house(float p)
{
float r;
if(p>2000000)
r=9;
else if(p>3000000)
r=9.5;
else if(p>5000000)
r=10;
else
r=11;
return r;
}
void create()
{
clrscr();
randomize();
char pass1[20],pass2[20];
h:clrscr();
cout<<"Enter your name ";
gets(a.name);
cout<<"Enter password ";
gets(pass2);
cout<<"Confirm password ";
gets(pass1);
if(strcmp(pass2,pass1)!=0)
{
cout<<"\nError. Enter the details again ";
getch();
goto h;
}
else
strcpy(a.pass,pass1);
a.accno=random(9999999999);
cout<<"Your account has been created\nYour Account Number is "<<a.accno;
cout<<"\nEnter the amount to be deposited ";
cin>>a.balance;
cout<<"The details of your account are ";
cout<<"\nName: "<<a.name<<"\nPassword: "<<a.pass<<"\nAccount Number: "<<a.accno<<"\nBalance: "<<a.balance;
}
void write()
{
ofstream ofile;
ofile.open("account.dat",ios::out|ios::binary);
ofile.write((char*)&a,sizeof(a));
ofile.close();
}
int rate(float p)
{
int r;
if(p>10000)
r=5;
else if(p>50000)
r=7;
else if(p>100000)
r=10;
else
r=12;
return r;
}
void si(float p,int r)
{
float t;
cout<<"\nEnter the period of time for which you want to borrow the money (in years) ";
cin>>t;
float SI;
SI=p*r*t/100;
cout<<"The total amount to be paid at the end of the time period is "<<p+SI;
cout<<"The money has been succesfuly deposited into your account";
a.balance=a.balance+p;
}
void fd()
{
c:cout<<"\nEnter the amount of money you want to deposit";
unsigned int d;
cin>>d;
if(d>a.balance)
{
cout<<"You do not have enough balance in you account\n";
cout<<"enter a different amount";
goto c;
}
else
{
cout<<"The percentage interest is "<<house(d);
cout<<"enter the time for which you want to deposit the money(in years) ";
int t;
cin>>t;
float si;
si=d*house(d)*t/100;
cout<<"You will earn Rs."<<d+si<<" at the end of your time period";
cout<<"\nThe money you have deposited has succesfuly been deducted from you main balance";
a.balance-=d;
getch();
}
}
void change()
{
int temp=0;
char nam[20],pas[20];
clrscr();
s:cout<<"Enter Name ";
gets(nam);
cout<<"Enter Password ";
gets(pas);
if(strcmp(nam,a.name)!=0||strcmp(pas,a.pass)!=0&&temp<3)
{
temp++;
cout<<"The Username or Password is wrong";
cout<<"\nPlease retype Username and Password\n";
cout<<"You have two(2) more tries\n";
goto s;
}
else
cout<<"You have accessed your account";
getch();
int c;
g:clrscr();
cout<<"1 Deposit Money\n2 Withdraw Money\n3 Change Password\n4 Apply for Loan\n5 Check Balance\n6 Log Out";
cout<<"\nEnter your choice ";
cin>>c;
switch(c)
{
case 1:
d1:cout<<"\n1.Fixed deposit\n2.Savings\nEnter your choice ";
int l;
cin>>l;
switch(l)
{
case 1:
fd();
write();
break;
case 2:
cout<<"Enter the amount you want to deposit ";
unsigned int s;
cin>>s;
a.balance+=s;
write();
break;
default:
cout<<"Wrong choice please enter again";
getch();
goto d1;
}
getch();
break;
case 2:
int with;
b:cout<<"Enter the amount you want to withdraw ";
cin>>with;
if(with>a.balance)
{
cout<<"You do not have enough money for transaction in your account";
cout<<"\nPlease enter a different ammount";
goto b;
}
else
{
a.balance-=with;
cout<<"Your new balance is "<<a.balance;
write();
exit(0);
getch();
}
break;
case 3:
char pas1[10],pas2[10];
f:cout<<"Enter the new password ";
gets(pas1);
cout<<"Confirm new password ";
gets(pas2);
if(strcmp(pas1,pas2)!=0)
{
cout<<"Password did not match retype new password";
goto f;
}
else
{
strcpy(pas1,a.pass);
cout<<"Your password has been changed";
getch();
}
write();
break;
case 4:
d2:cout<<"1.Personal loan\n2.Car Loan\n3.Home Loan\nEnter the type of loan you require";
int x;
cin>>x;
float loan;
switch(x)
{
case 1:
cout<<"Enter the amount you want to borrow (minimum amount 10,000) ";
cin>>loan;
cout<<"The rate of interest per annum is "<<rate(loan);
si(loan,rate(loan));
cout<<"\n Your loan has been sanctioned,the amount has been transfered to your account ";
getch();
break;
case 2:
cout<<"Enter the amout of loan required to purchase your car";
cin>>loan;
si(loan,car(loan));
cout<<"Your loan has been scantioned,the amount has been transferred to your account";
cout<<"\nYour car will belong to the bank(as colatral) and will remain so till the loan has be paid off completely";
getch();
break;
case 3:
cout<<"Enter the amout of loan required to purchase your house";
cin>>loan;
si(loan,house(loan));
cout<<"Your loan has been scantioned,the amount has been transferred to your account";
cout<<"\nYour house will belong to the bank(as colatral) and will remain so till the loan has be paid off completely";
getch();
break;
default:
cout<<"Wrong choice.Enter again";
getch();
goto d2;
clrscr();
break;
}
break;
case 5:
cout<<"Your Balance is "<<a.balance;
getch();
break;
case 6:
goto l;
default:
cout<<"Error!! :(";
}
goto g;
l:clrscr();
}
void main()
{
clrscr();
line();
int b;
l:j:cout<<"\n1 Create New Account\n2 Existing Account\n3.Exit\nEnter your choice ";
cin>>b;
switch(b)
{
case 1:
clrscr();
ofstream ofile;
ofile.open("account.dat",ios::out|ios::binary);
create();
ofile.write((char*)&a,sizeof(a));
ofile.close();
break;
case 2:
clrscr();
ofstream ofile1;
ifstream ifile;
ifile.open("account.dat",ios::in|ios::binary);
cout<<"1";
ifile.read((char*)&a,sizeof(a));
change();
ifile.close();
break;
case 3:
cout<”\nThank you for banking with us :)”;
getch();
exit(0);
break;
default:
cout<<"Error";
}
goto j;
getch();
}
