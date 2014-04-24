#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
    printf("Enter Age,Gender(M or F),Weight[in pounds] and height [in inches]\n");
    int age;
    float weight,height;
    char gender;
    scanf("%d %c %f %f",&age,&gender,&weight,&height);
    printf(" age is %d years\n gender is %c \n weight is pounds %f \n height is %f inches \n",age,gender,weight,height);
    
    float bmi = (weight / (height * height)) * 703;
    float bmr;
    if(gender == 'M')//male
    {
        bmr = 66+(6.23 * weight)+(12.7 * height)-(6.8 * age);
    }
    if(gender == 'F')
        bmr = 655+(4.35 * weight)+(4.7 * height)-(4.7 * age);
    else
    {
        printf("invalid weight ..terminating program\n");
        exit(1);
    }
    
    printf("BMI is %f and BMR is %f",bmi,bmr);
    if(bmi<=18.5)
    {
        printf("underweight\n");
    }
    else if(bmi > 18.5 && bmi <25)   
        printf("normal weight\n");
    else if(bmi >= 25 && bmi <29)   
        printf("over weight\n");
    else if(bmi >= 29 && bmi <35)   
            printf("obesity class 1\n");
    else if(bmi >= 35 && bmi <40)   
            printf("obesity class 2\n");
    else if(bmi >=40)   
        printf("morbid obesity\n");

    int natureex;
    float calorie;
    printf("enter info about your exercise nature\n");
    printf("1 for Sedentary, 2 for Lightly Active, 3 for Moderately Active 4 for Very Active and 5 for Extra Active \n");
    scanf("%d",&natureex);
    switch(natureex)
    {
        case 1:calorie = bmr * 1.2;
                break;
        case 2:calorie = bmr * 1.375;
                break;
        case 3:calorie = bmr * 1.55;
                break;
        case 4:calorie = bmr * 1.725;
                break;
        case 5:calorie = bmr * 1.9;
                break;                
    }
    printf("the calorie need is %f",calorie);
    return (0);
}

