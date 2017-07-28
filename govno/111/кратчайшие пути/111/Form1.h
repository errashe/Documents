#pragma once

namespace My111 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Microsoft::Glee;
	using namespace Microsoft::Glee::Drawing;

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
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	protected: 
	private: System::Windows::Forms::NumericUpDown^  numericUpDown2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: Microsoft::Glee::GraphViewerGdi::GViewer^  gViewer1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown3;


	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown4;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown5;

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
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->gViewer1 = (gcnew Microsoft::Glee::GraphViewerGdi::GViewer());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->numericUpDown3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->numericUpDown4 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown5 = (gcnew System::Windows::Forms::NumericUpDown());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown5))->BeginInit();
			this->SuspendLayout();
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(631, 280);
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(120, 20);
			this->numericUpDown1->TabIndex = 0;
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Location = System::Drawing::Point(631, 307);
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(120, 20);
			this->numericUpDown2->TabIndex = 1;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(702, 12);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 2;
			this->textBox1->Text = L"3";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(599, 401);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(228, 20);
			this->textBox2->TabIndex = 3;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(599, 428);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(228, 20);
			this->textBox3->TabIndex = 4;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(599, 455);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(228, 20);
			this->textBox4->TabIndex = 5;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(599, 340);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(120, 23);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Поиск кратч. пути";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(591, 286);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(23, 13);
			this->label1->TabIndex = 7;
			this->label1->Text = L"S =";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(591, 309);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(25, 13);
			this->label2->TabIndex = 8;
			this->label2->Text = L"g = ";
			// 
			// gViewer1
			// 
			this->gViewer1->AsyncLayout = false;
			this->gViewer1->AutoScroll = true;
			this->gViewer1->BackwardEnabled = false;
			this->gViewer1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->gViewer1->ForwardEnabled = false;
			this->gViewer1->Graph = nullptr;
			this->gViewer1->Location = System::Drawing::Point(12, 3);
			this->gViewer1->MouseHitDistance = 0.05;
			this->gViewer1->Name = L"gViewer1";
			this->gViewer1->NavigationVisible = true;
			this->gViewer1->PanButtonPressed = false;
			this->gViewer1->SaveButtonVisible = true;
			this->gViewer1->Size = System::Drawing::Size(540, 546);
			this->gViewer1->TabIndex = 9;
			this->gViewer1->ZoomF = 1;
			this->gViewer1->ZoomFraction = 0.5;
			this->gViewer1->ZoomWindowThreshold = 0.05;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(585, 511);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 10;
			this->button2->Text = L"Построить";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(702, 47);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(100, 23);
			this->button3->TabIndex = 11;
			this->button3->Text = L"Задать массив";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(589, 15);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(107, 13);
			this->label3->TabIndex = 12;
			this->label3->Text = L"Количество вершин";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(689, 511);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(100, 20);
			this->textBox5->TabIndex = 13;
			// 
			// numericUpDown3
			// 
			this->numericUpDown3->Location = System::Drawing::Point(641, 132);
			this->numericUpDown3->Name = L"numericUpDown3";
			this->numericUpDown3->Size = System::Drawing::Size(120, 20);
			this->numericUpDown3->TabIndex = 14;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(781, 80);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 72);
			this->button4->TabIndex = 17;
			this->button4->Text = L"Занести в массив";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// numericUpDown4
			// 
			this->numericUpDown4->Location = System::Drawing::Point(641, 80);
			this->numericUpDown4->Name = L"numericUpDown4";
			this->numericUpDown4->Size = System::Drawing::Size(120, 20);
			this->numericUpDown4->TabIndex = 18;
			// 
			// numericUpDown5
			// 
			this->numericUpDown5->Location = System::Drawing::Point(641, 106);
			this->numericUpDown5->Name = L"numericUpDown5";
			this->numericUpDown5->Size = System::Drawing::Size(120, 20);
			this->numericUpDown5->TabIndex = 18;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(918, 561);
			this->Controls->Add(this->numericUpDown5);
			this->Controls->Add(this->numericUpDown4);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->numericUpDown3);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->gViewer1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->numericUpDown2);
			this->Controls->Add(this->numericUpDown1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->numericUpDown5))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		int v;
		//int p=5;
		int **d;
		

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 //Graph ^z = gcnew Graph("graph");
				 int infinity = 8888;
				 int o=Convert::ToInt32(textBox1->Text);
				 
				 //textBox1->Text=Convert::ToString(d[1][1]);
				 int a[6][6]={ 0,1,0,0,1,3,  // Матрица смежности графа
                               1,0,5,0,0,1,
                               0,5,0,5,20,1,
     	                         0,0,5,0,3,2,
                               1,0,20,3,0,10,
                               3,1,1,2,10,0};
				 

				 /*for(int i = 0; i<6; i++)
				 {
					 for(int j = 0; j<6; j++)
					 {
						 
						 if (a[i][j]!=0)
						 z->AddEdge(Convert::ToString(i), Convert::ToString(a[i][j]), Convert::ToString(j)); 
					 }
				 }
				 gViewer1->Graph = z;*/
				 int s = Convert::ToInt32(numericUpDown1->Value);    // Номер исходной вершины
				 int g = Convert::ToInt32(numericUpDown2->Value);    // Номер конечной вершины
				 int *x = new int[o]; //Массив, содержащий единицы и нули для каждой вершины,
                  // x[i]=0 - еще не найден кратчайший путь в i-ю вершину,
                  // x[i]=1 - кратчайший путь в i-ю вершину уже найден
				 int *t = new int[o];  //t[i] - длина кратчайшего пути от вершины s в i
				 int *h = new int[o];  //h[i] - вершина, предшествующая i-й вершине
   		         // на кратчайшем пути

				 // Инициализируем начальные значения массивов
				int u;		    // Счетчик вершин
				for (u=0;u<o;u++)
				{
					t[u]=infinity; //Сначала все кратчайшие пути из s в i 
					//равны бесконечности
					x[u]=0;        // и нет кратчайшего пути ни для одной вершины
				}
				h[s]=0; // s - начало пути, поэтому этой вершине ничего не предшествует
				t[s]=0; // Кратчайший путь из s в s равен 0
				x[s]=1; // Для вершины s найден кратчайший путь
				v=s;    // Делаем s текущей вершиной
				//int mas[6]={-1,-1,-1,-1,-1,-1};

				while(1)
   {
      // Перебираем все вершины, смежные v, и ищем для них кратчайший путь
      for(u=0;u<o;u++)
      {
         if(d[v][u]==0)continue; // Вершины u и v несмежные
         if(x[u]==0 && t[u]>t[v]+a[v][u]) //Если для вершины u еще не 
	//найден кратчайший путь
            	// и новый путь в u короче чем 
	//старый, то
         {
            t[u]=t[v]+d[v][u];	//запоминаем более короткую длину пути в
	//массив t и
            h[u]=v;	//запоминаем, что v->u часть кратчайшего 
	//пути из s->u
         }
      }

      // Ищем из всех длин некратчайших путей самый короткий
      int w=infinity;  // Для поиска самого короткого пути
      v=-1;            // В конце поиска v - вершина, в которую будет 
                       // найден новый кратчайший путь. Она станет 
                       // текущей вершиной
      for(u=0;u<o;u++) // Перебираем все вершины.
      {
         if(x[u]==0 && t[u]<w) // Если для вершины не найден кратчайший 
                               // путь и если длина пути в вершину u меньше
                               // уже найденной, то
         {
            v=u; // текущей вершиной становится u-я вершина
            w=t[u];
			
         }
      }
      if(v==-1)
      {
         //cout<<"Нет пути из вершины "<<s<<" в вершину "<<g<<"."<<endl;
         break;
      }
      if(v==g) // Найден кратчайший путь,
      {        // выводим его
		  textBox2->Text="Кратчайший путь из вершины "+ s +" в вершину "+ g +":";
         
   	   u=g;
	   

   	   while(u!=s)
         {
			 
            textBox3->Text+=" "+ u;
			 
            u=h[u];
         }
	   textBox3->Text+=" "+ s;
	     textBox4->Text=" Длина пути = " + t[g];
         
   	   break;
      }
      x[v]=1;
   }
			 }
			          /**********Постройка графа***********/
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 int o=Convert::ToInt32(textBox1->Text);
			 Graph ^graf = gcnew Graph("graph");
			 for(int i = 0; i<o; i++)
				 {
					 for(int j = 0; j<o; j++)
					 {
						 
						 if (d[i][j]!=0)
						 graf->AddEdge(Convert::ToString(i), Convert::ToString(d[i][j]), Convert::ToString(j)); 
					 }
				 }
			 gViewer1->Graph = graf;
			 
                 
		 }
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {

		 }

		           /*************Задание матрицы***************/
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			     int o=Convert::ToInt32(textBox1->Text);
				 d = new int*[o];
				 for(int i=0; i<o; i++)
				 {
					 d[i] = new int [o];
				 }
				 for(int i=0; i<o; i++)
				 {
					 for(int j=0; j<o; j++)
					 {
						 d[i][j]=0;
					 }
				 }
					 
		 }
		       /***********Заполнение матрицы вручную**************/
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 d[Convert::ToInt32(numericUpDown4->Text)][Convert::ToInt32(numericUpDown5->Text)]=Convert::ToInt32(numericUpDown3->Text);
			 numericUpDown3->Value=0;
			 numericUpDown4->Value=0;
			 numericUpDown5->Value=0;
		 }
};
}

