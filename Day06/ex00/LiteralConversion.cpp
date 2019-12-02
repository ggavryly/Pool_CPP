//
// Created by Gennady GAVRYLYSHYN on 2019-10-10.
//

#include "LiteralConversion.hpp"

LiteralConversion::LiteralConversion(const std::string &value)
				: _is_inf_plus(false)
				, _is_inf_minus(false)
				, _is_nan(false)
				, _is_char(false)
				, _is_int(false)
				, _is_float(false)
				, _is_double(false)
				, _is_minus(false)
{
	this->_value = value;
	if (_value.size() == 1)
		_is_char = true;
	if (_value[0] == '-')
		_is_minus = 1;
	if (_value[0 + _is_minus] >= '0' && _value[0 + _is_minus] <= '9')
	{
		if (_value.find('.', 1 + _is_minus) != std::string::npos && _value.find('f', 2 + _is_minus) != std::string::npos)
			_is_float = true;
		else if (_value.find('.', 1 + _is_minus) != std::string::npos && _value.find('f', 2 + _is_minus) == std::string::npos)
			_is_double = true;
		else
			_is_int = true;
	}
	else if (_value == "nan")
		_is_nan = true;
	else if (_value == "+inf")
		_is_inf_plus = true;
	else if (_value == "-inf")
		_is_inf_minus = true;
	this->initialize();
	this->present_literals(this->conversion_literals());
}

int LiteralConversion::conversion_literals() {
	if (_is_int)
		valueToIntView();
	else if (_is_char)
		valueToCharView();
	else if (_is_float)
		valueToFloatView();
	else if (_is_double)
		valueToDoublerView();
	else if (_is_inf_plus)
		valueToInfP();
	else if (_is_inf_minus)
		valueToInfM();
	else if (_is_nan)
		valueToNan();
	else {
		_char_view = "char: impossible";
		_int_view = "int: impossible";
		_float_view = "float: impossible";
		_double_view = "double: impossible";
		return 1;
	}
	return 0;
}

LiteralConversion::LiteralConversion(LiteralConversion const &) {

}



LiteralConversion::~LiteralConversion() {
}

LiteralConversion& LiteralConversion::operator=(LiteralConversion const &) {
	return *this;
}

void LiteralConversion::initialize() {
	if (_is_int)
		_value_int = std::strtol(this->_value.c_str(), nullptr, 10);
	else if (_is_double)
		_value_double = std::strtod(this->_value.c_str(), nullptr);
	else if (_is_float)
		_value_float = std::strtof(this->_value.c_str(), nullptr);
	else if (_is_char)
		_value_char = _value[0];
}

void LiteralConversion::valueToIntView() {
	_value_char = static_cast<char>(_value_int);
	_value_float = static_cast<float>(_value_int);
	_value_double = static_cast<double>(_value_int);
}

void LiteralConversion::valueToFloatView() {
	_value_char = static_cast<char>(_value_float);
	_value_int = static_cast<int>(_value_float);
	_value_double = static_cast<double>(_value_float);
}

void LiteralConversion::valueToDoublerView() {
	_value_char = static_cast<char>(_value_double);
	_value_int = static_cast<int>(_value_double);
	_value_float = static_cast<float>(_value_double);
}

void LiteralConversion::valueToCharView() {
	_value_int = static_cast<int>(_value_char);
	_value_float = static_cast<float>(_value_char);
	_value_double = static_cast<double>(_value_char);
}

void LiteralConversion::valueToInfM() {
	_char_view = "char: impossible";
	_int_view = "int: impossible";
	_float_view = "float: -inff";
	_double_view = "double: -inf";
}

void LiteralConversion::valueToInfP() {
	_char_view = "char: impossible";
	_int_view = "int: impossible";
	_float_view = "float: +inff";
	_double_view = "double: +inf";
}

void LiteralConversion::valueToNan() {
	_char_view = "char: impossible";
	_int_view = "int: impossible";
	_float_view = "float: nanf";
	_double_view = "double: nan";
}

void LiteralConversion::present_literals(int error) {
	if (_is_nan || _is_inf_minus || _is_inf_plus || error) {
		std::cout << _char_view << std::endl <<
				  _int_view << std::endl <<
				  _float_view << std::endl <<
				  _double_view << std::endl;
	} else {
		std::cout << "char: ";
		if (std::strtol(this->_value.c_str(), nullptr, 10) >= CHAR_MIN  && std::strtol(this->_value.c_str(), nullptr, 10) <= CHAR_MAX && std::isprint(_value_char))
			std::cout << "'" << _value_char << "'";
		else if (std::strtol(this->_value.c_str(), nullptr, 10) < CHAR_MIN  || std::strtol(this->_value.c_str(), nullptr, 10) > CHAR_MAX)
			std::cout << "impossible";
		else
			std::cout << "Non displayable";
		std::cout << std::endl;
		std::cout << "int: ";
		if (std::strtol(this->_value.c_str(), nullptr, 10) >= INT_MIN  && std::strtol(this->_value.c_str(), nullptr, 10) <= INT_MAX)
			std::cout << _value_int;
		else
			std::cout << "impossible";
		std::cout << std::endl;
		std::cout.setf(std::ios::fixed);
		std::cout.precision(1);
		if (std::isinf(_value_float))
			std::cout << "float: " << ((_is_minus) ? ("") : ("+")) << _value_float << "f" << std::endl;
		else
			std::cout << "float: " << _value_float << "f" << std::endl;
		if (std::isinf(_value_double))
			std::cout << "float: " << ((_is_minus) ? ("") : ("+")) << _value_double << std::endl;
		else
			std::cout << "double: " << _value_double << std::endl;
	}
}






