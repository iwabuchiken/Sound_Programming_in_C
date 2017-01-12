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

	//test
//	char* fname_format = "files\\test_2.%s.aaaaaaaaaaaaaaaaaaaaaaa.txt";
	char* fname_format = "files\\test_2.%s.txt";

	//debug
//	printf("[%d] size of fname_format => %d\n", __LINE__, sizeof(fname_format));
//	printf("[%d] size of fname_format => %d\n", __LINE__, sizeof(fname_format) / sizeof(char));

	/****************************
	 *
	 * validate: file name less than (fname less time label)
	 *
	 *****************************/
	//debug
	//ref http://stackoverflow.com/questions/1838468/count-the-number-or-characters-in-the-string answered Dec 3 '09 at 8:29
	int i =0;
//	while (*(fname_format[i])) i++;	//=> invalid type argument of unary '*' (have 'int')
	while ((fname_format[i])) i++;	//=>

//	while (*(fname_format[i])) i++;
//	while (*fname_format++) i++;

	printf("[%d] fname_format => %d chars\n", __LINE__, i);

	int len_fname = sizeof(fname) / sizeof(char);
	int len_time_label = sizeof(time_label) / sizeof(char);

	if (i + len_time_label + 1 > len_fname) {

		printf("[%d] file name is more than %d; quitting...\n", __LINE__, len_fname);

		return;

	} else {

		printf("[%d] building fname...\n", __LINE__);

	}

	sprintf(fname, fname_format, time_label);
//	sprintf(fname, "files\\test_2.%s.txt", time_label);


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
