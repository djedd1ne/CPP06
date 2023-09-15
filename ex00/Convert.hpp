#ifndef CONVERT_HPP
#define CNVERT_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <cctype>

enum e_type {Null, Char, Int, Float, Double, Nan, Inf};

class Convert {
    private:
        char _char;
        int _int;
        float _float;
        double _double;
        e_type _type;
        e_type type(std::string input);
        std::string ctos(char a);

    public:
        Convert();
        Convert(std::string input);
        Convert(Convert const &obj);
        Convert &operator = (Convert const &obj);
        ~Convert();
        void print(void) const;
};

#endif