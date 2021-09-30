#pragma once
#include <iostream>
#include "Catenary.h"

using namespace geom;

namespace dlg {
    int dialog(const std::string msgs[], int N); // ���������� ����� �������� �������������
    int D_CreateCatenary(Catenary& C); // ���������� ������� �������� ������ ������ �����
    int D_PrintStatus(Catenary& C); // ���������� ������� ������ �������
    int D_GetY(Catenary& C); // ���������� ������� ��������� y
    int D_GetArcLength(Catenary& C); // ���������� ������� ��������� ����� ����
    int D_GetRadOfCurvature(Catenary& C); // ���������� ������� ��������� ������� ��������
    int D_GetCenterOfCurvature(Catenary& C); // ���������� ������� ��������� ������ ��������
    int D_GetArea(Catenary& C); // ���������� ������� ��������� �������

    template<class T>
    T getNum(T& n); // ���� �����
    template<class T>
    void CorrectInput(T& input); // ������� ����������� �����
}