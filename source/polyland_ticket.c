#include <stdio.h>
#include <time.h>


int main(){
	
	// ���� ��¥ ���ϱ� // 
	struct tm* t;
	time_t base = time(NULL);
	t = localtime(&base);
	printf ("Today : %d�� %d�� %d��\n ", t->tm_year + 1900, t->tm_mon+1, t->tm_mday);
		// �迭 ���� //
	int row = 0;
	int reportArray[50000][6] = {0};
	int restart; 
	
	// ���� ���� //
	
	for(;;){
	for(;;){
	
	int inputTicket, inputTicketDetail, inputBirth, inputAmount, inputPremier;
	int resultPrice, premierPrice, reOrder;
	int ageNumber, birthYear, birthDate, seventhDate, yearGap, interAge, birthMonth, birthDay, customerType; 
	int thisYear = t->tm_year + 1900;
	const int FULL_1DAYPRICEADULT = 59000, FULL_1DAYPRICETEEN = 52000, FULL_1DAYPRICEKIDS = 47000, FULL_1DAYPRICEBABY = 15000;
	const int FULL_AFTER4PRICEADULT = 48000, FULL_AFTER4PRICETEEN = 42000, FULL_AFTER4PRICEKIDS = 36000, FULL_AFTER4PRICEBABY = 15000;
	const int PARK_1DAYPRICEADULT = 56000, PARK_1DAYPRICETEEN = 50000, PARK_1DAYPRICEKIDS = 46000, PARK_1DAYPRICEBABY = 15000;
	const int PARK_AFTER4PRICEADULT = 45000, PARK_AFTER4PRICETEEN = 40000, PARK_AFTER4PRICEKIDS = 35000, PARK_AFTER4PRICEBABY = 15000;
	char todayMonth, todayDay, today;
	
	todayMonth = t->tm_mon+1;
	todayDay = t->tm_mday;
	

	
		
		// �̿�� ���� ���� //
		do {	
			printf("\n��.Ƽ�� ������ �Է��ϼ���. \n 1. �����̿�� \n 2. ��ũ�̿��\n");
			scanf("%d", &inputTicket);
			
			if ( inputTicket > 2){
			printf ("�Է��� �߸��Ǿ����ϴ�. �ٽ� �Է����ּ���\n\n");
			}
		} while (inputTicket >2);
		
		reportArray[row][0] = inputTicket;
		
		// ���ϱ�, After4 ���� // 
		do {
			printf("\n��.���� Ƽ�� ������ �Է��ϼ���. \n 1. 1Day \n 2. After4\n");
			scanf("%d", &inputTicketDetail);
			
			if ( inputTicketDetail > 2){
			printf ("�Է��� �߸��Ǿ����ϴ�. �ٽ� �Է����ּ���\n\n");
			} 
		}while (inputTicketDetail >2);
		
		reportArray[row][1] = inputTicketDetail;
		
		do {
			printf("\n��.�ֹι�ȣ�� �Է��ϼ���(7�ڸ�����)\n");
			scanf("%d", &inputBirth);
			
			if ( inputBirth%10 >= 5 || inputBirth%10 ==0 || inputBirth <= 999999 || inputBirth >= 10000000){
			printf ("�Է��� �߸��Ǿ����ϴ�. �ٽ� �Է����ּ���\n\n");
			}
		} while (inputBirth%10 >= 5 || inputBirth%10 ==0 || inputBirth <= 999999 || inputBirth >= 10000000);
		
	
		
		do {
			printf("\n��.��� �ֹ��Ͻðڽ��ϱ�? (�ִ� 10��)\n");
			scanf("%d", &inputAmount);
			
			if ( inputAmount > 10 || inputAmount <1 ){
			printf ("�Է��� �߸��Ǿ����ϴ�. �ٽ� �Է����ּ���\n");
			}
		} while (inputAmount > 10 || inputAmount <1);
		
		reportArray[row][2] = inputAmount;
		
		do {
			printf("\n��.��� ������ �����ϼ���. \n 1. ����(���� ���� �ڵ�ó��) \n 2. �����\n 3. ����������\n 4. �ް��庴\n 5. �ӻ��\n 6. �ٵ��� �ູī��\n");
			scanf("%d", &inputPremier);
			
			if (inputPremier > 7){
			printf ("�Է��� �߸��Ǿ����ϴ�. �ٽ� �Է����ּ���\n\n");
			}
		} while (inputPremier > 7);	
		
		reportArray[row][3] = inputPremier;
		
	//���� ���// 
	ageNumber = inputBirth/100000; //�ֹι�ȣ 7�ڸ��� 10������ ������ ���� ���������� ��ȯ
	birthDate = (inputBirth - (ageNumber*100000))/10; // (������� 7�ڸ� - ������*10��) = (����+�ֹ� ��ȣ 7��° �ڸ�) / 10 => ���� ������ 1018+1 / 10 = 1018
	birthMonth = (birthDate / 100); // 10�� 18�� => 10
	birthDay = birthDate - ((birthDate / 100) * 100); // 10�� 18�� ==> 18 
	
	
	if (inputBirth % 5 <= 2) { //�ֹι�ȣ 7�ڸ��� 5�� ���� ������ ���� 2���� �۰ų� ������� 1,2 = 1900��� �� 
		birthYear = (inputBirth / 100000)+ 1900;
	}
	
	else if (inputBirth%5 >= 3){ //�ֹι�ȣ 7�ڸ��� 5�� ���� �������� 3���� ũ�ų� ���� ��� 3,4 = 2000��� �� 
		birthYear = (inputBirth / 100000) + 2000;
	}
	
	yearGap = thisYear - birthYear;
	
	if (birthDate > 316) { // ������ 3�� 16�� ������ ���  
		interAge = yearGap - 1;
	}
	else if (birthDate <= 316 ) { //������ 3�� 16�� ������ ��� 
		interAge  = yearGap;
	}
	
		
	
	/* ���� ��� Ȯ�ο� 
	printf("%d\n", ageNumber);
	printf("%d\n", birthDate);
	printf("%d\n", birthYear);
	printf("%d\n", yearGap);	
	printf("%d\n", interAge); 
	printf("%d\n", birthMonth);
	printf("%d\n", birthDay); */

	// --- //
	
	// Ƽ�� �� ��� //
	
	// �� 65�� �̻� // 	
	if (interAge >= 65)	{
		if(inputTicket == 1) {   											//���� �̿�� ���� // 
			if (inputTicketDetail ==1 ){  									// 1 Day //
			resultPrice = FULL_1DAYPRICEKIDS * inputAmount;
			}
			else  if (inputTicketDetail ==2 ){ 								// After4 //
			resultPrice = FULL_AFTER4PRICEKIDS * inputAmount;
			}
		}		
		else if(inputTicket == 2){											//��ũ  �̿�� ���� // 
			if (inputTicketDetail ==1 ){ 									// 1 Day //
			resultPrice = PARK_1DAYPRICEKIDS * inputAmount;
			}
			else  if (inputTicketDetail ==2 ){ 								// After4 //
			resultPrice = PARK_AFTER4PRICEKIDS * inputAmount;
			}
		}
	customerType = 1; //������ 1 = �� 65�� �̻� 
	} 
	
	// � �� 19�� �̻�  ~ �� 65�� �̸�//
	
	else if (interAge >= 19){
		if(inputTicket == 1) {   											//���� �̿�� ���� // 
			if (inputTicketDetail ==1 ){  									// 1 Day //
			resultPrice = FULL_1DAYPRICEADULT * inputAmount;
			}
			else  if (inputTicketDetail ==2 ){ 								// After4 //
			resultPrice = FULL_AFTER4PRICEADULT * inputAmount;
			}
		}
		else if(inputTicket == 2){											//��ũ  �̿�� ���� // 
			if (inputTicketDetail ==1 ){ 									// 1 Day //
			resultPrice = PARK_1DAYPRICEADULT * inputAmount;
			}
			else  if (inputTicketDetail ==2 ){ 								// After4 //
			resultPrice = PARK_AFTER4PRICEADULT * inputAmount;
			}
		}	
	customerType = 2; //������ 2 = � : �� 19�� �̻� ~�� 65�� �̸�
	}
		
	// û�ҳ� �� 13�� �̻� ~ �� 18�� ���� //
	
	else if (interAge >= 13){
		if(inputTicket == 1) {   											//���� �̿�� ���� // 
			if (inputTicketDetail ==1 ){  									// 1 Day //
			resultPrice = FULL_1DAYPRICETEEN * inputAmount;
			}
			else  if (inputTicketDetail ==2 ){ 								// After4 //
			resultPrice = FULL_AFTER4PRICETEEN * inputAmount;
			}
		}
		else if(inputTicket == 2) {											//��ũ  �̿�� ���� // 
			if (inputTicketDetail ==1 ){ 									// 1 Day //
			resultPrice = PARK_1DAYPRICETEEN * inputAmount;
			}
			else  if (inputTicketDetail ==2 ){ 								// After4 //
			resultPrice = PARK_AFTER4PRICETEEN * inputAmount;
			}
		}
	customerType = 3; //������ 3 = û�ҳ� : �� 13�� �̻� ~�� 18�� ����
	}
		
	// ��� 36����(�� 3��) �̻� ~ �� 12�� ���� //
	
	else if (interAge >= 3){
		if(inputTicket == 1) {   											//���� �̿�� ���� // 
			if (inputTicketDetail ==1 ){  									// 1 Day //
			resultPrice = FULL_1DAYPRICEKIDS * inputAmount;
			}
			else  if (inputTicketDetail ==2 ){ 								// After4 //
			resultPrice = FULL_AFTER4PRICEKIDS * inputAmount;
			}
		}
		else if(inputTicket == 2){											//��ũ  �̿�� ���� // 
			if (inputTicketDetail ==1 ){ 									// 1 Day //
			resultPrice = PARK_1DAYPRICEKIDS * inputAmount;
			}
			else  if (inputTicketDetail ==2 ){ 								// After4 //
			resultPrice = PARK_AFTER4PRICEKIDS * inputAmount;
			}
		}
	customerType = 4; //������ 4 = ��� : �� 36���� �̻� ~�� 12�� ����	
	}		


	// ���̺� 0���� �̻� ~ 36���� (��3��) �̸� //
	
	else if (interAge < 3){
		if(inputTicket == 1) {   											//���� �̿�� ���� // 
			if (inputTicketDetail ==1 ){  									// 1 Day //
			resultPrice = FULL_1DAYPRICEBABY * inputAmount;
			}
			else  if (inputTicketDetail ==2 ){ 								// After4 //
			resultPrice = FULL_AFTER4PRICEBABY * inputAmount;
			}
		}
		else if(inputTicket == 2) {										//��ũ  �̿�� ���� // 
			if (inputTicketDetail ==1 ){ 									// 1 Day //
			resultPrice = PARK_1DAYPRICEBABY * inputAmount;
			}
			else  if (inputTicketDetail ==2 ){ 								// After4 //
			resultPrice = PARK_AFTER4PRICEBABY * inputAmount;
			}
		}
	customerType = 5; //������ 5 = ��� : �� 0���� �̻� ~�� 36���� �̸�
	}
	
	reportArray[row][4] = customerType;
	
	
	printf("\n========================================= �߱�   ��� ======================================\n");
	printf ("\n������ Ƽ�� ������ : %d\n", inputTicket);
	printf ("������ ����Ƽ�� ������ : %d\n", inputTicketDetail);
	printf ("���� ���� : %d��\n", interAge); 
	printf("�ֹ� ���� (�ִ� 10��) : %d��\n", inputAmount);
	

	// ��� ��� ���� *����1���� ������ //
	//�� 65�� �̻� �߰� ��� ���� �Ұ�// 
	if (interAge >= 65) {
		premierPrice = resultPrice * 1;
		printf("65�� �̻����� ��̿�� ����\n");
		printf("������ %d�� �Դϴ�.", premierPrice);	
	}
	
	//��� ���� ����// 
	else if (inputPremier == 1) {
		premierPrice = resultPrice * 1;
		printf("������ ���� \n"); 
		printf("������ %d�� �Դϴ�.", premierPrice);
	}
			
	//����� ��� 50% // 
	else if (inputPremier == 2) {
		premierPrice = resultPrice * 0.5;
		printf("����� ��� 50%% \n");
		printf("������ %d�� �Դϴ�.", premierPrice);
	}
	
	//���������� ��� 50% //
	else if (inputPremier == 3) {
		premierPrice = resultPrice * 0.5;
		printf("����������  ��� 50%% \n");
		printf("������ %d�� �Դϴ�.", premierPrice);
	}
	
	//�ް��庴  ��� 49% //
	else if (inputPremier == 4 && inputTicket==1) {
		premierPrice = resultPrice * 0.5 + 500;
		printf("�ް��庴 ��� 49%% \n");
		printf("������ %d�� �Դϴ�.", premierPrice);
	}
	
	//�ӻ��  ��� 50% //
	else if (inputPremier == 5 && inputTicket==1) {
		premierPrice = resultPrice * 0.5;
		printf("�ӻ�� ��� 50%% \n");
		printf("������ %d�� �Դϴ�.", premierPrice);
	}
	
	//�ٵ��� �ູī�� ��� 30% //
	else if (inputPremier == 6 && inputTicket==1) {
		premierPrice = resultPrice * 0.7;
		printf("�ٵ��� �ູī�� ���� 30%% \n");
		printf("������ %d�� �Դϴ�.\n", premierPrice);
	}
	
	reportArray[row][5] = premierPrice;
	
	printf("\n============================================================================================\n");	
	
	// ��� ���� ���� //
	printf("\n\n�̾ �߱ǽðڽ��ϱ�? \n 1.��\n 2.�ƴϿ�\n");
	scanf("%d", &reOrder);
	
	//��� ���� �迭������ �°� ���� �ʿ�// 
	
	if (reOrder == 2) {
		printf("\n========================================= �߱�  ���� =======================================\n");
		printf("%10s\t%10s\t%10s\t%10s\t%10s\t%10s\n","�̿�� ����","�̿� �ð�","�߱� ����","��� ����","������","����� �Ѿ�");
		printf("%10s\t%10s\t%10s\t%10s\t%10s\t%10s","(����/��ũ)","(1Day/After4)"," (��) ","(1-6)","(1~6) ","(��)");
		printf("\n============================================================================================\n");
		break;
	}
	
	else { 
		row ++; 
	} 

} for (int i=0;i<=row;i++){	
		for (int j=0;j<6;j++){
			printf("%10d\t",reportArray[i][j]);
			}
		printf("\n");
	}
		

printf("\n�̿����ּż� �����մϴ�.\n");

printf("\n��� ���� (1:���ο� �ֹ�, 2: ���α׷� ����) : ");
scanf("%d", &restart);

if(restart == 2) {
	printf("\n���α׷��� �����մϴ�."); 
	break;
}

else {
	printf("\n=========================================���� �߱�=======================================");
}
}
	return 0;

}
