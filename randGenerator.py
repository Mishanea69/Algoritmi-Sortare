import random

def create_random_numbers_file():
    x = 0
    try:
        x = int(input("How many random numbers?: "))
        s = str(x) + ".txt"
        a = x // 10000
        with open(s, "w") as afile:
            for i in range(1, x+1):
                random_number = random.randint(1, x)
                afile.write(str(random_number) + "\n")
                if i%a == 0:
                    print("%.2f" % ((i/x)*100))
        
    except ValueError:
        print("Invalid input. Please enter a valid integer.")

create_random_numbers_file()
