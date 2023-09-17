#include "Convert.hpp"

Convert::Convert() : _char(0), _int(0), \
     _float(0.0f), _double(0.0) {}

Convert::Convert(std::string input) {
    _type = type(input);
    switch (_type) {
        case Null:
            return ;
        case Char:
        {
            _char = input.at(0);
            _int = static_cast<int>(_char);
            _float = static_cast<float>(_char);
            _double = static_cast<double>(_char);
            break;
        }
        case Int:
        {
            _int = atoi(input.c_str());
            _char = static_cast<char>(_int);
            _float = static_cast<float>(_int);
            _double = static_cast<double>(_int);
            break;
        }
        case Float:
        {
            _float = strtof(input.c_str(), NULL);
            _char = static_cast<char>(_float);
            _int = static_cast<int>(_float);
            _double = static_cast<double>(_float);
            break;
        }
        case Double:
        case Inf:
        case Nan:
        {
            _double = strtod(input.c_str(), NULL);
            _char = static_cast<char>(_double);
            _int = static_cast<int>(_double);
            _float = static_cast<float>(_double);
            break;
        }
    }
}

Convert::Convert(Convert const &obj){
    *this = obj;
}

Convert &Convert::operator = (Convert const &obj){
	this->_type = obj._type;
	this->_char = obj._char;
	this->_int = obj._int;
	this->_float = obj._float;
	this->_double = obj._double;
	return *this;
}

Convert::~Convert() {}

e_type Convert::type(std::string input) {
    if (input.length() == 1 && !std::isdigit(input[0]))
        return (Char);
    if (input == "nan" || input == "nanf")
        return (Nan);
    if (input[0] == '-' || input[0] == '+')
        input = input.substr(1);
    if (input == "inf" || input == "inff")
        return (Inf);
    
    size_t length = input.length();
    bool is_double = false;
    for (size_t i = 0; i < length; i++)
    {
        if (i == length - 1 && (input[i] == 'f' || input[i] == 'F') && is_double)
            return (Float);
        if (input[i] == '.')
        {
            if (is_double)
                return (Null);
            is_double = true;
            continue;
        }
        if (!std::isdigit(input[i]))
            return (Null);
    }
    if (is_double == true)
        return (Double);
    else
        return (Int);
}

void Convert::print(void) const {
    if (_type == Null)
    {
        std::cerr << "Error" << std::endl;
        return ;
    }
    std::cout << "char: ";
    if (std::isprint(_char))
        std::cout << '\'' << _char << '\'';
    else
        std::cout << ((_type == Nan || _type == Inf)? "impossible" : "Non displayble");
    std::cout << std::endl;
    std::cout << "int: ";
    if (_type == Nan || _type == Inf)
        std::cout << "impossible";
    else
        std::cout << _int;
    std::cout << std::endl;
    std::cout << "float: " << _float << (static_cast<float>(_int) == _float ? ".0f" : "f") << std::endl;
	std::cout << "double: " << _double << (static_cast<double>(_int) == _float ? ".0" : "") << std::endl;
}