#include <stdio.h>
#include <stdlib.h>
#define max 60
#define length 30

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
        printf("Student [%d]\n\t",(i+1));
        printf("%s\n\t", v[i].name);
        printf("%d\n\t", v[i].age);
        printf("%.3f\n\t", v[i].weight);
        printf("%.3f\n\t", v[i].height);
    }
}

void highHeight(struct student v[], int *highHeightPosition)
{
    float aux = 0;
    for(int i=0;i<length;i++)
    {
        if(v[i].height>aux)
        {
            aux = v[i].height;
            *highHeightPosition = i;
        }
    }
}

void calculateIMC(struct student v[], float imc[], float *avarege)
{
    for(int i=0;i<length;i++)
    {
        imc[i] = v[i].weight / (v[i].height*v[i].height);
        *avarege += imc[i] / length;
    }
}

void highMinIMC(float imc[], int *minIMCPosition, int *highImcPosition)
{
    float aux = 0;
    float aux1 = imc[0];
    for(int i=0;i<length;i++)
    {
        if(imc[i] > aux)
        {
            aux = imc[i];
            *highImcPosition = i;
        }
        if(imc[i] < aux1)
        {
            aux1 = imc[i];
            *minIMCPosition = i;
        }
    }
}

void highMinAge(struct student v[], int *minAgePosition, int *highAgePosition)
{
    int aux = 0;
    int aux1 = v[0].age;
    for(int i=0;i<length;i++)
    {
        if(v[i].age > aux)
        {
            aux = v[i].age;
            *highAgePosition = i;
        }
        if(v[i].age < aux1)
        {
            aux1 = v[i].age;
            *minAgePosition = i;
        }
    }
}


int main(void)
{
    float imc[length];
    float avarege = 0; 
    int highHeightPosition, minIMCPosition, highImcPosition, highAgePosition, minAgePosition;
    struct student v[length];

    get_student(v);

    printStudent(v);

    calculateIMC(v, imc , &avarege);
    highHeight(v, &highHeightPosition);
    highMinIMC(imc, &minIMCPosition, &highImcPosition);
    highMinAge(v, &minAgePosition, &highAgePosition);

    
    //HigherHeight
    printf("The student with higher height is %s\n", v[highHeightPosition].name);

    //Higher IMC and Lower IMC 
    printf("The student with higher IMC is %s ", v[highImcPosition].name);
    printf("and the student with lower IMC is %s \n", v[minIMCPosition].name);

    //Higher Age and Lower Age
    printf("The student with higher Age is %s ", v[highAgePosition].name);
    printf("and the student with lower Age is %s \n", v[minAgePosition].name);

    //avarege IMC
    printf("The avarege IMC of the student is %.2f\n", avarege);

    return 0;

}