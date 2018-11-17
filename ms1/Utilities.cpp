// Name: Andrew Van
// Student ID: 141267179
// Email: avan3@myseneca.ca
// Date: November 10, 2018

#include "Utilities.h"

char Utilities::m_delimiter = ',';

void Utilities::setFieldWidth(size_t n) {
   this->m_widthField = n;
}

size_t Utilities::getFieldWidth() const {
   return m_widthField;
}

const std::string Utilities::extractToken(const std::string& str, size_t& next_post, bool& more) {
   if (str.find_first_of(m_delimiter) != 0) {
      size_t new_pos = str.find(getDelimiter(), next_post);
      std::string token = str.substr(next_post, new_pos - next_post);
      if (token.length() == 0) {
         more = false;
      }
      else if (token.length() > m_widthField) {
         more = true;
         this->setFieldWidth(token.length());
      }
      else {
         more = true;
      }
      return token;
   }
   else {
      throw nullptr; // TODO: Change this exception throw
   }
}

void Utilities::setDelimiter(const char c) {
   m_delimiter = c;   
}

const char Utilities::getDelimiter() const {
   return m_delimiter;
}