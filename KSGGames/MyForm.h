#pragma once

#include <fstream>
#include <string>
#include <msclr\marshal_cppstd.h>
#include "Register.h"
#include "MenuPage.h"

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
	private: System::Windows::Forms::Button^  SubmitButton;
	private: System::Windows::Forms::Button^  RegisterButton;
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
			this->SubmitButton = (gcnew System::Windows::Forms::Button());
			this->RegisterButton = (gcnew System::Windows::Forms::Button());
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
			// SubmitButton
			// 
			this->SubmitButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 28, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SubmitButton->Location = System::Drawing::Point(485, 350);
			this->SubmitButton->Name = L"SubmitButton";
			this->SubmitButton->Size = System::Drawing::Size(170, 63);
			this->SubmitButton->TabIndex = 2;
			this->SubmitButton->Text = L"Submit";
			this->SubmitButton->UseVisualStyleBackColor = true;
			this->SubmitButton->Click += gcnew System::EventHandler(this, &MyForm::SubmitButton_Click);
			// 
			// RegisterButton
			// 
			this->RegisterButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 28, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->RegisterButton->Location = System::Drawing::Point(32, 350);
			this->RegisterButton->Name = L"RegisterButton";
			this->RegisterButton->Size = System::Drawing::Size(170, 63);
			this->RegisterButton->TabIndex = 2;
			this->RegisterButton->Text = L"Register";
			this->RegisterButton->UseVisualStyleBackColor = true;
			this->RegisterButton->Click += gcnew System::EventHandler(this, &MyForm::RegisterButton_Click);
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
			this->Controls->Add(this->SubmitButton);
			this->Controls->Add(this->RegisterButton);
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
	private: System::Void SubmitButton_Click(System::Object^  sender, System::EventArgs^  e) {

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
			MenuPage^ input = gcnew MenuPage();
			input->ShowDialog();
		}

		else
		{
			fileIn.open("logIn.in");

			while (!fileIn.eof())
			{
				fileIn >> logName >> logPass;

				if (logName == name && logPass == password)
				{
					MenuPage^ input = gcnew MenuPage();
					input->ShowDialog();
					break;
				}
			}

			fileIn.close();
		}
	}
	private: System::Void RegisterButton_Click(System::Object^  sender, System::EventArgs^  e) {}
	private: System::Void pradeti(System::Object^  sender, System::EventArgs^  e) {
		this->FrontPageButton->Visible = false;
		this->pictureBox1->Visible = false;
	}
	};
}