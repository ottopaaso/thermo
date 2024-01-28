#include "ISystem.h"

class System : public ISystem {
public:
    SystemTimePoint getCurrentDateTime() const override;
};
