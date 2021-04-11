/* @JUDGE_ID: 19899RK 645 C++ "By Anadan" */
// File Mapping
// Accepted (0.008 seconds with low memory spent)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SZ 21

struct File{
	struct File *next;
	char name[SZ];
};

struct DirList{
	struct DirList *next;
	struct Dir *dir;
};

struct Dir{
	char name[SZ];
	struct Dir *next;
	struct DirList *sub;
	struct File *files;
} head;

void insert_sub(DirList *&sub, Dir *dir){
	if (sub == NULL){
		sub = (DirList *)malloc(sizeof(DirList));
		sub->dir = dir;
	}else{
		sub = sub->next = (DirList *)malloc(sizeof(DirList));
		sub->dir = dir;
	}

	sub->next = NULL;
}

void insert_file(File *&files, char *fname){
	File *p, *last;

	if (files == NULL){
		files = (File *)malloc(sizeof(File));
		files->next = NULL;
		strcpy(files->name, fname);
	}else{
		for (last = NULL, p = files; p; p = p->next){
			if (strcmp(fname, p->name) <= 0) break;
			last = p;
		}

		p = (File *)malloc(sizeof(File));
		strcpy(p->name, fname);
		if (last == NULL){
			p->next = files;
			files = p;
		}else{
			p->next = last->next;
			last->next = p;
		}
	}
}

void outprint(Dir *dir, int level){
	int i;
	DirList *p, *d_tmp;
	File *files, *f_tmp;

	if (dir == NULL) return;
	for (i = 0; i < level; ++i) printf("|     ");
	printf("%s\n", dir->name);

	for (p = dir->sub; p; ){
		outprint(p->dir, level + 1);
		d_tmp = p;
		p = p->next;
		free(d_tmp);
	}

	for (files = dir->files; files;){
		for (i = 0; i < level; ++i) printf("|     ");
		printf("%s\n", files->name);
		f_tmp = files;
		files = files->next;
		free(f_tmp);
	}

	if (dir != &head) free(dir);
}

int scanfdir(struct Dir *dir){
	char str[SZ];
	struct Dir *tmp;
	struct DirList *cursub = NULL;

	while (scanf("%s\n", str) == 1 && str[0] != ']' && str[0] != '*' && str[0] != '#'){
		if (str[0] == 'd'){
			tmp = (Dir *)malloc(sizeof(Dir));
			tmp->sub = NULL;
			tmp->next = NULL;
			tmp->files = NULL;
			strcpy(tmp->name, str);

			scanfdir(tmp);
			if (cursub == NULL){
				insert_sub(dir->sub, tmp);
				cursub = dir->sub;
			}else insert_sub(cursub, tmp);
		}else{
			insert_file(dir->files, str);
		}
	}

	if (str[0] == '#') return 0;
	return 1;
}

int main(){
	int set = 0;

	strcpy(head.name, "ROOT");
	head.files = NULL;
	head.next = NULL;
	head.sub = NULL;

	while (scanfdir(&head)){
		printf("DATA SET %d:\n", ++set);
		outprint(&head, 0);

		head.files = NULL;
		head.next = NULL;
		head.sub = NULL;

		putchar('\n');
	}


	return 0;
}
/* @END_OF_SOURCE_CODE */
