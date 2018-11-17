// Name: Andrew Van
// Student ID: 141267179
// Email: avan3@myseneca.ca
// Date: October 11, 2018

#include "Grades.h"

namespace sict {
   Grades::Grades(char * fileName) : size{0} {
      std::ifstream fin(fileName, std::ios::in);
      if (fin.is_open()) {
         std::string tmp;
         size = 0; 
         while (std::getline(fin, tmp)) { // Counts each line of file and increment numLines
            ++size;
         }
         fin.clear();
         fin.seekg(0); // Move file pointer to beginning of file again
         grade = new double[size + 1]; // Allocate memory for number of lines in file
         stdNo = new long long[size + 1];
         for (size_t i = 0; i < size; i++) {
            fin >> stdNo[i];
            fin >> grade[i];
         }
         fin.close();
      }
   }
}