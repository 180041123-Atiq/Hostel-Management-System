#include "Manager.h"
#include "Employee.h"
#include "Receptionist.h"
#include "Porter.h"
#include "Waiter.h"
#include "Cook.h"
#include "Cleaner.h"
#include "Guard.h"
#include<string>
#include<iostream>
#include<vector>
#include<fstream>

Manager::Manager()
{
    //main_func_mng();
}

void Manager::main_func_mng()
{
    //login option later

    while(1)
    {
        std::cout<<"Welcome manager."<<std::endl;
        std::cout<<"press 1 for add employee."<<std::endl;
        std::cout<<"press 2 for delete records."<<std::endl;
        std::cout<<"press 3 for show info of other employee"<<std::endl;
        std::cout<<"press 4 for showing this month's profit"<<std::endl;
        std::cout<<"press 5 for exiting managing panel"<<std::endl;
        int x;
        std::cin>>x;
        if(x==1)
        {
            add_mng();
            int e=0;
            std::ifstream infile("count_emp.txt");
            if(infile)
            {
                infile>>e;
                infile.close();
            }
            e++;
            std::ofstream outfile("count_emp.txt");
            outfile<<e
                   <<' ';
            outfile.close();
        }
        else if(x==2)
            del_rec();
        else if(x==3)
            show_info_otr();
        else if(x==4)
        {
            int e=0;
            std::ifstream infile("count_emp.txt");
            if(infile)
            {
                infile>>e;
                infile.close();
            }
            show_this_month_profit(e);
        }
        else if(x==5)
        {
            std::cout<<"Exiting managing panel"<<std::endl;
            break;
        }
        else
            std::cout<<"Invalid Input.Press again."<<std::endl;
    }
}

void Manager::add_mng()
{
    std::cout<<"how many you want to add?"<<std::endl;
    int x;
    std::cin>>x;
    for(int i=0; i<x; i++)
    {
        std::cout<<"which type of employee you want to add?"<<std::endl;
        std::cout<<"press 1 for Receptionist."<<std::endl;
        std::cout<<"press 2 for Guard"<<std::endl;
        std::cout<<"press 3 for Cleaner"<<std::endl;
        std::cout<<"press 4 for Cook"<<std::endl;
        std::cout<<"press 5 for Waiter"<<std::endl;
        std::cout<<"press 6 for Porter"<<std::endl;
        std::cout<<"press 7 for exiting adding panel"<<std::endl;
        int y;
        std::cin>>y;
        if(y==1)
        {
            Employee* obj=new Receptionist;
            obj->disk_out();
            delete obj;
        }
        else if(y==2)
        {
            Employee* obj=new Guard;
            obj->disk_out();
            delete obj;
        }
        else if(y==3)
        {
            Employee* obj=new Cleaner;
            obj->disk_out();
            delete obj;
        }
        else if(y==4)
        {
            Employee* obj=new Cook;
            obj->disk_out();
            delete obj;
        }
        else if(y==5)
        {
            Employee* obj=new Waiter;
            obj->disk_out();
            delete obj;
        }
        else if(y==6)
        {
            Employee* obj=new Porter;
            obj->disk_out();
            delete obj;
        }
        else if(y==7)
            break;
    }
}

void Manager::del_rec()
{
    while(1)
    {
        std::cout<<"which type of employee's info you want to delete?"<<std::endl;
        std::cout<<"press 1 for Receptionist."<<std::endl;
        std::cout<<"press 2 for Guard"<<std::endl;
        std::cout<<"press 3 for Cleaner"<<std::endl;
        std::cout<<"press 4 for Cook"<<std::endl;
        std::cout<<"press 5 for Waiter"<<std::endl;
        std::cout<<"press 6 for Porter"<<std::endl;
        std::cout<<"press 7 for exiting deleting panel"<<std::endl;
        int x;
        std::cin>>x;
        if(x==1)
        {
            Employee* obj=new Receptionist;
            obj->del_own_rec();
            delete obj;
        }
        else if(x==2)
        {
            Employee* obj=new Guard;
            obj->del_own_rec();
            delete obj;
        }
        else if(x==3)
        {
            Employee* obj=new Cleaner;
            obj->del_own_rec();
            delete obj;
        }
        else if(x==4)
        {
            Employee* obj=new Cook;
            obj->del_own_rec();
            delete obj;
        }
        else if(x==5)
        {
            Employee* obj=new Waiter;
            obj->del_own_rec();
            delete obj;
        }
        else if(x==6)
        {
            Employee* obj=new Porter;
            obj->del_own_rec();
            delete obj;
        }
        else if(x==7)
            break;
    }
}

void Manager::show_info_otr()
{
    while(1)
    {
        std::cout<<"which type of employee's info you want to see?"<<std::endl;
        std::cout<<"press 1 for Receptionist."<<std::endl;
        std::cout<<"press 2 for Guard"<<std::endl;
        std::cout<<"press 3 for Cleaner"<<std::endl;
        std::cout<<"press 4 for Cook"<<std::endl;
        std::cout<<"press 5 for Waiter"<<std::endl;
        std::cout<<"press 6 for Porter"<<std::endl;
        std::cout<<"press 7 for exiting info panel"<<std::endl;
        int x;
        std::cin>>x;
        if(x==1)
        {
            Employee* obj=new Receptionist;
            std::cout<<"show info Receptionist"<<std::endl;
            obj->disk_in();
            delete obj;
        }
        else if(x==2)
        {
            Employee* obj=new Guard;
            std::cout<<"show info Guard"<<std::endl;
            obj->disk_in();
            delete obj;
        }
        else if(x==3)
        {
            Employee* obj=new Cleaner;
            std::cout<<"show info cleaner"<<std::endl;
            obj->disk_in();
            delete obj;
        }
        else if(x==4)
        {
            Employee* obj=new Cook;
            std::cout<<"show info Cook"<<std::endl;
            obj->disk_in();
            delete obj;
        }
        else if(x==5)
        {
            Employee* obj=new Waiter;
            std::cout<<"show info Waiter"<<std::endl;
            obj->disk_in();
            delete obj;
        }
        else if(x==6)
        {
            Employee* obj=new Porter;
            std::cout<<"show info of Porter"<<std::endl;
            obj->disk_in();
            delete obj;
        }
        else if(x==7)
            break;
    }
}
void Manager::disk_out()
{
//boss implement
}

void Manager::disk_in()
{
//boss implement
}
std::string Manager::id_gnrt(std::string s_name)
{
    //boss implement
}
std::string Manager::pwd_gnrt()
{
    //boss implement
}
const void Manager::show_info()
{
    std::cout<<Getid()<<std::endl;
    std::cout<<Getpwd()<<std::endl;
    std::cout<<Getname()<<std::endl;
    std::cout<<Getdesg()<<std::endl;
}

void Manager::del_own_rec()
{

}

bool Manager::login_op()
{
    std::string s_id,s_pwd;
    std::cout<<"Give your ID : ";
    std::cin>>s_id;
    std::cout<<"Give your password : ";
    std::cin>>s_pwd;
    if(s_id=="admin"&&s_pwd=="admin")
        return true;
    return false;
}

void Manager::show_this_month_profit(int e)
{
    std::ifstream infile("count_gst.txt");
    if(!infile)
    {
        std::cout<<"there is no data to calculate"<<std::endl;
        return ;
    }
    int c=0;
    infile>>c;
    infile.close();
    int total_sum=c*5000;
    std::cout<<"Give a bulk value which approximately cover whole month's expanse"<<std::endl;
    int bulk=0;
    std::cin>>bulk;
    std::cout<<total_sum-(e*2000)-bulk<<std::endl;
}
