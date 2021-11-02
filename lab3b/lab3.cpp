#include "BigBin.h"
#include "dlg.h"

int main()
{
    BigBin a;
    int rc;
    int (*fptr[])(BigBin&) = { nullptr, // массив указателей на диалоговые функции
                               dlg::D_AdditionTwoNum,
                               dlg::D_DisplayStatus,
                               dlg::D_AddCode,
                               dlg::D_Input,
                               dlg::D_PlusOneBefore,
                               dlg::D_PlusOneAfter,
                               dlg::D_MinusOneBefore,
                               dlg::D_MinusOneAfter,
                               dlg::D_GetSign };

    const char* msgs[] = { "0. Exit", // menu
                           "1. Add 2 numbers",
                           "2. Display status",
                           "3. Get additional code",
                           "4. Input BigBin number",
                           "5. Increasing the number by one before using the number",
                           "6. Increasing the number by one after using the number",
                           "7. Decreasing the number by one before using the number",
                           "8. Decreasing the number by one after using the number",
                           "9. Get sign" };

    const int NMsgs = sizeof(msgs) / sizeof(msgs[0]); // размер массива меню

    while ((rc = dlg::dialog(msgs, NMsgs))) { // цикл закончится, когда пользователь введет 0 (Выход)
        if (!fptr[rc](a))
            break;
    }

    return 0;
}