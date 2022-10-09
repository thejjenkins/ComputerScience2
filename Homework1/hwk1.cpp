/*
Name: James Jenkins (jamesjenkins2@my.unt.edu)
Instructor: Rubenia Borge Flores
Date: 18 February 2022
CSCE 1040.002 Homework 1
Implementation files: hwk1.cpp, bubble.cpp
Header files: student.h, bubble.h
Data files: grades
Compile: g++ *.cpp
Execute: ./a.out < grades
Description: This program reads from the "grades" text file the name of the class, each students first and last name, and each of their 3 exam scores, and stores each separatly in a dynamic array of structures.
The dynamic array of structures is declared in the student.h header file. 
The average exam score for each student, the minimum score, maximum score, class average, and the median can all be calculated because each score is stored in the dynamic array of structures.
The dynamic array of structures can be sorted in order of lowest student average to highest student average using the bubble.cpp file which is declared in the bubble.h header file.
The final output is the class average, minimum, maximum, median, and bubble sorted dynamic array of student names and exam averages.
*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "student.h"
#include "bubble.h"
using namespace std;

typedef struct classStats {
  float mean;
  float min;
  float max;
  float median;
  char *name;
}stats;
int main()
{
  float sumofmeans = 0.0;
  struct classStats *stats;
  stats = (struct classStats*)malloc(sizeof(struct classStats));
  stats->name = (char*)malloc(sizeof(char)*10);
  struct student_info *students[19];
  for (int i = 0; i<19; ++i)
  {
    students[i]=(struct student_info*)malloc(sizeof(struct student_info));
    students[i]->first=(char*)malloc(sizeof(char)*15);
    students[i]->last=(char*)malloc(sizeof(char)*15);
  }

  scanf("%s", stats->name);
  stats->min=100.00;
  stats->max=0.0;

  for (int i=0;i<19;++i)
  {
    scanf("%s %s %d %d %d", students[i]->first, students[i]->last, &students[i]->exam1, &students[i]->exam2, &students[i]->exam3);
    students[i]->mean=(students[i]->exam1+students[i]->exam2+students[i]->exam3)/3.0;
    sumofmeans+=students[i]->mean;
    if(students[i]->mean<stats->min)
    {
      stats->min=students[i]->mean;
    }
    if(students[i]->mean>stats->max)
    {
      stats->max=students[i]->mean;
    }
  }
  
  stats->mean=sumofmeans/19;
  bubble(students, 19);
  stats->median=students[9]->mean;
  printf("123456789012345678901234567890123456789012345678901234567890\n");
  printf("%s MEAN: %7.2f MIN: %7.2f MAX: %7.2f MEDIAN: %7.2f\n", stats->name, stats->mean, stats->min, stats->max, stats->median);
  for(int i=0; i<19; ++i)
  {
    printf("%12s %12s  %.2f\n", students[i]->first, students[i]->last, students[i]->mean);
  }

  for(int i=0;i<19;++i)
  {
    free(students[i]->first);
    free(students[i]->last);
    free(students[i]);
  }
  free(stats->name);
  free(stats);
  return 0;
}