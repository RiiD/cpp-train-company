#include "pch.h"

#include <iostream>
#include <string>

#include "Station.h"
#include "Train_Company.h"
#include "Driver_Conductor.h"
#include "CancelledException.h"
#include "MyLinkedList.h"

enum actions { NONE, CREATE_TRAIN, MODIFY_TRAIN, DECOMISSION_TRAIN, BOARD_DISEMBARK_PASSANGERS, BOARD_DISEMBARK_CREW, TRAIN_RUN, SHOW_TRAINS, SHOW_TRAINS_COMPANY, QUIT };

void main();

void show_menu();
void create_train(Train_Company& train_company);
void modify_train(Train_Company& train_company);
void decomission_train(Train_Company& train_company);
void board_disembark_passangers(Train_Company& train_company);
void board_disembark_crew(Train_Company& train_company);
void train_run(Train_Company& train_company);
void show_trains(const Train_Company& train_company);
void show_train_company(const Train_Company& train_company);
void show_trains(const Train_Company& train_company);
void show_trains(const Train_Company& train_company);
void test_linked_list();

void main()
{
	//char a;
	//test_linked_list();

	//cin >> a;
	//return;

	int action = -1;
	int number_of_trains = 0;

	Station paris_station(Paris);
	Station berlin_station(Berlin);
	Station vienna_station(Vienna);
	Station prague_station(Prague);
	Station rome_station(Rome);

	Train_Company train_company;
	train_company += paris_station;
	train_company += berlin_station;
	train_company += vienna_station;
	train_company += prague_station;
	train_company += rome_station;

	while (action != QUIT)
	{
		show_menu();
		std::cin >> action;

		switch (action)
		{
		case CREATE_TRAIN:
			create_train(train_company);
			break;
		case MODIFY_TRAIN:
			modify_train(train_company);
			break;
		case DECOMISSION_TRAIN:
			decomission_train(train_company);
			break;
		case BOARD_DISEMBARK_PASSANGERS:
			board_disembark_passangers(train_company);
			break;
		case BOARD_DISEMBARK_CREW:
			board_disembark_crew(train_company);
			break;
		case TRAIN_RUN:
			train_run(train_company);
			break;
		case SHOW_TRAINS:
			show_trains(train_company);
			break;
		case SHOW_TRAINS_COMPANY:
			show_train_company(train_company);
			break;
		case QUIT:
			action = QUIT;
			break;
		default:
			break;
		}
	}
}

void show_menu()
{
	std::cout << "Train Company - Actions Menu" << std::endl;
	std::cout << CREATE_TRAIN << " - Create Train" << std::endl;
	std::cout << MODIFY_TRAIN << " - Modify Train" << std::endl;
	std::cout << DECOMISSION_TRAIN << " - Decomission Train" << std::endl;
	std::cout << BOARD_DISEMBARK_PASSANGERS << " - Board Passangers" << std::endl;
	std::cout << BOARD_DISEMBARK_CREW << " - Board Crew" << std::endl;
	std::cout << TRAIN_RUN << " - Train Run" << std::endl;
	std::cout << SHOW_TRAINS << " - Show Trains" << std::endl;
	std::cout << SHOW_TRAINS_COMPANY << " - Show Train Company" << std::endl;
	std::cout << QUIT << " - Quite Program" << std::endl;
	std::cout << "Which actions would you like to take? ";
}

void create_train(Train_Company& train_company)
{
	try {
		std::cout << "Please select the train station in which you would like to create the train: " << std::endl; 
	
		Station* selected_station = train_company.select_station();

		while (!selected_station->platforms_are_available()) {
			std::cout << "All platforms in this station are occupied by trains - please select another station:" << std::endl;
			selected_station = train_company.select_station();
		}

		selected_station->show();
		std::cout << "Please select an empty platform in which to create the train: " << std::endl;
		Platform* selected_platform = selected_station->select_platform();

		while (selected_platform->is_occupied())
		{
			selected_station->show();
			std::cout << "The platform you have selected is occupied by a train - please select another platform:" << std::endl;
			selected_platform = selected_station->select_platform(); 
		}

		Train* train = train_company += Train(selected_platform);
		selected_platform->set_train(train);
		std::cout << "The new train has been created" << std::endl;
	} 
	catch (CancelledException&) 
	{
		std::cout << "Cancelled" << endl;
	}
}

void modify_train(Train_Company& train_company)
{
	try {
		int action;
		int carraige_type;

		std::cout << "Please select the train you would like to modify: " << endl;
		Train* selected_train = train_company.select_train();

		
		do {
			std::cout << "What would you like to do?" << std::endl;
			std::cout << "1 - Add Carriage" << std::endl;
			std::cout << "2 - Remove Carriage" << std::endl;
			std::cout << "3 - Quit" << std::endl;

			cin >> action;

			switch (action)
			{
			case 1:
				do {
					std::cout << "Which type of carraige (Passangers - 0, Cargo - 1, Restaurant - 2, Engine - 3) would you to add to the train?";
					std::cin >> carraige_type;
				} while (carraige_type < 0 || carraige_type > 3);

				*selected_train += Carriage((Carriage::Type)carraige_type);
				break;
			case 2:
				do {
					std::cout << "Which type of carraige (Passangers - 0, Cargo - 1, Restaurant - 2, Engine - 3) would you to remove from the train?";
					std::cin >> carraige_type;
				} while (carraige_type < 0 || carraige_type > 3);
				
				selected_train->remove_carriage((Carriage::Type)carraige_type);
				break;
			case 3:
				std::cout << "Quitting..." << std::endl;
				return;
			default:
				std::cout << "Please select a valid option" << std::endl;
				break;
			}
		} while (true);
	}
	catch (CancelledException&)
	{
		std::cout << "Cancelled" << endl;
	}
}

void decomission_train(Train_Company& train_company)
{
	try {
		show_trains(train_company);
		std::cout << "Please select the train you would like to decomission: " << endl;
		Train* selected_train = train_company.select_train();
		train_company.decomission_train(selected_train);
	}
	catch (CancelledException&)
	{
		std::cout << "Cancelled" << endl;
	}
}

void board_disembark_passangers(Train_Company& train_company)
{
	try {
		int action;
		char name[20];
		const Passanger* passanger;

		std::cout << "Please select a train: " << endl;
		Train* selected_train = train_company.select_train();

		while (true)
		{
			std::cout << "What would you like to do?" << std::endl;
			std::cout << "1 - Board Passanger" << std::endl;
			std::cout << "2 - Disembark Passanger" << std::endl;
			std::cout << "3 - Quit function" << std::endl;

			cin >> action;

			switch (action)
			{
			case 1:
				if (!selected_train->can_passanger_board())
				{
					std::cout << "Passangers cannot board this train!" << std::endl;
					break;
				}

				std::cout << "What is the passanger's name?" << std::endl;
				std::cin >> name;
				selected_train->add_passanger(Passanger(name));
				break;
			case 2:
				if (!selected_train->has_passangers_onboard())
				{
					std::cout << "There are no passangers onboard this train!" << std::endl;
					break;
				}

				std::cout << "What is the passanger's name?" << std::endl;
				std::cin >> name;
				passanger = selected_train->get_passanger(name);

				if (passanger == nullptr)
					std::cout << "There is not passanger by that name onboard this train!" << std::endl;
				else
					selected_train->remove_passanger(*passanger);

				break;
			case 3:
				std::cout << "Quitting..." << std::endl;
				return;
			}
		}
	}
	catch (CancelledException&)
	{
		std::cout << "Cancelled" << endl;
	}
}

void board_disembark_crew(Train_Company& train_company)
{
	try {
		int action;
		int crew_member_type;
		char name[20];
		const Person* crew_member;

		std::cout << "Please select a train: " << endl;
		Train* selected_train = train_company.select_train();

		while (true)
		{
			std::cout << "What would you like to do?" << std::endl;
			std::cout << "1 - Board Crewmemeber" << std::endl;
			std::cout << "2 - Disembark Crewmemeber" << std::endl;
			std::cout << "3 - Quit function" << std::endl;

			cin >> action;

			switch (action)
			{
			case 1:
				std::cout << "What is the crew member's name?" << std::endl;
				std::cin >> name; 

				if (selected_train->get_crewmember(name) != nullptr) {
					std::cout << "There is already a crew member by that name onboard this train" << std::endl;
					continue;
				}

				std::cout << "Which type of crew member (1 - Driver, 2 - Conductor, 3 - Driver Conductor) would you to add to the train?";
				std::cin >> crew_member_type;
				switch (crew_member_type)
				{
				case 1:
					*selected_train += Driver(name);
					break;
				case 2:
					*selected_train += Conductor(name);
					break;
				case 3:
					*selected_train += Driver_Conductor(name);
					break;
				default:
					std::cout << "Invalid selection - crew member not created" << std::endl;
					break;
				}

				break;
			case 2:
				std::cout << "What is the crewmember's name?" << std::endl;
				std::cin >> name;
				crew_member = selected_train->get_crewmember(name);

				if (crew_member == nullptr)
					std::cout << "There is not crew member by that name onboard this train" << std::endl;
				else
					*selected_train -= *crew_member;

				break;
			case 3:
				std::cout << "Quitting..." << std::endl;
				return;
			}
		}
	}
	catch (CancelledException&)
	{
		std::cout << "Cancelled" << endl;
	}
}

void train_run(Train_Company& train_company)
{
	try {
		std::cout << "Please select a train: " << endl;
		Train* selected_train = train_company.select_train();

		while (!selected_train->can_train_depart())
		{
			std::cout << "This train cannot depart the station - please choose another" << endl;
			selected_train = train_company.select_train();
		}

		train_company.show();
		std::cout << "Please select a destination station: " << endl;
		Station* destination_station = train_company.select_station();

		if (destination_station == selected_train->get_platform()->get_station())
		{
			std::cout << "This is the same station the train is in" << endl;
			return;
		}

		Platform* platform = destination_station->get_available_platform();

		if (platform == nullptr)
		{
			std::cout << "This station cannot accept the train - there are not available platforms" << endl;
			return;
		}

		selected_train->set_platform(platform);
		selected_train->remove_all_passangers();
	}
	catch (CancelledException&)
	{
		std::cout << "Cancelled" << endl;
	}
}

void show_trains(const Train_Company& train_company)
{
	int number_of_trains = train_company.get_number_of_trains();

	for (int i = 0; i < number_of_trains; i++)
	{
		train_company.get_train(i)->show();
	}
}

void show_train_company(const Train_Company& train_company)
{
	train_company.show();
}

void test_linked_list()
{
	int action = -1;
	MyLinkedList<string> l;
	l.append("Hello");
	l.append("2");
	cout << l;
	cin >> action;
}