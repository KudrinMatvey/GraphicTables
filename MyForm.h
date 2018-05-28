#pragma once
#include<stdio.h>
#include<iostream>
#include<fstream>
#include"..\Tables\TArrayHash.h"
#include"..\Tables\TScanTable.h"
#include"..\Tables\TSortTable.h"
#include"..\Tables\TTreeTable.h"

using namespace std;
namespace GraphicTables {

	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;



	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	protected:
		int count = 1000;
		char* buffer;
		TScanTable<string, int> *scantab;
		TSortTable<string, int> *sorttab;
		TArrayHash<string, int> *hashtab;
		TTreeTable<string, int> *treetab;
		TRecord<string, int> *maximum;
		TSortTable<int, string> *top;
		int *eff;
		int flag = 0;
		int *mode;

	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	protected:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  KeyColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  ValueColumn;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  tabelsModeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  arrayToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  hashToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  scanToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sortToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  treeToolStripMenuItem;
	private: System::Windows::Forms::Label^  eff_label;
	private: System::Windows::Forms::Label^  eff_output;
	private: System::Windows::Forms::TextBox^  Insert_textbox;
	private: System::Windows::Forms::TextBox^  Find_textbox;


	private: System::Windows::Forms::Button^  eff_null;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown_value;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  Insert_button;
	private: System::Windows::Forms::Button^  Find_button;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->KeyColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ValueColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tabelsModeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->arrayToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->hashToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->scanToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sortToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->treeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->eff_label = (gcnew System::Windows::Forms::Label());
			this->eff_output = (gcnew System::Windows::Forms::Label());
			this->Insert_textbox = (gcnew System::Windows::Forms::TextBox());
			this->Find_textbox = (gcnew System::Windows::Forms::TextBox());
			this->eff_null = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown_value = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->Insert_button = (gcnew System::Windows::Forms::Button());
			this->Find_button = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_value))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
				this->KeyColumn,
					this->ValueColumn
			});
			this->dataGridView1->Location = System::Drawing::Point(12, 34);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(494, 489);
			this->dataGridView1->TabIndex = 0;
			// 
			// KeyColumn
			// 
			this->KeyColumn->HeaderText = L"Key";
			this->KeyColumn->Name = L"KeyColumn";
			this->KeyColumn->Width = 350;
			// 
			// ValueColumn
			// 
			this->ValueColumn->HeaderText = L"Value";
			this->ValueColumn->Name = L"ValueColumn";
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->openToolStripMenuItem,
					this->tabelsModeToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(742, 28);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(105, 24);
			this->openToolStripMenuItem->Text = L"Open txt File";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::openToolStripMenuItem_Click);
			// 
			// tabelsModeToolStripMenuItem
			// 
			this->tabelsModeToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->arrayToolStripMenuItem,
					this->hashToolStripMenuItem, this->scanToolStripMenuItem, this->sortToolStripMenuItem, this->treeToolStripMenuItem
			});
			this->tabelsModeToolStripMenuItem->Name = L"tabelsModeToolStripMenuItem";
			this->tabelsModeToolStripMenuItem->Size = System::Drawing::Size(105, 24);
			this->tabelsModeToolStripMenuItem->Text = L"Tabels mode";
			// 
			// arrayToolStripMenuItem
			// 
			this->arrayToolStripMenuItem->Name = L"arrayToolStripMenuItem";
			this->arrayToolStripMenuItem->Size = System::Drawing::Size(119, 26);
			this->arrayToolStripMenuItem->Text = L"Array";
			// 
			// hashToolStripMenuItem
			// 
			this->hashToolStripMenuItem->Name = L"hashToolStripMenuItem";
			this->hashToolStripMenuItem->Size = System::Drawing::Size(119, 26);
			this->hashToolStripMenuItem->Text = L"Hash";
			// 
			// scanToolStripMenuItem
			// 
			this->scanToolStripMenuItem->Name = L"scanToolStripMenuItem";
			this->scanToolStripMenuItem->Size = System::Drawing::Size(119, 26);
			this->scanToolStripMenuItem->Text = L"Scan";
			// 
			// sortToolStripMenuItem
			// 
			this->sortToolStripMenuItem->Name = L"sortToolStripMenuItem";
			this->sortToolStripMenuItem->Size = System::Drawing::Size(119, 26);
			this->sortToolStripMenuItem->Text = L"Sort";
			// 
			// treeToolStripMenuItem
			// 
			this->treeToolStripMenuItem->Name = L"treeToolStripMenuItem";
			this->treeToolStripMenuItem->Size = System::Drawing::Size(119, 26);
			this->treeToolStripMenuItem->Text = L"Tree";
			// 
			// eff_label
			// 
			this->eff_label->AutoSize = true;
			this->eff_label->Location = System::Drawing::Point(522, 506);
			this->eff_label->Name = L"eff_label";
			this->eff_label->Size = System::Drawing::Size(28, 17);
			this->eff_label->TabIndex = 2;
			this->eff_label->Text = L"eff:";
			// 
			// eff_output
			// 
			this->eff_output->AutoSize = true;
			this->eff_output->Location = System::Drawing::Point(557, 506);
			this->eff_output->Name = L"eff_output";
			this->eff_output->Size = System::Drawing::Size(0, 17);
			this->eff_output->TabIndex = 3;
			// 
			// Insert_textbox
			// 
			this->Insert_textbox->Location = System::Drawing::Point(525, 57);
			this->Insert_textbox->Name = L"Insert_textbox";
			this->Insert_textbox->Size = System::Drawing::Size(100, 22);
			this->Insert_textbox->TabIndex = 4;
			// 
			// Find_textbox
			// 
			this->Find_textbox->Location = System::Drawing::Point(528, 128);
			this->Find_textbox->Name = L"Find_textbox";
			this->Find_textbox->Size = System::Drawing::Size(100, 22);
			this->Find_textbox->TabIndex = 5;
			this->Find_textbox->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// eff_null
			// 
			this->eff_null->Location = System::Drawing::Point(593, 503);
			this->eff_null->Name = L"eff_null";
			this->eff_null->Size = System::Drawing::Size(75, 23);
			this->eff_null->TabIndex = 6;
			this->eff_null->Text = L"Reset eff";
			this->eff_null->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(525, 34);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(43, 17);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Insert";
			// 
			// numericUpDown_value
			// 
			this->numericUpDown_value->Location = System::Drawing::Point(632, 56);
			this->numericUpDown_value->Name = L"numericUpDown_value";
			this->numericUpDown_value->Size = System::Drawing::Size(72, 22);
			this->numericUpDown_value->TabIndex = 8;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(525, 108);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 17);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Find";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// Insert_button
			// 
			this->Insert_button->Location = System::Drawing::Point(632, 85);
			this->Insert_button->Name = L"Insert_button";
			this->Insert_button->Size = System::Drawing::Size(75, 23);
			this->Insert_button->TabIndex = 10;
			this->Insert_button->Text = L"Insert";
			this->Insert_button->UseVisualStyleBackColor = true;
			// 
			// Find_button
			// 
			this->Find_button->Location = System::Drawing::Point(635, 126);
			this->Find_button->Name = L"Find_button";
			this->Find_button->Size = System::Drawing::Size(75, 23);
			this->Find_button->TabIndex = 11;
			this->Find_button->Text = L"Find";
			this->Find_button->UseVisualStyleBackColor = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(742, 535);
			this->Controls->Add(this->Find_button);
			this->Controls->Add(this->Insert_button);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->numericUpDown_value);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->eff_null);
			this->Controls->Add(this->Find_textbox);
			this->Controls->Add(this->Insert_textbox);
			this->Controls->Add(this->eff_output);
			this->Controls->Add(this->eff_label);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown_value))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		string filename;
		
		OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;

		openFileDialog1->InitialDirectory = "c:\\";
		openFileDialog1->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
		openFileDialog1->FilterIndex = 2;
		openFileDialog1->RestoreDirectory = true;
		filename = openFileDialog1->FileName->ToString;
		ifstream ifs(filename);
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			if (ifs.open)
			{
				while (!ifs.eof)
				{
					ifs >> buffer;
					string str(buffer);
					TRecord<string, int>tmp;
					tmp.Key = str;
					tmp.Value = 1;

					if (!sorttab->Insert(tmp))
						sorttab->IncrCurrVal();

					if (!scantab->Insert(tmp))
						scantab->IncrCurrVal();

					if (!hashtab->Insert(tmp))
						hashtab->IncrCurrVal();

					if (!treetab->Insert(tmp)) {
						treetab->SetpCurrTopRes();
						treetab->IncrCurrVal();
					}
				}
				ifs.close();
			}

			else throw("cannot read");
		}

	}
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	buffer = new char[50];
	scantab = new TScanTable<string, int>(count);
	sorttab = new TSortTable<string, int>(count);
	hashtab = new TArrayHash<string, int>(count);
	treetab = new TTreeTable<string, int>();
	maximum = new TRecord<string, int>[10];
	top = new TSortTable<int, string>(count);
	eff = new int[4];
	mode = new int;
	const int TSCAN_TABLE = 0;
	const int TSORT_TABLE = 1;
	const int TARRAY_TABLE = 2;
	const int TTREE_TABLE = 3;
}
};
}
