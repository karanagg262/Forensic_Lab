//*********************************************
//                 FORENSIC LAB
//*********************************************

//*********************************************
//                 HEADER FILES
//*********************************************
#include<fstream>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<string.h>
#include<process.h>
//  STRUCTURE FOR DATE
struct date1
{
  int dd,mm,yy;
};
//*********************************************
//         CLASS NAME : CADAVER
//*********************************************
class cadaver
{
  protected:
  int cid;
  char cnm[20];
  char csex;
  char cevi[30];
  public:
  cadaver()
  {
    cid=0;
    strcpy(cnm,"Name Not Alloted");
    csex='-n';
    strcpy(cevi,"Not Alloted");
  }
  void cidgnrt();
  void cgetdata()    //FUNCTION TO TAKE DATA
  {
    clrscr();
    int i;
    gotoxy(24,7);
    cout<<"**************************************";
    gotoxy(24,8);
    cout<<"   Cadaver ID : ";
    cidgnrt();
    cout<<cid;
    gotoxy(24,9);
    cout<<"   Enter Name : ";
    gets(cnm);
    gotoxy(24,10);
    cout<<"   Enter Sex (M/F) : ";
    cin>>csex;
    gotoxy(24,11);
    cout<<"   Enter any Evidences Founded : ";
    gets(cevi);
    gotoxy(24,12);
    cout<<"**************************************";
    cout<<endl;
 }

  void cshowdata()    //FUNCTION TO SHOW DATA
  {
    gotoxy(12,7);
    cout<<"**********************************************************";
    gotoxy(12,8);
    cout<<"*   Cadever #"<<cid<<" :";
    gotoxy(12,9);
    cout<<"*   Name : ";
    puts(cnm);
    gotoxy(12,10);
    cout<<"*   Sex : "<<csex;
    gotoxy(12,11);
    cout<<"*   Evidences Founded :";
    puts(cevi);
  }
  void changename(char nm[])  //FUNCTION TO CHANGE NAME
  {
    strcpy(this->cnm,nm);
  }
  void changecevi(char nm[]) //FUNCTION TO CHANGE EVIDENCES FOUND
  {
    strcpy(this->cevi,nm);
  }
  int getcid()          //FUNCTION TO RETURN ID NO.
  {
    return cid;
  }
};
//*********************************************
//         CLASS NAME : EMPLOYEE
//*********************************************
class employee
{
  protected:
  int eid;
  char enm[20];
  char epos[20];
  char equal[30];
  char esex;
  int ecount;
  int eage;
  long esal;
  public:
  employee()
  {
    eid=0;
    strcpy(enm,"Name Not Alloted");
    strcpy(equal,"Not Alloted");
    esex='-n';
    eage=0;
    esal=0;
    ecount=0;
  }
  void eidgnrt();
  void egetdata()       //FUNCTION TO GET DATA
  {
    clrscr();
    gotoxy(24,7);
    cout<<"*****************************" ;
    gotoxy(24,8);
    cout<<"   ID No. : ";
    eidgnrt();
    cout<<eid;
    gotoxy(24,9);
    cout<<"   Enter Name : ";
    gets(enm);
    gotoxy(24,10);
    cout<<"   Qualification Done : ";
    gets(equal);
    gotoxy(24,11);
    cout<<"   Enter Sex (M/F) : ";
    cin>>esex;
    gotoxy(24,12);
    cout<<"   Enter Age : ";
    cin>>eage;
    gotoxy(24,13);
    cout<<"   Enter the Salary : ";
    cin>>esal;
    gotoxy(24,14);
    cout<<"******************************";
  }
  void eshowdata()       //FUNCTION TO SHOW DATA
  {
    gotoxy(24,7);
    cout<<"*********************************";
    gotoxy(24,8);
    cout<<"  ID No. : #"<<eid;
    gotoxy(24,9);
    cout<<"  Qualification Done : "<<equal;
    gotoxy(24,10);
    cout<<"  Name : "<<enm;
    gotoxy(24,11);
    cout<<"  Sex : "<<esex;
    gotoxy(24,12);
    cout<<"  Age : "<<eage;
    gotoxy(24,13);
    cout<<"  Salary :"<<esal;
    gotoxy(24,14);
    cout<<"*********************************";
    gotoxy(24,15);
    cout<<"Press any Key to Continue...";
    getch();
  }
  void changeeid(int id)        //FUNCTION TO CHANGE ID NO.
  {
    eid=id;
  }
  void changeename(char nam[])    //FUNCTION TO CHANGE NAME
  {
    strcpy(this->enm,nam);
  }
  void changeequal(char nam[])   //FUNCTION TO UPDATE QUALIFICATION
  {
    strcpy(this->equal,nam);
  }
  void changeeage(int age)    //FUNCTION TO UPDATE AGE
  {
    eage=age;
  }
  void changeesal(int sal)     //FUNCTION TO UPDATE SALARY
  {
    esal=sal;
  }
  void changeecount()       //FUNCTION TO INCREMENT ECOUNT
  {
    ecount++;
  }
  void changec()         //FUNCTION TO DECREMENT ECOUNT
  {
    ecount--;
  }
  int geteid()         //FUNCTION TO RETURN ID NO.
  {
    return eid;
  }
  int getecount()       //FUNCTION TO RETURN ECOUNT
  {
  return ecount;
  }
};
//*********************************************
//         CLASS NAME : FORENSIC
//*********************************************
class forensic:public cadaver,public employee
{
 date1 doa;
 char obs[30];
 public:
 forensic()
 {
   strcpy(obs,"NOT ALLOTED");
   doa.dd=1;
   doa.mm=1;
   doa.yy=2014;
 }
 void getfor()       //FUNCTION TO GET DATA
 {
   struct date td;
   getdate(&td);
   doa.dd=td.da_day;
   doa.mm=td.da_mon;
   doa.yy=td.da_year;
   gotoxy(12,12);
   cout<<"*   Date of Observation is : ";
   cout<<doa.dd<<"/"<<doa.mm<<"/"<<doa.yy<<endl;
   gotoxy(12,13);
   cout<<"*   Enter the Observation Made ";
   gotoxy(12,14);
   gets(obs);
 }
 void putfor()    //FUNCTION TO SHOW DATA
 {
   gotoxy(12,12);
   cout<<"*   Date of Observation is : ";
   cout<<doa.dd<<"/"<<doa.mm<<"/"<<doa.yy;
   gotoxy(12,13);
   cout<<"*   Observation Made : ";
   puts(obs);
 }
 void changeccobs(char ccobs[])  //FUNCTION TO CHANGE OBSERVATIONS
 {
   strcpy(this->obs,ccobs);
 }
};
void employee :: eidgnrt()   //FUNCTION TO SELF GENERATE EMPLOYEE ID
{
  employee e;
  ifstream f1;
  f1.open("employee",ios::binary);
  if(!f1)
  eid=1;
  else
  {
    while(!f1.eof())
    {
      f1.read((char*)&e,sizeof(e));
    }
    f1.close();
    eid=e.geteid()+1;
  }
}
void cadaver :: cidgnrt()    //FUNCTION TO SELF GNERATE CADAVER ID
{
  forensic c;
  ifstream f1;
  f1.open("cadaver",ios::binary);
  if(!f1)
  cid=1;
  else
  {
    while(!f1.eof())
    {
      f1.read((char*)&c,sizeof(c));
    }
    f1.close();
    cid=c.cid+1;
  }
}
void cgetrecord()  //FUNCTION TO PUT CADAVER DETAILS
{
  clrscr();
  forensic f;
  ofstream f1;
  ifstream f2;
  employee e;
  int k,flag;
  f1.open("cadaver" ,ios::binary|ios::app);
  f.cgetdata();
  cout<<"Employee Id\t No. of cadavers\n";
  f2.open("employee",ios::binary|ios::in);
  f2.read((char*)&e,sizeof(e));
  while(!f2.eof())
  {
    cout<<e.geteid()<<"\t\t"<<e.getecount()<<"\n";
    f2.read((char*)&e,sizeof(e));
  }
  f2.close();
  lb:
  flag=0;
  cout<<"Enter Id of the employee you want to choose\n";
  cin>>k;
  fstream f3;
  f3.open("employee",ios::binary|ios::in|ios::out);
  while(!f3.eof())
  {
    f3.read((char*)&e,sizeof(e));
    if(k==e.geteid())
    {
      flag=1;
      e.changeecount();
      f.changeeid(e.geteid());
      f3.seekg(f3.tellg()-sizeof(e));
      f3.write((char*)&e,sizeof(e));
      break;
    }
  }
  if(flag==0)
  {
    cout<<"Enter a valid Id\n Please enter again\n";
    goto lb;
  }
  f3.close();
  f1.write((char*)&f,sizeof(f));
  f1.close();
}
void fgetrecord()    //FUNCTION TO PUT FORENSIC RECORD
{
  clrscr();
  int n;
  forensic f;
  fstream f1;
  f1.open("cadaver" ,ios::binary|ios::out|ios::in);
  cout<<"Enter the cadaver id\n";
  cin>>n;
  while(!f1.eof())
  {
    f1.read((char*)&f,sizeof(f));
    if(n==f.getcid())
    {
      f.cshowdata();
      f.getfor();
      f1.seekg(f1.tellg()-sizeof(f));
      f1.write((char*)&f,sizeof(f));
      break;
    }
  }
  f1.close();
  getch();
}
void cshowrecord(int n)  //FUNCTION TO SHOW CADAVER RECORD
{
  clrscr();
  forensic f;
  int id;
  ifstream f2;
  f2.open("cadaver",ios::binary|ios::in);
  if(n==1)
  {
    f2.read((char*)&f,sizeof(f));
    if(!f2)
    cout<<"No Data to Show";
    else
    {
      while(!f2.eof())
      {
      f.cshowdata();
      f.putfor();
      gotoxy(12,14);
      cout<<"*   Employee Working on this Cadaver is of ID No. :"<<f.geteid();
      gotoxy(12,15);
      cout<<"*   Press Enter to Continue...";
      gotoxy(12,16);
      cout<<"**********************************************************";
      getch();
      f2.read((char*)&f,sizeof(f));
      }
    }
  }
  else if(n==2)
  {
    gotoxy(12,5);
    cout<<"Enter the Cadaver's ID No. : ";
    cin>>id;
    f2.read((char*)&f,sizeof(f));
    while(!f2.eof())
    {
      if(id==f.getcid())
      {
	f.cshowdata();
	f.putfor();
	gotoxy(12,14);
	cout<<"*   Employee Working on this Cadaver is of ID No. :"<<f.geteid();
	gotoxy(12,15);
	cout<<"**********************************************************";
	getch();
	f2.read((char*)&f,sizeof(f));
      }
    }
  }
  f2.close();
}
void fshowrecord()      //FUNTION TO SHOW CADAVER RECORD
{                         //   (EMPLOYEE WISE
  clrscr();
  forensic f;
  int id;
  ifstream f2;
  f2.open("cadaver",ios::binary|ios::in);
  gotoxy(12,5);
  cout<<"Enter Employee Id : ";
  cin>>id;
  f2.read((char*)&f,sizeof(f));
  while(!f2.eof())
  {
    if(id==f.geteid())
    {
      f.cshowdata();
      f.putfor();
      gotoxy(12,14);
      cout<<"****************************************************";
      gotoxy(12,15);
      cout<<"Press any Key to Continue";
      getch();
    }
    else
    {
      cout<<"Data not Found";
      getch();
      break;
    }
    f2.read((char*)&f,sizeof(f));
  }
  f2.close();
  getch();
}
void egetrecord()    // FUNTION TO PUT EMPPLOYEE RECORD
{
  clrscr();
  employee e;
  ofstream f1;
  char ans='y';
  while (ans=='y')
  {
    f1.open("employee" ,ios::binary|ios::app);
    gotoxy(24,5);
    cout<<"Fill Employee Information";
    e.egetdata();
    f1.write((char*)&e,sizeof(e));
    f1.close();
    gotoxy(20,15);
    cout<<"Do you Want to Continue?(y/n) : ";
    cin>>ans;
  }

}
void eshowrecord(int n)  //FUNCTION TO SHOW EMPLOYEE RECORD
{
  clrscr();
  employee e;
  int ide;
  ifstream f2;
  f2.open("employee",ios::binary|ios::in);
  if(n==1)
  {
    f2.read((char*)&e,sizeof(e));
    while(!f2.eof())
    {
      e.eshowdata();
      f2.read((char*)&e,sizeof(e));
    }
  }
  else if(n==2)
  {
    cout<<"Enter the Employee's ID No.\n";
    cin>>ide;
    f2.read((char*)&e,sizeof(e));
    while(!f2.eof())
    {
      if(ide==e.geteid())
      e.eshowdata();
      f2.read((char*)&e,sizeof(e));
    }
  }
  f2.close();
  getch();
}
void cmodify()  //FUNCTION TO MODIFY CADAVER
{
  clrscr();
  int a=0,r,p=0;
  fstream f1;
  forensic f;
  gotoxy(15,4);
  cout<<"Enter Cadaver ID No. : ";
  cin>>r;
  f1.open("cadaver",ios::binary|ios::in|ios::out);
  while(!f1.eof())
  {
    f1.read((char*)&f,sizeof(f));
    if(f.getcid()==r)
    {
      f.cshowdata();
      f.putfor();
      gotoxy(15,17);
      cout<<"1. Change Cadaver's Name";
      gotoxy(15,18);
      cout<<"2. Update the Evidences Found";
      gotoxy(15,19);
      cout<<"3. Update the Observations Done";
      gotoxy(15,20);
      cout<<"4. Back";
      gotoxy(15,21);
      cin>>a;
      p=1;
    }
    if(a==1)
    {
      clrscr();
      char cnam[20];
      gotoxy(24,7);
      cout<<"Enter Cadaver's Name : ";
      gets(cnam);
      f.changename(cnam);
      f1.seekg(f1.tellg()-sizeof(f));
      f1.write((char*)&f,sizeof(f));
    }
    else if(a==2)
    {
      clrscr();
      char ccevi[20];
      gotoxy(24,7);
      cout<<"Enter Evidences Found : ";
      gets(ccevi);
      f.changecevi(ccevi);
      f1.seekg(f1.tellg()-sizeof(f));
      f1.write((char*)&f,sizeof(f));
    }
    else if(a==3)
    {
      clrscr();
      char ccobs[20];
      gotoxy(24,7);
      cout<<"Enter Observations done : ";
      gets(ccobs);
      f.changeccobs(ccobs);
      f1.seekg(f1.tellg()-sizeof(f));
      f1.write((char*)&f,sizeof(f));
    }
    else if(a==4)
    break;
    if(p)
    break;
  }
  f1.close();
}
void emodify()  //FUNCTION TO MODIFY EMPLOYEE
{
  clrscr();
  int a=0,r,p=0;
  fstream f1;
  employee e;
  gotoxy(15,4);
  cout<<"Enter Employee ID No. : ";
  cin>>r;
  f1.open("employee",ios::binary|ios::in|ios::out);
  while(!f1.eof())
  {
    f1.read((char*)&e,sizeof(e));
    if(e.geteid()==r)
    {
      e.eshowdata();
      gotoxy(24,17);
      cout<<"1. Change Employee's Name";
      gotoxy(24,18);
      cout<<"2. Change Employee's Qualification";
      gotoxy(24,19);
      cout<<"3. Update Employee's Age";
      gotoxy(24,20);
      cout<<"4. Upadte Employee's Salary";
      gotoxy(24,21);
      cout<<"5. Back";
      gotoxy(24,22);
      cin>>a;
      p=1;
    }
    if(a==1)
    {
      clrscr();
      char enam[20];
      gotoxy(24,7);
      cout<<"Enter Employee's Name : ";
      gets(enam);
      e.changeename(enam);
      f1.seekg(f1.tellg()-sizeof(e));
      f1.write((char*)&e,sizeof(e));
    }
    else if(a==2)
    {
      clrscr();
      char equa[20];
      gotoxy(24,7);
      cout<<"Enter Employee's Qualification : ";
      gets(equa);
      e.changeequal(equa);
      f1.seekg(f1.tellg()-sizeof(e));
      f1.write((char*)&e,sizeof(e));
    }
    else if(a==3)
    {
      clrscr();
      int eag;
      gotoxy(24,7);
      cout<<"Enter Employee's Age : ";
      cin>>eag;
      e.changeeage(eag);
      f1.seekg(f1.tellg()-sizeof(e));
      f1.write((char*)&e,sizeof(e));
    }
    else if(a==4)
    {
      clrscr();
      int esa;
      gotoxy(24,7);
      cout<<"Enter Employee's Salary : ";
      cin>>esa;
      e.changeesal(esa);
      f1.seekg(f1.tellg()-sizeof(e));
      f1.write((char*)&e,sizeof(e));
    }
    else if(a==5)
    break;
    if(p)
    break;
  }
  f1.close();
}
void archive()   //FUNCTION TO OLD DATA OF CADAVER
{
  clrscr();
  forensic f;
  ifstream f1;
  int i,id;
  gotoxy(24,6);
  cout<<"************************************";
  gotoxy(24,7);
  cout<<"*        Enter your Choice         *";
  gotoxy(24,8);
  cout<<"*  (1) Show a Particular Record    *";
  gotoxy(24,9 );
  cout<<"*  (2) Show all Records            *";
  gotoxy(24,10);
  cout<<"*                                  *";
  gotoxy(24,11);
  cout<<"************************************";
  gotoxy(28,10);
  cin>>i;
  if(i==1)
  {
    clrscr();
    cout<<"Enter Cadaver's ID\n";
    cin>>id;
    f1.open("archives",ios::binary);
    f1.read((char*)&f,sizeof(f));
    while(!f1.eof())
    {
      if(id==f.getcid())
      f.cshowdata();
      f.putfor();
      cout<<endl;
      f1.read((char*)&f,sizeof(f));
    }
    f1.close();
  }
  else if(i==2)
  {
    clrscr();
    f1.open("archives",ios::binary);
    f1.read((char*)&f,sizeof(f));
    while(!f1.eof())
    {
      f.cshowdata();
      f.putfor();
      cout<<endl;
      getch();
      f1.read((char*)&f,sizeof(f));
    }
    f1.close();
  }
  getch();

}
void emodify(int r)   //FUNCTION TO DECREMENT EMPLOYEE NUMBER
{                     //  (AFTER REMOVING A CADAVER)
  fstream f1;
  employee e;
  f1.open("employee",ios::binary|ios::in|ios::out);
  while(!f1.eof())
  {
    f1.read((char*)&e,sizeof(e));
    if(e.geteid()==r)
    {
      e.changec();
      f1.seekg(f1.tellg()-sizeof(e));
      f1.write((char*)&e,sizeof(e));
    }
  }
}
void cdelete()    //FUNCTION TO DELETE A CADAVER
{
  clrscr();
  forensic f;
  ifstream f1;
  ofstream f3;
  int n,k,flag=0;
  f1.open("cadaver",ios::binary);
  if(!f1)
  {
     cout<<"File could not be Open !! Press any Key...";
     getch();
     return;
  }
  else
  {
    ofstream f2;
    f2.open("Temp",ios::binary);
    cout<<"Enter Cadaver Id to be Deleted\n";
    cin>>n;
    f1.seekg(0,ios::beg);
    while(f1.read((char *)&f, sizeof(f)))
    {
      if(f.getcid()!=n)
      {
	f2.write((char *)&f, sizeof(f));
      }
      else
      {
	f3.open("archives",ios::binary|ios::app);
	f3.write((char *)&f,sizeof(f));
	f3.close();
	flag=1;
      }
    }
    f1.close();
    f2.close();
    remove("cadaver");
    rename("Temp","cadaver");
    cout<<"\n\n\tRecord Deleted ..";
  }
  if(flag==1)
  emodify(n);
  getch();
}
void edelete()    //FUNCTION TO DELETE A EMPLOYEE
{
  clrscr();
  employee e;
  ifstream f1;
  int n;
  char found='f',confirm='n';
  f1.open("employee",ios::binary);
  if(!f1)
  {
     cout<<"File could not be Open !! Press any Key...";
     getch();
     return;
  }
  ofstream f2;
  f2.open("Temp",ios::binary|ios::app);
  cout<<"Enter Employee Id to be Deleted\n";
  cin>>n;
  f1.read((char *)&e, sizeof(e));
  while(!f1.eof())
  {
    if(e.geteid()==n)
    {
      e.eshowdata();
      found='t';
      gotoxy(24,17);
      cout<<"Are you Sure(y/n) : ";
      cin>>confirm;
      if(confirm=='n')
      f2.write((char *)&e, sizeof(e));
      if(confirm=='y')
      cout<<"\n\n\tRecord Deleted ..";
    }
    else
    f2.write((char *)&e, sizeof(e));
    f1.read((char *)&e, sizeof(e));
  }
  if(found=='f')
  cout<<"Record not Found\n";
  f1.close();
  f2.close();
  remove("employee");
  rename("Temp","employee");
  getch();
}
void agtime()    //FUNCTION TO HAVE PRESENT TIME
{
  struct date td;
  getdate(&td);
  struct time tt;
  gettime(&tt);
  int m=td.da_mon,d=td.da_day;
  cout<<d<<"/"<<m<<"/"<<td.da_year<<endl;
  int h=tt.ti_hour,min=tt.ti_min,s=tt.ti_sec;
  gotoxy(71,1);
  cout<<h<<":"<<min<<":"<<s<<endl;
}
void cadavermenu()   //FUNCTION HAVING MENU FOR CADAVER
{
 agtime();
 int a;
 label:
 clrscr();
 gotoxy(24,7);
 cout<<"***********************************";
 gotoxy(24,8);
 cout<<"*                                 *";
 gotoxy(24,9);
 cout<<"*         Cadaver Menu            *";
 gotoxy(24,10);
 cout<<"*     1.Show all Cadaver          *";
 gotoxy(24,11);
 cout<<"*     2.Modify Cadaver            *";
 gotoxy(24,12);
 cout<<"*     3.Delete a cadaver          *";
 gotoxy(24,13);
 cout<<"*     4.Enter the observations    *";
 gotoxy(24,14);
 cout<<"*     5.Old Files                 *";
 gotoxy(24,15);
 cout<<"*     6.Back                      *";
 gotoxy(24,16);
 cout<<"*       Enter the choice          *";
 gotoxy(24,17);
 cout<<"*                                 *";
 gotoxy(24,18);
 cout<<"***********************************";
 gotoxy(39,17);
 cin>>a;
 switch(a)
  {
    case 1: cshowrecord(1);
	    break;
    case 2: cmodify();
	    break;
    case 3: cdelete();
	    break;
    case 4: fgetrecord();
	    break;
    case 5: archive();
	    break;
    case 6: break;
    default: exit(0);
  }
  if(a!=6)
  goto label;
}
void employeemenu()  //FUNCTION HAVING MENU FOR EMPLOYEE
{
  agtime();
  int a;
  label:
  clrscr();
  gotoxy(24,7);
  cout<<"***********************************";
  gotoxy(24,8);
  cout<<"*                                 *";
  gotoxy(24,9);
  cout<<"*          Employee Menu          *";
  gotoxy(24,10);
  cout<<"*                                 *";
  gotoxy(24,11);
  cout<<"*      1.Add a new Employee       *";
  gotoxy(24,12);
  cout<<"*      2.Display all Employees    *";
  gotoxy(24,13);
  cout<<"*      3.Modify a Employee        *";
  gotoxy(24,14);
  cout<<"*      4.Remove a Employee        *";
  gotoxy(24,15);
  cout<<"*      5.Show all cadaver for a   *";
  gotoxy(24,16);
  cout<<"*        particular employee      *";
  gotoxy(24,17);
  cout<<"*      6.Back                     *";
  gotoxy(24,18);
  cout<<"*         Enter the Choice        *";
  gotoxy(24,19);
  cout<<"*                                 *";
  gotoxy(24,20);
  cout<<"***********************************";
  gotoxy(41,19);
  cin>>a;
  switch(a)
  {
    case 1: egetrecord();
	    break;
    case 2: eshowrecord(1);
	    break;
    case 3: emodify();
	    break;
    case 4: edelete();
	    break;
    case 5: fshowrecord();
	    break;
    case 6: break;
    default: exit(0);
 }
 if(a!=6)
 goto label;
}
void admin()  //FUNCTION HAVING ADMINISTRATOR BLOCK
{
 agtime();
 int a;
 label:
 clrscr();
 gotoxy(24,7);
 cout<<"***********************************";
 gotoxy(24,8);
 cout<<"*                                 *";
 gotoxy(24,9);
 cout<<"*       Administrator Menu        *";
 gotoxy(24,10);
 cout<<"*                                 *";
 gotoxy(24,11);
 cout<<"*         1.Cadaver               *";
 gotoxy(24,12);
 cout<<"*         2.Employee              *";
 gotoxy(24,13);
 cout<<"*         3.Back                  *";
 gotoxy(24,14);
 cout<<"*       Enter the Choice          *";
 gotoxy(24,15);
 cout<<"*                                 *";
 gotoxy(24,16);
 cout<<"***********************************";
 gotoxy(39,15);
 cin>>a;
 switch(a)
 {
 case 1: cadavermenu();
	 break;
 case 2: employeemenu();
	 break;
 case 3: break;
 default: exit(0);
 }
 if(a!=3)
 goto label;
}
void password()  //FUNCTION HAVING PASSWORD
{                  //(TO ACESS ADMIN BLOCK)
  clrscr();
  int i;
  char apass[20];
  gotoxy(24,10);
  cout<<"Enter Administrator Password\n";
  gotoxy(35,11);
  for(i=0;;i++)
  {
    apass[i]=getch();
    if(apass[i]=='\r')
    break;
    cout<<"*";
  }
  apass[i]='\0';
  cout<<endl;
  if(((strcmp("knc",apass)==0)||(strcmp("KNC",apass)==0)))
  admin();
  else
  {
    cout<<"Acess Denied\n";
    getch();
  }
}
void menu()  //FUNCTION HAVING THE MAIN MENU
{
  int a,b;
  label:
  clrscr();
  agtime();
  gotoxy(24,7);
  cout<<"-----------------------------";
  gotoxy(24,8);
  cout<<"|         Main Menu         |";
  gotoxy(24,9);
  cout<<"|                           |";
  gotoxy(24,10);
  cout<<"|    1.Add a new Cadaver    |";
  gotoxy(24,11);
  cout<<"|    2.Show a Cadaver       |";
  gotoxy(24,12);
  cout<<"|    3.Show an Employee     |";
  gotoxy(24,13);
  cout<<"|    4.Admin                |";
  gotoxy(24,14);
  cout<<"|    5.Logout               |";
  gotoxy(24,15);
  cout<<"|                           |";
  gotoxy(24,16);
  cout<<"|      Enter the Choice:    |";
  gotoxy(24,17);
  cout<<"-----------------------------";
  gotoxy(49,16);
  cin>>a;
  switch(a)
  {
    case 1: cgetrecord();
	    break;
    case 2: cshowrecord(2);
	    break;
    case 3: eshowrecord(2);
	    break;
    case 4: password();
	    break;
    case 5: exit(0);
    default: exit(0);
  }
  goto label;
}
void page()   //FUNCTION HAVING WELCOME SCREEN
{
  clrscr();
  long k;
  int run1,run2=3;
  while(run2>0)
  {
    run1=2;
    while(run1>0)
    {
      for(int i=25;i<47;i++)
      {
	gotoxy(i,12);
	cout<<"*****";
	gotoxy(31,13);
	if(run2==3)
	cout<<"Customising the Lab";
	else if(run2==2)
	cout<<"Retrieving Data";
	else
	cout<<"Wait for a Moment";
	for(long k=0;k<2000000;k++);
	clrscr();
      }
      run1--;
    }
    run2--;
  }
  clrscr();
  long l;
  gotoxy(15,5);
  cout<<" ***        *** ";
  gotoxy(15,6);
  cout<<"*****        ***";
  gotoxy(15,7);
  cout<<"*** **       ***";
  gotoxy(15,8);
  cout<<"***  **      ***";
  gotoxy(15,9);
  cout<<"***   **     ***";
  gotoxy(15,10);
  cout<<"***    **    ***";
  gotoxy(15,11);
  cout<<"***     **   ***";
  gotoxy(15,12);
  cout<<"***      **  ***";
  gotoxy(15,13);
  cout<<"***       ** ***";
  gotoxy(15,14);
  cout<<"***        *****";
  gotoxy(15,15);
  cout<<" ***        *** ";
  for(l=0;l<8000000;l++);
  gotoxy(35,5);
  cout<<" ************";
  gotoxy(35,6);
  cout<<"************";
  gotoxy(35,7);
  cout<<"*** ";
  gotoxy(35,8);
  cout<<"*** ";
  gotoxy(35,9);
  cout<<"************";
  gotoxy(35,10);
  cout<<"************";
  gotoxy(35,11);
  cout<<"*** ";
  gotoxy(35,12);
  cout<<"*** ";
  gotoxy(35,13);
  cout<<"*** ";
  gotoxy(35,14);
  cout<<"*** ";
  gotoxy(35,15);
  cout<<" ***";
  for(l=0;l<8000000;l++);
  gotoxy(51,5);
  cout<<" *****";
  gotoxy(51,6);
  cout<<"*****";
  gotoxy(51,7);
  cout<<"*****";
  gotoxy(51,8);
  cout<<"*****";
  gotoxy(51,9);
  cout<<"*****";
  gotoxy(51,10);
  cout<<"*****";
  gotoxy(51,11);
  cout<<"*****";
  gotoxy(51,12);
  cout<<"*****";
  gotoxy(51,13);
  cout<<"*****";
  gotoxy(51,14);
  cout<<"****************";
  gotoxy(51,15);
  cout<<" ****************";
  for(l=0;l<8000000;l++);
  cout<<"\n\n\t\t\t    NATIONAL FORENSIC LAB";
  cout<<"\n\n\n\t\t\t   Press Enter to Continue";
  cout<<"\t\t\t\t";
  getch();
  menu();
}
int main()  //VOID MAIN FUNCTION
{
  clrscr();
  page();
  return 0;
}
