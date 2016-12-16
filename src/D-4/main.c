/*
 * test.c
 *
 *  Created on: 2016/12/15
 *      Author: iwabuchiken
 */
#include <stdlib.h>
#include <stdio.h>

#include "wave.h"
//ref http://stackoverflow.com/questions/7581408/including-a-header-file-from-another-directory
//#include "/utils/utils.h"	//=> error
#include "./utils/utils.h"	//=> works

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
	char	*fname = "test_2.txt";
//	char	*fname = "/test_2.txt";	//=> file not found in the paths
//	char	*fname = "/test.txt";
//	char	*fname = "test.txt";

	char	time_label[14];

	//ref https://www.tutorialspoint.com/cprogramming/c_file_io.htm
	fp = fopen(fname, "a");
//	fp = fopen(fname, "w+");

	fprintf(fp, "This is testing for fprintf...\n");
	fputs("This is testing for fputs...\n", fp);

	// get: time label
	get_Time_Label(time_label);

	//debug
	printf("[%d] %s\n", __LINE__, time_label);

	fputs(time_label, fp);
	fputs("\n", fp);


	fclose(fp);

	printf("file closed => %s", fname);
}
