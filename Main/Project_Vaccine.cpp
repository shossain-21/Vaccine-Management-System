#include<stdio.h>
#include<iostream>
#include<fstream>
#include<conio.h>
#include<string.h>
#include<windows.h>
#include<iomanip>
#include<time.h>
#define num_of_vaccine 1000
using namespace std;
int password();
void menu();
void show();
class vaccine
{
    int age;
    int vac_cnt;
    char gender;
    string name;
    string nid;
    string profession;
    string address;
    string mobile_number;
    int cnt;
public:
    void search_data();
    void add_new();
    void setdata();
    void view_vaccine();
    void showdata();
    void search_by_nid();
    void search_by_age();
    void search_by_phone();
    void search_by_num_of_vac();
    void show_list();
};
void show()
{
    cout<<setw(22)<<setiosflags(ios::left)<<"Name ";
    cout<<setw(20)<<"NID No.";
    cout<<setw(10)<<"Age";
    cout<<setw(18)<<"Profession";
    cout<<setw(7)<<"gender";
    cout<<setw(15)<<"Mobile No.";
    cout<<setw(6)<<"N.V.";
    cout<<"\t"<<"Address"<<endl;

}
void vaccine ::view_vaccine()
{
    ifstream ind;
    int i=0;
    ind.open("vaccinetrial.txt");
    ind.seekg(0,ios::beg);
    while(ind.read((char*)this,sizeof(vaccine)))
    {
        i++;
    }
    ind.close();
    int ch;
    int s=num_of_vaccine-i;
    cout<<"\n\n\n";
    cout<<"\t\t\t\t\t-----------------------------------\n";
    cout<<"\t\t\t\t\t|||| VACCINE MANAGEMENT SYSTEM ||||\n";
    cout<<"\t\t\t\t\t-----------------------------------\n\n";
    cout<<"\t\t\t\t\t************************************\n";
    cout<<"\t\t\t\t\t*        Vaccine Statistics        *\n";
    cout<<"\t\t\t\t\t************************************\n\n\n";
    cout<<"\t\t\t\t 1.View Available\t\t    2.Add More Vaccine \n\n\t\t\t\t\t\t      3.Back"<<endl;
    cout<<"\n\n\t\t\t\t\t\t  Your Choice :: ";
    cin>>ch;
    int f_var=0;
    fstream file("count.txt");
    file>>f_var;
    switch(ch)
    {
    case 1:
        cout<<"\n\n\t\t\t\t   Available number of vaccines are : "<<s+f_var;
        break;
    case 2:
        int m;
        cout<<"\n\n\t\t\t\t   Enter number of vaccines you want to add :: ";
        cin>>m;
        f_var=f_var+m;
        file.seekg(0);
        file<<f_var;
        cout<<"\n\n\t\t\t\t   Now total number of vaccines are : "<<f_var+s;
        break;
    case 3:
        system("cls");
        menu();
    default:
        system("cls");
        cout<<"\n\n\t\t\t\t\t\t   ENTER VALID OPTION "<<endl;
        menu();
    }
    file.close();
    getch();
}
void vaccine::show_list()
{
    cout<<"\n";
    cout<<setw(22)<<setiosflags(ios::left)<<name;
    cout<<setw(20)<<nid;
    cout<<setw(10)<<age;
    cout<<setw(18)<<profession;
    cout<<setw(7)<<gender;
    cout<<setw(15)<<mobile_number;
    cout<<setw(6)<<"Dose:"<<vac_cnt;
    cout<<"\t"<<address<<endl;
}
void vaccine::search_data()
{
    vaccine item;
    cout<<"\n\n\n";
    cout<<"\t\t\t\t\t-----------------------------------\n";
    cout<<"\t\t\t\t\t|||| VACCINE MANAGEMENT SYSTEM ||||\n";
    cout<<"\t\t\t\t\t-----------------------------------\n\n";
    cout<<"\t\t\t\t\t************************************\n";
    cout<<"\t\t\t\t\t*       Search  Information        *\n";
    cout<<"\t\t\t\t\t************************************\n\n\n";
    cout<<"\n\t\t\t\t\t    CHOOSE AN OPTION TO SEARCH BY \n"<<endl;
    cout<<"\n\t\t\t      1: Search by NID \t\t\t 2: Search by Phone Number\n"<<endl;
    cout<<"\n\t\t\t      3: Search by Age\t\t\t 4: Search by Number of Doses"<<endl;
    cout<<"\n\n\t\t\t\t\t\t  Your Choice :: ";
    int ch;
    cin>>ch;
    switch(ch)
    {
    case 1:
        system("cls");
        search_by_nid();
        getch();
        break;
    case 2:
        system("cls");
        search_by_phone();
        getch();
        break;
    case 3:
        system("cls");
        search_by_age();
        getch();
        break;
    case 4:
        system("cls");
        search_by_num_of_vac();
        getch();
        break;
    default:
        system("cls");
        cout<<"ENTER VALID OPTION"<<endl;
        menu();
    }
}
void vaccine::search_by_nid()
{
    ifstream in("vaccinetrial.txt");
    int flag =0;
    string nid_num;
    cout<<"\n\n\n";
    cout<<"\t\t\t\t\t-----------------------------------\n";
    cout<<"\t\t\t\t\t|||| VACCINE MANAGEMENT SYSTEM ||||\n";
    cout<<"\t\t\t\t\t-----------------------------------\n\n";
    cout<<"\t\t\t\t\t************************************\n";
    cout<<"\t\t\t\t\t*          Search By NID           *\n";
    cout<<"\t\t\t\t\t************************************\n\n\n";
    cout<<"\n\t\t\t\t\tEnter Your NID Number  : ";
    fflush(stdin);
    getline(cin,nid_num);
    cout<<"\n\n\n";
    in.read((char*)this,sizeof(vaccine));
    while(!in.eof())
    {
        if(nid_num.compare(nid)==0)
        {
            showdata();
            flag=1;
            break;
        }
        in.read((char*)this,sizeof(vaccine));
    }
    if(flag==0)
    {
        cout<<"\n\n\t\t\t\t\t\tNID Number Not Found!!!"<<endl;
    }
    in.close();
}
void vaccine::search_by_age()
{
    ifstream in("vaccinetrial.txt");
    int flag =0;
    int a,p=0;
    cout<<"\n\n\n";
    cout<<"\t\t\t\t\t-----------------------------------\n";
    cout<<"\t\t\t\t\t|||| VACCINE MANAGEMENT SYSTEM ||||\n";
    cout<<"\t\t\t\t\t-----------------------------------\n\n";
    cout<<"\t\t\t\t\t************************************\n";
    cout<<"\t\t\t\t\t*          Search By Age           *\n";
    cout<<"\t\t\t\t\t************************************\n\n\n";
    cout<<"\n\n\t\t\t\t      Enter Age of people to be Searched : ";
    cin>>a;
    cout<<endl<<endl;
    show();
    in.read((char*)this,sizeof(vaccine));
    while(!in.eof())
    {
        if(a==age)
        {
            show_list();
            flag=1;
            p++;
        }
        in.read((char*)this,sizeof(vaccine));
    }
    if(flag==0)
    {
        cout<<"Age you entered is not found"<<endl;
    }
    cout<<"\n\n\n\t\t\t\t    Number of people vaccinated  by this age : "<<p;
    in.close();

}
void vaccine::search_by_phone()
{
    ifstream in("vaccinetrial.txt");
    int flag =0,p=0;
    string src_phn;
    cout<<"\n\n\n";
    cout<<"\t\t\t\t\t-----------------------------------\n";
    cout<<"\t\t\t\t\t|||| VACCINE MANAGEMENT SYSTEM ||||\n";
    cout<<"\t\t\t\t\t-----------------------------------\n\n";
    cout<<"\t\t\t\t\t************************************\n";
    cout<<"\t\t\t\t\t*         Search By PHONE          *\n";
    cout<<"\t\t\t\t\t************************************\n\n\n";
    cout<<"\n\n\n\t\t\t\t      Enter Your Phone Number  : ";
    fflush(stdin);
    getline(cin,src_phn);
    cout<<"\n\n";
    show();
    in.read((char*)this,sizeof(vaccine));
    while(!in.eof())
    {
        if(src_phn.compare(mobile_number)==0)
        {
            show_list();
            flag=1;
            p++;
        }
        in.read((char*)this,sizeof(vaccine));
    }
    if(flag==0)
    {
        cout<<"\n\n\t\t\t\t\t\t  Number Not Found!!!"<<endl;
    }
    cout<<"\n\n\n\t\t\t\t     NO of people vaccinated  by this age : "<<p;
    in.close();
}
void vaccine::search_by_num_of_vac()
{
    ifstream in("vaccinetrial.txt");
    int flag =0;
    int a,p=0;
    cout<<"\n\n\n";
    cout<<"\t\t\t\t\t-----------------------------------\n";
    cout<<"\t\t\t\t\t|||| VACCINE MANAGEMENT SYSTEM ||||\n";
    cout<<"\t\t\t\t\t-----------------------------------\n\n";
    cout<<"\t\t\t\t\t************************************\n";
    cout<<"\t\t\t\t\t*    Search By Number of Doses     *\n";
    cout<<"\t\t\t\t\t************************************\n\n\n";
    cout<<"\n\t\t\t\t\t   Enter Your Number of Dose  : ";
    cin>>a;
    cout<<"\n\n";
    show();
    in.read((char*)this,sizeof(vaccine));
    while(!in.eof())
    {
        if(a==vac_cnt)
        {
            show_list();
            flag=1;
            p++;
        }
        in.read((char*)this,sizeof(vaccine));
    }
    if(flag==0)
    {
        cout<<"\n\n\t\t\t\t   The number of vaccine you entered is not found"<<endl;
    }
    cout<<"\n\n\t\t\t\t   Number of people vaccinated by "<<a<<" dose is :: "<<p;
    in.close();

}
void vaccine::setdata()
{
    cout<<"\n\n\n";
    cout<<"\t\t\t\t\t-----------------------------------\n";
    cout<<"\t\t\t\t\t|||| VACCINE MANAGEMENT SYSTEM ||||\n";
    cout<<"\t\t\t\t\t-----------------------------------\n\n";
    cout<<"\t\t\t\t\t************************************\n";
    cout<<"\t\t\t\t\t*    Input Personal Information    *\n";
    cout<<"\t\t\t\t\t************************************\n\n\n";
    fflush(stdin);
    cout<<"\n\t\t Enter Your Name       : ";
    getline(cin, name);
    cout<<"\n\t\t Enter Your NID        : ";
    getline(cin, nid);
    cout<<"\n\t\t Enter Your Gender(M|F): ";
    cin>>gender;
    cout<<"\n\t\t Enter Your Age        : ";
    cin>>age;
    fflush(stdin);
    cout<<"\n\t\t Enter Your Profession : ";
    getline(cin, profession);
    cout<<"\n\t\t Enter Your Address    : ";
    getline(cin, address);
    //cout<<"\n"<<address<<endl;
    cout<<"\n\t\t Enter Your Phone No.  : ";
    getline(cin, mobile_number);
    cout<<"\n\t\t Enter Vaccine Dose No.: ";
    cin>>vac_cnt;
    //cout<<"\n"<<mobile_number<<endl;
}
void vaccine::showdata()
{
    cout<<"\n\n\n";
    cout<<"\t\t\t\t\t-----------------------------------\n";
    cout<<"\t\t\t\t\t|||| VACCINE MANAGEMENT SYSTEM ||||\n";
    cout<<"\t\t\t\t\t-----------------------------------\n\n";
    cout<<"\t\t\t\t\t************************************\n";
    cout<<"\t\t\t\t\t*   Vaccine Receiver Information   *\n";
    cout<<"\t\t\t\t\t************************************\n\n\n";
    cout<<"\n\t\t Name        : "<<name<<endl;
    cout<<"\n\t\t NID         : "<<nid<<endl;
    cout<<"\n\t\t Gender      : "<<gender<<endl;
    cout<<"\n\t\t Age         : "<<age<<endl;
    cout<<"\n\t\t Profession  : "<<profession<<endl;
    cout<<"\n\t\t Address     : "<<address<<endl;
    cout<<"\n\t\t Phone Number: "<<mobile_number<<endl;
    cout<<"\n\t\t Dose Taken  : "<<vac_cnt<<endl;
}

void vaccine::add_new()
{
    fstream outin;
    outin.open("vaccinetrial.txt",ios::app|ios::in);
    setdata();
    outin.write((char*)this,sizeof(vaccine));
    cout<<"\n\t\t\t\t     YOUR DATA HAS BEEN SUCCESSFULLY INSERTED. "<<endl;
    getch();
    outin.close();
}
void menu()
{
    system("cls");
    cout<<"\n\n\n";
    cout<<"\t\t\t\t\t-----------------------------------\n";
    cout<<"\t\t\t\t\t|||| VACCINE MANAGEMENT SYSTEM ||||\n";
    cout<<"\t\t\t\t\t-----------------------------------\n\n";
    cout<<"\t\t\t\t\t************************************\n";
    cout<<"\t\t\t\t\t*               Menu               *\n";
    cout<<"\t\t\t\t\t************************************\n\n\n";
    cout<<"\n\t\t\t      1: ADD NEW RECORD\t\t\t 2: VIEW VACCINE DATA\n"<<endl;
    cout<<"\n\t\t\t      3: SEARCH        \t\t\t 4: EXIT"<<endl;
}
int main()
{
    vaccine obj;
    int k=3;
    int num_vac;
    cout<<"\n\n\n";
    cout<<"\t\t\t\t\t-----------------------------------\n";
    cout<<"\t\t\t\t\t|||| VACCINE MANAGEMENT SYSTEM ||||\n";
    cout<<"\t\t\t\t\t-----------------------------------\n\n\n";
    cout<<"\t\t\t\t\t   Press Any Key to Continue.....\n\n\n";
    getch();
B:
    system("cls");
    cout<<"\n\n\n";
    cout<<"\t\t\t\t\t************************************\n";
    cout<<"\t\t\t\t\t*   Enter Your Login Credentials   *\n";
    cout<<"\t\t\t\t\t************************************\n\n\n";
    while(k>=1)
    {
        int c = password();
        if(c==1)
            break;
        else
            cout<<"\n\n\n\t\t\t\t\t   Wrong Password or Username...\n\n\n\t\t\t\t\t You Can try Only "<<k-1<<" times more";
        k--;
        if(k<1)
        {
            for(int i=59; i>=0; i--)
            {
                system("cls");
                cout<<"\n\n\n\t\t\t\t\t   YOU ARE BLOCKED FOR 1 MINUTE!!!";
                cout<<"\n\n\n\t\t\t\t\t   TRY AFTER "<<i<<" SECONDS...";
                Sleep(1000);
            }
            k=3;
            goto B;
        }
    }
    int ch;
    do
    {
        cout<<"\n\n\n";
        cout<<"\t\t\t\t\t-----------------------------------\n";
        cout<<"\t\t\t\t\t|||| VACCINE MANAGEMENT SYSTEM ||||\n";
        cout<<"\t\t\t\t\t-----------------------------------\n\n\n";
        menu();
        cout<<"\n\n\t\t\t\t\t    Choose According to Your Need\n\n\n";
        cout<<"\n\n\t\t\t\t\t\t  Your Choice :: ";
        cin>>ch;
        vaccine v1;
        switch(ch)
        {
        case 1:
            system("cls");
            obj.add_new();
            break;
        case 2:
            system("cls");
            obj.view_vaccine();
            break;
        case 3:
            system("cls");
            obj.search_data();
            break;
        case 4:
            system("cls");
            exit(0);
        default:
            system("cls");
            cout<<"\n\n\n\t\t\t\t\t   THANK YOU!!!";
            cout<<"\n\t\t\t\t\t HAVE A NICE DAY.";
            Sleep(3000);
            exit(0);
        }
    }
    while(ch!=0);

    return 0;
}
int password()
{
    char cname[30],pass[20];
    int ch, i=0,cap=0,capt=0;
    cout<<"\n\n\n\t\t\t\t\t\t  USER NAME:  ";
    fflush(stdin);
    gets(cname);
    cout<<"\n\n\t\t\t\t\t\t  PASSWORD :  ";
    while((ch=getch()) != 13)
    {
        cout<<"*";
        pass[i]=ch;
        i++;
    }
    pass[i] = '\0';
    srand(time(0));
    cap=rand();
    cout<<"\n\n\t\t\t\t\t   CAPTURE:->  "<<cap<<endl;
    cout<<"\n\t\t\t\t\t   Please enter the valid capture :-   ";
    cin>>capt;
    if( (strcmp(cname,"a")==0) && (strcmp(pass,"b")==0) && cap==capt)
        return 1;
    else
        return 0;
}

