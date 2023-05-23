#include "Guard.h"
#include<iostream>
#include<fstream>
#include<string>
#include<time.h>
#include<stdlib.h>
#include "Employee.h"

Guard::Guard()
{
    //ctor
}

const void Guard::show_info()
{
    std::cout<<Getid()<<std::endl;
    std::cout<<Getpwd()<<std::endl;
    std::cout<<Getname()<<std::endl;
    std::cout<<Getdesg()<<std::endl;
}

void Guard::disk_out()
{
    Employee* obj[100];
    int k=0;
    bool flag=true;

    std::ifstream infile("Guard.txt");
    if(!infile)
    {
        std::cout<<"there is no file"<<"\n";
        flag=false;
    }
    if(flag==true)
    {
        obj[k]=new Guard;
        std::string s_id,s_pwd,s_name,s_desg;

        infile>>s_id>>s_pwd>>s_name>>s_desg;
        obj[k]->Setid(s_id);
        obj[k]->Setpwd(s_pwd);
        obj[k]->Setname(s_name);
        obj[k]->Setdesg(s_desg);

        while(!infile.eof())
        {
            k++;
            obj[k]=new Guard;
            infile>>s_id>>s_pwd>>s_name>>s_desg;
            obj[k]->Setid(s_id);
            obj[k]->Setpwd(s_pwd);
            obj[k]->Setname(s_name);
            obj[k]->Setdesg(s_desg);

        }
        infile.close();
    }

    std::ofstream outfile("Guard.txt");
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
    for(int i=0;i<k;i++)delete obj[i];

    Employee* obj1=new Guard;
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
void Guard::disk_in()
{
    Employee* obj[100];
    int k=0;
    std::ifstream infile("Guard.TXT");
    if(!infile)
    {
        std::cout<<"there are no file for Guard"<<std::endl;
        return ;
    }
    obj[k]=new Guard;
    std::string s_id,s_name,s_pwd,s_desg;
    infile>>s_id>>s_pwd>>s_name>>s_desg;
    obj[k]->Setid(s_id);
    obj[k]->Setpwd(s_pwd);
    obj[k]->Setname(s_name);
    obj[k]->Setdesg(s_desg);
    while(!infile.eof())
    {
        k++;
        obj[k]=new Guard;
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
    for(int i=0;i<k;i++)delete obj[i];
}

std::string Guard::id_gnrt(std::string s_name)
{
    std::string s_res="";
    s_res+=("011");
    s_res+=s_name;
    int n=3;//Receptionist::disk_count();
    s_res+=(std::to_string(n+1));
    return s_res;
}

std::string Guard::pwd_gnrt()
{
    std::srand(time(NULL));
    std::string p="";
    int co[4]= {3,3,3,3};
    int k=0;
    while(co[0]--)
    {
        p+=48+(std::rand()%10);
        k++;
    }
    while(co[1]--)
    {
        p+=97+(std::rand()%26);
        k++;
    }
    while(co[2]--)
    {
        p+=65+(std::rand()%26);
        k++;
    }
    while(co[3]--)
    {
        p+=33+(std::rand()%15);
        k++;
    }
    //p[k]='\0';
    return p;
}

void Guard::del_own_rec()
{
    std::string d_id,d_name;
    std::cout<<"Give the id you want to delete"<<std::endl;
    std::cin>>d_id;
    std::cout<<"Give the name you want to delete"<<std::endl;
    std::cin>>d_name;
    Employee* obj[100];
    int k=0;
    std::ifstream infile("Guard.TXT");
    bool flag1=true;
    if(!infile)
    {
        std::cout<<"There is no Guard to delete"<<std::endl;
        flag1=false;
    }
    if(flag1==true)
    {
        obj[k]=new Guard;

        std::string s_id,s_pwd,s_name,s_desg;

        infile>>s_id>>s_pwd>>s_name>>s_desg;

        obj[k]->Setid(s_id);
        obj[k]->Setpwd(s_pwd);
        obj[k]->Setname(s_name);
        obj[k]->Setdesg(s_desg);

        while(!infile.eof())
        {
            k++;
            obj[k]=new Guard;
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
            std::ofstream outfile("Guard.TXT");
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
    for(int i=0;i<k;i++)delete obj[i];
}

bool Guard::login_op()
{
    std::ifstream infile("Guard.txt");
    if(!infile)
    {
        std::cout<<"Sorry, there is no guard right now"<<std::endl;
        return false;
    }
    std::string L_id,L_pwd;
    std::cout<<"Welcome to Guard's login terminal."<<std::endl;
    std::cout<<"Give your ID : ";
    std::cin>>L_id;
    std::cout<<"Give your Password : ";
    std::cin>>L_pwd;

    std::string s_id,s_pwd,s_name,s_desg;
    int k=0;
    Employee* obj[100];
    obj[k]=new Guard;
    infile>>s_id>>s_pwd>>s_name>>s_desg;
    obj[k]->Setid(s_id);
    obj[k]->Setpwd(s_pwd);
    obj[k]->Setname(s_name);
    obj[k]->Setdesg(s_desg);
    while(!infile.eof())
    {
        k++;
        obj[k]=new Guard;
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
    for(int i=0;i<k;i++)delete obj[i];

    return flag;
}

