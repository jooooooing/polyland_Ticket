#include <stdio.h>

int main(){
	
	//��¥, �̿�� ����, �̿� �ð�, �߱� ����, ��� ����, ������, ����� �Ѿ� //
		
	FILE *fp = fopen("report.csv", "r");
	const int MAX = 100;
	int count = 0;
	int date[MAX], inputTicket[MAX] , inputTicketDetail[MAX], inputAmount[MAX], premierType[MAX], customerType[MAX], finalPrice[MAX];
	
	while( fscanf(fp, "%d, %d, %d, %d, %d, %d, %d\n", &date[count], &inputTicket [count] , &inputTicketDetail[count], &inputAmount[count], 
															&premierType[count], &customerType[count], &finalPrice[count]) != -1) {
			count ++;													
														}
														
	fclose(fp);
	
	for(int index = 0; index < count; index++) {
		printf("%d, %d, %d, %d, %d, %d, %d\n", date[index], inputTicket[index] , inputTicketDetail[index], inputAmount[index], 
															premierType[index], customerType[index], finalPrice[index]);
	}
	
	
	
	return 0;
	
}
