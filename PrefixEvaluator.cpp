///////////////////////////////////////////////////////////////////////////////////
//On my honor,
//The following program is a result of personal effort. I have not discussed with
//anyone other than my instructor or any appropriate person in charge of the class.
//I have not used, or slightly modified  code or portion of code from another
//student, or an unauthorized source.
//If any C++ language code or documentation used in my program was obtained from
//another source, such as a textbook or course notes, that has been clearly noted
//with a proper citation in the comments of my program.
//I have not designed this program in such a way as to defeat or interfere with the
//normal operation of the eniac system or cslab machines at Hunter College .
// ****<Johnny Qiu>****
/////////////////////////////////////////////////////////////////////////////////////
//
//Author:***** <Johnny Qiu> ******
//Course: {235}
//Instructor: <Severin Ngnosse>
//Assignment: <Midterm Prefix Evaluation>
//Due Date: May 9th, 2016

 // This program takes a Pre-fix input from a user and evaluates it to give it a correct answer using stacks to implement
 // the algorithm.



#include <iostream>
#include <stack>
#include <string>
#include <stdlib.h>
#include <cstring>
#include <sstream>


using namespace std;


int main (){
    
   string userInput;      //string input that is taken from the user input already at a prefix expression
   stack<char> wholeInput;
   stack<char> allOperator;//stack for Operators
   stack<int> allOperand;//stack for Operands
   cout << " Enter a Pre-Fix input " << endl;    
   getline(cin,userInput); // getting the string from the input
   stringstream oper; // used to covert char to int 
   int operand1,operand2,operand3,pushOper; // the operators are used to evaluate the expressions with pushOper
 
   for (int i=0; i<userInput.size();i++){
       
       wholeInput.push(userInput.at(i));  //loops to stack it into reverse form where evaluating pre-fix can be done
   }
    while( !(wholeInput.empty())){                       // The numbers are pushed into the operand stack until the stack is complete
        if(( wholeInput.top()=='1')||(wholeInput.top()=='2'||(wholeInput.top()=='3')||(wholeInput.top()=='4')||(wholeInput.top()=='5')||
         (wholeInput.top()=='6')|| (wholeInput.top()=='7')|| (wholeInput.top()=='8')|| (wholeInput.top()=='9')))
        {
           oper<<wholeInput.top(); // used to convert char to int
           oper>>pushOper;
           allOperand.push(pushOper);
           wholeInput.pop();
             oper.clear();       // resets the stringstream so it can perform its operation again
   
   } 
      else {
     allOperator.push(wholeInput.top());      // if it's an operator it is pushed into allOperator stack
          while(!(allOperator.empty())){       // if the operator stack has an operator it will perform the task and then it is popped out
           operand1=allOperand.top();
           allOperand.pop();
           operand2=allOperand.top();
           allOperand.pop();  
       
           if(allOperator.top()=='+'){
              operand3=operand1+operand2;
              allOperand.push(operand3); 
           }
          
             else if(allOperator.top()=='-'){
                 operand3=operand1-operand2;
                 allOperand.push(operand3); 
                 
             }
            else if(allOperator.top()=='/'){
                  operand3=operand1/operand2;;
                  allOperand.push(operand3); 
           }
             else if (allOperator.top()=='*'){
                  operand3=operand2*operand1;
                  allOperand.push(operand3); 
             }
             allOperator.pop();
             wholeInput.pop();
      }   
      
      }
     
   
      }
       cout << "The Evaluated Expression is equal to " << allOperand.top()<<endl;
}
       
    
