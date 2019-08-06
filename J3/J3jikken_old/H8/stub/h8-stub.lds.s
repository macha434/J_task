OUTPUT_FORMAT("coff-h8300")
OUTPUT_ARCH("h8300h")

/*
  Memory Map
  0x000000 - 0x07ffff (0x80000 bytes) : Internal Flash-ROM (512kB)
    0x000000 - 0x0000ff (0x00100 bytes) : Vector Area        (256Byte)
    0x000100 - 0x07ffff (0x7ff00 bytes) : Internal ROM Area  (512KB)
  0x200000 - 0x21ffff (0x20000 bytes) : External RAM Area  (128kB)
  0xffdf10 - 0xffff0f (0x02000 bytes) : Internal RAM Area  (8kB)
    ROM Emulation : 
    0xffe000 - 0xffefff (0x01000 bytes) <=> 0x000000 - 0x000fff (4kB)
*/

MEMORY
{
        vect   : ORIGIN = 0xffe000, LENGTH = 0x100
        intram : ORIGIN = 0xffe200, LENGTH = 0x1710
        stack  : ORIGIN = 0xfff910, LENGTH = 0x600
        extram : ORIGIN = 0x21f700, LENGTH = 0x900
}

SECTIONS
{
.vectors :
  {
    *(.vectors)
  } > vect
  . = ALIGN(4);

.text :
  {
    __text = .; 
    entry.o(.text)
    *(.text)
    *(.rodata)
  } > intram
  . = ALIGN(4);
  
.data :
  {
    __data_start = .; 
    *(.data)
  } > extram
  . = ALIGN(2);	
  __data_end = __data_start + SIZEOF(.data);
    
  __bss_start = .;
.bss :
  {
    *(.bss)
    *(COMMON)
  } > extram
  . = ALIGN(2);
  
  __bss_end = .;
.stack   :
  {
    *(.stack)
  } > stack
}
