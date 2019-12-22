#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<graphics.h>
void menu();
void add();
void list();
void edit();
void payment();
void search();
void screen();
void info();
void data();
void password();
void notfound();
void null();
void title(char *);
struct std
{ int cls;
  float amt;
  char r[5],pn[20],n[25];
  }s;
long int size=sizeof(s);
int n=0,i=0,cls,gd=DETECT,gm;
char r[5],c,p[10],x[10]="kist";
FILE *f;
void main()
{
  initgraph(&gd,&gm,"C:\\TC\\BGI");
  screen();
  settextstyle(7,0,2);
  outtextxy(160,190,"STUDENT FEE PAYMENT SYSTEM");
  outtextxy(180,270,"      RUKESH BASUKALA");
  getch();
  menu();
  }
void menu()
{ char t[]="MAIN MENU";
  while(1)
  {
	screen();
	title(t);
	delay(500);
	outtextxy(130,145,"1) Adding new records");
	outtextxy(130,170,"2) List of records");
	outtextxy(130,195,"3) Modifying records");
	outtextxy(130,220,"4) Payment");
	outtextxy(130,245,"5) Searching records");
	outtextxy(130,270,"6) Exit.");
	delay(500);	outtextxy(130,320,"Enter your choice(1-6): ");
	c=getche();
	screen();
    switch(c)
    {
      case '1':
	 password();
	 add();
	 break;
      case '2':
	 list();
	 break;
      case '3':
	 password();
	 edit();
	 break;
      case '4':
	 password();
	 payment();
	 break;
      case '5':
	 search();
	 break;
      case '6':
	 exit(0);
	 break;
      default:
	 screen();
	 setcolor(12);
	 outtextxy(250,220," INVALID choice");
	 outtextxy(250,240,"PLEASE TRY AGAILN");
	 getch();
	 menu();
      }
  outtextxy(180,370,"   ***Enter any key to goto menu***");
  getch();
  }
 }
void add()
{ char t[]="ADD RECORDS";
  f=fopen("c:/student.txt","a+");
  if(f==NULL)
    null();
     screen();
     title(t);
     gotoxy(20,13); printf("Class:");
		    scanf("%d",&s.cls);
     gotoxy(20,14); printf("Roll no.:");
		    scanf("%s",&s.r);
     gotoxy(20,15); printf("Name:");
		    scanf("%s",&s.n);
     gotoxy(20,16); printf("Phone number:");
		    scanf("%s",&s.pn);
     gotoxy(20,17); printf("Total amount:");
		    scanf("%f",&s.amt);
     fwrite(&s,sizeof(s),1,f);
     fclose(f);
     outtextxy(180,350,"Enter y if you want to add another record:");
     c=getche();
     if(c=='y'|| c=='Y')
       add();  																																									fclose(f);
  }
void list()
  {
  int n=0;
  char a[20],t[]="LIST RECORDS";
   f=fopen("c:/student.txt","r+");
   screen();
   if(f==NULL)
     null();
   title(t);
   gotoxy(20,15); printf("Which Class record do you want to see:");
		  scanf("%d",&cls);
   screen();
   title(t);
   outtextxy(90,100,"Class");
   outtextxy(145,100,"Roll no.");
   outtextxy(225,100,"Name");
   outtextxy(345,100,"Phone number");
   outtextxy(470,100,"Totl Amount");
   setcolor(15); rectangle(70,110,580,115);
   setcolor(10);
   i=20;
	while(fread(&s,sizeof(s),1,f)==1)
	{
	    if(s.cls==cls)
	      {
		if(i>250)
		{
			outtextxy(180,370,"***Enter any key to continue***");
			getch();
			screen();
			title(t);
			outtextxy(90,100,"Class");
			outtextxy(145,100,"Roll no.");
			outtextxy(225,100,"Name");
			outtextxy(345,100,"Phone number");
			outtextxy(470,100,"Totl Amount");
			setcolor(15); rectangle(70,110,580,115);
			setcolor(10);
			i=20;
		}
		sprintf(a,"%d",s.cls); //accept int value convert into string
		delay(500); outtextxy(90,110+i,a);
		outtextxy(145,110+i,s.r);
		outtextxy(225,110+i,s.n);
		outtextxy(345,110+i,s.pn);
		sprintf(a,"%.2f",s.amt);
		outtextxy(470,110+i,a);
		i=i+20;
		n=1;
	      }
	    }
    if(n==0)
     notfound();
    fclose(f);
  }
void edit()
{ int n=0;
  char t[]="EDIT RECORDS";
  f=fopen("c:/student.txt","r+");
  if(f==NULL)
    null();
  title(t);
  info();
  title(t);
     while(fread(&s,sizeof(s),1,f)==1)
      {
	if(strcmp(s.r,r)==0 && s.cls==cls)
	 { gotoxy(20,8); printf("Old Data:");
	   data();
	   setcolor(15); rectangle(70,245,580,250);
	   gotoxy(20,17); printf("Enter New Data:");
	   gotoxy(20,18); printf("Class:");
			  scanf("%d",&s.cls);
	   gotoxy(20,19); printf("Roll number:");
			  scanf("%s",&s.r);
	   gotoxy(20,20); printf("Name:");
			  scanf("%s",&s.n);
	   gotoxy(20,21); printf("Phone number:");
			  scanf("%s",&s.pn);
	   gotoxy(20,22); printf("Total amount:");
			  scanf("%f",&s.amt);
	   fseek(f,-size,SEEK_CUR);
	   fwrite(&s,sizeof(s),1,f);
	   n=1;
	   }
	}
   if(n==0)
     notfound();
   fclose(f);
  }
void payment()
{ int n=0;
  float amt;
  char t[]="PAYMENT";
  f=fopen("c:/student.txt","r+");
  if(f==NULL)
    null();
  title(t);
  info();
  title(t);
  while(fread(&s,sizeof(s),1,f)==1)
      {
	if(strcmp(s.r,r)==0 && s.cls==cls)
	{
	   gotoxy(20,8); printf("Record:");
	   data();
	   setcolor(15); rectangle(70,245,580,250);
	   gotoxy(20,17); printf("Enter payment amount:");
			  scanf("%f",&amt);
	   s.amt=s.amt-amt;
	   rectangle(70,295,580,300);
	   gotoxy(20,20); printf("Remaining amount:%.2f",s.amt);
	   fseek(f,-size,SEEK_CUR);
	   fwrite(&s,sizeof(s),1,f);
	   n=1;
	   }
	}
   if(n==0)
    notfound();
   fclose(f);
  }
void search()
{ int n=0;
  char t[]="SEARCH RECORDS";
  f=fopen("c:/student.txt","r+");
  if(f==NULL)
    null();
  title(t);
  info();
  title(t);
  while(fread(&s,sizeof(s),1,f)==1)
   {
     if(strcmp(s.r,r)==0 && s.cls==cls)
       {
	   gotoxy(20,8); printf("Student record:");
	   data();
	   n=1;
	 }
       }
   if(n==0)
    notfound();
   fclose(f);
  }

void screen()
{
  cleardevice();
  setcolor(15);
  setfillstyle(6,15);
  rectangle(65,80,585,385);
  rectangle(70,85,580,380);
  floodfill(67,200,15);
  setcolor(10);
  settextstyle(12,0,1);
  }
void info()
{
  gotoxy(25,12); printf("Enter class of student:");
		 scanf("%d",&cls);
  gotoxy(25,15); printf("Enter Roll no. of student:");
		 scanf("%s",&r);
  screen();
      }
void data()
{
	   gotoxy(20,10);
	   printf("Class: %d",s.cls);
	   gotoxy(20,11);
	   printf("Roll number: %s",s.r);
	   gotoxy(20,12);
	   printf("Name: %s",s.n);
	   gotoxy(20,13);
	   printf("Phone number: %s",s.pn);
	   gotoxy(20,14);
	   printf("Current amount: Rs %.2f",s.amt);
	   }
void password()
{
  screen();
  outtextxy(250,350,"Press Esc to goto menu");
  gotoxy(25,15);
  printf("enter password:");
 for(i=0;i<10;i++)
  {p[i]=getch();
   n=p[i];
   if(n==13)    //13 is ASCII value of Enter
   break;       //to break loop when press Enter
   if(n==27)    //27 is ASCII value of Esc
   menu();      //to go back to menu when press Esc
   else
   printf("*");
   }
  p[i]='\0';    //end the string
  screen();
  if(strcmp(p,x)!=0)
   { screen();
     setcolor(12);
     outtextxy(240,220," ***Wrong password***");
     outtextxy(180,370,"   ***Enter any key to goto menu***");
     getch();
     menu();
     }
  }
void notfound()
{ screen();
  setcolor(12);
  outtextxy(240,220," !!!record not found!!!");
  }
void null()
{ screen();
  setcolor(12);
  outtextxy(240,220," !!!FILE IS EMPTY!!!");
  outtextxy(180,370,"   ***Enter any key to goto menu***");
  getch();
  menu();
  }
void title(char *t)
{ setcolor(14);
  settextstyle(1,0,2);
  outtextxy(260,50,t);
  setcolor(10);
  settextstyle(12,0,1);
  }