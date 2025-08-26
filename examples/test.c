#include <stdio.h>
#include "../src/CCCtypes.h"

int main()
{
    char *str = "hello";
    char *str2 = "... ";

    char *new_str = CCCstr_insert(str, 4, str2);

    printf_s("%s\n%s\n%s\n", str, str2, new_str);

    free(new_str);

    char *str3 = "moj";
    new_str = CCCstr_replace(str, 2, 4, str3);
    printf_s("%s\n%s\n%s\n", str, str3, new_str);

    free(new_str);


    return 0;
}