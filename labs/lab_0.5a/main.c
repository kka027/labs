#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int enter_str(char** osn_str, char* vsp_str, int* size) {
	int q = 0;
	int n = 1;
	*osn_str = (char*)malloc(1 * sizeof(char));
	while (1) {

		n = scanf("%9[^\n]s", vsp_str);
		if (n == EOF) { return 1; }
		if (n == 0) { return 0; }
		*size += 10;
		*osn_str = (char*)realloc(*osn_str, *size * sizeof(char));
		strcpy(*(osn_str)+q, vsp_str);

		q += 9;

	}
}

void work_str(char** osn_str, int size, char** help_str) {

	char a, b;
	//size += 100;
	*help_str = (char*)calloc(size, sizeof(char));
	//printf("%d      %s", sizeof(*help_str) , help_str);
	int i = 0, pl, first, second, kol, k, sz,flag,flag1;
	char* last_str;
	last_str = (char*)calloc(size, sizeof(char));
	strcpy(*help_str, *osn_str);
	kol = 0;
	while ((*osn_str)[i] != '\0') {
		pl = 0;
		flag1 = 0;
		sz = 0;
		flag = 0;
		while ((*osn_str)[i] != ' ' && (*osn_str)[i] != '\t' && (*osn_str)[i] != '\0') {
			if ((*osn_str)[i] == '-') {
				i++;
				sz++;
				continue;
			}
			if (pl == 0) {
				if ((*osn_str)[i] - '0' > 9 || (*osn_str)[i] - '0' < 0) {
					flag = 1;
				}
				first = (*osn_str)[i]-'0';
				i++;
				pl = 1;
				sz++;
			}
			flag1 = 1;
			if ((*osn_str)[i] == ' ' || (*osn_str)[i] == '\t' || (*osn_str)[i] == '\0') {
				break;
			}
			if ((*osn_str)[i] - '0' > 9 || (*osn_str)[i] - '0' < 0) {
				flag = 1;
			}
			second = (*osn_str)[i]-'0';
			sz++;
			i++;
			if (second < first) {
				flag = 1;
			}
			first = second;
		}
		if (flag == 0 && flag1 == 1) {
			strncpy(last_str + kol, &(*osn_str)[i - sz], sz);
			kol += sz;
			last_str[kol] = ' ';
			kol++;
		}
		if (flag1 == 0) { i++; }

	}
	printf("%s", last_str);
	
}
int main() {
	char* osn_str = NULL;
	char* help_str = NULL;
	int size = 0;
	char vsp_str[10];
	int k = 0, r = 0;
	//printf("%d          %d", osn_str, &osn_str);
	while (r != 1) {
		printf("Enter line:");
		r = enter_str(&osn_str, vsp_str, &size);
		if (r != 1) {
			work_str(&osn_str, size, &help_str);
			printf("\n");
			while (getchar() != '\n');
		}
	}
	free(osn_str);
	free(help_str);

	return 0;
}