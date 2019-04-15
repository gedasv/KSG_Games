#pragma once

#include <string>
#include <fstream>
#include <msclr\marshal_cppstd.h>

using namespace System;
using namespace MySql::Data::MySqlClient;

public class User
{
private:
	int id;
	bool admin;
	std::string username;
	std::string email;
	std::string password;


public:
	int points;

	void initUser(int ID);
	int GetId() { return id; }
	std::string GetName() { return username; }
	std::string GetEmail() { return email; }
	std::string GetPassword() { return password; }
	
	void SetPassword(std::string str) { password = str; }
};

void connectToSQL(MySqlConnection^ &conn);