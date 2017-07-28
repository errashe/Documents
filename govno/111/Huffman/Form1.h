#include "HuffmanAlg.h"
#include "DrowingTree.h"
#include <windows.h>
#include <math.h>
#include "arifm_packer.h"


#pragma once
namespace Huffman {

	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace HuffmanAlg;
	using namespace DrowingTree;
	using namespace System::Runtime::InteropServices;
	int str_len(unsigned char *str)
	{
		int i;
		for (i = 0; str[i] != '\0'; i++);
		return i + 1;
	}

	char * and_SysStringToChar(System::String^ string)
	{
		return (char*)(void*)Marshal::StringToHGlobalAnsi(string);
	}

	System::String^  and_CharToSysString(unsigned char* ch)
	{
		unsigned char * chr = ch;
		System::String^ str;
		for (int i = 0; chr[i] != '\0'; i++)
		{
			str += wchar_t(ch[i]);
		}
		return str;
	}
	//константы
	const int Step_TreeSdvig = 80;
	const int Start_TreeSdvig_W = 12;
	const int Start_TreeSdvig_H = 3;
	//глобальные переменные
	Spisok Table;
	Tree HaffmanTree;
	int TreeSdvig_W = Start_TreeSdvig_W;
	int TreeSdvig_H = Start_TreeSdvig_H;
	/// <summary>
	/// Сводка для Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^  tcMain;
	private: System::Windows::Forms::TabPage^  tpEnter;
	private: System::Windows::Forms::TabPage^  tpFreq;
	private: System::Windows::Forms::Button^  bNextEnter;
	private: System::Windows::Forms::Button^  bOpenEnter;
	private: System::Windows::Forms::Button^  bSaveEnter;
	private: System::Windows::Forms::TextBox^  tbEnter;
	private: System::Windows::Forms::OpenFileDialog^  ofdEnter;
	private: System::Windows::Forms::SaveFileDialog^  sfdEnter;
	private: System::Windows::Forms::DataGridView^  dgvFreq;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  sym;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Unicode;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  num;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  freq;
	private: System::Windows::Forms::TabPage^  tpDrowTree;

	private: System::Windows::Forms::PictureBox^  pbTree;
	private: System::Windows::Forms::Button^  bTreeCenter;
	private: System::Windows::Forms::Button^  bTreeRight;
	private: System::Windows::Forms::Button^  bTreeLeft;
	private: System::Windows::Forms::Button^  bTreeDown;
	private: System::Windows::Forms::Button^  bTreeUp;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  code;
	private: System::Windows::Forms::TabPage^  tpSteps;
	private: System::Windows::Forms::DataGridView^  dgvSteps;
	private: System::Windows::Forms::TabPage^  tpOut;
	private: System::Windows::Forms::TextBox^  tbOut;
	private: System::Windows::Forms::TextBox^  tbTime;
	private: System::Windows::Forms::Label^  lTime;
	private: System::Windows::Forms::Label^  lEnterLength;
	private: System::Windows::Forms::Label^  lEnterText;
	private: System::Windows::Forms::Label^  lEnterSize;
	private: System::Windows::Forms::Label^  l2;

	private: System::Windows::Forms::Label^  l1;
	private: System::Windows::Forms::Label^  lHafSize;
	private: System::Windows::Forms::Label^  l4;
	private: System::Windows::Forms::Label^  l3;
	private: System::Windows::Forms::Button^  bOpenRes;
	private: System::Windows::Forms::Button^  bSaveRes;
	private: System::Windows::Forms::OpenFileDialog^  ofdRes;
	private: System::Windows::Forms::SaveFileDialog^  sfdRes;
	private: System::Windows::Forms::TabPage^  tpEks;
	private: System::Windows::Forms::Button^  bEks;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  tbEksStart;
	private: System::Windows::Forms::TextBox^  tbEksStep;
	private: System::Windows::Forms::TextBox^  tbEksSize;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::DataGridView^  dgvEks;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  EksNum;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  EksTime;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  EksN;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  EksN2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  EksXN;

	private: System::Windows::Forms::TextBox^  tbEksRes1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::GroupBox^  gbRes;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  tbDepakTime;
	private: System::Windows::Forms::TextBox^  tbPakTime;
	private: System::Windows::Forms::TextBox^  tbKoff;
	private: System::Windows::Forms::TextBox^  tbResCoding;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::DataGridView^  dgvTable;
	private: System::Windows::Forms::CheckBox^  cbExp;
	private: System::Windows::Forms::TextBox^  tbCode;
	private: System::Windows::Forms::RadioButton^  rbDepak;
	private: System::Windows::Forms::RadioButton^  rbPaked;





















	protected: 



	private:
		/// <summary>
		/// Требуется переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Обязательный метод для поддержки конструктора - не изменяйте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->tcMain = (gcnew System::Windows::Forms::TabControl());
			this->tpEnter = (gcnew System::Windows::Forms::TabPage());
			this->bNextEnter = (gcnew System::Windows::Forms::Button());
			this->bOpenEnter = (gcnew System::Windows::Forms::Button());
			this->bSaveEnter = (gcnew System::Windows::Forms::Button());
			this->tbEnter = (gcnew System::Windows::Forms::TextBox());
			this->tpSteps = (gcnew System::Windows::Forms::TabPage());
			this->dgvSteps = (gcnew System::Windows::Forms::DataGridView());
			this->tpDrowTree = (gcnew System::Windows::Forms::TabPage());
			this->bTreeDown = (gcnew System::Windows::Forms::Button());
			this->bTreeUp = (gcnew System::Windows::Forms::Button());
			this->bTreeCenter = (gcnew System::Windows::Forms::Button());
			this->bTreeRight = (gcnew System::Windows::Forms::Button());
			this->bTreeLeft = (gcnew System::Windows::Forms::Button());
			this->pbTree = (gcnew System::Windows::Forms::PictureBox());
			this->tpFreq = (gcnew System::Windows::Forms::TabPage());
			this->bOpenRes = (gcnew System::Windows::Forms::Button());
			this->bSaveRes = (gcnew System::Windows::Forms::Button());
			this->lHafSize = (gcnew System::Windows::Forms::Label());
			this->l4 = (gcnew System::Windows::Forms::Label());
			this->l3 = (gcnew System::Windows::Forms::Label());
			this->lEnterSize = (gcnew System::Windows::Forms::Label());
			this->l2 = (gcnew System::Windows::Forms::Label());
			this->l1 = (gcnew System::Windows::Forms::Label());
			this->lEnterLength = (gcnew System::Windows::Forms::Label());
			this->lEnterText = (gcnew System::Windows::Forms::Label());
			this->tbTime = (gcnew System::Windows::Forms::TextBox());
			this->lTime = (gcnew System::Windows::Forms::Label());
			this->dgvFreq = (gcnew System::Windows::Forms::DataGridView());
			this->sym = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Unicode = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->num = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->freq = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->code = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tpOut = (gcnew System::Windows::Forms::TabPage());
			this->tbOut = (gcnew System::Windows::Forms::TextBox());
			this->tpEks = (gcnew System::Windows::Forms::TabPage());
			this->tbEksRes1 = (gcnew System::Windows::Forms::TextBox());
			this->bEks = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tbEksStart = (gcnew System::Windows::Forms::TextBox());
			this->tbEksStep = (gcnew System::Windows::Forms::TextBox());
			this->tbEksSize = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dgvEks = (gcnew System::Windows::Forms::DataGridView());
			this->EksNum = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->EksTime = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->EksN = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->EksN2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->EksXN = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->gbRes = (gcnew System::Windows::Forms::GroupBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->tbDepakTime = (gcnew System::Windows::Forms::TextBox());
			this->tbPakTime = (gcnew System::Windows::Forms::TextBox());
			this->tbKoff = (gcnew System::Windows::Forms::TextBox());
			this->tbResCoding = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->dgvTable = (gcnew System::Windows::Forms::DataGridView());
			this->cbExp = (gcnew System::Windows::Forms::CheckBox());
			this->tbCode = (gcnew System::Windows::Forms::TextBox());
			this->rbDepak = (gcnew System::Windows::Forms::RadioButton());
			this->rbPaked = (gcnew System::Windows::Forms::RadioButton());
			this->ofdEnter = (gcnew System::Windows::Forms::OpenFileDialog());
			this->sfdEnter = (gcnew System::Windows::Forms::SaveFileDialog());
			this->ofdRes = (gcnew System::Windows::Forms::OpenFileDialog());
			this->sfdRes = (gcnew System::Windows::Forms::SaveFileDialog());
			this->tcMain->SuspendLayout();
			this->tpEnter->SuspendLayout();
			this->tpSteps->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvSteps))->BeginInit();
			this->tpDrowTree->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbTree))->BeginInit();
			this->tpFreq->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvFreq))->BeginInit();
			this->tpOut->SuspendLayout();
			this->tpEks->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvEks))->BeginInit();
			this->tabPage1->SuspendLayout();
			this->gbRes->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvTable))->BeginInit();
			this->SuspendLayout();
			// 
			// tcMain
			// 
			this->tcMain->Controls->Add(this->tpEnter);
			this->tcMain->Controls->Add(this->tpSteps);
			this->tcMain->Controls->Add(this->tpDrowTree);
			this->tcMain->Controls->Add(this->tpFreq);
			this->tcMain->Controls->Add(this->tpOut);
			this->tcMain->Controls->Add(this->tpEks);
			this->tcMain->Controls->Add(this->tabPage1);
			this->tcMain->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tcMain->Location = System::Drawing::Point(0, 0);
			this->tcMain->Margin = System::Windows::Forms::Padding(4);
			this->tcMain->Name = L"tcMain";
			this->tcMain->SelectedIndex = 0;
			this->tcMain->Size = System::Drawing::Size(1286, 558);
			this->tcMain->TabIndex = 0;
			this->tcMain->Enter += gcnew System::EventHandler(this, &Form1::tcMain_Enter);
			// 
			// tpEnter
			// 
			this->tpEnter->Controls->Add(this->bNextEnter);
			this->tpEnter->Controls->Add(this->bOpenEnter);
			this->tpEnter->Controls->Add(this->bSaveEnter);
			this->tpEnter->Controls->Add(this->tbEnter);
			this->tpEnter->Location = System::Drawing::Point(4, 25);
			this->tpEnter->Margin = System::Windows::Forms::Padding(4);
			this->tpEnter->Name = L"tpEnter";
			this->tpEnter->Padding = System::Windows::Forms::Padding(4);
			this->tpEnter->Size = System::Drawing::Size(1278, 529);
			this->tpEnter->TabIndex = 0;
			this->tpEnter->Text = L"Ввод исходных данных";
			this->tpEnter->UseVisualStyleBackColor = true;
			// 
			// bNextEnter
			// 
			this->bNextEnter->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->bNextEnter->Location = System::Drawing::Point(1112, 494);
			this->bNextEnter->Margin = System::Windows::Forms::Padding(4);
			this->bNextEnter->Name = L"bNextEnter";
			this->bNextEnter->Size = System::Drawing::Size(120, 28);
			this->bNextEnter->TabIndex = 3;
			this->bNextEnter->Text = L"Расчет";
			this->bNextEnter->UseVisualStyleBackColor = true;
			this->bNextEnter->Click += gcnew System::EventHandler(this, &Form1::bNextEnter_Click);
			// 
			// bOpenEnter
			// 
			this->bOpenEnter->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->bOpenEnter->Location = System::Drawing::Point(11, 494);
			this->bOpenEnter->Margin = System::Windows::Forms::Padding(4);
			this->bOpenEnter->Name = L"bOpenEnter";
			this->bOpenEnter->Size = System::Drawing::Size(147, 28);
			this->bOpenEnter->TabIndex = 2;
			this->bOpenEnter->Text = L"Открыть";
			this->bOpenEnter->UseVisualStyleBackColor = true;
			this->bOpenEnter->Click += gcnew System::EventHandler(this, &Form1::bOpenEnter_Click);
			// 
			// bSaveEnter
			// 
			this->bSaveEnter->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->bSaveEnter->Location = System::Drawing::Point(165, 494);
			this->bSaveEnter->Margin = System::Windows::Forms::Padding(4);
			this->bSaveEnter->Name = L"bSaveEnter";
			this->bSaveEnter->Size = System::Drawing::Size(147, 28);
			this->bSaveEnter->TabIndex = 1;
			this->bSaveEnter->Text = L"Сохранить как...";
			this->bSaveEnter->UseVisualStyleBackColor = true;
			this->bSaveEnter->Click += gcnew System::EventHandler(this, &Form1::bSaveEnter_Click);
			// 
			// tbEnter
			// 
			this->tbEnter->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tbEnter->BackColor = System::Drawing::SystemColors::Window;
			this->tbEnter->Location = System::Drawing::Point(4, 4);
			this->tbEnter->Margin = System::Windows::Forms::Padding(4);
			this->tbEnter->Multiline = true;
			this->tbEnter->Name = L"tbEnter";
			this->tbEnter->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->tbEnter->Size = System::Drawing::Size(1266, 482);
			this->tbEnter->TabIndex = 0;
			// 
			// tpSteps
			// 
			this->tpSteps->Controls->Add(this->dgvSteps);
			this->tpSteps->Location = System::Drawing::Point(4, 25);
			this->tpSteps->Margin = System::Windows::Forms::Padding(4);
			this->tpSteps->Name = L"tpSteps";
			this->tpSteps->Padding = System::Windows::Forms::Padding(4);
			this->tpSteps->Size = System::Drawing::Size(1278, 529);
			this->tpSteps->TabIndex = 3;
			this->tpSteps->Text = L"Промежуточные решения по итерациям";
			this->tpSteps->UseVisualStyleBackColor = true;
			// 
			// dgvSteps
			// 
			this->dgvSteps->AllowUserToAddRows = false;
			this->dgvSteps->AllowUserToDeleteRows = false;
			this->dgvSteps->BackgroundColor = System::Drawing::Color::White;
			this->dgvSteps->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvSteps->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dgvSteps->Location = System::Drawing::Point(4, 4);
			this->dgvSteps->Margin = System::Windows::Forms::Padding(4);
			this->dgvSteps->Name = L"dgvSteps";
			this->dgvSteps->ReadOnly = true;
			this->dgvSteps->RowHeadersVisible = false;
			this->dgvSteps->Size = System::Drawing::Size(1270, 521);
			this->dgvSteps->TabIndex = 0;
			// 
			// tpDrowTree
			// 
			this->tpDrowTree->Controls->Add(this->bTreeDown);
			this->tpDrowTree->Controls->Add(this->bTreeUp);
			this->tpDrowTree->Controls->Add(this->bTreeCenter);
			this->tpDrowTree->Controls->Add(this->bTreeRight);
			this->tpDrowTree->Controls->Add(this->bTreeLeft);
			this->tpDrowTree->Controls->Add(this->pbTree);
			this->tpDrowTree->Location = System::Drawing::Point(4, 25);
			this->tpDrowTree->Margin = System::Windows::Forms::Padding(4);
			this->tpDrowTree->Name = L"tpDrowTree";
			this->tpDrowTree->Padding = System::Windows::Forms::Padding(4);
			this->tpDrowTree->Size = System::Drawing::Size(1278, 529);
			this->tpDrowTree->TabIndex = 2;
			this->tpDrowTree->Text = L"Кодовое дерево";
			this->tpDrowTree->UseVisualStyleBackColor = true;
			// 
			// bTreeDown
			// 
			this->bTreeDown->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->bTreeDown->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->bTreeDown->Location = System::Drawing::Point(54, 489);
			this->bTreeDown->Margin = System::Windows::Forms::Padding(4);
			this->bTreeDown->Name = L"bTreeDown";
			this->bTreeDown->Size = System::Drawing::Size(31, 28);
			this->bTreeDown->TabIndex = 5;
			this->bTreeDown->TabStop = false;
			this->bTreeDown->Text = L"D";
			this->bTreeDown->UseVisualStyleBackColor = true;
			this->bTreeDown->Click += gcnew System::EventHandler(this, &Form1::bTreeDown_Click);
			// 
			// bTreeUp
			// 
			this->bTreeUp->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->bTreeUp->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->bTreeUp->Location = System::Drawing::Point(54, 418);
			this->bTreeUp->Margin = System::Windows::Forms::Padding(4);
			this->bTreeUp->Name = L"bTreeUp";
			this->bTreeUp->Size = System::Drawing::Size(31, 28);
			this->bTreeUp->TabIndex = 4;
			this->bTreeUp->TabStop = false;
			this->bTreeUp->Text = L"U";
			this->bTreeUp->UseVisualStyleBackColor = true;
			this->bTreeUp->Click += gcnew System::EventHandler(this, &Form1::bTreeUp_Click);
			// 
			// bTreeCenter
			// 
			this->bTreeCenter->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->bTreeCenter->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->bTreeCenter->Location = System::Drawing::Point(54, 453);
			this->bTreeCenter->Margin = System::Windows::Forms::Padding(4);
			this->bTreeCenter->Name = L"bTreeCenter";
			this->bTreeCenter->Size = System::Drawing::Size(31, 28);
			this->bTreeCenter->TabIndex = 3;
			this->bTreeCenter->TabStop = false;
			this->bTreeCenter->Text = L" ";
			this->bTreeCenter->UseVisualStyleBackColor = true;
			this->bTreeCenter->Click += gcnew System::EventHandler(this, &Form1::bTreeCenter_Click);
			// 
			// bTreeRight
			// 
			this->bTreeRight->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->bTreeRight->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->bTreeRight->Location = System::Drawing::Point(93, 453);
			this->bTreeRight->Margin = System::Windows::Forms::Padding(4);
			this->bTreeRight->Name = L"bTreeRight";
			this->bTreeRight->Size = System::Drawing::Size(31, 28);
			this->bTreeRight->TabIndex = 2;
			this->bTreeRight->TabStop = false;
			this->bTreeRight->Text = L"R";
			this->bTreeRight->UseVisualStyleBackColor = true;
			this->bTreeRight->Click += gcnew System::EventHandler(this, &Form1::bTreeRight_Click);
			// 
			// bTreeLeft
			// 
			this->bTreeLeft->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->bTreeLeft->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->bTreeLeft->Location = System::Drawing::Point(17, 453);
			this->bTreeLeft->Margin = System::Windows::Forms::Padding(4);
			this->bTreeLeft->Name = L"bTreeLeft";
			this->bTreeLeft->Size = System::Drawing::Size(31, 28);
			this->bTreeLeft->TabIndex = 1;
			this->bTreeLeft->TabStop = false;
			this->bTreeLeft->Text = L"L";
			this->bTreeLeft->UseVisualStyleBackColor = true;
			this->bTreeLeft->Click += gcnew System::EventHandler(this, &Form1::bTreeLeft_Click);
			// 
			// pbTree
			// 
			this->pbTree->BackColor = System::Drawing::Color::DarkGray;
			this->pbTree->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pbTree->Location = System::Drawing::Point(4, 4);
			this->pbTree->Margin = System::Windows::Forms::Padding(4);
			this->pbTree->Name = L"pbTree";
			this->pbTree->Size = System::Drawing::Size(1270, 521);
			this->pbTree->TabIndex = 0;
			this->pbTree->TabStop = false;
			this->pbTree->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pbTree_Paint);
			// 
			// tpFreq
			// 
			this->tpFreq->Controls->Add(this->bOpenRes);
			this->tpFreq->Controls->Add(this->bSaveRes);
			this->tpFreq->Controls->Add(this->lHafSize);
			this->tpFreq->Controls->Add(this->l4);
			this->tpFreq->Controls->Add(this->l3);
			this->tpFreq->Controls->Add(this->lEnterSize);
			this->tpFreq->Controls->Add(this->l2);
			this->tpFreq->Controls->Add(this->l1);
			this->tpFreq->Controls->Add(this->lEnterLength);
			this->tpFreq->Controls->Add(this->lEnterText);
			this->tpFreq->Controls->Add(this->tbTime);
			this->tpFreq->Controls->Add(this->lTime);
			this->tpFreq->Controls->Add(this->dgvFreq);
			this->tpFreq->Location = System::Drawing::Point(4, 25);
			this->tpFreq->Margin = System::Windows::Forms::Padding(4);
			this->tpFreq->Name = L"tpFreq";
			this->tpFreq->Padding = System::Windows::Forms::Padding(4);
			this->tpFreq->Size = System::Drawing::Size(1278, 529);
			this->tpFreq->TabIndex = 1;
			this->tpFreq->Text = L"Результаты";
			this->tpFreq->UseVisualStyleBackColor = true;
			// 
			// bOpenRes
			// 
			this->bOpenRes->Location = System::Drawing::Point(709, 288);
			this->bOpenRes->Margin = System::Windows::Forms::Padding(4);
			this->bOpenRes->Name = L"bOpenRes";
			this->bOpenRes->Size = System::Drawing::Size(221, 48);
			this->bOpenRes->TabIndex = 12;
			this->bOpenRes->Text = L"Загрузка сохраненных ранее результатов работы";
			this->bOpenRes->UseVisualStyleBackColor = true;
			this->bOpenRes->Click += gcnew System::EventHandler(this, &Form1::bOpenRes_Click);
			// 
			// bSaveRes
			// 
			this->bSaveRes->Enabled = false;
			this->bSaveRes->Location = System::Drawing::Point(709, 343);
			this->bSaveRes->Margin = System::Windows::Forms::Padding(4);
			this->bSaveRes->Name = L"bSaveRes";
			this->bSaveRes->Size = System::Drawing::Size(217, 43);
			this->bSaveRes->TabIndex = 11;
			this->bSaveRes->Text = L"Сохранение результатов работы алгоритма";
			this->bSaveRes->UseVisualStyleBackColor = true;
			this->bSaveRes->Click += gcnew System::EventHandler(this, &Form1::bSaveRes_Click);
			// 
			// lHafSize
			// 
			this->lHafSize->AutoSize = true;
			this->lHafSize->Location = System::Drawing::Point(705, 180);
			this->lHafSize->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lHafSize->Name = L"lHafSize";
			this->lHafSize->Size = System::Drawing::Size(60, 17);
			this->lHafSize->TabIndex = 10;
			this->lHafSize->Text = L"lHafSize";
			this->lHafSize->Visible = false;
			// 
			// l4
			// 
			this->l4->AutoSize = true;
			this->l4->Location = System::Drawing::Point(705, 164);
			this->l4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->l4->Name = L"l4";
			this->l4->Size = System::Drawing::Size(168, 17);
			this->l4->TabIndex = 9;
			this->l4->Text = L"Хаффмана потребуется";
			this->l4->Visible = false;
			// 
			// l3
			// 
			this->l3->AutoSize = true;
			this->l3->Location = System::Drawing::Point(705, 148);
			this->l3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->l3->Name = L"l3";
			this->l3->Size = System::Drawing::Size(184, 17);
			this->l3->TabIndex = 8;
			this->l3->Text = L"При использовании кодов ";
			this->l3->Visible = false;
			// 
			// lEnterSize
			// 
			this->lEnterSize->AutoSize = true;
			this->lEnterSize->Location = System::Drawing::Point(705, 132);
			this->lEnterSize->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lEnterSize->Name = L"lEnterSize";
			this->lEnterSize->Size = System::Drawing::Size(72, 17);
			this->lEnterSize->TabIndex = 7;
			this->lEnterSize->Text = L"lEnterSize";
			this->lEnterSize->Visible = false;
			// 
			// l2
			// 
			this->l2->AutoSize = true;
			this->l2->Location = System::Drawing::Point(705, 116);
			this->l2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->l2->Name = L"l2";
			this->l2->Size = System::Drawing::Size(217, 17);
			this->l2->TabIndex = 6;
			this->l2->Text = L"для хранения файла требуется";
			this->l2->Visible = false;
			// 
			// l1
			// 
			this->l1->AutoSize = true;
			this->l1->Location = System::Drawing::Point(705, 100);
			this->l1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->l1->Name = L"l1";
			this->l1->Size = System::Drawing::Size(216, 17);
			this->l1->TabIndex = 5;
			this->l1->Text = L"при кодировании 1байт/символ";
			this->l1->Visible = false;
			// 
			// lEnterLength
			// 
			this->lEnterLength->AutoSize = true;
			this->lEnterLength->Location = System::Drawing::Point(705, 84);
			this->lEnterLength->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lEnterLength->Name = L"lEnterLength";
			this->lEnterLength->Size = System::Drawing::Size(89, 17);
			this->lEnterLength->TabIndex = 4;
			this->lEnterLength->Text = L"lEnterLength";
			this->lEnterLength->Visible = false;
			// 
			// lEnterText
			// 
			this->lEnterText->AutoSize = true;
			this->lEnterText->Location = System::Drawing::Point(705, 68);
			this->lEnterText->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lEnterText->Name = L"lEnterText";
			this->lEnterText->Size = System::Drawing::Size(180, 17);
			this->lEnterText->TabIndex = 3;
			this->lEnterText->Text = L"Исходный текст содержит";
			this->lEnterText->Visible = false;
			this->lEnterText->VisibleChanged += gcnew System::EventHandler(this, &Form1::lEnterText_VisibleChanged);
			// 
			// tbTime
			// 
			this->tbTime->BackColor = System::Drawing::Color::White;
			this->tbTime->Location = System::Drawing::Point(737, 30);
			this->tbTime->Margin = System::Windows::Forms::Padding(4);
			this->tbTime->Name = L"tbTime";
			this->tbTime->ReadOnly = true;
			this->tbTime->Size = System::Drawing::Size(185, 22);
			this->tbTime->TabIndex = 2;
			this->tbTime->TabStop = false;
			// 
			// lTime
			// 
			this->lTime->AutoSize = true;
			this->lTime->Location = System::Drawing::Point(705, 10);
			this->lTime->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lTime->Name = L"lTime";
			this->lTime->Size = System::Drawing::Size(180, 17);
			this->lTime->TabIndex = 1;
			this->lTime->Text = L"Время работы алгоритма:";
			// 
			// dgvFreq
			// 
			this->dgvFreq->AllowUserToAddRows = false;
			this->dgvFreq->AllowUserToDeleteRows = false;
			this->dgvFreq->AllowUserToResizeColumns = false;
			this->dgvFreq->AllowUserToResizeRows = false;
			this->dgvFreq->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvFreq->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->sym, this->Unicode,
					this->num, this->freq, this->code
			});
			this->dgvFreq->Dock = System::Windows::Forms::DockStyle::Left;
			this->dgvFreq->Location = System::Drawing::Point(4, 4);
			this->dgvFreq->Margin = System::Windows::Forms::Padding(4);
			this->dgvFreq->MultiSelect = false;
			this->dgvFreq->Name = L"dgvFreq";
			this->dgvFreq->ReadOnly = true;
			this->dgvFreq->RowHeadersVisible = false;
			this->dgvFreq->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvFreq->Size = System::Drawing::Size(699, 521);
			this->dgvFreq->TabIndex = 0;
			// 
			// sym
			// 
			this->sym->Frozen = true;
			this->sym->HeaderText = L"Символ";
			this->sym->Name = L"sym";
			this->sym->ReadOnly = true;
			this->sym->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// Unicode
			// 
			this->Unicode->Frozen = true;
			this->Unicode->HeaderText = L"Код символа(Unicode)";
			this->Unicode->Name = L"Unicode";
			this->Unicode->ReadOnly = true;
			this->Unicode->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// num
			// 
			this->num->Frozen = true;
			this->num->HeaderText = L"Колличество повторений";
			this->num->Name = L"num";
			this->num->ReadOnly = true;
			this->num->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// freq
			// 
			this->freq->Frozen = true;
			this->freq->HeaderText = L"Вероятность";
			this->freq->Name = L"freq";
			this->freq->ReadOnly = true;
			this->freq->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// code
			// 
			this->code->Frozen = true;
			this->code->HeaderText = L"Код Хаффмана";
			this->code->Name = L"code";
			this->code->ReadOnly = true;
			this->code->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->code->Width = 120;
			// 
			// tpOut
			// 
			this->tpOut->Controls->Add(this->tbOut);
			this->tpOut->Location = System::Drawing::Point(4, 25);
			this->tpOut->Margin = System::Windows::Forms::Padding(4);
			this->tpOut->Name = L"tpOut";
			this->tpOut->Padding = System::Windows::Forms::Padding(4);
			this->tpOut->Size = System::Drawing::Size(1278, 529);
			this->tpOut->TabIndex = 4;
			this->tpOut->Text = L"Закодированная строка";
			this->tpOut->UseVisualStyleBackColor = true;
			// 
			// tbOut
			// 
			this->tbOut->BackColor = System::Drawing::Color::White;
			this->tbOut->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tbOut->Location = System::Drawing::Point(4, 4);
			this->tbOut->Margin = System::Windows::Forms::Padding(4);
			this->tbOut->Multiline = true;
			this->tbOut->Name = L"tbOut";
			this->tbOut->ReadOnly = true;
			this->tbOut->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->tbOut->Size = System::Drawing::Size(1270, 521);
			this->tbOut->TabIndex = 0;
			// 
			// tpEks
			// 
			this->tpEks->Controls->Add(this->tbEksRes1);
			this->tpEks->Controls->Add(this->bEks);
			this->tpEks->Controls->Add(this->label3);
			this->tpEks->Controls->Add(this->tbEksStart);
			this->tpEks->Controls->Add(this->tbEksStep);
			this->tpEks->Controls->Add(this->tbEksSize);
			this->tpEks->Controls->Add(this->label2);
			this->tpEks->Controls->Add(this->label1);
			this->tpEks->Controls->Add(this->dgvEks);
			this->tpEks->Location = System::Drawing::Point(4, 25);
			this->tpEks->Margin = System::Windows::Forms::Padding(4);
			this->tpEks->Name = L"tpEks";
			this->tpEks->Padding = System::Windows::Forms::Padding(4);
			this->tpEks->Size = System::Drawing::Size(1278, 529);
			this->tpEks->TabIndex = 5;
			this->tpEks->Text = L"Эксперимент";
			this->tpEks->UseVisualStyleBackColor = true;
			// 
			// tbEksRes1
			// 
			this->tbEksRes1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->tbEksRes1->BackColor = System::Drawing::Color::White;
			this->tbEksRes1->Location = System::Drawing::Point(365, 5);
			this->tbEksRes1->Margin = System::Windows::Forms::Padding(4);
			this->tbEksRes1->Multiline = true;
			this->tbEksRes1->Name = L"tbEksRes1";
			this->tbEksRes1->ReadOnly = true;
			this->tbEksRes1->Size = System::Drawing::Size(596, 109);
			this->tbEksRes1->TabIndex = 8;
			// 
			// bEks
			// 
			this->bEks->Location = System::Drawing::Point(149, 86);
			this->bEks->Margin = System::Windows::Forms::Padding(4);
			this->bEks->Name = L"bEks";
			this->bEks->Size = System::Drawing::Size(177, 28);
			this->bEks->TabIndex = 7;
			this->bEks->Text = L"Начать";
			this->bEks->UseVisualStyleBackColor = true;
			this->bEks->Click += gcnew System::EventHandler(this, &Form1::bEks_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(35, 36);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(149, 17);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Стартовое значение:";
			// 
			// tbEksStart
			// 
			this->tbEksStart->Location = System::Drawing::Point(193, 32);
			this->tbEksStart->Margin = System::Windows::Forms::Padding(4);
			this->tbEksStart->Name = L"tbEksStart";
			this->tbEksStart->Size = System::Drawing::Size(132, 22);
			this->tbEksStart->TabIndex = 5;
			this->tbEksStart->Text = L"100";
			// 
			// tbEksStep
			// 
			this->tbEksStep->Location = System::Drawing::Point(193, 59);
			this->tbEksStep->Margin = System::Windows::Forms::Padding(4);
			this->tbEksStep->Name = L"tbEksStep";
			this->tbEksStep->Size = System::Drawing::Size(132, 22);
			this->tbEksStep->TabIndex = 4;
			this->tbEksStep->Text = L"100";
			// 
			// tbEksSize
			// 
			this->tbEksSize->Location = System::Drawing::Point(193, 5);
			this->tbEksSize->Margin = System::Windows::Forms::Padding(4);
			this->tbEksSize->Name = L"tbEksSize";
			this->tbEksSize->Size = System::Drawing::Size(132, 22);
			this->tbEksSize->TabIndex = 3;
			this->tbEksSize->Text = L"10";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(145, 63);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(36, 17);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Шаг:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(57, 9);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(121, 17);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Размер выборки:";
			// 
			// dgvEks
			// 
			this->dgvEks->BackgroundColor = System::Drawing::Color::White;
			this->dgvEks->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvEks->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->EksNum, this->EksTime,
					this->EksN, this->EksN2, this->EksXN
			});
			this->dgvEks->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->dgvEks->Location = System::Drawing::Point(4, 249);
			this->dgvEks->Margin = System::Windows::Forms::Padding(4);
			this->dgvEks->Name = L"dgvEks";
			this->dgvEks->RowHeadersVisible = false;
			this->dgvEks->Size = System::Drawing::Size(1270, 276);
			this->dgvEks->TabIndex = 0;
			// 
			// EksNum
			// 
			this->EksNum->Frozen = true;
			this->EksNum->HeaderText = L"№";
			this->EksNum->Name = L"EksNum";
			this->EksNum->ReadOnly = true;
			// 
			// EksTime
			// 
			this->EksTime->Frozen = true;
			this->EksTime->HeaderText = L"Время t, мс";
			this->EksTime->Name = L"EksTime";
			this->EksTime->ReadOnly = true;
			// 
			// EksN
			// 
			this->EksN->Frozen = true;
			this->EksN->HeaderText = L"Количество символов, n";
			this->EksN->Name = L"EksN";
			this->EksN->ReadOnly = true;
			// 
			// EksN2
			// 
			this->EksN2->Frozen = true;
			this->EksN2->HeaderText = L"n^2";
			this->EksN2->Name = L"EksN2";
			this->EksN2->ReadOnly = true;
			// 
			// EksXN
			// 
			this->EksXN->Frozen = true;
			this->EksXN->HeaderText = L"x * t";
			this->EksXN->Name = L"EksXN";
			this->EksXN->ReadOnly = true;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->gbRes);
			this->tabPage1->Controls->Add(this->dgvTable);
			this->tabPage1->Controls->Add(this->cbExp);
			this->tabPage1->Controls->Add(this->tbCode);
			this->tabPage1->Controls->Add(this->rbDepak);
			this->tabPage1->Controls->Add(this->rbPaked);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Size = System::Drawing::Size(1278, 529);
			this->tabPage1->TabIndex = 6;
			this->tabPage1->Text = L"Арифметическое кодирование";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// gbRes
			// 
			this->gbRes->Controls->Add(this->button1);
			this->gbRes->Controls->Add(this->tbDepakTime);
			this->gbRes->Controls->Add(this->tbPakTime);
			this->gbRes->Controls->Add(this->tbKoff);
			this->gbRes->Controls->Add(this->tbResCoding);
			this->gbRes->Controls->Add(this->label7);
			this->gbRes->Controls->Add(this->label6);
			this->gbRes->Controls->Add(this->label5);
			this->gbRes->Controls->Add(this->label4);
			this->gbRes->Location = System::Drawing::Point(499, 128);
			this->gbRes->Name = L"gbRes";
			this->gbRes->Size = System::Drawing::Size(431, 277);
			this->gbRes->TabIndex = 6;
			this->gbRes->TabStop = false;
			this->gbRes->Text = L"Результаты";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(166, 206);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(95, 34);
			this->button1->TabIndex = 11;
			this->button1->Text = L"Старт";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// tbDepakTime
			// 
			this->tbDepakTime->Location = System::Drawing::Point(217, 114);
			this->tbDepakTime->Name = L"tbDepakTime";
			this->tbDepakTime->Size = System::Drawing::Size(200, 22);
			this->tbDepakTime->TabIndex = 7;
			// 
			// tbPakTime
			// 
			this->tbPakTime->Location = System::Drawing::Point(217, 86);
			this->tbPakTime->Name = L"tbPakTime";
			this->tbPakTime->Size = System::Drawing::Size(200, 22);
			this->tbPakTime->TabIndex = 8;
			// 
			// tbKoff
			// 
			this->tbKoff->Location = System::Drawing::Point(217, 58);
			this->tbKoff->Name = L"tbKoff";
			this->tbKoff->Size = System::Drawing::Size(200, 22);
			this->tbKoff->TabIndex = 9;
			// 
			// tbResCoding
			// 
			this->tbResCoding->Location = System::Drawing::Point(217, 30);
			this->tbResCoding->Name = L"tbResCoding";
			this->tbResCoding->Size = System::Drawing::Size(200, 22);
			this->tbResCoding->TabIndex = 10;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(6, 114);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(130, 17);
			this->label7->TabIndex = 3;
			this->label7->Text = L"Время распаковки";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(6, 86);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(114, 17);
			this->label6->TabIndex = 2;
			this->label6->Text = L"Время упаковки";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(6, 58);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(152, 17);
			this->label5->TabIndex = 1;
			this->label5->Text = L"Коэффициент сжатия";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(6, 30);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(166, 17);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Результат кодирования";
			// 
			// dgvTable
			// 
			this->dgvTable->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvTable->Location = System::Drawing::Point(25, 128);
			this->dgvTable->Name = L"dgvTable";
			this->dgvTable->RowTemplate->Height = 24;
			this->dgvTable->Size = System::Drawing::Size(453, 277);
			this->dgvTable->TabIndex = 5;
			// 
			// cbExp
			// 
			this->cbExp->AutoSize = true;
			this->cbExp->Location = System::Drawing::Point(25, 100);
			this->cbExp->Name = L"cbExp";
			this->cbExp->Size = System::Drawing::Size(117, 21);
			this->cbExp->TabIndex = 4;
			this->cbExp->Text = L"Эксперимент";
			this->cbExp->UseVisualStyleBackColor = true;
			// 
			// tbCode
			// 
			this->tbCode->Location = System::Drawing::Point(25, 72);
			this->tbCode->Name = L"tbCode";
			this->tbCode->Size = System::Drawing::Size(200, 22);
			this->tbCode->TabIndex = 3;
			// 
			// rbDepak
			// 
			this->rbDepak->AutoSize = true;
			this->rbDepak->Location = System::Drawing::Point(25, 45);
			this->rbDepak->Name = L"rbDepak";
			this->rbDepak->Size = System::Drawing::Size(113, 21);
			this->rbDepak->TabIndex = 1;
			this->rbDepak->Text = L"Распаковать";
			this->rbDepak->UseVisualStyleBackColor = true;
			// 
			// rbPaked
			// 
			this->rbPaked->AutoSize = true;
			this->rbPaked->Checked = true;
			this->rbPaked->Location = System::Drawing::Point(25, 17);
			this->rbPaked->Name = L"rbPaked";
			this->rbPaked->Size = System::Drawing::Size(69, 21);
			this->rbPaked->TabIndex = 0;
			this->rbPaked->TabStop = true;
			this->rbPaked->Text = L"Сжать";
			this->rbPaked->UseVisualStyleBackColor = true;
			// 
			// ofdEnter
			// 
			this->ofdEnter->FileName = L".txt";
			this->ofdEnter->Filter = L"Text Files|*.txt";
			// 
			// sfdEnter
			// 
			this->sfdEnter->FileName = L"Haffman.txt";
			this->sfdEnter->Filter = L"Text Files|*.txt";
			// 
			// ofdRes
			// 
			this->ofdRes->FileName = L".bin";
			this->ofdRes->Filter = L"Бинарный файл|*.bin";
			// 
			// sfdRes
			// 
			this->sfdRes->FileName = L"HaffmanResult.bin";
			this->sfdRes->Filter = L"Бинарный файл|*.bin";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1286, 558);
			this->Controls->Add(this->tcMain);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Алгоритм сжатия данных. Алгоритм Хаффмана и арифметического кодирования";
			this->tcMain->ResumeLayout(false);
			this->tpEnter->ResumeLayout(false);
			this->tpEnter->PerformLayout();
			this->tpSteps->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvSteps))->EndInit();
			this->tpDrowTree->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbTree))->EndInit();
			this->tpFreq->ResumeLayout(false);
			this->tpFreq->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvFreq))->EndInit();
			this->tpOut->ResumeLayout(false);
			this->tpOut->PerformLayout();
			this->tpEks->ResumeLayout(false);
			this->tpEks->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvEks))->EndInit();
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->gbRes->ResumeLayout(false);
			this->gbRes->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvTable))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
//загрузка исходного текста из текстового файла
	private: System::Void bOpenEnter_Click(System::Object^  sender, System::EventArgs^  e) {
		if (ofdEnter -> ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			tbEnter -> Text =  IO::File::ReadAllText(ofdEnter -> FileName, System::Text::Encoding::Default);
			sfdEnter -> FileName = ofdEnter -> FileName;
		}
	}
//сохранение исходного текчта в текстовый файл
private: System::Void bSaveEnter_Click(System::Object^  sender, System::EventArgs^  e) {
		if (sfdEnter -> ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			IO::File::WriteAllText(sfdEnter -> FileName, tbEnter -> Text, System::Text::Encoding::Default);
			ofdEnter -> FileName = sfdEnter -> FileName;
		}
	}
private: System::Void bNextEnter_Click(System::Object^  sender, System::EventArgs^  e) {
			 LARGE_INTEGER timerFrequency, timerStart, timerStop;
			 QueryPerformanceFrequency(&timerFrequency);

			 Table.clear();//удаляем все элементы списка Table
		     HaffmanTree.clear();//удаляем все элементы дерева HaffmanTree

			 QueryPerformanceCounter(&timerStart);//начинаем отсчет времени
			 Table.calc(tbEnter -> Text);//подсчитываем частоты повторения символов
			 Table.sort();//сортируем Table по возрастанию частоты символов
			 HaffmanTree.create(Table, dgvSteps);//строим дерево HaffmanTree на основе Table
			 HaffmanTree.codes(Table);//строим коды символов
			 tbOut -> Text = StrToCode(tbEnter -> Text, Table);//кодируем исходное сообщение
			 QueryPerformanceCounter(&timerStop);//заканчиваем отсчет времени
			 double const time_sec = static_cast<double>( timerStop.QuadPart - timerStart.QuadPart ) / timerFrequency.QuadPart;
			 //Вывод оценки работы алгоритма
			 tbTime -> Text = time_sec*1000+" мс.";
			 lEnterText -> Visible = true;
			 int len = tbEnter-> Text -> Length;
			 lEnterLength -> Text = len + " символов";
			 lEnterSize -> Text = len + " * 8 = "+(len*8)+" бит";
			 lHafSize -> Text = tbOut->Text->Length+" бит";
			 Table.freq();//рассчитываем вероятности символов
			 Table.display(dgvFreq);//выводим Table в элемент dgvFreq
			 TreeSdvig_W = Start_TreeSdvig_W;//определяем начальные координаты для рисования дерева по x
			 TreeSdvig_H = Start_TreeSdvig_H;//по y
			 tcMain->SelectTab(tpFreq);//переходим на вкладку с шагами алгоритма
			 bSaveRes -> Enabled = true;
		 }
private: System::Void bTree_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void tcMain_Enter(System::Object^  sender, System::EventArgs^  e) {
		 }


//прорисовка дерева по событию Paint элемента pbTree
private: System::Void pbTree_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			 HaffmanTree.drow_tree(e->Graphics, pbTree->Width, TreeSdvig_W, TreeSdvig_H);
		 }
//изменение координат прорисовки дерева
private: System::Void bTreeLeft_Click(System::Object^  sender, System::EventArgs^  e) {
			 TreeSdvig_W += Step_TreeSdvig;
			 pbTree -> Refresh();
		 }
private: System::Void bTreeCenter_Click(System::Object^  sender, System::EventArgs^  e) {
			 TreeSdvig_W = Start_TreeSdvig_W;
			 TreeSdvig_H = Start_TreeSdvig_H;
			 pbTree -> Refresh();
		 }
private: System::Void bTreeRight_Click(System::Object^  sender, System::EventArgs^  e) {
			 TreeSdvig_W -= Step_TreeSdvig;
			 pbTree -> Refresh();
		 }
private: System::Void bTreeUp_Click(System::Object^  sender, System::EventArgs^  e) {
			 TreeSdvig_H += Step_TreeSdvig;
			 pbTree -> Refresh();
		 }
private: System::Void bTreeDown_Click(System::Object^  sender, System::EventArgs^  e) {
			 TreeSdvig_H -= Step_TreeSdvig;
			 pbTree -> Refresh();
		 }


private: System::Void lEnterText_VisibleChanged(System::Object^  sender, System::EventArgs^  e) {
			bool now = lEnterText -> Visible;
			lEnterLength -> Visible = now;
			l1 -> Visible = now;
			l2 -> Visible = now;
			lEnterSize -> Visible = now;
			l3 -> Visible = now;
			l4 -> Visible = now;
			lHafSize -> Visible = now;
		 }
private: System::Void bOpenRes_Click(System::Object^  sender, System::EventArgs^  e) {
		if (ofdRes -> ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			tbTime -> Text = " ";
			Table.clear();//удаляем все элементы списка Table
		    HaffmanTree.clear();//удаляем все элементы дерева HaffmanTree
			lEnterText -> Visible = false;
			char* str = (char*)(void*)Runtime::InteropServices::Marshal::StringToHGlobalAnsi(ofdRes -> FileName);
			Table.fromFile( str);
			sfdRes -> FileName = ofdRes -> FileName;
			HaffmanTree.create(Table, dgvSteps);
			HaffmanTree.codes(Table);
			Table.freq();
			Table.display(dgvFreq);
			TreeSdvig_W = Start_TreeSdvig_W;
			TreeSdvig_H = Start_TreeSdvig_H;
			bSaveRes -> Enabled = true;
			tbOut -> Text = IO::File::ReadAllText(ofdRes -> FileName+".txt", System::Text::Encoding::Default);
		}
}
private: System::Void bSaveRes_Click(System::Object^  sender, System::EventArgs^  e) {
		if (sfdRes -> ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			char* str = (char*)(void*)Runtime::InteropServices::Marshal::StringToHGlobalAnsi(sfdRes -> FileName);
			Table.toFile( str);
			ofdRes -> FileName = sfdRes -> FileName;
			IO::File::WriteAllText(sfdRes -> FileName+".txt", tbOut -> Text, System::Text::Encoding::Default);
		}
}
private: System::Void bEks_Click(System::Object^  sender, System::EventArgs^  e) {
			ifstream file("Eks.bin", ios::binary);
			if (file.fail()) 
				return;
			int start = System::Int32::Parse(tbEksStart	->	Text);
			int step  = System::Int32::Parse(tbEksStep	->	Text);
			int size  = System::Int32::Parse(tbEksSize	->	Text);
			int n = start;
			wchar_t ch;
			double N2 = 0;
			long double NT = 0;
			double SumN2 = 0;
			long double SumNT = 0;
			long long int SumN = 0;
			long double SumT = 0;
			double time = 0;
			dgvEks-> Rows  ->Clear();//удаляем все строки
			LARGE_INTEGER timerFrequency, timerStart, timerStop;
			QueryPerformanceFrequency(&timerFrequency);
			tbEnter -> Text = "";
			for(int j = 0; j < size; j++)
			{
				for(int i = 0; (i < step) && !(file.eof()); i++)
				{
					file.read(reinterpret_cast<char*>(&ch), sizeof(wchar_t) );
					tbEnter -> Text = tbEnter -> Text + ch;
				}
				Table.clear();//удаляем все элементы списка Table
				HaffmanTree.clear();//удаляем все элементы дерева HaffmanTree

				QueryPerformanceCounter(&timerStart);//начинаем отсчет времени
				Table.calc(tbEnter -> Text);//подсчитываем частоты повторения символов
				Table.sort();//сортируем Table по возрастанию частоты символов
				HaffmanTree.create(Table, dgvSteps);//строим дерево HaffmanTree на основе Table
				HaffmanTree.codes(Table);//строим коды символов
				tbOut -> Text = StrToCode(tbEnter -> Text, Table);//кодируем исходное сообщение
				QueryPerformanceCounter(&timerStop);//заканчиваем отсчет времени
				time = static_cast<double>( timerStop.QuadPart - timerStart.QuadPart ) / timerFrequency.QuadPart*1000;
				//Заносим в таблицу
				N2 = n*n;
				NT = n*time;
				SumN2 += N2;
				SumNT += NT;
				SumN += n;
				SumT += time;

				dgvEks -> Rows -> Add(j+1, time, n, N2, NT);
				n += step;
			}
			file.close();
			dgvEks -> Rows -> Add("Сумма", SumT, SumN, SumN2, SumNT);
			tbEksRes1 -> Text = "";
			double a1 = ( (size*SumNT)-(SumT*SumN) ) / ( size * SumN2 - SumN * SumN );
			double a0 = ( SumT - (a1*SumN) ) / size;
			tbEksRes1 -> Text = "Уравнение связи: t = " + a0 + " + " + a1 + " * n\r\n";
			double sr_y = SumT / size;
			double sr_x = SumN / size;
			//float dom_y = a0 + a1/;
			double S_xy = 0;
			double S_x = 0;
			double S_y = 0;
			int x = 0;
			double y = 0;
			for(int j = 0; j < size; j++)
			{
				y = Convert::ToDouble(dgvEks -> Rows[j] -> Cells[1] -> Value);
				x = Convert::ToInt32(dgvEks -> Rows[j] -> Cells[2] -> Value);
				S_xy += (y - (a0+a1*x))*(y - (a0+a1*x));
				S_x += (x - sr_x)*(x - sr_x);
				S_y += (y - sr_y)*(y - sr_y);
			}
			S_xy = sqrt( S_xy/size+2 );
			S_x = sqrt( S_x/size );
			S_y = sqrt( S_y/size );
			long double r = sqrt(1-(S_xy/S_y)*(S_xy/S_y));
			tbEksRes1 -> Text += "Коэффициент корелляции: r = " + r + "\r\n";
			tbEksRes1 -> Text += "Коэффициент детерминации: R = " + (r*r)*10 + "\r\n";
			tbEksRes1 -> Text += "Коэффициент эластичности: Э = " + a1 * sr_x/sr_y + "\r\n";
			tbEksRes1 -> Text += "Бета-коэффициент: B = " + a1 * S_x/S_y + "\r\n";
		 }
		 
		 private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
		 {
			 LARGE_INTEGER freq;
			 QueryPerformanceFrequency(&freq);

			 LARGE_INTEGER time1;
			 QueryPerformanceCounter(&time1);

			 double span;

			 if (rbPaked->Checked)
			 {
				 dgvTable->Columns->Clear();
				 unsigned char *str = (unsigned char*)and_SysStringToChar(tbEnter->Text);
				 code_len = str_len(str);
				 if (code_len>8000)
				 {
					 MessageBox::Show("Слишком длинный текст");
					 return;
				 }
				 initialization();

				 init_table(str, code_len - 1);
				 set_interval();

				 code_res = start_coding(str, code_len - 1);
			     double res = code_res;
				 tbResCoding->Text = code_res.ToString();
				 double kof = (double)sizeof(res) / code_len;
				 tbKoff->Text = kof.ToString();

				 LARGE_INTEGER time2;
				 QueryPerformanceCounter(&time2);
				 time2.QuadPart -= time1.QuadPart;
				 span = (double)time2.QuadPart / freq.QuadPart;
				 tbPakTime->Text = span.ToString();
			 }
			 if (rbDepak->Checked)
			 {
				 unsigned char *str = start_decoding(code_res, code_len);
				 tbCode->Text = and_CharToSysString(str);
				 LARGE_INTEGER time2;
				 QueryPerformanceCounter(&time2);
				 time2.QuadPart -= time1.QuadPart;
				 span = (double)time2.QuadPart / freq.QuadPart;
				 tbDepakTime->Text = span.ToString();
			 }


			 dgvTable->Columns->Add("ch", "ch");
			 dgvTable->Columns[0]->Width = 70;
			 dgvTable->Columns->Add("Pr", "Pr");
			 dgvTable->Columns[1]->Width = 70;
			 dgvTable->Columns->Add("low", "low");
			 dgvTable->Columns[2]->Width = 70;
			 dgvTable->Columns->Add("high", "high");
			 dgvTable->Columns[3]->Width = 70;

			 int j = 0;
			 for (int i = 0; i<MAX_SYMBOLS; i++)
			 {
				 if (code_table[i].freq != 0)
				 {
					 dgvTable->Rows->Add(1);
					 dgvTable->Rows[j]->Cells[0]->Value = "" + (wchar_t)btowc(code_table[i].symb);
					 dgvTable->Rows[j]->Cells[1]->Value = "" + code_table[i].freq.ToString();
					 dgvTable->Rows[j]->Cells[2]->Value = "" + code_table[i].low.ToString();
					 dgvTable->Rows[j]->Cells[3]->Value = "" + code_table[i].high.ToString();
					 j++;
				 }
			 }

			 if (cbExp && rbPaked->Checked)
			 {

				 writeToFile(code_len - 1, span, code_res);
			 }
		 }
};
}

