#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <getopt.h>
#include "lib/testrf.h"
#include "lib/rsrc.h"

#define VERSION 1.0

/*
 -A                              Full output (default).
 -H                              Show all PE headers.
 -s                              Show PE section headers.
 -d                              Show data directories.
 -h                              Show specific header. It can be used multiple times.
 -i                              Show imported functions.
 -e                              Show exported functions.
 -v                              Show version.
 --help                          Show this help.
*/
static void show_help(char *name) {
  fprintf(stderr, "\
usage: %s <options>\n\
--help              show help.\n\
-A, --all           Show all PE headers.\n\
-s, --sec-headers   Show PE section headers.\n\
-d, --data-dir Show Data directories.\n\
-h, --show-header   Show specific header. Multiple use.\n\
-i, --imported      Show imported functions.\n\
-e, --exported      Show exported functions.\n\
-v, --version       Show program version.\n", name);
 
  exit(EXIT_FAILURE) ;
}


int main(int argc, char *argv[]){


  int opt;
      
  const struct option stopcoes[] = {
        {"all"            , no_argument       , 0               , 'A'},
        {"all-headers"    , no_argument       , 0               , 'H'},
        {"sec-headers"    , no_argument       , 0               , 's'},
        {"data-dir"       , no_argument       , 0               , 'd'},
        {"show-header"    , required_argument , 0               , 'h'},
        {"imported"       , no_argument       , 0               , 'i'},
        {"exported"       , no_argument       , 0               , 'e'},
        {"version"        , no_argument       , 0               , 'v'},
        {0                , 0                 , 0               , 0  },
    } ;

  if(argc < 2) show_help(argv[0]);

  PEFILE pe;  
  
  pe.filepath = argv[1];
  file_init(&pe);

  while((opt = getopt(argc, argv, "AHsdh:iev"))!=1){
    
    switch(opt){

      case 'A':
           
      case 'H':

      case 's':

      case 'd':

      case 'h':

      case 'i':

      case 'e':

      case 'v':  

    }

  } 

  file_deinit(&pe);

  return 0;
}
