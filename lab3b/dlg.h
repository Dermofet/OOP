#pragma once
namespace dlg {
    int dialog(const char* msgs[], int N);

    template<class T>
    T getNum(T& n);
    template<class T>
    void CorrectInput(T& input);

    int D_AdditionTwoNum(BigBin&);
    int D_DisplayStatus(BigBin&);
    int D_AddCode(BigBin&);
    int D_Input(BigBin&);
    int D_PlusOneBefore(BigBin&);
    int D_PlusOneAfter(BigBin&);
    int D_MinusOneBefore(BigBin&);
    int D_MinusOneAfter(BigBin&);
    int D_GetSign(BigBin&);
}
