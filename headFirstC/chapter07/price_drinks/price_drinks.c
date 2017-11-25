#include <stdio.h>
#include <stdarg.h>

enum drink {
    MUDSLIDE, FUZZY_NAVEL, MONKEY_GLAND, ZOMBIE
};

double price(enum drink d)
{
    switch (d) {
    case MUDSLIDE:
        return 6.82;
    case FUZZY_NAVEL:
        return 8.50;
    case MONKEY_GLAND:
        return 35.99;
    case ZOMBIE:
        return 24.21;
    default:
        return 0;
    }
}

double total(int num_drinks, ...)
{
    va_list arg_list;
    va_start(arg_list, num_drinks);

    int i;
    double current_price = 0;

    for (i = 0; i < num_drinks; i++) {
       current_price += price(va_arg(arg_list, enum drink));
    }
    
    va_end(arg_list);
    
    return current_price;
}

int main()
{
    double total_cost;

    total_cost = total(5, MUDSLIDE, FUZZY_NAVEL, MONKEY_GLAND, ZOMBIE, MUDSLIDE);
    printf("%f\n", total_cost);

    return 0;
}
