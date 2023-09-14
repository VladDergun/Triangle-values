#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

float Perimeter(float a,float b, float c);
float Square(float a, float b, float c, float p);
float Height(float a, float b, float c, float p);
float Median(float a, float b, float c);
float Bisector(float a, float b, float c, float p);

int main()
{
    float a, b, c;

    char a_n[38]; //These arrays are needed to temporarily store user input. 38 corresponds to the maximum size of float
    char b_n[38];
    char c_n[38];

    bool check = false; //Çì³ííà ïåðåâ³ðêè

    while(check == false){
        printf("Please, enter the first side a: ");
        fgets(a_n, 38, stdin); //reads a string and writes it to an array.
        fflush(stdin); // buffer clearing, which is used to ensure that even if the number of characters exceeds 38, they will not automatically go to the next input
        a = atof(a_n); //Converting to float. Reads the array only until it encounters something that cannot be converted
        printf("Please, enter the second side b: ");
        fgets(b_n, 38, stdin);
        b = atof(b_n);
        fflush(stdin);
        printf("Please, enter the third side c:");
        fgets(c_n, 38, stdin);
        c = atof(c_n);
        fflush(stdin);
        if(a < 0 || b<0 || c<0){
            printf("One of the values is equal 0 or negative. Please, enter only positive numbers!\n Press any button to try again\n");


            getch();

        }
        else if((a+b) <= c || (a+c) <= b || (c+b) <= a){
            printf("The equation of triangle is not satisfied. \nBeware, that a triangle can only be created when following conditions are met: \n");
            printf("a+b > c, a+c > b, b+c > a\n Press any button to try again\n");
            getch();

        }
        else{
            check = true;
        }

    }




    float p = (a+b+c)/2;

    printf("\nPerimeter of a triangle: %f\n", Perimeter(a,b,c));
    printf("Square of a triangle: %f\n\n", Square(a,b,c,p));
    printf("Height of a triangle to side a: %f\n", Height(a,b,c,p));
    printf("Height of a triangle to side b: %f\n", Height(b,a,c,p));
    printf("Height of a triangle to side c: %f\n\n", Height(c,b,a,p));
    printf("Median of a triangle to side a: %f\n", Median(a,b,c));
    printf("Median of a triangle to side b: %f\n", Median(b,a,c));
    printf("Median of a triangle to side c: %f\n\n", Median(c,b,a));
    printf("Bisector of a triangle to side a: %f\n", Bisector(a,b,c,p));
    printf("Bisector of a triangle to side b: %f\n", Bisector(b,a,c,p));
    printf("Bisector of a triangle to side c: %f\n", Bisector(c,b,a,p));

    getch();

    return 0;
}


float Perimeter(float a, float b, float c){
    float result = a +b+c;
    return result;
}
float Square(float a, float b, float c, float p){
    float result = sqrt(p*(p-a)*(p-b)*(p-c));

    return result;
}
float Height(float a, float b, float c, float p){
    float result = 2*sqrt(p*(p-a)*(p-b)*(p-c))/a;
    return result;

}
float Median(float a, float b, float c){
    float result = sqrt(2*b*b + 2*c*c - a*a)/2;
    return result;
}
float Bisector(float a, float b, float c, float p){
    float result = (2/(b+c))*sqrt(b*c*p*(p-a));
    return result;


}

