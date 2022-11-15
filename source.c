#include <stdio.h>
#include <stdlib.h>
#define max 60
#define length 3

struct student
{
    char name[max];
    int age;
    float weight;
    float height;
};

void get_student(struct student v[])
{
    for(int i=0;i<length;i++)
    {
        printf("Student[%d]\n",(i+1));
        printf("Name: \n");
        scanf("%s", v[i].name);
        printf("Age:\n");
        scanf("%d", &v[i].age);
        printf("Weight:\n");
        scanf("%f", &v[i].weight);
        printf("Height:\n");
        scanf("%f", &v[i].height);

    }
}
void printStudent(struct student v[])
{
    for(int i=0;i<length;i++)
    {
        printf("%s\n", v[i].name);
        printf("%d\n", v[i].age);
        printf("%.3f\n", v[i].weight);
        printf("%.3f\n", v[i].height);
    }
}
float highHeight(struct student v[])
{
    float high = 0;
    for(int i=0;i<length;i++)
    {
        if(v[i].height>high)
        {
            high = v[i].height;
        }
    }
    return high;
}


int main(void)
{
    struct student v[length];
    get_student(v);
    printStudent(v);
    return 0;

}