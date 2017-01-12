/*
 * test.c
 *
 *  Created on: 2016/12/15
 *      Author: iwabuchiken
 *
 *	<Usage>
 *	exe file executed at: C:\WORKS_2\WS\Eclipse_Neon\Sound_Programming_in_C
pushd C:\WORKS_2\WS\Eclipse_Neon\Sound_Programming_in_C
C:\WORKS_2\WS\Eclipse_Neon\Sound_Programming_in_C\Debug\Sound_Programming_in_C.exe

	<generated files => into: C:\WORKS_2\WS\Eclipse_Neon\Sound_Programming_in_C\files>
 *
 */
#include <stdlib.h>
#include <stdio.h>

#include "wave.h"
//ref http://stackoverflow.com/questions/7581408/including-a-header-file-from-another-directory
//#include "/utils/utils.h"	//=> error
#include "./utils/utils.h"	//=> works
//#include "utils/utils.h"	//=>

/****************************
 *
 *	global vars
 *
 *****************************/
char time_label[14];

/****************************
 *
 * 	protos
 *
 *****************************/
void _test(void);


/****************************
 *
 *	funcs
 *
 *****************************/

int main() {

//	FILE	*fp;
	_test();

//	printf("new");

	return 0;

}

void _test() {

	FILE	*fp;
//	char	*fname = "\\test_3.txt";	//=> file not found in the paths
//	char	*fname = "C:\\WORKS_2\\test_2.txt";
//	char	*fname = "test_2.txt";	//=> working:
									//	exe file executed at: C:\WORKS_2\WS\Eclipse_Neon\Sound_Programming_in_C\Debug>popd
									//	file created at: execution location

//	char	*fname = "files\\test_2.txt";	//=>
	char	fname[50];	//=>

	// get: time label
	char	time_label[14];
	get_Time_Label(time_label);

	sprintf(fname, "files\\test_2.%s.txt", time_label);


//	char	*fname = "/test_2.txt";	//=> file not found in the paths
//	char	*fname = "/test.txt";
//	char	*fname = "test.txt";

//	char	time_label[14];

	//ref https://www.tutorialspoint.com/cprogramming/c_file_io.htm
	fp = fopen(fname, "a");
//	fp = fopen(fname, "w+");

	fprintf(fp, "This is testing for fprintf...\n");
	fputs("This is testing for fputs...\n", fp);

//	// get: time label
//	get_Time_Label(time_label);

	//debug
	printf("[%d] %s\n", __LINE__, time_label);

	fputs(time_label, fp);
	fputs("\n", fp);


	fclose(fp);

	printf("file closed => %s", fname);
}
