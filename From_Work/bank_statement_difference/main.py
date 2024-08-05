# This is a sample Python script.

# Press ⌃R to execute it or replace it with your code.
# Press Double ⇧ to search everywhere for classes, files, tool windows, actions, and settings.

import os

# assuming that the data files are named type0_i.txt and type1_j.txt

files = os.listdir() # get all file names
type0 = []
type0_numbers_to_count = {}
type1 = []
type1_numbers_to_count = {}
for file in files:
    if file[4] == '0':
        type0.append(str(file))
    else:
        type1.append(str(file))

# for each files of type 0
# read in the lines until you find a ")"
# get the two numbers after that
for filename in type0:
    input_file = open(filename, 'r')
    for line in input_file.readlines():
        words = line.strip().split()
        interesting_idx = -1
        for word, i in enumerate(words):
            if ')' in word: # it's an interesting line
                interesting_idx = i
                break
            else:
                break

        if interesting_idx != -1:
            if float(words[i]) not in type1_numbers_to_count.keys():
                type1_numbers_to_count[float(words[i])] = 0
            type1_numbers_to_count[float(words[i])] += 1

# for each files of type 1
# read in the lines until you find a line with the ----------
# go to the next line. get the first number on there.

# get files of type 0 whose data does not
digits = "1234567890"

this_line_interesting = False
for filename in type1:
    input_file = open(filename, 'r')
    lines = input_file.readlines()
    for line, i in enumerate(lines):
        words = line.strip().split()
        if this_line_interesting:
            # get the first word in this line and add or increment in the map
            if float(words[0]) not in type0_numbers_to_count.keys():
                type0_numbers_to_count[float(words[0])] = 0
            type0_numbers_to_count[float(words[0])] += 1
            if lines[i+1].strip().split()[0][0] in digits:
                this_line_interesting = True
            else:
                this_line_interesting = False
            continue

        if len(words[0]) > 15 and words[0][:2] == "--":
            this_line_interesting = True
            continue


type0_items = type0_numbers_to_count.items()
type1_items = type1_numbers_to_count.items()

in0_notin1 = [item if item not in type1_items else None for item in type0_items]
in1_notin0 = [item if item not in type0_items else None for item in type1_items]

differ_in_quantity = set()
print("Items in documents of type 0 but not in documents of type 1:")
print("Name\tQty.")
for item in in0_notin1:
    if item is None:
        continue
    if item[0] in type1_numbers_to_count.keys():
        # then the count of them will be different.
        differ_in_quantity.add(item[0]) # item[0] is a key in both sets, print out something like the following after this for loop:
    else:
        print(item[0], "\t", type0_numbers_to_count[item[0]])

print("Items in documents of type 1 but not in documents of type 0:")
print("Name\tQty.")
for item in in1_notin0:
    if item is None:
        continue
    if item[0] in type0_numbers_to_count.keys():
        # then the count of them will be different.
        differ_in_quantity.add(item[0]) # item[0] is a key in both sets, print out something like the following after this for loop:
    else:
        print(item[0], "\t", type1_numbers_to_count[item[0]])

print("Items that occur in both documents, but differ in quantity:")
print("Name\tQty0\tQty1")
for item in differ_in_quantity:
    print(item, "\t", type0_numbers_to_count[item], "\t", type1_numbers_to_count[item])