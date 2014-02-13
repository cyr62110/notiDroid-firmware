#include "ndInternalMemory.h"

uint8_t isInternalMemoryOpened = 0;

uint8_t openInternalMemory() {
	if(isInternalMemoryOpened)
		return 0;
	isInternalMemoryOpened = 1;
	return -1;
}

void closeInternalMemory() {
	isInternalMemoryOpened = 0;
}