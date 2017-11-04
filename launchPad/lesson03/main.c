int counter = 0;

int main()
{
    int *p_int;
    p_int = &counter;
    while (*p_int < 21) {
        ++(*p_int);     
    }
 
    /* 
    Set our own address manually with type casting.
    Use it to mess up RAM.
    */
    p_int = (int *)0x20000002;
    *p_int = 0xDEADBEEF;
    
    return 0;
}
