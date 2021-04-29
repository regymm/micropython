SECTIONS
{
	. = 0x20000000;
	.text : { *(.text.boot) }
	.text : { *(.text) }
	.data : { *(.data) }

	__heap_size = DEFINED(__heap_size) ? __heap_size : 0x1000;

	.heap          :
	{
		PROVIDE(__heap_start = .);
		. = __heap_size;
		PROVIDE(__heap_end = .);
	}
}
