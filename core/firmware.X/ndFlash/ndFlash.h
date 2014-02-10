/**
 * ndFlash is a library that allow you to write some instruction
 * on the PIC flash at runtime.
 *
 * ndFlash is used by the eventbus to write the event dispatcher.
 */

#ifndef NDFLASH_H
#define	NDFLASH_H

void initFlash();

void seekFlash();

void skipFlash();

void writeFlash();

void flushFlash();

#endif	/* NDFLASH_H */

