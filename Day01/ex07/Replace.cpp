# include "Replace.hpp"
Replace::Replace(std::string const & dst, std::string const & src) : dst_(dst), src_(src)
{}

void Replace::setCur(std::string const & cur)
{
	this->cur_ = cur;
}

std::string Replace::replace()
{
	std::size_t occur = 0;
	while (occur != std::string::npos)
	{
		this->cur_.replace(occur, this->dst_.size(), this->src_);
		occur = this->cur_.find(this->dst_);
	}
	return this->cur_;
}