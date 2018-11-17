// Workshop 5 - Lambda Expression
// 345_w5.cpp
// Chris Szalwinski & Dr. Elliott Coleshill
// 2018-08-22
// Name: Andrew Van
// Student ID: 141267179
// Email: avan3@myseneca.ca
// Date: October 11, 2018

#include <iostream>
#include "Grades.h"
#include "Letter.h"
using namespace sict;

int main(int argc, char* argv[]) {

   std::cout << "Command Line: ";
   for (int i = 0; i < argc; i++)
      std::cout << argv[i] << ' ';
   std::cout << std::endl;

   if (argc == 1) {
      std::cerr << "\n*** Insufficient number of arguments ***\n";
      std::cerr << "Usage: " << argv[0] << " fileName \n";
      return 1;
   }
   else if (argc != 2) {
      std::cerr << "\n*** Too many arguments ***\n";
      std::cerr << "Usage: " << argv[0] << " fileName \n";
      return 2;
   }

   //TODO: Update the main functions as per the specifications here
   Grades grades(argv[1]);

   auto letter = [](double grade) {
      if (grade >= 90) {
         return Letter::A_PLUS;
      }
      else if (grade >= 80) {
         return Letter::A;
      }
      else if (grade >= 75) {
         return Letter::B_PLUS;
      }
      else if (grade >= 70) {
         return Letter::B;
      }
      else if (grade >= 65) {
         return Letter::C_PLUS;
      }
      else if (grade >= 60) {
         return Letter::C;
      }
      else if (grade >= 55) {
         return Letter::D_PLUS;
      }
      else if (grade >= 50) {
         return Letter::D;
      }
      else {
          return Letter::F;
      }
   };

   grades.displayGrades(std::cout, letter);

   return 0;
}