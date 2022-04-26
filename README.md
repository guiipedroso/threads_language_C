++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
+								   +
+ I made this program using the c language to fill a 40-position   +
+ vector with random numbers, and the program has 4 threads, each  +
+ thread being responsible for a quarter of the vector, that is:   +
+								   +
+ Thread 1 fills numbers between positions 0 to 9;                 + 
+                                                                  +
+ Thread 2 fills in numbers between positions 10 to 19;            +
+                                                                  +
+ Thread 3 fills in numbers between positions 20 to 29;            +
+								   + 
+ Thread 4 fills in numbers between positions 30 to 39;		   +
+								   +
+								   +
+ to compile use this comand: 					   +
+ gcc -pthread programming_thread.c -o programming_threads         +
+ 								   +
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
