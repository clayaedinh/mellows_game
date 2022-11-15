#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

#include "interpreter.hpp"
#include "misc.hpp"


using namespace std;

void printInputRequest(string msg){
    cout << msg << "\n >";
}
/* COMMAND FUNCTIONS*/

typedef vector<string> const& Argslist;

string commandNull(Argslist args){
    return "";
}

string commandLook(Argslist args){
    return "you are blind.";
}
/* LIST OF COMMANDS */

class Command{
    private:
    string (* action)(Argslist args);
    string usage;

    public:
    void printUsage();
    void activate(Argslist args);
    Command(string (* action)(Argslist args), string usage);
    Command();
    //string activate(unique_ptr<vector<string>> args);
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


static unordered_map<string, Command> commands = {
    {"NULL" , Command(&commandNull, "")},
    {"LOOK" , Command(&commandLook, "LOOK [thing]")},

};

Command * findCommand(string arg){
    toUpper(&arg);
    if (commands.count(arg)){
        return &commands[arg];
    }else{
        return &commands["NULL"];
    }
}

void nextCommand(){
    printInputRequest("Enter Command:");
    vector<string> args;
    string input;

    getline(cin, input);
    cin.clear();

    stringstream ss(input);

    string tmp;
    while(ss >> tmp){
        args.push_back(tmp);
    }
    
    if (args.size() == 0){
        printInputRequest("Please input. Type [help] for list of commands:");
        return;
    }

    auto command = findCommand(args[0]);

    if (args.size() == 1){
        command->printUsage();  
        return; 
    }

    command->activate(args);
     
}