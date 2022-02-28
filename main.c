#include "main.h"

void addperson(person *personptr, int age, float weight){
        *personptr->age = age;
        *personptr->weight = weight;
        print("\nperson are %d", personptr->age);
}

int main(){
        int age=0;
        float weight=0.0;
        print("enter age = ");
        scanf("%d",age);
        printf("\nenter weight = ");
        scanf("%f",weight);
        ps *personnew;
        addperson(personnew, age, weight);
}
