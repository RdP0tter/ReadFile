#ifndef RSRC_H__
#define RSRC_H__

#include <stdio.h>
#include <stdlib.h>
#include "testrf.h"

struct OPTIONS{
  bool all;
  bool allhdr;
  bool dos;
  bool coff;
  bool opt;
  bool nt; 
  bool sec;
  bool datadir;
  bool imprt;
  bool exptr;
};

void fatal_error(const char *str);
void* s_malloc(size_t size);
void s_free(void *ptr);

#endif
