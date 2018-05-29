#pragma once
#include<stdio.h>
#include<iostream>
#include<fstream>
#include <msclr\marshal_cppstd.h>
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
		string *fileName;
		int *eff;
		int *mode;
		bool *OpenFlag;
		const int TSCAN_TABLE = 0;
		const int TSORT_TABLE = 1;
		const int THASH_TABLE = 2;
		const int TTREE_TABLE = 3;
	private: System::Windows::Forms::Button^  Delete_button;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::ToolStripMenuItem^  chooseTxtFileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  reloadToolStripMenuItem;
	protected:
		

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

	private: System::Windows::Forms::ToolStripMenuItem^  hashToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  scanToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  sortToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  treeToolStripMenuItem;
	private: System::Windows::Forms::Label^  eff_label;
	private: System::Windows::Forms::Label^  eff_output;
	private: System::Windows::Forms::TextBox^  Insert_textbox;



	private: System::Windows::Forms::Button^  eff_null;

	private: System::Windows::Forms::NumericUpDown^  numericUpDown_value;


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
			this->chooseTxtFileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->reloadToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tabelsModeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->hashToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->scanToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->sortToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->treeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->eff_label = (gcnew System::Windows::Forms::Label());
			this->eff_output = (gcnew System::Windows::Forms::Label());
			this->Insert_textbox = (gcnew System::Windows::Forms::TextBox());
			this->eff_null = (gcnew System::Windows::Forms::Button());
			this->numericUpDown_value = (gcnew System::Windows::Forms::NumericUpDown());
			this->Insert_button = (gcnew System::Windows::Forms::Button());
			this->Find_button = (gcnew System::Windows::Forms::Button());
			this->Delete_button = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
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
			this->dataGridView1->Location = System::Drawing::Point(28, 31);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(710, 489);
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
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->chooseTxtFileToolStripMenuItem,
					this->openToolStripMenuItem, this->reloadToolStripMenuItem, this->tabelsModeToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(988, 28);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// chooseTxtFileToolStripMenuItem
			// 
			this->chooseTxtFileToolStripMenuItem->Name = L"chooseTxtFileToolStripMenuItem";
			this->chooseTxtFileToolStripMenuItem->Size = System::Drawing::Size(116, 24);
			this->chooseTxtFileToolStripMenuItem->Text = L"Choose txt file";
			this->chooseTxtFileToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::chooseTxtFileToolStripMenuItem_Click);
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(105, 24);
			this->openToolStripMenuItem->Text = L"Open txt File";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::openToolStripMenuItem_Click);
			// 
			// reloadToolStripMenuItem
			// 
			this->reloadToolStripMenuItem->Name = L"reloadToolStripMenuItem";
			this->reloadToolStripMenuItem->Size = System::Drawing::Size(68, 24);
			this->reloadToolStripMenuItem->Text = L"Reload";
			this->reloadToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::reloadToolStripMenuItem_Click);
			// 
			// tabelsModeToolStripMenuItem
			// 
			this->tabelsModeToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->hashToolStripMenuItem,
					this->scanToolStripMenuItem, this->sortToolStripMenuItem, this->treeToolStripMenuItem
			});
			this->tabelsModeToolStripMenuItem->Name = L"tabelsModeToolStripMenuItem";
			this->tabelsModeToolStripMenuItem->Size = System::Drawing::Size(105, 24);
			this->tabelsModeToolStripMenuItem->Text = L"Tabels mode";
			// 
			// hashToolStripMenuItem
			// 
			this->hashToolStripMenuItem->Name = L"hashToolStripMenuItem";
			this->hashToolStripMenuItem->Size = System::Drawing::Size(181, 26);
			this->hashToolStripMenuItem->Text = L"Hash";
			this->hashToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::hashToolStripMenuItem_Click);
			// 
			// scanToolStripMenuItem
			// 
			this->scanToolStripMenuItem->Name = L"scanToolStripMenuItem";
			this->scanToolStripMenuItem->Size = System::Drawing::Size(181, 26);
			this->scanToolStripMenuItem->Text = L"Scan";
			this->scanToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::scanToolStripMenuItem_Click);
			// 
			// sortToolStripMenuItem
			// 
			this->sortToolStripMenuItem->Name = L"sortToolStripMenuItem";
			this->sortToolStripMenuItem->Size = System::Drawing::Size(181, 26);
			this->sortToolStripMenuItem->Text = L"Sort";
			this->sortToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::sortToolStripMenuItem_Click);
			// 
			// treeToolStripMenuItem
			// 
			this->treeToolStripMenuItem->Name = L"treeToolStripMenuItem";
			this->treeToolStripMenuItem->Size = System::Drawing::Size(181, 26);
			this->treeToolStripMenuItem->Text = L"Tree";
			this->treeToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::treeToolStripMenuItem_Click);
			// 
			// eff_label
			// 
			this->eff_label->AutoSize = true;
			this->eff_label->Location = System::Drawing::Point(788, 497);
			this->eff_label->Name = L"eff_label";
			this->eff_label->Size = System::Drawing::Size(28, 17);
			this->eff_label->TabIndex = 2;
			this->eff_label->Text = L"eff:";
			// 
			// eff_output
			// 
			this->eff_output->AutoSize = true;
			this->eff_output->Location = System::Drawing::Point(823, 497);
			this->eff_output->Name = L"eff_output";
			this->eff_output->Size = System::Drawing::Size(0, 17);
			this->eff_output->TabIndex = 3;
			// 
			// Insert_textbox
			// 
			this->Insert_textbox->Location = System::Drawing::Point(791, 53);
			this->Insert_textbox->Name = L"Insert_textbox";
			this->Insert_textbox->Size = System::Drawing::Size(100, 22);
			this->Insert_textbox->TabIndex = 4;
			this->Insert_textbox->TextChanged += gcnew System::EventHandler(this, &MyForm::Insert_textbox_TextChanged);
			// 
			// eff_null
			// 
			this->eff_null->Location = System::Drawing::Point(859, 494);
			this->eff_null->Name = L"eff_null";
			this->eff_null->Size = System::Drawing::Size(75, 23);
			this->eff_null->TabIndex = 6;
			this->eff_null->Text = L"Reset eff";
			this->eff_null->UseVisualStyleBackColor = true;
			this->eff_null->Click += gcnew System::EventHandler(this, &MyForm::eff_null_Click);
			// 
			// numericUpDown_value
			// 
			this->numericUpDown_value->Location = System::Drawing::Point(898, 52);
			this->numericUpDown_value->Name = L"numericUpDown_value";
			this->numericUpDown_value->Size = System::Drawing::Size(72, 22);
			this->numericUpDown_value->TabIndex = 8;
			// 
			// Insert_button
			// 
			this->Insert_button->Location = System::Drawing::Point(898, 76);
			this->Insert_button->Name = L"Insert_button";
			this->Insert_button->Size = System::Drawing::Size(75, 23);
			this->Insert_button->TabIndex = 10;
			this->Insert_button->Text = L"Insert";
			this->Insert_button->UseVisualStyleBackColor = true;
			this->Insert_button->Click += gcnew System::EventHandler(this, &MyForm::Insert_button_Click);
			// 
			// Find_button
			// 
			this->Find_button->Location = System::Drawing::Point(791, 81);
			this->Find_button->Name = L"Find_button";
			this->Find_button->Size = System::Drawing::Size(75, 23);
			this->Find_button->TabIndex = 11;
			this->Find_button->Text = L"Find";
			this->Find_button->UseVisualStyleBackColor = true;
			this->Find_button->Click += gcnew System::EventHandler(this, &MyForm::Find_button_Click);
			// 
			// Delete_button
			// 
			this->Delete_button->Location = System::Drawing::Point(791, 110);
			this->Delete_button->Name = L"Delete_button";
			this->Delete_button->Size = System::Drawing::Size(75, 23);
			this->Delete_button->TabIndex = 12;
			this->Delete_button->Text = L"Delete";
			this->Delete_button->UseVisualStyleBackColor = true;
			this->Delete_button->Click += gcnew System::EventHandler(this, &MyForm::Delete_button_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(794, 191);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(77, 17);
			this->label3->TabIndex = 13;
			this->label3->Text = L"Mode: Sort";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(988, 535);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->Delete_button);
			this->Controls->Add(this->Find_button);
			this->Controls->Add(this->Insert_button);
			this->Controls->Add(this->numericUpDown_value);
			this->Controls->Add(this->eff_null);
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
		if (*OpenFlag)
		{
			treetab->clear();
			sorttab->ClearTable();
			scantab->ClearTable();
			hashtab->ClearTable();
		}
		*OpenFlag = true;
		
	/*	OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;

		openFileDialog1->InitialDirectory = "c:\\";
		openFileDialog1->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
		openFileDialog1->FilterIndex = 2;
		openFileDialog1->RestoreDirectory = true;
		filename = openFileDialog1->FileName->ToString;*/
	
		ifstream ifs(*fileName);
	//	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			if (ifs.is_open())
			{
				while (!ifs.eof())
				{
					ifs >> buffer;
					string str(buffer);
					TRecord<string, int>tmp;
					tmp.Key = str;
					tmp.Value = 1;

					bool tmpp = sorttab->Insert(tmp);
					if (!tmpp)
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
		Reload();
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
	*mode = TSORT_TABLE;
	OpenFlag = new bool;
	*OpenFlag = false;
	fileName = new string;
	*fileName = "..\\Tables\\Text.txt";

}
//private: System::Void arrayToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
//	*mode = TARRAY_TABLE;
//	ClearScreen();
//
//}
	private: void ClearScreen() {
		for (int i = 0; i < count; i++) {
			dataGridView1->Rows[i]->Cells[0]->Value = i;
			dataGridView1->Rows[i]->Cells[1]->Value = "";
		}
	}
private: System::Void hashToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	label3->Text = "Mode: Hash";
	*mode = THASH_TABLE;
	
}
private: System::Void reloadToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	dataGridView1->Rows->Clear();
	sorttab->nulleff();
	scantab->nulleff();
	hashtab->nulleff();
	treetab->nulleff();
	eff_output->Text = "0";
	Reload();
}
public: String^ StrToStr(string str) {
			 return gcnew String(GetStr(str));
		 }
public: char *GetStr(string str) {
				int len = str.length();
				char *res = new char[len + 1];
				for (int i = 0; i < len; i++) {
					res[i] = str[i];
				}
				res[len] = '\0';
				return res;
			}

private: System::Void scanToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	label3->Text = "Mode: Scan";
	*mode = TSCAN_TABLE;
}
private: System::Void sortToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	label3->Text = "Mode: Sort";
	*mode = TSORT_TABLE;
}
private: System::Void treeToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	label3->Text = "Mode: Tree";
	*mode = TTREE_TABLE;
}
private: System::Void Insert_textbox_TextChanged(System::Object^  sender, System::EventArgs^  e) {

}
private: System::Void Insert_button_Click(System::Object^  sender, System::EventArgs^  e) {
	ResetEff();
	string str = msclr::interop::marshal_as<std::string>(Insert_textbox->Text);
	TRecord<string, int>tmp;
	tmp.Key = str;
	tmp.Value = (int)numericUpDown_value->Value;

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
	if (*mode == TSCAN_TABLE)
		eff_output->Text = scantab->geteff().ToString();
	if (*mode == TSORT_TABLE)
		eff_output->Text = sorttab->geteff().ToString();
	if (*mode == THASH_TABLE)
		eff_output->Text = hashtab->geteff().ToString();
	if (*mode == TTREE_TABLE)
		eff_output->Text = treetab->geteff().ToString();
	Reload();
}
private: System::Void Find_button_Click(System::Object^  sender, System::EventArgs^  e) {
	string str = msclr::interop::marshal_as<std::string>(Insert_textbox->Text);
	TRecord<string, int> tmp;
	int i = 0;
	bool flag = false;
	if (*mode == TSCAN_TABLE)
	{
		scantab->nulleff();
		flag = scantab->Find(str);
		if (flag)
		{
				tmp = scantab->GetCurr();
				dataGridView1->Rows->Clear();
				dataGridView1->Rows->Add();
				dataGridView1->Rows[i]->Cells[0]->Value = Convert::ToString(StrToStr(tmp.Key));
				dataGridView1->Rows[i]->Cells[1]->Value = Convert::ToString(tmp.Value);
				System::String^ eff_str = scantab->geteff().ToString(); 
				eff_output->Text = eff_str;
		}
		else
		{
			dataGridView1->Rows->Clear();
			dataGridView1->Rows->Add();
			dataGridView1->Rows[i]->Cells[0]->Value = "Nothing found";
		}
	}
	else if (*mode == TSORT_TABLE)
	{
		sorttab->nulleff();
		flag = sorttab->Find(str);
		if (flag)
		{
			tmp = sorttab->GetCurr();
			dataGridView1->Rows->Clear();
			dataGridView1->Rows->Add();
			dataGridView1->Rows[i]->Cells[0]->Value = Convert::ToString(StrToStr(tmp.Key));
			dataGridView1->Rows[i]->Cells[1]->Value = Convert::ToString(tmp.Value);
			System::String^ eff_str = sorttab->geteff().ToString();
			eff_output->Text = eff_str;
		}
		else
		{
			dataGridView1->Rows->Clear();
			dataGridView1->Rows->Add();
			dataGridView1->Rows[i]->Cells[0]->Value = "Nothing found";
		}
	}
	else if (*mode == THASH_TABLE)
	{
		hashtab->nulleff();
		flag = hashtab->Find(str);
		if (flag)
		{
			tmp = hashtab->GetCurr();
			dataGridView1->Rows->Clear();
			dataGridView1->Rows->Add();
			dataGridView1->Rows[i]->Cells[0]->Value = Convert::ToString(StrToStr(tmp.Key));
			dataGridView1->Rows[i]->Cells[1]->Value = Convert::ToString(tmp.Value);
			System::String^ eff_str = hashtab->geteff().ToString();
			eff_output->Text = eff_str;
		}
		else
		{
			dataGridView1->Rows->Clear();
			dataGridView1->Rows->Add();
			dataGridView1->Rows[i]->Cells[0]->Value = "Nothing found";
		}
	}
	else if (*mode == TTREE_TABLE)
	{
		treetab->nulleff();
		flag = scantab->Find(str);
		if (flag)
		{
			treetab->SetpCurrTopRes();
			tmp = treetab->GetCurr();
			dataGridView1->Rows->Clear();
			dataGridView1->Rows->Add();
			dataGridView1->Rows[i]->Cells[0]->Value = Convert::ToString(StrToStr(tmp.Key));
			dataGridView1->Rows[i]->Cells[1]->Value = Convert::ToString(tmp.Value);
			System::String^ eff_str = treetab->geteff().ToString();
			eff_output->Text = eff_str;

		}
		else
		{
			dataGridView1->Rows->Clear();
			dataGridView1->Rows->Add();
			dataGridView1->Rows[i]->Cells[0]->Value = "Nothing found";
		}
	}
	/*if (flag)
		Delete_button->Enabled = true;*/
}
private: System::Void eff_null_Click(System::Object^  sender, System::EventArgs^  e) {
	ResetEff();
}
	private:void ResetEff()
	{
		sorttab->nulleff();
		scantab->nulleff();
		hashtab->nulleff();
		treetab->nulleff();
		eff_output->Text = "0";
	}
private: System::Void Delete_button_Click(System::Object^  sender, System::EventArgs^  e) {
	ResetEff();
	string str = msclr::interop::marshal_as<std::string>(Insert_textbox->Text);

	sorttab->Delete(str);
	scantab->Delete(str);
	hashtab->Delete(str);
	treetab->Delete(str);

	if (*mode == TSCAN_TABLE)
		eff_output->Text = scantab->geteff().ToString();
	if (*mode == TSORT_TABLE)
		eff_output->Text = sorttab->geteff().ToString();
	if (*mode == THASH_TABLE)
		eff_output->Text = hashtab->geteff().ToString();
	if (*mode == TTREE_TABLE)
		eff_output->Text = treetab->geteff().ToString();
	Reload();
}
	private:void Reload()
	{
		TRecord<string, int> tmp;
		dataGridView1->Rows->Clear();
		if (*mode == TSCAN_TABLE)
		{
			int i = 0;
			for (scantab->Reset(); !scantab->IsEnd(); scantab->GoNext())
			{

				tmp = scantab->GetCurr();
				dataGridView1->Rows->Add();
				dataGridView1->Rows[i]->Cells[0]->Value = Convert::ToString(StrToStr(tmp.Key));
				dataGridView1->Rows[i]->Cells[1]->Value = Convert::ToString(tmp.Value);
				i++;

			}
		}
		else if (*mode == TSORT_TABLE)
		{
			int i = 0;
			for (sorttab->Reset(); !sorttab->IsEnd(); sorttab->GoNext())
			{

				tmp = sorttab->GetCurr();
				dataGridView1->Rows->Add();
				dataGridView1->Rows[i]->Cells[0]->Value = Convert::ToString(StrToStr(tmp.Key));
				dataGridView1->Rows[i]->Cells[1]->Value = Convert::ToString(tmp.Value);
				i++;
			}
		}
		else if (*mode == THASH_TABLE)
		{
			int i = 0;
			for (hashtab->Reset(); !hashtab->IsEnd(); hashtab->GoNext())
			{

				tmp = hashtab->GetCurr();
				dataGridView1->Rows->Add();
				dataGridView1->Rows[i]->Cells[0]->Value = Convert::ToString(StrToStr(tmp.Key));
				dataGridView1->Rows[i]->Cells[1]->Value = Convert::ToString(tmp.Value);
				i++;
			}
		}
		else if (*mode == TTREE_TABLE)
		{
			int i = 0;
			for (treetab->Reset(); !treetab->IsEnd(); treetab->GoNext())
			{

				tmp = treetab->GetCurr();
				dataGridView1->Rows->Add();
				dataGridView1->Rows[i]->Cells[0]->Value = Convert::ToString(StrToStr(tmp.Key));
				dataGridView1->Rows[i]->Cells[1]->Value = Convert::ToString(tmp.Value);
				i++;
			}
		}
	}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void chooseTxtFileToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;

	openFileDialog1->InitialDirectory = "c:\\";
	openFileDialog1->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
	openFileDialog1->FilterIndex = 2;
	openFileDialog1->RestoreDirectory = true;
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	*fileName = msclr::interop::marshal_as<std::string>(openFileDialog1->FileName);
}
};
}
