// 1711640118 Ҷ����

#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#define MAXSTU 1024
#define MAXNAMELENGTH 18
#define MAXPHONELENGTH 18
#define MAXQQLENGTH 18

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
				case 1: { printf("\n����ǰ�Ѿ�����������ˡ��Ƿ�Ҫ��ղ��������룿\n����ǣ������� Y ���س�\n�������� N �������������ģ�顣\n����ѡ���ǣ�"); break; }
				case 2: { printf("\n��֮ǰ�Ѿ���������ݿ�ร�ϵ��Ҫ��ղ����������룿����գ������� Y Ȼ֮��س�\n��ϵ���������� N Ȼ֮������������ģ�顣\n������أ�\n\n"); break; }
			}
			gets(&temp);
			if (temp == *"Y" || temp == *"y") { system("cls"); break; }
			else if (&temp == "N" || temp == *"n") { system("cls"); return; break; }
		} while(1);
	}
	switch(language) {
		case 0: { printf("\nPlease enter Name (without space) in order (split by space). Press Enter to confirm.\nMaximum storage is 1024 students. Input 0 and enter to finish.\n\n"); break; }
		case 1: { printf("\n�밴˳�����������������ո񣩡��绰��QQ���Կո����֡����ո����ȷ�ϡ����洢����Ϊ 1024 ��ѧ�������� 0 ���س��Խ�����"); break; }
		case 2: { printf("\n��˳ס����������������пո񣩡��绰��QQ�����ո����֡��οո�������һ�������װ���� 1024 ��ѧ�������� 0 Ȼ֮��س��Ϳ��Խ�����\n\n"); break; }
	}
	putchar(10);
	do{												// Input information
		switch(language) {
			case 0: { printf("Please input the No.%d person's information: ", index + 1); break; }
			case 1: { printf("������� %d ���˵���Ϣ��", index + 1); break; }
			case 2: { printf("�ն������ %d ���ˆ���Ϣ��", index + 1); break; }			
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
		case 1: { printf("��Ա������%d\n\n", index); break; }
		case 2: { printf("һ��¼��� %d ���ˡ�\n\n", index); break; }		
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
		case 1: { printf("---���---|---����---|-�绰����-|----QQ---"); break; }
		case 2: { printf("---���---|---����---|-�绰����-|----QQ---"); break; }		
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
			case 1: { printf("����ѧ������/�绰/QQ���س������������˵��������㲢�س���"); break; }
			case 2: { printf("����ѧ��������/�绰/QQȻ��س��������뷭�����˵���������Ȼ֮��س���"); break; }			
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
						case 1: { printf("�Ҳ�������� :-(�����������롣\n\n"); break; }
						case 2: { printf("�h�������ѡ�������������� :-)��\n\n"); break; }						
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
			case 1: { printf("����ѧ������/�绰/QQ���س������������˵��������㲢�س���"); break; }
			case 2: { printf("����ѧ��������/�绰/QQȻ��س��������뷭�����˵���������Ȼ֮��س���"); break; }			
		}
		scanf("%s", &toFind);
		getchar();									// clear cache
		if (strcmp(toFind, "0")) {
			do {
				if (!strcmp((student+index)->name, toFind) || !strcmp((student+index)->phone, toFind) || !strcmp((student+index)->qq, toFind)) {
					DisplayRecord(student, stuNum, 1);
					switch(language) {
						case 0: { printf("ID        : %8d\nname      : %8s\nphone     : %8s\nQQ        : %8s\n", (student+index)->ID, (student+index)->name, (student+index)->phone, (student+index)->qq); break; }
						case 1: { printf("���      : %8d\n����      : %8s\n�绰      : %8s\nQQ        : %8s\n", (student+index)->ID, (student+index)->name, (student+index)->phone, (student+index)->qq); break; }						
						case 2: { printf("���      : %8d\n����      : %8s\n�绰      : %8s\nQQ        : %8s\n", (student+index)->ID, (student+index)->name, (student+index)->phone, (student+index)->qq); break; }						
					}
					putchar(10);
					index = 0;
					break;
				}
				else if (index == stuNum) {
					switch(language) {
						case 0: { printf("Couldn't find this person :-(. Please re-input.\n\n"); break; }
						case 1: { printf("�Ҳ�������� :-(�����������롣\n\n"); break; }
						case 2: { printf("�h�������ѡ�������������� :-)��\n\n"); break; }						
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
		case 1: { printf("����ѧ������/�绰/QQ���س������������˵��������㲢�س���"); break; }
		case 2: { printf("����ѧ��������/�绰/QQȻ��س��������뷭�����˵���������Ȼ֮��س���"); break; }			
		}
		scanf("%s", &toFind);
		getchar();									// clear cache
		if (strcmp(toFind, "0")) {
			do {
				if (!strcmp((student+index)->name, toFind) || !strcmp((student+index)->phone, toFind) || !strcmp((student+index)->qq, toFind)) {
					switch(language) {
						case 0: { printf("\nPlease enter Name (without space) in order (split by space). Press Enter to confirm: "); break; }
						case 1: { printf("\n�밴˳�����������������ո񣩡��绰��QQ���Կո����֡����ո���ָ����س����޸ģ�"); break; }
						case 2: { printf("\n��˳ס����������������пո񣩡��绰��QQ�����ո����֡��οո񳸷ָ����س��Ϳ����޸ģ�"); break; }
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
						case 1: { printf("�Ҳ�������� :-(�����������롣\n\n"); break; }
						case 2: { printf("�h�������ѡ�������������� :-)��\n\n"); break; }						
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
		case 1: { printf("\n�밴˳�����������������ո񣩡��绰��QQ���Կո����֡����ո����ȷ�ϡ����洢����Ϊ 1024 ��ѧ�������� 0 ���س��Խ�����"); break; }
		case 2: { printf("\n��˳ס����������������пո񣩡��绰��QQ�����ո����֡��οո�������һ�������װ���� 1024 ��ѧ�������� 0 Ȼ֮��س��Ϳ��Խ�����\n\n"); break; }
	}
	putchar(10);
	do{												// Input information
		switch(language) {
			case 0: { printf("Please input the No.%d person's information: ", index + 1); break; }
			case 1: { printf("������� %d ���˵���Ϣ��", index + 1); break; }
			case 2: { printf("�ն������ %d ���ˆ���Ϣ��", index + 1); break; }			
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
		case 1: { printf("��Ա������%d\n\n", index); break; }
		case 2: { printf("һ��¼��� %d ���ˡ�\n\n", index); break; }		
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
			case 1: { printf("�����ѱ�������ǰĿ¼�µ� \"PhoneRecord\" �ļ��ڡ�\n\n"); break; }
			case 2: { printf("���ݱ�������˼��ظ�Ŀ¼��߆� \"PhoneRecord\" �ļ���ߡ�\n\n"); break; }		
		}
	} else {
		switch(language) {
			case 0: { printf("Sorry. Fail to open file.\n\n"); break; }
			case 1: { printf("��Ǹ���ļ���ʧ�ܡ�\n\n"); break; }
			case 2: { printf("�����˼�����ļ�������\n\n"); break; }			
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
			case 1: { printf("��Ǹ���ļ���ʧ�ܡ�\n\n"); break; }
			case 2: { printf("�����˼�����ļ�������\n\n"); break; }			
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
	
	printf("ͨѶ¼����ϵͳ V1.0 date: 20180624\n\nSelect language:\n");
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
	if ((fp = fopen("PhoneRecord","rb")) != NULL) {		// Found data.
		do {
			switch(language) {
				case 0: { printf("You have previously saved your data here. Read it? [Y/N] "); break; }
				case 1: { printf("����ǰ���ڴ˴��������ݡ��Ƿ��ȡ��[Y/N] "); break; }
				case 2: { printf("��֮ǰ��??���Ѿ��������ϵ��Ҫ�����ڣ�[Y/N] "); break; }
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
				printf("%s", "�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
				printf("%-64s �U\n", "�d   1. Input   record");
				printf("%-64s �U\n", "�d   2. Display record");
				printf("%-64s �U\n", "�d   3. Delete  record");
				printf("%-64s �U\n", "�d   4. Search  record");
				printf("%-64s �U\n", "�d   5. Modify  record");
				printf("%-64s �U\n", "�d   6. Insert  record");
				printf("%-64s �U\n", "�d   7. Sort    record");
				printf("%-64s �U\n", "�d   8. Save    record");
				printf("%-64s �U\n", "�d   0. Quit    system");
				printf("%s", "�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
				printf("Please enter your choice: ");
				break;
			}
			case 1: {
				printf("ͨѶ¼����ϵͳ V1.0 date: 20180624\n\n");
				printf("%s", "�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
				printf("%-48s �U\n", "�d   1. ��������");
				printf("%-48s �U\n", "�d   2. ��ʾ����");
				printf("%-48s �U\n", "�d   3. ɾ������");
				printf("%-48s �U\n", "�d   4. ��������");
				printf("%-48s �U\n", "�d   5. �޸�����");
				printf("%-48s �U\n", "�d   6. ��������");
				printf("%-48s �U\n", "�d   7. ��������");
				printf("%-48s �U\n", "�d   8. ��������");
				printf("%-48s �U\n", "�d   0. �˳�ϵͳ");
				printf("%s", "�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
				printf("����������ѡ��");
				break;
			}
			case 2: {
				printf("�绰������ϵͳ V1.0 date: 20180624\n\n");
				printf("%s", "�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[\n");
				printf("%-48s �U\n", "�d   1. ��������");
				printf("%-48s �U\n", "�d   2. ��ʾ����");
				printf("%-48s �U\n", "�d   3. ɾ������");
				printf("%-48s �U\n", "�d   4. ��������");
				printf("%-48s �U\n", "�d   5. �޸�����");
				printf("%-48s �U\n", "�d   6. ��������");
				printf("%-48s �U\n", "�d   7. ��������");
				printf("%-48s �U\n", "�d   8. ��������");
				printf("%-48s �U\n", "�d   0. �˳�ϵͳ");
				printf("%s", "�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a\n");
				printf("����������ѡ��");
				printf("������أ�");
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
					case 1: { printf("����ѡ����ȷ�ޣ����������롣\n\n"); break; }
					case 2: { printf("�δ�����������������\n\n"); break; }
				}					
				break;
			}
		}
	}while(!isExit);
	system("pause");
	return 0;
}
