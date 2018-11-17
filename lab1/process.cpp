#include "process.h"
#include "CString.h"

void process(char * str, std::ostream& os) {
   w1::CString obj(str);
   os << obj << std::endl;
}