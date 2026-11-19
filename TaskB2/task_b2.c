#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static int valid_group(const char *g)
{
    const char *groups[] = {"A+", "A-", "B+", "B-", "AB+", "AB-", "O+", "O-"};
    size_t i;
    for (i = 0; i < sizeof groups / sizeof groups[0]; ++i)
        if (strcmp(g, groups[i]) == 0) return 1;
    return 0;
}

int main(int argc, char *argv[])
{
    char name[20];
    FILE *fp;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s name <donor-name> | group <blood-group> | file <filename>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "name") == 0) {
        if (argc != 3) {
            fprintf(stderr, "Usage: %s name <donor-name>\n", argv[0]);
            return 1;
        }
        if (strlen(argv[2]) >= sizeof name) {
            fprintf(stderr, "Name is too long (maximum 19 characters).\n");
            return 1;
        }
        snprintf(name, sizeof name, "%s", argv[2]);
        printf("Accepted donor name: %s\n", name);
    } else if (strcmp(argv[1], "group") == 0) {
        if (argc != 3 || !valid_group(argv[2])) {
            fprintf(stderr, "Invalid blood group. Use A+, A-, B+, B-, AB+, AB-, O+ or O-.\n");
            return 1;
        }
        printf("Valid blood group: %s\n", argv[2]);
    } else if (strcmp(argv[1], "file") == 0) {
        if (argc != 3) {
            fprintf(stderr, "Usage: %s file <filename>\n", argv[0]);
            return 1;
        }
        fp = fopen(argv[2], "r");
        if (fp == NULL) {
            perror(argv[2]);
            return 1;
        }
        printf("File opened successfully: %s\n", argv[2]);
        fclose(fp);
    } else {
        fprintf(stderr, "Unknown command.\n");
        return 1;
    }

    return 0;
}
