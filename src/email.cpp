#include "email.hpp"

Email::Email(const std::string message){
	message_=message;
}

Email::Email(){
	message_=" ";
}

void Email::setRank(int pri){
	rank=pri;
}

int Email::getRank() const {
	return rank;
}

std::string Email::getMessage() const {
	return message_;
}