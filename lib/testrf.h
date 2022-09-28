#ifndef TESTRF_H__
#define TESTRF_H__

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#define IMAGE_NUMBEROF_DIRECTORY_ENTRIES 16
#define SECTION_NAME_SIZE 8

uint16_t numOfSections;

#pragma pack(push,1)

typedef struct {
    uint8_t  Name[SECTION_NAME_SIZE];
    uint32_t VirtualSize;
    uint32_t VirtualAddress;
    uint32_t SizeOfRawData;
    uint32_t PointerToRawData;
    uint32_t PointerToRelocations;
    uint32_t PointerToLinenumbers; // descontinuado
    uint16_t NumberOfRelocations;
    uint16_t NumberOfLinenumbers;  // descontinuado
    uint32_t Characteristics;
} IMAGE_SECTION_HEADER;

typedef struct _IMAGE_DATA_DIRECTORY {
  uint32_t  virtualAddress;
  uint32_t  size;
}IMAGE_DATA_DIRECTORY;

typedef struct _IMAGE_OPTIONAL_HEADER {
  uint16_t  magic;
  uint8_t   majorLinkerVersion;
  uint8_t   minorLinkerVersion;
  uint32_t  sizeOfCode;
  uint32_t  sizeOfInitializedData;
  uint32_t  sizeOfUninitializedData;
  uint32_t  addressOfEntryPoint;
  uint32_t  baseOfCode;
  uint32_t  baseOfData;
  uint32_t  imageBase;
  uint32_t  sectionAlignment;
  uint32_t  fileAlignment;
  uint16_t  majorOperatingSystemVersion;
  uint16_t  minorOperatingSystemVersion;
  uint16_t  majorImageVersion;
  uint16_t  minorImageVersion;
  uint16_t  majorSubsystemVersion;
  uint16_t  minorSubsystemVersion;
  uint32_t  win32VersionValue;
  uint32_t  sizeOfImage;
  uint32_t  sizeOfHeaders;
  uint32_t  checkSum;
  uint16_t  subsystem;
  uint16_t  dllCharacteristics;
  uint32_t  sizeOfStackReserve;
  uint32_t  sizeOfStackCommit;
  uint32_t  sizeOfHeapReserve;
  uint32_t  sizeOfHeapCommit;
  uint32_t  loaderFlags;
  uint32_t  numberOfRvaAndSizes;
  IMAGE_DATA_DIRECTORY dataDirectory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
} IMAGE_OPTIONAL_HEADER;


typedef struct _IMAGE_DOS_HEADER
{    
    uint16_t e_magic;
    uint16_t e_cblp;
    uint16_t e_cp;
    uint16_t e_crlc;
    uint16_t e_cparhdr;
    uint16_t e_minalloc;
    uint16_t e_maxalloc;
    uint16_t e_ss;
    uint16_t e_sp;
    uint16_t e_csum;
    uint16_t e_ip;
    uint16_t e_cs;
    uint16_t e_lfarlc;
    uint16_t e_ovno;
    uint16_t e_res[4];
    uint16_t e_oemid;
    uint16_t e_oeminfo;
    uint16_t e_res2[10];
    uint32_t e_lfanew;
 } IMAGE_DOS_HEADER;

typedef struct _IMAGE_FILE_HEADER {
  uint16_t  machine;
  uint16_t  numberOfSections; 
  uint32_t  timeDateStamp;
  uint32_t  pointerToSymbolTable;
  uint32_t  numberOfSymbols; 
  uint16_t  sizeOfOptionalHeader; 
  uint16_t  characteristics;
} IMAGE_FILE_HEADER;


typedef struct _IMAGE_NT_HEADERS {
  uint32_t                signature;
  IMAGE_FILE_HEADER	   	  fileHeader; 
  IMAGE_OPTIONAL_HEADER  	optionalHeader; 
} IMAGE_NT_HEADERS, *PIMAGE_NT_HEADERS;

typedef struct PEFILE {
  char* filepath;
  IMAGE_DOS_HEADER* dos_hdr;
  IMAGE_NT_HEADERS* nt_hdr;
  IMAGE_SECTION_HEADER* sec_hdr; 
} PEFILE;

#pragma pack(pop)

bool file_init(PEFILE *file);
void file_deinit(PEFILE *file);

#endif
