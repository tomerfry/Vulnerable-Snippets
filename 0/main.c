#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <sys/socket.h>


int get_url_from_socket(int sock) {
	unsigned int size;
	char *input;
	char c;
	
	if (recv(sock, &size, sizeof(size), 0) < 0)
		return -1;
	
	input = malloc(size);

	for (int i = 0; i < size; i++) {
		if (recv(sock, &c, sizeof(char), 0) < 0) {
			free(input);
			return -1;
		}
		char temp =  isalnum(c) || c == '.' || c == '?' || c == '_' || c == '-' || c == '#' || c == ';' ? c : (c == ' ' ? '+' : 0);
		if (!temp) {
			char *encoded = malloc(4);
			sprintf(encoded, "%%%02X", c);
			strcat(input, encoded);
		}
		else {
			strcat(input, &temp);
		}
	}	
	
	printf(input);
	free(input);
}
