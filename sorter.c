#include <stdio.h>
struct Evaluation
{
    char name[50];
    int score;
};
 
void display_details(struct Evaluation e1);
int main()
{
    struct Evaluation e;
    printf("Name: ");
    scanf("%[^\n]%*c", e.name);
    printf("Score: ");
    scanf("%d", &e.score);
     
    display_details(e);   // passing structure as an argument
     
    return 0;
}
void display_details(struct Evaluation e1) 
{
  printf("\nEvaluation details.....\n");
  printf("Name: %s", e1.name);
  printf("\nScore: %d", e1.score);
}