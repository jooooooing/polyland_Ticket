#include <stdio.h>

int main(){
	int inputTicket, inputTicketDetail, inputBirth, inputAmount, inputPremier;
	int resultPrice;
	
	printf("Ƽ�� ������ �Է��ϼ���. \n 1. �����̿�� \n 2. ��ũ�̿��\n");
	scanf("%d", &inputTicket);
	
	printf("���� Ƽ�� ������ �Է��ϼ���. \n 1. 1Day \n 2. After4\n");
	scanf("%d", &inputTicketDetail);	
		
	printf("�ֹι�ȣ�� �Է��ϼ���(7�ڸ�����)\n");
	scanf("%d", &inputBirth);
	
	printf("��� �ֹ��Ͻðڽ��ϱ�? (�ִ� 10��)\n");
	scanf("%d", &inputAmount);
	
	printf("��� ������ �����ϼ���. \n 1. ����(���� ���� �ڵ�ó��) \n 2. �����\n 3. ����������\n 4. ���ڳ�\n 5. �ӻ�� \n");
	scanf("%d", &inputPremier);
	
	printf("������ %d �� �Դϴ�.", resultPrice);
	
	
	
	
	
	return 0; 
	
}
