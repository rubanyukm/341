
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

double compute_pi(int n) {

    long int i;
    double sum=0.0, term, pi;
 

    for (i = 0; i < n; i++) {
        term = pow(-1, i) / (2*i+1);
        sum += term;
    }

    pi = 4 * sum;
 
    return pi;

}

double compute_sqrt(double x) {

    int a = x;
    double sqrt;

      while (1) {
 
        sqrt = 0.5 * (a + (x / a));
 
        if (abs(sqrt - a) < 1)
            break;
 
         a = sqrt;
    }
    
    return sqrt;
}

int is_prime(int n) {

    int i;
    int tf = 1;

    if (n <= 1) {
        tf = 0;
    }

    for (i = 2; i <= sqrt(n); i++) {
        
        if (n % i == 0) {
            tf = 0;
            break;
        }
    }
    
    return tf;
}

void display_primes(int n) { 

    int i;

    for(i = 0; i < n; i++) {

        if(is_prime(i) == 1) {
            printf("%d ", i);
        }
    }
    
}

void process_scores(){

    double avg = 0, minScore = 100, maxScore = 0;
    char student[25];
    char maxStudent[25];
    char minStudent[25];
    char choice[10];
    int score, numStudents = 0;

    do {

        printf("Enter a students name: \n");
        scanf("%s", student);

        numStudents++;

        printf("Enter a students score: \n");
        scanf("%d", &score);

        avg = avg + score;

        if (score > maxScore) {
            maxScore = score;
            strcpy(maxStudent, student);
        }

        if (minScore > score) {
            minScore = score;
            strcpy(minStudent, student);
        }

        printf("Enter q to exit or y to continue: \n");
        scanf("%s", choice);

        if (strcmp(choice, "q") == 0) {
            break;
        }

    } while(strcmp(choice, "q") != 0);

    printf("Average score: %.2f\n", avg/numStudents);
    printf("Highest score: %f\n", maxScore);
    printf("Student with highest score: %s\n", maxStudent);
    printf("Lowest score: %f\n", minScore);
    printf("Student with lowest score: %s\n", minStudent);
    
}

double compute_tax(int income, char *marriageStatus, char state) {

    double tax = -1;
    char married[] = "married";
    char Married[] = "Married";
    char single[] = "single";
    char Single[] = "Single";

    puts(marriageStatus);
    if (state == 'i'|| state == 'I'){
        if (strcmp(marriageStatus, single) == 0 || strcmp(marriageStatus, Single) == 0){
            if (income < 40000) {
                tax = income * 0.3;
            }
            else if (income >= 40000) {
                tax = income * 0.35;
            }
        }

    if (strcmp(marriageStatus, married) == 0 || strcmp(marriageStatus, Married) == 0){
        if (income < 60000) {
                tax = income * 0.2;
            }
        else if (income >= 60000) {
                tax = income * 0.25;
            }
        }
    }

    if (state == 'o' || state == 'O'){
        if (strcmp(marriageStatus, single) == 0 || strcmp(marriageStatus, Single) == 0){
            if (income < 40000) {
                tax = income * 0.27;
            }
        else if (income >= 40000) {
                tax = income * 0.32;
            }
        }

    if (strcmp(marriageStatus, married) == 0 || strcmp(marriageStatus, Married) == 0){
        if (income < 60000) {
                tax = income * 0.17;
            }
        else if (income >= 60000) {
                tax = income * 0.22;
            }
        }
    }

    return tax;
}

int quadratic(double a, double b, double c, double *solution1, double *solution2) {

    float disc = b*b - 4*a*c;
    int tf;

    if (disc <= 0) {

        *solution1 = -1;
        *solution2 = -1;
        tf = 0;
    }
    else if (disc > 0) {

        *solution1 = (-b + sqrt(disc))/2*a;  
        *solution2 = (-b - sqrt(disc))/2*a;
        tf = 1;
    }

    printf("Solution1: %f\n", *solution1);
    printf("Solution2: %f\n", *solution2);

    return tf;
}

int  sum_squares(int  n){

    if (n<=1) {
        return pow(n,2); 
    }
    else {
        return pow(n,2)+sum_squares(n-1);
    }

}

void file_count(char *file, int *characters, int  *blanks,  int  *lines){

    char ch;

    *lines = 1;

    FILE *fp; 
    fp = fopen(file, "r");

    if(fp != NULL) {

        while ((ch = fgetc(fp)) != EOF) {

            (*characters)++;

            if (ch == '\n') {
                (*lines)++;
            }
            else if (ch == ' ') {
                (*blanks)++;
            } 
        }
        fclose(fp);
    }
}

void file_sort(char *infile, char *outfile) {

    FILE *inputFile = fopen(infile, "r");
    FILE *outputFile = fopen(outfile, "w");

    char *grade, tempGrade;
    double *gpa, tempGpa;
    int *id, n, i, j, minIdx, tempId;
  
    if (inputFile == NULL){
        printf("Input file does not exist %s\n", infile);
        exit(1);
    }

    if (outputFile == NULL) {
        printf("Output file does not exist %s\n", outfile);
        exit(1);
    }
  
    fscanf(inputFile, "%d", &n);
    id = (int*) malloc(sizeof(int) * n);
    grade = (char *) malloc(sizeof(char) * n);
    gpa = (double *) malloc(sizeof(double) * n);
  
  
    for (i = 0; i < n; i++) {
        fscanf(inputFile, "%d %c %lf", &id[i], &grade[i] , &gpa[i]);
    }
    fclose(inputFile);
  
    for (i = 0; i < n; i++) {
        minIdx = i;
        for (j = i + 1; j < n; j++) {
            if(id[j] < id[minIdx])
                minIdx = j;
            }
        
            if (i != minIdx)
            {
                tempId = id[i];
                id[i] = id[minIdx];
                id[minIdx] = tempId;
                
                tempGrade = grade[i];
                grade[i] = grade[minIdx];
                grade[minIdx] = tempGrade;
                
                tempGpa = gpa[i];
                gpa[i] = gpa[minIdx];
                gpa[minIdx] = tempGpa;
            }
    }

    fprintf(outputFile,"%d\n",n);
    for(i = 0; i < n; i++)
    fprintf(outputFile, "%5d %5c %7.2lf\n", id[i], grade[i], gpa[i]);
    
    fclose(outputFile);
    
    free(id);
    free(gpa);
    free(grade);
  
}

int main() {

    int funcNum;
    char choice[10];

    do {
        
        printf("1-computing pi, 2-computing square root, 3-displaying primes, 4-processing grades, 5-computing tax, 6-solving quadratic, 7-computing sum squares, 8-counting file, 9-sorting file, 10-student file, 11-quit");
        printf("\nEnter the number of the function you would like to use: ");
        scanf("%d", &funcNum);
           
        if (funcNum == 1) {
            int computation;
            printf("Enter an integer: ");
            scanf("%d", &computation); 
            printf("The desired value of pi is: %.6lf", compute_pi(computation));
        }

        else if (funcNum == 2) { 
            double square;
            printf("Enter a number: ");
            scanf("%lf", &square);
            printf("Square Root of %.2f: %f", square,  compute_sqrt(square));
        }

        else if (funcNum == 3) { 
            int number;
            printf("Enter an integer: ");
            scanf("%d", &number); 

            if (is_prime(number) == 1) {
                printf("The result is: true %d is a prime number", number);
            }
            else {
                printf("The result is: false %d is not a prime number", number);
            }

            printf("\nThe prime numbers between 0 and %d are: ", number);
            display_primes(number);
        }

        else if (funcNum == 4) {
            process_scores();
        }        

        else if (funcNum == 5) { 
            int income;
            char state;
            char marriageStatus[25];

            printf("\nEnter inside or outside state (i/o): ");
            scanf("%c",&state);
            printf("\nEnter marital Status (single/married): ");
            gets(marriageStatus);
            printf("\nEnter income: ");
            scanf("%d",&income); 

            double result = compute_tax(income, marriageStatus, state);
            
            printf("\ncomputed tax is : %f", result);
        }

        else if (funcNum == 6) {
            double solution1;
            double solution2;
            double a, b, c;

            printf("\nEnter the value for a: ");
            scanf("%lf", &a);
            printf("\nEnter the value for b: ");
            scanf("%lf", &b);
            printf("\nEnter the value for c: ");
            scanf("%lf", &c);

            if (quadratic(a, b, c, &solution1, &solution2) == 1) {
                printf("true\n");
            }
            else {
                printf("false\n");
            }
        }

        else if (funcNum == 7) {
            int input, squaresSum;
            printf("Enter the number of squares to sum: ");
            scanf("%d",&input);
            squaresSum = sum_squares(input);
            printf("The sum is: %d",squaresSum);

        }

        else if (funcNum == 8) {
            char *fileName = malloc(50+1);
            int charCount = 0, lineCount = 0, blankCount = 0;

            printf("Enter the filename with extension: ");
            scanf("%s", fileName);

            file_count(fileName, &charCount, &blankCount, &lineCount);
            printf("Number of characters: %d\nblanks: %d\nlines: %d\n", charCount, blankCount, lineCount);
        }

        else if (funcNum == 9) {
            char *inFile = malloc(50+1);
            char *outFile = malloc(50+1);

            printf("Enter the input filename with extension: ");
            scanf("%s", inFile);

            printf("Enter the output filename with extension: ");
            scanf("%s", outFile);

            file_sort(inFile, outFile);
        }

        else if (funcNum == 11) {
            break;
        }
        

        printf("\nWould you like to choose again(y/n)?: ");
        scanf("%s", choice);

        if (strcmp(choice, "n") == 0) {
            break;
        }

    } while(strcmp(choice, "n") != 0);

    return 0;
}