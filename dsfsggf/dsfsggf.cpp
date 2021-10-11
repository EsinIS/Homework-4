/*
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
int main() {
	using namespace std;
	setlocale(0, "");
	string a, b, ctrl = "";
	int i, flag = 0, j;
	double x, sum;
	vector <double> arr;
	cout << "Запишите данные в файл." << endl;
	getline(cin, a);
	ofstream file("7.txt");
	file << a;
	file.close();
	ifstream file_1("7.txt");
	getline(file_1, b);
	b = b + " e";
	for (i = 0; i < b.size(); i++) {
		if (b[i] != ' ') {
			if (b[i] == '.') {
				b[i] = ',';
			}
			ctrl += b[i];
		}
		else {
			if (b[i + 1] == ' ') {
				continue;
			}
			else {
				flag = 0;
				if (ctrl[0] != '-' && (ctrl[0] < '0' || ctrl[0] > '9')) {
					flag = 1;
				}
				for (j = 1; j < ctrl.size() - 1; j++) {
					if (ctrl[j] != ',' && (ctrl[j] < '0' || ctrl[j] > '9')) {
						flag = 1;
					}
				}
				if (ctrl[ctrl.size() - 1] < '0' || ctrl[ctrl.size() - 1] > '9') {
					flag = 1;
				}
				sum = count(ctrl.begin(), ctrl.end(), ',');
				if (sum > 1) {
					flag = 1;
				}
				if (flag == 0) {
					x = stod(ctrl);
					arr.push_back(x);
					cout << x << endl;
				}
				else {
					cout << "Ошибка! Было введено что-то кроме чисел.";
					flag = 2;
					break;
				}

				ctrl = "";
				flag = 0;
			}
		}
	}
	sum = arr[0];
	if (flag != 2) {
		if (arr.size() < 10) {
			cout << "Вы ввели меньше 10 чисел!";
		}
		else {
			for (i = 1; i < arr.size(); i++) {
				sum = sum + arr[i];
			}
			cout << "Сумма всех чисел в файле равна: " << sum;
		}
	}
}
*/
/*
#include <iostream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <fstream>
double sign(double x) {
	if (x < 0) {
		return -1;
	}
	else if (x > 0) {
		return 1;
	}
	else {
		return 0;
	}
}
int main() {
	using namespace std;
	setlocale(0, "");
	cout << "Пожалуйста, введите число" << endl;
	double x;
	if (cin >> x) {
		cout << sign(x);
	}
	else {
		cout << "Пожалуйста, введите число";
	}

}
*/
/*
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
double rectangle(double a, double b) {
	return a * b;
}
double circle(double R) {
	return 3.1415 * R * R;
}
double triangle31(double a, double h) {
	return h * a / 2;
}
double triangle32(double a, double b, double x) {
	double degrees = x * 3.1415 / 180;
	return (a * b * sin(degrees)) / 2;
}
double triangle34(double a, double b, double c, double r) {
	double p = (a + b + c) / 2;
	return p * r;
}
double triangle35(double a, double b, double c, double R) {
	return (a * b * c) / (4 * R);
}
double triangle33(double a, double b, double c) {
	double p = (a + b + c) / 2;
	return pow((p * (p - a) * (p - b) * (p - c)), 0.5);
}
double triangle36(double a, double b) {
	return a * b / 2;
}
int main() {
	using namespace std;
	setlocale(0, "");
	int ctrl, ctrl2;
	double a, b, R, p, r, h, x, c;
	cout << "Для вычисления площади прямоугольника введите 1, для вычисления площади круга введите 2, для вычисления площади треугольника введите 3." << endl;
	if ((cin >> ctrl) && (0 < ctrl) && (ctrl < 4)) {
		if (ctrl == 1) {
			cout << "Введите стороны прямоугольника." << endl;
			if ((cin >> a >> b) && (a > 0) && (b > 0)) {
				cout << "S = " << rectangle(a, b);
			}
			else {
				cout << "Введите корректные данные.";
			}
		}
		else if (ctrl == 2) {
			cout << "Введите радиус окружности." << endl;
			if ((cin >> R) && (R > 0)) {
				cout << "S = " << circle(R);
			}
			else {
				cout << "Введите корректные данные.";
			}
		}
		else if (ctrl == 3) {
			cout << "Для нахождения площади треугольника через основание и высоту введите 31 \nДля нахождения площади через произведение двух сторон и синуса угла между ними введите 32 \nДля нахождения площади треугольника по формуле Геррона введите 33 \nДля нахождения площади описанного треугольника введите 34\nДля нахождения площади вписанного треугольника введите 35\nДля наождения площади прямого прямоугольника введие 36" << endl;
			if ((cin >> ctrl2) && ctrl2 > 30 && ctrl2 < 37) {
				if (ctrl2 == 31) {
					cout << "Введите основание и высоту." << endl;
					if ((cin >> a >> h) && a > 0 && h > 0) {
						cout << "S = " << triangle31(a, h);
					}
					else {
						cout << "Введите корректные данные.";
					}
				}
				else if (ctrl2 == 32) {
					cout << "Введите 2 стороны треугольника и угол между ними." << endl;
					if ((cin >> a >> b >> x) && a > 0 && b > 0 && x > 0) {
						cout << "S = " << triangle32(a, b, x);
					}
					else {
						cout << "Введите корректные данные.";
					}
				}
				else if (ctrl2 == 33) {
					cout << "Введите 3 стороны треугольника." << endl;
					if ((cin >> a >> b >> c) && a > 0 && b > 0 && c > 0 && min(min(a, b), c) + (a + b + c - max(max(a, b), c) - min(min(a, b), c)) > max(max(a, b), c)) {
						cout << "S = " << triangle33(a, b, c);
					}
					else {
						cout << "Введите корректные данные.";
					}
				}
				else if (ctrl2 == 34) {
					cout << "Введите 3 стороны и радиус вписанной в треугольник оркужности." << endl;
						if ((cin >> a >> b >> c >> r) && a > 0 && b > 0 && c > 0 && r > 0 && min(min(a, b), c) + (a + b + c - max(max(a, b), c) - min(min(a, b), c)) > max(max(a, b), c)) {
							cout << "S = " << triangle34(a, b, c, r);
						}
						else {
							cout << "Введите корректные данные.";
						}
				}
				else if (ctrl2 == 35) {
					cout << "Введите 3 стороны и радису окружности, описаной около треугольника." << endl;
					if ((cin >> a >> b >> c >> R) && a > 0 && b > 0 && c > 0 && R > 0 && min(min(a, b), c) + (a + b + c - max(max(a, b), c) - min(min(a, b), c)) > max(max(a, b), c)) {
						cout << "S = " << triangle35(a, b, c, R);
					}
					else {
						cout << "Введите корректные данные.";
					}
				}
				else if (ctrl2 == 36) {
					cout << "Введите 2 катета прямоугольного треугольника." << endl;
					if ((cin >> a >> b) && a > 0 && b > 0) {
						cout << "S = " << triangle36(a, b);
					}
					else {
						cout << "Введите корректные данные.";
					}
				}
			}
			else {
				cout << "Введите корректные данные.";
			}
		}
	}
	else {
		cout << "Введите корректные данные.";
	}
}
*/
/*
#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <map>
using namespace std;
int count(string s, char s1) {
	int ans = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == s1) {
			ans += 1;
		}
	}
	return ans;
}
*/
/*
int main() {
	using namespace std;
	setlocale(0, "");
	string s, ctrl, Rome;
	int flag = 0, i, ans = 0, n;
	cout << "Введите число в римской записи." << endl;
	Rome = "IVXLCDM";
	map <string, int> Units;
	Units["I"] = 1;
	Units["II"] = 2;
	Units["III"] = 3;
	Units["IV"] = 4;
	Units["V"] = 5;
	Units["VI"] = 6;
	Units["VII"] = 7;
	Units["VIII"] = 8;
	Units["IX"] = 9;
	map <string, int> Dozens;
	Dozens["X"] = 10;
	Dozens["XX"] = 20;
	Dozens["XXX"] = 30;
	Dozens["XL"] = 40;
	Dozens["L"] = 50;
	Dozens["LX"] = 60;
	Dozens["LXX"] = 70;
	Dozens["LXXX"] = 80;
	Dozens["XC"] = 90;
	map <string, int> Hundreds;
	Hundreds["C"] = 100;
	Hundreds["CC"] = 200;
	Hundreds["CCC"] = 300;
	Hundreds["CD"] = 400;
	Hundreds["D"] = 500;
	Hundreds["DC"] = 600;
	Hundreds["DCC"] = 700;
	Hundreds["DCCC"] = 800;
	Hundreds["CM"] = 900;
	map <string, int> Thousands;
	Thousands["M"] = 1000;
	Thousands["MM"] = 2000;
	Thousands["MMM"] = 3000;
	cin >> s;
	for (i = 0; i < s.size(); i++) {
		if (count(Rome, s[i]) == 0) {
			flag = 1;
			cout << "Введие римское число, используя только символы: I, V, X, L, C, D, M";
			break;
		}
	}
	if (flag == 0 && s.size() > 0) {
		ctrl = "";
		for (auto now : Thousands) {
			if (s.find(now.first) == 0) {
				ctrl = now.first;
			}
		}
		if (ctrl != "") {
			ans += Thousands[ctrl];
			s.replace(0, ctrl.size(), "");
		}
		ctrl = "";
	}
	if (flag == 0 && s.size() > 0) {
		ctrl = "";
		for (auto now : Hundreds) {
			if (s.find(now.first) == 0) {
				ctrl = now.first;
			}
		}
		if (ctrl != "") {
			ans += Hundreds[ctrl];
			s.replace(0, ctrl.size(), "");
		}
		ctrl = "";
	}
	if (flag == 0 && s.size() > 0) {
		ctrl = "";
		for (auto now : Dozens) {
			if (s.find(now.first) == 0) {
				ctrl = now.first;
			}
		}
		if (ctrl != "") {
			ans += Dozens[ctrl];
			s.replace(0, ctrl.size(), "");
		}
		ctrl = "";
	}
	if (flag == 0 && s.size() > 0) {
		ctrl = "";
		for (auto now : Units) {
			if (s.find(now.first) == 0) {
				ctrl = now.first;
			}
		}
		if (ctrl != "") {
			ans += Units[ctrl];
			s.replace(0, ctrl.size(), "");
		}
		ctrl = "";
	}
	if (s.size() > 0) {
		cout << "Введите корректное римское число.";
	}
	else {
		cout << "Ваше число в арабской записи будет выглядеть как " << ans;
	}
}
*/
/*
#include <iostream>
#include <cstdlib>
using namespace std;
int main() {
	char arr[13][49];
	int i, j;
	for (i = 0; i < 13; i++) {
		for (j = 0; j < 49; j++) {
			arr[i][j] = '*';
		}
	}
	for (i = 0; i < 13; i++) {
		for (j = 0; j < 49; j++) {
			if (i == 0) {
				arr[i][j] = '_';
			}
		}
	}
	for (i = 1; i < 7; i++) {
		for (j = 8; j < 49; j++) {
			if (i % 2 == 1) {
				arr[i][j] = '|';
			}
			else {
				arr[i][j] = '_';
			}
		}
	}
	for (i = 7; i < 13; i++) {
		for (j = 0; j < 49; j++) {
			if (i % 2 == 1) {
				arr[i][j] = '|';
			}
			else {
				arr[i][j] = '_';
			}
		}
	}
	for (i = 0; i < 13; i++) {
		for (j = 0; j < 49; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}
}
*/
/*
#include <iostream>
#include <math.h>
#include <windows.h>
#include <conio.h>
using namespace std;
int main()
{
	HWND hwnd;
	wchar_t Title[1024];
	GetConsoleTitle(Title, 1024);
	hwnd = FindWindow(NULL, Title);
	HDC hdc = GetDC(hwnd);
	int x = 0;
	for (float i = 34.6; i < 3.14 * 90; i += 0.05) {
		SetPixel(hdc, x, 50 + 30 * sin(i), RGB(255, 255, 255));
		x += 1;
	}
	ReleaseDC(hwnd, hdc);
	cin.ignore();
	return 0;
}
*/
/*
#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;
int main() {
	int arr1[100];
	arr1[0] = 0;
	int m1 = 37;
	int c1 = 64;
	for (int i = 1; i < 4; i++) {
		arr1[i] = (m1 * arr1[i - 1] + i - 1) % c1;
	}
	for (int i = 0; i < 4; i++) {
		cout << arr1[i] << endl;
	}
	int arr2[20000];
	arr2[0] = 0;
	int m = 25173;
	int c = 65537;
	for (int i = 1; i < 13850; i++) {
		arr2[i] = (m * arr2[i - 1] + i - 1) % c;
	}
	for (int i = 0; i < 13850; i++) {
		cout << arr2[i] << endl;
	}
}
*/
/*
#include <iostream>
#include <cstdlib>
using namespace std;
int main() {
	setlocale(0, "");
	int flag = 0;
	double sum1 = 0, sum2 = 0, sum3 = 0, max1 = 0, min1 = 0, max2 = 0, min2 = 0;
	int Table1[3][4];
	double Table2[4][2];
	double Table3[3][2];
	for (int i = 0; i < 3; i++) {
		if (flag == 0) {
			cout << "Пожалуйста, введите, сколько товаров каждого типа было у " << i + 1 << " " << "Продавца." << endl;
			for (int j = 0; j < 4; j++) {
				cout << "Пожалуйста, введите, сколько у продавца было товаров " << j + 1 << " " << "Типа." << endl;
				int a;
				if (cin >> a && a >= 0) {
					Table1[i][j] = a;
				}
				else {
					flag = 1;
					cout << "Пожалуйста, введите корректное значение!";
					break;
				}
			}
		}
	}
	if (flag == 0) {
		for (int i = 0; i < 4; i++) {
			if (flag == 0) {
				for (int j = 0; j < 2; j++) {
					if (j == 0) {
						cout << "Пожалуйста, введите цену товара " << i + 1 << " типа." << endl;
					}
					else {
						cout << "Пожалуйста, введите комиссионные за товар " << i + 1 << " типа." << endl;
					}
					double b;
					if (cin >> b && b > 0) {
						Table2[i][j] = b;
					}
					else {
						flag = 1;
						cout << "Введите корректное значение.";
						break;
					}
				}
			}
		}
	}
	if (flag == 0) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 2; j++) {
				Table3[i][j] = Table1[i][0] * Table2[0][j] + Table1[i][1] * Table2[1][j] + Table1[i][2] * Table2[2][j] + Table1[i][3] * Table2[3][j];
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			cout << Table3[i][j] << " ";
		}
		cout << endl;
	}
	if (flag == 0) {
		sum1 = Table3[0][0] + Table3[1][0] + Table3[2][0];
		sum2 = Table3[0][1] + Table3[1][1] + Table3[2][1];
		sum3 = sum1 + sum2;
		max1 = max(Table3[0][0], max(Table3[1][0], Table3[2][0]));
		min1 = min(Table3[0][0], min(Table3[1][0], Table3[2][0]));
		max2 = max(Table3[0][1], max(Table3[1][1], Table3[2][1]));
		min2 = min(Table3[0][1], min(Table3[1][1], Table3[2][1]));
		for (int i = 0; i < 3; i++) {
			if (Table3[i][0] == max1) {
				cout << "Продавец " << i + 1 << " выручил больше всего денег с продажи" << endl;
			}
			else if (Table3[i][0] == min1) {
				cout << "Продавец " << i + 1 << " выручил меньше всего денег с продажи" << endl;
			}
		}
		for (int i = 0; i < 3; i++) {
			if (Table3[i][1] == max2) {
				cout << "Продавец " << i + 1 << " выручил больше всего комиссионных" << endl;
			}
			else if (Table3[i][1] == min2) {
				cout << "Продавец " << i + 1 << " выручил меньше всего комиссионных" << endl;
			}
		}
		cout << "Сумма денег, вырученных за продажу товаров равна " << sum1 << endl;
		cout << "Сумма денег, вырученных с комиссионных " << sum2 << endl;
		cout << "Всего продавцы заработали " << sum3 << endl;
	}
}
*/
/*
#include <iostream>
#include <cstdlib>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;
int main() {
	setlocale(0, "");
	int a, b, flag = 0, x1=0, ctrl=0;
	string x, x2;
	cout << "Введите число x, систему счисления, в которой это число находится, и систему счисления, в которую вы хотите перевести своё число." << endl;
	if (cin >> x >> a >> b && a > 1 && b > 1) {
		for (int i = 0; i < x.size(); i++) {
			if ((int)x[i] < 48 || (int)x[i] > 90 || x[0] == '0') {
				flag = 1;
				cout << "Введите корректное число.";
				break;
			}
		}
	}
	if (flag == 0) {
		for (int i = 0; i < x.size(); i++) {
			if ((int)x[i] < 58) {
				if ((int)x[i] - 48 >= a) {
					flag = 1;
					cout << "Введите корректное число.";
					break;
				}
			}
			else if ((int)x[i] - 55 >= a) {
				flag = 1;
				cout << "Введите корректное число.";
				break;
			}
		}
	}
	if (flag == 0) {
		for (int i = 0; i < x.size(); i++) {
			if (x[i] <= '9') {
				x1 += ((int)x[i]-48)*pow(a, x.size()-1-i);
			}
			else {
				x1 += ((int)x[i] - 55) * pow(a, x.size() - 1 - i);
			}
		}
	}
	if (flag == 0) {
		while (x1 > 0) {
			ctrl = x1 % b;
			if (ctrl < 10) {
				x2 += (char)(ctrl + 48);
			}
			else {
				x2 += (char)(ctrl + 55);
			}
			x1 = x1 / b;
		}
	}
	reverse(x2.begin(), x2.end());
	cout << "Ваше число в " << b << " системе счисления будет выглядеть как \n";
	cout << x2;
}
*/