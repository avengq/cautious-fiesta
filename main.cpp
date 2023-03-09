#include "PasswordGenerator.h"
#include "UI.h"

int main()
{
    PasswordGenerator pg;
    UI UI(pg);
    UI.Run();
    return 0;
}