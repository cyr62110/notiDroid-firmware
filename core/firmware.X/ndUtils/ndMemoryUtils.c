#include "ndMemoryUtils.h"

void copyNBytes(uint8_t* in, uint8_t* out, uint8_t numberOfBytes) {
    while(numberOfBytes-- != 0) {
        out[numberOfBytes] = in[numberOfBytes];
    }
}
