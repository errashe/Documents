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
		wchar_t sym;//символ
		int num;	//кол-во повторений
		float freq;	//вероятность
		char* code; //код Хаффмана
		SymFreq(): sym(-1), num(-1), freq(-1), code(NULL)
		{ }
		~SymFreq(){
			if( code ) 
				delete [] code;
			code = NULL;
		}
	};	

	struct elem{//элемент списка
		SymFreq data;	//структура данных
		elem* next;		//указатель на следующий элемент
		elem* prev;		//указатель на предыдущий элемент
	};

	struct uzel{//узел дерева
		SymFreq data;	//структура данных
		uzel* potomok[2];//0 - left, 1 - right потомки
	};

	struct elemFIFO{//элемент очереди
		uzel* data;	//указатель на узел данных
		elemFIFO* next;		//указатель на следующий элемент
	};

class Spisok{//двусвязный список
private:
	elem *first;//указатель на первый элемент списка
	elem *end;//указатель на последний элемент списка
	elem *iter;
	int lendth_text; //кол-во символов в тексте
	int length; //кол-во элементов в списке
public:
	Spisok(): first(NULL), end(NULL), iter(NULL), lendth_text(-1), length(0)
	{ }

	void add(wchar_t n);		//подсчитывает символ
	void add(wchar_t, int);		//добавляет новый элемент символ и кол-во повторений
	void calc(System::String^ );//подсчитывает символы в строке
	void freq();
	void sort();				//сортировка списка
	void display(System::Windows::Forms::DataGridView^ );//отображает список
	int display_step(System::Windows::Forms::DataGridView^ );
	int get();	//возвращает количество повторений
	bool add_code( wchar_t , char* , int );
	char* Spisok::get_code( wchar_t sym ) const;
	uzel* pop_front(); 
	bool fromFile(char* );			//загружает список из файла
	bool toFile(char* );			//сохраняет список в файл
	void clear();
	~Spisok();
};
//очередь
class FIFO{
private:
	elemFIFO *first;//указатель на первый элемент
	elemFIFO *end;	//указатель на последний элемент
	
public:
	FIFO(): first(NULL), end(NULL)
	{ }

	void push_back(uzel* );	//добавляет узел в конец очереди
	uzel* pop_front( );		//удаляет узел из начала очереди
	int get();	//возвращает количество повторений
	~FIFO();
};
//дерево Хаффмана
class Tree{
private:
	uzel *first;
	int num_list;
	
public:
	Tree(): first(NULL), num_list(0)
	{ }
	void create(Spisok& , System::Windows::Forms::DataGridView^);//строит дерево из списка 
	//рекурсивно вызывается для потомков и рисует переданный узел
	int drow_uzel(uzel* , System::Drawing::Graphics^&,  int , int, int, int&);
	//рисует дерево
	void drow_tree(System::Drawing::Graphics^, int, int, int);
	void display_step(System::Windows::Forms::DataGridView^ , int , int , int );
	bool serch_code(uzel* , Spisok&, char* , int );
	bool codes(Spisok& );
	//удаление всех элементов поддерева переданного узла
	void clear_uzel(uzel* );
	void clear();//удаление всех элементов дерева
	~Tree();
};

//кодирование текста
System::String^ StrToCode(System::String^ , const Spisok& );
}//namespace

#endif