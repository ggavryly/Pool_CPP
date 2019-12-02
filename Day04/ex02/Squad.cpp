#include "Squad.hpp"

Squad::Squad()
{
	this->num_units = 0;
	this->max_units = 30;
	for (int i = 0; i < 30; i++)
		this->squad_arr[i] = nullptr;
}

int Squad::getCount() const
{
	return this->num_units;
}

ISpaceMarine* Squad::getUnit(int a) const
{
	if (a < this->getCount())
		return this->squad_arr[a];
	return nullptr;
}

Squad::~Squad()
{
	for (int i = 0; i < this->num_units; i++)
		delete this->squad_arr[i];
}

int Squad::push(ISpaceMarine *robotyaga)
{
	if (this->num_units < 30 && robotyaga)
	{
		for (int i = 0; i < this->num_units + 1; i++)
		{
			if (this->squad_arr[i] == robotyaga)
				return this->num_units;
		}
		this->squad_arr[this->num_units++] = robotyaga;
	}
	return this->num_units;
}

Squad & Squad::operator=(Squad const &a)
{
	if (this != &a)
	{
		for(int i = 0; i < a.getCount(); i++)
		{
			delete this->squad_arr[i];
			this->squad_arr[i] = a.squad_arr[i]->clone();
		}
		this->num_units = a.getCount();
	}
	return *this;
}

Squad::Squad(Squad const &a)
{
	*this = a;
}



