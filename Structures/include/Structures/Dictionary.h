#pragma once

#include <array>
#include <iostream>
#include <map>
#include <utility>
#include <variant>
#include <vector>

namespace dictionary
{
    using CustomVariant = std::variant<int, float, std::string>;
    using DictionaryContainer = std::map<const std::string, CustomVariant>; 

    

    class Dictionary{

        public:
         
        DictionaryContainer items_;
        static int counter_;

        friend Dictionary operator+(const Dictionary& dictionary1, const Dictionary& dictionary2);
        friend Dictionary& operator+=(Dictionary& dictionary1, const Dictionary& dictionary2);

        Dictionary() : items_{} {
            ++counter_;
            std::cout << "default constructor" << std::endl;
        }
    
        Dictionary(const Dictionary& other) : items_{other.items_} {
            ++counter_;
            std::cout << "copy constructor" << std::endl;
        }


        Dictionary(Dictionary&& other) noexcept : items_{std::move(other.items_)}  {
            ++counter_;
            std::cout << "move constructor" << std::endl;
        }

        Dictionary& operator=(const Dictionary& other) {
            items_ = other.items_;
            std::cout << "copy assignment" << std::endl;
            return *this;
        }
 
        Dictionary& operator=(Dictionary&& other) noexcept {
            items_= std::move(other.items_);
            std::cout << "move assignment" << std::endl;
            return *this;
        }

        Dictionary(std::initializer_list<std::pair<const std::string, CustomVariant>> ini_list) : items_{ini_list} {
            ++counter_;
            std::cout << "initializer list constructor" << std::endl;
        }

        ~Dictionary() {
            --counter_;
            std::cout << "destructor" << std::endl;
        }

        static int getObjCounter()
        {
            return counter_;
        }

        const CustomVariant& operator[](const std::string& key) const {
            auto it = items_.find(key);
            if (it != items_.end()) {
                return it->second;
            } else {
                throw std::out_of_range("The Key is out of range of the Dictionary");
            }
        }

            CustomVariant& operator[](const std::string& key) {
            return items_[key];
        }

        void pop(const std::string& key) {
            items_.erase(key);
        }

        const std::vector<CustomVariant> values() const {
            std::vector<CustomVariant> vi; //value
            for (const auto& pair : items_) {
                vi.push_back(pair.second);
            }
            return vi;
        }

        const std::vector<std::string> keys() const {
            std::vector<std::string> h; //key
            for (const auto& pair : items_) {
                h.push_back(pair.first);
            }
            return h;
        }
        
    };
    int Dictionary::counter_ = 0;


    
    Dictionary operator+(const Dictionary& dictionary1, const Dictionary& dictionary2) {
            Dictionary result_dict(dictionary1);
            for (const auto& pair : dictionary2.items_) {
                result_dict.items_[pair.first] = pair.second;
            }
            return result_dict;
        }
    Dictionary& operator+=(Dictionary& dictionary1, const Dictionary& dictionary2) {
            for (const auto& pair : dictionary2.items_) {
                dictionary1.items_[pair.first] = pair.second;
            }
            return dictionary1;
        }

} // namespace dictionary
