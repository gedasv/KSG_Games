#pragma once
//#include "logIn.h"
#include <fstream>
#include <string>
#include <msclr\marshal_cppstd.h>

namespace KSGGames {

	using namespace System;
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
	private: System::Windows::Forms::TextBox^  textBox1;
	protected:
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  FrontPageButton;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->FrontPageButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 28, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(252, 185);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(426, 50);
			this->textBox1->TabIndex = 0;
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 28, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(252, 267);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(426, 50);
			this->textBox2->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 28, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(485, 350);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(170, 63);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Submit";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 28, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(136, 360);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(125, 44);
			this->label1->TabIndex = 3;
			this->label1->Text = L"WOW";
			this->label1->Visible = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->Location = System::Drawing::Point(-1, -2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(693, 446);
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			// 
			// FrontPageButton
			// 
			this->FrontPageButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FrontPageButton->Location = System::Drawing::Point(33, 351);
			this->FrontPageButton->Name = L"FrontPageButton";
			this->FrontPageButton->Size = System::Drawing::Size(123, 53);
			this->FrontPageButton->TabIndex = 5;
			this->FrontPageButton->Text = L"Start";
			this->FrontPageButton->UseVisualStyleBackColor = true;
			this->FrontPageButton->Click += gcnew System::EventHandler(this, &MyForm::pradeti);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(687, 437);
			this->Controls->Add(this->FrontPageButton);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

		using namespace std;

		msclr::interop::marshal_context tekstas;
		string name = tekstas.marshal_as<string>(this->textBox1->Text);
		string password = tekstas.marshal_as<string>(this->textBox2->Text);

		ifstream fileIn("adminLogIn.in");
		string logName, logPass;
		fileIn >> logName >> logPass;
		fileIn.close();

		if (logName == name && logPass == password)
		{
			this->label1->Text = L"Admin";
		}

		else
		{
			fileIn.open("logIn.in");

			while (!fileIn.eof())
			{
				fileIn >> logName >> logPass;

				if (logName == name && logPass == password)
				{
					this->label1->Text = L"User";
					break;
				}
				else
				{
					this->label1->Text = L"Unauthorized";
				}
			}

			fileIn.close();
		}

		this->label1->Visible = true;
	}
	private: System::Void pradeti(System::Object^  sender, System::EventArgs^  e) {
		this->FrontPageButton->Visible = false;
		this->pictureBox1->Visible = false;
	}
	};
}
