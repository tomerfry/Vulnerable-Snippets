#include <stdio.h>
#include <malloc.h>
#include <socket.h>


int get_input_from_socket(int sock) {
	unsigned int size;
	char *input;
	
	if (recv(sock, &size, sizeof(size), 0) < 0)
		return -1;
	
	input = malloc(size);

	for (int i = 0; i < size; i++) {
		if (recv(sock, &input[i], sizeof(char), 0) < 0) {
			free(input);
			return -1;
		}
	}	
	
	printf(input);
	free(input);
}
