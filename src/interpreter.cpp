#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

#include "interpreter.hpp"
#include "misc.hpp"
#include "room.hpp"

using namespace std;

void printInputRequest(string msg){
    cout << msg << "\n >";
}
/* COMMAND FUNCTIONS*/

typedef vector<string> const& Argslist;

string commandNull(Argslist args){
    return "";
}

string commandView(Argslist args){
    return commandRoomView(args[1]);
}

/* LIST OF COMMANDS */

class Command{
    private:
    string (* action)(Argslist args);
    string usage;

    public:
    Command(string (* action)(Argslist args), string usage);
    Command();
    void printUsage();
    void activate(Argslist args);
    bool isNull();

};

Command::Command(string (* act)(Argslist args), string us){
    action = act;
    usage = us;
}
Command::Command(){
    action = NULL;
    usage = "";
}

void Command::printUsage(){
    cout << "USAGE:\n" << usage << "\n";
}

void Command::activate(Argslist args){
    cout << action(args) << "\n";
}
bool Command::isNull(){
    return action == &commandNull;
}


static unordered_map<string, Command> commands = {
    {"NULL" , Command(&commandNull, "")},
    {"VIEW" , Command(&commandView, "LOOK [thing]")},

};

Command * findCommand(string arg){
    toUpper(&arg);
    if (commands.count(arg)){
        return &commands[arg];
    }else{
        return &commands["NULL"];
    }
}

void interpretNextCommand(){
    printInputRequest("Enter Command:");
    
    string input;
    getline(cin, input);

    stringstream ss(input);
    vector<string> args;
    string tmp;
    
    while(ss >> tmp) args.push_back(tmp);
    
    if (args.size() == 0){
        printInputRequest("Please input. Type [help] for list of commands:");
        return;
    }

    auto command = findCommand(args[0]);

    if (command->isNull()){
        printInputRequest("Command unrecognized. Type [help] for list of commands:");
        return;
    }

    if (args.size() == 1){
        command->printUsage();  
        return; 
    }

    command->activate(args);
     
}