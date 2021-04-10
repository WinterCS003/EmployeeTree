#ifndef EMPLOYEEINFO_H
#define EMPLOYEEINFO_H

#include <string>

class employeeInfo
{
private:
    std::string _name; // IN - name of employee
    int _ID;           // IN - id of employee
public:
    /*****************
     ** CONSTRUCTOR **
     *****************/
    employeeInfo(std::string, // IN - name of employee
                 int);        // IN - id of employee

    /***************
     ** MUTATORS **
     ***************/
    void setName(std::string); // IN - name of employee
    void setID(int);           // IN - id of employee

    /***************
     ** ACCESSORS **
     ***************/
    bool operator<(const employeeInfo&); // IN - employee to compare to
    bool operator>(const employeeInfo&); // IN - employee to compare to
    bool operator==(const employeeInfo&); // IN - employee to compare to
    friend std::ostream& operator<<(std::ostream& os, // IN - stream output
                                    const employeeInfo& e) // IN - employee to print
    {
        std::string output;
        output = "{ID: ";
        output += std::to_string(e._ID);
        output += ", Name: ";
        output += e._name;
        output += "}";

        os << output;

        return os;
    }
};

#endif // EMPLOYEEINFO_H

/****************************************************************
 * employeeInfo Class
 *   This class represents an employee. It manages 2 attributes
 *   a name, and an ID. The uesr can create an employee, change
 *   set a name and id, and perform comparisons between the
 *   ID's of different employees.
 ***************************************************************/


/******************************
 ** CONSTRUCTOR & DESTRUCTOR **
 ******************************/

/****************************************************************
 * employeeInfo(std::string, int);
 *   Constructor; Initialize the name and id of employee
 *   Parameters: name (std::string) // IN - name of employee
 *               id   (int) //IN - id of employee
 *   Return: none
 ***************************************************************/


/**************
 ** MUTATORS **
 **************/

/*******************************************************************
 * void setID(int ID);
 *
 *   Mutator; This method will update the ID attribute to the
 *   parameter.
 *------------------------------------------------------------------
 *   Parameter: ID (int) // IN – id of employee
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/

/*******************************************************************
 * void setName(std::string name);
 *
 *   Mutator; This method will update the name attribute to the
 *   parameter.
 *------------------------------------------------------------------
 *   Parameter: name (std::string) // IN – name of employee
 *------------------------------------------------------------------
 *   Return: none
 *******************************************************************/


/***************
  ** ACCESSORS **
  ***************/

/****************************************************************
 * bool operator<(const employeeInfo&)
 *
 *   Accessor; This method will compare the ID's of 2 employees.
 *             True is returned if the calling object's id is
 *             smaller.
 * --------------------------------------------------------------
 *   Parameters: e (const employeeInfo&) // IN - reference to
 *                                               another employee
 *                                               object
 * --------------------------------------------------------------
 *   Return: bool
 ***************************************************************/

/****************************************************************
 * bool operator>(const employeeInfo&)
 *
 *   Accessor; This method will compare the ID's of 2 employees.
 *             True is returned if the calling object's id is
 *             greater.
 * --------------------------------------------------------------
 *   Parameters: e (const employeeInfo&) // IN - reference to
 *                                               another employee
 *                                               object
 * --------------------------------------------------------------
 *   Return: bool
 ***************************************************************/

/****************************************************************
 * bool operator==(const employeeInfo&)
 *
 *   Accessor; This method will compare the ID's of 2 employees.
 *             True is returned if the calling object's id is
 *             the same.
 * --------------------------------------------------------------
 *   Parameters: e (const employeeInfo&) // IN - reference to
 *                                               another employee
 *                                               object
 * --------------------------------------------------------------
 *   Return: bool
 ***************************************************************/

/****************************************************************
 * std::ostream& operator<<(std::ostream& os, const employeeInfo& e)
 *
 *   Accessor; This method will print the name and id of the
 *             employee to the terminal.
 * --------------------------------------------------------------
 *   Parameters: os (std::ostream&) // IN - reference to the stream
 *                                          output.
 *               e (const employeeInfo&) // IN - reference to
 *                                               another employee
 *                                               object
 * --------------------------------------------------------------
 *   Return: stream output object, employee info is printed to
 *           terminal
 ***************************************************************/
