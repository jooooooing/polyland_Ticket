#include <stdio.h>
#include <time.h>


int main(){
	
	//report 값 불러오기// 
	//날짜, 이용권 종류, 이용 시간, 발권 수량, 우대 구분, 고객구분, 입장료 총액 //
	
	FILE *fp = fopen("report.csv", "r");
	const int MAX = 5000;

	int row = 0;
	int date[MAX], inputTicket[MAX] , inputTicketDetail[MAX], inputAmount[MAX], premierType[MAX], customerType[MAX], finalPrice[MAX];
	
	printf("\n========================================= report.csv =======================================\n");
	printf ("%s,\t %s,\t %s,\t %s,\t %s,\t %s,\t %s\t\n", "날짜","권종","시간","수량","우대사항","고객분류","금액"); 
	while( fscanf(fp, "%d, %d, %d, %d, %d, %d, %d\n", &date[row], &inputTicket [row] , &inputTicketDetail[row], &inputAmount[row], 
															&premierType[row], &customerType[row], &finalPrice[row]) != -1) {
			row ++;													
														}
														
	fclose(fp);
	
	for(int index = 0; index < row; index++) {
		printf("%d\t %d\t %d\t %d\t %d\t %d\t %d\n", date[index], inputTicket[index] , inputTicketDetail[index], inputAmount[index], 
															premierType[index], customerType[index], finalPrice[index]);
											
	}
	printf("=============================================================================================\n");
	
	printf("\n=========================================== 일자  별 판매 현황 ==============================\n\n");
	
	int dateIncome[5000]= {0,};
	
	for (int dateIndex = 101; dateIndex <= 1231; dateIndex++){
		for (int index = 0; index <= 5000 ; index++){
			if (dateIndex == date[index]%10000){
			dateIncome[dateIndex] += finalPrice[index];
			}
		}	
	}
	
	for (int i= 1; i<=2000; i++ ){
		if (dateIncome[i] > 0)
		printf("\t\t\t\t\t%5d 월%5.2d 일:%10d 원\n",i/100,i%100, dateIncome[i]);
	}
	
	
	//권종별 매출  종합이용권 :1, 파크이용권 :2 // 
	printf("\n=========================================권종 별 판매 현황===================================\n");
	
	int countAll = 0, countPark  = 0, incomeAll = 0, incomePark =0 ;
	
	for (int index=0; index < row; index++){
		if (inputTicket[index] == 1 ) {
			countAll += inputAmount[index];
			incomeAll += finalPrice[index];
		}
		else {
			countPark += inputAmount[index];
			incomePark += finalPrice[index];
		}
	}
	
	printf("\n\t\t\t\t\t종합 이용권: 총 %d매\t / 매출 %d원\n",countAll,incomeAll);
	printf("\n\t\t\t\t\t파크 이용권: 총 %d매\t / 매출 %d원\n",countPark,incomePark);
	
	//이용시간별 매출  종일권 :1, After4 :2 // 
	printf("\n=====================================이용시간 별 판매 현황===================================\n");
	
	int countAllday = 0, countAfter4  = 0, incomeAllday = 0, incomeAfter4 =0 ;
	
	for (int index=0; index < row; index++){
		if (inputTicketDetail[index] == 1 ) {
			countAllday += inputAmount[index];
			incomeAllday += finalPrice[index];
		}
		else {
			countAfter4 += inputAmount[index];
			incomeAfter4 += finalPrice[index];
		}
	}
	
	printf("\n\t\t\t\t\t종합 이용권: 총 %d매\t / 매출 %d원\n",countAllday,incomeAllday);
	printf("\n\t\t\t\t\t파크 이용권: 총 %d매\t / 매출 %d원\n",countAfter4,incomeAfter4);
	
	
	//우대사항별 매출  NONE = 1, DISABLE = 2, MERIT = 3, SOLDIIER = 4, PREGNANT = 5, MULTICHILD = 6; // 
	printf("\n===================================== 우대 사항 분류 별 판매 현황 ===========================\n");
	
	int countNo = 0, countDis = 0 , countMer = 0, countSol = 0, countPreg = 0, countMulti = 0;
	
	for (int index=0; index < row; index++){
		if (premierType[index] == 1) {
			countNo += inputAmount[index];		 
		} 
		else if (premierType[index] == 2) {
			countDis += inputAmount[index];		 
		} 
		else if (premierType[index] == 3) {
			countMer += inputAmount[index];
		}
		else if (premierType[index] == 4) {
			countSol += inputAmount[index];		 
		} 
		else if (premierType[index] == 5) {
			countPreg += inputAmount[index];		 
		}
		else {
			countMulti += inputAmount[index];		 
		} 
	}
	
	printf("\n%12s\t%12s\t%12s\t%12s\t%12s\t%12s\n","없음","장애인","국가유공자","휴가장병","임산부","다둥이");
	printf("\n%12d\t%12d\t%12d\t%12d\t%12d\t%12d\n",countNo, countDis, countMer, countSol, countPreg, countMulti);
	printf("\n=============================================================================================\n");
	
	
	return 0;
	
}
