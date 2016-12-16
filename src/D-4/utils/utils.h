/*
 * utils.h
 *
 *  Created on: 2015/08/22
 *      Author: kbuchi
 */

#ifndef UTILS_H_
#define UTILS_H_

#ifndef TIME_H_
#define TIME_H_
#include <time.h>
#endif

#ifndef ASSERT_H_
#define ASSERT_H_
#include <assert.h>
#endif

#ifndef STRING_H_
#define STRING_H_
#include <string.h>
#endif

/****************************
 *	@param time_label ---> char[14]
 *
 *	@return
 *	20161217_0112 (13 + 1 = 14 length)
 *
 *****************************/
char* get_Time_Label(char* time_label) {

	//ref http://stackoverflow.com/questions/5141960/get-the-current-time-in-c
	time_t rawtime;
	struct tm * timeinfo;

	time ( &rawtime );
	timeinfo = localtime ( &rawtime );

	sprintf(time_label, "%04d%02d%02d_%02d%02d%02d",
//	sprintf(time_label, "[%04d%02d%02d_%02d%02d%02d]",
//			timeinfo->tm_year,
			timeinfo->tm_year + 1900,
			timeinfo->tm_mon + 1,
			timeinfo->tm_mday,
			timeinfo->tm_hour,
			timeinfo->tm_min,
			timeinfo->tm_sec);

//	char time_label[30];

//	sprintf(time_label, "%s", "2015-08");

	return time_label;

}

char** str_split(char* a_str, const char a_delim)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    /* Count how many elements will be extracted. */
    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (a_str + strlen(a_str) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result = malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}

#endif /* UTILS_H_ */
