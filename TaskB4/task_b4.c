#include <stdio.h>
#include <string.h>

int valid_group(const char *g)
{
    const char *groups[] = {
        "A+", "A-", "B+", "B-", "AB+", "AB-", "O+", "O-"
    };

    int i;
    for (i = 0; i < 8; i++) {
        if (strcmp(g, groups[i]) == 0)
            return 1;
    }
    return 0;
}

int main(void)
{
    char choice[10], name[20], group[5];

    printf("Enter option (name/group): ");
    if (scanf("%9s", choice) != 1)
        return 1;

    if (strcmp(choice, "name") == 0) {
        printf("Enter donor name: ");
        if (scanf("%19s", name) != 1)
            return 1;
        printf("Accepted donor name: %s\\n", name);
    }
    else if (strcmp(choice, "group") == 0) {
        printf("Enter blood group: ");
        if (scanf("%4s", group) != 1)
            return 1;

        if (valid_group(group))
            printf("Valid blood group: %s\\n", group);
        else
            printf("Invalid blood group.\\n");
    }
    else {
        printf("Unknown command.\\n");
    }

    return 0;
}
