#pragma once
#pragma once
#include <iostream>

class Error : public std::exception { // ����� ���� ����������
public:
    Error() : str("") {};
    explicit Error(const char* msg) : str(msg) {}; // ���������������� �����������
    std::string what() { return str; }; // ���������� ������ � �������
private:
    std::string str; // ������ � �������
};