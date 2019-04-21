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
	void configurePoints(int amount);

	int GetId() { return id; }
	bool GetAdmin() { return admin; }
	std::string GetName() { return username; }
	std::string GetEmail() { return email; }
	std::string GetPassword() { return password; }
	

	void SetPassword(std::string str) { password = str; }
	
};

void connectToSQL(MySqlConnection^ &conn);