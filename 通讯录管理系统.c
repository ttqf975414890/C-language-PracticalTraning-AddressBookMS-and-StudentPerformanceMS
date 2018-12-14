// 1711640118 叶文滔

#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#define MAXSTU 1024
#define MAXNAMELENGTH 18
#define MAXPHONELENGTH 18
#define MAXQQLENGTH 18

const char byebye[] = "\
＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝\n\
　　　　       　　　  　　　　  　　        　　　　\n\
　　　　■■■■■■■　　　■■　　　　■■　　■■■■■■■■　　　　\n\
　　　　■■　　　　■■　　■■　　　　■■　　■■　　　　　　　　　　\n\
　　　　■■　　　　■■　　　■■　　■■　　　■■　　　　　　　　　　\n\
　　　　■■■■■■■■　　　　■■■■　　　　■■■■■■■■　　　　\n\
　　　　■■　　　　■■　　　　　■■　　　　　■■　　　　　　　　　　\n\
　　　　■■　　　　■■　　　　　■■　　　　　■■　　　　　　　　　　\n\
　　　　■■■■■■■　　　　　　■■　　　　　■■■■■■■■　　　　\n\
　　　　       　　　  　　　　  　　        　　　　\n\
　　　　       　　　  　　　　  　　        　　　　\n\
　　　　■■■■■■■　　　■■　　　　■■　　■■■■■■■■　　　　\n\
　　　　■■　　　　■■　　■■　　　　■■　　■■　　　　　　　　　　\n\
　　　　■■　　　　■■　　　■■　　■■　　　■■　　　　　　　　　　\n\
　　　　■■■■■■■■　　　　■■■■　　　　■■■■■■■■　　　　\n\
　　　　■■　　　　■■　　　　　■■　　　　　■■　　　　　　　　　　\n\
　　　　■■　　　　■■　　　　　■■　　　　　■■　　　　　　　　　　\n\
　　　　■■■■■■■　　　　　　■■　　　　　■■■■■■■■　　　　\n\
　　　　       　　　  　　　　  　　        　　　　\n\
＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝\n\n\
";

struct typeStudent{
	long ID;
	char name[MAXNAMELENGTH];
	char phone[MAXPHONELENGTH];
	char qq[MAXQQLENGTH];
};
typedef struct typeStudent STUDENT;

int language;

/* Make var randomless. Not used in this program.
void makeZeroInteger(int *integer, int number) {
	int i;
	for (i = 0; i < number; i++) {
		*(integer + i) = 0;
	}
}
void makeZeroChar(char *charset, int number) {
	int i;
	for (i = 0; i < number; i++) {
		*(charset + i) = 0;
	}
}
*/

// 1. Input record
void InputRecord(STUDENT *student, int *stuNum) {
	int index = 0;
	char temp;
	
	system("cls");
	if (*stuNum > 0) {
		do {
			switch(language) {
				case 0: { printf("\nYou have already input data here. If you want to clear them all and input, please input Y and enter.\nElse, input N, then go to INSERT RECORD.\nYour choice: "); break; }
				case 1: { printf("\n您此前已经输入过数据了。是否要清空并重新输入？\n如果是，请输入 Y 并回车\n否则，输入 N 并进入插入数据模块。\n您的选择是："); break; }
				case 2: { printf("\n你之前已经输入过数据咯喔，系咪要清空并且重新输入？如果喺，请输入 Y 然之后回车\n唔系嘅话，输入 N 然之后进入插入数据模块。\n你想点呢：\n\n"); break; }
			}
			gets(&temp);
			if (temp == *"Y" || temp == *"y") { system("cls"); break; }
			else if (&temp == "N" || temp == *"n") { system("cls"); return; break; }
		} while(1);
	}
	switch(language) {
		case 0: { printf("\nPlease enter Name (without space) in order (split by space). Press Enter to confirm.\nMaximum storage is 1024 students. Input 0 and enter to finish.\n\n"); break; }
		case 1: { printf("\n请按顺序输入姓名（不含空格）、电话、QQ，以空格区分。按空格键以确认。最大存储容量为 1024 个学生。输入 0 并回车以结束。"); break; }
		case 2: { printf("\n请顺住输入姓名（唔可以有空格）、电话、QQ，摞空格区分。滴空格掣输入下一个。最大装得落 1024 个学生。输入 0 然之后回车就可以结束。\n\n"); break; }
	}
	putchar(10);
	do{												// Input information
		switch(language) {
			case 0: { printf("Please input the No.%d person's information: ", index + 1); break; }
			case 1: { printf("请输入第 %d 个人的信息：", index + 1); break; }
			case 2: { printf("喺度输入第 %d 个人嘅信息：", index + 1); break; }			
		}
		(student+index)->ID = index;
		scanf("%s", (student+index)->name);
		if (!strcmp((student+index)->name, "0")) break;		// Input 0 to finish input
		scanf("%s", (student+index)->phone);
		scanf("%s", (student+index)->qq);
		getchar();									// clear cache
	}while (++index != MAXSTU);
	
	system("cls");
	switch(language) {
		case 0: { printf("Number of persons: %d\n\n", index); break; }
		case 1: { printf("人员数量：%d\n\n", index); break; }
		case 2: { printf("一共录入咗 %d 个人。\n\n", index); break; }		
	}
	*stuNum = index;
}

// 2. Display record
void DisplayRecord(STUDENT *student, int stuNum, int ClearScreen) {
	int index = 0;
	int rep, sum;

	if (ClearScreen) system("cls");
	switch(language) {
		case 0: { printf("----ID----|---Name---|-Phonenum-|----QQ---"); break; }
		case 1: { printf("---编号---|---姓名---|-电话号码-|----QQ---"); break; }
		case 2: { printf("---编号---|---姓名---|-电话号码-|----QQ---"); break; }		
	}
	putchar(10);
	for (index = 0; index < stuNum; index++) {
		printf(" %8d | %8s | %8s | %8s", (student+index)->ID + 1, (student+index)->name, (student+index)->phone, (student+index)->qq);
		printf("\n");
	}
	putchar(10);
}

// Swapper
void Swap(STUDENT *stuA, STUDENT *stuB) {
	STUDENT temp = *stuA;
	*stuA = *stuB;
	*stuB = temp;
}

// 3. Delete Record
void DeleteRecord(STUDENT *student, int *stuNum) {
	int index = 0, i, j;
	char toFind[MAXNAMELENGTH];

	system("cls");
	DisplayRecord(student, *stuNum, 1);
	do {
		switch(language) {
			case 0: { printf("Input student's name/phone/QQ	then enter. To go back to main menu, input 0 then enter: "); break; }
			case 1: { printf("输入学生姓名/电话/QQ并回车。欲返回主菜单，输入零并回车："); break; }
			case 2: { printf("输入学生嘅姓名/电话/QQ然后回车。假如想翻番主菜单，输入零然之后回车："); break; }			
		}
		scanf("%s", &toFind);
		getchar();									// clear cache
		if (strcmp(toFind, "0")) {
			do {
				if (!strcmp((student+index)->name, toFind) || !strcmp((student+index)->phone, toFind) || !strcmp((student+index)->qq, toFind)) {
					for (i = index; i < *stuNum; i++) {
						student[i] = student[i+1];
					}
					(*stuNum)--;
					DisplayRecord(student, *stuNum, 1);
					index = 0;
					break;
				}
				else if (index == *stuNum) {
					switch(language) {
						case 0: { printf("Couldn't find this person :-(. Please re-input.\n\n"); break; }
						case 1: { printf("找不到这个人 :-(。请重新输入。\n\n"); break; }
						case 2: { printf("揾唔到呢条友。唔该重新输入下 :-)。\n\n"); break; }						
					}
					index = 0;
					break;
				}
				else {
					index++;
				}
			} while (1);
		}
		else {
			break;
		}
	} while (1);
	system("cls");
}

// 4. Search by number
void SearchRecord(STUDENT *student, int stuNum) {
	int index = 0;
	char toFind[MAXNAMELENGTH];

	DisplayRecord(student, stuNum, 1);
	do {
		switch(language) {
			case 0: { printf("Input student's name/phone/QQ	then enter. To go back to main menu, input 0 then enter: "); break; }
			case 1: { printf("输入学生姓名/电话/QQ并回车。欲返回主菜单，输入零并回车："); break; }
			case 2: { printf("输入学生嘅姓名/电话/QQ然后回车。假如想翻番主菜单，输入零然之后回车："); break; }			
		}
		scanf("%s", &toFind);
		getchar();									// clear cache
		if (strcmp(toFind, "0")) {
			do {
				if (!strcmp((student+index)->name, toFind) || !strcmp((student+index)->phone, toFind) || !strcmp((student+index)->qq, toFind)) {
					DisplayRecord(student, stuNum, 1);
					switch(language) {
						case 0: { printf("ID        : %8d\nname      : %8s\nphone     : %8s\nQQ        : %8s\n", (student+index)->ID, (student+index)->name, (student+index)->phone, (student+index)->qq); break; }
						case 1: { printf("编号      : %8d\n姓名      : %8s\n电话      : %8s\nQQ        : %8s\n", (student+index)->ID, (student+index)->name, (student+index)->phone, (student+index)->qq); break; }						
						case 2: { printf("编号      : %8d\n姓名      : %8s\n电话      : %8s\nQQ        : %8s\n", (student+index)->ID, (student+index)->name, (student+index)->phone, (student+index)->qq); break; }						
					}
					putchar(10);
					index = 0;
					break;
				}
				else if (index == stuNum) {
					switch(language) {
						case 0: { printf("Couldn't find this person :-(. Please re-input.\n\n"); break; }
						case 1: { printf("找不到这个人 :-(。请重新输入。\n\n"); break; }
						case 2: { printf("揾唔到呢条友。唔该重新输入下 :-)。\n\n"); break; }						
					}
					index = 0;
					break;
				}
				else {
					index++;
				}
			} while (1);
		}
		else {
			break;
		}
	} while (1);
	system("cls");
}

// 5. Modify Record
void ModifyRecord(STUDENT *student, int stuNum) {
	int index = 0, i;
	char toFind[MAXNAMELENGTH];

	system("cls");
	DisplayRecord(student, stuNum, 1);
	do {
		switch(language) {
		case 0: { printf("Input student's name/phone/QQ	then enter. To go back to main menu, input 0 then enter: "); break; }
		case 1: { printf("输入学生姓名/电话/QQ并回车。欲返回主菜单，输入零并回车："); break; }
		case 2: { printf("输入学生嘅姓名/电话/QQ然后回车。假如想翻番主菜单，输入零然之后回车："); break; }			
		}
		scanf("%s", &toFind);
		getchar();									// clear cache
		if (strcmp(toFind, "0")) {
			do {
				if (!strcmp((student+index)->name, toFind) || !strcmp((student+index)->phone, toFind) || !strcmp((student+index)->qq, toFind)) {
					switch(language) {
						case 0: { printf("\nPlease enter Name (without space) in order (split by space). Press Enter to confirm: "); break; }
						case 1: { printf("\n请按顺序输入姓名（不含空格）、电话、QQ，以空格区分。按空格键分隔。回车以修改："); break; }
						case 2: { printf("\n请顺住输入姓名（唔可以有空格）、电话、QQ，摞空格区分。滴空格掣分隔。回车就可以修改："); break; }
					}
					putchar(10);
					scanf("%s", (student+index)->name);
					scanf("%s", (student+index)->phone);
					scanf("%s", (student+index)->qq);
					getchar();									// clear cache
					DisplayRecord(student, stuNum, 1);
					index = 0;
					break;
				}
				else if (index == stuNum) {
					switch(language) {
						case 0: { printf("Couldn't find this person :-(. Please re-input.\n\n"); break; }
						case 1: { printf("找不到这个人 :-(。请重新输入。\n\n"); break; }
						case 2: { printf("揾唔到呢条友。唔该重新输入下 :-)。\n\n"); break; }						
					}
					index = 0;
					break;
				}
				else {
					index++;
				}
			} while (1);
		}
		else {
			break;
		}
	} while (1);
	system("cls");
}

// 6. Input record
void InsertRecord(STUDENT *student, int *stuNum) {
	int index;
	index = *stuNum;
	
	system("cls");
	switch(language) {
		case 0: { printf("\nPlease enter Name (without space) in order (split by space). Press Enter to confirm.\nMaximum storage is 1024 students. Input 0 and enter to finish.\n\n"); break; }
		case 1: { printf("\n请按顺序输入姓名（不含空格）、电话、QQ，以空格区分。按空格键以确认。最大存储容量为 1024 个学生。输入 0 并回车以结束。"); break; }
		case 2: { printf("\n请顺住输入姓名（唔可以有空格）、电话、QQ，摞空格区分。滴空格掣输入下一个。最大装得落 1024 个学生。输入 0 然之后回车就可以结束。\n\n"); break; }
	}
	putchar(10);
	do{												// Input information
		switch(language) {
			case 0: { printf("Please input the No.%d person's information: ", index + 1); break; }
			case 1: { printf("请输入第 %d 个人的信息：", index + 1); break; }
			case 2: { printf("喺度输入第 %d 个人嘅信息：", index + 1); break; }			
		}
		(student+index)->ID = index;
		scanf("%s", (student+index)->name);
		if (!strcmp((student+index)->name, "0")) break;		// Input 0 to finish input
		scanf("%s", (student+index)->phone);
		scanf("%s", (student+index)->qq);
		getchar();									// clear cache
	}while (++index != MAXSTU);
	
	system("cls");
	switch(language) {
		case 0: { printf("Number of persons: %d\n\n", index); break; }
		case 1: { printf("人员数量：%d\n\n", index); break; }
		case 2: { printf("一共录入咗 %d 个人。\n\n", index); break; }		
	}
	*stuNum = index;
}

// 7. Sort record
void SortRecord(STUDENT *student, int stuNum) {
	int i, j;
	for (i = 0; i < stuNum - 1; i++) {
		for (j = i + 1; j < stuNum; j++) {
			if (strcmp((student+i)->phone, (student+j)->phone) > 0) {
				Swap(student + j, student + i);
			}
		}
	}
	DisplayRecord(student, stuNum, 1);
}

// 8. Save record
void WriteFile(STUDENT *student, int stuNum) {
	FILE *fp;
	system("cls");
	if ((fp = fopen("PhoneRecord","wb")) != NULL) {
		fwrite(&stuNum, sizeof(int), 1, fp);
		fwrite(student, sizeof(STUDENT), stuNum, fp);
		fclose(fp);
		switch(language) {
			case 0: { printf("Data saved in \"PhoneRecord\" in current directory.\n\n"); break; }
			case 1: { printf("数据已保存至当前目录下的 \"PhoneRecord\" 文件内。\n\n"); break; }
			case 2: { printf("数据保存咗喺宜家呢个目录入边嘅 \"PhoneRecord\" 文件入边。\n\n"); break; }		
		}
	} else {
		switch(language) {
			case 0: { printf("Sorry. Fail to open file.\n\n"); break; }
			case 1: { printf("抱歉，文件打开失败。\n\n"); break; }
			case 2: { printf("唔好意思，个文件开唔到。\n\n"); break; }			
		}
	}
}

void ReadFile(STUDENT *student, int *stuNum) {
	int index;
	FILE *fp;
	system("cls");
	if ((fp = fopen("PhoneRecord","rb")) != NULL) {
		fread(stuNum, sizeof(int), 1, fp);
		for (index = 0; !feof(fp); index++) {
			fread(student+index, sizeof(STUDENT), 1, fp);
		}
		fclose(fp);
		DisplayRecord(student, *stuNum, 0);
	} else {
		switch(language) {
			case 0: { printf("Sorry. Fail to open file.\n\n"); break; }
			case 1: { printf("抱歉，文件打开失败。\n\n"); break; }
			case 2: { printf("唔好意思，个文件打唔开。\n\n"); break; }			
		}
	}
}

int main()
{
	int selection;
	char temp;						// yes or no
	int stuNum = 0;
	int isExit = 0;					// a flag
	STUDENT student[MAXSTU];		// an object array
	FILE *fp = NULL;
	
	printf("通讯录管理系统 V1.0 date: 20180624\n\nSelect language:\n");
	do {
		printf("[ a. English ] [ b. 汉语 ] [ c. 粤语（非书面） ] : ");
		gets(&temp);
		switch(temp) {
			case 65: { language = 0; goto start; }
			case 97: { language = 0; goto start; }
			case 66: { language = 0; goto start; }
			case 98: { language = 1; goto start; }
			case 67: { language = 0; goto start; }
			case 99: { language = 2; goto start; }
		}
	} while(1);
	start:
	if ((fp = fopen("PhoneRecord","rb")) != NULL) {		// Found data.
		do {
			switch(language) {
				case 0: { printf("You have previously saved your data here. Read it? [Y/N] "); break; }
				case 1: { printf("您此前已在此处保存数据。是否读取？[Y/N] "); break; }
				case 2: { printf("你之前喺??度已经存过档。系咪要读翻佢？[Y/N] "); break; }
			}
			gets(&temp);
			if (temp == *"Y" || temp == *"y") { ReadFile(student, &stuNum); break; }
			else if (&temp == "N" || temp == *"n") { system("cls"); break; }
		} while(1);
	}
	
	system("cls");
	do{
		selection = -1;				// function selection
		switch(language) {
			case 0: {
				printf("The telephone-book Management System V1.0 date: 20180624\n\n");
				printf("%s", "╔═══════════════════════════════════════════════════════════════╗\n");
				printf("%-64s ║\n", "╠   1. Input   record");
				printf("%-64s ║\n", "╠   2. Display record");
				printf("%-64s ║\n", "╠   3. Delete  record");
				printf("%-64s ║\n", "╠   4. Search  record");
				printf("%-64s ║\n", "╠   5. Modify  record");
				printf("%-64s ║\n", "╠   6. Insert  record");
				printf("%-64s ║\n", "╠   7. Sort    record");
				printf("%-64s ║\n", "╠   8. Save    record");
				printf("%-64s ║\n", "╠   0. Quit    system");
				printf("%s", "╚═══════════════════════════════════════════════════════════════╝\n");
				printf("Please enter your choice: ");
				break;
			}
			case 1: {
				printf("通讯录管理系统 V1.0 date: 20180624\n\n");
				printf("%s", "╔═══════════════════════════════════════════════╗\n");
				printf("%-48s ║\n", "╠   1. 输入数据");
				printf("%-48s ║\n", "╠   2. 显示数据");
				printf("%-48s ║\n", "╠   3. 删除数据");
				printf("%-48s ║\n", "╠   4. 搜索数据");
				printf("%-48s ║\n", "╠   5. 修改数据");
				printf("%-48s ║\n", "╠   6. 插入数据");
				printf("%-48s ║\n", "╠   7. 排序数据");
				printf("%-48s ║\n", "╠   8. 保存数据");
				printf("%-48s ║\n", "╠   0. 退出系统");
				printf("%s", "╚═══════════════════════════════════════════════╝\n");
				printf("请输入您的选择：");
				break;
			}
			case 2: {
				printf("电话簿管理系统 V1.0 date: 20180624\n\n");
				printf("%s", "╔═══════════════════════════════════════════════╗\n");
				printf("%-48s ║\n", "╠   1. 输入数据");
				printf("%-48s ║\n", "╠   2. 显示数据");
				printf("%-48s ║\n", "╠   3. 删除数据");
				printf("%-48s ║\n", "╠   4. 搜索数据");
				printf("%-48s ║\n", "╠   5. 修改数据");
				printf("%-48s ║\n", "╠   6. 插入数据");
				printf("%-48s ║\n", "╠   7. 排序数据");
				printf("%-48s ║\n", "╠   8. 保存数据");
				printf("%-48s ║\n", "╠   0. 退出系统");
				printf("%s", "╚═══════════════════════════════════════════════╝\n");
				printf("请输入您的选择：");
				printf("你想点呢：");
				break;
			}
		}
		scanf("%d", &selection);
		getchar();					// clear cache
		switch(selection) {
			case 1:									// 1. Input record
				InputRecord(student, &stuNum);
				break;
			case 2:									// 2. Display record
				DisplayRecord(student, stuNum, 1);
				break;
			case 3:									// 3. Delete record
				DeleteRecord(student, &stuNum);
				break;
			case 4:									// 4. Search record
				SearchRecord(student, stuNum);
				break;
			case 5:									// 5. Modify record
				ModifyRecord(student, stuNum);
				break;
			case 6:									// 6. Insert record
				InsertRecord(student, &stuNum);
				break;
			case 7:									// 7. Sort record
				SortRecord(student, stuNum);
				break;
			case 8:									// 8. Save record
				WriteFile(student, stuNum);
				break;
			case 0:
				isExit = 1;
				system("cls");
				printf("%s", byebye);
				break;
			case -1:{
			}
			default:{
				system("cls");
				switch (language) {
					case 0: { printf("Hey, guy! Your input is unvalidated. Please input again.\n\n"); break; }
					case 1: { printf("您的选择不正确噢，请重新输入。\n\n"); break; }
					case 2: { printf("滴错掣啦，重新输多次啦。\n\n"); break; }
				}					
				break;
			}
		}
	}while(!isExit);
	system("pause");
	return 0;
}
