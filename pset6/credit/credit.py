from cs50 import get_string

card = get_string("Number: ")
i = 0
sum1 = 0
sum2 = 0

for c in card[::-1]:

    if i % 2 == 0:
        sum1 += int(c)
    else:
        if int(c) * 2 < 10:
            sum2 += int(c) * 2;
        else:
            sum2+= (int(c) * 2) % 10;
            sum2+= (int(c) * 2) // 10;
    i += 1

if (sum1 + sum2) % 10 == 0:
    valid = True
else:
    valid = False

if valid:
    if card[0] == '4' and (len(card) == 16 or 13):
        print("VISA\n")
    elif card[0] == '5' and (card[1] == '1' or '2' or '3' or '4'or '5') and len(card) == 16:
        print("MASTERCARD\n")
    elif card[0] == '3' and (card[1] == '4' or '7') and len(card) == 15:
        print("AMEX\n")
    else:
        print("INVALID\n")
elif valid == False:
    print("INVALID\n")

