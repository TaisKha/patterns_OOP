#include <iostream>
#include <vector>


using namespace std;
class Command;
class Lamp;
class TurnOn;
class TurnOff;
class BrightnessCommandDown;
class BrightnessCommandDown;
class Brightness;
class NothingCommand;
class Invoker;
class Lamp


{
public:
    void On()
    {
        cout << "Lamp is on" << endl;
    }
    void Off(){
        cout << "Lamp is off" << endl;
    }
};
class Command
{
public:
    virtual void Execute(){};
    virtual void unExecute(){};
    
};
class TurnOn : public Command{
private:
    Lamp* lamp;
public:
    TurnOn(Lamp* l) : lamp(l){};
    virtual void Execute(){
        lamp->On();
    }
    virtual void unExecute(){
        lamp->Off();
    }
};
class TurnOff : public Command{
    private:
        Lamp* lamp;
    public:
        TurnOff(Lamp* l) : lamp(l){};
        virtual void unExecute(){
            lamp->On();
        }
        virtual void Execute(){
            lamp->Off();
        }
};
class Brightness
{
private:
    int level;
public:
    Brightness() : level(1){};
    void addBrigtness(){
        if (level < 5){
            level++;
            cout << "Brightness level is " << level << endl;
        }
        else{
            cout << "Brightness level is already maximum" << endl;;
        }
    }
    void dropBrightness(){
        if (level > 1){
            level--;
            cout << "Brightness level is " << level << endl;
        }
        else{
             cout << "Brightness level is already minimum" << endl;
        }
    }
};
class BrightnessCommandUp : public Command
{
private:
    Brightness* brightness;
public:
    BrightnessCommandUp(Brightness* b) : brightness(b){};
    virtual void Execute(){
        brightness->addBrigtness();
    }
    virtual void unExecute(){
        brightness->dropBrightness();
    }
    
};
class BrightnessCommandDown : public Command
{
private:
    Brightness* brightness;
public:
    BrightnessCommandDown(Brightness* b) : brightness(b){};
    virtual void unExecute(){
        brightness->addBrigtness();
    }
    virtual void Execute(){
        brightness->dropBrightness();
    }
    
};

class NothingCommand : public Command
{
public:
    virtual void Execute() {};
    virtual void unExecute() {};
};

class Invoker
{
private:
    vector<Command*> buttons;
    vector<Command*> history;
    Command* buffer;
public:
    Invoker():history(0){
        buttons.push_back(new NothingCommand()); //buttons[0]
        buttons.push_back(new NothingCommand());//buttons[1]
        buttons.push_back(new NothingCommand());//buttons[2]
        buttons.push_back(new NothingCommand());//buttons[3]
        buffer = nullptr;
    }
    void setCommand(const int n, Command* command){
        buttons[n] = command;
    }
    void pressButton(const int n){
        buttons[n]->Execute();
        history.push_back(buttons[n]);
    }
    void pressUndo(){
        if (!history.empty()){
            Command* undo = history.back();
            buffer = undo;
            history.pop_back();
            undo->unExecute();
        }
        else{
            cout << "History is empty" << endl;
        }
    }
    void pressRedo(){
        if (buffer == nullptr){
            cout << "Undo should be done before" << endl;
        }
        else{
            buffer->Execute();
            history.push_back(buffer);
            delete buffer;
        }
    }
    ~Invoker(){
        history.clear();
        buttons.clear();
    }
};

int main() {
    Lamp* lamp = new Lamp;
    Brightness* brightness = new Brightness;
    Invoker* pult = new Invoker;
    pult->setCommand(0, new TurnOff(lamp));
    pult->setCommand(1, new TurnOn(lamp));
    pult->setCommand(2, new BrightnessCommandUp(brightness));
    pult->setCommand(3, new BrightnessCommandDown(brightness));
    //завершили настройку пульта управление
    pult->pressUndo();//действий еще не было, но попытается отменить(выведется сообщение об этом)
    pult->pressButton(1);//включение
    pult->pressUndo();//отмена(выключение)
    pult->pressRedo();//отмена undo - снова включение
    pult->pressButton(3); //попытка уменьшить яркость, хотя она и так на минимуме(выводится сообщение об этом)
    pult->pressButton(2);//увеличить яркость
    pult->pressButton(2);//увеличить яркость
    pult->pressButton(2);//увеличить яркость
    pult->pressUndo();//отмена(уменьшение)
    pult->pressUndo();//отмена(уменьшение)
    pult->pressRedo();//отмена undo (увеличили обратно)
    pult->pressRedo();
    cout << " lll" << endl;
    pult->pressButton(2);//увеличить яркость(достигли максимума)
    pult->pressButton(2);//увеличить яркость(сообщение, что уже и так максиум)
    pult->pressButton(3);//уменьшить яркость
    pult->pressButton(0);//выключение
    pult->pressButton(2);
    return 0;
}
