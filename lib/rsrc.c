#include "rsrc.h"

void fatal_error(const char *str){
  fprintf(stderr, "Fatal Error: \t%s\n", str);
  exit(EXIT_FAILURE);
}

void* s_malloc(size_t size){

    void* ptr = NULL;
   
    ptr = malloc(sizeof(size));
    
    return ptr;
}

void s_free(void *ptr){
  if(ptr)
    free(ptr);
}
