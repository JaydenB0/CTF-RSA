#include "includes/variables.hpp"

bool VarEngine::checkModify() {
    if ((newVals & updated).any()) {
        origVals = newVals;
        origVals &= ~updated;
        return true;
    } else {
        return false;
    }
}