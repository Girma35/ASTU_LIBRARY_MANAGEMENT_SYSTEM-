import random

letters = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']
numbers = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
symbols = ['!', '#', '$', '%', '&', '(', ')', '*', '+']

nr_letters = int(input("Please enter the number of letters you want to add: "))
nr_symbols = int(input("Please enter the number of symbols you want to add: "))
nr_numbers = int(input("Please enter the number of numbers you want to add: "))

password = ""

for i in range(nr_letters):
    password += random.choice(letters)

for i in range(nr_numbers):
    password += random.choice(numbers)

for i in range(nr_symbols):
    password += random.choice(symbols)

print(password)
