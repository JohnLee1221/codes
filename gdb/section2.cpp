#include <iostream>
#include <malloc.h>
#include <string.h>
#include <string>

using namespace std;


typedef struct _DISTRICT_BUS_ {
	char name[100];
	int bus_number;
	_DISTRICT_BUS_ *prev;
	_DISTRICT_BUS_ *next;
} DISTRICT_BUS, *PDISTRICT_BUS;

typedef struct _BUS_STOP_ {
	char name[100];
	_BUS_STOP_* prev;
	_BUS_STOP_* next;

} BUS_STOP, *PBUS_STOP;

typedef struct _SCHOOL_BUS_ {
	char bus_no[16];
	int bus_seat_number;
	char driver_name[100];
	char driver_phone[20];
	bool ordered;
	struct _SCHOOL_BUS_* prev;
	struct _SCHOOL_BUS_* next;

} SCHOOL_BUS, *PSCHOOL_BUS;

PSCHOOL_BUS bus_queue_head = nullptr;
PBUS_STOP bus_stop_head = nullptr;
int ordered_bus_number = 0;
PDISTRICT_BUS dis_bus_head = nullptr;

void AddBusStop() {
	PBUS_STOP new_bus_stop = nullptr;
	new_bus_stop = (PBUS_STOP)malloc(sizeof(BUS_STOP));
	new_bus_stop->next = nullptr;
	PBUS_STOP prev_bus = bus_stop_head->prev;
	if (prev_bus) {
		prev_bus->next = new_bus_stop;
		new_bus_stop->prev = prev_bus;
		bus_stop_head->prev = new_bus_stop;
	} else {
		bus_stop_head->next = new_bus_stop;
		new_bus_stop->prev = bus_stop_head;
		bus_stop_head->prev = new_bus_stop;
	}
	std::cout << "请输入班车车站名,然后按回车" << std::endl;
	std::cin >> new_bus_stop->name;
	std::cout << "添加班车车站成功" << std::endl;
}

void DeleteBusStop() {
	char bus_no[100] = {0};
	std::cout << "请输入班车车站名字,然后按回车" << std::endl;
	std::cin >> bus_no;
	PBUS_STOP bus_stop = bus_stop_head->next;

	bool found = false;
	while (bus_stop) {
		if (strcmp(bus_stop->name, bus_no) == 0) {
			std::cout << "删除班车站点成功" << std::endl;
			if (bus_stop->next) {
				bus_stop->next->prev = bus_stop->prev;
				free(bus_stop);
				bus_stop = nullptr;
				found = true;
				break;
			}
			bus_stop = bus_stop->next;
		}
	}
	if (!found) {
		std::cout << "没有找到班车站点" << std::endl;
	}
}

void ViewBusStop() {
	PBUS_STOP bus_stop = bus_stop_head->next;
	int num = 1;
	while (bus_stop) {
		std::cout << num << "班车车站：" << bus_stop->name << std::endl;
		bus_stop = bus_stop->next; 
	}
}

int AddBus() {
	PSCHOOL_BUS new_bus = nullptr;
	new_bus = (PSCHOOL_BUS)malloc(sizeof(SCHOOL_BUS));
	new_bus->next = nullptr;
	PSCHOOL_BUS prev_bus = bus_queue_head->prev;
	if (prev_bus) {
		prev_bus->next = new_bus;
		new_bus->prev = prev_bus;
		bus_queue_head->prev = new_bus;
	} else {
		bus_queue_head->next = new_bus;
		new_bus->prev = bus_queue_head;
		bus_queue_head->prev = new_bus;
	}

	std::cout << "请输入班车车牌（15个字符以内）,然后按回车" << std::endl;
	std::cin >> new_bus->bus_no;
	std::cout << "请输入班车座位数,然后按回车\n" << std::endl;
	std::cin >> new_bus->bus_seat_number;
	std::cout << "请输入班车驾驶员姓名,然后按回车\n" << std::endl;
	std::cin >> new_bus->driver_name;
	std::cout << "请输入班车驾驶员电话,然后按回车\n" << std::endl;
	std::cin >> new_bus->driver_phone;

	std::cout << "添加班车成功\n" << std::endl;
	return 0;
}

int GetSeatNum(PSCHOOL_BUS bus) {
	return bus->bus_seat_number;
}

bool IsOrdered(PSCHOOL_BUS bus) {
	return bus->ordered;
}

int DeleteBus() {
	char bus_no[16] = {0};
	std::cout << "请输入班车车牌（15个字符以内）,然后按回车" << std::endl;
	std::cin >> bus_no;
	PSCHOOL_BUS bus = bus_queue_head->next;

	bool found = false;
	while (bus) {
		if (IsOrdered && GetSeatNum(bus) < 100) {
			continue;
		}
		if (strcmp(bus->bus_no, bus_no) == 0) {
			std::cout << "删除班车成功" << std::endl;
			bus->prev->next = bus->next;
			if (bus->next) {
				bus->next->prev = bus->prev;
			}
			free(bus);
			bus = nullptr;
			found = true;
			break;
		}
		bus = bus->next;
	}
	if (!found) {
		std::cout << "没有找到班车" << std::endl;
	}
	return 0;
}




