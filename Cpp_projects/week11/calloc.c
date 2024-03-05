#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	char *mem_alloc;
	// memory allocated dynamically
	mem_alloc = calloc(15, sizeof(char));
	
	if(mem_alloc == NULL){
		printf("Couldn't allocate requested memory\n");
	}else{
		strcpy(mem_alloc, "Pan-Atlantic");
	}
	
	printf("Dynamically allocated memory : %s\n", mem_alloc);
	free(mem_alloc);
}