// Name: Andrew Van
// Student ID: 141267179
// Email: avan3@myseneca.ca
// Date: November 10, 2018

#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
#include <string>
#include <sstream>

class Utilities {
private:
   size_t m_widthField;
   static char m_delimiter;
public:
   void setFieldWidth(size_t);
   size_t getFieldWidth() const;
   const std::string extractToken(const std::string& str, size_t& next_post, bool& more);
   static void setDelimiter(const char);
   const char getDelimiter() const;
};
#endif