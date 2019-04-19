#include "user.h"

#include <string>
#include <fstream>

using namespace System;
using namespace MySql::Data::MySqlClient;

const std::string connInfo = "SERVER=127.0.0.1;UserID=root;Password=;Database=ksg_games";;

void User::initUser(int ID) {
	MySqlConnection^ conn;
	MySqlDataReader^ dr;
	MySqlCommand^ cmd;
	connectToSQL(conn);

	cmd = gcnew MySqlCommand("SELECT * FROM users WHERE id= '" + ID + "' ", conn);
	dr = cmd->ExecuteReader();
	dr->Read();

	id = ID;
	admin = dr->GetBoolean(1);
	username = msclr::interop::marshal_as<std::string>(dr->GetString(2));
	email = msclr::interop::marshal_as<std::string>(dr->GetString(3));
	password = msclr::interop::marshal_as<std::string>(dr->GetString(4));
	points = dr->GetInt32(5);

	conn->Close();
}

void User::configurePoints(int amount) {
	MySqlConnection^ conn;
	MySqlDataReader^ dr;
	MySqlCommand^ cmd;
	connectToSQL(conn);

	points += amount;
	cmd = gcnew MySqlCommand("UPDATE users SET Points=" + points + " WHERE id=" + id + "", conn);
	cmd->ExecuteReader();

	conn->Close();
}

void connectToSQL(MySqlConnection^ &conn) {
	String^ connectionInfo = gcnew String(connInfo.c_str());
	conn = gcnew MySqlConnection(connectionInfo);
	conn->Open();
}

