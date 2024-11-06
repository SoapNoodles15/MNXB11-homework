#ifndef __MOMENTUM_DATA_H__
#define __MOMENTUM_DATA_H__
#include <TObject.h>


class MomentumData : public TObject {
    public:
        MomentumData();
        MomentumData(Float_t px, Float_t py, Float_t pz);
        virtual ~MomentumData();
        
        Float_t getPx() const { return fPx; }
        Float_t getPy() const { return fPy; }
        Float_t getPz() const { return fPz; }

        Float_t calculateMagnitude() const;

    private:
        Float_t fPx;
        Float_t fPy;
        Float_t fPz;
        Float_t fPmag;
        ClassDef(MomentumData, 1);
};


#endif // __MOMENTUM_DATA_H__
