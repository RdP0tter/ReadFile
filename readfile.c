#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "lib/testrf.h"
#include "lib/rsrc.h"

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

 int main(int argc, char *argv[]){

  //if(argc != 2)
    //fatal_error("Number of arguments invalid.");
  int opt;

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
