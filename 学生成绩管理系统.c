// 1711640118 Ҷ����

#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#define MAXNUMLENGTH 18
#define MAXNAMELENGTH 18

const char byebye[] = "\
������������������������������������������������������������������������\n\
��������       ������  ��������  ����        ��������\n\
������������������������������������������������������������������������\n\
������������������������������������������������������������������������\n\
������������������������������������������������������������������������\n\
������������������������������������������������������������������������\n\
������������������������������������������������������������������������\n\
������������������������������������������������������������������������\n\
������������������������������������������������������������������������\n\
��������       ������  ��������  ����        ��������\n\
��������       ������  ��������  ����        ��������\n\
������������������������������������������������������������������������\n\
������������������������������������������������������������������������\n\
������������������������������������������������������������������������\n\
������������������������������������������������������������������������\n\
������������������������������������������������������������������������\n\
������������������������������������������������������������������������\n\
������������������������������������������������������������������������\n\
��������       ������  ��������  ����        ��������\n\
������������������������������������������������������������������������\n\n\
";

struct student
{
	char num[MAXNUMLENGTH];   	/*ѧ��*/
	char name[MAXNAMELENGTH];  	/*����*/
	int cgrade;     			/*C���Գɼ�*/
	int mgrade;     			/*��ѧ�ɼ�*/
	int egrade;     			/*Ӣ��ɼ�*/
	int total;      			/*�ܷ�*/
	float ave;      			/*ƽ����*/
	int mingci;     			/*����*/
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
				case 1: { printf("\n����ǰ�Ѿ�����������ˡ��Ƿ�Ҫ��ղ��������룿\n����ǣ������� Y ���س�\n�������� N ����������¼ģ�顣\n����ѡ���ǣ�"); break; }
				case 2: { printf("\n��֮ǰ�Ѿ���������ݿ�ร�ϵ��Ҫ��ղ����������룿����գ������� Y Ȼ֮��س�\n��ϵ���������� N Ȼ֮���������¼ģ�顣\n������أ�\n\n"); break; }
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
		case 1: { printf("\n�밴˳������ѧ��ѧ�š�ѧ�������������ո񣩡����ĳɼ�����ѧ�ɼ���Ӣ��ɼ����Կո����֡����ո����ȷ�ϡ����� 0 ���س��Խ�����\n\n"); break; }
		case 2: { printf("\n��˳ס����ѧ��ѧ�š�ѧ��������������пո񣩡����ĳɼ�����ѧ�ɼ���Ӣ��ɼ������ո����֡��οո�������һ�������� 0 Ȼ֮��س��Ϳ��Խ�����\n\n"); break; }
	}
	do{												// Input information of every student
		switch(language) {
			case 0: { printf("Please input the No.%d student's information: ", ++stuNum); break; }
			case 1: { printf("������� %d ��ѧ������Ϣ��", ++stuNum); break; }
			case 2: { printf("�ն������ %d ��ѧ������Ϣ��", ++stuNum); break; }
		}
		pr = p;															// Before allocating memory, save the old one
		// makeZeroChar(&((student+index)->name), MAXNAMELENGTH);		// Don't keep it ramdom.
		p = (struct link *)malloc(sizeof(struct link));					// Allocate new node
		if (p == NULL) {
			switch(language) {
				case 0: { printf(":-( Memory allocation failed. Please check your OS.\n"); break; }
				case 1: { printf(":-( �ڴ����ʧ�ܡ�������Ĳ���ϵͳ��\n"); break; }
				case 2: { printf(":-( �ڴ���������������������ϵͳ��\n"); break; }			
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
		case 1: { printf("ѧ��������%d\n\n", --stuNum); break; }
		case 2: { printf("һ��¼��� %d ��ѧ����\n\n", --stuNum); break; }		
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
			case 1: { printf("ľ�����ݡ�\n\n"); break; }
			case 2: { printf("δ�����ݡ�\n\n"); break; }		
		}
		return;
	}
	do {
		DisplayRecord(head, 0);
		switch(language) {
			case 0: { printf("Please input the ID/name of student to delete. To go back to main menu, input 0 then enter: "); break; }
			case 1: { printf("������Ҫɾ����ѧ����ѧ�Ż����������������˵��������㲢�س���"); break; }
			case 2: { printf("����ɾ�߸�ѧ�Ż���������ѧ���������뷭�����˵���������Ȼ֮��س���"); break; }		
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
					case 0: { printf("�r(������)�q Student not found.\n\n"); break; }
					case 1: { printf("�r(������)�q �Ҳ������ѧ����\n\n"); break; }
					case 2: { printf("�r(������)�q �h����ม�\n\n"); break; }		
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
			case 1: { printf("û�����ݡ�\n\n"); break; }
			case 2: { printf("δ�����ݡ�\n\n"); break; }		
		}
		return;
	}
	switch(language) {
		case 0: { printf("Please input the ID/name of student to search: "); break; }
		case 1: { printf("������ҪѰ�ҵ�ѧ����ѧ�Ż�������"); break; }
		case 2: { printf("����h�߸�ѧ�Ż���������ѧ����"); break; }		
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
			case 1: { printf("ѧ��      : %15s\n����      : %15s\nC ����    : %15d\n��ѧ      : %15d\nӢ��      : %15d\n�ܷ�      : %15d\nƽ����    : %15.2f\n����      : %15d\n\n", p->data.num, p->data.name, p->data.cgrade, p->data.mgrade, p->data.egrade, p->data.total, p->data.ave, p->data.mingci); break; }
			case 2: { printf("ѧ��      : %15s\n����      : %15s\nC ����    : %15d\n��ѧ      : %15d\nӢ��      : %15d\n�ܷ�      : %15d\nƽ����    : %15.2f\n����      : %15d\n\n", p->data.num, p->data.name, p->data.cgrade, p->data.mgrade, p->data.egrade, p->data.total, p->data.ave, p->data.mingci); break; }
		}
	} else {
		system("cls");
		switch(language) {
			case 0: { printf("�r(������)�q Student not found.\n\n"); break; }
			case 1: { printf("�r(������)�q �Ҳ������ѧ����\n\n"); break; }
			case 2: { printf("�r(������)�q �h����ม�\n\n"); break; }		
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
			case 1: { printf("û�����ݡ�\n\n"); break; }
			case 2: { printf("δ�����ݡ�\n\n"); break; }		
		}
		return;
	}
	do {
		DisplayRecord(head, 0);
		switch(language) {
			case 0: { printf("Please input the ID/name of student to modify. To go back to main menu, input 0 then enter: "); break; }
			case 1: { printf("������Ҫ�޸ĵ�ѧ����ѧ�Ż����������������˵��������㲢�س���"); break; }
			case 2: { printf("��ʷ�ӵ��Ҹģ���ϵ�������������ٿ���ԭ�¡������뷭�����˵���������Ȼ֮��س���"); break; }		
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
					case 1: { printf("�밴˳������ѧ����ѧ�š������������ո񣩡����ĳɼ�����ѧ�ɼ���Ӣ��ɼ����Կո����֣�"); break; }
					case 2: { printf("��˳ס�����ظ�ѧ����ѧ�š�������������пո񣩡����ĳɼ�����ѧ�ɼ���Ӣ��ɼ������ո����֣�"); break; }			
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
					case 0: { printf("�r(������)�q Student not found.\n\n"); break; }
					case 1: { printf("�r(������)�q �Ҳ������ѧ����\n\n"); break; }
					case 2: { printf("�r(������)�q �h����ม�\n\n"); break; }		
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
			case 1: { printf("û�����ݡ�\n\n"); break; }
			case 2: { printf("δ�����ݡ�\n\n"); break; }		
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
			case 1: { printf(":-( �ڴ����ʧ�ܡ�������Ĳ���ϵͳ��\n"); break; }
			case 2: { printf(":-( �ڴ���������������������ϵͳ��\n"); break; }			
		}
		exit(0);
	}
	pr->next = p;													// Link the old one to the new one
	switch(language) {
		case 0: { printf("Please input the student's information - StudentID, StudentName (without space), Grade of C Language, Grade of Math, Grade Of English in order (split by space): "); break; }
		case 1: { printf("�밴˳������ѧ����ѧ�š������������ո񣩡����ĳɼ�����ѧ�ɼ���Ӣ��ɼ����Կո����֣�"); break; }
		case 2: { printf("��˳ס������ѧ����ѧ�š�������������пո񣩡����ĳɼ�����ѧ�ɼ���Ӣ��ɼ������ո����֣�"); break; }			
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
		case 1: { printf("�����ɡ�\n\n"); break; }
		case 2: { printf("��ࡣ\n\n"); break; }		
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
			case 1: { printf("û�����ݡ�\n\n"); break; }
			case 2: { printf("δ�����ݡ�\n\n"); break; }		
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
		case 1: { printf("-C ����- --��ѧ-- --Ӣ��---"); break; }
		case 2: { printf("-C ����- --��ѧ-- --Ӣ��---"); break; }		
	}
	switch(language) { case 0: { printf("\nExcellent: "); break; } case 1: { printf("\n����     : "); break; } case 2: { printf("\n����     : "); break; } }
	for (rep = 0; rep < 3; rep++) { printf("%6d | ", s90[rep]); }
	switch(language) { case 0: { printf("\nGood     : "); break; } case 1: { printf("\n����     : "); break; } case 2: { printf("\n����     : "); break; } }
	for (rep = 0; rep < 3; rep++) { printf("%6d | ", s80[rep]); }
	switch(language) { case 0: { printf("\nNormal   : "); break; } case 1: { printf("\n�е�     : "); break; } case 2: { printf("\n�е�     : "); break; } }
	for (rep = 0; rep < 3; rep++) { printf("%6d | ", s80[rep]); }
	switch(language) { case 0: { printf("\nPassed   : "); break; } case 1: { printf("\n����     : "); break; } case 2: { printf("\n�ϸ�     : "); break; } }
	for (rep = 0; rep < 3; rep++) { printf("%6d | ", s60[rep]); }
	switch(language) { case 0: { printf("\nFailed   : "); break; } case 1: { printf("\n������   : "); break; } case 2: { printf("\n�ҿ�     : "); break; } }
	for (rep = 0; rep < 3; rep++) { printf("%6d | ", s0[rep]); }
	switch(language) { case 0: { printf("\nTotal    : "); break; } case 1: { printf("\n�ܷ�     : "); break; } case 2: { printf("\n�ܷ�     : "); break; } }
	for (rep = 0; rep < 3; rep++) { printf("%6d | ", sum[rep]); }
	switch(language) { case 0: { printf("\nAverage  : "); break; } case 1: { printf("\nƽ����   : "); break; } case 2: { printf("\nƽ����   : "); break; } }
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
			case 1: { printf("û�����ݡ�\n\n"); break; }
			case 2: { printf("δ�����ݡ�\n\n"); break; }		
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
			case 1: { printf("û�����ݡ�\n\n"); break; }
			case 2: { printf("δ�����ݡ�\n\n"); break; }		
		}
		return;
	}
	if ((fp = fopen("StudentRecord.txt","w")) != NULL) {
		
		switch(language) {
			case 0: { fprintf(fp, "----ID----|---Name---|-C lang-|--Math--|-English-|-Total--|-Average-"); break; }
			case 1: { fprintf(fp, "---ѧ��---|---����---|-C ����-|--��ѧ--|--Ӣ��---|--�ܷ�--|--ƽ����-"); break; }
			case 2: { fprintf(fp, "---ѧ��---|---����---|-C ����-|--��ѧ--|--Ӣ��---|--�ܷ�--|--ƽ����-"); break; }		
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
			case 1: { printf("�����ѱ�������ǰĿ¼�µ� \"StudentRecord.txt\" �ļ��ڡ�\n\n"); break; }
			case 2: { printf("���ݱ�������˼��ظ�Ŀ¼��߆� \"StudentRecord.txt\" �ļ���ߡ�\n\n"); break; }		
		}
	} else {
		switch(language) {
			case 0: { printf("Sorry. Fail to open file.\n\n"); break; }
			case 1: { printf("��Ǹ���ļ���ʧ�ܡ�\n\n"); break; }
			case 2: { printf("�����˼�����ļ�������\n\n"); break; }			
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
					case 1: { printf(":-( �ڴ����ʧ�ܡ�������Ĳ���ϵͳ��\n"); break; }
					case 2: { printf(":-( �ڴ���������������������ϵͳ��\n"); break; }			
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
			case 1: { printf("��Ǹ���ļ���ʧ�ܡ�\n\n"); break; }
			case 2: { printf("�����˼�����ļ�������\n\n"); break; }			
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
			case 1: { printf("û�����ݡ�\n\n"); break; }
			case 2: { printf("δ�����ݡ�\n\n"); break; }		
		}
		return;
	}
	
	switch(language) {
		case 0: { printf("----ID----|---Name---|-C lang-|--Math--|-English-|-Total--|-Average-"); break; }
		case 1: { printf("---ѧ��---|---����---|-C ����-|--��ѧ--|--Ӣ��---|--�ܷ�--|--ƽ����-"); break; }
		case 2: { printf("---ѧ��---|---����---|-C ����-|--��ѧ--|--Ӣ��---|--�ܷ�--|--ƽ����-"); break; }		
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
	
	printf("ѧ���ɼ�����ϵͳ V7.0 date: 20180620\n\nSelect language:\n");
	do {
		printf("[ a. English ] [ b. ���� ] [ c. ��������棩 ] : ");
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
				case 1: { printf("����ǰ���ڴ˴��������ݡ��Ƿ��ȡ��[Y/N] "); break; }
				case 2: { printf("��֮ǰ��??���Ѿ��������ϵ��Ҫ�����ڣ�[Y/N] "); break; }
			}
			gets(&temp);
			if (temp == *"Y" || temp == *"y") { head = ReadRecord(head); break; }
			else if (&temp == "N" || temp == *"n") { system("cls"); break; }
		} while(1);
	}
	
	system("cls");
	printf("ѧ���ɼ�����ϵͳ V7.0 date: 20180620\n\n");
	
	do{
		selection = -1;				// function selection
		switch(language) {
			case 0: {
				printf("The Student's Grade Management System\n");
				printf("%s", "�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
				printf("%-64s �U\n", "�d   1. Input   record");
				printf("%-64s �U\n", "�d   2. Delete  record");
				printf("%-64s �U\n", "�d   3. Search  record");
				printf("%-64s �U\n", "�d   4. Modify  record");
				printf("%-64s �U\n", "�d   5. Insert  record");
				printf("%-64s �U\n", "�d   6. Count   record");
				printf("%-64s �U\n", "�d   7. Sort    record");
				printf("%-64s �U\n", "�d   8. Save    record");
				printf("%-64s �U\n", "�d   9. Display record");
				printf("%-64s �U\n", "�d   0. Quit    system");
				printf("%s", "�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
				printf("Please enter your choice: ");
				break;
			}
			case 1: {
				printf("ѧ���ɼ�����ϵͳ\n");
				printf("%s", "�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
				printf("%-48s �U\n", "�d   1. �����¼");
				printf("%-48s �U\n", "�d   2. ɾ����¼");
				printf("%-48s �U\n", "�d   3. ������¼");
				printf("%-48s �U\n", "�d   4. �޸ļ�¼");
				printf("%-48s �U\n", "�d   5. �����¼");
				printf("%-48s �U\n", "�d   6. ͳ�Ƽ�¼");
				printf("%-48s �U\n", "�d   7. �����¼");
				printf("%-48s �U\n", "�d   8. �����¼");
				printf("%-48s �U\n", "�d   9. ��ʾ��¼");
				printf("%-48s �U\n", "�d   0. �˳�ϵͳ");
				printf("%s", "�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
				printf("����������ѡ��");
				break;
			}
			case 2: {
				printf("ѧ���ɼ�����ϵͳ\n");
				printf("%s", "�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
				printf("%-48s �U\n", "�d   1. �����¼");
				printf("%-48s �U\n", "�d   2. ɾ����¼");
				printf("%-48s �U\n", "�d   3. ������¼");
				printf("%-48s �U\n", "�d   4. �޸ļ�¼");
				printf("%-48s �U\n", "�d   5. �����¼");
				printf("%-48s �U\n", "�d   6. ͳ�Ƽ�¼");
				printf("%-48s �U\n", "�d   7. �����¼");
				printf("%-48s �U\n", "�d   8. �����¼");
				printf("%-48s �U\n", "�d   9. ��ʾ��¼");
				printf("%-48s �U\n", "�d   0. ����");
				printf("%s", "�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
				printf("������أ�");
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
					case 1: { printf("����ѡ����ȷ�ޣ����������롣\n\n"); }
					case 2: { printf("�δ�����������������"); break; }		
				}
				break;
		}
	}while(!isExit);
	system("pause");
	return 0;
}
