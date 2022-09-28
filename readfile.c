#include <stdlib.h>
#include <stdio.h>
#include "lib/testrf.h"

int main(int argc, char *argv[]){

  if(argc != 2)
    exit(1);

  PEFILE pe;  
  pe.filepath = argv[1];


  file_init(&pe);
  //test accessing structs
  printf("%x\n", pe.dos_hdr->e_magic);
  printf("%x\n", pe.nt_hdr->signature);
  printf("%x\n", pe.nt_hdr->fileHeader.machine);
  printf("%x\n", pe.nt_hdr->optionalHeader.magic);
  printf("%x\n", pe.nt_hdr->optionalHeader.numberOfRvaAndSizes);
  printf("Size of IMAGE_NT_HDR: %zu\n", sizeof(IMAGE_NT_HEADERS));
  printf("Size of IMAGE_FILE_HDR: %zu\n", sizeof(IMAGE_FILE_HEADER));
  printf("Size of IMAGE_OPT_HDR: %zu\n", sizeof(IMAGE_OPTIONAL_HEADER));
  printf("Size of IMAGE_SEC_HDR: %zu\n", sizeof(IMAGE_SECTION_HEADER));

  printf("%x\n", pe.nt_hdr->optionalHeader.dataDirectory[1].virtualAddress);
 
  printf("First section name: %s\n", pe.sec_hdr->Name);

  file_deinit(&pe);

  return 0;
}
