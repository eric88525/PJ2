#pragma once
#include "DataManager.h"
#include "DotNetUtilities.h"


namespace Optimization {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm 的摘要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			dataManager = new DataManager();
			//
			//TODO:  在此加入建構函式程式碼
			//
		}

	public:











	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  Output;
	private: System::Windows::Forms::Label^  label2;


	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  Initial_X;
	private: System::Windows::Forms::TextBox^  Initial_Y;


	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  Interval_X2;

	private: System::Windows::Forms::TextBox^  Interval_X1;



	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  Interval_Y1;
	private: System::Windows::Forms::TextBox^  Interval_Y2;


	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::CheckedListBox^  Methods;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Button^  Enter;

	private: System::Windows::Forms::Button^  Reset;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Button^  File;
	private: System::Windows::Forms::ListBox^  Input;









	public:











	protected:
		/// <summary>
		DataManager* dataManager;
		/// 清除任何使用中的資源。
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:










	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Output = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->Initial_X = (gcnew System::Windows::Forms::TextBox());
			this->Initial_Y = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->Interval_X2 = (gcnew System::Windows::Forms::TextBox());
			this->Interval_X1 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->Interval_Y1 = (gcnew System::Windows::Forms::TextBox());
			this->Interval_Y2 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->Methods = (gcnew System::Windows::Forms::CheckedListBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->Enter = (gcnew System::Windows::Forms::Button());
			this->Reset = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->File = (gcnew System::Windows::Forms::Button());
			this->Input = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"新細明體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label1->Location = System::Drawing::Point(114, 7);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(62, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Input";
			// 
			// Output
			// 
			this->Output->Location = System::Drawing::Point(567, 39);
			this->Output->Multiline = true;
			this->Output->Name = L"Output";
			this->Output->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->Output->Size = System::Drawing::Size(491, 529);
			this->Output->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"新細明體", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label2->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label2->Location = System::Drawing::Point(573, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(70, 21);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Output";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"新細明體-ExtB", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label3->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label3->Location = System::Drawing::Point(6, 309);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(83, 19);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Initial_X";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"新細明體", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label4->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label4->Location = System::Drawing::Point(312, 309);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(23, 19);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Y";
			// 
			// Initial_X
			// 
			this->Initial_X->Font = (gcnew System::Drawing::Font(L"新細明體", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->Initial_X->Location = System::Drawing::Point(107, 309);
			this->Initial_X->Multiline = true;
			this->Initial_X->Name = L"Initial_X";
			this->Initial_X->Size = System::Drawing::Size(200, 33);
			this->Initial_X->TabIndex = 6;
			// 
			// Initial_Y
			// 
			this->Initial_Y->Font = (gcnew System::Drawing::Font(L"新細明體", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->Initial_Y->Location = System::Drawing::Point(341, 307);
			this->Initial_Y->Multiline = true;
			this->Initial_Y->Name = L"Initial_Y";
			this->Initial_Y->Size = System::Drawing::Size(189, 33);
			this->Initial_Y->TabIndex = 7;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"新細明體", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label5->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label5->Location = System::Drawing::Point(4, 353);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(97, 19);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Interval_X";
			// 
			// Interval_X2
			// 
			this->Interval_X2->Font = (gcnew System::Drawing::Font(L"新細明體", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->Interval_X2->Location = System::Drawing::Point(341, 353);
			this->Interval_X2->Multiline = true;
			this->Interval_X2->Name = L"Interval_X2";
			this->Interval_X2->Size = System::Drawing::Size(189, 33);
			this->Interval_X2->TabIndex = 9;
			// 
			// Interval_X1
			// 
			this->Interval_X1->Font = (gcnew System::Drawing::Font(L"新細明體", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->Interval_X1->Location = System::Drawing::Point(107, 353);
			this->Interval_X1->Multiline = true;
			this->Interval_X1->Name = L"Interval_X1";
			this->Interval_X1->Size = System::Drawing::Size(200, 33);
			this->Interval_X1->TabIndex = 10;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"新細明體", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label6->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label6->Location = System::Drawing::Point(316, 353);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(19, 19);
			this->label6->TabIndex = 11;
			this->label6->Text = L"~";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"新細明體", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label7->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label7->Location = System::Drawing::Point(316, 403);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(19, 19);
			this->label7->TabIndex = 15;
			this->label7->Text = L"~";
			// 
			// Interval_Y1
			// 
			this->Interval_Y1->Font = (gcnew System::Drawing::Font(L"新細明體", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->Interval_Y1->Location = System::Drawing::Point(107, 403);
			this->Interval_Y1->Multiline = true;
			this->Interval_Y1->Name = L"Interval_Y1";
			this->Interval_Y1->Size = System::Drawing::Size(200, 33);
			this->Interval_Y1->TabIndex = 14;
			// 
			// Interval_Y2
			// 
			this->Interval_Y2->Font = (gcnew System::Drawing::Font(L"新細明體", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->Interval_Y2->Location = System::Drawing::Point(341, 403);
			this->Interval_Y2->Multiline = true;
			this->Interval_Y2->Name = L"Interval_Y2";
			this->Interval_Y2->Size = System::Drawing::Size(189, 33);
			this->Interval_Y2->TabIndex = 13;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"新細明體", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label8->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label8->Location = System::Drawing::Point(6, 403);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(97, 19);
			this->label8->TabIndex = 12;
			this->label8->Text = L"Interval_Y";
			// 
			// Methods
			// 
			this->Methods->Font = (gcnew System::Drawing::Font(L"新細明體", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->Methods->FormattingEnabled = true;
			this->Methods->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Powell", L"Newton", L"Steep Descent Algorithm ",
					L"Quasi-Newton Method ", L"Conjugate Gradient Methods "
			});
			this->Methods->Location = System::Drawing::Point(107, 447);
			this->Methods->Name = L"Methods";
			this->Methods->Size = System::Drawing::Size(200, 104);
			this->Methods->TabIndex = 16;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"新細明體", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label9->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label9->Location = System::Drawing::Point(17, 475);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(79, 19);
			this->label9->TabIndex = 17;
			this->label9->Text = L"Methods";
			// 
			// Enter
			// 
			this->Enter->Font = (gcnew System::Drawing::Font(L"新細明體", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->Enter->Location = System::Drawing::Point(341, 447);
			this->Enter->Name = L"Enter";
			this->Enter->Size = System::Drawing::Size(189, 47);
			this->Enter->TabIndex = 18;
			this->Enter->Text = L"Enter";
			this->Enter->UseVisualStyleBackColor = true;
			this->Enter->Click += gcnew System::EventHandler(this, &MyForm::Enter_Click);
			// 
			// Reset
			// 
			this->Reset->Font = (gcnew System::Drawing::Font(L"新細明體", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->Reset->Location = System::Drawing::Point(341, 500);
			this->Reset->Name = L"Reset";
			this->Reset->Size = System::Drawing::Size(189, 51);
			this->Reset->TabIndex = 19;
			this->Reset->Text = L"Reset";
			this->Reset->UseVisualStyleBackColor = true;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// File
			// 
			this->File->Font = (gcnew System::Drawing::Font(L"新細明體", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->File->Location = System::Drawing::Point(17, 133);
			this->File->Name = L"File";
			this->File->Size = System::Drawing::Size(72, 37);
			this->File->TabIndex = 20;
			this->File->Text = L"File";
			this->File->UseVisualStyleBackColor = true;
			this->File->Click += gcnew System::EventHandler(this, &MyForm::File_Click);
			// 
			// Input
			// 
			this->Input->FormattingEnabled = true;
			this->Input->ItemHeight = 12;
			this->Input->Location = System::Drawing::Point(118, 39);
			this->Input->Name = L"Input";
			this->Input->Size = System::Drawing::Size(412, 244);
			this->Input->TabIndex = 21;
			this->Input->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::Input_SelectedIndexChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1070, 580);
			this->Controls->Add(this->Input);
			this->Controls->Add(this->File);
			this->Controls->Add(this->Reset);
			this->Controls->Add(this->Enter);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->Methods);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->Interval_Y1);
			this->Controls->Add(this->Interval_Y2);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->Interval_X1);
			this->Controls->Add(this->Interval_X2);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->Initial_Y);
			this->Controls->Add(this->Initial_X);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->Output);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"Optimization";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void loadEquationsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		openFileDialog1->ShowDialog();
	}
	private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
		//在Dialog按下OK便會進入此函式
		//字串轉制string^ to string
		std::string tempFileName;
		MarshalString(openFileDialog1->FileName, tempFileName);
		//將檔案路徑名稱傳入dataManager
		dataManager->SetFileName(tempFileName);
		//從讀取讀取向量資料
		if (dataManager->LoadEquationData())
		{
			std::vector<std::string> equations = dataManager->GetEquations();
			Output->Multiline = true;
			for (unsigned int i = 0; i < equations.size(); i++)
			{
				Output->Text += gcnew String(equations[i].c_str());
				Output->Text += Environment::NewLine;
			}
		}
	}
	private: System::Void File_Click(System::Object^  sender, System::EventArgs^  e) {
		openFileDialog1->ShowDialog();
		std::string tempFileName;
		MarshalString(openFileDialog1->FileName, tempFileName);
		dataManager->SetFileName(tempFileName);
		if (dataManager->LoadEquationData())
		{
			std::vector<std::string> Equations = dataManager->GetEquations();
			for (auto i : Equations) {
				std::string tempString;
				tempString += i;
				Input->Items->Add(gcnew String(tempString.c_str()));
			}
		}
	}
	private: System::Void Enter_Click(System::Object^  sender, System::EventArgs^  e) {

		int EquationsID = Input->SelectedIndex;		//要處裡哪個方程式
		int MeythodsID = Methods->SelectedIndex;		//要用哪個方法

		if (EquationsID == -1 || MeythodsID == -1)throw no_select_item; 

		//輸入字串處裡
		std::string str;
		String^ s = Input->GetItemText(Input->SelectedItem);
		MarshalString(s, str);

		//讀表格值
		double  InitialX = 1;  double  InitialY = 1;
		double IntervalX1 = 1; double IntervalX2 = 1;
		double IntervalY1 = 1; double IntervalY2 = 1;
		if (Initial_X->Text != "")    InitialX = Convert::ToDouble(Initial_X->Text);
		if (Initial_Y->Text != "")	  InitialY = Convert::ToDouble(Initial_Y->Text);
		if (Interval_X1->Text != "")  IntervalX1 = Convert::ToDouble(Interval_X1->Text);
		if (Interval_X2->Text != "")  IntervalX2 = Convert::ToDouble(Interval_X2->Text);
		if (Interval_Y1->Text != "")  IntervalY1 = Convert::ToDouble(Interval_Y1->Text);
		if (Interval_Y2->Text != "")  IntervalY2 = Convert::ToDouble(Interval_Y2->Text);

		//中轉後
		std::vector<string> Pos = IntoPost(str);
		double testv = cal(str,InitialX, InitialY);
		double testmin = golden_search(-10,-5,100,str);
		powell_method_1dim( str, InitialX, IntervalX1, IntervalX2,Output);

		//不同方法 呼叫
		switch (MeythodsID)
		{
		case 0:


			break;
		case 1:


			break;
		case 2:


			break;
		case 3:


			break;
		case 4:


			break;
		default:
			break;
		}
	}

	private: System::Void Input_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	}
};
}
