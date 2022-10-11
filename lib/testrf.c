#include <stdlib.h>
#include <stdio.h>
#include "testrf.h"
#include "rsrc.h"

extern uint16_t numOfSections; 

bool file_init(PEFILE *file){ 

  FILE *f = fopen(file->filepath, "rb");  
    if(f == NULL)  
      fatal_error("Failed opening the file.");

  //DOS HDR
  file->dos_hdr = malloc(sizeof(IMAGE_DOS_HEADER));
  if(!file->dos_hdr)
    fatal_error("Failed to allocate memory... Exiting...");

  if(fread(file->dos_hdr,sizeof(IMAGE_DOS_HEADER),1,f) != 1)
    fatal_error("Failed to read file.");

  fseek(f,file->dos_hdr->e_lfanew,SEEK_SET);

  //IMAGE NT HDR
  file->nt_hdr = malloc(sizeof(IMAGE_NT_HEADERS));
  if(!file->nt_hdr)
    fatal_error("Failed to allocate memory... Exiting...");

  if(fread(file->nt_hdr,sizeof(IMAGE_NT_HEADERS),1,f) !=1)
    fatal_error("Failed to read file");
  
  //IMAGE SEC HDR
  numOfSections = file->nt_hdr->fileHeader.numberOfSections; 

  file->sec_hdr = malloc(sizeof(IMAGE_SECTION_HEADER)*numOfSections); 
  if(!file->sec_hdr)
    fatal_error("Failed to allocate memory... Exiting...");

  if(fread(file->sec_hdr, sizeof(IMAGE_SECTION_HEADER), numOfSections,f) !=numOfSections)
    fatal_error("Failed to read file");

  fclose(f);
  
  return true;
}

void file_deinit(PEFILE *file){
  s_free(file->dos_hdr);
  s_free(file->nt_hdr);
  s_free(file->sec_hdr);
}
