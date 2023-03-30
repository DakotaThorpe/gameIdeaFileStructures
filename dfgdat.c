#include <stdio.h>

struct fileHeader {
    int fileVersion;
    int fileCount;
    char description[64];
};

int main()
{
    printf("Saving file.\n");
    FILE* out;
    out=fopen("data.bin", "wb+");
    
    struct fileHeader fhead = {1, 1, "test"};
    struct fileHeader frd; // Read File
    
    fwrite(&fhead, sizeof(fhead), 1, out);
    printf("Done saving file.\n");
    rewind(out);
    
    fread(&frd, sizeof(frd), 1, out);
    
    printf("Desc:%s\n", frd.description);
    
    fclose(out);
    return 0;
}
