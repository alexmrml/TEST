/* ����������� �������� ������������ � ��������� ���������*/
#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <fstream>

using namespace std;

double Fn; //F(n)
double Gn; //G(n)
double ATg_FG;
double ATg_GF;
double pi;
double Nbegin; //����� ������� ���������
double Nend; //������ ������� ���������
double step; //��� ��������� ���������
double phi; //�������� ����
double k; //����������� ���������
double Delta; //������ �������
double Theta; //������ ������
double O_large; //������ ��-�������
double ii; //�������� ��������� ������� ������������
double M_PI = 3.1415;

void main()
{

	//��������� �� ����, � ������� �������������� ����-����� �������� 11
	ofstream fout("cppstudio.txt"); // �������� ����� ��� ������
									/*���� �������� ������ ����������, ���� ���������
									��������� ������ ���������, ������������ ���������*/
	cout << "Input Nbegin ";
	cin >> Nbegin; //����� �������, ���� ��������
	cout << "Input Nend ";
	cin >> Nend; //������ �������, ���� ��������
	cout << "Input step ";
	cin >> step; //��� ��������� ���������
	cout << "Input koefficient";
	cin >> k; //����������� ���������
	phi = M_PI / k;

	ii = Nbegin; //�������� ������� ����� ����� ������� ���������
	while (ii <= Nend)
	{
		Fn = (59 * ii) / (log(ii)); //������ �������� ������� F(n)
		Gn = 14 * (pow(sqrt(ii), log10(ii))); //	�������� ������� G(n)
		ATg_FG = atan(Fn / Gn);
		ATg_GF = atan(Gn / Fn);
		pi = ATg_FG - ATg_GF;
		Delta = phi - pi;
		Theta = fabs(pi) - phi;
		O_large = pi + phi;
		fout << ii << " " << Fn << " " << Gn << " " << ATg_FG << " " << ATg_GF << " " << pi << " " << Delta << " " << Theta << " " << O_large << " " << endl;
		//������ �������� � ����
		ii = ii + step; //��������� ���������� �������� ���������
	}//end while
	fout.close(); //������� ����
	system("pause");
}// end main
