#pragma once
//#include "Login.h";
#include "Chess.h"
#include "Minesweeper.h"

namespace KSGGames {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for PgrMenu
	/// </summary>
	public ref class PgrMenu : public System::Windows::Forms::Form
	{
	public:
		PgrMenu(void)
		{
			InitializeComponent();
			gamesPanel->Hide();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~PgrMenu()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected:
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Button^  gamesButton;
	private: System::Windows::Forms::Button^  leaderboardButton;
	private: System::Windows::Forms::Button^  userButton;
	private: System::Windows::Forms::Button^  friendsButton;
	private: System::Windows::Forms::Button^  logoutButton;
	private: System::Windows::Forms::Panel^  menuPanel;
	private: System::Windows::Forms::Panel^  gamesPanel;



	private: System::Windows::Forms::Button^  game3Button;
	private: System::Windows::Forms::Button^  game2Button;
	private: System::Windows::Forms::Button^  gamesBackButton;
	private: System::Windows::Forms::Button^  game1Button;

	private: System::Void PgrMenu_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		Application::Exit();
	}
	private: System::Void logoutButton_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();

		/*
		Login ^ log = gcnew Login;
		this->Close();
		log->Show();
		*/
	}
	private: System::Void gamesButton_Click(System::Object^  sender, System::EventArgs^  e) {
		menuPanel->Hide();
		gamesPanel->Show();
	}
	private: System::Void ChessGame(System::Object^  sender, System::EventArgs^  e) {
		Chess ^ chessGame = gcnew Chess;
		//gamesPanel->Hide();
		//menuPanel->Hide();
		//this->Hide();
		chessGame->Show();
	}
	private: System::Void MinesweeperGame(System::Object^  sender, System::EventArgs^  e) {
		Minesweeper ^ minesweeperGame = gcnew Minesweeper;
		//this->Hide();
		minesweeperGame->Show();
	}

	private: System::Void gamesBackButton_Click(System::Object^  sender, System::EventArgs^  e) {
		gamesPanel->Hide();
		menuPanel->Show();
	}

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
				 System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(PgrMenu::typeid));
				 this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
				 this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
				 this->gamesButton = (gcnew System::Windows::Forms::Button());
				 this->leaderboardButton = (gcnew System::Windows::Forms::Button());
				 this->userButton = (gcnew System::Windows::Forms::Button());
				 this->friendsButton = (gcnew System::Windows::Forms::Button());
				 this->logoutButton = (gcnew System::Windows::Forms::Button());
				 this->menuPanel = (gcnew System::Windows::Forms::Panel());
				 this->gamesPanel = (gcnew System::Windows::Forms::Panel());
				 this->gamesBackButton = (gcnew System::Windows::Forms::Button());
				 this->game3Button = (gcnew System::Windows::Forms::Button());
				 this->game2Button = (gcnew System::Windows::Forms::Button());
				 this->game1Button = (gcnew System::Windows::Forms::Button());
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
				 this->menuPanel->SuspendLayout();
				 this->gamesPanel->SuspendLayout();
				 this->SuspendLayout();
				 // 
				 // pictureBox1
				 // 
				 this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
				 this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
				 this->pictureBox1->Location = System::Drawing::Point(165, 54);
				 this->pictureBox1->Name = L"pictureBox1";
				 this->pictureBox1->Size = System::Drawing::Size(297, 215);
				 this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
				 this->pictureBox1->TabIndex = 0;
				 this->pictureBox1->TabStop = false;
				 // 
				 // pictureBox2
				 // 
				 this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
				 this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
				 this->pictureBox2->Location = System::Drawing::Point(3, 15);
				 this->pictureBox2->Name = L"pictureBox2";
				 this->pictureBox2->Size = System::Drawing::Size(370, 61);
				 this->pictureBox2->TabIndex = 1;
				 this->pictureBox2->TabStop = false;
				 // 
				 // gamesButton
				 // 
				 this->gamesButton->BackColor = System::Drawing::Color::Transparent;
				 this->gamesButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"gamesButton.BackgroundImage")));
				 this->gamesButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				 this->gamesButton->Font = (gcnew System::Drawing::Font(L"Rockwell", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->gamesButton->Location = System::Drawing::Point(67, 311);
				 this->gamesButton->Name = L"gamesButton";
				 this->gamesButton->Size = System::Drawing::Size(291, 58);
				 this->gamesButton->TabIndex = 2;
				 this->gamesButton->Text = L"GAMES";
				 this->gamesButton->UseVisualStyleBackColor = false;
				 this->gamesButton->Click += gcnew System::EventHandler(this, &PgrMenu::gamesButton_Click);
				 // 
				 // leaderboardButton
				 // 
				 this->leaderboardButton->BackColor = System::Drawing::Color::Transparent;
				 this->leaderboardButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"leaderboardButton.BackgroundImage")));
				 this->leaderboardButton->Enabled = false;
				 this->leaderboardButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				 this->leaderboardButton->Font = (gcnew System::Drawing::Font(L"Rockwell", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->leaderboardButton->Location = System::Drawing::Point(67, 386);
				 this->leaderboardButton->Name = L"leaderboardButton";
				 this->leaderboardButton->Size = System::Drawing::Size(291, 58);
				 this->leaderboardButton->TabIndex = 3;
				 this->leaderboardButton->Text = L"LEADERBOARD";
				 this->leaderboardButton->UseVisualStyleBackColor = false;
				 // 
				 // userButton
				 // 
				 this->userButton->BackColor = System::Drawing::Color::Transparent;
				 this->userButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"userButton.BackgroundImage")));
				 this->userButton->Enabled = false;
				 this->userButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				 this->userButton->Font = (gcnew System::Drawing::Font(L"Rockwell", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->userButton->Location = System::Drawing::Point(67, 459);
				 this->userButton->Name = L"userButton";
				 this->userButton->Size = System::Drawing::Size(291, 58);
				 this->userButton->TabIndex = 4;
				 this->userButton->Text = L"USER";
				 this->userButton->UseVisualStyleBackColor = false;
				 // 
				 // friendsButton
				 // 
				 this->friendsButton->BackColor = System::Drawing::Color::Transparent;
				 this->friendsButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"friendsButton.BackgroundImage")));
				 this->friendsButton->Enabled = false;
				 this->friendsButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				 this->friendsButton->Font = (gcnew System::Drawing::Font(L"Rockwell", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->friendsButton->Location = System::Drawing::Point(67, 533);
				 this->friendsButton->Name = L"friendsButton";
				 this->friendsButton->Size = System::Drawing::Size(291, 58);
				 this->friendsButton->TabIndex = 5;
				 this->friendsButton->Text = L"FRIENDS (\?)";
				 this->friendsButton->UseVisualStyleBackColor = false;
				 // 
				 // logoutButton
				 // 
				 this->logoutButton->BackColor = System::Drawing::Color::Transparent;
				 this->logoutButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"logoutButton.BackgroundImage")));
				 this->logoutButton->Enabled = false;
				 this->logoutButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				 this->logoutButton->Font = (gcnew System::Drawing::Font(L"Rockwell", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->logoutButton->Location = System::Drawing::Point(67, 608);
				 this->logoutButton->Name = L"logoutButton";
				 this->logoutButton->Size = System::Drawing::Size(291, 58);
				 this->logoutButton->TabIndex = 6;
				 this->logoutButton->Text = L"LOGOUT";
				 this->logoutButton->UseVisualStyleBackColor = false;
				 this->logoutButton->Click += gcnew System::EventHandler(this, &PgrMenu::logoutButton_Click);
				 // 
				 // menuPanel
				 // 
				 this->menuPanel->BackColor = System::Drawing::Color::Transparent;
				 this->menuPanel->Controls->Add(this->pictureBox2);
				 this->menuPanel->Controls->Add(this->userButton);
				 this->menuPanel->Controls->Add(this->friendsButton);
				 this->menuPanel->Controls->Add(this->leaderboardButton);
				 this->menuPanel->Controls->Add(this->logoutButton);
				 this->menuPanel->Controls->Add(this->gamesButton);
				 this->menuPanel->Controls->Add(this->pictureBox1);
				 this->menuPanel->Location = System::Drawing::Point(23, 33);
				 this->menuPanel->Name = L"menuPanel";
				 this->menuPanel->Size = System::Drawing::Size(428, 705);
				 this->menuPanel->TabIndex = 7;
				 // 
				 // gamesPanel
				 // 
				 this->gamesPanel->BackColor = System::Drawing::Color::Transparent;
				 this->gamesPanel->Controls->Add(this->gamesBackButton);
				 this->gamesPanel->Controls->Add(this->game3Button);
				 this->gamesPanel->Controls->Add(this->game2Button);
				 this->gamesPanel->Controls->Add(this->game1Button);
				 this->gamesPanel->Location = System::Drawing::Point(23, 33);
				 this->gamesPanel->Name = L"gamesPanel";
				 this->gamesPanel->Size = System::Drawing::Size(428, 705);
				 this->gamesPanel->TabIndex = 8;
				 // 
				 // gamesBackButton
				 // 
				 this->gamesBackButton->BackColor = System::Drawing::Color::Transparent;
				 this->gamesBackButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"gamesBackButton.BackgroundImage")));
				 this->gamesBackButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				 this->gamesBackButton->Font = (gcnew System::Drawing::Font(L"Rockwell", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->gamesBackButton->Location = System::Drawing::Point(67, 544);
				 this->gamesBackButton->Name = L"gamesBackButton";
				 this->gamesBackButton->Size = System::Drawing::Size(291, 58);
				 this->gamesBackButton->TabIndex = 8;
				 this->gamesBackButton->Text = L"BACK";
				 this->gamesBackButton->UseVisualStyleBackColor = false;
				 this->gamesBackButton->Click += gcnew System::EventHandler(this, &PgrMenu::gamesBackButton_Click);
				 // 
				 // game3Button
				 // 
				 this->game3Button->BackColor = System::Drawing::Color::Transparent;
				 this->game3Button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"game3Button.BackgroundImage")));
				 this->game3Button->Enabled = false;
				 this->game3Button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				 this->game3Button->Font = (gcnew System::Drawing::Font(L"Rockwell", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->game3Button->Location = System::Drawing::Point(67, 322);
				 this->game3Button->Name = L"game3Button";
				 this->game3Button->Size = System::Drawing::Size(291, 58);
				 this->game3Button->TabIndex = 6;
				 this->game3Button->Text = L"GAME3";
				 this->game3Button->UseVisualStyleBackColor = false;
				 // 
				 // game2Button
				 // 
				 this->game2Button->BackColor = System::Drawing::Color::Transparent;
				 this->game2Button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"game2Button.BackgroundImage")));
				 this->game2Button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				 this->game2Button->Font = (gcnew System::Drawing::Font(L"Rockwell", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->game2Button->Location = System::Drawing::Point(67, 211);
				 this->game2Button->Name = L"game2Button";
				 this->game2Button->Size = System::Drawing::Size(291, 58);
				 this->game2Button->TabIndex = 5;
				 this->game2Button->Text = L"MINESWEEPER";
				 this->game2Button->UseVisualStyleBackColor = false;
				 this->game2Button->Click += gcnew System::EventHandler(this, &PgrMenu::MinesweeperGame);
				 // 
				 // game1Button
				 // 
				 this->game1Button->BackColor = System::Drawing::Color::Transparent;
				 this->game1Button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"game1Button.BackgroundImage")));
				 this->game1Button->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				 this->game1Button->Font = (gcnew System::Drawing::Font(L"Rockwell", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->game1Button->Location = System::Drawing::Point(67, 100);
				 this->game1Button->Name = L"game1Button";
				 this->game1Button->Size = System::Drawing::Size(291, 58);
				 this->game1Button->TabIndex = 4;
				 this->game1Button->Text = L"CHESS";
				 this->game1Button->UseVisualStyleBackColor = false;
				 this->game1Button->Click += gcnew System::EventHandler(this, &PgrMenu::ChessGame);
				 // 
				 // PgrMenu
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
				 this->ClientSize = System::Drawing::Size(463, 750);
				 this->Controls->Add(this->gamesPanel);
				 this->Controls->Add(this->menuPanel);
				 this->Cursor = System::Windows::Forms::Cursors::Default;
				 this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
				 this->MaximizeBox = false;
				 this->Name = L"PgrMenu";
				 this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
				 this->Text = L"PgrMenu";
				 this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &PgrMenu::PgrMenu_FormClosing);
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
				 this->menuPanel->ResumeLayout(false);
				 this->gamesPanel->ResumeLayout(false);
				 this->ResumeLayout(false);

			 }
#pragma endregion

};
}
