#pragma once

namespace geom {
    struct Point { // структура точки
        float x, y; // координаты
        Point() : x(0), y(1) {} // конструктор по умолчанию
        Point(float x, float y) : x(x), y(y) {} // инициализирующий конструктор
    };

    class Catenary {
    public:
        // конструкторы
        explicit Catenary(Point LLim = Point(-2, 1), Point RLim = Point(2, 1)); // конструктор по умолчанию
        Catenary(float, float, float, float); // инициализирующий конструтор

        // геттеры
        [[nodiscard]] Point get_LLim() const { return LLim; };
        [[nodiscard]] Point get_RLim() const { return RLim; };
        [[nodiscard]] Point get_Vert() const { return Vert; };

        [[nodiscard]] float get_y(float, bool) const; // получение y по x
        [[nodiscard]] float get_ArcLength() const; // получение длину линии
        [[nodiscard]] float get_RadOfCurvature(float) const; // получение радиуса кривизны
        [[nodiscard]] Point get_CenterOfCurvature(float) const; // получение координат центра кривизны
        [[nodiscard]] float get_Square() const; // получение площади

        // сеттеры
        void set_LLim(Point llim) { LLim = llim; }; // установить левый предел
        void set_RLim(Point rlim) { RLim = rlim; }; // установить правый предел
        void set_Vert(Point vert) { Vert = vert; }; // установить вершину

        // прочие функции
        void PrintStatus() const; // вывод состояния класса

        // деструктор
        ~Catenary() = default; // деструктор

    private:
        Point Vert, // вершина цепи
            LLim, // левая граница
            RLim; // правая граница
    };
}