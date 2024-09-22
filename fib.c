#include <stdio.h>
#include <stdint.h>

//write in C fibonnaci recursively and write it iteratively 
//then accept the command line argument read the file then calculate the value to the Nth fibbnoaci

uint64_t fibo_iterative(uint64_t f) {
   if (f <= 1){
    return f;
   } 
   uint64_t a = 0;
   uint64_t b = 1;
   for (int i = 2; i <= f; i++){
      uint64_t origin = a;
      a = b;
      b = origin + b;
   }
    return b;
}

uint64_t fibo_recursive(uint64_t f){
    if (f <= 1){
        return f;
    }
    return fibo_recursive(f-1) + fibo_recursive(f-2);
}


int main(int argc, char *cmd[]) {
    if (argc != 4) {
        return 1;
    }

    uint64_t input_number = atoi(cmd[1]), file_number;
    FILE *file = fopen(cmd[3], "r");
    fscanf(file, "%llu", &file_number);

    uint64_t N = input_number + file_number;
    uint64_t result = 0;
    char fib = cmd[2][0];
    if (fib == 'r'){
        result = fibo_recursive(N);
    }
    if (fib == 'i'){
        result = fibo_iterative(N);
    }
    fscanf("%llu\n", result);

    return 0;
}
