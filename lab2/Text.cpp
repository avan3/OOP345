#define _CRT_SECURE_NO_WARNINGS
#include "Text.h"

namespace w2 {
   // One argument constructor: allocate memory for lines in file and copy into memory
   Text::Text(const char * str) : lines{nullptr} {
      std::ifstream fin(str, std::ios::in);
      if (fin.is_open()) {
         numLines = 1; // File starts at line 1 --> Increment numLines to match
         std::string tmp;
         while (std::getline(fin, tmp)) { // Counts each line of file and increment numLines
            ++numLines; 
         }
         fin.clear();
         fin.seekg(0); // Move file pointer to beginning of file again
         lines = new std::string[numLines + 1]; // Allocate memory for number of lines in file
         for (int i = 0; i < numLines; i++) {
            std::getline(fin, lines[i]);
         }
         fin.close();
      }
      else {
         *this = Text();
      }
   }

   // Destructor: deallocate dynamically allocated memory
   Text::~Text() {
      delete [] lines;
   }

   // Copy constructor:
   Text::Text(Text& src) {
      lines = nullptr;
      *this = src;
   }

   // Copy assignment operator
   Text& Text::operator=(Text& src) {
      if (this != &src) {
         numLines = src.numLines;
         lines = nullptr;
         if (src.lines != nullptr) {
            lines = new std::string[numLines + 1];
            for (int i = 0; i < numLines; i++) {
               lines[i] = src.lines[i]; 
            }
         }
      }
      return *this;
   }

   // Move constructor:
   Text::Text(Text&& rhs) {
      *this = std::move(rhs); // Make rhs an rlvaue
   }
   
   // Move assignment operator:
   Text& Text::operator=(Text&& rhs) {
      if (this != &rhs) {
         // Move numLines to current object and set rhs to 0
         numLines = rhs.numLines;
         rhs.numLines = 0;
         // Move the file records to current object and set rhs to nullptr
         lines = rhs.lines;
         rhs.lines = nullptr;
      }
      return *this;
   }

   // Query for numLines
   size_t Text::size() const {
      return numLines;
   }
}
