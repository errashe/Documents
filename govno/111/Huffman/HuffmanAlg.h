#ifndef HuffmanAlg_h
#define HuffmanAlg_h
#define NULL 0
//#include <iostream>
#include <string.h>
#include <fstream>
#include "DrowingTree.h"
namespace HuffmanAlg
{
	using namespace std;
	const int LIST_W = 35;
	const int UZEL_W = 50;
	
	struct SymFreq{
		wchar_t sym;//������
		int num;	//���-�� ����������
		float freq;	//�����������
		char* code; //��� ��������
		SymFreq(): sym(-1), num(-1), freq(-1), code(NULL)
		{ }
		~SymFreq(){
			if( code ) 
				delete [] code;
			code = NULL;
		}
	};	

	struct elem{//������� ������
		SymFreq data;	//��������� ������
		elem* next;		//��������� �� ��������� �������
		elem* prev;		//��������� �� ���������� �������
	};

	struct uzel{//���� ������
		SymFreq data;	//��������� ������
		uzel* potomok[2];//0 - left, 1 - right �������
	};

	struct elemFIFO{//������� �������
		uzel* data;	//��������� �� ���� ������
		elemFIFO* next;		//��������� �� ��������� �������
	};

class Spisok{//���������� ������
private:
	elem *first;//��������� �� ������ ������� ������
	elem *end;//��������� �� ��������� ������� ������
	elem *iter;
	int lendth_text; //���-�� �������� � ������
	int length; //���-�� ��������� � ������
public:
	Spisok(): first(NULL), end(NULL), iter(NULL), lendth_text(-1), length(0)
	{ }

	void add(wchar_t n);		//������������ ������
	void add(wchar_t, int);		//��������� ����� ������� ������ � ���-�� ����������
	void calc(System::String^ );//������������ ������� � ������
	void freq();
	void sort();				//���������� ������
	void display(System::Windows::Forms::DataGridView^ );//���������� ������
	int display_step(System::Windows::Forms::DataGridView^ );
	int get();	//���������� ���������� ����������
	bool add_code( wchar_t , char* , int );
	char* Spisok::get_code( wchar_t sym ) const;
	uzel* pop_front(); 
	bool fromFile(char* );			//��������� ������ �� �����
	bool toFile(char* );			//��������� ������ � ����
	void clear();
	~Spisok();
};
//�������
class FIFO{
private:
	elemFIFO *first;//��������� �� ������ �������
	elemFIFO *end;	//��������� �� ��������� �������
	
public:
	FIFO(): first(NULL), end(NULL)
	{ }

	void push_back(uzel* );	//��������� ���� � ����� �������
	uzel* pop_front( );		//������� ���� �� ������ �������
	int get();	//���������� ���������� ����������
	~FIFO();
};
//������ ��������
class Tree{
private:
	uzel *first;
	int num_list;
	
public:
	Tree(): first(NULL), num_list(0)
	{ }
	void create(Spisok& , System::Windows::Forms::DataGridView^);//������ ������ �� ������ 
	//���������� ���������� ��� �������� � ������ ���������� ����
	int drow_uzel(uzel* , System::Drawing::Graphics^&,  int , int, int, int&);
	//������ ������
	void drow_tree(System::Drawing::Graphics^, int, int, int);
	void display_step(System::Windows::Forms::DataGridView^ , int , int , int );
	bool serch_code(uzel* , Spisok&, char* , int );
	bool codes(Spisok& );
	//�������� ���� ��������� ��������� ����������� ����
	void clear_uzel(uzel* );
	void clear();//�������� ���� ��������� ������
	~Tree();
};

//����������� ������
System::String^ StrToCode(System::String^ , const Spisok& );
}//namespace

#endif