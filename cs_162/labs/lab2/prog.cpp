#include <iostream>
#include <string>
#include <fstream>

#include "student.h"

using namespace std;


int main(){
  fstream  fin;
  ofstream fout;

  // open file
  fin.open("./input.txt");
  fout.open("./output.txt");
  if((!fin.is_open()) or (!fout.is_open())){
    cout << "Error, unable to open file";
    return 1;
  }

  // read first line
  int num_students;
  fin>>num_students;
  student* student_db = new student[num_students];
  get_student_db_info(student_db, num_students, fin);
  sort_by_id_ascending(student_db, num_students);
  for(int i=0; i<num_students; i++){
    fout << student_db[i].id << " " << student_db[i].first_name << " " << student_db[i].last_name
         << " "<< student_db[i].major << " " << endl;
  }fout<< endl;

  sort_by_last_name(student_db, num_students);
  for(int i=0; i<num_students; i++){
    fout << student_db[i].id << " " << student_db[i].first_name << " " << student_db[i].last_name
          << " "<< student_db[i].major << " " << endl;
  }fout<<endl;

  fout<<get_num_majors(student_db, num_students);


  delete_student_db_info(student_db, num_students);
  fin.close();
  fout.close();
  return 0;
}


 

