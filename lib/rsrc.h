#ifndef RSRC_H__
#define RSRC_H__

#include <stdio.h>
#include <stdlib.h>
#include "testrf.h"

void fatal_error(char str[]);
void* s_malloc(size_t size);
void s_free(void *ptr);

#endif
