#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "CString.h"

int MAX = 3;
static int count = 0;

namespace w1 {
   // CString Constructor:
   CString::CString(char * str) : max_char{MAX} {
      word = new char[max_char+1];
      if (str == nullptr) {
         strncpy(word, '\0', max_char);
      }
      else {
         strncpy(word, str, max_char);
         word[max_char] = '\0';
      }
   }

   // CString Destructor:
   CString::~CString() {
      delete [] word;
      word = nullptr;
   }
   // Display:
   std::ostream & CString::display(std::ostream & os) const {
      os << word;
      return os;
   }

   // Helper function:
   std::ostream& operator<<(std::ostream& os, const CString& obj) {
	  os << count++ << ": "; 
      obj.display(os);
      return os;
   }
}
