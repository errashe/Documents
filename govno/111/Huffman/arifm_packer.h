#pragma once
#include <cmath>
#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
using namespace std;

#define MAX_SYMBOLS 256					//количетсво символов в ASCII  таблице

struct symbol							//структура, описывающа€ один элемент из таблицы символов
{
	unsigned char symb;					//символ
	double freq;						//веро€тность по€вление в тексте
	double high, low;					//верхни€ и нижн€€ границы символа
};


static long all_freq;					//общее количество символов	
static symbol code_table[MAX_SYMBOLS];	//таблица символов
static double code_res;					//резльтат кодировани€
static int code_len;					//длинна кода

void initialization()					//заполнение таблицы нул€ми
{
	for (int i = 0; i<MAX_SYMBOLS; i++)
	{
		code_table[i].freq = 0;
		code_table[i].high = 0;
		code_table[i].low = 0;
		code_table[i].symb = 'q';
	}
	all_freq = 0;
}

void add_freq(unsigned char symb)		//функци€ добавлени€ частоты символа в таблицу(примен€етс€ в функции init_table)
{
	code_table[symb].freq++;
	code_table[symb].symb = symb;
	all_freq++;
}


void init_table(unsigned char *str, int N) //инициализаци€ таблицы в соответствие с кодируемой строкой
{
	for (int i = 0; i<N; i++)
		add_freq(str[i]);
	for (int i = 0; i<MAX_SYMBOLS; i++)
		code_table[i].freq /= all_freq;
}

void set_interval()							//растановка интервалов символов в диапазоне [0;1]
{
	//cout<<"================"<<endl;
	double low = 0;
	for (int i = 0; i<MAX_SYMBOLS; i++)
	{
		if (code_table[i].freq != 0)
		{
			code_table[i].low = low;
			//cout<<code_table[i].symb<<endl;
			//cout<<"freq="<<code_table[i].freq<<endl;
			//cout<<"low="<<low<<endl;
			code_table[i].high = low + code_table[i].freq;
			//cout<<"high="<<code_table[i].high<<endl;
			//cout<<endl;
			low = code_table[i].high;
		}
	}
}


double start_coding(unsigned char *str, int N)					//кодирование строки
{
	//unsigned long code=0;
	double low_old = code_table[str[0]].low, high_old = code_table[str[0]].high;
	double low = 0, high = 1;

	//cout<<"================"<<endl;
	for (int i = 1; i<N; i++)
	{
		high = low_old + (high_old - low_old)*code_table[str[i]].high;
		low = low_old + (high_old - low_old)*code_table[str[i]].low;
		//cout<<"res="<<low<<endl;
		low_old = low;
		high_old = high;
	}
	return low;
}

unsigned char decode_symbol(double *code)				//декодирование символа(примен€етс€ в функции start_decoding)
{
	//unsigned char s;
	for (int i = 0; i<MAX_SYMBOLS; i++)
	{
		if (code_table[i].low <= *code && code_table[i].high >= *code)
		{
			*code = (*code - code_table[i].low) / (code_table[i].high - code_table[i].low);
			return code_table[i].symb;
		}
	}

}

unsigned char* start_decoding(double code, int N)			//декодирование входного кода в строку
{
	unsigned char *str = new unsigned char[N];
	for (int i = 0; i<N; i++)
	{
		str[i] = decode_symbol(&code);
	}
	str[N - 1] = 0;
	cout << str << endl;
	return str;
}


void writeToFile(int len, double time, double code_res)
{
	ofstream out_file("result_arifm/table.txt", ios::app);
	if (!out_file) return;

	char buf1[100], buf2[100];
	out_file << len << "         " << time << endl;
	ofstream res_file("result_arifm/res.txt", ios::app);
	if (!res_file) return;
	int N = 16;
	res_file << setprecision(N) << code_res << endl;

}
