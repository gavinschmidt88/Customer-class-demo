#include "customer.h"
#include <string>

using namespace std;

customer::customer(string customerName, int customerID, string customerStreet, string customerCityStateZip, string customerPhoneNumber)
{
  this->customerName = customerName;
  this->customerID = customerID;
  this->customerStreet = customerStreet;
  this->customerCityStateZip = customerCityStateZip;
  this->customerPhoneNumber = customerPhoneNumber;
}

//default constructor
customer::customer()
{
  customerName = "None";
  customerID = 000000;
  customerStreet = "None";
  customerCityStateZip = "None";
  customerPhoneNumber = "(000)000-0000";
}

//GETTERS
  string customer::getName()
  {
    return customerName;
  }

  int customer::getID()
  {
    return customerID;
  }

  string customer::getStreet()
  {
    return customerStreet;
  }

  string customer::getCityStateZip()
  {
    return customerCityStateZip;
  }

  string customer::getPhone()
  {
    return customerPhoneNumber;
  }

//SETTERS
  void customer::setID(int)
  {
    this->customerID = customerID;
  }

  void customer::setName(std::string)
  {
    this->customerName = customerName;
  }

  void customer::setStreet(std::string)
  {
    this->customerStreet = customerStreet;
  }

  void customer::setCityStateZip(std::string)
  {
    this->customerCityStateZip = customerCityStateZip;
  }

  void customer::setPhone(std::string)
  {
    this->customerPhoneNumber = customerPhoneNumber;
  }

  //comparison operators
  bool customer::operator<(const customer& othCustomer)
{
	return this->customerID < othCustomer.customerID;
}
bool customer::operator>(const customer& othCustomer)
{
	return this->customerID > othCustomer.customerID;
}
bool customer::operator>=(const customer& othCustomer)
{
	return this->customerID >= othCustomer.customerID;
}
bool customer::operator<=(const customer& othCustomer)
{
	return this->customerID <= othCustomer.customerID;
}
bool customer::operator==(const customer& othCustomer)
{
	return this->customerID == othCustomer.customerID;
}
bool customer::operator!=(const customer& othCustomer)
{
	return this->customerID != othCustomer.customerID;
}


//output stream overload
ostream& operator<<(ostream& out, const customer& myCustomer)
{
  out << "(" << myCustomer.customerID << ") " << myCustomer.customerName << endl;
  out << myCustomer.customerStreet << endl;
  out << myCustomer.customerCityStateZip << endl;
  out << myCustomer.customerPhoneNumber << endl;
  return out;
}