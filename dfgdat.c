/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef int uint8_t;
typedef unsigned int uint16_t;
typedef long uint32_t;
typedef unsigned long uint64_t;



struct test {
    int version;
    char name[32];
    char description[32];
    uint32_t textures;
};
struct fileData {
    int type;
    uint32_t size;
    char fname[32];
    char data;
};
int main()
{
    FILE* infile;
    infile = fopen("person1.dat", "wb+");
    if (infile == NULL) {
        fprintf(stderr, "\nError opening file\n");
        exit(1);
    }
    struct test write_struct = { 1, "Rohan", "test", 1 };
    struct fileData fdat = {0, 16, "test.bin", (char)"1234567890abcdef"[16]};
    struct test read_struct;
    struct fileData testRd;
    // writing to file
    fwrite(&write_struct, sizeof(write_struct), 1,
           infile);
    fwrite(&fdat, sizeof(fdat), 1,
           infile);
    
    rewind(infile);
    
    fread(&read_struct, sizeof(read_struct), 1, infile);
    
    for(int f=0; f<read_struct.textures; f++)
    {
        fread(&testRd, sizeof(testRd), 1, infile);
        char dat[testRd.size];
        fseek( infile, SEEK_CUR, SEEK_SET );
        fread(dat, sizeof(dat), 1, infile);
        printf("File name:%s\nData: %s\n", testRd.fname, dat);
    }
    printf("Name: %s, Description: %s \nVersion: %d", read_struct.name,
           read_struct.description, read_struct.version);
  
    return 0;
}
