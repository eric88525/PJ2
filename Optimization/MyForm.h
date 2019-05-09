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
	private: System::Windows::Forms::TextBox^  Input;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::CheckedListBox^  Methods;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Button^  nter;
	private: System::Windows::Forms::Button^  Reset;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Button^  File;









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
			this->Input = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->Methods = (gcnew System::Windows::Forms::CheckedListBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->nter = (gcnew System::Windows::Forms::Button());
			this->Reset = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->File = (gcnew System::Windows::Forms::Button());
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
			// Input
			// 
			this->Input->Location = System::Drawing::Point(107, 39);
			this->Input->Multiline = true;
			this->Input->Name = L"Input";
			this->Input->Size = System::Drawing::Size(423, 245);
			this->Input->TabIndex = 3;
			this->Input->TextChanged += gcnew System::EventHandler(this, &MyForm::Input_TextChanged_1);
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
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(107, 309);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(200, 33);
			this->textBox2->TabIndex = 6;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(341, 307);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(189, 33);
			this->textBox3->TabIndex = 7;
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
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(341, 353);
			this->textBox4->Multiline = true;
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(189, 33);
			this->textBox4->TabIndex = 9;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(107, 353);
			this->textBox5->Multiline = true;
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(200, 33);
			this->textBox5->TabIndex = 10;
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
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(107, 403);
			this->textBox6->Multiline = true;
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(200, 33);
			this->textBox6->TabIndex = 14;
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(341, 403);
			this->textBox7->Multiline = true;
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(189, 33);
			this->textBox7->TabIndex = 13;
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
			// nter
			// 
			this->nter->Font = (gcnew System::Drawing::Font(L"新細明體", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->nter->Location = System::Drawing::Point(341, 447);
			this->nter->Name = L"nter";
			this->nter->Size = System::Drawing::Size(189, 47);
			this->nter->TabIndex = 18;
			this->nter->Text = L"Enter";
			this->nter->UseVisualStyleBackColor = true;
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
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1070, 580);
			this->Controls->Add(this->File);
			this->Controls->Add(this->Reset);
			this->Controls->Add(this->nter);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->Methods);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->Input);
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
private: System::Void flowLayoutPanel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
}
private: System::Void tableLayoutPanel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
}

private: System::Void Input_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void Output_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void File_Click(System::Object^  sender, System::EventArgs^  e) {
	openFileDialog1->ShowDialog();
	std::string tempFileName;
	MarshalString(openFileDialog1->FileName, tempFileName);
	dataManager->SetFileName(tempFileName);
	if (dataManager->LoadEquationData())
	{
		
	
	
	}


}
private: System::Void Input_TextChanged_1(System::Object^  sender, System::EventArgs^  e) {
}
};
}
