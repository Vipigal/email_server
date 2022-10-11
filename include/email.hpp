#include <string>

class Email{
	public:
		Email(const std::string message);
		Email();
		std::string getMessage() const;
	private:
		std::string message_;
};