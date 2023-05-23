#include "Waiter.h"
#include "Employee.h"
#include "Menu.h"
#include<string>
#include<time.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>

Waiter::Waiter()
{
    //ctor
}

const void Waiter::show_info()
{
    std::cout<<Getid()<<std::endl;
    std::cout<<Getpwd()<<std::endl;
    std::cout<<Getname()<<std::endl;
    std::cout<<Getdesg()<<std::endl;
}

void Waiter::disk_out()
{
    Employee* obj[100];
    int k=0;
    bool flag=true;

    std::ifstream infile("Waiter.txt");
    if(!infile)
    {
        std::cout<<"there is no file"<<"\n";
        flag=false;
    }
    if(flag==true)
    {
        obj[k]=new Waiter;
        std::string s_id,s_pwd,s_name,s_desg;

        infile>>s_id>>s_pwd>>s_name>>s_desg;
        obj[k]->Setid(s_id);
        obj[k]->Setpwd(s_pwd);
        obj[k]->Setname(s_name);
        obj[k]->Setdesg(s_desg);

        while(!infile.eof())
        {
            k++;
            obj[k]=new Waiter;
            infile>>s_id>>s_pwd>>s_name>>s_desg;
            obj[k]->Setid(s_id);
            obj[k]->Setpwd(s_pwd);
            obj[k]->Setname(s_name);
            obj[k]->Setdesg(s_desg);

        }
        infile.close();
    }

    std::ofstream outfile("Waiter.txt");
    for(int i=0; i<k; i++)
    {
        outfile << obj[i]->Getid() //insert (write) data
                << ' ' //needs space between numbers
                << obj[i]->Getpwd()
                <<' '
                <<obj[i]->Getname()
                <<' '
                <<obj[i]->Getdesg()
                <<' ';
        std::cout << "File written\n";
    }
    for(int i=0;i<k;i++)delete obj;

    Employee* obj1=new Waiter;
    while(1)
    {
        int x;
        std::cin>>x;
        if(x==1)
        {

            std::string s_id,s_pwd,s_name,s_desg;
            std::cout<<"Give a name : "<<std::endl;
            std::cin>>s_name;
            s_id=obj1->id_gnrt(s_name);
            s_pwd=obj1->pwd_gnrt();
            std::cout<<"Your ID is : "<<s_id<<std::endl;
            std::cout<<"Your Password is : "<<s_pwd<<std::endl;
            std::cout<<"Give Designation : "<<std::endl;
            std::cin>>s_desg;
            obj1->Setid(s_id);
            obj1->Setpwd(s_pwd);
            obj1->Setname(s_name);
            obj1->Setdesg(s_desg);
            //create ofstream object
            outfile << obj1->Getid() //insert (write) data
                    <<' ' //needs space between numbers
                    << obj1->Getpwd()
                    <<' '
                    <<obj1->Getname()
                    <<' '
                    <<obj1->Getdesg()
                    <<' ';
            std::cout << "File written\n";
        }
        else
            break;
    }
    delete obj1;
    outfile.close();
}

void Waiter::disk_in()
{
    Employee* obj[100];
    int k=0;
    std::ifstream infile("Waiter.TXT");
    if(!infile)
    {
        std::cout<<"there are no file for porter"<<std::endl;
        return ;
    }
    obj[k]=new Waiter;
    std::string s_id,s_name,s_pwd,s_desg;
    infile>>s_id>>s_pwd>>s_name>>s_desg;
    obj[k]->Setid(s_id);
    obj[k]->Setpwd(s_pwd);
    obj[k]->Setname(s_name);
    obj[k]->Setdesg(s_desg);
    while(!infile.eof())
    {
        k++;
        obj[k]=new Waiter;
        infile>>s_id>>s_pwd>>s_name>>s_desg;
        obj[k]->Setid(s_id);
        obj[k]->Setpwd(s_pwd);
        obj[k]->Setname(s_name);
        obj[k]->Setdesg(s_desg);
    }
    for(int i=0; i<k; i++)
    {
        obj[i]->show_info();
    }
    infile.close();
    for(int i=0;i<k;i++)delete obj;
}

std::string Waiter::id_gnrt(std::string s_name)
{
    std::string s_res="";
    s_res+=("110");
    s_res+=s_name;
    int n=3;//Receptionist::disk_count();
    s_res+=(std::to_string(n+1));
    return s_res;
}

std::string Waiter::pwd_gnrt()
{
    std::srand(time(NULL));
    std::string p="";
    int co[4]= {3,3,3,3};
    int k=0;
    while(co[0]--)
    {
        p+=65+(std::rand()%26);
        k++;
    }
    while(co[1]--)
    {
        p+=48+(std::rand()%10);
        k++;
    }
    while(co[2]--)
    {
        p+=33+(std::rand()%15);
        k++;
    }
    while(co[3]--)
    {
        p+=97+(std::rand()%26);
        k++;
    }
    //p[k]='\0';
    return p;
}

void Waiter::del_own_rec()
{
    std::string d_id,d_name;
    std::cout<<"Give the id you want to delete"<<std::endl;
    std::cin>>d_id;
    std::cout<<"Give the name you want to delete"<<std::endl;
    std::cin>>d_name;
    Employee* obj[100];
    int k=0;
    std::ifstream infile("Waiter.TXT");
    bool flag1=true;
    if(!infile)
    {
        std::cout<<"There is no Waiter to delete"<<std::endl;
        flag1=false;
    }
    if(flag1==true)
    {
        obj[k]=new Waiter;

        std::string s_id,s_pwd,s_name,s_desg;

        infile>>s_id>>s_pwd>>s_name>>s_desg;

        obj[k]->Setid(s_id);
        obj[k]->Setpwd(s_pwd);
        obj[k]->Setname(s_name);
        obj[k]->Setdesg(s_desg);

        while(!infile.eof())
        {
            k++;
            obj[k]=new Waiter;
            infile>>s_id>>s_pwd>>s_name>>s_desg;
            obj[k]->Setid(s_id);
            obj[k]->Setpwd(s_pwd);
            obj[k]->Setname(s_name);
            obj[k]->Setdesg(s_desg);
        }
        infile.close();
        int idx;
        bool flag=false;
        for(int i=0; i<k; i++)
        {
            if((d_id==obj[i]->Getid())&&(d_name==obj[i]->Getname()))
            {
                flag=true;
                std::cout<<"Record is found"<<std::endl;
                idx=i;
                break;
            }
        }
        if(flag==true)
        {
            std::cout<<"Record is deleting"<<std::endl;
            std::ofstream outfile("Waiter.TXT");
            for(int i=0; i<k; i++)
            {
                if(idx!=i)
                {
                    outfile<<obj[i]->Getid()
                           <<' '
                           <<obj[i]->Getpwd()
                           <<' '
                           <<obj[i]->Getname()
                           <<' '
                           <<obj[i]->Getdesg()
                           <<' ';
                }
            }
            outfile.close();
        }
    }
    for(int i=0;i<k;i++)delete obj;
}

bool Waiter::login_op()
{
    std::ifstream infile("Waiter.txt");
    if(!infile)
    {
        std::cout<<"Sorry, there is no waiters right now"<<std::endl;
        return false;
    }
    std::string L_id,L_pwd;
    std::cout<<"Welcome to Waiter's login terminal."<<std::endl;
    std::cout<<"Give your ID : ";
    std::cin>>L_id;
    std::cout<<"Give your Password : ";
    std::cin>>L_pwd;

    std::string s_id,s_pwd,s_name,s_desg;
    int k=0;
    Employee* obj[100];
    obj[k]=new Waiter;
    infile>>s_id>>s_pwd>>s_name>>s_desg;
    obj[k]->Setid(s_id);
    obj[k]->Setpwd(s_pwd);
    obj[k]->Setname(s_name);
    obj[k]->Setdesg(s_desg);
    while(!infile.eof())
    {
        k++;
        obj[k]=new Waiter;
        infile>>s_id>>s_pwd>>s_name>>s_desg;
        obj[k]->Setid(s_id);
        obj[k]->Setpwd(s_pwd);
        obj[k]->Setname(s_name);
        obj[k]->Setdesg(s_desg);
    }
    infile.close();

    bool flag=false;
    for(int i=0; i<k; i++)
    {
        if((obj[i]->Getid()==L_id)&&(obj[i]->Getpwd()==L_pwd))
        {
            flag=true;
            break;
        }
    }
    for(int i=0;i<k;i++)delete obj;

    return flag;
}

void Waiter::main_func_wtr()
{
    while(1)
    {
        std::cout<<"press 1 for checking guests' order."<<std::endl;
        std::cout<<"press 2 for exiting this terminal."<<std::endl;
        int x;
        std::cin>>x;
        if(x==1)
            ck_gst_ord();
        else if(x==2)
            break;
        else
            std::cout<<"Invalid Input"<<std::endl;
    }
}
void Waiter::ck_gst_ord()
{
    std::ifstream infile("wtr_gst_ord.txt");
    if(!infile)
    {
        std::cout<<"There is no order to check"<<std::endl;
        return ;
    }
    std::string s_set,s_room_no;
    infile>>s_set>>s_room_no;
    if(addequate(s_set))
    {
        del_gst_ord(s_room_no);
    }
    while(!infile.eof())
    {
        infile>>s_set>>s_room_no;
        if(addequate(s_set))
        {
            del_gst_ord(s_room_no);
        }
    }
    infile.close();
}
void Waiter::del_gst_ord(std::string q_room_no)
{
    std::string s_set,s_room_no;
    std::ifstream infile("wtr_gst_ord.txt");
    Menu* obj[100];
    int k=0;
    obj[k]=new Menu;
    infile>>s_set>>s_room_no;
    obj[k]->Setset(s_set);
    obj[k]->Setroom_no(s_room_no);
    while(!infile.eof())
    {
        k++;
        obj[k]=new Menu;
        infile>>s_set>>s_room_no;
        obj[k]->Setset(s_set);
        obj[k]->Setroom_no(s_room_no);
    }
    infile.close();
    std::cout<<"Order for "<<q_room_no<<" is taken care of"<<std::endl;

    std::ofstream outfile("wtr_gst_ord.txt");
    for(int i=0; i<k; i++)
    {
        if(obj[i]->Getroom_no()!=q_room_no)
        {
            outfile<<obj[i]->Getset()
                   <<' '
                   <<obj[i]->Getroom_no()
                   <<' ';
        }
    }
    outfile.close();
    for(int i=0;i<k;i++)delete obj;
}

bool Waiter::addequate(std::string q_set)
{
    std::ifstream infile("cook_lst.txt");
    if(!infile)
    {
        std::cout<<"There are no food"<<std::endl;
        return false;
    }
    int a,b,c;
    bool flag=false;
    infile>>a>>b>>c;
    if(q_set=="seta"&&a>0)
    {
        a--;
        flag=true;
    }
    else if(q_set=="setb"&&b>0)
    {
        b--;
        flag=true;
    }
    else if(q_set=="setc"&&c>0)
    {
        c--;
        flag=true;
    }
    infile.close();
    std::ofstream outfile("cook_lst.txt");
    outfile<<a
           <<' '
           <<b
           <<' '
           <<c
           <<' ';
    outfile.close();
    return flag;
}
