#include <stdio.h>
#include <time.h>


int main(){
	
	//report �� �ҷ�����// 
	//��¥, �̿�� ����, �̿� �ð�, �߱� ����, ��� ����, ������, ����� �Ѿ� //
	
	FILE *fp = fopen("report.csv", "r");
	const int MAX = 5000;

	int row = 0;
	int date[MAX], inputTicket[MAX] , inputTicketDetail[MAX], inputAmount[MAX], premierType[MAX], customerType[MAX], finalPrice[MAX];
	
	printf("\n========================================= report.csv =======================================\n");
	printf ("%s,\t %s,\t %s,\t %s,\t %s,\t %s,\t %s\t\n", "��¥","����","�ð�","����","������","���з�","�ݾ�"); 
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
	
	printf("\n=========================================== ����  �� �Ǹ� ��Ȳ ==============================\n\n");
	
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
		printf("\t\t\t\t\t%5d ��%5.2d ��:%10d ��\n",i/100,i%100, dateIncome[i]);
	}
	
	
	//������ ����  �����̿�� :1, ��ũ�̿�� :2 // 
	printf("\n=========================================���� �� �Ǹ� ��Ȳ===================================\n");
	
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
	
	printf("\n\t\t\t\t\t���� �̿��: �� %d��\t / ���� %d��\n",countAll,incomeAll);
	printf("\n\t\t\t\t\t��ũ �̿��: �� %d��\t / ���� %d��\n",countPark,incomePark);
	
	//�̿�ð��� ����  ���ϱ� :1, After4 :2 // 
	printf("\n=====================================�̿�ð� �� �Ǹ� ��Ȳ===================================\n");
	
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
	
	printf("\n\t\t\t\t\t���� �̿��: �� %d��\t / ���� %d��\n",countAllday,incomeAllday);
	printf("\n\t\t\t\t\t��ũ �̿��: �� %d��\t / ���� %d��\n",countAfter4,incomeAfter4);
	
	
	//�����׺� ����  NONE = 1, DISABLE = 2, MERIT = 3, SOLDIIER = 4, PREGNANT = 5, MULTICHILD = 6; // 
	printf("\n===================================== ��� ���� �з� �� �Ǹ� ��Ȳ ===========================\n");
	
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
	
	printf("\n%12s\t%12s\t%12s\t%12s\t%12s\t%12s\n","����","�����","����������","�ް��庴","�ӻ��","�ٵ���");
	printf("\n%12d\t%12d\t%12d\t%12d\t%12d\t%12d\n",countNo, countDis, countMer, countSol, countPreg, countMulti);
	printf("\n=============================================================================================\n");
	
	
	return 0;
	
}
