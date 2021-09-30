#include <iostream>
#include <cmath>
#include "Catenary.h"
#include "MyErrors.h"

using namespace std;
using namespace geom;

// ������������
Catenary::Catenary(Point LLim, Point RLim)
{
    Catenary::set_LLim(LLim);
    set_RLim(RLim);
    set_Vert(Point());
}

Catenary::Catenary(float x1, float x2, float Vx, float Vy)
{
    if (Vy <= 0 || x1 > x2 || Vx < x1 || Vx > x2)
        throw Error("\nError input [Constructor]: error coordinates\n");
    set_Vert(Point(Vx, Vy));
    set_LLim(Point(x1, get_y(x1, false)));
    set_RLim(Point(x2, get_y(x2, false)));
}

// ��������
float Catenary::get_y(float x, bool flag) const
{
    if (flag && (x < LLim.x || x > RLim.x))
        throw Error("\nError input [get_y]: error coordinates\n");
    return (Vert.y * coshf((x + Vert.x) / Vert.y));
}
float Catenary::get_ArcLength() const
{
    float arc1 = Vert.y * sinh((LLim.x + Vert.x) / Vert.y);
    float arc2 = Vert.y * sinh((RLim.x + Vert.x) / Vert.y);
    return (arc2 - arc1);
}
float Catenary::get_RadOfCurvature(float x) const
{
    if (x < LLim.x || x > RLim.x)
        throw Error("\nError input [get_RadOfCurvature]: error coordinates\n");
    return Vert.y * powf(coshf((x + Vert.x) / Vert.y), 2.0);
}
Point Catenary::get_CenterOfCurvature(float x) const
{
    if (x < LLim.x || x > RLim.x) throw Error("\nError input [get_CenterOfCurvature]: error coordinates\n");
    float R = get_RadOfCurvature(x);
    float y = get_y(x, true);
    Point p = Point(R * (-sinhf(x + Vert.x / Vert.y)) + x, R + y);
    return p;
}
float Catenary::get_Square() const
{
    return (powf(Vert.y, 2.0) * (sinhf(RLim.x / Vert.y) - sinhf(LLim.x / Vert.y)));
}

// ������ �������
void Catenary::PrintStatus() const
{
    cout << "Left limit = Point(" << this->LLim.x << ", " << this->LLim.y << ")" << endl;
    cout << "Right limit = Point(" << this->RLim.x << ", " << this->RLim.y << ")" << endl;
    cout << "Vertex = Point(" << this->Vert.x << ", " << this->Vert.y << ")" << endl;
}