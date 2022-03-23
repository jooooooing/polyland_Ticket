#include <stdio.h>
#include <time.h>


int main(){
	
	// 현재 날짜 구하기 // 
	struct tm* t;
	time_t base = time(NULL);
	t = localtime(&base);
	printf ("\t\t\t\tToday : %d년 %d월 %d일\n ", t->tm_year + 1900, t->tm_mon+1, t->tm_mday);
		// 배열 선언 //
	
	int reportArray[50000][6] = {0};
	int restart; 
	
	// 변수 선언 //
	
	for(;;){
	int row = 0;
	int inputTicket =0 , inputTicketDetail=0, inputBirth=0, inputAmount=0, inputPremier=0;
	int resultPrice=0, premierPrice=0, reOrder;
	int ageNumber=0, birthYear=0, birthDate=0, yearGap=0, interAge=0, birthMonth=0, birthDay=0, customerType=0; 
	int thisYear = t->tm_year + 1900, todayDate = (t->tm_year + 1900)*10000 + (t->tm_mon+1)*100 + t->tm_mday; 
	const int FULL_1DAYPRICEADULT = 59000, FULL_1DAYPRICETEEN = 52000, FULL_1DAYPRICEKIDS = 47000, FULL_1DAYPRICEBABY = 15000;
	const int FULL_AFTER4PRICEADULT = 48000, FULL_AFTER4PRICETEEN = 42000, FULL_AFTER4PRICEKIDS = 36000, FULL_AFTER4PRICEBABY = 15000;
	const int PARK_1DAYPRICEADULT = 56000, PARK_1DAYPRICETEEN = 50000, PARK_1DAYPRICEKIDS = 46000, PARK_1DAYPRICEBABY = 15000;
	const int PARK_AFTER4PRICEADULT = 45000, PARK_AFTER4PRICETEEN = 40000, PARK_AFTER4PRICEKIDS = 35000, PARK_AFTER4PRICEBABY = 15000;
	char todayMonth, todayDay, today;
	
	
	for(;;){
		
		// 이용권 종류 선택 //
		do {	
			printf("\nⅠ.티켓 종류를 입력하세요. \n 1. 종합이용권 \n 2. 파크이용권\n");
			scanf("%d", &inputTicket);
			
			if ( inputTicket > 2){
			printf ("입력이 잘못되었습니다. 다시 입력해주세요\n\n");
			}
		} while (inputTicket >2);
		
		// 종일권, After4 선택 // 
		do {
			printf("\nⅡ.세부 티켓 종류를 입력하세요. \n 1. 1Day \n 2. After4\n");
			scanf("%d", &inputTicketDetail);
			
			if ( inputTicketDetail > 2){
			printf ("입력이 잘못되었습니다. 다시 입력해주세요\n\n");
			} 
		}while (inputTicketDetail >2);
						
		do {
			printf("\nⅢ.주민번호를 입력하세요(7자리까지)\n");
			scanf("%d", &inputBirth);
				ageNumber = inputBirth/100000; //주민번호 7자리를 10만으로 나누어 생년 정수형으로 변환
				birthDate = (inputBirth - (ageNumber*100000))/10; // (생년월일 7자리 - 생년정수형*10만) = (생일+주민 번호 7번째 자리) / 10 => 생일 정수형 1018+1 / 10 = 1018
				birthMonth = (birthDate / 100); // 10월 18일 => 10
				birthDay = birthDate - ((birthDate / 100) * 100); // 10월 18일 ==> 18  
			if ( inputBirth%10 >= 5 || inputBirth%10 ==0 || inputBirth <= 999999 || inputBirth >= 10000000 || birthDate > 1231 || birthDate < 101 || birthMonth > 12 || birthDay > 31){
			printf ("입력이 잘못되었습니다. 다시 입력해주세요\n\n");
			}
		} while (inputBirth%10 >= 5 || inputBirth%10 ==0 || inputBirth <= 999999 || inputBirth >= 10000000 || birthDate > 1231 || birthDate < 101 || birthMonth > 12 || birthDay > 31);
		
		
		do {
			printf("\nⅣ.몇개를 주문하시겠습니까? (최대 10개)\n");
			scanf("%d", &inputAmount);
			
			if ( inputAmount > 10 || inputAmount <1 ){
			printf ("입력이 잘못되었습니다. 다시 입력해주세요\n");
			}
		} while (inputAmount > 10 || inputAmount <1);
		
		
		
		do {
			printf("\nⅤ.우대 사항을 선택하세요. \n 1. 없음(나이 우대는 자동처리) \n 2. 장애인\n 3. 국가유공자\n 4. 휴가장병\n 5. 임산부\n 6. 다둥이 행복카드\n");
			scanf("%d", &inputPremier);
			
			if (inputPremier > 7){
			printf ("입력이 잘못되었습니다. 다시 입력해주세요\n\n");
			}
		} while (inputPremier > 7);	
		
	
		
	//나이 계산// 

	

	
	if (inputBirth % 5 <= 2) { //주민번호 7자리를 5로 나눈 나머지 값이 2보다 작거나 같을경우 1,2 = 1900년대 생 
		birthYear = (inputBirth / 100000)+ 1900;
	}
	
	else if (inputBirth%5 >= 3){ //주민번호 7자리를 5로 나눈 나머지가 3보다 크거나 같을 경우 3,4 = 2000년대 생 
		birthYear = (inputBirth / 100000) + 2000;
	}
	
	yearGap = thisYear - birthYear;
	
	if (birthDate > 323) { // 생일이 3월 23일 이후인 사람  -> 오늘 날짜로 계산하는 방식 적용 필요 
		interAge = yearGap - 1;
	} 
	else if (birthDate <= 323 ) { //생일이 3월 23일 이전인 사람 -> 오늘 날짜로 계산하는 방식 적용 필요
		interAge  = yearGap;
	}
	
	/* 나이 계산 확인용 
	printf("%d\n", ageNumber);
	printf("%d\n", birthDate);
	printf("%d\n", birthYear);
	printf("%d\n", birthMonth);
	printf("%d\n", birthDay); 
	printf("%d\n", yearGap);	
	printf("%d\n", interAge); */
    	
	// 티켓 값 계산 //
	// 만 65세 이상 // 	
	if (interAge >= 65)	{
		if(inputTicket == 1) {   											//종일 이용권 선택 // 
			if (inputTicketDetail ==1 ){  									// 1 Day //
			resultPrice = FULL_1DAYPRICEKIDS * inputAmount;
			}
			else  if (inputTicketDetail ==2 ){ 								// After4 //
			resultPrice = FULL_AFTER4PRICEKIDS * inputAmount;
			}
		}		
		else if(inputTicket == 2){											//파크  이용권 선택 // 
			if (inputTicketDetail ==1 ){ 									// 1 Day //
			resultPrice = PARK_1DAYPRICEKIDS * inputAmount;
			}
			else  if (inputTicketDetail ==2 ){ 								// After4 //
			resultPrice = PARK_AFTER4PRICEKIDS * inputAmount;
			}
		}
	customerType = 1; //고객유형 1 = 만 65세 이상 
	} 
	
	// 어른 만 19세 이상  ~ 만 65세 미만//
	
	else if (interAge >= 19){
		if(inputTicket == 1) {   											//종일 이용권 선택 // 
			if (inputTicketDetail ==1 ){  									// 1 Day //
			resultPrice = FULL_1DAYPRICEADULT * inputAmount;
			}
			else  if (inputTicketDetail ==2 ){ 								// After4 //
			resultPrice = FULL_AFTER4PRICEADULT * inputAmount;
			}
		}
		else if(inputTicket == 2){											//파크  이용권 선택 // 
			if (inputTicketDetail ==1 ){ 									// 1 Day //
			resultPrice = PARK_1DAYPRICEADULT * inputAmount;
			}
			else  if (inputTicketDetail ==2 ){ 								// After4 //
			resultPrice = PARK_AFTER4PRICEADULT * inputAmount;
			}
		}	
	customerType = 2; //고객유형 2 = 어른 : 만 19세 이상 ~만 65세 미만
	}
		
	// 청소년 만 13세 이상 ~ 만 18세 이하 //
	
	else if (interAge >= 13){
		if(inputTicket == 1) {   											//종일 이용권 선택 // 
			if (inputTicketDetail ==1 ){  									// 1 Day //
			resultPrice = FULL_1DAYPRICETEEN * inputAmount;
			}
			else  if (inputTicketDetail ==2 ){ 								// After4 //
			resultPrice = FULL_AFTER4PRICETEEN * inputAmount;
			}
		}
		else if(inputTicket == 2) {											//파크  이용권 선택 // 
			if (inputTicketDetail ==1 ){ 									// 1 Day //
			resultPrice = PARK_1DAYPRICETEEN * inputAmount;
			}
			else  if (inputTicketDetail ==2 ){ 								// After4 //
			resultPrice = PARK_AFTER4PRICETEEN * inputAmount;
			}
		}
	customerType = 3; //고객유형 3 = 청소년 : 만 13세 이상 ~만 18세 이하
	}
		
	// 어린이 36개월(만 3세) 이상 ~ 만 12세 이하 //
	
	else if (interAge >= 3){
		if(inputTicket == 1) {   											//종일 이용권 선택 // 
			if (inputTicketDetail ==1 ){  									// 1 Day //
			resultPrice = FULL_1DAYPRICEKIDS * inputAmount;
			}
			else  if (inputTicketDetail ==2 ){ 								// After4 //
			resultPrice = FULL_AFTER4PRICEKIDS * inputAmount;
			}
		}
		else if(inputTicket == 2){											//파크  이용권 선택 // 
			if (inputTicketDetail ==1 ){ 									// 1 Day //
			resultPrice = PARK_1DAYPRICEKIDS * inputAmount;
			}
			else  if (inputTicketDetail ==2 ){ 								// After4 //
			resultPrice = PARK_AFTER4PRICEKIDS * inputAmount;
			}
		}
	customerType = 4; //고객유형 4 = 어린이 : 만 36개월 이상 ~만 12세 이하	
	}		


	// 베이비 0개월 이상 ~ 36개월 (만3세) 미만 //
	
	else if (interAge < 3){
		if(inputTicket == 1) {   											//종일 이용권 선택 // 
			if (inputTicketDetail ==1 ){  									// 1 Day //
			resultPrice = FULL_1DAYPRICEBABY * inputAmount;
			}
			else  if (inputTicketDetail ==2 ){ 								// After4 //
			resultPrice = FULL_AFTER4PRICEBABY * inputAmount;
			}
		}
		else if(inputTicket == 2) {										//파크  이용권 선택 // 
			if (inputTicketDetail ==1 ){ 									// 1 Day //
			resultPrice = PARK_1DAYPRICEBABY * inputAmount;
			}
			else  if (inputTicketDetail ==2 ){ 								// After4 //
			resultPrice = PARK_AFTER4PRICEBABY * inputAmount;
			}
		}
	customerType = 5; //고객유형 5 = 어린이 : 만 0개월 이상 ~만 36개월 미만
	}
		
	// 우대 요금 적용 *동반1인은 미적용 //
	//만 65세 이상 추가 우대 적용 불가// 
	if (interAge >= 65) {
		premierPrice = resultPrice * 1;
		printf("65세 이상으로 어린이요금 적용\n");
		printf("가격은 %d원 입니다.\n", premierPrice);	
	}
	
	//우대 사항 없음// 
	else if (inputPremier == 1) {
		premierPrice = resultPrice * 1;
		printf("우대사항 없음 \n"); 
		printf("가격은 %d원 입니다.\n", premierPrice);
	}
			
	//장애인 우대 50% // 
	else if (inputPremier == 2) {
		premierPrice = resultPrice * 0.5;
		printf("장애인 우대 50%% \n");
		printf("가격은 %d원 입니다.\n", premierPrice);
	}
	
	//국가유공자 우대 50% //
	else if (inputPremier == 3) {
		premierPrice = resultPrice * 0.5;
		printf("국가유공자  우대 50%% \n");
		printf("가격은 %d원 입니다.\n", premierPrice);
	}
	
	//휴가장병  우대 49% //
	else if (inputPremier == 4) {
		if (inputTicket ==1) {
		premierPrice = resultPrice * 0.5 + 500;
		printf("휴가장병 우대 49%% \n");
		printf("가격은 %d원 입니다.\n", premierPrice);
		}
		else if (inputTicket ==2) {
		premierPrice = resultPrice * 1;
		printf("파크이용권은 우대 적용 불가 \n");
		printf("가격은 %d원 입니다.\n", premierPrice);			
		}
				
	}
	
	//임산부  우대 50% //
	else if (inputPremier == 5) {
		if (inputTicket == 1) {
		premierPrice = resultPrice * 0.5;
		printf("임산부 우대 50%% \n");
		printf("가격은 %d원 입니다.\n", premierPrice);	
		}
		else if (inputTicket ==2) {
		premierPrice = resultPrice * 1;
		printf("파크이용권은 우대 적용 불가 \n");
		printf("가격은 %d원 입니다.\n", premierPrice);			
		}
	}
	
	//다둥이 행복카드 우대 30% //
	else if (inputPremier == 6) {
		if (inputTicket ==1){
		premierPrice = resultPrice * 0.7;
		printf("다둥이 행복카드 본인 30%% \n");
		printf("가격은 %d원 입니다.\n", premierPrice);			
		}
		else if (inputTicket ==2) {
		premierPrice = resultPrice * 1;
		printf("파크이용권은 우대 적용 불가 \n");
		printf("가격은 %d원 입니다.\n", premierPrice);
		}
	}
	
	reportArray[row][0] = inputTicket;
	reportArray[row][1] = inputTicketDetail;
	reportArray[row][2] = inputAmount;
	reportArray[row][3] = inputPremier;
	reportArray[row][4] = customerType;
	reportArray[row][5] = premierPrice;
	
	//개별 발권 결과 // 
	printf("\n========================================= 발권   결과 ======================================\n");
	printf ("\n선택한 티켓 종류는 : %d\n", inputTicket);
	printf ("선택한 세부티켓 종류는 : %d\n", inputTicketDetail);
	printf ("나이 구분 : %d세\n", interAge); 
	printf("주문 갯수 (최대 10개) : %d개\n", inputAmount);
	printf("티켓 금액은 %d원 \n", premierPrice);
	
	printf("\n============================================================================================\n");	
	
	// 계속 예매 선택 //
	printf("\n\n이어서 발권하시겠습니까? \n 1.예\n 2.아니요\n");
	scanf("%d", &reOrder); 
			
	if (reOrder == 2) {
		
		break;
	}
	
	else { 
		row ++; 
	} 

} 
	
	FILE *filePointer = fopen("report.csv", "a");
	printf("\n========================================= 발권  내역 =======================================\n");
	printf("%10s\t%10s\t%10s\t%10s\t%10s\t%10s\n","이용권 종류","이용 시간","발권 수량","우대 구분","고객구분","입장료 총액");
	printf("%10s\t%10s\t%10s\t%10s\t%10s\t%10s","(종합/파크)","(1Day/After4)"," (매) ","(1-6)","(1~6) ","(원)");
	printf("\n============================================================================================\n");
	
	for (int i=0; i<=row; i++){
			for (int j=0; j<6; j++){
				printf("%10d\t",reportArray[i][j]);
			}			
			
		printf("\n");
	}
	for (int i=0; i<=row; i++){
		fprintf(filePointer, "%d%d%d, %d, %d, %d, %d, %d, %d\n", t->tm_year + 1900, t->tm_mon+1, t->tm_mday, reportArray[i][0], reportArray[i][1], reportArray[i][2], reportArray[i][3],
															reportArray[i][4], reportArray[i][5]);	
	}
	

printf("\n이용해주셔서 감사합니다.\n");
printf("\n계속 진행 (1:새로운 주문, 2: 프로그램 종료) : ");
scanf("%d", &restart);

if(restart == 2) {
	printf("\n프로그램을 종료합니다."); 
	break;
}

else {
	printf("\n=========================================새로 발권=======================================");
}
}
	return 0;

}
