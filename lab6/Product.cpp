// Name: Andrew Van
// Student ID: 141267179
// Email: avan3@myseneca.ca
// Date: October 30, 2018

#include "Product.h"

namespace w6 {
   double Product::getPrice() const {
      return price;
   }

   void Product::display(std::ostream& os) const {
      os << std::setfill(' ') << std::setw(11) << ' ';
      os << std::setw(5) << std::setfill('0') << prodCode << std::setfill(' ');
      os << std::setw(16) << Product::getPrice();
   }
}