#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    int testletter = 0;
    string key = (argv[1]);


    if (argc < 2 || argc > 2 || strlen(key) != 26)
    {
        printf("INVALID ARGUMENT\n");
        return 1;
    }

    //pass the key to lowercase:

    for (int i = 0; i < 26; i++)
    {
        key[i] = tolower(key[i]);

    }

    //test the key for countaining each letter exacly once:

    for (int i = 0; i < 26 ; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if ((int) key[j] == 97 + i)
            {
                testletter++;
            }
        }
        if (testletter != 1)
        {
            printf("INVALID ARGUMENT\n");
            return 1;
        }
        testletter = 0;
    }

    string text = get_string("plaintext: ");

    // Substitute the text:

    for (int j = 0, len = strlen(text); j < len ; j++)
    {
        for (int i = 0 ; i < 26 ; i++)

        {
            if (text[j] == 'a' + i)
            {
                text[j] = key[i];
                i = 26;
            }
            else if (text[j] == 'A' + i)
            {
                text[j] = key[i] - 32;
                i = 26;
            }
        }
    }

    printf("ciphertext: %s\n", text);

}
