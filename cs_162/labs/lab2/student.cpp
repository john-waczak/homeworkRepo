#include <iostream>
#include <fstream>
#include <string>
#include "student.h"

using namespace std;

student* create_student_db(int num_students){
  student* student_db = new student[num_students];
  return student_db;
}


void get_student_db_info(student* student_db, int num_students, fstream& f){
  for (int i=0; i<num_students; i++){
    // make sure you're not at the end of the file
    if(f.eof()){
      break;
    }

    f >> student_db[i].id;
    f >> student_db[i].first_name;
    f >> student_db[i].last_name;
    f >> student_db[i].major;

  }
}




void sort_by_id_descending(student* student_db, int num_students){
  student temp;
  for(int i=0; i<num_students-1; i++){
    for(int j=(i+1); j<num_students; j++){
      // exchange the values
      if(student_db[i].id<student_db[j].id){
        temp = student_db[i];
        student_db[i] = student_db[j];
        student_db[j] = temp;
      }
    }
  }
}


void sort_by_id_ascending(student* student_db, int num_students){
  student temp;
  for(int i=0; i<num_students-1; i++){
    for(int j=(i+1); j<num_students; j++){
      // exchange the values
      if(student_db[i].id>student_db[j].id){
        temp = student_db[i];
        student_db[i] = student_db[j];
        student_db[j] = temp;
      }
    }
  }
}


void sort_by_last_name_reverse(student* student_db, int num_students){
  student temp;
  for(int i=0; i<num_students-1; i++){
    for(int j=(i+1); j<num_students; j++){
    // exchange the values
      if(student_db[i].last_name<student_db[j].last_name){
        temp = student_db[i];
        student_db[i] = student_db[j];
        student_db[j] = temp;
      }
    }
  }
}


void sort_by_last_name(student* student_db, int num_students){
  student temp;
  for(int i=0; i<num_students-1; i++){
    for(int j=(i+1); j<num_students; j++){
      // exchange the values
      if(student_db[i].last_name>student_db[j].last_name){
        temp = student_db[i];
        student_db[i] = student_db[j];
        student_db[j] = temp;
      }
    }
  }
}


void delete_student_db_info(student* student_db, int num_students){
  delete []student_db; 
}


int get_num_majors(student* student_db, int num_students){
  int num_major = num_students;
  cout << num_major;
  for(int i =1; i<num_students; i++){
    if(student_db[i].major==student_db[i-1].major){
      num_major--;
    }
  }


  return num_major;
}
