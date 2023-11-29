#include<iostream>
#include<stack>
#include<string>

using namespace std;

struct task{                  //straucture to represent a task 
  string descr;        //task  discripton 
  bool finshied ;      //indicates whether thetask is completed or not 
}


class ToDoList{

  private :
    stack<Task> Tstack;   //stack t o store tasks
    stack<Task>UDstack;   //undone the task frot redo fuction





//fuction to addt h new task to the list 
public : 

 void addTask (const string& descr ){

  Task newTask{descr ,false};               // create a new task withthe given description 
  Tstack.push(newtask);                        // add the new task to the task stack 
  UDstack=stack<task>();                     // clear undonw stack when a new task is add

  
}



// fuction to mark the perious add fuction is complted 
void finshedtask(){

  if(!Tstack.empty()){

    Task finshedTask  = Tstack.top();  // ger the op task form the stack 
    finshedTask.finshied = true;    //marl the tsk as complted 
    Tstack.pop();                        //remove the task fromt eh tstack 
    UDstack  = stack<task>();                  //clear undone stck when a task 
    cout<<"Task finshied: "<< finshedTask.descr<<endl;
  }
  else{
       cout<< "No task to complete." << endl;
    
  }
}



//fuction to undon the last task operation 
void undo(){

  if(!Tstack.empty()){
      task undonetask  = Tstack.top();   //get hte top task formt eh stack 
      Tstack.pop();                               //remove the task fromt eh stack 
    UDstack.push(undoneTask);                           //add the undone task to undone
    cout<<"undo:"<< undonetask.descr<<endl;
    

  } else {
      cout<<"Nothing to undo" endl;
  }
}




//function to redo the last undone task 
Void redo(){

  if(!UDstack.empty ()){

    Task UDstack = UDstack.top();         //get the top taks from the undone 
    UDstack.pop();
    Tstack.push(UDstack);                        add the redone task back to the list 
    cout<< "Redo : " << UDstack.descr<<endli;
    
  } 
  else{
    Cout<< "nothing to redo. "<< endl;
  }
}



// function to display the current task in the to-do list 

void displaytask() const{

  if (Tstack.empty()) {
      cout<<"no task in the to-do list."<< endl;
  }
    else{
      cout <<"To do list:" << endly;
      stack<task> tempstack = Tstack;      //creat a copy of hte stack for siplay 
        while(!tempstack.empty()){
          Task task = tempstack.top();
          tempstack.pop();
          cout<< "- " <<(task.finshied ? "[Done] " :[pending] ") <<task.descr <<endl;
            
        }
    }
  }
}
};



//main fuciton 

int main() {

  ToDoList  TDlist;

  while (true) {

    Cout<< " Menu\n;";
    cout << "1.Add Task \n";
    cout << "2. Complete Task \n";
    cout << "3. Undo \n";
    cout << "4. Redo \n";
    cout << "5.Display Tasks \n";
    cout << "6.Exit\n";


    int choice;
    cout<< "Enter your choice:";
    cin>> choice;




    /// switch statement to perform different actions based on user input 
    switch(choice){

      case 1: {
           string descr;
            cout <<"Enter Task description: ";
            cin.ignore();
            getline(cin,descr);
            TDlist.addTask(descr);
        
      }
      break;

      case2:
            TDlist.finshedTask();
            break;
      case 3:TDlist.undo();
            break;
      
      case 4:TDlist.redo();
            break;
      case 5: Tdlist.displayTask();
            break;
      case 6:
          cout<<"Exiting the program .\n"
            return 0;
      default:
        cout << "INvalid choice.please enter a valid option .\n"
      
    }
    
  }

  return ;
  
}
