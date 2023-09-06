#pragma once

#include <array>
#include <iostream>
#include <map>
#include <sstream>
#include <utility>
#include <variant>
#include <vector>

namespace variantVisitors
{

    using PrintVariant = std::variant<bool, int, float>;
    struct PrintVisitor {
        void operator()(bool& ) { std::cout << "bool";}
        void operator()(int& ) { std::cout << "int";}
        void operator()(float& ) { std::cout << "float";}
    };

    using ToStringVariant = std::variant<bool, int, double, float>;
    struct ToStringVisitor {
        std::string operator()(bool y){
            if(y==true)
            return "true";
            else
            return "false";
        }

        std::string operator()(int z){
            std::stringstream stream;
            stream<<std::hex<<z;
            return stream.str();
        
        }
        std::string operator()(float s){
            std::stringstream stream;
            stream<<s;
            return stream.str();

        }

        std::string operator()(double x){
            std::stringstream stream;
            stream<<x;
            return stream.str();
    }

}; // namespace variantVisitors
}

