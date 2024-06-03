#pragma once
#include <iostream>
#include <sstream>

class Priority
{
	int priority;
public:
	int GetPriority() { return priority; }
	void SetPriority(int _priority) { priority = _priority; }
};

class Date
{
	std::string date;
public:
	std::string GetDate() { return date; }
	void SetDate(std::string _date) { date = _date; }
};

class Task
{
	std::string task;
	std::string teg;
	Priority priority;
	Date date;
protected:
	void SetTask(std::string _task) { this->task = _task; }

	void SetTeg(std::string _teg) { this->teg = _teg; }

	void SetPriority(int _priority) { priority.SetPriority(_priority); }

	void SetDate(std::string _date) { date.SetDate(_date); }	

public:
	int GetPriority() { return priority.GetPriority(); }
	std::string GetDate() { return date.GetDate(); }
	std::string GetTeg() { return this->teg; }
	std::string GetTask() { return this->task; }
	Task() { task = "0"; priority.SetPriority(0); date.SetDate("0"); }

	void RedactTask()
	{
		std::string TxtForRedact;
		std::cout << "������� ������: ";
		std::cin.ignore();
		std::getline(std::cin, TxtForRedact);
		SetTask(TxtForRedact);

		int priority;
		std::cout << "������� ���������: "; std::cin >> priority;
		SetPriority(priority);

		std::string date;
		std::cout << "������� ����: "; std::cin >> date;
		SetDate(date);

		std::string teg;
		std::cout << "������� ���: "; std::cin >> teg;
		SetTeg(teg);
	}
	void DeleteTask()
	{
		SetTask("0");
		SetPriority(0);
		SetDate("0");
		SetTeg("0");
	}
	void PrintTask()
	{
		std::cout << "������: " << this->GetTask() << "\n��������� �� " << this->GetDate() << "\n���: " << this->GetTeg()<< "\n���������: " << this->GetPriority();
	}
	std::string GetTaskToFile()
	{
		std::string txt;
		txt = "������: " + this->GetTask() + "\n��������� �� " + this->GetDate() + "\n���: " + this->GetTeg() + "\n���������: " + std::to_string(this->GetPriority()) + "\n";
		return txt;
	}
};
