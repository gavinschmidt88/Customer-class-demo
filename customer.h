#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>

using namespace std;

class customer
{
  public:
    customer(string, int, string, string, string);
    customer();

    //getters
    string getName();
    int getID();
    string getStreet();
    string getCityStateZip();
    string getPhone();

    //setters
    void setName(string);
    void setID(int);
    void setStreet(string);
    void setCityStateZip(string);
    void setPhone(string);

    //comparision operators
    bool operator<(const customer&);
		bool operator>(const customer&);
		bool operator>=(const customer&);
		bool operator<=(const customer&);
		bool operator==(const customer&);
		bool operator!=(const customer&);

    //otuput stream overload
    friend ostream& operator<<(ostream&, const customer&);

  //private variables to create instances
  private:
    string customerName;
    int customerID;
    string customerStreet;
    string customerCityStateZip;
    string customerPhoneNumber;

};

#endif
