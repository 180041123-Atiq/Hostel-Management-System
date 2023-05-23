#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<iostream>
#include<string>

class Employee
{
public:
    /** Default constructor */
    Employee();
    virtual const void show_info()=0;
    virtual void disk_in()=0;
    virtual void disk_out()=0;
    virtual std::string id_gnrt(std::string s_name)=0;
    virtual std::string pwd_gnrt()=0;
    virtual void del_own_rec()=0;
    virtual bool login_op()=0;


    /** Access id
     * \return The current value of id
     */
    std::string Getid()
    {
        return id;
    }
    /** Set id
     * \param val New value to set
     */
    void Setid(std::string val)
    {
        id = val;
    }
    /** Access pwd
     * \return The current value of pwd
     */
    std::string Getpwd()
    {
        return pwd;
    }
    /** Set pwd
     * \param val New value to set
     */
    void Setpwd(std::string val)
    {
        pwd = val;
    }
    /** Access name
     * \return The current value of name
     */
    std::string Getname()
    {
        return name;
    }
    /** Set name
     * \param val New value to set
     */
    void Setname(std::string val)
    {
        name = val;
    }
    /** Access desg
     * \return The current value of desg
     */
    std::string Getdesg()
    {
        return desg;
    }
    /** Set desg
     * \param val New value to set
     */
    void Setdesg(std::string val)
    {
        desg = val;
    }

    virtual ~Employee()
    {

    }

protected:

private:
    std::string id; //!< Member variable "id"
    std::string pwd; //!< Member variable "pwd"
    std::string name; //!< Member variable "name"
    std::string desg; //!< Member variable "desg"

};

#endif // EMPLOYEE_H
