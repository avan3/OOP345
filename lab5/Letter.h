// Name: Andrew Van
// Student ID: 141267179
// Email: avan3@myseneca.ca
// Date: October 11, 2018

#define _CRT_SECURE_NO_WARNINGS
#ifndef SICT_LETTER_H
#define SICT_LETTER_H

#include <iostream>

namespace sict {
   enum class Letter { A_PLUS, A, B_PLUS, B, C_PLUS, C, D_PLUS, D, F };

   template <typename T>
   const char* convert(const T& enumConst) {
      switch (enumConst) {
         case Letter::A_PLUS:
            return "A+";
         case Letter::A:
            return "A ";
         case Letter::B_PLUS:
            return "B+";
         case Letter::B:
            return "B ";
         case Letter::C_PLUS:
            return "C+";
         case Letter::C:
            return "C ";
         case Letter::D_PLUS:
            return "D+";
         case Letter::D:
            return "D ";
         default:
            return "F ";
      }
   }
}
#endif