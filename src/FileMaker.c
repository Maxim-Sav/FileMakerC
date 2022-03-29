/*
 ============================================================================
 Name        : FileMaker.c
 Author      : Maxim Savenkov
 Version     :
 Copyright   : © Maxim Savenkov 2022
 Description : Executable that can create and execute files. This version uses python on MacOS
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//Write your script here, just don't forget the correct syntax and \n
#define PYSCRIPT "\
	import pyautogui\n\
	import time \n\
	import random \n\
	pyautogui.FAILSAFE = False\n\
	for i in range(10):\n\
		r = int(random.random() * 1000000000)\n\
		name = \"data\" + str(r) + \".dat\"\n\
		print(name)\n\
	"

int main(void) {
	//Import dependencies for script
	system("pip3 install pyautogui");
	//Make the file, in the fopen() you can change where the file is made.
	FILE *pyFile;
	pyFile = fopen("data.py", "w");
	fprintf(pyFile, PYSCRIPT);
	fclose(pyFile);
	//Since system is called from executables directory, we have to use cd. I used applescript
	//As I am on Mac, but this can be changed and adapted for any OS.
	system("osascript -e 'tell application \"Terminal\" to do script \"cd\npython3 data.py\"'");

	return 0;
}
