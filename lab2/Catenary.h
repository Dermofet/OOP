#pragma once

namespace geom {
    struct Point { // ��������� �����
        float x, y; // ����������
        Point() : x(0), y(1) {} // ����������� �� ���������
        Point(float x, float y) : x(x), y(y) {} // ���������������� �����������
    };

    class Catenary {
    public:
        // ������������
        explicit Catenary(Point LLim = Point(-2, 1), Point RLim = Point(2, 1)); // ����������� �� ���������
        Catenary(float, float, float, float); // ���������������� ����������

        // �������
        [[nodiscard]] Point get_LLim() const { return LLim; };
        [[nodiscard]] Point get_RLim() const { return RLim; };
        [[nodiscard]] Point get_Vert() const { return Vert; };

        [[nodiscard]] float get_y(float, bool) const; // ��������� y �� x
        [[nodiscard]] float get_ArcLength() const; // ��������� ����� �����
        [[nodiscard]] float get_RadOfCurvature(float) const; // ��������� ������� ��������
        [[nodiscard]] Point get_CenterOfCurvature(float) const; // ��������� ��������� ������ ��������
        [[nodiscard]] float get_Square() const; // ��������� �������

        // �������
        void set_LLim(Point llim) { LLim = llim; }; // ���������� ����� ������
        void set_RLim(Point rlim) { RLim = rlim; }; // ���������� ������ ������
        void set_Vert(Point vert) { Vert = vert; }; // ���������� �������

        // ������ �������
        void PrintStatus() const; // ����� ��������� ������

        // ����������
        ~Catenary() = default; // ����������

    private:
        Point Vert, // ������� ����
            LLim, // ����� �������
            RLim; // ������ �������
    };
}