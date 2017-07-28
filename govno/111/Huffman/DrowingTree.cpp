#include "stdafx.h"
#include "DrowingTree.h"
namespace DrowingTree{

using namespace System::Drawing;
void DrowUzel(wchar_t ch, int num, int w, int h, Graphics^ g, int start_w, int finish_w, int start_h, int sdvig, bool list)
{
	int center_w = (start_w + finish_w)/2 + sdvig;
	int rect_w = w-2*SPACE_W;	//������ ��������������
	int rect_h = h-SPACE_H;		//������ ��������������
	int rect_start_w = center_w - rect_w/2;//�������� ������� �������������� �� �
	int rect_finish_w = rect_start_w + rect_w;//�������� ������� �������������� �� �
	
	//int line_len = (finish_w - start_w)/4;//����� ����� 
	int line_len = (finish_w - start_w)/2;//����� �����
	//int line_start  = center_w - line_len;//�������� ������� ����� �� �
	//int line_finish = center_w + line_len;//�������� ������� ����� �� �
	int line_start  = start_w + sdvig;//�������� ������� ����� �� �
	int line_finish = finish_w + sdvig;//�������� ������� ����� �� �
	int line_h = start_h + h - 2*SPACE_H;//�������� ������� ����� �� �

	Pen^ pen = gcnew Pen(Color::Blue);
	SolidBrush^ drawBrushCh = gcnew SolidBrush(Color::White);
	SolidBrush^ drawBrushNum = gcnew SolidBrush(Color::Red);
	//SolidBrush^ drawBrushRect = gcnew SolidBrush(Color::Navy);
	SolidBrush^ drawBrushRectList = gcnew SolidBrush(Color::Black);
    Font^ drawFontCh = gcnew Font("Arial", (float)FONT);
	Font^ drawFontNum = gcnew Font("Arial", (float)FONT-1);
  
    StringFormat^ drawFormat = gcnew StringFormat();
	
	if(!list)//���� �� ����
	{
		g->DrawLine(pen, line_start,	line_h, line_finish, line_h		);
		//����� �����
		g->DrawLine(pen, line_start,	line_h, line_start,	 start_h+h-1	);
		//������ �����
		g->DrawLine(pen, line_finish,	line_h, line_finish, start_h+h-1	);
	}
	
	if(list)//���� ����
	{
		//�������������
		int rect_l_w = (rect_w+rect_w)/3;
		g->FillRectangle(drawBrushRectList, Rectangle(center_w-rect_l_w/2, start_h, rect_l_w, rect_h+rect_h ));
		//�������
		g->DrawString( (""+ch) , drawFontCh, drawBrushCh, center_w-8, start_h, drawFormat);
		g->DrawString((""+num) , drawFontNum, drawBrushNum, center_w-rect_l_w/2, start_h+FONT+7, drawFormat);
	}
	else//���� �� ����
	{
		//�������������
		g->FillRectangle(drawBrushRectList, Rectangle(rect_start_w, start_h, list?(rect_w/2):(rect_w), list?(rect_h+rect_h):rect_h) );
		//�������
		g->DrawString((""+num) , drawFontNum, drawBrushNum, rect_start_w, start_h+2, drawFormat);
		g->DrawString("0", drawFontNum, drawBrushCh, rect_start_w-line_len/2-3, start_h+2, drawFormat);
		g->DrawString("1", drawFontNum, drawBrushCh, rect_finish_w+line_len/2-9, start_h+2, drawFormat);
	}
}
}//namespace