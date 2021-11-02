#include <iostream>
#include "BigBin.h"
#include "dlg.h"

int dlg::dialog(const char* msgs[], int N)
{
    const char* errmsg = "";
    int rc;
    int i;
    do {
        std::cout << errmsg << std::endl;
        errmsg = "Error input! Try again\n";
        for (i = 0; i < N; ++i)
            std::cout << msgs[i] << std::endl;
        std::cout << "Make your choice --> ";
        dlg::CorrectInput(rc);
        std::cout << std::endl;
    } while (rc < 0 || rc >= N);
    return rc;
}

template<class T>
T dlg::getNum(T& n)
{
    std::cin >> n;
    if (!std::cin.good()) return 1;
    return 0;
}
template<class T>
void dlg::CorrectInput(T& input)
{
    int n;
    do {
        try {
            n = dlg::getNum(input);
        }
        catch (std::bad_alloc& err) {
            std::cerr << err.what() << std::endl;
            std::cin.clear();
            std::cin.ignore();
            n = 1;
        }
    } while (n == 1);
}

int dlg::D_AdditionTwoNum(BigBin& a)
{
    long _b = 0;
    std::cout << "Input second number --> ";
    std::cin >> _b;
    BigBin b(_b);

    a = a + b;

    return 1;
}
int dlg::D_DisplayStatus(BigBin& a)
{
    a.showInfo();
    return 1;
}
int dlg::D_AddCode(BigBin& a)
{
    char* _a = a.toAddCode();
    std::cout << _a[0] << ".";
    for (int i = 1; i < MAX_SIZE; i++) {
        std::cout << _a[i];
    }
    std::cout << std::endl;
    return 1;
}
int dlg::D_Input(BigBin& a)
{
    std::cin >> a;
    return 1;
}
int dlg::D_PlusOneBefore(BigBin& a)
{
    ++a;
    return 1;
}
int dlg::D_PlusOneAfter(BigBin& a)
{
    a++;
    return 1;
}
int dlg::D_MinusOneBefore(BigBin& a)
{
    --a;
    return 1;
}
int dlg::D_MinusOneAfter(BigBin& a)
{
    a--;
    return 1;
}
int dlg::D_GetSign(BigBin& a)
{
    if (a.get_bin()[0] == '0') std::cout << "+" << std::endl;
    else std::cout << "-" << std::endl;
    return 1;
}