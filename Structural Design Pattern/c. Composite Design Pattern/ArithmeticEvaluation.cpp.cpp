#include <iostream>
#include <vector>
using namespace std;

class ArithmeticExp {

public:
    virtual int evaluate()=0;
};

class Num:public ArithmeticExp {

int val;
public:
    Num(int val){

    this->val = val;
    }
    int evaluate() {
        //cout<<val<<endl;
      return val;
    }
};

enum Operation {
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE
};

class Exp:public ArithmeticExp {

ArithmeticExp* left;
ArithmeticExp* right;
Operation op;

public:
    Exp(ArithmeticExp* l,ArithmeticExp* r,Operation op) {

    left = l;
    right = r;
    this->op = op;

    }

    int evaluate() {

    int val = 0;
    switch(op){
   case ADD:
    val = left->evaluate() + right->evaluate();
    break;
   case SUBTRACT:
    val = left->evaluate() - right->evaluate();
    break;
   case DIVIDE:
    val=left->evaluate()/right->evaluate();
    break;
   case MULTIPLY:
     val = left->evaluate()*right->evaluate();
     break;
    }
    return val;
    }

};


int main() {

ArithmeticExp* two = new Num(2);
ArithmeticExp* three = new Num(3);
ArithmeticExp* one  = new Num(1);
Operation ope;
ArithmeticExp* addExp = new Exp(two,three,ADD);
cout<<addExp->evaluate()<<endl;
ArithmeticExp* parentExp = new Exp(one,addExp,SUBTRACT);

cout<<parentExp->evaluate()<<endl;

return 0;
}
