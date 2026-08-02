#include <cmath>
#include <string>
#include <unistd.h>
#include<iostream>
#include<fstream>
std::string help();
void percentage(double arg1, double arg2){
    double result;
    result=(arg2/100)*arg1;
    std::cout<<result;
}
template<typename tem1,typename tem2,typename tem3>
auto calc(tem1 arg1,tem2 op,tem3 arg2){
    double result;
    switch(op){
        case 'p':
            result=pow(arg1,arg2);
            break;
        case 's':
            result=sqrt(arg1);
            break;
        case '*':
            result=arg1*arg2;
            break;
        case '/':
            result=arg1/arg2;
            break;
        case '+':
            result=arg1+arg2;
            break;
        case '-':
            result=arg1-arg2;
            break;
        case '%':
            result=(arg1/100)*arg2;
    }
    std::fstream a;
    a.open("ans.txt",std::ios::out );
    a<<std::to_string(result);
    a.close();
    return result;
};
int main(){
    std::cout<<"--Calcy-"<<std::endl;
    std::cout<<help()<<std::endl;
    
        
        while(true){ 
        std::string arg1;
        std::string op;
        std::string arg2;
        std::string availableoperators[]{"p","s","/","*","+","-","%"};
        bool opisavailable;
        std::cout<<":";
        std::cin>>arg1;
        if(arg1=="exit"){break;}
        if(arg1=="help"){std::cout<<help();}
        if(arg1=="ans"){
        std::ifstream ans("ans.txt",std::ios::in);
        getline(ans,arg1);
        ans.close();
        }
        std::cin>>op;
        std::cin>>arg2;
    for(int i=0;i<(sizeof(availableoperators)/sizeof(availableoperators[0]));i++){
        if(op==availableoperators[i]){
            opisavailable=true;
            break;
    }}
    
    if(opisavailable==true){
         try{

        std::cout<<calc(std::stod(arg1),op[0], stod(arg2))<<std::endl;
    }   catch(std::invalid_argument){
        std::cout<<"exception caught";
        }
    }
    else{
        std::cout<<help();
    }    
        }
    }

std::string help(){
    return "Available operators:\nExponentiation(p),\nSquare root(s),\nMultiplication(*)\nDivision(/),\nAddition(+),\nSubstraction(-)";
}