#include<stdio.h>
main(){
  int i;
  char fname[20];
  char lname[20];
  char religion[15];
  char occupation[30];
  float lpa;
  char ragat[3];
  char contactno[11];
  int age;
  float height;
  char gender;
  FILE *ptz;

  ptz = fopen("data.txt", "a");
  printf("No. Of Users: ");
  scanf("%d", &i);
  for (i; i>0; i--){
    printf("fname: ");
    scanf("%s", fname);
    printf("lname of %s : ",fname);
    scanf("%s", lname);
    printf("Gender(M/F): ");
    scanf(" %c", &gender);
    printf("Religion of %s : ",fname);
    scanf("%s", religion);
    printf("Occupation of %s : ", fname);
    scanf("%s", occupation);
    printf("Blood group: ");
    scanf("%s", ragat);
    printf("Annual Income in LPA format: ");
    scanf("%f", &lpa);
    printf("Contact Number: ");
    scanf(" %s", contactno);
    printf("Your age: ");
    scanf("%d", &age);
    printf("Your Height in ft: ");
    scanf("%f", &height);
    printf("\n");
    if (age>=18){
      fprintf(ptz, "%s %s %c %s %s %s %f %s %d %f\n",fname, lname, gender, religion, occupation, ragat, lpa, contactno, age, height);
    }
  }
  fclose(ptz);
}