// Caches.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <intrin.h>
#include <Windows.h> // used for sleep functions
#include <math.h> // used for pow (exponent) function
#include "Caches2.h"

using namespace std;

// return current processor clock timestamp
uint64_t rdtsc() {
    return __rdtsc();
}

// disable interrupts
/*
void disable() {
    return _disable();
}
*/

// caches test method 1 (timestamp to bucketize L1, L2, L3 hits/misses)
void caches1(void) {
    uint64_t minCycles = INT32_MAX;
    uint64_t maxCycles = 0;

    while (1) {
        uint64_t start = rdtsc();
        //__nop();
        uint64_t end = rdtsc();
        float freq = (end - start) * (1.0f / 50) * (1000.0f);
        freq = freq / pow(10, 9);
        cout << "cycles: " << end - start << ", freq: " << freq << " Ghz" << endl;

        uint64_t cycles = end - start;
        if (cycles < minCycles) {
            minCycles = cycles;
        }
        if (cycles > maxCycles) {
            maxCycles = cycles;
        }
        cout << "minCycles: " << minCycles << ", maxCycles: " << maxCycles << endl;

        Sleep(250); // slow the execution down
    }

    __asm {
        // anything to write inline assembly
    }

    while (1) {
        __nop();
    }

}

int main()
{
    //caches1();
    caches2();
    return 0;
}
