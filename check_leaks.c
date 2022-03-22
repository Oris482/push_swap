#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    while (1)
    {
        system("leaks push_swap");
        sleep(1);
    }
}