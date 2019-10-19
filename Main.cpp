
#include <iostream>
#include <string>
#include "Station.h"
#include "Train_Company.h"
#include "Driver_Conductor.h"

enum actions { NONE, CREATE_TRAIN, MODIFY_TRAIN, DECOMISSION_TRAIN, BOARD_DISEMBARK_PASSANGERS, BOARD_DISEMBARK_CREW, TRAIN_RUN, SHOW_TRAINS, SHOW_TRAINS_COMPANY, QUIT };

void main()
{
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
			board_disembark_passangers(train_company);
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
	std::cout << "1 - Create Train" << std::endl;
	std::cout << "2 - Modify Train" << std::endl;
	std::cout << "3 - Decomission Train" << std::endl;
	std::cout << "4 - Board Passangers" << std::endl;
	std::cout << "5 - Board Crew" << std::endl;
	std::cout << "6 - Train Run" << std::endl;
	std::cout << "7 - Show Trains" << std::endl;
	std::cout << "8 - Show Train Company" << std::endl;
	std::cout << "9 - Quite Program" << std::endl;
	std::cout << "Which actions would you like to take? ";
}

void create_train(Train_Company& train_company)
{
	train_company.show();
	std::cout << "Please select the train station in which you would like to create the train: " << std::endl;
	Station& selected_station = train_company.select_station;

	while (!selected_station.platforms_are_available) {
		std::cout << "All platforms in this station are occupied by trains - please select another station: ";
		selected_station = train_company.select_station;
	}

	selected_station.show;
	std::cout << "Please select an empty platform in which to create the train: ";
	Platform& selected_platform = selected_station.select_platform;

	while (selected_platform.is_occupied)
	{
		selected_station.show;
		std::cout << "The platform you have selected is occupied by a train - please select another platform: ";
		selected_platform = selected_station.select_platform;
	}

	Train new_train(selected_station); 
	train_company += new_train;
	selected_platform += new_train;
	std::cout << "The new train has been created" << std::endl;
}

void modify_train(Train_Company& train_company)
{
	int action;
	int carraige_type;

	train_company.show();
	std::cout << "Please select the train you would like to modify: ";
	Train& selected_train = train_company.select_train;

	std::cout << "What would you like to do?" << std::endl;
	std::cout << "1 - Add Carriage" << std::endl;
	std::cout << "2 - Remove Carriage" << std::endl;
	std::cout << "3 - Quit" << std::endl;

	while (true)
	{
		switch (action)
		{
		case 1:
			std::cout << "Which type of carraige (Passangers - 0, Cargo - 1, Restaurant - 2, Engine - 3) would you to add to the train?";
			std::cin >> carraige_type;
			selected_train += new Carriage((Carriage_Type)carraige_type);
			break;
		case 2:
			std::cout << "Which type of carraige (Passangers - 0, Cargo - 1, Restaurant - 2, Engine - 3) would you to remove from the train?";
			std::cin >> carraige_type;
			selected_train.remove_carriage((Carriage_Type)carraige_type);
			break;
		case 3:
			std::cout << "Quitting..." << std::endl;
			return;
		default:
			std::cout << "Please select a valid option" << std::endl;
			break;
		}
	}
}

void decomission_train(Train_Company& train_company)
{
	show_trains(train_company);
	std::cout << "Please select the train you would like to decomission: ";
	Train& selected_train = train_company.select_train;
	train_company.decomission_train(selected_train);
}

void board_disembark_passangers(Train_Company& train_company)
{
	int action;
	char* name;
	Passanger* passanger;

	train_company.show();
	std::cout << "Please select a train: ";
	Train& selected_train = train_company.select_train;

	std::cout << "What would you like to do?" << std::endl;
	std::cout << "1 - Board Passanger" << std::endl;
	std::cout << "2 - Disembark Passanger" << std::endl;
	std::cout << "3 - Quit function" << std::endl;

	while (true)
	{
		switch (action)
		{
		case 1:
			if (!selected_train.can_passanger_board)
			{
				std::cout << "Passangers cannot board this train!" << std::endl;
				break;
			}

			std::cout << "What is the passanger's name?" << std::endl;
			std::cin >> name; //is this ok?
			selected_train.add_passanger(new Passanger(name));
			break;
		case 2:
			if (!selected_train.has_passangers_onboard)
			{
				std::cout << "There are no passangers onboard this train!" << std::endl;
				break;
			}

			std::cout << "What is the passanger's name?" << std::endl;
			std::cin >> name; //is this ok?
			passanger = selected_train.get_passanger(name);

			if (passanger == NULL)
				std::cout << "There is not passanger by that name onboard this train!" << std::endl;
			else
				selected_train.remove_passanger(passanger);

			break;
		case 3:
			std::cout << "Quitting..." << std::endl;
			return;
		}
	}
}

void board_disembark_crew(Train_Company& train_company)
{
	int action;
	int crew_member_type;
	char* name;

	train_company.show();
	std::cout << "Please select a train: ";
	Train& selected_train = train_company.select_train;

	std::cout << "What would you like to do?" << std::endl;
	std::cout << "1 - Board Crewmemeber" << std::endl;
	std::cout << "2 - Disembark Crewmemeber" << std::endl;
	std::cout << "3 - Quit function" << std::endl;

	while (true)
	{
		switch (action)
		{
		case 1:
			std::cout << "What is the crew member's name?" << std::endl;
			std::cin >> name; 

			if (selected_train.get_crewmember(name) != NULL)
				std::cout << "There is already a crew member by that name onboard this train" << std::endl;

			std::cout << "Which type of crew member (1 - Driver, 2 - Conductor, 3 - Driver Conductor) would you to add to the train?";
			std::cin >> crew_member_type;
			switch (crew_member_type)
			{
			case 1:
				selected_train += new Driver(name);
				break;
			case 2:
				selected_train += new Conductor(name);
				break;
			case 3:
				selected_train += new Driver_Conductor(name); 
				break;
			default:
				std::cout << "Invalid selection - crew member not created" << std::endl;
				break;
			}

			break;
		case 2:
			std::cout << "What is the crewmember's name?" << std::endl;
			std::cin >> name;
			Person* crew_member = selected_train.get_crewmember(name);

			if (crew_member == NULL)
				std::cout << "There is not crew member by that name onboard this train" << std::endl;
			else
				selected_train -= crew_member;

			break;
		case 3:
			std::cout << "Quitting..." << std::endl;
			return;
		}
	}
}

void train_run(Train_Company& train_company)
{
	show_trains(train_company);
	std::cout << "Please select a train: ";
	Train& selected_train = train_company.select_train;

	while (!selected_train.can_train_depart)
	{
		std::cout << "This train cannot depart the station - please choose another";
		selected_train = train_company.select_train; //can I do this?
	}

	train_company.show;
	std::cout << "Please select a destination station: ";
	Station& destination_station = train_company.select_station;

	if (destination_station == selected_train.get_station)
	{
		std::cout << "This is the same station the train is in";
		return;
	}
	if (!destination_station.platforms_are_available())
	{
		std::cout << "This station cannot accept the train - there are not available platforms";
		return;
	}

	selected_train.set_station(&destination_station);
	selected_train.remove_all_passangers();
}

void show_trains(const Train_Company& train_company)
{
	int number_of_trains = train_company.get_number_of_trains;

	for (int i = 0; i < number_of_trains; i++)
		train_company.get_train(i).show();
}

void show_train_company(const Train_Company& train_company)
{
	train_company.show();
}

