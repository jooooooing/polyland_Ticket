#include <stdio.h>
#include <time.h>


int main(){
	
	// ���� ��¥ ���ϱ� // 
	struct tm* t;
	time_t base = time(NULL);
	t = localtime(&base);
	printf ("Today : %d�� %d�� %d��\n ", t->tm_year + 1900, t->tm_mon+1, t->tm_mday);
	// --- //
	int inputTicket, inputTicketDetail, inputBirth, inputAmount, inputPremier;
	int resultPrice, premierPrice;
	int ageNumber, birthYear, birthDate, seventhDate, yearGap, interAge;
	int thisYear = t->tm_year + 1900, thisDate=316;
	const int FULL_1DAYPRICEADULT = 59000, FULL_1DAYPRICETEEN = 52000, FULL_1DAYPRICEKIDS = 47000, FULL_1DAYPRICEBABY = 15000;
	const int FULL_AFTER4PRICEADULT = 48000, FULL_AFTER4PRICETEEN = 42000, FULL_AFTER4PRICEKIDS = 36000, FULL_AFTER4PRICEBABY = 15000;
	const int PARK_1DAYPRICEADULT = 56000, PARK_1DAYPRICETEEN = 50000, PARK_1DAYPRICEKIDS = 46000, PARK_1DAYPRICEBABY = 15000;
	const int PARK_AFTER4PRICEADULT = 45000, PARK_AFTER4PRICETEEN = 40000, PARK_AFTER4PRICEKIDS = 35000, PARK_AFTER4PRICEBABY = 15000;
	char todayMonth, todayDay, today;
	
	todayMonth = t->tm_mon+1;
	todayDay = t->tm_mday;
	today = todayMonth + todayDay;
	
	printf("%d\n", thisYear);
	printf("%d %d %d\n", todayMonth, todayDay, today);
	
		
	do {																			//�Է� �ݺ�// 
		printf("Ƽ�� ������ �Է��ϼ���. \n 1. �����̿�� \n 2. ��ũ�̿��\n");
		
		scanf("%d", &inputTicket);
	
		printf("���� Ƽ�� ������ �Է��ϼ���. \n 1. 1Day \n 2. After4\n");
		scanf("%d", &inputTicketDetail);	
		
		printf("�ֹι�ȣ�� �Է��ϼ���(7�ڸ�����)\n");
		scanf("%d", &inputBirth);
	
		printf("��� �ֹ��Ͻðڽ��ϱ�? (�ִ� 10��)\n");
		scanf("%d", &inputAmount);
	
		printf("��� ������ �����ϼ���. \n 1. ����(���� ���� �ڵ�ó��) \n 2. �����\n 3. ����������\n 4. �ް��庴\n 5. �ӻ��\n 6. �ٵ��� �ູī��\n");
		scanf("%d", &inputPremier);
		
		if ( inputTicket > 2 || inputTicketDetail > 2 || inputBirth%10 > 5 || inputAmount > 10 || inputPremier > 7 )
		printf ("�Է��� �߸��Ǿ����ϴ�. �ٽ� �Է����ּ���\n\n");
	} while ( inputTicket > 2 || inputTicketDetail > 2 || inputBirth%10 > 5 || inputAmount > 10 || inputPremier > 7 );
	
	//���� ���// 
	ageNumber = inputBirth/100000; //�ֹι�ȣ 7�ڸ��� 10������ ������ ���� ���������� ��ȯ 
	birthDate = (inputBirth - (ageNumber*100000))/10; // (������� 7�ڸ� - ������*10��) = (����+�ֹ� ��ȣ 7�ڸ�) / 10 => ���� ������
	
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
	printf("%d\n", interAge);  */

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
		else (inputTicket == 2) ;											//��ũ  �̿�� ���� // 
			if (inputTicketDetail ==1 ){ 									// 1 Day //
			resultPrice = PARK_1DAYPRICEKIDS * inputAmount;
			}
			else  if (inputTicketDetail ==2 ){ 								// After4 //
			resultPrice = PARK_AFTER4PRICEKIDS * inputAmount;
			}
		}	
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
		else (inputTicket == 2) ;											//��ũ  �̿�� ���� // 
			if (inputTicketDetail ==1 ){ 									// 1 Day //
			resultPrice = PARK_1DAYPRICEADULT * inputAmount;
			}
			else  if (inputTicketDetail ==2 ){ 								// After4 //
			resultPrice = PARK_AFTER4PRICEADULT * inputAmount;
			}
		}
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
		else (inputTicket == 2) ;											//��ũ  �̿�� ���� // 
			if (inputTicketDetail ==1 ){ 									// 1 Day //
			resultPrice = PARK_1DAYPRICETEEN * inputAmount;
			}
			else  if (inputTicketDetail ==2 ){ 								// After4 //
			resultPrice = PARK_AFTER4PRICETEEN * inputAmount;
			}
		}
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
		else (inputTicket == 2) ;											//��ũ  �̿�� ���� // 
			if (inputTicketDetail ==1 ){ 									// 1 Day //
			resultPrice = PARK_1DAYPRICEKIDS * inputAmount;
			}
			else  if (inputTicketDetail ==2 ){ 								// After4 //
			resultPrice = PARK_AFTER4PRICEKIDS * inputAmount;
			}
		}
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
		else (inputTicket == 2) ;											//��ũ  �̿�� ���� // 
			if (inputTicketDetail ==1 ){ 									// 1 Day //
			resultPrice = PARK_1DAYPRICEBABY * inputAmount;
			}
			else  if (inputTicketDetail ==2 ){ 								// After4 //
			resultPrice = PARK_AFTER4PRICEBABY * inputAmount;
			}
		}
	}



	// ��� ��� ���� *����1���� ������ //
	
	printf ("������ Ƽ�� ������ : %d\n", inputTicket);
	printf ("������ ����Ƽ�� ������ : %d\n", inputTicketDetail);
	printf ("���� ���� : %d\n", interAge); 
	printf("�ֹ� ���� (�ִ� 10��) : %d\n", inputAmount);
	
	//�� 65�� �̻� �߰� ��� ���� �Ұ�// 
	if (interAge >= 65) {
		printf("65�� �̻����� ���̺��� ����\n");
		printf("������ %d�� �Դϴ�.", resultPrice);	
	}
	
	//��� ���� ����// 
	else if (inputPremier == 1) {
		premierPrice = resultPrice * 0.5;
		printf("����� ��� 50%% \n");
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
		printf("������ %d�� �Դϴ�.", premierPrice);
	}
	
	return 0;

}
