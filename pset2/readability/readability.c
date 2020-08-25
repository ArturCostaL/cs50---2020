#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    /*
    printf("%i letter(s)", count_letters(text));
    printf("%i word(s)", count_words(text));
    printf("%i sentence(s)", count_sentences(text));
    */

    float L = (float) 100 * (float) count_letters(text) / count_words(text);
    float S = (float) 100 * (float) count_sentences(text) / count_words(text);

    float grade = 0.0588 * L - 0.296 * S - 15.8;

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade < 16)
    {
        printf("Grade %.0f\n", round(grade));
    }
    else
    {
        printf("Grade 16+\n");
    }

}



int count_letters(string text)
{
    int count = 0;
    for (int i = 0, size = strlen(text); i < size; i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            count++;
        }
    }
    return count;
}


int count_words(string text)
{
    int count = 1;
    for (int i = 0, size = strlen(text); i < size; i++)
    {
        if (text[i] == ' ')
        {
            count++;
        }
    }
    return count;
}

int count_sentences(string text)
{
    int count = 0;
    for (int i = 0, size = strlen(text); i < size; i++)
    {
        if (text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            count++;
        }
    }
    return count;
}
