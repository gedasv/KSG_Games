#pragma once

#include "Game1.h"
#include "Game2.h"
#include "Leaderboard.h"
#include "Settings.h"
#include "AdminMenu.h"

namespace KSGGames {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MenuPage
	/// </summary>
	public ref class MenuPage : public System::Windows::Forms::Form
	{
	public:
		MenuPage(void)
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
		~MenuPage()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  Game1But;
	private: System::Windows::Forms::Button^  Game2But;
	private: System::Windows::Forms::Button^  LeaderboardBut;
	private: System::Windows::Forms::Button^  SettingsBut;
	private: System::Windows::Forms::Button^  AdminBut;
	protected:





	protected:

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MenuPage::typeid));
			this->Game1But = (gcnew System::Windows::Forms::Button());
			this->Game2But = (gcnew System::Windows::Forms::Button());
			this->LeaderboardBut = (gcnew System::Windows::Forms::Button());
			this->SettingsBut = (gcnew System::Windows::Forms::Button());
			this->AdminBut = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Game1But
			// 
			this->Game1But->Location = System::Drawing::Point(100, 195);
			this->Game1But->Name = L"Game1But";
			this->Game1But->Size = System::Drawing::Size(75, 23);
			this->Game1But->TabIndex = 0;
			this->Game1But->Text = L"Game-1";
			this->Game1But->UseVisualStyleBackColor = true;
			this->Game1But->Click += gcnew System::EventHandler(this, &MenuPage::Game1But_Click);
			// 
			// Game2But
			// 
			this->Game2But->Location = System::Drawing::Point(320, 195);
			this->Game2But->Name = L"Game2But";
			this->Game2But->Size = System::Drawing::Size(75, 23);
			this->Game2But->TabIndex = 1;
			this->Game2But->Text = L"Game-2";
			this->Game2But->UseVisualStyleBackColor = true;
			this->Game2But->Click += gcnew System::EventHandler(this, &MenuPage::Game2But_Click);
			// 
			// LeaderboardBut
			// 
			this->LeaderboardBut->Location = System::Drawing::Point(199, 279);
			this->LeaderboardBut->Name = L"LeaderboardBut";
			this->LeaderboardBut->Size = System::Drawing::Size(75, 23);
			this->LeaderboardBut->TabIndex = 2;
			this->LeaderboardBut->Text = L"Leaderboard";
			this->LeaderboardBut->UseVisualStyleBackColor = true;
			this->LeaderboardBut->Click += gcnew System::EventHandler(this, &MenuPage::LeaderboardBut_Click);
			// 
			// SettingsBut
			// 
			this->SettingsBut->Location = System::Drawing::Point(199, 386);
			this->SettingsBut->Name = L"SettingsBut";
			this->SettingsBut->Size = System::Drawing::Size(75, 23);
			this->SettingsBut->TabIndex = 3;
			this->SettingsBut->Text = L"Settings";
			this->SettingsBut->UseVisualStyleBackColor = true;
			this->SettingsBut->Click += gcnew System::EventHandler(this, &MenuPage::SettingsBut_Click);
			// 
			// AdminBut
			// 
			this->AdminBut->Location = System::Drawing::Point(396, 517);
			this->AdminBut->Name = L"AdminBut";
			this->AdminBut->Size = System::Drawing::Size(75, 23);
			this->AdminBut->TabIndex = 4;
			this->AdminBut->Text = L"Admin";
			this->AdminBut->UseVisualStyleBackColor = true;
			this->AdminBut->Visible = false;
			this->AdminBut->Click += gcnew System::EventHandler(this, &MenuPage::AdminBut_Click);
			// 
			// MenuPage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(509, 572);
			this->Controls->Add(this->AdminBut);
			this->Controls->Add(this->SettingsBut);
			this->Controls->Add(this->LeaderboardBut);
			this->Controls->Add(this->Game2But);
			this->Controls->Add(this->Game1But);
			this->Name = L"MenuPage";
			this->Text = L"MenuPage";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Game1But_Click(System::Object^  sender, System::EventArgs^  e) {
		Game1^ input = gcnew Game1();
		input->ShowDialog();
	}
	private: System::Void Game2But_Click(System::Object^  sender, System::EventArgs^  e) {
		Game2^ input = gcnew Game2();
		input->ShowDialog();
	}
	private: System::Void LeaderboardBut_Click(System::Object^  sender, System::EventArgs^  e) {
		Leaderboard^ input = gcnew Leaderboard();
		input->ShowDialog();
	}
	private: System::Void SettingsBut_Click(System::Object^  sender, System::EventArgs^  e) {
		Settings^ input = gcnew Settings();
		input->ShowDialog();
	}
	private: System::Void AdminBut_Click(System::Object^  sender, System::EventArgs^  e) {
		AdminMenu^ input = gcnew AdminMenu();
		input->ShowDialog();
	}
	};
}
