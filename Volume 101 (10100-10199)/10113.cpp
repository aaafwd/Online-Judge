/* @JUDGE_ID: 19899RK 10113 C++ "By Anadan" */ 
// Exchange Rates
// Accepted (0.010 seconds with low memory spent)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int maxi = 0;
char items[60][22];
long double table[60][60];
char flag[60][60];
int m, n;
char ch, str1[22], str2[22];

int getID(char *str){
    int i;

    for (i=0; i< maxi; i++){
        if (!strcmp(items[i], str)) return i;
    }

    return -1;
}

void addKV(int id1, int id2){
     table[id1][id2] = (long double)(n)/(long double)(m);
     table[id2][id1] = (long double)(m)/(long double)(n);

     for (int i=0; i<maxi; i++){
         if (i == id1) continue;
         if (i == id2) continue;
         if (table[i][id1]){
            table[i][id2] = table[i][id1]*table[id1][id2];
            table[id2][i] = table[id2][id1]*table[id1][i];
            for (int j=0; j<maxi; j++){
                if (i == j) continue;
		if (j == id2) continue;
                if (table[id2][j]){
                   table[i][j] = table[i][id1]*table[id1][id2]*table[id2][j];
                   table[j][i] = table[j][id2]*table[id2][id1]*table[id1][i];
                }
            }
         }
         if (table[i][id2]){
            table[i][id1] = table[i][id2]*table[id2][id1];
            table[id1][i] = table[id1][id2]*table[id2][i];
	    for (int j=0; j<maxi; j++){
                if (i == j) continue;
		if (j == id1) continue;
                if (table[id1][j]){
                   table[i][j] = table[i][id2]*table[id2][id1]*table[id1][j];
                   table[j][i] = table[j][id1]*table[id1][id2]*table[id2][i];
                }
            }
         }
     }
}

void Norm(int &a, int &b, long double d){
     long double tmp;
     for (b = 1; b > 0; b++){
            tmp = d * b;
	    if (fabs(tmp - ceil(tmp)) < 10e-12 ){
	       a = int(ceil(tmp));
               break;
            }
     }

     for (int i=2; i*i <= a; i++){
         if ((!(a%i))&&(!(b%i))){
            a/=i; b/=i;
         }
     }
}

long double getReq(int id1, int id2){
    if (table[id1][id2]) return table[id1][id2];
    return 0.0;
}

void outRequest(){
    int a=0, b=0;
    long double tmp = 0.0;
    if ((m != -1) && (n != -1)){
       if (m != n) tmp = getReq(m, n);
       else { a = b = 1; tmp = 1.0; }
    }

    if (tmp){
       Norm(a, b, tmp);
       printf("%d %s = %d %s\n", b, str1, a, str2);
    }else{
       printf("? %s = ? %s\n", str1, str2);
    }
}

int main(){
    memset(table, 0, 60*60*sizeof(long double));
    memset(items, 0, 60*22);

    while (scanf("%c", &ch) > 0){
	  if (ch == '!'){
	     scanf("%d %s = %d %s\n", &m, str1, &n, str2);
	      int id1, id2;
	      if ((id1 = getID(str1)) == -1){
		 id1 = maxi++;
		 strcpy(items[id1], str1);
	      }

	      if ((id2 = getID(str2)) == -1){
		 id2 = maxi++;
		 strcpy(items[id2], str2);
	      }
	     addKV(id1, id2);
	  }else if (ch == '?'){
	     scanf("%s = %s\n", str1, str2);
	     m = getID(str1);
	     n = getID(str2);
	     memset(flag, 0, 60*60);
	     outRequest();
	  }
    }
    return 0;
}
/* @END_OF_SOURCE_CODE */
