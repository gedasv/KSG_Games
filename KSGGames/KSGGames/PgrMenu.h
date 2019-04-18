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
			leaderboardLabelArray = gcnew array<System::Windows::Forms::Label^, 2>(3, 7);
			labelArrayInit(leaderboardLabelArray);
			
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

	private: array<System::Windows::Forms::Label^, 2>^ leaderboardLabelArray;
	private: array<String^, 1>^ leaderboardFoundNames;
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

	private: System::Windows::Forms::TextBox^  leaderboardSearchTextbox;
	private: System::Windows::Forms::Label^  leaderboardLabel1;
	private: System::Windows::Forms::Panel^  leaderboardListPanel;
	private: System::Windows::Forms::Label^  leaderboardListPointsLabel;
	private: System::Windows::Forms::Label^  leaderboardListNameLabel;
	private: System::Windows::Forms::Label^  leaderboardListPlaceLabel;
	private: System::Windows::Forms::Label^  leaderboardYourLabel3;

	private: System::Windows::Forms::Label^  leaderboardYourLabel2;

	private: System::Windows::Forms::Label^  leaderboardYourLabel1;
	private: System::Windows::Forms::Label^  leaderboardYouAreLabel;
	private: System::Windows::Forms::Button^  gamesVSPlayerButton;
	private: System::Windows::Forms::Button^  gamesVSBotButton;





	private: System::Windows::Forms::Button^  game1Button;


	private: System::Void PgrMenu_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		Application::Exit();
	}

	private: System::Void gamesButton_Click(System::Object^  sender, System::EventArgs^  e) {
		menuPanel->Hide();
		gamesPanel->Show();
		gamesVSBotButton->Visible = false;
		gamesVSPlayerButton->Visible = false;
	}
	private: System::Void gamesBackButton_Click(System::Object^  sender, System::EventArgs^  e) {
		gamesPanel->Hide();
		menuPanel->Show();

	}
	private: System::Void ChessGame(System::Object^  sender, System::EventArgs^  e) {
		gamesVSBotButton->Visible = true;
		gamesVSPlayerButton->Visible = true;

	}
	private: System::Void gamesVSBotButton_Click(System::Object^  sender, System::EventArgs^  e) {
		
		Chess ^ chessGame = gcnew Chess;
		chessGame->Show();
	}
	private: System::Void gamesVSPlayerButton_Click(System::Object^  sender, System::EventArgs^  e) {
		/*
		Chess ^ chessGame = gcnew Chess;
		chessGame->Show();
		*/
	}
	private: System::Void MinesweeperGame(System::Object^  sender, System::EventArgs^  e) {
		Minesweeper ^ minesweeperGame = gcnew Minesweeper;
		minesweeperGame->Show();
	}

	private: System::Void leaderboardButton_Click(System::Object^  sender, System::EventArgs^  e) {
		menuPanel->Hide();
		setLeaderboardInfo("");
		leaderboardPanel->Show();
	}
	private: System::Void leaderboardBackButton_Click(System::Object^  sender, System::EventArgs^  e) {
		menuPanel->Show();
		leaderboardPanel->Hide();
	}
	private: System::Void leaderboardSearchTextbox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		setLeaderboardInfo(leaderboardSearchTextbox->Text);
	}
	private: void labelArrayInit(array<System::Windows::Forms::Label^, 2>^ leaderboardLabelArray) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 7; j++) {
				System::Windows::Forms::Label^ leaderboardLabel = (gcnew System::Windows::Forms::Label());

				leaderboardLabel->AutoSize = true;
				leaderboardLabel->Parent = leaderboardListPanel;
				leaderboardLabel->Font = (gcnew System::Drawing::Font(L"Rockwell", 17));
				leaderboardLabel->Name = L"leaderboardPlaceLabel" + j;
				leaderboardLabel->Size = System::Drawing::Size(10, 26);
				leaderboardLabel->TabIndex = 69;

				switch (i) {

				case 0: leaderboardLabel->Text = "";
					leaderboardLabel->Location = System::Drawing::Point(7, 52 + j * 41);
					leaderboardLabel->MaximumSize = System::Drawing::Size(55, 26);
					break;
				case 1: leaderboardLabel->Text = "";
					leaderboardLabel->Location = System::Drawing::Point(62, 52 + j * 41);
					leaderboardLabel->MaximumSize = System::Drawing::Size(205, 28);
					break;
				case 2: leaderboardLabel->Text = "";
					leaderboardLabel->Location = System::Drawing::Point(252, 52 + j * 41);
					leaderboardLabel->MaximumSize = System::Drawing::Size(84, 26);
					leaderboardLabel->ForeColor = System::Drawing::Color::DodgerBlue;
					break;
				}

				leaderboardLabelArray[i, j] = leaderboardLabel;

			}
		}

	}
	private: void setLeaderboardInfo(String ^ enteredName) {
		try {
			MySqlConnection ^conn;
			MySqlDataReader ^dr;
			MySqlCommand ^cmd1, ^cmd2;
			int i = 0, i2 = 0, rowAmount = 0, userPlace = 0;
			leaderboardFoundNames = gcnew array<String^, 1>(7);
			String^ userUsername = gcnew String(user.GetName().c_str());
			for (int i = 0; i < 3; i++) 
				for (int j = 0; j < 7; j++) 
					leaderboardLabelArray[i, j]->Text = "";

			connectToSQL(conn);

			// while loop kad rasti kurioje vietoje yra user ir suskaiciuoti db diduma
			cmd1 = gcnew MySqlCommand("SELECT Username, Points FROM users ORDER BY Points DESC LIMIT 1000", conn);
			dr = cmd1->ExecuteReader();
			while (dr->Read()) {
				if (dr->GetString(0) == userUsername)
					userPlace = rowAmount + 1;
					
				rowAmount++;
			}
			dr->Close();
			leaderboardYourLabel1->Text = L"" + userPlace + ".";
			leaderboardYourLabel2->Text = userUsername;
			leaderboardYourLabel3->Text = L"" + user.points;
			leaderboardYouAreLabel->Text = L"You are #" + userPlace + " out of " + rowAmount + " users!";

			cmd1 = gcnew MySqlCommand("SELECT Username, Points FROM users WHERE Username LIKE '%"+enteredName+"%' ORDER BY Points DESC LIMIT 1000", conn);
			cmd2 = gcnew MySqlCommand("SELECT Username, Points FROM users ORDER BY Points DESC LIMIT 1000", conn);

			///
			dr = cmd1->ExecuteReader();
			i = 0;
			while (dr->Read()) {
				if(i < 7)
					leaderboardFoundNames[i] = dr->GetString(0);
				else break;
				i++;
			}
			dr->Close();
			///

			dr = cmd2->ExecuteReader();
			i = 0;
			while (dr->Read()) {
				i++;
				if (enteredName != "" && dr->GetString(0) == leaderboardFoundNames[i2] && i2 < 7) {
					leaderboardLabelArray[0, i2]->Text = L"" + i + ".";
					leaderboardLabelArray[1, i2]->Text = dr->GetString(0);
					leaderboardLabelArray[2, i2]->Text = dr->GetString(1);
					i2++;
				}
				else if (enteredName == "") {
					if (i < 8) {
						leaderboardLabelArray[0, i-1]->Text = L"" + i + ".";
						leaderboardLabelArray[1, i-1]->Text = dr->GetString(0);
						leaderboardLabelArray[2, i-1]->Text = dr->GetString(1);
					}
				}
			}
			dr->Close();
			conn->Close();
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message);
		}
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
				 this->gamesVSPlayerButton = (gcnew System::Windows::Forms::Button());
				 this->gamesVSBotButton = (gcnew System::Windows::Forms::Button());
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
				 this->leaderboardYouAreLabel = (gcnew System::Windows::Forms::Label());
				 this->leaderboardListPanel = (gcnew System::Windows::Forms::Panel());
				 this->leaderboardYourLabel3 = (gcnew System::Windows::Forms::Label());
				 this->leaderboardYourLabel2 = (gcnew System::Windows::Forms::Label());
				 this->leaderboardYourLabel1 = (gcnew System::Windows::Forms::Label());
				 this->leaderboardListPointsLabel = (gcnew System::Windows::Forms::Label());
				 this->leaderboardListNameLabel = (gcnew System::Windows::Forms::Label());
				 this->leaderboardListPlaceLabel = (gcnew System::Windows::Forms::Label());
				 this->leaderboardSearchTextbox = (gcnew System::Windows::Forms::TextBox());
				 this->leaderboardLabel1 = (gcnew System::Windows::Forms::Label());
				 this->leaderboardBackButton = (gcnew System::Windows::Forms::Button());
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
				 this->gamesPanel->Controls->Add(this->gamesVSPlayerButton);
				 this->gamesPanel->Controls->Add(this->gamesVSBotButton);
				 this->gamesPanel->Controls->Add(this->gamesBackButton);
				 this->gamesPanel->Controls->Add(this->game3Button);
				 this->gamesPanel->Controls->Add(this->game2Button);
				 this->gamesPanel->Controls->Add(this->game1Button);
				 this->gamesPanel->Location = System::Drawing::Point(23, 33);
				 this->gamesPanel->Name = L"gamesPanel";
				 this->gamesPanel->Size = System::Drawing::Size(428, 705);
				 this->gamesPanel->TabIndex = 8;
				 // 
				 // gamesVSPlayerButton
				 // 
				 this->gamesVSPlayerButton->BackColor = System::Drawing::Color::Transparent;
				 this->gamesVSPlayerButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"gamesVSPlayerButton.BackgroundImage")));
				 this->gamesVSPlayerButton->FlatStyle = System::Windows::Forms::FlatStyle::System;
				 this->gamesVSPlayerButton->Font = (gcnew System::Drawing::Font(L"Rockwell", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->gamesVSPlayerButton->Location = System::Drawing::Point(213, 101);
				 this->gamesVSPlayerButton->Name = L"gamesVSPlayerButton";
				 this->gamesVSPlayerButton->Size = System::Drawing::Size(145, 58);
				 this->gamesVSPlayerButton->TabIndex = 10;
				 this->gamesVSPlayerButton->Text = L"Local";
				 this->gamesVSPlayerButton->UseVisualStyleBackColor = false;
				 this->gamesVSPlayerButton->Visible = false;
				 this->gamesVSPlayerButton->Click += gcnew System::EventHandler(this, &PgrMenu::gamesVSPlayerButton_Click);
				 // 
				 // gamesVSBotButton
				 // 
				 this->gamesVSBotButton->BackColor = System::Drawing::Color::Transparent;
				 this->gamesVSBotButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"gamesVSBotButton.BackgroundImage")));
				 this->gamesVSBotButton->FlatStyle = System::Windows::Forms::FlatStyle::System;
				 this->gamesVSBotButton->Font = (gcnew System::Drawing::Font(L"Rockwell", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->gamesVSBotButton->Location = System::Drawing::Point(67, 101);
				 this->gamesVSBotButton->Name = L"gamesVSBotButton";
				 this->gamesVSBotButton->Size = System::Drawing::Size(148, 58);
				 this->gamesVSBotButton->TabIndex = 9;
				 this->gamesVSBotButton->Text = L"A.I.";
				 this->gamesVSBotButton->UseVisualStyleBackColor = false;
				 this->gamesVSBotButton->Visible = false;
				 this->gamesVSBotButton->Click += gcnew System::EventHandler(this, &PgrMenu::gamesVSBotButton_Click);
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
				 this->game3Button->Text = L"MONOPOLY";
				 this->game3Button->UseVisualStyleBackColor = false;
				 // 
				 // game2Button
				 // 
				 this->game2Button->BackColor = System::Drawing::Color::Transparent;
				 this->game2Button->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"game2Button.BackgroundImage")));
				 this->game2Button->Enabled = false;
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
				 this->leaderboardPanel->Controls->Add(this->leaderboardYouAreLabel);
				 this->leaderboardPanel->Controls->Add(this->leaderboardListPanel);
				 this->leaderboardPanel->Controls->Add(this->leaderboardSearchTextbox);
				 this->leaderboardPanel->Controls->Add(this->leaderboardLabel1);
				 this->leaderboardPanel->Controls->Add(this->leaderboardBackButton);
				 this->leaderboardPanel->Location = System::Drawing::Point(12, 15);
				 this->leaderboardPanel->Name = L"leaderboardPanel";
				 this->leaderboardPanel->Size = System::Drawing::Size(439, 723);
				 this->leaderboardPanel->TabIndex = 9;
				 // 
				 // leaderboardYouAreLabel
				 // 
				 this->leaderboardYouAreLabel->AutoSize = true;
				 this->leaderboardYouAreLabel->Font = (gcnew System::Drawing::Font(L"Rockwell", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->leaderboardYouAreLabel->Location = System::Drawing::Point(84, 127);
				 this->leaderboardYouAreLabel->Name = L"leaderboardYouAreLabel";
				 this->leaderboardYouAreLabel->Size = System::Drawing::Size(96, 27);
				 this->leaderboardYouAreLabel->TabIndex = 18;
				 this->leaderboardYouAreLabel->Text = L"You are";
				 // 
				 // leaderboardListPanel
				 // 
				 this->leaderboardListPanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"leaderboardListPanel.BackgroundImage")));
				 this->leaderboardListPanel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				 this->leaderboardListPanel->Controls->Add(this->leaderboardYourLabel3);
				 this->leaderboardListPanel->Controls->Add(this->leaderboardYourLabel2);
				 this->leaderboardListPanel->Controls->Add(this->leaderboardYourLabel1);
				 this->leaderboardListPanel->Controls->Add(this->leaderboardListPointsLabel);
				 this->leaderboardListPanel->Controls->Add(this->leaderboardListNameLabel);
				 this->leaderboardListPanel->Controls->Add(this->leaderboardListPlaceLabel);
				 this->leaderboardListPanel->Location = System::Drawing::Point(49, 163);
				 this->leaderboardListPanel->Name = L"leaderboardListPanel";
				 this->leaderboardListPanel->Size = System::Drawing::Size(347, 408);
				 this->leaderboardListPanel->TabIndex = 17;
				 // 
				 // leaderboardYourLabel3
				 // 
				 this->leaderboardYourLabel3->AutoSize = true;
				 this->leaderboardYourLabel3->Font = (gcnew System::Drawing::Font(L"Rockwell", 17, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->leaderboardYourLabel3->ForeColor = System::Drawing::Color::MidnightBlue;
				 this->leaderboardYourLabel3->Location = System::Drawing::Point(252, 365);
				 this->leaderboardYourLabel3->MaximumSize = System::Drawing::Size(84, 26);
				 this->leaderboardYourLabel3->Name = L"leaderboardYourLabel3";
				 this->leaderboardYourLabel3->Size = System::Drawing::Size(48, 26);
				 this->leaderboardYourLabel3->TabIndex = 23;
				 this->leaderboardYourLabel3->Text = L"420";
				 // 
				 // leaderboardYourLabel2
				 // 
				 this->leaderboardYourLabel2->AutoSize = true;
				 this->leaderboardYourLabel2->Font = (gcnew System::Drawing::Font(L"Rockwell", 17, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->leaderboardYourLabel2->ForeColor = System::Drawing::SystemColors::HighlightText;
				 this->leaderboardYourLabel2->Location = System::Drawing::Point(62, 365);
				 this->leaderboardYourLabel2->MaximumSize = System::Drawing::Size(205, 28);
				 this->leaderboardYourLabel2->Name = L"leaderboardYourLabel2";
				 this->leaderboardYourLabel2->Size = System::Drawing::Size(152, 26);
				 this->leaderboardYourLabel2->TabIndex = 22;
				 this->leaderboardYourLabel2->Text = L"SampleName";
				 // 
				 // leaderboardYourLabel1
				 // 
				 this->leaderboardYourLabel1->AutoSize = true;
				 this->leaderboardYourLabel1->Font = (gcnew System::Drawing::Font(L"Rockwell", 17, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->leaderboardYourLabel1->ForeColor = System::Drawing::SystemColors::HighlightText;
				 this->leaderboardYourLabel1->Location = System::Drawing::Point(7, 365);
				 this->leaderboardYourLabel1->MaximumSize = System::Drawing::Size(55, 26);
				 this->leaderboardYourLabel1->Name = L"leaderboardYourLabel1";
				 this->leaderboardYourLabel1->Size = System::Drawing::Size(43, 26);
				 this->leaderboardYourLabel1->TabIndex = 21;
				 this->leaderboardYourLabel1->Text = L"69.";
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
				 this->leaderboardSearchTextbox->TabIndex = 1;
				 this->leaderboardSearchTextbox->TextChanged += gcnew System::EventHandler(this, &PgrMenu::leaderboardSearchTextbox_TextChanged);
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
				 // PgrMenu
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
				 this->ClientSize = System::Drawing::Size(463, 750);
				 this->Controls->Add(this->gamesPanel);
				 this->Controls->Add(this->userPanel);
				 this->Controls->Add(this->leaderboardPanel);
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
