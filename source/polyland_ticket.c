#include <stdio.h>

int main(){
	int inputTicket, inputTicketDetail, inputBirth, inputAmount;
	
	printf("티켓 종류를 입력하세요. \n 1. 종합이용권 \n 2. 파크이용권\n");
	scanf("%d", &inputTicket);
	
	printf("세부 티켓 종류를 입력하세요. \n 1. 1Day \n 2. After4\n");
	scanf("%d", &inputTicketDetail);	
		
	printf("주민번호를 입력하세요(7자리까지)\n");
	scanf("%d", &inputBirth);
	
	printf("몇개를 주문하시겠습니까? (최대 10개)\n");
	scanf("%d", &inputAmount);
	
	
	
	
	return 0; 
	
}
