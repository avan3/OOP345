// Name: Andrew Van
// Student ID: 141267179
// Email: avan3@myseneca.ca
// Date: November 10, 2018

#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include <iomanip>

class Item {
private:
   std::string m_name;
   std::string m_description;
   unsigned int m_serialNumber;
   unsigned int m_quantity;
   static size_t m_widthField;
public:
   Item() : m_name{}, m_description{}, m_serialNumber{}, m_quantity{} {};
   Item(std::string str);
   const std::string& getName() const;
   const unsigned int getSerialNumber();
   const unsigned int getQuantity();
   void updateQuantity();
   void display(std::ostream& os, bool full) const;
};
#endif