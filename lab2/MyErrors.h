#pragma once
#include <iostream>

using namespace std;

class Error : public exception { // ����� ���� ����������
public:
    Error() = default; // ������ �����������
    explicit Error(const char* msg) : str(msg) {}; // ���������������� �����������
    string what() { return str; }; // ���������� ������ � �������
    ~Error() override = default; // ����������
private:
    string str; // ������ � �������
};