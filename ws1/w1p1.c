#include <stdio.h>

int main(){

    char First_Name[20], Last_Name[20];
    int ID;

    printf("Adinizi soyadinizi giriniz.\n");
    scanf("%s %s",First_Name, Last_Name);
    printf("Ogrenci ID'nizi giriniz.\n");
    scanf("%d",&ID);

printf("Workshop 1 Part-1\n");
printf("=================\n\n");
printf("I'm displaying this using the 'printf' stdio\n");
printf("(standard input output) library function!\n\n");
printf("Dear teacher,\n\n"); 
printf(" I promise I will work hard from this day onward.\n");
printf(" I acknowledge that practice is extremely important,\n"); 
printf(" so I will do all workshops, quizzes, and assignments.\n\n"); 
printf("Sincerely,\n");

printf("%s %s\n",First_Name, Last_Name);
printf("%d\n",ID);
    
    getchar();

return 0;

}
