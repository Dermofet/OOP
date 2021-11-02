#pragma once
#pragma once
#include <iostream>

class Error : public std::exception { // класс моих исключений
public:
    Error() : str("") {};
    explicit Error(const char* msg) : str(msg) {}; // инициализирующий конструктор
    std::string what() { return str; }; // возвращает строку с ошибкой
private:
    std::string str; // строка с ошибкой
};