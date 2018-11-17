#ifndef W1_CSTRING_H
#define W1_CSTRING_H

#include <iostream>


namespace w1 {
	class CString {
	private:
		const int max_char;
		char * word;
	public:
	   CString(char * str);
      ~CString();
      std::ostream& display(std::ostream& os) const;
	};
   std::ostream& operator<<(std::ostream& os, const CString& obj);
}

#endif