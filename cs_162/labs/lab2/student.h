#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <fstream>
#include <string>

struct student{
  int id;
  std::string first_name;
  std::string last_name;
  std::string major;
};


student* create_student_db(int num_students);
void get_student_db_info(student* student_db, int num_students, std::fstream& f);
void sort_by_id_descending(student* student_db, int num_students);
void sort_by_id_ascending(student* student_db, int num_students);
void sort_by_last_name_reverse(student* student_db, int num_students);
void sort_by_last_name(student* student_db, int num_students);
void delete_student_db_info(student* student_db, int num_students);
int get_num_majors(student* student_db, int num_students); 
#endif
