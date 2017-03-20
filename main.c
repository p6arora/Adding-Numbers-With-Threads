/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Paarth
 *
 * Created on March 19, 2017, 8:36 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//create a global variable sum so all threads can access it
 long long sum = 0;
/*
 * 
 */
//thread function to generate a sum of 0 to N

 
 //needs to pass a ptr of void arg because that's what the pthread_create function passes as argument
void* sum_runner(void* arg){
    
//creates the ptr to the actual limit 
// has to pass the type case into a long long ptr the arg which was originally a void ptr
    long long *limit_ptr = (long long*) arg;
    
//a star function on a ptr makes it turn into the actual value
    long long limit = *limit_ptr;
    
    

//basic loop to start from the value of 0 and generate a sum all the way to the value of limit
	for (long long i = 0; i <= limit; i++) {
		sum += i;
	}
    
// calls the exit function on a pthread. Not always neccissary because that return value of 0 is known as status and out pthread_join
// has the &Status set to NULL, which means it's not really catching it anyway
 	pthread_exit(0);
}






int main(int argc, char** argv) {
    
//checks if 2 inputs are given, then knows it has some input
// first input in the command line is always gonna be the name of the file
// if determines more than 2 inputs given, will exit the program
    if(argc > 2){
//outputs the order required for program
        printf("Usage: %s <num> \n", argv[0]);
        exit(-1);
    }
// as the command line is passed as an array of characters, the second string, which is the number
// is converted to int by the atoll command
    long long limit = atoll(argv[1]);
    
    //Thread ID
    pthread_t ID;
    
    //create attributes
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    
    //creates the thread which sums the value of limit
    pthread_create(&ID, &attr,sum_runner, &limit );
    
    //wait until thread is finished
    pthread_join(ID, NULL);
    
  //outputs the sum
    printf("Sum is %lld. \n", sum);

    return (EXIT_SUCCESS);
}

