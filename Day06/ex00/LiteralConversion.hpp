 //
// Created by Gennady GAVRYLYSHYN on 2019-10-10.
//

#ifndef PISCINE_LITERALCONVERSION_HPP
#define PISCINE_LITERALCONVERSION_HPP


#include <string>
#include <iostream>
#include <iosfwd>
#include <cmath>
 class LiteralConversion {
 	private:
		std::string		_value;
	 	std::string		_char_view;
		std::string		_int_view;
		std::string		_float_view;
		std::string		_double_view;
		bool			_is_inf_plus;
		bool			_is_inf_minus;
		bool			_is_nan;
		bool			_is_char;
		bool			_is_int;
		bool			_is_float;
		bool			_is_double;
		int				_is_minus;
		char			_value_char;
		int 			_value_int;
	 	float			_value_float;
	 	double			_value_double;
	 LiteralConversion& operator=(LiteralConversion const &);
	public:

	 explicit LiteralConversion(const std::string &value);
	 LiteralConversion(LiteralConversion const &);
	 virtual ~LiteralConversion();
	 void	valueToNan();
	 void	valueToInfP();
	 void	valueToInfM();
	 void	valueToCharView();
	 void	valueToIntView();
	 void	valueToFloatView();
	 void	valueToDoublerView();
	 void	initialize();
	 void	present_literals(int error);
	 int	conversion_literals();

 };


#endif //PISCINE_LITERALCONVERSION_HPP
