#include "Interface.h"
#include "Employee.h"
#include "Receptionist.h"
#include "Manager.h"
#include "Porter.h"
#include "Guest.h"
#include "Waiter.h"
#include "Cook.h"
#include "Cleaner.h"
#include "Guard.h"
#include"Room.h"
#include<iostream>
#include<fstream>

Interface::Interface()
{
    std::cout<<"Welcome to login terminal"<<std::endl;
    r_obj=new Room;
    load_stat_room();
    main_func();
}
void Interface::main_func()
{


    while(1)
    {
        std::cout<<"press 1 for manager"<<std::endl;
        std::cout<<"press 2 for guest"<<std::endl;
        std::cout<<"press 3 for receptionist"<<std::endl;
        std::cout<<"press 4 for porter"<<std::endl;
        std::cout<<"press 5 for waiter"<<std::endl;
        std::cout<<"press 6 for cook"<<std::endl;
        std::cout<<"press 7 for cleaner"<<std::endl;
        std::cout<<"press 8 for guard"<<std::endl;
        std::cout<<"press 9 for terminating the program"<<std::endl;
        int x;
        std::cin>>x;
        if(x==1)
        {
            Manager* obj;
            obj=new Manager;
            if(obj->login_op())
            {
                obj->main_func_mng();
            }
            else
            {
                std::cout<<"wrong information"<<std::endl;
            }
            delete obj;
        }
        else if(x==2)
        {
            Guest* obj;
            obj=new Guest;
            if(obj->login_op())
            {
                obj->main_func_gst();
            }
            else
            {
                std::cout<<"Wrong information"<<std::endl;
            }
            delete obj;
        }
        else if(x==3)
        {
            Receptionist* obj;
            obj=new Receptionist;
            if(obj->login_op())
            {
                obj->main_func_recep();
            }
            else
            {
                std::cout<<"Sorry wrong information."<<std::endl;
            }
            delete obj;
        }
        else if(x==4)
        {
            Porter* obj;
            obj=new Porter;
            if(obj->login_op())
            {
                obj->main_func_prt();
            }
            else
            {
                std::cout<<"sorry wrong information."<<std::endl;
            }
            delete obj;
        }
        else if(x==5)
        {
            Waiter* obj;
            obj=new Waiter;
            if(obj->login_op())
            {
                obj->main_func_wtr();
            }
            else
            {
                std::cout<<"sorry wrong information."<<std::endl;
            }
            delete obj;
        }
        else if(x==6)
        {
            Cook* obj;
            obj=new Cook;
            if(obj->login_op())
            {
                obj->main_func_cok();
            }
            else
            {
                std::cout<<"sorry wrong information."<<std::endl;
            }
            delete obj;
        }
        else if(x==7)
        {
            Cleaner* obj=new Cleaner;
            if(obj->login_op())
            {
                obj->main_func_cln();
            }
            else
            {
                std::cout<<"sorry wrong information"<<std::endl;
            }
            delete obj;
        }
        else if(x==8)
        {
            Guard* obj=new Guard;
            if(obj->login_op())
            {
                obj->disk_in();
            }
            else
            {
                std::cout<<"sorry wrong information"<<std::endl;
            }
            delete obj;
        }
        else if(x==9)
        {
            std::cout<<"program is terminating"<<std::endl;
            break;
        }
        else
            std::cout<<"Invalid Input."<<std::endl;
    }
}

void Interface::load_stat_room()
{
    std::ifstream infile("stat_room.txt");
    if(!infile)
    {
        std::cout<<"There is no file to load"<<std::endl;
        return ;
    }
    int r;
    infile>>r;
    int floor=r/100;
    r%=100;
    r=(r-1)+(30*(floor-1));
    r_obj->rooms[r]=full;
    while(!infile.eof())
    {
        infile>>r;
        int floor=r/100;
        r%=100;
        r=(r-1)+(30*(floor-1));
        r_obj->rooms[r]=full;
    }
    infile.close();
}

void Interface::save_stat_room()
{
    std::ofstream outfile("stat_room.txt");
    for(int i=101;i<=130;i++)
    {
        if(r_obj->occupied(i))
        {
            outfile<<i
                   <<' ';
        }
    }
    for(int i=201;i<=230;i++)
    {
        if(r_obj->occupied(i))
        {
            outfile<<i
                   <<' ';
        }
    }
    for(int i=301;i<=330;i++)
    {
        if(r_obj->occupied(i))
        {
            outfile<<i
                   <<' ';
        }
    }
    outfile.close();
}
