#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
//#include<random>  //注释掉是因为我不会用……也没用着……那什么什么mt19959的让人头晕的玩意儿……

int table[1000],left,right,out;
//限制为1000是因为我把结果展示部分（result函数）设计成3位整数的了，那样美观且实用

int random(int floor,int ceil) {
	if (ceil-floor>0) return floor+rand()%(ceil-floor);
	else return ceil;
}

void initialize() { //初始化部分
	left=NULL;
	right=NULL;
	out=NULL; //我想想办法解决当输入了字母时爆炸的问题，但似乎赋值NULL不起作用……
	srand(time(NULL)); //经典菜鸟操作
	for(int i=0; i<=999; i++) {
		table[i]=i;
	}
}

void get_parameter() { //获得参数
	printf("Enter range left edge: ");
	scanf("%d",&left);
	printf("Enter range right edge: ");
	scanf("%d",&right);
	printf("Enter sample size: ");
	scanf("%d",&out);
}

void please_wait() { //“请等待”的UI，其实是为了装B
	printf("\n############################\n");
	printf("#                          #\n");
	printf("#      Please wait...      #\n");
	printf("#                          #\n");
	printf("############################\n");
}

bool statement() { //状态显示
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

void shuffle() { //乱序操作：网上看到的洗牌算法
	int target,temp;
	for(int i=left; i<=right; i++) {
		temp=table[i];
		target=random(left,i);
		table[i]=table[target];
		table[target]=temp;
		//Knuth-Shuffle 算法
		//1~x，从最后一个数开始，往前遍历，每一次，从当前数和第 1 个数之间，随机选择一个数，与当前数字进行交换
	}
}

void result() { //结果展示
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

void final() { //结束返回
	Sleep(100);
	printf("#      press any key       #\n");
	printf("#        to restart        #\n");
	printf("############################\n");
	getch();
	system("cls");
}

int main() {
	while(1) { //日常死循环lol
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
