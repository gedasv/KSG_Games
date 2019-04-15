#pragma once
//#include "Login.h";
#include "Chess.h"
#include "Minesweeper.h"
#include "user.h"

namespace KSGGames {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	namespace
	{
		User user;
	}

	/// <summary>
	/// Summary for PgrMenu
	/// </summary>
	public ref class PgrMenu : public System::Windows::Forms::Form
	{
	public:
		PgrMenu(int id)
		{
			InitializeComponent();
			gamesPanel->Hide();
			userPanel->Hide();
			leaderboardPanel->Hide();

			user.initUser(id);
			playerList = gcnew array<System::Windows::Forms::Label^, 2>(3, 6);

			
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 6; j++) {
			//		playerList[i][j] = leaderboardPointsLabel1;
				}
			}
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

	private: array<System::Windows::Forms::Label^, 2>^ playerList;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected:
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Button^  gamesButton;
	private: System::Windows::Forms::Button^  leaderboardButton;
	private: System::Windows::Forms::Button^  userButton;
	private: System::Windows::Forms::Button^  friendsButton;

	private: System::Windows::Forms::Panel^  menuPanel;
	private: System::Windows::Forms::Panel^  gamesPanel;
	private: System::Windows::Forms::Panel^  userPanel;

	private: System::Windows::Forms::Button^  game3Button;
	private: System::Windows::Forms::Button^  game2Button;
	private: System::Windows::Forms::Button^  gamesBackButton;
	private: System::Windows::Forms::Button^  userBackButton;

	private: System::Windows::Forms::Label^  userNameLabel;
	private: System::Windows::Forms::Label^  userLabel1;
	private: System::Windows::Forms::Label^  userEmailLabel;
	private: System::Windows::Forms::Label^  userLabel2;
	private: System::Windows::Forms::Label^  userPointsLabel;
	private: System::Windows::Forms::Label^  userLabel3;
	private: System::Windows::Forms::Button^  userTerminateAccButton;
	private: System::Windows::Forms::Button^  userChangePassButton;
	private: System::Windows::Forms::Panel^  userPasswordPanel;
	private: System::Windows::Forms::TextBox^  userTextBox1;
	private: System::Windows::Forms::Panel^  userBGPanel;

	private: System::Windows::Forms::TextBox^  userTextBox3;
	private: System::Windows::Forms::TextBox^  userTextBox2;
	private: System::Windows::Forms::Button^  userChangePassButton2;
	private: System::Windows::Forms::Panel^  userTerminatePanel;
	private: System::Windows::Forms::Button^  userTerminateButton2;
	private: System::Windows::Forms::Panel^  leaderboardPanel;
	private: System::Windows::Forms::Button^  leaderboardBackButton;
	private: System::Windows::Forms::Panel^  leaderboardListPanel;
	private: System::Windows::Forms::Label^  leaderboardsPlaceLabel1;
	private: System::Windows::Forms::Label^  leaderboardListPointsLabel;
	private: System::Windows::Forms::Label^  leaderboardListNameLabel;
	private: System::Windows::Forms::Label^  leaderboardListPlaceLabel;
	private: System::Windows::Forms::TextBox^  leaderboardSearchTextbox;
	private: System::Windows::Forms::Label^  leaderboardLabel1;
	private: System::Windows::Forms::Label^  leaderboardYourNameLabel;
	private: System::Windows::Forms::Label^  leaderboardYourPointsLabel;
	private: System::Windows::Forms::Label^  leaderboardYourPlaceLabel;

	private: System::Windows::Forms::Label^  leaderboardsPlaceLabel6;

	private: System::Windows::Forms::Label^  leaderboardsPlaceLabel5;

	private: System::Windows::Forms::Label^  leaderboardsPlaceLabel4;

	private: System::Windows::Forms::Label^  leaderboardsPlaceLabel3;

	private: System::Windows::Forms::Label^  leaderboardsPlaceLabel2;
	private: System::Windows::Forms::Label^  leaderboardPointsLabel1;

	private: System::Windows::Forms::Label^  leaderboardNameLabel1;
	private: System::Windows::Forms::Label^  leaderboardPointsLabel6;

	private: System::Windows::Forms::Label^  leaderboardPointsLabel5;

	private: System::Windows::Forms::Label^  leaderboardPointsLabel4;

	private: System::Windows::Forms::Label^  leaderboardPointsLabel3;

	private: System::Windows::Forms::Label^  leaderboardPointsLabel2;

	private: System::Windows::Forms::Label^  leaderboardNameLabel6;

	private: System::Windows::Forms::Label^  leaderboardNameLabel5;

	private: System::Windows::Forms::Label^  leaderboardNameLabel4;

	private: System::Windows::Forms::Label^  leaderboardNameLabel3;

	private: System::Windows::Forms::Label^  leaderboardNameLabel2;

	private: System::Windows::Forms::Button^  game1Button;


	private: System::Void PgrMenu_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		Application::Exit();
	}

	private: System::Void gamesButton_Click(System::Object^  sender, System::EventArgs^  e) {
		menuPanel->Hide();
		gamesPanel->Show();
	}
	private: System::Void gamesBackButton_Click(System::Object^  sender, System::EventArgs^  e) {
		gamesPanel->Hide();
		menuPanel->Show();
	}
	private: System::Void ChessGame(System::Object^  sender, System::EventArgs^  e) {
		Chess ^ chessGame = gcnew Chess;
		chessGame->Show();
	}
	private: System::Void MinesweeperGame(System::Object^  sender, System::EventArgs^  e) {
		Minesweeper ^ minesweeperGame = gcnew Minesweeper;
		minesweeperGame->Show();
	}

	private: System::Void leaderboardButton_Click(System::Object^  sender, System::EventArgs^  e) {
		menuPanel->Hide();
		leaderboardPanel->Show();
	}
	private: System::Void leaderboardBackButton_Click(System::Object^  sender, System::EventArgs^  e) {
		menuPanel->Show();
		leaderboardPanel->Hide();
	}

	private: System::Void userButton_Click(System::Object^  sender, System::EventArgs^  e) {
		menuPanel->Hide();
		userPasswordPanel->Hide();
		userTerminatePanel->Hide();
		userPanel->Show();
		

		String^ name = gcnew String(user.GetName().c_str());
		userNameLabel->Text = name;

		String^ email = gcnew String(user.GetEmail().c_str());
		userEmailLabel->Text = email;

		userPointsLabel->Text = "" + user.points;
	}
	private: System::Void userBackButton_Click(System::Object^  sender, System::EventArgs^  e) {
		userPanel->Hide();
		menuPanel->Show();
	}
	private: System::Void userChangePassButton_Click(System::Object^  sender, System::EventArgs^  e) {
		
		if (userPasswordPanel->Visible == true) {
			slideIn(userPasswordPanel, 255, 455, 20);
		}
		else {
			userTerminatePanel->Location = Point(21, 455);
			userTerminatePanel->Visible = false;
			slideOut(userPasswordPanel, 21, 455, 205);

			startPasswordText(userTextBox1, "Enter current password");
			startPasswordText(userTextBox2, "Confirm password");
			startPasswordText(userTextBox3, "New password");
		}
	}
	private: System::Void userTextBox1_Enter(System::Object^  sender, System::EventArgs^  e) {
		resetPasswordText(userTextBox1);

	}
	private: System::Void userTextBox2_Enter(System::Object^  sender, System::EventArgs^  e) {
		resetPasswordText(userTextBox2);

	}
	private: System::Void userTextBox3_Enter(System::Object^  sender, System::EventArgs^  e) {
		resetPasswordText(userTextBox3);
	}
	private: System::Void userChangePassButton2_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ password = gcnew String(user.GetPassword().c_str());
		MySqlConnection^ conn;
		MySqlDataReader^ dr;
		MySqlCommand^ cmd;
		connectToSQL(conn);

		if (userTextBox1->Text != password) {
			errorPasswordText(userTextBox1, "Incorrect password");
			userTextBox2->Text = "";
			return;
		}
		
		if (userTextBox1->Text != userTextBox2->Text) {
			errorPasswordText(userTextBox2, "Passwords don't match");
			userTextBox1->Text = "";
			return;
		}

		if (userTextBox3->Text == "" || userTextBox3->Text == "Invalid password") {
			errorPasswordText(userTextBox3, "Invalid password");
			return;
		}
		
		try {
			cmd = gcnew MySqlCommand("UPDATE users SET password='" + userTextBox3->Text + "' WHERE id=" + user.GetId() + "", conn);
			dr = cmd->ExecuteReader();

			std::string newPassword = msclr::interop::marshal_as<std::string>(userTextBox3->Text);
			user.SetPassword(newPassword);

			MessageBox::Show("Password updated successfully.");
			dr->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message);
		}
		conn->Close();
	}
	private: System::Void userTerminateAccButton_Click(System::Object^  sender, System::EventArgs^  e) {
		if (userTerminatePanel->Visible == true) {
			slideIn(userTerminatePanel, 255, 455, 20);
		}
		else {
			userPasswordPanel->Location = Point(21, 455);
			userPasswordPanel->Visible = false;
			slideOut(userTerminatePanel, 21, 455, 205);
		}
	}
	private: System::Void userTerminateButton2_Click(System::Object^  sender, System::EventArgs^  e) {
		auto confirmResult = MessageBox::Show("Are you sure to terminate your account?", "Confirm", MessageBoxButtons::YesNo);
		if (confirmResult == System::Windows::Forms::DialogResult::Yes) {
			try {
				String^ password = gcnew String(user.GetPassword().c_str());
				MySqlConnection^ conn;
				MySqlCommand^ cmd;
				connectToSQL(conn);

				cmd = gcnew MySqlCommand("DELETE FROM users WHERE id=" + user.GetId() + "", conn);
				cmd->ExecuteReader();

				MessageBox::Show("User deleted successfully.");

				conn->Close();
				Application::Exit();
			}
			catch (Exception^ ex) {
				MessageBox::Show(ex->Message);
			}
		}
	}

	private: void slideIn(System::Windows::Forms::Panel^ panel, int x, int y, int xTo) {
		panel->Location = Point(x, y);
		while (panel->Location.X > xTo) {
			panel->Location = Point(panel->Location.X - 50, y);
			System::Threading::Thread::Sleep(5);
		}
		panel->Hide();
	}
	private: void slideOut(System::Windows::Forms::Panel^ panel, int x, int y, int xTo) {
		panel->Show();
		panel->Location = Point(x, y);
		while (panel->Location.X < xTo) {
			panel->Location = Point(panel->Location.X + 50, y);
			System::Threading::Thread::Sleep(5);
		}
	}

	private: void startPasswordText(System::Windows::Forms::TextBox^ textBox, String^ str) {
		textBox->UseSystemPasswordChar = false;
		textBox->Text = str;
		textBox->ForeColor = Color::DarkGray;

	}
	private: void errorPasswordText(System::Windows::Forms::TextBox^ textBox, String^ str) {
		textBox->ForeColor = Color::Red;
		textBox->UseSystemPasswordChar = false;
		textBox->Text = str;
	}
	private: void resetPasswordText(System::Windows::Forms::TextBox^ textBox) {
		textBox->Text = "";
		textBox->ForeColor = Color::Black;
		textBox->UseSystemPasswordChar = true;
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
				 this->menuPanel = (gcnew System::Windows::Forms::Panel());
				 this->gamesPanel = (gcnew System::Windows::Forms::Panel());
				 this->gamesBackButton = (gcnew System::Windows::Forms::Button());
				 this->game3Button = (gcnew System::Windows::Forms::Button());
				 this->game2Button = (gcnew System::Windows::Forms::Button());
				 this->game1Button = (gcnew System::Windows::Forms::Button());
				 this->userPanel = (gcnew System::Windows::Forms::Panel());
				 this->userChangePassButton = (gcnew System::Windows::Forms::Button());
				 this->userTerminateAccButton = (gcnew System::Windows::Forms::Button());
				 this->userPointsLabel = (gcnew System::Windows::Forms::Label());
				 this->userLabel3 = (gcnew System::Windows::Forms::Label());
				 this->userEmailLabel = (gcnew System::Windows::Forms::Label());
				 this->userLabel2 = (gcnew System::Windows::Forms::Label());
				 this->userLabel1 = (gcnew System::Windows::Forms::Label());
				 this->userNameLabel = (gcnew System::Windows::Forms::Label());
				 this->userBackButton = (gcnew System::Windows::Forms::Button());
				 this->userBGPanel = (gcnew System::Windows::Forms::Panel());
				 this->userTerminatePanel = (gcnew System::Windows::Forms::Panel());
				 this->userTerminateButton2 = (gcnew System::Windows::Forms::Button());
				 this->userPasswordPanel = (gcnew System::Windows::Forms::Panel());
				 this->userChangePassButton2 = (gcnew System::Windows::Forms::Button());
				 this->userTextBox3 = (gcnew System::Windows::Forms::TextBox());
				 this->userTextBox2 = (gcnew System::Windows::Forms::TextBox());
				 this->userTextBox1 = (gcnew System::Windows::Forms::TextBox());
				 this->leaderboardPanel = (gcnew System::Windows::Forms::Panel());
				 this->leaderboardListPanel = (gcnew System::Windows::Forms::Panel());
				 this->leaderboardsPlaceLabel1 = (gcnew System::Windows::Forms::Label());
				 this->leaderboardListPointsLabel = (gcnew System::Windows::Forms::Label());
				 this->leaderboardListNameLabel = (gcnew System::Windows::Forms::Label());
				 this->leaderboardListPlaceLabel = (gcnew System::Windows::Forms::Label());
				 this->leaderboardSearchTextbox = (gcnew System::Windows::Forms::TextBox());
				 this->leaderboardLabel1 = (gcnew System::Windows::Forms::Label());
				 this->leaderboardBackButton = (gcnew System::Windows::Forms::Button());
				 this->leaderboardNameLabel1 = (gcnew System::Windows::Forms::Label());
				 this->leaderboardPointsLabel1 = (gcnew System::Windows::Forms::Label());
				 this->leaderboardsPlaceLabel2 = (gcnew System::Windows::Forms::Label());
				 this->leaderboardsPlaceLabel3 = (gcnew System::Windows::Forms::Label());
				 this->leaderboardsPlaceLabel4 = (gcnew System::Windows::Forms::Label());
				 this->leaderboardsPlaceLabel5 = (gcnew System::Windows::Forms::Label());
				 this->leaderboardsPlaceLabel6 = (gcnew System::Windows::Forms::Label());
				 this->leaderboardYourPlaceLabel = (gcnew System::Windows::Forms::Label());
				 this->leaderboardYourPointsLabel = (gcnew System::Windows::Forms::Label());
				 this->leaderboardYourNameLabel = (gcnew System::Windows::Forms::Label());
				 this->leaderboardNameLabel2 = (gcnew System::Windows::Forms::Label());
				 this->leaderboardNameLabel3 = (gcnew System::Windows::Forms::Label());
				 this->leaderboardNameLabel4 = (gcnew System::Windows::Forms::Label());
				 this->leaderboardNameLabel5 = (gcnew System::Windows::Forms::Label());
				 this->leaderboardNameLabel6 = (gcnew System::Windows::Forms::Label());
				 this->leaderboardPointsLabel2 = (gcnew System::Windows::Forms::Label());
				 this->leaderboardPointsLabel3 = (gcnew System::Windows::Forms::Label());
				 this->leaderboardPointsLabel4 = (gcnew System::Windows::Forms::Label());
				 this->leaderboardPointsLabel5 = (gcnew System::Windows::Forms::Label());
				 this->leaderboardPointsLabel6 = (gcnew System::Windows::Forms::Label());
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
				 this->menuPanel->SuspendLayout();
				 this->gamesPanel->SuspendLayout();
				 this->userPanel->SuspendLayout();
				 this->userTerminatePanel->SuspendLayout();
				 this->userPasswordPanel->SuspendLayout();
				 this->leaderboardPanel->SuspendLayout();
				 this->leaderboardListPanel->SuspendLayout();
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
				 this->leaderboardButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				 this->leaderboardButton->Font = (gcnew System::Drawing::Font(L"Rockwell", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->leaderboardButton->Location = System::Drawing::Point(67, 411);
				 this->leaderboardButton->Name = L"leaderboardButton";
				 this->leaderboardButton->Size = System::Drawing::Size(291, 58);
				 this->leaderboardButton->TabIndex = 3;
				 this->leaderboardButton->Text = L"LEADERBOARD";
				 this->leaderboardButton->UseVisualStyleBackColor = false;
				 this->leaderboardButton->Click += gcnew System::EventHandler(this, &PgrMenu::leaderboardButton_Click);
				 // 
				 // userButton
				 // 
				 this->userButton->BackColor = System::Drawing::Color::Transparent;
				 this->userButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"userButton.BackgroundImage")));
				 this->userButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				 this->userButton->Font = (gcnew System::Drawing::Font(L"Rockwell", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->userButton->Location = System::Drawing::Point(67, 511);
				 this->userButton->Name = L"userButton";
				 this->userButton->Size = System::Drawing::Size(291, 58);
				 this->userButton->TabIndex = 4;
				 this->userButton->Text = L"USER";
				 this->userButton->UseVisualStyleBackColor = false;
				 this->userButton->Click += gcnew System::EventHandler(this, &PgrMenu::userButton_Click);
				 // 
				 // friendsButton
				 // 
				 this->friendsButton->BackColor = System::Drawing::Color::Transparent;
				 this->friendsButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"friendsButton.BackgroundImage")));
				 this->friendsButton->Enabled = false;
				 this->friendsButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				 this->friendsButton->Font = (gcnew System::Drawing::Font(L"Rockwell", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->friendsButton->Location = System::Drawing::Point(67, 608);
				 this->friendsButton->Name = L"friendsButton";
				 this->friendsButton->Size = System::Drawing::Size(291, 58);
				 this->friendsButton->TabIndex = 5;
				 this->friendsButton->Text = L"FRIENDS (\?)";
				 this->friendsButton->UseVisualStyleBackColor = false;
				 // 
				 // menuPanel
				 // 
				 this->menuPanel->BackColor = System::Drawing::Color::Transparent;
				 this->menuPanel->Controls->Add(this->pictureBox2);
				 this->menuPanel->Controls->Add(this->userButton);
				 this->menuPanel->Controls->Add(this->friendsButton);
				 this->menuPanel->Controls->Add(this->leaderboardButton);
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
				 // userPanel
				 // 
				 this->userPanel->BackColor = System::Drawing::Color::Transparent;
				 this->userPanel->Controls->Add(this->userChangePassButton);
				 this->userPanel->Controls->Add(this->userTerminateAccButton);
				 this->userPanel->Controls->Add(this->userPointsLabel);
				 this->userPanel->Controls->Add(this->userLabel3);
				 this->userPanel->Controls->Add(this->userEmailLabel);
				 this->userPanel->Controls->Add(this->userLabel2);
				 this->userPanel->Controls->Add(this->userLabel1);
				 this->userPanel->Controls->Add(this->userNameLabel);
				 this->userPanel->Controls->Add(this->userBackButton);
				 this->userPanel->Controls->Add(this->userBGPanel);
				 this->userPanel->Controls->Add(this->userTerminatePanel);
				 this->userPanel->Controls->Add(this->userPasswordPanel);
				 this->userPanel->Location = System::Drawing::Point(12, 12);
				 this->userPanel->Name = L"userPanel";
				 this->userPanel->Size = System::Drawing::Size(439, 726);
				 this->userPanel->TabIndex = 6;
				 // 
				 // userChangePassButton
				 // 
				 this->userChangePassButton->BackColor = System::Drawing::Color::Transparent;
				 this->userChangePassButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"userChangePassButton.BackgroundImage")));
				 this->userChangePassButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				 this->userChangePassButton->Font = (gcnew System::Drawing::Font(L"Rockwell", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->userChangePassButton->Location = System::Drawing::Point(18, 454);
				 this->userChangePassButton->Name = L"userChangePassButton";
				 this->userChangePassButton->Size = System::Drawing::Size(199, 37);
				 this->userChangePassButton->TabIndex = 5;
				 this->userChangePassButton->Text = L"Change Password";
				 this->userChangePassButton->UseVisualStyleBackColor = false;
				 this->userChangePassButton->Click += gcnew System::EventHandler(this, &PgrMenu::userChangePassButton_Click);
				 // 
				 // userTerminateAccButton
				 // 
				 this->userTerminateAccButton->BackColor = System::Drawing::Color::Transparent;
				 this->userTerminateAccButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"userTerminateAccButton.BackgroundImage")));
				 this->userTerminateAccButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				 this->userTerminateAccButton->Font = (gcnew System::Drawing::Font(L"Rockwell", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->userTerminateAccButton->Location = System::Drawing::Point(18, 538);
				 this->userTerminateAccButton->Name = L"userTerminateAccButton";
				 this->userTerminateAccButton->Size = System::Drawing::Size(199, 35);
				 this->userTerminateAccButton->TabIndex = 6;
				 this->userTerminateAccButton->Text = L"Terminate Account";
				 this->userTerminateAccButton->UseVisualStyleBackColor = false;
				 this->userTerminateAccButton->Click += gcnew System::EventHandler(this, &PgrMenu::userTerminateAccButton_Click);
				 // 
				 // userPointsLabel
				 // 
				 this->userPointsLabel->AutoSize = true;
				 this->userPointsLabel->Font = (gcnew System::Drawing::Font(L"Rockwell", 22));
				 this->userPointsLabel->Location = System::Drawing::Point(271, 271);
				 this->userPointsLabel->MaximumSize = System::Drawing::Size(140, 40);
				 this->userPointsLabel->Name = L"userPointsLabel";
				 this->userPointsLabel->Size = System::Drawing::Size(122, 35);
				 this->userPointsLabel->TabIndex = 15;
				 this->userPointsLabel->Text = L"[points]";
				 // 
				 // userLabel3
				 // 
				 this->userLabel3->AutoSize = true;
				 this->userLabel3->Font = (gcnew System::Drawing::Font(L"Rockwell", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->userLabel3->Location = System::Drawing::Point(271, 232);
				 this->userLabel3->Name = L"userLabel3";
				 this->userLabel3->Size = System::Drawing::Size(125, 39);
				 this->userLabel3->TabIndex = 14;
				 this->userLabel3->Text = L"Points:";
				 // 
				 // userEmailLabel
				 // 
				 this->userEmailLabel->AutoSize = true;
				 this->userEmailLabel->Font = (gcnew System::Drawing::Font(L"Rockwell", 18));
				 this->userEmailLabel->Location = System::Drawing::Point(14, 166);
				 this->userEmailLabel->MaximumSize = System::Drawing::Size(412, 36);
				 this->userEmailLabel->Name = L"userEmailLabel";
				 this->userEmailLabel->Size = System::Drawing::Size(92, 27);
				 this->userEmailLabel->TabIndex = 13;
				 this->userEmailLabel->Text = L"[email]";
				 // 
				 // userLabel2
				 // 
				 this->userLabel2->AutoSize = true;
				 this->userLabel2->Font = (gcnew System::Drawing::Font(L"Rockwell", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->userLabel2->Location = System::Drawing::Point(14, 130);
				 this->userLabel2->Name = L"userLabel2";
				 this->userLabel2->Size = System::Drawing::Size(134, 39);
				 this->userLabel2->TabIndex = 12;
				 this->userLabel2->Text = L"E-Mail:";
				 // 
				 // userLabel1
				 // 
				 this->userLabel1->AutoSize = true;
				 this->userLabel1->Font = (gcnew System::Drawing::Font(L"Rockwell", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->userLabel1->Location = System::Drawing::Point(14, 21);
				 this->userLabel1->Name = L"userLabel1";
				 this->userLabel1->Size = System::Drawing::Size(187, 39);
				 this->userLabel1->TabIndex = 11;
				 this->userLabel1->Text = L"Username:";
				 // 
				 // userNameLabel
				 // 
				 this->userNameLabel->AutoSize = true;
				 this->userNameLabel->Font = (gcnew System::Drawing::Font(L"Rockwell", 22));
				 this->userNameLabel->Location = System::Drawing::Point(14, 61);
				 this->userNameLabel->MaximumSize = System::Drawing::Size(412, 36);
				 this->userNameLabel->Name = L"userNameLabel";
				 this->userNameLabel->Size = System::Drawing::Size(113, 35);
				 this->userNameLabel->TabIndex = 10;
				 this->userNameLabel->Text = L"[name]";
				 // 
				 // userBackButton
				 // 
				 this->userBackButton->BackColor = System::Drawing::Color::Transparent;
				 this->userBackButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"userBackButton.BackgroundImage")));
				 this->userBackButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				 this->userBackButton->Font = (gcnew System::Drawing::Font(L"Rockwell", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->userBackButton->Location = System::Drawing::Point(78, 596);
				 this->userBackButton->Name = L"userBackButton";
				 this->userBackButton->Size = System::Drawing::Size(291, 58);
				 this->userBackButton->TabIndex = 7;
				 this->userBackButton->Text = L"BACK";
				 this->userBackButton->UseVisualStyleBackColor = false;
				 this->userBackButton->Click += gcnew System::EventHandler(this, &PgrMenu::userBackButton_Click);
				 // 
				 // userBGPanel
				 // 
				 this->userBGPanel->Location = System::Drawing::Point(0, 455);
				 this->userBGPanel->Name = L"userBGPanel";
				 this->userBGPanel->Size = System::Drawing::Size(218, 119);
				 this->userBGPanel->TabIndex = 19;
				 // 
				 // userTerminatePanel
				 // 
				 this->userTerminatePanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"userTerminatePanel.BackgroundImage")));
				 this->userTerminatePanel->Controls->Add(this->userTerminateButton2);
				 this->userTerminatePanel->Location = System::Drawing::Point(224, 455);
				 this->userTerminatePanel->Name = L"userTerminatePanel";
				 this->userTerminatePanel->Size = System::Drawing::Size(205, 119);
				 this->userTerminatePanel->TabIndex = 19;
				 this->userTerminatePanel->Visible = false;
				 // 
				 // userTerminateButton2
				 // 
				 this->userTerminateButton2->BackColor = System::Drawing::Color::Transparent;
				 this->userTerminateButton2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"userTerminateButton2.BackgroundImage")));
				 this->userTerminateButton2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				 this->userTerminateButton2->Font = (gcnew System::Drawing::Font(L"Rockwell", 18));
				 this->userTerminateButton2->ForeColor = System::Drawing::Color::Firebrick;
				 this->userTerminateButton2->Location = System::Drawing::Point(16, 37);
				 this->userTerminateButton2->Name = L"userTerminateButton2";
				 this->userTerminateButton2->Size = System::Drawing::Size(172, 49);
				 this->userTerminateButton2->TabIndex = 3;
				 this->userTerminateButton2->Text = L"TERMINATE";
				 this->userTerminateButton2->UseVisualStyleBackColor = false;
				 this->userTerminateButton2->Click += gcnew System::EventHandler(this, &PgrMenu::userTerminateButton2_Click);
				 // 
				 // userPasswordPanel
				 // 
				 this->userPasswordPanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"userPasswordPanel.BackgroundImage")));
				 this->userPasswordPanel->Controls->Add(this->userChangePassButton2);
				 this->userPasswordPanel->Controls->Add(this->userTextBox3);
				 this->userPasswordPanel->Controls->Add(this->userTextBox2);
				 this->userPasswordPanel->Controls->Add(this->userTextBox1);
				 this->userPasswordPanel->Location = System::Drawing::Point(224, 455);
				 this->userPasswordPanel->Name = L"userPasswordPanel";
				 this->userPasswordPanel->Size = System::Drawing::Size(205, 119);
				 this->userPasswordPanel->TabIndex = 18;
				 this->userPasswordPanel->Visible = false;
				 // 
				 // userChangePassButton2
				 // 
				 this->userChangePassButton2->BackColor = System::Drawing::Color::Transparent;
				 this->userChangePassButton2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"userChangePassButton2.BackgroundImage")));
				 this->userChangePassButton2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				 this->userChangePassButton2->Font = (gcnew System::Drawing::Font(L"Rockwell", 9));
				 this->userChangePassButton2->Location = System::Drawing::Point(15, 88);
				 this->userChangePassButton2->Name = L"userChangePassButton2";
				 this->userChangePassButton2->Size = System::Drawing::Size(172, 22);
				 this->userChangePassButton2->TabIndex = 3;
				 this->userChangePassButton2->Text = L"Change password";
				 this->userChangePassButton2->UseVisualStyleBackColor = false;
				 this->userChangePassButton2->Click += gcnew System::EventHandler(this, &PgrMenu::userChangePassButton2_Click);
				 // 
				 // userTextBox3
				 // 
				 this->userTextBox3->BackColor = System::Drawing::SystemColors::Menu;
				 this->userTextBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->userTextBox3->ForeColor = System::Drawing::Color::DarkGray;
				 this->userTextBox3->Location = System::Drawing::Point(15, 62);
				 this->userTextBox3->Name = L"userTextBox3";
				 this->userTextBox3->Size = System::Drawing::Size(172, 20);
				 this->userTextBox3->TabIndex = 2;
				 this->userTextBox3->Text = L"New password";
				 this->userTextBox3->Enter += gcnew System::EventHandler(this, &PgrMenu::userTextBox3_Enter);
				 // 
				 // userTextBox2
				 // 
				 this->userTextBox2->BackColor = System::Drawing::SystemColors::Menu;
				 this->userTextBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->userTextBox2->ForeColor = System::Drawing::Color::DarkGray;
				 this->userTextBox2->Location = System::Drawing::Point(15, 36);
				 this->userTextBox2->Name = L"userTextBox2";
				 this->userTextBox2->Size = System::Drawing::Size(172, 20);
				 this->userTextBox2->TabIndex = 1;
				 this->userTextBox2->Text = L"Confirm password";
				 this->userTextBox2->Enter += gcnew System::EventHandler(this, &PgrMenu::userTextBox2_Enter);
				 // 
				 // userTextBox1
				 // 
				 this->userTextBox1->BackColor = System::Drawing::SystemColors::Menu;
				 this->userTextBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->userTextBox1->ForeColor = System::Drawing::Color::DarkGray;
				 this->userTextBox1->Location = System::Drawing::Point(15, 10);
				 this->userTextBox1->Name = L"userTextBox1";
				 this->userTextBox1->Size = System::Drawing::Size(172, 20);
				 this->userTextBox1->TabIndex = 0;
				 this->userTextBox1->Text = L"Enter current password";
				 this->userTextBox1->Enter += gcnew System::EventHandler(this, &PgrMenu::userTextBox1_Enter);
				 // 
				 // leaderboardPanel
				 // 
				 this->leaderboardPanel->BackColor = System::Drawing::Color::Transparent;
				 this->leaderboardPanel->Controls->Add(this->leaderboardListPanel);
				 this->leaderboardPanel->Controls->Add(this->leaderboardSearchTextbox);
				 this->leaderboardPanel->Controls->Add(this->leaderboardLabel1);
				 this->leaderboardPanel->Controls->Add(this->leaderboardBackButton);
				 this->leaderboardPanel->Location = System::Drawing::Point(12, 15);
				 this->leaderboardPanel->Name = L"leaderboardPanel";
				 this->leaderboardPanel->Size = System::Drawing::Size(439, 723);
				 this->leaderboardPanel->TabIndex = 9;
				 // 
				 // leaderboardListPanel
				 // 
				 this->leaderboardListPanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"leaderboardListPanel.BackgroundImage")));
				 this->leaderboardListPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				 this->leaderboardListPanel->Controls->Add(this->leaderboardPointsLabel6);
				 this->leaderboardListPanel->Controls->Add(this->leaderboardPointsLabel5);
				 this->leaderboardListPanel->Controls->Add(this->leaderboardPointsLabel4);
				 this->leaderboardListPanel->Controls->Add(this->leaderboardPointsLabel3);
				 this->leaderboardListPanel->Controls->Add(this->leaderboardPointsLabel2);
				 this->leaderboardListPanel->Controls->Add(this->leaderboardNameLabel6);
				 this->leaderboardListPanel->Controls->Add(this->leaderboardNameLabel5);
				 this->leaderboardListPanel->Controls->Add(this->leaderboardNameLabel4);
				 this->leaderboardListPanel->Controls->Add(this->leaderboardNameLabel3);
				 this->leaderboardListPanel->Controls->Add(this->leaderboardNameLabel2);
				 this->leaderboardListPanel->Controls->Add(this->leaderboardYourNameLabel);
				 this->leaderboardListPanel->Controls->Add(this->leaderboardYourPointsLabel);
				 this->leaderboardListPanel->Controls->Add(this->leaderboardYourPlaceLabel);
				 this->leaderboardListPanel->Controls->Add(this->leaderboardsPlaceLabel6);
				 this->leaderboardListPanel->Controls->Add(this->leaderboardsPlaceLabel5);
				 this->leaderboardListPanel->Controls->Add(this->leaderboardsPlaceLabel4);
				 this->leaderboardListPanel->Controls->Add(this->leaderboardsPlaceLabel3);
				 this->leaderboardListPanel->Controls->Add(this->leaderboardsPlaceLabel2);
				 this->leaderboardListPanel->Controls->Add(this->leaderboardPointsLabel1);
				 this->leaderboardListPanel->Controls->Add(this->leaderboardNameLabel1);
				 this->leaderboardListPanel->Controls->Add(this->leaderboardsPlaceLabel1);
				 this->leaderboardListPanel->Controls->Add(this->leaderboardListPointsLabel);
				 this->leaderboardListPanel->Controls->Add(this->leaderboardListNameLabel);
				 this->leaderboardListPanel->Controls->Add(this->leaderboardListPlaceLabel);
				 this->leaderboardListPanel->Location = System::Drawing::Point(49, 163);
				 this->leaderboardListPanel->Name = L"leaderboardListPanel";
				 this->leaderboardListPanel->Size = System::Drawing::Size(347, 408);
				 this->leaderboardListPanel->TabIndex = 17;
				 // 
				 // leaderboardsPlaceLabel1
				 // 
				 this->leaderboardsPlaceLabel1->AutoSize = true;
				 this->leaderboardsPlaceLabel1->Font = (gcnew System::Drawing::Font(L"Rockwell", 17, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->leaderboardsPlaceLabel1->Location = System::Drawing::Point(7, 52);
				 this->leaderboardsPlaceLabel1->Name = L"leaderboardsPlaceLabel1";
				 this->leaderboardsPlaceLabel1->Size = System::Drawing::Size(55, 26);
				 this->leaderboardsPlaceLabel1->TabIndex = 21;
				 this->leaderboardsPlaceLabel1->Text = L"999.";
				 // 
				 // leaderboardListPointsLabel
				 // 
				 this->leaderboardListPointsLabel->AutoSize = true;
				 this->leaderboardListPointsLabel->Font = (gcnew System::Drawing::Font(L"Rockwell", 17, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->leaderboardListPointsLabel->ForeColor = System::Drawing::Color::DodgerBlue;
				 this->leaderboardListPointsLabel->Location = System::Drawing::Point(252, 15);
				 this->leaderboardListPointsLabel->Name = L"leaderboardListPointsLabel";
				 this->leaderboardListPointsLabel->Size = System::Drawing::Size(82, 28);
				 this->leaderboardListPointsLabel->TabIndex = 20;
				 this->leaderboardListPointsLabel->Text = L"Points";
				 // 
				 // leaderboardListNameLabel
				 // 
				 this->leaderboardListNameLabel->AutoSize = true;
				 this->leaderboardListNameLabel->Font = (gcnew System::Drawing::Font(L"Rockwell", 17, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->leaderboardListNameLabel->Location = System::Drawing::Point(62, 15);
				 this->leaderboardListNameLabel->Name = L"leaderboardListNameLabel";
				 this->leaderboardListNameLabel->Size = System::Drawing::Size(79, 28);
				 this->leaderboardListNameLabel->TabIndex = 19;
				 this->leaderboardListNameLabel->Text = L"Name";
				 // 
				 // leaderboardListPlaceLabel
				 // 
				 this->leaderboardListPlaceLabel->AutoSize = true;
				 this->leaderboardListPlaceLabel->Font = (gcnew System::Drawing::Font(L"Rockwell", 17, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->leaderboardListPlaceLabel->Location = System::Drawing::Point(13, 15);
				 this->leaderboardListPlaceLabel->Name = L"leaderboardListPlaceLabel";
				 this->leaderboardListPlaceLabel->Size = System::Drawing::Size(27, 28);
				 this->leaderboardListPlaceLabel->TabIndex = 18;
				 this->leaderboardListPlaceLabel->Text = L"#";
				 // 
				 // leaderboardSearchTextbox
				 // 
				 this->leaderboardSearchTextbox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular,
					 System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
				 this->leaderboardSearchTextbox->Location = System::Drawing::Point(78, 80);
				 this->leaderboardSearchTextbox->Name = L"leaderboardSearchTextbox";
				 this->leaderboardSearchTextbox->Size = System::Drawing::Size(291, 32);
				 this->leaderboardSearchTextbox->TabIndex = 16;
				 // 
				 // leaderboardLabel1
				 // 
				 this->leaderboardLabel1->AutoSize = true;
				 this->leaderboardLabel1->Font = (gcnew System::Drawing::Font(L"Rockwell", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->leaderboardLabel1->Location = System::Drawing::Point(121, 38);
				 this->leaderboardLabel1->Name = L"leaderboardLabel1";
				 this->leaderboardLabel1->Size = System::Drawing::Size(199, 39);
				 this->leaderboardLabel1->TabIndex = 15;
				 this->leaderboardLabel1->Text = L"Search user";
				 // 
				 // leaderboardBackButton
				 // 
				 this->leaderboardBackButton->BackColor = System::Drawing::Color::Transparent;
				 this->leaderboardBackButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"leaderboardBackButton.BackgroundImage")));
				 this->leaderboardBackButton->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				 this->leaderboardBackButton->Font = (gcnew System::Drawing::Font(L"Rockwell", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->leaderboardBackButton->Location = System::Drawing::Point(78, 603);
				 this->leaderboardBackButton->Name = L"leaderboardBackButton";
				 this->leaderboardBackButton->Size = System::Drawing::Size(291, 58);
				 this->leaderboardBackButton->TabIndex = 9;
				 this->leaderboardBackButton->Text = L"BACK";
				 this->leaderboardBackButton->UseVisualStyleBackColor = false;
				 this->leaderboardBackButton->Click += gcnew System::EventHandler(this, &PgrMenu::leaderboardBackButton_Click);
				 // 
				 // leaderboardNameLabel1
				 // 
				 this->leaderboardNameLabel1->AutoSize = true;
				 this->leaderboardNameLabel1->Font = (gcnew System::Drawing::Font(L"Rockwell", 17, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->leaderboardNameLabel1->Location = System::Drawing::Point(62, 52);
				 this->leaderboardNameLabel1->MaximumSize = System::Drawing::Size(205, 28);
				 this->leaderboardNameLabel1->Name = L"leaderboardNameLabel1";
				 this->leaderboardNameLabel1->Size = System::Drawing::Size(196, 28);
				 this->leaderboardNameLabel1->TabIndex = 22;
				 this->leaderboardNameLabel1->Text = L"testName69420154";
				 // 
				 // leaderboardPointsLabel1
				 // 
				 this->leaderboardPointsLabel1->AutoSize = true;
				 this->leaderboardPointsLabel1->Font = (gcnew System::Drawing::Font(L"Rockwell", 17, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->leaderboardPointsLabel1->ForeColor = System::Drawing::Color::DodgerBlue;
				 this->leaderboardPointsLabel1->Location = System::Drawing::Point(252, 52);
				 this->leaderboardPointsLabel1->MaximumSize = System::Drawing::Size(84, 26);
				 this->leaderboardPointsLabel1->Name = L"leaderboardPointsLabel1";
				 this->leaderboardPointsLabel1->Size = System::Drawing::Size(84, 26);
				 this->leaderboardPointsLabel1->TabIndex = 23;
				 this->leaderboardPointsLabel1->Text = L"226671";
				 // 
				 // leaderboardsPlaceLabel2
				 // 
				 this->leaderboardsPlaceLabel2->AutoSize = true;
				 this->leaderboardsPlaceLabel2->Font = (gcnew System::Drawing::Font(L"Rockwell", 17, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->leaderboardsPlaceLabel2->Location = System::Drawing::Point(7, 97);
				 this->leaderboardsPlaceLabel2->Name = L"leaderboardsPlaceLabel2";
				 this->leaderboardsPlaceLabel2->Size = System::Drawing::Size(31, 26);
				 this->leaderboardsPlaceLabel2->TabIndex = 24;
				 this->leaderboardsPlaceLabel2->Text = L"1.";
				 // 
				 // leaderboardsPlaceLabel3
				 // 
				 this->leaderboardsPlaceLabel3->AutoSize = true;
				 this->leaderboardsPlaceLabel3->Font = (gcnew System::Drawing::Font(L"Rockwell", 17, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->leaderboardsPlaceLabel3->Location = System::Drawing::Point(7, 147);
				 this->leaderboardsPlaceLabel3->Name = L"leaderboardsPlaceLabel3";
				 this->leaderboardsPlaceLabel3->Size = System::Drawing::Size(31, 26);
				 this->leaderboardsPlaceLabel3->TabIndex = 25;
				 this->leaderboardsPlaceLabel3->Text = L"1.";
				 // 
				 // leaderboardsPlaceLabel4
				 // 
				 this->leaderboardsPlaceLabel4->AutoSize = true;
				 this->leaderboardsPlaceLabel4->Font = (gcnew System::Drawing::Font(L"Rockwell", 17, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->leaderboardsPlaceLabel4->Location = System::Drawing::Point(7, 197);
				 this->leaderboardsPlaceLabel4->Name = L"leaderboardsPlaceLabel4";
				 this->leaderboardsPlaceLabel4->Size = System::Drawing::Size(31, 26);
				 this->leaderboardsPlaceLabel4->TabIndex = 26;
				 this->leaderboardsPlaceLabel4->Text = L"1.";
				 // 
				 // leaderboardsPlaceLabel5
				 // 
				 this->leaderboardsPlaceLabel5->AutoSize = true;
				 this->leaderboardsPlaceLabel5->Font = (gcnew System::Drawing::Font(L"Rockwell", 17, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->leaderboardsPlaceLabel5->Location = System::Drawing::Point(7, 246);
				 this->leaderboardsPlaceLabel5->Name = L"leaderboardsPlaceLabel5";
				 this->leaderboardsPlaceLabel5->Size = System::Drawing::Size(31, 26);
				 this->leaderboardsPlaceLabel5->TabIndex = 27;
				 this->leaderboardsPlaceLabel5->Text = L"1.";
				 // 
				 // leaderboardsPlaceLabel6
				 // 
				 this->leaderboardsPlaceLabel6->AutoSize = true;
				 this->leaderboardsPlaceLabel6->Font = (gcnew System::Drawing::Font(L"Rockwell", 17, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->leaderboardsPlaceLabel6->Location = System::Drawing::Point(7, 298);
				 this->leaderboardsPlaceLabel6->Name = L"leaderboardsPlaceLabel6";
				 this->leaderboardsPlaceLabel6->Size = System::Drawing::Size(31, 26);
				 this->leaderboardsPlaceLabel6->TabIndex = 28;
				 this->leaderboardsPlaceLabel6->Text = L"1.";
				 // 
				 // leaderboardYourPlaceLabel
				 // 
				 this->leaderboardYourPlaceLabel->AutoSize = true;
				 this->leaderboardYourPlaceLabel->Font = (gcnew System::Drawing::Font(L"Rockwell", 17, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->leaderboardYourPlaceLabel->ForeColor = System::Drawing::SystemColors::HighlightText;
				 this->leaderboardYourPlaceLabel->Location = System::Drawing::Point(7, 365);
				 this->leaderboardYourPlaceLabel->Name = L"leaderboardYourPlaceLabel";
				 this->leaderboardYourPlaceLabel->Size = System::Drawing::Size(31, 26);
				 this->leaderboardYourPlaceLabel->TabIndex = 29;
				 this->leaderboardYourPlaceLabel->Text = L"1.";
				 // 
				 // leaderboardYourPointsLabel
				 // 
				 this->leaderboardYourPointsLabel->AutoSize = true;
				 this->leaderboardYourPointsLabel->Font = (gcnew System::Drawing::Font(L"Rockwell", 17, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->leaderboardYourPointsLabel->ForeColor = System::Drawing::Color::MidnightBlue;
				 this->leaderboardYourPointsLabel->Location = System::Drawing::Point(252, 365);
				 this->leaderboardYourPointsLabel->MaximumSize = System::Drawing::Size(84, 26);
				 this->leaderboardYourPointsLabel->Name = L"leaderboardYourPointsLabel";
				 this->leaderboardYourPointsLabel->Size = System::Drawing::Size(84, 26);
				 this->leaderboardYourPointsLabel->TabIndex = 30;
				 this->leaderboardYourPointsLabel->Text = L"226671";
				 // 
				 // leaderboardYourNameLabel
				 // 
				 this->leaderboardYourNameLabel->AutoSize = true;
				 this->leaderboardYourNameLabel->Font = (gcnew System::Drawing::Font(L"Rockwell", 17, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->leaderboardYourNameLabel->ForeColor = System::Drawing::SystemColors::HighlightText;
				 this->leaderboardYourNameLabel->Location = System::Drawing::Point(44, 365);
				 this->leaderboardYourNameLabel->MaximumSize = System::Drawing::Size(211, 28);
				 this->leaderboardYourNameLabel->Name = L"leaderboardYourNameLabel";
				 this->leaderboardYourNameLabel->Size = System::Drawing::Size(172, 26);
				 this->leaderboardYourNameLabel->TabIndex = 31;
				 this->leaderboardYourNameLabel->Text = L"testName69420";
				 // 
				 // leaderboardNameLabel2
				 // 
				 this->leaderboardNameLabel2->AutoSize = true;
				 this->leaderboardNameLabel2->Font = (gcnew System::Drawing::Font(L"Rockwell", 17, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->leaderboardNameLabel2->Location = System::Drawing::Point(62, 97);
				 this->leaderboardNameLabel2->MaximumSize = System::Drawing::Size(205, 28);
				 this->leaderboardNameLabel2->Name = L"leaderboardNameLabel2";
				 this->leaderboardNameLabel2->Size = System::Drawing::Size(92, 26);
				 this->leaderboardNameLabel2->TabIndex = 32;
				 this->leaderboardNameLabel2->Text = L"[Name]";
				 // 
				 // leaderboardNameLabel3
				 // 
				 this->leaderboardNameLabel3->AutoSize = true;
				 this->leaderboardNameLabel3->Font = (gcnew System::Drawing::Font(L"Rockwell", 17, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->leaderboardNameLabel3->Location = System::Drawing::Point(62, 147);
				 this->leaderboardNameLabel3->MaximumSize = System::Drawing::Size(205, 28);
				 this->leaderboardNameLabel3->Name = L"leaderboardNameLabel3";
				 this->leaderboardNameLabel3->Size = System::Drawing::Size(92, 26);
				 this->leaderboardNameLabel3->TabIndex = 33;
				 this->leaderboardNameLabel3->Text = L"[Name]";
				 // 
				 // leaderboardNameLabel4
				 // 
				 this->leaderboardNameLabel4->AutoSize = true;
				 this->leaderboardNameLabel4->Font = (gcnew System::Drawing::Font(L"Rockwell", 17, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->leaderboardNameLabel4->Location = System::Drawing::Point(62, 197);
				 this->leaderboardNameLabel4->MaximumSize = System::Drawing::Size(205, 28);
				 this->leaderboardNameLabel4->Name = L"leaderboardNameLabel4";
				 this->leaderboardNameLabel4->Size = System::Drawing::Size(92, 26);
				 this->leaderboardNameLabel4->TabIndex = 34;
				 this->leaderboardNameLabel4->Text = L"[Name]";
				 // 
				 // leaderboardNameLabel5
				 // 
				 this->leaderboardNameLabel5->AutoSize = true;
				 this->leaderboardNameLabel5->Font = (gcnew System::Drawing::Font(L"Rockwell", 17, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->leaderboardNameLabel5->Location = System::Drawing::Point(62, 246);
				 this->leaderboardNameLabel5->MaximumSize = System::Drawing::Size(205, 28);
				 this->leaderboardNameLabel5->Name = L"leaderboardNameLabel5";
				 this->leaderboardNameLabel5->Size = System::Drawing::Size(92, 26);
				 this->leaderboardNameLabel5->TabIndex = 35;
				 this->leaderboardNameLabel5->Text = L"[Name]";
				 // 
				 // leaderboardNameLabel6
				 // 
				 this->leaderboardNameLabel6->AutoSize = true;
				 this->leaderboardNameLabel6->Font = (gcnew System::Drawing::Font(L"Rockwell", 17, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->leaderboardNameLabel6->Location = System::Drawing::Point(62, 298);
				 this->leaderboardNameLabel6->MaximumSize = System::Drawing::Size(205, 28);
				 this->leaderboardNameLabel6->Name = L"leaderboardNameLabel6";
				 this->leaderboardNameLabel6->Size = System::Drawing::Size(92, 26);
				 this->leaderboardNameLabel6->TabIndex = 36;
				 this->leaderboardNameLabel6->Text = L"[Name]";
				 // 
				 // leaderboardPointsLabel2
				 // 
				 this->leaderboardPointsLabel2->AutoSize = true;
				 this->leaderboardPointsLabel2->Font = (gcnew System::Drawing::Font(L"Rockwell", 17, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->leaderboardPointsLabel2->ForeColor = System::Drawing::Color::DodgerBlue;
				 this->leaderboardPointsLabel2->Location = System::Drawing::Point(252, 97);
				 this->leaderboardPointsLabel2->MaximumSize = System::Drawing::Size(84, 26);
				 this->leaderboardPointsLabel2->Name = L"leaderboardPointsLabel2";
				 this->leaderboardPointsLabel2->Size = System::Drawing::Size(48, 26);
				 this->leaderboardPointsLabel2->TabIndex = 37;
				 this->leaderboardPointsLabel2->Text = L"123";
				 // 
				 // leaderboardPointsLabel3
				 // 
				 this->leaderboardPointsLabel3->AutoSize = true;
				 this->leaderboardPointsLabel3->Font = (gcnew System::Drawing::Font(L"Rockwell", 17, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->leaderboardPointsLabel3->ForeColor = System::Drawing::Color::DodgerBlue;
				 this->leaderboardPointsLabel3->Location = System::Drawing::Point(252, 147);
				 this->leaderboardPointsLabel3->MaximumSize = System::Drawing::Size(84, 26);
				 this->leaderboardPointsLabel3->Name = L"leaderboardPointsLabel3";
				 this->leaderboardPointsLabel3->Size = System::Drawing::Size(48, 26);
				 this->leaderboardPointsLabel3->TabIndex = 38;
				 this->leaderboardPointsLabel3->Text = L"123";
				 // 
				 // leaderboardPointsLabel4
				 // 
				 this->leaderboardPointsLabel4->AutoSize = true;
				 this->leaderboardPointsLabel4->Font = (gcnew System::Drawing::Font(L"Rockwell", 17, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->leaderboardPointsLabel4->ForeColor = System::Drawing::Color::DodgerBlue;
				 this->leaderboardPointsLabel4->Location = System::Drawing::Point(252, 197);
				 this->leaderboardPointsLabel4->MaximumSize = System::Drawing::Size(84, 26);
				 this->leaderboardPointsLabel4->Name = L"leaderboardPointsLabel4";
				 this->leaderboardPointsLabel4->Size = System::Drawing::Size(48, 26);
				 this->leaderboardPointsLabel4->TabIndex = 39;
				 this->leaderboardPointsLabel4->Text = L"123";
				 // 
				 // leaderboardPointsLabel5
				 // 
				 this->leaderboardPointsLabel5->AutoSize = true;
				 this->leaderboardPointsLabel5->Font = (gcnew System::Drawing::Font(L"Rockwell", 17, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->leaderboardPointsLabel5->ForeColor = System::Drawing::Color::DodgerBlue;
				 this->leaderboardPointsLabel5->Location = System::Drawing::Point(252, 246);
				 this->leaderboardPointsLabel5->MaximumSize = System::Drawing::Size(84, 26);
				 this->leaderboardPointsLabel5->Name = L"leaderboardPointsLabel5";
				 this->leaderboardPointsLabel5->Size = System::Drawing::Size(48, 26);
				 this->leaderboardPointsLabel5->TabIndex = 40;
				 this->leaderboardPointsLabel5->Text = L"123";
				 // 
				 // leaderboardPointsLabel6
				 // 
				 this->leaderboardPointsLabel6->AutoSize = true;
				 this->leaderboardPointsLabel6->Font = (gcnew System::Drawing::Font(L"Rockwell", 17, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->leaderboardPointsLabel6->ForeColor = System::Drawing::Color::DodgerBlue;
				 this->leaderboardPointsLabel6->Location = System::Drawing::Point(252, 298);
				 this->leaderboardPointsLabel6->MaximumSize = System::Drawing::Size(84, 26);
				 this->leaderboardPointsLabel6->Name = L"leaderboardPointsLabel6";
				 this->leaderboardPointsLabel6->Size = System::Drawing::Size(48, 26);
				 this->leaderboardPointsLabel6->TabIndex = 41;
				 this->leaderboardPointsLabel6->Text = L"123";
				 // 
				 // PgrMenu
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
				 this->ClientSize = System::Drawing::Size(463, 750);
				 this->Controls->Add(this->leaderboardPanel);
				 this->Controls->Add(this->menuPanel);
				 this->Controls->Add(this->gamesPanel);
				 this->Controls->Add(this->userPanel);
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
				 this->userPanel->ResumeLayout(false);
				 this->userPanel->PerformLayout();
				 this->userTerminatePanel->ResumeLayout(false);
				 this->userPasswordPanel->ResumeLayout(false);
				 this->userPasswordPanel->PerformLayout();
				 this->leaderboardPanel->ResumeLayout(false);
				 this->leaderboardPanel->PerformLayout();
				 this->leaderboardListPanel->ResumeLayout(false);
				 this->leaderboardListPanel->PerformLayout();
				 this->ResumeLayout(false);

			 }
#pragma endregion


};
}
