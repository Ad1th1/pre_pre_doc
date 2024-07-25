#include<stdio.h>
#include<stdlib.h>
#include <x86intrin.h>


#define FLUSH(addr) = _mm_clflush(addr)

#define RDTSC_START(cycles)                 \                 
    do{                                     \
        uint32_t cyc_high, cyc_low;         \
        asm volatile ("CPUID\n\t"           \
                      "RDTSC\n\t"           \
                      "mov %%edx, %0\n\t"   \
                      "mov %%eax, %1\n\t"   \
                      : "=r" (cyc_high),  "=r" (cyc_low)    \
                      :: "%rax", "%rbx", "%rcx", "%rdx");   \
        (cycles) = ((uint64_t)cyc_high << 32) | cyc_low;    \
    }while(0);

#define RDTSC_STOP(cycles)                  \                 
    do{                                     \
        uint32_t cyc_high, cyc_low;         \
        asm volatile ("RDTSCP\n\t"          \
                      "mov %%edx, %0\n\t"   \
                      "mov %%eax, %1\n\t"   \
                      "CPUID\n\t"           \
                      : "=r" (cyc_high),  "=r" (cyc_low)    \
                      :: "%rax", "%rbx", "%rcx", "%rdx");   \
        (cycles) = ((uint64_t)cyc_high << 32) | cyc_low;    \
    }while(0);

uint64_t measure_access_time(void *addr){
    uint64_t start, end;
    RDTSC_START(start);
    asm volatile("mov (%0), %%eax\n" : : "c" (addr) : "eax");
    RDTSC_STOP(end);
    return end - start;
}

void flush_reload(void *addr){
    uint64_t access_time;

    FLUSH(addr);

    usleep(100);

    access_time = measure_access_time(addr);
    printf("Access time: %lu cycles\n", access_time);

}


int main() {
    char shared_data[64] = "Secret data to be accessed.";

    flush_reload(shared_data);

    return 0;
}
