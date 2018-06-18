/* подключение основных используемых в программе библиотек*/
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
double Nbegin; //Левая граница интервала
double Nend; //Правая граница интервала
double step; //Шаг изменения аргумента
//ИЗМЕНЕНИЕ
double phi; //Значение угла
double k; //Коэффициент кратности
double Delta; //Оценка «Дельта»
double Theta; //Оценка «Тетта»
double O_large; //Оценка «О-большое»
double ii; //Значение аргумента функций трудоемкости
double M_PI = 3.1415;

void main()
{

	//Указатель на файл, в который осуществляется ввод-вывод расчетов 11
	ofstream fout("cppstudio.txt"); // открытие файла для записи
									/*Ввод значений границ интервалов, шага изменения
									аргумента внутри интервала, коэффициента кратности*/
	cout << "Input Nbegin ";
	cin >> Nbegin; //Левая граница, ввод значения
	cout << "Input Nend ";
	cin >> Nend; //Правая граница, ввод значения
	cout << "Input step ";
	cin >> step; //Шаг изменения аргумента
	cout << "Input koefficient";
	cin >> k; //Коэффициент кратности
	phi = M_PI / k;

	ii = Nbegin; //Аргумент функций равен левой границе интервала
	while (ii <= Nend)
	{
		Fn = (59 * ii) / (log(ii)); //Расчет значения функции F(n)
		Gn = 14 * (pow(sqrt(ii), log10(ii))); //	значения функции G(n)
		ATg_FG = atan(Fn / Gn);
		ATg_GF = atan(Gn / Fn);
		pi = ATg_FG - ATg_GF;
		Delta = phi - pi;
		Theta = fabs(pi) - phi;
		O_large = pi + phi;
		fout << ii << " " << Fn << " " << Gn << " " << ATg_FG << " " << ATg_GF << " " << pi << " " << Delta << " " << Theta << " " << O_large << " " << endl;
		//Запись расчетов в файл
		ii = ii + step; //Получение следующего значения аргумента
	}//end while
	fout.close(); //Закрыли файл
	system("pause");
}// end main
