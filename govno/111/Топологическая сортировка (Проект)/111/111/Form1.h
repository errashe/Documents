#pragma once
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <list>
#include <stack>



namespace My111 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace Microsoft::Glee;
	using namespace Microsoft::Glee::Drawing;
	using namespace std;
	using namespace IO;
	
	stack <int> Stack;

	/// <summary>
	/// Сводка для Form1
	/// </summary>

	
	class Graphics
	{
		int V; // No. of vertices'

		// Pointer to an array containing adjacency listsList
		list<int> *adj;

		// A function used by topologicalSort
		void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
	public:
		Graphics(int V); // Constructor

		// function to add an edge to graph
		void addEdge(int v, int w);

		// prints a Topological Sort of the complete graph
		void topologicalSort();
	};

	Graphics::Graphics(int V)
	{
		this->V = V;
		adj = new list<int>[V];
	}

	void Graphics::addEdge(int v, int w)
	{
		adj[v].push_back(w); // Add w to v’s list.
	}

	// A recursive function used by topologicalSort
	void Graphics::topologicalSortUtil(int v, bool visited[], stack<int> &Stack)
	{
		// Mark the current node as visited.
		visited[v] = true;

		// Recur for all the vertices adjacent to this vertex
		list<int>::iterator i;
		for (i = adj[v].begin(); i != adj[v].end(); ++i)
			if (!visited[*i])
				topologicalSortUtil(*i, visited, Stack);

		// Push current vertex to stack which stores result
		Stack.push(v);
	}

	// The function to do Topological Sort. It uses recursive topologicalSortUtil()
	void Graphics::topologicalSort()
	{
		

		// Mark all the vertices as not visited
		bool *visited = new bool[V];
		for (int i = 0; i < V; i++)
			visited[i] = false;

		// Call the recursive helper function to store Topological Sort
		// starting from all vertices one by one
		for (int i = 0; i < V; i++)
			if (visited[i] == false)
				topologicalSortUtil(i, visited, Stack);

		// Print contents of stack

		
	}





	/*enum TYPE_VERTEX{ WHITE, GRAY, BLACK };
	vector<vector<int> > adj;
	vector<TYPE_VERTEX> used;
	int to;

	 void dfs(int cur, vector<int> &ans) {
		used[cur] = GRAY;
		for (int i = 0; i<adj[cur].size(); i++) {
			int next = adj[cur][i];
			// if (used[next] == GRAY) // Circle
			if (used[next] == WHITE)
				dfs(next, ans);
		}
		used[cur] = BLACK;
		ans.push_back(cur);
	}
	void topological_sort(vector<int> &ans) {
		for (int i = 0; i<to; i++) {
			if (used[i] == WHITE) {
				dfs(i, ans);
			}
		}
	}*/




	/* vector < vector<int> > x;
	int o;
	bool used[maxo];
	vector<int> ans;
	void dfs(int v, bool used[])
	{
		used[v] = true;
		for (vector<int>::iterator i = x[v].begin(); i != x[v].end(); ++i)
		{
			if (!used[*i])
				dfs(*i, used);
		}
		ans.push_back(v);
	}

	void topological_sort(int o, bool used[]) {
		for (int i = 0; i<o; ++i)
			used[i] = false;
		ans.clear();
		for (int i = 0; i<o; ++i)
			if (!used[i])
				dfs(i, used);
		reverse(ans.begin(), ans.end());
	}*/
	
	/* int o; // число вершин
	const int maxo = 50;
	vector <int> g[maxo]; // граф
	bool used[maxo];
	vector<int> ans;

	void dfs(int v) {
		used[v] = true;
		for (size_t i = 0; i<g[v].size(); ++i) {
			int to = g[v][i];
			if (!used[to])
				dfs(to);
		}
		ans.push_back(v);
	}

	void topological_sort() {
		for (int i = 0; i<o; ++i)
			used[i] = false;
		ans.clear();
		for (int i = 0; i<o; ++i)
			if (!used[i])
				dfs(i);
		reverse(ans.begin(), ans.end());
	}*/
	
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

	protected: 

	private: System::Windows::Forms::TextBox^  textBox1;







	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown4;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown5;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::ListBox^  listBox1;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: Microsoft::Glee::GraphViewerGdi::GViewer^  gViewer1;
	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::Label^  label1;


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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->numericUpDown4 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown5 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->gViewer1 = (gcnew Microsoft::Glee::GraphViewerGdi::GViewer());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown5))->BeginInit();
			this->groupBox4->SuspendLayout();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->tabPage1->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(553, 20);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(75, 20);
			this->textBox1->TabIndex = 2;
			this->textBox1->Text = L"4";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(428, 181);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(178, 43);
			this->button2->TabIndex = 10;
			this->button2->Text = L"Построить граф";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(634, 10);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(161, 40);
			this->button3->TabIndex = 11;
			this->button3->Text = L"Добавить пути для вершин";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(440, 23);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(107, 13);
			this->label3->TabIndex = 12;
			this->label3->Text = L"Количество вершин";
			// 
			// numericUpDown3
			// 
			this->numericUpDown3->Location = System::Drawing::Point(84, 70);
			this->numericUpDown3->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, System::Int32::MinValue });
			this->numericUpDown3->Name = L"numericUpDown3";
			this->numericUpDown3->Size = System::Drawing::Size(75, 20);
			this->numericUpDown3->TabIndex = 14;
			this->numericUpDown3->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(206, 18);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(160, 72);
			this->button4->TabIndex = 17;
			this->button4->Text = L"Добавить путь и вес";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// numericUpDown4
			// 
			this->numericUpDown4->Location = System::Drawing::Point(84, 18);
			this->numericUpDown4->Name = L"numericUpDown4";
			this->numericUpDown4->Size = System::Drawing::Size(75, 20);
			this->numericUpDown4->TabIndex = 18;
			// 
			// numericUpDown5
			// 
			this->numericUpDown5->Location = System::Drawing::Point(84, 44);
			this->numericUpDown5->Name = L"numericUpDown5";
			this->numericUpDown5->Size = System::Drawing::Size(75, 20);
			this->numericUpDown5->TabIndex = 18;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(10, 20);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(68, 13);
			this->label5->TabIndex = 20;
			this->label5->Text = L"из вершины";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(19, 46);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(59, 13);
			this->label6->TabIndex = 21;
			this->label6->Text = L"в вершину";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(30, 72);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(48, 13);
			this->label7->TabIndex = 22;
			this->label7->Text = L"с весом";
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(428, 230);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(372, 277);
			this->listBox1->TabIndex = 31;
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(428, 513);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(130, 36);
			this->button8->TabIndex = 33;
			this->button8->Text = L"Сброс";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &Form1::button8_Click);
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->numericUpDown5);
			this->groupBox4->Controls->Add(this->numericUpDown3);
			this->groupBox4->Controls->Add(this->button4);
			this->groupBox4->Controls->Add(this->numericUpDown4);
			this->groupBox4->Controls->Add(this->label5);
			this->groupBox4->Controls->Add(this->label6);
			this->groupBox4->Controls->Add(this->label7);
			this->groupBox4->Location = System::Drawing::Point(428, 56);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(372, 105);
			this->groupBox4->TabIndex = 45;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Добавить путь";
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(622, 181);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(178, 43);
			this->button10->TabIndex = 46;
			this->button10->Text = L"Отсортировать";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &Form1::button10_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(665, 513);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(130, 36);
			this->button1->TabIndex = 47;
			this->button1->Text = L"Выход";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->dataGridView1);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(402, 513);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Матрица смежности";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCellsExceptHeader;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCellsExceptHeaders;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(7, 7);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->Size = System::Drawing::Size(389, 500);
			this->dataGridView1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->gViewer1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(402, 513);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Граф";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// gViewer1
			// 
			this->gViewer1->AsyncLayout = false;
			this->gViewer1->AutoScroll = true;
			this->gViewer1->BackwardEnabled = false;
			this->gViewer1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->gViewer1->ForwardEnabled = false;
			this->gViewer1->Graph = nullptr;
			this->gViewer1->Location = System::Drawing::Point(6, 6);
			this->gViewer1->MouseHitDistance = 0.05;
			this->gViewer1->Name = L"gViewer1";
			this->gViewer1->NavigationVisible = true;
			this->gViewer1->PanButtonPressed = false;
			this->gViewer1->SaveButtonVisible = true;
			this->gViewer1->Size = System::Drawing::Size(390, 501);
			this->gViewer1->TabIndex = 9;
			this->gViewer1->ZoomF = 1;
			this->gViewer1->ZoomFraction = 0.5;
			this->gViewer1->ZoomWindowThreshold = 0.05;
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(12, 10);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(410, 539);
			this->tabControl1->TabIndex = 27;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(447, 165);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(40, 13);
			this->label1->TabIndex = 48;
			this->label1->Text = L"Время";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(812, 561);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox1);
			this->Name = L"Form1";
			this->Text = L"Топологическая сортировка";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown5))->EndInit();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->tabPage1->ResumeLayout(false);
			this->tabControl1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}


#pragma endregion
		int v;
		int **d;
		int **dop;
		int **mass;
		private:
		int iter = 0;
		

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
			 
	groupBox4->Hide();
	button2->Hide();
	button4->Hide();

	button10->Hide();
	tabControl1->Hide();
	listBox1->Hide();
		 }

		           /*************Задание матрицы***************/
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			     int o=Convert::ToInt32(textBox1->Text);
				 int for_mass = 0;
				 for_mass = o*o;
				 iter = 0;
				 groupBox4->Show();
				 button2->Show();
				 button4->Show();
				 label1 ->Text  =  "Время";
				 button10->Show();
				 tabControl1->Show();
				 listBox1->Show();

				 mass = new int*[for_mass];
				 int chislo = 2;
				 for (int u = 0; u<for_mass; u++)
				 {
					 mass[u] = new int[chislo];
				 }
				 for (int i = 0; i<for_mass; i++)
				 {
					 for (int j = 0; j<2; j++)
					 {
						 mass[i][j] = 0;
						 //dataGridView1[i,j]->Value = 0;
					 }
				 }

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
						 //dataGridView1[i,j]->Value = 0;
					 }
				 }
				 

				 dataGridView1->Rows->Clear();
				 dataGridView1->RowCount = o;
                 dataGridView1->ColumnCount = o;
				 for (int i=0; i<o; i++)
				 {
					 dataGridView1->Columns[i]->Name = System::Convert::ToString(i);
					 dataGridView1->Rows[i]->HeaderCell->Value = System::Convert::ToString(i);
				 }
					 
		 }
		       /***********Заполнение матрицы вручную**************/
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 d[Convert::ToInt32(numericUpDown4->Text)][Convert::ToInt32(numericUpDown5->Text)]=Convert::ToInt32(numericUpDown3->Text);
			 dataGridView1->Rows[Convert::ToInt32(numericUpDown4->Text)]->Cells[Convert::ToInt32(numericUpDown5->Text)]->Value = Convert::ToString(numericUpDown3->Text);
			 int o = Convert::ToInt32(textBox1->Text);
			 
			 int iter2 = 0;


			 mass[iter][iter2] = Convert::ToInt32(numericUpDown4->Text);
			 iter2++;
			 mass[iter][iter2] = Convert::ToInt32(numericUpDown5->Text);//куда
			 iter++;




			 numericUpDown3->Value=1;
			 numericUpDown4->Value=0;
			 numericUpDown5->Value=0;
		 }



		private: int max(int a, int b)
		{
		return (a >= b) ? a : b;
		}
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
			 listBox1->Items->Clear();

		 }


	private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) {
		int o = Convert::ToInt32(textBox1->Text);

		for (int g = 0; g < o; g++)
		{
			listBox1->Items->Add(" Из вершины .. в вершину .. :");
			for (int k = 0; k < 2; k++)
			{
				
				listBox1->Items->Add(mass[g][k]);
			}
			
		}
		//в качестве пробы___________________________________ 
		listBox1->Items->Add("В результате сортировки вершины должны быть расположены в таком порядке: ");
		Graphics g(o);
		double start = clock();
		
		for (int i = 0; i < o; i++)
		{
			int k = mass[i][0];
			int y = mass[i][1];
			g.addEdge(k, y);
		}
		int *konec;
		konec = new int[o];
		for (int i = 0; i < o; i++)
		{
			konec[i] = 0;
		}
		g.topologicalSort();

		for (int i = 0; i < o; i++)
		{
			while (Stack.empty() == false)
			{
				listBox1->Items->Add(Stack.top());
			
				//konec[i] = Stack.top();
				Stack.pop();
				
			}
			
			
		}
		double end = clock();
		end -= start;
		end /= CLOCKS_PER_SEC;
		label1->Text = Convert::ToString("Время сортировки составило " + end + " секунд");
		for (int i = o; i > 0; i--)
		{
			//listBox1->Items->Add(konec[i]);
		}
	
	//____________________________________________________
	
	/*vector<int> ans;
	for (int i = 0; i < o; i++)
	{
		
		if (d[r][i] >= 1)
			g[r].push_back(1);
		else
			g[r].push_back(0);
		topological_sort();
		r++;
	}
	for (int i = 0; i < o; i++)
	{
		listBox1->Items->Add(ans.at(o));
	}*/
	/* StreamWriter ^wr = gcnew StreamWriter("random.txt");
	for (int i = 0; i < o; i++)
	{
		for (int j = 0; j < o; j++)
		{
			wr->WriteLine((System::Convert::ToString(d[i][j])));
		}
		
	}
	wr->Close();*/

/*	 String^ str;
	System::IO::StreamReader ^ reader;
	OpenFileDialog^ ofd = gcnew OpenFileDialog;
	if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		reader = gcnew System::IO::StreamReader(ofd->FileName);
		while (reader->Peek() != -1)
		{
			str = reader->ReadLine();
			for (int i = 0; i < to; i++)
			{
				adj[i].push_back(System::Convert::ToInt32(str));
			
			}
		}
	}*/


	

	/*vector<int> ans;
	topological_sort(ans);
	for (int i = to - 1; i >= 0; i--)
		listBox1->Items->Add(ans.at(i));*/

}
private: System::Void button11_Click(System::Object^  sender, System::EventArgs^  e) {
	/* int iter2 = 0;


	mass[iter][iter2] = Convert::ToInt32(numericUpDown4->Text);
	iter2++;
	mass[iter][iter2] = Convert::ToInt32(numericUpDown5->Text);//куда
	iter++;


	numericUpDown4->Value = 0;
	numericUpDown5->Value = 0;*/
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	Application::Exit();
}
};
}

