// 1711640118 叶文滔

#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#define MAXNUMLENGTH 18
#define MAXNAMELENGTH 18

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

struct student
{
	char num[MAXNUMLENGTH];   	/*学号*/
	char name[MAXNAMELENGTH];  	/*姓名*/
	int cgrade;     			/*C语言成绩*/
	int mgrade;     			/*数学成绩*/
	int egrade;     			/*英语成绩*/
	int total;      			/*总分*/
	float ave;      			/*平均分*/
	int mingci;     			/*名次*/
};
typedef struct student STUDENT;
struct link
{
	STUDENT data;
	struct link *next;
};

int language, stuNum;
void DisplayRecord(struct link *head, int ClearScreen);

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
struct link *InputRecord(struct link *head) {
	struct link *p = NULL, *pr = head;
	char temp;
	
	system("cls");
	if (stuNum > 0) {
		do {
			switch(language) {
				case 0: { printf("\nYou have already input data here. If you want to clear them all and input, please input Y and enter.\nElse, input N, then go to INSERT RECORD.\nYour choice: "); break; }
				case 1: { printf("\n您此前已经输入过数据了。是否要清空并重新输入？\n如果是，请输入 Y 并回车\n否则，输入 N 并进入插入记录模块。\n您的选择是："); break; }
				case 2: { printf("\n你之前已经输入过数据咯喔，系咪要清空并且重新输入？如果喺，请输入 Y 然之后回车\n唔系嘅话，输入 N 然之后进入插入记录模块。\n你想点呢：\n\n"); break; }
			}
			gets(&temp);
			if (temp == *"Y" || temp == *"y") {
				p = head;
				do {
					pr = p;										// Save pointer of current node in pr
					free(p);
					p = p->next;
				} while (pr->next != NULL);		// Not to the end node
				p = NULL;
				system("cls");
				break; 
			}
			else if (&temp == "N" || temp == *"n") { system("cls"); return head; break; }
		} while(1);
	}
	stuNum = 0;
	// p: New node;  pr: Old node
	switch(language) {
		case 0: { printf("\nPlease enter StudentID, StudentName (without space), Grade Of C Language, Grade Of Math, Grade Of English in order (split by space). Press Enter to confirm.\nInput 0 and enter to finish.\n\n"); break; }
		case 1: { printf("\n请按顺序输入学生学号、学生姓名（不含空格）、语文成绩、数学成绩、英语成绩，以空格区分。按空格键以确认。输入 0 并回车以结束。\n\n"); break; }
		case 2: { printf("\n请顺住输入学生学号、学生姓名（唔可以有空格）、语文成绩、数学成绩、英语成绩，摞空格区分。滴空格掣输入下一个。输入 0 然之后回车就可以结束。\n\n"); break; }
	}
	do{												// Input information of every student
		switch(language) {
			case 0: { printf("Please input the No.%d student's information: ", ++stuNum); break; }
			case 1: { printf("请输入第 %d 个学生的信息：", ++stuNum); break; }
			case 2: { printf("喺度输入第 %d 个学生嘅信息：", ++stuNum); break; }
		}
		pr = p;															// Before allocating memory, save the old one
		// makeZeroChar(&((student+index)->name), MAXNAMELENGTH);		// Don't keep it ramdom.
		p = (struct link *)malloc(sizeof(struct link));					// Allocate new node
		if (p == NULL) {
			switch(language) {
				case 0: { printf(":-( Memory allocation failed. Please check your OS.\n"); break; }
				case 1: { printf(":-( 内存分配失败。请检查你的操作系统。\n"); break; }
				case 2: { printf(":-( 内存分配唔到。请检查下你嘅操作系统。\n"); break; }			
			}
			exit(0);
		}
		if (stuNum == 1) {
			head = p;
			pr = p;														// There is nothing in pr, but in line 89 it will error without validate data
		}
		pr->next = p;													// Point old node's "next" to new node
		scanf("%s", &(p->data.num));									// Input 0 to finish input
		if (p->data.num[0] == 48) {
			pr->next = NULL;												// Make the next node of the old node clear
			free(p);
			break;
		}
		scanf("%s", &(p->data.name));
		scanf("%d", &(p->data.cgrade));
		scanf("%d", &(p->data.mgrade));
		scanf("%d", &(p->data.egrade));
		p->data.total = p->data.cgrade + p->data.mgrade + p->data.egrade;
		p->data.ave = p->data.total / 3.0;
		p->data.mingci = 0;
		getchar();									// clear cache		
	}while (1);
	
	system("cls");
	switch(language) {
		case 0: { printf("Number of students: %d\n\n", --stuNum); break; }
		case 1: { printf("学生数量：%d\n\n", --stuNum); break; }
		case 2: { printf("一共录入咗 %d 个学生。\n\n", --stuNum); break; }		
	}
	
	return head;
}

// 2. Delete record by student's id
struct link *DeleteRecord(struct link *head) {
	char toDelete[MAXNUMLENGTH];
	struct link *p = head, *pr = head;
	system("cls");	
	if (head == NULL || stuNum == 0) {
		switch(language) {
			case 0: { printf("Database is empty.\n\n"); break; }
			case 1: { printf("木有数据。\n\n"); break; }
			case 2: { printf("未有数据。\n\n"); break; }		
		}
		return;
	}
	do {
		DisplayRecord(head, 0);
		switch(language) {
			case 0: { printf("Please input the ID/name of student to delete. To go back to main menu, input 0 then enter: "); break; }
			case 1: { printf("请输入要删除的学生的学号或姓名。欲返回主菜单，输入零并回车："); break; }
			case 2: { printf("你想删边个学号或者姓名嘅学生。假如想翻番主菜单，输入零然之后回车："); break; }		
		}
		scanf("%10s", &toDelete);
		getchar();									// clear cache
		if (strcmp(toDelete, "0")) {
			while (!(!strcmp(toDelete, p->data.num) || !strcmp(toDelete, p->data.name)) && p->next != NULL) {		// Not found and not to the end node
				pr = p;														// Save pointer of current node in pr
				p = p->next;
			}
			if ((strcmp(toDelete, p->data.num) == 0) || (strcmp(toDelete, p->data.name) == 0))	{						// Found data
				if (p == head) {											// Head must be treated seperately
					head = p->next;											// Point the head "next" to the next node of current node
				} else {
					pr->next = p->next;										// Point the previous "next" to the next node of current node
				}
				free(p);
				stuNum--;
				system("cls");
			} else {
				switch(language) {
					system("cls");
					case 0: { printf("╮(￣▽￣)╭ Student not found.\n\n"); break; }
					case 1: { printf("╮(￣▽￣)╭ 找不到这个学生。\n\n"); break; }
					case 2: { printf("╮(￣▽￣)╭ 揾唔到佢喔。\n\n"); break; }		
				}
			}
		} else {
			break;
		}
	} while (1);
	return head;
}

// 3. Search record by student's id
void SearchRecord(struct link *head) {
	char toSearch[MAXNUMLENGTH];
	struct link *p = head, *pr = head;
	if (head == NULL || stuNum == 0) {
		system("cls");
		switch(language) {
			case 0: { printf("Database is empty.\n\n"); break; }
			case 1: { printf("没有数据。\n\n"); break; }
			case 2: { printf("未有数据。\n\n"); break; }		
		}
		return;
	}
	switch(language) {
		case 0: { printf("Please input the ID/name of student to search: "); break; }
		case 1: { printf("请输入要寻找的学生的学号或姓名："); break; }
		case 2: { printf("你想揾边个学号或者姓名嘅学生："); break; }		
	}
	scanf("%10s", &toSearch);	
	while (!(!strcmp(toSearch, p->data.num) || !strcmp(toSearch, p->data.name)) && p->next != NULL) {		// Not found and not to the end node
		pr = p;														// Save pointer of current node in pr
		p = p->next;
	}
	if ((strcmp(toSearch, p->data.num) == 0) || (strcmp(toSearch, p->data.name) == 0))	{						// Found data
		system("cls");
		switch(language) {
			case 0: { printf("ID        : %15s\nName      : %15s\nC Language: %15d\nMath      : %15d\nEnglish   : %15d\nTotal     : %15d\nAverage   : %15.2f\nRank      : %15d\n\n", p->data.num, p->data.name, p->data.cgrade, p->data.mgrade, p->data.egrade, p->data.total, p->data.ave, p->data.mingci); break; }
			case 1: { printf("学号      : %15s\n姓名      : %15s\nC 语言    : %15d\n数学      : %15d\n英语      : %15d\n总分      : %15d\n平均分    : %15.2f\n排名      : %15d\n\n", p->data.num, p->data.name, p->data.cgrade, p->data.mgrade, p->data.egrade, p->data.total, p->data.ave, p->data.mingci); break; }
			case 2: { printf("学号      : %15s\n姓名      : %15s\nC 语言    : %15d\n数学      : %15d\n英语      : %15d\n总分      : %15d\n平均分    : %15.2f\n排名      : %15d\n\n", p->data.num, p->data.name, p->data.cgrade, p->data.mgrade, p->data.egrade, p->data.total, p->data.ave, p->data.mingci); break; }
		}
	} else {
		system("cls");
		switch(language) {
			case 0: { printf("╮(￣▽￣)╭ Student not found.\n\n"); break; }
			case 1: { printf("╮(￣▽￣)╭ 找不到这个学生。\n\n"); break; }
			case 2: { printf("╮(￣▽￣)╭ 揾唔到佢喔。\n\n"); break; }		
		}
	}
}

// 4. Modify record
void ModifyRecord(struct link *head) {
	char toModify[MAXNUMLENGTH];
	struct link *p = head, *pr = head;
	system("cls");
	if (head == NULL || stuNum == 0) {
		switch(language) {
			case 0: { printf("Database is empty.\n\n"); break; }
			case 1: { printf("没有数据。\n\n"); break; }
			case 2: { printf("未有数据。\n\n"); break; }		
		}
		return;
	}
	do {
		DisplayRecord(head, 0);
		switch(language) {
			case 0: { printf("Please input the ID/name of student to modify. To go back to main menu, input 0 then enter: "); break; }
			case 1: { printf("请输入要修改的学生的学号或姓名。欲返回主菜单，输入零并回车："); break; }
			case 2: { printf("历史冇得乱改，但系如果你喺输错咗，仲可以原谅。假如想翻番主菜单，输入零然之后回车："); break; }		
		}
		scanf("%10s", &toModify);
		getchar();									// clear cache
		if (strcmp(toModify, "0")) {
			while (!(!strcmp(toModify, p->data.num) || !strcmp(toModify, p->data.name)) && p->next != NULL) {		// Not found and not to the end node
				pr = p;														// Save pointer of current node in pr
				p = p->next;
			}
			if ((strcmp(toModify, p->data.num) == 0) || (strcmp(toModify, p->data.name) == 0))	{						// Found data
				switch(language) {
					case 0: { printf("Please input the student's information - StudentID, StudentName (without space), Grade of C Language, Grade of Math, Grade Of English in order (split by space): "); break; }
					case 1: { printf("请按顺序输入学生的学号、姓名（不含空格）、语文成绩、数学成绩、英语成绩，以空格区分："); break; }
					case 2: { printf("请顺住输入呢个学生嘅学号、姓名（唔可以有空格）、语文成绩、数学成绩、英语成绩，摞空格区分："); break; }			
				}
				// makeZeroChar(&((student+index)->name), MAXNAMELENGTH);		// Don't keep it ramdom.
				scanf("%s", &(p->data.num));
				scanf("%s", &(p->data.name));
				scanf("%d", &(p->data.cgrade));
				scanf("%d", &(p->data.mgrade));
				scanf("%d", &(p->data.egrade));
				p->data.total = p->data.cgrade + p->data.mgrade + p->data.egrade;
				p->data.ave = p->data.total / 3;
				getchar();													// clear cache
				system("cls");
			} else {
				system("cls");
				switch(language) {
					case 0: { printf("╮(￣▽￣)╭ Student not found.\n\n"); break; }
					case 1: { printf("╮(￣▽￣)╭ 找不到这个学生。\n\n"); break; }
					case 2: { printf("╮(￣▽￣)╭ 揾唔到佢喔。\n\n"); break; }		
				}
			}
		} else {
			break;
		}
	} while (1);
	system("cls");
}

// 5. Insert Record
void InsertRecord(struct link *head) {
	struct link *p = head, *pr = head;
	char temp[MAXNUMLENGTH];						// Input 0 to exit.
	system("cls");
	if (head == NULL || stuNum == 0) {
		switch(language) {
			case 0: { printf("Database is empty.\n\n"); break; }
			case 1: { printf("没有数据。\n\n"); break; }
			case 2: { printf("未有数据。\n\n"); break; }		
		}
		return;
	} 
	DisplayRecord(head, 1);	
	while (p->next != NULL) {						// Not to the end node
		pr = p;										// Save pointer of current node in pr
		p = p->next;
	}
	pr = p;															// Before allocating memory, save the old one
	// makeZeroChar(&((student+index)->name), MAXNAMELENGTH);		// Don't keep it ramdom.
	p = (struct link *)malloc(sizeof(struct link));					// Allocate new node
	if (p == NULL) {
		switch(language) {
			case 0: { printf(":-( Memory allocation failed. Please check your OS.\n"); break; }
			case 1: { printf(":-( 内存分配失败。请检查你的操作系统。\n"); break; }
			case 2: { printf(":-( 内存分配唔到。请检查下你嘅操作系统。\n"); break; }			
		}
		exit(0);
	}
	pr->next = p;													// Link the old one to the new one
	switch(language) {
		case 0: { printf("Please input the student's information - StudentID, StudentName (without space), Grade of C Language, Grade of Math, Grade Of English in order (split by space): "); break; }
		case 1: { printf("请按顺序输入学生的学号、姓名（不含空格）、语文成绩、数学成绩、英语成绩，以空格区分："); break; }
		case 2: { printf("请顺住输入新学生嘅学号、姓名（唔可以有空格）、语文成绩、数学成绩、英语成绩，摞空格区分："); break; }			
	}
	// makeZeroChar(&((student+index)->name), MAXNAMELENGTH);		// Don't keep it ramdom.
	scanf("%s", &(p->data.num));
	scanf("%s", &(p->data.name));
	scanf("%d", &(p->data.cgrade));
	scanf("%d", &(p->data.mgrade));
	scanf("%d", &(p->data.egrade));
	getchar();														// clear cache
	p->data.total = p->data.cgrade + p->data.mgrade + p->data.egrade;
	p->data.ave = p->data.total / 3;
	printf(" %8s | %8s | %6d | %6d | %7d | %6d | %7.2f \n", p->data.num, p->data.name, p->data.cgrade, p->data.mgrade, p->data.egrade, p->data.total, p->data.ave);
	stuNum++;
	p->next = NULL;
	system("cls");
	switch(language) {
		case 0: { printf("OK.\n\n"); break; }
		case 1: { printf("添加完成。\n\n"); break; }
		case 2: { printf("搞掂。\n\n"); break; }		
	}
}

// 6. Count Record
void CountRecord(struct link *head) {
	struct link *p = head, *pr;
	int s90[3]={0}, s80[3]={0}, s70[3]={0}, s60[3]={0}, s0[3]={0}, sum[3]={0}, rep = 0, temp;
	system("cls");
	if (head == NULL || stuNum == 0) {
		switch(language) {
			case 0: { printf("Database is empty.\n\n"); break; }
			case 1: { printf("没有数据。\n\n"); break; }
			case 2: { printf("未有数据。\n\n"); break; }		
		}
		return;
	}
	
	do {
		for (rep = 0; rep <= 3; rep++) {
			switch (rep) {
				case 0: { temp = p->data.cgrade; break; }
				case 1: { temp = p->data.mgrade; break; }
				case 2: { temp = p->data.egrade; break; }
			}
			sum[rep] += temp;
			switch (temp / 10) {
				case 10: {}
				case 9:  { s90[rep]++; break; }
				case 8:  { s80[rep]++; break; }
				case 7:  { s70[rep]++; break; }
				case 6:  { s60[rep]++; break; }
				case 5:  {}
				case 4:  {}
				case 3:  {}
				case 2:  {}
				case 1:  {}
				case 0:  { s0[rep]++;  break; }
				default: {             break; }
			}
		}
		pr = p;										// Save pointer of current node in pr
		p = p->next;
	} while (pr->next != NULL);		// Not to the end node

	printf("          ");
	switch(language) {
		case 0: { printf("-C lang- --Math-- -English-"); break; }
		case 1: { printf("-C 语言- --数学-- --英语---"); break; }
		case 2: { printf("-C 语言- --数学-- --英语---"); break; }		
	}
	switch(language) { case 0: { printf("\nExcellent: "); break; } case 1: { printf("\n优秀     : "); break; } case 2: { printf("\n优秀     : "); break; } }
	for (rep = 0; rep < 3; rep++) { printf("%6d | ", s90[rep]); }
	switch(language) { case 0: { printf("\nGood     : "); break; } case 1: { printf("\n良好     : "); break; } case 2: { printf("\n良好     : "); break; } }
	for (rep = 0; rep < 3; rep++) { printf("%6d | ", s80[rep]); }
	switch(language) { case 0: { printf("\nNormal   : "); break; } case 1: { printf("\n中等     : "); break; } case 2: { printf("\n中等     : "); break; } }
	for (rep = 0; rep < 3; rep++) { printf("%6d | ", s80[rep]); }
	switch(language) { case 0: { printf("\nPassed   : "); break; } case 1: { printf("\n及格     : "); break; } case 2: { printf("\n合格     : "); break; } }
	for (rep = 0; rep < 3; rep++) { printf("%6d | ", s60[rep]); }
	switch(language) { case 0: { printf("\nFailed   : "); break; } case 1: { printf("\n不及格   : "); break; } case 2: { printf("\n挂科     : "); break; } }
	for (rep = 0; rep < 3; rep++) { printf("%6d | ", s0[rep]); }
	switch(language) { case 0: { printf("\nTotal    : "); break; } case 1: { printf("\n总分     : "); break; } case 2: { printf("\n总分     : "); break; } }
	for (rep = 0; rep < 3; rep++) { printf("%6d | ", sum[rep]); }
	switch(language) { case 0: { printf("\nAverage  : "); break; } case 1: { printf("\n平均分   : "); break; } case 2: { printf("\n平均分   : "); break; } }
	for (rep = 0; rep < 3; rep++) { printf("%6.2f | ", sum[rep] / 3.0); }
	putchar(10);
	putchar(10);
}

// Swapper
void Swap(struct link *stuA, struct link *stuB) {
	char temp_num[MAXNUMLENGTH];
	char temp_name[MAXNAMELENGTH];
	int temp_cgrade;
	int temp_mgrade;
	int temp_egrade;
	int temp_total;
	int temp_ave;
	printf("Swapping: %s (%d), %s (%d)\n", stuA->data.num, stuA->data.total, stuB->data.num, stuB->data.total);

	strcpy(temp_num, stuA->data.num);
	strcpy(temp_name, stuA->data.name);
	temp_cgrade = stuA->data.cgrade;
	temp_mgrade = stuA->data.mgrade;
	temp_egrade = stuA->data.egrade;
	temp_ave = stuA->data.ave;
	temp_total = stuA->data.total;
	
	strcpy(stuA->data.num, stuB->data.num);
	strcpy(stuA->data.name, stuB->data.name);
	stuA->data.cgrade = stuB->data.cgrade;
	stuA->data.mgrade = stuB->data.mgrade;
	stuA->data.egrade = stuB->data.egrade;
	stuA->data.total = stuB->data.total;
	stuA->data.ave = stuB->data.ave;

	strcpy(stuB->data.num, temp_num);
	strcpy(stuB->data.name, temp_name);
	stuB->data.cgrade = temp_cgrade;
	stuB->data.mgrade = temp_mgrade;
	stuB->data.egrade = temp_egrade;
	stuB->data.total = temp_total;
	stuB->data.ave = temp_ave;
}

// Read by index
struct link *ReadByIndex(struct link *head, int index) {
	struct link *p = head;
	int	i;
	if (head == NULL || stuNum == 0) {
		return NULL;
	}
	for (i = 0; i < index; i++) {
		p = p->next;
	}
	return p;
}

// 7. Sort Record
void SortRecord(struct link *head) {
	struct link *p_i, *p_j;
	int i, j;
	// system("cls");
	if (head == NULL || stuNum == 0) {
		switch(language) {
			case 0: { printf("Database is empty.\n\n"); break; }
			case 1: { printf("没有数据。\n\n"); break; }
			case 2: { printf("未有数据。\n\n"); break; }		
		}
		return;
	}

	for (i = 0; i < stuNum - 1; i++) {
		for (j = i + 1; j < stuNum; j++) {
			p_i = ReadByIndex(head, i);
			p_j = ReadByIndex(head, j);
			if (p_i->data.total < p_j->data.total) {
				Swap(p_i, p_j);
			}
		}
	}
	DisplayRecord(head, 1);
}
	
// 8. Save Record
void SaveRecord(struct link *head) {
	struct link *p = head, *pr;
	FILE *fp;
	char buffer[128];
	system("cls");
	if (head == NULL || stuNum == 0) {
		switch(language) {
			case 0: { printf("Database is empty.\n\n"); break; }
			case 1: { printf("没有数据。\n\n"); break; }
			case 2: { printf("未有数据。\n\n"); break; }		
		}
		return;
	}
	if ((fp = fopen("StudentRecord.txt","w")) != NULL) {
		
		switch(language) {
			case 0: { fprintf(fp, "----ID----|---Name---|-C lang-|--Math--|-English-|-Total--|-Average-"); break; }
			case 1: { fprintf(fp, "---学号---|---姓名---|-C 语言-|--数学--|--英语---|--总分--|--平均分-"); break; }
			case 2: { fprintf(fp, "---学号---|---姓名---|-C 语言-|--数学--|--英语---|--总分--|--平均分-"); break; }		
		}
		fputc(10, fp);

		do {
			fprintf(fp, " %8s | %8s | %6d | %6d | %7d | %6d | %7.2f \n", p->data.num, p->data.name, p->data.cgrade, p->data.mgrade, p->data.egrade, p->data.total, p->data.ave);
			pr = p;										// Save pointer of current node in pr
			p = p->next;
		} while (pr->next != NULL);		// Not to the end node
		fputc(10, fp);

		fclose(fp);
		switch(language) {
			case 0: { printf("Data saved in \"StudentRecord.txt\" in current directory.\n\n"); break; }
			case 1: { printf("数据已保存至当前目录下的 \"StudentRecord.txt\" 文件内。\n\n"); break; }
			case 2: { printf("数据保存咗喺宜家呢个目录入边嘅 \"StudentRecord.txt\" 文件入边。\n\n"); break; }		
		}
	} else {
		switch(language) {
			case 0: { printf("Sorry. Fail to open file.\n\n"); break; }
			case 1: { printf("抱歉，文件打开失败。\n\n"); break; }
			case 2: { printf("唔好意思，个文件开唔到。\n\n"); break; }			
		}
	}	
}

// Read Record
struct link *ReadRecord(struct link *head) {
	struct link *p = NULL, *pr = head;
	FILE *fp;
	char buffer[72];
	char temp[5][10];
	system("cls");
	stuNum = 0;
	if ((fp = fopen("StudentRecord.txt","r")) != NULL) {
		fgets(buffer, 72, fp);							// First line is useless
		//fscanf(fp, "%s", buffer);fscanf(fp, "%s", buffer);
		printf("%s\ndone\n", buffer);
		do{													// Input information of every student
			stuNum++;
			pr = p;															// Before allocating memory, save the old one
			// makeZeroChar(&((student+index)->name), MAXNAMELENGTH);		// Don't keep it ramdom.
			p = (struct link *)malloc(sizeof(struct link));					// Allocate new node
			if (p == NULL) {
				switch(language) {
					case 0: { printf(":-( Memory allocation failed. Please check your OS.\n"); break; }
					case 1: { printf(":-( 内存分配失败。请检查你的操作系统。\n"); break; }
					case 2: { printf(":-( 内存分配唔到。请检查下你嘅操作系统。\n"); break; }			
				}
				exit(0);
			}
			if (stuNum == 1) {
				head = p;
				pr = p;														// There is nothing in pr
			}
			pr->next = p;													// Point old node's "next" to new node
			if (fscanf(fp, "%9s |%9s |%7s |%7s |%7s |%7s |%8s ", &(p->data.num), &(p->data.name), temp[0], temp[1], temp[2], temp[3], temp[4]) != EOF) {
				p->data.cgrade = atoi(temp[0]);
				p->data.mgrade = atoi(temp[1]);
				p->data.egrade = atoi(temp[2]);
				p->data.total = atoi(temp[3]);
				p->data.ave = atof(temp[4]);
			} else {
				printf("NULL\n");
				pr->next = NULL;											// Make the next node of the old node clear
				free(p);
				stuNum--;
				break;				
			}
		}while (1);
	} else {
		switch(language) {
			case 0: { printf("Sorry. Fail to open file.\n\n"); break; }
			case 1: { printf("抱歉，文件打开失败。\n\n"); break; }
			case 2: { printf("唔好意思，个文件开唔到。\n\n"); break; }			
		}
	}
	return head;
}

// 9. Display Record
void DisplayRecord(struct link *head, int ClearScreen) {
	struct link *p = head, *pr;
	if (ClearScreen) system("cls");
	if (head == NULL || stuNum == 0) {
		switch(language) {
			case 0: { printf("Database is empty.\n\n"); break; }
			case 1: { printf("没有数据。\n\n"); break; }
			case 2: { printf("未有数据。\n\n"); break; }		
		}
		return;
	}
	
	switch(language) {
		case 0: { printf("----ID----|---Name---|-C lang-|--Math--|-English-|-Total--|-Average-"); break; }
		case 1: { printf("---学号---|---姓名---|-C 语言-|--数学--|--英语---|--总分--|--平均分-"); break; }
		case 2: { printf("---学号---|---姓名---|-C 语言-|--数学--|--英语---|--总分--|--平均分-"); break; }		
	}
	putchar(10);
	do {
		printf(" %8s | %8s | %6d | %6d | %7d | %6d | %7.2f \n", p->data.num, p->data.name, p->data.cgrade, p->data.mgrade, p->data.egrade, p->data.total, p->data.ave);
		pr = p;										// Save pointer of current node in pr
		p = p->next;
	} while (pr->next != NULL);		// Not to the end node
	putchar(10);
}

int main()
{
	int selection;
	char temp;						// yes or no
	int isExit = 0;					// a flag
	struct link *head = NULL;		// Head is the entry of our data
	FILE *fp = NULL;
	
	printf("学生成绩管理系统 V7.0 date: 20180620\n\nSelect language:\n");
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
	if ((fp = fopen("StudentRecord.txt","r")) != NULL) {		// Found data.
		do {
			switch(language) {
				case 0: { printf("You have previously saved your data here. Read it? [Y/N] "); break; }
				case 1: { printf("您此前已在此处保存数据。是否读取？[Y/N] "); break; }
				case 2: { printf("你之前喺??度已经存过档。系咪要读翻佢？[Y/N] "); break; }
			}
			gets(&temp);
			if (temp == *"Y" || temp == *"y") { head = ReadRecord(head); break; }
			else if (&temp == "N" || temp == *"n") { system("cls"); break; }
		} while(1);
	}
	
	system("cls");
	printf("学生成绩管理系统 V7.0 date: 20180620\n\n");
	
	do{
		selection = -1;				// function selection
		switch(language) {
			case 0: {
				printf("The Student's Grade Management System\n");
				printf("%s", "╔═══════════════════════════════════════════════════════════════╗\n");
				printf("%-64s ║\n", "╠   1. Input   record");
				printf("%-64s ║\n", "╠   2. Delete  record");
				printf("%-64s ║\n", "╠   3. Search  record");
				printf("%-64s ║\n", "╠   4. Modify  record");
				printf("%-64s ║\n", "╠   5. Insert  record");
				printf("%-64s ║\n", "╠   6. Count   record");
				printf("%-64s ║\n", "╠   7. Sort    record");
				printf("%-64s ║\n", "╠   8. Save    record");
				printf("%-64s ║\n", "╠   9. Display record");
				printf("%-64s ║\n", "╠   0. Quit    system");
				printf("%s", "╚═══════════════════════════════════════════════════════════════╝\n");
				printf("Please enter your choice: ");
				break;
			}
			case 1: {
				printf("学生成绩管理系统\n");
				printf("%s", "╔═══════════════════════════════════════════════╗\n");
				printf("%-48s ║\n", "╠   1. 输入记录");
				printf("%-48s ║\n", "╠   2. 删除记录");
				printf("%-48s ║\n", "╠   3. 搜索记录");
				printf("%-48s ║\n", "╠   4. 修改记录");
				printf("%-48s ║\n", "╠   5. 插入记录");
				printf("%-48s ║\n", "╠   6. 统计记录");
				printf("%-48s ║\n", "╠   7. 排序记录");
				printf("%-48s ║\n", "╠   8. 保存记录");
				printf("%-48s ║\n", "╠   9. 显示记录");
				printf("%-48s ║\n", "╠   0. 退出系统");
				printf("%s", "╚═══════════════════════════════════════════════╝\n");
				printf("请输入您的选择：");
				break;
			}
			case 2: {
				printf("学生成绩管理系统\n");
				printf("%s", "╔═══════════════════════════════════════════════╗\n");
				printf("%-48s ║\n", "╠   1. 输入记录");
				printf("%-48s ║\n", "╠   2. 删除记录");
				printf("%-48s ║\n", "╠   3. 搜索记录");
				printf("%-48s ║\n", "╠   4. 修改记录");
				printf("%-48s ║\n", "╠   5. 插入记录");
				printf("%-48s ║\n", "╠   6. 统计记录");
				printf("%-48s ║\n", "╠   7. 排序记录");
				printf("%-48s ║\n", "╠   8. 保存记录");
				printf("%-48s ║\n", "╠   9. 显示记录");
				printf("%-48s ║\n", "╠   0. 走佬");
				printf("%s", "╚═══════════════════════════════════════════════╝\n");
				printf("你想点呢：");
				break;
			}
		}
		scanf("%d", &selection);
		getchar();					// clear cache
		switch(selection) {
			case 1:									// 1. Input record
				head = InputRecord(head);
				break;
			case 2:									// 2. Delete record by student's id
				head = DeleteRecord(head);
				break;
			case 3:									// 3. Search record by student's id
				SearchRecord(head);
				break;
			case 4:									// 4. Modify record
				ModifyRecord(head);
				break;
			case 5:									// 5. Insert record
				InsertRecord(head);
				break;
			case 6:									// 6. Count record
				CountRecord(head);
				break;
			case 7:									// 7. Sort record by total
				SortRecord(head);
				break;
			case 8:									// 8. Save record into txt file
				SaveRecord(head);
				break;
			case 9:									// 9. Display Record
				DisplayRecord(head, 1);
				break;
			case 0:
				isExit = 1;
				system("cls");
				printf("%s", byebye);
				break;
			case -1:
			default:
				system("cls");
				switch(language) {
					case 0: { printf("Hey, guy! Your input is unvalidated. Please input again.\n\n"); }
					case 1: { printf("您的选择不正确噢，请重新输入。\n\n"); }
					case 2: { printf("滴错掣啦，重新输多次啦。"); break; }		
				}
				break;
		}
	}while(!isExit);
	system("pause");
	return 0;
}
