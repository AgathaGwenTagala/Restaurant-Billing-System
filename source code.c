//Billing System
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
#include<time.h>

//header; restaurant name and address
head() {
	printf("		MASARAP-KUMAIN RESTAURTANT\n");
	printf("		143 MABUSOG ST., LOVE CITY\n\n");
}

//converts each word to proper casing
convert(int length, int a, char details[]) {
	length = 0;
	length = strlen(details);
	for (a = 0; a < length; a++)	
		details[a] = tolower(details[a]);
	for (a = 0; a < length; a++) {			
		if (a == 0)
			details[a] = toupper(details[a]);
		else if (details[a] == ' ')
			details[a+1] = toupper(details[a+1]);
	}
}

void main() {
	char ans1, ans2;
	int length, i, j, k, table, dtype, ttype, count, ctr;
	float sd, gmd, td, total, net, amtnd, change;
	time_t t;
	
	struct order {
		char code[10];
		char desc[15];
		int qty;
		float price, amt;
	}
    
    item [j];
	while (j > 0) {
		for (i = 0, j = 0; i <= j; i++)	{
			j++;
			dtype = 0; ttype = 0; count = 1; ctr = 1; 
			sd = 0; gmd = 0; td = 0; total = 0; net = 0; amtnd = 0; change = 0;
	
			//input order details
			head();
			printf("	    		ORDER FORM\n\n");
			printf("TABLE NO.: ");
			scanf("%d", &table);
			printf("\n1 - PWD\t      3 - STUDENT\n2 - SENIOR    4 - NONE\n");
			while (dtype < 1 || dtype > 4) {
                printf("\nDISCOUNT TYPE: ");
				scanf("\n");
				scanf("%d", &dtype); }
			printf("\n1 - DINE-IN   2 - TAKE-AWAY\n");
			while (ttype < 1 || ttype > 2) {
                printf("\nTRANSACTION TYPE: ");
				scanf("\n");
				scanf("%d", &ttype); }
			system("cls");

			//input order(s)
			head();
			printf("	    		ORDER FORM\n\n");
			for (k = 0; k < ctr; k++) {
				printf("ITEM NO.: %d", count);
				printf("\nITEM CODE: ");
				scanf("\n");
				gets(item[k].code);
				printf("ITEM DESCRIPTION: ");
				gets(item[k].desc);
				convert(length, i, item[k].desc);
				printf("QUANTITY: ");
				scanf("%d", &item[k].qty);
				printf("PRICE: ");
				scanf("%f", &item[k].price);
				//compute amount
				item[k].amt = item[k].qty * item[k].price;
				total += item[k].amt;
				//add more items
				printf("\nDo you want to add more? (Y/N) ");
				scanf("%s", &ans1);
				ans1 = toupper(ans1);
				if (ans1 == 'Y') {	
                    system("cls");
					count++;
					ctr = count;
                }
			}			
			//compute discount
			if (total >= 200 && total <= 1000)
				sd = total * .02;
			else if (total >= 1001 && total <= 2000)
				sd = total * .03;
			else if (total > 2000)
				sd = total * .04;
			if (dtype == 1 || dtype == 2 || dtype == 3)
				gmd = total * .20;
			//compute net bill
			td = gmd + sd;
			net = total - td;
			//output final details
			system("cls");
			head();
			printf("	    	    BILLING STATEMENT\n\n");
			time(&t);
			printf(" Date: %s\n", ctime(&t));
			printf(" TABLE NO.: %2d", table);
			printf("\t\tDISCOUNT TYPE: ");
			switch (dtype) {
				case 1:
					printf("X PWD  _ SENIOR  _ STUDENT\n\n");
					break;
				case 2:
					printf("_ PWD  X SENIOR  _ STUDENT\n\n");
					break;
				case 3:
					printf("_ PWD  _ SENIOR  X STUDENT\n\n");
					break;
				case 4:
					printf("_ PWD  _ SENIOR  _ STUDENT\n\n");
					break;
			}
			printf(" TRANSACTION TYPE: ");
			switch (ttype) {
				case 1:
					printf("X DINE-IN  _ TAKE-AWAY\n\n");
					break;
				case 2:
					printf("_ DINE-IN  X TAKE-AWAY\n\n");
					break;
			}
			printf("  ---------------------------------------------------------------\n");
			printf("  | ITEM CODE\tITEM DESCRIPTION\tQTY\tPRICE \t AMOUNT |\n");
			printf("  ---------------------------------------------------------------\n");
			for (k = 0; k < count; k++)
				printf("  | %-9s\t%-15s\t\t%d\t%7.2f\t%7.2f |\n", item[k].code, item[k].desc, item[k].qty, item[k].price, item[k].amt);
			printf("  ---------------------------------------------------------------\n");
			printf("\t\t\t\t    TOTAL BILL :\t%7.2f\n", total);
			printf("\t\t\t\t    DISCOUNT   :\n");
			printf("\t\t\t\t      GM       : %6.2f\n", gmd);
			printf("\t\t\t\t      SD       : %6.2f\n", sd);
			printf("\t\t\t\t\t\t\t %6.2f", td);
			printf("\n\t\t\t\t    NET BILL   :\t%7.2f\n", net);
			while (amtnd < net)	{
                printf("\t\t\t       AMOUNT TENDERED :\t ");
				scanf("%f", &amtnd); }
			change = amtnd - net;
			printf("\n\t\t\t\t     CHANGE    :\t%7.2f\n", change);
			//repeat process
			printf("\nDo you want to continue? (Y/N) ");
			scanf("%s", &ans2);
			ans2 = toupper(ans2);
			ans2 == 'Y' ? system("cls") : exit(0);			
		}
	}	
}
