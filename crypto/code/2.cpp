#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

/* Convert character to 0-25 */
int charToInt(char ch) {
    return tolower(ch) - 'a';
}

/* Generate key matching the text length */
void extendKey(const char *text, const char *key, char *extendedKey) {
    int keyLen = strlen(key);
    int keyIndex = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            extendedKey[i] = key[keyIndex % keyLen];
            keyIndex++;
        } else {
            extendedKey[i] = text[i];
        }
    }

    extendedKey[strlen(text)] = '\0';
}

/* Encryption */
void vigenereEncrypt(const char *text, const char *key, char *encrypted) {
    char extendedKey[MAX_LEN];

    extendKey(text, key, extendedKey);

    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char base = isupper(text[i]) ? 'A' : 'a';

            int plainValue = text[i] - base;
            int keyValue = charToInt(extendedKey[i]);

            encrypted[i] = base + (plainValue + keyValue) % 26;
        } else {
            encrypted[i] = text[i];
        }
    }

    encrypted[strlen(text)] = '\0';
}

/* Decryption */
void vigenereDecrypt(const char *cipherText, const char *key, char *decrypted) {
    char extendedKey[MAX_LEN];

    extendKey(cipherText, key, extendedKey);

    for (int i = 0; cipherText[i] != '\0'; i++) {
        if (isalpha(cipherText[i])) {
            char base = isupper(cipherText[i]) ? 'A' : 'a';

            int cipherValue = cipherText[i] - base;
            int keyValue = charToInt(extendedKey[i]);

            decrypted[i] = base + (cipherValue - keyValue + 26) % 26;
        } else {
            decrypted[i] = cipherText[i];
        }
    }

    decrypted[strlen(cipherText)] = '\0';
}

int main() {
    char text[MAX_LEN];
    char key[MAX_LEN];
    char encrypted[MAX_LEN];
    char decrypted[MAX_LEN];

    printf("Compiled by Aswin Phuyal\n");
    printf("=================================\n");
    printf("      Polyalphabetic Cipher\n");
    printf("=================================\n");

    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    printf("Enter the key: ");
    scanf("%99s", key);

    vigenereEncrypt(text, key, encrypted);
    printf("\nEncrypted Text : %s\n", encrypted);

    vigenereDecrypt(encrypted, key, decrypted);
    printf("Decrypted Text : %s\n", decrypted);

    return 0;
}