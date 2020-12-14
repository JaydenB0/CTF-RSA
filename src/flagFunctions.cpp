#include "includes/variables.hpp"

StateFlag::StateFlag(string* valueArray)
{
    for (int i = 0; i < 8; i++)
        if (valueArray[i].compare("0") == 0)
            this->currentFlag.reset(i);
        else 
            this->currentFlag.set(i);
    resetInitial();
}

bool StateFlag::checkModified()
{
    if ((this->currentFlag & this->initialFlag) == this->initialFlag) return false;
    else return true;
}

void StateFlag::resetInitial()
{
    this->initialFlag = this->currentFlag;
}
