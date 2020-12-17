
#ifndef Header_h
#define Header_h
#include <iostream>


using namespace std;


class MakeUp
{
protected:
    string description;
public:
    MakeUp() : description ("Unknown Beverage"){};
    virtual string getDescription(){
        return description;
    }
    virtual double cost() = 0;
    virtual ~MakeUp(){};
};

class Nude : public MakeUp
{
public:
    Nude(){
        description = "Nude make up";
    }
    double cost() {return 15.3;}
    virtual ~Nude(){};
};
class Shining : public MakeUp
{
public:
    Shining(){
        description = "Shining make up";
    }
    double cost(){return 17.5;}
    virtual ~Shining(){};
};

class Extras : public MakeUp
{
public:
    virtual string getDescription() = 0;
};

class Glitter : public Extras
{
private:
    MakeUp *makeup;
public:
    Glitter(MakeUp* makeup_){
        makeup = makeup_;
    }
    string getDescription(){
        return makeup->getDescription();
    }
    double cost(){
        return 2.5 + makeup->cost();
    }
    virtual ~Glitter(){
        delete makeup;
    }
};
class BrigthLipstick : public Extras
{
private:
    MakeUp *makeup;
public:
    BrigthLipstick(MakeUp *makeup_){
        makeup = makeup_;
    }
    string getDescription(){
        return makeup->getDescription();
    }
    double cost(){
        return 1.0 + makeup->cost();
    }
    virtual ~BrigthLipstick(){
        delete makeup;
    }
};
class Baking: public Extras
{
private:
    MakeUp *makeup;
public:
    Baking(MakeUp *makeup_){
        makeup = makeup_;
    }
    string getDescription(){
        return makeup->getDescription();
    }
    double cost(){
        return 5.67 + makeup->cost();
    }
    virtual ~Baking(){
        delete makeup;
    }
};
#endif /* Header_h */
