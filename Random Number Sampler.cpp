#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
//#include<random>
int table[1000],left,right,out;
int random(int floor,int ceil) {
	if (ceil-floor>0) return floor+rand()%(ceil-floor);
	else return ceil;
}
void initialize() {
	left=NULL;
	right=NULL;
	out=NULL;
	srand(time(NULL));
	for(int i=0; i<=999; i++) {
		table[i]=i;
	}
}
void get_parameter() {
	printf("Enter range left edge: ");
	scanf("%d",&left);
	printf("Enter range right edge: ");
	scanf("%d",&right);
	printf("Enter sample size: ");
	scanf("%d",&out);
}
void please_wait() {
	printf("\n############################\n");
	printf("#                          #\n");
	printf("#      Please wait...      #\n");
	printf("#                          #\n");
	printf("############################\n");
}
bool statement() {
	system("cls");
	printf("Enter range left edge: %d\n",left);
	printf("Enter range right edge: %d\n",right);
	printf("Enter sample size: %d\n",out);
	if(right>999||left>999||right-left<0||left<=0||out>1+right-left) {
		printf("\n############################\n");
		printf("#            !!!           #\n");
		printf("#     ILLEGAL INPUT :(     #\n");
		printf("#            !!!           #\n");
		printf("############################\n");
		if(right>999||left>999) {
			printf("#          CAUTION         #\n");
			printf("#  Only integers between 1 #\n");
			printf("# and 999 are supported to  #\n");
			printf("# run.                     #\n");
			printf("############################\n");
		}
		return 0;
	} else {
		printf("\n############################\n");
		printf("#                          #\n");
		printf("# RANDOMIZED SUCCESSFULLY! #\n");
		printf("#                          #\n");
		printf("############################\n");
		return 1;
	}
}
void shuffle() {
	int target,temp;
	for(int i=left; i<=right; i++) {
		temp=table[i];
		target=random(left,right);
		table[i]=table[target];
		table[target]=temp;
	}
}
void result() {
	for(int j=1; j<=4*(out/4); j=j+4) {
		printf("#  %3d   %3d   %3d   %3d   #\n",table[j+left-1],table[j+left],table[j+left+1],table[j+left+2]);
	}
	switch(out%4) {
		case 1:
			printf("#  %3d                     #\n",table[left+out-1]);
			break;
		case 2:
			printf("#  %3d   %3d               #\n",table[left+out-2],table[left+out-1]);
			break;
		case 3:
			printf("#  %3d   %3d   %3d         #\n",table[left+out-3],table[left+out-2],table[left+out-1]);
			break;
	}
	printf("############################\n");
}
void final() {
	Sleep(100);
	printf("#      press any key       #\n");
	printf("#        to restart        #\n");
	printf("############################\n");
	getch();
	system("cls");
}
int main() {
	while(1) {
		initialize();
		get_parameter();
		please_wait();
		Sleep(100);
		if(statement()) {
			shuffle();
			result();
		}
		final();
	}
}
