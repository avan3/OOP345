// Name: Andrew Van
// Student ID: 141267179
// Email: avan3@myseneca.ca
// Date: October 11, 2018

#ifndef SICT_GRADES_H
#define SICT_GRADES_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

namespace sict {
   class Grades {
   private:
      char * name;
      double* grade;
      long long* stdNo;
      size_t size;
   public:
      Grades() : name{ nullptr } {};
      Grades(char * fileName);
      template <typename F>
      void displayGrades(std::ostream& os, F letter) const {
         for (size_t i = 0; i < size; i++) {
            auto enumCovert = letter(grade[i]);
            const char * letterGrade = convert(enumCovert);
            os << "   " << stdNo[i] << " ";
            os << std::fixed << std::setprecision(2) << grade[i] << " ";
            os << letterGrade << "  " << std::endl;
         }
      }
      Grades(const Grades&) = delete;
      Grades& operator=(const Grades&) = delete;
      Grades(const Grades&&) = delete;
      Grades&& operator=(const Grades&&) = delete;
   };
}
#endif