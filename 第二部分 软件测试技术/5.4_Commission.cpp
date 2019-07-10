// Commission.cpp
#include "stdio.h"
#include "math.h"

// �ú�����Chap5�׺в������õ���һ������
// ������Ҫ�����Ǽ���ÿ��������۶������Ա�����
// ����Ϊ�˷�������Ҫ��������ѭ����������ֱ�����趨�õ�����ȡ
double Commission()
{// alcohol, redWine��beer�ֱ��¼�׾ơ���ƺ�ơ�Ƶ�������������λ��ƿ��
	int alcoholPrice = 168;// �׾Ƶĵ���
	int redWinePrice = 120; // ��Ƶĵ���
	int beerPrice = 5; // ơ�Ƶĵ���

	int totalSales = 0;// ��¼���������۶�
	double totalCommission = 0.0;// �����
	int monthSales = 0;// ��¼ÿ�����۶�
	double commission = -1.0;// ��¼���

	int input[6][3] = { {50, 30, 300},// ������������
						{69, 49, 506},
						{143, 123, 1244 },
						{5000, 3000, 30000},
						{60, 39, 398},
						{106, 86, 875}	};
	double exp[6][2] = { {13500, 540.00},// Ԥ�����
						{20002, 800.02},
						{45004, 1050.02},
						{1350000, 7575.00},
						{16750, 670.00},
						{32503, 925.03} };
	int month = 0;
	while( month < 6 )
	{
		monthSales = alcoholPrice * input[month][0] + redWinePrice * input[month][1] + beerPrice * input[month][2];
		if( monthSales <= 20000 )// ������۶����20000Ԫ�Ĳ��֣���4%���
			commission = monthSales * 0.04;
		else if( monthSales <= 45000 )// ���۶����45000Ԫ�Ĳ��֣���1%���
			commission = (monthSales - 20000) * 0.01 + 20000 * 0.04;
		else// ���۶����45000Ԫ�Ĳ��֣���0.5%���
		commission = (monthSales - 45000) * 0.005 + (45000 - 20000) * 0.01 + 20000 * 0.04;

		printf( "alcohol = %d, redWine = %d, beer = %d, monthSales = %d, commission = %f------\n", 
			input[month][0], input[month][1], input[month][2], monthSales, commission );
		if( monthSales==exp[month][0] && fabs(commission-exp[month][1])<1e-3 )
			printf( "Pass.\n ");
		else
			printf( "Fail.\n" );

		totalSales = totalSales + monthSales;
		totalCommission = totalCommission + commission;

		month = month +1;
	}
	printf( "totalSales = %d, totalCommission = %f\n", totalSales, totalCommission );

	return totalCommission;
}

void main()
{
	Commission();
	int in;
	printf( "���������һ����������...\n" );
	scanf( "%d", &in );
}