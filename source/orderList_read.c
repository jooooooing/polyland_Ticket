#include <stdio.h>

int main(){
	
	//report 값 불러오기// 
	//날짜, 이용권 종류, 이용 시간, 발권 수량, 우대 구분, 고객구분, 입장료 총액 //
	
	FILE *fp = fopen("report.csv", "r");
	const int INITIAL_VALUE = 0, START = 0, MAX = 100;

	const int FULL = 1, PARK = 2; 	//권종 구분 //
	const int ALLDAY = 1, AFTER4 = 2 ; //이용 시간 구분 //
	const int NONE = 1, DISABLE = 2, MERIT = 3, SOLDIIER = 4, PREGNANT = 5, MULTICHILD = 6; //우대사항 구분/. 
	const int OLD = 1, ADULT = 2, TEEN = 3, CHILD = 2, BABY = 1; //연령 구분// 
	const int MIB_BABY =1, MIN_CHILD = 3, MIN_TEEN = 13, MIN_ADULT = 19, MAX_CHILD = 12, MAX_TEEN = 18, MAX_ADULT = 64;
	
	
	int count = 0;
	int date[MAX], inputTicket[MAX] , inputTicketDetail[MAX], inputAmount[MAX], premierType[MAX], customerType[MAX], finalPrice[MAX];
	printf("\n========================================= report.csv =======================================\n");
	printf ("%5s, %5s, %5s, %5s, %5s, %5s, %5s\n", "날짜","권종","시간","수량","우대사항","고객분류","금액"); 
	while( fscanf(fp, "%d, %d, %d, %d, %d, %d, %d\n", &date[count], &inputTicket [count] , &inputTicketDetail[count], &inputAmount[count], 
															&premierType[count], &customerType[count], &finalPrice[count]) != -1) {
			count ++;													
														}
														
	fclose(fp);
	
	for(int index = 0; index < count; index++) {
		printf("%d, %d, %d, %d, %d, %d, %d\n", date[index], inputTicket[index] , inputTicketDetail[index], inputAmount[index], 
															premierType[index], customerType[index], finalPrice[index]);
															
	}
	printf("\n=============================================================================================\n");
	
	printf("\n=========================================권종 별 판매 현황===================================\n");
	
	
	return 0;
	
}
