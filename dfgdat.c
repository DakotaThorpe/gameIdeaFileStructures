#include <stdio.h>

struct fileHeader {
    int fileVersion;
    int fileCount;
    char description[64];
};
struct fileInfo {
    int64_t size;
    char name[64];
};

typedef struct fileHeader FileHeader;
typedef struct fileInfo FileInfo;

int main()
{
    printf("Saving file.\n");
    FILE* out;
    out=fopen("data.bin", "wb+");
    
    FileHeader fhead = {1, 1, "testing"};
    FileHeader frd; // Read File
    FileInfo testFile = {16, "test.bin"};
    char data[16];
    sprintf(data, "Testing data");
    
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
