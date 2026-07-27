ENTRY(main)
OUTPUT_FORMAT(binary)
SECTIONS
{
    . = 0x1000;
    .text : ALIGN(4) { *(.text) }
    .data : ALIGN(4) { *(.data) }
    .bss  : ALIGN(4) { *(.bss) }
}
