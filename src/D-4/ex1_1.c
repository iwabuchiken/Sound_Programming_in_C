/*
 * ex1_1.c
 *
 *  Created on: 2017/01/13 13:21:00
 *      Author: http://floor13.sakura.ne.jp/book03/book03.html　"chapter01.zip"
 *
 *	<Usage>
 *	exe file executed at: C:\WORKS_2\WS\Eclipse_Neon\Sound_Programming_in_C
pushd C:\WORKS_2\WS\Eclipse_Neon\Sound_Programming_in_C
C:\WORKS_2\WS\Eclipse_Neon\Sound_Programming_in_C\Debug\Sound_Programming_in_C.exe

	<generated files => into: C:\WORKS_2\WS\Eclipse_Neon\Sound_Programming_in_C\files>
 *
 */

/*
 * <execution patterns>



 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "wave.h"

#include "utils/utils.h"

char* FNAME_SRC = "C:\\WORKS_2\\WS\\Eclipse_Neon\\Sound_Programming_in_C\\src\\D-4\\a.wav";
char* FNAME_DST_TRUNK = "C:\\WORKS_2\\WS\\Eclipse_Neon\\Sound_Programming_in_C\\files\\b";

int main(void)
{
  MONO_PCM pcm0, pcm1;
  int n;
  
//  char* fname_src = "C:\\WORKS_2\\WS\\Eclipse_Neon\\Sound_Programming_in_C\\src\\D-4\\a.wav";

  mono_wave_read(&pcm0, FNAME_SRC); /* WAVEファイルからモノラルの音データを入力する */
//  mono_wave_read(&pcm0, fname_src); /* WAVEファイルからモノラルの音データを入力する */
//  mono_wave_read(&pcm0, "a.wav"); /* WAVEファイルからモノラルの音データを入力する */
  

  //debug
  printf("[%d] wave --> read done\n", __LINE__);

  //test
  char fname[100];
//  char fname[50];

  get_file_name_with_time_label(fname, FNAME_DST_TRUNK, "wav");
//  get_file_name_with_time_label(fname, "files/b", "wav");
//  get_file_name_with_time_label(fname, "b", "wav");
//  get_file_name_with_time_label(fname, "b", ".wav");
//  char* fname = get_file_name_with_time_label("b", ".wav");

  printf("[%d] fname(utils.h) --> %s\n", __LINE__, fname);


  pcm1.fs = pcm0.fs; /* 標本化周波数 */
  pcm1.bits = pcm0.bits; /* 量子化精度 */
  pcm1.length = pcm0.length; /* 音データの長さ */
  pcm1.s = calloc(pcm1.length, sizeof(double)); /* メモリの確保 */
  for (n = 0; n < pcm1.length; n++)
  {
    pcm1.s[n] = pcm0.s[n]; /* 音データのコピー */
//    pcm1.s[n] = pcm0.s[n]; /* 音データのコピー */
  }
  
  mono_wave_write(&pcm1, fname); /* WAVEファイルにモノラルの音データを出力する */
//  mono_wave_write(&pcm1, "b.wav"); /* WAVEファイルにモノラルの音データを出力する */
  
  free(pcm0.s); /* メモリの解放 */
  free(pcm1.s); /* メモリの解放 */
  
  return 0;
}
