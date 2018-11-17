#ifndef W3_TEXT_H
#define W3_TEXT_H

#include <iostream>
#include <string>
#include <fstream>

namespace w2 {
   class Text {
   private:
      size_t numLines;
      std::string * lines;
   public:
      Text() : numLines{0}, lines{nullptr} {};
      Text(const char * str);
      Text(Text& src);
      Text& operator=(Text& src);
      Text(Text&& rhs);
      Text& operator=(Text&& rhs);
      ~Text();
      size_t size() const;
   };
}
#endif