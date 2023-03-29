/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct test {
    int version;
    char name[32];
    char description[32];
    uint16_t textures;
    uint32_t textureSizeFixed;
    char
};

int main()
{
    FILE* infile;
    infile = fopen("person1.dat", "wb+");
    if (infile == NULL) {
        fprintf(stderr, "\nError opening file\n");
        exit(1);
    }
    struct test write_struct = { 1, "Rohan", "test" };
    struct test read_struct;
    // writing to file
    fwrite(&write_struct, sizeof(write_struct), 1,
           infile);
           
    rewind(infile);
    
    fread(&read_struct, sizeof(read_struct), 1, infile);
  
    printf("Name: %s, Description: %s \nVersion: %d", read_struct.name,
           read_struct.description, read_struct.version);
  
    return 0;
}
