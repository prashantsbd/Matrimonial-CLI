#include <stdio.h>
#include <string.h>

void ads(char v);

struct record {
  char fname[20];
  char lname[20];
  char gender[10];
  char religion[20];
  char occupation[20];
  char bloodgroup[10];
  float earning;
  long long contact;
  int age;
  float height;
};

int main() {
  char ur_fname[20];
  char ur_lname[20];
  char ur_gender[10];
  char ur_religion[20];
  char ur_occupation[20];
  char ur_bloodgroup[10];
  float ur_earning;
  long long ur_contact;
  int ur_age;
  float ur_height;
  int age_gap;


  printf("fname: ");
  scanf("%s", ur_fname);
  printf("lname of %s : ",ur_fname);
  scanf("%s", ur_lname);
  printf("Gender(M/F): ");
  scanf(" %s", &ur_gender);
  printf("Religion of %s : ",ur_fname);
  scanf("%s", ur_religion);
  printf("Occupation of %s : ", ur_fname);
  scanf("%s", ur_occupation);
  printf("Blood group: ");
  scanf("%s", ur_bloodgroup);
  printf("Annual Income in LPA format: ");
  scanf("%f", &ur_earning);
  printf("Contact Number: ");
  scanf(" %11d", &ur_contact);
  printf("Your age: ");
  scanf("%d", &ur_age);
  printf("Your Height in ft: ");
  scanf("%f", &ur_height);
  printf("What's your expected age gap: ");
  scanf("%d", &age_gap);


  FILE *fp;
  // struct ma rakhda data buffer hunu paunxa so that every time we don't heed to interact with file
  struct record records[55];
  int i = 0, n;
  // requesting access to navigate over other file at any mode while running this file too
  fp = fopen("data.txt", "r");
  if (fp == NULL) {
    printf("there is bug in file opening master\n");
    return false;
  }

  // jaba samma scanner le uta file ma pauxa taba samma data eta records ma faldai agi janxa
  n = 0;
  while (fscanf(fp, "%s %s %s %s %s %s %f %lld %d %f",
                records[n].fname, records[n].lname, records[n].gender,
                records[n].religion, records[n].occupation, records[n].bloodgroup,
                &(records[n].earning), &(records[n].contact), &(records[n].age),
                &(records[n].height)) != EOF) {
                    // EOF: End Of File to titerate loop until ending of line 
                    // Alternative: while loop ma fgets rakhera jati line xa tetinjel chalni banauna ne sakinxa
    n++;
  }
// closing is necessary once opened file
  fclose(fp);
  float holder = 0;
  int c = 0;
  int g;

    if (strcmp(ur_gender,"M") == 0){
        for (c;c<n;c++){
          float max_earning = ur_earning;
          if(records[c].earning <= max_earning && records[c].earning > holder && records[c].gender[0] == 'F' &&
            strncmp(strlwr(ur_lname), strlwr(records[c].lname), 4) != 0 &&
            records[c].bloodgroup[strlen(records[c].bloodgroup)-1] == ur_bloodgroup[strlen(ur_bloodgroup)-1] &&
            records[c].age <= (ur_age - age_gap) && records[c].height < ur_height &&
            strcmp(strlwr(records[c].religion),strlwr(ur_religion)) == 0){
            holder = records[c].earning;
            g = c;
            }
        }
        printf("\nHere is what we found\nFull Name: %s %s\nGender: %s\nAge: %d\nHer Annual income is: %.2f LPA\nHer Height is: %.2fft\nEmployeed as %s\n",
                records[g].fname, records[g].lname, records[g].gender, records[g].age, records[g].earning, records[g].height, records[g].occupation);
                printf("Blood group: %s\n",records[g].bloodgroup);
                printf("%s's family are %s, which makes both of your culture and tone symmetric too.\n",records[g].fname, records[g].religion);
                printf("I know this Bot addressed your desire,Right?\nWhy won't you contact her at %lld and gossepe mid-night at this rainy season\n\n", records[g].contact);
            ads('M');
    }
    else if (strcmp(ur_gender,"F") == 0){
      holder = 100;
      for (c;c<n;c++){
          float min_earning = ur_earning;
          if(records[c].earning >= min_earning && records[c].earning < holder && records[c].gender[0] == 'M' &&
            strncmp(strlwr(ur_lname), strlwr(records[c].lname), 4) != 0 &&
            records[c].bloodgroup[strlen(records[c].bloodgroup)-1] == ur_bloodgroup[strlen(ur_bloodgroup)-1] &&
            records[c].age >= (ur_age + age_gap) && records[c].height > ur_height &&
            strcmp(strlwr(records[c].religion),strlwr(ur_religion)) == 0){
            holder = records[c].earning;
            g = c;
            }
        }
        printf("\nHere is what we found\nFull Name: %s %s\nGender: %s\nAge: %d\nHis Annual income is: %.2f LPA\nHis Height is: %.2fft\nEmployeed as %s\n",
                records[g].fname, records[g].lname, records[g].gender, records[g].age, records[g].earning, records[g].height, records[g].occupation);
                printf("Blood group: %s\n",records[g].bloodgroup);
                printf("%s's family are %s, which makes both of your culture and tone symmetric too.\n",records[g].fname, records[g].religion);
                printf("I know this Bot addressed your desire,Right?\nWhy won't you contact him at %lld and gossepe mid-night at this rainy season\n\n", records[g].contact);
            ads('F');
    }
    else{
        printf("Sorry it's against our company policy to assist your gender....%s...",ur_gender);
    }
  return 0;
}

void ads(char v){
  if (v =='M'){
    printf("\nGo Premium for More!\nWhere we have Data of \nperfect match PR holder\nCross verified historic gene disorder of every seekers\nProperty insights\n");
    printf("Detective reporting\nfull access on contact of 80+ Perfect girls waiting for you\nCompany validated earning levels\n...many more");
  }
  else if (v =='F'){
    printf("\nGo Premium for More!\nWhere we have Data of \nCross verified historic gene disorder of every seekers\nProperty insights\n");
    printf("Detective reporting\nGet perfect match PR holder\nfull access on contact of 80+ Perfect boys waiting for you\nCompany validated earning levels\n...many more");
  }
};