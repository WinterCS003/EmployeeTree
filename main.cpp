/******************************************************************
 * AUTHOR       : Jaemok C. Lee
 * ASSIGNMENT 6 : Binary Search Trees
 * CLASS        : CS 008 Data Structures
 * SECTION      : 6:30p - 8:35
 * DUE DATE     : 04/20/2021
 ******************************************************************/

#include <iostream>
#include <string>

#include "binarySearchTree.h"
#include "employeeInfo.h"

/****************************************************************
 * enum option
 *   This is an enum that refers to the possible options a user
 *   has when using the menu.
 ***************************************************************/
enum option {Quit, Insert, Search, Remove, InOrder, PreOrder, PostOrder, Leaf, NonLeaf, Size, Front, Copy, Assign, Menu, Error};

/****************************************************************
 * show_menu
 *   This function receives nothing and prints the menu to the
 *   screen.
 *   -returns  nothing -> This will output the menu.
 ***************************************************************/
void show_menu();

/****************************************************************
 * operator>>
 *   This function receives an enum option and reads from the
 *   input stream to assign the option a value. An error flag
 *   is set to indicate an invalid choice.
 *   -returns input stream.
 ***************************************************************/
std::istream& operator>>(std::istream& is, option& o);

/************************************************************
*
* Binary Search Tree
*___________________________________________________________
* This program is a Binary Search Tree of employees
* implemented using pointers.
*___________________________________________________________
* INPUTS:
*   The user can input an option from a list of choices of
*   a menu.
*
* OUTPUTS:
*   According the the menu, the user has 12 different choices.
*************************************************************/

int main(){
    BinaryTree<employeeInfo> staff;

    option choice = Menu;
    show_menu();
    while(choice != Quit){
        std::cout << "Choose an option 1-10 (0 to quit, 11 to show menu): ";
        std::cin >> choice;
        std::cout << std::endl << std::endl;

        std::string name;
        int ID;
        employeeInfo fake("Fake", 0);
        if(choice == Quit)
        {
            std::cout << "Quitting..." << std::endl;
        }
        else if(choice == Insert)
        {
            std::cin.ignore();
            std::cout << "Enter a name: ";
            std::getline(std::cin, name);
            std::cout << "Enter an ID: ";
            std::cin >> ID;
            std::cout << std::endl;

            fake.setName(name);
            fake.setID(ID);
            staff.insertNode(fake);
            std::cout << std::endl;
        }
        else if(choice == Search)
        {
            std::cout << "Enter an employee's ID number: ";
            std::cin >> ID;
            std::cout << std::endl;

            std::cout << "Results: ";
            fake.setID(ID);
            staff.searchNode(fake);
            std::cout << std::endl;
        }
        else if(choice == Remove)
        {
            std::cout << "Enter an employee's ID number: ";
            std::cin >> ID;
            std::cout << std::endl;

            std::cout << "Results: ";
            fake.setID(ID);
            staff.remove(fake);
            std::cout << std::endl;
        }
        else if(choice == InOrder)
        {
            std::cout << "--- In-Order Display ---\n";
            staff.displayInOrder();
            std::cout << std::endl;
        }
        else if(choice == PreOrder)
        {
            std::cout << "--- Pre-Order Display ---\n";
            staff.displayPreOrder();
            std::cout << std::endl;
        }
        else if(choice == PostOrder)
        {
            std::cout << "--- Post-Order Display ---\n";
            staff.displayPostOrder();
            std::cout << std::endl;
        }
        else if(choice == Leaf)
        {
            std::cout << "Leaf count: ";
            std::cout << staff.leaf_count() << std::endl;
            std::cout << std::endl;
        }
        else if(choice == NonLeaf)
        {
            std::cout << "Non-leaf count: ";
            std::cout << staff.non_leaf_count() << std::endl;
            std::cout << std::endl;
        }
        else if(choice == Size)
        {
            std::cout << "Size: ";
            std::cout << staff.size() << std::endl;
            std::cout << std::endl;
        }
        else if(choice == Front)
        {
            std::cout << "Front node: ";
            std::cout << staff.frontNode() << std::endl;
            std::cout << std::endl;
        }
        else if(choice == Copy)
        {
            BinaryTree<employeeInfo> copy = staff;
            std::cout << "Printing the original tree: \n";
            staff.displayInOrder();
            std::cout << "\n\nPrinting the new tree: \n";
            copy.displayInOrder();
            std::cout << "\nShould be the same\n";
        }
        else if(choice == Assign)
        {
            BinaryTree<employeeInfo> assign;
            assign = staff;
            std::cout << "Printing the original tree: \n";
            staff.displayInOrder();
            std::cout << "\n\nPrinting the new tree: \n";
            assign.displayInOrder();
            std::cout << "\nShould be the same\n";
        }
        else if(choice == Menu)
        {
            show_menu();
        }
        else
        {
            std::cout << "Invalid choice" << std::endl;
            show_menu();
        }
    }

    return 0;
}

/**********************************************************
 *
 * FUNCTION show_menu
 *_________________________________________________________
 * This function receives nothing and prints the menu
 * of choices to perform on the binary search tree to
 * the screen.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   none
 *
 * POST-CONDITIONS
 *   This function will output all the possible choices
 *   to the screen.
 ***********************************************************/
void show_menu()
{
    std::cout << "---Menu---\n\n";
    std::cout << "1: Insert | 2: Search | 3: Remove\n"
              << "4: Display In-Order | 5: Display Pre-Order | 6: Display Post-Order\n"
              << "7: Leaf Count | 8: Non-Leaf Count | 9: Size\n"
              << "10: Show Front | 11: Make New Copy | 12: Copy using assignment operator\n"
              << "13: Show Menu | 0: Quit\n\n";
}

/**********************************************************
 *
 * FUNCTION operator>>
 *_________________________________________________________
 * This function receives a stream input and an option.
 * The function updates the option with user input taken
 * from the stream.
 *_________________________________________________________
 * PRE-CONDITIONS
 *   The following need previously defined values:
 *     is: reference to the input stream
 *     o: an option to set
 *
 * POST-CONDITIONS
 *   This function will set the option t othe user input.
 ***********************************************************/
std::istream& operator>>(std::istream& is, // IN - input stream
                         option& o)        // IN - option to set
{
    int choice = -1;
    is >> choice;

    if(choice < 0 || choice > 13){
        o = Error;
    }else{
        o = static_cast<option>(choice);
    }

    return is;
}
