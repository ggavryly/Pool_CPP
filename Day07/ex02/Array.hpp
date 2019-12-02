//
// Created by Gennady GAVRYLYSHYN on 2019-10-11.
//

#ifndef PISCINE_ARRAY_HPP
#define PISCINE_ARRAY_HPP

#include <iostream>

template <typename T = int>
class Array
{
public:
	explicit Array(unsigned int size) : data_(static_cast<T*>(operator new [] (size * sizeof(T)))), size_(size)
	{
		for (size_t i = 0; i < size_; i++)
		{
			new (this->data_ + i) T();
		}
	}
	Array(const Array &a)
	{
		if (this != &a) {
			this->size_ = a.size();
			this->data_ = static_cast<T *>(operator new[](this->size_ * sizeof(T)));
			for (size_t i = 0; i < a.size_; i++)
				new(this->data_ + i) T(a.data_[i]);
		}
		else
			Array();
	}
	Array()  : data_(static_cast<T*>(operator new [] (0 * sizeof(T)))) , size_(0)
	{}
	~Array()
	{
		for (size_t i = 0; i < this->size_; i++)
		{
			this->data_[i].~T();
		}
		operator delete [] (this->data_);
	}
	Array& operator=(Array<T> const & a)
	{
		if (this != &a)
		{
			for (size_t i = 0; i < this->size_; i++)
			{
				this->data_[i].~T();
			}
			operator delete [] (this->data_);
			this->size_ = a.size();
			this->data_ = static_cast<T*>(operator new [] (this->size_ * sizeof(T)));
			for (size_t i = 0; i < this->size_; i++)
			{
				new (this->data_ + i) T(a.data_[i]);
			}
		}
		return *this;
	}
	size_t size() const
	{
		return this->size_;
	}
	T& operator[](size_t i)
	{
		if (i > size_)
			throw OutOfLimits();
		return this->data_[i];
	}
	const T& operator[](size_t i) const
	{
		if (i > size_)
			throw OutOfLimits();
		return this->data_[i];
	}
	class OutOfLimits : public std::exception {
		public:
			OutOfLimits() {

			}
			OutOfLimits(OutOfLimits const &) {

			}
			OutOfLimits &operator=(OutOfLimits const &) {

			}
			const char *what() const _NOEXCEPT {
				return "Accessing array out of bounds error";
			}
			~OutOfLimits() _NOEXCEPT {

			}
	};
private:
	T *data_;
	size_t size_;
};


#endif //PISCINE_ARRAY_HPP
