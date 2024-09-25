#ifndef CAN_H
#define CAN_H

#include <vector>
#include <map>
#include <FlexCAN_T4.h>

#define TIMEOUT_TIME 10	//CAN通信のタイムアウトの時間を設定する[ms]

extern std::map<uint32_t, bool> is_can_contact[3];
extern std::map<uint32_t, uint32_t> time_stamp[3];

class CanControl{
	public:
		CanControl(uint8_t _canbus);

		int canbus;
		bool is_can_open;
		
		void init(int baudrate);
		void resetTable();
		void CANDataPull(uint32_t id ,uint8_t data[8]);
		void CANDataPush(uint32_t id ,uint8_t data[8]);
		void MsgStackClear();
		void CANMsgWrite(CAN_message_t msg);
		int8_t CANAllDataWrite();
		bool check_is_contact(uint16_t id);

	private:
		CAN_message_t MSG;
		
		bool _can1 = false;
		bool _can2 = false;
		bool _can3 = false;
		
	protected:
		CanControl(){};
};

#endif