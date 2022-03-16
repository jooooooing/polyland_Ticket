#include <stdio.h>
#include <time.h>


int main(){
	
	// 현재 날짜 구하기 // 
	struct tm* t;
	time_t base = time(NULL);
	t = localtime(&base);
	printf ("Today : %d년 %d월 %d일\n ", t->tm_year + 1900, t->tm_mon+1, t->tm_mday);
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
	
	printf("티켓 종류를 입력하세요. \n 1. 종합이용권 \n 2. 파크이용권\n");
	scanf("%d", &inputTicket);
	
	printf("세부 티켓 종류를 입력하세요. \n 1. 1Day \n 2. After4\n");
	scanf("%d", &inputTicketDetail);	
		
	printf("주민번호를 입력하세요(7자리까지)\n");
	scanf("%d", &inputBirth);
	
	printf("몇개를 주문하시겠습니까? (최대 10개)\n");
	scanf("%d", &inputAmount);
	
	printf("우대 사항을 선택하세요. \n 1. 없음(나이 우대는 자동처리) \n 2. 장애인\n 3. 국가유공자\n 4. 휴가장병\n 5. 임산부\n 6. 다둥이 행복카드\n");
	scanf("%d", &inputPremier);
	
	//나이 계산// 
	ageNumber = inputBirth/100000; //주민번호 7자리를 10만으로 나누어 생년 정수형으로 변환 
	birthDate = (inputBirth - (ageNumber*100000))/10; // (생년월일 7자리 - 정수형*10만) = (생일+주민 번호 7자리) / 10 => 생일 정수형
	
	if (inputBirth % 5 <= 2) { //주민번호 7자리를 5로 나눈 나머지 값이 2보다 작거나 같을경우 1,2 = 1900년대 생 
		birthYear = (inputBirth / 100000)+ 1900;
	}
	
	else if (inputBirth%5 >= 3){ //주민번호 7자리를 5로 나눈 나머지가 3보다 크거나 같을 경우 3,4 = 2000년대 생 
		birthYear = (inputBirth / 100000) + 2000;
	}
	
	yearGap = thisYear - birthYear;
	
	if (birthDate > 316) { // 생일이 3월 16일 이후인 사람  
		interAge = yearGap - 1;
	}
	else if (birthDate <= 316 ) { //생일이 3월 16일 이전인 사람 
		interAge  = yearGap;
	}
	
	printf("%d\n", ageNumber);
	printf("%d\n", birthDate);
	printf("%d\n", birthYear);
	printf("%d\n", yearGap);	
	printf("%d\n", interAge);  
	
	// --- //
	
	// 티켓 값 계산 //
	// 만 65세 이상 // 
	
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
	
	// 어른 만 19세 이상  ~ 만 65세 미만//
	
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
	 
	// 청소년 만 13세 이상 ~ 만 18세 이하 //
	
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
	
	// 어린이 36개월(만 3세) 이상 ~ 만 12세 이하 //
	
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
	
		// 베이비 0개월 이상 ~ 36개월 (만3세) 미만 //
	
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

	// 우대 요금 적용 *동반1인은 미적용 //
	
	//만 65세 이상 우대 적용 불가// 
	if (interAge >= 65) {
		printf("65세 이상으로 베이비요금 적용\n");
		printf("가격은 %d원 입니다.", resultPrice); 
	}
	
	//우대 사항 없음// 
	else if (inputPremier == 1) {
		printf("우대사항 없음\n");
		printf("가격은 %d원 입니다.", resultPrice); 
	}
	
	//장애인 우대 50% // 
	else if (inputPremier == 2) {
		premierPrice = resultPrice * 0.5;
		printf("장애인 우대 50%% \n");
		printf("가격은 %d원 입니다.", premierPrice);
	}
	
	//국가유공자 우대 50% //
	else if (inputPremier == 3) {
		premierPrice = resultPrice * 0.5;
		printf("국가유공자  우대 50%% \n");
		printf("가격은 %d원 입니다.", premierPrice);
	}
	
	//휴가장병  우대 49% //
	else if (inputPremier == 4 && inputTicket==1) {
		premierPrice = resultPrice * 0.5 + 500;
		printf("휴가장병 우대 49%% \n");
		printf("가격은 %d원 입니다.", premierPrice);
	}
	
	//임산부  우대 50% //
	else if (inputPremier == 5 && inputTicket==1) {
		premierPrice = resultPrice * 0.5;
		printf("임산부 우대 50%% \n");
		printf("가격은 %d원 입니다.", premierPrice);
	}
	
	//다둥이 행복카드 우대 30% //
	else if (inputPremier == 6 && inputTicket==1) {
		premierPrice = resultPrice * 0.7;
		printf("다둥이 행복카드 본인 30%% \n");
		printf("가격은 %d원 입니다.", premierPrice);
	}
	
	
	return 0;

	
}
