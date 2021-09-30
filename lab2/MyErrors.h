#pragma once
#include <iostream>

using namespace std;

class Error : public exception { // класс моих исключений
public:
    Error() = default; // пустой конструктор
    explicit Error(const char* msg) : str(msg) {}; // инициализирующий конструктор
    string what() { return str; }; // возвращает строку с ошибкой
    ~Error() override = default; // деструктор
private:
    string str; // строка с ошибкой
};