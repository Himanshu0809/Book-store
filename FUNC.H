fstream f1,f2,f3;
int retkey(int x,int y,int r,int height);
int t,qty,p=-1;
long int sum,sum1;
void load();
char user1[20];

//------------------------------------------------CLASS FOR HISTORY (records) ------------------------------------------
class history
{
    char uname[50],bname[70];
    int copy,price;
public:
    void copyname(char* t);
    void copyqty(int t);
    void copybook(char* t);
    void copyprice(int t);
    void showinfo(int t);
    void showinfo1(int i);
    int chkuname(char* t);
} h;

int history::chkuname(char* t)                     //matching username
{
    int c;
    c=strcmpi(uname,t);
    return c;
}

void history::showinfo1(int i)                 //display information
{
    gotoxy(4,7+i);
    cout<<i+1;
    gotoxy(16,7+i);
    cout<<bname;
    gotoxy(55,7+i);
    cout<<copy;
    gotoxy(66,7+i);
    cout<<price;
    sum1+=price*copy;
}

void history::showinfo(int i)                  //display information
{
    gotoxy(4,7+i);
    cout<<uname;
    gotoxy(16,7+i);
    cout<<bname;
    gotoxy(55,7+i);
    cout<<copy;
    gotoxy(66,7+i);
    cout<<price;
    sum1+=price*copy;
}

void history::copyprice(int t)
{
    price=t;
}

void history::copyname(char* t)
{
    strcpy(uname,t);
}

void history::copyqty(int t)
{
    copy=t;
}

void history::copybook(char* t)
{
    strcpy(bname,t);
}

//-----------------------------------CLASS FOR BOOK-----------------------------------------

class book
{
    int id,price,year,copies;
    char fname[20],sname[20],title[20],pub[30],description[50],genre[10];
public:
    void input();
    void output();
    char* ret_title();
    int matchgenre(char* n);
    int matchtitle(char* n1);
    int matchauthor(char*n,char* m);
    int matchpublication(char* n2);
    void rettitle();
    void showhistory();
    void copydec();
    int retprice();
    int retcopies();
} s;

int book::retcopies()
{
    return copies;
}

int book::retprice()
{
    return price;
}

void book::showhistory()
{
    gotoxy(13,8);
    cout<<title;
    gotoxy(54,8);
    cout<<price;
    gotoxy(67,8);
    cout<<qty;
    sum=qty*price;
}

void book::rettitle()
{
    cout<<title;
}

char* book::ret_title()
{
    return title;
}

int book::matchpublication(char* n)
{
    int c;
    c=strcmpi(n,pub);
    return c;
}

void book::copydec()
{
    copies-=qty;
}

int book::matchauthor(char*n,char* m)
{
    int c,k;
    c=strcmpi(n,fname);
    k=strcmpi(m,sname);
    if(c==0&&k==0)
        return 0;
    else
        return 1;
}

int book::matchgenre(char* n)
{
    int c;
    c=strcmpi(n,genre);
    return c;
}

int book::matchtitle(char* n1)
{
    int c;
    c=strcmpi(n1,title);
    return c;
}

void book::input()                          //input
{
    cout<<"enter title               : ";
    gets(title);
    cout<<"enter book id             : ";
    cin>>id;
    cout<<"enter auther's first name : ";
    gets(fname);
    cout<<"enter author's last name  : ";
    gets(sname);
    cout<<"enter the publication     : ";
    gets(pub);
    cout<<"enter genre               : ";
    gets(genre);
    cout<<"enter price               : ";
    cin>>price;
    cout<<"enter publishing year     : ";
    cin>>year;
    cout<<"enter number of copies    : ";
    cin>>copies;
    cout<<"book's desription         : ";
    gets(description);
    f1.open("books.dat",ios::binary|ios::out|ios::app);
    f1.write((char*)&s,sizeof(s));
    f1.close();
}

void book::output()                          //output
{
    cout<<"title              : "<<title<<endl
           <<"book id            : "<<id<<endl
           <<"author's name      : "<<fname<<" "<<sname<<endl
           <<"genre              : "<<genre<<endl
           <<"price              : "<<price<<endl
           <<"publication        : "<<pub<<endl
           <<"publishing year    : "<<year<<endl
           <<"number of copies   : "<<copies<<endl
           <<"book's desription  : "<<description<<endl;
}

//-----------------------------CLASS FOR USERS------------------------------------------------
class user
{
    char f_name[20],l_name[20],password[20],usernm[20],mob[11];
public:
    void create_acc();
    void show_acc();
    int matchuser(char* n);
    void retusername();
    char* retpass();
    void change(int c);
} u;

void user::retusername()
{
    cout<<f_name<<" "<<l_name;
}

char* user::retpass()
{
    return password;
}

int user::matchuser(char* n)
{
    int c;
    c=strcmpi(n,usernm);
    return c;
}

void user::create_acc()
{
    cout<<"\t\t\tCREATING ACCOUNT\n";
    cout<<"\n\t1. First name        :\t ";
    gets(f_name);
    cout<<"\n\t2. Last name         :\t ";
    gets(l_name);
    cout<<"\n\t3. Mobile            :\t ";
    cin>>mob;
    cout<<"\n\t4. Username          :\t ";
    gets(usernm);
    cout<<"\n\t5. Set Password      :\t ";
    gets(password);
}

void user::show_acc()
{
cout<<"\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl
        <<"\t\t\t\tACCOUNT"<<endl
        <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"                             
<< endl<<endl
        <<"\t1. First name\t:\t "<<f_name<<endl<<endl
        <<"\t2. Last name \t:\t "<<l_name<<endl<<endl
        <<"\t3. Mobile      \t:\t "<<mob<<endl<<endl
        <<"\t4. Username \t:\t "<<usernm<<endl<<endl
        <<"\t5. Password  \t:\t "<<password;
}

void user::change(int c)
{
    clrscr();
    cout<<"\n\n\n\n";
    switch(c)
    {
    	case 1:  cout<<"\t\tfirst name           : "<<f_name<<endl
                     	         <<"\t\tre-enter first name  : ";
          	  gets(f_name);
        	     	  break;
    	case 2:  cout<<"\t\tlast name            : "<<l_name<<endl
         		        <<"\t\tre-enter last name   : ";
        	        	  gets(l_name);
        	        	  break;
     	case 3:  cout<<"\t\tmobile no.           : "<<mob<<endl
         		        <<"\t\tre-enter mobile no.  : ";
        	         	  gets(mob);
       	     	  break;
    	case 4:   cout<<"\t\tusername             : "<<usernm<<endl
            	         <<"\t\tre-enter username    : ";
     	  gets(usernm);
     	  break;
    	case 5:  cout<<"\t\tpassword             : "<<password<<endl
          	        <<"\t\tre-enter password    : ";
        	    	 gets(password);
        	     	 break;
    }
}

//------------------------------------CLASS ENDS-------------------------------------------------------

//-------------------------------------FUNCTIONS START HERE-------------------------------------

void enquiry()		//terms and conditions
{
    clrscr();
    cout<<"\n\t\t\tTERMS AND CODITIONS"<<endl<<endl
           <<"1. We will send products to the customer as soon as practicable after it"<<endl
           <<"   receives payment."<<endl<<endl
           <<"2. If the product is defective, customer has to give the details and return it"<<endl
           <<"   within 2 days of purchase. your product will:-"<<endl
           <<"\teither be replaced "<<endl
           <<"\tor money will be refuded"<<endl<<endl
           <<"3. The customer agrees that the content which the customer accesses, views or "<<endl
           <<"   downloads and the software used to create it remains the intellectual"<<endl
           <<"   property of us"<<endl<<endl
           <<"4. The customer's personal details will not be sold or leased to any third party"<<endl
           <<"\n\n\t\tPRESS ANY KEY TO GO BACK "<<endl;
    getch();
}

int password(char* c)             //for checking password
{
    char ch[20]="              ";
    int i=0;
    cout<<"enter password : ";
    while(1)
    {
        ch[i]=getch();
        if(ch[i]!=8&&ch[i]!=13)
        {
            cout<<"*";
            i++;
        }
        if(ch[i]==13)
        {
            ch[i]='\0';
            break;
        }
        else if(ch[i]==8)
        {
            cout<<"\b";
            clreol();
            ch[i]='~';
            i--;
        }
    }
    if(strcmp(ch,c)==0)
        return 0;
    else
        return 1;
}

int chkaccess()		//for entering as guest/admin
{
    int c;
    while(1)
    {
        clrscr();
        cout<<"\n\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl
               <<"\n\t\t\t\tWELCOME\n"
               <<"\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        delay(200);
        cout<<"\n\n\n\n\n\t\t\t\tenter as guest "
               <<"\n\n\t\t\t\tenter as administrator "
               <<"\n\n\t\t\t\texit program";
        c=retkey(31,10,3,9);
        switch(c)
        {
        	      case 1:  c=1;
            	       return c;
        	      case 3:  int q,n=1;
            	       char nm[20];
            	       clrscr();
            	       gotoxy(20,10);
            	       cout<<"enter username : ";
            	       gets(nm);
            	       if(strcmpi("admin",nm)==0)
                	       n=0;
            	       gotoxy(20,12);
           	       q=password("password");
            	       if(q==0&&n==0)
           	       {
                		c=2;
                		clrscr();
                		cout<<"\n\n\n\t\t\tWELCOME ADMIN";
                		delay(700);
                		return c;
            	       }
            	       else
            	       {
                		cout<<"\ninvalid credentials";
                		getch();
           	       }
            	       break;
        	     case 5:  exit(0);
        }
    }
}

void search(char* wd,int x,int t)      	//matching title/genre/publication
{
    while(1)
    {
        int n,flag=0,a=0,b[20],i=0,c;
        f1.open("books.dat",ios::binary|ios::in);
        clrscr();
        while(f1.read((char*)&s,sizeof(s)))
        {
            if(x==1)
                n=s.matchtitle(wd);
            else if(x==0)
                n=s.matchgenre(wd);
            else if(x==2)
                n=s.matchpublication(wd);
            if(n==0)
            {
                cout<<"\n\n\t\t"<<flag+1<<". ";
                s.rettitle();
                flag++;
                b[i]=a;
                i++;
            }
            a++;
        }
        cout<<"\n\n\t\t"<<"  #go back";
        f1.close();
        if(flag==0)
        {
            clrscr();
            cout<<"\nno books found";
            getch();
            break;
        }
        else
        {
            c=retkey(9,3,i+1,2);
            if(c==((2*(i+1))-1))
                break;
            clrscr();
            i=0;
            int recno=-1;
            f1.open("books.dat",ios::binary|ios::in|ios::out);
            while(f1.read((char*)&s,sizeof(s)))
            {
                recno++;
                if(i==b[((c+1)/2)-1])
                {
                    s.output();
                    if(t==1)
                    {
                        int z;
                        cout<<"\n\t\tbuy"
                            <<"\n\n\t\tgo back";
                        z=retkey(10,11,2,10);
                        if(z==1)
                        {
                            if(p!=0)
                            {
                                clrscr();
                                cout<<"\n\n\n\n\n\t\t\tYOU HAVE TO LOGIN FIRST";
                                getch();
                            }
                            else if((s.retcopies())<=0)
                            {
                                clrscr();
                                cout<<"\n\n\n\n\n\t\t\tSORRY..THE BOOK IS OUT OF STOCK";
                                getch();
                            }
                            else
                            {
                                gotoxy(45,11);
                                cout<<"enter quantity : ";
                                cin>>qty;
                                load();
                                if(s.retcopies()-qty<0)
                                {
                                    cout<<"\n\n\n\n\n\t\t\tSORRY..only  "<<s.retcopies()<< " books available";
                                    getch();
                                }
                                else {
                                       cout<<"===============================================================================\n"
                                        <<"\t\t!!!!!!!!!!!!!!!       BILL       !!!!!!!!!!!!!!! \n"
                      		                        <<"===============================================================================\n";
                                    gotoxy(18,5);
                                    cout<<"Name of Book";
                                    gotoxy(54,5);
                                    cout<<"Price";
                                    gotoxy(65,5);
                                    cout<<"Qty"<<endl;
                                    sum=0;
                                    s.showhistory();
                                    gotoxy(54,11);
                                    cout<<"Grand Total= Rs"<<sum;
                                    int i=0;
                                    gotoxy(20,18);
                                    delay(200);
                                    cout<<". ";
                                    delay(200);
                                    cout<<". ";
                                    delay(200);
                                    cout<<". ";
                                    delay(100);
                                    cout<<" BOOK PURCHASED ";
                                    delay(200);
                                    while(i<5)
                                    {
                                        gotoxy(30,20);
                                        cout<<"                         ";
                                        delay(400);
                                        gotoxy(30,20);
                                        cout<<"PRESS ANY KEY TO CONTINUE";
                                        i++;
                                        delay(400);
                                    }
                                    getch();
                                    h.copyqty(qty);
                                    h.copybook(s.ret_title());
                                    h.copyprice(s.retprice());
                                    f3.open("his.dat",ios::binary|ios::out|ios::app);
                                    f3.write((char*)&h,sizeof(h));
                                    f3.close();
                                    f1.seekg(recno*sizeof(s),ios::beg);
                                    s.copydec();
                                    f1.seekg(recno*sizeof(s),ios::beg);
                                    f1.write((char*)&s,sizeof(s));
                                }
                            }
                        }
                        else if(z==3)
                            break;

                    }
                    break;
                }
                i++;
            }
            if(t==2)
                getch();
            f1.close();
        }
    }
}

void search(char* wd,char*wd1)        //matching author’s name
{
    int n,flag=0,a=0,b[20],i=0,c;
    f1.open("books.dat",ios::binary|ios::in);
    clrscr();
    while(f1.read((char*)&s,sizeof(s)))
    {
        n=s.matchauthor(wd,wd1);
        if(n==0)
        {
            cout<<endl<<flag+1<<". ";
            s.rettitle();
            flag++;
            b[i]=a;
            i++;
        }
        a++;
    }
    f1.close();
    if(flag==0)
    {
        clrscr();
        cout<<"\nno books found";
        getch();
    }
    else
    {
        cout<<"\n\nenter number to get info for the book : ";
        cin>>c;
        getch();
        clrscr();
        i=0;
        f1.open("books.dat",ios::binary|ios::in);
        while(f1.read((char*)&s,sizeof(s)))
        {
            if(i==b[c-1])
            {
                s.output();
                break;
            }
            i++;
        }
        getch();
        f1.close();
    }
}


int searchpass(char* wd)		//matching username
{
    int n=0,flag=0,c;
    char q[20];
    f2.open("accounts.dat",ios::binary|ios::in);
    while(f2.read((char*)&u,sizeof(u)))
    {
        n=u.matchuser(wd);
        if(n==0)
        {
            flag=1;
            h.copyname(wd);
            break;
        }
    }
    f2.close();
    if(flag==0)
    {
        c=password(wd);
        getch();
        return 0;
    }
    else
    {
        strcpy(q,u.retpass());
        c=password(q);
        if(c==0)
            return 1;
        else
            return 0;
    }
}

void load()
{
    clrscr();
    gotoxy(30,22);
    cout<<"~~~LOADING~~~ ";
    delay(200);
    cout<<".";
    delay(200);
    cout<<".";
    delay(200);
    cout<<".";
    delay(200);
    clrscr();
}

void cursor(int x,int y,int a)
{
    gotoxy(x,a);
    cout<<" ";
    gotoxy(x,y);
    cout<<">";
}

int retkey(int x,int y,int r,int height)    //function for accesing cursors
{
    int key=0,row=1,a=y;
    while(key!=7181)
    {
        cursor(x,y,a);
        a=y;
        key=bioskey(0);
        switch(key)
        {
        	   case 7181: return row;
        	   case 20480:  row+=2;
            		if(row>=(2*r)-1)
                			row=(2*r)-1;
            		y=height+row;
            		cursor(x,y,a);
            		break;
       	 case 18432:   row-=2;
            	           if(row<=1)
               			row=1;
            		y=height+row;
            		cursor(x,y,a);
            		break;
       }
    }
}

void user_info()    
{
    int flag1=0,c;
    f2.open("accounts.dat",ios::binary|ios::in);
    f2.seekg(0,ios::end);
    cout<<"\n\n No. of accounts are:  "<<f2.tellg()/sizeof(u)<<"\n\n-------------------------------------------------------------------------------"<<"\n\t\t\t\tLIST \n";
    f2.seekg(0,ios::beg);
    while(f2.read((char*)&u,sizeof(u)))
    {
        cout<<endl<<"\t"<<flag1+1<<". ";
        u.retusername();
        flag1++;
    }
    f2.close();
    if(flag1==0)
    {
        clrscr();
        cout<<"\nno user found";
        getch();
    }
    else
    {
        cout<<"\n\nenter number to get info for the user : ";
        cin>>c;
        clrscr();
        int i=1;
        f2.open("accounts.dat",ios::binary|ios::in);
        while(f2.read((char*)&u,sizeof(u)))
        {
            if(i==c)
            {
                u.show_acc();
                break;
            }
            i++;
        }
        getch();
        f2.close();
    }
}

void show_menu(int c)
{
    clrscr();
    switch(c)
    {
    case 1:
        cout<<"\n\t\t---------MYSTERY----------\n\n";
        search("mystery",0,t);
        break;
    case 3:
        cout<<"\n\t\t---------FANTASY----------\n\n";
        search("fantasy",0,t);
        break;
    case 5:
        cout<<"\n\t\t---------ROMANCE----------\n\n";
        search("romance",0,t);
        break;
    case 7:
        cout<<"\n\t\t---------SCIENCE-FICTION----------\n\n";
        search("science fiction",0,t);
        break;
    }
    getch();
}
//---------------------------------------FUNCTIONS ENDS----------------------------------------

