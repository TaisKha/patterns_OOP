#ifndef file_hpp
#define file_hpp

#include <iostream>
#include <list>


using namespace std;


class Observer;
class Channel;

class Observer {
public:
    virtual void refresh(Channel*){};
};

class Channel {
public:
    virtual void registerObserver(Observer* person){};
    virtual void removeObserver(Observer *person){};
    virtual void notifyObservers(){};
};

class FunnyCats : public Channel{
private:
    list<Observer*> people;
    int num;
public:
    FunnyCats() : people(), num(0){};
    FunnyCats(int n) : people(), num(n){};
    void registerObserver(Observer* person){
        people.push_back(person);
        cout << "Registration in Funny Cats is succsessful. Person ( " << person << " )" << endl;
    }
    void removeObserver(Observer* person){
        people.remove(person);
        cout << "Removing observer from Funny Cats is successful" << endl;
    }
    void notifyObservers(){
        cout << "Notifying observers of Funny Cats" << endl;
        for(const auto person : people){
            cout << "Notifying " << person << endl;
            person->refresh(this);
        }
    }
    void addPost(){
        ++num;
        notifyObservers();
    }
    void setInfo(int n){
        num = n;
    }
    int getInfo(){
        return num;
    }
    ~FunnyCats(){
        people.clear();
    }
    
};
class FunnyDogs : public Channel{
private:
    list<Observer*> people;
    int num;
public:
    FunnyDogs() : people(), num(0){};
    FunnyDogs(int n) : people(), num(n){};
    void registerObserver(Observer* person){
        people.push_back(person);
        cout << "Registration in Funny Dogs is succsessful. Person ( " << person << " )" << endl;
    }
    void removeObserver(Observer* person){
        people.remove(person);
        cout << "Removing observer from Funny Dogs is successful" << endl;
    }
    void notifyObservers(){
        cout << "Notifying observers of Funny Dogs" << endl;
        for(const auto person : people){
            cout << "Notifying " << person << endl;
            person->refresh(this);
        }
    }
    void addPost(){
        ++num;
        notifyObservers();
    }
    void setInfo(int n){
        num = n;
    }
    int getInfo(){
        return num;
    }
    ~FunnyDogs(){
        people.clear();
    }
    
};
class Man : public Observer{
private:
    FunnyCats *Cats;
    FunnyDogs *Dogs;
public:
    Man():Cats(NULL), Dogs(NULL){};
    void subscribe(Channel * chanel){
        chanel->registerObserver(this);
        FunnyCats * funnyC = dynamic_cast<FunnyCats*>(chanel);
        FunnyDogs * funnyD = dynamic_cast<FunnyDogs*>(chanel);
        if (funnyC){
            Cats = new FunnyCats;
            Cats->setInfo(funnyC->getInfo());
        }
        if (funnyD){
            Dogs = new FunnyDogs;
            Dogs->setInfo(funnyD->getInfo());
        }
    }
    void unsubscribe(Channel & chanel){
        chanel.removeObserver(this); //?
    }
    void refresh(Channel * chanel){
        FunnyCats * funnyC = dynamic_cast<FunnyCats*>(chanel);
        FunnyDogs * funnyD = dynamic_cast<FunnyDogs*>(chanel);
        if (funnyC){
            Cats->setInfo(funnyC->getInfo());
        }
        if (funnyD){
            Dogs->setInfo(funnyD->getInfo());
        }
    }
    void display(){
        cout << "Person is " << this << endl;
        if (Cats){
            cout << "Funny Cats - " << Cats->getInfo()<< endl;
        }
        if (Dogs){
            cout << "Funny Dogs - " << Dogs->getInfo()<< endl;
        }
    }
};
class Woman : public Observer{
private:
    FunnyCats *Cats;
    FunnyDogs *Dogs;
public:
    Woman():Cats(NULL), Dogs(NULL){};
    void subscribe(Channel * chanel){
        chanel->registerObserver(this);
        FunnyCats * funnyC = dynamic_cast<FunnyCats*>(chanel);
        FunnyDogs * funnyD = dynamic_cast<FunnyDogs*>(chanel);
        if (funnyC){
            Cats = new FunnyCats;
            Cats->setInfo(funnyC->getInfo());
        }
        if (funnyD){
            Dogs = new FunnyDogs;
            Dogs->setInfo(funnyD->getInfo());
        }
    }
    void unsubscribe(Channel & chanel){
        chanel.removeObserver(this); //?
    }
    void refresh(Channel * chanel){
        FunnyCats * funnyC = dynamic_cast<FunnyCats*>(chanel);
        FunnyDogs * funnyD = dynamic_cast<FunnyDogs*>(chanel);
        if (funnyC){
            Cats->setInfo(funnyC->getInfo());
        }
        if (funnyD){
            Dogs->setInfo(funnyD->getInfo());
        }
    }
    void display(){
        cout << "Person is " << this << endl;
        if (Cats){
            cout << "Funny Cats - " << Cats->getInfo()<< endl;
        }
        if (Dogs){
            cout << "Funny Dogs - " << Dogs->getInfo()<< endl;
        }
    }
};
#endif /* file_hpp */
