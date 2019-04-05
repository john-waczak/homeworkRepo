#ifndef MULT_DIV_H
#define MULT_DIV_H

// Prototypes
void were_dimensions_specified(int);

struct mult_div_values;

bool is_valid_dimensions(char*, char*);

mult_div_values** create_table(int m, int n);
void set_mult_values(mult_div_values** table, int m, int n);
void set_div_values(mult_div_values** table, int m, int n);
void delete_table(mult_div_values** table, int m);
void print_table(mult_div_values** table, int m, int n);



#endif
