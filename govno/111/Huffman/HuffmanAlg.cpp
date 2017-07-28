#include "stdafx.h"
#include "HuffmanAlg.h"
namespace HuffmanAlg
{
//МЕТОДЫ КЛАССА Spisok
//подсчитывает символ
void Spisok::add(wchar_t n)	
{
	elem* cur = first;
	while( cur ){//пока current указывает на элемент списка
		if( cur->data.sym == n) //если нашли символ в списке
		{
			cur->data.num++;//увеличиваем кол-во на 1
			return ;	
		}
		cur = cur->next; //иначе переходим к следующему элементу
	}
	//если символ n в списке отсутствует
	//добавляем в список новый элемент
	add(n, 1);
}
//добавляем в список новый элемент
void Spisok::add(wchar_t n, int k)
{
	elem *newelement = new elem;//выделяем память под новый элемент
	newelement->data.sym = n;	//заполняем элемент начальными значениями
	newelement->data.num = k;
	newelement->data.freq = 0;
	
	newelement->next = NULL;	//добавляем элемент в конец
	newelement->prev = end;
	if(!first) 
	{
		first = newelement;
		iter = first;
	}
	if(end) end->next = newelement;
	end = newelement;
	length++;
	return ;
}

//подсчитывает символы в строке
void Spisok::calc(System::String^ str)
{
	lendth_text = str->Length;//длина строки
	for(int i = 0; i<lendth_text; i++)
		add(str[i]);
}
//сортировка списка по возрастанию
void Spisok::freq(){
	elem* current;
	current = first;
	while(current)
	{
		current->data.freq = (float)current->data.num / lendth_text;
		current = current->next;
	}
}
//простыми вставками
void Spisok::sort()
{
	if(!first) return;
	if(!first->next) return;
	elem* cur;//позиция для вставки(вставляем перед cur)
	elem* gr;//последний элемент отсортированной части
	elem* temp;//элемент добавляемый в упорядоченную часть
	gr = first;
	while( gr->next )
	{
		cur = first;
		while( ( cur != gr->next ) && ( gr->next->data.num >= cur->data.num ) )
			cur = cur->next;
		if( cur != gr->next )
		{
			temp = gr->next;
			if(cur->prev) cur->prev->next = temp;
			else first = temp;
			gr->next = temp->next;
			if(temp->next) temp->next->prev = gr;
			else end = gr;
			temp->next = cur;
			temp->prev = cur->prev;
			cur->prev = temp;
		}
		else
			gr = gr->next;
	}
	iter = first;
}
//отображает список
void Spisok::display(System::Windows::Forms::DataGridView^ dgv)
{
	dgv -> Rows -> Clear();//удаляем все строки
	elem* current;
	current = first;
	while(current)
	{
		dgv -> Rows -> Add(current->data.sym, (int)current->data.sym, current->data.num, current->data.freq, gcnew System::String(current->data.code) );
		current = current->next;
	}  
}

int Spisok::display_step(System::Windows::Forms::DataGridView^ dgv)
{
	dgv->Columns->Clear();//удаляем все столбцы
	dgv-> Rows  ->Clear();//удаляем все строки
	if( !length ) return 0;
	for(int i = 0; i < length; i++)	//добаляем x столбцов
	{
		dgv->Columns->Add("step"+(i+1), "шаг "+(i+1));
		dgv->Columns[i]->Width = 55;//устанавливаем ширину столбцов
		dgv->Columns[i]->Resizable = System::Windows::Forms::DataGridViewTriState::False;//запрешам изменять ширину столбцов
		dgv->Columns[i]->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
	}
	dgv -> Rows -> Add(length);//добавляем y строк
	int i = 0;
	elem* cur = end;
	while( cur )
	{
		dgv->Rows[i]->Cells[0]->Value = cur->data.num + " (" + cur->data.sym + ") ";
		dgv->Rows[i]->Resizable = System::Windows::Forms::DataGridViewTriState::False;//запрешам изменять ширину строк
		cur = cur->prev;
		i++;
	}
	return i;
}

int Spisok::get()
{
	if(!iter) return (-1);
	return iter->data.num;
}

uzel* Spisok::pop_front()
{
	uzel* res = new uzel;
	res->data = iter->data;
	res->potomok[0] = NULL;
	res->potomok[1] = NULL;
	iter = iter->next;
	return res;
}
//удаляет все элементы списка
void Spisok::clear(){
	if( !first ) return;
	while( first->next )
	{
		first = first->next;
		delete (first->prev);
	}
	delete first;
	first = NULL;
	end = NULL;
	length = 0;
}

//добавляет код (CODE) длины (N) для указанного символа (sym)
bool Spisok::add_code( wchar_t sym, char* CODE, int N)
{
	elem* cur = end;
	char* newcode = new char[N];
	strcpy( newcode, CODE );
	while( cur )
	{
		if( cur -> data.sym == sym )
		{
			cur -> data.code = newcode;
			return true;
		}
		cur = cur -> prev;
	}
	return false;
}

//возвращает код указанного символа (указатель на строку)
char* Spisok::get_code( wchar_t sym ) const
{
	elem* cur = end;
	while( cur )
	{
		if( cur -> data.sym == sym )
			return cur -> data.code;
		cur = cur -> prev;
	}
	return NULL;
}

bool Spisok::toFile(char* file_name)
{
	ofstream fspisok(file_name, ios::binary); //открываем файл на запись
	if (fspisok.fail()) 
		return false;
	elem* cur = first;
	fspisok.write(reinterpret_cast<char*>(&lendth_text), sizeof(int) );//длина исходного текста
	fspisok.write(reinterpret_cast<char*>(&length), sizeof(int) );//кол-во элементов
	while( cur )
	{
		fspisok.write(reinterpret_cast<char*>(&cur -> data.sym), sizeof(wchar_t) );//символ
		fspisok.write(reinterpret_cast<char*>(&cur -> data.num), sizeof(int) );//кол-во повторений	
		cur = cur -> next;
	}
	fspisok.close();
	return true;
}
//загружает список из файла c именем file_name
bool Spisok::fromFile(char* file_name)
{
	ifstream fspisok(file_name, ios::binary); //открываем файл на чтение
	if (fspisok.fail()) 
		return false;
	wchar_t n = 0;
	int m = 0;
	int i = 0;
	fspisok.read(reinterpret_cast<char*>(&lendth_text), sizeof(int) );//длина исходного текста
	fspisok.read(reinterpret_cast<char*>(&i), sizeof(int) );//кол-во элементов
	 
	while( i && !(fspisok.eof()) )
	{
		fspisok.read(reinterpret_cast<char*>(&n), sizeof(wchar_t) );//символ
		fspisok.read(reinterpret_cast<char*>(&m), sizeof(int) );//кол-во повторений
		add(n, m);//записываем их в список	
		i--;
	}
	fspisok.close();
	return true;
}
//Деструктор. Освобождает выделенную под элементы списка память
Spisok::~Spisok(){
	clear();
}
//МЕТОДЫ КЛАССА FIFO
//добавляет узел в конец очереди
void FIFO::push_back(uzel* n)
{
	elemFIFO *newelement = new elemFIFO;//выделяем память под новый элемент
	newelement->data = n;	//запоминаем указатель на узел
	newelement->next = NULL; //добовляем в конец следующего элемента нет
	if( !first )//если в очереди нет элементов
	{
		first = newelement;
		end = newelement;
		return;
	}
	end->next = newelement;
	end = newelement;
}

//удаляет узел из начала очереди
uzel* FIFO::pop_front( )
{
	if( !first ) return NULL;//если в очереди нет элементов
	uzel* res = first->data;
	if(first == end)//в списке 1 элемент
	{
		delete first;
		first = NULL;
		end = NULL;
		return res;
	}
	elemFIFO* temp = first->next;
	delete first;
	first = temp;
	return res;
}

//возвращает количество повторений
int FIFO::get()
{
	if(!first) return (-1);
	return first->data->data.num;
}

FIFO::~FIFO()
{
	if( !first ) return;
	elemFIFO* cur = first;
	while( cur->next )
	{
		first = cur->next;
		delete cur;
		cur = first;
	}
	delete first;
	first = NULL;
	end = NULL;
}

//МЕТОДЫ КЛАССА Tree
void Tree::create(Spisok& S, System::Windows::Forms::DataGridView^ dgv)
{
	if ( (S.get()==-1) ) return; //если в списке нет элементов завершаем процедуру
	int k = S.display_step(dgv);
	int step = 0;
	FIFO fifo;//очередь
	uzel* root = NULL;//узел объединяющий два узла с наименьшей частотой повторения
	int i = 0;
	while( 1 )
	{
		root = new uzel;
		root->data.num = 0;
		for(i = 0; (i<2); i++)
		{
			if( (fifo.get()!=-1) && ( (fifo.get()<=S.get())||(S.get()==-1) ) )///////////запомнить fifo.get()
			{
				root->data.num += fifo.get();			//берем узел из очереди
				root->potomok[i] = fifo.pop_front();
			}
			else
			{
				root->data.num += S.get();				//берем узел из списка
				root->potomok[i] = S.pop_front();
				num_list++;
				k--;
			}
			if( (S.get()==-1)&&(fifo.get()==-1) ) //если в списке и в очереди нет узлов
			{
				if( i == 1 )	//если root имеет двух потомков
					first = root;//root корень дерева
				else
				{
					first = root->potomok[0]; //иначе его потомок корень дерева
					delete root;
				}
				display_step(dgv, step, k, root->data.num);
				return;
			}
		}
		display_step(dgv, step, k, root->data.num);
		fifo.push_back(root);//добовляем новый узел в очередь
		step++;
	}
}

//рекурсивно русует поддерево с корнем now
int Tree::drow_uzel(uzel* now, System::Drawing::Graphics^& g, int start_h, int step_h, int sdvig, int& NUM_list)
{
	if( !now ) return 0;
	bool list = (now->potomok[0])?false:true;
	int center_l;
	int center_r;
	if(!list)
	{
		center_l = drow_uzel( now->potomok[0], g, start_h+step_h, step_h, sdvig, NUM_list);
		center_r = drow_uzel( now->potomok[1], g, start_h+step_h, step_h, sdvig, NUM_list);
	}
	else
	{
		center_l = LIST_W * NUM_list - LIST_W/2;
		NUM_list++;
		center_r = center_l + LIST_W;
	}
	DrowingTree::DrowUzel( now->data.sym, now->data.num, UZEL_W, step_h, g, center_l, center_r, start_h, sdvig, list);
	return (center_r+center_l)/2;
}
//рисует дерево
void Tree::drow_tree(System::Drawing::Graphics^ g, int finish_w, int sdvig_w, int sdvig_h )
{
	if( !first ) return;
	int step_h = 22;
	int NUM_list = 0;
	int start_w = 0;
	bool list = (first->potomok[0])?false:true;
	
	if(!list)
	{
		start_w = drow_uzel( first->potomok[0], g,  step_h+sdvig_h, step_h, sdvig_w, NUM_list);
		finish_w = drow_uzel( first->potomok[1], g, step_h+sdvig_h, step_h, sdvig_w, NUM_list);
	}
	DrowingTree::DrowUzel( first->data.sym, first->data.num, 50, step_h, g, start_w, finish_w, sdvig_h, sdvig_w, list);
}

//обходим дерево, получаем коды символов
bool Tree::serch_code(uzel* now, Spisok& S, char* TEMP, int i)
{
	if( !now ) return false;
	bool list = (now->potomok[0])?false:true;
	
	if(!list)
	{
		i++;
		TEMP[i]='\0';
		TEMP[i-1]='0';
		if( !serch_code( now->potomok[0], S, TEMP, i ) ) return false;
		TEMP[i]='\0';
		TEMP[i-1]='1';
		if( !serch_code( now->potomok[1], S, TEMP, i ) ) return false;
		return true;
	}
	return S.add_code( now->data.sym, TEMP, i+1);
}

//
bool Tree::codes(Spisok& S)
{
	if(!first) return false;
	char TEMP[256];
	TEMP[0] = '\0';
	int i = 0;
	return serch_code(first, S, TEMP, i);
}

//отображаем шаг построения дерева
void Tree::display_step(System::Windows::Forms::DataGridView^ dgv, int step, int i, int num)
{
	int len = (dgv->Columns->Count) - step;
	if (len<2) return;
	int j;
	for( j=0; j<i; j++ )
		dgv->Rows[j]->Cells[step+1]->Value = dgv->Rows[j]->Cells[step]->Value;
	dgv->Rows[i++]->Cells[step]->Style->BackColor = System::Drawing::Color::Red;
	dgv->Rows[i++]->Cells[step]->Style->BackColor = System::Drawing::Color::Red;
	for( i; i<len; i++, j++ )
		dgv->Rows[j]->Cells[step+1]->Value = dgv->Rows[i]->Cells[step]->Value;
	dgv->Rows[j]->Cells[step+1]->Style->Font = gcnew System::Drawing::Font("Arial", 14);
	dgv->Rows[j]->Cells[step+1]->Value = ""+ num;
}

//удаление всех элементов поддерева с корнем now
void Tree::clear_uzel(uzel* now)
{
	if( !now ) return; 
	if(now->potomok[0]) 
	{
		clear_uzel( now->potomok[0] );
		clear_uzel( now->potomok[1] );
	}
	delete now;
}
//удаление всех элементов дерева
void Tree::clear()
{
	if(!first) return; 
	clear_uzel(first);
	first = NULL;
}

Tree::~Tree()
{
	clear();
}

//возвращает закодированную строку str
System::String^ StrToCode(System::String^ str, const Spisok& S)
{
	System::String^ res;
	int lendth = str->Length;//длина строки
	res = "";
	for(int i = 0; i<lendth; i++)
		res += gcnew System::String(S.get_code(str[i]));
	return res;
}

}//namespace