#ifndef VICTIM_HPP
# define VICTIM_HPP

#include <iostream>

class Victim
{
public:
	Victim(std::string name = "Slave");
	Victim(Victim const &);
	~Victim();
	Victim &operator=(Victim const &);
	std::string getName() const;
	std::string getTitle() const;
	void setName(std::string const &);
	void setTitle(std::string const &);
	virtual void getPolymorphed() const;
protected:
	std::string name_;
};

std::ostream & operator<<(std::ostream & o, Victim const &s);

#endif