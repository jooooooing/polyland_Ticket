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
	const int full_1DayPriceAdult = 59000, full_1DayPriceTeen = 52000, full_1DayPriceKids = 47000, full_1DayPriceBaby = 15000;
	const int full_After4PriceAdult = 48000, full_After4PriceTeen = 42000, full_After4PriceKids = 36000, full_After4PriceBaby = 15000;
	const int park_1DayPriceAdult = 56000, park_1DayPriceTeen = 50000, park_1DayPriceKids = 46000, park_1DayPriceBaby = 15000;
	const int park_After4PriceAdult = 45000, park_After4PriceTeen = 40000, park_After4PriceKids = 35000, park_After4PriceBaby = 15000;
	char todayMonth, todayDay, today;
	
	todayMonth = t->tm_mon+1;
	todayDay = t->tm_mday;
	today = todayMonth + todayDay;
	
	printf("%d\n", thisYear);
	printf("%d %d %d\n", todayMonth, todayDay, today);
	
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
	
	printf("%d\n", ageNumber);
	printf("%d\n", birthDate);
	printf("%d\n", birthYear);
	printf("%d\n", yearGap);	
	printf("%d\n", interAge);  
	
	// --- //
	
	// Ƽ�� �� ��� //
	// �� 65�� �̻� // 
	
	if (interAge >= 65 && inputTicket == 1 && inputTicketDetail == 1) {
		resultPrice = full_1DayPriceKids * inputAmount;
	}
	
	else if (interAge >= 65 && inputTicket == 1 && inputTicketDetail == 2) {
		resultPrice = full_After4PriceKids * inputAmount;
	}
	
	else if (interAge >= 65 && inputTicket == 2 && inputTicketDetail == 1) {
		resultPrice = park_1DayPriceKids * inputAmount;
	}
	
	else if (interAge >= 65 && inputTicket == 2 && inputTicketDetail == 2) {
		resultPrice = park_After4PriceKids * inputAmount;
	}
	
	// � �� 19�� �̻�  ~ �� 65�� �̸�//
	
	if (interAge >= 19 && interAge < 65 && inputTicket == 1 && inputTicketDetail == 1) {
		resultPrice = full_1DayPriceAdult * inputAmount;
	}
	
	else if (interAge >= 19 && interAge < 65 && inputTicket == 1 && inputTicketDetail == 2) {
		resultPrice = full_After4PriceAdult * inputAmount;
	}
	
	else if (interAge >= 19 && interAge < 65 && inputTicket == 2 && inputTicketDetail == 1) {
		resultPrice = park_1DayPriceAdult * inputAmount;
	}
	
	else if (interAge >= 19 && interAge < 65 && inputTicket == 2 && inputTicketDetail == 2) {
		resultPrice = park_After4PriceAdult * inputAmount;
	}
	 
	// û�ҳ� �� 13�� �̻� ~ �� 18�� ���� //
	
	if (interAge >= 13 && interAge <= 18 && inputTicket == 1 && inputTicketDetail == 1) {
		resultPrice = full_1DayPriceTeen * inputAmount;
	}
	
	else if (interAge >= 13 && interAge <= 18 && inputTicket == 1 && inputTicketDetail == 2) {
		resultPrice = full_After4PriceTeen * inputAmount;
	}
	
	else if (interAge >= 13 && interAge <= 18 && inputTicket == 2 && inputTicketDetail == 1) {
		resultPrice = park_1DayPriceTeen * inputAmount;
	}
	
	else if (interAge >= 13 && interAge <= 18 && inputTicket == 2 && inputTicketDetail == 2) {
		resultPrice = park_After4PriceTeen * inputAmount;
	} 
	
	// ��� 36����(�� 3��) �̻� ~ �� 12�� ���� //
	
	if (interAge >= 3 && interAge <= 12 && inputTicket == 1 && inputTicketDetail == 1) {
		resultPrice = full_1DayPriceKids * inputAmount;
	}
	
	else if (interAge >= 3 && interAge <= 12 && inputTicket == 1 && inputTicketDetail == 2) {
		resultPrice = full_After4PriceKids * inputAmount;
	}
	
	else if (interAge >= 3 && interAge <= 12 && inputTicket == 2 && inputTicketDetail == 1) {
		resultPrice = park_1DayPriceKids * inputAmount;
	}
	
	else if (interAge >= 3 && interAge <= 12 && inputTicket == 2 && inputTicketDetail == 2) {
		resultPrice = park_After4PriceKids * inputAmount;
	} 
	
		// ���̺� 0���� �̻� ~ 36���� (��3��) �̸� //
	
	if (interAge < 3 && inputTicket == 1 && inputTicketDetail == 1) {
		resultPrice = full_1DayPriceBaby * inputAmount;
	}
	
	else if (interAge < 3 && inputTicket == 1 && inputTicketDetail == 2) {
		resultPrice = full_1DayPriceBaby * inputAmount;
	}
	
	else if (interAge < 3 && inputTicket == 2 && inputTicketDetail == 1) {
		resultPrice = full_1DayPriceBaby * inputAmount;
	}
	else if (interAge < 3 && inputTicket == 2 && inputTicketDetail == 2) {
		resultPrice = full_1DayPriceBaby * inputAmount;
	}

	// ��� ��� ���� *����1���� ������ //
	
	//�� 65�� �̻� ��� ���� �Ұ�// 
	if (interAge >= 65) {
		printf("65�� �̻����� ���̺��� ����\n");
		printf("������ %d�� �Դϴ�.", resultPrice); 
	}
	
	//��� ���� ����// 
	else if (inputPremier == 1) {
		printf("������ ����\n");
		printf("������ %d�� �Դϴ�.", resultPrice); 
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
