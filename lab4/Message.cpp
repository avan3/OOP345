// Name: Andrew Van
// Student ID: 141267179
// Email: avan3@myseneca.ca
// Date: October 5, 2018

#include "Message.h"

namespace w4 {
Message::Message(std::ifstream& in, char c) {
   // Parse through the record to get the specific fields
   std::string temp;
   in >> user; // First field is user name
   if (in.get() == ' ') {
      std::getline(in, temp, c); // Get the rest of the record
      std::istringstream iss(temp);
      if (temp.find('@') == 0) { // If the character is @, then save it as a reply name
         std::getline(iss, reply, ' ');
         reply = reply.substr(1, c);
      }
      std::getline(iss, tweet, c); // Save the rest in the tweet 
   }
}

bool Message::empty() const {
   if (user.length() == 0) {
      return true;
   }
   return false;
}

void Message::display(std::ostream& os) const {
   if ((user.empty() == false && tweet.empty() == false) || reply.empty() == false) {
      os << "Message" << std::endl;
      os << " User  : " << user << std::endl;
      if (reply.length() != 0) {
         os << " Reply : " << reply << std::endl;
      }
      os << " Tweet : " << tweet << std::endl;   
      os << std::endl;
   }
}
}