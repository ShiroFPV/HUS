#include <stdio.h>

typedef struct {
  char vorname[30];
  char nachname[30];
  char beruf[30];
  int alter;
} TPerson;

int main(void) {
  TPerson person1 = {"Max", "Muster", "Programmierer", 37};
  TPerson person2 = {"Hans", "Muster", "Informatiker", 19};

  printf("Personendaten mit typedef TPerson\n");
  printf("--------------------------------\n");
  printf("Name: %s %s, Alter: %d Jahre, Beruf: %s\n", person1.vorname,
         person1.nachname, person1.alter, person1.beruf);
  printf("Name: %s %s, Alter: %d Jahre, Beruf: %s\n", person2.vorname,
         person2.nachname, person2.alter, person2.beruf);

  return 0;
}
