#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 100

/* Encryption Function */
void railFenceEncrypt(const char *text, int rails, char *encrypted)
{
    int len = strlen(text);

    char fence[rails][MAX_LEN];
    memset(fence, 0, sizeof(fence));

    int row = 0;
    int direction = 1;

    /* Fill zigzag pattern */
    for (int i = 0; i < len; i++)
    {
        fence[row][i] = text[i];

        row += direction;

        if (row == 0 || row == rails - 1)
        {
            direction *= -1;
        }
    }

    /* Read row by row */
    int index = 0;

    for (int r = 0; r < rails; r++)
    {
        for (int c = 0; c < len; c++)
        {
            if (fence[r][c] != 0)
            {
                encrypted[index++] = fence[r][c];
            }
        }
    }

    encrypted[index] = '\0';
}

/* Decryption Function */
void railFenceDecrypt(const char *encrypted,
                      int rails,
                      char *decrypted)
{
    int len = strlen(encrypted);

    char fence[rails][MAX_LEN];
    memset(fence, 0, sizeof(fence));

    int row = 0;
    int direction = 1;

    /* Mark zigzag positions */
    for (int i = 0; i < len; i++)
    {
        fence[row][i] = '*';

        row += direction;

        if (row == 0 || row == rails - 1)
        {
            direction *= -1;
        }
    }

    /* Fill marked positions */
    int index = 0;

    for (int r = 0; r < rails; r++)
    {
        for (int c = 0; c < len; c++)
        {
            if (fence[r][c] == '*' && index < len)
            {
                fence[r][c] = encrypted[index++];
            }
        }
    }

    /* Read zigzag pattern */
    row = 0;
    direction = 1;

    for (int i = 0; i < len; i++)
    {
        decrypted[i] = fence[row][i];

        row += direction;

        if (row == 0 || row == rails - 1)
        {
            direction *= -1;
        }
    }

    decrypted[len] = '\0';
}

/* Main Function */
int main()
{
    char text[MAX_LEN];
    char encrypted[MAX_LEN];
    char decrypted[MAX_LEN];

    int rails;

    printf("Compiled by Aswin Phuyal\n");
    printf("============================\n");
    printf("      Rail Fence Cipher\n");
    printf("============================\n");

    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);

    text[strcspn(text, "\n")] = '\0';

    printf("Enter number of rails: ");
    scanf("%d", &rails);

    if (rails < 2)
    {
        printf("\nInvalid number of rails!\n");
        printf("Rails must be at least 2.\n");
        return 1;
    }

    railFenceEncrypt(text, rails, encrypted);
    railFenceDecrypt(encrypted, rails, decrypted);

    printf("\nOriginal Text  : %s\n", text);
    printf("Encrypted Text : %s\n", encrypted);
    printf("Decrypted Text : %s\n", decrypted);

    return 0;
}