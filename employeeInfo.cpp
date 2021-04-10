#include "employeeInfo.h"

/**********************************************************
 *
 * CONSTRUCTOR employeeInfo
 *_________________________________________________________
 * This function receives and initializes the name and id
 * of the employee
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     name: std::string name of employee
 *     ID: int id of employee
 *
 * POST-CONDITIONS
 *   This function will initialize the name and id of
 *   employee
 ***********************************************************/
employeeInfo::employeeInfo(std::string name, // IN - name of employee
                           int ID)           // IN - id of employee
{
    _name = name;
    _ID = ID;
}

/***********************************************************
 *
 * FUNCTION setID
 *__________________________________________________________
 * This function receives and updates the id of the employee
 *__________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     ID: new id of employee
 *
 * POST-CONDITIONS
 *   This function will update the employee id
 ************************************************************/
void employeeInfo::setID(int ID) // IN - id of employee
{
    _ID = ID;
}

/***********************************************************
 *
 * FUNCTION setName
 *__________________________________________________________
 * This function receives and updates the name of the
 * employee
 *__________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     name: new name of employee
 *
 * POST-CONDITIONS
 *   This function will update the employee name
 ************************************************************/
void employeeInfo::setName(std::string name) // IN - name of employee
{
    _name = name;
}

/**********************************************************
 *
 * FUNCTION operator<
 *_________________________________________________________
 * This functionreceives an employeeInfo object and
 * compares its ID with the calling object's ID.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     e: employeeInfo object to compare
 *
 * POST-CONDITIONS
 *   This function will output true if the calling object's
 *   id is less than the operand's id.
 ***********************************************************/
bool employeeInfo::operator<(const employeeInfo& e) // IN - employee to compare
{
    return this->_ID < e._ID;
}

/**********************************************************
 *
 * FUNCTION operator>
 *_________________________________________________________
 * This functionreceives an employeeInfo object and
 * compares its ID with the calling object's ID.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     e: employeeInfo object to compare
 *
 * POST-CONDITIONS
 *   This function will output true if the calling object's
 *   id is greater than the operand's id.
 ***********************************************************/
bool employeeInfo::operator>(const employeeInfo& e) // IN - employee to compare
{
    return this->_ID > e._ID;
}

/**********************************************************
 *
 * FUNCTION operator==
 *_________________________________________________________
 * This functionreceives an employeeInfo object and
 * compares its ID with the calling object's ID.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     e: employeeInfo object to compare
 *
 * POST-CONDITIONS
 *   This function will output true if the calling object's
 *   id is equal to the operand's id.
 ***********************************************************/
bool employeeInfo::operator==(const employeeInfo& e) // IN - employee to compare
{
    return this->_ID == e._ID;
}
