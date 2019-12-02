# ifndef REPLACE_HPP
# define REPLACE_HPP
# include <iostream>

class Replace
{
public:
	Replace(std::string const & dst, std::string const & src);
	std::string replace();
	void setCur(std::string const &);
	std::string dst_;
	std::string src_;
	std::string cur_;
};

#endif