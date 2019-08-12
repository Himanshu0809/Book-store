//###################E-BOOK STORE- H&G BOOK STORE ###########################

#include<fstream.h>
#include<conio.h>
#include<dos.h>
#include<process.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<bios.h>
#include "func.h"

//admin username:admin
//password:password

//**************************MAIN STARTS*******************************
void main()
{
    textcolor(4);
	textbackground(WHITE);
	clrscr();
	int ch,ch1,ch2,ch3,ch4,ch5;

    //--------------who wants to access-----------------------
    t=chkaccess();
    load();
    //-----------------for administrator------------------------
	if(t==2)
    {
        while(1)
        {
            clrscr();
            cout<<"===============================================================================\n"
                <<"\t\t#### WELCOME ####\n"
                <<"===============================================================================\n\n"
                <<"\n\t   add books"<<endl
                <<"\n\t   show books by genre"<<endl
                <<"\n\t   user information"<<endl
                <<"\n\t   purchase history"<<endl
                <<"\n\t   Exit"<<endl;
            ch=retkey(10,6,5,5);
            switch(ch)
            {
            case 1:  int n;
                	   cout<<endl<<"\n\n\n\n\n\n\n\n\nenter number of books to add : ";
                	   cin>>n;
               	   for(int i=0; i<n; i++)
                	  {
                    		clrscr();
                    		cout<<"book "<<i+1<<endl<<endl<<endl;
                    		s.input();
                	 }
                	 break;
           case 3: char cat[20];
                	 int x=0;
                	 cout<<endl<<"\n\n\n\n\n\n\nenter the title to search for : ";
                	 gets(cat);
                	 fflush(stdin);
                	 search(cat,x,t);
               	 break;
           case 5: clrscr();
   cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"
          <<"\n\t\t\t    USER INFORMATION\n"
          <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
                        user_info();
            	break;
          case 7: clrscr();
cout<<"===============================================================================\n"
        <<"\t\t!!!!!!!!!!!!!!!       HISTORY       !!!!!!!!!!!!!!! \n"
 <<"===============================================================================\n";
            gotoxy(4,5);
                      cout<<"USERNAME";
                      gotoxy(18,5);
                      cout<<"BOOK NAME";
                      gotoxy(54,5);
                      cout<<"QUANTITY";
                      gotoxy(66,5);
                      cout<<"PRICE";
					  i=0;
                      sum1=0;
                      f3.open("his.dat",ios::binary|ios::in);
                      while(f3.read((char*)&h,sizeof(h)))
                   {
                   	 h.showinfo(i);
                    	i++;
                   }
                   cout<<endl<<endl;
                   cout<<"\t\t\t\t\tTotal Sale= Rs"<<sum1;
                   getch();
                   f3.close();
                   break;
      case 9: exit(0);
       	     }
        }
    }
    //------------------for guest-----------------------------
    else if(t==1)
    {
        while(1)
        {
            clrscr();
cout<<"===============================================================================\n"
        <<"\t\t#### WELCOME ####\n"
<<"===============================================================================\n\n"
         <<"\n\t   Categories of books"<<endl
         <<"\n\t   Enquiries"<<endl
         <<"\n\t   Sign up"<<endl
          <<"\n\t   sign in"<<endl
          <<"\n\t   Exit"<<endl;
     ch=retkey(10,6,5,5);
     switch(ch)
     {
    	case 1: while(1)
                	{
            clrscr();
cout<<"===============================================================================\n"
                                   <<"\t\t#### WELCOME####\n"
<<"===============================================================================\n\n"
            <<"\n\t   Categories of books"<<endl
                                   <<"\n\t\t     mystery"<<endl
                                   <<"\n\t\t     fantasy"<<endl
                                   <<"\n\t\t     romance"<<endl
                                  <<"\n\t\t     science fiction"<<endl
                                  <<"\n\t\t     go back"<<endl
                                  <<"\n\t   Enquiries"<<endl
                                  <<"\n\t   Sign up"<<endl
                                  <<"\n\t   sign in"<<endl
                                  <<"\n\t   Exit"<<endl;
                                ch1=retkey(20,8,5,7);
                                if(ch1==9)
                       		 break;
                    	         else
                        	show_menu(ch1);
                }
                break;
   case 3:while(1)
                {
                    clrscr();
cout<<"===============================================================================\n"
                        <<"\t\t#### WELCOME ####\n"
<<"===============================================================================\n\n"
                        <<"\n\t   Categories of books"<<endl
                        <<"\n\t   Enquiries"<<endl
                        <<"\n\t\t     Regarding terms and conditions"<<endl
                        <<"\n\t\t     Details of books"<<endl
                        <<"\n\t\t     Go back"<<endl
                        <<"\n\t   Exit"<<endl;
                    ch2=retkey(20,10,3,9);
                    if(ch2==5)
                        break;
                    else
                    {
                        clrscr();
                        switch(ch2)
                        {
                        case 1:
                            enquiry();
                            break;
                        case 3:
                            while(1)
                            {
                                clrscr();
                                cout<<"===============================================================================\n"
                                    <<"\t\t#### SEARCH A BOOK BY~~~ ####\n"
                                    <<"===============================================================================\n"
                                    <<"\n\t   title"<<endl
                                    <<"\n\t   author's name"<<endl
                                    <<"\n\t   publications"<<endl
                                    <<"\n\t   Go back"<<endl;
                                ch1=retkey(10,5,4,4);
                                if(ch1==7)
                                    break;
                                else
                                {
                                    clrscr();
                                    switch(ch1)
                                    {
                                    case 1:
                                        char wd[20];
                                        int x=1;
                                        cout<<"enter the title to search for : ";
                                        gets(wd);
                                        search(wd,x,t);
                                        break;
                                    case 3:
                                        char wd1[20];
                                        cout<<"author's first name : ";
                                        gets(wd);
                                        cout<<"enter author's sername : ";
                                        gets(wd1);
                                        search(wd,wd1);
                                        break;
                                    case 5:
                                        cout<<"enter the publication to search for : ";
                                        gets(wd);
                                        x=2;
                                        search(wd,x,t);
                                        break;
                                    }
                                }

                            }
                        }
                    }
                }
                break;
            case 5:
                ch3=0;
                clrscr();
                f2.open("accounts.dat",ios::binary|ios::out|ios::app);
                u.create_acc();
                while(ch3!=6)
                {
                    clrscr();
                    u.show_acc();
                    cout<<"\n\n\n change any detail(press 6 to move on) : ";
                    cin>>ch3;
                    u.change(ch3);
                }
                f2.write((char*)&u,sizeof(u));
                f2.close();
                clrscr();
                u.show_acc();
                getch();
                load();
                break;
            case 7:
                int x;
                clrscr();
                gotoxy(15,10);
                cout<<"enter username : ";
                gets(user1);
                gotoxy(15,12);
                x=searchpass(user1);
                if(x==0)
                {
                    gotoxy(20,15);
                    cout<<"invalid credentials";
                    getch();
                }
                else
                {
                    load();
                    p=0;
                    while(1)
                    {
                        clrscr();
                        cout<<"===============================================================================\n"
                            <<"\t#### WELCOME ####\t\t\twelcome "<<user1<<endl<<endl
                            <<"===============================================================================\n"
                            <<"\n\n\t   Categories of books"<<endl
                            <<"\n\t   Enquiries"<<endl
                            <<"\n\t   Purchase history"<<endl
                            <<"\n\t   log out"<<endl;
                        ch3=retkey(10,7,4,6);
                        if(ch3==7)
                        {
                            load();
                            break;
                        }
                        switch(ch3)
                        {
                        case 1:
                            while(1)
                            {
                                clrscr();
                                cout<<"===============================================================================\n"
                                    <<"\t\t#### WELCOME ####\n"
                                    <<"===============================================================================\n"
                                    <<"\n\t   Categories of books"<<endl
                                    <<"\n\t\t     mystery"<<endl
                                    <<"\n\t\t     fantasy"<<endl
                                    <<"\n\t\t     romance"<<endl
                                    <<"\n\t\t     science fiction"<<endl
                                    <<"\n\t\t     go back"<<endl
                                    <<"\n\t   Enquiries"<<endl
                                    <<"\n\t   Purchase history"<<endl
                                    <<"\n\t   log out"<<endl;
                                ch5=retkey(20,7,5,6);
                                if(ch5==9)
                                    break;
                                else
                                    show_menu(ch5);
                            }
                            break;
                        case 3:
                            while(1)
                            {
                                clrscr();
                                cout<<"===============================================================================\n"
                                    <<"\t\t#### WELCOME####\n"
                                    <<"===============================================================================\n"
                                    <<"\n\t   Categories of books"<<endl
                                    <<"\n\t   Enquiries"<<endl
                                    <<"\n\t\t     Regarding terms and conditions"<<endl
                                    <<"\n\t\t     Details of books"<<endl
                                    <<"\n\t\t     Go back"<<endl
                                    <<"\n\t   Purchase history"<<endl
                                    <<"\n\t   log out"<<endl;
                                ch5=retkey(20,9,3,8);
                                if(ch5==5)
                                    break;
                                else
                                {
                                    clrscr();
                                    switch(ch5)
                                    {
                                    case 1:  enquiry();
                                        	break;
                                    case 3:  while(1)
                                       	 {
                                            	         clrscr();
cout<<"===============================================================================\n"
                                                <<"\t\t#### SEARCH A BOOK BY~~~ ####\n"
                                                <<"===============================================================================\n"
                                                <<"\n\t   title"<<endl
                                                <<"\n\t   author's name"<<endl
                                                <<"\n\t   publications"<<endl
                                                <<"\n\t   Go back"<<endl;
                                            ch4=retkey(10,5,4,4);
                                            if(ch4==7)
                                                break;
                                            else
                                            {
                                                clrscr();
                                                switch(ch4)
                                                {
                                                case 1:
                                                    char wd[20];
                                                    int x=1;
                                                    cout<<"enter the title to search for : ";
                                                    gets(wd);
                                                    search(wd,x,t);
                                                    break;
                                                case 3:
                                                    char wd1[20];
                                                    cout<<"author's first name : ";
                                                    gets(wd);
                                                    cout<<"enter author's sername : ";
                                                    gets(wd1);
                                                    search(wd,wd1);
                                                    break;
                                                case 5:
                                                    cout<<"enter the publication to search for : ";
                                                    gets(wd);
                                                    x=2;
                                                    search(wd,x,t);
                                                    break;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            break;
                        case 5:
                            while(1)
                            {
                                clrscr();
                                cout<<"===============================================================================\n"
                                    <<"\tYour Purchase history\n"
                                    <<"===============================================================================\n";
                                gotoxy(1,5);
                                cout<<"Sno.";
                                gotoxy(25,5);
                                cout<<"Name of Book";
                                gotoxy(54,5);
                                cout<<"qty";
                                gotoxy(65,5);
                                cout<<"price/book"<<endl;
                                sum1=0;
                                f3.open("his.dat",ios::binary|ios::in);
                                int c,i=0;
                                while(f3.read((char*)&h,sizeof(h)))
                                {
                                    c=h.chkuname(user1);
                                    if(c==0)
                                    {
                                        h.showinfo1(i);
                                        i++;
                                    }
                                }
                                f3.close();
                                cout<<endl<<endl<<"\t\t\t\t\tTotal purchase= Rs"<<sum1;
                                gotoxy(5,22);
                                cout<<"go back";
                                ch4=retkey(2,22,1,21);
                                if(ch4==1)
                                {
                                    break;
                                }
                            }
                            break;
                        }
                    }
                    p=-1;
                }
                break;
			case 9:
                exit(0);

            }
        }
    }
}

//######################## END OF PROGRAM ################################
