// Name: Andrew Van
// Student ID: 141267179
// Email: avan3@myseneca.ca
// Date: November 10, 2018

#include "Item.h"
#include "Utilities.h"

size_t Item::m_widthField = 0;

Item::Item(std::string str) {
   Utilities tmp;
   bool more = false;
   tmp.setFieldWidth(0);
   size_t position = tmp.getFieldWidth();

   // Get the name
   m_name = tmp.extractToken(str, position, more);
   m_widthField = m_name.length() + 1;
   // Get the Serial Number
   if (more) {
      // str.erase(position, m_name.length() + 1);
      position += m_name.length() + 1;
      m_serialNumber = std::stoi(tmp.extractToken(str, position, more));
   }

   // Get the quantity
   if (more) {
      // str.erase(position, std::to_string(m_serialNumber).length() + 1);
      position += std::to_string(m_serialNumber).length() + 1;
      m_quantity = std::stoi(tmp.extractToken(str, position, more));
   }
   
   // Get the description
   if (more) {
      // str.erase(position, std::to_string(m_quantity).length() + 1); 
      position += std::to_string(m_quantity).length() + 1;
      m_description = tmp.extractToken(str, position, more);
   }
}

const std::string& Item::getName() const {
   return m_name;
}

const unsigned int Item::getSerialNumber() {
   return m_serialNumber++;
}

const unsigned int Item::getQuantity() {
   return m_quantity;
}

void Item::updateQuantity() {
   if (m_quantity) {
      m_quantity--;
   }
}

void Item::display(std::ostream& os, bool full) const {
   if (full) {
      os << std::setw(m_widthField) << std::left << m_name
         << "[" << std::setw(6) << std::right << std::setfill('0') << m_serialNumber << "]" << " "
         << std::setfill(' ') << "Quantity: " << std::setw(m_widthField) << std::left << m_quantity
         << "Description: " << m_description << std::endl;
      //TODO: Add formatting to the variables
   }
   else {
      os << std::setw(13) << std::left << m_name << "[" << std::setw(6) << std::right << std::setfill('0') << m_serialNumber << "]" << std::setfill(' ') << std::endl;
      //TODO: Add formatting
   }
}