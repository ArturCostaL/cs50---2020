from sys import argv, exit
import csv

def main():

    if(len(argv) != 3):
        print("Wrong number of arguments")
        exit()

    data_list = []

    with open(argv[1], "r") as reader:
        database = csv.reader(reader)

        for row in database:
            data_list.append(row)

    with open(argv[2], "r") as reader:
        sequence = reader.read()

    # for each STR:
    max_STR_counted = []
    for i in data_list[0][1:]:
        count = get_max(sequence, i)
        max_STR_counted.append(count)


    # print(max_STR_counted)
    name = check_name(max_STR_counted, data_list)

    print(name)

def check_name(max_counted, data_list):
    for i in range(len(data_list)):
        count = 0
        for j in range(len(max_counted)):
            if (data_list[i][j+1]) == str(max_counted[j]):
                count += 1

        if count == len(max_counted):
            return data_list[i][0]
    return "No match"
def get_max(dna, STR):
    max_count = 0
    for i in range(len(dna)):
        a = i
        b = i + len(STR)
        if dna[a:b] == STR:
            count = 0
            while dna[a:b] == STR:
                count +=1

                if count > max_count:
                    max_count = count
                a += len(STR)
                b += len(STR)

    return max_count

main()