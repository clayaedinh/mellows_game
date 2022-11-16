#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

#include "interpreter.hpp"
#include "misc.hpp"
#include "room.hpp"

using namespace std;

typedef vector<string> & Argslist;

//FWD DECLARATIONS
string commandHelp(Argslist args);
string findCommandUsage(string arg);


// COMMAND FUNCTIONS
string commandNull(Argslist args){
    return "NULL DETECTED: " + args[0] + "\n";
}
string commandQuit(Argslist args){
    return "Quitting...\n";
}

string commandView(Argslist args){
    if (args.size() == 1 || args.size() >= 3){
        return findCommandUsage(args[0]);
    }
    return commandRoomView(args[1]);
}

/* COMMAND DECLARATION */

class Command{
    private:
    string (* action)(Argslist args);
    
    public:
    string usage;
    Command(string (* action)(Argslist args), string usage);
    Command();

    string getUsage();
    void activate(Argslist args);
    bool isNull();
    bool isQuit();

};

Command::Command(string (* act)(Argslist args), string us){
    action = act;
    usage = us;
}
Command::Command(){
    action = NULL;
    usage = "";
}

string Command::getUsage(){
    return "Usage:\n" + usage;
}

void Command::activate(Argslist args){
    cout << "\n" << action(args) << "\n\n";
}

bool Command::isNull(){
    return action == &commandNull;
}
bool Command::isQuit(){
    return action == &commandQuit;
}


// COMMANDS LIST

static unordered_map<string, Command> commands = {
    {"HELP" , Command(&commandHelp, "HELP [commandName (optional)]")},
    {"NULL" , Command(&commandNull, "")},
    {"QUIT" , Command(&commandQuit, "QUIT")},
    {"VIEW" , Command(&commandView, "VIEW [thing]")},
};

// SEARCH COMMANDS LIST

Command * findCommand(string arg){
    toUpper(&arg);
    if (commands.count(arg)){
        return &commands[arg];
    }else{
        return &commands["NULL"];
    }
}

string findCommandUsage(string arg){
    Command * cmd = findCommand(arg);
    if (cmd != NULL){
        return cmd->getUsage();
    }else{
        return "";
    }
}

// MORE COMMAND FUNCTIONS

string commandHelp(Argslist args){
    if (args.size() == 1){
        string helpList = "list of commands:\n";
        for (auto s : commands){
            if (s.second.isNull()) continue;
            helpList += "\n" + s.second.usage;
        }
        return helpList;
    }
    if (args.size() >= 3){
        return findCommandUsage(args[0]);
    }
    return findCommandUsage(args[1]);
}

void printInputRequest(string msg){
    cout << "- - - - - - - - - - - - - - - - \n" << msg << "\n >";
}

// INTERPRET COMMAND

InterpretResult interpretNextCommand(){
    printInputRequest("Enter Command:");
    
    string input;
    getline(cin, input);

    stringstream ss(input);
    vector<string> args;
    string tmp;
    
    while(ss >> tmp) args.push_back(tmp);
    
    if (args.size() == 0){
        printInputRequest("Please input. Type HELP for list of commands:");
        return INTERPRET_AGAIN;
    }

    auto command = findCommand(args[0]);

    if (command->isNull()){
        printInputRequest("Command unrecognized. Type HELP for list of commands:");
        return INTERPRET_AGAIN;
    }

    command->activate(args);

    if (command->isQuit()){
        return INTERPRET_QUIT;
    }

    return INTERPRET_DONE;
}