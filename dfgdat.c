#include <stdio.h>

struct fileHeader {
    int fileVersion;
    int fileCount;
    char description[64];
};

typedef struct fileHeader FileHeader;

int main()
{
    printf("Saving file.\n");
    FILE* out;
    out=fopen("data.bin", "wb+");
    
    FileHeader fhead = {1, 1, "testing"};
    FileHeader frd; // Read File
    
    fwrite(&fhead, sizeof(fhead), 1, out);
    printf("Done saving file.\n\nReading...\n");
    fseek(out, ftell(out)-16, SEEK_SET);
    printf("Cursor:%d\n", ftell(out));

    rewind(out);
    
    fread(&frd, sizeof(frd), 1, out);
    
    printf("Version:%d\n", frd.fileVersion);
    printf("Description:%s\n", frd.description);
    
    fclose(out);
    return 0;
}
