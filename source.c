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

void calculateIMC(struct student v[], float imc[], float *avarege)
{
    for(int i=0;i<length;i++)
    {
        imc[i] = v[i].weight / (v[i].height*v[i].height);
        *avarege += imc[i] / length;
    }
}

float highMinIMC(float imc[], float *minIMC)
{
    float highIMC = 0;
    *minIMC = imc[0];
    for(int i=0;i<length;i++)
    {
        if(imc[i] > highIMC)
        {
            highIMC = imc[i];
        }
        if(imc[i] < *minIMC)
        {
            *minIMC = imc[i];
        }
    }
    return highIMC;
}

int highMinAge(struct student v[], int *minAge)
{
    int highAge = 0;
    *minAge = v[0].age;
    for(int i=0;i<length;i++)
    {
        if(v[i].age > highAge)
        {
            highAge = v[i].age;
            
        }
        if(v[i].age < *minAge)
        {
            *minAge = v[i].age;
        }
    }
    return highAge;
}


int main(void)
{
    float imc[length];
    float avarege = 0, minIMC; 
    int minAge; 
    struct student v[length];
    get_student(v);
    printStudent(v);
    calculateIMC(v, imc , &avarege);
    for(int i=0;i<length;i++)
    {
        printf("%.3f\n", imc[i]);
    }
    printf("High IMC = %.3f \n" , highMinIMC(imc, &minIMC));
    printf("Lower IMC= %.3f\n", minIMC);
    printf("High Age = %d\n" , highMinAge(v, &minAge));
    printf("Lower Age = %d\n", minAge);
    printf("Avarege of IMC = %.3f\n" , avarege);
    return 0;

}