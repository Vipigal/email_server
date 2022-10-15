#include <string>

class Email{
	public:
		Email(const std::string message);
		Email();
		std::string getMessage() const;
		void setRank(int pri);
		int getRank() const;
	private:
		std::string message_;
		int rank;
};