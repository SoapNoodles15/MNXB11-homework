#include "MomentumData.h"
#include <cmath>

ClassImp(MomentumData)

MomentumData::MomentumData() : fPx(0), fPy(0), fPz(0)
{

}

MomentumData::MomentumData(Float_t px, Float_t py, Float_t pz) : fPx(px), fPy(py), fPz(pz)
{
fPmag = calculateMagnitude();
}

MomentumData::~MomentumData()
{
}
Float_t MomentumData::calculateMagnitude() const 
{
    return std::sqrt(fPx * fPx + fPy * fPy + fPz * fPz);
}
