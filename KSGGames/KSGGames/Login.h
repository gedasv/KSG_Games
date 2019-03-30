#pragma once
#include <msclr\marshal_cppstd.h>
#include <regex>
#include "PgrMenu.h"

namespace KSGGames {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;



	/// <summary>
	/// Summary for Login
	/// </summary>
	public ref class Login : public System::Windows::Forms::Form
	{
	public:
		Login(void)
		{
			bool nameValidation(String^ name);
			bool passwordValidation(String^ pass1, String^ pass2);
			bool emailValidation(String^ email);

			InitializeComponent();
			registerPanel->Hide();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Login()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  loginButton1;
	private: System::Windows::Forms::Label^  loginLabel1;
	private: System::Windows::Forms::TextBox^  loginTextBox1;
	private: System::Windows::Forms::Label^  loginLabel2;
	private: System::Windows::Forms::Label^  loginLabel3;
	private: System::Windows::Forms::TextBox^  loginTextBox2;

	private: System::Windows::Forms::Label^  loginLabel4;
	private: System::Windows::Forms::Panel^  loginPanel;
	private: System::Windows::Forms::Panel^  registerPanel;
	private: System::Windows::Forms::TextBox^  registerTextBox3;
	private: System::Windows::Forms::Label^  registerLabel6;
	private: System::Windows::Forms::Label^  registerLabel5;
	private: System::Windows::Forms::TextBox^  registerTextBox6;
	private: System::Windows::Forms::Label^  registerLabel9;
	private: System::Windows::Forms::TextBox^  registerTextBox5;
	private: System::Windows::Forms::Label^  registerLabel8;
	private: System::Windows::Forms::TextBox^  registerTextBox4;
	private: System::Windows::Forms::Label^  registerLabel7;
	private: System::Windows::Forms::Label^  registerLabel10;

	private: System::Windows::Forms::Button^  registerButton2;
	private: System::Windows::Forms::Label^  registerErrorLabel4;

	private: System::Windows::Forms::Label^  registerErrorLabel3;

	private: System::Windows::Forms::Label^  registerErrorLabel2;

	private: System::Windows::Forms::Label^  registerErrorLabel1;
	private: System::Windows::Forms::Label^  registerErrorLabel0;



	protected:

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Login::typeid));
			this->loginButton1 = (gcnew System::Windows::Forms::Button());
			this->loginLabel1 = (gcnew System::Windows::Forms::Label());
			this->loginTextBox1 = (gcnew System::Windows::Forms::TextBox());
			this->loginLabel2 = (gcnew System::Windows::Forms::Label());
			this->loginLabel3 = (gcnew System::Windows::Forms::Label());
			this->loginTextBox2 = (gcnew System::Windows::Forms::TextBox());
			this->loginLabel4 = (gcnew System::Windows::Forms::Label());
			this->loginPanel = (gcnew System::Windows::Forms::Panel());
			this->registerPanel = (gcnew System::Windows::Forms::Panel());
			this->registerErrorLabel0 = (gcnew System::Windows::Forms::Label());
			this->registerErrorLabel4 = (gcnew System::Windows::Forms::Label());
			this->registerErrorLabel3 = (gcnew System::Windows::Forms::Label());
			this->registerErrorLabel2 = (gcnew System::Windows::Forms::Label());
			this->registerErrorLabel1 = (gcnew System::Windows::Forms::Label());
			this->registerLabel10 = (gcnew System::Windows::Forms::Label());
			this->registerButton2 = (gcnew System::Windows::Forms::Button());
			this->registerTextBox6 = (gcnew System::Windows::Forms::TextBox());
			this->registerLabel9 = (gcnew System::Windows::Forms::Label());
			this->registerTextBox5 = (gcnew System::Windows::Forms::TextBox());
			this->registerLabel8 = (gcnew System::Windows::Forms::Label());
			this->registerTextBox4 = (gcnew System::Windows::Forms::TextBox());
			this->registerLabel7 = (gcnew System::Windows::Forms::Label());
			this->registerTextBox3 = (gcnew System::Windows::Forms::TextBox());
			this->registerLabel6 = (gcnew System::Windows::Forms::Label());
			this->registerLabel5 = (gcnew System::Windows::Forms::Label());
			this->loginPanel->SuspendLayout();
			this->registerPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// loginButton1
			// 
			this->loginButton1->Location = System::Drawing::Point(160, 511);
			this->loginButton1->Name = L"loginButton1";
			this->loginButton1->Size = System::Drawing::Size(127, 40);
			this->loginButton1->TabIndex = 2;
			this->loginButton1->Text = L"LOGIN";
			this->loginButton1->UseVisualStyleBackColor = true;
			this->loginButton1->Click += gcnew System::EventHandler(this, &Login::loginButton1_Click);
			// 
			// loginLabel1
			// 
			this->loginLabel1->AutoSize = true;
			this->loginLabel1->BackColor = System::Drawing::Color::Transparent;
			this->loginLabel1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(186)));
			this->loginLabel1->ForeColor = System::Drawing::SystemColors::Highlight;
			this->loginLabel1->Location = System::Drawing::Point(18, 535);
			this->loginLabel1->Name = L"loginLabel1";
			this->loginLabel1->Size = System::Drawing::Size(136, 16);
			this->loginLabel1->TabIndex = 1;
			this->loginLabel1->Text = L"Create a new account";
			this->loginLabel1->Click += gcnew System::EventHandler(this, &Login::loginLabel1_Click);
			this->loginLabel1->MouseEnter += gcnew System::EventHandler(this, &Login::loginLabel1_MouseEnter);
			this->loginLabel1->MouseLeave += gcnew System::EventHandler(this, &Login::loginLabel1_MouseLeave);
			// 
			// loginTextBox1
			// 
			this->loginTextBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(186)));
			this->loginTextBox1->Location = System::Drawing::Point(21, 173);
			this->loginTextBox1->MaxLength = 36;
			this->loginTextBox1->Name = L"loginTextBox1";
			this->loginTextBox1->Size = System::Drawing::Size(271, 22);
			this->loginTextBox1->TabIndex = 0;
			// 
			// loginLabel2
			// 
			this->loginLabel2->AutoSize = true;
			this->loginLabel2->BackColor = System::Drawing::Color::Transparent;
			this->loginLabel2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(186)));
			this->loginLabel2->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->loginLabel2->Location = System::Drawing::Point(16, 133);
			this->loginLabel2->Name = L"loginLabel2";
			this->loginLabel2->Size = System::Drawing::Size(116, 25);
			this->loginLabel2->TabIndex = 3;
			this->loginLabel2->Text = L"Username:";
			// 
			// loginLabel3
			// 
			this->loginLabel3->AutoSize = true;
			this->loginLabel3->BackColor = System::Drawing::Color::Transparent;
			this->loginLabel3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(186)));
			this->loginLabel3->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->loginLabel3->Location = System::Drawing::Point(16, 228);
			this->loginLabel3->Name = L"loginLabel3";
			this->loginLabel3->Size = System::Drawing::Size(112, 25);
			this->loginLabel3->TabIndex = 4;
			this->loginLabel3->Text = L"Password:";
			// 
			// loginTextBox2
			// 
			this->loginTextBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(186)));
			this->loginTextBox2->Location = System::Drawing::Point(21, 265);
			this->loginTextBox2->MaxLength = 36;
			this->loginTextBox2->Name = L"loginTextBox2";
			this->loginTextBox2->Size = System::Drawing::Size(271, 22);
			this->loginTextBox2->TabIndex = 1;
			this->loginTextBox2->UseSystemPasswordChar = true;
			// 
			// loginLabel4
			// 
			this->loginLabel4->AutoSize = true;
			this->loginLabel4->BackColor = System::Drawing::Color::Transparent;
			this->loginLabel4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 48, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(186)));
			this->loginLabel4->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->loginLabel4->Location = System::Drawing::Point(33, 26);
			this->loginLabel4->Name = L"loginLabel4";
			this->loginLabel4->Size = System::Drawing::Size(232, 73);
			this->loginLabel4->TabIndex = 6;
			this->loginLabel4->Text = L"LOGIN";
			// 
			// loginPanel
			// 
			this->loginPanel->BackColor = System::Drawing::Color::Transparent;
			this->loginPanel->Controls->Add(this->loginLabel1);
			this->loginPanel->Controls->Add(this->loginLabel4);
			this->loginPanel->Controls->Add(this->loginButton1);
			this->loginPanel->Controls->Add(this->loginTextBox2);
			this->loginPanel->Controls->Add(this->loginTextBox1);
			this->loginPanel->Controls->Add(this->loginLabel2);
			this->loginPanel->Controls->Add(this->loginLabel3);
			this->loginPanel->Location = System::Drawing::Point(16, 14);
			this->loginPanel->Name = L"loginPanel";
			this->loginPanel->Size = System::Drawing::Size(305, 569);
			this->loginPanel->TabIndex = 0;
			// 
			// registerPanel
			// 
			this->registerPanel->BackColor = System::Drawing::Color::Transparent;
			this->registerPanel->Controls->Add(this->registerErrorLabel0);
			this->registerPanel->Controls->Add(this->registerErrorLabel4);
			this->registerPanel->Controls->Add(this->registerErrorLabel3);
			this->registerPanel->Controls->Add(this->registerErrorLabel2);
			this->registerPanel->Controls->Add(this->registerErrorLabel1);
			this->registerPanel->Controls->Add(this->registerLabel10);
			this->registerPanel->Controls->Add(this->registerButton2);
			this->registerPanel->Controls->Add(this->registerTextBox6);
			this->registerPanel->Controls->Add(this->registerLabel9);
			this->registerPanel->Controls->Add(this->registerTextBox5);
			this->registerPanel->Controls->Add(this->registerLabel8);
			this->registerPanel->Controls->Add(this->registerTextBox4);
			this->registerPanel->Controls->Add(this->registerLabel7);
			this->registerPanel->Controls->Add(this->registerTextBox3);
			this->registerPanel->Controls->Add(this->registerLabel6);
			this->registerPanel->Controls->Add(this->registerLabel5);
			this->registerPanel->Location = System::Drawing::Point(16, 12);
			this->registerPanel->Name = L"registerPanel";
			this->registerPanel->Size = System::Drawing::Size(296, 563);
			this->registerPanel->TabIndex = 1;
			// 
			// registerErrorLabel0
			// 
			this->registerErrorLabel0->AutoSize = true;
			this->registerErrorLabel0->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->registerErrorLabel0->ForeColor = System::Drawing::Color::OrangeRed;
			this->registerErrorLabel0->Location = System::Drawing::Point(142, 167);
			this->registerErrorLabel0->Name = L"registerErrorLabel0";
			this->registerErrorLabel0->Size = System::Drawing::Size(150, 20);
			this->registerErrorLabel0->TabIndex = 20;
			this->registerErrorLabel0->Text = L"Name already exists";
			// 
			// registerErrorLabel4
			// 
			this->registerErrorLabel4->AutoSize = true;
			this->registerErrorLabel4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->registerErrorLabel4->ForeColor = System::Drawing::Color::OrangeRed;
			this->registerErrorLabel4->Location = System::Drawing::Point(119, 440);
			this->registerErrorLabel4->Name = L"registerErrorLabel4";
			this->registerErrorLabel4->Size = System::Drawing::Size(173, 20);
			this->registerErrorLabel4->TabIndex = 19;
			this->registerErrorLabel4->Text = L"Passwords don\'t match";
			// 
			// registerErrorLabel3
			// 
			this->registerErrorLabel3->AutoSize = true;
			this->registerErrorLabel3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->registerErrorLabel3->ForeColor = System::Drawing::Color::OrangeRed;
			this->registerErrorLabel3->Location = System::Drawing::Point(162, 350);
			this->registerErrorLabel3->Name = L"registerErrorLabel3";
			this->registerErrorLabel3->Size = System::Drawing::Size(130, 20);
			this->registerErrorLabel3->TabIndex = 18;
			this->registerErrorLabel3->Text = L"Invalid password!";
			// 
			// registerErrorLabel2
			// 
			this->registerErrorLabel2->AutoSize = true;
			this->registerErrorLabel2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->registerErrorLabel2->ForeColor = System::Drawing::Color::OrangeRed;
			this->registerErrorLabel2->Location = System::Drawing::Point(190, 254);
			this->registerErrorLabel2->Name = L"registerErrorLabel2";
			this->registerErrorLabel2->Size = System::Drawing::Size(100, 20);
			this->registerErrorLabel2->TabIndex = 17;
			this->registerErrorLabel2->Text = L"Invalid e-mail";
			// 
			// registerErrorLabel1
			// 
			this->registerErrorLabel1->AutoSize = true;
			this->registerErrorLabel1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->registerErrorLabel1->ForeColor = System::Drawing::Color::OrangeRed;
			this->registerErrorLabel1->Location = System::Drawing::Point(195, 167);
			this->registerErrorLabel1->Name = L"registerErrorLabel1";
			this->registerErrorLabel1->Size = System::Drawing::Size(98, 20);
			this->registerErrorLabel1->TabIndex = 16;
			this->registerErrorLabel1->Text = L"Invalid name";
			// 
			// registerLabel10
			// 
			this->registerLabel10->AutoSize = true;
			this->registerLabel10->BackColor = System::Drawing::Color::Transparent;
			this->registerLabel10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(186)));
			this->registerLabel10->ForeColor = System::Drawing::SystemColors::Highlight;
			this->registerLabel10->Location = System::Drawing::Point(25, 537);
			this->registerLabel10->Name = L"registerLabel10";
			this->registerLabel10->Size = System::Drawing::Size(53, 16);
			this->registerLabel10->TabIndex = 15;
			this->registerLabel10->Text = L"<- Back";
			this->registerLabel10->Click += gcnew System::EventHandler(this, &Login::registerLabel10_Click);
			this->registerLabel10->MouseEnter += gcnew System::EventHandler(this, &Login::registerLabel10_MouseEnter);
			this->registerLabel10->MouseLeave += gcnew System::EventHandler(this, &Login::registerLabel10_MouseLeave);
			// 
			// registerButton2
			// 
			this->registerButton2->Location = System::Drawing::Point(135, 520);
			this->registerButton2->Name = L"registerButton2";
			this->registerButton2->Size = System::Drawing::Size(157, 40);
			this->registerButton2->TabIndex = 14;
			this->registerButton2->Text = L"REGISTER NEW USER";
			this->registerButton2->UseVisualStyleBackColor = true;
			this->registerButton2->Click += gcnew System::EventHandler(this, &Login::registerButton2_Click);
			// 
			// registerTextBox6
			// 
			this->registerTextBox6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(186)));
			this->registerTextBox6->Location = System::Drawing::Point(21, 415);
			this->registerTextBox6->MaxLength = 36;
			this->registerTextBox6->Name = L"registerTextBox6";
			this->registerTextBox6->PasswordChar = '*';
			this->registerTextBox6->Size = System::Drawing::Size(271, 22);
			this->registerTextBox6->TabIndex = 13;
			this->registerTextBox6->UseSystemPasswordChar = true;
			// 
			// registerLabel9
			// 
			this->registerLabel9->AutoSize = true;
			this->registerLabel9->BackColor = System::Drawing::Color::Transparent;
			this->registerLabel9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(186)));
			this->registerLabel9->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->registerLabel9->Location = System::Drawing::Point(16, 378);
			this->registerLabel9->Name = L"registerLabel9";
			this->registerLabel9->Size = System::Drawing::Size(192, 25);
			this->registerLabel9->TabIndex = 12;
			this->registerLabel9->Text = L"Confirm Password:";
			// 
			// registerTextBox5
			// 
			this->registerTextBox5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(186)));
			this->registerTextBox5->Location = System::Drawing::Point(21, 325);
			this->registerTextBox5->MaxLength = 36;
			this->registerTextBox5->Name = L"registerTextBox5";
			this->registerTextBox5->Size = System::Drawing::Size(271, 22);
			this->registerTextBox5->TabIndex = 11;
			this->registerTextBox5->UseSystemPasswordChar = true;
			// 
			// registerLabel8
			// 
			this->registerLabel8->AutoSize = true;
			this->registerLabel8->BackColor = System::Drawing::Color::Transparent;
			this->registerLabel8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(186)));
			this->registerLabel8->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->registerLabel8->Location = System::Drawing::Point(16, 287);
			this->registerLabel8->Name = L"registerLabel8";
			this->registerLabel8->Size = System::Drawing::Size(112, 25);
			this->registerLabel8->TabIndex = 10;
			this->registerLabel8->Text = L"Password:";
			// 
			// registerTextBox4
			// 
			this->registerTextBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(186)));
			this->registerTextBox4->Location = System::Drawing::Point(21, 229);
			this->registerTextBox4->MaxLength = 36;
			this->registerTextBox4->Name = L"registerTextBox4";
			this->registerTextBox4->Size = System::Drawing::Size(271, 22);
			this->registerTextBox4->TabIndex = 9;
			// 
			// registerLabel7
			// 
			this->registerLabel7->AutoSize = true;
			this->registerLabel7->BackColor = System::Drawing::Color::Transparent;
			this->registerLabel7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(186)));
			this->registerLabel7->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->registerLabel7->Location = System::Drawing::Point(16, 195);
			this->registerLabel7->Name = L"registerLabel7";
			this->registerLabel7->Size = System::Drawing::Size(79, 25);
			this->registerLabel7->TabIndex = 8;
			this->registerLabel7->Text = L"E-Mail:";
			// 
			// registerTextBox3
			// 
			this->registerTextBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(186)));
			this->registerTextBox3->Location = System::Drawing::Point(21, 142);
			this->registerTextBox3->MaxLength = 36;
			this->registerTextBox3->Name = L"registerTextBox3";
			this->registerTextBox3->Size = System::Drawing::Size(271, 22);
			this->registerTextBox3->TabIndex = 7;
			// 
			// registerLabel6
			// 
			this->registerLabel6->AutoSize = true;
			this->registerLabel6->BackColor = System::Drawing::Color::Transparent;
			this->registerLabel6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(186)));
			this->registerLabel6->ForeColor = System::Drawing::SystemColors::ActiveCaption;
			this->registerLabel6->Location = System::Drawing::Point(16, 105);
			this->registerLabel6->Name = L"registerLabel6";
			this->registerLabel6->Size = System::Drawing::Size(116, 25);
			this->registerLabel6->TabIndex = 7;
			this->registerLabel6->Text = L"Username:";
			// 
			// registerLabel5
			// 
			this->registerLabel5->AutoSize = true;
			this->registerLabel5->BackColor = System::Drawing::Color::Transparent;
			this->registerLabel5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(186)));
			this->registerLabel5->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->registerLabel5->Location = System::Drawing::Point(18, 23);
			this->registerLabel5->Name = L"registerLabel5";
			this->registerLabel5->Size = System::Drawing::Size(269, 55);
			this->registerLabel5->TabIndex = 7;
			this->registerLabel5->Text = L"REGISTER";
			// 
			// Login
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(329, 593);
			this->Controls->Add(this->registerPanel);
			this->Controls->Add(this->loginPanel);
			this->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->MaximizeBox = false;
			this->Name = L"Login";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"-";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Login::Login_FormClosing);
			this->loginPanel->ResumeLayout(false);
			this->loginPanel->PerformLayout();
			this->registerPanel->ResumeLayout(false);
			this->registerPanel->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

		////////////////////////////
		/*  LOGIN PANEL CONTROLS  */
		////////////////////////////

		private: System::Void loginButton1_Click(System::Object^  sender, System::EventArgs^  e) {
			PgrMenu ^ PgrMenuForm = gcnew PgrMenu;
			this->Hide();
			PgrMenuForm->Show();
			//loginLabel1->Text = this->Parent;
		}

		private: System::Void Login_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
			Application::Exit();
		}
		private: System::Void loginLabel1_Click(System::Object^  sender, System::EventArgs^  e) {
			loginPanel->Hide();
			registerTextBox3->Clear();
			registerTextBox4->Clear();
			registerTextBox5->Clear();
			registerTextBox6->Clear();
			registerErrorLabel0->Hide();
			registerErrorLabel1->Hide();
			registerErrorLabel2->Hide();
			registerErrorLabel3->Hide();
			registerErrorLabel4->Hide();
			registerPanel->Show();
		}

		private: System::Void loginLabel1_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
			loginLabel1->ForeColor = System::Drawing::SystemColors::HotTrack;
		}
		private: System::Void loginLabel1_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
			loginLabel1->ForeColor = System::Drawing::SystemColors::MenuHighlight;
		}
		/////////////////////////////
		/* REGISTER PANEL CONTROLS */
		/////////////////////////////

		private: System::Void registerLabel10_Click(System::Object^  sender, System::EventArgs^  e) {
			registerPanel->Hide();
			loginTextBox1->Clear();
			loginTextBox2->Clear();
			loginPanel->Show();
		}

		private: System::Void registerButton2_Click(System::Object^  sender, System::EventArgs^  e) {
			bool validName = nameValidation(registerTextBox3->Text);
			bool validEmail = emailValidation(registerTextBox4->Text);
			bool validPass = passwordValidation(registerTextBox5->Text, registerTextBox6->Text);

			if (validName && validEmail && validPass) {
				registerLabel5->Text = "WORKS";
			}
			else {
				registerLabel5->Text = "NOPE";
			}
		}

		bool nameValidation(String^ unmanagedName) {
			std::string name = msclr::interop::marshal_as<std::string>(unmanagedName);
			char c;
		
			if (name.empty()) {
				registerErrorLabel1->Show();
				return false;
			}
			/*
			for (size_t i = 0; i < user_count; i++) {
				if (Users[i].name == name) {
					registerErrorLabel0->Show();
					return false;
				}
			}
			registeredErrorLabel0->Hide();
			*/

			for (size_t i = 0; i < name.length(); i++) {
				c = name[i];
				if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))) {
					registerErrorLabel1->Show();
					return false;
				}
			}
			registerErrorLabel1->Hide();

			return true;
		}

		bool emailValidation(String^ unmanagedEmail) {
			std::string email = msclr::interop::marshal_as<std::string>(unmanagedEmail);
			const std::regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

			if (regex_match(email, pattern)) {
				registerErrorLabel2->Hide();
				return true;
			}
			else {
				registerErrorLabel2->Show();
				return false;
			}
		}

		bool passwordValidation(String^ unmanagedPass1, String^ unmanagedPass2) {
			std::string pass1 = msclr::interop::marshal_as<std::string>(unmanagedPass1);
			std::string pass2 = msclr::interop::marshal_as<std::string>(unmanagedPass2);
			char c;

			if (pass1.empty()) {
				registerErrorLabel3->Show();
				return false;
			}

			for (size_t i = 0; i < pass1.length(); i++) {
				c = pass1[i];
				if (!( (c >= 33 && c <= 126) )) {
					registerErrorLabel3->Show();
					return false;
				}
			}
			registerErrorLabel3->Hide();

			if (pass1 != pass2) {
				registerErrorLabel4->Show();
				
				registerTextBox6->Text = "";
				return false;
			}
			registerErrorLabel4->Hide();

			return true;
		}

		private: System::Void registerLabel10_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
			registerLabel10->ForeColor = System::Drawing::SystemColors::HotTrack;
		}
		private: System::Void registerLabel10_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
			registerLabel10->ForeColor = System::Drawing::SystemColors::MenuHighlight;
		}
	};

}
