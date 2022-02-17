
import math as m

# All the functions are below 
def compute_pi(n):
    pi = 0
    c = 4
    d = 1
    for i in range(1, n):
        a = 2 * (i % 2) - 1
        pi += a * (c / d)
        d += 2
    return pi


def compute_sqrt(x):
    
    last = 1.0
    next = 1.0
    count = 0

    while count < 10:

        next = 0.5 * (last + x / last)
        last = next
        count += 1

    sqrt = next

    return sqrt


def is_prime(x):

    tf = False

    if x > 1:
        for i in range(2, int(m.sqrt(x)) + 1):
            if (x % i) == 0:
                tf = False
                break
            else:
                tf = True

    return tf


def display_primes(x):

    primes = []

    for i in range(1,x):
        if is_prime(i) == True:
            primes.append(i)

    return primes


def process_scores():

    max = 0
    min = 100
    avg = 0
    con = True
    maxStudent = ""
    minStudent = ""
    numStudents = 0
    score = 0

    while con:

        student = input("Enter a student's name: ")
        numStudents += 1

        score = int(input("Enter a student's score: "))

        avg = avg + score

        if score > max:
            max = score
            maxStudent = student
        
        if min > score:
            min = score
            minStudent = student

        choice = input("Enter q to exit or y to continue: ")

        if choice.lower() == "q":
            con = False
            break
        elif choice.lower() == "y":
            continue
    
    avg = avg / numStudents

    return ("The average score is: %f\n" 
    "The high score is: %f\n"
    "The low score is: %f\n"
    "The student with the high score is: %s\n"
    "The student with the low score is: %s\n"
    %(avg, max, min, maxStudent, minStudent))


def compute_tax(income, status, state):

    tax = 0

    if status.lower() == "married" and state.lower() == "i":
        if (income < 50000):
            tax += income * 0.1
        elif (income >= 50000):
            tax += income * 0.15

    if status.lower() == "single" and state.lower() == "i":
        if (income < 30000):
            tax += income * 0.2

        elif (income >= 30000):
            tax += income * 0.25

    if status.lower() == "married" and state.lower() == "o":
        if (income < 50000):
            tax += income * 0.07

        elif (income >= 50000):
            tax += income * 0.12

    if status.lower() == "single" and state.lower() == "o":
        if (income < 30000):
            tax += income * 0.17

        elif (income >= 30000):
            tax += income * 0.22

    return tax


def solve_quadratic(a, b, c):

    disc = b*b - 4*a*c

    if disc < 0:
        solution1 = 0
        solution2 = 0
        return("Solution 1: %f\n"
        "Solution 2: %f" %(solution1, solution2))
        
    elif disc >= 0:
        solution1 = (-b + m.sqrt(disc))/2*a  
        solution2 = (-b - m.sqrt(disc))/2*a
        return("Solution 1: %f\n"
        "Solution 2: %f" %(solution1, solution2))


def sort(list): 

    sortedList = list

    for i in range(len(sortedList)):

        min = i
        for j in range(i+1, len(sortedList)):
            if sortedList[min] > sortedList[j]:
                min = j
       
        sortedList[i], sortedList[min] = sortedList[min], sortedList[i]

    return sortedList

# cuts the letters from the specified indexes and puts them together to form the password and ID 
def id_password(first, last):
    
    id = first[0] + last

    password = first[0] + first[-1] + last[0:3] + str(len(first)) + str(len(last))

    return ("User id: %s\n"
    "Password: %s" %(id.upper(), password.upper()))


def file_sort(infile = "inPut.txt", outfile = "outPut.txt"):

    infile = open(infile, 'r')
    outfile = open(outfile, 'w')

    numStudents = int(infile.readline())
    students = []

    for i in range(numStudents):
        students.append(infile.readline().split())
        students[i][0] = int(students[i][0])
        students[i][2] = float(students[i][2])

    for i in range(numStudents):
        for j in range(numStudents - 1):
            if students[j][0] > students[j + 1][0]:
                students[j], students[j + 1] = students[j + 1], students[j]

    for student in students:
        outfile.write("%s %s %s\n" %(str(student[0]), student[1], str(student[2])))

    infile.close()
    outfile.close()

    return "File sorted successfully "

# main() function that takes a user input and runs the specified function
def main():

    while True:
        print("1-compute_pi 2-compute_sqrt 3-primes_functions 4-process_scores() 5-compute_tax() 6-solve_quadratic() 7-sort() 8-id_password() 9-file_sort() ")
        choice = input("Enter the number of the function you would like to use or q to exit: ")

        if choice == "1":
            number = int(input("Enter a number: "))
            print(compute_pi(number))

        elif choice == "2":
            num = float(input("Enter a number: "))
            sqrt = compute_sqrt(num)
            print("The sqrt of %.3f is: %.3f" %(num, sqrt))

        elif choice == "3":
            number = int(input("Enter the number you would like to check: "))

            if is_prime(number) == False:
                print("%d is not prime " %number)
            else:
                print("%d is prime " %number)

            c = ("The prime numbers between 0 and %d are "  %number)
            primes = ' '.join(map(str, display_primes(number)))
            c += primes

            print(c)

        elif choice == "4":
            print(process_scores())

        elif choice == "5":
            income = int(input("Enter your yearly income: "))
            status = input("Enter if you are single or married: ")
            state = input("Enter I if you are in-state or O if you are out of state: ")

            print(compute_tax(income, status, state))

        elif choice == "6":
            a = int(input("Enter a value for a: "))
            b = int(input("Enter a value for b: "))
            c = int(input("Enter a value for c: "))

            print(solve_quadratic(a, b, c))

        elif choice == "7":
            inputLst = []

            n = int(input("Enter the number of elements in the list: "))

            for i in range(0, n):
                ele = int(input())
            
                inputLst.append(ele)

            print(sort(inputLst))

        elif choice == "8":
            first = input("Enter your first name: ")

            last = input("Enter your last name: ")

            print(id_password(first, last))

        elif choice == "9":
            inputf = input("Enter the name of the input file or leave it blank to use the default one: ")
            outputf = input("Enter the name of the output file or leave it blank to use the default one: ")

            print(file_sort(inputf, outputf))

        elif choice == "q":
            break
    
        cont = input("Enter q to exit or y to continue: ")

        if cont == "q":
            break
        else:
            continue

    return "Thank you for running the program "
    
print(main())
