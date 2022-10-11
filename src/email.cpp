#include "email.hpp"

Email::Email(const std::string message){
	message_=message;
}

Email::Email(){
	message_=" ";
}

std::string Email::getMessage() const {
	return message_;
}