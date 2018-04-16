/* gcc -Wall ./memory.c -o memory */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* System used: Ubunut 16.04 64bit */

 /* store page size here */
 int page_size = 4096;

int calculate_page (int address) {
	return address / page_size;
}

int calculate_offset (int address , int page) {
	return address - (page * page_size);
}

int main(int argc, char *argv[])
{
	long long_input;
	int address;
	int offset , page;

	if (argc != 2) {
		printf("You must provide a parameter as input!\n");
		return -1;
	} else {
		long_input = atol(argv[1]);
		long supremum = pow(2 , 8*sizeof(int));
		if (long_input < 0 || long_input >= supremum) {
			printf("You must enter a valid 32bit address as parameter!\n");
			return -1;
		} else {
			address = (int) long_input;
		}
	}

	page = calculate_page(address);
	offset = calculate_offset(address, page);
	printf("The address %d contains:\npage number = %d\noffset = %d\n", address, page, offset);

	return 0;
}
