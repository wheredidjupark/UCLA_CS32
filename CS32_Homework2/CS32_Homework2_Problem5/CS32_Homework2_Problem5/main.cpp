//
//  main.cpp
//  CS32_Homework2_Problem5
//
//  Created by Ju Hyeon Park on 11/2/14.
//  Copyright (c) 2014 Ju Hyeon Park. All rights reserved.
//

/*
 Implement this function that evaluates an infix boolean expression that consists of the binary boolean operators & (meaning and) and | (meaning inclusive or), the unary boolean operator ! (meaning not), parentheses, and the operands T and F, with blanks allowed for readability. Following convention, ! has higher precedence than &, which has higher precedence than |, and the operators & and | associate left to right. In evaluating the expressions, T represents the value true, and F false.
 
 Here are some examples of valid expressions:
 
 
 T                          evaluates to true
 (F)                        evaluates to false
 T&(F)                      evaluates to false
 T & !F                     evaluates to true
 !(F|T)                     evaluates to false
 !F|T                       evaluates to true
 T|F&F                      evaluates to true
 T&!(F|T&T|F)|!!!(F&T&F)    evaluates to true
 
 Here is the function:
 
 
 int evaluate(string infix, string& postfix, bool& result)
 // Evaluates a boolean expression
 //   If infix is a syntactically valid infix boolean expression,
 //   then set postfix to the postfix form of that expression, set
 //   result to the value of the expression, and return zero.  If
 //   infix is not a syntactically valid expression, return 1; in
 //   that case, postfix may or may not be changed, but result must
 //   be unchanged.)
 
 Adapt the algorithms presented on pp. 311-316 of the textbook to convert the infix expression to postfix, then evaluate the postfix form of the expression. The algorithms use stacks. Rather than implementing the stack types yourself, you must use the stack class template from the Standard C++ library. You may not assume that the infix string passed to the function is syntactically valid; you'll have to detect whether it is or not.
 
 For this problem, you will turn in a file named eval.cpp whose structure is probably of the form
 
 
 #include lines you need
 
 declarations of any additional functions you might have written
 to help you evaluate an expression
 
 int evaluate(string infix, string& postfix, bool& result)
 {
 your expression evaluation code
 }
 
 implementations of any additional functions you might have written
 to help you evaluate an expression
 
 a main routine to test your function
 
 If we take your eval.cpp file, rename your main routine (which we will never call) to something harmless, prepend the lines
 
 
 #include <iostream>
 #include <string>
 #include <stack>
 #include <cassert>
 using namespace std;
 
 if necessary, and append the lines
 
 
 int main()
 {
 string pf;
 bool answer;
 assert(evaluate("T| F", pf, answer) == 0  &&  pf == "TF|"  &&  answer);
 assert(evaluate("T|", pf, answer) == 1);
 assert(evaluate("F F", pf, answer) == 1);
 assert(evaluate("TF", pf, answer) == 1);
 assert(evaluate("()", pf, answer) == 1);
 assert(evaluate("T(F|T)", pf, answer) == 1);
 assert(evaluate("T(&T)", pf, answer) == 1);
 assert(evaluate("(T&(F|F)", pf, answer) == 1);
 assert(evaluate("", pf, answer) == 1);
 assert(evaluate("F  |  !F & (T&F) ", pf, answer) == 0
 &&  pf == "FF!TF&&|"  &&  !answer);
 assert(evaluate(" F  ", pf, answer) == 0 &&  pf == "F"  &&  !answer);
 assert(evaluate("((T))", pf, answer) == 0 &&  pf == "T"  &&  answer);
 cout << "Passed all tests" << endl;
 }
 
 then the resulting file must compile and build successfully, and when executed, produce no output other than Passed all tests.
 
 Do not use variables named and, or, or not; the g++ and clang++ compilers treat these as keywords (as the C++ Standard requires) even though Visual C++ doesn't.
 
 (Tips: In case you didn't already know it, you can append a character c to a string s by saying s += c. You'll have to adapt the code from the book, since it doesn't do any error checking and assumes that all operators are binary operators. It's possible to do the error checking as you do the infix-to-postfix conversion instead of in a separate step before that; as you go through the infix string, almost all syntax errors can be detected by noting whether it is legal for the current nonblank character to follow the nearest nonblank character before it. When converting infix to postfix, a unary operator like ! behaves a lot more like an open parenthesis than like a binary operator.)
 
 By Monday, April 28, there will be a link on the class webpage that will enable you to turn in this homework. Turn in one zip file that contains your solutions to the homework problems. The zip file should contain
 
 mazestack.cpp, if you solved problem 1
 mazequeue.cpp, if you solved problem 3
 eval.cpp, if you solved problem 5
 hw.doc, hw.docx, or hw.txt, if you solved problems 2 and/or 4
 Each source file you turn in may or may not contain a main routine; we'd prefer that it doesn't. If it does, our testing scripts will rename your main routine to something harmless. Our scripts will append our own main routine, then compile and run the resulting source file. Therefore, to get any credit, each source file you turn in must at least compile successfully (even though it's allowed to not link because of a missing main routine).
 
 In each source file you turn in, do not comment out your implementation; you want our test scripts to see it! (Some people do this when testing other files' code because they put all their code in one project instead of having a separate project for each of problems 1, 3, and 5.)
 */

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int evaluate(string infix, string& postfix, bool& result);
bool convert_ch_to_bool(char ch);
bool isLetter(char ch);
bool isOperator(char ch);
bool isClosedParentheses(char ch);
int operatorPrecedence(char ch);

int main() {
  
    string infix = "!F|  F|T&F";
    string postfix = "";
    bool result = false;
    evaluate(infix, postfix, result);
    return 0;
}

//attempt 1
// i wasn't even doing the homework... lol...
/*
 
int evaluate(string infix, string& postfix, bool& result)
{
    postfix = "";
    
    stack<string> expression;
    size_t expression_size = infix.size();
    
    string character("");
    
    for(int i=0; i < expression_size; i++)
    {
        string character = infix.substr(i,1);
        
        if (character != "*" && character != "/" && character != "+" && character != "-" && character != "(" && character != ")")
        {
            postfix.append(character);
        }
        if(character == "(")
        {
            expression.push(character);
        }
        if(character == "+" || character == "-" || character == "*"|| character == "/")
        {
            if(expression.empty()==true)
            {
                expression.push(character);
            }
            else
            {
                if(character == "*" || character =="/")
                {
                    while(expression.top() == "+" || expression.top() == "-" || expression.top() == "(")
                    {
                        postfix.append(expression.top());
                        expression.pop();
                        
                        if(expression.empty() == true)
                            break;
                    }
                    expression.push(character);
                }
                
                if(character == "+" || character == "-")
                {
                    while(expression.top() == "(")
                    {
                        postfix.append(expression.top());
                        expression.pop();
                        
                        if(expression.empty() == true)
                            break;
                    }
                    expression.push(character);
                }
            }
        }
        if(character == ")")
        {
            while(expression.top() != "(")
            {
                postfix.append(expression.top());
                expression.pop();
            }
            postfix.append(expression.top()); //append '('
            expression.pop(); //pop '('. assume
        }
    }
    
    
    while(expression.empty() == false)
    {
        postfix.append(expression.top());
        expression.pop();
    }
    
    cerr << postfix;
    
    
    return -1;
}
*/
int evaluate(string infix, string& postfix, bool& result)
{
    postfix = "";
    stack<char> expression;
    size_t expression_size = infix.size();
    char prev = '|';
    
    for(int i =0; i < expression_size; i++)
    {
        char ch = infix[i];
        //attempt 1:
        /*
        switch(ch)
        {
            case 'T':
            case 'F':
                postfix+= ch;
                break;
                
            case '(':
            {
                expression.push(ch);
                break;
            }
        
            case '!':
                if(!expression.empty())
                {
                    while((expression.top() != '|' || expression.top() != '&' || expression.top() ||expression.top() != '(') && expression.empty() == false)
                    {
                        postfix = postfix + expression.top();
                        expression.pop();
                    }
                    expression.push(ch);
                }
                else
                {
                    expression.push(ch);
                }
                break;
            case '&':
                if(!expression.empty())
                {
                    while((expression.top() != '|' || !expression.empty() || expression.top()!= '(') && expression.empty() == false)
                    {
                        postfix = postfix + expression.top();
                        expression.pop();
                    }
                    expression.push(ch);
                }
                else
                {
                    expression.push(ch);
                }
                break;
                
            case '|':
                if(!expression.empty())
                {
                    while(expression.top() != ')' && expression.empty() == false)
                    {
                        postfix = postfix + expression.top();
                        expression.pop();
                    }
                    expression.push(ch);
                }
                else
                {
                    expression.push(ch);
                }
                break;
            case ')':
                while(expression.top() != '(')
                {
                    postfix = postfix + expression.top();
                    expression.pop();
                }
                if(expression.empty() == false && expression.top() == '(')
                {
                    postfix = postfix + expression.top();
                    expression.pop(); //popping '('
                }
            case ' ':
                continue;
                break;
        }
         */
        
        //attempt 2:
        /*
        switch(ch)
        {
            case 'T':
            case 'F':
                postfix+= ch;
                break;
                
            case '(':
            {
                expression.push(ch);
                break;
            }
                
            case '!':
                if(!expression.empty())
                {
                    while((expression.top() != '|' || expression.top() != '&' || expression.top() ||expression.top() != '(') && expression.empty() == false)
                    {
                        postfix = postfix + expression.top();
                        expression.pop();
                    }
                    expression.push(ch);
                }
                else
                {
                    expression.push(ch);
                }
                
                            break;
            case '&':
                if(!expression.empty())
                {
                    while((expression.top() != '|' || !expression.empty() || expression.top()!= '(') && expression.empty() == false)
                    {
                        postfix = postfix + expression.top();
                        expression.pop();
                    }
                    expression.push(ch);
                }
                else
                {
                    expression.push(ch);
                }
                break;
                
            case '|':
                if(!expression.empty())
                {
                    while(expression.top() != ')' && expression.empty() == false)
                    {
                        postfix = postfix + expression.top();
                        expression.pop();
                    }
                    expression.push(ch);
                }
                else
                {
                    expression.push(ch);
                }
                break;
                
            case ')':
                while(expression.top() != '(') //pop the stack until you see '('
                {
                    postfix = postfix + expression.top();
                    expression.pop();
                    if(expression.top() == '(')
                    {
                        postfix = postfix + expression.top();
                        expression.pop();
                        break;
                    }
                }
                
            case ' ':
                continue;
                
            default:
                return 1;
        }
         */
        
        //attempt 3: I figured what's causing the bug
        switch(ch)
        {
            case ' ':
                continue;
                
            case 'T':
            case 'F':
                postfix += ch;
                break;
                
            case '|':
            case '&':
                if(isLetter(prev) || isClosedParentheses(prev))
                {
                    if(expression.empty())
                    {
                        expression.push(ch);
                    }
                    else //not empty, then pop all operators with greater or equal precedence off the stack and append them on the postfix string. Stop when you reach an operator with lower precedence or '('. push.
                    {
                      while(!expression.empty() && (operatorPrecedence(ch) <= operatorPrecedence(expression.top())) )//comment: order of the condition checks matter!
                      {
                          postfix += expression.top();
                          expression.pop(); //THIS POP INSIDE THE WHILE LOOP IS THE SOURCE FOR THE BUG!!!
                      }
                        expression.push(ch);
                    }
                }
                else
                {
                    return 1;
                }
                break;
            case '!':
                if(isOperator(prev)) //if the previous character is an operator
                {
                    expression.push(ch);
                }
                else
                {
                    return 1;
                }
                break;
            case '(':
                expression.push(ch);
                break;
            case ')':
                while(expression.top() != '(' && expression.empty() == false)
                {
                    postfix += expression.top();
                    expression.pop();
                }
                if(expression.top() == ')' && expression.empty() == false)
                {
                    postfix += expression.top();
                    expression.pop();
                }
                else
                {
                    return 1;
                }
                break;
    
            default:
                return 1;
        }
        prev = ch;
    } //end of for loop
    
    while(expression.empty() == false)
    {
        postfix = postfix + expression.top();
        expression.pop();
    }
    
    cerr <<postfix <<"\n";
    
    stack<bool> postfix_eval;
    for(int j =0; j < postfix.size(); j++)
    {
        char ch2 = postfix[j];
        switch(ch2)
        {
                case 'T':
            {
                postfix_eval.push(true);
                break;
            }
                case 'F':
            {
                postfix_eval.push(false);
                break;
            }
          
                case '|':
            {
                    bool temp = postfix_eval.top();
                    postfix_eval.pop();
                    bool temp2 = postfix_eval.top();
                    postfix_eval.pop();
                    postfix_eval.push(temp || temp2);
                break;
            }
            
            case '!':
            {
                    bool temp3 = postfix_eval.top();
                    postfix_eval.pop();
                    postfix_eval.push(!temp3);
                break;
                
            }

                case '&':
            {
                if(postfix_eval.empty() == false)
                {
                    bool temp4 = convert_ch_to_bool(postfix_eval.top());
                    postfix_eval.pop();
                    bool temp5 = convert_ch_to_bool(postfix_eval.top());
                    postfix_eval.pop();
                    postfix_eval.push(temp4&&temp5);
                }
                break;

            }
          
        }
        
        //another method of implementation.
        /*
         if(ch2 == 'T')
         postfix_eval.push(true);
         else if (ch2 == 'F')
         postfix_eval.push(false);
         else
         {
         bool temp = postfix_eval.top();
         postfix_eval.pop();
         if(ch2 == '!')
         postfix_eval.push(!temp);
         else
         {
         bool temp2 = postfix_eval.top();
         postfix_eval.pop();
         if(ch2 == '&')
         postfix_eval.push(temp && temp2);
         else if (ch2 == '|')
         postfix_eval.push(temp || temp2);
         }
         }
         
         */
    }
    
    result = postfix_eval.top();
    cerr <<result;
    return 0;
}

/*
 char temp = postfix_eval.top();
 postfix_eval.pop();
 char temp2 = postfix_eval.top();
 postfix_eval.pop();
 if(temp)
*/

bool convert_ch_to_bool(char ch)
{
    if(ch == 'T')
        return true;
    else
        return false;
}

bool isLetter(char ch)
{
    if(ch == 'T' || ch == 'F')
        return true;
    else
        return false;
}

bool isOperator(char ch)
{
    string operators = "|&!("; //except ')'
    for(int i =0; i < operators.size(); i++)
    {
        char ops = operators[i];
        if(ch == ops)
        return true;
    }
    return false;
    
}

bool isClosedParentheses(char ch)
{
    if(ch == ')')
        return true;
    else return false;
}

int operatorPrecedence(char ch)
{
    if(isOperator(ch) == false)
    {
        cerr << "not an operator\n";
        return -1;
    }
    const string operators = "(|&!";
    for(int i =0; i < operators.size(); i++)
    {
        if(ch == operators[i])
            return i;
    }
    return -1; // error
}
