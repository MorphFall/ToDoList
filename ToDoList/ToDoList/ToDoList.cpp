#include "task.h"
#include <Windows.h>
#include <vector>
#include <fstream>

void FindTask(std::vector<Task> TaskList)
{
	int chose = -1;
	std::cout << "По какому параметру будем искать?: \n1. По дате\n2. По тегу\n3. По приоритету\n4. По записи\n0. Вернуться\nВведите выбор: ";
	std::cin >> chose;

	if (chose == 1)
	{
		std::string date;
		std::cout << "Введите дату: "; std::cin >> date; std::cout << "\n";
		for (Task task : TaskList)
		{
			if (task.GetDate() == date) task.PrintTask();
		}
	}
	else if (chose == 2)
	{
		std::string teg;
		std::cout << "Введите тег: "; std::cin >> teg; std::cout << "\n";
		for (Task task : TaskList)
		{
			if (task.GetTeg() == teg) task.PrintTask();
		}
	}
	else if (chose == 3)
	{
		int priority;
		std::cout << "Введите приоритет: "; std::cin >> priority; std::cout << "\n";
		for (Task task : TaskList)
		{
			if (task.GetPriority() == priority) task.PrintTask();
		}
	}
	else if (chose == 4)
	{
		std::string TxtForSearch;
		std::cout << "Введите задачу: ";
		std::cin.ignore();
		std::getline(std::cin, TxtForSearch);
		for (Task task : TaskList)
		{
			if (task.GetTeg() == "0" && task.GetPriority() == 0) {}
			else
			{
				if (task.GetTask() == TxtForSearch) { task.PrintTask(); break; }
			}
		}
	}
}
void PrintAllTasks(std::vector<Task> TaskList)
{
	int num = 1;
	for (Task task : TaskList)
	{
		if (task.GetTeg() == "0" && task.GetPriority() == 0) {}
		else
		{
			std::cout << "\n==========================";
			std::cout << "\n" << num << ". ";
			task.PrintTask(); 
			std::cout << "\n==========================";
			num++;
		}
	}
}
void SaveToFile(std::vector<Task> TaskList)
{
	std::ofstream out;
	out.open("ToDoList.txt");
	for (Task task : TaskList)
	{
		if (task.GetTeg() == "0" && task.GetPriority() == 0) {}
		else out << task.GetTaskToFile();
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	std::vector<Task> TaskList;
	Task newTask;
	int chose = -1;

	do
	{
		std::cout << "\n\n\t\tTo-Do List\n1. Добавить запись\n2. Удалить запись\n3. Вывести список дел\n4. Поиск записи\n5. Сохранить в файл"
			<<"\n0.Выход\nВведите цифру выбора : ";
		std::cin >> chose;
		if (chose == 1)
		{
			newTask.RedactTask();
			TaskList.push_back(newTask);
		}
		else if (chose == 2)
		{
			int chose = 0;
			PrintAllTasks(TaskList);
			std::cout << "\nВведите номер записи, которую нужно удалить: "; std::cin >> chose;
			int num = 1;
			for (Task task : TaskList)
			{
				if (task.GetTeg() == "0" && task.GetPriority() == 0) {}
				else
				{
					if (num == chose) { TaskList[num - 1].DeleteTask(); break; }
				}
				num++;
			}
		}
		else if (chose == 3) { PrintAllTasks(TaskList); }
		else if (chose == 4) { FindTask(TaskList); }
		else if (chose == 5) { SaveToFile(TaskList); }
	} while (chose != 0);
}