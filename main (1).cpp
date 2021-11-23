// Program name: main.cpp
// Author: Gavin Schmidt
// Date last updated: 9/10/2021
// Purpose: Take input from the user about customers and store the in an ordered linked list

#include <iostream>
#include "customer.h"
#include "orderedLinkedList.h"
#include <cstdlib>
#include <climits>
#include <string>

using namespace std;

int main() {

  //creating the list
  orderedLinkedList<customer> list;
  list.print();

  //variables for saving user input
  int userSelection, customerID, T;
  string customerName, customerStreet, customerCityStateZip, customerPhoneNumber;

  //user choices
  do{
    cout << "Please choose an option from the menu:" << endl;
    cout << "1. Add a customer" << endl;
    cout << "2. Delete a customer" << endl;
    cout << "3. Display the list" << endl;
    cout << "4. Exit" << endl;
    cin >> userSelection;

    //while no input or user selection is not between 1 and 4
    while (!cin || userSelection < 1 || userSelection > 4)
	  {
		  if(!cin)
		  {
			  cin.clear();
			  cin.ignore(INT_MAX,'\n');
		  }
		cout << "That is not valid input. Please enter a number between 1 and 4: ";
		cin >> userSelection;
		cout << endl;
	  }

    if(userSelection == 1)
    {  

      //taking user input and saving it
      cout << "Enter the customer id: ";
      cin >> customerID;
      cin.ignore(1000, '\n');
      cout << endl;
     
      cout << "Enter the customer name (first and last): ";
      getline(cin, customerName);
      cout << endl;

      cout << "Enter " << customerName << "'s street address: ";
      getline(cin, customerStreet);
      cout << endl;

      cout << "Enter the city, state and zip code for the address: ";
      getline(cin, customerCityStateZip);
      cout << endl;

      cout << "Enter " << customerName << "'s phone number: ";
      getline(cin, customerPhoneNumber);
      cout << endl;

      //creating new instance of customer
      customer *c = new customer(customerName, customerID, customerStreet, customerCityStateZip, customerPhoneNumber);
      
      //use the pointer to input the new customer
      list.sortedInsert(*c);
      delete c;
    }
    else if(userSelection == 2)
    {
      cout << "Please choose the ID of the customer you want to delete: ";
      cin >> T;
      cout << endl;

      //makes a 'deleteCustomer' to use later
      customer deleteCustomer;
      deleteCustomer.setID(T);

      //uses the 'deleteCustomer' to find a match and deletes it
      list.deleteNode(deleteCustomer);
      list.print();
    }
    else if(userSelection == 3)
    {
      //calls print list
      list.print();
    }

  }while(userSelection != 4);

  return 0;
  
} //ends main