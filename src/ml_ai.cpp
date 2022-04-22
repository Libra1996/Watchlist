#include "ml_ai.h"

void MachineAi::move_history(Choice user_move) // ai moves are in even number indexes in history. User moves are in odd numbered indexes in history
{
	string move = choice_to_string(user_move);
    if (move == "rock")
        History.push_back("R");
    else if (move == "paper")
        History.push_back("P");
    else
        History.push_back("S");

    string s;
    if (History.size() == 5)
    {
        // push to hashmap
        for (auto i : History)
        {
            s += i;
        }

        std::unordered_map<string, int>::iterator it = frequency.find(s);

        // key already present on the map
        if (it != frequency.end())
        {
            it->second++; // increment map's value for key `c`
        }
        // key not found
        else
        {
            frequency.insert(std::make_pair(s, 1));
        }

        History.erase(History.begin(), History.begin() + 2);
    }
    write_to_file(frequency);
}

Choice MachineAi::DecideMove(Choice user_move)
{
	move_history(user_move);
    if (flag == true)
    {
        ai_move = next_move;
        string s = choice_to_string(ai_move);
        flag = false;
        move_history(ai_move);
    }
    else
    { // random number
        int moveInt = rand() % 3;
        switch (moveInt)
        {
        case 0:
            ai_move = ROCK;
            break;
        case 1:
            ai_move = PAPER;
            break;
        case 2:
            ai_move = SCISSORS;
            break;
        default:
            ai_move = NONE;
        }
        string s = choice_to_string(ai_move);

        move_history(ai_move);
    }
    if (History.size() == 4 && frequency.size() > 0) // prediction
    {
        string s;
        for (auto i : History)
        {
            s += i;
        }
        string a = s + "R";
        string b = s + "S";
        string c = s + "P";

        int d, e, f;
        d = getHashValue(a);
        e = getHashValue(b);
        f = getHashValue(c);

        if (d == -1 && e == -1 && f == -1)
        {
            int moveInt = rand() % 3;
            switch (moveInt)
            {
            case 0:
                next_move = ROCK;
                break;
            case 1:
                next_move = PAPER;
                break;
            case 2:
                next_move = SCISSORS;
                break;
            default:
                next_move = NONE;
            }
            flag = true;
        }
        else
        {
            int val = d;
            val = max(val, e);
            val = max(val, f);

            if (val == d)
            {
                next_move = PAPER;
            }
            else if (val == e)
            {
                next_move = ROCK;
            }
            else
            {
                next_move = SCISSORS;
            }
            string s = choice_to_string(next_move);
            flag = true;
        }
    }
    
    return ai_move;
}

int MachineAi::getHashValue(string s)
{
    int i;
    std::unordered_map<string, int>::iterator it = frequency.find(s);

    // key already present on the map
    if (it != frequency.end())
    {
        i = it->second; // set map's value for key `c`
    }
    // key not found
    else
    {
        i = -1;
    }
    return i;
}

void MachineAi::write_to_file(unordered_map<string, int> map)
{
    ofstream outfile;
    outfile.open("freq.txt");
    for(auto it = map.begin(); it != map.end(); ++it)
    {
        outfile << it->first << " " << it->second << endl;
    }
    outfile.close();
}

//a fucntion that takes a text file and reads it into a hashmap
unordered_map<string, int> MachineAi::read_from_file(string file_name)
{
    unordered_map<string, int> map;
    ifstream infile;
    infile.open(file_name);
    string line;
    while(getline(infile, line))
    {
        string word;
        string count;
        stringstream ss(line);
        getline(ss, word, ' ');
        getline(ss, count, ' ');
        int icount = stoi(count);
        map.insert(pair<string, int>(word, icount));
    }
    infile.close();
    return map;
}

void MachineAi::set_next_move(Choice c) {
	next_move = c;
}

Choice MachineAi::GetPredictedMove(Choice user_move) {
	Choice c = next_move;
	return c;
}
