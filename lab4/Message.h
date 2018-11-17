// Name: Andrew Van
// Student ID: 141267179
// Email: avan3@myseneca.ca
// Date: October 5, 2018

#ifndef MESSAGE_H
#define MESSAGE_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

namespace w4 {
class Message {
private:
   std::string user;
   std::string reply;
   std::string tweet;
public:
   Message() : user {}, reply {}, tweet {} {};
   Message(std::ifstream& in, char c); 
   bool empty() const; // Query returns true if object is in safe empty state
   void display(std::ostream& os) const; // Display function
};
}
#endif // !MESSAGE_H