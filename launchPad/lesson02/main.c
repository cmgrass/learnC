
int main()
{
    int counter = 0;
    int oddStrikes = 0;
    while (counter < 21) {
        ++counter;
        
        /* Do something special if counter value is odd */
        if ((counter & 1) != 0) {
            ++oddStrikes;    
        }
    }
    
    return 0;
}
