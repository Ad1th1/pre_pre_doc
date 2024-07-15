#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char some_data[] = "some data";
char secret_data[] = "TOPSECRET";

void print_data(char *data, int len){
    for (int i=0; i<len; i++){
        printf("%c", data[i]);
    }
    printf("\n");
}

int main(int argc, char **argv){
    if(argc != 2) {
        printf("Usage: %s <num_chars>\n", argv[0]);
        return 1;
    }

    int len = atoi(argv[1]);

    printf("some_data address: %p\n", (void *)some_data);
    printf("secret_data address: %p\n", (void *)secret_data);
    printf("Reading %d characters from some data...\n", len);
    print_data(some_data, len);
}
