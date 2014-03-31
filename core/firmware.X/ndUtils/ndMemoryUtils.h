/**
 * Library that contains some utility functions.
 */

#include "../ndCore.h"

#ifndef NDUTILS_H
#define	NDUTILS_H

/**
 * Copy n bytes for the input buffer to the output buffer
 *
 * @param in Input buffer
 * @param out Ouput buffer
 * @param numberOfBytes Number of bytes to copy
 */
void copyNBytes(uint8_t* in, uint8_t* out, uint8_t numberOfBytes);

#endif	/* NDUTILS_H */

