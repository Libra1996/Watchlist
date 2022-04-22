#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstab.h>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>

#include "ai.h"
#include "Choice.h"

using namespace std;

class MachineAi : public Ai
{
public:
	Choice DecideMove(Choice user_move);
	Choice GetPredictedMove(Choice user_move);
	MachineAi() {
		frequency = read_from_file("freq.txt");
	}
	void move_history(Choice user_move);
	void print_freq_map();
	void write_to_file(unordered_map<string, int> map);
	unordered_map<string, int> read_from_file(string file_name);
	int getHashValue(string s);
	bool flag;
	void set_next_move(Choice c);
private:
	Choice next_move;
	Choice ai_move;
	vector<string> History;
	unordered_map<string, int> frequency;
};
