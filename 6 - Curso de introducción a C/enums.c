#include <stdio.h>

enum weekDays {Monday, Tuesday, Wednesady, Thursday, Friday, Saturday, Sunday};

int main()
{
    enum weekDays today;
    today = Friday;
    printf("Day %d", today+1);
    return 0;
}