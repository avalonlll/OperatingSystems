#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

int global_var; //global variable
const int inc = 1, dec = -1; //steps for thread's function

void *adjust_function(void *n){
	int *i = (int *)n;
	while (1) { //loop for ever
		printf("adj = %2i; x=%i\n", *i, global_var);
		global_var += *i;
} }

int change_number(int global_var, int child_a ){
 	if ( child_a ==0){ //if child_a called change_number function
		global_var += 2;
		printf("%d\n", global_var);
		return global_var;}
	else if ( child_a > 0 ) { //if parent called change_number function
		global_var -= 1;
		printf("%d\n", global_var);
		return global_var;}
	else //other case
		{ printf("failed\n");} }	


int main(int argc, char *argv[])
{
	int variable = 0; 
		printf("Please give the global integer");
		scanf("%d", &global_var); //user gives the global variable
	pid_t child_a; //second process' id
 	child_a = fork();  //make second process
		printf("fork returned %d\n", child_a);
	for (int i=0; i<30; i++){ //call 30 times change_number function for each process
		variable = change_number( global_var, child_a);
		global_var = variable; } 

	if (child_a == 0 ) { //only for child process
		pthread_t thread1, thread2; 
		pthread_attr_t *attr;
     	attr=0;
     	pthread_create(&thread1, attr, adjust_function, (void *)&inc); //make two threads for child process
     	pthread_create(&thread2, attr, adjust_function, (void *)&dec);
     	while (1) { ;} }     //loop forever
	
 }
