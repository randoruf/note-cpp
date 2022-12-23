#include <stdint.h>
#include <stdio.h>
// A normal function with an int parameter
// and void return type

// void (*func_ptr)(void) = NULL;
int64_t func_ptr = (int64_t) NULL; 

void func(void)
{
    printf("[ func ]: Hello World !\n");
}
  
void set_func_ptr(void *fp){
    func_ptr = (int64_t)fp; 
}


int main()
{
    set_func_ptr(func); 
    // printf("invoke func by C\n"); 
    // (*func_ptr)();
    printf("invoke func by asm: \n\n"); 
    __asm__ __volatile__(
        "leaq _func_ptr(%rip), %r11\n"
        "movq (%r11), %r11\n"
        "call *%r11" 
    ); 

    return 0; 
}

