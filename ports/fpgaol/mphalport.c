#include <unistd.h>
#include "mmio_basic/mmio_basic.h"
#include "py/mpconfig.h"

char _uart_list[100];
char uart_list_i;
char uart_list_cnt;

// Receive single character, blocking until one is available.
int mp_hal_stdin_rx_chr(void) {
    unsigned char c = 0;
    int r = read(STDIN_FILENO, &c, 1);
    (void)r;
    return c;
	/*char c;*/
	/*if (uart_list_i == uart_list_cnt) {*/
		/*uart_list_i = 0;*/
		/*uart_list_cnt = 0;*/
		/*// read a full line*/
		/*while(1) {*/
			/*while(!*uart_rx_new);*/
			/*c = *uart_rx_data;*/
			/**uart_rx_reset = 1;*/
			/*_uart_list[uart_list_cnt++] = c;*/
			/*if (c == '\r' | c == '\n') {*/
				/*_uart_list[uart_list_cnt-1] = '\r';*/
				/*break;*/
			/*}*/
		/*}*/
	/*}*/
	/*return _uart_list[uart_list_i++];*/
	

	/*short int i;*/
	/*char list[50];*/
	/*while(1) {*/
		/*if (*uart_rx_new) c = *uart_rx_data;*/
	/*}*/
    /*unsigned char c = 0;*/
    /*int r = read(STDIN_FILENO, &c, 1);*/
    /*(void)r;*/
    /*return c;*/
}

// Send the string of given length.
void mp_hal_stdout_tx_strn(const char *str, mp_uint_t len) {
    int r = write(STDOUT_FILENO, str, len);
    (void)r;
}
