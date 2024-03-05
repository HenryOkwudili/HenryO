#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	char *mem_alloc;
	// memory allocated dynamically
	mem_alloc = malloc(20*sizeof(char));
	
	if(mem_alloc == NULL){
		printf("Couldn't allocate requested memory\n");
	}else{
		strcpy(mem_alloc, "Pan-Atlantic");
	}
	
	printf("Dynamically allocated memory : %s\n", mem_alloc);
	mem_alloc=realloc(mem_alloc,100*sizeof(char));
	
	if(mem_alloc == NULL){
		printf("Couldn't allocate requested memory\n");
	}else{
		strcpy(mem_alloc, " memory space is extended upto 100 characaters");
	}
	
	printf("Resized memory : %s\n", mem_alloc);
	free(mem_alloc);
}