from cs50 import get_string
import string

text = get_string("Text: ")

n_word = 1
n_letter = 0
n_pont = 0

for letter in text:

    if letter == ' ':
        n_word += 1

    if letter.lower() in list(string.ascii_lowercase):
        n_letter += 1

    if letter in ['.', '?' ,'!']:
        n_pont += 1

L = 100 * n_letter / n_word
S = 100 * n_pont / n_word
index = round(0.0588 * L - 0.296 * S - 15.8)

if index < 1:
    print("Before Grade 1")
elif index >=16:
    print("Grade 16+")
else:
    print(f"Grade {index}")

